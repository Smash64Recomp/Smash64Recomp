#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbFadeMakeActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D4064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D4068: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D406C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D4070: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D4074: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800D4078: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x800D407C: jal         0x80009968
    // 0x800D4080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D4080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800D4084: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D4088: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800D408C: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800D4090: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D4094: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D4098: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800D409C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D40A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D40A4: addiu       $a1, $a1, 0x3F08
    ctx->r5 = ADD32(ctx->r5, 0X3F08);
    // 0x800D40A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D40AC: jal         0x80009F74
    // 0x800D40B0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80009F74(rdram, ctx);
        goto after_1;
    // 0x800D40B0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800D40B4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D40B8: addiu       $a1, $a1, 0x3E80
    ctx->r5 = ADD32(ctx->r5, 0X3E80);
    // 0x800D40BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D40C4: jal         0x80008188
    // 0x800D40C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x800D40C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x800D40CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800D40D0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800D40D4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D40D8: lwl         $t2, 0x0($t0)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r8, 0X0);
    // 0x800D40DC: lwr         $t2, 0x3($t0)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r8, 0X3);
    // 0x800D40E0: addiu       $t9, $t9, 0x646C
    ctx->r25 = ADD32(ctx->r25, 0X646C);
    // 0x800D40E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D40E8: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x800D40EC: sw          $v1, 0x6460($at)
    MEM_W(0X6460, ctx->r1) = ctx->r3;
    // 0x800D40F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D40F4: sw          $zero, 0x6464($at)
    MEM_W(0X6464, ctx->r1) = 0;
    // 0x800D40F8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800D40FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D4100: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x800D4104: sw          $t3, 0x6468($at)
    MEM_W(0X6468, ctx->r1) = ctx->r11;
    // 0x800D4108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D410C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D4110: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800D4114: sw          $t4, 0x6474($at)
    MEM_W(0X6474, ctx->r1) = ctx->r12;
    // 0x800D4118: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D411C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D4120: jr          $ra
    // 0x800D4124: sw          $t5, 0x6470($at)
    MEM_W(0X6470, ctx->r1) = ctx->r13;
    return;
    // 0x800D4124: sw          $t5, 0x6470($at)
    MEM_W(0X6470, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void itEggWaitSetModelVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801816B8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801816BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801816C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801816C4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801816C8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x801816CC: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801816D0: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x801816D4: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x801816D8: jr          $ra
    // 0x801816DC: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x801816DC: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void lbCommonSim3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7B60: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7B64: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7B68: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C7B6C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C7B70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C7B74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7B78: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7B7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C7B80: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C7B84: jal         0x80033510
    // 0x800C7B88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7B88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800C7B8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800C7B90: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7B94: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7B98: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7B9C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7BA0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7BA4: nop

    // 0x800C7BA8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C7BAC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C7BB0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C7BB4: jal         0x80033510
    // 0x800C7BB8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7BB8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x800C7BBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C7BC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800C7BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7BC8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7BCC: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7BD0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7BD4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7BD8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800C7BDC: nop

    // 0x800C7BE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C7BE4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C7BE8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7BEC: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C7BF0: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C7BF4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C7BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7BFC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800C7C00: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C7C04: jr          $ra
    // 0x800C7C08: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    return;
    // 0x800C7C08: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
;}
RECOMP_FUNC void gcSetAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BB08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000BB0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000BB10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000BB14: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000BB18: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8000BB1C: beql        $s0, $zero, L_8000BB3C
    if (ctx->r16 == 0) {
        // 0x8000BB20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000BB3C;
    }
    goto skip_0;
    // 0x8000BB20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8000BB24:
    // 0x8000BB24: swc1        $f20, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f20.u32l;
    // 0x8000BB28: jal         0x8000BAA0
    // 0x8000BB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_0;
    // 0x8000BB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BB30: bne         $v0, $zero, L_8000BB24
    if (ctx->r2 != 0) {
        // 0x8000BB34: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000BB24;
    }
    // 0x8000BB34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000BB38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000BB3C:
    // 0x8000BB3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000BB40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000BB44: jr          $ra
    // 0x8000BB48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BB48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unref_8000A00C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A00C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000A018: bne         $a0, $zero, L_8000A028
    if (ctx->r4 != 0) {
        // 0x8000A01C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8000A028;
    }
    // 0x8000A01C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8000A020: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A024: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000A028:
    // 0x8000A028: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A02C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000A030: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000A034: lw          $a2, 0x28($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X28);
    // 0x8000A038: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8000A03C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000A040: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A044: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000A048: jal         0x80009F28
    // 0x8000A04C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80009F28(rdram, ctx);
        goto after_0;
    // 0x8000A04C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8000A050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A054: jal         0x80007B98
    // 0x8000A058: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A058: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8000A05C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A064: jr          $ra
    // 0x8000A068: nop

    return;
    // 0x8000A068: nop

;}
RECOMP_FUNC void itBombHeiFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801774B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801774B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801774B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801774BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801774C0: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x801774C4: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801774C8: jal         0x80173F78
    // 0x801774CC: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801774CC: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x801774D0: jal         0x80177208
    // 0x801774D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_1;
    // 0x801774D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801774D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801774DC: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x801774E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801774E4: jal         0x80172EC8
    // 0x801774E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801774E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x801774EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801774F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801774F4: jr          $ra
    // 0x801774F8: nop

    return;
    // 0x801774F8: nop

;}
RECOMP_FUNC void gcGetCObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080DC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800080E0: addiu       $a2, $a2, 0x6A48
    ctx->r6 = ADD32(ctx->r6, 0X6A48);
    // 0x800080E4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800080E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800080EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800080F0: bne         $v1, $zero, L_80008118
    if (ctx->r3 != 0) {
        // 0x800080F4: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80008118;
    }
    // 0x800080F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800080F8: lhu         $a0, 0x6A50($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6A50);
    // 0x800080FC: jal         0x80004980
    // 0x80008100: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80008100: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80008104: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80008108: addiu       $a2, $a2, 0x6A48
    ctx->r6 = ADD32(ctx->r6, 0X6A48);
    // 0x8000810C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80008110: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80008114: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80008118:
    // 0x80008118: bne         $v1, $zero, L_80008134
    if (ctx->r3 != 0) {
        // 0x8000811C: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80008134;
    }
    // 0x8000811C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80008120: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80008124: jal         0x80023624
    // 0x80008128: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80008128: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    after_1:
L_8000812C:
    // 0x8000812C: b           L_8000812C
    pause_self(rdram);
    // 0x80008130: nop

L_80008134:
    // 0x80008134: addiu       $a1, $a1, 0x6A4C
    ctx->r5 = ADD32(ctx->r5, 0X6A4C);
    // 0x80008138: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000813C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008140: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80008144: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80008148: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000814C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008150: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80008154: jr          $ra
    // 0x80008158: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80008158: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void itRShellThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017AAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AAF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017AAFC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017AB00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017AB04: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8017AB08: lbu         $t8, 0x2CE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017AB0C: sb          $v0, 0x352($a0)
    MEM_B(0X352, ctx->r4) = ctx->r2;
    // 0x8017AB10: sb          $v0, 0x353($a0)
    MEM_B(0X353, ctx->r4) = ctx->r2;
    // 0x8017AB14: andi        $t9, $t8, 0xFFF1
    ctx->r25 = ctx->r24 & 0XFFF1;
    // 0x8017AB18: sb          $t7, 0x350($a0)
    MEM_B(0X350, ctx->r4) = ctx->r15;
    // 0x8017AB1C: jal         0x80173F78
    // 0x8017AB20: sb          $t9, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r25;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017AB20: sb          $t9, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r25;
    after_0:
    // 0x8017AB24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017AB28: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017AB2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017AB30: jal         0x80172EC8
    // 0x8017AB34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017AB34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8017AB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017AB40: jr          $ra
    // 0x8017AB44: nop

    return;
    // 0x8017AB44: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcSetOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D77C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D784: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016D788: lbu         $t6, 0x2A2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2A2);
    // 0x8016D78C: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x8016D790: bnel        $t7, $zero, L_8016D7A4
    if (ctx->r15 != 0) {
        // 0x8016D794: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D7A4;
    }
    goto skip_0;
    // 0x8016D794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8016D798: jal         0x8016CDC8
    // 0x8016D79C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpLinkBoomerangSetReturnVars(rdram, ctx);
        goto after_0;
    // 0x8016D79C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016D7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016D7A4:
    // 0x8016D7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D7A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016D7AC: jr          $ra
    // 0x8016D7B0: nop

    return;
    // 0x8016D7B0: nop

;}
RECOMP_FUNC void lbRelocLoadFilesIntern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDE78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CDE7C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDE80: lw          $v1, 0x62F0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62F0);
    // 0x800CDE84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CDE88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CDE8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CDE90: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CDE94: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CDE98: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CDE9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDEA0: beq         $a1, $zero, L_800CDECC
    if (ctx->r5 == 0) {
        // 0x800CDEA4: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_800CDECC;
    }
    // 0x800CDEA4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_800CDEA8:
    // 0x800CDEA8: jal         0x800CDCAC
    // 0x800CDEAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    lbRelocGetInternBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDEAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800CDEB0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800CDEB4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800CDEB8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CDEBC: bne         $s0, $zero, L_800CDEA8
    if (ctx->r16 != 0) {
        // 0x800CDEC0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800CDEA8;
    }
    // 0x800CDEC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800CDEC4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDEC8: lw          $v1, 0x62F0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62F0);
L_800CDECC:
    // 0x800CDECC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDED0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800CDED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CDED8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDEDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CDEE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CDEE4: jr          $ra
    // 0x800CDEE8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    return;
    // 0x800CDEE8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
;}
RECOMP_FUNC void ftYoshiSpecialAirNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E588: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E58C: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8015E590: jr          $ra
    // 0x8015E594: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015E594: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void syAudioCheckBGMPlaying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80020D5C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020D60: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80020D64: lw          $t7, -0x26A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26A0);
    // 0x80020D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020D6C: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80020D70: bne         $t8, $zero, L_80020D80
    if (ctx->r24 != 0) {
        // 0x80020D74: nop
    
            goto L_80020D80;
    }
    // 0x80020D74: nop

    // 0x80020D78: jr          $ra
    // 0x80020D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80020D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020D80:
    // 0x80020D80: jr          $ra
    // 0x80020D84: nop

    return;
    // 0x80020D84: nop

;}
RECOMP_FUNC void syVectorMag3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018F84: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018F88: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018F8C: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018F90: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018F94: nop

    // 0x80018F98: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018F9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018FA0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018FA4: jal         0x80033510
    // 0x80018FA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018FA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80018FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018FB4: jr          $ra
    // 0x80018FB8: nop

    return;
    // 0x80018FB8: nop

;}
RECOMP_FUNC void sc1PStageClearMakeTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013213C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132140: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132144: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80132148: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8013214C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132158: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8013215C: jal         0x80009968
    // 0x80132160: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132160: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132164: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132168: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x8013216C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132174: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132178: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8013217C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132180: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132184: jal         0x80009DF4
    // 0x80132188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013218C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80132190: addiu       $s2, $s2, 0x5588
    ctx->r18 = ADD32(ctx->r18, 0X5588);
    // 0x80132194: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80132198: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8013219C: addiu       $t8, $t8, -0x2E38
    ctx->r24 = ADD32(ctx->r24, -0X2E38);
    // 0x801321A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321A4: jal         0x800CCFDC
    // 0x801321A8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801321A8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801321AC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801321B0: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x801321B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801321B8: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801321BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801321C0: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801321C4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801321C8: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801321CC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801321D0: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801321D4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801321D8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801321DC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801321E0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801321E4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801321E8: lw          $t3, 0x52D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X52D4);
    // 0x801321EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801321F0: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801321F4: bne         $t3, $at, L_80132264
    if (ctx->r11 != ctx->r1) {
        // 0x801321F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132264;
    }
    // 0x801321F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321FC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80132200: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80132204: addiu       $t5, $t5, -0x5068
    ctx->r13 = ADD32(ctx->r13, -0X5068);
    // 0x80132208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013220C: jal         0x800CCFDC
    // 0x80132210: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132210: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80132214: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132218: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x8013221C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132220: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132224: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132228: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013222C: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x80132230: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132234: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132238: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x8013223C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132240: sb          $s1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r17;
    // 0x80132244: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132248: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x8013224C: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x80132250: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132254: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132258: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013225C: b           L_8013234C
    // 0x80132260: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_8013234C;
    // 0x80132260: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132264:
    // 0x80132264: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80132268: addiu       $t2, $t2, 0x1D58
    ctx->r10 = ADD32(ctx->r10, 0X1D58);
    // 0x8013226C: jal         0x800CCFDC
    // 0x80132270: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132270: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80132274: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80132278: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
    // 0x8013227C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132280: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132284: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132288: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x8013228C: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x80132290: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132294: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132298: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8013229C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801322A0: sb          $s1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r17;
    // 0x801322A4: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801322A8: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801322AC: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x801322B0: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801322B4: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801322B8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801322BC: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801322C0: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801322C4: lw          $t8, 0x52D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X52D4);
    // 0x801322C8: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801322CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322D0: bne         $t8, $zero, L_801322F4
    if (ctx->r24 != 0) {
        // 0x801322D4: lui         $t2, 0x0
        ctx->r10 = S32(0X0 << 16);
            goto L_801322F4;
    }
    // 0x801322D4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801322D8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x801322DC: addiu       $t0, $t0, 0x9D8
    ctx->r8 = ADD32(ctx->r8, 0X9D8);
    // 0x801322E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322E4: jal         0x800CCFDC
    // 0x801322E8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801322E8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x801322EC: b           L_80132308
    // 0x801322F0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
        goto L_80132308;
    // 0x801322F0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
L_801322F4:
    // 0x801322F4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x801322F8: addiu       $t2, $t2, 0x1338
    ctx->r10 = ADD32(ctx->r10, 0X1338);
    // 0x801322FC: jal         0x800CCFDC
    // 0x80132300: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132300: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80132304: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
L_80132308:
    // 0x80132308: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8013230C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132310: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132318: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x8013231C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132320: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132324: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x80132328: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013232C: sb          $s1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r17;
    // 0x80132330: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132334: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132338: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x8013233C: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132340: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132344: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132348: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_8013234C:
    // 0x8013234C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132350: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132354: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132358: jal         0x80009968
    // 0x8013235C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_7;
    // 0x8013235C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_7:
    // 0x80132360: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132364: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132368: sw          $v0, 0x5314($at)
    MEM_W(0X5314, ctx->r1) = ctx->r2;
    // 0x8013236C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132370: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132378: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8013237C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132380: jal         0x80009DF4
    // 0x80132384: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_8;
    // 0x80132384: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80132388: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8013238C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80132390: addiu       $t0, $t0, -0x2CC0
    ctx->r8 = ADD32(ctx->r8, -0X2CC0);
    // 0x80132394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132398: jal         0x800CCFDC
    // 0x8013239C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x8013239C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_9:
    // 0x801323A0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801323A4: lui         $at, 0x42F2
    ctx->r1 = S32(0X42F2 << 16);
    // 0x801323A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801323AC: lui         $at, 0x4286
    ctx->r1 = S32(0X4286 << 16);
    // 0x801323B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801323B4: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801323B8: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801323BC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801323C0: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x801323C4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801323C8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801323CC: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x801323D0: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x801323D4: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801323D8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801323DC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801323E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801323E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801323E8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801323EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801323F0: jr          $ra
    // 0x801323F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801323F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ifCommonSetMaxNumGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114800: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80114804: addiu       $v0, $v0, 0x65E8
    ctx->r2 = ADD32(ctx->r2, 0X65E8);
    // 0x80114808: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8011480C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80114810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80114814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114818: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8011481C: jal         0x8000A334
    // 0x80114820: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    gcGetMaxNumGObj(rdram, ctx);
        goto after_0;
    // 0x80114820: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80114824: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80114828: bne         $v0, $at, L_8011484C
    if (ctx->r2 != ctx->r1) {
        // 0x8011482C: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_8011484C;
    }
    // 0x8011482C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80114830: sltiu       $at, $t9, 0x6400
    ctx->r1 = ctx->r25 < 0X6400 ? 1 : 0;
    // 0x80114834: beql        $at, $zero, L_80114850
    if (ctx->r1 == 0) {
        // 0x80114838: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80114850;
    }
    goto skip_0;
    // 0x80114838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8011483C: jal         0x800078C8
    // 0x80114840: nop

    gcGetGObjsActiveNum(rdram, ctx);
        goto after_1;
    // 0x80114840: nop

    after_1:
    // 0x80114844: jal         0x8000A328
    // 0x80114848: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcSetMaxNumGObj(rdram, ctx);
        goto after_2;
    // 0x80114848: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_8011484C:
    // 0x8011484C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114850:
    // 0x80114850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80114854: jr          $ra
    // 0x80114858: nop

    return;
    // 0x80114858: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingSelectFighterPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $v1, $zero, 0xB8
    ctx->r3 = ADD32(0, 0XB8);
    // 0x80131B5C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131B64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131B68: addiu       $v0, $v0, -0x7AA8
    ctx->r2 = ADD32(ctx->r2, -0X7AA8);
    // 0x80131B6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131B74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131B78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131B80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80131B84: mflo        $t7
    ctx->r15 = lo;
    // 0x80131B88: addu        $s2, $v0, $t7
    ctx->r18 = ADD32(ctx->r2, ctx->r15);
    // 0x80131B8C: beq         $a1, $at, L_80131BF4
    if (ctx->r5 == ctx->r1) {
        // 0x80131B90: lw          $s1, 0x7C($s2)
        ctx->r17 = MEM_W(ctx->r18, 0X7C);
            goto L_80131BF4;
    }
    // 0x80131B90: lw          $s1, 0x7C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X7C);
    // 0x80131B94: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B98: mflo        $t8
    ctx->r24 = lo;
    // 0x80131B9C: addu        $s0, $v0, $t8
    ctx->r16 = ADD32(ctx->r2, ctx->r24);
    // 0x80131BA0: jal         0x800EC0EC
    // 0x80131BA4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131BA4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x80131BA8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80131BAC: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80131BB0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80131BB4: jal         0x80133350
    // 0x80131BB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckCostumeUsed(rdram, ctx);
        goto after_1;
    // 0x80131BB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80131BBC: beq         $v0, $zero, L_80131BD4
    if (ctx->r2 == 0) {
        // 0x80131BC0: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80131BD4;
    }
    // 0x80131BC0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80131BC4: jal         0x800269C0
    // 0x80131BC8: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80131BC8: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_2:
    // 0x80131BCC: b           L_80131C5C
    // 0x80131BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80131C5C;
    // 0x80131BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80131BD4:
    // 0x80131BD4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80131BD8: jal         0x800E9248
    // 0x80131BDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_3;
    // 0x80131BDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80131BE0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80131BE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131BE8: addiu       $v0, $v0, -0x7AA8
    ctx->r2 = ADD32(ctx->r2, -0X7AA8);
    // 0x80131BEC: addiu       $v1, $zero, 0xB8
    ctx->r3 = ADD32(0, 0XB8);
    // 0x80131BF0: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
L_80131BF4:
    // 0x80131BF4: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131BFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80131C00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80131C04: mflo        $t0
    ctx->r8 = lo;
    // 0x80131C08: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // 0x80131C0C: jal         0x80134A4C
    // 0x80131C10: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
    mnPlayers1PTrainingUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_4;
    // 0x80131C10: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
    after_4:
    // 0x80131C14: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80131C18: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x80131C1C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80131C20: sw          $t3, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r11;
    // 0x80131C24: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80131C28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80131C2C: jal         0x80133A90
    // 0x80131C30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_5;
    // 0x80131C30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x80131C34: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80131C38: sw          $t4, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r12;
    // 0x80131C3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80131C40: sw          $t5, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r13;
    // 0x80131C44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80131C48: jal         0x801341B0
    // 0x80131C4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PTrainingAnnounceFighter(rdram, ctx);
        goto after_6;
    // 0x80131C4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80131C50: jal         0x8013405C
    // 0x80131C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PTrainingMakePortraitFlash(rdram, ctx);
        goto after_7;
    // 0x80131C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80131C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80131C5C:
    // 0x80131C5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131C60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131C68: jr          $ra
    // 0x80131C6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131C6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void efManagerDustLightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEFE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FEFE4: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x800FEFE8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800FEFEC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800FEFF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FEFF4: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800FEFF8: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x800FEFFC: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FF000: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FF004: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FF008: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x800FF00C: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x800FF010: beq         $a1, $zero, L_800FF040
    if (ctx->r5 == 0) {
        // 0x800FF014: nop
    
            goto L_800FF040;
    }
    // 0x800FF014: nop

    // 0x800FF018: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800FF01C: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800FF020: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FF024: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800FF028: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FF02C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800FF030: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x800FF034: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FF038: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x800FF03C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
L_800FF040:
    // 0x800FF040: jr          $ra
    // 0x800FF044: nop

    return;
    // 0x800FF044: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156BD8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156BDC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156BE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80156BE4: lw          $v1, 0xADC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XADC);
    // 0x80156BE8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80156BEC: beq         $v1, $zero, L_80156C04
    if (ctx->r3 == 0) {
        // 0x80156BF0: nop
    
            goto L_80156C04;
    }
    // 0x80156BF0: nop

    // 0x80156BF4: beq         $v1, $at, L_80156C04
    if (ctx->r3 == ctx->r1) {
        // 0x80156BF8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80156C04;
    }
    // 0x80156BF8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80156BFC: bne         $v1, $at, L_80156C0C
    if (ctx->r3 != ctx->r1) {
        // 0x80156C00: addiu       $a1, $zero, 0xE9
        ctx->r5 = ADD32(0, 0XE9);
            goto L_80156C0C;
    }
    // 0x80156C00: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
L_80156C04:
    // 0x80156C04: b           L_80156C0C
    // 0x80156C08: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
        goto L_80156C0C;
    // 0x80156C08: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
L_80156C0C:
    // 0x80156C0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156C10: jal         0x800E6F24
    // 0x80156C14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156C14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80156C18: jal         0x800E0830
    // 0x80156C1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80156C1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80156C20: jal         0x80156BB8
    // 0x80156C24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyMarioSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156C24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156C30: jr          $ra
    // 0x80156C34: nop

    return;
    // 0x80156C34: nop

;}
RECOMP_FUNC void ftKirbySpecialNGotoSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161E9C: jal         0x80161E3C
    // 0x80161EA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftKirbySpecialNSetCatchParams(rdram, ctx);
        goto after_0;
    // 0x80161EA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80161EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80161EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161EAC: jr          $ra
    // 0x80161EB0: nop

    return;
    // 0x80161EB0: nop

;}
RECOMP_FUNC void func_ovl8_80373750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373758: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037375C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80373760: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80373764: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80373768: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8037376C: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80373770: lh          $t6, 0x40($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X40);
    // 0x80373774: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80373778: jalr        $t9
    // 0x8037377C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037377C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80373780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373788: jr          $ra
    // 0x8037378C: nop

    return;
    // 0x8037378C: nop

;}
RECOMP_FUNC void mvOpeningFoxMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC0C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC14: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC18: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC1C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC20: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC24: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC30: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC34: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC38: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC3C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC40: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC44: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC48: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC4C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC58: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC5C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC64: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC68: jal         0x8000B93C
    // 0x8018DC6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC70: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC74: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC78: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC80: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DC84: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DC88: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC8C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC90: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DC94: jal         0x80007080
    // 0x8018DC98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DCA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCA4: lwc1        $f6, -0x1E1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E1C);
    // 0x8018DCA8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DCAC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DCB0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DCB4: lw          $t4, -0x1BEC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1BEC);
    // 0x8018DCB8: addiu       $t5, $t5, 0x90
    ctx->r13 = ADD32(ctx->r13, 0X90);
    // 0x8018DCBC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCC0: jal         0x8000FA3C
    // 0x8018DCC4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCC4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCC8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCCC: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCD8: jal         0x80008188
    // 0x8018DCDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DCDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DCE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DCE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DCE8: jr          $ra
    // 0x8018DCEC: nop

    return;
    // 0x8018DCEC: nop

;}
RECOMP_FUNC void mnPlayersVSMakeHandicapLevelCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138CAC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80138CB0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80138CB4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80138CB8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80138CBC: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80138CC0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80138CC4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80138CC8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80138CCC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138CD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138CD4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138CD8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138CDC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80138CE0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80138CE4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80138CE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80138CEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80138CF0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80138CF4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80138CF8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80138CFC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80138D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138D04: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80138D08: jal         0x8000B93C
    // 0x80138D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80138D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80138D10: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80138D14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80138D18: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80138D1C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138D20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138D24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80138D28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80138D2C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80138D30: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80138D34: jal         0x80007080
    // 0x80138D38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80138D38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80138D3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80138D40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80138D44: jr          $ra
    // 0x80138D48: nop

    return;
    // 0x80138D48: nop

;}
RECOMP_FUNC void lbCommonSetupCustomTreeDObjsWithMObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9050: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800C9054: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C9058: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C905C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C9060: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C9064: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800C9068: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800C906C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C9070: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C9074: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C9078: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C907C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C9080: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C9084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9088: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800C908C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800C9090: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800C9094: addiu       $v0, $sp, 0x64
    ctx->r2 = ADD32(ctx->r29, 0X64);
    // 0x800C9098: addiu       $v1, $sp, 0xA4
    ctx->r3 = ADD32(ctx->r29, 0XA4);
L_800C909C:
    // 0x800C909C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C90A0: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800C90A4: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x800C90A8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800C90AC: bne         $v0, $v1, L_800C909C
    if (ctx->r2 != ctx->r3) {
        // 0x800C90B0: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_800C909C;
    }
    // 0x800C90B0: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800C90B4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C90B8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C90BC: lbu         $fp, 0xCB($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0XCB);
    // 0x800C90C0: beq         $v0, $at, L_800C91F8
    if (ctx->r2 == ctx->r1) {
        // 0x800C90C4: lbu         $s7, 0xC7($sp)
        ctx->r23 = MEM_BU(ctx->r29, 0XC7);
            goto L_800C91F8;
    }
    // 0x800C90C4: lbu         $s7, 0xC7($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0XC7);
    // 0x800C90C8: lbu         $s6, 0xC3($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0XC3);
    // 0x800C90CC: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_800C90D0:
    // 0x800C90D0: beq         $v1, $zero, L_800C90F8
    if (ctx->r3 == 0) {
        // 0x800C90D4: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800C90F8;
    }
    // 0x800C90D4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C90D8: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x800C90DC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800C90E0: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x800C90E4: jal         0x800093F4
    // 0x800C90E8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x800C90E8: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_0:
    // 0x800C90EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800C90F0: b           L_800C910C
    // 0x800C90F4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800C910C;
    // 0x800C90F4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800C90F8:
    // 0x800C90F8: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800C90FC: jal         0x800093F4
    // 0x800C9100: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_1;
    // 0x800C9100: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_1:
    // 0x800C9104: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800C9108: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800C910C:
    // 0x800C910C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800C9110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9114: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x800C9118: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800C911C: beq         $t9, $zero, L_800C9148
    if (ctx->r25 == 0) {
        // 0x800C9120: andi        $a2, $s7, 0xFF
        ctx->r6 = ctx->r23 & 0XFF;
            goto L_800C9148;
    }
    // 0x800C9120: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    // 0x800C9124: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800C9128: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C912C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C9130: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x800C9134: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    // 0x800C9138: jal         0x8000F364
    // 0x800C913C: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x800C913C: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    after_2:
    // 0x800C9140: b           L_800C9154
    // 0x800C9144: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
        goto L_800C9154;
    // 0x800C9144: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
L_800C9148:
    // 0x800C9148: jal         0x8000F2FC
    // 0x800C914C: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_3;
    // 0x800C914C: andi        $a3, $fp, 0xFF
    ctx->r7 = ctx->r30 & 0XFF;
    after_3:
    // 0x800C9150: lw          $t2, 0x8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8);
L_800C9154:
    // 0x800C9154: sw          $t2, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r10;
    // 0x800C9158: lw          $t1, 0xC($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XC);
    // 0x800C915C: sw          $t1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r9;
    // 0x800C9160: lw          $t2, 0x10($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X10);
    // 0x800C9164: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
    // 0x800C9168: lw          $t4, 0x14($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X14);
    // 0x800C916C: sw          $t4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r12;
    // 0x800C9170: lw          $t3, 0x18($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X18);
    // 0x800C9174: sw          $t3, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r11;
    // 0x800C9178: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x800C917C: sw          $t4, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r12;
    // 0x800C9180: lw          $t6, 0x20($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X20);
    // 0x800C9184: sw          $t6, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r14;
    // 0x800C9188: lw          $t5, 0x24($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X24);
    // 0x800C918C: sw          $t5, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r13;
    // 0x800C9190: lw          $t6, 0x28($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X28);
    // 0x800C9194: beq         $s4, $zero, L_800C91D4
    if (ctx->r20 == 0) {
        // 0x800C9198: sw          $t6, 0x48($s2)
        MEM_W(0X48, ctx->r18) = ctx->r14;
            goto L_800C91D4;
    }
    // 0x800C9198: sw          $t6, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r14;
    // 0x800C919C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C91A0: beql        $v0, $zero, L_800C91D4
    if (ctx->r2 == 0) {
        // 0x800C91A4: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800C91D4;
    }
    goto skip_0;
    // 0x800C91A4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_0:
    // 0x800C91A8: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x800C91AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C91B0: beq         $s1, $zero, L_800C91D0
    if (ctx->r17 == 0) {
        // 0x800C91B4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C91D0;
    }
    // 0x800C91B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C91B8:
    // 0x800C91B8: jal         0x800090DC
    // 0x800C91BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_4;
    // 0x800C91BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800C91C0: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x800C91C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C91C8: bnel        $s1, $zero, L_800C91B8
    if (ctx->r17 != 0) {
        // 0x800C91CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C91B8;
    }
    goto skip_1;
    // 0x800C91CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_800C91D0:
    // 0x800C91D0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_800C91D4:
    // 0x800C91D4: beql        $s5, $zero, L_800C91E8
    if (ctx->r21 == 0) {
        // 0x800C91D8: lw          $v0, 0x2C($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X2C);
            goto L_800C91E8;
    }
    goto skip_2;
    // 0x800C91D8: lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2C);
    skip_2:
    // 0x800C91DC: sw          $s2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r18;
    // 0x800C91E0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800C91E4: lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2C);
L_800C91E8:
    // 0x800C91E8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C91EC: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x800C91F0: bnel        $v0, $at, L_800C90D0
    if (ctx->r2 != ctx->r1) {
        // 0x800C91F4: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_800C90D0;
    }
    goto skip_3;
    // 0x800C91F4: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_3:
L_800C91F8:
    // 0x800C91F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C91FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9200: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C9204: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C9208: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C920C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C9210: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C9214: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C9218: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C921C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C9220: jr          $ra
    // 0x800C9224: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800C9224: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void mnVSItemSwitchUpdateOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132A9C: bne         $a0, $zero, L_80132ACC
    if (ctx->r4 != 0) {
        // 0x80132AA0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80132ACC;
    }
    // 0x80132AA0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80132AA4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80132AA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132AAC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80132AB0: lw          $a0, 0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33E0);
    // 0x80132AB4: jal         0x80009A84
    // 0x80132AB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132AB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80132ABC: jal         0x80132224
    // 0x80132AC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    mnVSItemSwitchMakeAppearance(rdram, ctx);
        goto after_1;
    // 0x80132AC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80132AC4: b           L_80132AE4
    // 0x80132AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132AE4;
    // 0x80132AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132ACC:
    // 0x80132ACC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80132AD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132AD4: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80132AD8: jal         0x80131B24
    // 0x80132ADC: lw          $a0, 0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33E0);
    mnVSItemSwitchSetToggleSpriteColors(rdram, ctx);
        goto after_2;
    // 0x80132ADC: lw          $a0, 0x33E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33E0);
    after_2:
    // 0x80132AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132AE4:
    // 0x80132AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132AE8: jr          $ra
    // 0x80132AEC: nop

    return;
    // 0x80132AEC: nop

;}
RECOMP_FUNC void mnScreenAdjustFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2850
    ctx->r24 = ADD32(ctx->r24, 0X2850);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void itPowerBlockMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C1E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8017C1E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8017C1EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C1F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017C1F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017C1F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C1FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C200: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8017C204: addiu       $a1, $a1, -0x5830
    ctx->r5 = ADD32(ctx->r5, -0X5830);
    // 0x8017C208: jal         0x8016E174
    // 0x8017C20C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017C20C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017C210: beq         $v0, $zero, L_8017C224
    if (ctx->r2 == 0) {
        // 0x8017C214: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8017C224;
    }
    // 0x8017C214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8017C218: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017C21C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017C220: sb          $t7, 0x244($v1)
    MEM_B(0X244, ctx->r3) = ctx->r15;
L_8017C224:
    // 0x8017C224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C22C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8017C230: jr          $ra
    // 0x8017C234: nop

    return;
    // 0x8017C234: nop

;}
RECOMP_FUNC void func_ovl8_80374C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374C34: beq         $a0, $zero, L_80374C54
    if (ctx->r4 == 0) {
        // 0x80374C38: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80374C54;
    }
    // 0x80374C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374C3C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374C40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80374C44: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80374C48: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80374C4C: jalr        $t9
    // 0x80374C50: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374C50: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
L_80374C54:
    // 0x80374C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374C5C: jr          $ra
    // 0x80374C60: nop

    return;
    // 0x80374C60: nop

;}
RECOMP_FUNC void ftCommonTurnRunProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F1C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F1C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F1C8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013F1CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013F1D0: jal         0x8013F598
    // 0x8013F1D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonKneeBendCheckInterruptRun(rdram, ctx);
        goto after_0;
    // 0x8013F1D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013F1D8: bne         $v0, $zero, L_8013F1F8
    if (ctx->r2 != 0) {
        // 0x8013F1DC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8013F1F8;
    }
    // 0x8013F1DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013F1E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F1E4: lw          $t8, 0x184($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X184);
    // 0x8013F1E8: beql        $t8, $zero, L_8013F1FC
    if (ctx->r24 == 0) {
        // 0x8013F1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F1FC;
    }
    goto skip_0;
    // 0x8013F1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013F1F0: jal         0x8013F0EC
    // 0x8013F1F4: nop

    ftCommonRunBrakeCheckInterruptTurnRun(rdram, ctx);
        goto after_1;
    // 0x8013F1F4: nop

    after_1:
L_8013F1F8:
    // 0x8013F1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F1FC:
    // 0x8013F1FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F200: jr          $ra
    // 0x8013F204: nop

    return;
    // 0x8013F204: nop

;}
RECOMP_FUNC void mnPlayersVSUpdatePuckDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136038: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013603C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136044: addiu       $t6, $t6, -0x4810
    ctx->r14 = ADD32(ctx->r14, -0X4810);
    // 0x80136048: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013604C: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80136050: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80136054: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80136058: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013605C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80136060: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80136064: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80136068: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013606C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80136070: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136074: addiu       $t0, $t0, -0x4578
    ctx->r8 = ADD32(ctx->r8, -0X4578);
    // 0x80136078: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013607C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80136080: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    // 0x80136084: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
    // 0x80136088: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013608C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80136090: bne         $t1, $zero, L_801360B0
    if (ctx->r9 != 0) {
        // 0x80136094: sw          $t7, 0xC($a3)
        MEM_W(0XC, ctx->r7) = ctx->r15;
            goto L_801360B0;
    }
    // 0x80136094: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x80136098: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x8013609C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801360A0: bnel        $t2, $zero, L_801360B4
    if (ctx->r10 != 0) {
        // 0x801360A4: sw          $zero, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = 0;
            goto L_801360B4;
    }
    goto skip_0;
    // 0x801360A4: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    skip_0:
    // 0x801360A8: b           L_801360B4
    // 0x801360AC: sw          $t3, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r11;
        goto L_801360B4;
    // 0x801360AC: sw          $t3, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r11;
L_801360B0:
    // 0x801360B0: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_801360B4:
    // 0x801360B4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801360B8: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x801360BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801360C0: beq         $v1, $zero, L_801360E4
    if (ctx->r3 == 0) {
        // 0x801360C4: addu        $t5, $a3, $t4
        ctx->r13 = ADD32(ctx->r7, ctx->r12);
            goto L_801360E4;
    }
    // 0x801360C4: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x801360C8: beq         $v1, $at, L_801360F8
    if (ctx->r3 == ctx->r1) {
        // 0x801360CC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_801360F8;
    }
    // 0x801360CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801360D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801360D4: beql        $v1, $at, L_80136114
    if (ctx->r3 == ctx->r1) {
        // 0x801360D8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80136114;
    }
    goto skip_1;
    // 0x801360D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_1:
    // 0x801360DC: b           L_8013611C
    // 0x801360E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013611C;
    // 0x801360E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801360E4:
    // 0x801360E4: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x801360E8: jal         0x801386E4
    // 0x801360EC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    mnPlayersVSUpdatePuck(rdram, ctx);
        goto after_0;
    // 0x801360EC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_0:
    // 0x801360F0: b           L_8013611C
    // 0x801360F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013611C;
    // 0x801360F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801360F8:
    // 0x801360F8: jal         0x801386E4
    // 0x801360FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mnPlayersVSUpdatePuck(rdram, ctx);
        goto after_1;
    // 0x801360FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80136100: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80136104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136108: b           L_80136118
    // 0x8013610C: sw          $t6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r14;
        goto L_80136118;
    // 0x8013610C: sw          $t6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r14;
    // 0x80136110: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80136114:
    // 0x80136114: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
L_80136118:
    // 0x80136118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013611C:
    // 0x8013611C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80136120: jr          $ra
    // 0x80136124: nop

    return;
    // 0x80136124: nop

;}
RECOMP_FUNC void mnPlayersVSCheckTeamSelectInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135554: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80135558: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8013555C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80135560: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80135564: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135568: addiu       $t6, $v1, 0x22
    ctx->r14 = ADD32(ctx->r3, 0X22);
    // 0x8013556C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80135570: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135578: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013557C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135580: addiu       $t7, $v1, 0x3A
    ctx->r15 = ADD32(ctx->r3, 0X3A);
    // 0x80135584: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135588: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013558C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135590: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80135594: nop

    // 0x80135598: bc1f        L_801355C4
    if (!c1cs) {
        // 0x8013559C: nop
    
            goto L_801355C4;
    }
    // 0x8013559C: nop

    // 0x801355A0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801355A4: nop

    // 0x801355A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801355AC: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801355B0: nop

    // 0x801355B4: bc1f        L_801355C4
    if (!c1cs) {
        // 0x801355B8: nop
    
            goto L_801355C4;
    }
    // 0x801355B8: nop

    // 0x801355BC: b           L_801355C4
    // 0x801355C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801355C4;
    // 0x801355C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801355C4:
    // 0x801355C4: beql        $v1, $zero, L_8013562C
    if (ctx->r3 == 0) {
        // 0x801355C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013562C;
    }
    goto skip_0;
    // 0x801355C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801355CC: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801355D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801355D4: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x801355D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801355DC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801355E0: lui         $at, 0x430D
    ctx->r1 = S32(0X430D << 16);
    // 0x801355E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801355E8: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801355EC: nop

    // 0x801355F0: bc1f        L_80135618
    if (!c1cs) {
        // 0x801355F4: nop
    
            goto L_80135618;
    }
    // 0x801355F4: nop

    // 0x801355F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801355FC: nop

    // 0x80135600: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135604: nop

    // 0x80135608: bc1f        L_80135618
    if (!c1cs) {
        // 0x8013560C: nop
    
            goto L_80135618;
    }
    // 0x8013560C: nop

    // 0x80135610: b           L_80135618
    // 0x80135614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135618;
    // 0x80135614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135618:
    // 0x80135618: beql        $v1, $zero, L_8013562C
    if (ctx->r3 == 0) {
        // 0x8013561C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013562C;
    }
    goto skip_1;
    // 0x8013561C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80135620: jr          $ra
    // 0x80135624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80135628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013562C:
    // 0x8013562C: jr          $ra
    // 0x80135630: nop

    return;
    // 0x80135630: nop

;}
RECOMP_FUNC void mnVSResultsGetBestManExcept(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137E34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80137E38: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80137E3C: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x80137E40: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80137E44: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x80137E48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80137E4C:
    // 0x80137E4C: lbu         $t6, 0x22($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X22);
    // 0x80137E50: bnel        $t6, $zero, L_80137E64
    if (ctx->r14 != 0) {
        // 0x80137E54: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_80137E64;
    }
    goto skip_0;
    // 0x80137E54: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_0:
    // 0x80137E58: b           L_80137E64
    // 0x80137E5C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80137E64;
    // 0x80137E5C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80137E60: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80137E64:
    // 0x80137E64: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80137E68: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80137E6C: bne         $at, $zero, L_80137E4C
    if (ctx->r1 != 0) {
        // 0x80137E70: addiu       $v0, $v0, 0x74
        ctx->r2 = ADD32(ctx->r2, 0X74);
            goto L_80137E4C;
    }
    // 0x80137E70: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
    // 0x80137E74: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80137E78: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80137E7C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80137E80: beq         $at, $zero, L_80137FF0
    if (ctx->r1 == 0) {
        // 0x80137E84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80137FF0;
    }
    // 0x80137E84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80137E88: subu        $t0, $t2, $v0
    ctx->r8 = SUB32(ctx->r10, ctx->r2);
    // 0x80137E8C: andi        $t0, $t0, 0x3
    ctx->r8 = ctx->r8 & 0X3;
    // 0x80137E90: beq         $t0, $zero, L_80137EF4
    if (ctx->r8 == 0) {
        // 0x80137E94: addu        $a3, $t0, $v0
        ctx->r7 = ADD32(ctx->r8, ctx->r2);
            goto L_80137EF4;
    }
    // 0x80137E94: addu        $a3, $t0, $v0
    ctx->r7 = ADD32(ctx->r8, ctx->r2);
    // 0x80137E98: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80137E9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137EA0: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x80137EA4: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x80137EA8: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
L_80137EAC:
    // 0x80137EAC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80137EB0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80137EB4: beql        $t8, $zero, L_80137EE8
    if (ctx->r24 == 0) {
        // 0x80137EB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80137EE8;
    }
    goto skip_1;
    // 0x80137EB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80137EBC: beq         $a0, $v1, L_80137EE4
    if (ctx->r4 == ctx->r3) {
        // 0x80137EC0: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80137EE4;
    }
    // 0x80137EC0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80137EC4: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x80137EC8: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    // 0x80137ECC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80137ED0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80137ED4: bnel        $t4, $t6, L_80137EE8
    if (ctx->r12 != ctx->r14) {
        // 0x80137ED8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80137EE8;
    }
    goto skip_2;
    // 0x80137ED8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80137EDC: b           L_80138128
    // 0x80137EE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80138128;
    // 0x80137EE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80137EE4:
    // 0x80137EE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80137EE8:
    // 0x80137EE8: bne         $a3, $v1, L_80137EAC
    if (ctx->r7 != ctx->r3) {
        // 0x80137EEC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80137EAC;
    }
    // 0x80137EEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80137EF0: beq         $v1, $t2, L_80137FF0
    if (ctx->r3 == ctx->r10) {
        // 0x80137EF4: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80137FF0;
    }
L_80137EF4:
    // 0x80137EF4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137EF8: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80137EFC: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x80137F00: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x80137F04: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
L_80137F08:
    // 0x80137F08: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80137F0C: beql        $t8, $zero, L_80137F40
    if (ctx->r24 == 0) {
        // 0x80137F10: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_80137F40;
    }
    goto skip_3;
    // 0x80137F10: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_3:
    // 0x80137F14: beq         $a0, $v1, L_80137F3C
    if (ctx->r4 == ctx->r3) {
        // 0x80137F18: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80137F3C;
    }
    // 0x80137F18: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80137F1C: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x80137F20: addu        $t4, $v0, $a1
    ctx->r12 = ADD32(ctx->r2, ctx->r5);
    // 0x80137F24: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80137F28: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80137F2C: bnel        $t5, $t6, L_80137F40
    if (ctx->r13 != ctx->r14) {
        // 0x80137F30: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_80137F40;
    }
    goto skip_4;
    // 0x80137F30: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_4:
    // 0x80137F34: b           L_80138128
    // 0x80137F38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80138128;
    // 0x80137F38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80137F3C:
    // 0x80137F3C: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
L_80137F40:
    // 0x80137F40: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x80137F44: beql        $t7, $zero, L_80137F78
    if (ctx->r15 == 0) {
        // 0x80137F48: lw          $t6, 0x8($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X8);
            goto L_80137F78;
    }
    goto skip_5;
    // 0x80137F48: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    skip_5:
    // 0x80137F4C: beq         $a0, $a3, L_80137F74
    if (ctx->r4 == ctx->r7) {
        // 0x80137F50: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_80137F74;
    }
    // 0x80137F50: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80137F54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80137F58: addu        $t4, $v0, $a1
    ctx->r12 = ADD32(ctx->r2, ctx->r5);
    // 0x80137F5C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80137F60: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80137F64: bnel        $t3, $t5, L_80137F78
    if (ctx->r11 != ctx->r13) {
        // 0x80137F68: lw          $t6, 0x8($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X8);
            goto L_80137F78;
    }
    goto skip_6;
    // 0x80137F68: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    skip_6:
    // 0x80137F6C: b           L_80138128
    // 0x80137F70: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80138128;
    // 0x80137F70: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80137F74:
    // 0x80137F74: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
L_80137F78:
    // 0x80137F78: addiu       $a3, $v1, 0x2
    ctx->r7 = ADD32(ctx->r3, 0X2);
    // 0x80137F7C: beql        $t6, $zero, L_80137FB0
    if (ctx->r14 == 0) {
        // 0x80137F80: lw          $t5, 0xC($a2)
        ctx->r13 = MEM_W(ctx->r6, 0XC);
            goto L_80137FB0;
    }
    goto skip_7;
    // 0x80137F80: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    skip_7:
    // 0x80137F84: beq         $a0, $a3, L_80137FAC
    if (ctx->r4 == ctx->r7) {
        // 0x80137F88: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80137FAC;
    }
    // 0x80137F88: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80137F8C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80137F90: addu        $t4, $v0, $a1
    ctx->r12 = ADD32(ctx->r2, ctx->r5);
    // 0x80137F94: lw          $t3, 0x8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X8);
    // 0x80137F98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80137F9C: bnel        $t9, $t3, L_80137FB0
    if (ctx->r25 != ctx->r11) {
        // 0x80137FA0: lw          $t5, 0xC($a2)
        ctx->r13 = MEM_W(ctx->r6, 0XC);
            goto L_80137FB0;
    }
    goto skip_8;
    // 0x80137FA0: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    skip_8:
    // 0x80137FA4: b           L_80138128
    // 0x80137FA8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80138128;
    // 0x80137FA8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80137FAC:
    // 0x80137FAC: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
L_80137FB0:
    // 0x80137FB0: addiu       $a3, $v1, 0x3
    ctx->r7 = ADD32(ctx->r3, 0X3);
    // 0x80137FB4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80137FB8: beq         $t5, $zero, L_80137FE8
    if (ctx->r13 == 0) {
        // 0x80137FBC: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80137FE8;
    }
    // 0x80137FBC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80137FC0: beq         $a0, $a3, L_80137FE8
    if (ctx->r4 == ctx->r7) {
        // 0x80137FC4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80137FE8;
    }
    // 0x80137FC4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137FC8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80137FCC: addu        $t4, $v0, $a1
    ctx->r12 = ADD32(ctx->r2, ctx->r5);
    // 0x80137FD0: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x80137FD4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80137FD8: bne         $t8, $t9, L_80137FE8
    if (ctx->r24 != ctx->r25) {
        // 0x80137FDC: nop
    
            goto L_80137FE8;
    }
    // 0x80137FDC: nop

    // 0x80137FE0: b           L_80138128
    // 0x80137FE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80138128;
    // 0x80137FE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80137FE8:
    // 0x80137FE8: bne         $v1, $t2, L_80137F08
    if (ctx->r3 != ctx->r10) {
        // 0x80137FEC: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80137F08;
    }
    // 0x80137FEC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_80137FF0:
    // 0x80137FF0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137FF4: addiu       $v0, $v0, -0x6460
    ctx->r2 = ADD32(ctx->r2, -0X6460);
    // 0x80137FF8: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    // 0x80137FFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80138000: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
L_80138004:
    // 0x80138004: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80138008: beql        $t3, $zero, L_80138020
    if (ctx->r11 == 0) {
        // 0x8013800C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80138020;
    }
    goto skip_9;
    // 0x8013800C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_9:
    // 0x80138010: beql        $a0, $v1, L_80138020
    if (ctx->r4 == ctx->r3) {
        // 0x80138014: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80138020;
    }
    goto skip_10;
    // 0x80138014: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_10:
    // 0x80138018: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8013801C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80138020:
    // 0x80138020: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80138024: bne         $at, $zero, L_80138004
    if (ctx->r1 != 0) {
        // 0x80138028: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80138004;
    }
    // 0x80138028: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8013802C: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x80138030: bne         $a1, $at, L_80138040
    if (ctx->r5 != ctx->r1) {
        // 0x80138034: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_80138040;
    }
    // 0x80138034: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80138038: b           L_80138128
    // 0x8013803C: addiu       $v0, $zero, 0x29A
    ctx->r2 = ADD32(0, 0X29A);
        goto L_80138128;
    // 0x8013803C: addiu       $v0, $zero, 0x29A
    ctx->r2 = ADD32(0, 0X29A);
L_80138040:
    // 0x80138040: beq         $t5, $zero, L_80138078
    if (ctx->r13 == 0) {
        // 0x80138044: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80138078;
    }
    // 0x80138044: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80138048: beq         $a0, $zero, L_80138078
    if (ctx->r4 == 0) {
        // 0x8013804C: nop
    
            goto L_80138078;
    }
    // 0x8013804C: nop

    // 0x80138050: beq         $a1, $zero, L_80138078
    if (ctx->r5 == 0) {
        // 0x80138054: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80138078;
    }
    // 0x80138054: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80138058: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8013805C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80138060: lw          $t8, -0x6460($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6460);
    // 0x80138064: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80138068: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8013806C: beq         $at, $zero, L_80138078
    if (ctx->r1 == 0) {
        // 0x80138070: nop
    
            goto L_80138078;
    }
    // 0x80138070: nop

    // 0x80138074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80138078:
    // 0x80138078: beq         $t9, $zero, L_801380B0
    if (ctx->r25 == 0) {
        // 0x8013807C: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_801380B0;
    }
    // 0x8013807C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80138080: beq         $a0, $t1, L_801380B0
    if (ctx->r4 == ctx->r9) {
        // 0x80138084: nop
    
            goto L_801380B0;
    }
    // 0x80138084: nop

    // 0x80138088: beq         $a1, $t1, L_801380B0
    if (ctx->r5 == ctx->r9) {
        // 0x8013808C: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_801380B0;
    }
    // 0x8013808C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80138090: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x80138094: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138098: lw          $t7, -0x645C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X645C);
    // 0x8013809C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801380A0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801380A4: beq         $at, $zero, L_801380B0
    if (ctx->r1 == 0) {
        // 0x801380A8: nop
    
            goto L_801380B0;
    }
    // 0x801380A8: nop

    // 0x801380AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801380B0:
    // 0x801380B0: beq         $t4, $zero, L_801380EC
    if (ctx->r12 == 0) {
        // 0x801380B4: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_801380EC;
    }
    // 0x801380B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801380B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801380BC: beq         $a0, $v1, L_801380EC
    if (ctx->r4 == ctx->r3) {
        // 0x801380C0: nop
    
            goto L_801380EC;
    }
    // 0x801380C0: nop

    // 0x801380C4: beq         $a1, $v1, L_801380EC
    if (ctx->r5 == ctx->r3) {
        // 0x801380C8: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_801380EC;
    }
    // 0x801380C8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801380CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x801380D0: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801380D4: lw          $t5, -0x6458($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6458);
    // 0x801380D8: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x801380DC: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801380E0: beq         $at, $zero, L_801380EC
    if (ctx->r1 == 0) {
        // 0x801380E4: nop
    
            goto L_801380EC;
    }
    // 0x801380E4: nop

    // 0x801380E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_801380EC:
    // 0x801380EC: beq         $t6, $zero, L_80138124
    if (ctx->r14 == 0) {
        // 0x801380F0: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80138124;
    }
    // 0x801380F0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x801380F4: beql        $a0, $v1, L_80138128
    if (ctx->r4 == ctx->r3) {
        // 0x801380F8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80138128;
    }
    goto skip_11;
    // 0x801380F8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_11:
    // 0x801380FC: beq         $a1, $v1, L_80138124
    if (ctx->r5 == ctx->r3) {
        // 0x80138100: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_80138124;
    }
    // 0x80138100: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80138104: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x80138108: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013810C: lw          $t9, -0x6454($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6454);
    // 0x80138110: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80138114: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80138118: beql        $at, $zero, L_80138128
    if (ctx->r1 == 0) {
        // 0x8013811C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80138128;
    }
    goto skip_12;
    // 0x8013811C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_12:
    // 0x80138120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80138124:
    // 0x80138124: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80138128:
    // 0x80138128: jr          $ra
    // 0x8013812C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013812C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void grSectorArwingUpdatePatrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107CA8: jal         0x80106C28
    // 0x80107CAC: nop

    grSectorArwingDecideZNear(rdram, ctx);
        goto after_0;
    // 0x80107CAC: nop

    after_0:
    // 0x80107CB0: jal         0x80106DD8
    // 0x80107CB4: nop

    func_ovl2_80106DD8(rdram, ctx);
        goto after_1;
    // 0x80107CB4: nop

    after_1:
    // 0x80107CB8: jal         0x80107958
    // 0x80107CBC: nop

    func_ovl2_80107958(rdram, ctx);
        goto after_2;
    // 0x80107CBC: nop

    after_2:
    // 0x80107CC0: jal         0x80107B30
    // 0x80107CC4: nop

    func_ovl2_80107B30(rdram, ctx);
        goto after_3;
    // 0x80107CC4: nop

    after_3:
    // 0x80107CC8: jal         0x80107BA0
    // 0x80107CCC: nop

    grSectorArwingUpdateCollisions(rdram, ctx);
        goto after_4;
    // 0x80107CCC: nop

    after_4:
    // 0x80107CD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80107CD4: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80107CD8: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80107CDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107CE0: lwc1        $f4, 0xAF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAF8);
    // 0x80107CE4: lwc1        $f6, 0x74($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X74);
    // 0x80107CE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80107CEC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80107CF0: nop

    // 0x80107CF4: bc1fl       L_80107D38
    if (!c1cs) {
        // 0x80107CF8: lhu         $t1, 0x44($v1)
        ctx->r9 = MEM_HU(ctx->r3, 0X44);
            goto L_80107D38;
    }
    goto skip_0;
    // 0x80107CF8: lhu         $t1, 0x44($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X44);
    skip_0:
    // 0x80107CFC: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80107D00: addiu       $a0, $zero, 0x474
    ctx->r4 = ADD32(0, 0X474);
    // 0x80107D04: jal         0x80018994
    // 0x80107D08: sw          $t7, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r15;
    syUtilsRandIntRange(rdram, ctx);
        goto after_5;
    // 0x80107D08: sw          $t7, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->r15;
    after_5:
    // 0x80107D0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80107D10: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80107D14: addiu       $t9, $v0, 0x3C0
    ctx->r25 = ADD32(ctx->r2, 0X3C0);
    // 0x80107D18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80107D1C: sh          $t9, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r25;
    // 0x80107D20: sb          $t0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r8;
    // 0x80107D24: jal         0x800FC604
    // 0x80107D28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_6;
    // 0x80107D28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80107D2C: b           L_80107D44
    // 0x80107D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80107D44;
    // 0x80107D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107D34: lhu         $t1, 0x44($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X44);
L_80107D38:
    // 0x80107D38: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80107D3C: sh          $t2, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r10;
    // 0x80107D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80107D44:
    // 0x80107D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107D48: jr          $ra
    // 0x80107D4C: nop

    return;
    // 0x80107D4C: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePuckCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137308: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013730C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80137310: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80137314: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80137318: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8013731C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80137320: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80137324: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80137328: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013732C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80137330: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80137334: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80137338: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013733C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80137340: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80137344: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80137348: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013734C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80137350: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80137354: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80137358: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013735C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137360: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80137364: jal         0x8000B93C
    // 0x80137368: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80137368: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013736C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80137370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80137374: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80137378: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013737C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137380: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80137384: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80137388: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013738C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80137390: jal         0x80007080
    // 0x80137394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80137394: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80137398: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013739C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801373A0: jr          $ra
    // 0x801373A4: nop

    return;
    // 0x801373A4: nop

;}
RECOMP_FUNC void ftLinkSpecialAirLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016445C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164464: jal         0x801643D0
    // 0x80164468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftLinkSpecialLwMakeBomb(rdram, ctx);
        goto after_0;
    // 0x80164468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016446C: jal         0x800D94E8
    // 0x80164470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x80164470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80164474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016447C: jr          $ra
    // 0x80164480: nop

    return;
    // 0x80164480: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801578C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801578C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801578C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801578CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801578D0: jal         0x800DEEC8
    // 0x801578D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801578D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801578D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801578DC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801578E0: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x801578E4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801578E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801578EC: jal         0x800E6F24
    // 0x801578F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801578F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801578F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801578F8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801578FC: addiu       $t8, $t8, 0x77A0
    ctx->r24 = ADD32(ctx->r24, 0X77A0);
    // 0x80157900: jal         0x800D8EB8
    // 0x80157904: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80157904: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    after_2:
    // 0x80157908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015790C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157910: jr          $ra
    // 0x80157914: nop

    return;
    // 0x80157914: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CEC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80131CF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80131CF4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131CF8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80131CFC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80131D00: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x80131D04: addiu       $t6, $t6, -0x7970
    ctx->r14 = ADD32(ctx->r14, -0X7970);
    // 0x80131D08: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80131D0C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131D10: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80131D14: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80131D18: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80131D1C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80131D20: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80131D24: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80131D28: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80131D2C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80131D30: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131D34: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131D38: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131D3C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80131D40: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131D44: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80131D48:
    // 0x80131D48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D4C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131D50: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131D54: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131D58: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131D5C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131D60: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131D64: bne         $t6, $t0, L_80131D48
    if (ctx->r14 != ctx->r8) {
        // 0x80131D68: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131D48;
    }
    // 0x80131D68: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131D6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D70: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80131D74: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80131D78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131D7C: bgez        $s3, L_80131D88
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80131D80: lwc1        $f20, 0xA0($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_80131D88;
    }
    // 0x80131D80: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80131D84: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131D88:
    // 0x80131D88: div         $zero, $s3, $s6
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r22)));
    // 0x80131D8C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80131D90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80131D94: addiu       $s7, $s7, -0x6960
    ctx->r23 = ADD32(ctx->r23, -0X6960);
    // 0x80131D98: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80131D9C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80131DA0: lw          $t5, 0x24($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X24);
    // 0x80131DA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131DA8: bne         $s6, $zero, L_80131DB4
    if (ctx->r22 != 0) {
        // 0x80131DAC: nop
    
            goto L_80131DB4;
    }
    // 0x80131DAC: nop

    // 0x80131DB0: break       7
    do_break(2148736432);
L_80131DB4:
    // 0x80131DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131DB8: bne         $s6, $at, L_80131DCC
    if (ctx->r22 != ctx->r1) {
        // 0x80131DBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131DCC;
    }
    // 0x80131DBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131DC0: bne         $s3, $at, L_80131DCC
    if (ctx->r19 != ctx->r1) {
        // 0x80131DC4: nop
    
            goto L_80131DCC;
    }
    // 0x80131DC4: nop

    // 0x80131DC8: break       6
    do_break(2148736456);
L_80131DCC:
    // 0x80131DCC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80131DD0: jal         0x800CCFDC
    // 0x80131DD4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131DD4: nop

    after_0:
    // 0x80131DD8: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x80131DDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DE4: jal         0x80131BF8
    // 0x80131DE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayers1PGameSetDigitColors(rdram, ctx);
        goto after_1;
    // 0x80131DE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80131DEC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80131DF0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131DF4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80131DF8: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x80131DFC: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131E00: sub.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80131E04: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80131E08: beq         $s5, $zero, L_80131E1C
    if (ctx->r21 == 0) {
        // 0x80131E0C: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131E1C;
    }
    // 0x80131E0C: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131E10: lw          $s2, 0xAC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XAC);
    // 0x80131E14: b           L_80131E30
    // 0x80131E18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131E30;
    // 0x80131E18: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131E1C:
    // 0x80131E1C: lw          $s2, 0xAC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XAC);
    // 0x80131E20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131E24: jal         0x80131C40
    // 0x80131E28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameGetNumberDigitCount(rdram, ctx);
        goto after_2;
    // 0x80131E28: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80131E2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131E30:
    // 0x80131E30: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131E34: bne         $at, $zero, L_80131F20
    if (ctx->r1 != 0) {
        // 0x80131E38: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131F20;
    }
    // 0x80131E38: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80131E3C:
    // 0x80131E3C: jal         0x80131B58
    // 0x80131E40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_3;
    // 0x80131E40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80131E44: beq         $v0, $zero, L_80131E8C
    if (ctx->r2 == 0) {
        // 0x80131E48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131E8C;
    }
    // 0x80131E48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131E4C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80131E50: jal         0x80131B58
    // 0x80131E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80131E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80131E58: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80131E5C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E60: bne         $v0, $zero, L_80131E6C
    if (ctx->r2 != 0) {
        // 0x80131E64: nop
    
            goto L_80131E6C;
    }
    // 0x80131E64: nop

    // 0x80131E68: break       7
    do_break(2148736616);
L_80131E6C:
    // 0x80131E6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131E70: bne         $v0, $at, L_80131E84
    if (ctx->r2 != ctx->r1) {
        // 0x80131E74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131E84;
    }
    // 0x80131E74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131E78: bne         $s3, $at, L_80131E84
    if (ctx->r19 != ctx->r1) {
        // 0x80131E7C: nop
    
            goto L_80131E84;
    }
    // 0x80131E7C: nop

    // 0x80131E80: break       6
    do_break(2148736640);
L_80131E84:
    // 0x80131E84: b           L_80131E8C
    // 0x80131E88: nop

        goto L_80131E8C;
    // 0x80131E88: nop

L_80131E8C:
    // 0x80131E8C: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80131E90: mfhi        $t0
    ctx->r8 = hi;
    // 0x80131E94: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80131E98: addu        $t9, $sp, $t6
    ctx->r25 = ADD32(ctx->r29, ctx->r14);
    // 0x80131E9C: lw          $t9, 0x70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70);
    // 0x80131EA0: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x80131EA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131EA8: bne         $s6, $zero, L_80131EB4
    if (ctx->r22 != 0) {
        // 0x80131EAC: nop
    
            goto L_80131EB4;
    }
    // 0x80131EAC: nop

    // 0x80131EB0: break       7
    do_break(2148736688);
L_80131EB4:
    // 0x80131EB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131EB8: bne         $s6, $at, L_80131ECC
    if (ctx->r22 != ctx->r1) {
        // 0x80131EBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131ECC;
    }
    // 0x80131EBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131EC0: bne         $v1, $at, L_80131ECC
    if (ctx->r3 != ctx->r1) {
        // 0x80131EC4: nop
    
            goto L_80131ECC;
    }
    // 0x80131EC4: nop

    // 0x80131EC8: break       6
    do_break(2148736712);
L_80131ECC:
    // 0x80131ECC: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x80131ED0: jal         0x800CCFDC
    // 0x80131ED4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131ED4: nop

    after_5:
    // 0x80131ED8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EE0: jal         0x80131BF8
    // 0x80131EE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayers1PGameSetDigitColors(rdram, ctx);
        goto after_6;
    // 0x80131EE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80131EE8: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80131EEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131EF0: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131EF4: beq         $s5, $zero, L_80131F04
    if (ctx->r21 == 0) {
        // 0x80131EF8: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131F04;
    }
    // 0x80131EF8: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131EFC: b           L_80131F14
    // 0x80131F00: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F14;
    // 0x80131F00: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131F04:
    // 0x80131F04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131F08: jal         0x80131C40
    // 0x80131F0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameGetNumberDigitCount(rdram, ctx);
        goto after_7;
    // 0x80131F0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80131F10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F14:
    // 0x80131F14: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131F18: bnel        $at, $zero, L_80131E3C
    if (ctx->r1 != 0) {
        // 0x80131F1C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131E3C;
    }
    goto skip_0;
    // 0x80131F1C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80131F20:
    // 0x80131F20: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80131F24: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131F28: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80131F2C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80131F30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131F34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80131F38: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80131F3C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F40: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80131F44: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80131F48: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80131F4C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F50: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80131F54: jr          $ra
    // 0x80131F58: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80131F58: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void lbRelocGetExternBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDC0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CDC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CDC14: jal         0x800CD620
    // 0x800CDC18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDC18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CDC1C: beq         $v0, $zero, L_800CDC2C
    if (ctx->r2 == 0) {
        // 0x800CDC20: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_800CDC2C;
    }
    // 0x800CDC20: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CDC24: b           L_800CDC7C
    // 0x800CDC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CDC7C;
    // 0x800CDC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CDC2C:
    // 0x800CDC2C: lw          $t6, 0x6348($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6348);
    // 0x800CDC30: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDC34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CDC38: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x800CDC3C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CDC40: jal         0x800CD814
    // 0x800CDC44: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    lbRelocReadDmaTableEntry(rdram, ctx);
        goto after_1;
    // 0x800CDC44: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x800CDC48: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800CDC4C: lw          $t9, 0x6334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6334);
    // 0x800CDC50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDC54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDC58: lhu         $a2, 0xA($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0XA);
    // 0x800CDC5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CDC60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800CDC64: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800CDC68: addu        $t0, $a1, $a2
    ctx->r8 = ADD32(ctx->r5, ctx->r6);
    // 0x800CDC6C: jal         0x800CD854
    // 0x800CDC70: sw          $t0, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r8;
    lbRelocLoadAndRelocFile(rdram, ctx);
        goto after_2;
    // 0x800CDC70: sw          $t0, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r8;
    after_2:
    // 0x800CDC74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDC78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CDC7C:
    // 0x800CDC7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CDC80: jr          $ra
    // 0x800CDC84: nop

    return;
    // 0x800CDC84: nop

;}
RECOMP_FUNC void ftMainUpdateAttackStatFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2910: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E2914: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E2918: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E291C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2920: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E2924: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E2928: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E292C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800E2930: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800E2934: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800E2938: jal         0x800F0BC4
    // 0x800E293C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    gmCollisionGetFighterAttacksPosition(rdram, ctx);
        goto after_0;
    // 0x800E293C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800E2940: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800E2944: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x800E2948: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800E294C: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x800E2950: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800E2954: beq         $at, $zero, L_800E29E0
    if (ctx->r1 == 0) {
        // 0x800E2958: lw          $a2, 0x48($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X48);
            goto L_800E29E0;
    }
    // 0x800E2958: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E295C: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E2960: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800E2964: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800E2968: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800E296C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800E2970: jal         0x800E26BC
    // 0x800E2974: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E2974: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800E2978: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E297C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800E2980: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E2984: jal         0x800E287C
    // 0x800E2988: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    ftMainSetHitRebound(rdram, ctx);
        goto after_2;
    // 0x800E2988: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x800E298C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800E2990: jal         0x80100BF0
    // 0x800E2994: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_3;
    // 0x800E2994: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x800E2998: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800E299C: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50E8);
    // 0x800E29A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E29A4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800E29A8: bnel        $t2, $at, L_800E29E4
    if (ctx->r10 != ctx->r1) {
        // 0x800E29AC: lw          $t9, 0xC($s1)
        ctx->r25 = MEM_W(ctx->r17, 0XC);
            goto L_800E29E4;
    }
    goto skip_0;
    // 0x800E29AC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x800E29B0: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x800E29B4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800E29B8: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800E29BC: bne         $at, $zero, L_800E29E0
    if (ctx->r1 != 0) {
        // 0x800E29C0: lui         $t4, 0x800A
        ctx->r12 = S32(0X800A << 16);
            goto L_800E29E0;
    }
    // 0x800E29C0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800E29C4: lbu         $t4, 0x4AE3($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AE3);
    // 0x800E29C8: lbu         $t7, 0xD($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0XD);
    // 0x800E29CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E29D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800E29D4: bnel        $t4, $t7, L_800E29E4
    if (ctx->r12 != ctx->r15) {
        // 0x800E29D8: lw          $t9, 0xC($s1)
        ctx->r25 = MEM_W(ctx->r17, 0XC);
            goto L_800E29E4;
    }
    goto skip_1;
    // 0x800E29D8: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    skip_1:
    // 0x800E29DC: sb          $t6, 0x36AC($at)
    MEM_B(0X36AC, ctx->r1) = ctx->r14;
L_800E29E0:
    // 0x800E29E0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
L_800E29E4:
    // 0x800E29E4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800E29E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800E29EC: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x800E29F0: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800E29F4: beq         $at, $zero, L_800E2A7C
    if (ctx->r1 == 0) {
        // 0x800E29F8: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_800E2A7C;
    }
    // 0x800E29F8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800E29FC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800E2A00: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800E2A04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E2A08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800E2A0C: jal         0x800E26BC
    // 0x800E2A10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_4;
    // 0x800E2A10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x800E2A14: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800E2A18: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E2A1C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800E2A20: jal         0x800E287C
    // 0x800E2A24: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    ftMainSetHitRebound(rdram, ctx);
        goto after_5;
    // 0x800E2A24: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x800E2A28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800E2A2C: jal         0x80100BF0
    // 0x800E2A30: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x800E2A30: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    after_6:
    // 0x800E2A34: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800E2A38: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x800E2A3C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E2A40: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800E2A44: bnel        $t3, $at, L_800E2A80
    if (ctx->r11 != ctx->r1) {
        // 0x800E2A48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E2A80;
    }
    goto skip_2;
    // 0x800E2A48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800E2A4C: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x800E2A50: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800E2A54: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x800E2A58: bne         $at, $zero, L_800E2A7C
    if (ctx->r1 != 0) {
        // 0x800E2A5C: lui         $t4, 0x800A
        ctx->r12 = S32(0X800A << 16);
            goto L_800E2A7C;
    }
    // 0x800E2A5C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800E2A60: lbu         $t4, 0x4AE3($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AE3);
    // 0x800E2A64: lbu         $t6, 0xD($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XD);
    // 0x800E2A68: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E2A6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800E2A70: bnel        $t4, $t6, L_800E2A80
    if (ctx->r12 != ctx->r14) {
        // 0x800E2A74: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E2A80;
    }
    goto skip_3;
    // 0x800E2A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800E2A78: sb          $t9, 0x36AC($at)
    MEM_B(0X36AC, ctx->r1) = ctx->r25;
L_800E2A7C:
    // 0x800E2A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E2A80:
    // 0x800E2A80: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2A84: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E2A88: jr          $ra
    // 0x800E2A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800E2A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itTaruBombMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018518C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80185190: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80185194: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80185198: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8018519C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801851A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801851A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801851A8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801851AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801851B0: addiu       $a1, $a1, -0x4A60
    ctx->r5 = ADD32(ctx->r5, -0X4A60);
    // 0x801851B4: jal         0x8016E174
    // 0x801851B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801851B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801851BC: beq         $v0, $zero, L_801851E0
    if (ctx->r2 == 0) {
        // 0x801851C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801851E0;
    }
    // 0x801851C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801851C4: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x801851C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801851CC: nop

    // 0x801851D0: swc1        $f4, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->f4.u32l;
    // 0x801851D4: jal         0x80184FAC
    // 0x801851D8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    itTaruBombCommonSetMapCollisionBox(rdram, ctx);
        goto after_1;
    // 0x801851D8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x801851DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_801851E0:
    // 0x801851E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801851E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801851E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801851EC: jr          $ra
    // 0x801851F0: nop

    return;
    // 0x801851F0: nop

;}
RECOMP_FUNC void itBatWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174ECC: jal         0x80172E74
    // 0x80174ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80174ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174ED4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174ED8: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    // 0x80174EDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174EE0: jal         0x80172EC8
    // 0x80174EE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174EE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80174EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174EF0: jr          $ra
    // 0x80174EF4: nop

    return;
    // 0x80174EF4: nop

;}
RECOMP_FUNC void ftCommonAttackAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150A08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150A10: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80150A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80150A18: jal         0x800DE6B0
    // 0x80150A1C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80150A1C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80150A20: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80150A24: beq         $v0, $zero, L_80150AF0
    if (ctx->r2 == 0) {
        // 0x80150A28: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80150AF0;
    }
    // 0x80150A28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80150A2C: lw          $v0, 0x180($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X180);
    // 0x80150A30: beql        $v0, $zero, L_80150AC0
    if (ctx->r2 == 0) {
        // 0x80150A34: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80150AC0;
    }
    goto skip_0;
    // 0x80150A34: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_0:
    // 0x80150A38: lw          $t6, 0x160($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X160);
    // 0x80150A3C: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80150A40: bnel        $at, $zero, L_80150AC0
    if (ctx->r1 != 0) {
        // 0x80150A44: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80150AC0;
    }
    goto skip_1;
    // 0x80150A44: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_1:
    // 0x80150A48: lw          $t7, 0x9C4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X9C4);
    // 0x80150A4C: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x80150A50: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80150A54: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80150A58: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80150A5C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80150A60: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80150A64: lw          $t2, 0x3C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X3C);
    // 0x80150A68: beql        $t2, $zero, L_80150A84
    if (ctx->r10 == 0) {
        // 0x80150A6C: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_80150A84;
    }
    goto skip_2;
    // 0x80150A6C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_2:
    // 0x80150A70: jal         0x80150E80
    // 0x80150A74: nop

    ftCommonLandingAirSetStatus(rdram, ctx);
        goto after_1;
    // 0x80150A74: nop

    after_1:
    // 0x80150A78: b           L_80150AF4
    // 0x80150A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150AF4;
    // 0x80150A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150A80: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_80150A84:
    // 0x80150A84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80150A88: bgez        $v0, L_80150A9C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80150A8C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80150A9C;
    }
    // 0x80150A8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80150A90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80150A94: nop

    // 0x80150A98: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80150A9C:
    // 0x80150A9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150AA0: lwc1        $f10, -0x3B00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3B00);
    // 0x80150AA4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80150AA8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80150AAC: jal         0x80142E10
    // 0x80150AB0: nop

    ftCommonLandingAirNullSetStatus(rdram, ctx);
        goto after_2;
    // 0x80150AB0: nop

    after_2:
    // 0x80150AB4: b           L_80150AF4
    // 0x80150AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150AF4;
    // 0x80150AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150ABC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_80150AC0:
    // 0x80150AC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80150AC4: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80150AC8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80150ACC: nop

    // 0x80150AD0: bc1f        L_80150AE8
    if (!c1cs) {
        // 0x80150AD4: nop
    
            goto L_80150AE8;
    }
    // 0x80150AD4: nop

    // 0x80150AD8: jal         0x8013E1C8
    // 0x80150ADC: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_3;
    // 0x80150ADC: nop

    after_3:
    // 0x80150AE0: b           L_80150AF4
    // 0x80150AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150AF4;
    // 0x80150AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150AE8:
    // 0x80150AE8: jal         0x80142D9C
    // 0x80150AEC: nop

    ftCommonLandingSetStatus(rdram, ctx);
        goto after_4;
    // 0x80150AEC: nop

    after_4:
L_80150AF0:
    // 0x80150AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150AF4:
    // 0x80150AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150AF8: jr          $ra
    // 0x80150AFC: nop

    return;
    // 0x80150AFC: nop

;}
RECOMP_FUNC void wpSamusBombProcAbsorb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016923C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80169248: jal         0x800269C0
    // 0x8016924C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8016924C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80169250: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80169254: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80169258: jal         0x801005C8
    // 0x8016925C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016925C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80169260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80169264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80169268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016926C: jr          $ra
    // 0x80169270: nop

    return;
    // 0x80169270: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingSetSceneData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801375D8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801375DC: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x801375E0: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x801375E4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801375E8: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801375EC: addiu       $a1, $a1, -0x7AA8
    ctx->r5 = ADD32(ctx->r5, -0X7AA8);
    // 0x801375F0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x801375F4: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x801375F8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801375FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80137600: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x80137604: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x80137608: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8013760C: sb          $t8, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r24;
    // 0x80137610: sb          $t9, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r25;
    // 0x80137614: lw          $t0, -0x7768($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7768);
    // 0x80137618: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013761C: mflo        $t1
    ctx->r9 = lo;
    // 0x80137620: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
    // 0x80137624: lw          $t2, 0x48($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X48);
    // 0x80137628: lw          $t3, 0x4C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4C);
    // 0x8013762C: sb          $t2, 0x3D($a0)
    MEM_B(0X3D, ctx->r4) = ctx->r10;
    // 0x80137630: jr          $ra
    // 0x80137634: sb          $t3, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r11;
    return;
    // 0x80137634: sb          $t3, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void efManagerFireGrindMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102DEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102DF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80102DF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102DF8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80102DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102E00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102E04: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80102E08: jal         0x800CE9E8
    // 0x80102E0C: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80102E0C: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x80102E10: beq         $v0, $zero, L_80102E78
    if (ctx->r2 == 0) {
        // 0x80102E14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80102E78;
    }
    // 0x80102E14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80102E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102E1C: jal         0x800CE1DC
    // 0x80102E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80102E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80102E24: beq         $v0, $zero, L_80102E6C
    if (ctx->r2 == 0) {
        // 0x80102E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80102E6C;
    }
    // 0x80102E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80102E2C: jal         0x800CEA14
    // 0x80102E30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80102E30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80102E34: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80102E38: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80102E3C: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80102E40: bnel        $t6, $zero, L_80102E54
    if (ctx->r14 != 0) {
        // 0x80102E44: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80102E54;
    }
    goto skip_0;
    // 0x80102E44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80102E48: b           L_80102E7C
    // 0x80102E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102E7C;
    // 0x80102E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102E50: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80102E54:
    // 0x80102E54: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80102E58: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80102E5C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80102E60: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80102E64: b           L_80102E78
    // 0x80102E68: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80102E78;
    // 0x80102E68: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80102E6C:
    // 0x80102E6C: jal         0x800CEA40
    // 0x80102E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80102E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80102E74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80102E78:
    // 0x80102E78: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80102E7C:
    // 0x80102E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102E80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80102E84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80102E88: jr          $ra
    // 0x80102E8C: nop

    return;
    // 0x80102E8C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeHandicapLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013462C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80134630: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80134634: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134638: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013463C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80134640: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80134644: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80134648: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x8013464C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134650: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x80134654: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80134658: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013465C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80134660: beq         $a1, $zero, L_80134674
    if (ctx->r5 == 0) {
        // 0x80134664: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80134674;
    }
    // 0x80134664: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80134668: jal         0x80009A84
    // 0x8013466C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8013466C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80134670: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
L_80134674:
    // 0x80134674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013467C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80134680: jal         0x80009968
    // 0x80134684: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80134684: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134688: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013468C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80134690: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80134694: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
    // 0x80134698: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013469C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801346A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801346A4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x801346A8: jal         0x80009DF4
    // 0x801346AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801346AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801346B0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801346B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801346B8: addiu       $a1, $a1, 0x45B8
    ctx->r5 = ADD32(ctx->r5, 0X45B8);
    // 0x801346BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801346C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801346C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801346C8: jal         0x80008188
    // 0x801346CC: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801346CC: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    after_3:
    // 0x801346D0: lw          $t1, 0x80($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X80);
    // 0x801346D4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801346D8: addiu       $s1, $s1, -0x7368
    ctx->r17 = ADD32(ctx->r17, -0X7368);
    // 0x801346DC: bne         $t1, $zero, L_8013473C
    if (ctx->r9 != 0) {
        // 0x801346E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013473C;
    }
    // 0x801346E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801346E4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801346E8: addiu       $s1, $s1, -0x7368
    ctx->r17 = ADD32(ctx->r17, -0X7368);
    // 0x801346EC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801346F0: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801346F4: addiu       $t3, $t3, 0x1108
    ctx->r11 = ADD32(ctx->r11, 0X1108);
    // 0x801346F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801346FC: jal         0x800CCFDC
    // 0x80134700: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80134700: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_4:
    // 0x80134704: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80134708: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013470C: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80134710: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80134714: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80134718: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8013471C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80134720: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80134724: addiu       $t4, $a2, 0x23
    ctx->r12 = ADD32(ctx->r6, 0X23);
    // 0x80134728: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8013472C: nop

    // 0x80134730: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134734: b           L_80134784
    // 0x80134738: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_80134784;
    // 0x80134738: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_8013473C:
    // 0x8013473C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80134740: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80134744: addiu       $t6, $t6, 0x1218
    ctx->r14 = ADD32(ctx->r14, 0X1218);
    // 0x80134748: jal         0x800CCFDC
    // 0x8013474C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8013474C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x80134750: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80134754: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134758: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013475C: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80134760: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80134764: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80134768: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013476C: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80134770: addiu       $t7, $a2, 0x22
    ctx->r15 = ADD32(ctx->r6, 0X22);
    // 0x80134774: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80134778: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x8013477C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134780: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
L_80134784:
    // 0x80134784: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    // 0x80134788: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x8013478C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134790: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80134794: addiu       $t9, $zero, 0xC2
    ctx->r25 = ADD32(0, 0XC2);
    // 0x80134798: addiu       $t0, $zero, 0xBD
    ctx->r8 = ADD32(0, 0XBD);
    // 0x8013479C: addiu       $t1, $zero, 0xAD
    ctx->r9 = ADD32(0, 0XAD);
    // 0x801347A0: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x801347A4: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801347A8: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
    // 0x801347AC: sb          $t0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r8;
    // 0x801347B0: sb          $t1, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r9;
    // 0x801347B4: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x801347B8: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
    // 0x801347BC: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x801347C0: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801347C4: addiu       $t7, $t7, -0x2310
    ctx->r15 = ADD32(ctx->r15, -0X2310);
    // 0x801347C8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801347CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801347D0: jal         0x800CCFDC
    // 0x801347D4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x801347D4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x801347D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801347DC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801347E0: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x801347E4: addiu       $t8, $a2, 0x3D
    ctx->r24 = ADD32(ctx->r6, 0X3D);
    // 0x801347E8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801347EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801347F0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801347F4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801347F8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801347FC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80134800: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80134804: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80134808: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013480C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80134810: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80134814: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80134818: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013481C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134820: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80134824: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80134828: jr          $ra
    // 0x8013482C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8013482C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mpCollisionCheckProjectLWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA0A4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800FA0A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FA0AC: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800FA0B0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800FA0B4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800FA0B8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800FA0BC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800FA0C0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800FA0C4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800FA0C8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800FA0CC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800FA0D0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800FA0D4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800FA0D8: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800FA0DC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800FA0E0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800FA0E4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800FA0E8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800FA0EC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800FA0F0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800FA0F4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800FA0F8: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800FA0FC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800FA100: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800FA104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FA108: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800FA10C: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800FA110: lwc1        $f26, 0x904($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X904);
    // 0x800FA114: blez        $t0, L_800FA4B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800FA118: nop
    
            goto L_800FA4B8;
    }
    // 0x800FA118: nop

    // 0x800FA11C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800FA120: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800FA124:
    // 0x800FA124: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800FA128: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FA12C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FA130: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800FA134: lhu         $t3, 0x10($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X10);
    // 0x800FA138: addiu       $a0, $t7, 0xE
    ctx->r4 = ADD32(ctx->r15, 0XE);
    // 0x800FA13C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800FA140: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800FA144: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800FA148: beq         $t3, $zero, L_800FA498
    if (ctx->r11 == 0) {
        // 0x800FA14C: lw          $v0, 0x0($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X0);
            goto L_800FA498;
    }
    // 0x800FA14C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800FA150: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800FA154: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800FA158: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800FA15C: beql        $at, $zero, L_800FA49C
    if (ctx->r1 == 0) {
        // 0x800FA160: lw          $t4, 0x70($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X70);
            goto L_800FA49C;
    }
    goto skip_0;
    // 0x800FA160: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x800FA164: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x800FA168: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800FA16C: lwc1        $f2, 0x4($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800FA170: bnel        $t5, $zero, L_800FA184
    if (ctx->r13 != 0) {
        // 0x800FA174: lwc1        $f4, 0x1C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800FA184;
    }
    goto skip_1;
    // 0x800FA174: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    skip_1:
    // 0x800FA178: beql        $v1, $zero, L_800FA198
    if (ctx->r3 == 0) {
        // 0x800FA17C: mov.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
            goto L_800FA198;
    }
    goto skip_2;
    // 0x800FA17C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    skip_2:
    // 0x800FA180: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
L_800FA184:
    // 0x800FA184: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FA188: sub.s       $f24, $f0, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800FA18C: b           L_800FA19C
    // 0x800FA190: sub.s       $f20, $f2, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_800FA19C;
    // 0x800FA190: sub.s       $f20, $f2, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800FA194: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
L_800FA198:
    // 0x800FA198: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_800FA19C:
    // 0x800FA19C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800FA1A0: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800FA1A4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800FA1A8: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800FA1AC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800FA1B0: beq         $at, $zero, L_800FA498
    if (ctx->r1 == 0) {
        // 0x800FA1B4: sll         $s7, $v0, 2
        ctx->r23 = S32(ctx->r2 << 2);
            goto L_800FA498;
    }
    // 0x800FA1B4: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800FA1B8: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x800FA1BC: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
L_800FA1C0:
    // 0x800FA1C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FA1C4: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800FA1C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FA1CC: addu        $t1, $t8, $s7
    ctx->r9 = ADD32(ctx->r24, ctx->r23);
    // 0x800FA1D0: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800FA1D4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800FA1D8: nop

    // 0x800FA1DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FA1E0: c.le.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl <= ctx->f10.fl;
    // 0x800FA1E4: nop

    // 0x800FA1E8: bc1fl       L_800FA470
    if (!c1cs) {
        // 0x800FA1EC: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800FA470;
    }
    goto skip_3;
    // 0x800FA1EC: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_3:
    // 0x800FA1F0: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800FA1F4: sll         $t3, $s6, 2
    ctx->r11 = S32(ctx->r22 << 2);
    // 0x800FA1F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FA1FC: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
    // 0x800FA200: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800FA204: lw          $a2, 0x1374($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1374);
    // 0x800FA208: lhu         $a3, 0x2($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X2);
    // 0x800FA20C: sll         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2 << 1);
    // 0x800FA210: addu        $v1, $a2, $s2
    ctx->r3 = ADD32(ctx->r6, ctx->r18);
    // 0x800FA214: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800FA218: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800FA21C: lw          $t0, 0x1370($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1370);
    // 0x800FA220: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA224: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800FA228: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800FA22C: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x800FA230: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x800FA234: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x800FA238: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800FA23C: mflo        $t5
    ctx->r13 = lo;
    // 0x800FA240: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800FA244: lh          $s1, 0x2($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X2);
    // 0x800FA248: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA24C: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800FA250: nop

    // 0x800FA254: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FA258: mflo        $t7
    ctx->r15 = lo;
    // 0x800FA25C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800FA260: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800FA264: lh          $s0, 0x2($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X2);
    // 0x800FA268: bc1fl       L_800FA290
    if (!c1cs) {
        // 0x800FA26C: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_800FA290;
    }
    goto skip_4;
    // 0x800FA26C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_4:
    // 0x800FA270: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800FA274: nop

    // 0x800FA278: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800FA27C: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800FA280: nop

    // 0x800FA284: bc1tl       L_800FA2B8
    if (c1cs) {
        // 0x800FA288: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800FA2B8;
    }
    goto skip_5;
    // 0x800FA288: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800FA28C: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_800FA290:
    // 0x800FA290: nop

    // 0x800FA294: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800FA298: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800FA29C: nop

    // 0x800FA2A0: bc1fl       L_800FA470
    if (!c1cs) {
        // 0x800FA2A4: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800FA470;
    }
    goto skip_6;
    // 0x800FA2A4: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_6:
    // 0x800FA2A8: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800FA2AC: nop

    // 0x800FA2B0: bc1f        L_800FA46C
    if (!c1cs) {
        // 0x800FA2B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800FA46C;
    }
    // 0x800FA2B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800FA2B8:
    // 0x800FA2B8: beql        $a3, $at, L_800FA374
    if (ctx->r7 == ctx->r1) {
        // 0x800FA2BC: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800FA374;
    }
    goto skip_7;
    // 0x800FA2BC: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_7:
    // 0x800FA2C0: blez        $a3, L_800FA370
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800FA2C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800FA370;
    }
    // 0x800FA2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FA2C8:
    // 0x800FA2C8: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800FA2CC: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800FA2D0: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA2D4: mflo        $t5
    ctx->r13 = lo;
    // 0x800FA2D8: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800FA2DC: lh          $s1, 0x2($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X2);
    // 0x800FA2E0: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA2E4: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800FA2E8: nop

    // 0x800FA2EC: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FA2F0: mflo        $t9
    ctx->r25 = lo;
    // 0x800FA2F4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800FA2F8: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x800FA2FC: lh          $s0, 0x2($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X2);
    // 0x800FA300: bc1fl       L_800FA328
    if (!c1cs) {
        // 0x800FA304: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_800FA328;
    }
    goto skip_8;
    // 0x800FA304: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_8:
    // 0x800FA308: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800FA30C: nop

    // 0x800FA310: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FA314: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x800FA318: nop

    // 0x800FA31C: bc1tl       L_800FA374
    if (c1cs) {
        // 0x800FA320: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800FA374;
    }
    goto skip_9;
    // 0x800FA320: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_9:
    // 0x800FA324: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_800FA328:
    // 0x800FA328: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FA32C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FA330: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x800FA334: nop

    // 0x800FA338: bc1fl       L_800FA354
    if (!c1cs) {
        // 0x800FA33C: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800FA354;
    }
    goto skip_10;
    // 0x800FA33C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_10:
    // 0x800FA340: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800FA344: nop

    // 0x800FA348: bc1tl       L_800FA374
    if (c1cs) {
        // 0x800FA34C: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800FA374;
    }
    goto skip_11;
    // 0x800FA34C: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_11:
    // 0x800FA350: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_800FA354:
    // 0x800FA354: bne         $v0, $a3, L_800FA2C8
    if (ctx->r2 != ctx->r7) {
        // 0x800FA358: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800FA2C8;
    }
    // 0x800FA358: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800FA35C: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800FA360: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800FA364: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800FA368: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800FA36C: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
L_800FA370:
    // 0x800FA370: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
L_800FA374:
    // 0x800FA374: lh          $s4, 0x0($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X0);
    // 0x800FA378: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800FA37C: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA380: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800FA384: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800FA388: mflo        $t3
    ctx->r11 = lo;
    // 0x800FA38C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800FA390: lh          $s5, 0x0($t4)
    ctx->r21 = MEM_H(ctx->r12, 0X0);
    // 0x800FA394: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FA398: jal         0x800F3A34
    // 0x800FA39C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    mpCollisionGetLineDistanceLR(rdram, ctx);
        goto after_0;
    // 0x800FA39C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x800FA3A0: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800FA3A4: sub.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800FA3A8: bc1f        L_800FA46C
    if (!c1cs) {
        // 0x800FA3AC: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800FA46C;
    }
    // 0x800FA3AC: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800FA3B0: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x800FA3B4: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800FA3B8: bc1fl       L_800FA3CC
    if (!c1cs) {
        // 0x800FA3BC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800FA3CC;
    }
    goto skip_12;
    // 0x800FA3BC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x800FA3C0: b           L_800FA3CC
    // 0x800FA3C4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_800FA3CC;
    // 0x800FA3C4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800FA3C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800FA3CC:
    // 0x800FA3CC: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800FA3D0: nop

    // 0x800FA3D4: bc1fl       L_800FA470
    if (!c1cs) {
        // 0x800FA3D8: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800FA470;
    }
    goto skip_13;
    // 0x800FA3D8: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_13:
    // 0x800FA3DC: beq         $t5, $zero, L_800FA3E8
    if (ctx->r13 == 0) {
        // 0x800FA3E0: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800FA3E8;
    }
    // 0x800FA3E0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FA3E4: sw          $s6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r22;
L_800FA3E8:
    // 0x800FA3E8: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800FA3EC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800FA3F0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800FA3F4: beq         $t6, $zero, L_800FA400
    if (ctx->r14 == 0) {
        // 0x800FA3F8: or          $a3, $s5, $zero
        ctx->r7 = ctx->r21 | 0;
            goto L_800FA400;
    }
    // 0x800FA3F8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x800FA3FC: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
L_800FA400:
    // 0x800FA400: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800FA404: beql        $t9, $zero, L_800FA438
    if (ctx->r25 == 0) {
        // 0x800FA408: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_800FA438;
    }
    goto skip_14;
    // 0x800FA408: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_14:
    // 0x800FA40C: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800FA410: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FA414: lw          $t8, 0x1370($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1370);
    // 0x800FA418: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800FA41C: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x800FA420: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA424: mflo        $t3
    ctx->r11 = lo;
    // 0x800FA428: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800FA42C: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800FA430: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800FA434: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_800FA438:
    // 0x800FA438: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800FA43C: beq         $t6, $zero, L_800FA450
    if (ctx->r14 == 0) {
        // 0x800FA440: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800FA450;
    }
    // 0x800FA440: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800FA444: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800FA448: jal         0x800F46D0
    // 0x800FA44C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_1;
    // 0x800FA44C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
L_800FA450:
    // 0x800FA450: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x800FA454: nop

    // 0x800FA458: bc1fl       L_800FA46C
    if (!c1cs) {
        // 0x800FA45C: mov.s       $f26, $f22
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
            goto L_800FA46C;
    }
    goto skip_15;
    // 0x800FA45C: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    skip_15:
    // 0x800FA460: b           L_800FA46C
    // 0x800FA464: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
        goto L_800FA46C;
    // 0x800FA464: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
    // 0x800FA468: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_800FA46C:
    // 0x800FA46C: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
L_800FA470:
    // 0x800FA470: lhu         $t7, 0x2($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X2);
    // 0x800FA474: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800FA478: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x800FA47C: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800FA480: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800FA484: bne         $at, $zero, L_800FA1C0
    if (ctx->r1 != 0) {
        // 0x800FA488: nop
    
            goto L_800FA1C0;
    }
    // 0x800FA488: nop

    // 0x800FA48C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FA490: lw          $t3, 0x1368($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1368);
    // 0x800FA494: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
L_800FA498:
    // 0x800FA498: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_800FA49C:
    // 0x800FA49C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800FA4A0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800FA4A4: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800FA4A8: addiu       $t6, $t9, 0x12
    ctx->r14 = ADD32(ctx->r25, 0X12);
    // 0x800FA4AC: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800FA4B0: bne         $at, $zero, L_800FA124
    if (ctx->r1 != 0) {
        // 0x800FA4B4: sw          $t5, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r13;
            goto L_800FA124;
    }
    // 0x800FA4B4: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_800FA4B8:
    // 0x800FA4B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FA4BC: lwc1        $f8, 0x908($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X908);
    // 0x800FA4C0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800FA4C4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800FA4C8: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x800FA4CC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800FA4D0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800FA4D4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800FA4D8: bc1f        L_800FA4E8
    if (!c1cs) {
        // 0x800FA4DC: lw          $s0, 0x48($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X48);
            goto L_800FA4E8;
    }
    // 0x800FA4DC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800FA4E0: b           L_800FA4EC
    // 0x800FA4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA4EC;
    // 0x800FA4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FA4E8:
    // 0x800FA4E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FA4EC:
    // 0x800FA4EC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800FA4F0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800FA4F4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800FA4F8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800FA4FC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800FA500: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800FA504: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800FA508: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800FA50C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800FA510: jr          $ra
    // 0x800FA514: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800FA514: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_ovl8_8037F4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F4F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037F4F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F4FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037F504: beq         $a0, $zero, L_8037F57C
    if (ctx->r4 == 0) {
        // 0x8037F508: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037F57C;
    }
    // 0x8037F508: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037F50C: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037F510: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037F514: addiu       $t6, $t6, -0x50C8
    ctx->r14 = ADD32(ctx->r14, -0X50C8);
    // 0x8037F518: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037F51C: addiu       $t7, $t7, -0x4FE8
    ctx->r15 = ADD32(ctx->r15, -0X4FE8);
    // 0x8037F520: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037F524: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037F528: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037F52C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037F530: addiu       $t9, $t9, -0x4E90
    ctx->r25 = ADD32(ctx->r25, -0X4E90);
    // 0x8037F534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037F538: jal         0x8037354C
    // 0x8037F53C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_8037354C(rdram, ctx);
        goto after_0;
    // 0x8037F53C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x8037F540: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8037F544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037F548: beql        $t1, $zero, L_8037F568
    if (ctx->r9 == 0) {
        // 0x8037F54C: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8037F568;
    }
    goto skip_0;
    // 0x8037F54C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037F550: jal         0x8037C30C
    // 0x8037F554: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x8037F554: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x8037F558: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037F55C: jal         0x803718C4
    // 0x8037F560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x8037F560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8037F564: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8037F568:
    // 0x8037F568: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8037F56C: beql        $t3, $zero, L_8037F580
    if (ctx->r11 == 0) {
        // 0x8037F570: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037F580;
    }
    goto skip_1;
    // 0x8037F570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037F574: jal         0x803717C0
    // 0x8037F578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x8037F578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8037F57C:
    // 0x8037F57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037F580:
    // 0x8037F580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037F588: jr          $ra
    // 0x8037F58C: nop

    return;
    // 0x8037F58C: nop

;}
RECOMP_FUNC void ftDonkeyThrowFKneeBendSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D950: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014D954: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014D958: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D95C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8014D960: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D964: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014D968: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014D96C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014D970: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x8014D974: jal         0x800E6F24
    // 0x8014D978: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014D978: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014D97C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014D980: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014D984: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014D988: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x8014D98C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8014D990: nop

    // 0x8014D994: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D998: swc1        $f6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f6.u32l;
    // 0x8014D99C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8014D9A0: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
    // 0x8014D9A4: sw          $t7, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r15;
    // 0x8014D9A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D9AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014D9B0: jr          $ra
    // 0x8014D9B4: nop

    return;
    // 0x8014D9B4: nop

;}
RECOMP_FUNC void stringCopyPartial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387420: beq         $a2, $zero, L_80387464
    if (ctx->r6 == 0) {
        // 0x80387424: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80387464;
    }
    // 0x80387424: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80387428: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8038742C: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x80387430: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80387434: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80387438: beq         $a3, $zero, L_80387464
    if (ctx->r7 == 0) {
        // 0x8038743C: sb          $a3, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r7;
            goto L_80387464;
    }
    // 0x8038743C: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
L_80387440:
    // 0x80387440: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80387444: beq         $a2, $zero, L_80387464
    if (ctx->r6 == 0) {
        // 0x80387448: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80387464;
    }
    // 0x80387448: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8038744C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80387450: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x80387454: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80387458: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8038745C: bne         $a3, $zero, L_80387440
    if (ctx->r7 != 0) {
        // 0x80387460: sb          $a3, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r7;
            goto L_80387440;
    }
    // 0x80387460: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
L_80387464:
    // 0x80387464: jr          $ra
    // 0x80387468: nop

    return;
    // 0x80387468: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154F54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80154F58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80154F5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80154F60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80154F64: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80154F68: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80154F6C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80154F70: lwc1        $f6, 0xB30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB30);
    // 0x80154F74: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80154F78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80154F7C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80154F80: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80154F84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80154F88: lwc1        $f18, 0xB34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB34);
    // 0x80154F8C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80154F90: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80154F94: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80154F98: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80154F9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80154FA0: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80154FA4: bc1fl       L_80154FB8
    if (!c1cs) {
        // 0x80154FA8: sw          $t7, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r15;
            goto L_80154FB8;
    }
    goto skip_0;
    // 0x80154FA8: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    skip_0:
    // 0x80154FAC: b           L_80154FB8
    // 0x80154FB0: sw          $t6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r14;
        goto L_80154FB8;
    // 0x80154FB0: sw          $t6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r14;
    // 0x80154FB4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
L_80154FB8:
    // 0x80154FB8: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x80154FBC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80154FC0: nop

    // 0x80154FC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80154FC8: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80154FCC: jal         0x8001863C
    // 0x80154FD0: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80154FD0: nop

    after_0:
    // 0x80154FD4: swc1        $f0, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->f0.u32l;
    // 0x80154FD8: jal         0x80035CD0
    // 0x80154FDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80154FDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80154FE0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80154FE4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80154FE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80154FEC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80154FF0: lwc1        $f12, 0xB2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB2C);
    // 0x80154FF4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80154FF8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80154FFC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80155000: jal         0x800303F0
    // 0x80155004: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80155004: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80155008: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8015500C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80155010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80155014: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80155018: jal         0x80154DBC
    // 0x8015501C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    ftNessSpecialHiJibakuInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015501C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80155020: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80155024: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80155028: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8015502C: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80155030: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155034: jal         0x800E6F24
    // 0x80155038: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x80155038: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x8015503C: jal         0x800E0830
    // 0x80155040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_5;
    // 0x80155040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80155044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80155048: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8015504C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80155050: jr          $ra
    // 0x80155054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80155054: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wpNessPKReflectHeadProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B848: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016B84C: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8016B850: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8016B854: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8016B858: jal         0x801680EC
    // 0x8016B85C: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016B85C: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    after_0:
    // 0x8016B860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016B86C: jr          $ra
    // 0x8016B870: nop

    return;
    // 0x8016B870: nop

;}
RECOMP_FUNC void itLGunMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80175804: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80175808: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017580C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80175810: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80175814: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80175818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017581C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175820: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80175824: addiu       $a1, $a1, -0x64B0
    ctx->r5 = ADD32(ctx->r5, -0X64B0);
    // 0x80175828: jal         0x8016E174
    // 0x8017582C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017582C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80175830: beq         $v0, $zero, L_801758A8
    if (ctx->r2 == 0) {
        // 0x80175834: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801758A8;
    }
    // 0x80175834: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80175838: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8017583C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80175840: sh          $t7, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r15;
    // 0x80175844: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80175848: jal         0x80018910
    // 0x8017584C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    syUtilsRandUShort(rdram, ctx);
        goto after_1;
    // 0x8017584C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80175850: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80175854: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80175858: beq         $t8, $zero, L_80175874
    if (ctx->r24 == 0) {
        // 0x8017585C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80175874;
    }
    // 0x8017585C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80175860: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175864: lwc1        $f4, -0x3300($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3300);
    // 0x80175868: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8017586C: b           L_80175884
    // 0x80175870: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
        goto L_80175884;
    // 0x80175870: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
L_80175874:
    // 0x80175874: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175878: lwc1        $f6, -0x32FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X32FC);
    // 0x8017587C: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x80175880: swc1        $f6, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f6.u32l;
L_80175884:
    // 0x80175884: lbu         $t2, 0x2D3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80175888: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8017588C: sb          $t3, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r11;
    // 0x80175890: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80175894: jal         0x80111EC0
    // 0x80175898: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_2;
    // 0x80175898: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8017589C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801758A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801758A4: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_801758A8:
    // 0x801758A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801758AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801758B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801758B4: jr          $ra
    // 0x801758B8: nop

    return;
    // 0x801758B8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusDestroyPortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013485C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134860: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80134864: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134868: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8013486C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134870: beql        $a0, $zero, L_80134884
    if (ctx->r4 == 0) {
        // 0x80134874: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134884;
    }
    goto skip_0;
    // 0x80134874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80134878: jal         0x80009A84
    // 0x8013487C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8013487C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    after_0:
    // 0x80134880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134884:
    // 0x80134884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134888: jr          $ra
    // 0x8013488C: nop

    return;
    // 0x8013488C: nop

;}
RECOMP_FUNC void unref_800154F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800154F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800154F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800154F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800154FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015504: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80015508: jal         0x80015358
    // 0x8001550C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    gcDrawDObjTreeDLArray(rdram, ctx);
        goto after_0;
    // 0x8001550C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x80015510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015518: jr          $ra
    // 0x8001551C: nop

    return;
    // 0x8001551C: nop

;}
RECOMP_FUNC void lbCommonMatrixTraRotScaInv(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DB4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C7DB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7DBC: lwc1        $f0, 0x5E74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E74);
    // 0x800C7DC0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C7DC4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C7DC8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800C7DCC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C7DD0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C7DD4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C7DD8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C7DDC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800C7DE0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800C7DE4: addiu       $t3, $t3, -0x46B0
    ctx->r11 = ADD32(ctx->r11, -0X46B0);
    // 0x800C7DE8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800C7DEC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C7DF0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7DF4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C7DF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C7DFC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800C7E00: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800C7E04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7E08: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C7E0C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C7E10: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800C7E14: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x800C7E18: andi        $t7, $a1, 0x7FF
    ctx->r15 = ctx->r5 & 0X7FF;
    // 0x800C7E1C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800C7E20: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800C7E24: andi        $t6, $a1, 0x800
    ctx->r14 = ctx->r5 & 0X800;
    // 0x800C7E28: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800C7E2C: lhu         $s0, 0x0($t9)
    ctx->r16 = MEM_HU(ctx->r25, 0X0);
    // 0x800C7E30: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7E34: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800C7E38: beq         $t6, $zero, L_800C7E44
    if (ctx->r14 == 0) {
        // 0x800C7E3C: trunc.w.s   $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
            goto L_800C7E44;
    }
    // 0x800C7E3C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C7E40: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_800C7E44:
    // 0x800C7E44: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x800C7E48: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800C7E4C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800C7E50: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800C7E54: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x800C7E58: beq         $t6, $zero, L_800C7E64
    if (ctx->r14 == 0) {
        // 0x800C7E5C: lhu         $t1, 0x0($t9)
        ctx->r9 = MEM_HU(ctx->r25, 0X0);
            goto L_800C7E64;
    }
    // 0x800C7E5C: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800C7E60: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
L_800C7E64:
    // 0x800C7E64: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800C7E68: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x800C7E6C: andi        $t8, $a1, 0x7FF
    ctx->r24 = ctx->r5 & 0X7FF;
    // 0x800C7E70: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C7E74: addu        $t6, $t3, $t9
    ctx->r14 = ADD32(ctx->r11, ctx->r25);
    // 0x800C7E78: andi        $t7, $a1, 0x800
    ctx->r15 = ctx->r5 & 0X800;
    // 0x800C7E7C: beq         $t7, $zero, L_800C7E88
    if (ctx->r15 == 0) {
        // 0x800C7E80: lhu         $t2, 0x0($t6)
        ctx->r10 = MEM_HU(ctx->r14, 0X0);
            goto L_800C7E88;
    }
    // 0x800C7E80: lhu         $t2, 0x0($t6)
    ctx->r10 = MEM_HU(ctx->r14, 0X0);
    // 0x800C7E84: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_800C7E88:
    // 0x800C7E88: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x800C7E8C: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x800C7E90: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C7E94: addu        $t6, $t3, $t9
    ctx->r14 = ADD32(ctx->r11, ctx->r25);
    // 0x800C7E98: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x800C7E9C: beq         $t7, $zero, L_800C7EA8
    if (ctx->r15 == 0) {
        // 0x800C7EA0: lhu         $a2, 0x0($t6)
        ctx->r6 = MEM_HU(ctx->r14, 0X0);
            goto L_800C7EA8;
    }
    // 0x800C7EA0: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x800C7EA4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_800C7EA8:
    // 0x800C7EA8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C7EAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C7EB0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C7EB4: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x800C7EB8: andi        $t9, $a3, 0x7FF
    ctx->r25 = ctx->r7 & 0X7FF;
    // 0x800C7EBC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800C7EC0: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800C7EC4: andi        $t8, $a3, 0x800
    ctx->r24 = ctx->r7 & 0X800;
    // 0x800C7EC8: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x800C7ECC: beq         $t8, $zero, L_800C7ED8
    if (ctx->r24 == 0) {
        // 0x800C7ED0: div.s       $f16, $f2, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
            goto L_800C7ED8;
    }
    // 0x800C7ED0: div.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800C7ED4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800C7ED8:
    // 0x800C7ED8: addiu       $v1, $a3, 0x400
    ctx->r3 = ADD32(ctx->r7, 0X400);
    // 0x800C7EDC: andi        $t9, $v1, 0x7FF
    ctx->r25 = ctx->r3 & 0X7FF;
    // 0x800C7EE0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800C7EE4: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800C7EE8: andi        $t8, $v1, 0x800
    ctx->r24 = ctx->r3 & 0X800;
    // 0x800C7EEC: beq         $t8, $zero, L_800C7EF8
    if (ctx->r24 == 0) {
        // 0x800C7EF0: lhu         $v0, 0x0($t7)
        ctx->r2 = MEM_HU(ctx->r15, 0X0);
            goto L_800C7EF8;
    }
    // 0x800C7EF0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x800C7EF4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800C7EF8:
    // 0x800C7EF8: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800C7EFC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800C7F00: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7F04: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C7F08: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800C7F0C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C7F10: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C7F14: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7F18: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800C7F1C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800C7F20: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800C7F24: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800C7F28: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800C7F2C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800C7F30: nop

    // 0x800C7F34: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C7F38: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800C7F3C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C7F40: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C7F44: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C7F48: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800C7F4C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800C7F50: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C7F54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C7F58: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C7F5C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C7F60: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7F64: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C7F68: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C7F6C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800C7F70: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C7F74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C7F78: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C7F7C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7F80: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800C7F84: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C7F88: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C7F8C: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7F90: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C7F94: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7F98: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C7F9C: nop

    // 0x800C7FA0: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7FA4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7FA8: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C7FAC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800C7FB0: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7FB4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C7FB8: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7FBC: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C7FC0: nop

    // 0x800C7FC4: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7FC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7FCC: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C7FD0: nop

    // 0x800C7FD4: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7FD8: mflo        $t6
    ctx->r14 = lo;
    // 0x800C7FDC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C7FE0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C7FE4: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x800C7FE8: and         $t6, $t9, $v1
    ctx->r14 = ctx->r25 & ctx->r3;
    // 0x800C7FEC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800C7FF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C7FF4: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800C7FF8: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C7FFC: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800C8000: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800C8004: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800C8008: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x800C800C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C8010: negu        $t8, $t2
    ctx->r24 = SUB32(0, ctx->r10);
    // 0x800C8014: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8018: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C801C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8020: sra         $t9, $t7, 7
    ctx->r25 = S32(SIGNED(ctx->r15) >> 7);
    // 0x800C8024: nop

    // 0x800C8028: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C802C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8030: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C8034: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C8038: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C803C: and         $t9, $t7, $v1
    ctx->r25 = ctx->r15 & ctx->r3;
    // 0x800C8040: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C8044: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800C8048: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800C804C: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x800C8050: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8054: sra         $t9, $t7, 15
    ctx->r25 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800C8058: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C805C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8060: mflo        $t8
    ctx->r24 = lo;
    // 0x800C8064: sra         $t6, $t8, 14
    ctx->r14 = S32(SIGNED(ctx->r24) >> 14);
    // 0x800C8068: nop

    // 0x800C806C: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8070: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8074: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C8078: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x800C807C: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8080: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8084: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C8088: nop

    // 0x800C808C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8090: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8094: sra         $t6, $t7, 8
    ctx->r14 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C8098: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C809C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800C80A4: sra         $t7, $t8, 14
    ctx->r15 = S32(SIGNED(ctx->r24) >> 14);
    // 0x800C80A8: nop

    // 0x800C80AC: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800C80B4: sra         $t8, $t9, 14
    ctx->r24 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C80B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C80BC: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800C80C4: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C80C8: nop

    // 0x800C80CC: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80D0: and         $t8, $t6, $v1
    ctx->r24 = ctx->r14 & ctx->r3;
    // 0x800C80D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800C80D8: sra         $t7, $t9, 8
    ctx->r15 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C80DC: srl         $t9, $t7, 16
    ctx->r25 = S32(U32(ctx->r15) >> 16);
    // 0x800C80E0: multu       $s0, $a2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80E4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800C80E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C80EC: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800C80F0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C80F4: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800C80F8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800C80FC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800C8100: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800C8104: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8108: sra         $t8, $t9, 14
    ctx->r24 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C810C: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    // 0x800C8110: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8114: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C8118: mflo        $t6
    ctx->r14 = lo;
    // 0x800C811C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C8120: nop

    // 0x800C8124: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8128: mflo        $t8
    ctx->r24 = lo;
    // 0x800C812C: sra         $t6, $t8, 8
    ctx->r14 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C8130: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800C8134: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8138: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x800C813C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800C8140: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C8144: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800C8148: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x800C814C: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8150: sra         $t0, $t0, 15
    ctx->r8 = S32(SIGNED(ctx->r8) >> 15);
    // 0x800C8154: nop

    // 0x800C8158: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C815C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8160: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C8164: nop

    // 0x800C8168: multu       $s0, $a1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C816C: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8170: sra         $t8, $t9, 14
    ctx->r24 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C8174: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800C8178: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C817C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C8180: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8184: sra         $t7, $t9, 8
    ctx->r15 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C8188: nop

    // 0x800C818C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8190: mflo        $t3
    ctx->r11 = lo;
    // 0x800C8194: sra         $t3, $t3, 8
    ctx->r11 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800C8198: nop

    // 0x800C819C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C81A0: mflo        $t6
    ctx->r14 = lo;
    // 0x800C81A4: sra         $t9, $t6, 14
    ctx->r25 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C81A8: nop

    // 0x800C81AC: multu       $s0, $v0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C81B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800C81B4: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C81B8: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x800C81BC: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C81C0: and         $t8, $t3, $v1
    ctx->r24 = ctx->r11 & ctx->r3;
    // 0x800C81C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C81C8: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C81CC: nop

    // 0x800C81D0: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C81D4: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800C81D8: mflo        $t4
    ctx->r12 = lo;
    // 0x800C81DC: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800C81E0: srl         $t6, $t4, 16
    ctx->r14 = S32(U32(ctx->r12) >> 16);
    // 0x800C81E4: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C81E8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800C81EC: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800C81F0: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x800C81F4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C81F8: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x800C81FC: mflo        $t7
    ctx->r15 = lo;
    // 0x800C8200: sra         $t9, $t7, 14
    ctx->r25 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C8204: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C8208: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C820C: mflo        $t8
    ctx->r24 = lo;
    // 0x800C8210: sra         $t6, $t8, 8
    ctx->r14 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C8214: nop

    // 0x800C8218: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C821C: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8220: sra         $t8, $t9, 8
    ctx->r24 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C8224: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C8228: and         $t6, $t8, $v1
    ctx->r14 = ctx->r24 & ctx->r3;
    // 0x800C822C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C8230: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800C8234: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800C8238: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C823C: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x800C8240: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800C8244: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800C8248: and         $t8, $t6, $v1
    ctx->r24 = ctx->r14 & ctx->r3;
    // 0x800C824C: srl         $t7, $t9, 16
    ctx->r15 = S32(U32(ctx->r25) >> 16);
    // 0x800C8250: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800C8254: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800C8258: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800C825C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C8260: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8264: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800C8268: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800C826C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800C8270: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x800C8274: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C8278: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C827C: nop

    // 0x800C8280: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800C8284: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C8288: nop

    // 0x800C828C: and         $t8, $v0, $v1
    ctx->r24 = ctx->r2 & ctx->r3;
    // 0x800C8290: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x800C8294: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800C8298: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x800C829C: sw          $t9, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r25;
    // 0x800C82A0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800C82A4: jr          $ra
    // 0x800C82A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800C82A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftSamusSpecialAirLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E058: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8015E05C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8015E060: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015E064: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015E068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E06C: jal         0x800D8E50
    // 0x8015E070: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_0;
    // 0x8015E070: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8015E074: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015E078: lwc1        $f6, -0x371C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X371C);
    // 0x8015E07C: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8015E080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E084: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8015E088: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8015E08C: jal         0x800D8EDC
    // 0x8015E090: nop

    ftPhysicsCheckClampAirVelXDec(rdram, ctx);
        goto after_1;
    // 0x8015E090: nop

    after_1:
    // 0x8015E094: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015E098: bne         $v0, $zero, L_8015E0D4
    if (ctx->r2 != 0) {
        // 0x8015E09C: lwc1        $f0, -0x3718($at)
        ctx->f0.u32l = MEM_W(ctx->r1, -0X3718);
            goto L_8015E0D4;
    }
    // 0x8015E09C: lwc1        $f0, -0x3718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3718);
    // 0x8015E0A0: lwc1        $f10, 0x4C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8015E0A4: lwc1        $f18, 0x50($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8015E0A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E0AC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8015E0B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8015E0B4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8015E0B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8015E0BC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8015E0C0: jal         0x800D8FC8
    // 0x8015E0C4: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_2;
    // 0x8015E0C4: nop

    after_2:
    // 0x8015E0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E0CC: jal         0x800D9074
    // 0x8015E0D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x8015E0D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_8015E0D4:
    // 0x8015E0D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E0D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8015E0DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8015E0E0: jr          $ra
    // 0x8015E0E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8015E0E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itKamexAttackUpdateHydro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180630: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80180634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80180638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018063C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80180640: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80180644: lw          $t6, 0x350($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X350);
    // 0x80180648: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x8018064C: bgtzl       $t6, L_801807CC
    if (SIGNED(ctx->r14) > 0) {
        // 0x80180650: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801807CC;
    }
    goto skip_0;
    // 0x80180650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80180654: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80180658: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8018065C: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80180660: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80180664: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80180668: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8018066C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80180670: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80180674: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80180678: bnel        $t9, $at, L_801806C4
    if (ctx->r25 != ctx->r1) {
        // 0x8018067C: lw          $t1, 0x24($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X24);
            goto L_801806C4;
    }
    goto skip_1;
    // 0x8018067C: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x80180680: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80180684: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80180688: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018068C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80180690: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80180694: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80180698: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018069C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801806A0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801806A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801806A8: nop

    // 0x801806AC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801806B0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801806B4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801806B8: b           L_801806E4
    // 0x801806BC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
        goto L_801806E4;
    // 0x801806BC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801806C0: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
L_801806C4:
    // 0x801806C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801806C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801806CC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801806D0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801806D4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801806D8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801806DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801806E0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_801806E4:
    // 0x801806E4: jal         0x80180F9C
    // 0x801806E8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    itKamexAttackMakeHydro(rdram, ctx);
        goto after_0;
    // 0x801806E8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x801806EC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x801806F0: jal         0x801001A8
    // 0x801806F4: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    efManagerDamageSpawnSparksMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801806F4: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_1:
    // 0x801806F8: jal         0x800269C0
    // 0x801806FC: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801806FC: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    after_2:
    // 0x80180700: jal         0x80018994
    // 0x80180704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80180704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80180708: addiu       $t2, $v0, 0x1E
    ctx->r10 = ADD32(ctx->r2, 0X1E);
    // 0x8018070C: sw          $t2, 0x350($s0)
    MEM_W(0X350, ctx->r16) = ctx->r10;
    // 0x80180710: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80180714: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80180718: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8018071C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80180720: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80180724: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80180728: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8018072C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80180730: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
    // 0x80180734: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x80180738: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018073C: lh          $t7, 0x2E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2E);
    // 0x80180740: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80180744: nop

    // 0x80180748: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018074C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80180750: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80180754: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80180758: bnel        $t8, $at, L_801807A0
    if (ctx->r24 != ctx->r1) {
        // 0x8018075C: lw          $a1, 0x24($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X24);
            goto L_801807A0;
    }
    goto skip_2;
    // 0x8018075C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x80180760: lw          $t9, 0x2D4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2D4);
    // 0x80180764: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80180768: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8018076C: lh          $t0, 0x30($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X30);
    // 0x80180770: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80180774: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80180778: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8018077C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80180780: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80180784: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80180788: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018078C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80180790: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80180794: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80180798: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018079C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
L_801807A0:
    // 0x801807A0: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x801807A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801807A8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x801807AC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x801807B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801807B4: sw          $t3, 0x358($s0)
    MEM_W(0X358, ctx->r16) = ctx->r11;
    // 0x801807B8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801807BC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801807C0: jal         0x800FF278
    // 0x801807C4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    efManagerDustHeavyMakeEffect(rdram, ctx);
        goto after_4;
    // 0x801807C4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x801807C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801807CC:
    // 0x801807CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801807D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801807D4: jr          $ra
    // 0x801807D8: nop

    return;
    // 0x801807D8: nop

;}
RECOMP_FUNC void ftKirbyCopyNessSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155CF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155CFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155D00: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155D04: jal         0x800DEE98
    // 0x80155D08: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80155D08: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155D0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155D10: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80155D14: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x80155D18: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155D1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155D20: jal         0x800E6F24
    // 0x80155D24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155D24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155D28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80155D2C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80155D30: addiu       $t8, $t8, 0x5B40
    ctx->r24 = ADD32(ctx->r24, 0X5B40);
    // 0x80155D34: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80155D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155D3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155D40: jr          $ra
    // 0x80155D44: nop

    return;
    // 0x80155D44: nop

;}
RECOMP_FUNC void itHeartFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174758: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8017475C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174760: addiu       $a3, $a3, 0x4780
    ctx->r7 = ADD32(ctx->r7, 0X4780);
    // 0x80174764: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174768: jal         0x80173B24
    // 0x8017476C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x8017476C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80174770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174778: jr          $ra
    // 0x8017477C: nop

    return;
    // 0x8017477C: nop

;}
RECOMP_FUNC void ftCommonAttackHi4CheckInterruptMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150668: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x8015066C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80150670: jal         0x80146A8C
    // 0x80150674: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x80150674: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80150678: beq         $v0, $zero, L_80150694
    if (ctx->r2 == 0) {
        // 0x8015067C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80150694;
    }
    // 0x8015067C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80150680: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80150684: jal         0x80146690
    // 0x80150688: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80150688: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_1:
    // 0x8015068C: b           L_801506BC
    // 0x80150690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801506BC;
    // 0x80150690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150694:
    // 0x80150694: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80150698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015069C: lbu         $t8, 0x100($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X100);
    // 0x801506A0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801506A4: beq         $t9, $zero, L_801506BC
    if (ctx->r25 == 0) {
        // 0x801506A8: nop
    
            goto L_801506BC;
    }
    // 0x801506A8: nop

    // 0x801506AC: jal         0x801505F0
    // 0x801506B0: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    ftCommonAttackHi4SetStatus(rdram, ctx);
        goto after_2;
    // 0x801506B0: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    after_2:
    // 0x801506B4: b           L_801506BC
    // 0x801506B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801506BC;
    // 0x801506B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801506BC:
    // 0x801506BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801506C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801506C4: jr          $ra
    // 0x801506C8: nop

    return;
    // 0x801506C8: nop

;}
RECOMP_FUNC void itHammerFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017613C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80176140: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80176144: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80176148: jal         0x80172558
    // 0x8017614C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017614C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_0:
    // 0x80176150: jal         0x801713F4
    // 0x80176154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80176154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80176158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017615C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80176164: jr          $ra
    // 0x80176168: nop

    return;
    // 0x80176168: nop

;}
RECOMP_FUNC void sySchedulerSetNextFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017B8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800017BC: lw          $t6, 0x4F88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F88);
    // 0x800017C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800017C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800017C8: beq         $t6, $zero, L_800017EC
    if (ctx->r14 == 0) {
        // 0x800017CC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800017EC;
    }
    // 0x800017CC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800017D0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800017D4: lw          $t7, 0x5020($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5020);
    // 0x800017D8: bne         $t7, $zero, L_800017EC
    if (ctx->r15 != 0) {
        // 0x800017DC: nop
    
            goto L_800017EC;
    }
    // 0x800017DC: nop

    // 0x800017E0: jal         0x80000EAC
    // 0x800017E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sySchedulerApplyViMode(rdram, ctx);
        goto after_0;
    // 0x800017E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800017E8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_800017EC:
    // 0x800017EC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800017F0: lw          $t8, 0x5010($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5010);
    // 0x800017F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800017F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800017FC: beq         $t8, $zero, L_80001848
    if (ctx->r24 == 0) {
        // 0x80001800: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80001848;
    }
    // 0x80001800: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80001804: lw          $a0, 0x5014($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5014);
    // 0x80001808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000180C: jal         0x80030000
    // 0x80001810: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80001810: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80001814: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80001818: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000181C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001820: bne         $a3, $at, L_8000183C
    if (ctx->r7 != ctx->r1) {
        // 0x80001824: addiu       $v1, $v1, 0x4F9C
        ctx->r3 = ADD32(ctx->r3, 0X4F9C);
            goto L_8000183C;
    }
    // 0x80001824: addiu       $v1, $v1, 0x4F9C
    ctx->r3 = ADD32(ctx->r3, 0X4F9C);
    // 0x80001828: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000182C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001830: sw          $t9, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = ctx->r25;
    // 0x80001834: b           L_800018AC
    // 0x80001838: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800018AC;
    // 0x80001838: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000183C:
    // 0x8000183C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001840: b           L_800018AC
    // 0x80001844: sw          $a3, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = ctx->r7;
        goto L_800018AC;
    // 0x80001844: sw          $a3, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = ctx->r7;
L_80001848:
    // 0x80001848: bne         $a3, $at, L_80001894
    if (ctx->r7 != ctx->r1) {
        // 0x8000184C: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_80001894;
    }
    // 0x8000184C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001850: addiu       $v1, $v1, 0x4F9C
    ctx->r3 = ADD32(ctx->r3, 0X4F9C);
    // 0x80001854: jal         0x80001764
    // 0x80001858: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    sySchedulerReadyBuffer(rdram, ctx);
        goto after_2;
    // 0x80001858: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x8000185C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001860: addiu       $v1, $v1, 0x4F9C
    ctx->r3 = ADD32(ctx->r3, 0X4F9C);
    // 0x80001864: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80001868: lw          $t0, 0x4FA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4FA0);
    // 0x8000186C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80001870: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80001874: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001878: bne         $v0, $t0, L_80001884
    if (ctx->r2 != ctx->r8) {
        // 0x8000187C: nop
    
            goto L_80001884;
    }
    // 0x8000187C: nop

    // 0x80001880: sw          $t1, 0x4FA4($at)
    MEM_W(0X4FA4, ctx->r1) = ctx->r9;
L_80001884:
    // 0x80001884: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001888: sw          $v0, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = ctx->r2;
    // 0x8000188C: b           L_800018AC
    // 0x80001890: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800018AC;
    // 0x80001890: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80001894:
    // 0x80001894: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80001898: jal         0x80001764
    // 0x8000189C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    sySchedulerReadyBuffer(rdram, ctx);
        goto after_3;
    // 0x8000189C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x800018A0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800018A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800018A8: sw          $a3, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = ctx->r7;
L_800018AC:
    // 0x800018AC: jal         0x80033490
    // 0x800018B0: nop

    osGetCount_recomp(rdram, ctx);
        goto after_4;
    // 0x800018B0: nop

    after_4:
    // 0x800018B4: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800018B8: lw          $t2, 0x4FAC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4FAC);
    // 0x800018BC: addiu       $at, $zero, 0xB9B
    ctx->r1 = ADD32(0, 0XB9B);
    // 0x800018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800018C4: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x800018C8: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x800018CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800018D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800018D4: sw          $t4, 0x4FB4($at)
    MEM_W(0X4FB4, ctx->r1) = ctx->r12;
    // 0x800018D8: jr          $ra
    // 0x800018DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800018DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ifCommonPlayerStockSetIconAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FD2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010FD30: addiu       $a0, $a0, 0xD40
    ctx->r4 = ADD32(ctx->r4, 0XD40);
    // 0x8010FD34: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010FD38: lw          $t7, -0x1138($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1138);
    // 0x8010FD3C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8010FD40: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    // 0x8010FD44: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010FD48: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010FD4C: sh          $a1, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r5;
    // 0x8010FD50: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x8010FD54: lw          $t0, -0x1134($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1134);
    // 0x8010FD58: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8010FD5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010FD60: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010FD64: sh          $a1, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r5;
    // 0x8010FD68: lw          $t3, -0x1130($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X1130);
    // 0x8010FD6C: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x8010FD70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010FD74: addiu       $v0, $v0, -0x110C
    ctx->r2 = ADD32(ctx->r2, -0X110C);
    // 0x8010FD78: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8010FD7C: sh          $a1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r5;
    // 0x8010FD80: addiu       $v1, $v1, -0x112C
    ctx->r3 = ADD32(ctx->r3, -0X112C);
L_8010FD84:
    // 0x8010FD84: lw          $t5, 0x10($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10);
    // 0x8010FD88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8010FD8C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8010FD90: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8010FD94: sh          $a1, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r5;
    // 0x8010FD98: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8010FD9C: lw          $t9, -0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, -0XC);
    // 0x8010FDA0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8010FDA4: sh          $a1, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r5;
    // 0x8010FDA8: lw          $t1, 0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X10);
    // 0x8010FDAC: lw          $t2, -0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, -0X8);
    // 0x8010FDB0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8010FDB4: sh          $a1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r5;
    // 0x8010FDB8: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x8010FDBC: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x8010FDC0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8010FDC4: bne         $v1, $v0, L_8010FD84
    if (ctx->r3 != ctx->r2) {
        // 0x8010FDC8: sh          $a1, 0x14($t6)
        MEM_H(0X14, ctx->r14) = ctx->r5;
            goto L_8010FD84;
    }
    // 0x8010FDC8: sh          $a1, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r5;
    // 0x8010FDCC: jr          $ra
    // 0x8010FDD0: nop

    return;
    // 0x8010FDD0: nop

;}
RECOMP_FUNC void syAudioGetRestarting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021048: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002104C: jr          $ra
    // 0x80021050: lw          $v0, -0x34D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34D4);
    return;
    // 0x80021050: lw          $v0, -0x34D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34D4);
;}
RECOMP_FUNC void ftKirbySpecialAirNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016289C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801628A0: jal         0x800DE6E4
    // 0x801628A4: addiu       $a1, $a1, 0x29D8
    ctx->r5 = ADD32(ctx->r5, 0X29D8);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801628A4: addiu       $a1, $a1, 0x29D8
    ctx->r5 = ADD32(ctx->r5, 0X29D8);
    after_0:
    // 0x801628A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801628AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801628B0: jr          $ra
    // 0x801628B4: nop

    return;
    // 0x801628B4: nop

;}
RECOMP_FUNC void itNessPKFireFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018568C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185690: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80185694: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80185698: addiu       $a3, $a3, 0x5710
    ctx->r7 = ADD32(ctx->r7, 0X5710);
    // 0x8018569C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801856A0: jal         0x80173C68
    // 0x801856A4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckLanding(rdram, ctx);
        goto after_0;
    // 0x801856A4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x801856A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801856AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801856B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801856B4: jr          $ra
    // 0x801856B8: nop

    return;
    // 0x801856B8: nop

;}
RECOMP_FUNC void sc1PBonusStageTimerProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E114: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E118: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E11C: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x8018E120: ori         $at, $at, 0x4BC0
    ctx->r1 = ctx->r1 | 0X4BC0;
    // 0x8018E124: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x8018E128: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8018E12C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E130: sltu        $at, $v0, $at
    ctx->r1 = ctx->r2 < ctx->r1 ? 1 : 0;
    // 0x8018E134: bne         $at, $zero, L_8018E144
    if (ctx->r1 != 0) {
        // 0x8018E138: lui         $a2, 0x8019
        ctx->r6 = S32(0X8019 << 16);
            goto L_8018E144;
    }
    // 0x8018E138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018E13C: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x8018E140: ori         $v0, $v0, 0x4BBF
    ctx->r2 = ctx->r2 | 0X4BBF;
L_8018E144:
    // 0x8018E144: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8018E148: addiu       $a2, $a2, -0x1004
    ctx->r6 = ADD32(ctx->r6, -0X1004);
    // 0x8018E14C: bgez        $v0, L_8018E164
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8018E150: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E164;
    }
    // 0x8018E150: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E154: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E15C: nop

    // 0x8018E160: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8018E164:
    // 0x8018E164: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018E16C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E170: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018E174: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018E178: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018E17C: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018E180: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8018E184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018E188: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018E18C: addiu       $a0, $a0, -0x116C
    ctx->r4 = ADD32(ctx->r4, -0X116C);
    // 0x8018E190: addiu       $t0, $t0, 0xD40
    ctx->r8 = ADD32(ctx->r8, 0XD40);
    // 0x8018E194: addiu       $t1, $t1, -0xFEC
    ctx->r9 = ADD32(ctx->r9, -0XFEC);
    // 0x8018E198: addiu       $t2, $t2, -0xC60
    ctx->r10 = ADD32(ctx->r10, -0XC60);
    // 0x8018E19C: addiu       $t4, $t4, -0xC5A
    ctx->r12 = ADD32(ctx->r12, -0XC5A);
    // 0x8018E1A0: addiu       $a3, $a3, -0xC60
    ctx->r7 = ADD32(ctx->r7, -0XC60);
    // 0x8018E1A4: addiu       $t3, $zero, -0x5
    ctx->r11 = ADD32(0, -0X5);
L_8018E1A8:
    // 0x8018E1A8: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8018E1AC: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x8018E1B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8018E1B4: div.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8018E1B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018E1BC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8018E1C0: nop

    // 0x8018E1C4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8018E1C8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8018E1CC: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8018E1D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018E1D4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8018E1D8: beq         $v0, $t8, L_8018E280
    if (ctx->r2 == ctx->r24) {
        // 0x8018E1DC: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_8018E280;
    }
    // 0x8018E1DC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018E1E0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8018E1E4: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x8018E1E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E1EC: addiu       $t7, $t8, 0x3C
    ctx->r15 = ADD32(ctx->r24, 0X3C);
    // 0x8018E1F0: or          $t6, $v1, $zero
    ctx->r14 = ctx->r3 | 0;
L_8018E1F4:
    // 0x8018E1F4: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8018E1F8: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018E1FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018E200: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8018E204: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8018E208: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018E20C: lw          $t5, -0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, -0X4);
    // 0x8018E210: bne         $t8, $t7, L_8018E1F4
    if (ctx->r24 != ctx->r15) {
        // 0x8018E214: sw          $t5, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->r13;
            goto L_8018E1F4;
    }
    // 0x8018E214: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x8018E218: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8018E21C: addu        $t7, $t1, $a1
    ctx->r15 = ADD32(ctx->r9, ctx->r5);
    // 0x8018E220: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x8018E224: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018E228: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x8018E22C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8018E230: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x8018E234: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x8018E238: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018E23C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018E240: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E244: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8018E248: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E24C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E250: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8018E254: nop

    // 0x8018E258: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8018E25C: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8018E260: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x8018E264: sub.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8018E268: swc1        $f8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f8.u32l;
    // 0x8018E26C: bne         $a3, $t2, L_8018E280
    if (ctx->r7 != ctx->r10) {
        // 0x8018E270: sb          $v0, 0x0($a3)
        MEM_B(0X0, ctx->r7) = ctx->r2;
            goto L_8018E280;
    }
    // 0x8018E270: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8018E274: lhu         $t5, 0x24($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X24);
    // 0x8018E278: and         $t7, $t5, $t3
    ctx->r15 = ctx->r13 & ctx->r11;
    // 0x8018E27C: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
L_8018E280:
    // 0x8018E280: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8018E284: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8018E288: bne         $a3, $t4, L_8018E1A8
    if (ctx->r7 != ctx->r12) {
        // 0x8018E28C: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_8018E1A8;
    }
    // 0x8018E28C: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8018E290: jr          $ra
    // 0x8018E294: nop

    return;
    // 0x8018E294: nop

;}
RECOMP_FUNC void itSpearFlyInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018010C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180114: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80180118: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018011C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80180120: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80180124: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80180128: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8018012C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80180130: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80180134: lwc1        $f6, 0x20($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80180138: sw          $zero, 0x354($v0)
    MEM_W(0X354, ctx->r2) = 0;
    // 0x8018013C: sh          $t7, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r15;
    // 0x80180140: bne         $t8, $at, L_80180150
    if (ctx->r24 != ctx->r1) {
        // 0x80180144: swc1        $f6, 0x358($v0)
        MEM_W(0X358, ctx->r2) = ctx->f6.u32l;
            goto L_80180150;
    }
    // 0x80180144: swc1        $f6, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->f6.u32l;
    // 0x80180148: jal         0x800269C0
    // 0x8018014C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8018014C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    after_0:
L_80180150:
    // 0x80180150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180158: jr          $ra
    // 0x8018015C: nop

    return;
    // 0x8018015C: nop

;}
RECOMP_FUNC void efManagerSetPrevStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD4F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FD4FC: addiu       $v0, $v0, 0x13BC
    ctx->r2 = ADD32(ctx->r2, 0X13BC);
    // 0x800FD500: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800FD504: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD508: addiu       $v1, $v1, 0x13C0
    ctx->r3 = ADD32(ctx->r3, 0X13C0);
    // 0x800FD50C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800FD510: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800FD514: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800FD518: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800FD51C: jr          $ra
    // 0x800FD520: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x800FD520: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void efManagerRebirthHaloMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010406C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80104070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80104074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104078: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010407C: addiu       $a0, $a0, -0x1890
    ctx->r4 = ADD32(ctx->r4, -0X1890);
    // 0x80104080: jal         0x800FDB1C
    // 0x80104084: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80104084: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80104088: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8010408C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80104090: bne         $v0, $zero, L_801040A0
    if (ctx->r2 != 0) {
        // 0x80104094: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801040A0;
    }
    // 0x80104094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104098: b           L_801040D0
    // 0x8010409C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801040D0;
    // 0x8010409C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801040A0:
    // 0x801040A0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801040A4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801040A8: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x801040AC: lw          $t6, 0x84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X84);
    // 0x801040B0: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x801040B4: lw          $t7, 0x8E8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8E8);
    // 0x801040B8: sw          $t7, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r15;
    // 0x801040BC: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801040C0: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x801040C4: swc1        $f12, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f12.u32l;
    // 0x801040C8: swc1        $f12, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f12.u32l;
    // 0x801040CC: swc1        $f12, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f12.u32l;
L_801040D0:
    // 0x801040D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801040D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801040D8: jr          $ra
    // 0x801040DC: nop

    return;
    // 0x801040DC: nop

;}
RECOMP_FUNC void scStaffrollHighlightThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013270C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132710: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132714: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80132718: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8013271C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80132720: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80132724: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013272C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80132730: addiu       $s1, $s1, -0x5714
    ctx->r17 = ADD32(ctx->r17, -0X5714);
    // 0x80132734: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80132738: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8013273C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80132740: sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
L_80132744:
    // 0x80132744: beq         $s3, $zero, L_80132768
    if (ctx->r19 == 0) {
        // 0x80132748: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_80132768;
    }
    // 0x80132748: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8013274C: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
L_80132750:
    // 0x80132750: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80132754: jal         0x8000B1E8
    // 0x80132758: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80132758: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8013275C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80132760: bnel        $s0, $zero, L_80132750
    if (ctx->r16 != 0) {
        // 0x80132764: addiu       $t6, $s0, -0x1
        ctx->r14 = ADD32(ctx->r16, -0X1);
            goto L_80132750;
    }
    goto skip_0;
    // 0x80132764: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    skip_0:
L_80132768:
    // 0x80132768: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8013276C: bnel        $s2, $s4, L_80132744
    if (ctx->r18 != ctx->r20) {
        // 0x80132770: sw          $s3, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r19;
            goto L_80132744;
    }
    goto skip_1;
    // 0x80132770: sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
    skip_1:
    // 0x80132774: jal         0x80009A84
    // 0x80132778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80132778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8013277C: jal         0x8000B1E8
    // 0x80132780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_2;
    // 0x80132780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80132784: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80132788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013278C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80132790: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80132794: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80132798: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8013279C: jr          $ra
    // 0x801327A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801327A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPikachuSpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151E7C: jal         0x80151E44
    // 0x80151E80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwStartUpdateThunder(rdram, ctx);
        goto after_0;
    // 0x80151E80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151E84: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151E88: addiu       $a1, $a1, 0x236C
    ctx->r5 = ADD32(ctx->r5, 0X236C);
    // 0x80151E8C: jal         0x800D9480
    // 0x80151E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151E90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80151E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151E9C: jr          $ra
    // 0x80151EA0: nop

    return;
    // 0x80151EA0: nop

;}
RECOMP_FUNC void gmCameraZebesFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C8C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010C8C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010C8CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010C8D0: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8010C8D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010C8D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8010C8DC: jal         0x8010BC54
    // 0x8010C8E0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    gmCameraUpdateInterests(rdram, ctx);
        goto after_0;
    // 0x8010C8E0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8010C8E4: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8010C8E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010C8EC: jal         0x8010C70C
    // 0x8010C8F0: nop

    gmCameraAdjustFOV(rdram, ctx);
        goto after_1;
    // 0x8010C8F0: nop

    after_1:
    // 0x8010C8F4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010C8F8: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010C8FC: jal         0x8010C200
    // 0x8010C900: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    gmCameraGetClampDimensionsMax(rdram, ctx);
        goto after_2;
    // 0x8010C900: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8010C904: jal         0x8010C670
    // 0x8010C908: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_ovl2_8010C670(rdram, ctx);
        goto after_3;
    // 0x8010C908: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8010C90C: jal         0x8010C4D0
    // 0x8010C910: nop

    func_ovl2_8010C4D0(rdram, ctx);
        goto after_4;
    // 0x8010C910: nop

    after_4:
    // 0x8010C914: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010C918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C91C: jal         0x8010C55C
    // 0x8010C920: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    gmCameraPan(rdram, ctx);
        goto after_5;
    // 0x8010C920: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8010C924: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8010C928: jal         0x8010C3C0
    // 0x8010C92C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_ovl2_8010C3C0(rdram, ctx);
        goto after_6;
    // 0x8010C92C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8010C930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C934: jal         0x8010C7D0
    // 0x8010C938: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    gmCameraUpdateAcidZoom(rdram, ctx);
        goto after_7;
    // 0x8010C938: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x8010C93C: jal         0x8010C6B8
    // 0x8010C940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_8;
    // 0x8010C940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010C944: jal         0x8010C6FC
    // 0x8010C948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_9;
    // 0x8010C948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8010C94C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C950: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010C954: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010C958: jr          $ra
    // 0x8010C95C: nop

    return;
    // 0x8010C95C: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwCheckCollideThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015203C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152040: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80152044: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80152048: bnel        $v1, $zero, L_80152060
    if (ctx->r3 != 0) {
        // 0x8015204C: lw          $t8, 0xADC($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XADC);
            goto L_80152060;
    }
    goto skip_0;
    // 0x8015204C: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x80152050: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x80152054: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80152058: sw          $t7, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = ctx->r15;
    // 0x8015205C: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
L_80152060:
    // 0x80152060: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80152064: beql        $t9, $zero, L_80152078
    if (ctx->r25 == 0) {
        // 0x80152068: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80152078;
    }
    goto skip_1;
    // 0x80152068: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    skip_1:
    // 0x8015206C: jr          $ra
    // 0x80152070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80152070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152074: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
L_80152078:
    // 0x80152078: lw          $a2, 0x74($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X74);
    // 0x8015207C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80152080: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80152084: lwc1        $f2, 0x1C($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80152088: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x8015208C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80152090: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80152094: nop

    // 0x80152098: bc1fl       L_801520B0
    if (!c1cs) {
        // 0x8015209C: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_801520B0;
    }
    goto skip_2;
    // 0x8015209C: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x801520A0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801520A4: b           L_801520B0
    // 0x801520A8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801520B0;
    // 0x801520A8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801520AC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_801520B0:
    // 0x801520B0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x801520B4: nop

    // 0x801520B8: bc1fl       L_8015211C
    if (!c1cs) {
        // 0x801520BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015211C;
    }
    goto skip_3;
    // 0x801520BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x801520C0: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x801520C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801520C8: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801520CC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x801520D0: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801520D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801520D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801520DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801520E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801520E4: nop

    // 0x801520E8: bc1fl       L_80152100
    if (!c1cs) {
        // 0x801520EC: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80152100;
    }
    goto skip_4;
    // 0x801520EC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x801520F0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801520F4: b           L_80152100
    // 0x801520F8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80152100;
    // 0x801520F8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801520FC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_80152100:
    // 0x80152100: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80152104: nop

    // 0x80152108: bc1fl       L_8015211C
    if (!c1cs) {
        // 0x8015210C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015211C;
    }
    goto skip_5;
    // 0x8015210C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80152110: jr          $ra
    // 0x80152114: sw          $t0, 0x29C($a1)
    MEM_W(0X29C, ctx->r5) = ctx->r8;
    return;
    // 0x80152114: sw          $t0, 0x29C($a1)
    MEM_W(0X29C, ctx->r5) = ctx->r8;
    // 0x80152118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015211C:
    // 0x8015211C: jr          $ra
    // 0x80152120: nop

    return;
    // 0x80152120: nop

;}
RECOMP_FUNC void itMLuckyMakeEggProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181200: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80181204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80181208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018120C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80181210: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80181214: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
    // 0x80181218: bnel        $v1, $zero, L_80181234
    if (ctx->r3 != 0) {
        // 0x8018121C: lhu         $v0, 0x350($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X350);
            goto L_80181234;
    }
    goto skip_0;
    // 0x8018121C: lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X350);
    skip_0:
    // 0x80181220: jal         0x801813F8
    // 0x80181224: nop

    itMLuckyDisappearSetStatus(rdram, ctx);
        goto after_0;
    // 0x80181224: nop

    after_0:
    // 0x80181228: b           L_80181354
    // 0x8018122C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80181354;
    // 0x8018122C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181230: lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X350);
L_80181234:
    // 0x80181234: bne         $v0, $zero, L_80181344
    if (ctx->r2 != 0) {
        // 0x80181238: nop
    
            goto L_80181344;
    }
    // 0x80181238: nop

    // 0x8018123C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80181240: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80181244: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80181248: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8018124C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80181250: beql        $t7, $zero, L_80181338
    if (ctx->r15 == 0) {
        // 0x80181254: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_80181338;
    }
    goto skip_1;
    // 0x80181254: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    skip_1:
    // 0x80181258: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x8018125C: beql        $t8, $zero, L_80181338
    if (ctx->r24 == 0) {
        // 0x80181260: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_80181338;
    }
    goto skip_2;
    // 0x80181260: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    skip_2:
    // 0x80181264: lw          $t1, 0x1C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1C);
    // 0x80181268: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x8018126C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80181270: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
    // 0x80181274: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80181278: lw          $t1, 0x24($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X24);
    // 0x8018127C: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x80181280: jal         0x80018948
    // 0x80181284: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80181284: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_1:
    // 0x80181288: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8018128C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181290: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80181294: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80181298: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018129C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801812A0: jal         0x80018948
    // 0x801812A4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x801812A4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801812A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801812AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801812B0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801812B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801812B8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801812BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801812C0: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x801812C4: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x801812C8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x801812CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801812D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801812D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801812D8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x801812DC: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x801812E0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x801812E4: jal         0x8016EA78
    // 0x801812E8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_3;
    // 0x801812E8: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801812EC: beq         $v0, $zero, L_8018132C
    if (ctx->r2 == 0) {
        // 0x801812F0: nop
    
            goto L_8018132C;
    }
    // 0x801812F0: nop

    // 0x801812F4: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x801812F8: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x801812FC: jal         0x800269C0
    // 0x80181300: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80181300: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    after_4:
    // 0x80181304: lhu         $t5, 0x33E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X33E);
    // 0x80181308: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x8018130C: sh          $t4, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r12;
    // 0x80181310: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80181314: sh          $t6, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r14;
    // 0x80181318: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8018131C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80181320: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80181324: jal         0x800FF048
    // 0x80181328: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80181328: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    after_5:
L_8018132C:
    // 0x8018132C: b           L_80181344
    // 0x80181330: lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X350);
        goto L_80181344;
    // 0x80181330: lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X350);
    // 0x80181334: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
L_80181338:
    // 0x80181338: sh          $t8, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r24;
    // 0x8018133C: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x80181340: sh          $t9, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r25;
L_80181344:
    // 0x80181344: blez        $v0, L_80181350
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80181348: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80181350;
    }
    // 0x80181348: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8018134C: sh          $t0, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r8;
L_80181350:
    // 0x80181350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80181354:
    // 0x80181354: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80181358: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018135C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80181360: jr          $ra
    // 0x80181364: nop

    return;
    // 0x80181364: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeComboDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E62C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E630: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018E634: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018E638: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018E63C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018E640: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018E644: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018E648: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018E64C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018E650: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018E654: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E65C: jal         0x80009968
    // 0x8018E660: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E660: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x8018E664: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8018E668: addiu       $s4, $s4, 0xB58
    ctx->r20 = ADD32(ctx->r20, 0XB58);
    // 0x8018E66C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E670: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018E674: sw          $v0, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r2;
    // 0x8018E678: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8018E67C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E680: addiu       $a1, $a1, -0x1A94
    ctx->r5 = ADD32(ctx->r5, -0X1A94);
    // 0x8018E684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E688: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018E68C: jal         0x80009DF4
    // 0x8018E690: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018E690: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018E694: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E698: addiu       $a1, $a1, -0x1AB8
    ctx->r5 = ADD32(ctx->r5, -0X1AB8);
    // 0x8018E69C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E6A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E6A4: jal         0x80008188
    // 0x8018E6A8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8018E6A8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8018E6AC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8018E6B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018E6B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018E6B8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8018E6BC:
    // 0x8018E6BC: lw          $t7, 0x28($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X28);
    // 0x8018E6C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E6C4: jal         0x800CCFDC
    // 0x8018E6C8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8018E6C8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x8018E6CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018E6D0: jal         0x8018E300
    // 0x8018E6D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_4;
    // 0x8018E6D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8018E6D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E6DC: bne         $s0, $s2, L_8018E6BC
    if (ctx->r16 != ctx->r18) {
        // 0x8018E6E0: swc1        $f20, 0x5C($s1)
        MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
            goto L_8018E6BC;
    }
    // 0x8018E6E0: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x8018E6E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E6E8: jal         0x8018E424
    // 0x8018E6EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sc1PTrainingModeUpdateComboDisplay(rdram, ctx);
        goto after_5;
    // 0x8018E6EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8018E6F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E6F4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018E6F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018E6FC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E700: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018E704: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018E708: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018E70C: jr          $ra
    // 0x8018E710: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018E710: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sc1PGameBossDefeatInterfaceProcSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F6F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018F6FC: addiu       $a0, $a0, 0x366C
    ctx->r4 = ADD32(ctx->r4, 0X366C);
    // 0x8018F700: jal         0x8000AF58
    // 0x8018F704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_0;
    // 0x8018F704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018F708: jal         0x80191114
    // 0x8018F70C: nop

    sc1PGameBossSetChangeWallpaper(rdram, ctx);
        goto after_1;
    // 0x8018F70C: nop

    after_1:
    // 0x8018F710: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018F714: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8018F718: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018F71C: addiu       $t8, $t8, 0x4D48
    ctx->r24 = ADD32(ctx->r24, 0X4D48);
    // 0x8018F720: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8018F724: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8018F728: addiu       $t0, $t0, 0x6450
    ctx->r8 = ADD32(ctx->r8, 0X6450);
    // 0x8018F72C: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018F730: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8018F734: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8018F738: addiu       $a2, $a2, 0x2FD0
    ctx->r6 = ADD32(ctx->r6, 0X2FD0);
    // 0x8018F73C: jal         0x8010D030
    // 0x8018F740: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    gmCameraSetStatusAnim(rdram, ctx);
        goto after_2;
    // 0x8018F740: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x8018F744: jal         0x80114BE4
    // 0x8018F748: nop

    ifCommonBattleBossDefeatSetGameStatus(rdram, ctx);
        goto after_3;
    // 0x8018F748: nop

    after_3:
    // 0x8018F74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F754: jr          $ra
    // 0x8018F758: nop

    return;
    // 0x8018F758: nop

;}
RECOMP_FUNC void ftCommonFallSpecialSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801438F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801438F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801438F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801438FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80143900: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80143904: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80143908: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014390C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80143910: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80143914: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x80143918: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014391C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80143920: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80143924: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80143928: jal         0x800E6F24
    // 0x8014392C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014392C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80143930: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80143934: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80143938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014393C: lwc1        $f4, 0x50($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X50);
    // 0x80143940: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80143944: swc1        $f8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->f8.u32l;
    // 0x80143948: jal         0x800D8E78
    // 0x8014394C: lw          $a1, 0xB18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB18);
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_1;
    // 0x8014394C: lw          $a1, 0xB18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB18);
    after_1:
    // 0x80143950: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x80143954: bnel        $t9, $zero, L_80143968
    if (ctx->r25 != 0) {
        // 0x80143958: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_80143968;
    }
    goto skip_0;
    // 0x80143958: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8014395C: jal         0x800DEEC8
    // 0x80143960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_2;
    // 0x80143960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80143964: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_80143968:
    // 0x80143968: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8014396C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80143970: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x80143974: sw          $t2, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r10;
    // 0x80143978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014397C: sb          $t1, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r9;
    // 0x80143980: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80143984: sw          $t3, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r11;
    // 0x80143988: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8014398C: swc1        $f10, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->f10.u32l;
    // 0x80143990: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80143994: sw          $t4, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r12;
    // 0x80143998: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8014399C: sw          $t5, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r13;
    // 0x801439A0: jal         0x800E9814
    // 0x801439A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x801439A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x801439A8: jal         0x80165024
    // 0x801439AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPublicTryPlayFallSpecialReact(rdram, ctx);
        goto after_4;
    // 0x801439AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x801439B0: lbu         $t7, 0x192($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X192);
    // 0x801439B4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801439B8: sb          $t8, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r24;
    // 0x801439BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801439C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801439C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801439C8: jr          $ra
    // 0x801439CC: nop

    return;
    // 0x801439CC: nop

;}
RECOMP_FUNC void mvOpeningFoxMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D40C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D410: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D418: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D41C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D424: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D428: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D42C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D430: addiu       $t6, $t6, -0x1F70
    ctx->r14 = ADD32(ctx->r14, -0X1F70);
    // 0x8018D434: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D438: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D43C: addiu       $s0, $s0, -0x1DE8
    ctx->r16 = ADD32(ctx->r16, -0X1DE8);
    // 0x8018D440: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D444: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D448: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D44C: addiu       $t9, $t9, -0x1F54
    ctx->r25 = ADD32(ctx->r25, -0X1F54);
    // 0x8018D450: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D454: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D458: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $s1, $s1, -0x1DC8
    ctx->r17 = ADD32(ctx->r17, -0X1DC8);
    // 0x8018D460: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D464: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D46C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D470: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D474: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D478: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D47C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D480: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D484: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D488: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D48C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D490: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D494: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D498: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D49C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4A0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4A4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4A8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4AC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4B4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4BC: jal         0x8010DB2C
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D4C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D4CC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4D0: addiu       $v1, $v1, -0x1DF8
    ctx->r3 = ADD32(ctx->r3, -0X1DF8);
    // 0x8018D4D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4D8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4DC: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D4E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D4EC: lui         $a3, 0x4352
    ctx->r7 = S32(0X4352 << 16);
    // 0x8018D4F0: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4F4: jal         0x80007080
    // 0x8018D4F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D500: lwc1        $f6, -0x1E24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E24);
    // 0x8018D504: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D508: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D50C: jal         0x8000B39C
    // 0x8018D510: lw          $a0, -0x1DF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DF8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D510: lw          $a0, -0x1DF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DF8);
    after_2:
    // 0x8018D514: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D518: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D51C: addiu       $a1, $a1, -0x2CEC
    ctx->r5 = ADD32(ctx->r5, -0X2CEC);
    // 0x8018D520: lw          $a0, -0x1DF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DF8);
    // 0x8018D524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D528: jal         0x80008188
    // 0x8018D52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D530: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D534: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D538: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D53C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D540: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D544: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D548: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D54C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D550: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D554: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D558: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D55C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D560: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D564: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D568: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D56C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D570: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D574: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D578: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D57C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D580: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D584: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D588: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D58C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D590: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D594: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D598: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D59C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D5A0: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5A4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5A8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5AC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5B0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5B4: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5B8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5BC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5C0: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5C4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5C8: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5CC: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5D0: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5D4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5D8: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5DC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5E0: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5E4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5E8: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5EC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5F0: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5F8: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5FC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D600: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D604: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D608: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D60C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D614: jr          $ra
    // 0x8018D618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D618: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSItemSwitchGetItemSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132650: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132654: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x80132658: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x8013265C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132660: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132664: lw          $t7, 0x3214($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3214);
    // 0x80132668: sw          $t6, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r14;
    // 0x8013266C: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80132670: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132674: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80132678: and         $t0, $t9, $a0
    ctx->r8 = ctx->r25 & ctx->r4;
    // 0x8013267C: beq         $t0, $zero, L_80132694
    if (ctx->r8 == 0) {
        // 0x80132680: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80132694;
    }
    // 0x80132680: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132684: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132688: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013268C: b           L_8013269C
    // 0x80132690: sw          $t1, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r9;
        goto L_8013269C;
    // 0x80132690: sw          $t1, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r9;
L_80132694:
    // 0x80132694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132698: sw          $zero, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = 0;
L_8013269C:
    // 0x8013269C: lw          $t2, 0x3218($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3218);
    // 0x801326A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801326A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801326A8: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x801326AC: and         $t5, $t4, $a0
    ctx->r13 = ctx->r12 & ctx->r4;
    // 0x801326B0: beq         $t5, $zero, L_801326C8
    if (ctx->r13 == 0) {
        // 0x801326B4: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_801326C8;
    }
    // 0x801326B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801326B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801326BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326C0: b           L_801326D0
    // 0x801326C4: sw          $t6, 0x3428($at)
    MEM_W(0X3428, ctx->r1) = ctx->r14;
        goto L_801326D0;
    // 0x801326C4: sw          $t6, 0x3428($at)
    MEM_W(0X3428, ctx->r1) = ctx->r14;
L_801326C8:
    // 0x801326C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326CC: sw          $zero, 0x3428($at)
    MEM_W(0X3428, ctx->r1) = 0;
L_801326D0:
    // 0x801326D0: lw          $t8, 0x321C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X321C);
    // 0x801326D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801326D8: addiu       $v1, $v1, 0x3220
    ctx->r3 = ADD32(ctx->r3, 0X3220);
    // 0x801326DC: sllv        $t9, $t7, $t8
    ctx->r25 = S32(ctx->r15 << (ctx->r24 & 31));
    // 0x801326E0: and         $t0, $t9, $a0
    ctx->r8 = ctx->r25 & ctx->r4;
    // 0x801326E4: beq         $t0, $zero, L_801326FC
    if (ctx->r8 == 0) {
        // 0x801326E8: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_801326FC;
    }
    // 0x801326E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801326EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801326F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326F4: b           L_80132704
    // 0x801326F8: sw          $t1, 0x342C($at)
    MEM_W(0X342C, ctx->r1) = ctx->r9;
        goto L_80132704;
    // 0x801326F8: sw          $t1, 0x342C($at)
    MEM_W(0X342C, ctx->r1) = ctx->r9;
L_801326FC:
    // 0x801326FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132700: sw          $zero, 0x342C($at)
    MEM_W(0X342C, ctx->r1) = 0;
L_80132704:
    // 0x80132704: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132708: addiu       $a2, $a2, 0x3460
    ctx->r6 = ADD32(ctx->r6, 0X3460);
    // 0x8013270C: addiu       $a1, $a1, 0x3430
    ctx->r5 = ADD32(ctx->r5, 0X3430);
    // 0x80132710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132714:
    // 0x80132714: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80132718: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013271C: sllv        $t4, $t2, $t3
    ctx->r12 = S32(ctx->r10 << (ctx->r11 & 31));
    // 0x80132720: and         $t5, $t4, $a0
    ctx->r13 = ctx->r12 & ctx->r4;
    // 0x80132724: beql        $t5, $zero, L_80132738
    if (ctx->r13 == 0) {
        // 0x80132728: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80132738;
    }
    goto skip_0;
    // 0x80132728: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_0:
    // 0x8013272C: b           L_80132738
    // 0x80132730: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80132738;
    // 0x80132730: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80132734: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80132738:
    // 0x80132738: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8013273C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132740: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80132744: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x80132748: beql        $t9, $zero, L_8013275C
    if (ctx->r25 == 0) {
        // 0x8013274C: sw          $zero, 0x4($a1)
        MEM_W(0X4, ctx->r5) = 0;
            goto L_8013275C;
    }
    goto skip_1;
    // 0x8013274C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    skip_1:
    // 0x80132750: b           L_8013275C
    // 0x80132754: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
        goto L_8013275C;
    // 0x80132754: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80132758: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8013275C:
    // 0x8013275C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80132760: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132764: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80132768: and         $t3, $t2, $a0
    ctx->r11 = ctx->r10 & ctx->r4;
    // 0x8013276C: beql        $t3, $zero, L_80132780
    if (ctx->r11 == 0) {
        // 0x80132770: sw          $zero, 0x8($a1)
        MEM_W(0X8, ctx->r5) = 0;
            goto L_80132780;
    }
    goto skip_2;
    // 0x80132770: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    skip_2:
    // 0x80132774: b           L_80132780
    // 0x80132778: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
        goto L_80132780;
    // 0x80132778: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8013277C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_80132780:
    // 0x80132780: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x80132784: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132788: sllv        $t7, $t5, $t4
    ctx->r15 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x8013278C: and         $t6, $t7, $a0
    ctx->r14 = ctx->r15 & ctx->r4;
    // 0x80132790: beql        $t6, $zero, L_801327A4
    if (ctx->r14 == 0) {
        // 0x80132794: sw          $zero, 0xC($a1)
        MEM_W(0XC, ctx->r5) = 0;
            goto L_801327A4;
    }
    goto skip_3;
    // 0x80132794: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    skip_3:
    // 0x80132798: b           L_801327A4
    // 0x8013279C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
        goto L_801327A4;
    // 0x8013279C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x801327A0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
L_801327A4:
    // 0x801327A4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x801327A8: bne         $a1, $a2, L_80132714
    if (ctx->r5 != ctx->r6) {
        // 0x801327AC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80132714;
    }
    // 0x801327AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801327B0: jr          $ra
    // 0x801327B4: nop

    return;
    // 0x801327B4: nop

;}
RECOMP_FUNC void func_ovl8_8038569C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038569C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803856A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803856A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803856A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803856AC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x803856B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803856B4: bne         $a0, $zero, L_803856CC
    if (ctx->r4 != 0) {
        // 0x803856B8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803856CC;
    }
    // 0x803856B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803856BC: jal         0x803717A0
    // 0x803856C0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803856C0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x803856C4: beq         $v0, $zero, L_80385740
    if (ctx->r2 == 0) {
        // 0x803856C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385740;
    }
    // 0x803856C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803856CC:
    // 0x803856CC: bne         $s1, $zero, L_803856F0
    if (ctx->r17 != 0) {
        // 0x803856D0: addiu       $a0, $s0, 0x54
        ctx->r4 = ADD32(ctx->r16, 0X54);
            goto L_803856F0;
    }
    // 0x803856D0: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x803856D4: addiu       $a1, $s0, 0xB4
    ctx->r5 = ADD32(ctx->r16, 0XB4);
    // 0x803856D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803856DC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x803856E0: jal         0x803717E0
    // 0x803856E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803856E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_1:
    // 0x803856E8: jal         0x8037C2D0
    // 0x803856EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803856EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_803856F0:
    // 0x803856F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803856F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x803856F8: jal         0x803820B0
    // 0x803856FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803820B0(rdram, ctx);
        goto after_3;
    // 0x803856FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80385700: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80385704: jal         0x80372430
    // 0x80385708: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_80372430(rdram, ctx);
        goto after_4;
    // 0x80385708: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8038570C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80385710: addiu       $t6, $t6, -0x2400
    ctx->r14 = ADD32(ctx->r14, -0X2400);
    // 0x80385714: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80385718: addiu       $t7, $t7, -0x2328
    ctx->r15 = ADD32(ctx->r15, -0X2328);
    // 0x8038571C: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x80385720: sw          $t7, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r15;
    // 0x80385724: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80385728: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038572C: addiu       $t8, $t8, -0x21D0
    ctx->r24 = ADD32(ctx->r24, -0X21D0);
    // 0x80385730: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80385734: addiu       $t0, $t0, -0x21A8
    ctx->r8 = ADD32(ctx->r8, -0X21A8);
    // 0x80385738: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8038573C: sw          $t0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r8;
L_80385740:
    // 0x80385740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80385744: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80385748: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8038574C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80385750: jr          $ra
    // 0x80385754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80385754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void syVideoSetCenterOffsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80006E98: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80006E9C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80006EA0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80006EA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006EA8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80006EAC: sh          $a0, 0x6694($at)
    MEM_H(0X6694, ctx->r1) = ctx->r4;
    // 0x80006EB0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80006EB4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80006EB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006EBC: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80006EC0: sh          $a1, 0x6696($at)
    MEM_H(0X6696, ctx->r1) = ctx->r5;
    // 0x80006EC4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80006EC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80006ECC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006ED0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80006ED4: sh          $a2, 0x6698($at)
    MEM_H(0X6698, ctx->r1) = ctx->r6;
    // 0x80006ED8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80006EDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006EE0: sh          $a3, 0x669A($at)
    MEM_H(0X669A, ctx->r1) = ctx->r7;
    // 0x80006EE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006EE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006EEC: jr          $ra
    // 0x80006EF0: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
    return;
    // 0x80006EF0: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8002C708_2D308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C708: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002C70C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002C710: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8002C714: addiu       $s3, $s3, -0x2CEC
    ctx->r19 = ADD32(ctx->r19, -0X2CEC);
    // 0x8002C718: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C71C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C720: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C724: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002C728: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002C72C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002C730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C734: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8002C738: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8002C73C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8002C740: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8002C744: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8002C748: bne         $t6, $zero, L_8002C75C
    if (ctx->r14 != 0) {
        // 0x8002C74C: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8002C75C;
    }
    // 0x8002C74C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8002C750: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8002C754: b           L_8002C9FC
    // 0x8002C758: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_8002C9FC;
    // 0x8002C758: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_8002C75C:
    // 0x8002C75C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8002C760: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8002C764: lui         $a1, 0x7FFF
    ctx->r5 = S32(0X7FFF << 16);
    // 0x8002C768: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8002C76C: beq         $v1, $zero, L_8002C798
    if (ctx->r3 == 0) {
        // 0x8002C770: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002C798;
    }
    // 0x8002C770: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002C774: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8002C778: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C77C: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x8002C780: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002C784: beql        $at, $zero, L_8002C79C
    if (ctx->r1 == 0) {
        // 0x8002C788: lw          $v1, 0x4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X4);
            goto L_8002C79C;
    }
    goto skip_0;
    // 0x8002C788: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8002C78C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8002C790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002C794: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_8002C798:
    // 0x8002C798: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_8002C79C:
    // 0x8002C79C: beql        $v1, $zero, L_8002C7CC
    if (ctx->r3 == 0) {
        // 0x8002C7A0: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8002C7CC;
    }
    goto skip_1;
    // 0x8002C7A0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8002C7A4: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x8002C7A8: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C7AC: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
    // 0x8002C7B0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002C7B4: beql        $at, $zero, L_8002C7CC
    if (ctx->r1 == 0) {
        // 0x8002C7B8: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8002C7CC;
    }
    goto skip_2;
    // 0x8002C7B8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x8002C7BC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8002C7C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002C7C4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C7C8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8002C7CC:
    // 0x8002C7CC: beql        $v0, $zero, L_8002C7F8
    if (ctx->r2 == 0) {
        // 0x8002C7D0: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_8002C7F8;
    }
    goto skip_3;
    // 0x8002C7D0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x8002C7D4: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8002C7D8: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C7DC: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8002C7E0: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002C7E4: beql        $at, $zero, L_8002C7F8
    if (ctx->r1 == 0) {
        // 0x8002C7E8: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_8002C7F8;
    }
    goto skip_4;
    // 0x8002C7E8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x8002C7EC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002C7F0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C7F4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_8002C7F8:
    // 0x8002C7F8: lw          $v0, 0x10($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X10);
    // 0x8002C7FC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8002C800: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C804: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8002C808: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C80C: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8002C810: slt         $at, $t7, $s2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8002C814: beq         $at, $zero, L_8002C94C
    if (ctx->r1 == 0) {
        // 0x8002C818: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8002C94C;
    }
    // 0x8002C818: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
L_8002C81C:
    // 0x8002C81C: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x8002C820: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x8002C824: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002C828: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002C82C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8002C830: jalr        $t9
    // 0x8002C834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002C834: nop

    after_0:
    // 0x8002C838: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8002C83C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002C840: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002C844: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x8002C848: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002C84C: lwc1        $f18, -0x11AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X11AC);
    // 0x8002C850: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8002C854: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002C858: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002C85C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002C860: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C864: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8002C868: lui         $a1, 0x7FFF
    ctx->r5 = S32(0X7FFF << 16);
    // 0x8002C86C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8002C870: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C874: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8002C878: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002C87C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002C880: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002C884: nop

    // 0x8002C888: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8002C88C: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    // 0x8002C890: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C894: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8002C898: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8002C89C: beql        $v1, $zero, L_8002C8CC
    if (ctx->r3 == 0) {
        // 0x8002C8A0: lw          $v1, 0x4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X4);
            goto L_8002C8CC;
    }
    goto skip_5;
    // 0x8002C8A0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x8002C8A4: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8002C8A8: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C8AC: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8002C8B0: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002C8B4: beql        $at, $zero, L_8002C8CC
    if (ctx->r1 == 0) {
        // 0x8002C8B8: lw          $v1, 0x4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X4);
            goto L_8002C8CC;
    }
    goto skip_6;
    // 0x8002C8B8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x8002C8BC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8002C8C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8002C8C4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C8C8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_8002C8CC:
    // 0x8002C8CC: beql        $v1, $zero, L_8002C8FC
    if (ctx->r3 == 0) {
        // 0x8002C8D0: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8002C8FC;
    }
    goto skip_7;
    // 0x8002C8D0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_7:
    // 0x8002C8D4: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8002C8D8: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C8DC: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x8002C8E0: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002C8E4: beql        $at, $zero, L_8002C8FC
    if (ctx->r1 == 0) {
        // 0x8002C8E8: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_8002C8FC;
    }
    goto skip_8;
    // 0x8002C8E8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_8:
    // 0x8002C8EC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8002C8F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8002C8F4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C8F8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8002C8FC:
    // 0x8002C8FC: beql        $v0, $zero, L_8002C928
    if (ctx->r2 == 0) {
        // 0x8002C900: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8002C928;
    }
    goto skip_9;
    // 0x8002C900: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_9:
    // 0x8002C904: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x8002C908: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C90C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8002C910: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002C914: beql        $at, $zero, L_8002C928
    if (ctx->r1 == 0) {
        // 0x8002C918: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8002C928;
    }
    goto skip_10;
    // 0x8002C918: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_10:
    // 0x8002C91C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002C920: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C924: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_8002C928:
    // 0x8002C928: lw          $v0, 0x10($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X10);
    // 0x8002C92C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8002C930: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C934: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8002C938: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C93C: subu        $t3, $v1, $t5
    ctx->r11 = SUB32(ctx->r3, ctx->r13);
    // 0x8002C940: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8002C944: bnel        $at, $zero, L_8002C81C
    if (ctx->r1 != 0) {
        // 0x8002C948: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8002C81C;
    }
    goto skip_11;
    // 0x8002C948: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    skip_11:
L_8002C94C:
    // 0x8002C94C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8002C950: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x8002C954: blez        $s2, L_8002C9E0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8002C958: sw          $t6, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r14;
            goto L_8002C9E0;
    }
    // 0x8002C958: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x8002C95C: lui         $s1, 0x7FFF
    ctx->r17 = S32(0X7FFF << 16);
    // 0x8002C960: ori         $s1, $s1, 0xFF47
    ctx->r17 = ctx->r17 | 0XFF47;
    // 0x8002C964: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_8002C968:
    // 0x8002C968: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8002C96C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x8002C970: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8002C974: beq         $at, $zero, L_8002C984
    if (ctx->r1 == 0) {
        // 0x8002C978: nop
    
            goto L_8002C984;
    }
    // 0x8002C978: nop

    // 0x8002C97C: b           L_8002C984
    // 0x8002C980: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8002C984;
    // 0x8002C980: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8002C984:
    // 0x8002C984: sw          $s4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r20;
    // 0x8002C988: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8002C98C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8002C990: lw          $a0, 0x2C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X2C);
    // 0x8002C994: jal         0x8002C6BC
    // 0x8002C998: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    n_alSavePull(rdram, ctx);
        goto after_1;
    // 0x8002C998: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002C99C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8002C9A0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8002C9A4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002C9A8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8002C9AC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8002C9B0: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
    // 0x8002C9B4: slt         $at, $a0, $s1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002C9B8: beq         $at, $zero, L_8002C9CC
    if (ctx->r1 == 0) {
        // 0x8002C9BC: subu        $s2, $s2, $v1
        ctx->r18 = SUB32(ctx->r18, ctx->r3);
            goto L_8002C9CC;
    }
    // 0x8002C9BC: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
    // 0x8002C9C0: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x8002C9C4: b           L_8002C9D8
    // 0x8002C9C8: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
        goto L_8002C9D8;
    // 0x8002C9C8: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
L_8002C9CC:
    // 0x8002C9CC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8002C9D0: ori         $t1, $t1, 0x90
    ctx->r9 = ctx->r9 | 0X90;
    // 0x8002C9D4: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
L_8002C9D8:
    // 0x8002C9D8: bgtzl       $s2, L_8002C968
    if (SIGNED(ctx->r18) > 0) {
        // 0x8002C9DC: lw          $s0, 0x0($s3)
        ctx->r16 = MEM_W(ctx->r19, 0X0);
            goto L_8002C968;
    }
    goto skip_12;
    // 0x8002C9DC: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    skip_12:
L_8002C9E0:
    // 0x8002C9E0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8002C9E4: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8002C9E8: subu        $t4, $s5, $t2
    ctx->r12 = SUB32(ctx->r21, ctx->r10);
    // 0x8002C9EC: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8002C9F0: jal         0x8002C598
    // 0x8002C9F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    _n_collectPVoices(rdram, ctx);
        goto after_2;
    // 0x8002C9F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    after_2:
    // 0x8002C9F8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8002C9FC:
    // 0x8002C9FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CA00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002CA04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002CA08: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CA0C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002CA10: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002CA14: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002CA18: jr          $ra
    // 0x8002CA1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002CA1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakePuckCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136088: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013608C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80136090: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80136094: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80136098: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x8013609C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801360A0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801360A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801360A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801360AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801360B0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801360B4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801360B8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801360BC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801360C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801360C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801360C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801360CC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801360D0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801360D4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801360D8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801360DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801360E0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801360E4: jal         0x8000B93C
    // 0x801360E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801360E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801360EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801360F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801360F4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801360F8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801360FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136100: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80136104: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80136108: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013610C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80136110: jal         0x80007080
    // 0x80136114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80136114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80136118: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013611C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80136120: jr          $ra
    // 0x80136124: nop

    return;
    // 0x80136124: nop

;}
RECOMP_FUNC void mnTitleFireFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A20: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80132A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132A28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132A2C: beq         $t6, $at, L_80132A50
    if (ctx->r14 == ctx->r1) {
        // 0x80132A30: addiu       $v0, $v0, 0x4464
        ctx->r2 = ADD32(ctx->r2, 0X4464);
            goto L_80132A50;
    }
    // 0x80132A30: addiu       $v0, $v0, 0x4464
    ctx->r2 = ADD32(ctx->r2, 0X4464);
    // 0x80132A34: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80132A38: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80132A3C: addiu       $t8, $t7, 0xD
    ctx->r24 = ADD32(ctx->r15, 0XD);
    // 0x80132A40: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x80132A44: bne         $at, $zero, L_80132A50
    if (ctx->r1 != 0) {
        // 0x80132A48: sw          $t8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r24;
            goto L_80132A50;
    }
    // 0x80132A48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132A4C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80132A50:
    // 0x80132A50: jr          $ra
    // 0x80132A54: nop

    return;
    // 0x80132A54: nop

;}
RECOMP_FUNC void mvOpeningFoxInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE58: jr          $ra
    // 0x8018DE5C: sw          $zero, -0x1E08($at)
    MEM_W(-0X1E08, ctx->r1) = 0;
    return;
    // 0x8018DE5C: sw          $zero, -0x1E08($at)
    MEM_W(-0X1E08, ctx->r1) = 0;
;}
RECOMP_FUNC void syTaskmanCommonTaskDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800063A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800063A8: jal         0x800049B0
    // 0x800063AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syTaskmanResetGraphicsHeap(rdram, ctx);
        goto after_0;
    // 0x800063AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800063B0: jal         0x80004AB0
    // 0x800063B4: nop

    func_80004AB0(rdram, ctx);
        goto after_1;
    // 0x800063B4: nop

    after_1:
    // 0x800063B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800063BC: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800063C0: jalr        $t9
    // 0x800063C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800063C4: nop

    after_2:
    // 0x800063C8: jal         0x800053CC
    // 0x800063CC: nop

    func_800053CC(rdram, ctx);
        goto after_3;
    // 0x800063CC: nop

    after_3:
    // 0x800063D0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800063D4: lw          $t7, 0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6630);
    // 0x800063D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800063DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800063E0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800063E4: jal         0x80006F5C
    // 0x800063E8: lw          $a0, 0x6568($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6568);
    syVideoApplySettingsNoBlock(rdram, ctx);
        goto after_4;
    // 0x800063E8: lw          $a0, 0x6568($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6568);
    after_4:
    // 0x800063EC: jal         0x80004EFC
    // 0x800063F0: nop

    func_80004EFC(rdram, ctx);
        goto after_5;
    // 0x800063F0: nop

    after_5:
    // 0x800063F4: jal         0x80005C9C
    // 0x800063F8: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_6;
    // 0x800063F8: nop

    after_6:
    // 0x800063FC: beql        $v0, $zero, L_80006410
    if (ctx->r2 == 0) {
        // 0x80006400: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006410;
    }
    goto skip_0;
    // 0x80006400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80006404: jal         0x8000B7B4
    // 0x80006408: nop

    gcEjectAll(rdram, ctx);
        goto after_7;
    // 0x80006408: nop

    after_7:
    // 0x8000640C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006410:
    // 0x80006410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006414: jr          $ra
    // 0x80006418: nop

    return;
    // 0x80006418: nop

;}
RECOMP_FUNC void gmCollisionGetWeaponAttackFighterAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0C08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0C10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0C14: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0C18: jal         0x800F08C8
    // 0x800F0C1C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0C1C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0C20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0C24: jal         0x800F0850
    // 0x800F0C28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0C28: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800F0C2C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0C30: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0C34: jal         0x800F0A48
    // 0x800F0C38: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0C38: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0C40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0C44: jr          $ra
    // 0x800F0C48: nop

    return;
    // 0x800F0C48: nop

;}
RECOMP_FUNC void mnPlayers1PBonusUpdateGameMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801358C8: addiu       $v0, $v0, 0x7714
    ctx->r2 = ADD32(ctx->r2, 0X7714);
    // 0x801358CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801358D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801358D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801358D8: bne         $t6, $zero, L_801358EC
    if (ctx->r14 != 0) {
        // 0x801358DC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801358EC;
    }
    // 0x801358DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801358E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801358E4: b           L_801358F0
    // 0x801358E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_801358F0;
    // 0x801358E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_801358EC:
    // 0x801358EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801358F0:
    // 0x801358F0: jal         0x80009A84
    // 0x801358F4: lw          $a0, 0x7718($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7718);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801358F4: lw          $a0, 0x7718($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7718);
    after_0:
    // 0x801358F8: jal         0x80133218
    // 0x801358FC: nop

    mnPlayers1PBonusMakeLabels(rdram, ctx);
        goto after_1;
    // 0x801358FC: nop

    after_1:
    // 0x80135900: jal         0x80133BCC
    // 0x80135904: nop

    mnPlayers1PBonusMakeHiScore(rdram, ctx);
        goto after_2;
    // 0x80135904: nop

    after_2:
    // 0x80135908: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013590C: lw          $a0, 0x771C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X771C);
    // 0x80135910: beq         $a0, $zero, L_80135928
    if (ctx->r4 == 0) {
        // 0x80135914: nop
    
            goto L_80135928;
    }
    // 0x80135914: nop

    // 0x80135918: jal         0x80009A84
    // 0x8013591C: nop

    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x8013591C: nop

    after_3:
    // 0x80135920: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135924: sw          $zero, 0x771C($at)
    MEM_W(0X771C, ctx->r1) = 0;
L_80135928:
    // 0x80135928: jal         0x80136C88
    // 0x8013592C: nop

    mnPlayers1PBonusCheckBonusCompleteAll(rdram, ctx);
        goto after_4;
    // 0x8013592C: nop

    after_4:
    // 0x80135930: beql        $v0, $zero, L_80135944
    if (ctx->r2 == 0) {
        // 0x80135934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135944;
    }
    goto skip_0;
    // 0x80135934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80135938: jal         0x80133C1C
    // 0x8013593C: nop

    mnPlayers1PBonusMakeTotalTime(rdram, ctx);
        goto after_5;
    // 0x8013593C: nop

    after_5:
    // 0x80135940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135944:
    // 0x80135944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135948: jr          $ra
    // 0x8013594C: nop

    return;
    // 0x8013594C: nop

;}
RECOMP_FUNC void func_ovl8_8037D5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D5AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037D5B0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D5B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037D5B8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8037D5BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D5C0: beq         $a0, $zero, L_8037D634
    if (ctx->r4 == 0) {
        // 0x8037D5C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037D634;
    }
    // 0x8037D5C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037D5C8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8037D5CC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8037D5D0: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_8037D5D4:
    // 0x8037D5D4: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x8037D5D8: subu        $t8, $t1, $t7
    ctx->r24 = SUB32(ctx->r9, ctx->r15);
    // 0x8037D5DC: srav        $t9, $t6, $t8
    ctx->r25 = S32(SIGNED(ctx->r14) >> (ctx->r24 & 31));
    // 0x8037D5E0: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x8037D5E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037D5E8: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x8037D5EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037D5F0: andi        $t3, $a1, 0x7
    ctx->r11 = ctx->r5 & 0X7;
    // 0x8037D5F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8037D5F8: bne         $t1, $t3, L_8037D608
    if (ctx->r9 != ctx->r11) {
        // 0x8037D5FC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037D608;
    }
    // 0x8037D5FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D604: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8037D608:
    // 0x8037D608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037D60C: bne         $v1, $t0, L_8037D628
    if (ctx->r3 != ctx->r8) {
        // 0x8037D610: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8037D628;
    }
    // 0x8037D610: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8037D614: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8037D618: beq         $v1, $zero, L_8037D624
    if (ctx->r3 == 0) {
        // 0x8037D61C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8037D624;
    }
    // 0x8037D61C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D620: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8037D624:
    // 0x8037D624: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037D628:
    // 0x8037D628: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D62C: bnel        $a0, $zero, L_8037D5D4
    if (ctx->r4 != 0) {
        // 0x8037D630: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_8037D5D4;
    }
    goto skip_0;
    // 0x8037D630: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_0:
L_8037D634:
    // 0x8037D634: jr          $ra
    // 0x8037D638: nop

    return;
    // 0x8037D638: nop

;}
RECOMP_FUNC void lbCommonSetupFighterPartsDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8DB4: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800C8DB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C8DBC: lw          $s0, 0xD8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD8);
    // 0x800C8DC0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C8DC4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C8DC8: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x800C8DCC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C8DD0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C8DD4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C8DD8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C8DDC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C8DE0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C8DE4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C8DE8: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800C8DEC: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800C8DF0: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x800C8DF4: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x800C8DF8: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800C8DFC: lw          $s4, -0x10($t8)
    ctx->r20 = MEM_W(ctx->r24, -0X10);
    // 0x800C8E00: addiu       $v0, $sp, 0x6C
    ctx->r2 = ADD32(ctx->r29, 0X6C);
    // 0x800C8E04: addiu       $v1, $sp, 0xB4
    ctx->r3 = ADD32(ctx->r29, 0XB4);
    // 0x800C8E08: lw          $s6, 0x4($s0)
    ctx->r22 = MEM_W(ctx->r16, 0X4);
    // 0x800C8E0C: lw          $s5, 0x0($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X0);
L_800C8E10:
    // 0x800C8E10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C8E14: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C8E18: bne         $at, $zero, L_800C8E10
    if (ctx->r1 != 0) {
        // 0x800C8E1C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800C8E10;
    }
    // 0x800C8E1C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800C8E20: bne         $s5, $zero, L_800C8E30
    if (ctx->r21 != 0) {
        // 0x800C8E24: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C8E30;
    }
    // 0x800C8E24: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C8E28: beql        $s6, $zero, L_800C9024
    if (ctx->r22 == 0) {
        // 0x800C8E2C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800C9024;
    }
    goto skip_0;
    // 0x800C8E2C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_800C8E30:
    // 0x800C8E30: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800C8E34: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C8E38: beq         $a0, $at, L_800C9020
    if (ctx->r4 == ctx->r1) {
        // 0x800C8E3C: slti        $at, $s3, 0x20
        ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
            goto L_800C9020;
    }
    // 0x800C8E3C: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
L_800C8E40:
    // 0x800C8E40: beq         $at, $zero, L_800C8E50
    if (ctx->r1 == 0) {
        // 0x800C8E44: or          $v0, $s6, $zero
        ctx->r2 = ctx->r22 | 0;
            goto L_800C8E50;
    }
    // 0x800C8E44: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x800C8E48: b           L_800C8E50
    // 0x800C8E4C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_800C8E50;
    // 0x800C8E4C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800C8E50:
    // 0x800C8E50: sll         $t9, $v0, 0
    ctx->r25 = S32(ctx->r2 << 0);
    // 0x800C8E54: bgez        $t9, L_800C8FE4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C8E58: andi        $a2, $a0, 0xFFF
        ctx->r6 = ctx->r4 & 0XFFF;
            goto L_800C8FE4;
    }
    // 0x800C8E58: andi        $a2, $a0, 0xFFF
    ctx->r6 = ctx->r4 & 0XFFF;
    // 0x800C8E5C: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x800C8E60: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800C8E64: subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
    // 0x800C8E68: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8E6C: subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
    // 0x800C8E70: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C8E74: beq         $t0, $at, L_800C8E94
    if (ctx->r8 == ctx->r1) {
        // 0x800C8E78: sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3 << 2);
            goto L_800C8E94;
    }
    // 0x800C8E78: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8E7C: lw          $t1, 0x10($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X10);
    // 0x800C8E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8E84: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800C8E88: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800C8E8C: bne         $t3, $zero, L_800C8E9C
    if (ctx->r11 != 0) {
        // 0x800C8E90: nop
    
            goto L_800C8E9C;
    }
    // 0x800C8E90: nop

L_800C8E94:
    // 0x800C8E94: b           L_800C8E9C
    // 0x800C8E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C8E9C;
    // 0x800C8E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8E9C:
    // 0x800C8E9C: beq         $a2, $zero, L_800C8ED4
    if (ctx->r6 == 0) {
        // 0x800C8EA0: sll         $t4, $a2, 2
        ctx->r12 = S32(ctx->r6 << 2);
            goto L_800C8ED4;
    }
    // 0x800C8EA0: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800C8EA4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800C8EA8: addu        $s2, $fp, $t6
    ctx->r18 = ADD32(ctx->r30, ctx->r14);
    // 0x800C8EAC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800C8EB0: addiu       $t5, $sp, 0x6C
    ctx->r13 = ADD32(ctx->r29, 0X6C);
    // 0x800C8EB4: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x800C8EB8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C8EBC: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x800C8EC0: jal         0x800093F4
    // 0x800C8EC4: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x800C8EC4: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    after_0:
    // 0x800C8EC8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800C8ECC: b           L_800C8EF8
    // 0x800C8ED0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800C8EF8;
    // 0x800C8ED0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C8ED4:
    // 0x800C8ED4: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800C8ED8: addu        $s2, $fp, $t9
    ctx->r18 = ADD32(ctx->r30, ctx->r25);
    // 0x800C8EDC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800C8EE0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x800C8EE4: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800C8EE8: jal         0x800093F4
    // 0x800C8EEC: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_1;
    // 0x800C8EEC: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    after_1:
    // 0x800C8EF0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800C8EF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C8EF8:
    // 0x800C8EF8: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800C8EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8F00: lbu         $a1, 0xDF($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XDF);
    // 0x800C8F04: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800C8F08: beq         $t3, $zero, L_800C8F34
    if (ctx->r11 == 0) {
        // 0x800C8F0C: lbu         $a2, 0xE3($sp)
        ctx->r6 = MEM_BU(ctx->r29, 0XE3);
            goto L_800C8F34;
    }
    // 0x800C8F0C: lbu         $a2, 0xE3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XE3);
    // 0x800C8F10: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x800C8F14: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C8F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8F1C: lbu         $a1, 0xDF($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XDF);
    // 0x800C8F20: lbu         $a2, 0xE3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XE3);
    // 0x800C8F24: jal         0x8000F364
    // 0x800C8F28: lbu         $a3, 0xE7($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XE7);
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x800C8F28: lbu         $a3, 0xE7($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XE7);
    after_2:
    // 0x800C8F2C: b           L_800C8F48
    // 0x800C8F30: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
        goto L_800C8F48;
    // 0x800C8F30: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
L_800C8F34:
    // 0x800C8F34: lbu         $t5, 0xEF($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XEF);
    // 0x800C8F38: lbu         $a3, 0xE7($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XE7);
    // 0x800C8F3C: jal         0x800C8A58
    // 0x800C8F40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    lbCommonInitDObj(rdram, ctx);
        goto after_3;
    // 0x800C8F40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800C8F44: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
L_800C8F48:
    // 0x800C8F48: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800C8F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8F50: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x800C8F54: lw          $t6, 0xC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XC);
    // 0x800C8F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C8F5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C8F60: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x800C8F64: lw          $t7, 0x10($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X10);
    // 0x800C8F68: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x800C8F6C: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800C8F70: lw          $t9, 0x14($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X14);
    // 0x800C8F74: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x800C8F78: lw          $t8, 0x18($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X18);
    // 0x800C8F7C: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x800C8F80: lw          $t9, 0x1C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X1C);
    // 0x800C8F84: sw          $t9, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r25;
    // 0x800C8F88: lw          $t1, 0x20($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X20);
    // 0x800C8F8C: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x800C8F90: lw          $t0, 0x24($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X24);
    // 0x800C8F94: sw          $t0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r8;
    // 0x800C8F98: lw          $t1, 0x28($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X28);
    // 0x800C8F9C: sw          $t1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r9;
    // 0x800C8FA0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800C8FA4: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800C8FA8: beq         $v0, $zero, L_800C8FB8
    if (ctx->r2 == 0) {
        // 0x800C8FAC: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_800C8FB8;
    }
    // 0x800C8FAC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800C8FB0: b           L_800C8FB8
    // 0x800C8FB4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
        goto L_800C8FB8;
    // 0x800C8FB4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
L_800C8FB8:
    // 0x800C8FB8: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800C8FBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C8FC0: beq         $v0, $zero, L_800C8FD0
    if (ctx->r2 == 0) {
        // 0x800C8FC4: addu        $t5, $v0, $t4
        ctx->r13 = ADD32(ctx->r2, ctx->r12);
            goto L_800C8FD0;
    }
    // 0x800C8FC4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800C8FC8: b           L_800C8FD0
    // 0x800C8FCC: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
        goto L_800C8FD0;
    // 0x800C8FCC: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
L_800C8FD0:
    // 0x800C8FD0: jal         0x800C8CB8
    // 0x800C8FD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_4;
    // 0x800C8FD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x800C8FD8: beql        $s7, $zero, L_800C8FE8
    if (ctx->r23 == 0) {
        // 0x800C8FDC: slti        $at, $s3, 0x20
        ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
            goto L_800C8FE8;
    }
    goto skip_1;
    // 0x800C8FDC: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
    skip_1:
    // 0x800C8FE0: sw          $s0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r16;
L_800C8FE4:
    // 0x800C8FE4: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
L_800C8FE8:
    // 0x800C8FE8: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800C8FEC: beq         $at, $zero, L_800C8FFC
    if (ctx->r1 == 0) {
        // 0x800C8FF0: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_800C8FFC;
    }
    // 0x800C8FF0: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    // 0x800C8FF4: b           L_800C9000
    // 0x800C8FF8: sll         $s5, $s5, 1
    ctx->r21 = S32(ctx->r21 << 1);
        goto L_800C9000;
    // 0x800C8FF8: sll         $s5, $s5, 1
    ctx->r21 = S32(ctx->r21 << 1);
L_800C8FFC:
    // 0x800C8FFC: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
L_800C9000:
    // 0x800C9000: bne         $s5, $zero, L_800C9010
    if (ctx->r21 != 0) {
        // 0x800C9004: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800C9010;
    }
    // 0x800C9004: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C9008: beql        $s6, $zero, L_800C9024
    if (ctx->r22 == 0) {
        // 0x800C900C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800C9024;
    }
    goto skip_2;
    // 0x800C900C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
L_800C9010:
    // 0x800C9010: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800C9014: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C9018: bnel        $a0, $at, L_800C8E40
    if (ctx->r4 != ctx->r1) {
        // 0x800C901C: slti        $at, $s3, 0x20
        ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
            goto L_800C8E40;
    }
    goto skip_3;
    // 0x800C901C: slti        $at, $s3, 0x20
    ctx->r1 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
    skip_3:
L_800C9020:
    // 0x800C9020: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800C9024:
    // 0x800C9024: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9028: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C902C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C9030: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9034: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C9038: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C903C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C9040: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C9044: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C9048: jr          $ra
    // 0x800C904C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800C904C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void ftDisplayMainDrawAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1D44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1D48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F1D4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F1D50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F1D54: lbu         $v0, 0xC($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XC);
    // 0x800F1D58: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x800F1D5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F1D60: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x800F1D64: beq         $v0, $zero, L_800F1D7C
    if (ctx->r2 == 0) {
        // 0x800F1D68: lw          $s0, 0x74($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X74);
            goto L_800F1D7C;
    }
    // 0x800F1D68: lw          $s0, 0x74($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X74);
    // 0x800F1D6C: beql        $v0, $at, L_800F1DE4
    if (ctx->r2 == ctx->r1) {
        // 0x800F1D70: lw          $v0, 0x50($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X50);
            goto L_800F1DE4;
    }
    goto skip_0;
    // 0x800F1D70: lw          $v0, 0x50($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X50);
    skip_0:
    // 0x800F1D74: b           L_800F1E50
    // 0x800F1D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F1E50;
    // 0x800F1D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F1D7C:
    // 0x800F1D7C: lw          $t7, 0x50($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X50);
    // 0x800F1D80: beql        $t7, $zero, L_800F1E50
    if (ctx->r15 == 0) {
        // 0x800F1D84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F1E50;
    }
    goto skip_1;
    // 0x800F1D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800F1D88: lbu         $t8, 0x54($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X54);
    // 0x800F1D8C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F1D90: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800F1D94: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800F1D98: bne         $t9, $zero, L_800F1E4C
    if (ctx->r25 != 0) {
        // 0x800F1D9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F1E4C;
    }
    // 0x800F1D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F1DA0: jal         0x80012D90
    // 0x800F1DA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_0;
    // 0x800F1DA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F1DA8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F1DAC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800F1DB0: jal         0x800F1C08
    // 0x800F1DB4: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_1;
    // 0x800F1DB4: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    after_1:
    // 0x800F1DB8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800F1DBC: lw          $v1, 0x65B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X65B0);
    // 0x800F1DC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800F1DC4: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800F1DC8: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800F1DCC: sw          $t0, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r8;
    // 0x800F1DD0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800F1DD4: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800F1DD8: b           L_800F1E4C
    // 0x800F1DDC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
        goto L_800F1E4C;
    // 0x800F1DDC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800F1DE0: lw          $v0, 0x50($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X50);
L_800F1DE4:
    // 0x800F1DE4: beql        $v0, $zero, L_800F1E50
    if (ctx->r2 == 0) {
        // 0x800F1DE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F1E50;
    }
    goto skip_2;
    // 0x800F1DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800F1DEC: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800F1DF0: beql        $t3, $zero, L_800F1E50
    if (ctx->r11 == 0) {
        // 0x800F1DF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F1E50;
    }
    goto skip_3;
    // 0x800F1DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800F1DF8: lbu         $t4, 0x54($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X54);
    // 0x800F1DFC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F1E00: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800F1E04: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800F1E08: bne         $t5, $zero, L_800F1E4C
    if (ctx->r13 != 0) {
        // 0x800F1E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F1E4C;
    }
    // 0x800F1E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F1E10: jal         0x80012D90
    // 0x800F1E14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x800F1E14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x800F1E18: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F1E1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800F1E20: jal         0x800F1C08
    // 0x800F1E24: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_3;
    // 0x800F1E24: lbu         $a0, 0xC($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XC);
    after_3:
    // 0x800F1E28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1E2C: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F1E30: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800F1E34: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800F1E38: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800F1E3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F1E40: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800F1E44: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x800F1E48: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_800F1E4C:
    // 0x800F1E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F1E50:
    // 0x800F1E50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F1E54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1E58: jr          $ra
    // 0x800F1E5C: nop

    return;
    // 0x800F1E5C: nop

;}
RECOMP_FUNC void ftBossDrillProcPhysicsFollow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A13C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A140: jal         0x800D9414
    // 0x8015A144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x8015A144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015A148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8015A14C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8015A150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8015A154: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015A158: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8015A15C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8015A160: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A164: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8015A168: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8015A16C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8015A170: addiu       $t3, $t3, -0x6BEC
    ctx->r11 = ADD32(ctx->r11, -0X6BEC);
    // 0x8015A174: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8015A178: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8015A17C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8015A180: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015A184: nop

    // 0x8015A188: bc1fl       L_8015A19C
    if (!c1cs) {
        // 0x8015A18C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8015A19C;
    }
    goto skip_0;
    // 0x8015A18C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8015A190: b           L_8015A19C
    // 0x8015A194: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8015A19C;
    // 0x8015A194: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8015A198: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8015A19C:
    // 0x8015A19C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8015A1A0: nop

    // 0x8015A1A4: bc1fl       L_8015A1D4
    if (!c1cs) {
        // 0x8015A1A8: swc1        $f0, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
            goto L_8015A1D4;
    }
    goto skip_1;
    // 0x8015A1A8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    skip_1:
    // 0x8015A1AC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8015A1B0: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8015A1B4: bc1fl       L_8015A1C8
    if (!c1cs) {
        // 0x8015A1B8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8015A1C8;
    }
    goto skip_2;
    // 0x8015A1B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x8015A1BC: b           L_8015A1D4
    // 0x8015A1C0: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
        goto L_8015A1D4;
    // 0x8015A1C0: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
    // 0x8015A1C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8015A1C8:
    // 0x8015A1C8: b           L_8015A1D4
    // 0x8015A1CC: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
        goto L_8015A1D4;
    // 0x8015A1CC: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x8015A1D0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
L_8015A1D4:
    // 0x8015A1D4: lh          $t0, 0xB18($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A1D8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8015A1DC: sh          $t1, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r9;
    // 0x8015A1E0: lh          $t2, 0xB18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A1E4: bnel        $t2, $zero, L_8015A1F8
    if (ctx->r10 != 0) {
        // 0x8015A1E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015A1F8;
    }
    goto skip_3;
    // 0x8015A1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8015A1EC: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    // 0x8015A1F0: sw          $t3, 0x9E0($v0)
    MEM_W(0X9E0, ctx->r2) = ctx->r11;
    // 0x8015A1F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A1F8:
    // 0x8015A1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A1FC: jr          $ra
    // 0x8015A200: nop

    return;
    // 0x8015A200: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper0ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191D68: jal         0x80191AEC
    // 0x80191D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    SC1PGameBossWallpaper3ProcUpdate0(rdram, ctx);
        goto after_0;
    // 0x80191D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80191D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80191D74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80191D78: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80191D7C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80191D80: nop

    // 0x80191D84: bc1fl       L_80191D98
    if (!c1cs) {
        // 0x80191D88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80191D98;
    }
    goto skip_0;
    // 0x80191D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80191D8C: jal         0x80191B44
    // 0x80191D90: nop

    func_ovl65_80191B44(rdram, ctx);
        goto after_1;
    // 0x80191D90: nop

    after_1:
    // 0x80191D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80191D98:
    // 0x80191D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191D9C: jr          $ra
    // 0x80191DA0: nop

    return;
    // 0x80191DA0: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueScoreDigitInitSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131BFC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80131C00: addiu       $t1, $zero, 0xEC
    ctx->r9 = ADD32(0, 0XEC);
    // 0x80131C04: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131C08: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131C0C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131C10: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131C14: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80131C18: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80131C1C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x80131C20: sb          $t0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r8;
    // 0x80131C24: sb          $t1, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r9;
    // 0x80131C28: jr          $ra
    // 0x80131C2C: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
    return;
    // 0x80131C2C: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
;}
RECOMP_FUNC void func_ovl8_8037D2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D2F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037D2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D2F8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037D2FC: addiu       $a1, $a1, -0x3000
    ctx->r5 = ADD32(ctx->r5, -0X3000);
    // 0x8037D300: addiu       $a0, $zero, -0x1FA
    ctx->r4 = ADD32(0, -0X1FA);
    // 0x8037D304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037D308: jal         0x80009968
    // 0x8037D30C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8037D30C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x8037D310: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037D314: addiu       $v1, $v1, -0x57A0
    ctx->r3 = ADD32(ctx->r3, -0X57A0);
    // 0x8037D318: bne         $v0, $zero, L_8037D328
    if (ctx->r2 != 0) {
        // 0x8037D31C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8037D328;
    }
    // 0x8037D31C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8037D320: b           L_8037D33C
    // 0x8037D324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8037D33C;
    // 0x8037D324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8037D328:
    // 0x8037D328: jal         0x8037D45C
    // 0x8037D32C: nop

    func_ovl8_8037D45C(rdram, ctx);
        goto after_1;
    // 0x8037D32C: nop

    after_1:
    // 0x8037D330: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D334: sh          $zero, -0x1004($at)
    MEM_H(-0X1004, ctx->r1) = 0;
    // 0x8037D338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037D33C:
    // 0x8037D33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037D340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037D344: jr          $ra
    // 0x8037D348: nop

    return;
    // 0x8037D348: nop

;}
RECOMP_FUNC void syAudioDmaNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EAC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EACC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001EAD0: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8001EAD4: addiu       $s2, $s2, -0x2D28
    ctx->r18 = ADD32(ctx->r18, -0X2D28);
    // 0x8001EAD8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001EADC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001EAE0: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x8001EAE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001EAE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001EAEC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001EAF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001EAF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001EAF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001EAFC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001EB00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EB04: jal         0x8001E5F4
    // 0x8001EB08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8001EB08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8001EB0C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8001EB10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001EB14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001EB18: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8001EB1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001EB20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001EB24: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x8001EB28: addiu       $s3, $zero, 0x400
    ctx->r19 = ADD32(0, 0X400);
L_8001EB2C:
    // 0x8001EB2C: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001EB30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EB34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001EB38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001EB3C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001EB40: jal         0x8001E5F4
    // 0x8001EB44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x8001EB44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8001EB48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001EB4C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8001EB50: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8001EB54: sw          $zero, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = 0;
    // 0x8001EB58: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8001EB5C: bne         $s1, $s4, L_8001EB2C
    if (ctx->r17 != ctx->r20) {
        // 0x8001EB60: sw          $s3, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r19;
            goto L_8001EB2C;
    }
    // 0x8001EB60: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x8001EB64: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001EB68: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8001EB6C: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001EB70: addiu       $v0, $v0, -0x1664
    ctx->r2 = ADD32(ctx->r2, -0X1664);
    // 0x8001EB74: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001EB78: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001EB7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001EB80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EB84: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001EB88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001EB8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001EB90: jr          $ra
    // 0x8001EB94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001EB94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ifCommonPlayerStockMakeStockSnap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011496C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114970: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80114974: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x80114978: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8011497C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80114980: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80114984: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x80114988: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8011498C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80114990: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80114994: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80114998: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8011499C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801149A0: bgez        $t1, L_801149B4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801149A4: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801149B4;
    }
    // 0x801149A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801149A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801149AC: nop

    // 0x801149B0: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_801149B4:
    // 0x801149B4: jal         0x80103974
    // 0x801149B8: nop

    efManagerStockSnapMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801149B8: nop

    after_0:
    // 0x801149BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801149C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801149C4: jr          $ra
    // 0x801149C8: nop

    return;
    // 0x801149C8: nop

;}
RECOMP_FUNC void syMatrixTraRotPyRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CD90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CD94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CD98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001CD9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001CDA0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CDA4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001CDA8: jal         0x8001CC80
    // 0x8001CDAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotPyRF(rdram, ctx);
        goto after_0;
    // 0x8001CDAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CDB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CDB4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CDB8: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001CDBC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001CDC0: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001CDC4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CDC8: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001CDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CDD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CDD4: jr          $ra
    // 0x8001CDD8: nop

    return;
    // 0x8001CDD8: nop

;}
RECOMP_FUNC void mvOpeningMarioMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D40C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D410: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D418: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D41C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D424: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D428: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D42C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D430: addiu       $t6, $t6, -0x1F70
    ctx->r14 = ADD32(ctx->r14, -0X1F70);
    // 0x8018D434: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D438: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D43C: addiu       $s0, $s0, -0x1DD8
    ctx->r16 = ADD32(ctx->r16, -0X1DD8);
    // 0x8018D440: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D444: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D448: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D44C: addiu       $t9, $t9, -0x1F54
    ctx->r25 = ADD32(ctx->r25, -0X1F54);
    // 0x8018D450: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D454: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D458: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $s1, $s1, -0x1DB8
    ctx->r17 = ADD32(ctx->r17, -0X1DB8);
    // 0x8018D460: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D464: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D46C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D470: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D474: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D478: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D47C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D480: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D484: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D488: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D48C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D490: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D494: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D498: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D49C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4A0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4A4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4A8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4AC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4B4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4BC: jal         0x8010DB2C
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4C4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4C8: addiu       $v1, $v1, -0x1DE8
    ctx->r3 = ADD32(ctx->r3, -0X1DE8);
    // 0x8018D4CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4D0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4D4: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4DC: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    // 0x8018D4E0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018D4E4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D4E8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4EC: jal         0x80007080
    // 0x8018D4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D4F8: lwc1        $f6, -0x1E14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E14);
    // 0x8018D4FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D500: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D504: jal         0x8000B39C
    // 0x8018D508: lw          $a0, -0x1DE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DE8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D508: lw          $a0, -0x1DE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DE8);
    after_2:
    // 0x8018D50C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D510: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D514: addiu       $a1, $a1, -0x2CEC
    ctx->r5 = ADD32(ctx->r5, -0X2CEC);
    // 0x8018D518: lw          $a0, -0x1DE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DE8);
    // 0x8018D51C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D520: jal         0x80008188
    // 0x8018D524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D528: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D52C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D530: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D534: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D538: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D53C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D540: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D544: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D548: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D54C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D550: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D554: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D558: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D55C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D560: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D564: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D568: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D56C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D570: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D574: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D578: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D57C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D580: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D584: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D588: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D58C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D590: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D594: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D598: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D59C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5A0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5A4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5A8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5AC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5B0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5B4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5B8: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5BC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5C0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5C4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5C8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5CC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5D0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5D4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5D8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5DC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5E0: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5E4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5E8: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5EC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5F0: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5F4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D5F8: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D600: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D604: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D60C: jr          $ra
    // 0x8018D610: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D610: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

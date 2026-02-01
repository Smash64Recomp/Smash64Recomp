#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl2_800EBA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBA6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EBA70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBA74: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800EBA78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800EBA7C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EBA80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800EBA84: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800EBA88: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800EBA8C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800EBA90: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800EBA94: jal         0x80018EE0
    // 0x800EBA98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x800EBA98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EBA9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EBAA0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EBAA4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EBAA8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EBAAC: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EBAB0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EBAB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800EBAB8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EBABC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EBAC0: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EBAC4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EBAC8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800EBACC: add.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800EBAD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EBAD4: jal         0x800190B0
    // 0x800EBAD8: nop

    syVectorScale3D(rdram, ctx);
        goto after_1;
    // 0x800EBAD8: nop

    after_1:
    // 0x800EBADC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EBAE0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EBAE4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EBAE8: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EBAEC: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800EBAF0: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EBAF4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800EBAF8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EBAFC: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EBB00: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800EBB04: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EBB08: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800EBB0C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EBB10: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EBB14: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800EBB18: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EBB1C: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x800EBB20: lwc1        $f14, 0x8($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EBB24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBB28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EBB2C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EBB30: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EBB34: jr          $ra
    // 0x800EBB38: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    return;
    // 0x800EBB38: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
;}
RECOMP_FUNC void gcSetupGObjScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACD0: bne         $a0, $zero, L_8000ACE0
    if (ctx->r4 != 0) {
        // 0x8000ACD4: nop
    
            goto L_8000ACE0;
    }
    // 0x8000ACD4: nop

    // 0x8000ACD8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000ACDC: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000ACE0:
    // 0x8000ACE0: bnel        $a2, $zero, L_8000ACF4
    if (ctx->r6 != 0) {
        // 0x8000ACE4: lw          $v1, 0x70($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X70);
            goto L_8000ACF4;
    }
    goto skip_0;
    // 0x8000ACE4: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x8000ACE8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000ACEC: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
    // 0x8000ACF0: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
L_8000ACF4:
    // 0x8000ACF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000ACF8: bne         $v1, $at, L_8000AD08
    if (ctx->r3 != ctx->r1) {
        // 0x8000ACFC: sll         $t6, $v1, 3
        ctx->r14 = S32(ctx->r3 << 3);
            goto L_8000AD08;
    }
    // 0x8000ACFC: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8000AD00: jr          $ra
    // 0x8000AD04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8000AD04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000AD08:
    // 0x8000AD08: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8000AD0C: sw          $a1, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r5;
    // 0x8000AD10: lw          $t8, 0x70($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X70);
    // 0x8000AD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000AD18: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8000AD1C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8000AD20: sw          $a2, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r6;
    // 0x8000AD24: lw          $t1, 0x70($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X70);
    // 0x8000AD28: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000AD2C: sw          $t2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r10;
    // 0x8000AD30: jr          $ra
    // 0x8000AD34: nop

    return;
    // 0x8000AD34: nop

;}
RECOMP_FUNC void itBoxContainerSmashUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179128: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8017912C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80179130: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80179134: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x80179138: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8017913C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80179140: bne         $t7, $zero, L_80179160
    if (ctx->r15 != 0) {
        // 0x80179144: sw          $t7, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r15;
            goto L_80179160;
    }
    // 0x80179144: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x80179148: jal         0x800FD4F8
    // 0x8017914C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x8017914C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80179150: jal         0x80009A84
    // 0x80179154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80179154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179158: b           L_801791E8
    // 0x8017915C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801791E8;
    // 0x8017915C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80179160:
    // 0x80179160: beq         $v0, $zero, L_801791E4
    if (ctx->r2 == 0) {
        // 0x80179164: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801791E4;
    }
    // 0x80179164: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179168: lwc1        $f0, -0x32A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X32A0);
    // 0x8017916C: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
L_80179170:
    // 0x80179170: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80179174: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80179178: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8017917C: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80179180: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80179184: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x80179188: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8017918C: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80179190: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80179194: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80179198: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8017919C: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801791A0: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x801791A4: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x801791A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801791AC: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x801791B0: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801791B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801791B8: lwc1        $f4, 0x7C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x801791BC: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801791C0: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x801791C4: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x801791C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801791CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801791D0: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x801791D4: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x801791D8: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x801791DC: bnel        $v0, $zero, L_80179170
    if (ctx->r2 != 0) {
        // 0x801791E0: lwc1        $f4, 0x44($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
            goto L_80179170;
    }
    goto skip_0;
    // 0x801791E0: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    skip_0:
L_801791E4:
    // 0x801791E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801791E8:
    // 0x801791E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801791EC: jr          $ra
    // 0x801791F0: nop

    return;
    // 0x801791F0: nop

;}
RECOMP_FUNC void func_ovl8_8037C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C660: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8037C664: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8037C668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037C66C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8037C670: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037C674: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8037C678: jal         0x8037C6DC
    // 0x8037C67C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037C6DC(rdram, ctx);
        goto after_0;
    // 0x8037C67C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8037C680: jal         0x803717A0
    // 0x8037C684: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_1;
    // 0x8037C684: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_1:
    // 0x8037C688: beq         $v0, $zero, L_8037C6C4
    if (ctx->r2 == 0) {
        // 0x8037C68C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037C6C4;
    }
    // 0x8037C68C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037C690: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8037C694: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8037C698: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8037C69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C6A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037C6A4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037C6A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8037C6AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037C6B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8037C6B4: jal         0x8037C7D4
    // 0x8037C6B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_8037C7D4(rdram, ctx);
        goto after_2;
    // 0x8037C6B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_2:
    // 0x8037C6BC: b           L_8037C6C8
    // 0x8037C6C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_8037C6C8;
    // 0x8037C6C0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_8037C6C4:
    // 0x8037C6C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037C6C8:
    // 0x8037C6C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037C6CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8037C6D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037C6D4: jr          $ra
    // 0x8037C6D8: nop

    return;
    // 0x8037C6D8: nop

;}
RECOMP_FUNC void mnPlayersVSSelectFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013718C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137190: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80137194: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x80137198: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013719C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801371A0: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x801371A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801371A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801371AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801371B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801371B4: mflo        $t6
    ctx->r14 = lo;
    // 0x801371B8: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x801371BC: lw          $t7, 0x54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X54);
    // 0x801371C0: beql        $t7, $at, L_801371D4
    if (ctx->r15 == ctx->r1) {
        // 0x801371C4: lw          $t8, 0x80($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X80);
            goto L_801371D4;
    }
    goto skip_0;
    // 0x801371C4: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    skip_0:
    // 0x801371C8: b           L_80137224
    // 0x801371CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137224;
    // 0x801371CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801371D0: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
L_801371D4:
    // 0x801371D4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801371D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801371DC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801371E0: mflo        $t9
    ctx->r25 = lo;
    // 0x801371E4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x801371E8: lw          $t1, 0x48($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X48);
    // 0x801371EC: beq         $t1, $at, L_80137218
    if (ctx->r9 == ctx->r1) {
        // 0x801371F0: nop
    
            goto L_80137218;
    }
    // 0x801371F0: nop

    // 0x801371F4: jal         0x80131C74
    // 0x801371F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mnPlayersVSSelectFighterPuck(rdram, ctx);
        goto after_0;
    // 0x801371F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x801371FC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80137200: lw          $t2, -0x4234($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4234);
    // 0x80137204: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80137208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013720C: addiu       $t3, $t2, 0x1E
    ctx->r11 = ADD32(ctx->r10, 0X1E);
    // 0x80137210: b           L_80137224
    // 0x80137214: sw          $t3, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r11;
        goto L_80137224;
    // 0x80137214: sw          $t3, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r11;
L_80137218:
    // 0x80137218: jal         0x800269C0
    // 0x8013721C: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8013721C: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_1:
    // 0x80137220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137224:
    // 0x80137224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013722C: jr          $ra
    // 0x80137230: nop

    return;
    // 0x80137230: nop

;}
RECOMP_FUNC void syUtilsQSortIntern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018AB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018ABC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80018AC0: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80018AC4: addiu       $s3, $s3, -0x46B8
    ctx->r19 = ADD32(ctx->r19, -0X46B8);
    // 0x80018AC8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80018ACC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80018AD0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80018AD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80018AD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80018ADC: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80018AE0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80018AE4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80018AE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018AEC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80018AF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80018AF4: beq         $at, $zero, L_80018BF0
    if (ctx->r1 == 0) {
        // 0x80018AF8: addu        $s1, $a1, $t6
        ctx->r17 = ADD32(ctx->r5, ctx->r14);
            goto L_80018BF0;
    }
    // 0x80018AF8: addu        $s1, $a1, $t6
    ctx->r17 = ADD32(ctx->r5, ctx->r14);
    // 0x80018AFC: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80018B00: addiu       $s4, $s4, -0x46B4
    ctx->r20 = ADD32(ctx->r20, -0X46B4);
    // 0x80018B04: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80018B08:
    // 0x80018B08: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x80018B0C: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x80018B10: beql        $at, $zero, L_80018B38
    if (ctx->r1 == 0) {
        // 0x80018B14: lw          $a2, 0x0($s3)
        ctx->r6 = MEM_W(ctx->r19, 0X0);
            goto L_80018B38;
    }
    goto skip_0;
    // 0x80018B14: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80018B18: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80018B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80018B20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018B24: jalr        $t9
    // 0x80018B28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80018B28: nop

    after_0:
    // 0x80018B2C: blezl       $v0, L_80018B08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80018B30: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80018B08;
    }
    goto skip_1;
    // 0x80018B30: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x80018B34: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
L_80018B38:
    // 0x80018B38: subu        $s1, $s1, $a2
    ctx->r17 = SUB32(ctx->r17, ctx->r6);
    // 0x80018B3C: sltu        $at, $s2, $s1
    ctx->r1 = ctx->r18 < ctx->r17 ? 1 : 0;
    // 0x80018B40: beql        $at, $zero, L_80018B6C
    if (ctx->r1 == 0) {
        // 0x80018B44: sltu        $at, $s0, $s1
        ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
            goto L_80018B6C;
    }
    goto skip_2;
    // 0x80018B44: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    skip_2:
    // 0x80018B48: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80018B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80018B50: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018B54: jalr        $t9
    // 0x80018B58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80018B58: nop

    after_1:
    // 0x80018B5C: bgezl       $v0, L_80018B38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018B60: lw          $a2, 0x0($s3)
        ctx->r6 = MEM_W(ctx->r19, 0X0);
            goto L_80018B38;
    }
    goto skip_3;
    // 0x80018B60: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x80018B64: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80018B68: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
L_80018B6C:
    // 0x80018B6C: beq         $at, $zero, L_80018B88
    if (ctx->r1 == 0) {
        // 0x80018B70: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80018B88;
    }
    // 0x80018B70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80018B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80018B78: jal         0x80018A80
    // 0x80018B7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syUtilsSwapMem(rdram, ctx);
        goto after_2;
    // 0x80018B7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80018B80: b           L_80018B08
    // 0x80018B84: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
        goto L_80018B08;
    // 0x80018B84: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80018B88:
    // 0x80018B88: jal         0x80018A80
    // 0x80018B8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syUtilsSwapMem(rdram, ctx);
        goto after_3;
    // 0x80018B8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80018B90: subu        $t8, $s1, $s2
    ctx->r24 = SUB32(ctx->r17, ctx->r18);
    // 0x80018B94: subu        $t0, $s5, $s1
    ctx->r8 = SUB32(ctx->r21, ctx->r17);
    // 0x80018B98: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80018B9C: bnel        $at, $zero, L_80018BC8
    if (ctx->r1 != 0) {
        // 0x80018BA0: lw          $t3, 0x0($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X0);
            goto L_80018BC8;
    }
    goto skip_4;
    // 0x80018BA0: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    skip_4:
    // 0x80018BA4: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80018BA8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80018BAC: jal         0x80018AB8
    // 0x80018BB0: addu        $a0, $s1, $t1
    ctx->r4 = ADD32(ctx->r17, ctx->r9);
    syUtilsQSortIntern(rdram, ctx);
        goto after_4;
    // 0x80018BB0: addu        $a0, $s1, $t1
    ctx->r4 = ADD32(ctx->r17, ctx->r9);
    after_4:
    // 0x80018BB4: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80018BB8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80018BBC: b           L_80018BE4
    // 0x80018BC0: subu        $s5, $s1, $t2
    ctx->r21 = SUB32(ctx->r17, ctx->r10);
        goto L_80018BE4;
    // 0x80018BC0: subu        $s5, $s1, $t2
    ctx->r21 = SUB32(ctx->r17, ctx->r10);
    // 0x80018BC4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
L_80018BC8:
    // 0x80018BC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80018BCC: jal         0x80018AB8
    // 0x80018BD0: subu        $a1, $s1, $t3
    ctx->r5 = SUB32(ctx->r17, ctx->r11);
    syUtilsQSortIntern(rdram, ctx);
        goto after_5;
    // 0x80018BD0: subu        $a1, $s1, $t3
    ctx->r5 = SUB32(ctx->r17, ctx->r11);
    after_5:
    // 0x80018BD4: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80018BD8: addu        $s2, $s1, $a2
    ctx->r18 = ADD32(ctx->r17, ctx->r6);
    // 0x80018BDC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80018BE0: addu        $s1, $s5, $a2
    ctx->r17 = ADD32(ctx->r21, ctx->r6);
L_80018BE4:
    // 0x80018BE4: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x80018BE8: bnel        $at, $zero, L_80018B08
    if (ctx->r1 != 0) {
        // 0x80018BEC: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80018B08;
    }
    goto skip_5;
    // 0x80018BEC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_5:
L_80018BF0:
    // 0x80018BF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80018BF4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80018BF8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80018BFC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80018C00: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80018C04: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80018C08: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80018C0C: jr          $ra
    // 0x80018C10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80018C10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wpDisplayMapCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801671F0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801671F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801671F8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x801671FC: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80167200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80167204: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80167208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8016720C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80167210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80167214: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80167218: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8016721C: lw          $t1, 0x84($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X84);
    // 0x80167220: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80167224: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80167228: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x8016722C: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80167230: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80167234: addiu       $s4, $s4, 0x65D8
    ctx->r20 = ADD32(ctx->r20, 0X65D8);
    // 0x80167238: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8016723C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80167240: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80167244: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80167248: addiu       $t9, $a0, 0x40
    ctx->r25 = ADD32(ctx->r4, 0X40);
    // 0x8016724C: sw          $t9, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r25;
    // 0x80167250: lwc1        $f6, 0x6C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x80167254: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80167258: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8016725C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80167260: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80167264: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80167268: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8016726C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80167270: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80167274: jal         0x8001B9C4
    // 0x80167278: nop

    syMatrixTra(rdram, ctx);
        goto after_0;
    // 0x80167278: nop

    after_0:
    // 0x8016727C: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80167280: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80167284: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x80167288: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x8016728C: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x80167290: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80167294: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80167298: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x8016729C: addiu       $v0, $t1, 0x64
    ctx->r2 = ADD32(ctx->r9, 0X64);
    // 0x801672A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801672A4: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x801672A8: sw          $t5, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r13;
    // 0x801672AC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801672B0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801672B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801672B8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801672BC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801672C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x801672C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801672C8: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801672CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801672D0: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801672D4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801672D8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801672DC: jal         0x8001B780
    // 0x801672E0: nop

    syMatrixSca(rdram, ctx);
        goto after_1;
    // 0x801672E0: nop

    after_1:
    // 0x801672E4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x801672E8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801672EC: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x801672F0: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x801672F4: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x801672F8: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x801672FC: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x80167300: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80167304: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80167308: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8016730C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80167310: addiu       $t3, $t3, -0x3C28
    ctx->r11 = ADD32(ctx->r11, -0X3C28);
    // 0x80167314: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80167318: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8016731C: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x80167320: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80167324: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80167328: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8016732C: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x80167330: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x80167334: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80167338: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x8016733C: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80167340: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80167344: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80167348: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x8016734C: addiu       $t7, $a0, 0x40
    ctx->r15 = ADD32(ctx->r4, 0X40);
    // 0x80167350: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
    // 0x80167354: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80167358: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016735C: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x80167360: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80167364: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80167368: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8016736C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80167370: jal         0x8001B9C4
    // 0x80167374: nop

    syMatrixTra(rdram, ctx);
        goto after_2;
    // 0x80167374: nop

    after_2:
    // 0x80167378: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8016737C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80167380: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x80167384: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80167388: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8016738C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80167390: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80167394: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80167398: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8016739C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801673A0: addiu       $t3, $a0, 0x40
    ctx->r11 = ADD32(ctx->r4, 0X40);
    // 0x801673A4: sw          $t3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r11;
    // 0x801673A8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801673AC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801673B0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801673B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801673B8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801673BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801673C0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801673C4: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801673C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801673CC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801673D0: jal         0x8001B780
    // 0x801673D4: nop

    syMatrixSca(rdram, ctx);
        goto after_3;
    // 0x801673D4: nop

    after_3:
    // 0x801673D8: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x801673DC: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x801673E0: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x801673E4: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801673E8: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x801673EC: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x801673F0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801673F4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x801673F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801673FC: addiu       $t8, $t8, -0x3BA8
    ctx->r24 = ADD32(ctx->r24, -0X3BA8);
    // 0x80167400: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80167404: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80167408: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x8016740C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80167410: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80167414: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80167418: lui         $t3, 0xD838
    ctx->r11 = S32(0XD838 << 16);
    // 0x8016741C: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x80167420: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80167424: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80167428: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x8016742C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80167430: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80167434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80167438: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8016743C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80167440: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80167444: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80167448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016744C: jr          $ra
    // 0x80167450: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80167450: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mvOpeningNewcomersMakeHide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013216C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132170: sw          $zero, 0x274C($at)
    MEM_W(0X274C, ctx->r1) = 0;
    // 0x80132174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013217C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132180: jal         0x80009968
    // 0x80132184: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132184: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132188: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013218C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132190: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132194: addiu       $a1, $a1, 0x2030
    ctx->r5 = ADD32(ctx->r5, 0X2030);
    // 0x80132198: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013219C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801321A0: jal         0x80009DF4
    // 0x801321A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801321A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801321A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801321AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801321B0: jr          $ra
    // 0x801321B4: nop

    return;
    // 0x801321B4: nop

;}
RECOMP_FUNC void sc1PIntroGetFighterVelocityZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132B84: addiu       $t6, $t6, 0x4F90
    ctx->r14 = ADD32(ctx->r14, 0X4F90);
    // 0x80132B88: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B90: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x80132B94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132B98: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132B9C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80132BA0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80132BA4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132BA8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132BAC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80132BB0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80132BB4: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80132BB8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80132BBC: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80132BC0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80132BC4: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80132BC8: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80132BCC: jr          $ra
    // 0x80132BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftMainSearchHitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4870: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800E4874: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800E4878: lw          $t8, 0x66FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X66FC);
    // 0x800E487C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E4880: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800E4884: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800E4888: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E488C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E4890: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E4894: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E4898: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E489C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E48A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E48A4: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800E48A8: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800E48AC: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x800E48B0: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800E48B4: beq         $t8, $zero, L_800E4EA4
    if (ctx->r24 == 0) {
        // 0x800E48B8: sw          $t7, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r15;
            goto L_800E4EA4;
    }
    // 0x800E48B8: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800E48BC: addiu       $fp, $zero, 0xC4
    ctx->r30 = ADD32(0, 0XC4);
L_800E48C0:
    // 0x800E48C0: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800E48C4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800E48C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800E48CC: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800E48D0: bnel        $t9, $t1, L_800E48E4
    if (ctx->r25 != ctx->r9) {
        // 0x800E48D4: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_800E48E4;
    }
    goto skip_0;
    // 0x800E48D4: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    skip_0:
    // 0x800E48D8: b           L_800E4E94
    // 0x800E48DC: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
        goto L_800E4E94;
    // 0x800E48DC: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x800E48E0: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
L_800E48E4:
    // 0x800E48E4: lw          $t5, 0x844($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X844);
    // 0x800E48E8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800E48EC: beql        $t3, $t5, L_800E4E98
    if (ctx->r11 == ctx->r13) {
        // 0x800E48F0: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_800E4E98;
    }
    goto skip_1;
    // 0x800E48F0: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    skip_1:
    // 0x800E48F4: lw          $a3, 0x50E8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X50E8);
    // 0x800E48F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E48FC: lw          $s7, 0x84($t3)
    ctx->r23 = MEM_W(ctx->r11, 0X84);
    // 0x800E4900: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x800E4904: bnel        $t7, $at, L_800E4948
    if (ctx->r15 != ctx->r1) {
        // 0x800E4908: lw          $t2, 0x190($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X190);
            goto L_800E4948;
    }
    goto skip_2;
    // 0x800E4908: lw          $t2, 0x190($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X190);
    skip_2:
    // 0x800E490C: lbu         $t8, 0x9($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X9);
    // 0x800E4910: bnel        $t8, $zero, L_800E4948
    if (ctx->r24 != 0) {
        // 0x800E4914: lw          $t2, 0x190($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X190);
            goto L_800E4948;
    }
    goto skip_3;
    // 0x800E4914: lw          $t2, 0x190($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X190);
    skip_3:
    // 0x800E4918: lw          $t1, 0x278($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X278);
    // 0x800E491C: lbu         $v1, 0xC($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0XC);
    // 0x800E4920: beql        $t1, $zero, L_800E4934
    if (ctx->r9 == 0) {
        // 0x800E4924: lbu         $v0, 0xC($s7)
        ctx->r2 = MEM_BU(ctx->r23, 0XC);
            goto L_800E4934;
    }
    goto skip_4;
    // 0x800E4924: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
    skip_4:
    // 0x800E4928: b           L_800E4934
    // 0x800E492C: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
        goto L_800E4934;
    // 0x800E492C: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
    // 0x800E4930: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
L_800E4934:
    // 0x800E4934: bnel        $v0, $v1, L_800E4948
    if (ctx->r2 != ctx->r3) {
        // 0x800E4938: lw          $t2, 0x190($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X190);
            goto L_800E4948;
    }
    goto skip_5;
    // 0x800E4938: lw          $t2, 0x190($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X190);
    skip_5:
    // 0x800E493C: b           L_800E4E98
    // 0x800E4940: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
        goto L_800E4E98;
    // 0x800E4940: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4944: lw          $t2, 0x190($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X190);
L_800E4948:
    // 0x800E4948: sll         $t3, $t2, 18
    ctx->r11 = S32(ctx->r10 << 18);
    // 0x800E494C: bltzl       $t3, L_800E4E98
    if (SIGNED(ctx->r11) < 0) {
        // 0x800E4950: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_800E4E98;
    }
    goto skip_6;
    // 0x800E4950: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    skip_6:
    // 0x800E4954: lw          $v0, 0x278($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X278);
    // 0x800E4958: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x800E495C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E4960: beq         $v0, $zero, L_800E4978
    if (ctx->r2 == 0) {
        // 0x800E4964: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_800E4978;
    }
    // 0x800E4964: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800E4968: bne         $t5, $v0, L_800E4978
    if (ctx->r13 != ctx->r2) {
        // 0x800E496C: nop
    
            goto L_800E4978;
    }
    // 0x800E496C: nop

    // 0x800E4970: b           L_800E4E98
    // 0x800E4974: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
        goto L_800E4E98;
    // 0x800E4974: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_800E4978:
    // 0x800E4978: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800E497C: addiu       $s6, $s6, 0x11A0
    ctx->r22 = ADD32(ctx->r22, 0X11A0);
    // 0x800E4980: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_800E4984:
    // 0x800E4984: lw          $t6, 0x294($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X294);
    // 0x800E4988: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x800E498C: beql        $t6, $zero, L_800E4A68
    if (ctx->r14 == 0) {
        // 0x800E4990: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_800E4A68;
    }
    goto skip_7;
    // 0x800E4990: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_7:
    // 0x800E4994: lw          $v0, 0x14C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X14C);
    // 0x800E4998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E499C: addiu       $s1, $a1, 0x294
    ctx->r17 = ADD32(ctx->r5, 0X294);
    // 0x800E49A0: bne         $v0, $at, L_800E49B8
    if (ctx->r2 != ctx->r1) {
        // 0x800E49A4: nop
    
            goto L_800E49B8;
    }
    // 0x800E49A4: nop

    // 0x800E49A8: lbu         $t8, 0x3C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3C);
    // 0x800E49AC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800E49B0: bnel        $t9, $zero, L_800E49D0
    if (ctx->r25 != 0) {
        // 0x800E49B4: lbu         $t4, 0x7C($sp)
        ctx->r12 = MEM_BU(ctx->r29, 0X7C);
            goto L_800E49D0;
    }
    goto skip_8;
    // 0x800E49B4: lbu         $t4, 0x7C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7C);
    skip_8:
L_800E49B8:
    // 0x800E49B8: bne         $v0, $zero, L_800E4A64
    if (ctx->r2 != 0) {
        // 0x800E49BC: addiu       $s1, $a1, 0x294
        ctx->r17 = ADD32(ctx->r5, 0X294);
            goto L_800E4A64;
    }
    // 0x800E49BC: addiu       $s1, $a1, 0x294
    ctx->r17 = ADD32(ctx->r5, 0X294);
    // 0x800E49C0: lb          $t2, 0x3D($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3D);
    // 0x800E49C4: bgezl       $t2, L_800E4A68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800E49C8: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_800E4A68;
    }
    goto skip_9;
    // 0x800E49C8: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_9:
    // 0x800E49CC: lbu         $t4, 0x7C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7C);
L_800E49D0:
    // 0x800E49D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E49D4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800E49D8: andi        $t1, $t4, 0xFFBF
    ctx->r9 = ctx->r12 & 0XFFBF;
    // 0x800E49DC: sb          $t1, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r9;
    // 0x800E49E0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800E49E4: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x800E49E8: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800E49EC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800E49F0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800E49F4: sll         $t9, $t7, 7
    ctx->r25 = S32(ctx->r15 << 7);
    // 0x800E49F8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800E49FC: sb          $t6, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r14;
    // 0x800E4A00: ori         $t7, $t6, 0xE
    ctx->r15 = ctx->r14 | 0XE;
    // 0x800E4A04: sb          $t7, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r15;
L_800E4A08:
    // 0x800E4A08: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x800E4A0C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E4A10: bne         $a0, $t8, L_800E4A28
    if (ctx->r4 != ctx->r24) {
        // 0x800E4A14: nop
    
            goto L_800E4A28;
    }
    // 0x800E4A14: nop

    // 0x800E4A18: lw          $t9, 0x60($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X60);
    // 0x800E4A1C: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x800E4A20: b           L_800E4A30
    // 0x800E4A24: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
        goto L_800E4A30;
    // 0x800E4A24: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
L_800E4A28:
    // 0x800E4A28: bne         $v1, $a2, L_800E4A08
    if (ctx->r3 != ctx->r6) {
        // 0x800E4A2C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E4A08;
    }
    // 0x800E4A2C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E4A30:
    // 0x800E4A30: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800E4A34: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x800E4A38: bne         $t4, $zero, L_800E4A64
    if (ctx->r12 != 0) {
        // 0x800E4A3C: sll         $t6, $t2, 1
        ctx->r14 = S32(ctx->r10 << 1);
            goto L_800E4A64;
    }
    // 0x800E4A3C: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x800E4A40: bltz        $t6, L_800E4A64
    if (SIGNED(ctx->r14) < 0) {
        // 0x800E4A44: sll         $t7, $t2, 4
        ctx->r15 = S32(ctx->r10 << 4);
            goto L_800E4A64;
    }
    // 0x800E4A44: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x800E4A48: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x800E4A4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E4A50: bne         $t8, $at, L_800E4A64
    if (ctx->r24 != ctx->r1) {
        // 0x800E4A54: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800E4A64;
    }
    // 0x800E4A54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800E4A58: sw          $t3, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r11;
    // 0x800E4A5C: b           L_800E4A68
    // 0x800E4A60: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_800E4A68;
    // 0x800E4A60: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800E4A64:
    // 0x800E4A64: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
L_800E4A68:
    // 0x800E4A68: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E4A6C: addiu       $t1, $t1, 0x11B0
    ctx->r9 = ADD32(ctx->r9, 0X11B0);
    // 0x800E4A70: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800E4A74: sltu        $at, $s6, $t1
    ctx->r1 = ctx->r22 < ctx->r9 ? 1 : 0;
    // 0x800E4A78: bne         $at, $zero, L_800E4984
    if (ctx->r1 != 0) {
        // 0x800E4A7C: addiu       $a1, $a1, 0xC4
        ctx->r5 = ADD32(ctx->r5, 0XC4);
            goto L_800E4984;
    }
    // 0x800E4A7C: addiu       $a1, $a1, 0xC4
    ctx->r5 = ADD32(ctx->r5, 0XC4);
    // 0x800E4A80: bne         $s4, $zero, L_800E4A90
    if (ctx->r20 != 0) {
        // 0x800E4A84: lw          $t9, 0x68($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X68);
            goto L_800E4A90;
    }
    // 0x800E4A84: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800E4A88: b           L_800E4E98
    // 0x800E4A8C: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
        goto L_800E4E98;
    // 0x800E4A8C: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_800E4A90:
    // 0x800E4A90: beq         $t9, $zero, L_800E4CE4
    if (ctx->r25 == 0) {
        // 0x800E4A94: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E4CE4;
    }
    // 0x800E4A94: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E4A98: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4A9C: lw          $t5, 0x844($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X844);
    // 0x800E4AA0: beq         $t4, $t5, L_800E4CE4
    if (ctx->r12 == ctx->r13) {
        // 0x800E4AA4: nop
    
            goto L_800E4CE4;
    }
    // 0x800E4AA4: nop

    // 0x800E4AA8: lw          $t6, 0x14C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X14C);
    // 0x800E4AAC: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4AB0: bne         $t6, $zero, L_800E4CE4
    if (ctx->r14 != 0) {
        // 0x800E4AB4: nop
    
            goto L_800E4CE4;
    }
    // 0x800E4AB4: nop

    // 0x800E4AB8: lw          $t7, 0x14C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X14C);
    // 0x800E4ABC: bne         $t7, $zero, L_800E4CE4
    if (ctx->r15 != 0) {
        // 0x800E4AC0: nop
    
            goto L_800E4CE4;
    }
    // 0x800E4AC0: nop

    // 0x800E4AC4: lw          $t8, 0x190($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X190);
    // 0x800E4AC8: sll         $t1, $t8, 18
    ctx->r9 = S32(ctx->r24 << 18);
    // 0x800E4ACC: bltz        $t1, L_800E4CE4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800E4AD0: nop
    
            goto L_800E4CE4;
    }
    // 0x800E4AD0: nop

    // 0x800E4AD4: lw          $v0, 0x278($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X278);
    // 0x800E4AD8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4ADC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E4AE0: beq         $v0, $zero, L_800E4B30
    if (ctx->r2 == 0) {
        // 0x800E4AE4: lw          $a2, 0xA0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XA0);
            goto L_800E4B30;
    }
    // 0x800E4AE4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4AE8: beq         $t9, $v0, L_800E4CE4
    if (ctx->r25 == ctx->r2) {
        // 0x800E4AEC: nop
    
            goto L_800E4CE4;
    }
    // 0x800E4AEC: nop

    // 0x800E4AF0: lbu         $t4, 0x2($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2);
    // 0x800E4AF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E4AF8: bne         $t4, $at, L_800E4B30
    if (ctx->r12 != ctx->r1) {
        // 0x800E4AFC: nop
    
            goto L_800E4B30;
    }
    // 0x800E4AFC: nop

    // 0x800E4B00: lbu         $t5, 0x9($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X9);
    // 0x800E4B04: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4B08: bne         $t5, $zero, L_800E4B30
    if (ctx->r13 != 0) {
        // 0x800E4B0C: nop
    
            goto L_800E4B30;
    }
    // 0x800E4B0C: nop

    // 0x800E4B10: lw          $t6, 0x278($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X278);
    // 0x800E4B14: beql        $t6, $zero, L_800E4B28
    if (ctx->r14 == 0) {
        // 0x800E4B18: lbu         $v0, 0xC($s7)
        ctx->r2 = MEM_BU(ctx->r23, 0XC);
            goto L_800E4B28;
    }
    goto skip_10;
    // 0x800E4B18: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
    skip_10:
    // 0x800E4B1C: b           L_800E4B28
    // 0x800E4B20: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
        goto L_800E4B28;
    // 0x800E4B20: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
    // 0x800E4B24: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
L_800E4B28:
    // 0x800E4B28: lbu         $t8, 0x280($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X280);
    // 0x800E4B2C: beq         $v0, $t8, L_800E4CE4
    if (ctx->r2 == ctx->r24) {
        // 0x800E4B30: lui         $a3, 0x8013
        ctx->r7 = S32(0X8013 << 16);
            goto L_800E4CE4;
    }
L_800E4B30:
    // 0x800E4B30: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800E4B34: addiu       $a3, $a3, 0x11B0
    ctx->r7 = ADD32(ctx->r7, 0X11B0);
L_800E4B38:
    // 0x800E4B38: lw          $t3, 0x294($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X294);
    // 0x800E4B3C: beql        $t3, $zero, L_800E4C1C
    if (ctx->r11 == 0) {
        // 0x800E4B40: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_800E4C1C;
    }
    goto skip_11;
    // 0x800E4B40: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_11:
    // 0x800E4B44: lw          $v0, 0x14C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14C);
    // 0x800E4B48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E4B4C: addiu       $a0, $a2, 0x294
    ctx->r4 = ADD32(ctx->r6, 0X294);
    // 0x800E4B50: bne         $v0, $at, L_800E4B68
    if (ctx->r2 != ctx->r1) {
        // 0x800E4B54: nop
    
            goto L_800E4B68;
    }
    // 0x800E4B54: nop

    // 0x800E4B58: lbu         $t1, 0x3C($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3C);
    // 0x800E4B5C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800E4B60: bnel        $t2, $zero, L_800E4B80
    if (ctx->r10 != 0) {
        // 0x800E4B64: lbu         $t5, 0x80($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X80);
            goto L_800E4B80;
    }
    goto skip_12;
    // 0x800E4B64: lbu         $t5, 0x80($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X80);
    skip_12:
L_800E4B68:
    // 0x800E4B68: bne         $v0, $zero, L_800E4C18
    if (ctx->r2 != 0) {
        // 0x800E4B6C: addiu       $a0, $a2, 0x294
        ctx->r4 = ADD32(ctx->r6, 0X294);
            goto L_800E4C18;
    }
    // 0x800E4B6C: addiu       $a0, $a2, 0x294
    ctx->r4 = ADD32(ctx->r6, 0X294);
    // 0x800E4B70: lb          $t4, 0x3D($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X3D);
    // 0x800E4B74: bgezl       $t4, L_800E4C1C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E4B78: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_800E4C1C;
    }
    goto skip_13;
    // 0x800E4B78: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_13:
    // 0x800E4B7C: lbu         $t5, 0x80($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X80);
L_800E4B80:
    // 0x800E4B80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E4B84: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4B88: andi        $t9, $t5, 0xFFBF
    ctx->r25 = ctx->r13 & 0XFFBF;
    // 0x800E4B8C: sb          $t9, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r25;
    // 0x800E4B90: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800E4B94: andi        $t4, $t9, 0x7F
    ctx->r12 = ctx->r25 & 0X7F;
    // 0x800E4B98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E4B9C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800E4BA0: srl         $t3, $t8, 31
    ctx->r11 = S32(U32(ctx->r24) >> 31);
    // 0x800E4BA4: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x800E4BA8: or          $t8, $t2, $t4
    ctx->r24 = ctx->r10 | ctx->r12;
    // 0x800E4BAC: sb          $t8, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r24;
    // 0x800E4BB0: ori         $t3, $t8, 0xE
    ctx->r11 = ctx->r24 | 0XE;
    // 0x800E4BB4: sb          $t3, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r11;
    // 0x800E4BB8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_800E4BBC:
    // 0x800E4BBC: lw          $t1, 0x5C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5C);
    // 0x800E4BC0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E4BC4: bne         $a0, $t1, L_800E4BDC
    if (ctx->r4 != ctx->r9) {
        // 0x800E4BC8: nop
    
            goto L_800E4BDC;
    }
    // 0x800E4BC8: nop

    // 0x800E4BCC: lw          $t2, 0x60($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X60);
    // 0x800E4BD0: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x800E4BD4: b           L_800E4BE4
    // 0x800E4BD8: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
        goto L_800E4BE4;
    // 0x800E4BD8: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_800E4BDC:
    // 0x800E4BDC: bne         $v1, $a1, L_800E4BBC
    if (ctx->r3 != ctx->r5) {
        // 0x800E4BE0: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E4BBC;
    }
    // 0x800E4BE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E4BE4:
    // 0x800E4BE4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800E4BE8: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x800E4BEC: bne         $t5, $zero, L_800E4C18
    if (ctx->r13 != 0) {
        // 0x800E4BF0: sll         $t8, $t4, 1
        ctx->r24 = S32(ctx->r12 << 1);
            goto L_800E4C18;
    }
    // 0x800E4BF0: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x800E4BF4: bltz        $t8, L_800E4C18
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E4BF8: sll         $t3, $t4, 4
        ctx->r11 = S32(ctx->r12 << 4);
            goto L_800E4C18;
    }
    // 0x800E4BF8: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x800E4BFC: srl         $t1, $t3, 29
    ctx->r9 = S32(U32(ctx->r11) >> 29);
    // 0x800E4C00: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E4C04: bne         $t1, $at, L_800E4C18
    if (ctx->r9 != ctx->r1) {
        // 0x800E4C08: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800E4C18;
    }
    // 0x800E4C08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E4C0C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800E4C10: b           L_800E4C1C
    // 0x800E4C14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800E4C1C;
    // 0x800E4C14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800E4C18:
    // 0x800E4C18: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800E4C1C:
    // 0x800E4C1C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800E4C20: addiu       $t9, $t9, 0x11C0
    ctx->r25 = ADD32(ctx->r25, 0X11C0);
    // 0x800E4C24: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800E4C28: sltu        $at, $a3, $t9
    ctx->r1 = ctx->r7 < ctx->r25 ? 1 : 0;
    // 0x800E4C2C: bne         $at, $zero, L_800E4B38
    if (ctx->r1 != 0) {
        // 0x800E4C30: addiu       $a2, $a2, 0xC4
        ctx->r6 = ADD32(ctx->r6, 0XC4);
            goto L_800E4B38;
    }
    // 0x800E4C30: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
    // 0x800E4C34: beq         $t0, $zero, L_800E4CE4
    if (ctx->r8 == 0) {
        // 0x800E4C38: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800E4CE4;
    }
    // 0x800E4C38: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800E4C3C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800E4C40: addiu       $s6, $s6, 0x11A0
    ctx->r22 = ADD32(ctx->r22, 0X11A0);
L_800E4C44:
    // 0x800E4C44: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x800E4C48: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800E4C4C: addiu       $s2, $s2, 0x11B0
    ctx->r18 = ADD32(ctx->r18, 0X11B0);
    // 0x800E4C50: beq         $t2, $zero, L_800E4CD4
    if (ctx->r10 == 0) {
        // 0x800E4C54: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800E4CD4;
    }
    // 0x800E4C54: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800E4C58:
    // 0x800E4C58: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800E4C5C: beql        $t5, $zero, L_800E4CC8
    if (ctx->r13 == 0) {
        // 0x800E4C60: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800E4CC8;
    }
    goto skip_14;
    // 0x800E4C60: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_14:
    // 0x800E4C64: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4C68: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4C6C: mflo        $t7
    ctx->r15 = lo;
    // 0x800E4C70: addu        $s1, $s7, $t7
    ctx->r17 = ADD32(ctx->r23, ctx->r15);
    // 0x800E4C74: addiu       $s1, $s1, 0x294
    ctx->r17 = ADD32(ctx->r17, 0X294);
    // 0x800E4C78: multu       $s3, $fp
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E4C80: mflo        $t4
    ctx->r12 = lo;
    // 0x800E4C84: addu        $s0, $t8, $t4
    ctx->r16 = ADD32(ctx->r24, ctx->r12);
    // 0x800E4C88: addiu       $s0, $s0, 0x294
    ctx->r16 = ADD32(ctx->r16, 0X294);
    // 0x800E4C8C: jal         0x800EFABC
    // 0x800E4C90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmCollisionCheckFighterAttacksCollide(rdram, ctx);
        goto after_0;
    // 0x800E4C90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800E4C94: beq         $v0, $zero, L_800E4CC4
    if (ctx->r2 == 0) {
        // 0x800E4C98: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800E4CC4;
    }
    // 0x800E4C98: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E4C9C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4CA0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4CA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E4CA8: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4CAC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800E4CB0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800E4CB4: jal         0x800E2910
    // 0x800E4CB8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    ftMainUpdateAttackStatFighter(rdram, ctx);
        goto after_1;
    // 0x800E4CB8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
    // 0x800E4CBC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800E4CC0: beq         $t6, $zero, L_800E4CD4
    if (ctx->r14 == 0) {
        // 0x800E4CC4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800E4CD4;
    }
L_800E4CC4:
    // 0x800E4CC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800E4CC8:
    // 0x800E4CC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E4CCC: bne         $s3, $at, L_800E4C58
    if (ctx->r19 != ctx->r1) {
        // 0x800E4CD0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800E4C58;
    }
    // 0x800E4CD0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800E4CD4:
    // 0x800E4CD4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E4CD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E4CDC: bne         $s5, $at, L_800E4C44
    if (ctx->r21 != ctx->r1) {
        // 0x800E4CE0: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E4C44;
    }
    // 0x800E4CE0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_800E4CE4:
    // 0x800E4CE4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800E4CE8: addiu       $s6, $s6, 0x11A0
    ctx->r22 = ADD32(ctx->r22, 0X11A0);
    // 0x800E4CEC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800E4CF0:
    // 0x800E4CF0: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x800E4CF4: beql        $t9, $zero, L_800E4D24
    if (ctx->r25 == 0) {
        // 0x800E4CF8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800E4D24;
    }
    goto skip_15;
    // 0x800E4CF8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_15:
    // 0x800E4CFC: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4D00: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4D04: mflo        $t2
    ctx->r10 = lo;
    // 0x800E4D08: addu        $a0, $s7, $t2
    ctx->r4 = ADD32(ctx->r23, ctx->r10);
    // 0x800E4D0C: jal         0x800EF364
    // 0x800E4D10: addiu       $a0, $a0, 0x294
    ctx->r4 = ADD32(ctx->r4, 0X294);
    gmCollisionCheckFighterInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800E4D10: addiu       $a0, $a0, 0x294
    ctx->r4 = ADD32(ctx->r4, 0X294);
    after_2:
    // 0x800E4D14: beq         $v0, $zero, L_800E4D20
    if (ctx->r2 == 0) {
        // 0x800E4D18: sw          $v0, 0x0($s6)
        MEM_W(0X0, ctx->r22) = ctx->r2;
            goto L_800E4D20;
    }
    // 0x800E4D18: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x800E4D1C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800E4D20:
    // 0x800E4D20: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800E4D24:
    // 0x800E4D24: slti        $at, $s5, 0x4
    ctx->r1 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x800E4D28: bne         $at, $zero, L_800E4CF0
    if (ctx->r1 != 0) {
        // 0x800E4D2C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E4CF0;
    }
    // 0x800E4D2C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800E4D30: beq         $s4, $zero, L_800E4E94
    if (ctx->r20 == 0) {
        // 0x800E4D34: lw          $t5, 0xA0($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA0);
            goto L_800E4E94;
    }
    // 0x800E4D34: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4D38: lw          $t7, 0x18C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18C);
    // 0x800E4D3C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800E4D40: addiu       $s6, $s6, 0x11A0
    ctx->r22 = ADD32(ctx->r22, 0X11A0);
    // 0x800E4D44: sll         $t4, $t7, 26
    ctx->r12 = S32(ctx->r15 << 26);
    // 0x800E4D48: bgez        $t4, L_800E4DB4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E4D4C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800E4DB4;
    }
    // 0x800E4D4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800E4D50:
    // 0x800E4D50: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x800E4D54: beql        $t3, $zero, L_800E4DA8
    if (ctx->r11 == 0) {
        // 0x800E4D58: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800E4DA8;
    }
    goto skip_16;
    // 0x800E4D58: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_16:
    // 0x800E4D5C: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4D60: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4D64: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4D68: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x800E4D6C: lw          $a2, 0x8F4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8F4);
    // 0x800E4D70: mflo        $t1
    ctx->r9 = lo;
    // 0x800E4D74: addu        $s1, $s7, $t1
    ctx->r17 = ADD32(ctx->r23, ctx->r9);
    // 0x800E4D78: addiu       $s1, $s1, 0x294
    ctx->r17 = ADD32(ctx->r17, 0X294);
    // 0x800E4D7C: jal         0x800EFCC0
    // 0x800E4D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCollisionCheckFighterAttackShieldCollide(rdram, ctx);
        goto after_3;
    // 0x800E4D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800E4D84: beq         $v0, $zero, L_800E4DA4
    if (ctx->r2 == 0) {
        // 0x800E4D88: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800E4DA4;
    }
    // 0x800E4D88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E4D8C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4D90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E4D94: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4D98: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4D9C: jal         0x800E2A90
    // 0x800E4DA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    ftMainUpdateShieldStatFighter(rdram, ctx);
        goto after_4;
    // 0x800E4DA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
L_800E4DA4:
    // 0x800E4DA4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800E4DA8:
    // 0x800E4DA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E4DAC: bne         $s5, $at, L_800E4D50
    if (ctx->r21 != ctx->r1) {
        // 0x800E4DB0: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E4D50;
    }
    // 0x800E4DB0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_800E4DB4:
    // 0x800E4DB4: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4DB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E4DBC: lw          $t5, 0x5AC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X5AC);
    // 0x800E4DC0: beql        $t5, $at, L_800E4E98
    if (ctx->r13 == ctx->r1) {
        // 0x800E4DC4: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_800E4E98;
    }
    goto skip_17;
    // 0x800E4DC4: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    skip_17:
    // 0x800E4DC8: lw          $t7, 0x5B4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X5B4);
    // 0x800E4DCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E4DD0: beql        $t7, $at, L_800E4E98
    if (ctx->r15 == ctx->r1) {
        // 0x800E4DD4: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_800E4E98;
    }
    goto skip_18;
    // 0x800E4DD4: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    skip_18:
    // 0x800E4DD8: lw          $t8, 0x5B8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X5B8);
    // 0x800E4DDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E4DE0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800E4DE4: beq         $t8, $at, L_800E4E94
    if (ctx->r24 == ctx->r1) {
        // 0x800E4DE8: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800E4E94;
    }
    // 0x800E4DE8: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800E4DEC: addiu       $s6, $s6, 0x11A0
    ctx->r22 = ADD32(ctx->r22, 0X11A0);
L_800E4DF0:
    // 0x800E4DF0: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x800E4DF4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E4DF8: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4DFC: beql        $t4, $zero, L_800E4E88
    if (ctx->r12 == 0) {
        // 0x800E4E00: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800E4E88;
    }
    goto skip_19;
    // 0x800E4E00: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_19:
L_800E4E04:
    // 0x800E4E04: lw          $t3, 0x5BC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X5BC);
    // 0x800E4E08: addiu       $s0, $s2, 0x5BC
    ctx->r16 = ADD32(ctx->r18, 0X5BC);
    // 0x800E4E0C: beq         $t3, $zero, L_800E4E84
    if (ctx->r11 == 0) {
        // 0x800E4E10: nop
    
            goto L_800E4E84;
    }
    // 0x800E4E10: nop

    // 0x800E4E14: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800E4E18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E4E1C: beql        $t1, $at, L_800E4E78
    if (ctx->r9 == ctx->r1) {
        // 0x800E4E20: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_800E4E78;
    }
    goto skip_20;
    // 0x800E4E20: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    skip_20:
    // 0x800E4E24: multu       $s5, $fp
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4E28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E4E2C: mflo        $t6
    ctx->r14 = lo;
    // 0x800E4E30: addu        $s1, $s7, $t6
    ctx->r17 = ADD32(ctx->r23, ctx->r14);
    // 0x800E4E34: addiu       $s1, $s1, 0x294
    ctx->r17 = ADD32(ctx->r17, 0X294);
    // 0x800E4E38: jal         0x800EFBA4
    // 0x800E4E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCollisionCheckFighterAttackDamageCollide(rdram, ctx);
        goto after_5;
    // 0x800E4E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800E4E40: beql        $v0, $zero, L_800E4E78
    if (ctx->r2 == 0) {
        // 0x800E4E44: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_800E4E78;
    }
    goto skip_21;
    // 0x800E4E44: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    skip_21:
    // 0x800E4E48: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800E4E4C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x800E4E50: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E4E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E4E58: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x800E4E5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800E4E60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800E4E64: jal         0x800E2D44
    // 0x800E4E68: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    ftMainUpdateDamageStatFighter(rdram, ctx);
        goto after_6;
    // 0x800E4E68: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x800E4E6C: b           L_800E4E84
    // 0x800E4E70: nop

        goto L_800E4E84;
    // 0x800E4E70: nop

    // 0x800E4E74: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
L_800E4E78:
    // 0x800E4E78: addiu       $at, $zero, 0x1E4
    ctx->r1 = ADD32(0, 0X1E4);
    // 0x800E4E7C: bne         $s4, $at, L_800E4E04
    if (ctx->r20 != ctx->r1) {
        // 0x800E4E80: addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
            goto L_800E4E04;
    }
    // 0x800E4E80: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
L_800E4E84:
    // 0x800E4E84: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800E4E88:
    // 0x800E4E88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E4E8C: bne         $s5, $at, L_800E4DF0
    if (ctx->r21 != ctx->r1) {
        // 0x800E4E90: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E4DF0;
    }
    // 0x800E4E90: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_800E4E94:
    // 0x800E4E94: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_800E4E98:
    // 0x800E4E98: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x800E4E9C: bne         $t2, $zero, L_800E48C0
    if (ctx->r10 != 0) {
        // 0x800E4EA0: sw          $t2, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r10;
            goto L_800E48C0;
    }
    // 0x800E4EA0: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
L_800E4EA4:
    // 0x800E4EA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E4EA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E4EAC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E4EB0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E4EB4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E4EB8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E4EBC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E4EC0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E4EC4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800E4EC8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800E4ECC: jr          $ra
    // 0x800E4ED0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800E4ED0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itIwarkMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DBA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017DBA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017DBA8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8017DBAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017DBB0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8017DBB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017DBB8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017DBBC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017DBC0: addiu       $a1, $a1, -0x5570
    ctx->r5 = ADD32(ctx->r5, -0X5570);
    // 0x8017DBC4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8017DBC8: jal         0x8016E174
    // 0x8017DBCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017DBCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8017DBD0: beq         $v0, $zero, L_8017DC98
    if (ctx->r2 == 0) {
        // 0x8017DBD4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8017DC98;
    }
    // 0x8017DBD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017DBD8: jal         0x8017279C
    // 0x8017DBDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017DBDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8017DBE0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8017DBE4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017DBE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DBEC: jal         0x80008CC0
    // 0x8017DBF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017DBF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x8017DBF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017DBF8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8017DBFC: jal         0x80008CC0
    // 0x8017DC00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8017DC00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8017DC04: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017DC08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017DC0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017DC10: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017DC14: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017DC18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017DC1C: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8017DC20: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017DC24: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x8017DC28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017DC2C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8017DC30: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8017DC34: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8017DC38: addiu       $t5, $t5, -0x5EC0
    ctx->r13 = ADD32(ctx->r13, -0X5EC0);
    // 0x8017DC3C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8017DC40: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x8017DC44: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8017DC48: addiu       $t7, $t7, 0x3624
    ctx->r15 = ADD32(ctx->r15, 0X3624);
    // 0x8017DC4C: lw          $t1, 0x2D4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017DC50: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017DC54: sb          $t0, 0x154($v1)
    MEM_B(0X154, ctx->r3) = ctx->r8;
    // 0x8017DC58: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8017DC5C: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017DC60: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017DC64: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x8017DC68: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017DC6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017DC70: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8017DC74: nop

    // 0x8017DC78: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017DC7C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017DC80: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8017DC84: lw          $t3, 0x2D4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017DC88: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8017DC8C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8017DC90: jal         0x8000BD1C
    // 0x8017DC94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x8017DC94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_4:
L_8017DC98:
    // 0x8017DC98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017DC9C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8017DCA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017DCA4: jr          $ra
    // 0x8017DCA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017DCA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void grHyruleTwisterCheckGetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AC70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010AC74: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010AC78: lbu         $v0, 0x28($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X28);
    // 0x8010AC7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010AC80: beq         $v0, $at, L_8010AC90
    if (ctx->r2 == ctx->r1) {
        // 0x8010AC84: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8010AC90;
    }
    // 0x8010AC84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010AC88: bnel        $v0, $at, L_8010ACBC
    if (ctx->r2 != ctx->r1) {
        // 0x8010AC8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010ACBC;
    }
    goto skip_0;
    // 0x8010AC8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8010AC90:
    // 0x8010AC90: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8010AC94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010AC98: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010AC9C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8010ACA0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8010ACA4: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8010ACA8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8010ACAC: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8010ACB0: jr          $ra
    // 0x8010ACB4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x8010ACB4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8010ACB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010ACBC:
    // 0x8010ACBC: jr          $ra
    // 0x8010ACC0: nop

    return;
    // 0x8010ACC0: nop

;}
RECOMP_FUNC void mnVSResultsSetPlayerTagPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339F4: addiu       $sp, $sp, -0x218
    ctx->r29 = ADD32(ctx->r29, -0X218);
    // 0x801339F8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801339FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133A00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133A04: addiu       $t7, $t7, -0x6E54
    ctx->r15 = ADD32(ctx->r15, -0X6E54);
    // 0x80133A08: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80133A0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80133A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133A18: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80133A1C: addiu       $t6, $sp, 0x1D0
    ctx->r14 = ADD32(ctx->r29, 0X1D0);
L_80133A20:
    // 0x80133A20: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133A24: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133A28: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133A2C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133A30: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133A34: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133A38: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133A3C: bne         $t7, $t0, L_80133A20
    if (ctx->r15 != ctx->r8) {
        // 0x80133A40: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133A20;
    }
    // 0x80133A40: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133A44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133A48: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133A4C: addiu       $t2, $t2, -0x6E14
    ctx->r10 = ADD32(ctx->r10, -0X6E14);
    // 0x80133A50: addiu       $t5, $t2, 0x60
    ctx->r13 = ADD32(ctx->r10, 0X60);
    // 0x80133A54: addiu       $t1, $sp, 0x170
    ctx->r9 = ADD32(ctx->r29, 0X170);
    // 0x80133A58: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_80133A5C:
    // 0x80133A5C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80133A60: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80133A64: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80133A68: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80133A6C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80133A70: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80133A74: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80133A78: bne         $t2, $t5, L_80133A5C
    if (ctx->r10 != ctx->r13) {
        // 0x80133A7C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80133A5C;
    }
    // 0x80133A7C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80133A80: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133A84: addiu       $t7, $t7, -0x6DB4
    ctx->r15 = ADD32(ctx->r15, -0X6DB4);
    // 0x80133A88: addiu       $t9, $t7, 0x78
    ctx->r25 = ADD32(ctx->r15, 0X78);
    // 0x80133A8C: addiu       $t0, $sp, 0xF0
    ctx->r8 = ADD32(ctx->r29, 0XF0);
L_80133A90:
    // 0x80133A90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80133A94: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133A98: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80133A9C: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80133AA0: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80133AA4: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80133AA8: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80133AAC: bne         $t7, $t9, L_80133A90
    if (ctx->r15 != ctx->r25) {
        // 0x80133AB0: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80133A90;
    }
    // 0x80133AB0: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80133AB4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80133AB8: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80133ABC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133AC0: addiu       $t2, $t2, -0x6D34
    ctx->r10 = ADD32(ctx->r10, -0X6D34);
    // 0x80133AC4: addiu       $t4, $t2, 0xC0
    ctx->r12 = ADD32(ctx->r10, 0XC0);
    // 0x80133AC8: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x80133ACC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80133AD0: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_80133AD4:
    // 0x80133AD4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80133AD8: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80133ADC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80133AE0: sw          $t3, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r11;
    // 0x80133AE4: lw          $t1, -0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, -0X8);
    // 0x80133AE8: sw          $t1, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r9;
    // 0x80133AEC: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x80133AF0: bne         $t2, $t4, L_80133AD4
    if (ctx->r10 != ctx->r12) {
        // 0x80133AF4: sw          $t3, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r11;
            goto L_80133AD4;
    }
    // 0x80133AF4: sw          $t3, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r11;
    // 0x80133AF8: jal         0x80133810
    // 0x80133AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnVSResultsGetSpot(rdram, ctx);
        goto after_0;
    // 0x80133AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80133B00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133B04: jal         0x801321AC
    // 0x80133B08: sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    mnVSResultsGetPlayerDistanceID(rdram, ctx);
        goto after_1;
    // 0x80133B08: sw          $v0, 0x214($sp)
    MEM_W(0X214, ctx->r29) = ctx->r2;
    after_1:
    // 0x80133B0C: jal         0x8013205C
    // 0x80133B10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_2;
    // 0x80133B10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x80133B14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133B18: beq         $v0, $at, L_80133B3C
    if (ctx->r2 == ctx->r1) {
        // 0x80133B1C: lw          $a1, 0x214($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X214);
            goto L_80133B3C;
    }
    // 0x80133B1C: lw          $a1, 0x214($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X214);
    // 0x80133B20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133B24: beq         $v0, $at, L_80133B94
    if (ctx->r2 == ctx->r1) {
        // 0x80133B28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80133B94;
    }
    // 0x80133B28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133B2C: beql        $v0, $at, L_80133BF0
    if (ctx->r2 == ctx->r1) {
        // 0x80133B30: sll         $t9, $s0, 5
        ctx->r25 = S32(ctx->r16 << 5);
            goto L_80133BF0;
    }
    goto skip_0;
    // 0x80133B30: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    skip_0:
    // 0x80133B34: b           L_80133BF0
    // 0x80133B38: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
        goto L_80133BF0;
    // 0x80133B38: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
L_80133B3C:
    // 0x80133B3C: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80133B40: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80133B44: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x80133B48: addiu       $t6, $sp, 0x1D0
    ctx->r14 = ADD32(ctx->r29, 0X1D0);
    // 0x80133B4C: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x80133B50: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133B54: lw          $t8, 0x74($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X74);
    // 0x80133B58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133B5C: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
    // 0x80133B60: jal         0x80133148
    // 0x80133B64: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80133B64: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x80133B68: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80133B6C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80133B70: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80133B74: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x80133B78: addu        $t1, $sp, $t5
    ctx->r9 = ADD32(ctx->r29, ctx->r13);
    // 0x80133B7C: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80133B80: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80133B84: lw          $t3, 0x74($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X74);
    // 0x80133B88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80133B8C: b           L_80133C40
    // 0x80133B90: swc1        $f10, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f10.u32l;
        goto L_80133C40;
    // 0x80133B90: swc1        $f10, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f10.u32l;
L_80133B94:
    // 0x80133B94: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80133B98: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80133B9C: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x80133BA0: addiu       $t6, $sp, 0x170
    ctx->r14 = ADD32(ctx->r29, 0X170);
    // 0x80133BA4: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x80133BA8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133BAC: lw          $t8, 0x74($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X74);
    // 0x80133BB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133BB4: swc1        $f16, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f16.u32l;
    // 0x80133BB8: jal         0x80133148
    // 0x80133BBC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_4;
    // 0x80133BBC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x80133BC0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80133BC4: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80133BC8: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80133BCC: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x80133BD0: addu        $t1, $sp, $t5
    ctx->r9 = ADD32(ctx->r29, ctx->r13);
    // 0x80133BD4: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80133BD8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80133BDC: lw          $t3, 0x74($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X74);
    // 0x80133BE0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80133BE4: b           L_80133C40
    // 0x80133BE8: swc1        $f6, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f6.u32l;
        goto L_80133C40;
    // 0x80133BE8: swc1        $f6, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f6.u32l;
    // 0x80133BEC: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
L_80133BF0:
    // 0x80133BF0: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80133BF4: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x80133BF8: addiu       $t6, $sp, 0xF0
    ctx->r14 = ADD32(ctx->r29, 0XF0);
    // 0x80133BFC: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x80133C00: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133C04: lw          $t8, 0x74($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X74);
    // 0x80133C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133C0C: swc1        $f8, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f8.u32l;
    // 0x80133C10: jal         0x80133148
    // 0x80133C14: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_5;
    // 0x80133C14: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x80133C18: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80133C1C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80133C20: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80133C24: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x80133C28: addu        $t1, $sp, $t5
    ctx->r9 = ADD32(ctx->r29, ctx->r13);
    // 0x80133C2C: lwc1        $f10, 0x30($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80133C30: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80133C34: lw          $t3, 0x74($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X74);
    // 0x80133C38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80133C3C: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_80133C40:
    // 0x80133C40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133C44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133C48: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133C4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133C50: jr          $ra
    // 0x80133C54: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
    return;
    // 0x80133C54: addiu       $sp, $sp, 0x218
    ctx->r29 = ADD32(ctx->r29, 0X218);
;}
RECOMP_FUNC void mvOpeningCliffStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132674: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013267C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132680: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132684: addiu       $a0, $a0, 0x2708
    ctx->r4 = ADD32(ctx->r4, 0X2708);
    // 0x80132688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013268C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132690: jal         0x80007024
    // 0x80132694: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132694: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132698: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8013269C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801326A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801326A4: addiu       $t9, $t9, 0x29A0
    ctx->r25 = ADD32(ctx->r25, 0X29A0);
    // 0x801326A8: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801326AC: addiu       $a0, $a0, 0x2724
    ctx->r4 = ADD32(ctx->r4, 0X2724);
    // 0x801326B0: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801326B4: jal         0x8000683C
    // 0x801326B8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801326B8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801326BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801326C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801326C4: jr          $ra
    // 0x801326C8: nop

    return;
    // 0x801326C8: nop

;}
RECOMP_FUNC void efGroundMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011652C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80116530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80116534: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80116538: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8011653C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80116540: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80116544: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80116548: beq         $t7, $zero, L_80116574
    if (ctx->r15 == 0) {
        // 0x8011654C: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80116574;
    }
    // 0x8011654C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80116550: jal         0x800FD4B8
    // 0x80116554: nop

    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80116554: nop

    after_0:
    // 0x80116558: bne         $v0, $zero, L_80116568
    if (ctx->r2 != 0) {
        // 0x8011655C: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80116568;
    }
    // 0x8011655C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80116560: b           L_80116768
    // 0x80116564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80116768;
    // 0x80116564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80116568:
    // 0x80116568: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8011656C: b           L_80116578
    // 0x80116570: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
        goto L_80116578;
    // 0x80116570: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
L_80116574:
    // 0x80116574: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_80116578:
    // 0x80116578: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8011657C: addiu       $a1, $a1, -0x28EC
    ctx->r5 = ADD32(ctx->r5, -0X28EC);
    // 0x80116580: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80116584: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80116588: jal         0x80009968
    // 0x8011658C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8011658C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80116590: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80116594: bne         $v0, $zero, L_801165B4
    if (ctx->r2 != 0) {
        // 0x80116598: sw          $v0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r2;
            goto L_801165B4;
    }
    // 0x80116598: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8011659C: beq         $a0, $zero, L_801165AC
    if (ctx->r4 == 0) {
        // 0x801165A0: nop
    
            goto L_801165AC;
    }
    // 0x801165A0: nop

    // 0x801165A4: jal         0x800FD4F8
    // 0x801165A8: nop

    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x801165A8: nop

    after_2:
L_801165AC:
    // 0x801165AC: b           L_80116768
    // 0x801165B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80116768;
    // 0x801165B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801165B4:
    // 0x801165B4: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x801165B8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x801165BC: sw          $a0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r4;
    // 0x801165C0: beq         $v1, $at, L_801165DC
    if (ctx->r3 == ctx->r1) {
        // 0x801165C4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_801165DC;
    }
    // 0x801165C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801165C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801165CC: beql        $v1, $at, L_801165E0
    if (ctx->r3 == ctx->r1) {
        // 0x801165D0: sb          $t9, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r25;
            goto L_801165E0;
    }
    goto skip_0;
    // 0x801165D0: sb          $t9, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r25;
    skip_0:
    // 0x801165D4: b           L_801165E0
    // 0x801165D8: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
        goto L_801165E0;
    // 0x801165D8: sb          $zero, 0x38($a0)
    MEM_B(0X38, ctx->r4) = 0;
L_801165DC:
    // 0x801165DC: sb          $t9, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r25;
L_801165E0:
    // 0x801165E0: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x801165E4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x801165E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801165EC: bne         $a1, $zero, L_801165FC
    if (ctx->r5 != 0) {
        // 0x801165F0: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_801165FC;
    }
    // 0x801165F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801165F4: b           L_80116768
    // 0x801165F8: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
        goto L_80116768;
    // 0x801165F8: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
L_801165FC:
    // 0x801165FC: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x80116600: jal         0x80009DF4
    // 0x80116604: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80116604: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x80116608: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8011660C: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x80116610: jal         0x8000A14C
    // 0x80116614: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    gcMoveGObjDLHead(rdram, ctx);
        goto after_4;
    // 0x80116614: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    after_4:
    // 0x80116618: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x8011661C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80116620: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80116624: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80116628: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x8011662C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80116630: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80116634: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80116638: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8011663C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80116640: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80116644: beq         $t7, $zero, L_80116764
    if (ctx->r15 == 0) {
        // 0x80116648: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_80116764;
    }
    // 0x80116648: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8011664C: jal         0x800092D0
    // 0x80116650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80116650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80116654: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80116658: addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // 0x8011665C: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80116660: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x80116664: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x80116668: jal         0x800C89BC
    // 0x8011666C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_6;
    // 0x8011666C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80116670: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80116674: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80116678: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8011667C: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80116680: beq         $t9, $zero, L_801166C8
    if (ctx->r25 == 0) {
        // 0x80116684: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_801166C8;
    }
    // 0x80116684: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80116688: addiu       $v1, $s0, 0xB
    ctx->r3 = ADD32(ctx->r16, 0XB);
    // 0x8011668C: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x80116690: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x80116694: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x80116698: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8011669C: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x801166A0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801166A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801166A8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x801166AC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801166B0: jal         0x8011633C
    // 0x801166B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    efGroundSetupEffectDObjs(rdram, ctx);
        goto after_7;
    // 0x801166B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_7:
    // 0x801166B8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x801166BC: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x801166C0: b           L_801166F4
    // 0x801166C4: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
        goto L_801166F4;
    // 0x801166C4: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_801166C8:
    // 0x801166C8: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x801166CC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801166D0: jal         0x800093F4
    // 0x801166D4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddChildForDObj(rdram, ctx);
        goto after_8;
    // 0x801166D4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x801166D8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801166DC: addiu       $v1, $s0, 0xB
    ctx->r3 = ADD32(ctx->r16, 0XB);
    // 0x801166E0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x801166E4: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x801166E8: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x801166EC: jal         0x800C89BC
    // 0x801166F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_9;
    // 0x801166F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
L_801166F4:
    // 0x801166F4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x801166F8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801166FC: beq         $v0, $zero, L_8011670C
    if (ctx->r2 == 0) {
        // 0x80116700: addu        $a1, $t9, $v0
        ctx->r5 = ADD32(ctx->r25, ctx->r2);
            goto L_8011670C;
    }
    // 0x80116700: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    // 0x80116704: jal         0x800C9228
    // 0x80116708: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    lbCommonAddMObjForTreeDObjs(rdram, ctx);
        goto after_10;
    // 0x80116708: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_10:
L_8011670C:
    // 0x8011670C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80116710: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80116714: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80116718: bne         $v0, $zero, L_80116728
    if (ctx->r2 != 0) {
        // 0x8011671C: nop
    
            goto L_80116728;
    }
    // 0x8011671C: nop

    // 0x80116720: beql        $v1, $zero, L_80116768
    if (ctx->r3 == 0) {
        // 0x80116724: lw          $v0, 0x6C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X6C);
            goto L_80116768;
    }
    goto skip_1;
    // 0x80116724: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    skip_1:
L_80116728:
    // 0x80116728: beq         $v0, $zero, L_8011673C
    if (ctx->r2 == 0) {
        // 0x8011672C: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8011673C;
    }
    // 0x8011672C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80116730: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80116734: b           L_80116740
    // 0x80116738: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
        goto L_80116740;
    // 0x80116738: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
L_8011673C:
    // 0x8011673C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80116740:
    // 0x80116740: beq         $v1, $zero, L_80116754
    if (ctx->r3 == 0) {
        // 0x80116744: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80116754;
    }
    // 0x80116744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80116748: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8011674C: b           L_80116754
    // 0x80116750: addu        $a2, $t1, $v1
    ctx->r6 = ADD32(ctx->r9, ctx->r3);
        goto L_80116754;
    // 0x80116750: addu        $a2, $t1, $v1
    ctx->r6 = ADD32(ctx->r9, ctx->r3);
L_80116754:
    // 0x80116754: jal         0x800C88AC
    // 0x80116758: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_11;
    // 0x80116758: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x8011675C: jal         0x8000DF34
    // 0x80116760: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    gcPlayAnimAll(rdram, ctx);
        goto after_12;
    // 0x80116760: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_12:
L_80116764:
    // 0x80116764: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
L_80116768:
    // 0x80116768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8011676C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80116770: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80116774: jr          $ra
    // 0x80116778: nop

    return;
    // 0x80116778: nop

;}
RECOMP_FUNC void ftLinkSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163778: jal         0x80163708
    // 0x8016377C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftLinkSpecialNMakeBoomerang(rdram, ctx);
        goto after_0;
    // 0x8016377C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163780: jal         0x800D94C4
    // 0x80163784: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x80163784: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80163788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016378C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163790: jr          $ra
    // 0x80163794: nop

    return;
    // 0x80163794: nop

;}
RECOMP_FUNC void itMSBombExplodeUpdateAttackEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176C14: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176C18: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80176C1C: lw          $t6, -0x61AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X61AC);
    // 0x80176C20: lw          $a1, 0x340($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X340);
    // 0x80176C24: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80176C28: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80176C2C: addiu       $t8, $t8, 0x404
    ctx->r24 = ADD32(ctx->r24, 0X404);
    // 0x80176C30: srl         $a1, $a1, 28
    ctx->r5 = S32(U32(ctx->r5) >> 28);
    // 0x80176C34: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80176C38: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80176C3C: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x80176C40: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x80176C44: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80176C48: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x80176C4C: bne         $t0, $t1, L_80176CF8
    if (ctx->r8 != ctx->r9) {
        // 0x80176C50: nop
    
            goto L_80176CF8;
    }
    // 0x80176C50: nop

    // 0x80176C54: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80176C58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80176C5C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80176C60: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x80176C64: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x80176C68: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80176C6C: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x80176C70: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x80176C74: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x80176C78: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    // 0x80176C7C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80176C80: bgez        $t8, L_80176C94
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80176C84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80176C94;
    }
    // 0x80176C84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80176C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80176C8C: nop

    // 0x80176C90: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80176C94:
    // 0x80176C94: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x80176C98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80176C9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80176CA0: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x80176CA4: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x80176CA8: andi        $t4, $t2, 0xF7
    ctx->r12 = ctx->r10 & 0XF7;
    // 0x80176CAC: lbu         $t2, 0x340($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X340);
    // 0x80176CB0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80176CB4: sb          $t4, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r12;
    // 0x80176CB8: andi        $t6, $t4, 0xFB
    ctx->r14 = ctx->r12 & 0XFB;
    // 0x80176CBC: andi        $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 & 0XF0;
    // 0x80176CC0: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80176CC4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80176CC8: sb          $t4, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r12;
    // 0x80176CCC: lw          $t5, 0x340($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X340);
    // 0x80176CD0: sb          $t6, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r14;
    // 0x80176CD4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80176CD8: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80176CDC: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x80176CE0: sb          $t7, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r15;
    // 0x80176CE4: bne         $t6, $at, L_80176CF8
    if (ctx->r14 != ctx->r1) {
        // 0x80176CE8: sw          $t8, 0x11C($v0)
        MEM_W(0X11C, ctx->r2) = ctx->r24;
            goto L_80176CF8;
    }
    // 0x80176CE8: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
    // 0x80176CEC: andi        $t8, $t4, 0xF
    ctx->r24 = ctx->r12 & 0XF;
    // 0x80176CF0: ori         $t9, $t8, 0x30
    ctx->r25 = ctx->r24 | 0X30;
    // 0x80176CF4: sb          $t9, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r25;
L_80176CF8:
    // 0x80176CF8: jr          $ra
    // 0x80176CFC: nop

    return;
    // 0x80176CFC: nop

;}
RECOMP_FUNC void lbTransitionMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4130: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D4134: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800D4138: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D413C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D4140: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800D4144: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x800D4148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D414C: jal         0x80009968
    // 0x800D4150: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D4150: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D4154: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800D4158: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800D415C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x800D4160: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D4164: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800D4168: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800D416C: addiu       $a1, $a1, 0x7DBC
    ctx->r5 = ADD32(ctx->r5, 0X7DBC);
    // 0x800D4170: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D4174: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D4178: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D417C: jal         0x80009F74
    // 0x800D4180: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80009F74(rdram, ctx);
        goto after_1;
    // 0x800D4180: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800D4184: jal         0x80009760
    // 0x800D4188: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    gcAddCameraForGObj(rdram, ctx);
        goto after_2;
    // 0x800D4188: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800D418C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D4190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D4194: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D4198: jal         0x80008CF0
    // 0x800D419C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddXObjForCamera(rdram, ctx);
        goto after_3;
    // 0x800D419C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800D41A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D41A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D41A8: jal         0x80008CF0
    // 0x800D41AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddXObjForCamera(rdram, ctx);
        goto after_4;
    // 0x800D41AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800D41B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800D41B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D41B8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800D41BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D41C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D41C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800D41C8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x800D41CC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x800D41D0: jal         0x80007080
    // 0x800D41D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_5;
    // 0x800D41D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800D41D8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800D41DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D41E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D41E4: lwc1        $f6, 0x62A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62A0);
    // 0x800D41E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D41EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D41F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D41F4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800D41F8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D41FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800D4200: lwc1        $f16, 0x62A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62A4);
    // 0x800D4204: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800D4208: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D420C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800D4210: jal         0x800184E0
    // 0x800D4214: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    syUtilsTan(rdram, ctx);
        goto after_6;
    // 0x800D4214: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    after_6:
    // 0x800D4218: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D421C: lwc1        $f6, 0x62A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62A8);
    // 0x800D4220: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x800D4224: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D4228: ori         $t0, $t9, 0x5
    ctx->r8 = ctx->r25 | 0X5;
    // 0x800D422C: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x800D4230: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x800D4234: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4238: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800D423C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800D4240: jr          $ra
    // 0x800D4244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D4244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftNessAppearWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DEC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013DEC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013DEC8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013DECC: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8013DED0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8013DED4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013DED8: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8013DEDC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013DEE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013DEE4: jal         0x800E6F24
    // 0x8013DEE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013DEE8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013DEEC: jal         0x8013DBAC
    // 0x8013DEF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonAppearInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8013DEF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013DEF4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013DEF8: lbu         $t8, 0x18E($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013DEFC: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8013DF00: sb          $t9, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r25;
    // 0x8013DF04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DF08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013DF0C: jr          $ra
    // 0x8013DF10: nop

    return;
    // 0x8013DF10: nop

;}
RECOMP_FUNC void mnVSResultsMakeKOs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013569C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801356A0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801356A4: lw          $t9, -0x5FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB8);
    // 0x801356A8: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801356AC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801356B0: addiu       $t0, $t0, 0xD38
    ctx->r8 = ADD32(ctx->r8, 0XD38);
    // 0x801356B4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801356B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801356BC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801356C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801356C4: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x801356C8: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x801356CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801356D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801356D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801356D8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801356DC: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801356E0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801356E4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801356E8: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801356EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801356F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801356F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801356F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801356FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135700: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80135704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135708: jal         0x800CD050
    // 0x8013570C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x8013570C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80135710: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80135714: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80135718: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x8013571C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80135720: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135724: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80135728: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8013572C: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80135730: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80135734: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80135738: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013573C: swc1        $f10, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f10.u32l;
    // 0x80135740: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135744: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80135748: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x8013574C: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x80135750: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135754: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135758: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x8013575C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80135760: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80135764: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x80135768: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
    // 0x8013576C: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80135770: sb          $zero, 0x29($t1)
    MEM_B(0X29, ctx->r9) = 0;
    // 0x80135774: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x80135778: sb          $zero, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = 0;
    // 0x8013577C: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80135780: sb          $a0, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r4;
    // 0x80135784: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80135788: sb          $a0, 0x29($t4)
    MEM_B(0X29, ctx->r12) = ctx->r4;
    // 0x8013578C: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80135790: sb          $a0, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r4;
    // 0x80135794: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80135798: beq         $t6, $zero, L_801357D8
    if (ctx->r14 == 0) {
        // 0x8013579C: nop
    
            goto L_801357D8;
    }
    // 0x8013579C: nop

    // 0x801357A0: jal         0x801352FC
    // 0x801357A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_1;
    // 0x801357A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801357A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801357AC: jal         0x80135670
    // 0x801357B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetKOs(rdram, ctx);
        goto after_2;
    // 0x801357B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x801357B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801357B8: jal         0x801353F4
    // 0x801357BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_3;
    // 0x801357BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801357C0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801357C4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801357C8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801357CC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801357D0: jal         0x80134AC4
    // 0x801357D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_4;
    // 0x801357D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
L_801357D8:
    // 0x801357D8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801357DC: lw          $t7, -0x642C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X642C);
    // 0x801357E0: beq         $t7, $zero, L_80135820
    if (ctx->r15 == 0) {
        // 0x801357E4: nop
    
            goto L_80135820;
    }
    // 0x801357E4: nop

    // 0x801357E8: jal         0x801352FC
    // 0x801357EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_5;
    // 0x801357EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x801357F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801357F4: jal         0x80135670
    // 0x801357F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetKOs(rdram, ctx);
        goto after_6;
    // 0x801357F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x801357FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135800: jal         0x801353F4
    // 0x80135804: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_7;
    // 0x80135804: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80135808: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8013580C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135810: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80135814: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135818: jal         0x80134AC4
    // 0x8013581C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_8;
    // 0x8013581C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
L_80135820:
    // 0x80135820: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135824: lw          $t8, -0x6428($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6428);
    // 0x80135828: beq         $t8, $zero, L_80135868
    if (ctx->r24 == 0) {
        // 0x8013582C: nop
    
            goto L_80135868;
    }
    // 0x8013582C: nop

    // 0x80135830: jal         0x801352FC
    // 0x80135834: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_9;
    // 0x80135834: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x80135838: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8013583C: jal         0x80135670
    // 0x80135840: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetKOs(rdram, ctx);
        goto after_10;
    // 0x80135840: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80135844: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135848: jal         0x801353F4
    // 0x8013584C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_11;
    // 0x8013584C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80135850: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135854: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135858: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8013585C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135860: jal         0x80134AC4
    // 0x80135864: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_12;
    // 0x80135864: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
L_80135868:
    // 0x80135868: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013586C: lw          $t9, -0x6424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6424);
    // 0x80135870: beql        $t9, $zero, L_801358B4
    if (ctx->r25 == 0) {
        // 0x80135874: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_801358B4;
    }
    goto skip_0;
    // 0x80135874: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80135878: jal         0x801352FC
    // 0x8013587C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_13;
    // 0x8013587C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80135880: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135884: jal         0x80135670
    // 0x80135888: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetKOs(rdram, ctx);
        goto after_14;
    // 0x80135888: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x8013588C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135890: jal         0x801353F4
    // 0x80135894: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_15;
    // 0x80135894: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_15:
    // 0x80135898: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8013589C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801358A0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801358A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801358A8: jal         0x80134AC4
    // 0x801358AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_16;
    // 0x801358AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // 0x801358B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801358B4:
    // 0x801358B4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x801358B8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801358BC: jr          $ra
    // 0x801358C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801358C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_803764C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803764C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803764CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803764D0: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x803764D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803764D8: lh          $t6, 0x88($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X88);
    // 0x803764DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x803764E0: lw          $t9, 0x8C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8C);
    // 0x803764E4: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x803764E8: jalr        $t9
    // 0x803764EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803764EC: nop

    after_0:
    // 0x803764F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803764F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803764F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803764FC: beq         $a2, $zero, L_80376508
    if (ctx->r6 == 0) {
        // 0x80376500: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80376508;
    }
    // 0x80376500: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80376504: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
L_80376508:
    // 0x80376508: lbu         $t7, 0x1B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1B);
    // 0x8037650C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80376510: bne         $t7, $zero, L_80376520
    if (ctx->r15 != 0) {
        // 0x80376514: nop
    
            goto L_80376520;
    }
    // 0x80376514: nop

    // 0x80376518: b           L_80376520
    // 0x8037651C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80376520;
    // 0x8037651C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80376520:
    // 0x80376520: jr          $ra
    // 0x80376524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80376524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void grInishieMakePakkun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109774: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80109778: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8010977C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80109780: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80109784: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80109788: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8010978C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80109790: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80109794: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80109798: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010979C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801097A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801097A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801097A8: addiu       $s5, $s5, 0x13F8
    ctx->r21 = ADD32(ctx->r21, 0X13F8);
    // 0x801097AC: addiu       $s1, $s1, -0x14B8
    ctx->r17 = ADD32(ctx->r17, -0X14B8);
    // 0x801097B0: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x801097B4: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x801097B8: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x801097BC: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
L_801097C0:
    // 0x801097C0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x801097C4: jal         0x800FC814
    // 0x801097C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x801097C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x801097CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801097D0: jal         0x800FC894
    // 0x801097D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x801097D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x801097D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801097DC: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x801097E0: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x801097E4: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x801097E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801097EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801097F0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x801097F4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x801097F8: jal         0x8016EA78
    // 0x801097FC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_2;
    // 0x801097FC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_2:
    // 0x80109800: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80109804: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80109808: bne         $s0, $s5, L_801097C0
    if (ctx->r16 != ctx->r21) {
        // 0x8010980C: sw          $v0, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->r2;
            goto L_801097C0;
    }
    // 0x8010980C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80109810: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80109814: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80109818: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8010981C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80109820: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80109824: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80109828: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8010982C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80109830: jr          $ra
    // 0x80109834: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80109834: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void scExplainSetInterfaceGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DBD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DBD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DBD8: jal         0x8018D748
    // 0x8018DBDC: nop

    scExplainMakeControlStickInterface(rdram, ctx);
        goto after_0;
    // 0x8018DBDC: nop

    after_0:
    // 0x8018DBE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DBE4: jal         0x8018DA04
    // 0x8018DBE8: sw          $v0, -0x160C($at)
    MEM_W(-0X160C, ctx->r1) = ctx->r2;
    scExplainMakeTapSpark(rdram, ctx);
        goto after_1;
    // 0x8018DBE8: sw          $v0, -0x160C($at)
    MEM_W(-0X160C, ctx->r1) = ctx->r2;
    after_1:
    // 0x8018DBEC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DBF0: jal         0x8018DB44
    // 0x8018DBF4: sw          $v0, -0x1608($at)
    MEM_W(-0X1608, ctx->r1) = ctx->r2;
    scExplainMakeSpecialMoveRGB(rdram, ctx);
        goto after_2;
    // 0x8018DBF4: sw          $v0, -0x1608($at)
    MEM_W(-0X1608, ctx->r1) = ctx->r2;
    after_2:
    // 0x8018DBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DBFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DC00: sw          $v0, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r2;
    // 0x8018DC04: jr          $ra
    // 0x8018DC08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8018DC08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gmCameraPrepLookAtFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D428: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8010D42C: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x8010D430: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010D434: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8010D438: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8010D43C: addiu       $t8, $t8, 0x1548
    ctx->r24 = ADD32(ctx->r24, 0X1548);
    // 0x8010D440: ori         $t7, $t7, 0xA
    ctx->r15 = ctx->r15 | 0XA;
    // 0x8010D444: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010D448: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8010D44C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8010D450: lui         $t2, 0xDC08
    ctx->r10 = S32(0XDC08 << 16);
    // 0x8010D454: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8010D458: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8010D45C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8010D460: addiu       $t3, $t3, 0x1558
    ctx->r11 = ADD32(ctx->r11, 0X1558);
    // 0x8010D464: ori         $t2, $t2, 0x30A
    ctx->r10 = ctx->r10 | 0X30A;
    // 0x8010D468: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8010D46C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8010D470: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8010D474: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x8010D478: ori         $t5, $t5, 0x7
    ctx->r13 = ctx->r13 | 0X7;
    // 0x8010D47C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8010D480: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8010D484: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8010D488: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8010D48C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8010D490: lui         $t7, 0xDB0E
    ctx->r15 = S32(0XDB0E << 16);
    // 0x8010D494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010D498: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8010D49C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8010D4A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010D4A4: lhu         $t8, 0x1C($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1C);
    // 0x8010D4A8: jr          $ra
    // 0x8010D4AC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x8010D4AC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void syVectorGranularNeg3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019608: andi        $t6, $a1, 0x40
    ctx->r14 = ctx->r5 & 0X40;
    // 0x8001960C: beq         $t6, $zero, L_80019718
    if (ctx->r14 == 0) {
        // 0x80019610: andi        $t3, $a1, 0x1
        ctx->r11 = ctx->r5 & 0X1;
            goto L_80019718;
    }
    // 0x80019610: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x80019614: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80019618: beq         $t7, $zero, L_80019644
    if (ctx->r15 == 0) {
        // 0x8001961C: andi        $t9, $a1, 0x2
        ctx->r25 = ctx->r5 & 0X2;
            goto L_80019644;
    }
    // 0x8001961C: andi        $t9, $a1, 0x2
    ctx->r25 = ctx->r5 & 0X2;
    // 0x80019620: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80019624: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019628: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001962C: nop

    // 0x80019630: bc1fl       L_80019648
    if (!c1cs) {
        // 0x80019634: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80019648;
    }
    goto skip_0;
    // 0x80019634: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80019638: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8001963C: b           L_80019670
    // 0x80019640: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
        goto L_80019670;
    // 0x80019640: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_80019644:
    // 0x80019644: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80019648:
    // 0x80019648: andi        $t8, $a1, 0x8
    ctx->r24 = ctx->r5 & 0X8;
    // 0x8001964C: beq         $t8, $zero, L_80019670
    if (ctx->r24 == 0) {
        // 0x80019650: nop
    
            goto L_80019670;
    }
    // 0x80019650: nop

    // 0x80019654: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019658: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001965C: nop

    // 0x80019660: bc1f        L_80019670
    if (!c1cs) {
        // 0x80019664: nop
    
            goto L_80019670;
    }
    // 0x80019664: nop

    // 0x80019668: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8001966C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80019670:
    // 0x80019670: beq         $t9, $zero, L_80019698
    if (ctx->r25 == 0) {
        // 0x80019674: andi        $t1, $a1, 0x4
        ctx->r9 = ctx->r5 & 0X4;
            goto L_80019698;
    }
    // 0x80019674: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
    // 0x80019678: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001967C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80019680: nop

    // 0x80019684: bc1fl       L_8001969C
    if (!c1cs) {
        // 0x80019688: andi        $t0, $a1, 0x10
        ctx->r8 = ctx->r5 & 0X10;
            goto L_8001969C;
    }
    goto skip_1;
    // 0x80019688: andi        $t0, $a1, 0x10
    ctx->r8 = ctx->r5 & 0X10;
    skip_1:
    // 0x8001968C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80019690: b           L_800196C0
    // 0x80019694: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
        goto L_800196C0;
    // 0x80019694: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_80019698:
    // 0x80019698: andi        $t0, $a1, 0x10
    ctx->r8 = ctx->r5 & 0X10;
L_8001969C:
    // 0x8001969C: beq         $t0, $zero, L_800196C0
    if (ctx->r8 == 0) {
        // 0x800196A0: nop
    
            goto L_800196C0;
    }
    // 0x800196A0: nop

    // 0x800196A4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800196A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800196AC: nop

    // 0x800196B0: bc1f        L_800196C0
    if (!c1cs) {
        // 0x800196B4: nop
    
            goto L_800196C0;
    }
    // 0x800196B4: nop

    // 0x800196B8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800196BC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800196C0:
    // 0x800196C0: beq         $t1, $zero, L_800196EC
    if (ctx->r9 == 0) {
        // 0x800196C4: andi        $t2, $a1, 0x20
        ctx->r10 = ctx->r5 & 0X20;
            goto L_800196EC;
    }
    // 0x800196C4: andi        $t2, $a1, 0x20
    ctx->r10 = ctx->r5 & 0X20;
    // 0x800196C8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800196CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800196D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800196D4: nop

    // 0x800196D8: bc1f        L_800196EC
    if (!c1cs) {
        // 0x800196DC: nop
    
            goto L_800196EC;
    }
    // 0x800196DC: nop

    // 0x800196E0: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x800196E4: jr          $ra
    // 0x800196E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x800196E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
L_800196EC:
    // 0x800196EC: beq         $t2, $zero, L_80019810
    if (ctx->r10 == 0) {
        // 0x800196F0: nop
    
            goto L_80019810;
    }
    // 0x800196F0: nop

    // 0x800196F4: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800196F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800196FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80019700: nop

    // 0x80019704: bc1f        L_80019810
    if (!c1cs) {
        // 0x80019708: nop
    
            goto L_80019810;
    }
    // 0x80019708: nop

    // 0x8001970C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80019710: jr          $ra
    // 0x80019714: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80019714: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_80019718:
    // 0x80019718: beq         $t3, $zero, L_80019744
    if (ctx->r11 == 0) {
        // 0x8001971C: andi        $t5, $a1, 0x2
        ctx->r13 = ctx->r5 & 0X2;
            goto L_80019744;
    }
    // 0x8001971C: andi        $t5, $a1, 0x2
    ctx->r13 = ctx->r5 & 0X2;
    // 0x80019720: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80019724: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019728: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001972C: nop

    // 0x80019730: bc1fl       L_80019748
    if (!c1cs) {
        // 0x80019734: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80019748;
    }
    goto skip_2;
    // 0x80019734: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x80019738: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8001973C: b           L_80019770
    // 0x80019740: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
        goto L_80019770;
    // 0x80019740: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_80019744:
    // 0x80019744: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80019748:
    // 0x80019748: andi        $t4, $a1, 0x8
    ctx->r12 = ctx->r5 & 0X8;
    // 0x8001974C: beq         $t4, $zero, L_80019770
    if (ctx->r12 == 0) {
        // 0x80019750: nop
    
            goto L_80019770;
    }
    // 0x80019750: nop

    // 0x80019754: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019758: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001975C: nop

    // 0x80019760: bc1f        L_80019770
    if (!c1cs) {
        // 0x80019764: nop
    
            goto L_80019770;
    }
    // 0x80019764: nop

    // 0x80019768: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8001976C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80019770:
    // 0x80019770: beq         $t5, $zero, L_80019798
    if (ctx->r13 == 0) {
        // 0x80019774: andi        $t7, $a1, 0x4
        ctx->r15 = ctx->r5 & 0X4;
            goto L_80019798;
    }
    // 0x80019774: andi        $t7, $a1, 0x4
    ctx->r15 = ctx->r5 & 0X4;
    // 0x80019778: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001977C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80019780: nop

    // 0x80019784: bc1fl       L_8001979C
    if (!c1cs) {
        // 0x80019788: andi        $t6, $a1, 0x10
        ctx->r14 = ctx->r5 & 0X10;
            goto L_8001979C;
    }
    goto skip_3;
    // 0x80019788: andi        $t6, $a1, 0x10
    ctx->r14 = ctx->r5 & 0X10;
    skip_3:
    // 0x8001978C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80019790: b           L_800197C0
    // 0x80019794: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
        goto L_800197C0;
    // 0x80019794: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_80019798:
    // 0x80019798: andi        $t6, $a1, 0x10
    ctx->r14 = ctx->r5 & 0X10;
L_8001979C:
    // 0x8001979C: beq         $t6, $zero, L_800197C0
    if (ctx->r14 == 0) {
        // 0x800197A0: nop
    
            goto L_800197C0;
    }
    // 0x800197A0: nop

    // 0x800197A4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800197A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800197AC: nop

    // 0x800197B0: bc1f        L_800197C0
    if (!c1cs) {
        // 0x800197B4: nop
    
            goto L_800197C0;
    }
    // 0x800197B4: nop

    // 0x800197B8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800197BC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800197C0:
    // 0x800197C0: beq         $t7, $zero, L_800197EC
    if (ctx->r15 == 0) {
        // 0x800197C4: andi        $t8, $a1, 0x20
        ctx->r24 = ctx->r5 & 0X20;
            goto L_800197EC;
    }
    // 0x800197C4: andi        $t8, $a1, 0x20
    ctx->r24 = ctx->r5 & 0X20;
    // 0x800197C8: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800197CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800197D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800197D4: nop

    // 0x800197D8: bc1f        L_800197EC
    if (!c1cs) {
        // 0x800197DC: nop
    
            goto L_800197EC;
    }
    // 0x800197DC: nop

    // 0x800197E0: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x800197E4: jr          $ra
    // 0x800197E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x800197E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
L_800197EC:
    // 0x800197EC: beq         $t8, $zero, L_80019810
    if (ctx->r24 == 0) {
        // 0x800197F0: nop
    
            goto L_80019810;
    }
    // 0x800197F0: nop

    // 0x800197F4: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800197F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800197FC: nop

    // 0x80019800: bc1f        L_80019810
    if (!c1cs) {
        // 0x80019804: nop
    
            goto L_80019810;
    }
    // 0x80019804: nop

    // 0x80019808: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8001980C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_80019810:
    // 0x80019810: jr          $ra
    // 0x80019814: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80019814: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void mpCollisionGetLWallEdgeD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4678: jal         0x800F4488
    // 0x800F467C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    mpCollisionGetUDEdge(rdram, ctx);
        goto after_0;
    // 0x800F467C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x800F4680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4688: jr          $ra
    // 0x800F468C: nop

    return;
    // 0x800F468C: nop

;}
RECOMP_FUNC void func_ovl8_80374C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374C6C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374C70: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80374C74: lh          $t6, 0x80($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X80);
    // 0x80374C78: jalr        $t9
    // 0x80374C7C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374C7C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374C88: jr          $ra
    // 0x80374C8C: nop

    return;
    // 0x80374C8C: nop

;}
RECOMP_FUNC void ftAnimParseDObjFigatree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC238: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800EC23C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800EC240: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800EC244: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800EC248: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800EC24C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800EC250: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800EC254: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800EC258: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800EC25C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800EC260: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800EC264: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800EC268: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800EC26C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EC270: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EC274: lwc1        $f4, 0x128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X128);
    // 0x800EC278: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800EC27C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800EC280: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EC284: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800EC288: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800EC28C: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x800EC290: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800EC294: bc1tl       L_800ECC6C
    if (c1cs) {
        // 0x800EC298: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800ECC6C;
    }
    goto skip_0;
    // 0x800EC298: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x800EC29C: lwc1        $f6, 0x12C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12C);
    // 0x800EC2A0: addiu       $fp, $sp, 0x80
    ctx->r30 = ADD32(ctx->r29, 0X80);
    // 0x800EC2A4: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800EC2A8: nop

    // 0x800EC2AC: bc1fl       L_800EC2CC
    if (!c1cs) {
        // 0x800EC2B0: lwc1        $f2, 0x78($s6)
        ctx->f2.u32l = MEM_W(ctx->r22, 0X78);
            goto L_800EC2CC;
    }
    goto skip_1;
    // 0x800EC2B0: lwc1        $f2, 0x78($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X78);
    skip_1:
    // 0x800EC2B4: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x800EC2B8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800EC2BC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800EC2C0: b           L_800EC304
    // 0x800EC2C4: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
        goto L_800EC304;
    // 0x800EC2C4: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
    // 0x800EC2C8: lwc1        $f2, 0x78($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X78);
L_800EC2CC:
    // 0x800EC2CC: lwc1        $f18, 0x7C($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X7C);
    // 0x800EC2D0: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x800EC2D4: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EC2D8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800EC2DC: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800EC2E0: swc1        $f16, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f16.u32l;
    // 0x800EC2E4: swc1        $f4, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = ctx->f4.u32l;
    // 0x800EC2E8: lwc1        $f6, 0x7C($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X7C);
    // 0x800EC2EC: swc1        $f6, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f6.u32l;
    // 0x800EC2F0: lwc1        $f8, 0x74($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC2F4: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x800EC2F8: nop

    // 0x800EC2FC: bc1tl       L_800ECC6C
    if (c1cs) {
        // 0x800EC300: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800ECC6C;
    }
    goto skip_2;
    // 0x800EC300: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
L_800EC304:
    // 0x800EC304: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800EC308: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_800EC30C:
    // 0x800EC30C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800EC310: sw          $zero, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = 0;
    // 0x800EC314: sw          $zero, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = 0;
    // 0x800EC318: sw          $zero, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = 0;
    // 0x800EC31C: bne         $s1, $v0, L_800EC30C
    if (ctx->r17 != ctx->r2) {
        // 0x800EC320: sw          $zero, -0x10($s1)
        MEM_W(-0X10, ctx->r17) = 0;
            goto L_800EC30C;
    }
    // 0x800EC320: sw          $zero, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = 0;
    // 0x800EC324: lw          $v0, 0x6C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X6C);
    // 0x800EC328: beql        $v0, $zero, L_800EC35C
    if (ctx->r2 == 0) {
        // 0x800EC32C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800EC35C;
    }
    goto skip_3;
    // 0x800EC32C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_3:
    // 0x800EC330: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
L_800EC334:
    // 0x800EC334: blez        $v1, L_800EC34C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800EC338: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_800EC34C;
    }
    // 0x800EC338: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x800EC33C: beq         $at, $zero, L_800EC34C
    if (ctx->r1 == 0) {
        // 0x800EC340: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800EC34C;
    }
    // 0x800EC340: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800EC344: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x800EC348: sw          $v0, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r2;
L_800EC34C:
    // 0x800EC34C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800EC350: bnel        $v0, $zero, L_800EC334
    if (ctx->r2 != 0) {
        // 0x800EC354: lbu         $v1, 0x4($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X4);
            goto L_800EC334;
    }
    goto skip_4;
    // 0x800EC354: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    skip_4:
    // 0x800EC358: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800EC35C:
    // 0x800EC35C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800EC360: addiu       $fp, $sp, 0x80
    ctx->r30 = ADD32(ctx->r29, 0X80);
    // 0x800EC364: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
L_800EC368:
    // 0x800EC368: bnel        $s2, $zero, L_800EC3D0
    if (ctx->r18 != 0) {
        // 0x800EC36C: lhu         $a0, 0x0($s2)
        ctx->r4 = MEM_HU(ctx->r18, 0X0);
            goto L_800EC3D0;
    }
    goto skip_5;
    // 0x800EC36C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    skip_5:
    // 0x800EC370: lw          $v0, 0x6C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X6C);
    // 0x800EC374: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC378: beql        $v0, $zero, L_800EC3B4
    if (ctx->r2 == 0) {
        // 0x800EC37C: lw          $t0, 0x4($s6)
        ctx->r8 = MEM_W(ctx->r22, 0X4);
            goto L_800EC3B4;
    }
    goto skip_6;
    // 0x800EC37C: lw          $t0, 0x4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X4);
    skip_6:
    // 0x800EC380: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
L_800EC384:
    // 0x800EC384: beql        $t9, $zero, L_800EC3A8
    if (ctx->r25 == 0) {
        // 0x800EC388: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800EC3A8;
    }
    goto skip_7;
    // 0x800EC388: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_7:
    // 0x800EC38C: lwc1        $f16, 0x78($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800EC390: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800EC394: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800EC398: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800EC39C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800EC3A0: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC3A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800EC3A8:
    // 0x800EC3A8: bnel        $v0, $zero, L_800EC384
    if (ctx->r2 != 0) {
        // 0x800EC3AC: lbu         $t9, 0x5($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X5);
            goto L_800EC384;
    }
    goto skip_8;
    // 0x800EC3AC: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    skip_8:
    // 0x800EC3B0: lw          $t0, 0x4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X4);
L_800EC3B4:
    // 0x800EC3B4: swc1        $f0, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = ctx->f0.u32l;
    // 0x800EC3B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EC3BC: swc1        $f0, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f0.u32l;
    // 0x800EC3C0: lwc1        $f6, 0x130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X130);
    // 0x800EC3C4: b           L_800ECC68
    // 0x800EC3C8: swc1        $f6, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f6.u32l;
        goto L_800ECC68;
    // 0x800EC3C8: swc1        $f6, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f6.u32l;
    // 0x800EC3CC: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
L_800EC3D0:
    // 0x800EC3D0: srl         $v0, $a0, 11
    ctx->r2 = S32(U32(ctx->r4) >> 11);
    // 0x800EC3D4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC3D8: sltiu       $at, $v0, 0xF
    ctx->r1 = ctx->r2 < 0XF ? 1 : 0;
    // 0x800EC3DC: beq         $at, $zero, L_800ECC54
    if (ctx->r1 == 0) {
        // 0x800EC3E0: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_800ECC54;
    }
    // 0x800EC3E0: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800EC3E4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800EC3E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EC3EC: addu        $at, $at, $t1
    gpr jr_addend_800EC3F4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800EC3F0: lw          $t1, 0x134($at)
    ctx->r9 = ADD32(ctx->r1, 0X134);
    // 0x800EC3F4: jr          $t1
    // 0x800EC3F8: nop

    switch (jr_addend_800EC3F4 >> 2) {
        case 0: goto L_800ECB68; break;
        case 1: goto L_800EC86C; break;
        case 2: goto L_800EC538; break;
        case 3: goto L_800EC538; break;
        case 4: goto L_800EC674; break;
        case 5: goto L_800EC674; break;
        case 6: goto L_800EC7D0; break;
        case 7: goto L_800EC3FC; break;
        case 8: goto L_800EC3FC; break;
        case 9: goto L_800EC8BC; break;
        case 10: goto L_800EC8BC; break;
        case 11: goto L_800ECA54; break;
        case 12: goto L_800ECB08; break;
        case 13: goto L_800EC9E0; break;
        case 14: goto L_800ECBF0; break;
        default: switch_error(__func__, 0x800EC3F4, 0x80130134);
    }
    // 0x800EC3F8: nop

L_800EC3FC:
    // 0x800EC3FC: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800EC400: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800EC404: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC408: addiu       $t2, $s2, 0x2
    ctx->r10 = ADD32(ctx->r18, 0X2);
    // 0x800EC40C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC410: sw          $t2, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r10;
    // 0x800EC414: beq         $v1, $zero, L_800EC44C
    if (ctx->r3 == 0) {
        // 0x800EC418: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800EC44C;
    }
    // 0x800EC418: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800EC41C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800EC420: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x800EC424: addiu       $t4, $s2, 0x2
    ctx->r12 = ADD32(ctx->r18, 0X2);
    // 0x800EC428: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800EC42C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC430: bgez        $t3, L_800EC444
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800EC434: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800EC444;
    }
    // 0x800EC434: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EC438: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800EC43C: nop

    // 0x800EC440: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_800EC444:
    // 0x800EC444: b           L_800EC450
    // 0x800EC448: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
        goto L_800EC450;
    // 0x800EC448: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
L_800EC44C:
    // 0x800EC44C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800EC450:
    // 0x800EC450: beq         $v0, $zero, L_800EC514
    if (ctx->r2 == 0) {
        // 0x800EC454: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_800EC514;
    }
    // 0x800EC454: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800EC458: beq         $t5, $zero, L_800EC504
    if (ctx->r13 == 0) {
        // 0x800EC45C: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EC504;
    }
    // 0x800EC45C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EC460: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x800EC464: addu        $s1, $fp, $t6
    ctx->r17 = ADD32(ctx->r30, ctx->r14);
    // 0x800EC468: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC46C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800EC470: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC474: bnel        $s0, $zero, L_800EC490
    if (ctx->r16 != 0) {
        // 0x800EC478: lwc1        $f10, 0x14($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800EC490;
    }
    goto skip_9;
    // 0x800EC478: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    skip_9:
    // 0x800EC47C: jal         0x80008E78
    // 0x800EC480: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_0;
    // 0x800EC480: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x800EC484: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EC488: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EC48C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
L_800EC490:
    // 0x800EC490: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EC498: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800EC49C: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    // 0x800EC4A0: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC4A4: addiu       $t7, $s2, 0x2
    ctx->r15 = ADD32(ctx->r18, 0X2);
    // 0x800EC4A8: jal         0x800EC160
    // 0x800EC4AC: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_1;
    // 0x800EC4AC: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    after_1:
    // 0x800EC4B0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4B4: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800EC4B8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800EC4BC: swc1        $f0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f0.u32l;
    // 0x800EC4C0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4C4: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800EC4C8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800EC4CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4D0: swc1        $f22, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f22.u32l;
    // 0x800EC4D4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4D8: bc1t        L_800EC4EC
    if (c1cs) {
        // 0x800EC4DC: sb          $t0, 0x5($t1)
        MEM_B(0X5, ctx->r9) = ctx->r8;
            goto L_800EC4EC;
    }
    // 0x800EC4DC: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
    // 0x800EC4E0: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800EC4E4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4E8: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
L_800EC4EC:
    // 0x800EC4EC: lwc1        $f6, 0x74($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC4F0: lwc1        $f16, 0x78($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800EC4F4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800EC4F8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800EC4FC: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800EC500: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
L_800EC504:
    // 0x800EC504: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800EC508: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800EC50C: bne         $s3, $s7, L_800EC450
    if (ctx->r19 != ctx->r23) {
        // 0x800EC510: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800EC450;
    }
    // 0x800EC510: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800EC514:
    // 0x800EC514: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800EC518: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800EC51C: bne         $t4, $at, L_800EC530
    if (ctx->r12 != ctx->r1) {
        // 0x800EC520: nop
    
            goto L_800EC530;
    }
    // 0x800EC520: nop

    // 0x800EC524: lwc1        $f18, 0x74($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC528: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800EC52C: swc1        $f4, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f4.u32l;
L_800EC530:
    // 0x800EC530: b           L_800ECC58
    // 0x800EC534: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC534: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC538:
    // 0x800EC538: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800EC53C: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800EC540: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC544: addiu       $t5, $s2, 0x2
    ctx->r13 = ADD32(ctx->r18, 0X2);
    // 0x800EC548: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC54C: sw          $t5, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r13;
    // 0x800EC550: beq         $v1, $zero, L_800EC588
    if (ctx->r3 == 0) {
        // 0x800EC554: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800EC588;
    }
    // 0x800EC554: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800EC558: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800EC55C: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800EC560: addiu       $t7, $s2, 0x2
    ctx->r15 = ADD32(ctx->r18, 0X2);
    // 0x800EC564: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800EC568: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC56C: bgez        $t6, L_800EC580
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EC570: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EC580;
    }
    // 0x800EC570: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EC574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EC578: nop

    // 0x800EC57C: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_800EC580:
    // 0x800EC580: b           L_800EC58C
    // 0x800EC584: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
        goto L_800EC58C;
    // 0x800EC584: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
L_800EC588:
    // 0x800EC588: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800EC58C:
    // 0x800EC58C: beq         $v0, $zero, L_800EC650
    if (ctx->r2 == 0) {
        // 0x800EC590: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800EC650;
    }
    // 0x800EC590: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800EC594: beq         $t8, $zero, L_800EC640
    if (ctx->r24 == 0) {
        // 0x800EC598: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EC640;
    }
    // 0x800EC598: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EC59C: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x800EC5A0: addu        $s1, $fp, $t9
    ctx->r17 = ADD32(ctx->r30, ctx->r25);
    // 0x800EC5A4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC5A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800EC5AC: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC5B0: bnel        $s0, $zero, L_800EC5CC
    if (ctx->r16 != 0) {
        // 0x800EC5B4: lwc1        $f16, 0x14($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800EC5CC;
    }
    goto skip_10;
    // 0x800EC5B4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    skip_10:
    // 0x800EC5B8: jal         0x80008E78
    // 0x800EC5BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_2;
    // 0x800EC5BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x800EC5C0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EC5C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EC5C8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
L_800EC5CC:
    // 0x800EC5CC: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC5D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EC5D4: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800EC5D8: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    // 0x800EC5DC: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC5E0: addiu       $t0, $s2, 0x2
    ctx->r8 = ADD32(ctx->r18, 0X2);
    // 0x800EC5E4: jal         0x800EC160
    // 0x800EC5E8: sw          $t0, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r8;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_3;
    // 0x800EC5E8: sw          $t0, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r8;
    after_3:
    // 0x800EC5EC: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800EC5F0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800EC5F4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800EC5F8: swc1        $f0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f0.u32l;
    // 0x800EC5FC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800EC600: bc1t        L_800EC620
    if (c1cs) {
        // 0x800EC604: sb          $t2, 0x5($t3)
        MEM_B(0X5, ctx->r11) = ctx->r10;
            goto L_800EC620;
    }
    // 0x800EC604: sb          $t2, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r10;
    // 0x800EC608: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC60C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800EC610: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800EC614: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800EC618: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800EC61C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_800EC620:
    // 0x800EC620: lwc1        $f8, 0x74($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC624: lwc1        $f10, 0x78($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800EC628: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800EC62C: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800EC630: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800EC634: swc1        $f18, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f18.u32l;
    // 0x800EC638: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800EC63C: swc1        $f22, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f22.u32l;
L_800EC640:
    // 0x800EC640: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800EC644: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800EC648: bne         $s3, $s7, L_800EC58C
    if (ctx->r19 != ctx->r23) {
        // 0x800EC64C: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800EC58C;
    }
    // 0x800EC64C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800EC650:
    // 0x800EC650: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800EC654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EC658: bne         $t6, $at, L_800EC66C
    if (ctx->r14 != ctx->r1) {
        // 0x800EC65C: nop
    
            goto L_800EC66C;
    }
    // 0x800EC65C: nop

    // 0x800EC660: lwc1        $f4, 0x74($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC664: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800EC668: swc1        $f6, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f6.u32l;
L_800EC66C:
    // 0x800EC66C: b           L_800ECC58
    // 0x800EC670: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC670: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC674:
    // 0x800EC674: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800EC678: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800EC67C: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC680: addiu       $t7, $s2, 0x2
    ctx->r15 = ADD32(ctx->r18, 0X2);
    // 0x800EC684: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC688: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    // 0x800EC68C: beq         $v1, $zero, L_800EC6C4
    if (ctx->r3 == 0) {
        // 0x800EC690: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800EC6C4;
    }
    // 0x800EC690: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800EC694: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800EC698: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800EC69C: addiu       $t9, $s2, 0x2
    ctx->r25 = ADD32(ctx->r18, 0X2);
    // 0x800EC6A0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800EC6A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC6A8: bgez        $t8, L_800EC6BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EC6AC: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800EC6BC;
    }
    // 0x800EC6AC: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EC6B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800EC6B4: nop

    // 0x800EC6B8: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_800EC6BC:
    // 0x800EC6BC: b           L_800EC6C8
    // 0x800EC6C0: sw          $t9, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r25;
        goto L_800EC6C8;
    // 0x800EC6C0: sw          $t9, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r25;
L_800EC6C4:
    // 0x800EC6C4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800EC6C8:
    // 0x800EC6C8: beq         $v0, $zero, L_800EC7AC
    if (ctx->r2 == 0) {
        // 0x800EC6CC: andi        $t0, $v0, 0x1
        ctx->r8 = ctx->r2 & 0X1;
            goto L_800EC7AC;
    }
    // 0x800EC6CC: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800EC6D0: beq         $t0, $zero, L_800EC79C
    if (ctx->r8 == 0) {
        // 0x800EC6D4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EC79C;
    }
    // 0x800EC6D4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EC6D8: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x800EC6DC: addu        $s1, $fp, $t1
    ctx->r17 = ADD32(ctx->r30, ctx->r9);
    // 0x800EC6E0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC6E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800EC6E8: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC6EC: bnel        $s0, $zero, L_800EC708
    if (ctx->r16 != 0) {
        // 0x800EC6F0: lwc1        $f10, 0x14($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800EC708;
    }
    goto skip_11;
    // 0x800EC6F0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    skip_11:
    // 0x800EC6F4: jal         0x80008E78
    // 0x800EC6F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_4;
    // 0x800EC6F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_4:
    // 0x800EC6FC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EC700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EC704: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
L_800EC708:
    // 0x800EC708: addiu       $s4, $s3, 0x1
    ctx->r20 = ADD32(ctx->r19, 0X1);
    // 0x800EC70C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800EC710: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800EC714: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    // 0x800EC718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EC71C: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC720: addiu       $t2, $s2, 0x2
    ctx->r10 = ADD32(ctx->r18, 0X2);
    // 0x800EC724: jal         0x800EC160
    // 0x800EC728: sw          $t2, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r10;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_5;
    // 0x800EC728: sw          $t2, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r10;
    after_5:
    // 0x800EC72C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800EC730: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800EC734: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800EC738: swc1        $f0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f0.u32l;
    // 0x800EC73C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC740: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800EC744: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800EC748: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    // 0x800EC74C: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC750: addiu       $t4, $s2, 0x2
    ctx->r12 = ADD32(ctx->r18, 0X2);
    // 0x800EC754: jal         0x800EC160
    // 0x800EC758: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_6;
    // 0x800EC758: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
    after_6:
    // 0x800EC75C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800EC760: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800EC764: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800EC768: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x800EC76C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800EC770: bc1t        L_800EC784
    if (c1cs) {
        // 0x800EC774: sb          $t6, 0x5($t7)
        MEM_B(0X5, ctx->r15) = ctx->r14;
            goto L_800EC784;
    }
    // 0x800EC774: sb          $t6, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r14;
    // 0x800EC778: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800EC77C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800EC780: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
L_800EC784:
    // 0x800EC784: lwc1        $f6, 0x74($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC788: lwc1        $f16, 0x78($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800EC78C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800EC790: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800EC794: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800EC798: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
L_800EC79C:
    // 0x800EC79C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800EC7A0: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800EC7A4: bne         $s3, $s7, L_800EC6C8
    if (ctx->r19 != ctx->r23) {
        // 0x800EC7A8: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800EC6C8;
    }
    // 0x800EC7A8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800EC7AC:
    // 0x800EC7AC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800EC7B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800EC7B4: bne         $t0, $at, L_800EC7C8
    if (ctx->r8 != ctx->r1) {
        // 0x800EC7B8: nop
    
            goto L_800EC7C8;
    }
    // 0x800EC7B8: nop

    // 0x800EC7BC: lwc1        $f18, 0x74($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC7C0: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800EC7C4: swc1        $f4, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f4.u32l;
L_800EC7C8:
    // 0x800EC7C8: b           L_800ECC58
    // 0x800EC7CC: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC7CC: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC7D0:
    // 0x800EC7D0: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800EC7D4: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800EC7D8: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC7DC: addiu       $t1, $s2, 0x2
    ctx->r9 = ADD32(ctx->r18, 0X2);
    // 0x800EC7E0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC7E4: sw          $t1, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r9;
    // 0x800EC7E8: beq         $v1, $zero, L_800EC7F8
    if (ctx->r3 == 0) {
        // 0x800EC7EC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800EC7F8;
    }
    // 0x800EC7EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800EC7F0: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x800EC7F4: sw          $t3, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r11;
L_800EC7F8:
    // 0x800EC7F8: beq         $v0, $zero, L_800EC864
    if (ctx->r2 == 0) {
        // 0x800EC7FC: andi        $t4, $v0, 0x1
        ctx->r12 = ctx->r2 & 0X1;
            goto L_800EC864;
    }
    // 0x800EC7FC: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800EC800: beq         $t4, $zero, L_800EC854
    if (ctx->r12 == 0) {
        // 0x800EC804: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EC854;
    }
    // 0x800EC804: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EC808: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x800EC80C: addu        $s1, $fp, $t5
    ctx->r17 = ADD32(ctx->r30, ctx->r13);
    // 0x800EC810: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800EC814: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800EC818: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC81C: bnel        $t6, $zero, L_800EC834
    if (ctx->r14 != 0) {
        // 0x800EC820: lw          $s2, 0x70($s6)
        ctx->r18 = MEM_W(ctx->r22, 0X70);
            goto L_800EC834;
    }
    goto skip_12;
    // 0x800EC820: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    skip_12:
    // 0x800EC824: jal         0x80008E78
    // 0x800EC828: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_7;
    // 0x800EC828: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_7:
    // 0x800EC82C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EC830: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
L_800EC834:
    // 0x800EC834: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC838: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800EC83C: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC840: addiu       $t7, $s2, 0x2
    ctx->r15 = ADD32(ctx->r18, 0X2);
    // 0x800EC844: jal         0x800EC160
    // 0x800EC848: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_8;
    // 0x800EC848: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    after_8:
    // 0x800EC84C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800EC850: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
L_800EC854:
    // 0x800EC854: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800EC858: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800EC85C: bne         $s3, $s7, L_800EC7F8
    if (ctx->r19 != ctx->r23) {
        // 0x800EC860: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800EC7F8;
    }
    // 0x800EC860: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800EC864:
    // 0x800EC864: b           L_800ECC58
    // 0x800EC868: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC868: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC86C:
    // 0x800EC86C: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC870: addiu       $t9, $s2, 0x2
    ctx->r25 = ADD32(ctx->r18, 0X2);
    // 0x800EC874: beq         $v1, $zero, L_800EC8B4
    if (ctx->r3 == 0) {
        // 0x800EC878: sw          $t9, 0x70($s6)
        MEM_W(0X70, ctx->r22) = ctx->r25;
            goto L_800EC8B4;
    }
    // 0x800EC878: sw          $t9, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r25;
    // 0x800EC87C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800EC880: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800EC884: lwc1        $f6, 0x74($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC888: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800EC88C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC890: bgez        $t0, L_800EC8A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800EC894: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800EC8A4;
    }
    // 0x800EC894: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EC898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EC89C: nop

    // 0x800EC8A0: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800EC8A4:
    // 0x800EC8A4: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800EC8A8: addiu       $t1, $s2, 0x2
    ctx->r9 = ADD32(ctx->r18, 0X2);
    // 0x800EC8AC: sw          $t1, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r9;
    // 0x800EC8B0: swc1        $f18, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f18.u32l;
L_800EC8B4:
    // 0x800EC8B4: b           L_800ECC58
    // 0x800EC8B8: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC8B8: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC8BC:
    // 0x800EC8BC: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800EC8C0: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800EC8C4: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800EC8C8: addiu       $t2, $s2, 0x2
    ctx->r10 = ADD32(ctx->r18, 0X2);
    // 0x800EC8CC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EC8D0: sw          $t2, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r10;
    // 0x800EC8D4: beq         $v1, $zero, L_800EC90C
    if (ctx->r3 == 0) {
        // 0x800EC8D8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800EC90C;
    }
    // 0x800EC8D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800EC8DC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800EC8E0: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x800EC8E4: addiu       $t4, $s2, 0x2
    ctx->r12 = ADD32(ctx->r18, 0X2);
    // 0x800EC8E8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800EC8EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC8F0: bgez        $t3, L_800EC904
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800EC8F4: cvt.s.w     $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800EC904;
    }
    // 0x800EC8F4: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EC8F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EC8FC: nop

    // 0x800EC900: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_800EC904:
    // 0x800EC904: b           L_800EC910
    // 0x800EC908: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
        goto L_800EC910;
    // 0x800EC908: sw          $t4, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r12;
L_800EC90C:
    // 0x800EC90C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800EC910:
    // 0x800EC910: beq         $v0, $zero, L_800EC9BC
    if (ctx->r2 == 0) {
        // 0x800EC914: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_800EC9BC;
    }
    // 0x800EC914: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800EC918: beq         $t5, $zero, L_800EC9AC
    if (ctx->r13 == 0) {
        // 0x800EC91C: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EC9AC;
    }
    // 0x800EC91C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EC920: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x800EC924: addu        $s1, $fp, $t6
    ctx->r17 = ADD32(ctx->r30, ctx->r14);
    // 0x800EC928: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800EC92C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800EC930: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC934: bnel        $s0, $zero, L_800EC950
    if (ctx->r16 != 0) {
        // 0x800EC938: lwc1        $f10, 0x14($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800EC950;
    }
    goto skip_13;
    // 0x800EC938: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    skip_13:
    // 0x800EC93C: jal         0x80008E78
    // 0x800EC940: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_9;
    // 0x800EC940: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_9:
    // 0x800EC944: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EC948: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EC94C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
L_800EC950:
    // 0x800EC950: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800EC954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EC958: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800EC95C: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    // 0x800EC960: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800EC964: addiu       $t7, $s2, 0x2
    ctx->r15 = ADD32(ctx->r18, 0X2);
    // 0x800EC968: jal         0x800EC160
    // 0x800EC96C: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    ftAnimGetTargetValue(rdram, ctx);
        goto after_10;
    // 0x800EC96C: sw          $t7, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r15;
    after_10:
    // 0x800EC970: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800EC974: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800EC978: swc1        $f0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f0.u32l;
    // 0x800EC97C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800EC980: sb          $t9, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r25;
    // 0x800EC984: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800EC988: swc1        $f20, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f20.u32l;
    // 0x800EC98C: lwc1        $f6, 0x74($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC990: lwc1        $f18, 0x78($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800EC994: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800EC998: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x800EC99C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800EC9A0: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x800EC9A4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800EC9A8: swc1        $f22, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f22.u32l;
L_800EC9AC:
    // 0x800EC9AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800EC9B0: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800EC9B4: bne         $s3, $s7, L_800EC910
    if (ctx->r19 != ctx->r23) {
        // 0x800EC9B8: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800EC910;
    }
    // 0x800EC9B8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800EC9BC:
    // 0x800EC9BC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x800EC9C0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800EC9C4: bne         $t4, $at, L_800EC9D8
    if (ctx->r12 != ctx->r1) {
        // 0x800EC9C8: nop
    
            goto L_800EC9D8;
    }
    // 0x800EC9C8: nop

    // 0x800EC9CC: lwc1        $f8, 0x74($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC9D0: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800EC9D4: swc1        $f10, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f10.u32l;
L_800EC9D8:
    // 0x800EC9D8: b           L_800ECC58
    // 0x800EC9DC: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800EC9DC: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800EC9E0:
    // 0x800EC9E0: addiu       $t5, $s2, 0x2
    ctx->r13 = ADD32(ctx->r18, 0X2);
    // 0x800EC9E4: sw          $t5, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r13;
    // 0x800EC9E8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800EC9EC: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800EC9F0: lw          $t0, 0x4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X4);
    // 0x800EC9F4: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800EC9F8: bgez        $t6, L_800ECA08
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EC9FC: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800ECA08;
    }
    // 0x800EC9FC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800ECA00: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800ECA04: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800ECA08:
    // 0x800ECA08: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800ECA0C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800ECA10: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x800ECA14: sw          $t9, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r25;
    // 0x800ECA18: swc1        $f0, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = ctx->f0.u32l;
    // 0x800ECA1C: swc1        $f0, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f0.u32l;
    // 0x800ECA20: lbu         $t1, 0x55($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X55);
    // 0x800ECA24: beq         $t1, $zero, L_800ECA4C
    if (ctx->r9 == 0) {
        // 0x800ECA28: nop
    
            goto L_800ECA4C;
    }
    // 0x800ECA28: nop

    // 0x800ECA2C: lw          $t2, 0x4($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X4);
    // 0x800ECA30: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ECA34: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x800ECA38: lw          $v0, 0x80($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X80);
    // 0x800ECA3C: beq         $v0, $zero, L_800ECA4C
    if (ctx->r2 == 0) {
        // 0x800ECA40: nop
    
            goto L_800ECA4C;
    }
    // 0x800ECA40: nop

    // 0x800ECA44: jalr        $v0
    // 0x800ECA48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x800ECA48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_11:
L_800ECA4C:
    // 0x800ECA4C: b           L_800ECC58
    // 0x800ECA50: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800ECA50: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800ECA54:
    // 0x800ECA54: sll         $v0, $a0, 21
    ctx->r2 = S32(ctx->r4 << 21);
    // 0x800ECA58: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800ECA5C: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x800ECA60: addiu       $t3, $s2, 0x2
    ctx->r11 = ADD32(ctx->r18, 0X2);
    // 0x800ECA64: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800ECA68: sw          $t3, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r11;
    // 0x800ECA6C: beq         $v1, $zero, L_800ECAA4
    if (ctx->r3 == 0) {
        // 0x800ECA70: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800ECAA4;
    }
    // 0x800ECA70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800ECA74: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800ECA78: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800ECA7C: addiu       $t5, $s2, 0x2
    ctx->r13 = ADD32(ctx->r18, 0X2);
    // 0x800ECA80: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800ECA84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECA88: bgez        $t4, L_800ECA9C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800ECA8C: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800ECA9C;
    }
    // 0x800ECA8C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800ECA90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ECA94: nop

    // 0x800ECA98: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_800ECA9C:
    // 0x800ECA9C: b           L_800ECAA8
    // 0x800ECAA0: sw          $t5, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r13;
        goto L_800ECAA8;
    // 0x800ECAA0: sw          $t5, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r13;
L_800ECAA4:
    // 0x800ECAA4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800ECAA8:
    // 0x800ECAA8: beq         $v0, $zero, L_800ECB00
    if (ctx->r2 == 0) {
        // 0x800ECAAC: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800ECB00;
    }
    // 0x800ECAAC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800ECAB0: beq         $t6, $zero, L_800ECAF0
    if (ctx->r14 == 0) {
        // 0x800ECAB4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800ECAF0;
    }
    // 0x800ECAB4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800ECAB8: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800ECABC: addu        $s1, $fp, $t7
    ctx->r17 = ADD32(ctx->r30, ctx->r15);
    // 0x800ECAC0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800ECAC4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ECAC8: addiu       $a1, $s3, 0x1
    ctx->r5 = ADD32(ctx->r19, 0X1);
    // 0x800ECACC: bnel        $s0, $zero, L_800ECAE8
    if (ctx->r16 != 0) {
        // 0x800ECAD0: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_800ECAE8;
    }
    goto skip_14;
    // 0x800ECAD0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800ECAD4: jal         0x80008E78
    // 0x800ECAD8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_12;
    // 0x800ECAD8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_12:
    // 0x800ECADC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800ECAE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800ECAE4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_800ECAE8:
    // 0x800ECAE8: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800ECAEC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_800ECAF0:
    // 0x800ECAF0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800ECAF4: sra         $v0, $s5, 1
    ctx->r2 = S32(SIGNED(ctx->r21) >> 1);
    // 0x800ECAF8: bne         $s3, $s7, L_800ECAA8
    if (ctx->r19 != ctx->r23) {
        // 0x800ECAFC: andi        $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 & 0XFFFF;
            goto L_800ECAA8;
    }
    // 0x800ECAFC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_800ECB00:
    // 0x800ECB00: b           L_800ECC58
    // 0x800ECB04: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800ECB04: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800ECB08:
    // 0x800ECB08: addiu       $t8, $s2, 0x2
    ctx->r24 = ADD32(ctx->r18, 0X2);
    // 0x800ECB0C: sw          $t8, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r24;
    // 0x800ECB10: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800ECB14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ECB18: bnel        $t9, $zero, L_800ECB30
    if (ctx->r25 != 0) {
        // 0x800ECB1C: lw          $s2, 0x70($s6)
        ctx->r18 = MEM_W(ctx->r22, 0X70);
            goto L_800ECB30;
    }
    goto skip_15;
    // 0x800ECB1C: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    skip_15:
    // 0x800ECB20: jal         0x80008E78
    // 0x800ECB24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    gcAddAObjForDObj(rdram, ctx);
        goto after_13;
    // 0x800ECB24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x800ECB28: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x800ECB2C: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
L_800ECB30:
    // 0x800ECB30: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800ECB34: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x800ECB38: bgez        $t0, L_800ECB48
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800ECB3C: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800ECB48;
    }
    // 0x800ECB3C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800ECB40: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800ECB44: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800ECB48:
    // 0x800ECB48: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800ECB4C: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x800ECB50: sw          $t3, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r11;
    // 0x800ECB54: lw          $t5, 0x70($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X70);
    // 0x800ECB58: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800ECB5C: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800ECB60: b           L_800ECC58
    // 0x800ECB64: sw          $t6, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r14;
        goto L_800ECC58;
    // 0x800ECB64: sw          $t6, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r14;
L_800ECB68:
    // 0x800ECB68: lw          $v0, 0x6C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X6C);
    // 0x800ECB6C: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800ECB70: beql        $v0, $zero, L_800ECBAC
    if (ctx->r2 == 0) {
        // 0x800ECB74: lw          $t8, 0x4($s6)
        ctx->r24 = MEM_W(ctx->r22, 0X4);
            goto L_800ECBAC;
    }
    goto skip_16;
    // 0x800ECB74: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    skip_16:
    // 0x800ECB78: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
L_800ECB7C:
    // 0x800ECB7C: beql        $t7, $zero, L_800ECBA0
    if (ctx->r15 == 0) {
        // 0x800ECB80: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800ECBA0;
    }
    goto skip_17;
    // 0x800ECB80: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_17:
    // 0x800ECB84: lwc1        $f10, 0x78($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X78);
    // 0x800ECB88: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800ECB8C: add.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800ECB90: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800ECB94: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x800ECB98: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800ECB9C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800ECBA0:
    // 0x800ECBA0: bnel        $v0, $zero, L_800ECB7C
    if (ctx->r2 != 0) {
        // 0x800ECBA4: lbu         $t7, 0x5($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X5);
            goto L_800ECB7C;
    }
    goto skip_18;
    // 0x800ECBA4: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    skip_18:
    // 0x800ECBA8: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
L_800ECBAC:
    // 0x800ECBAC: swc1        $f0, 0x7C($s6)
    MEM_W(0X7C, ctx->r22) = ctx->f0.u32l;
    // 0x800ECBB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800ECBB4: swc1        $f0, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->f0.u32l;
    // 0x800ECBB8: lbu         $t9, 0x55($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X55);
    // 0x800ECBBC: lwc1        $f18, 0x170($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X170);
    // 0x800ECBC0: beq         $t9, $zero, L_800ECC68
    if (ctx->r25 == 0) {
        // 0x800ECBC4: swc1        $f18, 0x74($s6)
        MEM_W(0X74, ctx->r22) = ctx->f18.u32l;
            goto L_800ECC68;
    }
    // 0x800ECBC4: swc1        $f18, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f18.u32l;
    // 0x800ECBC8: lw          $t0, 0x4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X4);
    // 0x800ECBCC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ECBD0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800ECBD4: lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X80);
    // 0x800ECBD8: beql        $v0, $zero, L_800ECC6C
    if (ctx->r2 == 0) {
        // 0x800ECBDC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800ECC6C;
    }
    goto skip_19;
    // 0x800ECBDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_19:
    // 0x800ECBE0: jalr        $v0
    // 0x800ECBE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_14;
    // 0x800ECBE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
    // 0x800ECBE8: b           L_800ECC6C
    // 0x800ECBEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800ECC6C;
    // 0x800ECBEC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800ECBF0:
    // 0x800ECBF0: sll         $t1, $a0, 21
    ctx->r9 = S32(ctx->r4 << 21);
    // 0x800ECBF4: srl         $t2, $t1, 22
    ctx->r10 = S32(U32(ctx->r9) >> 22);
    // 0x800ECBF8: sb          $t2, 0x54($s6)
    MEM_B(0X54, ctx->r22) = ctx->r10;
    // 0x800ECBFC: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800ECC00: addiu       $t3, $s2, 0x2
    ctx->r11 = ADD32(ctx->r18, 0X2);
    // 0x800ECC04: sw          $t3, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r11;
    // 0x800ECC08: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x800ECC0C: beq         $v1, $zero, L_800ECC4C
    if (ctx->r3 == 0) {
        // 0x800ECC10: nop
    
            goto L_800ECC4C;
    }
    // 0x800ECC10: nop

    // 0x800ECC14: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800ECC18: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800ECC1C: lwc1        $f4, 0x74($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X74);
    // 0x800ECC20: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800ECC24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ECC28: bgez        $t4, L_800ECC3C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800ECC2C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800ECC3C;
    }
    // 0x800ECC2C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800ECC30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ECC34: nop

    // 0x800ECC38: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800ECC3C:
    // 0x800ECC3C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800ECC40: addiu       $t5, $s2, 0x2
    ctx->r13 = ADD32(ctx->r18, 0X2);
    // 0x800ECC44: sw          $t5, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r13;
    // 0x800ECC48: swc1        $f16, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->f16.u32l;
L_800ECC4C:
    // 0x800ECC4C: b           L_800ECC58
    // 0x800ECC50: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
        goto L_800ECC58;
    // 0x800ECC50: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800ECC54:
    // 0x800ECC54: lwc1        $f0, 0x74($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X74);
L_800ECC58:
    // 0x800ECC58: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x800ECC5C: nop

    // 0x800ECC60: bc1tl       L_800EC368
    if (c1cs) {
        // 0x800ECC64: lw          $s2, 0x70($s6)
        ctx->r18 = MEM_W(ctx->r22, 0X70);
            goto L_800EC368;
    }
    goto skip_20;
    // 0x800ECC64: lw          $s2, 0x70($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X70);
    skip_20:
L_800ECC68:
    // 0x800ECC68: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800ECC6C:
    // 0x800ECC6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800ECC70: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800ECC74: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800ECC78: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800ECC7C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800ECC80: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800ECC84: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800ECC88: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800ECC8C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800ECC90: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800ECC94: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800ECC98: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800ECC9C: jr          $ra
    // 0x800ECCA0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800ECCA0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void mnVSResultsFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B2C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B30: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B3C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B48: jal         0x8039051C
    // 0x80131B4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B50: jal         0x80390528
    // 0x80131B54: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B54: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B60: jal         0x800FCB70
    // 0x80131B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B70: jr          $ra
    // 0x80131B74: nop

    return;
    // 0x80131B74: nop

;}
RECOMP_FUNC void itBombHeiThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017753C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80177540: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80177544: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80177548: jal         0x80172558
    // 0x8017754C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017754C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80177550: jal         0x801713F4
    // 0x80177554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80177554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80177558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017755C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177564: jr          $ra
    // 0x80177568: nop

    return;
    // 0x80177568: nop

;}
RECOMP_FUNC void scSubsysControllerGetPlayerStickInRangeUD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390AC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80390AC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80390AC8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80390ACC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80390AD0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80390AD4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80390AD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80390ADC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80390AE0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80390AE4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80390AE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80390AEC: addiu       $s1, $s1, 0x5228
    ctx->r17 = ADD32(ctx->r17, 0X5228);
    // 0x80390AF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80390AF4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80390AF8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80390AFC:
    // 0x80390AFC: jal         0x80390700
    // 0x80390B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x80390B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80390B04: beql        $v0, $zero, L_80390B4C
    if (ctx->r2 == 0) {
        // 0x80390B08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390B4C;
    }
    goto skip_0;
    // 0x80390B08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80390B0C: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80390B10: mflo        $t6
    ctx->r14 = lo;
    // 0x80390B14: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80390B18: lb          $v0, 0x9($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X9);
    // 0x80390B1C: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80390B20: bne         $at, $zero, L_80390B30
    if (ctx->r1 != 0) {
        // 0x80390B24: slt         $at, $s5, $v0
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80390B30;
    }
    // 0x80390B24: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80390B28: beq         $at, $zero, L_80390B38
    if (ctx->r1 == 0) {
        // 0x80390B2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80390B38;
    }
    // 0x80390B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80390B30:
    // 0x80390B30: b           L_80390B38
    // 0x80390B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80390B38;
    // 0x80390B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390B38:
    // 0x80390B38: beql        $v0, $zero, L_80390B4C
    if (ctx->r2 == 0) {
        // 0x80390B3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390B4C;
    }
    goto skip_1;
    // 0x80390B3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80390B40: b           L_80390B58
    // 0x80390B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80390B58;
    // 0x80390B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80390B48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80390B4C:
    // 0x80390B4C: bne         $s0, $s3, L_80390AFC
    if (ctx->r16 != ctx->r19) {
        // 0x80390B50: nop
    
            goto L_80390AFC;
    }
    // 0x80390B50: nop

    // 0x80390B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390B58:
    // 0x80390B58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80390B5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80390B60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80390B64: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80390B68: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80390B6C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80390B70: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80390B74: jr          $ra
    // 0x80390B78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80390B78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_8037EF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EF0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037EF10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037EF14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037EF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037EF1C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037EF20: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8037EF24: bne         $a0, $zero, L_8037EF3C
    if (ctx->r4 != 0) {
        // 0x8037EF28: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8037EF3C;
    }
    // 0x8037EF28: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8037EF2C: jal         0x803717A0
    // 0x8037EF30: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037EF30: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x8037EF34: beq         $v0, $zero, L_8037F01C
    if (ctx->r2 == 0) {
        // 0x8037EF38: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037F01C;
    }
    // 0x8037EF38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037EF3C:
    // 0x8037EF3C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8037EF40: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037EF44: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x8037EF48: bnel        $t6, $zero, L_8037EF6C
    if (ctx->r14 != 0) {
        // 0x8037EF4C: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_8037EF6C;
    }
    goto skip_0;
    // 0x8037EF4C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8037EF50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037EF54: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8037EF58: jal         0x803717E0
    // 0x8037EF5C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037EF5C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037EF60: jal         0x8037C2D0
    // 0x8037EF64: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037EF64: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8037EF68: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_8037EF6C:
    // 0x8037EF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EF70: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037EF74: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8037EF78: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037EF7C: jal         0x80373CC4
    // 0x8037EF80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80373CC4(rdram, ctx);
        goto after_3;
    // 0x8037EF80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037EF84: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037EF88: addiu       $t8, $t8, -0x5490
    ctx->r24 = ADD32(ctx->r24, -0X5490);
    // 0x8037EF8C: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x8037EF90: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8037EF94: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037EF98: addiu       $t9, $t9, -0x53B8
    ctx->r25 = ADD32(ctx->r25, -0X53B8);
    // 0x8037EF9C: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x8037EFA0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8037EFA4: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037EFA8: addiu       $t1, $t1, -0x5260
    ctx->r9 = ADD32(ctx->r9, -0X5260);
    // 0x8037EFAC: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8037EFB0: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8037EFB4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8037EFB8: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8037EFBC: lh          $t3, 0x70($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X70);
    // 0x8037EFC0: jalr        $t9
    // 0x8037EFC4: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8037EFC4: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    after_4:
    // 0x8037EFC8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8037EFCC: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8037EFD0: ori         $at, $at, 0x5842
    ctx->r1 = ctx->r1 | 0X5842;
    // 0x8037EFD4: lw          $v1, 0x14($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X14);
    // 0x8037EFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EFDC: beq         $v1, $at, L_8037F004
    if (ctx->r3 == ctx->r1) {
        // 0x8037EFE0: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_8037F004;
    }
    // 0x8037EFE0: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8037EFE4: ori         $at, $at, 0x5442
    ctx->r1 = ctx->r1 | 0X5442;
    // 0x8037EFE8: beq         $v1, $at, L_8037F00C
    if (ctx->r3 == ctx->r1) {
        // 0x8037EFEC: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_8037F00C;
    }
    // 0x8037EFEC: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8037EFF0: ori         $at, $at, 0x4F42
    ctx->r1 = ctx->r1 | 0X4F42;
    // 0x8037EFF4: beq         $v1, $at, L_8037F014
    if (ctx->r3 == ctx->r1) {
        // 0x8037EFF8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8037F014;
    }
    // 0x8037EFF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037EFFC: b           L_8037F014
    // 0x8037F000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037F014;
    // 0x8037F000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037F004:
    // 0x8037F004: b           L_8037F014
    // 0x8037F008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037F014;
    // 0x8037F008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037F00C:
    // 0x8037F00C: b           L_8037F014
    // 0x8037F010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037F014;
    // 0x8037F010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037F014:
    // 0x8037F014: jal         0x8037F030
    // 0x8037F018: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    func_ovl8_8037F030(rdram, ctx);
        goto after_5;
    // 0x8037F018: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    after_5:
L_8037F01C:
    // 0x8037F01C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037F020: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037F024: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037F028: jr          $ra
    // 0x8037F02C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037F02C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_80371D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371D10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80371D14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80371D18: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80371D1C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80371D20: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80371D24: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80371D28: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x80371D2C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80371D30: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80371D34: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80371D38: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80371D3C: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80371D40: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80371D44: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80371D48: lh          $t0, 0xD0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XD0);
    // 0x80371D4C: jalr        $t9
    // 0x80371D50: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371D50: addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    after_0:
    // 0x80371D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371D58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371D5C: jr          $ra
    // 0x80371D60: nop

    return;
    // 0x80371D60: nop

;}
RECOMP_FUNC void mvOpeningRoomInitScene2Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801333E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801333E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801333E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801333EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801333F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801333F4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801333F8: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x801333FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133400: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133404: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133408: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013340C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133410: jal         0x80007080
    // 0x80133414: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x80133414: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80133418: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013341C: lw          $t7, 0x50BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50BC);
    // 0x80133420: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133424: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80133428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013342C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133430: jal         0x8000FA3C
    // 0x80133434: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80133434: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133438: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8013343C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80133440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80133444: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133448: jal         0x80008188
    // 0x8013344C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8013344C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133450: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x80133454: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80133458: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x8013345C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133460: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133468: jr          $ra
    // 0x8013346C: nop

    return;
    // 0x8013346C: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeOutside(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D90: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131D94: jal         0x80009968
    // 0x80131D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D9C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131DA0: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131DA4: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80131DA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131DAC: addiu       $t7, $t7, 0x4200
    ctx->r15 = ADD32(ctx->r15, 0X4200);
    // 0x80131DB0: sw          $v0, 0x4D18($at)
    MEM_W(0X4D18, ctx->r1) = ctx->r2;
    // 0x80131DB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131DB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DBC: jal         0x800092D0
    // 0x80131DC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131DC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DC8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131DCC: jal         0x80008CC0
    // 0x80131DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80131DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80131DD4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131DD8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131DDC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131DE0: addiu       $a1, $a1, 0x43FC
    ctx->r5 = ADD32(ctx->r5, 0X43FC);
    // 0x80131DE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131DE8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131DEC: jal         0x80009DF4
    // 0x80131DF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80131DF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131DFC: jr          $ra
    // 0x80131E00: nop

    return;
    // 0x80131E00: nop

;}
RECOMP_FUNC void mvOpeningRunFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void mpCollisionClearYakumonoAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC450: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC454: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x800FC458: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800FC45C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FC460: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    // 0x800FC464: addiu       $a1, $a1, 0x1304
    ctx->r5 = ADD32(ctx->r5, 0X1304);
    // 0x800FC468: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FC46C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800FC470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC474: beq         $a0, $t7, L_800FC4A0
    if (ctx->r4 == ctx->r15) {
        // 0x800FC478: nop
    
            goto L_800FC4A0;
    }
    // 0x800FC478: nop

    // 0x800FC47C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_800FC480:
    // 0x800FC480: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x800FC484: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800FC488: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800FC48C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800FC490: sw          $zero, 0x84($t0)
    MEM_W(0X84, ctx->r8) = 0;
    // 0x800FC494: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800FC498: bnel        $a0, $t1, L_800FC480
    if (ctx->r4 != ctx->r9) {
        // 0x800FC49C: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_800FC480;
    }
    goto skip_0;
    // 0x800FC49C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_0:
L_800FC4A0:
    // 0x800FC4A0: jr          $ra
    // 0x800FC4A4: sh          $zero, 0x1398($at)
    MEM_H(0X1398, ctx->r1) = 0;
    return;
    // 0x800FC4A4: sh          $zero, 0x1398($at)
    MEM_H(0X1398, ctx->r1) = 0;
;}
RECOMP_FUNC void mpCollisionInitLineTypesAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB2A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB2A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FB2A8: addiu       $a2, $a2, 0x136C
    ctx->r6 = ADD32(ctx->r6, 0X136C);
    // 0x800FB2AC: addiu       $a0, $a0, 0x1348
    ctx->r4 = ADD32(ctx->r4, 0X1348);
    // 0x800FB2B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FB2B4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800FB2B8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
L_800FB2BC:
    // 0x800FB2BC: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB2C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FB2C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FB2C8: blezl       $t6, L_800FB30C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FB2CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800FB30C;
    }
    goto skip_0;
    // 0x800FB2CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800FB2D0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
L_800FB2D4:
    // 0x800FB2D4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800FB2D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FB2DC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800FB2E0: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800FB2E4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800FB2E8: multu       $t1, $a3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB2EC: mflo        $t2
    ctx->r10 = lo;
    // 0x800FB2F0: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x800FB2F4: sb          $v0, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r2;
    // 0x800FB2F8: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB2FC: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800FB300: bnel        $at, $zero, L_800FB2D4
    if (ctx->r1 != 0) {
        // 0x800FB304: lw          $t8, 0x4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X4);
            goto L_800FB2D4;
    }
    goto skip_1;
    // 0x800FB304: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x800FB308: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800FB30C:
    // 0x800FB30C: bne         $v0, $t0, L_800FB2BC
    if (ctx->r2 != ctx->r8) {
        // 0x800FB310: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800FB2BC;
    }
    // 0x800FB310: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800FB314: jr          $ra
    // 0x800FB318: nop

    return;
    // 0x800FB318: nop

;}
RECOMP_FUNC void mvOpeningMarioMakeName(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D1BC: addiu       $t7, $t7, -0x1F10
    ctx->r15 = ADD32(ctx->r15, -0X1F10);
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
    // 0x8018D1F0: addiu       $t1, $t1, -0x1EF8
    ctx->r9 = ADD32(ctx->r9, -0X1EF8);
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
    // 0x8018D24C: sw          $v0, -0x1DF4($at)
    MEM_W(-0X1DF4, ctx->r1) = ctx->r2;
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
    // 0x8018D290: addiu       $s2, $s2, -0x1BE0
    ctx->r18 = ADD32(ctx->r18, -0X1BE0);
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
    mvOpeningMarioInitName(rdram, ctx);
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
RECOMP_FUNC void func_ovl8_80386AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80386B00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80386B04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80386B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80386B0C: beq         $a0, $zero, L_80386BCC
    if (ctx->r4 == 0) {
        // 0x80386B10: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80386BCC;
    }
    // 0x80386B10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80386B14: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80386B18: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80386B1C: addiu       $t6, $t6, -0x17C0
    ctx->r14 = ADD32(ctx->r14, -0X17C0);
    // 0x80386B20: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80386B24: addiu       $t7, $t7, -0x1700
    ctx->r15 = ADD32(ctx->r15, -0X1700);
    // 0x80386B28: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80386B2C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80386B30: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80386B34: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80386B38: addiu       $t9, $t9, -0x15A8
    ctx->r25 = ADD32(ctx->r25, -0X15A8);
    // 0x80386B3C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80386B40: addiu       $t1, $t1, -0x1580
    ctx->r9 = ADD32(ctx->r9, -0X1580);
    // 0x80386B44: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80386B48: beq         $a0, $zero, L_80386B90
    if (ctx->r4 == 0) {
        // 0x80386B4C: sw          $t1, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->r9;
            goto L_80386B90;
    }
    // 0x80386B4C: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x80386B50: lw          $t4, 0x20($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X20);
    // 0x80386B54: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80386B58: addiu       $t2, $t2, -0x1A60
    ctx->r10 = ADD32(ctx->r10, -0X1A60);
    // 0x80386B5C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80386B60: addiu       $t3, $t3, -0x19A0
    ctx->r11 = ADD32(ctx->r11, -0X19A0);
    // 0x80386B64: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x80386B68: sw          $t3, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->r11;
    // 0x80386B6C: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80386B70: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80386B74: addiu       $t5, $t5, -0x1848
    ctx->r13 = ADD32(ctx->r13, -0X1848);
    // 0x80386B78: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80386B7C: addiu       $t7, $t7, -0x1820
    ctx->r15 = ADD32(ctx->r15, -0X1820);
    // 0x80386B80: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x80386B84: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x80386B88: jal         0x803761F4
    // 0x80386B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803761F4(rdram, ctx);
        goto after_0;
    // 0x80386B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_80386B90:
    // 0x80386B90: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80386B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80386B98: beql        $t8, $zero, L_80386BB8
    if (ctx->r24 == 0) {
        // 0x80386B9C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80386BB8;
    }
    goto skip_0;
    // 0x80386B9C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80386BA0: jal         0x8037C30C
    // 0x80386BA4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x80386BA4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x80386BA8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80386BAC: jal         0x803718C4
    // 0x80386BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80386BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80386BB4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80386BB8:
    // 0x80386BB8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80386BBC: beql        $t0, $zero, L_80386BD0
    if (ctx->r8 == 0) {
        // 0x80386BC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80386BD0;
    }
    goto skip_1;
    // 0x80386BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80386BC4: jal         0x803717C0
    // 0x80386BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80386BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80386BCC:
    // 0x80386BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80386BD0:
    // 0x80386BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80386BD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80386BD8: jr          $ra
    // 0x80386BDC: nop

    return;
    // 0x80386BDC: nop

;}
RECOMP_FUNC void syDebugWaitFramebufferOrController(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022908: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002290C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80022910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80022914: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022918: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8002291C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80022920: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80022924: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022928: addiu       $s2, $s2, 0x5470
    ctx->r18 = ADD32(ctx->r18, 0X5470);
L_8002292C:
    // 0x8002292C: jal         0x8002272C
    // 0x80022930: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    syDebugWaitMsec(rdram, ctx);
        goto after_0;
    // 0x80022930: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x80022934: jal         0x80004310
    // 0x80022938: nop

    syControllerFuncRead(rdram, ctx);
        goto after_1;
    // 0x80022938: nop

    after_1:
    // 0x8002293C: beql        $s0, $zero, L_80022960
    if (ctx->r16 == 0) {
        // 0x80022940: lhu         $t6, 0x0($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X0);
            goto L_80022960;
    }
    goto skip_0;
    // 0x80022940: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    skip_0:
    // 0x80022944: jal         0x80039630
    // 0x80022948: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x80022948: nop

    after_2:
    // 0x8002294C: beql        $v0, $s0, L_80022960
    if (ctx->r2 == ctx->r16) {
        // 0x80022950: lhu         $t6, 0x0($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X0);
            goto L_80022960;
    }
    goto skip_1;
    // 0x80022950: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    skip_1:
    // 0x80022954: b           L_8002296C
    // 0x80022958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002296C;
    // 0x80022958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002295C: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
L_80022960:
    // 0x80022960: bne         $s1, $t6, L_8002292C
    if (ctx->r17 != ctx->r14) {
        // 0x80022964: nop
    
            goto L_8002292C;
    }
    // 0x80022964: nop

    // 0x80022968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002296C:
    // 0x8002296C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022974: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80022978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002297C: jr          $ra
    // 0x80022980: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022980: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_803726CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803726CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803726D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803726D4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x803726D8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x803726DC: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    // 0x803726E0: beql        $a2, $zero, L_80372770
    if (ctx->r6 == 0) {
        // 0x803726E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80372770;
    }
    goto skip_0;
    // 0x803726E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803726E8: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x803726EC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x803726F0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803726F4: lh          $t6, 0xA0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA0);
    // 0x803726F8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x803726FC: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x80372700: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x80372704: jalr        $t9
    // 0x80372708: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372708: nop

    after_0:
    // 0x8037270C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80372710: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80372714: lw          $v1, 0x10($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X10);
    // 0x80372718: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037271C: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x80372720: lh          $t7, 0xA0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA0);
    // 0x80372724: jalr        $t9
    // 0x80372728: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372728: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_1:
    // 0x8037272C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80372730: lh          $t0, 0x2C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2C);
    // 0x80372734: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80372738: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x8037273C: lh          $t2, 0x2E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2E);
    // 0x80372740: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80372744: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80372748: lh          $t8, 0x40($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X40);
    // 0x8037274C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80372750: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x80372754: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80372758: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037275C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80372760: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80372764: jalr        $t9
    // 0x80372768: addu        $a0, $t8, $a3
    ctx->r4 = ADD32(ctx->r24, ctx->r7);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80372768: addu        $a0, $t8, $a3
    ctx->r4 = ADD32(ctx->r24, ctx->r7);
    after_2:
    // 0x8037276C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80372770:
    // 0x80372770: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80372774: jr          $ra
    // 0x80372778: nop

    return;
    // 0x80372778: nop

;}
RECOMP_FUNC void ftCommonFireFlowerShootAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147758: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8014775C: jal         0x800DE6E4
    // 0x80147760: addiu       $a1, $a1, 0x7774
    ctx->r5 = ADD32(ctx->r5, 0X7774);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80147760: addiu       $a1, $a1, 0x7774
    ctx->r5 = ADD32(ctx->r5, 0X7774);
    after_0:
    // 0x80147764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014776C: jr          $ra
    // 0x80147770: nop

    return;
    // 0x80147770: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151F5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80151F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151F64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151F68: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151F6C: jal         0x800DEEC8
    // 0x80151F70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80151F70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151F74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151F78: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80151F7C: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80151F80: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151F84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151F88: jal         0x800E6F24
    // 0x80151F8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151F8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151F90: jal         0x800D8EB8
    // 0x80151F94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80151F94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80151F98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151F9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151FA0: jr          $ra
    // 0x80151FA4: nop

    return;
    // 0x80151FA4: nop

;}
RECOMP_FUNC void itNBumperThrownProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B754: jal         0x80172FE0
    // 0x8017B758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x8017B758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017B75C: jal         0x8017279C
    // 0x8017B760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017B760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017B764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B76C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B770: jr          $ra
    // 0x8017B774: nop

    return;
    // 0x8017B774: nop

;}
RECOMP_FUNC void mnPlayersVSMakeTeamSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013271C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132720: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132728: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8013272C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80132730: addiu       $t7, $t7, -0x4A6C
    ctx->r15 = ADD32(ctx->r15, -0X4A6C);
    // 0x80132734: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132738: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8013273C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132740: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132744: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013274C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132750: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132754: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132758: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013275C: jal         0x80009968
    // 0x80132760: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132760: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x80132764: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80132768: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013276C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132770: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80132774: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80132778: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8013277C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80132780: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80132784: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80132788: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8013278C: sw          $v0, -0x455C($at)
    MEM_W(-0X455C, ctx->r1) = ctx->r2;
    // 0x80132790: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80132794: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132798: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013279C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327A0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x801327A4: jal         0x80009DF4
    // 0x801327A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801327A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801327AC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x801327B0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801327B4: lw          $t6, -0x3B60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3B60);
    // 0x801327B8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801327BC: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x801327C0: lw          $t5, 0x24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X24);
    // 0x801327C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801327C8: jal         0x800CCFDC
    // 0x801327CC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801327CC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x801327D0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801327D4: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801327D8: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x801327DC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801327E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801327E4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801327E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801327EC: addiu       $t9, $t8, 0x22
    ctx->r25 = ADD32(ctx->r24, 0X22);
    // 0x801327F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801327F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801327F8: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x801327FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132800: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132804: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132808: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013280C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132810: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132818: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013281C: jr          $ra
    // 0x80132820: nop

    return;
    // 0x80132820: nop

;}
RECOMP_FUNC void syUtilsArcCos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800187C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800187C4: lwc1        $f4, -0x1C78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C78);
    // 0x800187C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800187CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800187D0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800187D4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800187D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800187DC: bc1f        L_800187F0
    if (!c1cs) {
        // 0x800187E0: nop
    
            goto L_800187F0;
    }
    // 0x800187E0: nop

    // 0x800187E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800187E8: b           L_80018844
    // 0x800187EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018844;
    // 0x800187EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800187F0:
    // 0x800187F0: lwc1        $f6, -0x1C74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C74);
    // 0x800187F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800187F8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x800187FC: nop

    // 0x80018800: bc1f        L_80018810
    if (!c1cs) {
        // 0x80018804: nop
    
            goto L_80018810;
    }
    // 0x80018804: nop

    // 0x80018808: b           L_80018840
    // 0x8001880C: lwc1        $f0, -0x1C70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C70);
        goto L_80018840;
    // 0x8001880C: lwc1        $f0, -0x1C70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C70);
L_80018810:
    // 0x80018810: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018814: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018818: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001881C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80018820: jal         0x80033510
    // 0x80018824: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018824: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80018828: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001882C: jal         0x80018514
    // 0x80018830: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    syUtilsArcTan(rdram, ctx);
        goto after_1;
    // 0x80018830: div.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
    // 0x80018834: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018838: lwc1        $f16, -0x1C6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C6C);
    // 0x8001883C: sub.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
L_80018840:
    // 0x80018840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018844:
    // 0x80018844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018848: jr          $ra
    // 0x8001884C: nop

    return;
    // 0x8001884C: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser2DProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107238: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010723C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107240: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80107244: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80107248: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8010724C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80107250: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80107254: addiu       $a3, $v0, 0x20
    ctx->r7 = ADD32(ctx->r2, 0X20);
    // 0x80107258: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8010725C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80107260: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80107264: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x80107268: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8010726C: jal         0x80019438
    // 0x80107270: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80107270: nop

    after_0:
    // 0x80107274: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80107278: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8010727C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80107280: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80107284: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80107288: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8010728C: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80107290: jal         0x80018EE0
    // 0x80107294: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    syVectorNorm3D(rdram, ctx);
        goto after_1;
    // 0x80107294: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    after_1:
    // 0x80107298: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8010729C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x801072A0: lw          $a1, 0x74($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X74);
    // 0x801072A4: jal         0x8010719C
    // 0x801072A8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_ovl2_8010719C(rdram, ctx);
        goto after_2;
    // 0x801072A8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_2:
    // 0x801072AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801072B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801072B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801072B8: jr          $ra
    // 0x801072BC: nop

    return;
    // 0x801072BC: nop

;}
RECOMP_FUNC void ftNessSpecialLwEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155A7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155A84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155A88: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155A8C: jal         0x800DEEC8
    // 0x80155A90: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80155A90: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155A94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155A98: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80155A9C: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x80155AA0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155AA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155AA8: jal         0x800E6F24
    // 0x80155AAC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155AAC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155AB0: jal         0x800D8EB8
    // 0x80155AB4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80155AB4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80155AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155ABC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155AC0: jr          $ra
    // 0x80155AC4: nop

    return;
    // 0x80155AC4: nop

;}
RECOMP_FUNC void ftDisplayMainDrawDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1E60: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800F1E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F1E68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F1E6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F1E70: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800F1E74: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800F1E78: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F1E7C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800F1E80: addiu       $t2, $t2, 0x62D0
    ctx->r10 = ADD32(ctx->r10, 0X62D0);
    // 0x800F1E84: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800F1E88: lw          $t8, 0x84($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X84);
    // 0x800F1E8C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800F1E90: lbu         $t9, 0x54($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X54);
    // 0x800F1E94: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x800F1E98: bnel        $t0, $zero, L_800F2178
    if (ctx->r8 != 0) {
        // 0x800F1E9C: lw          $t8, 0xC($s1)
        ctx->r24 = MEM_W(ctx->r17, 0XC);
            goto L_800F2178;
    }
    goto skip_0;
    // 0x800F1E9C: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x800F1EA0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800F1EA4: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800F1EA8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800F1EAC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800F1EB0: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800F1EB4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x800F1EB8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1EBC: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x800F1EC0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800F1EC4: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F1EC8: beq         $t5, $zero, L_800F2074
    if (ctx->r13 == 0) {
        // 0x800F1ECC: nop
    
            goto L_800F2074;
    }
    // 0x800F1ECC: nop

    // 0x800F1ED0: lbu         $a0, 0xC($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0XC);
    // 0x800F1ED4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F1ED8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F1EDC: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x800F1EE0: beq         $v0, $zero, L_800F1EF8
    if (ctx->r2 == 0) {
        // 0x800F1EE4: nop
    
            goto L_800F1EF8;
    }
    // 0x800F1EE4: nop

    // 0x800F1EE8: beql        $v0, $at, L_800F1FA8
    if (ctx->r2 == ctx->r1) {
        // 0x800F1EEC: lw          $s0, 0x50($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X50);
            goto L_800F1FA8;
    }
    goto skip_1;
    // 0x800F1EEC: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
    skip_1:
    // 0x800F1EF0: b           L_800F20BC
    // 0x800F1EF4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
        goto L_800F20BC;
    // 0x800F1EF4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_800F1EF8:
    // 0x800F1EF8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1EFC: jal         0x80010D70
    // 0x800F1F00: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800F1F00: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    after_0:
    // 0x800F1F04: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800F1F08: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800F1F0C: beql        $t6, $zero, L_800F1F44
    if (ctx->r14 == 0) {
        // 0x800F1F10: lw          $t0, 0x50($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X50);
            goto L_800F1F44;
    }
    goto skip_2;
    // 0x800F1F10: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
    skip_2:
    // 0x800F1F14: lw          $t7, 0xDC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XDC);
    // 0x800F1F18: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800F1F1C: beql        $t7, $zero, L_800F1F44
    if (ctx->r15 == 0) {
        // 0x800F1F20: lw          $t0, 0x50($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X50);
            goto L_800F1F44;
    }
    goto skip_3;
    // 0x800F1F20: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
    skip_3:
    // 0x800F1F24: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800F1F28: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F1F2C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800F1F30: bne         $t9, $at, L_800F1F40
    if (ctx->r25 != ctx->r1) {
        // 0x800F1F34: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800F1F40;
    }
    // 0x800F1F34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F1F38: jal         0x800F1D44
    // 0x800F1F3C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    ftDisplayMainDrawAccessory(rdram, ctx);
        goto after_1;
    // 0x800F1F3C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_1:
L_800F1F40:
    // 0x800F1F40: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
L_800F1F44:
    // 0x800F1F44: beql        $t0, $zero, L_800F20BC
    if (ctx->r8 == 0) {
        // 0x800F1F48: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_4;
    // 0x800F1F48: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x800F1F4C: lbu         $t1, 0x54($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X54);
    // 0x800F1F50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F1F54: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F1F58: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800F1F5C: bnel        $t2, $zero, L_800F20BC
    if (ctx->r10 != 0) {
        // 0x800F1F60: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_5;
    // 0x800F1F60: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x800F1F64: jal         0x80012D90
    // 0x800F1F68: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x800F1F68: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    after_2:
    // 0x800F1F6C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800F1F70: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800F1F74: jal         0x800F1C08
    // 0x800F1F78: lbu         $a0, 0xC($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0XC);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_3;
    // 0x800F1F78: lbu         $a0, 0xC($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0XC);
    after_3:
    // 0x800F1F7C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800F1F80: lw          $v0, 0x65B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65B0);
    // 0x800F1F84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800F1F88: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800F1F8C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800F1F90: sw          $t4, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r12;
    // 0x800F1F94: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800F1F98: lw          $t7, 0x50($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X50);
    // 0x800F1F9C: b           L_800F20B8
    // 0x800F1FA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_800F20B8;
    // 0x800F1FA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800F1FA4: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
L_800F1FA8:
    // 0x800F1FA8: beq         $s0, $zero, L_800F1FF8
    if (ctx->r16 == 0) {
        // 0x800F1FAC: nop
    
            goto L_800F1FF8;
    }
    // 0x800F1FAC: nop

    // 0x800F1FB0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800F1FB4: beq         $t9, $zero, L_800F1FF8
    if (ctx->r25 == 0) {
        // 0x800F1FB8: nop
    
            goto L_800F1FF8;
    }
    // 0x800F1FB8: nop

    // 0x800F1FBC: lbu         $t8, 0x54($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X54);
    // 0x800F1FC0: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800F1FC4: bne         $t6, $zero, L_800F1FF8
    if (ctx->r14 != 0) {
        // 0x800F1FC8: nop
    
            goto L_800F1FF8;
    }
    // 0x800F1FC8: nop

    // 0x800F1FCC: jal         0x800F1C08
    // 0x800F1FD0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_4;
    // 0x800F1FD0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_4:
    // 0x800F1FD4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1FD8: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F1FDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800F1FE0: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800F1FE4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800F1FE8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800F1FEC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800F1FF0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800F1FF4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_800F1FF8:
    // 0x800F1FF8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1FFC: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F2000: jal         0x80010D70
    // 0x800F2004: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_5;
    // 0x800F2004: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800F2008: beq         $s0, $zero, L_800F20B8
    if (ctx->r16 == 0) {
        // 0x800F200C: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_800F20B8;
    }
    // 0x800F200C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800F2010: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800F2014: beql        $t3, $zero, L_800F20BC
    if (ctx->r11 == 0) {
        // 0x800F2018: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_6;
    // 0x800F2018: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x800F201C: lbu         $t4, 0x54($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X54);
    // 0x800F2020: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F2024: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F2028: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800F202C: bnel        $t5, $zero, L_800F20BC
    if (ctx->r13 != 0) {
        // 0x800F2030: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_7;
    // 0x800F2030: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_7:
    // 0x800F2034: jal         0x80012D90
    // 0x800F2038: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    gcDrawMObjForDObj(rdram, ctx);
        goto after_6;
    // 0x800F2038: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    after_6:
    // 0x800F203C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800F2040: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800F2044: jal         0x800F1C08
    // 0x800F2048: lbu         $a0, 0xC($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XC);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_7;
    // 0x800F2048: lbu         $a0, 0xC($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XC);
    after_7:
    // 0x800F204C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800F2050: lw          $v0, 0x65B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65B0);
    // 0x800F2054: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800F2058: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x800F205C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800F2060: sw          $t9, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r25;
    // 0x800F2064: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800F2068: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800F206C: b           L_800F20B8
    // 0x800F2070: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800F20B8;
    // 0x800F2070: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800F2074:
    // 0x800F2074: jal         0x80010D70
    // 0x800F2078: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_8;
    // 0x800F2078: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800F207C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F2080: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800F2084: beql        $t0, $zero, L_800F20BC
    if (ctx->r8 == 0) {
        // 0x800F2088: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_8;
    // 0x800F2088: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x800F208C: lw          $t1, 0xDC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XDC);
    // 0x800F2090: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800F2094: beql        $t1, $zero, L_800F20BC
    if (ctx->r9 == 0) {
        // 0x800F2098: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_800F20BC;
    }
    goto skip_9;
    // 0x800F2098: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_9:
    // 0x800F209C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800F20A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800F20A4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800F20A8: bne         $t3, $at, L_800F20B8
    if (ctx->r11 != ctx->r1) {
        // 0x800F20AC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800F20B8;
    }
    // 0x800F20AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F20B0: jal         0x800F1D44
    // 0x800F20B4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    ftDisplayMainDrawAccessory(rdram, ctx);
        goto after_9;
    // 0x800F20B4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_9:
L_800F20B8:
    // 0x800F20B8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_800F20BC:
    // 0x800F20BC: beql        $t4, $zero, L_800F20F4
    if (ctx->r12 == 0) {
        // 0x800F20C0: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F20F4;
    }
    goto skip_10;
    // 0x800F20C0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_10:
    // 0x800F20C4: lw          $t5, 0xDC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XDC);
    // 0x800F20C8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800F20CC: beql        $t5, $zero, L_800F20F4
    if (ctx->r13 == 0) {
        // 0x800F20D0: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F20F4;
    }
    goto skip_11;
    // 0x800F20D0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_11:
    // 0x800F20D4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800F20D8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800F20DC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800F20E0: bne         $t9, $at, L_800F20F0
    if (ctx->r25 != ctx->r1) {
        // 0x800F20E4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800F20F0;
    }
    // 0x800F20E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F20E8: jal         0x800F1D44
    // 0x800F20EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    ftDisplayMainDrawAccessory(rdram, ctx);
        goto after_10;
    // 0x800F20EC: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_10:
L_800F20F0:
    // 0x800F20F0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
L_800F20F4:
    // 0x800F20F4: beql        $a0, $zero, L_800F2108
    if (ctx->r4 == 0) {
        // 0x800F20F8: lw          $t8, 0x58($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X58);
            goto L_800F2108;
    }
    goto skip_12;
    // 0x800F20F8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    skip_12:
    // 0x800F20FC: jal         0x800F1E60
    // 0x800F2100: nop

    ftDisplayMainDrawDefault(rdram, ctx);
        goto after_11;
    // 0x800F2100: nop

    after_11:
    // 0x800F2104: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
L_800F2108:
    // 0x800F2108: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800F210C: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800F2110: beql        $t8, $zero, L_800F215C
    if (ctx->r24 == 0) {
        // 0x800F2114: lw          $t4, 0x0($t9)
        ctx->r12 = MEM_W(ctx->r25, 0X0);
            goto L_800F215C;
    }
    goto skip_13;
    // 0x800F2114: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    skip_13:
    // 0x800F2118: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x800F211C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F2120: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F2124: beq         $t6, $at, L_800F2138
    if (ctx->r14 == ctx->r1) {
        // 0x800F2128: addiu       $a0, $a0, 0x65B0
        ctx->r4 = ADD32(ctx->r4, 0X65B0);
            goto L_800F2138;
    }
    // 0x800F2128: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F212C: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x800F2130: beql        $t1, $zero, L_800F215C
    if (ctx->r9 == 0) {
        // 0x800F2134: lw          $t4, 0x0($t9)
        ctx->r12 = MEM_W(ctx->r25, 0X0);
            goto L_800F215C;
    }
    goto skip_14;
    // 0x800F2134: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    skip_14:
L_800F2138:
    // 0x800F2138: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800F213C: lui         $t2, 0xD838
    ctx->r10 = S32(0XD838 << 16);
    // 0x800F2140: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800F2144: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800F2148: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800F214C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800F2150: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800F2154: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800F2158: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
L_800F215C:
    // 0x800F215C: addiu       $t5, $t5, 0x62D0
    ctx->r13 = ADD32(ctx->r13, 0X62D0);
    // 0x800F2160: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800F2164: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800F2168: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x800F216C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800F2170: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x800F2174: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
L_800F2178:
    // 0x800F2178: bnel        $t8, $zero, L_800F21A4
    if (ctx->r24 != 0) {
        // 0x800F217C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F21A4;
    }
    goto skip_15;
    // 0x800F217C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x800F2180: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x800F2184: beql        $s0, $zero, L_800F21A4
    if (ctx->r16 == 0) {
        // 0x800F2188: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F21A4;
    }
    goto skip_16;
    // 0x800F2188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
L_800F218C:
    // 0x800F218C: jal         0x800F1E60
    // 0x800F2190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainDrawDefault(rdram, ctx);
        goto after_12;
    // 0x800F2190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800F2194: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800F2198: bne         $s0, $zero, L_800F218C
    if (ctx->r16 != 0) {
        // 0x800F219C: nop
    
            goto L_800F218C;
    }
    // 0x800F219C: nop

    // 0x800F21A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F21A4:
    // 0x800F21A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F21A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F21AC: jr          $ra
    // 0x800F21B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800F21B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}

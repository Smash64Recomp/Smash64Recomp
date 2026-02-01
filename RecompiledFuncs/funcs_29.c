#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sySchedulerAddPausedQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D44: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80000D48: addiu       $a1, $a1, 0x4ED8
    ctx->r5 = ADD32(ctx->r5, 0X4ED8);
    // 0x80000D4C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80000D50: beq         $v0, $zero, L_80000D88
    if (ctx->r2 == 0) {
        // 0x80000D54: nop
    
            goto L_80000D88;
    }
    // 0x80000D54: nop

    // 0x80000D58: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80000D5C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80000D60: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80000D64: beq         $at, $zero, L_80000D88
    if (ctx->r1 == 0) {
        // 0x80000D68: nop
    
            goto L_80000D88;
    }
    // 0x80000D68: nop

    // 0x80000D6C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_80000D70:
    // 0x80000D70: beq         $v0, $zero, L_80000D88
    if (ctx->r2 == 0) {
        // 0x80000D74: nop
    
            goto L_80000D88;
    }
    // 0x80000D74: nop

    // 0x80000D78: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80000D7C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80000D80: bnel        $at, $zero, L_80000D70
    if (ctx->r1 != 0) {
        // 0x80000D84: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_80000D70;
    }
    goto skip_0;
    // 0x80000D84: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
L_80000D88:
    // 0x80000D88: beq         $v0, $zero, L_80000DA0
    if (ctx->r2 == 0) {
        // 0x80000D8C: sw          $v0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r2;
            goto L_80000DA0;
    }
    // 0x80000D8C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80000D90: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80000D94: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x80000D98: b           L_80000DB4
    // 0x80000D9C: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80000DB4;
    // 0x80000D9C: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
L_80000DA0:
    // 0x80000DA0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000DA4: addiu       $v0, $v0, 0x4ED4
    ctx->r2 = ADD32(ctx->r2, 0X4ED4);
    // 0x80000DA8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000DAC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x80000DB0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80000DB4:
    // 0x80000DB4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000DB8: beql        $v0, $zero, L_80000DCC
    if (ctx->r2 == 0) {
        // 0x80000DBC: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_80000DCC;
    }
    goto skip_1;
    // 0x80000DBC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    skip_1:
    // 0x80000DC0: jr          $ra
    // 0x80000DC4: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    return;
    // 0x80000DC4: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x80000DC8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_80000DCC:
    // 0x80000DCC: jr          $ra
    // 0x80000DD0: nop

    return;
    // 0x80000DD0: nop

;}
RECOMP_FUNC void ftCommonDamageGetDamageLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140A94: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80140A98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80140A9C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80140AA0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80140AA4: nop

    // 0x80140AA8: bc1fl       L_80140ABC
    if (!c1cs) {
        // 0x80140AAC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80140ABC;
    }
    goto skip_0;
    // 0x80140AAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80140AB0: jr          $ra
    // 0x80140AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80140AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80140AB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80140ABC:
    // 0x80140ABC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80140AC0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80140AC4: nop

    // 0x80140AC8: bc1fl       L_80140ADC
    if (!c1cs) {
        // 0x80140ACC: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80140ADC;
    }
    goto skip_1;
    // 0x80140ACC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80140AD0: jr          $ra
    // 0x80140AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80140AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140AD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80140ADC:
    // 0x80140ADC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80140AE0: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80140AE4: nop

    // 0x80140AE8: bc1f        L_80140AF8
    if (!c1cs) {
        // 0x80140AEC: nop
    
            goto L_80140AF8;
    }
    // 0x80140AEC: nop

    // 0x80140AF0: jr          $ra
    // 0x80140AF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80140AF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80140AF8:
    // 0x80140AF8: jr          $ra
    // 0x80140AFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80140AFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl2_8010D14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D14C: jr          $ra
    // 0x8010D150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8010D150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mvOpeningRoomInitScene3Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133590: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133594: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013359C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801335A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801335A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801335A8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801335AC: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x801335B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801335B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335BC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801335C0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801335C4: jal         0x80007080
    // 0x801335C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x801335C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801335CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335D0: lwc1        $f6, 0x4C90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C90);
    // 0x801335D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801335DC: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x801335E0: lwc1        $f8, 0x4C94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C94);
    // 0x801335E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801335EC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x801335F0: lwc1        $f10, 0x4C98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C98);
    // 0x801335F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335F8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801335FC: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80133600: lwc1        $f16, 0x4C9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4C9C);
    // 0x80133604: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133608: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x8013360C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80133610: lwc1        $f18, 0x4CA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4CA0);
    // 0x80133614: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133618: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013361C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80133620: lwc1        $f4, 0x4CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4CA4);
    // 0x80133624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133628: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013362C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133630: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80133634: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80133638: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8013363C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80133640: lwc1        $f8, 0x4CA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4CA8);
    // 0x80133644: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80133648: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013364C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80133650: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133654: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80133658: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x8013365C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80133660: lw          $t7, 0x50C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50C0);
    // 0x80133664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133668: jal         0x8000FA3C
    // 0x8013366C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8013366C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133670: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133674: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80133678: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013367C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133680: jal         0x80008188
    // 0x80133684: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80133684: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133688: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x8013368C: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80133690: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x80133694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013369C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801336A0: jr          $ra
    // 0x801336A4: nop

    return;
    // 0x801336A4: nop

;}
RECOMP_FUNC void lbCommonTan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C793C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7940: lwc1        $f4, 0x5E6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E6C);
    // 0x800C7944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7948: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C794C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7950: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800C7954: nop

    // 0x800C7958: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800C795C: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800C7960: andi        $t7, $a0, 0x400
    ctx->r15 = ctx->r4 & 0X400;
    // 0x800C7964: beq         $t7, $zero, L_800C7988
    if (ctx->r15 == 0) {
        // 0x800C7968: andi        $t3, $a0, 0x800
        ctx->r11 = ctx->r4 & 0X800;
            goto L_800C7988;
    }
    // 0x800C7968: andi        $t3, $a0, 0x800
    ctx->r11 = ctx->r4 & 0X800;
    // 0x800C796C: andi        $t8, $a0, 0x3FF
    ctx->r24 = ctx->r4 & 0X3FF;
    // 0x800C7970: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C7974: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x800C7978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C797C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C7980: b           L_800C7998
    // 0x800C7984: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
        goto L_800C7998;
    // 0x800C7984: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
L_800C7988:
    // 0x800C7988: andi        $t1, $a0, 0x3FF
    ctx->r9 = ctx->r4 & 0X3FF;
    // 0x800C798C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C7990: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C7994: lwc1        $f2, 0x4CA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4CA0);
L_800C7998:
    // 0x800C7998: beq         $t3, $zero, L_800C79A4
    if (ctx->r11 == 0) {
        // 0x800C799C: addiu       $v0, $a0, 0x400
        ctx->r2 = ADD32(ctx->r4, 0X400);
            goto L_800C79A4;
    }
    // 0x800C799C: addiu       $v0, $a0, 0x400
    ctx->r2 = ADD32(ctx->r4, 0X400);
    // 0x800C79A0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800C79A4:
    // 0x800C79A4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C79A8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C79AC: andi        $t4, $v0, 0x400
    ctx->r12 = ctx->r2 & 0X400;
    // 0x800C79B0: beq         $t4, $zero, L_800C79D4
    if (ctx->r12 == 0) {
        // 0x800C79B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C79D4;
    }
    // 0x800C79B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C79B8: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x800C79BC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C79C0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800C79C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C79C8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C79CC: b           L_800C79E8
    // 0x800C79D0: lwc1        $f12, 0x5C9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5C9C);
        goto L_800C79E8;
    // 0x800C79D0: lwc1        $f12, 0x5C9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5C9C);
L_800C79D4:
    // 0x800C79D4: andi        $t8, $v1, 0x3FF
    ctx->r24 = ctx->r3 & 0X3FF;
    // 0x800C79D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C79DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C79E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C79E4: lwc1        $f12, 0x4CA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4CA0);
L_800C79E8:
    // 0x800C79E8: andi        $t0, $v1, 0x800
    ctx->r8 = ctx->r3 & 0X800;
    // 0x800C79EC: beq         $t0, $zero, L_800C79F8
    if (ctx->r8 == 0) {
        // 0x800C79F0: nop
    
            goto L_800C79F8;
    }
    // 0x800C79F0: nop

    // 0x800C79F4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800C79F8:
    // 0x800C79F8: jr          $ra
    // 0x800C79FC: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    return;
    // 0x800C79FC: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
;}
RECOMP_FUNC void mnMapsAllocModelHeaps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131B08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131B0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131B10: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80131B14: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80131B18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131B20: addiu       $s2, $s2, 0x452C
    ctx->r18 = ADD32(ctx->r18, 0X452C);
    // 0x80131B24: addiu       $s0, $s0, 0x44E4
    ctx->r16 = ADD32(ctx->r16, 0X44E4);
L_80131B28:
    // 0x80131B28: jal         0x800CDBD0
    // 0x80131B2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x80131B2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80131B30: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80131B34: beq         $at, $zero, L_80131B40
    if (ctx->r1 == 0) {
        // 0x80131B38: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80131B40;
    }
    // 0x80131B38: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80131B3C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80131B40:
    // 0x80131B40: bne         $s0, $s2, L_80131B28
    if (ctx->r16 != ctx->r18) {
        // 0x80131B44: nop
    
            goto L_80131B28;
    }
    // 0x80131B44: nop

    // 0x80131B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131B4C: jal         0x80004980
    // 0x80131B50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x80131B50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80131B54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131B58: sw          $v0, 0x4E24($at)
    MEM_W(0X4E24, ctx->r1) = ctx->r2;
    // 0x80131B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131B60: jal         0x80004980
    // 0x80131B64: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80131B64: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80131B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131B6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131B70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131B74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131B78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131B7C: sw          $v0, 0x4E28($at)
    MEM_W(0X4E28, ctx->r1) = ctx->r2;
    // 0x80131B80: jr          $ra
    // 0x80131B84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131B84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSModeMakeButtonViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801334D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801334D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801334D8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801334DC: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801334E0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801334E4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801334E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801334EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801334F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801334F4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801334F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801334FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133500: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133504: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133508: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013350C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133510: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133514: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133518: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013351C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133528: jal         0x8000B93C
    // 0x8013352C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013352C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133530: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133534: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133538: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013353C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133540: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133544: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133548: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013354C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133550: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133554: jal         0x80007080
    // 0x80133558: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133558: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013355C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133560: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133564: jr          $ra
    // 0x80133568: nop

    return;
    // 0x80133568: nop

;}
RECOMP_FUNC void wpLinkSpinAttackProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CB10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8016CB14: jr          $ra
    // 0x8016CB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016CB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void lbParticleMakeStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE4E4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CE4E8: addiu       $t0, $t0, 0x6350
    ctx->r8 = ADD32(ctx->r8, 0X6350);
    // 0x800CE4EC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800CE4F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800CE4F4: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800CE4F8: bne         $v1, $zero, L_800CE508
    if (ctx->r3 != 0) {
        // 0x800CE4FC: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800CE508;
    }
    // 0x800CE4FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CE500: jr          $ra
    // 0x800CE504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE508:
    // 0x800CE508: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CE50C: addiu       $a0, $a0, 0x6448
    ctx->r4 = ADD32(ctx->r4, 0X6448);
    // 0x800CE510: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800CE514: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800CE518: addiu       $t1, $t1, 0x644E
    ctx->r9 = ADD32(ctx->r9, 0X644E);
    // 0x800CE51C: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x800CE520: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CE524: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800CE528: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CE52C: beq         $at, $zero, L_800CE538
    if (ctx->r1 == 0) {
        // 0x800CE530: sh          $t7, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r15;
            goto L_800CE538;
    }
    // 0x800CE530: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800CE534: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
L_800CE538:
    // 0x800CE538: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800CE53C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CE540: addiu       $v0, $v0, 0x5D58
    ctx->r2 = ADD32(ctx->r2, 0X5D58);
    // 0x800CE544: beql        $a0, $zero, L_800CE55C
    if (ctx->r4 == 0) {
        // 0x800CE548: lhu         $t2, 0x0($v0)
        ctx->r10 = MEM_HU(ctx->r2, 0X0);
            goto L_800CE55C;
    }
    goto skip_0;
    // 0x800CE548: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x800CE54C: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x800CE550: b           L_800CE568
    // 0x800CE554: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_800CE568;
    // 0x800CE554: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x800CE558: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
L_800CE55C:
    // 0x800CE55C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800CE560: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x800CE564: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
L_800CE568:
    // 0x800CE568: beq         $a0, $zero, L_800CE58C
    if (ctx->r4 == 0) {
        // 0x800CE56C: sra         $t2, $a1, 3
        ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
            goto L_800CE58C;
    }
    // 0x800CE56C: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800CE570: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x800CE574: beq         $t5, $zero, L_800CE590
    if (ctx->r13 == 0) {
        // 0x800CE578: sw          $t5, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r13;
            goto L_800CE590;
    }
    // 0x800CE578: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    // 0x800CE57C: lhu         $t6, 0x2A($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2A);
    // 0x800CE580: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CE584: b           L_800CE590
    // 0x800CE588: sh          $t7, 0x2A($t5)
    MEM_H(0X2A, ctx->r13) = ctx->r15;
        goto L_800CE590;
    // 0x800CE588: sh          $t7, 0x2A($t5)
    MEM_H(0X2A, ctx->r13) = ctx->r15;
L_800CE58C:
    // 0x800CE58C: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
L_800CE590:
    // 0x800CE590: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800CE594: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800CE598: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800CE59C: bne         $t9, $zero, L_800CE5C0
    if (ctx->r25 != 0) {
        // 0x800CE5A0: sw          $t8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r24;
            goto L_800CE5C0;
    }
    // 0x800CE5A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800CE5A4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800CE5A8: addiu       $t4, $t4, 0x6358
    ctx->r12 = ADD32(ctx->r12, 0X6358);
    // 0x800CE5AC: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800CE5B0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800CE5B4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800CE5B8: b           L_800CE5D4
    // 0x800CE5BC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_800CE5D4;
    // 0x800CE5BC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_800CE5C0:
    // 0x800CE5C0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800CE5C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CE5C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CE5CC: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800CE5D0: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
L_800CE5D4:
    // 0x800CE5D4: sb          $a1, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r5;
    // 0x800CE5D8: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // 0x800CE5DC: sb          $a3, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r7;
    // 0x800CE5E0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CE5E4: ori         $t6, $a2, 0x10
    ctx->r14 = ctx->r6 | 0X10;
    // 0x800CE5E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CE5EC: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x800CE5F0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CE5F4: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x800CE5F8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CE5FC: swc1        $f8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f8.u32l;
    // 0x800CE600: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800CE604: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
    // 0x800CE608: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800CE60C: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x800CE610: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800CE614: swc1        $f18, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f18.u32l;
    // 0x800CE618: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800CE61C: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x800CE620: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800CE624: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800CE628: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x800CE62C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CE630: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x800CE634: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800CE638: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x800CE63C: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
    // 0x800CE640: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800CE644: sh          $t2, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r10;
    // 0x800CE648: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800CE64C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800CE650: beq         $t4, $zero, L_800CE65C
    if (ctx->r12 == 0) {
        // 0x800CE654: nop
    
            goto L_800CE65C;
    }
    // 0x800CE654: nop

    // 0x800CE658: sh          $t6, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r14;
L_800CE65C:
    // 0x800CE65C: beql        $v0, $zero, L_800CE670
    if (ctx->r2 == 0) {
        // 0x800CE660: sh          $zero, 0xC($v1)
        MEM_H(0XC, ctx->r3) = 0;
            goto L_800CE670;
    }
    goto skip_1;
    // 0x800CE660: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    skip_1:
    // 0x800CE664: b           L_800CE670
    // 0x800CE668: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
        goto L_800CE670;
    // 0x800CE668: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
    // 0x800CE66C: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
L_800CE670:
    // 0x800CE670: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800CE674: sb          $v0, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r2;
    // 0x800CE678: sb          $v0, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r2;
    // 0x800CE67C: sb          $v0, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r2;
    // 0x800CE680: sb          $v0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r2;
    // 0x800CE684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE688: sb          $v0, 0x52($v1)
    MEM_B(0X52, ctx->r3) = ctx->r2;
    // 0x800CE68C: sb          $v0, 0x51($v1)
    MEM_B(0X51, ctx->r3) = ctx->r2;
    // 0x800CE690: sb          $v0, 0x50($v1)
    MEM_B(0X50, ctx->r3) = ctx->r2;
    // 0x800CE694: sb          $zero, 0xB($v1)
    MEM_B(0XB, ctx->r3) = 0;
    // 0x800CE698: sb          $zero, 0x53($v1)
    MEM_B(0X53, ctx->r3) = 0;
    // 0x800CE69C: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x800CE6A0: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x800CE6A4: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x800CE6A8: sw          $a0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r4;
    // 0x800CE6AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE6B0: jr          $ra
    // 0x800CE6B4: nop

    return;
    // 0x800CE6B4: nop

;}
RECOMP_FUNC void ftPurinSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801516A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801516A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801516A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801516AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801516B0: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x801516B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801516B8: jal         0x800E6F24
    // 0x801516BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801516BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801516C0: jal         0x800E0830
    // 0x801516C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801516C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801516C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801516CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801516D0: jr          $ra
    // 0x801516D4: nop

    return;
    // 0x801516D4: nop

;}
RECOMP_FUNC void efManagerCaptainFalconKickMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101EE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101EE8: jal         0x800FDB1C
    // 0x80101EEC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80101EEC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    after_0:
    // 0x80101EF0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80101EF4: bne         $v0, $zero, L_80101F04
    if (ctx->r2 != 0) {
        // 0x80101EF8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80101F04;
    }
    // 0x80101EF8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80101EFC: b           L_80101F74
    // 0x80101F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101F74;
    // 0x80101F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101F04:
    // 0x80101F04: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80101F08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101F0C: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80101F10: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x80101F14: lw          $a2, 0x74($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X74);
    // 0x80101F18: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80101F1C: lw          $t6, 0x944($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X944);
    // 0x80101F20: sw          $t6, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r14;
    // 0x80101F24: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x80101F28: lwc1        $f8, 0x9E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9E8);
    // 0x80101F2C: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80101F30: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80101F34: nop

    // 0x80101F38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101F3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80101F40: swc1        $f10, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f10.u32l;
    // 0x80101F44: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80101F48: bne         $t8, $at, L_80101F74
    if (ctx->r24 != ctx->r1) {
        // 0x80101F4C: nop
    
            goto L_80101F74;
    }
    // 0x80101F4C: nop

    // 0x80101F50: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x80101F54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101F58: lwc1        $f4, 0x9EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9EC);
    // 0x80101F5C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x80101F60: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80101F64: nop

    // 0x80101F68: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80101F6C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80101F70: swc1        $f6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f6.u32l;
L_80101F74:
    // 0x80101F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101F7C: jr          $ra
    // 0x80101F80: nop

    return;
    // 0x80101F80: nop

;}
RECOMP_FUNC void itBatThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175008: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017500C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175010: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    // 0x80175014: jal         0x80172EC8
    // 0x80175018: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80175018: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8017501C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80175020: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175024: lwc1        $f4, -0x3330($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3330);
    // 0x80175028: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8017502C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80175030: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80175034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017503C: jr          $ra
    // 0x80175040: nop

    return;
    // 0x80175040: nop

;}
RECOMP_FUNC void func_80000E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E5C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80000E60: beql        $v0, $zero, L_80000E78
    if (ctx->r2 == 0) {
        // 0x80000E64: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_80000E78;
    }
    goto skip_0;
    // 0x80000E64: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x80000E68: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80000E6C: b           L_80000E80
    // 0x80000E70: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
        goto L_80000E80;
    // 0x80000E70: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80000E74: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_80000E78:
    // 0x80000E78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000E7C: sw          $t7, 0x4EDC($at)
    MEM_W(0X4EDC, ctx->r1) = ctx->r15;
L_80000E80:
    // 0x80000E80: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000E84: beql        $v0, $zero, L_80000E9C
    if (ctx->r2 == 0) {
        // 0x80000E88: lw          $t9, 0x10($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X10);
            goto L_80000E9C;
    }
    goto skip_1;
    // 0x80000E88: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x80000E8C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80000E90: jr          $ra
    // 0x80000E94: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    return;
    // 0x80000E94: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80000E98: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
L_80000E9C:
    // 0x80000E9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000EA0: sw          $t9, 0x4EE0($at)
    MEM_W(0X4EE0, ctx->r1) = ctx->r25;
    // 0x80000EA4: jr          $ra
    // 0x80000EA8: nop

    return;
    // 0x80000EA8: nop

;}
RECOMP_FUNC void func_ovl8_8037A6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A6D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037A6D8: lh          $a3, 0x4($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X4);
    // 0x8037A6DC: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8037A6E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037A6E4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8037A6E8: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8037A6EC: beql        $at, $zero, L_8037A710
    if (ctx->r1 == 0) {
        // 0x8037A6F0: lh          $a2, 0x0($a0)
        ctx->r6 = MEM_H(ctx->r4, 0X0);
            goto L_8037A710;
    }
    goto skip_0;
    // 0x8037A6F0: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    skip_0:
    // 0x8037A6F4: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x8037A6F8: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8037A6FC: bnel        $at, $zero, L_8037A710
    if (ctx->r1 != 0) {
        // 0x8037A700: lh          $a2, 0x0($a0)
        ctx->r6 = MEM_H(ctx->r4, 0X0);
            goto L_8037A710;
    }
    goto skip_1;
    // 0x8037A700: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    skip_1:
    // 0x8037A704: b           L_8037A754
    // 0x8037A708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037A754;
    // 0x8037A708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037A70C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
L_8037A710:
    // 0x8037A710: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037A714: bnel        $at, $zero, L_8037A738
    if (ctx->r1 != 0) {
        // 0x8037A718: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8037A738;
    }
    goto skip_2;
    // 0x8037A718: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
    // 0x8037A71C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x8037A720: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8037A724: beql        $at, $zero, L_8037A738
    if (ctx->r1 == 0) {
        // 0x8037A728: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8037A738;
    }
    goto skip_3;
    // 0x8037A728: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    skip_3:
    // 0x8037A72C: b           L_8037A754
    // 0x8037A730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037A754;
    // 0x8037A730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037A734: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
L_8037A738:
    // 0x8037A738: beq         $at, $zero, L_8037A754
    if (ctx->r1 == 0) {
        // 0x8037A73C: nop
    
            goto L_8037A754;
    }
    // 0x8037A73C: nop

    // 0x8037A740: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x8037A744: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8037A748: bne         $at, $zero, L_8037A754
    if (ctx->r1 != 0) {
        // 0x8037A74C: nop
    
            goto L_8037A754;
    }
    // 0x8037A74C: nop

    // 0x8037A750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037A754:
    // 0x8037A754: beql        $v0, $zero, L_8037A894
    if (ctx->r2 == 0) {
        // 0x8037A758: lw          $t7, 0x8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8);
            goto L_8037A894;
    }
    goto skip_4;
    // 0x8037A758: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    skip_4:
    // 0x8037A75C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x8037A760: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8037A764: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037A768: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8037A76C: beq         $at, $zero, L_8037A780
    if (ctx->r1 == 0) {
        // 0x8037A770: nop
    
            goto L_8037A780;
    }
    // 0x8037A770: nop

    // 0x8037A774: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8037A778: b           L_8037A780
    // 0x8037A77C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8037A780;
    // 0x8037A77C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037A780:
    // 0x8037A780: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x8037A784: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x8037A788: lh          $a3, 0x4($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X4);
    // 0x8037A78C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8037A790: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8037A794: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037A798: beq         $at, $zero, L_8037A7AC
    if (ctx->r1 == 0) {
        // 0x8037A79C: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8037A7AC;
    }
    // 0x8037A79C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037A7A0: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x8037A7A4: b           L_8037A7AC
    // 0x8037A7A8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8037A7AC;
    // 0x8037A7A8: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037A7AC:
    // 0x8037A7AC: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
    // 0x8037A7B0: lh          $a2, 0x6($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X6);
    // 0x8037A7B4: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x8037A7B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037A7BC: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8037A7C0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8037A7C4: beql        $at, $zero, L_8037A7E8
    if (ctx->r1 == 0) {
        // 0x8037A7C8: lh          $a3, 0x2($a0)
        ctx->r7 = MEM_H(ctx->r4, 0X2);
            goto L_8037A7E8;
    }
    goto skip_5;
    // 0x8037A7C8: lh          $a3, 0x2($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X2);
    skip_5:
    // 0x8037A7CC: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x8037A7D0: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8037A7D4: bnel        $at, $zero, L_8037A7E8
    if (ctx->r1 != 0) {
        // 0x8037A7D8: lh          $a3, 0x2($a0)
        ctx->r7 = MEM_H(ctx->r4, 0X2);
            goto L_8037A7E8;
    }
    goto skip_6;
    // 0x8037A7D8: lh          $a3, 0x2($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X2);
    skip_6:
    // 0x8037A7DC: b           L_8037A82C
    // 0x8037A7E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037A82C;
    // 0x8037A7E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037A7E4: lh          $a3, 0x2($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X2);
L_8037A7E8:
    // 0x8037A7E8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037A7EC: bnel        $at, $zero, L_8037A810
    if (ctx->r1 != 0) {
        // 0x8037A7F0: slt         $at, $a3, $v1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8037A810;
    }
    goto skip_7;
    // 0x8037A7F0: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    skip_7:
    // 0x8037A7F4: lh          $t3, 0x6($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X6);
    // 0x8037A7F8: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8037A7FC: beql        $at, $zero, L_8037A810
    if (ctx->r1 == 0) {
        // 0x8037A800: slt         $at, $a3, $v1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8037A810;
    }
    goto skip_8;
    // 0x8037A800: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    skip_8:
    // 0x8037A804: b           L_8037A82C
    // 0x8037A808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037A82C;
    // 0x8037A808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037A80C: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
L_8037A810:
    // 0x8037A810: beq         $at, $zero, L_8037A82C
    if (ctx->r1 == 0) {
        // 0x8037A814: nop
    
            goto L_8037A82C;
    }
    // 0x8037A814: nop

    // 0x8037A818: lh          $t4, 0x6($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X6);
    // 0x8037A81C: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8037A820: bne         $at, $zero, L_8037A82C
    if (ctx->r1 != 0) {
        // 0x8037A824: nop
    
            goto L_8037A82C;
    }
    // 0x8037A824: nop

    // 0x8037A828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037A82C:
    // 0x8037A82C: beql        $v0, $zero, L_8037A894
    if (ctx->r2 == 0) {
        // 0x8037A830: lw          $t7, 0x8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8);
            goto L_8037A894;
    }
    goto skip_9;
    // 0x8037A830: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    skip_9:
    // 0x8037A834: lh          $a3, 0x2($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X2);
    // 0x8037A838: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8037A83C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037A840: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8037A844: beq         $at, $zero, L_8037A858
    if (ctx->r1 == 0) {
        // 0x8037A848: nop
    
            goto L_8037A858;
    }
    // 0x8037A848: nop

    // 0x8037A84C: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x8037A850: b           L_8037A858
    // 0x8037A854: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8037A858;
    // 0x8037A854: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037A858:
    // 0x8037A858: sh          $t0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r8;
    // 0x8037A85C: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    // 0x8037A860: lh          $a2, 0x6($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X6);
    // 0x8037A864: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8037A868: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8037A86C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037A870: beq         $at, $zero, L_8037A884
    if (ctx->r1 == 0) {
        // 0x8037A874: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8037A884;
    }
    // 0x8037A874: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037A878: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8037A87C: b           L_8037A884
    // 0x8037A880: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
        goto L_8037A884;
    // 0x8037A880: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037A884:
    // 0x8037A884: sh          $t0, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r8;
    // 0x8037A888: jr          $ra
    // 0x8037A88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037A88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037A890: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
L_8037A894:
    // 0x8037A894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037A898: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x8037A89C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8037A8A0: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x8037A8A4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8037A8A8: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
    // 0x8037A8AC: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8037A8B0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x8037A8B4: jr          $ra
    // 0x8037A8B8: nop

    return;
    // 0x8037A8B8: nop

;}
RECOMP_FUNC void itIwarkCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DB5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DB64: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8017DB68: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8017DB6C: jal         0x801737B8
    // 0x8017DB70: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017DB70: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017DB74: beq         $v0, $zero, L_8017DB8C
    if (ctx->r2 == 0) {
        // 0x8017DB78: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8017DB8C;
    }
    // 0x8017DB78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DB7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017DB80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8017DB84: jal         0x80173F54
    // 0x8017DB88: swc1        $f4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f4.u32l;
    itMapSetGround(rdram, ctx);
        goto after_1;
    // 0x8017DB88: swc1        $f4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f4.u32l;
    after_1:
L_8017DB8C:
    // 0x8017DB8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DB90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DB94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DB98: jr          $ra
    // 0x8017DB9C: nop

    return;
    // 0x8017DB9C: nop

;}
RECOMP_FUNC void itHeartFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801746F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801746F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801746F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801746FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174700: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80174704: jal         0x80172558
    // 0x80174708: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174708: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_0:
    // 0x8017470C: jal         0x801713F4
    // 0x80174710: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80174710: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80174714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017471C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174720: jr          $ra
    // 0x80174724: nop

    return;
    // 0x80174724: nop

;}
RECOMP_FUNC void ftParamUpdateStaleQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA614: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800EA618: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800EA61C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800EA620: andi        $s0, $a3, 0xFFFF
    ctx->r16 = ctx->r7 & 0XFFFF;
    // 0x800EA624: beq         $a0, $t1, L_800EA740
    if (ctx->r4 == ctx->r9) {
        // 0x800EA628: sw          $a3, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r7;
            goto L_800EA740;
    }
    // 0x800EA628: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x800EA62C: beq         $a0, $a1, L_800EA740
    if (ctx->r4 == ctx->r5) {
        // 0x800EA630: lui         $t2, 0x800A
        ctx->r10 = S32(0X800A << 16);
            goto L_800EA740;
    }
    // 0x800EA630: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800EA634: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800EA638: addiu       $t2, $t2, 0x50E8
    ctx->r10 = ADD32(ctx->r10, 0X50E8);
    // 0x800EA63C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800EA640: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800EA644: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800EA648: sll         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4 << 3);
    // 0x800EA64C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800EA650: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x800EA654: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800EA658: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800EA65C: addu        $a3, $v1, $t7
    ctx->r7 = ADD32(ctx->r3, ctx->r15);
    // 0x800EA660: lhu         $t8, 0x80($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X80);
    // 0x800EA664: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x800EA668: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800EA66C: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x800EA670: lw          $v0, 0x7C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X7C);
    // 0x800EA674: bne         $a2, $t8, L_800EA684
    if (ctx->r6 != ctx->r24) {
        // 0x800EA678: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_800EA684;
    }
    // 0x800EA678: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800EA67C: lhu         $t9, 0x82($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X82);
    // 0x800EA680: beq         $s0, $t9, L_800EA740
    if (ctx->r16 == ctx->r25) {
        // 0x800EA684: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800EA740;
    }
L_800EA684:
    // 0x800EA684: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EA688: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800EA68C: addu        $t0, $a3, $t3
    ctx->r8 = ADD32(ctx->r7, ctx->r11);
    // 0x800EA690: lhu         $t4, 0x80($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X80);
    // 0x800EA694: bnel        $a2, $t4, L_800EA6AC
    if (ctx->r6 != ctx->r12) {
        // 0x800EA698: lhu         $t6, 0x84($t0)
        ctx->r14 = MEM_HU(ctx->r8, 0X84);
            goto L_800EA6AC;
    }
    goto skip_0;
    // 0x800EA698: lhu         $t6, 0x84($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X84);
    skip_0:
    // 0x800EA69C: lhu         $t5, 0x82($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X82);
    // 0x800EA6A0: beql        $s0, $t5, L_800EA744
    if (ctx->r16 == ctx->r13) {
        // 0x800EA6A4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800EA744;
    }
    goto skip_1;
    // 0x800EA6A4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_1:
    // 0x800EA6A8: lhu         $t6, 0x84($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X84);
L_800EA6AC:
    // 0x800EA6AC: bnel        $a2, $t6, L_800EA6C4
    if (ctx->r6 != ctx->r14) {
        // 0x800EA6B0: lhu         $t8, 0x88($t0)
        ctx->r24 = MEM_HU(ctx->r8, 0X88);
            goto L_800EA6C4;
    }
    goto skip_2;
    // 0x800EA6B0: lhu         $t8, 0x88($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X88);
    skip_2:
    // 0x800EA6B4: lhu         $t7, 0x86($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X86);
    // 0x800EA6B8: beql        $s0, $t7, L_800EA744
    if (ctx->r16 == ctx->r15) {
        // 0x800EA6BC: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800EA744;
    }
    goto skip_3;
    // 0x800EA6BC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_3:
    // 0x800EA6C0: lhu         $t8, 0x88($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X88);
L_800EA6C4:
    // 0x800EA6C4: bnel        $a2, $t8, L_800EA6DC
    if (ctx->r6 != ctx->r24) {
        // 0x800EA6C8: lhu         $t3, 0x8C($t0)
        ctx->r11 = MEM_HU(ctx->r8, 0X8C);
            goto L_800EA6DC;
    }
    goto skip_4;
    // 0x800EA6C8: lhu         $t3, 0x8C($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8C);
    skip_4:
    // 0x800EA6CC: lhu         $t9, 0x8A($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X8A);
    // 0x800EA6D0: beql        $s0, $t9, L_800EA744
    if (ctx->r16 == ctx->r25) {
        // 0x800EA6D4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800EA744;
    }
    goto skip_5;
    // 0x800EA6D4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_5:
    // 0x800EA6D8: lhu         $t3, 0x8C($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X8C);
L_800EA6DC:
    // 0x800EA6DC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800EA6E0: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x800EA6E4: bne         $a2, $t3, L_800EA6F8
    if (ctx->r6 != ctx->r11) {
        // 0x800EA6E8: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800EA6F8;
    }
    // 0x800EA6E8: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800EA6EC: lhu         $t4, 0x8E($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X8E);
    // 0x800EA6F0: beql        $s0, $t4, L_800EA744
    if (ctx->r16 == ctx->r12) {
        // 0x800EA6F4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800EA744;
    }
    goto skip_6;
    // 0x800EA6F4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_6:
L_800EA6F8:
    // 0x800EA6F8: sh          $a2, 0x80($t5)
    MEM_H(0X80, ctx->r13) = ctx->r6;
    // 0x800EA6FC: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800EA700: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800EA704: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800EA708: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800EA70C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800EA710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800EA714: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800EA718: bne         $v0, $t1, L_800EA730
    if (ctx->r2 != ctx->r9) {
        // 0x800EA71C: sh          $s0, 0x82($t9)
        MEM_H(0X82, ctx->r25) = ctx->r16;
            goto L_800EA730;
    }
    // 0x800EA71C: sh          $s0, 0x82($t9)
    MEM_H(0X82, ctx->r25) = ctx->r16;
    // 0x800EA720: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800EA724: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800EA728: b           L_800EA740
    // 0x800EA72C: sw          $zero, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = 0;
        goto L_800EA740;
    // 0x800EA72C: sw          $zero, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = 0;
L_800EA730:
    // 0x800EA730: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800EA734: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800EA738: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800EA73C: sw          $t5, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r13;
L_800EA740:
    // 0x800EA740: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_800EA744:
    // 0x800EA744: jr          $ra
    // 0x800EA748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800EA748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void grInishieInitHeaders(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109BD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109BD8: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x80109BDC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80109BE0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80109BE4: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x80109BE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80109BEC: addiu       $t7, $t7, 0x5F0
    ctx->r15 = ADD32(ctx->r15, 0X5F0);
    // 0x80109BF0: addiu       $t9, $t9, 0x14
    ctx->r25 = ADD32(ctx->r25, 0X14);
    // 0x80109BF4: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80109BF8: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x80109BFC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80109C00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80109C04: jr          $ra
    // 0x80109C08: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    return;
    // 0x80109C08: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeGateCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801329A8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801329AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801329B0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801329B4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801329B8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801329BC: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x801329C0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801329C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801329C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801329CC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801329D0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801329D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801329D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801329DC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801329E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801329E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801329E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801329EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801329F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801329F4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801329F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801329FC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132A00: jal         0x8000B93C
    // 0x80132A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132A0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132A10: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132A14: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132A1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132A20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132A24: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132A28: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132A2C: jal         0x80007080
    // 0x80132A30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132A30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132A34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132A38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132A3C: jr          $ra
    // 0x80132A40: nop

    return;
    // 0x80132A40: nop

;}
RECOMP_FUNC void mnMapsMakePreviewWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132D30: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80132D34: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80132D38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132D3C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80132D40: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80132D44: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80132D48: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80132D4C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80132D50: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80132D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132D58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D60: jal         0x80009968
    // 0x80132D64: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132D64: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_0:
    // 0x80132D68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132D70: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80132D74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D78: addiu       $a1, $a1, 0x2BC8
    ctx->r5 = ADD32(ctx->r5, 0X2BC8);
    // 0x80132D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D80: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80132D84: jal         0x80009DF4
    // 0x80132D88: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132D88: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80132D8C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80132D90: lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // 0x80132D94: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80132D98: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132D9C: addiu       $s3, $s3, 0x4E10
    ctx->r19 = ADD32(ctx->r19, 0X4E10);
    // 0x80132DA0: addiu       $s1, $s1, -0x38D8
    ctx->r17 = ADD32(ctx->r17, -0X38D8);
    // 0x80132DA4: addiu       $s0, $zero, 0x2B
    ctx->r16 = ADD32(0, 0X2B);
    // 0x80132DA8: addiu       $s2, $zero, 0x9B
    ctx->r18 = ADD32(0, 0X9B);
L_80132DAC:
    // 0x80132DAC: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x80132DB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80132DB4: jal         0x800CCFDC
    // 0x80132DB8: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132DB8: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    after_2:
    // 0x80132DBC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80132DC0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80132DC4: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132DC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132DCC: bne         $s0, $s2, L_80132DAC
    if (ctx->r16 != ctx->r18) {
        // 0x80132DD0: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80132DAC;
    }
    // 0x80132DD0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132DD4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80132DD8: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80132DDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80132DE0: bne         $v1, $at, L_80132E18
    if (ctx->r3 != ctx->r1) {
        // 0x80132DE4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132E18;
    }
    // 0x80132DE4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132DE8: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80132DEC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80132DF0: addiu       $t9, $t9, -0x21D0
    ctx->r25 = ADD32(ctx->r25, -0X21D0);
    // 0x80132DF4: jal         0x800CCFDC
    // 0x80132DF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132DF8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80132DFC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132E00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132E04: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80132E08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132E0C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132E10: b           L_80132EC8
    // 0x80132E14: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_80132EC8;
    // 0x80132E14: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132E18:
    // 0x80132E18: lw          $t0, 0x4C18($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C18);
    // 0x80132E1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132E20: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80132E24: bne         $t0, $at, L_80132E84
    if (ctx->r8 != ctx->r1) {
        // 0x80132E28: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80132E84;
    }
    // 0x80132E28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132E2C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132E30: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80132E34: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132E38: lw          $t3, 0x4C10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4C10);
    // 0x80132E3C: lw          $t1, 0x4568($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4568);
    // 0x80132E40: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132E44: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80132E48: lw          $t5, 0x452C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X452C);
    // 0x80132E4C: lw          $t4, 0x48($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X48);
    // 0x80132E50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E54: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80132E58: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80132E5C: lw          $a0, 0x4550($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4550);
    // 0x80132E60: jal         0x800CDDD8
    // 0x80132E64: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    lbRelocGetForceExternHeapFile(rdram, ctx);
        goto after_4;
    // 0x80132E64: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    after_4:
    // 0x80132E68: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80132E6C: addiu       $t6, $t6, 0x718
    ctx->r14 = ADD32(ctx->r14, 0X718);
    // 0x80132E70: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x80132E74: jal         0x800CCFDC
    // 0x80132E78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132E78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80132E7C: b           L_80132E94
    // 0x80132E80: nop

        goto L_80132E94;
    // 0x80132E80: nop

L_80132E84:
    // 0x80132E84: lw          $t7, 0x4C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C10);
    // 0x80132E88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80132E8C: jal         0x800CCFDC
    // 0x80132E90: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132E90: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    after_6:
L_80132E94:
    // 0x80132E94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E98: lwc1        $f0, 0x4BBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4BBC);
    // 0x80132E9C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132EA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132EA4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132EA8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80132EAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132EB0: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80132EB4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132EB8: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80132EBC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80132EC0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132EC4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_80132EC8:
    // 0x80132EC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132ECC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80132ED0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80132ED4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80132ED8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80132EDC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80132EE0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80132EE4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80132EE8: jr          $ra
    // 0x80132EEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80132EEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCaptainSpecialLwSetGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FCC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FCCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FCD0: jal         0x800DEE98
    // 0x8015FCD4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015FCD4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015FCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FCDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FCE0: jr          $ra
    // 0x8015FCE4: nop

    return;
    // 0x8015FCE4: nop

;}
RECOMP_FUNC void dbMenuDrawMenuOptionLabel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803694C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803694CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803694D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803694D4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x803694D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803694DC: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x803694E0: beq         $at, $zero, L_803695EC
    if (ctx->r1 == 0) {
        // 0x803694E4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_803695EC;
    }
    // 0x803694E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x803694E8: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x803694EC: addu        $at, $at, $t6
    gpr jr_addend_803694F4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x803694F0: lw          $t6, -0x5C4C($at)
    ctx->r14 = ADD32(ctx->r1, -0X5C4C);
    // 0x803694F4: jr          $t6
    // 0x803694F8: nop

    switch (jr_addend_803694F4 >> 2) {
        case 0: goto L_803694FC; break;
        case 1: goto L_80369518; break;
        case 2: goto L_80369560; break;
        case 3: goto L_80369594; break;
        case 4: goto L_803694FC; break;
        case 5: goto L_8036953C; break;
        case 6: goto L_803695C4; break;
        default: switch_error(__func__, 0x803694F4, 0x8036A3B4);
    }
    // 0x803694F8: nop

L_803694FC:
    // 0x803694FC: jal         0x803749BC
    // 0x80369500: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_0;
    // 0x80369500: nop

    after_0:
    // 0x80369504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80369508: jal         0x80369310
    // 0x8036950C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    dbMenuDrawString(rdram, ctx);
        goto after_1;
    // 0x8036950C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x80369510: b           L_803695F0
    // 0x80369514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803695F0;
    // 0x80369514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80369518:
    // 0x80369518: jal         0x803749BC
    // 0x8036951C: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_2;
    // 0x8036951C: nop

    after_2:
    // 0x80369520: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80369524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80369528: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8036952C: jal         0x80369310
    // 0x80369530: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    dbMenuDrawString(rdram, ctx);
        goto after_3;
    // 0x80369530: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80369534: b           L_803695F0
    // 0x80369538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803695F0;
    // 0x80369538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8036953C:
    // 0x8036953C: jal         0x803749BC
    // 0x80369540: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_4;
    // 0x80369540: nop

    after_4:
    // 0x80369544: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80369548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8036954C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80369550: jal         0x80369310
    // 0x80369554: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    dbMenuDrawString(rdram, ctx);
        goto after_5;
    // 0x80369554: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    after_5:
    // 0x80369558: b           L_803695F0
    // 0x8036955C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803695F0;
    // 0x8036955C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80369560:
    // 0x80369560: jal         0x803749BC
    // 0x80369564: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_6;
    // 0x80369564: nop

    after_6:
    // 0x80369568: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8036956C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80369570: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80369574: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80369578: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8036957C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80369580: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x80369584: jal         0x80369310
    // 0x80369588: nop

    dbMenuDrawString(rdram, ctx);
        goto after_7;
    // 0x80369588: nop

    after_7:
    // 0x8036958C: b           L_803695F0
    // 0x80369590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803695F0;
    // 0x80369590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80369594:
    // 0x80369594: jal         0x803749BC
    // 0x80369598: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_8;
    // 0x80369598: nop

    after_8:
    // 0x8036959C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x803695A0: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x803695A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803695A8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x803695AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x803695B0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x803695B4: jal         0x80369310
    // 0x803695B8: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    dbMenuDrawString(rdram, ctx);
        goto after_9;
    // 0x803695B8: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    after_9:
    // 0x803695BC: b           L_803695F0
    // 0x803695C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_803695F0;
    // 0x803695C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803695C4:
    // 0x803695C4: jal         0x803749BC
    // 0x803695C8: nop

    func_ovl8_803749BC(rdram, ctx);
        goto after_10;
    // 0x803695C8: nop

    after_10:
    // 0x803695CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x803695D0: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x803695D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803695D8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x803695DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x803695E0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x803695E4: jal         0x80369310
    // 0x803695E8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    dbMenuDrawString(rdram, ctx);
        goto after_11;
    // 0x803695E8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_11:
L_803695EC:
    // 0x803695EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803695F0:
    // 0x803695F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803695F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803695F8: jr          $ra
    // 0x803695FC: nop

    return;
    // 0x803695FC: nop

;}
RECOMP_FUNC void itLGunThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801756AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801756B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801756B4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801756B8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801756BC: addiu       $a1, $a1, -0x647C
    ctx->r5 = ADD32(ctx->r5, -0X647C);
    // 0x801756C0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801756C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801756C8: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x801756CC: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x801756D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801756D4: jal         0x80172EC8
    // 0x801756D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801756D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x801756DC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801756E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801756E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801756E8: bnel        $t0, $at, L_8017570C
    if (ctx->r8 != ctx->r1) {
        // 0x801756EC: lw          $t3, 0x74($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X74);
            goto L_8017570C;
    }
    goto skip_0;
    // 0x801756EC: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x801756F0: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x801756F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801756F8: lwc1        $f4, -0x3310($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3310);
    // 0x801756FC: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80175700: b           L_8017571C
    // 0x80175704: swc1        $f4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f4.u32l;
        goto L_8017571C;
    // 0x80175704: swc1        $f4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f4.u32l;
    // 0x80175708: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
L_8017570C:
    // 0x8017570C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175710: lwc1        $f6, -0x330C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X330C);
    // 0x80175714: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80175718: swc1        $f6, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f6.u32l;
L_8017571C:
    // 0x8017571C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80175724: jr          $ra
    // 0x80175728: nop

    return;
    // 0x80175728: nop

;}
RECOMP_FUNC void wpSamusBombProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801692C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801692C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801692CC: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801692D0: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x801692D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801692D8: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x801692DC: lw          $t8, 0xFC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XFC);
    // 0x801692E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801692E4: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x801692E8: bne         $t8, $at, L_8016930C
    if (ctx->r24 != ctx->r1) {
        // 0x801692EC: sw          $t7, 0x268($a2)
        MEM_W(0X268, ctx->r6) = ctx->r15;
            goto L_8016930C;
    }
    // 0x801692EC: sw          $t7, 0x268($a2)
    MEM_W(0X268, ctx->r6) = ctx->r15;
    // 0x801692F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801692F4: jal         0x801680EC
    // 0x801692F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x801692F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801692FC: jal         0x80167F68
    // 0x80169300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x80169300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80169304: b           L_80169318
    // 0x80169308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80169318;
    // 0x80169308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016930C:
    // 0x8016930C: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x80169310: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x80169314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80169318:
    // 0x80169318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016931C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169320: jr          $ra
    // 0x80169324: nop

    return;
    // 0x80169324: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFallSetStatusPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DBE8: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8014DBEC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8014DBF0: jal         0x80141DA0
    // 0x8014DBF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftCommonPassSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8014DBF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8014DBF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014DBFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DC00: jr          $ra
    // 0x8014DC04: nop

    return;
    // 0x8014DC04: nop

;}
RECOMP_FUNC void func_80007784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007784: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80007788: beql        $v0, $zero, L_800077A0
    if (ctx->r2 == 0) {
        // 0x8000778C: lw          $t8, 0x10($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X10);
            goto L_800077A0;
    }
    goto skip_0;
    // 0x8000778C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    skip_0:
    // 0x80007790: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80007794: b           L_800077B4
    // 0x80007798: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
        goto L_800077B4;
    // 0x80007798: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8000779C: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
L_800077A0:
    // 0x800077A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800077A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800077A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800077AC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800077B0: sw          $t7, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = ctx->r15;
L_800077B4:
    // 0x800077B4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800077B8: beq         $v0, $zero, L_800077C8
    if (ctx->r2 == 0) {
        // 0x800077BC: nop
    
            goto L_800077C8;
    }
    // 0x800077BC: nop

    // 0x800077C0: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x800077C4: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_800077C8:
    // 0x800077C8: jr          $ra
    // 0x800077CC: nop

    return;
    // 0x800077CC: nop

;}
RECOMP_FUNC void ftCommonGuardGetJointTransformScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148664: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80148668: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8014866C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80148670: lwc1        $f18, 0x34($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80148674: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80148678: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8014867C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80148680: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x80148684: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80148688: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8014868C: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80148690: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80148694: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80148698: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x8014869C: lwc1        $f14, 0x1C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801486A0: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801486A4: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801486A8: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x801486AC: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x801486B0: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x801486B4: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801486B8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801486BC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801486C0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801486C4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801486C8: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801486CC: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801486D0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x801486D4: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801486D8: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801486DC: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801486E0: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801486E4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801486E8: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x801486EC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801486F0: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x801486F4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801486F8: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801486FC: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80148700: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80148704: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80148708: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8014870C: jr          $ra
    // 0x80148710: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80148710: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void syVideoInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000702C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80007030: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x80007034: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    // 0x80007038: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8000703C: jal         0x80006DC4
    // 0x80007040: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syVideoSetFramebuffers(rdram, ctx);
        goto after_0;
    // 0x80007040: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80007044: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80007048: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000704C: lw          $t6, 0xC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XC);
    // 0x80007050: sw          $t6, 0x6670($at)
    MEM_W(0X6670, ctx->r1) = ctx->r14;
    // 0x80007054: lw          $a2, 0x18($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X18);
    // 0x80007058: lw          $a1, 0x14($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X14);
    // 0x8000705C: jal         0x80006FB8
    // 0x80007060: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    syVideoSetScreenSettings(rdram, ctx);
        goto after_1;
    // 0x80007060: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    after_1:
    // 0x80007064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000706C: jr          $ra
    // 0x80007070: nop

    return;
    // 0x80007070: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiEndProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015341C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80153420: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80153424: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80153428: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8015342C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80153430: beql        $t6, $zero, L_8015348C
    if (ctx->r14 == 0) {
        // 0x80153434: lwc1        $f0, 0x4C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
            goto L_8015348C;
    }
    goto skip_0;
    // 0x80153434: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    skip_0:
    // 0x80153438: jal         0x800D8E50
    // 0x8015343C: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_0;
    // 0x8015343C: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    after_0:
    // 0x80153440: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x80153444: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80153448: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015344C: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80153450: lwc1        $f8, 0x50($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80153454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80153458: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8015345C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80153460: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80153464: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80153468: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8015346C: jal         0x800D8FC8
    // 0x80153470: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_1;
    // 0x80153470: nop

    after_1:
    // 0x80153474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80153478: jal         0x800D9074
    // 0x8015347C: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x8015347C: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    after_2:
    // 0x80153480: b           L_801534AC
    // 0x80153484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801534AC;
    // 0x80153484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153488: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
L_8015348C:
    // 0x8015348C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80153490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80153494: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    // 0x80153498: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8015349C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801534A0: jal         0x800D9074
    // 0x801534A4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x801534A4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x801534A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801534AC:
    // 0x801534AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801534B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801534B4: jr          $ra
    // 0x801534B8: nop

    return;
    // 0x801534B8: nop

;}
RECOMP_FUNC void mvOpeningPortraitsInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132610: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132614: sw          $zero, 0x29E8($at)
    MEM_W(0X29E8, ctx->r1) = 0;
    // 0x80132618: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013261C: jr          $ra
    // 0x80132620: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
    return;
    // 0x80132620: sw          $zero, 0x29EC($at)
    MEM_W(0X29EC, ctx->r1) = 0;
;}
RECOMP_FUNC void mnPlayersVSMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138DEC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80138DF0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138DF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80138DF8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80138DFC: addiu       $t7, $t7, -0x4764
    ctx->r15 = ADD32(ctx->r15, -0X4764);
    // 0x80138E00: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80138E04: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80138E08: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80138E0C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80138E10: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80138E14: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80138E18: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80138E1C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80138E20: addiu       $t1, $t1, -0x4754
    ctx->r9 = ADD32(ctx->r9, -0X4754);
    // 0x80138E24: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80138E28: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80138E2C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80138E30: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80138E34: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x80138E38: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80138E3C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80138E40: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80138E44: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80138E48: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80138E4C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80138E50: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80138E54: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80138E58: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80138E5C: addiu       $t4, $t4, -0x4734
    ctx->r12 = ADD32(ctx->r12, -0X4734);
    // 0x80138E60: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80138E64: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80138E68: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80138E6C: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80138E70: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80138E74: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80138E78: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    // 0x80138E7C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80138E80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80138E84: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80138E88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80138E8C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80138E90: addiu       $t7, $t7, -0x3100
    ctx->r15 = ADD32(ctx->r15, -0X3100);
    // 0x80138E94: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80138E98: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80138E9C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80138EA0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80138EA4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80138EA8: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80138EAC: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80138EB0: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138EB4: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80138EB8: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x80138EBC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80138EC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80138EC4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80138EC8: lw          $t3, -0x3B60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3B60);
    // 0x80138ECC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138ED0: addiu       $t4, $t4, 0x76E8
    ctx->r12 = ADD32(ctx->r12, 0X76E8);
    // 0x80138ED4: addiu       $t7, $t7, -0x7D20
    ctx->r15 = ADD32(ctx->r15, -0X7D20);
    // 0x80138ED8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80138EDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80138EE0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80138EE4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80138EE8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80138EEC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80138EF0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80138EF4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80138EF8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80138EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138F04: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80138F08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80138F0C: jal         0x800CD050
    // 0x80138F10: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80138F10: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x80138F14: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80138F18: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80138F1C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80138F20: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80138F24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80138F28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138F2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80138F30: sw          $v0, -0x4578($at)
    MEM_W(-0X4578, ctx->r1) = ctx->r2;
    // 0x80138F34: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x80138F38: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x80138F3C: sw          $s0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r16;
    // 0x80138F40: addu        $a3, $t0, $t1
    ctx->r7 = ADD32(ctx->r8, ctx->r9);
    // 0x80138F44: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80138F48: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x80138F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80138F50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80138F54: swc1        $f4, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f4.u32l;
    // 0x80138F58: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80138F5C: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80138F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80138F64: swc1        $f6, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f6.u32l;
    // 0x80138F68: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138F6C: lhu         $t4, 0x24($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X24);
    // 0x80138F70: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x80138F74: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x80138F78: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138F7C: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80138F80: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80138F84: jal         0x80134D54
    // 0x80138F88: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x80138F88: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    after_1:
    // 0x80138F8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80138F90: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80138F94: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80138F98: jr          $ra
    // 0x80138F9C: nop

    return;
    // 0x80138F9C: nop

;}
RECOMP_FUNC void mnOptionMakeSoundToggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131DA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131DB0: jal         0x80009968
    // 0x80131DB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131DB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131DB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131DBC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131DC0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131DC4: sw          $v0, 0x37C8($at)
    MEM_W(0X37C8, ctx->r1) = ctx->r2;
    // 0x80131DC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131DD0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131DDC: jal         0x80009DF4
    // 0x80131DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131DE4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131DE8: lw          $t7, 0x38B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B4);
    // 0x80131DEC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131DF0: addiu       $t8, $t8, 0x71F8
    ctx->r24 = ADD32(ctx->r24, 0X71F8);
    // 0x80131DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DF8: jal         0x800CCFDC
    // 0x80131DFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131E00: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E04: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x80131E08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131E0C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80131E10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E14: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131E18: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131E1C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131E20: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131E24: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131E28: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131E2C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131E30: lw          $t3, 0x38B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X38B4);
    // 0x80131E34: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80131E38: addiu       $t4, $t4, 0x73A8
    ctx->r12 = ADD32(ctx->r12, 0X73A8);
    // 0x80131E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E40: jal         0x800CCFDC
    // 0x80131E44: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131E44: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80131E48: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E4C: lui         $at, 0x436C
    ctx->r1 = S32(0X436C << 16);
    // 0x80131E50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E54: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80131E58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E5C: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80131E60: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131E64: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80131E68: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131E6C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131E70: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131E74: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131E78: lw          $t9, 0x38B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38B0);
    // 0x80131E7C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131E80: addiu       $t0, $t0, -0x45D8
    ctx->r8 = ADD32(ctx->r8, -0X45D8);
    // 0x80131E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E88: jal         0x800CCFDC
    // 0x80131E8C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131E8C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80131E90: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E94: lui         $at, 0x4365
    ctx->r1 = S32(0X4365 << 16);
    // 0x80131E98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131E9C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80131EA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131EA4: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80131EA8: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80131EAC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131EB0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80131EB4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131EB8: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131EBC: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131EC0: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131EC4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131EC8: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131ECC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131ED0: lw          $a1, 0x37BC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X37BC);
    // 0x80131ED4: jal         0x80131D2C
    // 0x80131ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnOptionSetSoundToggleSpriteColors(rdram, ctx);
        goto after_5;
    // 0x80131ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80131EDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131EE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131EE8: jr          $ra
    // 0x80131EEC: nop

    return;
    // 0x80131EEC: nop

;}
RECOMP_FUNC void func_ovl27_801370E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801370E4: jr          $ra
    // 0x801370E8: nop

    return;
    // 0x801370E8: nop

;}
RECOMP_FUNC void itBombHeiExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80177BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177BF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177BF4: jal         0x80177A24
    // 0x80177BF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itBombHeiCommonUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80177BF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80177BFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80177C00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80177C04: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80177C08: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80177C0C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80177C10: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80177C14: bne         $t8, $at, L_80177C24
    if (ctx->r24 != ctx->r1) {
        // 0x80177C18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80177C24;
    }
    // 0x80177C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177C1C: b           L_80177C28
    // 0x80177C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80177C28;
    // 0x80177C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80177C24:
    // 0x80177C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80177C28:
    // 0x80177C28: jr          $ra
    // 0x80177C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80177C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133148: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013314C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133150: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80133154: jr          $ra
    // 0x80133158: lw          $v0, -0x6410($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6410);
    return;
    // 0x80133158: lw          $v0, -0x6410($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6410);
;}
RECOMP_FUNC void wpProcessUpdateHitOffsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165ED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80165ED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80165ED8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80165EDC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80165EE0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80165EE4: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80165EE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80165EEC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80165EF0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80165EF4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80165EF8: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80165EFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80165F00: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80165F04: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80165F08: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80165F0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80165F10: jal         0x800192D0
    // 0x80165F14: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syVectorRotate3D(rdram, ctx);
        goto after_0;
    // 0x80165F14: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80165F18: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80165F1C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80165F20: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80165F24: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80165F28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80165F2C: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80165F30: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80165F34: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80165F38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80165F3C: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80165F40: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80165F44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80165F48: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x80165F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80165F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80165F54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80165F58: jr          $ra
    // 0x80165F5C: nop

    return;
    // 0x80165F5C: nop

;}
RECOMP_FUNC void mnPlayersVSGetStatusSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348EC: sltiu       $at, $a0, 0xC
    ctx->r1 = ctx->r4 < 0XC ? 1 : 0;
    // 0x801348F0: beq         $at, $zero, L_8013493C
    if (ctx->r1 == 0) {
        // 0x801348F4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8013493C;
    }
    // 0x801348F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801348F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801348FC: addu        $at, $at, $t6
    gpr jr_addend_80134904 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80134900: lw          $t6, -0x45D0($at)
    ctx->r14 = ADD32(ctx->r1, -0X45D0);
    // 0x80134904: jr          $t6
    // 0x80134908: nop

    switch (jr_addend_80134904 >> 2) {
        case 0: goto L_80134930; break;
        case 1: goto L_8013490C; break;
        case 2: goto L_80134918; break;
        case 3: goto L_8013490C; break;
        case 4: goto L_80134918; break;
        case 5: goto L_80134918; break;
        case 6: goto L_80134924; break;
        case 7: goto L_80134918; break;
        case 8: goto L_80134930; break;
        case 9: goto L_8013493C; break;
        case 10: goto L_80134924; break;
        case 11: goto L_80134924; break;
        default: switch_error(__func__, 0x80134904, 0x8013BA30);
    }
    // 0x80134908: nop

L_8013490C:
    // 0x8013490C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134910: jr          $ra
    // 0x80134914: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    return;
    // 0x80134914: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_80134918:
    // 0x80134918: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8013491C: jr          $ra
    // 0x80134920: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    return;
    // 0x80134920: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_80134924:
    // 0x80134924: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134928: jr          $ra
    // 0x8013492C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    return;
    // 0x8013492C: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80134930:
    // 0x80134930: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134934: jr          $ra
    // 0x80134938: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    return;
    // 0x80134938: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
L_8013493C:
    // 0x8013493C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134940: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80134944: jr          $ra
    // 0x80134948: nop

    return;
    // 0x80134948: nop

;}
RECOMP_FUNC void gcAppendGObjToDLLinkedList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B98: beq         $a1, $zero, L_80007BB0
    if (ctx->r5 == 0) {
        // 0x80007B9C: sw          $a1, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r5;
            goto L_80007BB0;
    }
    // 0x80007B9C: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    // 0x80007BA0: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x80007BA4: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x80007BA8: b           L_80007BD0
    // 0x80007BAC: sw          $a0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r4;
        goto L_80007BD0;
    // 0x80007BAC: sw          $a0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r4;
L_80007BB0:
    // 0x80007BB0: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x80007BB4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80007BB8: addiu       $t9, $t9, 0x6800
    ctx->r25 = ADD32(ctx->r25, 0X6800);
    // 0x80007BBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80007BC0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80007BC4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80007BC8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x80007BCC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80007BD0:
    // 0x80007BD0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80007BD4: beql        $v0, $zero, L_80007BE8
    if (ctx->r2 == 0) {
        // 0x80007BD8: lbu         $t1, 0xD($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0XD);
            goto L_80007BE8;
    }
    goto skip_0;
    // 0x80007BD8: lbu         $t1, 0xD($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XD);
    skip_0:
    // 0x80007BDC: jr          $ra
    // 0x80007BE0: sw          $a0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r4;
    return;
    // 0x80007BE0: sw          $a0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r4;
    // 0x80007BE4: lbu         $t1, 0xD($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XD);
L_80007BE8:
    // 0x80007BE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007BEC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80007BF0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80007BF4: sw          $a0, 0x6908($at)
    MEM_W(0X6908, ctx->r1) = ctx->r4;
    // 0x80007BF8: jr          $ra
    // 0x80007BFC: nop

    return;
    // 0x80007BFC: nop

;}
RECOMP_FUNC void itHammerMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801763C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801763CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801763D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801763D4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801763D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801763DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801763E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801763E4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801763E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801763EC: addiu       $a1, $a1, -0x6290
    ctx->r5 = ADD32(ctx->r5, -0X6290);
    // 0x801763F0: jal         0x8016E174
    // 0x801763F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801763F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801763F8: beq         $v0, $zero, L_80176438
    if (ctx->r2 == 0) {
        // 0x801763FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80176438;
    }
    // 0x801763FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80176400: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80176404: lwc1        $f4, -0x32E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32E8);
    // 0x80176408: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x8017640C: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80176410: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x80176414: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80176418: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8017641C: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x80176420: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80176424: jal         0x80111EC0
    // 0x80176428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80176428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017642C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80176430: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80176434: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_80176438:
    // 0x80176438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017643C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80176440: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80176444: jr          $ra
    // 0x80176448: nop

    return;
    // 0x80176448: nop

;}
RECOMP_FUNC void lbParticleAddDistVelMagDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEEB8: beq         $a1, $zero, L_800CEF44
    if (ctx->r5 == 0) {
        // 0x800CEEBC: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_800CEF44;
    }
    // 0x800CEEBC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CEEC0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800CEEC4: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800CEEC8: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800CEECC: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800CEED0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CEED4: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800CEED8: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800CEEDC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800CEEE0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CEEE4: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800CEEE8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CEEEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CEEF0: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800CEEF4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CEEF8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800CEEFC: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800CEF00: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x800CEF04: nop

    // 0x800CEF08: bc1t        L_800CEF44
    if (c1cs) {
        // 0x800CEF0C: nop
    
            goto L_800CEF44;
    }
    // 0x800CEF0C: nop

    // 0x800CEF10: div.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CEF14: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CEF18: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800CEF1C: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CEF20: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CEF24: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800CEF28: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800CEF2C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x800CEF30: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800CEF34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CEF38: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800CEF3C: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x800CEF40: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
L_800CEF44:
    // 0x800CEF44: jr          $ra
    // 0x800CEF48: nop

    return;
    // 0x800CEF48: nop

;}
RECOMP_FUNC void ftMainSearchHitItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E55DC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800E55E0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800E55E4: lw          $t7, 0x6700($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6700);
    // 0x800E55E8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E55EC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800E55F0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800E55F4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E55F8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E55FC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E5600: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E5604: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E5608: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E560C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E5610: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800E5614: lw          $s7, 0x84($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X84);
    // 0x800E5618: beq         $t7, $zero, L_800E5C00
    if (ctx->r15 == 0) {
        // 0x800E561C: sw          $t7, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r15;
            goto L_800E5C00;
    }
    // 0x800E561C: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
L_800E5620:
    // 0x800E5620: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5624: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5628: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800E562C: lw          $fp, 0x84($t8)
    ctx->r30 = MEM_W(ctx->r24, 0X84);
    // 0x800E5630: addiu       $s6, $fp, 0x10C
    ctx->r22 = ADD32(ctx->r30, 0X10C);
    // 0x800E5634: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x800E5638: lw          $t1, 0x8($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X8);
    // 0x800E563C: beql        $t9, $t1, L_800E5BF4
    if (ctx->r25 == ctx->r9) {
        // 0x800E5640: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_0;
    // 0x800E5640: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_0:
    // 0x800E5644: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x800E5648: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E564C: lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2);
    // 0x800E5650: bnel        $t2, $at, L_800E5678
    if (ctx->r10 != ctx->r1) {
        // 0x800E5654: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_800E5678;
    }
    goto skip_1;
    // 0x800E5654: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800E5658: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x800E565C: bnel        $t3, $zero, L_800E5678
    if (ctx->r11 != 0) {
        // 0x800E5660: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_800E5678;
    }
    goto skip_2;
    // 0x800E5660: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_2:
    // 0x800E5664: lbu         $t4, 0x14($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X14);
    // 0x800E5668: lbu         $t5, 0xC($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0XC);
    // 0x800E566C: beql        $t4, $t5, L_800E5BF4
    if (ctx->r12 == ctx->r13) {
        // 0x800E5670: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_3;
    // 0x800E5670: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_3:
    // 0x800E5674: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
L_800E5678:
    // 0x800E5678: beql        $t6, $zero, L_800E5BF4
    if (ctx->r14 == 0) {
        // 0x800E567C: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_4;
    // 0x800E567C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_4:
    // 0x800E5680: lbu         $t7, 0x48($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X48);
    // 0x800E5684: lbu         $t9, 0x94($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X94);
    // 0x800E5688: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800E568C: beq         $t8, $zero, L_800E5BF0
    if (ctx->r24 == 0) {
        // 0x800E5690: andi        $t7, $t9, 0xFFDF
        ctx->r15 = ctx->r25 & 0XFFDF;
            goto L_800E5BF0;
    }
    // 0x800E5690: andi        $t7, $t9, 0xFFDF
    ctx->r15 = ctx->r25 & 0XFFDF;
    // 0x800E5694: sb          $t7, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r15;
    // 0x800E5698: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800E569C: andi        $t8, $t7, 0xBF
    ctx->r24 = ctx->r15 & 0XBF;
    // 0x800E56A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E56A4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E56A8: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800E56AC: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800E56B0: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x800E56B4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800E56B8: sb          $t7, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r15;
    // 0x800E56BC: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800E56C0: andi        $t6, $t7, 0x7F
    ctx->r14 = ctx->r15 & 0X7F;
    // 0x800E56C4: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x800E56C8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800E56CC: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800E56D0: sll         $t1, $t4, 7
    ctx->r9 = S32(ctx->r12 << 7);
    // 0x800E56D4: or          $t3, $t1, $t6
    ctx->r11 = ctx->r9 | ctx->r14;
    // 0x800E56D8: sb          $t3, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r11;
    // 0x800E56DC: ori         $t4, $t3, 0xE
    ctx->r12 = ctx->r11 | 0XE;
    // 0x800E56E0: sb          $t4, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r12;
L_800E56E4:
    // 0x800E56E4: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800E56E8: lw          $t9, 0x118($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X118);
    // 0x800E56EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E56F0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800E56F4: bne         $t5, $t9, L_800E570C
    if (ctx->r13 != ctx->r25) {
        // 0x800E56F8: nop
    
            goto L_800E570C;
    }
    // 0x800E56F8: nop

    // 0x800E56FC: lw          $t6, 0x11C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X11C);
    // 0x800E5700: addiu       $t7, $sp, 0x94
    ctx->r15 = ADD32(ctx->r29, 0X94);
    // 0x800E5704: b           L_800E5714
    // 0x800E5708: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_800E5714;
    // 0x800E5708: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_800E570C:
    // 0x800E570C: bne         $v1, $at, L_800E56E4
    if (ctx->r3 != ctx->r1) {
        // 0x800E5710: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E56E4;
    }
    // 0x800E5710: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E5714:
    // 0x800E5714: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x800E5718: srl         $t2, $t8, 31
    ctx->r10 = S32(U32(ctx->r24) >> 31);
    // 0x800E571C: bne         $t2, $zero, L_800E5BF0
    if (ctx->r10 != 0) {
        // 0x800E5720: sll         $t4, $t8, 1
        ctx->r12 = S32(ctx->r24 << 1);
            goto L_800E5BF0;
    }
    // 0x800E5720: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800E5724: bltz        $t4, L_800E5BF0
    if (SIGNED(ctx->r12) < 0) {
        // 0x800E5728: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_800E5BF0;
    }
    // 0x800E5728: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E572C: bltz        $t9, L_800E5BF0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800E5730: sll         $t7, $t8, 4
        ctx->r15 = S32(ctx->r24 << 4);
            goto L_800E5BF0;
    }
    // 0x800E5730: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x800E5734: srl         $t1, $t7, 29
    ctx->r9 = S32(U32(ctx->r15) >> 29);
    // 0x800E5738: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E573C: bnel        $t1, $at, L_800E5BF4
    if (ctx->r9 != ctx->r1) {
        // 0x800E5740: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_5;
    // 0x800E5740: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_5:
    // 0x800E5744: lw          $v1, 0x4C($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X4C);
    // 0x800E5748: srl         $t6, $v1, 31
    ctx->r14 = S32(U32(ctx->r3) >> 31);
    // 0x800E574C: beql        $t6, $zero, L_800E594C
    if (ctx->r14 == 0) {
        // 0x800E5750: lw          $t3, 0x54($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X54);
            goto L_800E594C;
    }
    goto skip_6;
    // 0x800E5750: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    skip_6:
    // 0x800E5754: lw          $t2, 0x190($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X190);
    // 0x800E5758: sll         $t4, $t2, 18
    ctx->r12 = S32(ctx->r10 << 18);
    // 0x800E575C: bltzl       $t4, L_800E594C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800E5760: lw          $t3, 0x54($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X54);
            goto L_800E594C;
    }
    goto skip_7;
    // 0x800E5760: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    skip_7:
    // 0x800E5764: lw          $v0, 0x278($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X278);
    // 0x800E5768: beql        $v0, $zero, L_800E57AC
    if (ctx->r2 == 0) {
        // 0x800E576C: lw          $t6, 0x18C($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X18C);
            goto L_800E57AC;
    }
    goto skip_8;
    // 0x800E576C: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
    skip_8:
    // 0x800E5770: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x800E5774: beql        $t5, $v0, L_800E594C
    if (ctx->r13 == ctx->r2) {
        // 0x800E5778: lw          $t3, 0x54($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X54);
            goto L_800E594C;
    }
    goto skip_9;
    // 0x800E5778: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    skip_9:
    // 0x800E577C: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800E5780: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E5784: bnel        $t9, $at, L_800E57AC
    if (ctx->r25 != ctx->r1) {
        // 0x800E5788: lw          $t6, 0x18C($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X18C);
            goto L_800E57AC;
    }
    goto skip_10;
    // 0x800E5788: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
    skip_10:
    // 0x800E578C: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x800E5790: bnel        $t8, $zero, L_800E57AC
    if (ctx->r24 != 0) {
        // 0x800E5794: lw          $t6, 0x18C($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X18C);
            goto L_800E57AC;
    }
    goto skip_11;
    // 0x800E5794: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
    skip_11:
    // 0x800E5798: lbu         $t7, 0x14($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X14);
    // 0x800E579C: lbu         $t1, 0x280($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X280);
    // 0x800E57A0: beql        $t7, $t1, L_800E594C
    if (ctx->r15 == ctx->r9) {
        // 0x800E57A4: lw          $t3, 0x54($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X54);
            goto L_800E594C;
    }
    goto skip_12;
    // 0x800E57A4: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    skip_12:
    // 0x800E57A8: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
L_800E57AC:
    // 0x800E57AC: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800E57B0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E57B4: sll         $t3, $t6, 5
    ctx->r11 = S32(ctx->r14 << 5);
    // 0x800E57B8: bgez        $t3, L_800E57C4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E57BC: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_800E57C4;
    }
    // 0x800E57BC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800E57C0: bltz        $t5, L_800E5948
    if (SIGNED(ctx->r13) < 0) {
        // 0x800E57C4: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800E5948;
    }
L_800E57C4:
    // 0x800E57C4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E57C8: addiu       $a2, $a2, 0x11B0
    ctx->r6 = ADD32(ctx->r6, 0X11B0);
L_800E57CC:
    // 0x800E57CC: lw          $t9, 0x294($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X294);
    // 0x800E57D0: beql        $t9, $zero, L_800E5880
    if (ctx->r25 == 0) {
        // 0x800E57D4: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E5880;
    }
    goto skip_13;
    // 0x800E57D4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_13:
    // 0x800E57D8: lw          $v0, 0x108($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X108);
    // 0x800E57DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E57E0: addiu       $a0, $a1, 0x294
    ctx->r4 = ADD32(ctx->r5, 0X294);
    // 0x800E57E4: bne         $v0, $at, L_800E57FC
    if (ctx->r2 != ctx->r1) {
        // 0x800E57E8: nop
    
            goto L_800E57FC;
    }
    // 0x800E57E8: nop

    // 0x800E57EC: lbu         $t8, 0x3C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X3C);
    // 0x800E57F0: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x800E57F4: bnel        $t7, $zero, L_800E5814
    if (ctx->r15 != 0) {
        // 0x800E57F8: lbu         $t3, 0x98($sp)
        ctx->r11 = MEM_BU(ctx->r29, 0X98);
            goto L_800E5814;
    }
    goto skip_14;
    // 0x800E57F8: lbu         $t3, 0x98($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X98);
    skip_14:
L_800E57FC:
    // 0x800E57FC: bne         $v0, $zero, L_800E587C
    if (ctx->r2 != 0) {
        // 0x800E5800: addiu       $a0, $a1, 0x294
        ctx->r4 = ADD32(ctx->r5, 0X294);
            goto L_800E587C;
    }
    // 0x800E5800: addiu       $a0, $a1, 0x294
    ctx->r4 = ADD32(ctx->r5, 0X294);
    // 0x800E5804: lb          $t6, 0x3D($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3D);
    // 0x800E5808: bgezl       $t6, L_800E5880
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E580C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E5880;
    }
    goto skip_15;
    // 0x800E580C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_15:
    // 0x800E5810: lbu         $t3, 0x98($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X98);
L_800E5814:
    // 0x800E5814: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E5818: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x800E581C: ori         $t4, $t3, 0xE
    ctx->r12 = ctx->r11 | 0XE;
    // 0x800E5820: sb          $t4, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r12;
    // 0x800E5824: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E5828: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_800E582C:
    // 0x800E582C: lw          $t5, 0x5C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X5C);
    // 0x800E5830: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E5834: bne         $a0, $t5, L_800E584C
    if (ctx->r4 != ctx->r13) {
        // 0x800E5838: nop
    
            goto L_800E584C;
    }
    // 0x800E5838: nop

    // 0x800E583C: lw          $t7, 0x60($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X60);
    // 0x800E5840: addiu       $t9, $sp, 0x98
    ctx->r25 = ADD32(ctx->r29, 0X98);
    // 0x800E5844: b           L_800E5854
    // 0x800E5848: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
        goto L_800E5854;
    // 0x800E5848: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_800E584C:
    // 0x800E584C: bne         $v1, $a3, L_800E582C
    if (ctx->r3 != ctx->r7) {
        // 0x800E5850: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E582C;
    }
    // 0x800E5850: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E5854:
    // 0x800E5854: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x800E5858: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E585C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800E5860: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x800E5864: srl         $t2, $t6, 29
    ctx->r10 = S32(U32(ctx->r14) >> 29);
    // 0x800E5868: bnel        $t2, $at, L_800E5880
    if (ctx->r10 != ctx->r1) {
        // 0x800E586C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E5880;
    }
    goto skip_16;
    // 0x800E586C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_16:
    // 0x800E5870: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800E5874: b           L_800E5880
    // 0x800E5878: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800E5880;
    // 0x800E5878: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800E587C:
    // 0x800E587C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800E5880:
    // 0x800E5880: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800E5884: addiu       $t4, $t4, 0x11C0
    ctx->r12 = ADD32(ctx->r12, 0X11C0);
    // 0x800E5888: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800E588C: sltu        $at, $a2, $t4
    ctx->r1 = ctx->r6 < ctx->r12 ? 1 : 0;
    // 0x800E5890: bne         $at, $zero, L_800E57CC
    if (ctx->r1 != 0) {
        // 0x800E5894: addiu       $a1, $a1, 0xC4
        ctx->r5 = ADD32(ctx->r5, 0XC4);
            goto L_800E57CC;
    }
    // 0x800E5894: addiu       $a1, $a1, 0xC4
    ctx->r5 = ADD32(ctx->r5, 0XC4);
    // 0x800E5898: beql        $t0, $zero, L_800E594C
    if (ctx->r8 == 0) {
        // 0x800E589C: lw          $t3, 0x54($s6)
        ctx->r11 = MEM_W(ctx->r22, 0X54);
            goto L_800E594C;
    }
    goto skip_17;
    // 0x800E589C: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
    skip_17:
    // 0x800E58A0: lw          $t5, 0x54($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X54);
    // 0x800E58A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E58A8: blez        $t5, L_800E5948
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E58AC: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800E5948;
    }
L_800E58AC:
    // 0x800E58AC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E58B0: addiu       $s1, $s1, 0x11B0
    ctx->r17 = ADD32(ctx->r17, 0X11B0);
    // 0x800E58B4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800E58B8:
    // 0x800E58B8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800E58BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E58C0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E58C4: beq         $t9, $zero, L_800E5920
    if (ctx->r25 == 0) {
        // 0x800E58C8: sll         $t8, $s2, 2
        ctx->r24 = S32(ctx->r18 << 2);
            goto L_800E5920;
    }
    // 0x800E58C8: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800E58CC: subu        $t8, $t8, $s2
    ctx->r24 = SUB32(ctx->r24, ctx->r18);
    // 0x800E58D0: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800E58D4: addu        $t8, $t8, $s2
    ctx->r24 = ADD32(ctx->r24, ctx->r18);
    // 0x800E58D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E58DC: addu        $s0, $s7, $t8
    ctx->r16 = ADD32(ctx->r23, ctx->r24);
    // 0x800E58E0: addiu       $s0, $s0, 0x294
    ctx->r16 = ADD32(ctx->r16, 0X294);
    // 0x800E58E4: jal         0x800F02BC
    // 0x800E58E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    gmCollisionCheckItemAttackFighterAttackCollide(rdram, ctx);
        goto after_0;
    // 0x800E58E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800E58EC: beq         $v0, $zero, L_800E5920
    if (ctx->r2 == 0) {
        // 0x800E58F0: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_800E5920;
    }
    // 0x800E58F0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E58F4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800E58F8: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x800E58FC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5900: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5904: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E5908: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E590C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E5910: jal         0x800E35BC
    // 0x800E5914: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    ftMainUpdateAttackStatItem(rdram, ctx);
        goto after_1;
    // 0x800E5914: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x800E5918: lw          $t6, 0x270($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X270);
    // 0x800E591C: bne         $t6, $zero, L_800E5BF0
    if (ctx->r14 != 0) {
        // 0x800E5920: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E5BF0;
    }
L_800E5920:
    // 0x800E5920: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E5924: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E5928: bne         $s2, $at, L_800E58B8
    if (ctx->r18 != ctx->r1) {
        // 0x800E592C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800E58B8;
    }
    // 0x800E592C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800E5930: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800E5934: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5938: lw          $v0, 0x54($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X54);
    // 0x800E593C: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5940: bne         $at, $zero, L_800E58AC
    if (ctx->r1 != 0) {
        // 0x800E5944: nop
    
            goto L_800E58AC;
    }
    // 0x800E5944: nop

L_800E5948:
    // 0x800E5948: lw          $t3, 0x54($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X54);
L_800E594C:
    // 0x800E594C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E5950: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E5954: blez        $t3, L_800E5998
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800E5958: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_800E5998;
    }
    // 0x800E5958: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E595C: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E5960: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_800E5964:
    // 0x800E5964: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5968: jal         0x800EF4F4
    // 0x800E596C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    gmCollisionCheckItemInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800E596C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    after_2:
    // 0x800E5970: beq         $v0, $zero, L_800E597C
    if (ctx->r2 == 0) {
        // 0x800E5974: sw          $v0, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r2;
            goto L_800E597C;
    }
    // 0x800E5974: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800E5978: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800E597C:
    // 0x800E597C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E5980: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5984: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800E5988: lw          $t5, 0x54($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X54);
    // 0x800E598C: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800E5990: bnel        $at, $zero, L_800E5964
    if (ctx->r1 != 0) {
        // 0x800E5994: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800E5964;
    }
    goto skip_18;
    // 0x800E5994: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_18:
L_800E5998:
    // 0x800E5998: beql        $s0, $zero, L_800E5BF4
    if (ctx->r16 == 0) {
        // 0x800E599C: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_19;
    // 0x800E599C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_19:
    // 0x800E59A0: lw          $v0, 0x18C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X18C);
    // 0x800E59A4: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x800E59A8: bgezl       $t8, L_800E5A3C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E59AC: sll         $t8, $v0, 26
        ctx->r24 = S32(ctx->r2 << 26);
            goto L_800E5A3C;
    }
    goto skip_20;
    // 0x800E59AC: sll         $t8, $v0, 26
    ctx->r24 = S32(ctx->r2 << 26);
    skip_20:
    // 0x800E59B0: lw          $t7, 0x4C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X4C);
    // 0x800E59B4: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x800E59B8: bgezl       $t6, L_800E5A3C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E59BC: sll         $t8, $v0, 26
        ctx->r24 = S32(ctx->r2 << 26);
            goto L_800E5A3C;
    }
    goto skip_21;
    // 0x800E59BC: sll         $t8, $v0, 26
    ctx->r24 = S32(ctx->r2 << 26);
    skip_21:
    // 0x800E59C0: lw          $t2, 0x54($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X54);
    // 0x800E59C4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E59C8: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E59CC: blez        $t2, L_800E5A38
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800E59D0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E5A38;
    }
    // 0x800E59D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E59D4:
    // 0x800E59D4: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800E59D8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E59DC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E59E0: bne         $t3, $zero, L_800E59F4
    if (ctx->r11 != 0) {
        // 0x800E59E4: or          $a2, $s7, $zero
        ctx->r6 = ctx->r23 | 0;
            goto L_800E59F4;
    }
    // 0x800E59E4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E59E8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E59EC: b           L_800E5A24
    // 0x800E59F0: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
        goto L_800E5A24;
    // 0x800E59F0: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
L_800E59F4:
    // 0x800E59F4: jal         0x800F0518
    // 0x800E59F8: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    gmCollisionCheckItemAttackSpecialCollide(rdram, ctx);
        goto after_3;
    // 0x800E59F8: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    after_3:
    // 0x800E59FC: beq         $v0, $zero, L_800E5A20
    if (ctx->r2 == 0) {
        // 0x800E5A00: lw          $t5, 0x88($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X88);
            goto L_800E5A20;
    }
    // 0x800E5A00: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x800E5A04: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5A08: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5A0C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E5A10: jal         0x800E3860
    // 0x800E5A14: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    ftMainUpdateReflectorStatItem(rdram, ctx);
        goto after_4;
    // 0x800E5A14: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    after_4:
    // 0x800E5A18: b           L_800E5BF4
    // 0x800E5A1C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
        goto L_800E5BF4;
    // 0x800E5A1C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
L_800E5A20:
    // 0x800E5A20: lw          $v0, 0x54($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X54);
L_800E5A24:
    // 0x800E5A24: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5A28: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5A2C: bne         $at, $zero, L_800E59D4
    if (ctx->r1 != 0) {
        // 0x800E5A30: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E59D4;
    }
    // 0x800E5A30: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800E5A34: lw          $v0, 0x18C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X18C);
L_800E5A38:
    // 0x800E5A38: sll         $t8, $v0, 26
    ctx->r24 = S32(ctx->r2 << 26);
L_800E5A3C:
    // 0x800E5A3C: bgezl       $t8, L_800E5AFC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E5A40: lw          $t2, 0x5AC($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X5AC);
            goto L_800E5AFC;
    }
    goto skip_22;
    // 0x800E5A40: lw          $t2, 0x5AC($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X5AC);
    skip_22:
    // 0x800E5A44: lw          $t7, 0x4C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X4C);
    // 0x800E5A48: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800E5A4C: bgezl       $t6, L_800E5AFC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E5A50: lw          $t2, 0x5AC($s7)
        ctx->r10 = MEM_W(ctx->r23, 0X5AC);
            goto L_800E5AFC;
    }
    goto skip_23;
    // 0x800E5A50: lw          $t2, 0x5AC($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X5AC);
    skip_23:
    // 0x800E5A54: lw          $t2, 0x54($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X54);
    // 0x800E5A58: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E5A5C: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E5A60: blez        $t2, L_800E5AF8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800E5A64: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E5AF8;
    }
    // 0x800E5A64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E5A68:
    // 0x800E5A68: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800E5A6C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E5A70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5A74: bne         $t3, $zero, L_800E5A88
    if (ctx->r11 != 0) {
        // 0x800E5A78: lw          $a2, 0xB8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB8);
            goto L_800E5A88;
    }
    // 0x800E5A78: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5A7C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E5A80: b           L_800E5AE8
    // 0x800E5A84: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
        goto L_800E5AE8;
    // 0x800E5A84: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
L_800E5A88:
    // 0x800E5A88: lw          $a3, 0x8F4($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X8F4);
    // 0x800E5A8C: addiu       $t5, $sp, 0x84
    ctx->r13 = ADD32(ctx->r29, 0X84);
    // 0x800E5A90: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x800E5A94: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800E5A98: jal         0x800F044C
    // 0x800E5A9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    gmCollisionCheckItemAttackShieldCollide(rdram, ctx);
        goto after_5;
    // 0x800E5A9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_5:
    // 0x800E5AA0: beq         $v0, $zero, L_800E5AE4
    if (ctx->r2 == 0) {
        // 0x800E5AA4: lw          $t6, 0x88($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X88);
            goto L_800E5AE4;
    }
    // 0x800E5AA4: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800E5AA8: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5AAC: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5AB0: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800E5AB4: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x800E5AB8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800E5ABC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5AC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5AC4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5AC8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E5ACC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800E5AD0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E5AD4: jal         0x800E36F8
    // 0x800E5AD8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    ftMainUpdateShieldStatItem(rdram, ctx);
        goto after_6;
    // 0x800E5AD8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x800E5ADC: b           L_800E5BF4
    // 0x800E5AE0: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
        goto L_800E5BF4;
    // 0x800E5AE0: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
L_800E5AE4:
    // 0x800E5AE4: lw          $v0, 0x54($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X54);
L_800E5AE8:
    // 0x800E5AE8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5AEC: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5AF0: bne         $at, $zero, L_800E5A68
    if (ctx->r1 != 0) {
        // 0x800E5AF4: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E5A68;
    }
    // 0x800E5AF4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E5AF8:
    // 0x800E5AF8: lw          $t2, 0x5AC($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X5AC);
L_800E5AFC:
    // 0x800E5AFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E5B00: beql        $t2, $at, L_800E5BF4
    if (ctx->r10 == ctx->r1) {
        // 0x800E5B04: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_24;
    // 0x800E5B04: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_24:
    // 0x800E5B08: lw          $t3, 0x5B4($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X5B4);
    // 0x800E5B0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E5B10: beql        $t3, $at, L_800E5BF4
    if (ctx->r11 == ctx->r1) {
        // 0x800E5B14: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_25;
    // 0x800E5B14: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_25:
    // 0x800E5B18: lw          $t4, 0x5B8($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X5B8);
    // 0x800E5B1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E5B20: beql        $t4, $at, L_800E5BF4
    if (ctx->r12 == ctx->r1) {
        // 0x800E5B24: lw          $t5, 0xB4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XB4);
            goto L_800E5BF4;
    }
    goto skip_26;
    // 0x800E5B24: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    skip_26:
    // 0x800E5B28: lw          $t5, 0x54($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X54);
    // 0x800E5B2C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E5B30: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E5B34: blez        $t5, L_800E5BF0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E5B38: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E5BF0;
    }
    // 0x800E5B38: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E5B3C:
    // 0x800E5B3C: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800E5B40: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800E5B44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E5B48: bne         $t9, $zero, L_800E5B58
    if (ctx->r25 != 0) {
        // 0x800E5B4C: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_800E5B58;
    }
    // 0x800E5B4C: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x800E5B50: b           L_800E5BE0
    // 0x800E5B54: lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X54);
        goto L_800E5BE0;
    // 0x800E5B54: lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X54);
L_800E5B58:
    // 0x800E5B58: lw          $t7, 0x5BC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5BC);
    // 0x800E5B5C: addiu       $s0, $s1, 0x5BC
    ctx->r16 = ADD32(ctx->r17, 0X5BC);
    // 0x800E5B60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E5B64: bne         $t7, $zero, L_800E5B78
    if (ctx->r15 != 0) {
        // 0x800E5B68: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800E5B78;
    }
    // 0x800E5B68: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5B6C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800E5B70: b           L_800E5BE0
    // 0x800E5B74: lw          $v0, 0x54($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X54);
        goto L_800E5BE0;
    // 0x800E5B74: lw          $v0, 0x54($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X54);
L_800E5B78:
    // 0x800E5B78: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E5B7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E5B80: beql        $t6, $at, L_800E5BCC
    if (ctx->r14 == ctx->r1) {
        // 0x800E5B84: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_800E5BCC;
    }
    goto skip_27;
    // 0x800E5B84: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    skip_27:
    // 0x800E5B88: jal         0x800F03B8
    // 0x800E5B8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    gmCollisionCheckItemAttackFighterDamageCollide(rdram, ctx);
        goto after_7;
    // 0x800E5B8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800E5B90: beql        $v0, $zero, L_800E5BCC
    if (ctx->r2 == 0) {
        // 0x800E5B94: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_800E5BCC;
    }
    goto skip_28;
    // 0x800E5B94: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    skip_28:
    // 0x800E5B98: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5B9C: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5BA0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5BA4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5BA8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5BAC: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E5BB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E5BB4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800E5BB8: jal         0x800E39B0
    // 0x800E5BBC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    ftMainUpdateDamageStatItem(rdram, ctx);
        goto after_8;
    // 0x800E5BBC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_8:
    // 0x800E5BC0: b           L_800E5BF4
    // 0x800E5BC4: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
        goto L_800E5BF4;
    // 0x800E5BC4: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5BC8: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
L_800E5BCC:
    // 0x800E5BCC: addiu       $at, $zero, 0x1E4
    ctx->r1 = ADD32(0, 0X1E4);
    // 0x800E5BD0: bne         $s3, $at, L_800E5B58
    if (ctx->r19 != ctx->r1) {
        // 0x800E5BD4: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E5B58;
    }
    // 0x800E5BD4: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x800E5BD8: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E5BDC: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
L_800E5BE0:
    // 0x800E5BE0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5BE4: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5BE8: bne         $at, $zero, L_800E5B3C
    if (ctx->r1 != 0) {
        // 0x800E5BEC: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E5B3C;
    }
    // 0x800E5BEC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E5BF0:
    // 0x800E5BF0: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
L_800E5BF4:
    // 0x800E5BF4: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800E5BF8: bne         $t9, $zero, L_800E5620
    if (ctx->r25 != 0) {
        // 0x800E5BFC: sw          $t9, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r25;
            goto L_800E5620;
    }
    // 0x800E5BFC: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
L_800E5C00:
    // 0x800E5C00: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E5C04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E5C08: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E5C0C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E5C10: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E5C14: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E5C18: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E5C1C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E5C20: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800E5C24: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800E5C28: jr          $ra
    // 0x800E5C2C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800E5C2C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void mnVSResultsMakeResultsTextCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801345EC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801345F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801345F4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801345F8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801345FC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134600: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80134604: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134608: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013460C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134610: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80134614: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80134618: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013461C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134620: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134624: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134628: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013462C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134630: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134634: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134638: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013463C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134640: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134644: jal         0x8000B93C
    // 0x80134648: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80134648: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013464C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134650: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134654: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80134658: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013465C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134660: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134664: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134668: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013466C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134670: jal         0x80007080
    // 0x80134674: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134674: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134678: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013467C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134680: jr          $ra
    // 0x80134684: nop

    return;
    // 0x80134684: nop

;}
RECOMP_FUNC void mnMapsMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013386C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133870: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133874: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133878: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013387C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80133880: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133884: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80133888: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013388C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133890: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133894: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133898: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013389C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801338A0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801338A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801338A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801338AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801338B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801338B4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801338B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801338BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801338C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801338C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801338C8: jal         0x8000B93C
    // 0x801338CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801338CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801338D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801338D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801338D8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801338DC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801338E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801338E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801338E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801338EC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801338F0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801338F4: jal         0x80007080
    // 0x801338F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801338F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801338FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133900: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133904: jr          $ra
    // 0x80133908: nop

    return;
    // 0x80133908: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F388: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F38C: jal         0x800DE6E4
    // 0x8015F390: addiu       $a1, $a1, -0xB50
    ctx->r5 = ADD32(ctx->r5, -0XB50);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015F390: addiu       $a1, $a1, -0xB50
    ctx->r5 = ADD32(ctx->r5, -0XB50);
    after_0:
    // 0x8015F394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F39C: jr          $ra
    // 0x8015F3A0: nop

    return;
    // 0x8015F3A0: nop

;}
RECOMP_FUNC void guMtxXFMF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800348E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800348E4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800348E8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800348EC: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800348F0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800348F4: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800348F8: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800348FC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80034900: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80034904: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80034908: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8003490C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80034910: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80034914: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80034918: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8003491C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80034920: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80034924: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80034928: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8003492C: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80034930: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80034934: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80034938: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003493C: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80034940: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80034944: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034948: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8003494C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80034950: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80034954: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80034958: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8003495C: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80034960: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80034964: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80034968: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8003496C: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80034970: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80034974: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80034978: jr          $ra
    // 0x8003497C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8003497C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftCommonHammerTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147B34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147B38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80147B3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80147B40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80147B44: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80147B48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80147B4C: jal         0x800F3828
    // 0x80147B50: sw          $t6, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r14;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_0;
    // 0x80147B50: sw          $t6, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r14;
    after_0:
    // 0x80147B54: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80147B58: jal         0x800F385C
    // 0x80147B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_1;
    // 0x80147B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80147B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147B64: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // 0x80147B68: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80147B6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147B70: jal         0x800E6F24
    // 0x80147B74: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80147B74: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80147B78: jal         0x800F388C
    // 0x80147B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_3;
    // 0x80147B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80147B80: jal         0x80147A70
    // 0x80147B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonHammerTurnUpdateModelYaw(rdram, ctx);
        goto after_4;
    // 0x80147B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80147B88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147B8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80147B90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80147B94: jr          $ra
    // 0x80147B98: nop

    return;
    // 0x80147B98: nop

;}
RECOMP_FUNC void efManagerDustExpandSmallMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF648: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FF64C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF654: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FF658: jal         0x800FD4B8
    // 0x800FF65C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FF65C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FF660: bne         $v0, $zero, L_800FF670
    if (ctx->r2 != 0) {
        // 0x800FF664: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_800FF670;
    }
    // 0x800FF664: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800FF668: b           L_800FF7C4
    // 0x800FF66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF7C4;
    // 0x800FF66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF670:
    // 0x800FF670: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FF674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FF678: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FF67C: jal         0x80009968
    // 0x800FF680: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FF680: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FF684: bne         $v0, $zero, L_800FF69C
    if (ctx->r2 != 0) {
        // 0x800FF688: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_800FF69C;
    }
    // 0x800FF688: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800FF68C: jal         0x800FD4F8
    // 0x800FF690: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FF690: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FF694: b           L_800FF7C4
    // 0x800FF698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF7C4;
    // 0x800FF698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF69C:
    // 0x800FF69C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800FF6A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FF6A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF6A8: sw          $t6, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r14;
    // 0x800FF6AC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800FF6B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF6B4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800FF6B8: nop

    // 0x800FF6BC: bc1f        L_800FF6E0
    if (!c1cs) {
        // 0x800FF6C0: nop
    
            goto L_800FF6E0;
    }
    // 0x800FF6C0: nop

    // 0x800FF6C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF6C8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF6CC: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x800FF6D0: jal         0x800CE9E8
    // 0x800FF6D4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FF6D4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_3:
    // 0x800FF6D8: b           L_800FF6F4
    // 0x800FF6DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800FF6F4;
    // 0x800FF6DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF6E0:
    // 0x800FF6E0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF6E4: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800FF6E8: jal         0x800CE9E8
    // 0x800FF6EC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_4;
    // 0x800FF6EC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_4:
    // 0x800FF6F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF6F4:
    // 0x800FF6F4: beq         $v0, $zero, L_800FF7B8
    if (ctx->r2 == 0) {
        // 0x800FF6F8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FF7B8;
    }
    // 0x800FF6F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FF6FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF700: jal         0x800CE1DC
    // 0x800FF704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_5;
    // 0x800FF704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800FF708: beq         $v0, $zero, L_800FF7A8
    if (ctx->r2 == 0) {
        // 0x800FF70C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FF7A8;
    }
    // 0x800FF70C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF710: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF714: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FF718: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FF71C: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FF720: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FF724: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800FF728: jal         0x800CEA14
    // 0x800FF72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LBParticleProcessStruct(rdram, ctx);
        goto after_6;
    // 0x800FF72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800FF730: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FF734: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FF738: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FF73C: lhu         $t9, 0x2A($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FF740: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FF748: bne         $t9, $zero, L_800FF758
    if (ctx->r25 != 0) {
        // 0x800FF74C: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800FF758;
    }
    // 0x800FF74C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800FF750: b           L_800FF7C4
    // 0x800FF754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF7C4;
    // 0x800FF754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF758:
    // 0x800FF758: jal         0x80008188
    // 0x800FF75C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x800FF75C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x800FF760: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FF764: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800FF768: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800FF76C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF770: sw          $v1, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r3;
    // 0x800FF774: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800FF778: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800FF77C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FF780: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800FF784: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FF788: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800FF78C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FF790: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800FF794: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800FF798: swc1        $f8, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f8.u32l;
    // 0x800FF79C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800FF7A0: b           L_800FF7C0
    // 0x800FF7A4: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
        goto L_800FF7C0;
    // 0x800FF7A4: swc1        $f10, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f10.u32l;
L_800FF7A8:
    // 0x800FF7A8: jal         0x800FDB3C
    // 0x800FF7AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_8;
    // 0x800FF7AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x800FF7B0: b           L_800FF7C0
    // 0x800FF7B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800FF7C0;
    // 0x800FF7B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF7B8:
    // 0x800FF7B8: jal         0x800FDB3C
    // 0x800FF7BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_9;
    // 0x800FF7BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
L_800FF7C0:
    // 0x800FF7C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800FF7C4:
    // 0x800FF7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF7CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FF7D0: jr          $ra
    // 0x800FF7D4: nop

    return;
    // 0x800FF7D4: nop

;}
RECOMP_FUNC void func_ovl8_8037E7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E7A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037E7AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037E7B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037E7B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037E7B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037E7BC: bne         $a0, $zero, L_8037E7CC
    if (ctx->r4 != 0) {
        // 0x8037E7C0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8037E7CC;
    }
    // 0x8037E7C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037E7C4: b           L_8037E7F8
    // 0x8037E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037E7F8;
    // 0x8037E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037E7CC:
    // 0x8037E7CC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8037E7D0: beq         $t6, $zero, L_8037E7F4
    if (ctx->r14 == 0) {
        // 0x8037E7D4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037E7F4;
    }
    // 0x8037E7D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8037E7D8:
    // 0x8037E7D8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8037E7DC: jal         0x8037E6F4
    // 0x8037E7E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_ovl8_8037E6F4(rdram, ctx);
        goto after_0;
    // 0x8037E7E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8037E7E4: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x8037E7E8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8037E7EC: bnel        $t7, $zero, L_8037E7D8
    if (ctx->r15 != 0) {
        // 0x8037E7F0: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037E7D8;
    }
    goto skip_0;
    // 0x8037E7F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
L_8037E7F4:
    // 0x8037E7F4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8037E7F8:
    // 0x8037E7F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037E7FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037E800: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037E804: jr          $ra
    // 0x8037E808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8037E808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void efManagerYoshiEntryEggMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102F40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102F44: jal         0x800FDAFC
    // 0x80102F48: addiu       $a0, $a0, -0x1A54
    ctx->r4 = ADD32(ctx->r4, -0X1A54);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102F48: addiu       $a0, $a0, -0x1A54
    ctx->r4 = ADD32(ctx->r4, -0X1A54);
    after_0:
    // 0x80102F4C: bne         $v0, $zero, L_80102F5C
    if (ctx->r2 != 0) {
        // 0x80102F50: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102F5C;
    }
    // 0x80102F50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102F54: b           L_80102F80
    // 0x80102F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102F80;
    // 0x80102F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102F5C:
    // 0x80102F5C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102F60: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102F64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102F68: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102F6C: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80102F70: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102F74: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80102F78: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102F7C: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80102F80:
    // 0x80102F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102F88: jr          $ra
    // 0x80102F8C: nop

    return;
    // 0x80102F8C: nop

;}
RECOMP_FUNC void mnVSRecordGetAvg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801348B8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801348BC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801348C0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801348C4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x801348C8: addiu       $t7, $t7, 0x44E0
    ctx->r15 = ADD32(ctx->r15, 0X44E0);
    // 0x801348CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801348D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801348D4: lhu         $v1, 0x28($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X28);
    // 0x801348D8: beql        $v1, $zero, L_80134928
    if (ctx->r3 == 0) {
        // 0x801348DC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80134928;
    }
    goto skip_0;
    // 0x801348DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x801348E0: lhu         $t8, 0x2A($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2A);
    // 0x801348E4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x801348E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801348EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801348F0: bgez        $t8, L_80134904
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801348F4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80134904;
    }
    // 0x801348F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801348F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801348FC: nop

    // 0x80134900: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80134904:
    // 0x80134904: bgez        $v1, L_8013491C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80134908: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8013491C;
    }
    // 0x80134908: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013490C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80134910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134914: nop

    // 0x80134918: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8013491C:
    // 0x8013491C: jr          $ra
    // 0x80134920: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    return;
    // 0x80134920: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80134924: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80134928:
    // 0x80134928: nop

    // 0x8013492C: jr          $ra
    // 0x80134930: nop

    return;
    // 0x80134930: nop

;}

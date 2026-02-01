#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itMLuckyMakeEggInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180FC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180FC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80180FCC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80180FD0: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80180FD4: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80180FD8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80180FDC: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80180FE0: bne         $t6, $at, L_80181020
    if (ctx->r14 != ctx->r1) {
        // 0x80180FE4: addiu       $t9, $t9, 0x0
        ctx->r25 = ADD32(ctx->r25, 0X0);
            goto L_80181020;
    }
    // 0x80180FE4: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80180FE8: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x80180FEC: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80180FF0: addiu       $t1, $t1, 0xBC
    ctx->r9 = ADD32(ctx->r9, 0XBC);
    // 0x80180FF4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80180FF8: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80180FFC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80181000: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80181004: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80181008: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8018100C: jal         0x8000BD1C
    // 0x80181010: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80181010: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80181014: jal         0x8000DF34
    // 0x80181018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80181018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8018101C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80181020:
    // 0x80181020: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80181024: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80181028: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8018102C: sw          $t2, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r10;
    // 0x80181030: sh          $t3, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r11;
    // 0x80181034: sh          $t4, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r12;
    // 0x80181038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018103C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181040: jr          $ra
    // 0x80181044: nop

    return;
    // 0x80181044: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveWalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E98: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80134E9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80134EA4: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80134EA8: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x80134EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80134EB0: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x80134EB4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80134EB8: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80134EBC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80134EC0: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x80134EC4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80134EC8: lwc1        $f4, 0x22C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X22C);
    // 0x80134ECC: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x80134ED0: lwc1        $f6, 0x230($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X230);
    // 0x80134ED4: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x80134ED8: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80134EDC: bnel        $v0, $zero, L_80134FF4
    if (ctx->r2 != 0) {
        // 0x80134EE0: lw          $t3, 0xF4($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XF4);
            goto L_80134FF4;
    }
    goto skip_0;
    // 0x80134EE0: lw          $t3, 0xF4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XF4);
    skip_0:
    // 0x80134EE4: lw          $v1, 0x8E8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8E8);
    // 0x80134EE8: addiu       $t0, $a0, 0x1CC
    ctx->r8 = ADD32(ctx->r4, 0X1CC);
    // 0x80134EEC: lwc1        $f10, 0x64($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80134EF0: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80134EF4: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x80134EF8: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    // 0x80134EFC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80134F00: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    // 0x80134F04: bc1fl       L_80134FF4
    if (!c1cs) {
        // 0x80134F08: lw          $t3, 0xF4($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XF4);
            goto L_80134FF4;
    }
    goto skip_1;
    // 0x80134F08: lw          $t3, 0xF4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XF4);
    skip_1:
    // 0x80134F0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80134F10: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134F14: jal         0x800F5E90
    // 0x80134F18: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_0;
    // 0x80134F18: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x80134F1C: beq         $v0, $zero, L_80135364
    if (ctx->r2 == 0) {
        // 0x80134F20: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80135364;
    }
    // 0x80134F20: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80134F24: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x80134F28: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80134F2C: jal         0x800F4468
    // 0x80134F30: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionGetCeilEdgeL(rdram, ctx);
        goto after_1;
    // 0x80134F30: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_1:
    // 0x80134F34: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x80134F38: jal         0x800F4448
    // 0x80134F3C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    mpCollisionGetCeilEdgeR(rdram, ctx);
        goto after_2;
    // 0x80134F3C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_2:
    // 0x80134F40: lw          $t9, 0x8E8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8E8);
    // 0x80134F44: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80134F48: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80134F4C: lwc1        $f0, 0x1C($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80134F50: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80134F54: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80134F58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80134F5C: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80134F60: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80134F64: bc1fl       L_80134F7C
    if (!c1cs) {
        // 0x80134F68: sub.s       $f18, $f6, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f0.fl;
            goto L_80134F7C;
    }
    goto skip_2;
    // 0x80134F68: sub.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f0.fl;
    skip_2:
    // 0x80134F6C: sub.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80134F70: b           L_80134F7C
    // 0x80134F74: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
        goto L_80134F7C;
    // 0x80134F74: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x80134F78: sub.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f0.fl;
L_80134F7C:
    // 0x80134F7C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80134F80: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80134F84: bc1fl       L_80134F9C
    if (!c1cs) {
        // 0x80134F88: sub.s       $f12, $f10, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
            goto L_80134F9C;
    }
    goto skip_3;
    // 0x80134F88: sub.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
    skip_3:
    // 0x80134F8C: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80134F90: b           L_80134F9C
    // 0x80134F94: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80134F9C;
    // 0x80134F94: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80134F98: sub.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
L_80134F9C:
    // 0x80134F9C: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80134FA0: nop

    // 0x80134FA4: bc1fl       L_80134FD4
    if (!c1cs) {
        // 0x80134FA8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80134FD4;
    }
    goto skip_4;
    // 0x80134FA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x80134FAC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80134FB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134FB4: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80134FB8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80134FBC: swc1        $f8, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f8.u32l;
    // 0x80134FC0: lw          $t1, 0x8E8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8E8);
    // 0x80134FC4: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80134FC8: b           L_80135364
    // 0x80134FCC: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
        goto L_80135364;
    // 0x80134FCC: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
    // 0x80134FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80134FD4:
    // 0x80134FD4: nop

    // 0x80134FD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80134FDC: swc1        $f8, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f8.u32l;
    // 0x80134FE0: lw          $t2, 0x8E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8E8);
    // 0x80134FE4: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80134FE8: b           L_80135364
    // 0x80134FEC: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
        goto L_80135364;
    // 0x80134FEC: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
    // 0x80134FF0: lw          $t3, 0xF4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XF4);
L_80134FF4:
    // 0x80134FF4: addiu       $t0, $s0, 0x1CC
    ctx->r8 = ADD32(ctx->r16, 0X1CC);
    // 0x80134FF8: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x80134FFC: bne         $t4, $zero, L_80135164
    if (ctx->r12 != 0) {
        // 0x80135000: nop
    
            goto L_80135164;
    }
    // 0x80135000: nop

    // 0x80135004: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x80135008: bltz        $a0, L_80135164
    if (SIGNED(ctx->r4) < 0) {
        // 0x8013500C: nop
    
            goto L_80135164;
    }
    // 0x8013500C: nop

    // 0x80135010: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135014: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80135018: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8013501C: lwc1        $f14, 0x20($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80135020: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135024: lwc1        $f16, 0x64($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80135028: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8013502C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80135030: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80135034: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80135038: nop

    // 0x8013503C: bc1f        L_80135164
    if (!c1cs) {
        // 0x80135040: nop
    
            goto L_80135164;
    }
    // 0x80135040: nop

    // 0x80135044: lwc1        $f2, 0x60($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80135048: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8013504C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80135050: nop

    // 0x80135054: bc1fl       L_8013506C
    if (!c1cs) {
        // 0x80135058: sub.s       $f18, $f2, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8013506C;
    }
    goto skip_5;
    // 0x80135058: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    skip_5:
    // 0x8013505C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80135060: b           L_8013506C
    // 0x80135064: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
        goto L_8013506C;
    // 0x80135064: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x80135068: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
L_8013506C:
    // 0x8013506C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80135070: nop

    // 0x80135074: bc1fl       L_8013508C
    if (!c1cs) {
        // 0x80135078: sub.s       $f12, $f16, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
            goto L_8013508C;
    }
    goto skip_6;
    // 0x80135078: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    skip_6:
    // 0x8013507C: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80135080: b           L_8013508C
    // 0x80135084: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8013508C;
    // 0x80135084: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80135088: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
L_8013508C:
    // 0x8013508C: lwc1        $f4, -0x4244($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4244);
    // 0x80135090: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80135094: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80135098: nop

    // 0x8013509C: bc1f        L_80135164
    if (!c1cs) {
        // 0x801350A0: nop
    
            goto L_80135164;
    }
    // 0x801350A0: nop

    // 0x801350A4: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x801350A8: jal         0x800F4428
    // 0x801350AC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x801350AC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_3:
    // 0x801350B0: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x801350B4: jal         0x800F4408
    // 0x801350B8: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x801350B8: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_4:
    // 0x801350BC: lw          $t5, 0x8E8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8E8);
    // 0x801350C0: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801350C4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801350C8: lwc1        $f0, 0x1C($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x801350CC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801350D0: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801350D4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801350D8: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801350DC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x801350E0: bc1fl       L_801350F8
    if (!c1cs) {
        // 0x801350E4: sub.s       $f18, $f10, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
            goto L_801350F8;
    }
    goto skip_7;
    // 0x801350E4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    skip_7:
    // 0x801350E8: sub.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x801350EC: b           L_801350F8
    // 0x801350F0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
        goto L_801350F8;
    // 0x801350F0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x801350F4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
L_801350F8:
    // 0x801350F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801350FC: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80135100: bc1fl       L_80135118
    if (!c1cs) {
        // 0x80135104: sub.s       $f12, $f6, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
            goto L_80135118;
    }
    goto skip_8;
    // 0x80135104: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    skip_8:
    // 0x80135108: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8013510C: b           L_80135118
    // 0x80135110: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80135118;
    // 0x80135110: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80135114: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
L_80135118:
    // 0x80135118: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8013511C: nop

    // 0x80135120: bc1fl       L_8013514C
    if (!c1cs) {
        // 0x80135124: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8013514C;
    }
    goto skip_9;
    // 0x80135124: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_9:
    // 0x80135128: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8013512C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135130: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80135134: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80135138: swc1        $f4, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f4.u32l;
    // 0x8013513C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80135140: b           L_80135364
    // 0x80135144: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
        goto L_80135364;
    // 0x80135144: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
    // 0x80135148: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8013514C:
    // 0x8013514C: nop

    // 0x80135150: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80135154: swc1        $f4, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f4.u32l;
    // 0x80135158: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8013515C: b           L_80135364
    // 0x80135160: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
        goto L_80135364;
    // 0x80135160: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
L_80135164:
    // 0x80135164: beql        $v0, $zero, L_801351A4
    if (ctx->r2 == 0) {
        // 0x80135168: lw          $v1, 0x8E8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8E8);
            goto L_801351A4;
    }
    goto skip_10;
    // 0x80135168: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
    skip_10:
    // 0x8013516C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80135170: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80135174: nop

    // 0x80135178: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8013517C: nop

    // 0x80135180: bc1tl       L_801351A4
    if (c1cs) {
        // 0x80135184: lw          $v1, 0x8E8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8E8);
            goto L_801351A4;
    }
    goto skip_11;
    // 0x80135184: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
    skip_11:
    // 0x80135188: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013518C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80135190: beq         $v0, $at, L_801351A0
    if (ctx->r2 == ctx->r1) {
        // 0x80135194: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801351A0;
    }
    // 0x80135194: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80135198: bnel        $v0, $at, L_80135368
    if (ctx->r2 != ctx->r1) {
        // 0x8013519C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135368;
    }
    goto skip_12;
    // 0x8013519C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_12:
L_801351A0:
    // 0x801351A0: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
L_801351A4:
    // 0x801351A4: lwc1        $f6, 0x60($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X60);
    // 0x801351A8: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x801351AC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801351B0: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    // 0x801351B4: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    // 0x801351B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801351BC: nop

    // 0x801351C0: bc1fl       L_801352A0
    if (!c1cs) {
        // 0x801351C4: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_801352A0;
    }
    goto skip_13;
    // 0x801351C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_13:
    // 0x801351C8: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    // 0x801351CC: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x801351D0: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    // 0x801351D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801351D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801351DC: jal         0x800F7F00
    // 0x801351E0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_5;
    // 0x801351E0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_5:
    // 0x801351E4: beq         $v0, $zero, L_80135364
    if (ctx->r2 == 0) {
        // 0x801351E8: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80135364;
    }
    // 0x801351E8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801351EC: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x801351F0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801351F4: jal         0x800F4650
    // 0x801351F8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_6;
    // 0x801351F8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_6:
    // 0x801351FC: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80135200: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80135204: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80135208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013520C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80135210: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135214: add.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f10.d + ctx->f0.d;
    // 0x80135218: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8013521C: swc1        $f6, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f6.u32l;
    // 0x80135220: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80135224: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80135228: add.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f10.d + ctx->f0.d;
    // 0x8013522C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80135230: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
    // 0x80135234: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x80135238: bnel        $t6, $zero, L_80135368
    if (ctx->r14 != 0) {
        // 0x8013523C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135368;
    }
    goto skip_14;
    // 0x8013523C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
    // 0x80135240: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80135244: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80135248: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8013524C: nop

    // 0x80135250: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135254: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80135258: nop

    // 0x8013525C: bc1fl       L_80135368
    if (!c1cs) {
        // 0x80135260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135368;
    }
    goto skip_15;
    // 0x80135260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_15:
    // 0x80135264: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135268: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013526C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135270: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80135274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135278: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8013527C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135280: swc1        $f10, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f10.u32l;
    // 0x80135284: lw          $t9, 0x8E8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135288: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8013528C: jal         0x80132758
    // 0x80135290: swc1        $f4, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f4.u32l;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_7;
    // 0x80135290: swc1        $f4, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f4.u32l;
    after_7:
    // 0x80135294: b           L_80135B68
    // 0x80135298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013529C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_801352A0:
    // 0x801352A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801352A4: jal         0x800F6B58
    // 0x801352A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_8;
    // 0x801352A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_8:
    // 0x801352AC: beq         $v0, $zero, L_80135364
    if (ctx->r2 == 0) {
        // 0x801352B0: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80135364;
    }
    // 0x801352B0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801352B4: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x801352B8: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801352BC: jal         0x800F4690
    // 0x801352C0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_9;
    // 0x801352C0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_9:
    // 0x801352C4: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801352C8: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x801352CC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801352D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801352D4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801352D8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801352DC: sub.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d - ctx->f0.d;
    // 0x801352E0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801352E4: swc1        $f4, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f4.u32l;
    // 0x801352E8: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801352EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x801352F0: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x801352F4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x801352F8: swc1        $f4, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f4.u32l;
    // 0x801352FC: lw          $t1, 0x14C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14C);
    // 0x80135300: bnel        $t1, $zero, L_80135368
    if (ctx->r9 != 0) {
        // 0x80135304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135368;
    }
    goto skip_16;
    // 0x80135304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_16:
    // 0x80135308: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8013530C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80135310: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80135314: nop

    // 0x80135318: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013531C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80135320: nop

    // 0x80135324: bc1fl       L_80135368
    if (!c1cs) {
        // 0x80135328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135368;
    }
    goto skip_17;
    // 0x80135328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_17:
    // 0x8013532C: lw          $t3, 0x8E8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135330: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80135334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135338: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8013533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135340: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80135344: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80135348: swc1        $f6, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f6.u32l;
    // 0x8013534C: lw          $t4, 0x8E8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135350: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80135354: jal         0x80132758
    // 0x80135358: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_10;
    // 0x80135358: swc1        $f10, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f10.u32l;
    after_10:
    // 0x8013535C: b           L_80135B68
    // 0x80135360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135364:
    // 0x80135364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80135368:
    // 0x80135368: jal         0x80134B4C
    // 0x8013536C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    ftComputerCheckTargetItemOrTwister(rdram, ctx);
        goto after_11;
    // 0x8013536C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_11:
    // 0x80135370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135374: jal         0x80132758
    // 0x80135378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_12;
    // 0x80135378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8013537C: lw          $t5, 0x14C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14C);
    // 0x80135380: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135384: beql        $t5, $zero, L_8013596C
    if (ctx->r13 == 0) {
        // 0x80135388: lw          $v1, 0x8E8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8E8);
            goto L_8013596C;
    }
    goto skip_18;
    // 0x80135388: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
    skip_18:
    // 0x8013538C: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
    // 0x80135390: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80135394: beq         $v1, $at, L_801353BC
    if (ctx->r3 == ctx->r1) {
        // 0x80135398: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801353BC;
    }
    // 0x80135398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013539C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801353A0: beq         $v0, $at, L_801353E0
    if (ctx->r2 == ctx->r1) {
        // 0x801353A4: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_801353E0;
    }
    // 0x801353A4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801353A8: beql        $v0, $at, L_801353E4
    if (ctx->r2 == ctx->r1) {
        // 0x801353AC: lw          $t8, 0x8E8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8E8);
            goto L_801353E4;
    }
    goto skip_19;
    // 0x801353AC: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
    skip_19:
    // 0x801353B0: lw          $t6, 0x8E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8E8);
    // 0x801353B4: b           L_80135400
    // 0x801353B8: lwc1        $f14, 0x20($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X20);
        goto L_80135400;
    // 0x801353B8: lwc1        $f14, 0x20($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X20);
L_801353BC:
    // 0x801353BC: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x801353C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801353C4: lwc1        $f14, 0x20($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X20);
    // 0x801353C8: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x801353CC: nop

    // 0x801353D0: bc1fl       L_80135404
    if (!c1cs) {
        // 0x801353D4: lwc1        $f16, 0x64($t0)
        ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
            goto L_80135404;
    }
    goto skip_20;
    // 0x801353D4: lwc1        $f16, 0x64($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
    skip_20:
    // 0x801353D8: b           L_80135B68
    // 0x801353DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x801353DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801353E0:
    // 0x801353E0: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
L_801353E4:
    // 0x801353E4: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x801353E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801353EC: lwc1        $f14, 0x20($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801353F0: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x801353F4: nop

    // 0x801353F8: bc1tl       L_80135B68
    if (c1cs) {
        // 0x801353FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80135B68;
    }
    goto skip_21;
    // 0x801353FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
L_80135400:
    // 0x80135400: lwc1        $f16, 0x64($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
L_80135404:
    // 0x80135404: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80135408: nop

    // 0x8013540C: bc1fl       L_80135634
    if (!c1cs) {
        // 0x80135410: lwc1        $f4, 0x4C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
            goto L_80135634;
    }
    goto skip_22;
    // 0x80135410: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    skip_22:
    // 0x80135414: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x80135418: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8013541C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80135420: beql        $a1, $t9, L_80135450
    if (ctx->r5 == ctx->r25) {
        // 0x80135424: lbu         $t1, 0x4A($t0)
        ctx->r9 = MEM_BU(ctx->r8, 0X4A);
            goto L_80135450;
    }
    goto skip_23;
    // 0x80135424: lbu         $t1, 0x4A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4A);
    skip_23:
    // 0x80135428: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013542C: nop

    // 0x80135430: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80135434: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x80135438: nop

    // 0x8013543C: bc1fl       L_80135450
    if (!c1cs) {
        // 0x80135440: lbu         $t1, 0x4A($t0)
        ctx->r9 = MEM_BU(ctx->r8, 0X4A);
            goto L_80135450;
    }
    goto skip_24;
    // 0x80135440: lbu         $t1, 0x4A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4A);
    skip_24:
    // 0x80135444: b           L_80135B64
    // 0x80135448: swc1        $f14, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f14.u32l;
        goto L_80135B64;
    // 0x80135448: swc1        $f14, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f14.u32l;
    // 0x8013544C: lbu         $t1, 0x4A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4A);
L_80135450:
    // 0x80135450: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80135454: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80135458: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x8013545C: sb          $t2, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r10;
    // 0x80135460: lw          $t4, 0x1300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1300);
    // 0x80135464: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135468: lw          $t3, 0x8E8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8E8);
    // 0x8013546C: lh          $t5, 0x74($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X74);
    // 0x80135470: lwc1        $f4, 0x20($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80135474: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80135478: nop

    // 0x8013547C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135480: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80135484: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80135488: nop

    // 0x8013548C: bc1f        L_80135628
    if (!c1cs) {
        // 0x80135490: nop
    
            goto L_80135628;
    }
    // 0x80135490: nop

    // 0x80135494: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80135498: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013549C: nop

    // 0x801354A0: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x801354A4: nop

    // 0x801354A8: bc1f        L_80135628
    if (!c1cs) {
        // 0x801354AC: nop
    
            goto L_80135628;
    }
    // 0x801354AC: nop

    // 0x801354B0: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x801354B4: lbu         $v1, 0x148($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X148);
    // 0x801354B8: lw          $a0, 0x64($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X64);
    // 0x801354BC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801354C0: beql        $at, $zero, L_8013551C
    if (ctx->r1 == 0) {
        // 0x801354C4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8013551C;
    }
    goto skip_25;
    // 0x801354C4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    skip_25:
    // 0x801354C8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x801354CC: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801354D0: beq         $v0, $at, L_801354F8
    if (ctx->r2 == ctx->r1) {
        // 0x801354D4: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_801354F8;
    }
    // 0x801354D4: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x801354D8: beq         $v0, $at, L_801354F8
    if (ctx->r2 == ctx->r1) {
        // 0x801354DC: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_801354F8;
    }
    // 0x801354DC: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x801354E0: beq         $v0, $at, L_801354F8
    if (ctx->r2 == ctx->r1) {
        // 0x801354E4: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_801354F8;
    }
    // 0x801354E4: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x801354E8: beq         $v0, $at, L_801354F8
    if (ctx->r2 == ctx->r1) {
        // 0x801354EC: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_801354F8;
    }
    // 0x801354EC: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x801354F0: bnel        $v0, $at, L_8013551C
    if (ctx->r2 != ctx->r1) {
        // 0x801354F4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8013551C;
    }
    goto skip_26;
    // 0x801354F4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    skip_26:
L_801354F8:
    // 0x801354F8: lw          $t7, 0xB18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB18);
    // 0x801354FC: bnel        $t7, $zero, L_8013551C
    if (ctx->r15 != 0) {
        // 0x80135500: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8013551C;
    }
    goto skip_27;
    // 0x80135500: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    skip_27:
    // 0x80135504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135508: jal         0x80132758
    // 0x8013550C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_13;
    // 0x8013550C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x80135510: b           L_80135B68
    // 0x80135514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135518: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8013551C:
    // 0x8013551C: beql        $at, $zero, L_8013556C
    if (ctx->r1 == 0) {
        // 0x80135520: lbu         $t8, 0x0($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0X0);
            goto L_8013556C;
    }
    goto skip_28;
    // 0x80135520: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    skip_28:
    // 0x80135524: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80135528: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8013552C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135530: beq         $v0, $at, L_80135558
    if (ctx->r2 == ctx->r1) {
        // 0x80135534: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80135558;
    }
    // 0x80135534: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80135538: beq         $v0, $at, L_80135558
    if (ctx->r2 == ctx->r1) {
        // 0x8013553C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80135558;
    }
    // 0x8013553C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80135540: beq         $v0, $at, L_80135558
    if (ctx->r2 == ctx->r1) {
        // 0x80135544: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80135558;
    }
    // 0x80135544: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80135548: beq         $v0, $at, L_80135558
    if (ctx->r2 == ctx->r1) {
        // 0x8013554C: addiu       $at, $zero, 0x3A
        ctx->r1 = ADD32(0, 0X3A);
            goto L_80135558;
    }
    // 0x8013554C: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80135550: bnel        $v0, $at, L_8013556C
    if (ctx->r2 != ctx->r1) {
        // 0x80135554: lbu         $t8, 0x0($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0X0);
            goto L_8013556C;
    }
    goto skip_29;
    // 0x80135554: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    skip_29:
L_80135558:
    // 0x80135558: jal         0x80132758
    // 0x8013555C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_14;
    // 0x8013555C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80135560: b           L_80135B68
    // 0x80135564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135568: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
L_8013556C:
    // 0x8013556C: bne         $a1, $t8, L_80135628
    if (ctx->r5 != ctx->r24) {
        // 0x80135570: nop
    
            goto L_80135628;
    }
    // 0x80135570: nop

    // 0x80135574: lhu         $t9, 0x48($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X48);
    // 0x80135578: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8013557C: bne         $t1, $zero, L_80135628
    if (ctx->r9 != 0) {
        // 0x80135580: nop
    
            goto L_80135628;
    }
    // 0x80135580: nop

    // 0x80135584: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80135588: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013558C: beq         $v0, $at, L_80135628
    if (ctx->r2 == ctx->r1) {
        // 0x80135590: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80135628;
    }
    // 0x80135590: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80135594: beq         $v0, $at, L_80135628
    if (ctx->r2 == ctx->r1) {
        // 0x80135598: nop
    
            goto L_80135628;
    }
    // 0x80135598: nop

    // 0x8013559C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x801355A0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801355A4: beq         $v0, $at, L_801355C4
    if (ctx->r2 == ctx->r1) {
        // 0x801355A8: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_801355C4;
    }
    // 0x801355A8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x801355AC: beq         $v0, $at, L_801355C4
    if (ctx->r2 == ctx->r1) {
        // 0x801355B0: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_801355C4;
    }
    // 0x801355B0: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801355B4: beq         $v0, $at, L_801355C4
    if (ctx->r2 == ctx->r1) {
        // 0x801355B8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_801355C4;
    }
    // 0x801355B8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x801355BC: bne         $v0, $at, L_80135628
    if (ctx->r2 != ctx->r1) {
        // 0x801355C0: nop
    
            goto L_80135628;
    }
    // 0x801355C0: nop

L_801355C4:
    // 0x801355C4: lbu         $t3, 0x49($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X49);
    // 0x801355C8: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801355CC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801355D0: sb          $t4, 0x49($t0)
    MEM_B(0X49, ctx->r8) = ctx->r12;
    // 0x801355D4: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x801355D8: beql        $t5, $at, L_80135618
    if (ctx->r13 == ctx->r1) {
        // 0x801355DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135618;
    }
    goto skip_30;
    // 0x801355DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_30:
    // 0x801355E0: jal         0x80018948
    // 0x801355E4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    syUtilsRandFloat(rdram, ctx);
        goto after_15;
    // 0x801355E4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_15:
    // 0x801355E8: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x801355EC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801355F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801355F4: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x801355F8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801355FC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135600: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135604: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80135608: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8013560C: nop

    // 0x80135610: bc1f        L_80135628
    if (!c1cs) {
        // 0x80135614: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135628;
    }
    // 0x80135614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80135618:
    // 0x80135618: jal         0x80132758
    // 0x8013561C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_16;
    // 0x8013561C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_16:
    // 0x80135620: b           L_80135B68
    // 0x80135624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135628:
    // 0x80135628: b           L_80135714
    // 0x8013562C: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
        goto L_80135714;
    // 0x8013562C: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
    // 0x80135630: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
L_80135634:
    // 0x80135634: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80135638: nop

    // 0x8013563C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80135640: nop

    // 0x80135644: bc1fl       L_80135718
    if (!c1cs) {
        // 0x80135648: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80135718;
    }
    goto skip_31;
    // 0x80135648: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_31:
    // 0x8013564C: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x80135650: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80135654: beql        $a1, $t8, L_80135718
    if (ctx->r5 == ctx->r24) {
        // 0x80135658: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80135718;
    }
    goto skip_32;
    // 0x80135658: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_32:
    // 0x8013565C: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x80135660: sll         $t2, $t9, 12
    ctx->r10 = S32(ctx->r25 << 12);
    // 0x80135664: bltzl       $t2, L_80135718
    if (SIGNED(ctx->r10) < 0) {
        // 0x80135668: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80135718;
    }
    goto skip_33;
    // 0x80135668: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_33:
    // 0x8013566C: lh          $t4, 0x4A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X4A);
    // 0x80135670: bltzl       $t4, L_80135718
    if (SIGNED(ctx->r12) < 0) {
        // 0x80135674: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80135718;
    }
    goto skip_34;
    // 0x80135674: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_34:
    // 0x80135678: lbu         $t6, 0x4A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X4A);
    // 0x8013567C: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80135680: sb          $t7, 0x4A($t0)
    MEM_B(0X4A, ctx->r8) = ctx->r15;
    // 0x80135684: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x80135688: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8013568C: bnel        $at, $zero, L_801356E8
    if (ctx->r1 != 0) {
        // 0x80135690: lbu         $v1, 0x3($t0)
        ctx->r3 = MEM_BU(ctx->r8, 0X3);
            goto L_801356E8;
    }
    goto skip_35;
    // 0x80135690: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
    skip_35:
    // 0x80135694: jal         0x80018948
    // 0x80135698: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    syUtilsRandFloat(rdram, ctx);
        goto after_17;
    // 0x80135698: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_17:
    // 0x8013569C: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x801356A0: addiu       $t2, $zero, 0x226
    ctx->r10 = ADD32(0, 0X226);
    // 0x801356A4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801356A8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x801356AC: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801356B0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801356B4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801356B8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801356BC: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x801356C0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801356C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801356C8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801356CC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801356D0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801356D4: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801356D8: nop

    // 0x801356DC: bc1tl       L_80135704
    if (c1cs) {
        // 0x801356E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135704;
    }
    goto skip_36;
    // 0x801356E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_36:
    // 0x801356E4: lbu         $v1, 0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X3);
L_801356E8:
    // 0x801356E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801356EC: beq         $v1, $at, L_80135700
    if (ctx->r3 == ctx->r1) {
        // 0x801356F0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80135700;
    }
    // 0x801356F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801356F4: beq         $v1, $at, L_80135700
    if (ctx->r3 == ctx->r1) {
        // 0x801356F8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80135700;
    }
    // 0x801356F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801356FC: bne         $v1, $at, L_80135714
    if (ctx->r3 != ctx->r1) {
        // 0x80135700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135714;
    }
L_80135700:
    // 0x80135700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80135704:
    // 0x80135704: jal         0x80132564
    // 0x80135708: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_18;
    // 0x80135708: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_18:
    // 0x8013570C: b           L_80135B68
    // 0x80135710: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135710: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135714:
    // 0x80135714: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80135718:
    // 0x80135718: beq         $v1, $at, L_80135738
    if (ctx->r3 == ctx->r1) {
        // 0x8013571C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80135738;
    }
    // 0x8013571C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80135720: beq         $v1, $at, L_80135738
    if (ctx->r3 == ctx->r1) {
        // 0x80135724: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80135738;
    }
    // 0x80135724: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80135728: beql        $v1, $at, L_8013573C
    if (ctx->r3 == ctx->r1) {
        // 0x8013572C: lw          $t4, 0x24($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X24);
            goto L_8013573C;
    }
    goto skip_37;
    // 0x8013572C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    skip_37:
    // 0x80135730: b           L_80135788
    // 0x80135734: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
        goto L_80135788;
    // 0x80135734: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
L_80135738:
    // 0x80135738: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
L_8013573C:
    // 0x8013573C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80135740: bnel        $t4, $at, L_80135788
    if (ctx->r12 != ctx->r1) {
        // 0x80135744: lbu         $v0, 0x13($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X13);
            goto L_80135788;
    }
    goto skip_38;
    // 0x80135744: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
    skip_38:
    // 0x80135748: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x8013574C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80135750: jal         0x800F8FFC
    // 0x80135754: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_19;
    // 0x80135754: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_19:
    // 0x80135758: beq         $v0, $zero, L_80135784
    if (ctx->r2 == 0) {
        // 0x8013575C: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80135784;
    }
    // 0x8013575C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135760: lw          $t5, 0x8E8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135764: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80135768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013576C: lwc1        $f6, 0x1C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80135770: swc1        $f6, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f6.u32l;
    // 0x80135774: lw          $t6, 0x8E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8E8);
    // 0x80135778: lwc1        $f10, 0x20($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8013577C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80135780: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
L_80135784:
    // 0x80135784: lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X13);
L_80135788:
    // 0x80135788: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8013578C: bnel        $at, $zero, L_801358AC
    if (ctx->r1 != 0) {
        // 0x80135790: lw          $t7, 0x48($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X48);
            goto L_801358AC;
    }
    goto skip_39;
    // 0x80135790: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
    skip_39:
    // 0x80135794: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
    // 0x80135798: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013579C: sll         $t9, $t7, 17
    ctx->r25 = S32(ctx->r15 << 17);
    // 0x801357A0: bgezl       $t9, L_801358AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801357A4: lw          $t7, 0x48($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X48);
            goto L_801358AC;
    }
    goto skip_40;
    // 0x801357A4: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
    skip_40:
    // 0x801357A8: lwc1        $f6, 0x64($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801357AC: lwc1        $f10, -0x4240($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4240);
    // 0x801357B0: lw          $t2, 0x8E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8E8);
    // 0x801357B4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801357B8: lwc1        $f8, 0x20($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X20);
    // 0x801357BC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801357C0: nop

    // 0x801357C4: bc1fl       L_801358AC
    if (!c1cs) {
        // 0x801357C8: lw          $t7, 0x48($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X48);
            goto L_801358AC;
    }
    goto skip_41;
    // 0x801357C8: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
    skip_41:
    // 0x801357CC: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801357D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801357D4: nop

    // 0x801357D8: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x801357DC: nop

    // 0x801357E0: bc1fl       L_801358AC
    if (!c1cs) {
        // 0x801357E4: lw          $t7, 0x48($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X48);
            goto L_801358AC;
    }
    goto skip_42;
    // 0x801357E4: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
    skip_42:
    // 0x801357E8: lw          $v1, 0x6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6C);
    // 0x801357EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801357F0: lwc1        $f6, -0x423C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X423C);
    // 0x801357F4: lw          $t1, 0x44($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X44);
    // 0x801357F8: lw          $t3, 0x8E8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8E8);
    // 0x801357FC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80135800: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80135804: nop

    // 0x80135808: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013580C: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80135810: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80135814: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80135818: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013581C: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80135820: lw          $t4, 0x8E8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8E8);
    // 0x80135824: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80135828: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8013582C: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x80135830: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x80135834: jal         0x800F8FFC
    // 0x80135838: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_20;
    // 0x80135838: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x8013583C: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80135840: beq         $v0, $zero, L_8013585C
    if (ctx->r2 == 0) {
        // 0x80135844: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_8013585C;
    }
    // 0x80135844: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135848: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8013584C: swc1        $f10, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f10.u32l;
    // 0x80135850: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80135854: b           L_801358A8
    // 0x80135858: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
        goto L_801358A8;
    // 0x80135858: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
L_8013585C:
    // 0x8013585C: lw          $t5, 0x44($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X44);
    // 0x80135860: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80135864: lwc1        $f10, -0x4238($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4238);
    // 0x80135868: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8013586C: lw          $t6, 0x8E8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8E8);
    // 0x80135870: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80135874: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80135878: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8013587C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80135880: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80135884: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135888: jal         0x800F8FFC
    // 0x8013588C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_21;
    // 0x8013588C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_21:
    // 0x80135890: beq         $v0, $zero, L_801358A8
    if (ctx->r2 == 0) {
        // 0x80135894: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_801358A8;
    }
    // 0x80135894: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135898: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8013589C: swc1        $f10, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f10.u32l;
    // 0x801358A0: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801358A4: swc1        $f6, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f6.u32l;
L_801358A8:
    // 0x801358A8: lw          $t7, 0x48($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X48);
L_801358AC:
    // 0x801358AC: sll         $t9, $t7, 17
    ctx->r25 = S32(ctx->r15 << 17);
    // 0x801358B0: bgezl       $t9, L_80135958
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801358B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135958;
    }
    goto skip_43;
    // 0x801358B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_43:
    // 0x801358B8: lw          $a0, 0x5C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X5C);
    // 0x801358BC: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x801358C0: bltzl       $a0, L_80135958
    if (SIGNED(ctx->r4) < 0) {
        // 0x801358C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135958;
    }
    goto skip_44;
    // 0x801358C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_44:
    // 0x801358C8: jal         0x800F4428
    // 0x801358CC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_22;
    // 0x801358CC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_22:
    // 0x801358D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801358D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x801358D8: jal         0x800F4408
    // 0x801358DC: lw          $a0, 0x5C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X5C);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_23;
    // 0x801358DC: lw          $a0, 0x5C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X5C);
    after_23:
    // 0x801358E0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801358E4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801358E8: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801358EC: lwc1        $f2, 0x60($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X60);
    // 0x801358F0: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x801358F4: nop

    // 0x801358F8: bc1fl       L_80135958
    if (!c1cs) {
        // 0x801358FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135958;
    }
    goto skip_45;
    // 0x801358FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_45:
    // 0x80135900: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80135904: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80135908: bc1fl       L_80135958
    if (!c1cs) {
        // 0x8013590C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135958;
    }
    goto skip_46;
    // 0x8013590C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_46:
    // 0x80135910: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135914: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80135918: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013591C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80135920: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80135924: nop

    // 0x80135928: bc1fl       L_8013593C
    if (!c1cs) {
        // 0x8013592C: lwc1        $f6, 0x68($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
            goto L_8013593C;
    }
    goto skip_47;
    // 0x8013592C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    skip_47:
    // 0x80135930: swc1        $f0, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f0.u32l;
    // 0x80135934: lwc1        $f2, 0x60($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80135938: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
L_8013593C:
    // 0x8013593C: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80135940: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80135944: nop

    // 0x80135948: bc1fl       L_80135958
    if (!c1cs) {
        // 0x8013594C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135958;
    }
    goto skip_48;
    // 0x8013594C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_48:
    // 0x80135950: swc1        $f0, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f0.u32l;
    // 0x80135954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80135958:
    // 0x80135958: jal         0x80132758
    // 0x8013595C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_24;
    // 0x8013595C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80135960: b           L_80135B68
    // 0x80135964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135968: lw          $v1, 0x8E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8E8);
L_8013596C:
    // 0x8013596C: lwc1        $f2, 0x60($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80135970: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80135974: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80135978: nop

    // 0x8013597C: bc1fl       L_80135994
    if (!c1cs) {
        // 0x80135980: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80135994;
    }
    goto skip_49;
    // 0x80135980: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_49:
    // 0x80135984: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80135988: b           L_80135994
    // 0x8013598C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80135994;
    // 0x8013598C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80135990: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_80135994:
    // 0x80135994: lwc1        $f8, 0x8C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x80135998: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8013599C: nop

    // 0x801359A0: bc1fl       L_80135AD0
    if (!c1cs) {
        // 0x801359A4: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_80135AD0;
    }
    goto skip_50;
    // 0x801359A4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_50:
    // 0x801359A8: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801359AC: lwc1        $f6, 0x64($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801359B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801359B4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x801359B8: nop

    // 0x801359BC: bc1f        L_80135ABC
    if (!c1cs) {
        // 0x801359C0: nop
    
            goto L_80135ABC;
    }
    // 0x801359C0: nop

    // 0x801359C4: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x801359C8: bltzl       $a0, L_80135A3C
    if (SIGNED(ctx->r4) < 0) {
        // 0x801359CC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80135A3C;
    }
    goto skip_51;
    // 0x801359CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_51:
    // 0x801359D0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801359D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801359D8: nop

    // 0x801359DC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801359E0: nop

    // 0x801359E4: bc1f        L_801359FC
    if (!c1cs) {
        // 0x801359E8: nop
    
            goto L_801359FC;
    }
    // 0x801359E8: nop

    // 0x801359EC: jal         0x800F4428
    // 0x801359F0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_25;
    // 0x801359F0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_25:
    // 0x801359F4: b           L_80135A08
    // 0x801359F8: lw          $t2, 0x8E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8E8);
        goto L_80135A08;
    // 0x801359F8: lw          $t2, 0x8E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8E8);
L_801359FC:
    // 0x801359FC: jal         0x800F4408
    // 0x80135A00: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_26;
    // 0x80135A00: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_26:
    // 0x80135A04: lw          $t2, 0x8E8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8E8);
L_80135A08:
    // 0x80135A08: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80135A0C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80135A10: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80135A14: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80135A18: nop

    // 0x80135A1C: bc1f        L_80135A30
    if (!c1cs) {
        // 0x80135A20: nop
    
            goto L_80135A30;
    }
    // 0x80135A20: nop

    // 0x80135A24: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80135A28: b           L_80135A40
    // 0x80135A2C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80135A40;
    // 0x80135A2C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80135A30:
    // 0x80135A30: b           L_80135A40
    // 0x80135A34: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
        goto L_80135A40;
    // 0x80135A34: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80135A38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80135A3C:
    // 0x80135A3C: nop

L_80135A40:
    // 0x80135A40: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80135A44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80135A48: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80135A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A50: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80135A54: nop

    // 0x80135A58: bc1fl       L_80135A6C
    if (!c1cs) {
        // 0x80135A5C: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80135A6C;
    }
    goto skip_52;
    // 0x80135A5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_52:
    // 0x80135A60: b           L_80135A6C
    // 0x80135A64: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_80135A6C;
    // 0x80135A64: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80135A68: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80135A6C:
    // 0x80135A6C: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80135A70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135A74: nop

    // 0x80135A78: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80135A7C: nop

    // 0x80135A80: bc1f        L_80135AAC
    if (!c1cs) {
        // 0x80135A84: nop
    
            goto L_80135AAC;
    }
    // 0x80135A84: nop

    // 0x80135A88: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80135A8C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80135A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A94: beql        $t1, $at, L_80135B68
    if (ctx->r9 == ctx->r1) {
        // 0x80135A98: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80135B68;
    }
    goto skip_53;
    // 0x80135A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_53:
    // 0x80135A9C: jal         0x80132564
    // 0x80135AA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_27;
    // 0x80135AA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_27:
    // 0x80135AA4: b           L_80135B68
    // 0x80135AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135AAC:
    // 0x80135AAC: jal         0x80132758
    // 0x80135AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_28;
    // 0x80135AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80135AB4: b           L_80135B68
    // 0x80135AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135AB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135ABC:
    // 0x80135ABC: jal         0x80132758
    // 0x80135AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_29;
    // 0x80135AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80135AC4: b           L_80135B68
    // 0x80135AC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135AC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135ACC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_80135AD0:
    // 0x80135AD0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80135AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135AD8: beq         $v0, $at, L_80135B5C
    if (ctx->r2 == ctx->r1) {
        // 0x80135ADC: nop
    
            goto L_80135B5C;
    }
    // 0x80135ADC: nop

    // 0x80135AE0: lw          $t3, 0xEC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XEC);
    // 0x80135AE4: lw          $t4, 0x5C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X5C);
    // 0x80135AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135AEC: beq         $t3, $t4, L_80135B4C
    if (ctx->r11 == ctx->r12) {
        // 0x80135AF0: nop
    
            goto L_80135B4C;
    }
    // 0x80135AF0: nop

    // 0x80135AF4: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80135AF8: lwc1        $f4, 0x64($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80135AFC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80135B00: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80135B04: nop

    // 0x80135B08: bc1fl       L_80135B2C
    if (!c1cs) {
        // 0x80135B0C: lw          $t5, 0xF4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XF4);
            goto L_80135B2C;
    }
    goto skip_54;
    // 0x80135B0C: lw          $t5, 0xF4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XF4);
    skip_54:
    // 0x80135B10: beq         $v0, $at, L_80135B64
    if (ctx->r2 == ctx->r1) {
        // 0x80135B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80135B64;
    }
    // 0x80135B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B18: jal         0x80132564
    // 0x80135B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_30;
    // 0x80135B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_30:
    // 0x80135B20: b           L_80135B68
    // 0x80135B24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135B24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135B28: lw          $t5, 0xF4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XF4);
L_80135B2C:
    // 0x80135B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B30: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80135B34: beql        $t6, $zero, L_80135B68
    if (ctx->r14 == 0) {
        // 0x80135B38: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80135B68;
    }
    goto skip_55;
    // 0x80135B38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_55:
    // 0x80135B3C: jal         0x80132564
    // 0x80135B40: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_31;
    // 0x80135B40: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_31:
    // 0x80135B44: b           L_80135B68
    // 0x80135B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135B4C:
    // 0x80135B4C: jal         0x80132758
    // 0x80135B50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_32;
    // 0x80135B50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80135B54: b           L_80135B68
    // 0x80135B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80135B68;
    // 0x80135B58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135B5C:
    // 0x80135B5C: jal         0x80132758
    // 0x80135B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_33;
    // 0x80135B60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
L_80135B64:
    // 0x80135B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80135B68:
    // 0x80135B68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80135B6C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80135B70: jr          $ra
    // 0x80135B74: nop

    return;
    // 0x80135B74: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A42C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016A430: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8016A434: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016A438: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8016A43C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8016A440: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8016A444: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016A448: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016A44C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016A450: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8016A454: ori         $a3, $a3, 0x2
    ctx->r7 = ctx->r7 | 0X2;
    // 0x8016A458: addiu       $a1, $a1, -0x6F1C
    ctx->r5 = ADD32(ctx->r5, -0X6F1C);
    // 0x8016A45C: jal         0x801655C8
    // 0x8016A460: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016A460: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8016A464: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016A468: bne         $v0, $zero, L_8016A478
    if (ctx->r2 != 0) {
        // 0x8016A46C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8016A478;
    }
    // 0x8016A46C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8016A470: b           L_8016A620
    // 0x8016A474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A620;
    // 0x8016A474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A478:
    // 0x8016A478: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    // 0x8016A47C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8016A480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016A484: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8016A488: sw          $t6, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r14;
    // 0x8016A48C: lw          $t7, 0x268($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X268);
    // 0x8016A490: sw          $t7, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r15;
    // 0x8016A494: lw          $t8, 0xA0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XA0);
    // 0x8016A498: sw          $t8, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r24;
    // 0x8016A49C: lw          $t9, 0xCC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XCC);
    // 0x8016A4A0: sw          $t9, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r25;
    // 0x8016A4A4: lw          $t0, 0xE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE0);
    // 0x8016A4A8: sw          $t0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r8;
    // 0x8016A4AC: jal         0x8000BB4C
    // 0x8016A4B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcSetAllAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x8016A4B0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8016A4B4: jal         0x80169D08
    // 0x8016A4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wpPikachuThunderJoltGroundProcMap(rdram, ctx);
        goto after_2;
    // 0x8016A4B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8016A4BC: lw          $a0, 0x29C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X29C);
    // 0x8016A4C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016A4C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A4C8: beql        $a0, $zero, L_8016A4EC
    if (ctx->r4 == 0) {
        // 0x8016A4CC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8016A4EC;
    }
    goto skip_0;
    // 0x8016A4CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8016A4D0: beq         $a0, $at, L_8016A5AC
    if (ctx->r4 == ctx->r1) {
        // 0x8016A4D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016A5AC;
    }
    // 0x8016A4D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016A4D8: beql        $a0, $at, L_8016A558
    if (ctx->r4 == ctx->r1) {
        // 0x8016A4DC: lwc1        $f12, 0x2A4($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
            goto L_8016A558;
    }
    goto skip_1;
    // 0x8016A4DC: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
    skip_1:
    // 0x8016A4E0: b           L_8016A604
    // 0x8016A4E4: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
        goto L_8016A604;
    // 0x8016A4E4: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x8016A4E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8016A4EC:
    // 0x8016A4EC: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8016A4F0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8016A4F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8016A4F8: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8016A4FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A500: bc1fl       L_8016A514
    if (!c1cs) {
        // 0x8016A504: sw          $t2, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r10;
            goto L_8016A514;
    }
    goto skip_2;
    // 0x8016A504: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
    skip_2:
    // 0x8016A508: b           L_8016A514
    // 0x8016A50C: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
        goto L_8016A514;
    // 0x8016A50C: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x8016A510: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
L_8016A514:
    // 0x8016A514: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
    // 0x8016A518: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8016A51C: nop

    // 0x8016A520: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016A524: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8016A528: nop

    // 0x8016A52C: bc1fl       L_8016A548
    if (!c1cs) {
        // 0x8016A530: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8016A548;
    }
    goto skip_3;
    // 0x8016A530: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_3:
    // 0x8016A534: lwc1        $f10, -0x3528($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3528);
    // 0x8016A538: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x8016A53C: b           L_8016A600
    // 0x8016A540: swc1        $f10, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f10.u32l;
        goto L_8016A600;
    // 0x8016A540: swc1        $f10, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f10.u32l;
    // 0x8016A544: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8016A548:
    // 0x8016A548: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x8016A54C: b           L_8016A600
    // 0x8016A550: swc1        $f16, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f16.u32l;
        goto L_8016A600;
    // 0x8016A550: swc1        $f16, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f16.u32l;
    // 0x8016A554: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
L_8016A558:
    // 0x8016A558: jal         0x8001863C
    // 0x8016A55C: lwc1        $f14, 0x2A0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2A0);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8016A55C: lwc1        $f14, 0x2A0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2A0);
    after_3:
    // 0x8016A560: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A564: lwc1        $f18, -0x3524($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3524);
    // 0x8016A568: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A56C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8016A570: nop

    // 0x8016A574: bc1f        L_8016A594
    if (!c1cs) {
        // 0x8016A578: nop
    
            goto L_8016A594;
    }
    // 0x8016A578: nop

    // 0x8016A57C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016A580: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8016A584: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8016A588: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    // 0x8016A58C: b           L_8016A600
    // 0x8016A590: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
        goto L_8016A600;
    // 0x8016A590: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_8016A594:
    // 0x8016A594: lwc1        $f6, -0x3520($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3520);
    // 0x8016A598: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8016A59C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8016A5A0: swc1        $f6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f6.u32l;
    // 0x8016A5A4: b           L_8016A600
    // 0x8016A5A8: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
        goto L_8016A600;
    // 0x8016A5A8: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
L_8016A5AC:
    // 0x8016A5AC: lwc1        $f12, 0x2A4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A4);
    // 0x8016A5B0: jal         0x8001863C
    // 0x8016A5B4: lwc1        $f14, 0x2A0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2A0);
    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x8016A5B4: lwc1        $f14, 0x2A0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2A0);
    after_4:
    // 0x8016A5B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A5BC: lwc1        $f8, -0x351C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X351C);
    // 0x8016A5C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A5C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8016A5C8: nop

    // 0x8016A5CC: bc1f        L_8016A5EC
    if (!c1cs) {
        // 0x8016A5D0: nop
    
            goto L_8016A5EC;
    }
    // 0x8016A5D0: nop

    // 0x8016A5D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8016A5D8: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x8016A5DC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8016A5E0: swc1        $f10, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f10.u32l;
    // 0x8016A5E4: b           L_8016A600
    // 0x8016A5E8: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
        goto L_8016A600;
    // 0x8016A5E8: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
L_8016A5EC:
    // 0x8016A5EC: lwc1        $f16, -0x3518($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3518);
    // 0x8016A5F0: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x8016A5F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8016A5F8: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x8016A5FC: sw          $t3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r11;
L_8016A600:
    // 0x8016A600: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
L_8016A604:
    // 0x8016A604: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x8016A608: jal         0x80101C34
    // 0x8016A60C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    efManagerPikachuThunderJoltMakeEffect(rdram, ctx);
        goto after_5;
    // 0x8016A60C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_5:
    // 0x8016A610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A614: jal         0x80167F08
    // 0x8016A618: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    wpMainPlayFGM(rdram, ctx);
        goto after_6;
    // 0x8016A618: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    after_6:
    // 0x8016A61C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8016A620:
    // 0x8016A620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A624: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8016A628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8016A62C: jr          $ra
    // 0x8016A630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8016A630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80377168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377168: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037716C: lh          $a0, 0x0($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X0);
    // 0x80377170: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x80377174: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80377178: bnel        $at, $zero, L_803771C4
    if (ctx->r1 != 0) {
        // 0x8037717C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_803771C4;
    }
    goto skip_0;
    // 0x8037717C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80377180: lhu         $t6, 0x4($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X4);
    // 0x80377184: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80377188: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8037718C: beq         $at, $zero, L_803771C0
    if (ctx->r1 == 0) {
        // 0x80377190: lh          $v0, 0x2($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X2);
            goto L_803771C0;
    }
    // 0x80377190: lh          $v0, 0x2($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2);
    // 0x80377194: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80377198: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037719C: bnel        $at, $zero, L_803771C4
    if (ctx->r1 != 0) {
        // 0x803771A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_803771C4;
    }
    goto skip_1;
    // 0x803771A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x803771A4: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x803771A8: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x803771AC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x803771B0: beql        $at, $zero, L_803771C4
    if (ctx->r1 == 0) {
        // 0x803771B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_803771C4;
    }
    goto skip_2;
    // 0x803771B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x803771B8: jr          $ra
    // 0x803771BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x803771BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_803771C0:
    // 0x803771C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803771C4:
    // 0x803771C4: jr          $ra
    // 0x803771C8: nop

    return;
    // 0x803771C8: nop

;}
RECOMP_FUNC void mvOpeningClashFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void mnModeSelectMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013216C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132170: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013217C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132180: jal         0x80009968
    // 0x80132184: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132184: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132188: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013218C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132190: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132194: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132198: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013219C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801321A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801321A4: jal         0x80009DF4
    // 0x801321A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801321A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801321AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801321B0: lw          $t7, 0x2D68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2D68);
    // 0x801321B4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801321B8: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x801321BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321C0: jal         0x800CCFDC
    // 0x801321C4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801321C4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801321C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801321CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801321D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801321D4: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801321D8: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x801321DC: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x801321E0: lw          $t9, 0x2D6C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2D6C);
    // 0x801321E4: addiu       $t0, $t0, 0x7C38
    ctx->r8 = ADD32(ctx->r8, 0X7C38);
    // 0x801321E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321EC: jal         0x800CCFDC
    // 0x801321F0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801321F0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x801321F4: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801321F8: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x801321FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80132200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132204: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80132208: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013220C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80132210: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80132214: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x80132218: addiu       $t7, $zero, 0x65
    ctx->r15 = ADD32(0, 0X65);
    // 0x8013221C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80132220: addiu       $t9, $zero, 0x60
    ctx->r25 = ADD32(0, 0X60);
    // 0x80132224: addiu       $t0, $zero, 0x26
    ctx->r8 = ADD32(0, 0X26);
    // 0x80132228: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013222C: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80132230: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80132234: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80132238: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x8013223C: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80132240: sb          $t8, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r24;
    // 0x80132244: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80132248: sh          $t9, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r25;
    // 0x8013224C: sh          $t0, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r8;
    // 0x80132250: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132254: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132258: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013225C: lw          $t1, 0x2D6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2D6C);
    // 0x80132260: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80132264: addiu       $t2, $t2, 0x72E8
    ctx->r10 = ADD32(ctx->r10, 0X72E8);
    // 0x80132268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
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
    // 0x80132278: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8013227C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132280: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x80132284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132288: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x8013228C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132290: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132294: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80132298: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x8013229C: addiu       $t9, $zero, 0x65
    ctx->r25 = ADD32(0, 0X65);
    // 0x801322A0: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801322A4: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x801322A8: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x801322AC: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x801322B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801322B4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801322B8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801322BC: lw          $t0, 0x2D6C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2D6C);
    // 0x801322C0: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801322C4: addiu       $t1, $t1, 0x40F0
    ctx->r9 = ADD32(ctx->r9, 0X40F0);
    // 0x801322C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322CC: jal         0x800CCFDC
    // 0x801322D0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801322D0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_5:
    // 0x801322D4: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x801322D8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801322DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801322E0: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x801322E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801322E8: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x801322EC: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801322F0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801322F4: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x801322F8: addiu       $t7, $zero, 0x73
    ctx->r15 = ADD32(0, 0X73);
    // 0x801322FC: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80132300: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132304: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132308: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8013230C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132310: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80132314: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132318: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x8013231C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132320: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132324: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132328: lw          $t9, 0x2D6C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2D6C);
    // 0x8013232C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80132330: addiu       $t0, $t0, 0x7AA8
    ctx->r8 = ADD32(ctx->r8, 0X7AA8);
    // 0x80132334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132338: jal         0x800CCFDC
    // 0x8013233C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8013233C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_6:
    // 0x80132340: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80132344: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x80132348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013234C: lui         $at, 0x4309
    ctx->r1 = S32(0X4309 << 16);
    // 0x80132350: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132354: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80132358: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013235C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80132360: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80132364: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x80132368: addiu       $t7, $zero, 0x65
    ctx->r15 = ADD32(0, 0X65);
    // 0x8013236C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132370: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80132374: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80132378: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x8013237C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132380: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132388: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013238C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132390: jr          $ra
    // 0x80132394: nop

    return;
    // 0x80132394: nop

;}
RECOMP_FUNC void ftKirbySpecialNEatProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016221C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80162220: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162224: addiu       $a1, $a1, 0x34C0
    ctx->r5 = ADD32(ctx->r5, 0X34C0);
    // 0x80162228: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8016222C: bne         $t6, $zero, L_80162240
    if (ctx->r14 != 0) {
        // 0x80162230: nop
    
            goto L_80162240;
    }
    // 0x80162230: nop

    // 0x80162234: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162238: b           L_80162240
    // 0x8016223C: addiu       $a1, $a1, 0x3274
    ctx->r5 = ADD32(ctx->r5, 0X3274);
        goto L_80162240;
    // 0x8016223C: addiu       $a1, $a1, 0x3274
    ctx->r5 = ADD32(ctx->r5, 0X3274);
L_80162240:
    // 0x80162240: jal         0x800D9480
    // 0x80162244: nop

    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80162244: nop

    after_0:
    // 0x80162248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016224C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162250: jr          $ra
    // 0x80162254: nop

    return;
    // 0x80162254: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwHitInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152578: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015257C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80152580: jr          $ra
    // 0x80152584: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
    return;
    // 0x80152584: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
;}
RECOMP_FUNC void ftPikachuSpecialAirHiStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801528B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801528B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801528BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801528C0: jal         0x800DEE98
    // 0x801528C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801528C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801528C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801528CC: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x801528D0: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x801528D4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801528D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801528DC: jal         0x800E6F24
    // 0x801528E0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801528E0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x801528E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801528E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801528EC: jr          $ra
    // 0x801528F0: nop

    return;
    // 0x801528F0: nop

;}
RECOMP_FUNC void ftNessSpecialHiCollideWallPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154598: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015459C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801545A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801545A4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801545A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801545AC: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x801545B0: bne         $t6, $at, L_801545C0
    if (ctx->r14 != ctx->r1) {
        // 0x801545B4: nop
    
            goto L_801545C0;
    }
    // 0x801545B4: nop

    // 0x801545B8: b           L_801545D0
    // 0x801545BC: lwc1        $f16, 0xB2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB2C);
        goto L_801545D0;
    // 0x801545BC: lwc1        $f16, 0xB2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB2C);
L_801545C0:
    // 0x801545C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801545C4: lwc1        $f4, -0x3A4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A4C);
    // 0x801545C8: lwc1        $f6, 0xB2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB2C);
    // 0x801545CC: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
L_801545D0:
    // 0x801545D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801545D4: lwc1        $f18, -0x3A48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A48);
    // 0x801545D8: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x801545DC: nop

    // 0x801545E0: bc1fl       L_801545F0
    if (!c1cs) {
        // 0x801545E4: lhu         $v0, 0x56($a1)
        ctx->r2 = MEM_HU(ctx->r5, 0X56);
            goto L_801545F0;
    }
    goto skip_0;
    // 0x801545E4: lhu         $v0, 0x56($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X56);
    skip_0:
    // 0x801545E8: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801545EC: lhu         $v0, 0x56($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X56);
L_801545F0:
    // 0x801545F0: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801545F4: beql        $t7, $zero, L_80154680
    if (ctx->r15 == 0) {
        // 0x801545F8: andi        $t8, $v0, 0x20
        ctx->r24 = ctx->r2 & 0X20;
            goto L_80154680;
    }
    goto skip_1;
    // 0x801545F8: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    skip_1:
    // 0x801545FC: lwc1        $f12, 0xAC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XAC);
    // 0x80154600: lwc1        $f14, 0xA8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XA8);
    // 0x80154604: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80154608: jal         0x8001863C
    // 0x8015460C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8015460C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80154610: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154614: lwc1        $f18, -0x3A44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A44);
    // 0x80154618: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8015461C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154620: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80154624: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80154628: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015462C: bc1f        L_80154638
    if (!c1cs) {
        // 0x80154630: nop
    
            goto L_80154638;
    }
    // 0x80154630: nop

    // 0x80154634: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
L_80154638:
    // 0x80154638: lwc1        $f8, -0x3A40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A40);
    // 0x8015463C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154640: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80154644: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80154648: nop

    // 0x8015464C: bc1f        L_8015466C
    if (!c1cs) {
        // 0x80154650: nop
    
            goto L_8015466C;
    }
    // 0x80154650: nop

    // 0x80154654: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154658: lwc1        $f4, -0x3A3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A3C);
    // 0x8015465C: lhu         $v0, 0x56($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X56);
    // 0x80154660: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80154664: b           L_8015467C
    // 0x80154668: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
        goto L_8015467C;
    // 0x80154668: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
L_8015466C:
    // 0x8015466C: lwc1        $f6, -0x3A38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A38);
    // 0x80154670: lhu         $v0, 0x56($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X56);
    // 0x80154674: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80154678: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
L_8015467C:
    // 0x8015467C: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
L_80154680:
    // 0x80154680: beq         $t8, $zero, L_801546F0
    if (ctx->r24 == 0) {
        // 0x80154684: lwc1        $f2, 0x24($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
            goto L_801546F0;
    }
    // 0x80154684: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80154688: lwc1        $f12, 0xC0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x8015468C: lwc1        $f14, 0xBC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0XBC);
    // 0x80154690: jal         0x8001863C
    // 0x80154694: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80154694: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80154698: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015469C: lwc1        $f18, -0x3A34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A34);
    // 0x801546A0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801546A4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801546A8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x801546AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801546B0: bc1f        L_801546BC
    if (!c1cs) {
        // 0x801546B4: nop
    
            goto L_801546BC;
    }
    // 0x801546B4: nop

    // 0x801546B8: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
L_801546BC:
    // 0x801546BC: lwc1        $f8, -0x3A30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A30);
    // 0x801546C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801546C4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x801546C8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801546CC: nop

    // 0x801546D0: bc1f        L_801546E8
    if (!c1cs) {
        // 0x801546D4: nop
    
            goto L_801546E8;
    }
    // 0x801546D4: nop

    // 0x801546D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801546DC: lwc1        $f4, -0x3A2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A2C);
    // 0x801546E0: b           L_801546F0
    // 0x801546E4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
        goto L_801546F0;
    // 0x801546E4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_801546E8:
    // 0x801546E8: lwc1        $f6, -0x3A28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A28);
    // 0x801546EC: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_801546F0:
    // 0x801546F0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x801546F4: lwc1        $f8, 0xB2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB2C);
    // 0x801546F8: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x801546FC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80154700: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80154704: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80154708: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8015470C: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80154710: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80154714: jal         0x800192D0
    // 0x80154718: nop

    syVectorRotate3D(rdram, ctx);
        goto after_2;
    // 0x80154718: nop

    after_2:
    // 0x8015471C: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80154720: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80154724: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80154728: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8015472C: nop

    // 0x80154730: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80154734: mul.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80154738: jal         0x8001863C
    // 0x8015473C: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8015473C: nop

    after_3:
    // 0x80154740: swc1        $f0, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->f0.u32l;
    // 0x80154744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154748: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015474C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80154750: jr          $ra
    // 0x80154754: nop

    return;
    // 0x80154754: nop

;}
RECOMP_FUNC void func_ovl2_800FB554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB55C: jal         0x800FB04C
    // 0x800FB560: nop

    func_ovl2_800FB04C(rdram, ctx);
        goto after_0;
    // 0x800FB560: nop

    after_0:
    // 0x800FB564: jal         0x800FB2A0
    // 0x800FB568: nop

    mpCollisionInitLineTypesAll(rdram, ctx);
        goto after_1;
    // 0x800FB568: nop

    after_1:
    // 0x800FB56C: jal         0x800FB31C
    // 0x800FB570: nop

    func_ovl2_800FB31C(rdram, ctx);
        goto after_2;
    // 0x800FB570: nop

    after_2:
    // 0x800FB574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FB57C: jr          $ra
    // 0x800FB580: nop

    return;
    // 0x800FB580: nop

;}
RECOMP_FUNC void ftCommonHammerTurnCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147BA4: jal         0x8013E9D0
    // 0x80147BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80147BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80147BAC: beql        $v0, $zero, L_80147BC8
    if (ctx->r2 == 0) {
        // 0x80147BB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80147BC8;
    }
    goto skip_0;
    // 0x80147BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80147BB4: jal         0x80147B34
    // 0x80147BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerTurnSetStatus(rdram, ctx);
        goto after_1;
    // 0x80147BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80147BBC: b           L_80147BC8
    // 0x80147BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147BC8;
    // 0x80147BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80147BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147BC8:
    // 0x80147BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147BD0: jr          $ra
    // 0x80147BD4: nop

    return;
    // 0x80147BD4: nop

;}
RECOMP_FUNC void itCapsuleDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017424C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174250: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174254: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x80174258: jal         0x80172EC8
    // 0x8017425C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017425C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80174260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174268: jr          $ra
    // 0x8017426C: nop

    return;
    // 0x8017426C: nop

;}
RECOMP_FUNC void func_ovl8_80371DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80371DC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80371DC8: jr          $ra
    // 0x80371DCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80371DCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void mnMessageMakeTint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131CBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131CC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131CCC: jal         0x80009968
    // 0x80131CD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131CD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131CD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131CD8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131CDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131CE0: addiu       $a1, $a1, 0x1BA4
    ctx->r5 = ADD32(ctx->r5, 0X1BA4);
    // 0x80131CE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131CEC: jal         0x80009DF4
    // 0x80131CF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131CF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131CF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131CFC: jr          $ra
    // 0x80131D00: nop

    return;
    // 0x80131D00: nop

;}
RECOMP_FUNC void itNBumperAttachedProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BCC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017BCC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BCC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017BCCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BCD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017BCD4: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8017BCD8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017BCDC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8017BCE0: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8017BCE4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017BCE8: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8017BCEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BCF0: sh          $t7, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r15;
    // 0x8017BCF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BCF8: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x8017BCFC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8017BD00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BD04: swc1        $f4, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f4.u32l;
    // 0x8017BD08: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x8017BD0C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8017BD10: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8017BD14: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8017BD18: nop

    // 0x8017BD1C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017BD20: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017BD24: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    // 0x8017BD28: lw          $t1, 0x44($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X44);
    // 0x8017BD2C: sh          $t2, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r10;
    // 0x8017BD30: jal         0x8017279C
    // 0x8017BD34: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x8017BD34: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    after_0:
    // 0x8017BD38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BD3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BD40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017BD44: jr          $ra
    // 0x8017BD48: nop

    return;
    // 0x8017BD48: nop

;}
RECOMP_FUNC void ftBossTsutsuku1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159EC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159EC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159ECC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159ED0: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80159ED4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159ED8: jal         0x800E6F24
    // 0x80159EDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159EDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159EE8: jr          $ra
    // 0x80159EEC: nop

    return;
    // 0x80159EEC: nop

;}
RECOMP_FUNC void ftCommonTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E908: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013E90C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E910: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013E914: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E918: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8013E91C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013E920: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8013E924: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013E928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013E92C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013E930: jal         0x800E6F24
    // 0x8013E934: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013E934: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013E938: jal         0x800E0830
    // 0x8013E93C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8013E93C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013E940: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013E944: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8013E948: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x8013E94C: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x8013E950: sw          $zero, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = 0;
    // 0x8013E954: sh          $zero, 0xB20($v0)
    MEM_H(0XB20, ctx->r2) = 0;
    // 0x8013E958: beq         $v1, $zero, L_8013E968
    if (ctx->r3 == 0) {
        // 0x8013E95C: sw          $v1, 0xB24($v0)
        MEM_W(0XB24, ctx->r2) = ctx->r3;
            goto L_8013E968;
    }
    // 0x8013E95C: sw          $v1, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r3;
    // 0x8013E960: b           L_8013E96C
    // 0x8013E964: sw          $zero, 0xB2C($v0)
    MEM_W(0XB2C, ctx->r2) = 0;
        goto L_8013E96C;
    // 0x8013E964: sw          $zero, 0xB2C($v0)
    MEM_W(0XB2C, ctx->r2) = 0;
L_8013E968:
    // 0x8013E968: sw          $t6, 0xB2C($v0)
    MEM_W(0XB2C, ctx->r2) = ctx->r14;
L_8013E96C:
    // 0x8013E96C: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013E970: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8013E974: sw          $t8, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->r24;
    // 0x8013E978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013E97C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013E980: jr          $ra
    // 0x8013E984: nop

    return;
    // 0x8013E984: nop

;}
RECOMP_FUNC void func_ovl8_80372250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037225C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80372260: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80372264: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80372268: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8037226C: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80372270: lh          $t7, 0x48($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X48);
    // 0x80372274: jalr        $t9
    // 0x80372278: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372278: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_0:
    // 0x8037227C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80372280: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80372284: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80372288: jal         0x80377AEC
    // 0x8037228C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_1;
    // 0x8037228C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80372290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372298: jr          $ra
    // 0x8037229C: nop

    return;
    // 0x8037229C: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNGetChargeShotPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156EBC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80156EC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80156EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156EC8: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80156ECC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80156ED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80156ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156ED8: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80156EDC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80156EE0: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80156EE4: jal         0x800EDF24
    // 0x80156EE8: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80156EE8: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    after_0:
    // 0x80156EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156EF4: jr          $ra
    // 0x80156EF8: nop

    return;
    // 0x80156EF8: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckTimeArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801354CC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801354D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801354D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801354D8: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801354DC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801354E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801354E4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801354E8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801354EC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801354F0: nop

    // 0x801354F4: bc1t        L_80135514
    if (c1cs) {
        // 0x801354F8: nop
    
            goto L_80135514;
    }
    // 0x801354F8: nop

    // 0x801354FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135500: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135504: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80135508: nop

    // 0x8013550C: bc1f        L_8013551C
    if (!c1cs) {
        // 0x80135510: nop
    
            goto L_8013551C;
    }
    // 0x80135510: nop

L_80135514:
    // 0x80135514: b           L_8013551C
    // 0x80135518: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013551C;
    // 0x80135518: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013551C:
    // 0x8013551C: beq         $v1, $zero, L_8013552C
    if (ctx->r3 == 0) {
        // 0x80135520: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013552C;
    }
    // 0x80135520: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135524: jr          $ra
    // 0x80135528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80135528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013552C:
    // 0x8013552C: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135530: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135534: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80135538: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013553C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80135540: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135544: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013554C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80135550: nop

    // 0x80135554: bc1f        L_8013557C
    if (!c1cs) {
        // 0x80135558: nop
    
            goto L_8013557C;
    }
    // 0x80135558: nop

    // 0x8013555C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135560: nop

    // 0x80135564: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135568: nop

    // 0x8013556C: bc1f        L_8013557C
    if (!c1cs) {
        // 0x80135570: nop
    
            goto L_8013557C;
    }
    // 0x80135570: nop

    // 0x80135574: b           L_8013557C
    // 0x80135578: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013557C;
    // 0x80135578: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013557C:
    // 0x8013557C: beq         $v1, $zero, L_8013558C
    if (ctx->r3 == 0) {
        // 0x80135580: nop
    
            goto L_8013558C;
    }
    // 0x80135580: nop

    // 0x80135584: jr          $ra
    // 0x80135588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013558C:
    // 0x8013558C: jr          $ra
    // 0x80135590: nop

    return;
    // 0x80135590: nop

;}
RECOMP_FUNC void mvOpeningJungleFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D7D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018D7D8: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018D7DC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018D7E0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D7E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018D7E8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018D7EC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018D7F0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018D7F4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D7F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018D7FC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018D800: jal         0x800FCB70
    // 0x8018D804: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018D804: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018D808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D80C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D810: jr          $ra
    // 0x8018D814: nop

    return;
    // 0x8018D814: nop

;}
RECOMP_FUNC void sySchedulerExecuteTaskGfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018E0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800018E4: lw          $t6, 0x4ECC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4ECC);
    // 0x800018E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800018EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800018F0: beq         $t6, $zero, L_8000192C
    if (ctx->r14 == 0) {
        // 0x800018F4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8000192C;
    }
    // 0x800018F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800018F8: jal         0x80032920
    // 0x800018FC: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_0;
    // 0x800018FC: nop

    after_0:
    // 0x80001900: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001904: addiu       $v0, $v0, 0x4ECC
    ctx->r2 = ADD32(ctx->r2, 0X4ECC);
    // 0x80001908: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000190C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80001910: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80001914: jal         0x80000D44
    // 0x80001918: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    sySchedulerAddPausedQueue(rdram, ctx);
        goto after_1;
    // 0x80001918: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x8000191C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80001920: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80001924: b           L_80001950
    // 0x80001928: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
        goto L_80001950;
    // 0x80001928: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_8000192C:
    // 0x8000192C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80001930: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80001934: jal         0x800306CC
    // 0x80001938: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x80001938: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8000193C: jal         0x8003085C
    // 0x80001940: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x80001940: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80001944: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80001948: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000194C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
L_80001950:
    // 0x80001950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001954: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80001958: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000195C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001960: jr          $ra
    // 0x80001964: sw          $t3, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = ctx->r11;
    return;
    // 0x80001964: sw          $t3, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void mvOpeningClashMakeFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B60: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80131B64: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B68: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131B6C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80131B70: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80131B74: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80131B78: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80131B7C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80131B80: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80131B84: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80131B88: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80131B8C: addiu       $t7, $t7, 0x2908
    ctx->r15 = ADD32(ctx->r15, 0X2908);
    // 0x80131B90: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131B94: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131B98: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x80131B9C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131BA0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131BA4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131BA8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131BAC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80131BB0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131BB4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131BB8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80131BBC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80131BC0: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x80131BC4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80131BC8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80131BCC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80131BD0: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80131BD4: addiu       $t0, $t0, 0x6DD0
    ctx->r8 = ADD32(ctx->r8, 0X6DD0);
    // 0x80131BD8: addiu       $t4, $t0, 0x3C
    ctx->r12 = ADD32(ctx->r8, 0X3C);
    // 0x80131BDC: or          $t3, $s3, $zero
    ctx->r11 = ctx->r19 | 0;
    // 0x80131BE0: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80131BE4: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
L_80131BE8:
    // 0x80131BE8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80131BEC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80131BF0: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80131BF4: sw          $t2, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r10;
    // 0x80131BF8: lw          $t1, -0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X8);
    // 0x80131BFC: sw          $t1, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r9;
    // 0x80131C00: lw          $t2, -0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, -0X4);
    // 0x80131C04: bne         $t0, $t4, L_80131BE8
    if (ctx->r8 != ctx->r12) {
        // 0x80131C08: sw          $t2, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r10;
            goto L_80131BE8;
    }
    // 0x80131C08: sw          $t2, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r10;
    // 0x80131C0C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80131C10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80131C18: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80131C1C: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
    // 0x80131C20: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131C24: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80131C28: ori         $s4, $s4, 0xB
    ctx->r20 = ctx->r20 | 0XB;
    // 0x80131C2C: addiu       $s5, $s5, 0x29F8
    ctx->r21 = ADD32(ctx->r21, 0X29F8);
    // 0x80131C30: addiu       $s0, $s0, 0x29D8
    ctx->r16 = ADD32(ctx->r16, 0X29D8);
    // 0x80131C34: addiu       $s2, $sp, 0x8C
    ctx->r18 = ADD32(ctx->r29, 0X8C);
    // 0x80131C38: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_80131C3C:
    // 0x80131C3C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80131C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C44: jal         0x800EC0EC
    // 0x80131C48: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131C48: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131C4C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80131C50: sb          $v0, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r2;
    // 0x80131C54: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x80131C58: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80131C5C: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x80131C60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131C64: jal         0x800D7F3C
    // 0x80131C68: sw          $t5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r13;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131C68: sw          $t5, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r13;
    after_1:
    // 0x80131C6C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C74: jal         0x803905CC
    // 0x80131C78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131C78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80131C7C: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x80131C80: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80131C84: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80131C88: swc1        $f22, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f22.u32l;
    // 0x80131C8C: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x80131C90: swc1        $f22, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f22.u32l;
    // 0x80131C94: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x80131C98: bne         $s0, $s5, L_80131C3C
    if (ctx->r16 != ctx->r21) {
        // 0x80131C9C: swc1        $f22, 0x48($t8)
        MEM_W(0X48, ctx->r24) = ctx->f22.u32l;
            goto L_80131C3C;
    }
    // 0x80131C9C: swc1        $f22, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f22.u32l;
    // 0x80131CA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131CA4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80131CA8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80131CAC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80131CB0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80131CB4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80131CB8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80131CBC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80131CC0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80131CC4: jr          $ra
    // 0x80131CC8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80131CC8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void gcMakeGObjSPAfter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000996C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009970: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009974: jal         0x800098A4
    // 0x80009978: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcInitGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009978: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x8000997C: bne         $v0, $zero, L_8000998C
    if (ctx->r2 != 0) {
        // 0x80009980: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000998C;
    }
    // 0x80009980: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80009984: b           L_80009998
    // 0x80009988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009998;
    // 0x80009988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000998C:
    // 0x8000998C: jal         0x80007A3C
    // 0x80009990: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcLinkGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80009990: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80009994: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80009998:
    // 0x80009998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000999C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800099A0: jr          $ra
    // 0x800099A4: nop

    return;
    // 0x800099A4: nop

;}
RECOMP_FUNC void sc1PStageClearSetupBonusStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FF8: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x80132FFC: beq         $at, $zero, L_80133010
    if (ctx->r1 == 0) {
        // 0x80133000: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80133010;
    }
    // 0x80133000: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80133004: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80133008: b           L_8013303C
    // 0x8013300C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
        goto L_8013303C;
    // 0x8013300C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
L_80133010:
    // 0x80133010: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x80133014: beq         $at, $zero, L_80133030
    if (ctx->r1 == 0) {
        // 0x80133018: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80133030;
    }
    // 0x80133018: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013301C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133020: addiu       $t7, $a1, -0x20
    ctx->r15 = ADD32(ctx->r5, -0X20);
    // 0x80133024: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80133028: b           L_8013303C
    // 0x8013302C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
        goto L_8013303C;
    // 0x8013302C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_80133030:
    // 0x80133030: addiu       $t9, $a1, -0x40
    ctx->r25 = ADD32(ctx->r5, -0X40);
    // 0x80133034: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80133038: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_8013303C:
    // 0x8013303C: addiu       $t0, $sp, 0x0
    ctx->r8 = ADD32(ctx->r29, 0X0);
    // 0x80133040: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80133044: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80133048: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8013304C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80133050: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80133054: jr          $ra
    // 0x80133058: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    return;
    // 0x80133058: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void ftCommonDashSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ED00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013ED04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013ED08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013ED0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013ED10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013ED14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013ED18: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8013ED1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013ED20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013ED24: jal         0x800E6F24
    // 0x8013ED28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013ED28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013ED2C: jal         0x800E0830
    // 0x8013ED30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8013ED30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013ED34: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013ED38: addiu       $t7, $zero, 0xFE
    ctx->r15 = ADD32(0, 0XFE);
    // 0x8013ED3C: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x8013ED40: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x8013ED44: sb          $t7, 0x268($v0)
    MEM_B(0X268, ctx->r2) = ctx->r15;
    // 0x8013ED48: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x8013ED4C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8013ED50: sw          $t8, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r24;
    // 0x8013ED54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013ED58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013ED5C: jr          $ra
    // 0x8013ED60: nop

    return;
    // 0x8013ED60: nop

;}
RECOMP_FUNC void func_ovl8_80375C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375C54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80375C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375C5C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80375C60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80375C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80375C68: beq         $a2, $zero, L_80375C7C
    if (ctx->r6 == 0) {
        // 0x80375C6C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80375C7C;
    }
    // 0x80375C6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80375C70: jal         0x8000A24C
    // 0x80375C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000A24C(rdram, ctx);
        goto after_0;
    // 0x80375C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80375C78: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80375C7C:
    // 0x80375C7C: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80375C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80375C84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80375C88: beql        $a0, $zero, L_80375CAC
    if (ctx->r4 == 0) {
        // 0x80375C8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80375CAC;
    }
    goto skip_0;
    // 0x80375C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80375C90: jal         0x80009C90
    // 0x80375C94: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80009C90(rdram, ctx);
        goto after_1;
    // 0x80375C94: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80375C98: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80375C9C: addiu       $t6, $zero, -0x1FE
    ctx->r14 = ADD32(0, -0X1FE);
    // 0x80375CA0: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80375CA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80375CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80375CAC:
    // 0x80375CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80375CB0: jr          $ra
    // 0x80375CB4: nop

    return;
    // 0x80375CB4: nop

;}
RECOMP_FUNC void func_ovl8_80372844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372844: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80372848: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037284C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80372850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372854: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80372858: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037285C: bne         $a0, $zero, L_80372874
    if (ctx->r4 != 0) {
        // 0x80372860: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_80372874;
    }
    // 0x80372860: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80372864: jal         0x803717A0
    // 0x80372868: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80372868: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_0:
    // 0x8037286C: beq         $v0, $zero, L_803728F4
    if (ctx->r2 == 0) {
        // 0x80372870: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803728F4;
    }
    // 0x80372870: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80372874:
    // 0x80372874: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80372878: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x8037287C: addiu       $a1, $s0, 0x94
    ctx->r5 = ADD32(ctx->r16, 0X94);
    // 0x80372880: bnel        $t6, $zero, L_803728A4
    if (ctx->r14 != 0) {
        // 0x80372884: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_803728A4;
    }
    goto skip_0;
    // 0x80372884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80372888: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037288C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80372890: jal         0x803717E0
    // 0x80372894: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80372894: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80372898: jal         0x8037C2D0
    // 0x8037289C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037289C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x803728A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_803728A4:
    // 0x803728A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803728A8: jal         0x803751C0
    // 0x803728AC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803751C0(rdram, ctx);
        goto after_3;
    // 0x803728AC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x803728B0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803728B4: addiu       $t7, $t7, -0x71A0
    ctx->r15 = ADD32(ctx->r15, -0X71A0);
    // 0x803728B8: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x803728BC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x803728C0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803728C4: addiu       $t8, $t8, -0x70E8
    ctx->r24 = ADD32(ctx->r24, -0X70E8);
    // 0x803728C8: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x803728CC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x803728D0: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803728D4: addiu       $t0, $t0, -0x6F90
    ctx->r8 = ADD32(ctx->r8, -0X6F90);
    // 0x803728D8: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x803728DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803728E0: jal         0x80371ECC
    // 0x803728E4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_ovl8_80371ECC(rdram, ctx);
        goto after_4;
    // 0x803728E4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x803728E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803728EC: jal         0x80373308
    // 0x803728F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_ovl8_80373308(rdram, ctx);
        goto after_5;
    // 0x803728F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
L_803728F4:
    // 0x803728F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803728F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803728FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80372900: jr          $ra
    // 0x80372904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80372904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PChallengerMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131C4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131C58: jal         0x80009968
    // 0x80131C5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131C64: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131C68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131C6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131C70: addiu       $a1, $a1, 0x1B24
    ctx->r5 = ADD32(ctx->r5, 0X1B24);
    // 0x80131C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131C7C: jal         0x80009DF4
    // 0x80131C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131C84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131C88: lw          $t7, 0x27F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X27F8);
    // 0x80131C8C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131C90: addiu       $t8, $t8, 0xDB0
    ctx->r24 = ADD32(ctx->r24, 0XDB0);
    // 0x80131C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C98: jal         0x800CCFDC
    // 0x80131C9C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C9C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131CA0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CA4: lui         $at, 0x430B
    ctx->r1 = S32(0X430B << 16);
    // 0x80131CA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131CAC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80131CB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131CB4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131CB8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131CBC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131CC0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131CC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131CC8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131CCC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131CD0: lw          $t3, 0x27F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X27F8);
    // 0x80131CD4: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80131CD8: addiu       $t4, $t4, 0x968
    ctx->r12 = ADD32(ctx->r12, 0X968);
    // 0x80131CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131CE0: jal         0x800CCFDC
    // 0x80131CE4: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131CE4: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80131CE8: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CEC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80131CF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131CF4: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x80131CF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131CFC: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80131D00: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131D04: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80131D08: addiu       $t9, $zero, 0xD5
    ctx->r25 = ADD32(0, 0XD5);
    // 0x80131D0C: addiu       $t0, $zero, 0x27
    ctx->r8 = ADD32(0, 0X27);
    // 0x80131D10: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131D14: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80131D18: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131D1C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    // 0x80131D20: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131D24: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131D28: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131D2C: lw          $t1, 0x27F8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X27F8);
    // 0x80131D30: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80131D34: addiu       $t2, $t2, 0x1F8
    ctx->r10 = ADD32(ctx->r10, 0X1F8);
    // 0x80131D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D3C: jal         0x800CCFDC
    // 0x80131D40: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131D40: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80131D44: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D48: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80131D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131D50: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80131D54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131D58: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80131D5C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131D60: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80131D64: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80131D68: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80131D6C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131D70: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80131D74: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80131D78: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131D7C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131D80: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131D84: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131D88: lw          $t9, 0x27F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X27F8);
    // 0x80131D8C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131D90: addiu       $t0, $t0, 0x488
    ctx->r8 = ADD32(ctx->r8, 0X488);
    // 0x80131D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D98: jal         0x800CCFDC
    // 0x80131D9C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131D9C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x80131DA0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131DA4: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80131DA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DAC: lui         $at, 0x4315
    ctx->r1 = S32(0X4315 << 16);
    // 0x80131DB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DB4: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80131DB8: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131DBC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80131DC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80131DC4: addiu       $t6, $zero, 0xA8
    ctx->r14 = ADD32(0, 0XA8);
    // 0x80131DC8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131DCC: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80131DD0: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80131DD4: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131DD8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131DDC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131DE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131DEC: jr          $ra
    // 0x80131DF0: nop

    return;
    // 0x80131DF0: nop

;}
RECOMP_FUNC void mpCollisionCheckExistLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC680: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC684: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC688: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC68C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC690: bne         $a0, $at, L_800FC6BC
    if (ctx->r4 != ctx->r1) {
        // 0x800FC694: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC6BC;
    }
    // 0x800FC694: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC698: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC69C: addiu       $s0, $s0, 0x6FC
    ctx->r16 = ADD32(ctx->r16, 0X6FC);
    // 0x800FC6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC6A4:
    // 0x800FC6A4: jal         0x80023624
    // 0x800FC6A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FC6A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FC6AC: jal         0x800A3040
    // 0x800FC6B0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FC6B0: nop

    after_1:
    // 0x800FC6B4: b           L_800FC6A4
    // 0x800FC6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FC6A4;
    // 0x800FC6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC6BC:
    // 0x800FC6BC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FC6C0: bne         $s1, $at, L_800FC6D0
    if (ctx->r17 != ctx->r1) {
        // 0x800FC6C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FC6D0;
    }
    // 0x800FC6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC6C8: b           L_800FC71C
    // 0x800FC6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FC71C;
    // 0x800FC6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FC6D0:
    // 0x800FC6D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC6D4: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FC6D8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FC6DC: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FC6E0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FC6E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FC6E8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800FC6EC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FC6F0: lw          $t1, 0x1304($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1304);
    // 0x800FC6F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FC6F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FC6FC: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800FC700: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800FC704: lw          $t4, 0x84($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X84);
    // 0x800FC708: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800FC70C: beq         $at, $zero, L_800FC71C
    if (ctx->r1 == 0) {
        // 0x800FC710: nop
    
            goto L_800FC71C;
    }
    // 0x800FC710: nop

    // 0x800FC714: b           L_800FC71C
    // 0x800FC718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800FC71C;
    // 0x800FC718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FC71C:
    // 0x800FC71C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC720: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC724: jr          $ra
    // 0x800FC728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftDonkeyThrowFWalkProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D590: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014D594: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014D59C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014D5A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014D5A4: jal         0x80146BE0
    // 0x8014D5A8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014D5A8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014D5AC: bnel        $v0, $zero, L_8014D67C
    if (ctx->r2 != 0) {
        // 0x8014D5B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D67C;
    }
    goto skip_0;
    // 0x8014D5B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8014D5B4: jal         0x8014DFA8
    // 0x8014D5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFFCheckInterruptThrowFCommon(rdram, ctx);
        goto after_1;
    // 0x8014D5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8014D5BC: bnel        $v0, $zero, L_8014D67C
    if (ctx->r2 != 0) {
        // 0x8014D5C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D67C;
    }
    goto skip_1;
    // 0x8014D5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8014D5C4: jal         0x8014D9B8
    // 0x8014D5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFKneeBendCheckInterruptThrowFCommon(rdram, ctx);
        goto after_2;
    // 0x8014D5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8014D5CC: bnel        $v0, $zero, L_8014D67C
    if (ctx->r2 != 0) {
        // 0x8014D5D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D67C;
    }
    goto skip_2;
    // 0x8014D5D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8014D5D4: jal         0x8014DC08
    // 0x8014D5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFFallCheckInterruptPass(rdram, ctx);
        goto after_3;
    // 0x8014D5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8014D5DC: bnel        $v0, $zero, L_8014D67C
    if (ctx->r2 != 0) {
        // 0x8014D5E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D67C;
    }
    goto skip_3;
    // 0x8014D5E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8014D5E4: jal         0x8014D4EC
    // 0x8014D5E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFWaitCheckInterruptThrowFWalk(rdram, ctx);
        goto after_4;
    // 0x8014D5E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8014D5EC: bne         $v0, $zero, L_8014D678
    if (ctx->r2 != 0) {
        // 0x8014D5F0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8014D678;
    }
    // 0x8014D5F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8014D5F4: lb          $v0, 0x1C2($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X1C2);
    // 0x8014D5F8: bgez        $v0, L_8014D608
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8014D5FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8014D608;
    }
    // 0x8014D5FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014D600: b           L_8014D608
    // 0x8014D604: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8014D608;
    // 0x8014D604: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8014D608:
    // 0x8014D608: sll         $a0, $v1, 24
    ctx->r4 = S32(ctx->r3 << 24);
    // 0x8014D60C: jal         0x8013E340
    // 0x8014D610: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    ftCommonWalkGetWalkStatus(rdram, ctx);
        goto after_5;
    // 0x8014D610: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_5:
    // 0x8014D614: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8014D618: addiu       $v1, $v0, 0xE1
    ctx->r3 = ADD32(ctx->r2, 0XE1);
    // 0x8014D61C: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8014D620: beql        $v1, $a1, L_8014D67C
    if (ctx->r3 == ctx->r5) {
        // 0x8014D624: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D67C;
    }
    goto skip_4;
    // 0x8014D624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8014D628: jal         0x8014D530
    // 0x8014D62C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    ftDonkeyThrowFWalkGetWalkAnimLength(rdram, ctx);
        goto after_6;
    // 0x8014D62C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_6:
    // 0x8014D630: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8014D634: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8014D638: jal         0x8014D530
    // 0x8014D63C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    ftDonkeyThrowFWalkGetWalkAnimLength(rdram, ctx);
        goto after_7;
    // 0x8014D63C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8014D640: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8014D644: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8014D648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014D64C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8014D650: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8014D654: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8014D658: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8014D65C: nop

    // 0x8014D660: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8014D664: nop

    // 0x8014D668: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014D66C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8014D670: jal         0x8014D68C
    // 0x8014D674: nop

    ftDonkeyThrowFWalkSetStatusParam(rdram, ctx);
        goto after_8;
    // 0x8014D674: nop

    after_8:
L_8014D678:
    // 0x8014D678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014D67C:
    // 0x8014D67C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014D680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014D684: jr          $ra
    // 0x8014D688: nop

    return;
    // 0x8014D688: nop

;}
RECOMP_FUNC void itStarRodWeaponStarProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017832C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178334: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178338: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8017833C: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x80178340: jal         0x80102070
    // 0x80178344: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80178344: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80178348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017834C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80178354: jr          $ra
    // 0x80178358: nop

    return;
    // 0x80178358: nop

;}
RECOMP_FUNC void func_ovl8_8037B46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B46C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037B470: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037B474: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8037B478: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8037B47C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8037B480: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8037B484: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037B488: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037B48C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037B490: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8037B494: addiu       $s5, $zero, 0x7FFF
    ctx->r21 = ADD32(0, 0X7FFF);
    // 0x8037B498: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8037B49C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8037B4A0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8037B4A4: beq         $t6, $s5, L_8037B5D0
    if (ctx->r14 == ctx->r21) {
        // 0x8037B4A8: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8037B5D0;
    }
    // 0x8037B4A8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8037B4AC: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x8037B4B0: addiu       $s6, $sp, 0x4C
    ctx->r22 = ADD32(ctx->r29, 0X4C);
    // 0x8037B4B4: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x8037B4B8: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
L_8037B4BC:
    // 0x8037B4BC: beq         $t7, $zero, L_8037B4D8
    if (ctx->r15 == 0) {
        // 0x8037B4C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8037B4D8;
    }
    // 0x8037B4C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8037B4C4: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x8037B4C8: andi        $t9, $v1, 0x7FFF
    ctx->r25 = ctx->r3 & 0X7FFF;
    // 0x8037B4CC: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x8037B4D0: b           L_8037B4DC
    // 0x8037B4D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8037B4DC;
    // 0x8037B4D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8037B4D8:
    // 0x8037B4D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037B4DC:
    // 0x8037B4DC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8037B4E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8037B4E4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8037B4E8: sh          $t1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r9;
    // 0x8037B4EC: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8037B4F0: andi        $t2, $v1, 0x8000
    ctx->r10 = ctx->r3 & 0X8000;
    // 0x8037B4F4: beq         $t2, $zero, L_8037B510
    if (ctx->r10 == 0) {
        // 0x8037B4F8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8037B510;
    }
    // 0x8037B4F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037B4FC: lhu         $t3, 0x6($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6);
    // 0x8037B500: andi        $t4, $v1, 0x7FFF
    ctx->r12 = ctx->r3 & 0X7FFF;
    // 0x8037B504: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x8037B508: b           L_8037B510
    // 0x8037B50C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8037B510;
    // 0x8037B50C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8037B510:
    // 0x8037B510: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8037B514: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8037B518: sh          $t6, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r14;
    // 0x8037B51C: lh          $v1, 0x4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4);
    // 0x8037B520: lh          $t5, 0x4C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4C);
    // 0x8037B524: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x8037B528: beq         $t7, $zero, L_8037B544
    if (ctx->r15 == 0) {
        // 0x8037B52C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8037B544;
    }
    // 0x8037B52C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037B530: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x8037B534: andi        $t9, $v1, 0x7FFF
    ctx->r25 = ctx->r3 & 0X7FFF;
    // 0x8037B538: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x8037B53C: b           L_8037B544
    // 0x8037B540: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8037B544;
    // 0x8037B540: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8037B544:
    // 0x8037B544: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8037B548: lh          $v1, 0x6($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6);
    // 0x8037B54C: addu        $a3, $t0, $v0
    ctx->r7 = ADD32(ctx->r8, ctx->r2);
    // 0x8037B550: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037B554: andi        $t1, $v1, 0x8000
    ctx->r9 = ctx->r3 & 0X8000;
    // 0x8037B558: beq         $t1, $zero, L_8037B574
    if (ctx->r9 == 0) {
        // 0x8037B55C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_8037B574;
    }
    // 0x8037B55C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8037B560: lhu         $t2, 0x6($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6);
    // 0x8037B564: andi        $t3, $v1, 0x7FFF
    ctx->r11 = ctx->r3 & 0X7FFF;
    // 0x8037B568: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x8037B56C: b           L_8037B578
    // 0x8037B570: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8037B578;
    // 0x8037B570: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8037B574:
    // 0x8037B574: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037B578:
    // 0x8037B578: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x8037B57C: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8037B580: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x8037B584: addu        $v1, $t4, $v0
    ctx->r3 = ADD32(ctx->r12, ctx->r2);
    // 0x8037B588: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037B58C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037B590: subu        $t9, $v1, $t8
    ctx->r25 = SUB32(ctx->r3, ctx->r24);
    // 0x8037B594: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8037B598: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8037B59C: sh          $t7, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r15;
    // 0x8037B5A0: sh          $t0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r8;
    // 0x8037B5A4: jal         0x80376EE0
    // 0x8037B5A8: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    func_ovl8_80376EE0(rdram, ctx);
        goto after_0;
    // 0x8037B5A8: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    after_0:
    // 0x8037B5AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8037B5B0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8037B5B4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8037B5B8: jal         0x80377AEC
    // 0x8037B5BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_1;
    // 0x8037B5BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8037B5C0: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x8037B5C4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8037B5C8: bnel        $v1, $s5, L_8037B4BC
    if (ctx->r3 != ctx->r21) {
        // 0x8037B5CC: andi        $t7, $v1, 0x8000
        ctx->r15 = ctx->r3 & 0X8000;
            goto L_8037B4BC;
    }
    goto skip_0;
    // 0x8037B5CC: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    skip_0:
L_8037B5D0:
    // 0x8037B5D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8037B5D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037B5D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037B5DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037B5E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8037B5E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8037B5E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8037B5EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8037B5F0: jr          $ra
    // 0x8037B5F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8037B5F4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftKirbySpecialNCopySwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162EC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162ECC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162ED0: jal         0x800DEEC8
    // 0x80162ED4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162ED4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162ED8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162EDC: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162EE0: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    // 0x80162EE4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162EE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162EEC: jal         0x800E6F24
    // 0x80162EF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162EF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162EF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162EF8: jal         0x800E8098
    // 0x80162EFC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162EFC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162F04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162F08: jr          $ra
    // 0x80162F0C: nop

    return;
    // 0x80162F0C: nop

;}
RECOMP_FUNC void mpCommonCheckFighterCeilHeavy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE8B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE8BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE8C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE8C4: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE8C8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800DE8CC: jal         0x800DA034
    // 0x800DE8D0: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE8D0: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE8DC: jr          $ra
    // 0x800DE8E0: nop

    return;
    // 0x800DE8E0: nop

;}
RECOMP_FUNC void sc1PTrainingModeDamageDisplayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E138: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E13C: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E140: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8018E144: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E148: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E14C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E150: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E154: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E15C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E160: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018E16C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018E170: lw          $a1, 0x70($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X70);
    // 0x8018E174: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x8018E178: bne         $at, $zero, L_8018E184
    if (ctx->r1 != 0) {
        // 0x8018E17C: nop
    
            goto L_8018E184;
    }
    // 0x8018E17C: nop

    // 0x8018E180: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
L_8018E184:
    // 0x8018E184: bnel        $a1, $zero, L_8018E1BC
    if (ctx->r5 != 0) {
        // 0x8018E188: lw          $t4, 0x4($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X4);
            goto L_8018E1BC;
    }
    goto skip_0;
    // 0x8018E188: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8018E18C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8018E190: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x8018E194: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018E198: beql        $t0, $zero, L_8018E1AC
    if (ctx->r8 == 0) {
        // 0x8018E19C: lbu         $t2, 0xD0($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0XD0);
            goto L_8018E1AC;
    }
    goto skip_1;
    // 0x8018E19C: lbu         $t2, 0xD0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XD0);
    skip_1:
    // 0x8018E1A0: sb          $t1, 0xD0($v0)
    MEM_B(0XD0, ctx->r2) = ctx->r9;
    // 0x8018E1A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018E1A8: lbu         $t2, 0xD0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XD0);
L_8018E1AC:
    // 0x8018E1AC: bnel        $t2, $zero, L_8018E1BC
    if (ctx->r10 != 0) {
        // 0x8018E1B0: lw          $t4, 0x4($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X4);
            goto L_8018E1BC;
    }
    goto skip_2;
    // 0x8018E1B0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x8018E1B4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018E1B8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
L_8018E1BC:
    // 0x8018E1BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8018E1C0: beq         $a1, $t4, L_8018E1E0
    if (ctx->r5 == ctx->r12) {
        // 0x8018E1C4: nop
    
            goto L_8018E1E0;
    }
    // 0x8018E1C4: nop

    // 0x8018E1C8: jal         0x8018E014
    // 0x8018E1CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sc1PTrainingModeUpdateDamageDisplay(rdram, ctx);
        goto after_0;
    // 0x8018E1CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018E1D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E1D4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E1D8: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E1DC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
L_8018E1E0:
    // 0x8018E1E0: jal         0x800CCF00
    // 0x8018E1E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x8018E1E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8018E1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E1EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E1F0: jr          $ra
    // 0x8018E1F4: nop

    return;
    // 0x8018E1F4: nop

;}
RECOMP_FUNC void itGShellThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178ACC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80178AD0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80178AD4: addiu       $a3, $a3, -0x76F0
    ctx->r7 = ADD32(ctx->r7, -0X76F0);
    // 0x80178AD8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80178ADC: jal         0x80173C68
    // 0x80178AE0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckLanding(rdram, ctx);
        goto after_0;
    // 0x80178AE0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80178AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178AF0: jr          $ra
    // 0x80178AF4: nop

    return;
    // 0x80178AF4: nop

;}
RECOMP_FUNC void ftBossYubideppou1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A374: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015A378: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A37C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015A380: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A384: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8015A388: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A38C: jal         0x800E6F24
    // 0x8015A390: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A390: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A394: jal         0x80158030
    // 0x8015A398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftBossCommonCheckPlayerInvertLR(rdram, ctx);
        goto after_1;
    // 0x8015A398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015A39C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8015A3A0: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015A3A4: sh          $zero, 0xB1A($v0)
    MEM_H(0XB1A, ctx->r2) = 0;
    // 0x8015A3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A3AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015A3B0: jr          $ra
    // 0x8015A3B4: nop

    return;
    // 0x8015A3B4: nop

;}
RECOMP_FUNC void func_ovl2_800ED490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED490: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED494: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED498: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED49C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED4A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED4A4: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED4A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800ED4AC: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED4B0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800ED4B4: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED4B8: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800ED4BC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800ED4C0: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED4C4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED4C8: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED4CC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED4D0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800ED4D4: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED4D8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800ED4DC: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED4E0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800ED4E4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800ED4E8: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800ED4EC: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800ED4F0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED4F4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED4F8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED4FC: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED500: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800ED504: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED508: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800ED50C: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED510: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800ED514: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800ED518: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800ED51C: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800ED520: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED524: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ED528: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED52C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ED530: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800ED534: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ED538: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800ED53C: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED540: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800ED544: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800ED548: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ED54C: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800ED550: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED554: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ED558: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED55C: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ED560: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800ED564: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ED568: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED56C: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED570: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ED574: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800ED578: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ED57C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800ED580: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED584: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ED588: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED58C: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ED590: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED594: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ED598: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800ED59C: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED5A0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800ED5A4: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED5A8: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800ED5AC: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x800ED5B0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED5B4: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800ED5B8: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED5BC: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800ED5C0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800ED5C4: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800ED5C8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800ED5CC: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED5D0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800ED5D4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800ED5D8: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800ED5DC: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x800ED5E0: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED5E4: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800ED5E8: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED5EC: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800ED5F0: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800ED5F4: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800ED5F8: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800ED5FC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED600: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800ED604: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800ED608: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800ED60C: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x800ED610: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED614: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800ED618: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED61C: lwc1        $f8, 0x24($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800ED620: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800ED624: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800ED628: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800ED62C: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED630: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800ED634: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800ED638: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ED63C: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x800ED640: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800ED644: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED648: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800ED64C: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED650: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800ED654: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED658: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED65C: lwc1        $f8, 0x38($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800ED660: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ED664: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800ED668: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800ED66C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800ED670: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800ED674: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800ED678: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800ED67C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED680: lwc1        $f18, 0x34($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800ED684: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED688: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800ED68C: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED690: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800ED694: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800ED698: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800ED69C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800ED6A0: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800ED6A4: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED6A8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800ED6AC: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    // 0x800ED6B0: lwc1        $f8, 0x30($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800ED6B4: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED6B8: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800ED6BC: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED6C0: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800ED6C4: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED6C8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800ED6CC: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800ED6D0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800ED6D4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ED6D8: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800ED6DC: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800ED6E0: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ED6E4: jr          $ra
    // 0x800ED6E8: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800ED6E8: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void ftNessSpecialAirHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015445C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80154460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154464: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80154468: jal         0x800DE80C
    // 0x8015446C: addiu       $a1, $a1, 0x4480
    ctx->r5 = ADD32(ctx->r5, 0X4480);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015446C: addiu       $a1, $a1, 0x4480
    ctx->r5 = ADD32(ctx->r5, 0X4480);
    after_0:
    // 0x80154470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80154478: jr          $ra
    // 0x8015447C: nop

    return;
    // 0x8015447C: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801527B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801527B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801527B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801527BC: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x801527C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801527C4: bne         $t7, $zero, L_801527D4
    if (ctx->r15 != 0) {
        // 0x801527C8: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_801527D4;
    }
    // 0x801527C8: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x801527CC: jal         0x80152E48
    // 0x801527D0: nop

    ftPikachuSpecialHiSetStatus(rdram, ctx);
        goto after_0;
    // 0x801527D0: nop

    after_0:
L_801527D4:
    // 0x801527D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801527D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801527DC: jr          $ra
    // 0x801527E0: nop

    return;
    // 0x801527E0: nop

;}
RECOMP_FUNC void gmCollisionGetItemAttackFighterDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F0E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0E10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F0E14: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800F0E18: jal         0x800F095C
    // 0x800F0E1C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0E1C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800F0E20: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0E24: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800F0E28: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800F0E2C: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x800F0E30: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x800F0E34: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800F0E38: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x800F0E3C: addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    // 0x800F0E40: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800F0E44: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x800F0E48: jal         0x800ED3C0
    // 0x800F0E4C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0E4C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    after_1:
    // 0x800F0E50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800F0E54: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800F0E58: jal         0x800F0A48
    // 0x800F0E5C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0E5C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800F0E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0E64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F0E68: jr          $ra
    // 0x800F0E6C: nop

    return;
    // 0x800F0E6C: nop

;}
RECOMP_FUNC void ftPhysicsAddClampAirVelY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8D34: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8D38: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8D3C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D8D40: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800D8D44: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x800D8D48: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8D4C: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800D8D50: nop

    // 0x800D8D54: bc1f        L_800D8D60
    if (!c1cs) {
        // 0x800D8D58: nop
    
            goto L_800D8D60;
    }
    // 0x800D8D58: nop

    // 0x800D8D5C: swc1        $f14, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f14.u32l;
L_800D8D60:
    // 0x800D8D60: jr          $ra
    // 0x800D8D64: nop

    return;
    // 0x800D8D64: nop

;}
RECOMP_FUNC void mpCollisionAllocLinesGetCountTotal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC09C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800FC0A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC0A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC0A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FC0AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FC0B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC0B4: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x800FC0B8: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
L_800FC0BC:
    // 0x800FC0BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800FC0C0: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800FC0C4: bne         $at, $zero, L_800FC0BC
    if (ctx->r1 != 0) {
        // 0x800FC0C8: sw          $zero, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = 0;
            goto L_800FC0BC;
    }
    // 0x800FC0C8: sw          $zero, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = 0;
    // 0x800FC0CC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FC0D0: lw          $a2, 0x1368($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1368);
    // 0x800FC0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FC0D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800FC0DC: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800FC0E0: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x800FC0E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC0E8: blez        $t6, L_800FC14C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FC0EC: lw          $a1, 0x10($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X10);
            goto L_800FC14C;
    }
    // 0x800FC0EC: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x800FC0F0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_800FC0F4:
    // 0x800FC0F4: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x800FC0F8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800FC0FC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800FC100: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800FC104: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800FC108: lhu         $t1, 0x8($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X8);
    // 0x800FC10C: addiu       $v0, $a1, 0xE
    ctx->r2 = ADD32(ctx->r5, 0XE);
    // 0x800FC110: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800FC114: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800FC118: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800FC11C: lhu         $t4, 0xC($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0XC);
    // 0x800FC120: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800FC124: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x800FC128: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800FC12C: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800FC130: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800FC134: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FC138: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800FC13C: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800FC140: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800FC144: bnel        $at, $zero, L_800FC0F4
    if (ctx->r1 != 0) {
        // 0x800FC148: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_800FC0F4;
    }
    goto skip_0;
    // 0x800FC148: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_800FC14C:
    // 0x800FC14C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800FC150: addiu       $s3, $s3, 0x1368
    ctx->r19 = ADD32(ctx->r19, 0X1368);
    // 0x800FC154: addiu       $s0, $s0, 0x1348
    ctx->r16 = ADD32(ctx->r16, 0X1348);
L_800FC158:
    // 0x800FC158: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800FC15C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FC160: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800FC164: beq         $v0, $zero, L_800FC178
    if (ctx->r2 == 0) {
        // 0x800FC168: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_800FC178;
    }
    // 0x800FC168: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x800FC16C: jal         0x80004980
    // 0x800FC170: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800FC170: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    after_0:
    // 0x800FC174: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800FC178:
    // 0x800FC178: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800FC17C: bne         $s0, $s3, L_800FC158
    if (ctx->r16 != ctx->r19) {
        // 0x800FC180: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800FC158;
    }
    // 0x800FC180: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800FC184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FC188: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800FC18C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC190: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC194: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC198: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FC19C: jr          $ra
    // 0x800FC1A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800FC1A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftParamResetModelPartAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8ECC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E8ED0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E8ED4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800E8ED8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800E8EDC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E8EE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E8EE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E8EE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E8EEC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E8EF0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E8EF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E8EF8: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800E8EFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E8F00: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E8F04: lw          $fp, 0x9C8($s2)
    ctx->r30 = MEM_W(ctx->r18, 0X9C8);
    // 0x800E8F08: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x800E8F0C: lw          $s7, 0x2D4($fp)
    ctx->r23 = MEM_W(ctx->r30, 0X2D4);
L_800E8F10:
    // 0x800E8F10: lw          $s1, 0x8F8($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X8F8);
    // 0x800E8F14: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800E8F18: addu        $v0, $s2, $t6
    ctx->r2 = ADD32(ctx->r18, ctx->r14);
    // 0x800E8F1C: beql        $s1, $zero, L_800E90AC
    if (ctx->r17 == 0) {
        // 0x800E8F20: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800E90AC;
    }
    goto skip_0;
    // 0x800E8F20: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x800E8F24: lb          $t7, 0x97C($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X97C);
    // 0x800E8F28: lb          $t8, 0x97D($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X97D);
    // 0x800E8F2C: addiu       $s0, $v0, 0x97C
    ctx->r16 = ADD32(ctx->r2, 0X97C);
    // 0x800E8F30: beql        $t7, $t8, L_800E90AC
    if (ctx->r15 == ctx->r24) {
        // 0x800E8F34: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800E90AC;
    }
    goto skip_1;
    // 0x800E8F34: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x800E8F38: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x800E8F3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E8F40: jal         0x800091F4
    // 0x800E8F44: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x800E8F44: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
    after_0:
    // 0x800E8F48: lb          $v1, 0x1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1);
    // 0x800E8F4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E8F50: bnel        $v1, $at, L_800E8F64
    if (ctx->r3 != ctx->r1) {
        // 0x800E8F54: lw          $t0, 0x328($fp)
        ctx->r8 = MEM_W(ctx->r30, 0X328);
            goto L_800E8F64;
    }
    goto skip_2;
    // 0x800E8F54: lw          $t0, 0x328($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X328);
    skip_2:
    // 0x800E8F58: b           L_800E90A8
    // 0x800E8F5C: sw          $zero, 0x50($s1)
    MEM_W(0X50, ctx->r17) = 0;
        goto L_800E90A8;
    // 0x800E8F5C: sw          $zero, 0x50($s1)
    MEM_W(0X50, ctx->r17) = 0;
    // 0x800E8F60: lw          $t0, 0x328($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X328);
L_800E8F64:
    // 0x800E8F64: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x800E8F68: subu        $a0, $a0, $s3
    ctx->r4 = SUB32(ctx->r4, ctx->r19);
    // 0x800E8F6C: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x800E8F70: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800E8F74: lw          $s5, 0x84($s1)
    ctx->r21 = MEM_W(ctx->r17, 0X84);
    // 0x800E8F78: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x800E8F7C: beq         $v0, $zero, L_800E8FF4
    if (ctx->r2 == 0) {
        // 0x800E8F80: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_800E8FF4;
    }
    // 0x800E8F80: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800E8F84: lbu         $t4, 0xE($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XE);
    // 0x800E8F88: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x800E8F8C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800E8F90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800E8F94: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800E8F98: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800E8F9C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800E8FA0: addu        $s0, $t3, $t5
    ctx->r16 = ADD32(ctx->r11, ctx->r13);
    // 0x800E8FA4: lw          $t6, -0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X14);
    // 0x800E8FA8: addiu       $s0, $s0, -0x14
    ctx->r16 = ADD32(ctx->r16, -0X14);
    // 0x800E8FAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E8FB0: sw          $t6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r14;
    // 0x800E8FB4: lbu         $t7, 0x10($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X10);
    // 0x800E8FB8: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x800E8FBC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800E8FC0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800E8FC4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800E8FC8: bgez        $t7, L_800E8FE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800E8FCC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800E8FE0;
    }
    // 0x800E8FCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E8FD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E8FD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E8FD8: nop

    // 0x800E8FDC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800E8FE0:
    // 0x800E8FE0: jal         0x800C8CB8
    // 0x800E8FE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_1;
    // 0x800E8FE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800E8FE8: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x800E8FEC: b           L_800E90A8
    // 0x800E8FF0: sb          $t8, 0xC($s5)
    MEM_B(0XC, ctx->r21) = ctx->r24;
        goto L_800E90A8;
    // 0x800E8FF0: sb          $t8, 0xC($s5)
    MEM_B(0XC, ctx->r21) = ctx->r24;
L_800E8FF4:
    // 0x800E8FF4: lbu         $t9, 0xE($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XE);
    // 0x800E8FF8: subu        $a0, $a0, $s3
    ctx->r4 = SUB32(ctx->r4, ctx->r19);
    // 0x800E8FFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E9000: beq         $t9, $at, L_800E9020
    if (ctx->r25 == ctx->r1) {
        // 0x800E9004: sll         $a0, $a0, 2
        ctx->r4 = S32(ctx->r4 << 2);
            goto L_800E9020;
    }
    // 0x800E9004: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800E9008: lw          $t0, 0x10($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X10);
    // 0x800E900C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E9010: addu        $t1, $t0, $a0
    ctx->r9 = ADD32(ctx->r8, ctx->r4);
    // 0x800E9014: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800E9018: bne         $t2, $zero, L_800E9028
    if (ctx->r10 != 0) {
        // 0x800E901C: nop
    
            goto L_800E9028;
    }
    // 0x800E901C: nop

L_800E9020:
    // 0x800E9020: b           L_800E9028
    // 0x800E9024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E9028;
    // 0x800E9024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E9028:
    // 0x800E9028: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x800E902C: addu        $s0, $s7, $t4
    ctx->r16 = ADD32(ctx->r23, ctx->r12);
    // 0x800E9030: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800E9034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E9038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E903C: addu        $t5, $t3, $a0
    ctx->r13 = ADD32(ctx->r11, ctx->r4);
    // 0x800E9040: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800E9044: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E9048: sw          $t6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r14;
    // 0x800E904C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800E9050: beq         $v1, $zero, L_800E9060
    if (ctx->r3 == 0) {
        // 0x800E9054: addu        $t7, $v1, $s4
        ctx->r15 = ADD32(ctx->r3, ctx->r20);
            goto L_800E9060;
    }
    // 0x800E9054: addu        $t7, $v1, $s4
    ctx->r15 = ADD32(ctx->r3, ctx->r20);
    // 0x800E9058: b           L_800E9060
    // 0x800E905C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
        goto L_800E9060;
    // 0x800E905C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
L_800E9060:
    // 0x800E9060: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800E9064: beq         $v0, $zero, L_800E9074
    if (ctx->r2 == 0) {
        // 0x800E9068: addu        $t8, $v0, $s4
        ctx->r24 = ADD32(ctx->r2, ctx->r20);
            goto L_800E9074;
    }
    // 0x800E9068: addu        $t8, $v0, $s4
    ctx->r24 = ADD32(ctx->r2, ctx->r20);
    // 0x800E906C: b           L_800E9074
    // 0x800E9070: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
        goto L_800E9074;
    // 0x800E9070: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
L_800E9074:
    // 0x800E9074: lbu         $t9, 0x10($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X10);
    // 0x800E9078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E907C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E9080: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800E9084: bgez        $t9, L_800E9098
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E9088: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800E9098;
    }
    // 0x800E9088: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E908C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E9090: nop

    // 0x800E9094: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800E9098:
    // 0x800E9098: jal         0x800C8CB8
    // 0x800E909C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_2;
    // 0x800E909C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800E90A0: lbu         $t0, 0xC($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XC);
    // 0x800E90A4: sb          $t0, 0xC($s5)
    MEM_B(0XC, ctx->r21) = ctx->r8;
L_800E90A8:
    // 0x800E90A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800E90AC:
    // 0x800E90AC: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x800E90B0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800E90B4: bne         $s3, $at, L_800E8F10
    if (ctx->r19 != ctx->r1) {
        // 0x800E90B8: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800E8F10;
    }
    // 0x800E90B8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800E90BC: lbu         $t1, 0x18C($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X18C);
    // 0x800E90C0: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x800E90C4: sb          $t2, 0x18C($s2)
    MEM_B(0X18C, ctx->r18) = ctx->r10;
    // 0x800E90C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E90CC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800E90D0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800E90D4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E90D8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E90DC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E90E0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E90E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E90E8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E90EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E90F0: jr          $ra
    // 0x800E90F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E90F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnVSOptionsMakeUnderline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013330C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133310: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133314: jal         0x80009968
    // 0x80133318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013331C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133320: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133324: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133328: addiu       $a1, $a1, 0x2F2C
    ctx->r5 = ADD32(ctx->r5, 0X2F2C);
    // 0x8013332C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133334: jal         0x80009DF4
    // 0x80133338: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133338: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013333C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133344: jr          $ra
    // 0x80133348: nop

    return;
    // 0x80133348: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPortraitAddCross(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132228: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013222C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132230: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132234: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132238: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013223C: lw          $t6, 0x7E08($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E08);
    // 0x80132240: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132244: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132248: addiu       $t7, $t7, 0x2B8
    ctx->r15 = ADD32(ctx->r15, 0X2B8);
    // 0x8013224C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80132250: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80132254: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80132258: jal         0x800CCFDC
    // 0x8013225C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8013225C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80132260: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132264: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132268: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8013226C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80132270: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132274: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132278: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8013227C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132280: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132284: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80132288: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x8013228C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132290: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80132294: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132298: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013229C: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801322A0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801322A4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801322A8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801322AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801322B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801322B4: jr          $ra
    // 0x801322B8: nop

    return;
    // 0x801322B8: nop

;}
RECOMP_FUNC void unref_80006B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006B48: beq         $a0, $at, L_80006B58
    if (ctx->r4 == ctx->r1) {
        // 0x80006B4C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80006B58;
    }
    // 0x80006B4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80006B50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006B54: bne         $a0, $at, L_80006B74
    if (ctx->r4 != ctx->r1) {
        // 0x80006B58: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_80006B74;
    }
L_80006B58:
    // 0x80006B58: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80006B5C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80006B60: lw          $t7, 0x6634($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6634);
    // 0x80006B64: bnel        $t7, $zero, L_80006B78
    if (ctx->r15 != 0) {
        // 0x80006B68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006B78;
    }
    goto skip_0;
    // 0x80006B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80006B6C: jr          $ra
    // 0x80006B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006B74:
    // 0x80006B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006B78:
    // 0x80006B78: jr          $ra
    // 0x80006B7C: nop

    return;
    // 0x80006B7C: nop

;}
RECOMP_FUNC void itEggFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801815C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801815C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801815C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801815CC: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x801815D0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801815D4: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x801815D8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801815DC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801815E0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x801815E4: jal         0x80172558
    // 0x801815E8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801815E8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x801815EC: jal         0x801713F4
    // 0x801815F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x801815F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801815F4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801815F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801815FC: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80181600: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x80181604: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    // 0x80181608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018160C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181610: jr          $ra
    // 0x80181614: nop

    return;
    // 0x80181614: nop

;}

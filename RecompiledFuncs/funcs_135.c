#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_803838B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803838B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803838BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803838C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803838C4: lh          $a1, 0x42($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X42);
    // 0x803838C8: jal         0x8037B7F0
    // 0x803838CC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_ovl8_8037B7F0(rdram, ctx);
        goto after_0;
    // 0x803838CC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x803838D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803838D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803838D8: jr          $ra
    // 0x803838DC: nop

    return;
    // 0x803838DC: nop

;}
RECOMP_FUNC void func_ovl8_80382D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80382D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80382D5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80382D60: jal         0x803817C0
    // 0x80382D64: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_ovl8_803817C0(rdram, ctx);
        goto after_0;
    // 0x80382D64: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x80382D68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80382D6C: jal         0x80373694
    // 0x80382D70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_80373694(rdram, ctx);
        goto after_1;
    // 0x80382D70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80382D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80382D7C: jr          $ra
    // 0x80382D80: nop

    return;
    // 0x80382D80: nop

;}
RECOMP_FUNC void itNBumperThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B7DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B7E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8017B7E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B7EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B7F0: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8017B7F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B7F8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8017B7FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B800: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017B804: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8017B808: sh          $t6, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r14;
    // 0x8017B80C: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x8017B810: jal         0x80172EC8
    // 0x8017B814: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017B814: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x8017B818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B81C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B820: jr          $ra
    // 0x8017B824: nop

    return;
    // 0x8017B824: nop

;}
RECOMP_FUNC void mn1PModeMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801327D4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801327D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801327DC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801327E0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801327E4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801327E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801327EC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801327F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801327F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801327F8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801327FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132800: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132804: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132808: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013280C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132810: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132814: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132818: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013281C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132828: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013282C: jal         0x8000B93C
    // 0x80132830: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132830: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132834: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132838: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013283C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132840: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132844: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132848: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013284C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132850: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132854: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132858: jal         0x80007080
    // 0x8013285C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013285C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132860: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132864: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132868: jr          $ra
    // 0x8013286C: nop

    return;
    // 0x8013286C: nop

;}
RECOMP_FUNC void ftMarioSpecialHiProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801560F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801560F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801560FC: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80156100: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x80156104: bnel        $t6, $zero, L_801561D0
    if (ctx->r14 != 0) {
        // 0x80156108: lw          $t8, 0x184($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X184);
            goto L_801561D0;
    }
    goto skip_0;
    // 0x80156108: lw          $t8, 0x184($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X184);
    skip_0:
    // 0x8015610C: lb          $v1, 0x1C2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C2);
    // 0x80156110: bgez        $v1, L_80156120
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80156114: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80156120;
    }
    // 0x80156114: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80156118: b           L_80156120
    // 0x8015611C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_80156120;
    // 0x8015611C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80156120:
    // 0x80156120: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80156124: bnel        $at, $zero, L_801561D0
    if (ctx->r1 != 0) {
        // 0x80156128: lw          $t8, 0x184($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X184);
            goto L_801561D0;
    }
    goto skip_1;
    // 0x80156128: lw          $t8, 0x184($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X184);
    skip_1:
    // 0x8015612C: blez        $v1, L_8015613C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80156130: addiu       $v0, $zero, -0x32
        ctx->r2 = ADD32(0, -0X32);
            goto L_8015613C;
    }
    // 0x80156130: addiu       $v0, $zero, -0x32
    ctx->r2 = ADD32(0, -0X32);
    // 0x80156134: b           L_8015613C
    // 0x80156138: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_8015613C;
    // 0x80156138: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_8015613C:
    // 0x8015613C: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x80156140: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80156144: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80156148: lwc1        $f8, -0x397C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X397C);
    // 0x8015614C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80156150: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80156154: lwc1        $f10, -0x3978($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3978);
    // 0x80156158: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8015615C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80156160: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80156164: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80156168: nop

    // 0x8015616C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80156170: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80156174: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80156178: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015617C: nop

    // 0x80156180: bc1f        L_80156190
    if (!c1cs) {
        // 0x80156184: nop
    
            goto L_80156190;
    }
    // 0x80156184: nop

    // 0x80156188: b           L_80156194
    // 0x8015618C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
        goto L_80156194;
    // 0x8015618C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
L_80156190:
    // 0x80156190: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80156194:
    // 0x80156194: lw          $v0, 0x8EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8EC);
    // 0x80156198: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8015619C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801561A0: nop

    // 0x801561A4: bc1fl       L_801561B8
    if (!c1cs) {
        // 0x801561A8: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_801561B8;
    }
    goto skip_2;
    // 0x801561A8: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x801561AC: b           L_801561B8
    // 0x801561B0: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
        goto L_801561B8;
    // 0x801561B0: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x801561B4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_801561B8:
    // 0x801561B8: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x801561BC: nop

    // 0x801561C0: bc1fl       L_801561D0
    if (!c1cs) {
        // 0x801561C4: lw          $t8, 0x184($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X184);
            goto L_801561D0;
    }
    goto skip_3;
    // 0x801561C4: lw          $t8, 0x184($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X184);
    skip_3:
    // 0x801561C8: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x801561CC: lw          $t8, 0x184($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X184);
L_801561D0:
    // 0x801561D0: beql        $t8, $zero, L_80156234
    if (ctx->r24 == 0) {
        // 0x801561D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156234;
    }
    goto skip_4;
    // 0x801561D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801561D8: lb          $v1, 0x1C2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C2);
    // 0x801561DC: sw          $zero, 0x184($a1)
    MEM_W(0X184, ctx->r5) = 0;
    // 0x801561E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801561E4: bgez        $v1, L_801561F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801561E8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801561F4;
    }
    // 0x801561E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801561EC: b           L_801561F4
    // 0x801561F0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801561F4;
    // 0x801561F0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801561F4:
    // 0x801561F4: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x801561F8: bnel        $at, $zero, L_80156234
    if (ctx->r1 != 0) {
        // 0x801561FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156234;
    }
    goto skip_5;
    // 0x801561FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80156200: jal         0x800E8044
    // 0x80156204: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamSetStickLR(rdram, ctx);
        goto after_0;
    // 0x80156204: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80156208: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015620C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80156210: lwc1        $f8, -0x3974($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3974);
    // 0x80156214: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x80156218: lw          $t0, 0x8E8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8E8);
    // 0x8015621C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80156220: nop

    // 0x80156224: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80156228: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015622C: swc1        $f10, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f10.u32l;
    // 0x80156230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156234:
    // 0x80156234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156238: jr          $ra
    // 0x8015623C: nop

    return;
    // 0x8015623C: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801329D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801329D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801329DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801329E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801329E4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801329E8: jal         0x80009968
    // 0x801329EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801329EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801329F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801329F8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801329FC: sw          $v0, 0x4314($at)
    MEM_W(0X4314, ctx->r1) = ctx->r2;
    // 0x80132A00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132A04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A08: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A10: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132A14: jal         0x80009DF4
    // 0x80132A18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132A18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132A1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A20: addiu       $a1, $a1, 0x29AC
    ctx->r5 = ADD32(ctx->r5, 0X29AC);
    // 0x80132A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132A2C: jal         0x80008188
    // 0x80132A30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132A30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132A34: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132A38: lw          $t7, 0x4528($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4528);
    // 0x80132A3C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132A40: addiu       $t8, $t8, 0x1E08
    ctx->r24 = ADD32(ctx->r24, 0X1E08);
    // 0x80132A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A48: jal         0x800CCFDC
    // 0x80132A4C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132A4C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132A50: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132A54: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80132A58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132A5C: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80132A60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132A64: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132A68: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132A6C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132A70: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132A74: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132A78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132A7C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132A80: lw          $t3, 0x4528($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4528);
    // 0x80132A84: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132A88: addiu       $t4, $t4, 0x2318
    ctx->r12 = ADD32(ctx->r12, 0X2318);
    // 0x80132A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A90: jal         0x800CCFDC
    // 0x80132A94: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132A94: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x80132A98: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80132A9C: lui         $at, 0x433D
    ctx->r1 = S32(0X433D << 16);
    // 0x80132AA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132AA4: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80132AA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132AAC: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80132AB0: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132AB4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80132AB8: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132ABC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132AC0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132AC4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132AC8: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    // 0x80132ACC: jal         0x801328D8
    // 0x80132AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MN1PContinueOptionSetHighlightColors(rdram, ctx);
        goto after_5;
    // 0x80132AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80132AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132AD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132ADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132AE0: jr          $ra
    // 0x80132AE4: nop

    return;
    // 0x80132AE4: nop

;}
RECOMP_FUNC void syMatrixOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B1E4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001B1E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001B1EC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B1F0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001B1F4: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B1F8: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001B1FC: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001B200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001B204: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001B208: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001B20C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001B210: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001B214: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B218: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001B21C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001B220: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001B224: jal         0x8001B050
    // 0x8001B228: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixOrthoF(rdram, ctx);
        goto after_0;
    // 0x8001B228: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8001B22C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B230: jal         0x80019C70
    // 0x8001B234: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001B234: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001B238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001B23C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001B240: jr          $ra
    // 0x8001B244: nop

    return;
    // 0x8001B244: nop

;}
RECOMP_FUNC void lbRelocInitSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDF78: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CDF7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CDF80: addiu       $v0, $v0, 0x62E0
    ctx->r2 = ADD32(ctx->r2, 0X62E0);
    // 0x800CDF84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CDF88: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800CDF8C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDF90: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDF94: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CDF98: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CDF9C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800CDFA0: addiu       $v1, $v1, 0x6334
    ctx->r3 = ADD32(ctx->r3, 0X6334);
    // 0x800CDFA4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CDFA8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800CDFAC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800CDFB0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CDFB4: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x800CDFB8: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800CDFBC: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800CDFC0: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800CDFC4: addiu       $t9, $t9, 0x6310
    ctx->r25 = ADD32(ctx->r25, 0X6310);
    // 0x800CDFC8: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800CDFCC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800CDFD0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800CDFD4: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x800CDFD8: addiu       $t8, $t9, 0xF
    ctx->r24 = ADD32(ctx->r25, 0XF);
    // 0x800CDFDC: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800CDFE0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800CDFE4: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x800CDFE8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800CDFEC: addiu       $t2, $t0, 0xC
    ctx->r10 = ADD32(ctx->r8, 0XC);
    // 0x800CDFF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDFF4: sw          $t2, 0x6338($at)
    MEM_W(0X6338, ctx->r1) = ctx->r10;
    // 0x800CDFF8: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800CDFFC: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CE000: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x800CE004: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x800CE008: sw          $t4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r12;
    // 0x800CE00C: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800CE010: sw          $t5, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r13;
    // 0x800CE014: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800CE018: jr          $ra
    // 0x800CE01C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    return;
    // 0x800CE01C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void itIwarkAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D948: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017D94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D950: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D954: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8017D958: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017D95C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D960: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017D964: sw          $t6, 0x108($v1)
    MEM_W(0X108, ctx->r3) = ctx->r14;
    // 0x8017D968: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017D96C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8017D970: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8017D974: jal         0x80018994
    // 0x8017D978: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8017D978: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017D97C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017D980: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8017D984: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8017D988: sh          $t8, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r24;
    // 0x8017D98C: sh          $t8, 0x358($v1)
    MEM_H(0X358, ctx->r3) = ctx->r24;
    // 0x8017D990: sh          $zero, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = 0;
    // 0x8017D994: sw          $zero, 0x354($v1)
    MEM_W(0X354, ctx->r3) = 0;
    // 0x8017D998: sh          $zero, 0x35A($v1)
    MEM_H(0X35A, ctx->r3) = 0;
    // 0x8017D99C: sh          $zero, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = 0;
    // 0x8017D9A0: sh          $zero, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = 0;
    // 0x8017D9A4: lw          $t0, 0x1C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1C);
    // 0x8017D9A8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8017D9AC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8017D9B0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8017D9B4: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x8017D9B8: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8017D9BC: addiu       $t4, $t4, -0x5EC0
    ctx->r12 = ADD32(ctx->r12, -0X5EC0);
    // 0x8017D9C0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8017D9C4: lw          $t0, 0x24($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X24);
    // 0x8017D9C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8017D9CC: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x8017D9D0: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8017D9D4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017D9D8: bnel        $t1, $at, L_8017DA18
    if (ctx->r9 != ctx->r1) {
        // 0x8017D9DC: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_8017DA18;
    }
    goto skip_0;
    // 0x8017D9DC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_0:
    // 0x8017D9E0: lw          $t2, 0x2D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017D9E4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8017D9E8: addiu       $t6, $t6, -0x59C0
    ctx->r14 = ADD32(ctx->r14, -0X59C0);
    // 0x8017D9EC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017D9F0: lui         $at, 0xC425
    ctx->r1 = S32(0XC425 << 16);
    // 0x8017D9F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D9F8: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8017D9FC: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8017DA00: sw          $v0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r2;
    // 0x8017DA04: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017DA08: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017DA0C: b           L_8017DA28
    // 0x8017DA10: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_8017DA28;
    // 0x8017DA10: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017DA14: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
L_8017DA18:
    // 0x8017DA18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017DA1C: nop

    // 0x8017DA20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017DA24: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
L_8017DA28:
    // 0x8017DA28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8017DA2C: jal         0x800FF3F4
    // 0x8017DA30: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017DA30: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017DA34: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017DA38: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8017DA3C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8017DA40: bnel        $t7, $at, L_8017DA54
    if (ctx->r15 != ctx->r1) {
        // 0x8017DA44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017DA54;
    }
    goto skip_1;
    // 0x8017DA44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8017DA48: jal         0x800269C0
    // 0x8017DA4C: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017DA4C: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_2:
    // 0x8017DA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017DA54:
    // 0x8017DA54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017DA58: jr          $ra
    // 0x8017DA5C: nop

    return;
    // 0x8017DA5C: nop

;}
RECOMP_FUNC void mvOpeningRoomTransitionOutlineProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133CEC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133CF0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133CF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133D00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133D04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133D08: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80133D0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133D10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133D14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D18: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80133D1C: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80133D20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133D24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133D28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133D2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133D30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D34: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80133D38: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80133D3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133D40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133D44: lw          $t7, 0x6678($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6678);
    // 0x80133D48: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80133D4C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80133D50: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80133D54: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80133D58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133D5C: lw          $t7, 0x6670($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6670);
    // 0x80133D60: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80133D64: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80133D68: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133D6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D70: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80133D74: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133D78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133D7C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80133D80: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133D84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D88: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80133D8C: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80133D90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133D94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133D98: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80133D9C: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80133DA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80133DA4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133DA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133DAC: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80133DB0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80133DB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133DB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133DBC: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80133DC0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80133DC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133DC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133DCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133DD0: lui         $t6, 0xF650
    ctx->r14 = S32(0XF650 << 16);
    // 0x80133DD4: ori         $t6, $t6, 0x3C0
    ctx->r14 = ctx->r14 | 0X3C0;
    // 0x80133DD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133DDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133DE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133DE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133DE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133DEC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80133DF0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80133DF4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133DF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133DFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133E00: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133E04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133E0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133E10: lw          $t6, 0x6674($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6674);
    // 0x80133E14: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80133E18: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80133E1C: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x80133E20: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x80133E24: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80133E28: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80133E2C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80133E30: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80133E34: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x80133E38: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133E3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133E40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E44: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80133E48: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80133E4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133E50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133E54: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80133E58: ori         $t6, $t6, 0x2048
    ctx->r14 = ctx->r14 | 0X2048;
    // 0x80133E5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80133E60: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133E64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E68: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    // 0x80133E6C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80133E70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133E74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133E78: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80133E7C: ori         $t8, $t8, 0x7D3E
    ctx->r24 = ctx->r24 | 0X7D3E;
    // 0x80133E80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133E84: jal         0x80013E68
    // 0x80133E88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    gcDrawDObjDLHead0(rdram, ctx);
        goto after_0;
    // 0x80133E88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80133E8C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133E90: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133E94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E98: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80133E9C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80133EA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133EA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133EA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133EAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133EB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133EB4: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80133EB8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80133EBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133EC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133EC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133EC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133ECC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133ED0: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80133ED4: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80133ED8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133EDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133EE0: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80133EE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133EE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80133EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133EF4: jr          $ra
    // 0x80133EF8: nop

    return;
    // 0x80133EF8: nop

;}
RECOMP_FUNC void func_ovl8_80385C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80385C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80385C78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80385C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385C80: beq         $a0, $zero, L_80385D20
    if (ctx->r4 == 0) {
        // 0x80385C84: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80385D20;
    }
    // 0x80385C84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80385C88: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80385C8C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80385C90: addiu       $t6, $t6, -0x2140
    ctx->r14 = ADD32(ctx->r14, -0X2140);
    // 0x80385C94: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80385C98: addiu       $t7, $t7, -0x2060
    ctx->r15 = ADD32(ctx->r15, -0X2060);
    // 0x80385C9C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80385CA0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80385CA4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80385CA8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80385CAC: addiu       $t9, $t9, -0x1F08
    ctx->r25 = ADD32(ctx->r25, -0X1F08);
    // 0x80385CB0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80385CB4: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80385CB8: addiu       $t2, $t2, -0x1E78
    ctx->r10 = ADD32(ctx->r10, -0X1E78);
    // 0x80385CBC: addiu       $t1, $t1, -0x1EE0
    ctx->r9 = ADD32(ctx->r9, -0X1EE0);
    // 0x80385CC0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80385CC4: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x80385CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385CCC: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x80385CD0: jal         0x8038120C
    // 0x80385CD4: sw          $t1, -0x6C($a0)
    MEM_W(-0X6C, ctx->r4) = ctx->r9;
    func_ovl8_8038120C(rdram, ctx);
        goto after_0;
    // 0x80385CD4: sw          $t1, -0x6C($a0)
    MEM_W(-0X6C, ctx->r4) = ctx->r9;
    after_0:
    // 0x80385CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80385CDC: jal         0x8037C92C
    // 0x80385CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037C92C(rdram, ctx);
        goto after_1;
    // 0x80385CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80385CE4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80385CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385CEC: beql        $t3, $zero, L_80385D0C
    if (ctx->r11 == 0) {
        // 0x80385CF0: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80385D0C;
    }
    goto skip_0;
    // 0x80385CF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80385CF4: jal         0x8037C30C
    // 0x80385CF8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x80385CF8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x80385CFC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80385D00: jal         0x803718C4
    // 0x80385D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x80385D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80385D08: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_80385D0C:
    // 0x80385D0C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80385D10: beql        $t5, $zero, L_80385D24
    if (ctx->r13 == 0) {
        // 0x80385D14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80385D24;
    }
    goto skip_1;
    // 0x80385D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80385D18: jal         0x803717C0
    // 0x80385D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x80385D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80385D20:
    // 0x80385D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80385D24:
    // 0x80385D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80385D28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80385D2C: jr          $ra
    // 0x80385D30: nop

    return;
    // 0x80385D30: nop

;}
RECOMP_FUNC void func_ovl8_8037E8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E8C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037E8CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037E8D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037E8D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037E8D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037E8DC: bne         $a0, $zero, L_8037E8F4
    if (ctx->r4 != 0) {
        // 0x8037E8E0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037E8F4;
    }
    // 0x8037E8E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037E8E4: jal         0x803717A0
    // 0x8037E8E8: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037E8E8: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x8037E8EC: beq         $v0, $zero, L_8037E968
    if (ctx->r2 == 0) {
        // 0x8037E8F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037E968;
    }
    // 0x8037E8F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037E8F4:
    // 0x8037E8F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E8F8: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // 0x8037E8FC: addiu       $a1, $s0, 0x114
    ctx->r5 = ADD32(ctx->r16, 0X114);
    // 0x8037E900: bnel        $t6, $zero, L_8037E924
    if (ctx->r14 != 0) {
        // 0x8037E904: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037E924;
    }
    goto skip_0;
    // 0x8037E904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8037E908: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037E90C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8037E910: jal         0x803717E0
    // 0x8037E914: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037E914: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037E918: jal         0x8037C2D0
    // 0x8037E91C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037E91C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037E920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037E924:
    // 0x8037E924: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E928: jal         0x8037C710
    // 0x8037E92C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C710(rdram, ctx);
        goto after_3;
    // 0x8037E92C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037E930: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037E934: addiu       $t7, $t7, -0x5760
    ctx->r15 = ADD32(ctx->r15, -0X5760);
    // 0x8037E938: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x8037E93C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E940: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037E944: addiu       $t8, $t8, -0x5680
    ctx->r24 = ADD32(ctx->r24, -0X5680);
    // 0x8037E948: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8037E94C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037E950: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037E954: addiu       $t0, $t0, -0x5528
    ctx->r8 = ADD32(ctx->r8, -0X5528);
    // 0x8037E958: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037E95C: addiu       $t2, $t2, -0x5500
    ctx->r10 = ADD32(ctx->r10, -0X5500);
    // 0x8037E960: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x8037E964: sw          $t2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r10;
L_8037E968:
    // 0x8037E968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037E96C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037E970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037E974: jr          $ra
    // 0x8037E978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037E978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void syMatrixRotRpyRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001BDF0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001BDF4: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8001BDF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001BDFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001BE00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001BE04: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001BE08: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001BE0C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8001BE10: jal         0x800303F0
    // 0x8001BE14: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001BE14: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8001BE18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001BE1C: jal         0x80035CD0
    // 0x8001BE20: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001BE20: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x8001BE24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001BE28: jal         0x800303F0
    // 0x8001BE2C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001BE2C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x8001BE30: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8001BE34: jal         0x80035CD0
    // 0x8001BE38: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001BE38: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x8001BE3C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001BE40: jal         0x800303F0
    // 0x8001BE44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8001BE44: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8001BE48: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001BE4C: jal         0x80035CD0
    // 0x8001BE50: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x8001BE50: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8001BE54: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001BE58: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BE5C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001BE60: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001BE64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001BE68: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8001BE6C: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001BE70: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8001BE74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001BE78: mul.s       $f12, $f20, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8001BE7C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001BE80: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x8001BE84: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8001BE88: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8001BE8C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8001BE90: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8001BE94: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001BE98: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8001BE9C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8001BEA0: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001BEA4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001BEA8: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001BEAC: nop

    // 0x8001BEB0: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001BEB4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8001BEB8: mul.s       $f6, $f20, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8001BEBC: nop

    // 0x8001BEC0: mul.s       $f12, $f22, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8001BEC4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001BEC8: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8001BECC: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8001BED0: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001BED4: nop

    // 0x8001BED8: mul.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001BEDC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001BEE0: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001BEE4: nop

    // 0x8001BEE8: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8001BEEC: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8001BEF0: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8001BEF4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001BEF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001BEFC: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8001BF00: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8001BF04: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8001BF08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BF0C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001BF10: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001BF14: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001BF18: jr          $ra
    // 0x8001BF1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001BF1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopSetProcDamageAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157ADC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157AE0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80157AE4: addiu       $t6, $t6, 0x77A0
    ctx->r14 = ADD32(ctx->r14, 0X77A0);
    // 0x80157AE8: lw          $t7, 0xAE8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157AEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80157AF0: sw          $t6, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r14;
    // 0x80157AF4: bnel        $t7, $at, L_80157B08
    if (ctx->r15 != ctx->r1) {
        // 0x80157AF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157B08;
    }
    goto skip_0;
    // 0x80157AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80157AFC: jal         0x8000BB04
    // 0x80157B00: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    gcSetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x80157B00: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x80157B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157B08:
    // 0x80157B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157B0C: jr          $ra
    // 0x80157B10: nop

    return;
    // 0x80157B10: nop

;}
RECOMP_FUNC void func_ovl8_80383344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038334C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80383350: jal         0x80371DDC
    // 0x80383354: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    func_ovl8_80371DDC(rdram, ctx);
        goto after_0;
    // 0x80383354: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x80383358: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8038335C: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x80383360: beq         $v1, $zero, L_80383374
    if (ctx->r3 == 0) {
        // 0x80383364: addiu       $v0, $v1, 0x7C
        ctx->r2 = ADD32(ctx->r3, 0X7C);
            goto L_80383374;
    }
    // 0x80383364: addiu       $v0, $v1, 0x7C
    ctx->r2 = ADD32(ctx->r3, 0X7C);
    // 0x80383368: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8038336C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80383370: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80383374:
    // 0x80383374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038337C: jr          $ra
    // 0x80383380: nop

    return;
    // 0x80383380: nop

;}
RECOMP_FUNC void itStarRodDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801780F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801780F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801780F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801780FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80178100: addiu       $a1, $a1, -0x5EDC
    ctx->r5 = ADD32(ctx->r5, -0X5EDC);
    // 0x80178104: jal         0x80172EC8
    // 0x80178108: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80178108: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8017810C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80178110: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80178114: lwc1        $f4, -0x32BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32BC);
    // 0x80178118: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8017811C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80178120: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80178124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017812C: jr          $ra
    // 0x80178130: nop

    return;
    // 0x80178130: nop

;}
RECOMP_FUNC void grYosterInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801089F4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801089F8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801089FC: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80108A00: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80108A04: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80108A08: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80108A0C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80108A10: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80108A14: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80108A18: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80108A1C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80108A20: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80108A24: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80108A28: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80108A2C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80108A30: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x80108A34: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80108A38: addiu       $v1, $v1, 0x100
    ctx->r3 = ADD32(ctx->r3, 0X100);
    // 0x80108A3C: subu        $v0, $t7, $v1
    ctx->r2 = SUB32(ctx->r15, ctx->r3);
    // 0x80108A40: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80108A44: addiu       $t2, $t2, 0x1E0
    ctx->r10 = ADD32(ctx->r10, 0X1E0);
    // 0x80108A48: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80108A4C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80108A50: lui         $t9, 0x8001
    ctx->r25 = S32(0X8001 << 16);
    // 0x80108A54: lui         $t1, 0x8001
    ctx->r9 = S32(0X8001 << 16);
    // 0x80108A58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80108A5C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80108A60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108A64: addiu       $t5, $t5, 0x580
    ctx->r13 = ADD32(ctx->r13, 0X580);
    // 0x80108A68: addiu       $t4, $t4, -0x14D8
    ctx->r12 = ADD32(ctx->r12, -0X14D8);
    // 0x80108A6C: addiu       $t1, $t1, -0x20CC
    ctx->r9 = ADD32(ctx->r9, -0X20CC);
    // 0x80108A70: addiu       $t9, $t9, 0x4038
    ctx->r25 = ADD32(ctx->r25, 0X4038);
    // 0x80108A74: addiu       $s7, $t8, 0x13F0
    ctx->r23 = ADD32(ctx->r24, 0X13F0);
    // 0x80108A78: addiu       $t6, $t6, 0x4B8
    ctx->r14 = ADD32(ctx->r14, 0X4B8);
    // 0x80108A7C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80108A80: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x80108A84: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108A88: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80108A8C: sw          $v0, 0x13F0($at)
    MEM_W(0X13F0, ctx->r1) = ctx->r2;
    // 0x80108A90: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x80108A94: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80108A98: addu        $s5, $v0, $t6
    ctx->r21 = ADD32(ctx->r2, ctx->r14);
    // 0x80108A9C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80108AA0: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80108AA4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80108AA8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80108AAC: addu        $s4, $v0, $t5
    ctx->r20 = ADD32(ctx->r2, ctx->r13);
    // 0x80108AB0: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_80108AB4:
    // 0x80108AB4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80108AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108ABC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108AC0: jal         0x80009968
    // 0x80108AC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80108AC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80108AC8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80108ACC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80108AD0: sw          $v0, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r2;
    // 0x80108AD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80108AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108ADC: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80108AE0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80108AE4: jal         0x80009DF4
    // 0x80108AE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80108AE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80108AEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80108AF0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80108AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80108AF8: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80108AFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80108B00: jal         0x8000F590
    // 0x80108B04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x80108B04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x80108B08: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80108B0C: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80108B10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108B14: jal         0x80008188
    // 0x80108B18: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80108B18: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x80108B1C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80108B20: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80108B24: jal         0x8000BD8C
    // 0x80108B28: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80108B28: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x80108B2C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80108B30: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80108B34: lw          $t9, 0x1304($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1304);
    // 0x80108B38: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80108B3C: lw          $s1, 0x74($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X74);
    // 0x80108B40: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80108B44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80108B48: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80108B4C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80108B50: lw          $t8, 0x1C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1C);
    // 0x80108B54: sw          $t8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r24;
    // 0x80108B58: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x80108B5C: sw          $t5, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r13;
    // 0x80108B60: lw          $t8, 0x24($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X24);
    // 0x80108B64: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80108B68: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    // 0x80108B6C: swc1        $f4, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->f4.u32l;
    // 0x80108B70: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80108B74: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
L_80108B78:
    // 0x80108B78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80108B7C: jal         0x800093F4
    // 0x80108B80: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gcAddChildForDObj(rdram, ctx);
        goto after_5;
    // 0x80108B80: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x80108B84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80108B88: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x80108B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108B90: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80108B94: jal         0x80008CC0
    // 0x80108B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_6;
    // 0x80108B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80108B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80108BA0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80108BA4: jal         0x80008CC0
    // 0x80108BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_7;
    // 0x80108BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80108BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80108BB0: jal         0x800C9228
    // 0x80108BB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    lbCommonAddMObjForTreeDObjs(rdram, ctx);
        goto after_8;
    // 0x80108BB4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_8:
    // 0x80108BB8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80108BBC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80108BC0: bne         $s2, $s6, L_80108B78
    if (ctx->r18 != ctx->r22) {
        // 0x80108BC4: lw          $s1, 0x8($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X8);
            goto L_80108B78;
    }
    // 0x80108BC4: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x80108BC8: jal         0x8000DF34
    // 0x80108BCC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_9;
    // 0x80108BCC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_9:
    // 0x80108BD0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80108BD4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80108BD8: sb          $zero, 0x1C($s7)
    MEM_B(0X1C, ctx->r23) = 0;
    // 0x80108BDC: sb          $zero, 0x1D($s7)
    MEM_B(0X1D, ctx->r23) = 0;
    // 0x80108BE0: sb          $t6, 0x1F($s7)
    MEM_B(0X1F, ctx->r23) = ctx->r14;
    // 0x80108BE4: sb          $zero, 0x1E($s7)
    MEM_B(0X1E, ctx->r23) = 0;
    // 0x80108BE8: swc1        $f22, 0x18($s7)
    MEM_W(0X18, ctx->r23) = ctx->f22.u32l;
    // 0x80108BEC: jal         0x800FC58C
    // 0x80108BF0: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_10;
    // 0x80108BF0: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_10:
    // 0x80108BF4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80108BF8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80108BFC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80108C00: addiu       $t3, $t3, 0x1450
    ctx->r11 = ADD32(ctx->r11, 0X1450);
    // 0x80108C04: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80108C08: addiu       $t2, $t9, 0x20
    ctx->r10 = ADD32(ctx->r25, 0X20);
    // 0x80108C0C: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x80108C10: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80108C14: bne         $t2, $t3, L_80108AB4
    if (ctx->r10 != ctx->r11) {
        // 0x80108C18: addiu       $s7, $s7, 0x20
        ctx->r23 = ADD32(ctx->r23, 0X20);
            goto L_80108AB4;
    }
    // 0x80108C18: addiu       $s7, $s7, 0x20
    ctx->r23 = ADD32(ctx->r23, 0X20);
    // 0x80108C1C: lui         $a0, 0xB2
    ctx->r4 = S32(0XB2 << 16);
    // 0x80108C20: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x80108C24: lui         $a2, 0xB2
    ctx->r6 = S32(0XB2 << 16);
    // 0x80108C28: lui         $a3, 0xB2
    ctx->r7 = S32(0XB2 << 16);
    // 0x80108C2C: addiu       $a3, $a3, 0x2C30
    ctx->r7 = ADD32(ctx->r7, 0X2C30);
    // 0x80108C30: addiu       $a2, $a2, 0x2A00
    ctx->r6 = ADD32(ctx->r6, 0X2A00);
    // 0x80108C34: addiu       $a1, $a1, 0x2A00
    ctx->r5 = ADD32(ctx->r5, 0X2A00);
    // 0x80108C38: jal         0x801159F8
    // 0x80108C3C: addiu       $a0, $a0, 0x2980
    ctx->r4 = ADD32(ctx->r4, 0X2980);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_11;
    // 0x80108C3C: addiu       $a0, $a0, 0x2980
    ctx->r4 = ADD32(ctx->r4, 0X2980);
    after_11:
    // 0x80108C40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80108C44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108C48: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80108C4C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80108C50: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80108C54: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80108C58: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80108C5C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80108C60: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80108C64: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80108C68: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80108C6C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80108C70: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80108C74: sw          $v0, 0x1454($at)
    MEM_W(0X1454, ctx->r1) = ctx->r2;
    // 0x80108C78: jr          $ra
    // 0x80108C7C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80108C7C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void ftCommonAttackLw3CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FD70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014FD74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FD78: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014FD7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014FD80: lw          $t6, 0x9C8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X9C8);
    // 0x8014FD84: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8014FD88: lhu         $t8, 0x1B4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B4);
    // 0x8014FD8C: lhu         $t7, 0x1BE($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
    // 0x8014FD90: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014FD94: beql        $t9, $zero, L_8014FE28
    if (ctx->r25 == 0) {
        // 0x8014FD98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FE28;
    }
    goto skip_0;
    // 0x8014FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014FD9C: lb          $t0, 0x1C3($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1C3);
    // 0x8014FDA0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014FDA4: slti        $at, $t0, -0x13
    ctx->r1 = SIGNED(ctx->r8) < -0X13 ? 1 : 0;
    // 0x8014FDA8: beql        $at, $zero, L_8014FE28
    if (ctx->r1 == 0) {
        // 0x8014FDAC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FE28;
    }
    goto skip_1;
    // 0x8014FDAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014FDB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014FDB4: jal         0x800E8000
    // 0x8014FDB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x8014FDB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014FDBC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FDC0: lwc1        $f4, -0x3B30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B30);
    // 0x8014FDC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FDC8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014FDCC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8014FDD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014FDD4: bc1fl       L_8014FE28
    if (!c1cs) {
        // 0x8014FDD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FE28;
    }
    goto skip_2;
    // 0x8014FDD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8014FDDC: jal         0x80146A8C
    // 0x8014FDE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_1;
    // 0x8014FDE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014FDE4: beq         $v0, $zero, L_8014FE00
    if (ctx->r2 == 0) {
        // 0x8014FDE8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8014FE00;
    }
    // 0x8014FDE8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014FDEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014FDF0: jal         0x80146690
    // 0x8014FDF4: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014FDF4: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
    after_2:
    // 0x8014FDF8: b           L_8014FE28
    // 0x8014FDFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FE28;
    // 0x8014FDFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014FE00:
    // 0x8014FE00: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8014FE04: lw          $t2, 0x100($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X100);
    // 0x8014FE08: sll         $t4, $t2, 5
    ctx->r12 = S32(ctx->r10 << 5);
    // 0x8014FE0C: bgezl       $t4, L_8014FE28
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8014FE10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FE28;
    }
    goto skip_3;
    // 0x8014FE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8014FE14: jal         0x8014FD14
    // 0x8014FE18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttackLw3SetStatus(rdram, ctx);
        goto after_3;
    // 0x8014FE18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8014FE1C: b           L_8014FE28
    // 0x8014FE20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FE28;
    // 0x8014FE20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014FE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014FE28:
    // 0x8014FE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014FE30: jr          $ra
    // 0x8014FE34: nop

    return;
    // 0x8014FE34: nop

;}
RECOMP_FUNC void func_ovl8_8037C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C3C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037C3C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037C3C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037C3CC: bne         $a0, $zero, L_8037C3E4
    if (ctx->r4 != 0) {
        // 0x8037C3D0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8037C3E4;
    }
    // 0x8037C3D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037C3D4: jal         0x803717A0
    // 0x8037C3D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037C3D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8037C3DC: beq         $v0, $zero, L_8037C42C
    if (ctx->r2 == 0) {
        // 0x8037C3E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037C42C;
    }
    // 0x8037C3E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037C3E4:
    // 0x8037C3E4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C3E8: addiu       $t6, $t6, -0x5E60
    ctx->r14 = ADD32(ctx->r14, -0X5E60);
    // 0x8037C3EC: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8037C3F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8037C3F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C3F8: sw          $zero, -0x5E44($at)
    MEM_W(-0X5E44, ctx->r1) = 0;
    // 0x8037C3FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C400: sw          $zero, -0x5E40($at)
    MEM_W(-0X5E40, ctx->r1) = 0;
    // 0x8037C404: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C408: sw          $zero, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = 0;
    // 0x8037C40C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C410: sw          $zero, -0x5E38($at)
    MEM_W(-0X5E38, ctx->r1) = 0;
    // 0x8037C414: addiu       $a0, $zero, -0x200
    ctx->r4 = ADD32(0, -0X200);
    // 0x8037C418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C41C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8037C420: jal         0x80009968
    // 0x8037C424: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8037C424: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8037C428: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8037C42C:
    // 0x8037C42C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037C430: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037C434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037C438: jr          $ra
    // 0x8037C43C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8037C43C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mn1PModeMakeOptionTab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D08: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D0C: lw          $t6, 0x3290($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3290);
    // 0x80131D10: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131D18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131D1C: addiu       $t7, $t7, 0x1E8
    ctx->r15 = ADD32(ctx->r15, 0X1E8);
    // 0x80131D20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131D24: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80131D28: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80131D2C: jal         0x800CCFDC
    // 0x80131D30: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131D30: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80131D34: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D38: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131D3C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80131D40: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131D44: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131D48: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131D4C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131D50: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131D54: addiu       $t3, $t3, 0x330
    ctx->r11 = ADD32(ctx->r11, 0X330);
    // 0x80131D58: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131D5C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131D60: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131D64: lw          $t2, 0x3290($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3290);
    // 0x80131D68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131D6C: jal         0x800CCFDC
    // 0x80131D70: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131D70: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80131D74: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D78: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80131D7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131D80: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80131D84: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131D88: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80131D8C: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131D90: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131D94: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80131D98: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x80131D9C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131DA0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131DA4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80131DA8: addiu       $t1, $t1, 0x568
    ctx->r9 = ADD32(ctx->r9, 0X568);
    // 0x80131DAC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131DB0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131DB4: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80131DB8: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80131DBC: sb          $t8, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r24;
    // 0x80131DC0: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80131DC4: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x80131DC8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80131DCC: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x80131DD0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80131DD4: sh          $v1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r3;
    // 0x80131DD8: lw          $t0, 0x3290($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3290);
    // 0x80131DDC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131DE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80131DE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131DE8: jal         0x800CCFDC
    // 0x80131DEC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DEC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x80131DF0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DF4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80131DF8: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80131DFC: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80131E00: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80131E04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80131E08: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131E0C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80131E10: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131E14: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80131E18: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131E1C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131E20: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80131E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131E28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E2C: jr          $ra
    // 0x80131E30: nop

    return;
    // 0x80131E30: nop

;}
RECOMP_FUNC void mvOpeningKirbyPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D870: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D874: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D878: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D87C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D880: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D884: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D888: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D88C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D890: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D894: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D898: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D89C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D8A0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8A4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8A8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D8AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D8B0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8B4: lui         $t7, 0x50AA
    ctx->r15 = S32(0X50AA << 16);
    // 0x8018D8B8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018D8BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8C0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8C4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D8C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8D0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8D4: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D8D8: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8E0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8E4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8E8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8F4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8F8: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8FC: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D900: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D904: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D908: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D90C: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D910: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D914: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D918: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D91C: lui         $t7, 0x34
    ctx->r15 = S32(0X34 << 16);
    // 0x8018D920: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8018D924: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D928: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D92C: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D930: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D934: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D938: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D93C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D940: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D944: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D948: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D94C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D950: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D954: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D958: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D95C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D960: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D964: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D968: jr          $ra
    // 0x8018D96C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D96C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void dbFallsExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D64B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D64BC: jr          $ra
    // 0x800D64C0: sw          $t6, 0x6720($at)
    MEM_W(0X6720, ctx->r1) = ctx->r14;
    return;
    // 0x800D64C0: sw          $t6, 0x6720($at)
    MEM_W(0X6720, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void itSawamuraWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018273C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182744: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182748: addiu       $a1, $a1, -0x4DAC
    ctx->r5 = ADD32(ctx->r5, -0X4DAC);
    // 0x8018274C: jal         0x80172EC8
    // 0x80182750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80182750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80182754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018275C: jr          $ra
    // 0x80182760: nop

    return;
    // 0x80182760: nop

;}
RECOMP_FUNC void efManagerCaptureKirbyStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103B28: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80103B2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103B30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103B34: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80103B38: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80103B3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80103B40: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80103B44: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80103B48: lw          $t7, 0x1074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1074);
    // 0x80103B4C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80103B50: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x80103B54: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80103B58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80103B5C: lwc1        $f8, 0xA20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA20);
    // 0x80103B60: lwc1        $f6, 0x38($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80103B64: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80103B68: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80103B6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80103B70: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80103B74: swc1        $f10, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f10.u32l;
    // 0x80103B78: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80103B7C: bgez        $a2, L_80103B90
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80103B80: andi        $t9, $a2, 0x1
        ctx->r25 = ctx->r6 & 0X1;
            goto L_80103B90;
    }
    // 0x80103B80: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x80103B84: beq         $t9, $zero, L_80103B90
    if (ctx->r25 == 0) {
        // 0x80103B88: nop
    
            goto L_80103B90;
    }
    // 0x80103B88: nop

    // 0x80103B8C: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_80103B90:
    // 0x80103B90: beql        $t9, $zero, L_80103CE0
    if (ctx->r25 == 0) {
        // 0x80103B94: addiu       $t7, $a2, 0x1
        ctx->r15 = ADD32(ctx->r6, 0X1);
            goto L_80103CE0;
    }
    goto skip_0;
    // 0x80103B94: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80103B98: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80103B9C: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80103BA0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80103BA4: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80103BA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80103BAC: lw          $t4, 0x1C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1C);
    // 0x80103BB0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103BB4: lw          $t3, 0x20($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20);
    // 0x80103BB8: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80103BBC: lw          $t4, 0x24($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X24);
    // 0x80103BC0: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
    // 0x80103BC4: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    // 0x80103BC8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80103BCC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80103BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80103BD4: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80103BD8: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80103BDC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80103BE0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80103BE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80103BE8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80103BEC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80103BF0: jal         0x80018994
    // 0x80103BF4: nop

    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80103BF4: nop

    after_0:
    // 0x80103BF8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80103BFC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80103C00: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80103C04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80103C08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80103C0C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80103C10: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80103C14: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80103C18: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80103C1C: lwc1        $f6, 0x48($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80103C20: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80103C24: nop

    // 0x80103C28: bc1fl       L_80103C8C
    if (!c1cs) {
        // 0x80103C2C: lw          $t3, 0x8($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X8);
            goto L_80103C8C;
    }
    goto skip_1;
    // 0x80103C2C: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    skip_1:
    // 0x80103C30: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80103C34: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80103C38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80103C3C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80103C40: mflo        $t1
    ctx->r9 = lo;
    // 0x80103C44: addu        $t0, $a3, $t1
    ctx->r8 = ADD32(ctx->r7, ctx->r9);
    // 0x80103C48: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80103C4C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80103C50: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80103C54: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80103C58: jal         0x80018994
    // 0x80103C5C: nop

    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80103C5C: nop

    after_1:
    // 0x80103C60: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80103C64: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80103C68: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80103C6C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80103C70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80103C74: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80103C78: jal         0x800FFEA4
    // 0x80103C7C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    efManagerStarRodSparkMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80103C7C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80103C80: b           L_80103CDC
    // 0x80103C84: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
        goto L_80103CDC;
    // 0x80103C84: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80103C88: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
L_80103C8C:
    // 0x80103C8C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80103C90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80103C94: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80103C98: mflo        $t4
    ctx->r12 = lo;
    // 0x80103C9C: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80103CA0: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80103CA4: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80103CA8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80103CAC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80103CB0: jal         0x80018994
    // 0x80103CB4: nop

    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80103CB4: nop

    after_3:
    // 0x80103CB8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80103CBC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80103CC0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80103CC4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80103CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80103CCC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80103CD0: jal         0x800FFEA4
    // 0x80103CD4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    efManagerStarRodSparkMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80103CD4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80103CD8: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
L_80103CDC:
    // 0x80103CDC: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
L_80103CE0:
    // 0x80103CE0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80103CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103CE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103CEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80103CF0: jr          $ra
    // 0x80103CF4: nop

    return;
    // 0x80103CF4: nop

;}
RECOMP_FUNC void mnVSResultsFaceWinner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801333E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801333EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801333F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801333F4: jal         0x8013234C
    // 0x801333F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x801333F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x801333FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80133400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133404: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80133408: beq         $t6, $zero, L_8013344C
    if (ctx->r14 == 0) {
        // 0x8013340C: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8013344C;
    }
    // 0x8013340C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80133410: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133414: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80133418: lw          $t9, -0x6420($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6420);
    // 0x8013341C: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80133420: lw          $v1, 0x74($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X74);
    // 0x80133424: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80133428: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8013342C: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80133430: lwc1        $f18, 0x24($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80133434: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80133438: jal         0x8001863C
    // 0x8013343C: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8013343C: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    after_1:
    // 0x80133440: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80133444: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x80133448: swc1        $f0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f0.u32l;
L_8013344C:
    // 0x8013344C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133454: jr          $ra
    // 0x80133458: nop

    return;
    // 0x80133458: nop

;}
RECOMP_FUNC void ftCommonLGunShootProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146FD4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80146FD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80146FDC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80146FE0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80146FE4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80146FE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80146FEC: lw          $v1, 0x84C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84C);
    // 0x80146FF0: beql        $v1, $zero, L_801471B0
    if (ctx->r3 == 0) {
        // 0x80146FF4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801471B0;
    }
    goto skip_0;
    // 0x80146FF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80146FF8: lw          $t6, 0x17C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X17C);
    // 0x80146FFC: beql        $t6, $zero, L_801471B0
    if (ctx->r14 == 0) {
        // 0x80147000: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801471B0;
    }
    goto skip_1;
    // 0x80147000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80147004: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80147008: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8014700C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80147010: lhu         $t7, 0x33E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X33E);
    // 0x80147014: addiu       $t8, $t8, -0x79A0
    ctx->r24 = ADD32(ctx->r24, -0X79A0);
    // 0x80147018: addiu       $t0, $t0, -0x7994
    ctx->r8 = ADD32(ctx->r8, -0X7994);
    // 0x8014701C: beql        $t7, $zero, L_80147158
    if (ctx->r15 == 0) {
        // 0x80147020: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_80147158;
    }
    goto skip_2;
    // 0x80147020: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x80147024: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80147028: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8014702C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80147030: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80147034: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80147038: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014703C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80147040: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80147044: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x80147048: lw          $t1, 0x9C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014704C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80147050: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80147054: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80147058: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8014705C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80147060: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80147064: nop

    // 0x80147068: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8014706C: nop

    // 0x80147070: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80147074: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80147078: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8014707C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80147080: lw          $t2, 0x9C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X9C8);
    // 0x80147084: lw          $t3, 0x33C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X33C);
    // 0x80147088: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8014708C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80147090: jal         0x800EDF24
    // 0x80147094: lw          $a0, 0x8E8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80147094: lw          $a0, 0x8E8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8E8);
    after_0:
    // 0x80147098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014709C: jal         0x80175AD8
    // 0x801470A0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    itLGunMakeAmmo(rdram, ctx);
        goto after_1;
    // 0x801470A0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x801470A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801470A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801470AC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801470B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801470B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801470B8: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x801470BC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x801470C0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x801470C4: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x801470C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801470CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801470D0: lw          $a2, 0x33C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X33C);
    // 0x801470D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801470D8: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x801470DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801470E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801470E4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x801470E8: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x801470EC: jal         0x800EABDC
    // 0x801470F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    ftParamMakeEffect(rdram, ctx);
        goto after_2;
    // 0x801470F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x801470F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801470F8: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x801470FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80147100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80147104: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80147108: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8014710C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80147110: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80147114: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80147118: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8014711C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80147120: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80147124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80147128: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x8014712C: jal         0x800EABDC
    // 0x80147130: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    ftParamMakeEffect(rdram, ctx);
        goto after_3;
    // 0x80147130: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80147134: jal         0x800269C0
    // 0x80147138: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80147138: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_4:
    // 0x8014713C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147140: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80147144: jal         0x800E806C
    // 0x80147148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_5;
    // 0x80147148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8014714C: b           L_801471AC
    // 0x80147150: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
        goto L_801471AC;
    // 0x80147150: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x80147154: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
L_80147158:
    // 0x80147158: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x8014715C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80147160: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80147164: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80147168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014716C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80147170: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x80147174: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80147178: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x8014717C: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x80147180: lw          $a2, 0x33C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X33C);
    // 0x80147184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80147188: lw          $t4, 0x44($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X44);
    // 0x8014718C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80147190: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80147194: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80147198: jal         0x800EABDC
    // 0x8014719C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    ftParamMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8014719C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x801471A0: jal         0x800269C0
    // 0x801471A4: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x801471A4: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_7:
    // 0x801471A8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_801471AC:
    // 0x801471AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801471B0:
    // 0x801471B0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801471B4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801471B8: jr          $ra
    // 0x801471BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801471BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void itStarCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80174934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174938: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017493C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174940: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80174944: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80174948: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8017494C: jal         0x80172558
    // 0x80174950: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174950: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174954: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80174958: lhu         $t7, 0x33E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X33E);
    // 0x8017495C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80174960: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80174964: bne         $t9, $zero, L_80174974
    if (ctx->r25 != 0) {
        // 0x80174968: sh          $t8, 0x33E($a0)
        MEM_H(0X33E, ctx->r4) = ctx->r24;
            goto L_80174974;
    }
    // 0x80174968: sh          $t8, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r24;
    // 0x8017496C: jal         0x8017275C
    // 0x80174970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainRefreshAttackColl(rdram, ctx);
        goto after_1;
    // 0x80174970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80174974:
    // 0x80174974: jal         0x801713F4
    // 0x80174978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_2;
    // 0x80174978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017497C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80174984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174988: jr          $ra
    // 0x8017498C: nop

    return;
    // 0x8017498C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPortraitFlashThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134890: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134894: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80134898: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013489C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801348A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801348A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801348A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801348AC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x801348B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801348B4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801348B8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_801348BC:
    // 0x801348BC: bne         $s2, $zero, L_801348CC
    if (ctx->r18 != 0) {
        // 0x801348C0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_801348CC;
    }
    // 0x801348C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x801348C4: jal         0x80134858
    // 0x801348C8: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    mnPlayers1PBonusDestroyPortraitFlash(rdram, ctx);
        goto after_0;
    // 0x801348C8: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    after_0:
L_801348CC:
    // 0x801348CC: bne         $s0, $zero, L_801348F0
    if (ctx->r16 != 0) {
        // 0x801348D0: nop
    
            goto L_801348F0;
    }
    // 0x801348D0: nop

    // 0x801348D4: lw          $t6, 0x7C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X7C);
    // 0x801348D8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801348DC: bnel        $s3, $t6, L_801348F0
    if (ctx->r19 != ctx->r14) {
        // 0x801348E0: sw          $s3, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->r19;
            goto L_801348F0;
    }
    goto skip_0;
    // 0x801348E0: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
    skip_0:
    // 0x801348E4: b           L_801348F0
    // 0x801348E8: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
        goto L_801348F0;
    // 0x801348E8: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x801348EC: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
L_801348F0:
    // 0x801348F0: jal         0x8000B1E8
    // 0x801348F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x801348F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801348F8: b           L_801348BC
    // 0x801348FC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_801348BC;
    // 0x801348FC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80134900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134904: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134908: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013490C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80134910: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80134914: jr          $ra
    // 0x80134918: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80134918: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __n_vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E2F8: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x8002E2FC: lw          $t6, 0x68($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X68);
    // 0x8002E300: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x8002E304: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002E308: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002E30C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002E310: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8002E314: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x8002E318: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x8002E31C: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x8002E320: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x8002E324: bgtzl       $v1, L_8002E334
    if (SIGNED(ctx->r3) > 0) {
        // 0x8002E328: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_8002E334;
    }
    goto skip_0;
    // 0x8002E328: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_0:
    // 0x8002E32C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002E330: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_8002E334:
    // 0x8002E334: bne         $at, $zero, L_8002E340
    if (ctx->r1 != 0) {
        // 0x8002E338: nop
    
            goto L_8002E340;
    }
    // 0x8002E338: nop

    // 0x8002E33C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_8002E340:
    // 0x8002E340: jr          $ra
    // 0x8002E344: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8002E344: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void ftCommonCapturePulledRotateScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A5F0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8014A5F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A5F8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8014A5FC: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8014A600: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014A604: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8014A608: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8014A60C: lw          $t6, 0x844($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X844);
    // 0x8014A610: lw          $t0, 0x10($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X10);
    // 0x8014A614: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8014A618: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8014A61C: lw          $t8, 0x9C8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014A620: lw          $t9, 0x334($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X334);
    // 0x8014A624: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8014A628: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8014A62C: lw          $a1, 0x8E8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8E8);
    // 0x8014A630: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x8014A634: jal         0x800C9A38
    // 0x8014A638: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    func_ovl0_800C9A38(rdram, ctx);
        goto after_0;
    // 0x8014A638: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014A63C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8014A640: jal         0x800EDA0C
    // 0x8014A644: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_ovl2_800EDA0C(rdram, ctx);
        goto after_1;
    // 0x8014A644: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x8014A648: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8014A64C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8014A650: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8014A654: lw          $t3, 0x74($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X74);
    // 0x8014A658: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8014A65C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8014A660: lwc1        $f8, 0x40($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X40);
    // 0x8014A664: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8014A668: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014A66C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8014A670: lw          $t4, 0x74($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X74);
    // 0x8014A674: lwc1        $f16, 0x20($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8014A678: lwc1        $f4, 0x44($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8014A67C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8014A680: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8014A684: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8014A688: lw          $t5, 0x74($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X74);
    // 0x8014A68C: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8014A690: lwc1        $f16, 0x48($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X48);
    // 0x8014A694: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8014A698: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014A69C: jal         0x800ED3C0
    // 0x8014A6A0: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x8014A6A0: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    after_2:
    // 0x8014A6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014A6A8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8014A6AC: jr          $ra
    // 0x8014A6B0: nop

    return;
    // 0x8014A6B0: nop

;}
RECOMP_FUNC void mvOpeningStandoffMakeFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131C04: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80131C08: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80131C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C10: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80131C14: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80131C18:
    // 0x80131C18: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C1C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131C20: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131C24: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131C28: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131C2C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131C30: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131C34: bne         $t7, $t0, L_80131C18
    if (ctx->r15 != ctx->r8) {
        // 0x80131C38: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131C18;
    }
    // 0x80131C38: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131C3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C48: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131C4C: jal         0x800EC0EC
    // 0x80131C50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131C50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80131C54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131C58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131C5C: lw          $t1, 0x29C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X29C8);
    // 0x80131C60: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80131C64: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80131C68: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131C6C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80131C70: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80131C74: jal         0x800D7F3C
    // 0x80131C78: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131C78: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    after_1:
    // 0x80131C7C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131C80: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x80131C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C88: jal         0x803905CC
    // 0x80131C8C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131C8C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80131C90: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80131C94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131C9C: lw          $t2, 0x74($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X74);
    // 0x80131CA0: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80131CA4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80131CA8: swc1        $f2, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f2.u32l;
    // 0x80131CAC: lw          $t3, 0x74($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X74);
    // 0x80131CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131CB4: swc1        $f2, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f2.u32l;
    // 0x80131CB8: lw          $t4, 0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X74);
    // 0x80131CBC: swc1        $f2, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f2.u32l;
    // 0x80131CC0: jal         0x800EC0EC
    // 0x80131CC4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_3;
    // 0x80131CC4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_3:
    // 0x80131CC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131CCC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131CD0: lw          $t0, 0x29CC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X29CC);
    // 0x80131CD4: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80131CD8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80131CDC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131CE0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80131CE4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80131CE8: jal         0x800D7F3C
    // 0x80131CEC: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    ftManagerMakeFighter(rdram, ctx);
        goto after_4;
    // 0x80131CEC: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    after_4:
    // 0x80131CF0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131CF4: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x80131CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CFC: jal         0x803905CC
    // 0x80131D00: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_5;
    // 0x80131D00: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80131D04: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80131D08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131D0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131D10: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x80131D14: swc1        $f2, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f2.u32l;
    // 0x80131D18: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x80131D1C: swc1        $f2, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f2.u32l;
    // 0x80131D20: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80131D24: swc1        $f2, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f2.u32l;
    // 0x80131D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131D2C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131D30: jr          $ra
    // 0x80131D34: nop

    return;
    // 0x80131D34: nop

;}
RECOMP_FUNC void itGShellWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178918: jal         0x801787CC
    // 0x8017891C: nop

    itGShellWaitInitVars(rdram, ctx);
        goto after_0;
    // 0x8017891C: nop

    after_0:
    // 0x80178920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178928: jr          $ra
    // 0x8017892C: nop

    return;
    // 0x8017892C: nop

;}
RECOMP_FUNC void ftFoxSpecialLwStartInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D1E8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015D1EC: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8015D1F0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8015D1F4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8015D1F8: sw          $t6, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r14;
    // 0x8015D1FC: sw          $zero, 0xB20($v1)
    MEM_W(0XB20, ctx->r3) = 0;
    // 0x8015D200: sw          $t7, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->r15;
    // 0x8015D204: sw          $t8, 0xB28($v1)
    MEM_W(0XB28, ctx->r3) = ctx->r24;
    // 0x8015D208: jal         0x80100FA4
    // 0x8015D20C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerFoxReflectorMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8015D20C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015D210: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D214: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8015D218: beq         $v0, $zero, L_8015D22C
    if (ctx->r2 == 0) {
        // 0x8015D21C: sw          $v0, 0xB24($v1)
        MEM_W(0XB24, ctx->r3) = ctx->r2;
            goto L_8015D22C;
    }
    // 0x8015D21C: sw          $v0, 0xB24($v1)
    MEM_W(0XB24, ctx->r3) = ctx->r2;
    // 0x8015D220: lbu         $t0, 0x18F($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18F);
    // 0x8015D224: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8015D228: sb          $t1, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r9;
L_8015D22C:
    // 0x8015D22C: lw          $t2, 0xE94($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE94);
    // 0x8015D230: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8015D234: addiu       $t3, $t3, 0x19B0
    ctx->r11 = ADD32(ctx->r11, 0X19B0);
    // 0x8015D238: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8015D23C: sw          $t4, 0x850($v1)
    MEM_W(0X850, ctx->r3) = ctx->r12;
    // 0x8015D240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D248: jr          $ra
    // 0x8015D24C: nop

    return;
    // 0x8015D24C: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeScene4Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801338D8: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x801338DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801338E0: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x801338E4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801338E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801338EC: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801338F0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801338F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801338F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801338FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133900: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133904: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133908: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8013390C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80133910: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133914: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133918: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8013391C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133920: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80133924: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133928: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013392C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133934: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133938: jal         0x8000B93C
    // 0x8013393C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013393C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133940: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133944: sw          $v0, 0x4CE8($at)
    MEM_W(0X4CE8, ctx->r1) = ctx->r2;
    // 0x80133948: jal         0x801337C8
    // 0x8013394C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRoomInitScene4Cameras(rdram, ctx);
        goto after_1;
    // 0x8013394C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80133950: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80133954: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80133958: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8013395C: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x80133960: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133964: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133968: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013396C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133970: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80133974: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80133978: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8013397C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80133980: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133984: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133988: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013398C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133994: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133998: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013399C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801339A0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801339A4: jal         0x8000B93C
    // 0x801339A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcMakeCameraGObj(rdram, ctx);
        goto after_2;
    // 0x801339A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x801339AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339B0: sw          $v0, 0x4CEC($at)
    MEM_W(0X4CEC, ctx->r1) = ctx->r2;
    // 0x801339B4: jal         0x801337C8
    // 0x801339B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRoomInitScene4Cameras(rdram, ctx);
        goto after_3;
    // 0x801339B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x801339BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801339C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801339C4: jr          $ra
    // 0x801339C8: nop

    return;
    // 0x801339C8: nop

;}
RECOMP_FUNC void ftCommonThrownKirbyStarInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C424: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014C428: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014C42C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014C430: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014C434: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8014C438: lw          $v0, 0x844($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X844);
    // 0x8014C43C: beql        $v0, $zero, L_8014C4C8
    if (ctx->r2 == 0) {
        // 0x8014C440: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014C4C8;
    }
    goto skip_0;
    // 0x8014C440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8014C444: jal         0x8014ADB0
    // 0x8014C448: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_0;
    // 0x8014C448: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    after_0:
    // 0x8014C44C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014C450: jal         0x800E8098
    // 0x8014C454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x8014C454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8014C458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C45C: jal         0x800E8098
    // 0x8014C460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014C460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014C464: lhu         $t6, 0x28E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X28E);
    // 0x8014C468: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8014C46C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8014C470: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014C474: lhu         $t7, 0x290($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X290);
    // 0x8014C478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014C47C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014C480: jal         0x800EAA2C
    // 0x8014C484: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_3;
    // 0x8014C484: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x8014C488: sw          $zero, 0x844($s1)
    MEM_W(0X844, ctx->r17) = 0;
    // 0x8014C48C: sw          $zero, 0x840($s1)
    MEM_W(0X840, ctx->r17) = 0;
    // 0x8014C490: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014C494: sw          $zero, 0x844($s0)
    MEM_W(0X844, ctx->r16) = 0;
    // 0x8014C498: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8014C49C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014C4A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014C4A4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8014C4A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014C4AC: nop

    // 0x8014C4B0: bc1fl       L_8014C4C4
    if (!c1cs) {
        // 0x8014C4B4: sh          $t9, 0xB1A($s1)
        MEM_H(0XB1A, ctx->r17) = ctx->r25;
            goto L_8014C4C4;
    }
    goto skip_1;
    // 0x8014C4B4: sh          $t9, 0xB1A($s1)
    MEM_H(0XB1A, ctx->r17) = ctx->r25;
    skip_1:
    // 0x8014C4B8: b           L_8014C4C4
    // 0x8014C4BC: sh          $t8, 0xB1A($s1)
    MEM_H(0XB1A, ctx->r17) = ctx->r24;
        goto L_8014C4C4;
    // 0x8014C4BC: sh          $t8, 0xB1A($s1)
    MEM_H(0XB1A, ctx->r17) = ctx->r24;
    // 0x8014C4C0: sh          $t9, 0xB1A($s1)
    MEM_H(0XB1A, ctx->r17) = ctx->r25;
L_8014C4C4:
    // 0x8014C4C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014C4C8:
    // 0x8014C4C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014C4CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014C4D0: jr          $ra
    // 0x8014C4D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8014C4D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itTaruRollSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179DF4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179DF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80179DFC: addiu       $t6, $zero, 0x168
    ctx->r14 = ADD32(0, 0X168);
    // 0x80179E00: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179E04: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179E08: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80179E0C: sw          $t6, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r14;
    // 0x80179E10: jal         0x80172EC8
    // 0x80179E14: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179E14: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x80179E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179E20: jr          $ra
    // 0x80179E24: nop

    return;
    // 0x80179E24: nop

;}
RECOMP_FUNC void grPupupuFlowersBackLoopStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105FC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80105FC8: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80105FCC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80105FD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80105FD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80105FD8: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x80105FDC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80105FE0: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80105FE4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80105FE8: nop

    // 0x80105FEC: bc1f        L_80106000
    if (!c1cs) {
        // 0x80105FF0: nop
    
            goto L_80106000;
    }
    // 0x80105FF0: nop

    // 0x80105FF4: sb          $t7, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r15;
    // 0x80105FF8: sb          $t8, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r24;
    // 0x80105FFC: sb          $t9, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r25;
L_80106000:
    // 0x80106000: jr          $ra
    // 0x80106004: nop

    return;
    // 0x80106004: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingGetFreeCostumeRoyal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133408: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013340C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80133410: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80133414: addiu       $s7, $s7, -0x776C
    ctx->r23 = ADD32(ctx->r23, -0X776C);
    // 0x80133418: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8013341C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80133420: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80133424: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80133428: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013342C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80133430: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80133434: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80133438: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013343C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133440: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133444: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013344C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80133450: bne         $a1, $a2, L_801334F8
    if (ctx->r5 != ctx->r6) {
        // 0x80133454: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801334F8;
    }
    // 0x80133454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133458: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x8013345C: addiu       $s7, $s7, -0x7768
    ctx->r23 = ADD32(ctx->r23, -0X7768);
    // 0x80133460: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80133464: addiu       $s5, $zero, 0xB8
    ctx->r21 = ADD32(0, 0XB8);
    // 0x80133468: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x8013346C: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133470: addiu       $s4, $s4, -0x7AA8
    ctx->r20 = ADD32(ctx->r20, -0X7AA8);
    // 0x80133474: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80133478: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8013347C: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80133480: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80133484: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133488: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8013348C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80133490: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x80133494: mflo        $t7
    ctx->r15 = lo;
    // 0x80133498: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8013349C: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x801334A0: bne         $s6, $t9, L_801334E4
    if (ctx->r22 != ctx->r25) {
        // 0x801334A4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_801334E4;
    }
    // 0x801334A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_801334A8:
    // 0x801334A8: jal         0x800EC0EC
    // 0x801334AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801334AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801334B0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x801334B4: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x801334B8: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x801334BC: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801334C0: mflo        $t1
    ctx->r9 = lo;
    // 0x801334C4: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x801334C8: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x801334CC: bnel        $v0, $t3, L_801334DC
    if (ctx->r2 != ctx->r11) {
        // 0x801334D0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801334DC;
    }
    goto skip_0;
    // 0x801334D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801334D4: sw          $s2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r18;
    // 0x801334D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801334DC:
    // 0x801334DC: bnel        $s0, $s3, L_801334A8
    if (ctx->r16 != ctx->r19) {
        // 0x801334E0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_801334A8;
    }
    goto skip_1;
    // 0x801334E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_1:
L_801334E4:
    // 0x801334E4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x801334E8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x801334EC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x801334F0: b           L_8013358C
    // 0x801334F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_8013358C;
    // 0x801334F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_801334F8:
    // 0x801334F8: addiu       $s5, $zero, 0xB8
    ctx->r21 = ADD32(0, 0XB8);
    // 0x801334FC: multu       $a2, $s5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133500: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80133504: addiu       $s4, $s4, -0x7AA8
    ctx->r20 = ADD32(ctx->r20, -0X7AA8);
    // 0x80133508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013350C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80133510: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80133514: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x80133518: mflo        $t6
    ctx->r14 = lo;
    // 0x8013351C: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x80133520: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x80133524: bne         $s6, $t8, L_8013358C
    if (ctx->r22 != ctx->r24) {
        // 0x80133528: nop
    
            goto L_8013358C;
    }
    // 0x80133528: nop

    // 0x8013352C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80133530: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80133534: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80133538: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8013353C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80133540:
    // 0x80133540: jal         0x800EC0EC
    // 0x80133544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x80133544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80133548: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8013354C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80133550: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x80133554: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133558: mflo        $t0
    ctx->r8 = lo;
    // 0x8013355C: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x80133560: lw          $t2, 0x4C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4C);
    // 0x80133564: bnel        $v0, $t2, L_80133574
    if (ctx->r2 != ctx->r10) {
        // 0x80133568: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133574;
    }
    goto skip_2;
    // 0x80133568: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8013356C: sw          $s2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r18;
    // 0x80133570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133574:
    // 0x80133574: bnel        $s0, $s3, L_80133540
    if (ctx->r16 != ctx->r19) {
        // 0x80133578: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80133540;
    }
    goto skip_3;
    // 0x80133578: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_3:
    // 0x8013357C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80133580: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80133584: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80133588: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_8013358C:
    // 0x8013358C: bne         $v1, $zero, L_8013359C
    if (ctx->r3 != 0) {
        // 0x80133590: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_8013359C;
    }
    // 0x80133590: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80133594: b           L_801335C8
    // 0x80133598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801335C8;
    // 0x80133598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013359C:
    // 0x8013359C: bne         $v0, $zero, L_801335AC
    if (ctx->r2 != 0) {
        // 0x801335A0: nop
    
            goto L_801335AC;
    }
    // 0x801335A0: nop

    // 0x801335A4: b           L_801335C8
    // 0x801335A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801335C8;
    // 0x801335A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801335AC:
    // 0x801335AC: bne         $a1, $zero, L_801335BC
    if (ctx->r5 != 0) {
        // 0x801335B0: nop
    
            goto L_801335BC;
    }
    // 0x801335B0: nop

    // 0x801335B4: b           L_801335C8
    // 0x801335B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_801335C8;
    // 0x801335B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801335BC:
    // 0x801335BC: bnel        $a0, $zero, L_801335CC
    if (ctx->r4 != 0) {
        // 0x801335C0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801335CC;
    }
    goto skip_4;
    // 0x801335C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x801335C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801335C8:
    // 0x801335C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801335CC:
    // 0x801335CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801335D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801335D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801335D8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801335DC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801335E0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x801335E4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x801335E8: jr          $ra
    // 0x801335EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801335EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_8037E830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E830: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037E834: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037E838: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8037E83C: lhu         $v0, 0x10($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X10);
    // 0x8037E840: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037E844: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037E848: bne         $v0, $at, L_8037E85C
    if (ctx->r2 != ctx->r1) {
        // 0x8037E84C: addiu       $a0, $zero, 0x120
        ctx->r4 = ADD32(0, 0X120);
            goto L_8037E85C;
    }
    // 0x8037E84C: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x8037E850: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8037E854: b           L_8037E86C
    // 0x8037E858: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_8037E86C;
    // 0x8037E858: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_8037E85C:
    // 0x8037E85C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8037E860: bne         $v0, $at, L_8037E86C
    if (ctx->r2 != ctx->r1) {
        // 0x8037E864: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8037E86C;
    }
    // 0x8037E864: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8037E868: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8037E86C:
    // 0x8037E86C: jal         0x803717A0
    // 0x8037E870: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037E870: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8037E874: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8037E878: beq         $v0, $zero, L_8037E8B0
    if (ctx->r2 == 0) {
        // 0x8037E87C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037E8B0;
    }
    // 0x8037E87C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037E880: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E884: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8037E888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037E88C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037E890: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x8037E894: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8037E898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037E89C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8037E8A0: jal         0x8037E97C
    // 0x8037E8A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_ovl8_8037E97C(rdram, ctx);
        goto after_1;
    // 0x8037E8A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x8037E8A8: b           L_8037E8B4
    // 0x8037E8AC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
        goto L_8037E8B4;
    // 0x8037E8AC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8037E8B0:
    // 0x8037E8B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037E8B4:
    // 0x8037E8B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037E8B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037E8BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E8C0: jr          $ra
    // 0x8037E8C4: nop

    return;
    // 0x8037E8C4: nop

;}
RECOMP_FUNC void mnPlayersVSMakePortraitWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DBC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132DC0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132DC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132DC8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132DCC: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80132DD0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80132DD4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132DD8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132DDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132DE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132DE4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132DE8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132DEC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132DF0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132DF4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132DF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132DFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132E00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132E04: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132E08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132E0C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E14: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132E18: jal         0x8000B93C
    // 0x80132E1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132E1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132E20: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132E24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132E28: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132E2C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132E30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132E38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132E3C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132E40: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132E44: jal         0x80007080
    // 0x80132E48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132E48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132E4C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132E50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132E54: jr          $ra
    // 0x80132E58: nop

    return;
    // 0x80132E58: nop

;}
RECOMP_FUNC void grWallpaperBonus3ProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104B58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80104B5C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80104B60: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80104B64: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80104B68: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80104B6C: addiu       $t8, $t8, -0x1840
    ctx->r24 = ADD32(ctx->r24, -0X1840);
    // 0x80104B70: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80104B74: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80104B78: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80104B7C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80104B80: jr          $ra
    // 0x80104B84: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80104B84: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mvUnknownMarioFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018D168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D16C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D170: jal         0x800E9B40
    // 0x8018D174: lw          $a0, -0x28B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X28B0);
    ftParamCheckHaveKey(rdram, ctx);
        goto after_0;
    // 0x8018D174: lw          $a0, -0x28B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X28B0);
    after_0:
    // 0x8018D178: bnel        $v0, $zero, L_8018D194
    if (ctx->r2 != 0) {
        // 0x8018D17C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D194;
    }
    goto skip_0;
    // 0x8018D17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D180: jal         0x800269C0
    // 0x8018D184: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8018D184: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_1:
    // 0x8018D188: jal         0x80005C74
    // 0x8018D18C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x8018D18C: nop

    after_2:
    // 0x8018D190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D194:
    // 0x8018D194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D198: jr          $ra
    // 0x8018D19C: nop

    return;
    // 0x8018D19C: nop

;}
RECOMP_FUNC void itBombHeiDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801775C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801775C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801775CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801775D0: jal         0x80173E58
    // 0x801775D4: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    itMapCheckMapProcAll(rdram, ctx);
        goto after_0;
    // 0x801775D4: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    after_0:
    // 0x801775D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801775DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801775E0: jr          $ra
    // 0x801775E4: nop

    return;
    // 0x801775E4: nop

;}
RECOMP_FUNC void itTaruBombCommonSetMapCollisionBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184FAC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184FB0: lwc1        $f4, -0x30B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30B4);
    // 0x80184FB4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80184FB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80184FBC: swc1        $f4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f4.u32l;
    // 0x80184FC0: lwc1        $f0, 0x7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80184FC4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80184FC8: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80184FCC: jr          $ra
    // 0x80184FD0: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80184FD0: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftParamStopVoiceRunProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E823C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E8240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E8248: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x800E824C: jal         0x800E8138
    // 0x800E8250: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamStopVoice(rdram, ctx);
        goto after_0;
    // 0x800E8250: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E8254: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E8258: lw          $v0, 0x9EC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9EC);
    // 0x800E825C: beql        $v0, $zero, L_800E8270
    if (ctx->r2 == 0) {
        // 0x800E8260: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8270;
    }
    goto skip_0;
    // 0x800E8260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E8264: jalr        $v0
    // 0x800E8268: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800E8268: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800E826C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8270:
    // 0x800E8270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E8274: jr          $ra
    // 0x800E8278: nop

    return;
    // 0x800E8278: nop

;}
RECOMP_FUNC void mvOpeningRunStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013256C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132578: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013257C: addiu       $a0, $a0, 0x2650
    ctx->r4 = ADD32(ctx->r4, 0X2650);
    // 0x80132580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132584: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132588: jal         0x80007024
    // 0x8013258C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013258C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132590: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132594: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132598: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013259C: addiu       $t9, $t9, 0x2AB0
    ctx->r25 = ADD32(ctx->r25, 0X2AB0);
    // 0x801325A0: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801325A4: addiu       $a0, $a0, 0x266C
    ctx->r4 = ADD32(ctx->r4, 0X266C);
    // 0x801325A8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801325AC: jal         0x8000683C
    // 0x801325B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801325B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801325B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801325B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801325BC: jr          $ra
    // 0x801325C0: nop

    return;
    // 0x801325C0: nop

;}
RECOMP_FUNC void ftBossHarauProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015940C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159414: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80159418: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015941C: nop

    // 0x80159420: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80159424: nop

    // 0x80159428: bc1fl       L_80159460
    if (!c1cs) {
        // 0x8015942C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80159460;
    }
    goto skip_0;
    // 0x8015942C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80159430: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159434: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80159438: lw          $t6, 0xEC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XEC);
    // 0x8015943C: bne         $t6, $at, L_80159454
    if (ctx->r14 != ctx->r1) {
        // 0x80159440: nop
    
            goto L_80159454;
    }
    // 0x80159440: nop

    // 0x80159444: jal         0x80159040
    // 0x80159448: nop

    ftBossWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159448: nop

    after_0:
    // 0x8015944C: b           L_80159460
    // 0x80159450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80159460;
    // 0x80159450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159454:
    // 0x80159454: jal         0x801593E0
    // 0x80159458: nop

    ftBossHarauResetStatus(rdram, ctx);
        goto after_1;
    // 0x80159458: nop

    after_1:
    // 0x8015945C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159460:
    // 0x80159460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159464: jr          $ra
    // 0x80159468: nop

    return;
    // 0x80159468: nop

;}
RECOMP_FUNC void mnVSRecordMakeStatsGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801333F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801333F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801333F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80133400: jal         0x80009968
    // 0x80133404: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133404: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133408: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013340C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133410: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133414: addiu       $a1, $a1, 0x328C
    ctx->r5 = ADD32(ctx->r5, 0X328C);
    // 0x80133418: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013341C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133420: jal         0x80009DF4
    // 0x80133424: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133424: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013342C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133430: jr          $ra
    // 0x80133434: nop

    return;
    // 0x80133434: nop

;}
RECOMP_FUNC void func_ovl2_80113744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011374C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80113750: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80113754: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80113758: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8011375C: bnel        $t6, $at, L_80113784
    if (ctx->r14 != ctx->r1) {
        // 0x80113760: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80113784;
    }
    goto skip_0;
    // 0x80113760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80113764: jal         0x8000B2B8
    // 0x80113768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x80113768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8011376C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80113770: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80113774: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x80113778: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8011377C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    // 0x80113780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80113784:
    // 0x80113784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113788: jr          $ra
    // 0x8011378C: nop

    return;
    // 0x8011378C: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueSetFighterScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013209C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x801320A0: addiu       $t7, $t7, 0xD90
    ctx->r15 = ADD32(ctx->r15, 0XD90);
    // 0x801320A4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801320A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801320AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801320B0: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801320B4: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
    // 0x801320B8: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x801320BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801320C0: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x801320C4: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x801320C8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801320CC: jr          $ra
    // 0x801320D0: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
    return;
    // 0x801320D0: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftBossMoveProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801591A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801591A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801591A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801591AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801591B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801591B4: lw          $a2, 0x74($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X74);
    // 0x801591B8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801591BC: addiu       $a1, $s0, 0xB1C
    ctx->r5 = ADD32(ctx->r16, 0XB1C);
    // 0x801591C0: jal         0x8001902C
    // 0x801591C4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x801591C4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_0:
    // 0x801591C8: jal         0x80018F7C
    // 0x801591CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x801591CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x801591D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801591D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801591D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801591DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801591E0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801591E4: nop

    // 0x801591E8: bc1fl       L_80159214
    if (!c1cs) {
        // 0x801591EC: swc1        $f2, 0xB28($s0)
        MEM_W(0XB28, ctx->r16) = ctx->f2.u32l;
            goto L_80159214;
    }
    goto skip_0;
    // 0x801591EC: swc1        $f2, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->f2.u32l;
    skip_0:
    // 0x801591F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801591F4: nop

    // 0x801591F8: swc1        $f6, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->f6.u32l;
    // 0x801591FC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80159200: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80159204: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80159208: b           L_8015924C
    // 0x8015920C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
        goto L_8015924C;
    // 0x8015920C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80159210: swc1        $f2, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->f2.u32l;
L_80159214:
    // 0x80159214: jal         0x80018EE0
    // 0x80159218: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x80159218: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8015921C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159220: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80159224: lwc1        $f16, -0x3840($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3840);
    // 0x80159228: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8015922C: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80159230: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80159234: jal         0x800190B0
    // 0x80159238: nop

    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x80159238: nop

    after_3:
    // 0x8015923C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80159240: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80159244: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80159248: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
L_8015924C:
    // 0x8015924C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80159254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80159258: jr          $ra
    // 0x8015925C: nop

    return;
    // 0x8015925C: nop

;}
RECOMP_FUNC void syMatrixTraRotPitchRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D210: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D214: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001D218: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001D21C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001D220: jal         0x8001D140
    // 0x8001D224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotPitchRF(rdram, ctx);
        goto after_0;
    // 0x8001D224: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001D228: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001D22C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D230: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001D234: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001D238: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001D23C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D240: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001D244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D24C: jr          $ra
    // 0x8001D250: nop

    return;
    // 0x8001D250: nop

;}
RECOMP_FUNC void ftParamSetHitStatusColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E87A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E87A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E87A8: beq         $a1, $at, L_800E87D0
    if (ctx->r5 == ctx->r1) {
        // 0x800E87AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800E87D0;
    }
    // 0x800E87AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E87B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E87B4: beq         $a1, $at, L_800E87E4
    if (ctx->r5 == ctx->r1) {
        // 0x800E87B8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E87E4;
    }
    // 0x800E87B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E87BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E87C0: beq         $a1, $at, L_800E87F4
    if (ctx->r5 == ctx->r1) {
        // 0x800E87C4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E87F4;
    }
    // 0x800E87C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E87C8: b           L_800E8800
    // 0x800E87CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E8800;
    // 0x800E87CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E87D0:
    // 0x800E87D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800E87D4: jal         0x800E9814
    // 0x800E87D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800E87D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800E87DC: b           L_800E8800
    // 0x800E87E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E8800;
    // 0x800E87E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E87E4:
    // 0x800E87E4: jal         0x800E9814
    // 0x800E87E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_1;
    // 0x800E87E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800E87EC: b           L_800E8800
    // 0x800E87F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E8800;
    // 0x800E87F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E87F4:
    // 0x800E87F4: jal         0x800E9814
    // 0x800E87F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x800E87F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800E87FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8800:
    // 0x800E8800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8804: jr          $ra
    // 0x800E8808: nop

    return;
    // 0x800E8808: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveUseItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013815C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80138160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138164: lw          $t6, 0x84C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84C);
    // 0x80138168: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013816C: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x80138170: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80138174: beql        $v0, $zero, L_801382E4
    if (ctx->r2 == 0) {
        // 0x80138178: addiu       $a2, $a0, 0x1CC
        ctx->r6 = ADD32(ctx->r4, 0X1CC);
            goto L_801382E4;
    }
    goto skip_0;
    // 0x80138178: addiu       $a2, $a0, 0x1CC
    ctx->r6 = ADD32(ctx->r4, 0X1CC);
    skip_0:
    // 0x8013817C: beq         $v0, $at, L_80138194
    if (ctx->r2 == ctx->r1) {
        // 0x80138180: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80138194;
    }
    // 0x80138180: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138184: beql        $v0, $at, L_801382E4
    if (ctx->r2 == ctx->r1) {
        // 0x80138188: addiu       $a2, $a0, 0x1CC
        ctx->r6 = ADD32(ctx->r4, 0X1CC);
            goto L_801382E4;
    }
    goto skip_1;
    // 0x80138188: addiu       $a2, $a0, 0x1CC
    ctx->r6 = ADD32(ctx->r4, 0X1CC);
    skip_1:
    // 0x8013818C: b           L_80138340
    // 0x80138190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138340;
    // 0x80138190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138194:
    // 0x80138194: lhu         $t7, 0x33E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X33E);
    // 0x80138198: addiu       $a2, $a0, 0x1CC
    ctx->r6 = ADD32(ctx->r4, 0X1CC);
    // 0x8013819C: beql        $t7, $zero, L_801382D8
    if (ctx->r15 == 0) {
        // 0x801381A0: lbu         $t1, 0x34($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X34);
            goto L_801382D8;
    }
    goto skip_2;
    // 0x801381A0: lbu         $t1, 0x34($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X34);
    skip_2:
    // 0x801381A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801381A8: jal         0x8013295C
    // 0x801381AC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_0;
    // 0x801381AC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x801381B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801381B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801381B8: lbu         $t8, 0x13($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X13);
    // 0x801381BC: addiu       $a2, $a0, 0x1CC
    ctx->r6 = ADD32(ctx->r4, 0X1CC);
    // 0x801381C0: lw          $v0, 0x6C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X6C);
    // 0x801381C4: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x801381C8: bnel        $at, $zero, L_80138204
    if (ctx->r1 != 0) {
        // 0x801381CC: lw          $v0, 0x8E8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8E8);
            goto L_80138204;
    }
    goto skip_3;
    // 0x801381CC: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    skip_3:
    // 0x801381D0: beql        $v0, $zero, L_80138204
    if (ctx->r2 == 0) {
        // 0x801381D4: lw          $v0, 0x8E8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8E8);
            goto L_80138204;
    }
    goto skip_4;
    // 0x801381D4: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    skip_4:
    // 0x801381D8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801381DC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801381E0: beq         $v1, $at, L_801381F0
    if (ctx->r3 == ctx->r1) {
        // 0x801381E4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801381F0;
    }
    // 0x801381E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801381E8: bnel        $v1, $at, L_80138204
    if (ctx->r3 != ctx->r1) {
        // 0x801381EC: lw          $v0, 0x8E8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8E8);
            goto L_80138204;
    }
    goto skip_5;
    // 0x801381EC: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    skip_5:
L_801381F0:
    // 0x801381F0: jal         0x80132564
    // 0x801381F4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_1;
    // 0x801381F4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_1:
    // 0x801381F8: b           L_80138340
    // 0x801381FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138340;
    // 0x801381FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80138200: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
L_80138204:
    // 0x80138204: lwc1        $f2, 0x64($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80138208: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8013820C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80138210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138214: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80138218: nop

    // 0x8013821C: bc1fl       L_80138234
    if (!c1cs) {
        // 0x80138220: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80138234;
    }
    goto skip_6;
    // 0x80138220: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_6:
    // 0x80138224: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80138228: b           L_80138234
    // 0x8013822C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80138234;
    // 0x8013822C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80138230: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_80138234:
    // 0x80138234: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80138238: nop

    // 0x8013823C: bc1f        L_801382C0
    if (!c1cs) {
        // 0x80138240: nop
    
            goto L_801382C0;
    }
    // 0x80138240: nop

    // 0x80138244: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x80138248: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013824C: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80138250: bne         $t9, $at, L_801382B0
    if (ctx->r25 != ctx->r1) {
        // 0x80138254: nop
    
            goto L_801382B0;
    }
    // 0x80138254: nop

    // 0x80138258: lw          $t0, 0x44($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X44);
    // 0x8013825C: lwc1        $f6, 0x60($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X60);
    // 0x80138260: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80138264: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80138268: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013826C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80138270: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138274: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80138278: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8013827C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80138280: nop

    // 0x80138284: bc1t        L_801382A0
    if (c1cs) {
        // 0x80138288: nop
    
            goto L_801382A0;
    }
    // 0x80138288: nop

    // 0x8013828C: lwc1        $f6, -0x40FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X40FC);
    // 0x80138290: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80138294: nop

    // 0x80138298: bc1f        L_801382B0
    if (!c1cs) {
        // 0x8013829C: nop
    
            goto L_801382B0;
    }
    // 0x8013829C: nop

L_801382A0:
    // 0x801382A0: jal         0x80134E98
    // 0x801382A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_2;
    // 0x801382A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x801382A8: b           L_801382CC
    // 0x801382AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_801382CC;
    // 0x801382AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_801382B0:
    // 0x801382B0: jal         0x80132564
    // 0x801382B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_3;
    // 0x801382B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x801382B8: b           L_801382CC
    // 0x801382BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_801382CC;
    // 0x801382BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_801382C0:
    // 0x801382C0: jal         0x80134E98
    // 0x801382C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_4;
    // 0x801382C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_4:
    // 0x801382C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_801382CC:
    // 0x801382CC: b           L_8013833C
    // 0x801382D0: sb          $zero, 0x34($a2)
    MEM_B(0X34, ctx->r6) = 0;
        goto L_8013833C;
    // 0x801382D0: sb          $zero, 0x34($a2)
    MEM_B(0X34, ctx->r6) = 0;
    // 0x801382D4: lbu         $t1, 0x34($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X34);
L_801382D8:
    // 0x801382D8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801382DC: sb          $t2, 0x34($a2)
    MEM_B(0X34, ctx->r6) = ctx->r10;
    // 0x801382E0: addiu       $a2, $a0, 0x1CC
    ctx->r6 = ADD32(ctx->r4, 0X1CC);
L_801382E4:
    // 0x801382E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801382E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801382EC: jal         0x8013295C
    // 0x801382F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_5;
    // 0x801382F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_5:
    // 0x801382F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801382F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801382FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80138300: lbu         $t3, 0x34($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X34);
    // 0x80138304: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x80138308: beql        $at, $zero, L_80138320
    if (ctx->r1 == 0) {
        // 0x8013830C: addiu       $a1, $zero, 0x2B
        ctx->r5 = ADD32(0, 0X2B);
            goto L_80138320;
    }
    goto skip_7;
    // 0x8013830C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    skip_7:
    // 0x80138310: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x80138314: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80138318: bne         $t4, $at, L_80138334
    if (ctx->r12 != ctx->r1) {
        // 0x8013831C: addiu       $a1, $zero, 0x2B
        ctx->r5 = ADD32(0, 0X2B);
            goto L_80138334;
    }
    // 0x8013831C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
L_80138320:
    // 0x80138320: jal         0x80132564
    // 0x80138324: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_6;
    // 0x80138324: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_6:
    // 0x80138328: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8013832C: b           L_8013833C
    // 0x80138330: sb          $zero, 0x34($a2)
    MEM_B(0X34, ctx->r6) = 0;
        goto L_8013833C;
    // 0x80138330: sb          $zero, 0x34($a2)
    MEM_B(0X34, ctx->r6) = 0;
L_80138334:
    // 0x80138334: jal         0x80132564
    // 0x80138338: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_7;
    // 0x80138338: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_7:
L_8013833C:
    // 0x8013833C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138340:
    // 0x80138340: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80138344: jr          $ra
    // 0x80138348: nop

    return;
    // 0x80138348: nop

;}
RECOMP_FUNC void func_ovl2_800EDBA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDBA4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800EDBA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800EDBAC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800EDBB0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800EDBB4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EDBB8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800EDBBC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EDBC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EDBC4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800EDBC8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EDBCC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800EDBD0: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800EDBD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800EDBD8: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x800EDBDC: lw          $v0, 0x190($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X190);
    // 0x800EDBE0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800EDBE4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800EDBE8: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800EDBEC: bnel        $v0, $zero, L_800EDCE8
    if (ctx->r2 != 0) {
        // 0x800EDBF0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800EDCE8;
    }
    goto skip_0;
    // 0x800EDBF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x800EDBF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800EDBF8: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x800EDBFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDC00:
    // 0x800EDC00: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800EDC04: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800EDC08: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x800EDC0C: lbu         $t8, 0x5($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X5);
    // 0x800EDC10: beql        $t8, $zero, L_800EDC24
    if (ctx->r24 == 0) {
        // 0x800EDC14: lw          $t9, 0x14($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X14);
            goto L_800EDC24;
    }
    goto skip_1;
    // 0x800EDC14: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    skip_1:
    // 0x800EDC18: b           L_800EDC78
    // 0x800EDC1C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800EDC78;
    // 0x800EDC1C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800EDC20: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
L_800EDC24:
    // 0x800EDC24: bnel        $v0, $t9, L_800EDC6C
    if (ctx->r2 != ctx->r25) {
        // 0x800EDC28: sw          $a0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r4;
            goto L_800EDC6C;
    }
    goto skip_2;
    // 0x800EDC28: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    skip_2:
    // 0x800EDC2C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800EDC30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800EDC34: bnel        $t0, $zero, L_800EDC50
    if (ctx->r8 != 0) {
        // 0x800EDC38: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_800EDC50;
    }
    goto skip_3;
    // 0x800EDC38: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    skip_3:
    // 0x800EDC3C: jal         0x800ECDE4
    // 0x800EDC40: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    gmCollisionTransformMatrixAll(rdram, ctx);
        goto after_0;
    // 0x800EDC40: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    after_0:
    // 0x800EDC44: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800EDC48: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
    // 0x800EDC4C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800EDC50:
    // 0x800EDC50: addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // 0x800EDC54: jal         0x800ECD80
    // 0x800EDC58: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    gmCollisionCopyMatrix(rdram, ctx);
        goto after_1;
    // 0x800EDC58: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    after_1:
    // 0x800EDC5C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800EDC60: b           L_800EDC78
    // 0x800EDC64: sb          $s4, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r20;
        goto L_800EDC78;
    // 0x800EDC64: sb          $s4, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r20;
    // 0x800EDC68: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
L_800EDC6C:
    // 0x800EDC6C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x800EDC70: b           L_800EDC00
    // 0x800EDC74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800EDC00;
    // 0x800EDC74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800EDC78:
    // 0x800EDC78: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800EDC7C: bltz        $s0, L_800EDDDC
    if (SIGNED(ctx->r16) < 0) {
        // 0x800EDC80: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_800EDDDC;
    }
    // 0x800EDC80: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800EDC84: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x800EDC88: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
L_800EDC8C:
    // 0x800EDC8C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800EDC90: addiu       $s3, $s2, 0x50
    ctx->r19 = ADD32(ctx->r18, 0X50);
    // 0x800EDC94: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800EDC98: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800EDC9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EDCA0: bnel        $t5, $zero, L_800EDCB8
    if (ctx->r13 != 0) {
        // 0x800EDCA4: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_800EDCB8;
    }
    goto skip_4;
    // 0x800EDCA4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    skip_4:
    // 0x800EDCA8: jal         0x800ECDE4
    // 0x800EDCAC: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    gmCollisionTransformMatrixAll(rdram, ctx);
        goto after_2;
    // 0x800EDCAC: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x800EDCB0: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x800EDCB4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
L_800EDCB8:
    // 0x800EDCB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EDCBC: jal         0x800ED490
    // 0x800EDCC0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_ovl2_800ED490(rdram, ctx);
        goto after_3;
    // 0x800EDCC0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_3:
    // 0x800EDCC4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800EDCC8: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x800EDCCC: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x800EDCD0: sb          $s4, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r20;
    // 0x800EDCD4: beq         $at, $zero, L_800EDC8C
    if (ctx->r1 == 0) {
        // 0x800EDCD8: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_800EDC8C;
    }
    // 0x800EDCD8: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x800EDCDC: b           L_800EDDE0
    // 0x800EDCE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800EDDE0;
    // 0x800EDCE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDCE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800EDCE8:
    // 0x800EDCE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDCEC:
    // 0x800EDCEC: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800EDCF0: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800EDCF4: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x800EDCF8: lbu         $t7, 0x5($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X5);
    // 0x800EDCFC: beql        $t7, $zero, L_800EDD10
    if (ctx->r15 == 0) {
        // 0x800EDD00: lw          $t8, 0x14($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X14);
            goto L_800EDD10;
    }
    goto skip_5;
    // 0x800EDD00: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    skip_5:
    // 0x800EDD04: b           L_800EDD70
    // 0x800EDD08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
        goto L_800EDD70;
    // 0x800EDD08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800EDD0C: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
L_800EDD10:
    // 0x800EDD10: bnel        $v0, $t8, L_800EDD64
    if (ctx->r2 != ctx->r24) {
        // 0x800EDD14: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800EDD64;
    }
    goto skip_6;
    // 0x800EDD14: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    skip_6:
    // 0x800EDD18: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800EDD1C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800EDD20: addiu       $a2, $s2, 0x10
    ctx->r6 = ADD32(ctx->r18, 0X10);
    // 0x800EDD24: bnel        $t9, $zero, L_800EDD48
    if (ctx->r25 != 0) {
        // 0x800EDD28: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800EDD48;
    }
    goto skip_7;
    // 0x800EDD28: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    skip_7:
    // 0x800EDD2C: jal         0x800ECFF4
    // 0x800EDD30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gmCollisionSetMatrixNcs(rdram, ctx);
        goto after_4;
    // 0x800EDD30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800EDD34: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800EDD38: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800EDD3C: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
    // 0x800EDD40: sb          $s4, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r20;
    // 0x800EDD44: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800EDD48:
    // 0x800EDD48: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800EDD4C: addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // 0x800EDD50: jal         0x800ECD80
    // 0x800EDD54: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    gmCollisionCopyMatrix(rdram, ctx);
        goto after_5;
    // 0x800EDD54: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    after_5:
    // 0x800EDD58: b           L_800EDD70
    // 0x800EDD5C: sb          $s4, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r20;
        goto L_800EDD70;
    // 0x800EDD5C: sb          $s4, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r20;
    // 0x800EDD60: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
L_800EDD64:
    // 0x800EDD64: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x800EDD68: b           L_800EDCEC
    // 0x800EDD6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800EDCEC;
    // 0x800EDD6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800EDD70:
    // 0x800EDD70: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800EDD74: bltz        $s0, L_800EDDDC
    if (SIGNED(ctx->r16) < 0) {
        // 0x800EDD78: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_800EDDDC;
    }
    // 0x800EDD78: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800EDD7C: addiu       $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800EDD80: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
L_800EDD84:
    // 0x800EDD84: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800EDD88: addiu       $s3, $s2, 0x50
    ctx->r19 = ADD32(ctx->r18, 0X50);
    // 0x800EDD8C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800EDD90: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800EDD94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EDD98: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x800EDD9C: bnel        $t4, $zero, L_800EDDB8
    if (ctx->r12 != 0) {
        // 0x800EDDA0: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_800EDDB8;
    }
    goto skip_8;
    // 0x800EDDA0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    skip_8:
    // 0x800EDDA4: jal         0x800ECFF4
    // 0x800EDDA8: addiu       $a3, $s2, 0x90
    ctx->r7 = ADD32(ctx->r18, 0X90);
    gmCollisionSetMatrixNcs(rdram, ctx);
        goto after_6;
    // 0x800EDDA8: addiu       $a3, $s2, 0x90
    ctx->r7 = ADD32(ctx->r18, 0X90);
    after_6:
    // 0x800EDDAC: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x800EDDB0: sb          $s4, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r20;
    // 0x800EDDB4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
L_800EDDB8:
    // 0x800EDDB8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EDDBC: jal         0x800ED490
    // 0x800EDDC0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_ovl2_800ED490(rdram, ctx);
        goto after_7;
    // 0x800EDDC0: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_7:
    // 0x800EDDC4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800EDDC8: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x800EDDCC: sltu        $at, $s1, $t5
    ctx->r1 = ctx->r17 < ctx->r13 ? 1 : 0;
    // 0x800EDDD0: sb          $s4, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r20;
    // 0x800EDDD4: beq         $at, $zero, L_800EDD84
    if (ctx->r1 == 0) {
        // 0x800EDDD8: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_800EDD84;
    }
    // 0x800EDDD8: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_800EDDDC:
    // 0x800EDDDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800EDDE0:
    // 0x800EDDE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EDDE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EDDE8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDDEC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800EDDF0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800EDDF4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800EDDF8: jr          $ra
    // 0x800EDDFC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800EDDFC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void mnTitleFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133F94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133F98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133FA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133FA4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80133FA8:
    // 0x80133FA8: jal         0x80004494
    // 0x80133FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_0;
    // 0x80133FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133FB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80133FB4: bne         $s0, $s1, L_80133FA8
    if (ctx->r16 != ctx->r17) {
        // 0x80133FB8: nop
    
            goto L_80133FA8;
    }
    // 0x80133FB8: nop

    // 0x80133FBC: jal         0x80134140
    // 0x80133FC0: nop

    mnTitleLoadFiles(rdram, ctx);
        goto after_1;
    // 0x80133FC0: nop

    after_1:
    // 0x80133FC4: jal         0x80133F3C
    // 0x80133FC8: nop

    mnTitleMakeActors(rdram, ctx);
        goto after_2;
    // 0x80133FC8: nop

    after_2:
    // 0x80133FCC: jal         0x80115890
    // 0x80133FD0: nop

    efParticleInitAll(rdram, ctx);
        goto after_3;
    // 0x80133FD0: nop

    after_3:
    // 0x80133FD4: jal         0x80133DDC
    // 0x80133FD8: nop

    mnTitleMakeLogoFire(rdram, ctx);
        goto after_4;
    // 0x80133FD8: nop

    after_4:
    // 0x80133FDC: jal         0x80133A94
    // 0x80133FE0: nop

    mnTitleMakeCameras(rdram, ctx);
        goto after_5;
    // 0x80133FE0: nop

    after_5:
    // 0x80133FE4: jal         0x80131CF4
    // 0x80133FE8: nop

    mnTitleInitVars(rdram, ctx);
        goto after_6;
    // 0x80133FE8: nop

    after_6:
    // 0x80133FEC: jal         0x80132B70
    // 0x80133FF0: nop

    mnTitleMakeFire(rdram, ctx);
        goto after_7;
    // 0x80133FF0: nop

    after_7:
    // 0x80133FF4: jal         0x80132FD8
    // 0x80133FF8: nop

    mnTitleMakeLogo(rdram, ctx);
        goto after_8;
    // 0x80133FF8: nop

    after_8:
    // 0x80133FFC: jal         0x801332E4
    // 0x80134000: nop

    mnTitleMakeLabels(rdram, ctx);
        goto after_9;
    // 0x80134000: nop

    after_9:
    // 0x80134004: jal         0x80133634
    // 0x80134008: nop

    func_ovl10_80133634(rdram, ctx);
        goto after_10;
    // 0x80134008: nop

    after_10:
    // 0x8013400C: jal         0x80133504
    // 0x80134010: nop

    mnTitleMakePressStart(rdram, ctx);
        goto after_11;
    // 0x80134010: nop

    after_11:
    // 0x80134014: jal         0x8013366C
    // 0x80134018: nop

    mnTitleMakeSlash(rdram, ctx);
        goto after_12;
    // 0x80134018: nop

    after_12:
    // 0x8013401C: jal         0x80133E68
    // 0x80134020: nop

    mnTitleMakeLogoFireParticles(rdram, ctx);
        goto after_13;
    // 0x80134020: nop

    after_13:
    // 0x80134024: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134028: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x8013402C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80134030: bnel        $t6, $at, L_80134064
    if (ctx->r14 != ctx->r1) {
        // 0x80134034: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134064;
    }
    goto skip_0;
    // 0x80134034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80134038: jal         0x8000092C
    // 0x8013403C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_14;
    // 0x8013403C: nop

    after_14:
    // 0x80134040: sltiu       $at, $v0, 0x1077
    ctx->r1 = ctx->r2 < 0X1077 ? 1 : 0;
    // 0x80134044: beql        $at, $zero, L_80134064
    if (ctx->r1 == 0) {
        // 0x80134048: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134064;
    }
    goto skip_1;
    // 0x80134048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8013404C:
    // 0x8013404C: jal         0x8000092C
    // 0x80134050: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_15;
    // 0x80134050: nop

    after_15:
    // 0x80134054: sltiu       $at, $v0, 0x1077
    ctx->r1 = ctx->r2 < 0X1077 ? 1 : 0;
    // 0x80134058: bne         $at, $zero, L_8013404C
    if (ctx->r1 != 0) {
        // 0x8013405C: nop
    
            goto L_8013404C;
    }
    // 0x8013405C: nop

    // 0x80134060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134064:
    // 0x80134064: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134068: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013406C: jr          $ra
    // 0x80134070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80134070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_8037217C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037217C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372184: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80372188: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8037218C: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x80372190: lw          $v1, 0x48($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X48);
    // 0x80372194: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80372198: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x8037219C: sw          $t6, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r14;
    // 0x803721A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x803721A4: jal         0x80025100
    // 0x803721A8: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    spDraw(rdram, ctx);
        goto after_0;
    // 0x803721A8: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x803721AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x803721B0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x803721B4: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x803721B8: lw          $t7, 0x4C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4C);
    // 0x803721BC: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x803721C0: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x803721C4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x803721C8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x803721CC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x803721D0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x803721D4: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x803721D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803721DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803721E0: jr          $ra
    // 0x803721E4: nop

    return;
    // 0x803721E4: nop

;}
RECOMP_FUNC void func_ovl28_801332CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332CC: jr          $ra
    // 0x801332D0: nop

    return;
    // 0x801332D0: nop

;}
RECOMP_FUNC void ftCommonCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149B80: jal         0x800DDE50
    // 0x80149B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80149B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80149B88: bnel        $v0, $zero, L_80149B9C
    if (ctx->r2 != 0) {
        // 0x80149B8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149B9C;
    }
    goto skip_0;
    // 0x80149B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80149B90: jal         0x80149AC8
    // 0x80149B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonCatchCaptureSetStatusRelease(rdram, ctx);
        goto after_1;
    // 0x80149B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80149B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80149B9C:
    // 0x80149B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149BA0: jr          $ra
    // 0x80149BA4: nop

    return;
    // 0x80149BA4: nop

;}
RECOMP_FUNC void func_8002C3D0_2CFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C3D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002C3D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002C3D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002C3DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002C3E0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x8002C3E4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8002C3E8: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8002C3EC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8002C3F0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8002C3F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002C3F8: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002C3FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002C400: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x8002C404: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x8002C408: sh          $t7, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r15;
    // 0x8002C40C: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x8002C410: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8002C414: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8002C418: sh          $t9, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r25;
    // 0x8002C41C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x8002C420: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x8002C424: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x8002C428: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x8002C42C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8002C430: sb          $t0, 0x3D($a0)
    MEM_B(0X3D, ctx->r4) = ctx->r8;
    // 0x8002C434: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x8002C438: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8002C43C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002C440: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8002C444: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x8002C448: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002C44C: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8002C450: sw          $t3, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r11;
    // 0x8002C454: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x8002C458: sh          $t5, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r13;
    // 0x8002C45C: sw          $t4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r12;
    // 0x8002C460: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8002C464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C468: sb          $t6, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r14;
    // 0x8002C46C: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x8002C470: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002C474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C478: jal         0x8001E5F4
    // 0x8002C47C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002C47C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002C480: sw          $v0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r2;
    // 0x8002C484: jal         0x8002F4A0
    // 0x8002C488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __n_initChanState(rdram, ctx);
        goto after_1;
    // 0x8002C488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002C48C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8002C490: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x8002C494: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002C498: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C49C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C4A0: jal         0x8001E5F4
    // 0x8002C4A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8002C4A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8002C4A8: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8002C4AC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C4B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C4B8: blez        $t9, L_8002C4E8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002C4BC: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_8002C4E8;
    }
    // 0x8002C4BC: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x8002C4C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002C4C4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
L_8002C4C8:
    // 0x8002C4C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002C4CC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8002C4D0: sw          $v1, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r3;
    // 0x8002C4D4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4D8: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x8002C4DC: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C4E0: bnel        $at, $zero, L_8002C4C8
    if (ctx->r1 != 0) {
        // 0x8002C4E4: lw          $t0, 0x74($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X74);
            goto L_8002C4C8;
    }
    goto skip_0;
    // 0x8002C4E4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    skip_0:
L_8002C4E8:
    // 0x8002C4E8: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x8002C4EC: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8002C4F0: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x8002C4F4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C4F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C4FC: jal         0x8001E5F4
    // 0x8002C500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x8002C500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8002C504: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8002C508: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002C50C: jal         0x80028F70
    // 0x8002C510: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x8002C510: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x8002C514: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x8002C518: addiu       $t3, $t3, -0x42D4
    ctx->r11 = ADD32(ctx->r11, -0X42D4);
    // 0x8002C51C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8002C520: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8002C524: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x8002C528: jal         0x8002D620
    // 0x8002C52C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynAddSeqPlayer(rdram, ctx);
        goto after_5;
    // 0x8002C52C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8002C530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002C534: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C538: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002C53C: jr          $ra
    // 0x8002C540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002C540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void wpMainPlayFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167F10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80167F14: lw          $t6, 0x270($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X270);
    // 0x80167F18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167F1C: beql        $t6, $zero, L_80167F34
    if (ctx->r14 == 0) {
        // 0x80167F20: lhu         $a0, 0x1E($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0X1E);
            goto L_80167F34;
    }
    goto skip_0;
    // 0x80167F20: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    skip_0:
    // 0x80167F24: jal         0x80167EB0
    // 0x80167F28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    wpMainStopFGM(rdram, ctx);
        goto after_0;
    // 0x80167F28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80167F2C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80167F30: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
L_80167F34:
    // 0x80167F34: jal         0x800269C0
    // 0x80167F38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80167F38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80167F3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80167F40: beq         $v0, $zero, L_80167F54
    if (ctx->r2 == 0) {
        // 0x80167F44: sw          $v0, 0x270($a2)
        MEM_W(0X270, ctx->r6) = ctx->r2;
            goto L_80167F54;
    }
    // 0x80167F44: sw          $v0, 0x270($a2)
    MEM_W(0X270, ctx->r6) = ctx->r2;
    // 0x80167F48: lhu         $t8, 0x26($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X26);
    // 0x80167F4C: b           L_80167F58
    // 0x80167F50: sh          $t8, 0x274($a2)
    MEM_H(0X274, ctx->r6) = ctx->r24;
        goto L_80167F58;
    // 0x80167F50: sh          $t8, 0x274($a2)
    MEM_H(0X274, ctx->r6) = ctx->r24;
L_80167F54:
    // 0x80167F54: sh          $zero, 0x274($a2)
    MEM_H(0X274, ctx->r6) = 0;
L_80167F58:
    // 0x80167F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167F60: jr          $ra
    // 0x80167F64: nop

    return;
    // 0x80167F64: nop

;}
RECOMP_FUNC void mnPlayers1PBonusDetectBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801357AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801357B0: lw          $t6, 0x7724($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7724);
    // 0x801357B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801357B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801357BC: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x801357C0: bne         $at, $zero, L_801357F0
    if (ctx->r1 != 0) {
        // 0x801357C4: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_801357F0;
    }
    // 0x801357C4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801357C8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x801357CC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801357D0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x801357D4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801357D8: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x801357DC: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x801357E0: beql        $t9, $zero, L_801357F4
    if (ctx->r25 == 0) {
        // 0x801357E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801357F4;
    }
    goto skip_0;
    // 0x801357E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801357E8: jal         0x80135740
    // 0x801357EC: nop

    mnPlayers1PBonusBackTo1PMode(rdram, ctx);
        goto after_0;
    // 0x801357EC: nop

    after_0:
L_801357F0:
    // 0x801357F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801357F4:
    // 0x801357F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801357F8: jr          $ra
    // 0x801357FC: nop

    return;
    // 0x801357FC: nop

;}
RECOMP_FUNC void mnSoundTestStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133988: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013398C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133994: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80133998: addiu       $a0, $a0, 0x4240
    ctx->r4 = ADD32(ctx->r4, 0X4240);
    // 0x8013399C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801339A0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801339A4: jal         0x80007024
    // 0x801339A8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801339A8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801339AC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801339B0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801339B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801339B8: addiu       $t9, $t9, 0x4480
    ctx->r25 = ADD32(ctx->r25, 0X4480);
    // 0x801339BC: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801339C0: addiu       $a0, $a0, 0x425C
    ctx->r4 = ADD32(ctx->r4, 0X425C);
    // 0x801339C4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801339C8: jal         0x8000683C
    // 0x801339CC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801339CC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801339D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801339D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801339D8: jr          $ra
    // 0x801339DC: nop

    return;
    // 0x801339DC: nop

;}
RECOMP_FUNC void ftCommonHammerFallSetStatusJump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147D30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80147D34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80147D38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80147D3C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80147D40: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80147D44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80147D48: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x80147D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147D50: jal         0x800DEEC8
    // 0x80147D54: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80147D54: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_0:
    // 0x80147D58: jal         0x800F3828
    // 0x80147D5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_1;
    // 0x80147D5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80147D60: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80147D64: jal         0x800F385C
    // 0x80147D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_2;
    // 0x80147D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80147D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80147D70: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80147D74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80147D78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147D7C: jal         0x800E6F24
    // 0x80147D80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x80147D80: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80147D84: jal         0x800F388C
    // 0x80147D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_4;
    // 0x80147D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80147D8C: lw          $v0, 0xB20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB20);
    // 0x80147D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80147D94: beq         $v0, $at, L_80147DBC
    if (ctx->r2 == ctx->r1) {
        // 0x80147D98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80147DBC;
    }
    // 0x80147D98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80147D9C: bne         $v0, $at, L_80147DBC
    if (ctx->r2 != ctx->r1) {
        // 0x80147DA0: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_80147DBC;
    }
    // 0x80147DA0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80147DA4: lb          $a0, 0x1C2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C2);
    // 0x80147DA8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80147DAC: jal         0x8013F6A0
    // 0x80147DB0: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    ftCommonJumpGetJumpForceButton(rdram, ctx);
        goto after_5;
    // 0x80147DB0: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    after_5:
    // 0x80147DB4: b           L_80147DDC
    // 0x80147DB8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
        goto L_80147DDC;
    // 0x80147DB8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80147DBC:
    // 0x80147DBC: lb          $t7, 0x1C2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1C2);
    // 0x80147DC0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80147DC4: lwc1        $f4, 0xB18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB18);
    // 0x80147DC8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80147DCC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80147DD0: nop

    // 0x80147DD4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80147DD8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80147DDC:
    // 0x80147DDC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80147DE0: addiu       $t2, $zero, 0xFE
    ctx->r10 = ADD32(0, 0XFE);
    // 0x80147DE4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80147DE8: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80147DEC: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80147DF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80147DF4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80147DF8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80147DFC: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80147E00: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80147E04: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80147E08: sb          $t2, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r10;
    // 0x80147E0C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80147E10: nop

    // 0x80147E14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80147E18: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80147E1C: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80147E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147E24: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80147E28: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80147E2C: jr          $ra
    // 0x80147E30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80147E30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void wpManagerMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801655C8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801655CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801655D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801655D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801655D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801655DC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801655E0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x801655E4: jal         0x80165558
    // 0x801655E8: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    wpManagerGetNextStructAlloc(rdram, ctx);
        goto after_0;
    // 0x801655E8: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801655EC: bne         $v0, $zero, L_801655FC
    if (ctx->r2 != 0) {
        // 0x801655F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801655FC;
    }
    // 0x801655F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801655F4: b           L_80165EBC
    // 0x801655F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80165EBC;
    // 0x801655F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801655FC:
    // 0x801655FC: addiu       $a0, $zero, 0x3F4
    ctx->r4 = ADD32(0, 0X3F4);
    // 0x80165600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80165604: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80165608: jal         0x80009968
    // 0x8016560C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8016560C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80165610: bne         $v0, $zero, L_80165628
    if (ctx->r2 != 0) {
        // 0x80165614: sw          $v0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r2;
            goto L_80165628;
    }
    // 0x80165614: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80165618: jal         0x80165588
    // 0x8016561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x8016561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80165620: b           L_80165EBC
    // 0x80165624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80165EBC;
    // 0x80165624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80165628:
    // 0x80165628: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8016562C: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80165630: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80165634: sw          $s0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r16;
    // 0x80165638: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8016563C: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80165640: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80165644: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80165648: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8016564C: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x80165650: beq         $t1, $zero, L_80165684
    if (ctx->r9 == 0) {
        // 0x80165654: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80165684;
    }
    // 0x80165654: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80165658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016565C: beq         $t1, $at, L_80165824
    if (ctx->r9 == ctx->r1) {
        // 0x80165660: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80165824;
    }
    // 0x80165660: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80165664: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80165668: beq         $t1, $at, L_8016571C
    if (ctx->r9 == ctx->r1) {
        // 0x8016566C: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_8016571C;
    }
    // 0x8016566C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80165670: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80165674: beq         $t1, $at, L_801657A0
    if (ctx->r9 == ctx->r1) {
        // 0x80165678: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_801657A0;
    }
    // 0x80165678: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8016567C: b           L_80165828
    // 0x80165680: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
        goto L_80165828;
    // 0x80165680: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
L_80165684:
    // 0x80165684: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80165688: lw          $v0, 0x84($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X84);
    // 0x8016568C: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x80165690: lbu         $t3, 0xC($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XC);
    // 0x80165694: sb          $t3, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r11;
    // 0x80165698: lbu         $t4, 0xD($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XD);
    // 0x8016569C: sb          $t4, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r12;
    // 0x801656A0: lbu         $t5, 0x12($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X12);
    // 0x801656A4: sb          $t5, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r13;
    // 0x801656A8: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x801656AC: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x801656B0: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x801656B4: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x801656B8: lw          $t8, 0xB4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB4C);
    // 0x801656BC: sw          $t8, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->r24;
    // 0x801656C0: lhu         $a2, 0x28C($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X28C);
    // 0x801656C4: lw          $a1, 0x288($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X288);
    // 0x801656C8: lbu         $a0, 0xD($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XD);
    // 0x801656CC: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x801656D0: jal         0x800EA470
    // 0x801656D4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    ftParamGetStale(rdram, ctx);
        goto after_3;
    // 0x801656D4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_3:
    // 0x801656D8: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x801656DC: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x801656E0: swc1        $f0, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f0.u32l;
    // 0x801656E4: lw          $t0, 0x288($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X288);
    // 0x801656E8: lbu         $t3, 0x149($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X149);
    // 0x801656EC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801656F0: andi        $t2, $t1, 0x7E
    ctx->r10 = ctx->r9 & 0X7E;
    // 0x801656F4: andi        $t4, $t3, 0xFF81
    ctx->r12 = ctx->r11 & 0XFF81;
    // 0x801656F8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x801656FC: sb          $t5, 0x149($s0)
    MEM_B(0X149, ctx->r16) = ctx->r13;
    // 0x80165700: lhu         $t6, 0x28C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X28C);
    // 0x80165704: sh          $t6, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r14;
    // 0x80165708: lhu         $t8, 0x28E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X28E);
    // 0x8016570C: sh          $t8, 0x14C($s0)
    MEM_H(0X14C, ctx->r16) = ctx->r24;
    // 0x80165710: lhu         $t9, 0x290($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X290);
    // 0x80165714: b           L_801658CC
    // 0x80165718: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
        goto L_801658CC;
    // 0x80165718: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
L_8016571C:
    // 0x8016571C: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x80165720: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80165724: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x80165728: lbu         $t3, 0x10($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X10);
    // 0x8016572C: sb          $t3, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r11;
    // 0x80165730: lbu         $t2, 0x11($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X11);
    // 0x80165734: sb          $t2, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r10;
    // 0x80165738: lbu         $t4, 0x12($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X12);
    // 0x8016573C: lbu         $t2, 0x149($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X149);
    // 0x80165740: sb          $t4, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r12;
    // 0x80165744: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x80165748: andi        $t4, $t2, 0xFF81
    ctx->r12 = ctx->r10 & 0XFF81;
    // 0x8016574C: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
    // 0x80165750: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80165754: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x80165758: lw          $t7, 0x2BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2BC);
    // 0x8016575C: sw          $t7, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->r15;
    // 0x80165760: lwc1        $f4, 0x108($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X108);
    // 0x80165764: swc1        $f4, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f4.u32l;
    // 0x80165768: lw          $t8, 0x148($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X148);
    // 0x8016576C: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80165770: srl         $t0, $t9, 26
    ctx->r8 = S32(U32(ctx->r25) >> 26);
    // 0x80165774: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80165778: andi        $t3, $t1, 0x7E
    ctx->r11 = ctx->r9 & 0X7E;
    // 0x8016577C: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80165780: sb          $t5, 0x149($s0)
    MEM_B(0X149, ctx->r16) = ctx->r13;
    // 0x80165784: lhu         $t6, 0x14A($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X14A);
    // 0x80165788: sh          $t6, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r14;
    // 0x8016578C: lhu         $t8, 0x14C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X14C);
    // 0x80165790: sh          $t8, 0x14C($s0)
    MEM_H(0X14C, ctx->r16) = ctx->r24;
    // 0x80165794: lhu         $t9, 0x14E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14E);
    // 0x80165798: b           L_801658CC
    // 0x8016579C: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
        goto L_801658CC;
    // 0x8016579C: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
L_801657A0:
    // 0x801657A0: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x801657A4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x801657A8: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x801657AC: lbu         $t2, 0x14($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X14);
    // 0x801657B0: sb          $t2, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r10;
    // 0x801657B4: lbu         $t3, 0x15($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X15);
    // 0x801657B8: sb          $t3, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r11;
    // 0x801657BC: lbu         $t4, 0x16($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X16);
    // 0x801657C0: lbu         $t3, 0x149($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X149);
    // 0x801657C4: sb          $t4, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r12;
    // 0x801657C8: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x801657CC: andi        $t4, $t3, 0xFF81
    ctx->r12 = ctx->r11 & 0XFF81;
    // 0x801657D0: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
    // 0x801657D4: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801657D8: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x801657DC: lw          $t7, 0x374($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X374);
    // 0x801657E0: sw          $t7, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->r15;
    // 0x801657E4: lwc1        $f6, 0x118($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X118);
    // 0x801657E8: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x801657EC: lw          $t8, 0x158($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X158);
    // 0x801657F0: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x801657F4: srl         $t0, $t9, 26
    ctx->r8 = S32(U32(ctx->r25) >> 26);
    // 0x801657F8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801657FC: andi        $t2, $t1, 0x7E
    ctx->r10 = ctx->r9 & 0X7E;
    // 0x80165800: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80165804: sb          $t5, 0x149($s0)
    MEM_B(0X149, ctx->r16) = ctx->r13;
    // 0x80165808: lhu         $t6, 0x15A($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X15A);
    // 0x8016580C: sh          $t6, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r14;
    // 0x80165810: lhu         $t8, 0x15C($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X15C);
    // 0x80165814: sh          $t8, 0x14C($s0)
    MEM_H(0X14C, ctx->r16) = ctx->r24;
    // 0x80165818: lhu         $t9, 0x15E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X15E);
    // 0x8016581C: b           L_801658CC
    // 0x80165820: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
        goto L_801658CC;
    // 0x80165820: sh          $t9, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r25;
L_80165824:
    // 0x80165824: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
L_80165828:
    // 0x80165828: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8016582C: lbu         $t2, 0x149($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X149);
    // 0x80165830: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80165834: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x80165838: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x8016583C: sb          $t0, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r8;
    // 0x80165840: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80165844: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x80165848: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8016584C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80165850: lw          $t3, -0x300C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X300C);
    // 0x80165854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80165858: andi        $t4, $t2, 0xFF81
    ctx->r12 = ctx->r10 & 0XFF81;
    // 0x8016585C: sb          $t4, 0x149($s0)
    MEM_B(0X149, ctx->r16) = ctx->r12;
    // 0x80165860: sw          $t3, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->r11;
    // 0x80165864: swc1        $f8, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f8.u32l;
    // 0x80165868: jal         0x800EA5BC
    // 0x8016586C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    ftParamGetMotionCount(rdram, ctx);
        goto after_4;
    // 0x8016586C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_4:
    // 0x80165870: lhu         $t5, 0x14C($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X14C);
    // 0x80165874: sh          $v0, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r2;
    // 0x80165878: andi        $t6, $t5, 0xFC00
    ctx->r14 = ctx->r13 & 0XFC00;
    // 0x8016587C: sh          $t6, 0x14C($s0)
    MEM_H(0X14C, ctx->r16) = ctx->r14;
    // 0x80165880: lbu         $t7, 0x14C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X14C);
    // 0x80165884: andi        $t1, $t7, 0xFFFB
    ctx->r9 = ctx->r15 & 0XFFFB;
    // 0x80165888: sb          $t1, 0x14C($s0)
    MEM_B(0X14C, ctx->r16) = ctx->r9;
    // 0x8016588C: lw          $a0, 0x14C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14C);
    // 0x80165890: andi        $t3, $t1, 0xF7
    ctx->r11 = ctx->r9 & 0XF7;
    // 0x80165894: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80165898: srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // 0x8016589C: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801658A0: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x801658A4: or          $t6, $t0, $t3
    ctx->r14 = ctx->r8 | ctx->r11;
    // 0x801658A8: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x801658AC: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x801658B0: andi        $t7, $t6, 0xEF
    ctx->r15 = ctx->r14 & 0XEF;
    // 0x801658B4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x801658B8: sb          $t6, 0x14C($s0)
    MEM_B(0X14C, ctx->r16) = ctx->r14;
    // 0x801658BC: jal         0x800EA74C
    // 0x801658C0: sb          $t8, 0x14C($s0)
    MEM_B(0X14C, ctx->r16) = ctx->r24;
    ftParamGetStatUpdateCount(rdram, ctx);
        goto after_5;
    // 0x801658C0: sb          $t8, 0x14C($s0)
    MEM_B(0X14C, ctx->r16) = ctx->r24;
    after_5:
    // 0x801658C4: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x801658C8: sh          $v0, 0x14E($s0)
    MEM_H(0X14E, ctx->r16) = ctx->r2;
L_801658CC:
    // 0x801658CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801658D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801658D4: sw          $t9, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r25;
    // 0x801658D8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x801658DC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x801658E0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x801658E4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x801658E8: lw          $t1, 0x28($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X28);
    // 0x801658EC: sll         $t0, $t1, 10
    ctx->r8 = S32(ctx->r9 << 10);
    // 0x801658F0: srl         $t3, $t0, 24
    ctx->r11 = S32(U32(ctx->r8) >> 24);
    // 0x801658F4: sw          $t3, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r11;
    // 0x801658F8: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x801658FC: sll         $t4, $t2, 18
    ctx->r12 = S32(ctx->r10 << 18);
    // 0x80165900: srl         $t6, $t4, 28
    ctx->r14 = S32(U32(ctx->r12) >> 28);
    // 0x80165904: sw          $t6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r14;
    // 0x80165908: lh          $t5, 0x10($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X10);
    // 0x8016590C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80165910: nop

    // 0x80165914: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80165918: swc1        $f16, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f16.u32l;
    // 0x8016591C: lh          $t7, 0x12($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X12);
    // 0x80165920: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80165924: nop

    // 0x80165928: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8016592C: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x80165930: lh          $t8, 0x14($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X14);
    // 0x80165934: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80165938: nop

    // 0x8016593C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80165940: swc1        $f8, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f8.u32l;
    // 0x80165944: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x80165948: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8016594C: nop

    // 0x80165950: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80165954: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
    // 0x80165958: lh          $t1, 0x18($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X18);
    // 0x8016595C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80165960: nop

    // 0x80165964: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80165968: swc1        $f4, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f4.u32l;
    // 0x8016596C: lh          $t0, 0x1A($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X1A);
    // 0x80165970: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80165974: nop

    // 0x80165978: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016597C: swc1        $f8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f8.u32l;
    // 0x80165980: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x80165984: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80165988: bgez        $t3, L_801659A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8016598C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801659A0;
    }
    // 0x8016598C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80165990: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80165994: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80165998: nop

    // 0x8016599C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801659A0:
    // 0x801659A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801659A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801659A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801659AC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801659B0: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
    // 0x801659B4: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x801659B8: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x801659BC: sw          $t4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r12;
    // 0x801659C0: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x801659C4: srl         $t5, $t6, 22
    ctx->r13 = S32(U32(ctx->r14) >> 22);
    // 0x801659C8: sw          $t5, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r13;
    // 0x801659CC: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x801659D0: lbu         $t5, 0x148($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X148);
    // 0x801659D4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x801659D8: sw          $t8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r24;
    // 0x801659DC: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x801659E0: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x801659E4: srl         $t1, $t9, 22
    ctx->r9 = S32(U32(ctx->r25) >> 22);
    // 0x801659E8: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
    // 0x801659EC: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x801659F0: sll         $t3, $t0, 10
    ctx->r11 = S32(ctx->r8 << 10);
    // 0x801659F4: srl         $t2, $t3, 31
    ctx->r10 = S32(U32(ctx->r11) >> 31);
    // 0x801659F8: sll         $t6, $t2, 7
    ctx->r14 = S32(ctx->r10 << 7);
    // 0x801659FC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80165A00: sb          $t8, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r24;
    // 0x80165A04: lb          $t9, 0x2C($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X2C);
    // 0x80165A08: sw          $t9, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->r25;
    // 0x80165A0C: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80165A10: lbu         $t9, 0x148($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X148);
    // 0x80165A14: sll         $t0, $t1, 11
    ctx->r8 = S32(ctx->r9 << 11);
    // 0x80165A18: srl         $t3, $t0, 22
    ctx->r11 = S32(U32(ctx->r8) >> 22);
    // 0x80165A1C: sh          $t3, 0x146($s0)
    MEM_H(0X146, ctx->r16) = ctx->r11;
    // 0x80165A20: lbu         $t2, 0x2E($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2E);
    // 0x80165A24: andi        $t1, $t9, 0xFFBF
    ctx->r9 = ctx->r25 & 0XFFBF;
    // 0x80165A28: andi        $t4, $t2, 0x7
    ctx->r12 = ctx->r10 & 0X7;
    // 0x80165A2C: sw          $t4, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r12;
    // 0x80165A30: lbu         $t5, 0x2F($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2F);
    // 0x80165A34: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80165A38: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80165A3C: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80165A40: or          $t7, $t8, $t1
    ctx->r15 = ctx->r24 | ctx->r9;
    // 0x80165A44: sb          $t7, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r15;
    // 0x80165A48: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x80165A4C: andi        $t9, $t7, 0xDF
    ctx->r25 = ctx->r15 & 0XDF;
    // 0x80165A50: sll         $t2, $t3, 25
    ctx->r10 = S32(ctx->r11 << 25);
    // 0x80165A54: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x80165A58: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80165A5C: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80165A60: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80165A64: sb          $t1, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r9;
    // 0x80165A68: andi        $t6, $t1, 0xEF
    ctx->r14 = ctx->r9 & 0XEF;
    // 0x80165A6C: sb          $t6, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r14;
    // 0x80165A70: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    // 0x80165A74: andi        $t9, $t6, 0xF7
    ctx->r25 = ctx->r14 & 0XF7;
    // 0x80165A78: sll         $t2, $t3, 26
    ctx->r10 = S32(ctx->r11 << 26);
    // 0x80165A7C: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x80165A80: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80165A84: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80165A88: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x80165A8C: sb          $t5, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r13;
    // 0x80165A90: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80165A94: andi        $t6, $t5, 0xFB
    ctx->r14 = ctx->r13 & 0XFB;
    // 0x80165A98: sll         $t0, $t1, 27
    ctx->r8 = S32(ctx->r9 << 27);
    // 0x80165A9C: srl         $t3, $t0, 31
    ctx->r11 = S32(U32(ctx->r8) >> 31);
    // 0x80165AA0: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80165AA4: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x80165AA8: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x80165AAC: sb          $t2, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r10;
    // 0x80165AB0: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x80165AB4: andi        $t5, $t2, 0xFD
    ctx->r13 = ctx->r10 & 0XFD;
    // 0x80165AB8: sll         $t8, $t9, 28
    ctx->r24 = S32(ctx->r25 << 28);
    // 0x80165ABC: srl         $t1, $t8, 31
    ctx->r9 = S32(U32(ctx->r24) >> 31);
    // 0x80165AC0: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80165AC4: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80165AC8: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80165ACC: sb          $t6, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r14;
    // 0x80165AD0: andi        $t7, $t6, 0xFE
    ctx->r15 = ctx->r14 & 0XFE;
    // 0x80165AD4: sb          $t7, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r15;
    // 0x80165AD8: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x80165ADC: lbu         $t3, 0x149($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X149);
    // 0x80165AE0: sll         $t8, $t9, 29
    ctx->r24 = S32(ctx->r25 << 29);
    // 0x80165AE4: srl         $t1, $t8, 31
    ctx->r9 = S32(U32(ctx->r24) >> 31);
    // 0x80165AE8: sll         $t2, $t1, 7
    ctx->r10 = S32(ctx->r9 << 7);
    // 0x80165AEC: andi        $t5, $t3, 0xFF7F
    ctx->r13 = ctx->r11 & 0XFF7F;
    // 0x80165AF0: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x80165AF4: sb          $t4, 0x149($s0)
    MEM_B(0X149, ctx->r16) = ctx->r12;
    // 0x80165AF8: lbu         $t6, 0x2D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2D);
    // 0x80165AFC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80165B00: sb          $t9, 0x144($s0)
    MEM_B(0X144, ctx->r16) = ctx->r25;
    // 0x80165B04: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x80165B08: sw          $t7, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->r15;
    // 0x80165B0C: jal         0x80168158
    // 0x80165B10: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    wpMainClearAttackRecord(rdram, ctx);
        goto after_6;
    // 0x80165B10: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_6:
    // 0x80165B14: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165B18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80165B1C: lbu         $t8, 0x260($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X260);
    // 0x80165B20: lbu         $t2, 0x26C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X26C);
    // 0x80165B24: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x80165B28: andi        $t0, $t8, 0xFF7F
    ctx->r8 = ctx->r24 & 0XFF7F;
    // 0x80165B2C: andi        $t4, $t2, 0xFF7F
    ctx->r12 = ctx->r10 & 0XFF7F;
    // 0x80165B30: sb          $t0, 0x260($s0)
    MEM_B(0X260, ctx->r16) = ctx->r8;
    // 0x80165B34: andi        $t3, $t0, 0xBF
    ctx->r11 = ctx->r8 & 0XBF;
    // 0x80165B38: sb          $t4, 0x26C($s0)
    MEM_B(0X26C, ctx->r16) = ctx->r12;
    // 0x80165B3C: andi        $t6, $t4, 0xBF
    ctx->r14 = ctx->r12 & 0XBF;
    // 0x80165B40: sw          $zero, 0x238($s0)
    MEM_W(0X238, ctx->r16) = 0;
    // 0x80165B44: sw          $zero, 0x23C($s0)
    MEM_W(0X23C, ctx->r16) = 0;
    // 0x80165B48: sw          $zero, 0x240($s0)
    MEM_W(0X240, ctx->r16) = 0;
    // 0x80165B4C: sw          $zero, 0x254($s0)
    MEM_W(0X254, ctx->r16) = 0;
    // 0x80165B50: sw          $zero, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = 0;
    // 0x80165B54: sb          $t3, 0x260($s0)
    MEM_B(0X260, ctx->r16) = ctx->r11;
    // 0x80165B58: sw          $zero, 0x264($s0)
    MEM_W(0X264, ctx->r16) = 0;
    // 0x80165B5C: sb          $t6, 0x26C($s0)
    MEM_B(0X26C, ctx->r16) = ctx->r14;
    // 0x80165B60: sw          $zero, 0x270($s0)
    MEM_W(0X270, ctx->r16) = 0;
    // 0x80165B64: sh          $zero, 0x274($s0)
    MEM_H(0X274, ctx->r16) = 0;
    // 0x80165B68: swc1        $f0, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->f0.u32l;
    // 0x80165B6C: swc1        $f0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->f0.u32l;
    // 0x80165B70: swc1        $f0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->f0.u32l;
    // 0x80165B74: swc1        $f0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->f0.u32l;
    // 0x80165B78: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x80165B7C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165B80: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80165B84: beql        $t9, $zero, L_80165BE4
    if (ctx->r25 == 0) {
        // 0x80165B88: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_80165BE4;
    }
    goto skip_0;
    // 0x80165B88: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80165B8C: lbu         $t8, 0x11($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X11);
    // 0x80165B90: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80165B94: lbu         $a3, 0x10($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X10);
    // 0x80165B98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80165B9C: lbu         $t1, 0x12($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X12);
    // 0x80165BA0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80165BA4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80165BAC: jal         0x8000F590
    // 0x80165BB0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    gcSetupCustomDObjs(rdram, ctx);
        goto after_7;
    // 0x80165BB0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_7:
    // 0x80165BB4: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x80165BB8: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165BBC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165BC0: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80165BC4: beq         $t3, $zero, L_80165BD8
    if (ctx->r11 == 0) {
        // 0x80165BC8: nop
    
            goto L_80165BD8;
    }
    // 0x80165BC8: nop

    // 0x80165BCC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165BD0: b           L_80165C24
    // 0x80165BD4: addiu       $a1, $a1, 0x763C
    ctx->r5 = ADD32(ctx->r5, 0X763C);
        goto L_80165C24;
    // 0x80165BD4: addiu       $a1, $a1, 0x763C
    ctx->r5 = ADD32(ctx->r5, 0X763C);
L_80165BD8:
    // 0x80165BD8: b           L_80165C24
    // 0x80165BDC: addiu       $a1, $a1, 0x7618
    ctx->r5 = ADD32(ctx->r5, 0X7618);
        goto L_80165C24;
    // 0x80165BDC: addiu       $a1, $a1, 0x7618
    ctx->r5 = ADD32(ctx->r5, 0X7618);
    // 0x80165BE0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_80165BE4:
    // 0x80165BE4: jal         0x800092D0
    // 0x80165BE8: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    gcAddDObjForGObj(rdram, ctx);
        goto after_8;
    // 0x80165BE8: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_8:
    // 0x80165BEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80165BF0: lbu         $a1, 0x10($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X10);
    // 0x80165BF4: lbu         $a2, 0x11($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X11);
    // 0x80165BF8: jal         0x800C89BC
    // 0x80165BFC: lbu         $a3, 0x12($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X12);
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_9;
    // 0x80165BFC: lbu         $a3, 0x12($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X12);
    after_9:
    // 0x80165C00: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80165C04: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165C08: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165C0C: andi        $t5, $t2, 0x2
    ctx->r13 = ctx->r10 & 0X2;
    // 0x80165C10: beq         $t5, $zero, L_80165C24
    if (ctx->r13 == 0) {
        // 0x80165C14: addiu       $a1, $a1, 0x75D0
        ctx->r5 = ADD32(ctx->r5, 0X75D0);
            goto L_80165C24;
    }
    // 0x80165C14: addiu       $a1, $a1, 0x75D0
    ctx->r5 = ADD32(ctx->r5, 0X75D0);
    // 0x80165C18: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165C1C: b           L_80165C24
    // 0x80165C20: addiu       $a1, $a1, 0x75F4
    ctx->r5 = ADD32(ctx->r5, 0X75F4);
        goto L_80165C24;
    // 0x80165C20: addiu       $a1, $a1, 0x75F4
    ctx->r5 = ADD32(ctx->r5, 0X75F4);
L_80165C24:
    // 0x80165C24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80165C28: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80165C2C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165C30: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80165C34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80165C38: jal         0x80009DF4
    // 0x80165C3C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    gcAddGObjDisplay(rdram, ctx);
        goto after_10;
    // 0x80165C3C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_10:
    // 0x80165C40: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165C44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80165C48: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165C4C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80165C50: beql        $a1, $zero, L_80165C6C
    if (ctx->r5 == 0) {
        // 0x80165C54: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_80165C6C;
    }
    goto skip_1;
    // 0x80165C54: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x80165C58: jal         0x8000F8F4
    // 0x80165C5C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    gcAddMObjAll(rdram, ctx);
        goto after_11;
    // 0x80165C5C: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_11:
    // 0x80165C60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80165C64: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165C68: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_80165C6C:
    // 0x80165C6C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165C70: bnel        $a1, $zero, L_80165C88
    if (ctx->r5 != 0) {
        // 0x80165C74: lw          $a2, 0xC($v1)
        ctx->r6 = MEM_W(ctx->r3, 0XC);
            goto L_80165C88;
    }
    goto skip_2;
    // 0x80165C74: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x80165C78: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80165C7C: beql        $t6, $zero, L_80165CA0
    if (ctx->r14 == 0) {
        // 0x80165C80: lw          $a0, 0x7C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X7C);
            goto L_80165CA0;
    }
    goto skip_3;
    // 0x80165C80: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    skip_3:
    // 0x80165C84: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
L_80165C88:
    // 0x80165C88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80165C8C: jal         0x8000BED8
    // 0x80165C90: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    gcAddAnimAll(rdram, ctx);
        goto after_12;
    // 0x80165C90: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_12:
    // 0x80165C94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80165C98: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80165C9C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
L_80165CA0:
    // 0x80165CA0: addiu       $t8, $s0, 0x18
    ctx->r24 = ADD32(ctx->r16, 0X18);
    // 0x80165CA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80165CA8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80165CAC: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80165CB0: addiu       $t5, $s0, 0x64
    ctx->r13 = ADD32(ctx->r16, 0X64);
    // 0x80165CB4: addiu       $t9, $t7, 0x1C
    ctx->r25 = ADD32(ctx->r15, 0X1C);
    // 0x80165CB8: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80165CBC: lh          $t1, 0x1C($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1C);
    // 0x80165CC0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80165CC4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165CC8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80165CCC: addiu       $a1, $a1, 0x62BC
    ctx->r5 = ADD32(ctx->r5, 0X62BC);
    // 0x80165CD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80165CD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80165CD8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80165CDC: swc1        $f10, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f10.u32l;
    // 0x80165CE0: lh          $t0, 0x1E($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X1E);
    // 0x80165CE4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80165CE8: nop

    // 0x80165CEC: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80165CF0: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    // 0x80165CF4: lh          $t3, 0x20($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X20);
    // 0x80165CF8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80165CFC: nop

    // 0x80165D00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80165D04: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80165D08: lh          $t2, 0x22($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X22);
    // 0x80165D0C: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
    // 0x80165D10: sw          $v0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r2;
    // 0x80165D14: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80165D18: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
    // 0x80165D1C: sw          $v0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r2;
    // 0x80165D20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80165D24: sw          $v0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r2;
    // 0x80165D28: sw          $v0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r2;
    // 0x80165D2C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x80165D30: lhu         $t4, 0x1398($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1398);
    // 0x80165D34: sh          $zero, 0x82($s0)
    MEM_H(0X82, ctx->r16) = 0;
    // 0x80165D38: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80165D3C: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80165D40: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x80165D44: jal         0x80008188
    // 0x80165D48: sh          $t4, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r12;
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x80165D48: sh          $t4, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r12;
    after_13:
    // 0x80165D4C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165D50: addiu       $a1, $a1, 0x6954
    ctx->r5 = ADD32(ctx->r5, 0X6954);
    // 0x80165D54: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165D58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80165D5C: jal         0x80008188
    // 0x80165D60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_14;
    // 0x80165D60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80165D64: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165D68: addiu       $a1, $a1, 0x6BE4
    ctx->r5 = ADD32(ctx->r5, 0X6BE4);
    // 0x80165D6C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165D70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80165D74: jal         0x80008188
    // 0x80165D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_15;
    // 0x80165D78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80165D7C: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x80165D80: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x80165D84: sw          $t6, 0x278($s0)
    MEM_W(0X278, ctx->r16) = ctx->r14;
    // 0x80165D88: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80165D8C: sw          $t7, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->r15;
    // 0x80165D90: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x80165D94: sw          $t9, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->r25;
    // 0x80165D98: lw          $t8, 0x20($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X20);
    // 0x80165D9C: sw          $t8, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->r24;
    // 0x80165DA0: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80165DA4: sw          $t1, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r9;
    // 0x80165DA8: lw          $t0, 0x28($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X28);
    // 0x80165DAC: sw          $t0, 0x28C($s0)
    MEM_W(0X28C, ctx->r16) = ctx->r8;
    // 0x80165DB0: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x80165DB4: sw          $t3, 0x290($s0)
    MEM_W(0X290, ctx->r16) = ctx->r11;
    // 0x80165DB8: lw          $t2, 0x30($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X30);
    // 0x80165DBC: sw          $zero, 0x298($s0)
    MEM_W(0X298, ctx->r16) = 0;
    // 0x80165DC0: sw          $t2, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->r10;
    // 0x80165DC4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80165DC8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80165DCC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80165DD0: lw          $t4, 0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X4);
    // 0x80165DD4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80165DD8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80165DDC: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80165DE0: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80165DE4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80165DE8: lw          $t9, 0x74($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X74);
    // 0x80165DEC: sw          $t1, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r9;
    // 0x80165DF0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80165DF4: sw          $t8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r24;
    // 0x80165DF8: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80165DFC: sw          $t1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r9;
    // 0x80165E00: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80165E04: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x80165E08: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80165E0C: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x80165E10: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x80165E14: sw          $t3, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r11;
    // 0x80165E18: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80165E1C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80165E20: sll         $t5, $t2, 0
    ctx->r13 = S32(ctx->r10 << 0);
    // 0x80165E24: bgezl       $t5, L_80165EAC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80165E28: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80165EAC;
    }
    goto skip_4;
    // 0x80165E28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_4:
    // 0x80165E2C: beq         $v0, $zero, L_80165E5C
    if (ctx->r2 == 0) {
        // 0x80165E30: lw          $t4, 0x80($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X80);
            goto L_80165E5C;
    }
    // 0x80165E30: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80165E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80165E38: beq         $v0, $at, L_80165EA8
    if (ctx->r2 == ctx->r1) {
        // 0x80165E3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80165EA8;
    }
    // 0x80165E3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80165E40: beq         $v0, $at, L_80165E78
    if (ctx->r2 == ctx->r1) {
        // 0x80165E44: lw          $t6, 0x80($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X80);
            goto L_80165E78;
    }
    // 0x80165E44: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80165E48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80165E4C: beq         $v0, $at, L_80165E94
    if (ctx->r2 == ctx->r1) {
        // 0x80165E50: lw          $t7, 0x80($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X80);
            goto L_80165E94;
    }
    // 0x80165E50: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80165E54: b           L_80165EAC
    // 0x80165E58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
        goto L_80165EAC;
    // 0x80165E58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80165E5C:
    // 0x80165E5C: lw          $v0, 0x84($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X84);
    // 0x80165E60: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165E64: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    // 0x80165E68: jal         0x800DF09C
    // 0x80165E6C: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_16;
    // 0x80165E6C: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    after_16:
    // 0x80165E70: b           L_80165EAC
    // 0x80165E74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
        goto L_80165EAC;
    // 0x80165E74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80165E78:
    // 0x80165E78: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x80165E7C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165E80: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x80165E84: jal         0x800DF09C
    // 0x80165E88: addiu       $a2, $v0, 0x2C
    ctx->r6 = ADD32(ctx->r2, 0X2C);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_17;
    // 0x80165E88: addiu       $a2, $v0, 0x2C
    ctx->r6 = ADD32(ctx->r2, 0X2C);
    after_17:
    // 0x80165E8C: b           L_80165EAC
    // 0x80165E90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
        goto L_80165EAC;
    // 0x80165E90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80165E94:
    // 0x80165E94: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x80165E98: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80165E9C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x80165EA0: jal         0x800DF09C
    // 0x80165EA4: addiu       $a2, $v0, 0x38
    ctx->r6 = ADD32(ctx->r2, 0X38);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_18;
    // 0x80165EA4: addiu       $a2, $v0, 0x38
    ctx->r6 = ADD32(ctx->r2, 0X38);
    after_18:
L_80165EA8:
    // 0x80165EA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80165EAC:
    // 0x80165EAC: sw          $t9, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r25;
    // 0x80165EB0: jal         0x80165F60
    // 0x80165EB4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_19;
    // 0x80165EB4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    after_19:
    // 0x80165EB8: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80165EBC:
    // 0x80165EBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80165EC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80165EC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80165EC8: jr          $ra
    // 0x80165ECC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80165ECC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void itStarmieAttackMakeSwift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018260C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182610: jal         0x80182530
    // 0x80182614: nop

    itStarmieWeaponSwiftMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80182614: nop

    after_0:
    // 0x80182618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018261C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182620: jr          $ra
    // 0x80182624: nop

    return;
    // 0x80182624: nop

;}
RECOMP_FUNC void ftCommonRebirthCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D264: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D268: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D26C: lwc1        $f8, -0x3FAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3FAC);
    // 0x8013D270: lwc1        $f0, 0xB1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x8013D274: lwc1        $f4, 0xB28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB28);
    // 0x8013D278: lw          $v1, 0xB38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB38);
    // 0x8013D27C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8013D280: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8013D284: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D288: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013D28C: mflo        $t6
    ctx->r14 = lo;
    // 0x8013D290: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8013D294: nop

    // 0x8013D298: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013D29C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8013D2A0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8013D2A4: jr          $ra
    // 0x8013D2A8: swc1        $f6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f6.u32l;
    return;
    // 0x8013D2A8: swc1        $f6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftPikachuSpecialAirHiSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152DA4: jal         0x800DEE98
    // 0x80152DA8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80152DA8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80152DAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152DB0: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80152DB4: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80152DB8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152DBC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152DC0: jal         0x800E6F24
    // 0x80152DC4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152DC4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80152DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152DCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152DD0: jr          $ra
    // 0x80152DD4: nop

    return;
    // 0x80152DD4: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateSpeedOptionSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F2C4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F2C8: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F2CC: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8018F2D0: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8018F2D4: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x8018F2D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F2DC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F2E0: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x8018F2E4: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018F2E8: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
    // 0x8018F2EC: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8018F2F0:
    // 0x8018F2F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F2F4: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018F2F8: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018F2FC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018F300: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018F304: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018F308: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018F30C: bne         $t1, $t5, L_8018F2F0
    if (ctx->r9 != ctx->r13) {
        // 0x8018F310: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018F2F0;
    }
    // 0x8018F310: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018F314: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F318: addiu       $t7, $zero, 0xBF
    ctx->r15 = ADD32(0, 0XBF);
    // 0x8018F31C: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018F320: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018F324: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018F328: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8018F32C: bgez        $t6, L_8018F33C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018F330: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8018F33C;
    }
    // 0x8018F330: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8018F334: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8018F338: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8018F33C:
    // 0x8018F33C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8018F340: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018F344: nop

    // 0x8018F348: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F34C: jr          $ra
    // 0x8018F350: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8018F350: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151AC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151ACC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151AD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151AD4: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    // 0x80151AD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151ADC: jal         0x800E6F24
    // 0x80151AE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151AE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151AE4: jal         0x80151860
    // 0x80151AE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyPurinSpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80151AE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151AEC: jal         0x800E0830
    // 0x80151AF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80151AF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151AF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151AFC: jr          $ra
    // 0x80151B00: nop

    return;
    // 0x80151B00: nop

;}
RECOMP_FUNC void ftCommonTurnSetStatusInvertLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E9B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E9B4: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x8013E9B8: jal         0x8013E908
    // 0x8013E9BC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    ftCommonTurnSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013E9BC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_0:
    // 0x8013E9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E9C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E9C8: jr          $ra
    // 0x8013E9CC: nop

    return;
    // 0x8013E9CC: nop

;}
RECOMP_FUNC void ftKirbySpecialNCopyCheckGotoCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016253C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80162540: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80162544: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80162548: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8016254C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80162550: bnel        $t8, $zero, L_8016256C
    if (ctx->r24 != 0) {
        // 0x80162554: lw          $a1, 0x840($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X840);
            goto L_8016256C;
    }
    goto skip_0;
    // 0x80162554: lw          $a1, 0x840($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X840);
    skip_0:
    // 0x80162558: lb          $t9, 0x1C3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1C3);
    // 0x8016255C: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x80162560: beql        $at, $zero, L_801625A0
    if (ctx->r1 == 0) {
        // 0x80162564: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801625A0;
    }
    goto skip_1;
    // 0x80162564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80162568: lw          $a1, 0x840($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X840);
L_8016256C:
    // 0x8016256C: beql        $a1, $zero, L_801625A0
    if (ctx->r5 == 0) {
        // 0x80162570: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801625A0;
    }
    goto skip_2;
    // 0x80162570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80162574: beq         $a1, $zero, L_80162588
    if (ctx->r5 == 0) {
        // 0x80162578: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80162588;
    }
    // 0x80162578: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8016257C: jal         0x80161CA0
    // 0x80162580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNApplyCaptureDamage(rdram, ctx);
        goto after_0;
    // 0x80162580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80162588:
    // 0x80162588: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8016258C: jalr        $t9
    // 0x80162590: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80162590: nop

    after_1:
    // 0x80162594: b           L_801625A0
    // 0x80162598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801625A0;
    // 0x80162598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016259C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801625A0:
    // 0x801625A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801625A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801625A8: jr          $ra
    // 0x801625AC: nop

    return;
    // 0x801625AC: nop

;}
RECOMP_FUNC void syUtilsRandTimeUCharRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018A38: jal         0x80034D50
    // 0x80018A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80018A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80018A40: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80018A44: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x80018A48: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80018A4C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018A50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018A5C: mflo        $t0
    ctx->r8 = lo;
    // 0x80018A60: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80018A64: nop

    // 0x80018A68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018A6C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80018A70: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80018A74: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80018A78: jr          $ra
    // 0x80018A7C: nop

    return;
    // 0x80018A7C: nop

;}
RECOMP_FUNC void n_alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D724: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002D728: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8002D72C: jal         0x80030350
    // 0x8002D730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8002D730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002D734: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8002D738: addiu       $v1, $v1, -0x2CEC
    ctx->r3 = ADD32(ctx->r3, -0X2CEC);
    // 0x8002D73C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002D740: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002D744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D748: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8002D74C: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x8002D750: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002D754: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002D758: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8002D75C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002D760: jal         0x80030350
    // 0x8002D764: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D764: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    after_1:
    // 0x8002D768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D770: jr          $ra
    // 0x8002D774: nop

    return;
    // 0x8002D774: nop

;}
RECOMP_FUNC void func_ovl8_803781A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803781A4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x803781A8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x803781AC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x803781B0: sltiu       $at, $a0, 0x4
    ctx->r1 = ctx->r4 < 0X4 ? 1 : 0;
    // 0x803781B4: lhu         $t0, 0x4($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X4);
    // 0x803781B8: lhu         $t1, 0x6($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X6);
    // 0x803781BC: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x803781C0: beq         $at, $zero, L_803787B0
    if (ctx->r1 == 0) {
        // 0x803781C4: lh          $v0, 0x2($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X2);
            goto L_803787B0;
    }
    // 0x803781C4: lh          $v0, 0x2($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X2);
    // 0x803781C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x803781CC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803781D0: addu        $at, $at, $t6
    gpr jr_addend_803781D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x803781D4: lw          $t6, -0x11E8($at)
    ctx->r14 = ADD32(ctx->r1, -0X11E8);
    // 0x803781D8: jr          $t6
    // 0x803781DC: nop

    switch (jr_addend_803781D8 >> 2) {
        case 0: goto L_803787B0; break;
        case 1: goto L_803781E0; break;
        case 2: goto L_803783A0; break;
        case 3: goto L_803785AC; break;
        default: switch_error(__func__, 0x803781D8, 0x8038EE18);
    }
    // 0x803781DC: nop

L_803781E0:
    // 0x803781E0: blez        $t1, L_803787B0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x803781E4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_803787B0;
    }
    // 0x803781E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x803781E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_803781EC:
    // 0x803781EC: blez        $t0, L_8037838C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x803781F0: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8037838C;
    }
    // 0x803781F0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x803781F4: lh          $t7, 0x2($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X2);
L_803781F8:
    // 0x803781F8: addu        $t3, $t7, $a0
    ctx->r11 = ADD32(ctx->r15, ctx->r4);
    // 0x803781FC: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x80378200: beq         $t8, $zero, L_80378260
    if (ctx->r24 == 0) {
        // 0x80378204: nop
    
            goto L_80378260;
    }
    // 0x80378204: nop

    // 0x80378208: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x8037820C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x80378210: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x80378214: beq         $t6, $zero, L_8037823C
    if (ctx->r14 == 0) {
        // 0x80378218: nop
    
            goto L_8037823C;
    }
    // 0x80378218: nop

    // 0x8037821C: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378220: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80378224: mflo        $t8
    ctx->r24 = lo;
    // 0x80378228: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8037822C: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80378230: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80378234: b           L_80378280
    // 0x80378238: lbu         $t4, -0x4($t7)
    ctx->r12 = MEM_BU(ctx->r15, -0X4);
        goto L_80378280;
    // 0x80378238: lbu         $t4, -0x4($t7)
    ctx->r12 = MEM_BU(ctx->r15, -0X4);
L_8037823C:
    // 0x8037823C: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378240: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80378244: mflo        $t9
    ctx->r25 = lo;
    // 0x80378248: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8037824C: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80378250: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80378254: lbu         $t5, 0x4($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X4);
    // 0x80378258: b           L_80378280
    // 0x8037825C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
        goto L_80378280;
    // 0x8037825C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_80378260:
    // 0x80378260: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378264: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x80378268: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8037826C: mflo        $t6
    ctx->r14 = lo;
    // 0x80378270: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80378274: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80378278: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8037827C: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
L_80378280:
    // 0x80378280: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80378284: addu        $t3, $t7, $a0
    ctx->r11 = ADD32(ctx->r15, ctx->r4);
    // 0x80378288: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x8037828C: beq         $t8, $zero, L_80378360
    if (ctx->r24 == 0) {
        // 0x80378290: nop
    
            goto L_80378360;
    }
    // 0x80378290: nop

    // 0x80378294: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80378298: addu        $t9, $t5, $t2
    ctx->r25 = ADD32(ctx->r13, ctx->r10);
    // 0x8037829C: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x803782A0: beq         $t6, $zero, L_80378318
    if (ctx->r14 == 0) {
        // 0x803782A4: nop
    
            goto L_80378318;
    }
    // 0x803782A4: nop

    // 0x803782A8: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803782AC: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x803782B0: mflo        $t8
    ctx->r24 = lo;
    // 0x803782B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803782B8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x803782BC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x803782C0: sb          $t4, -0x4($t7)
    MEM_B(-0X4, ctx->r15) = ctx->r12;
    // 0x803782C4: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x803782C8: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x803782CC: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x803782D0: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803782D4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x803782D8: mflo        $t7
    ctx->r15 = lo;
    // 0x803782DC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x803782E0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x803782E4: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x803782E8: sb          $t4, -0x4($t7)
    MEM_B(-0X4, ctx->r15) = ctx->r12;
    // 0x803782EC: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x803782F0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x803782F4: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x803782F8: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803782FC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80378300: mflo        $t7
    ctx->r15 = lo;
    // 0x80378304: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80378308: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8037830C: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x80378310: b           L_80378380
    // 0x80378314: sb          $t4, -0x4($t7)
    MEM_B(-0X4, ctx->r15) = ctx->r12;
        goto L_80378380;
    // 0x80378314: sb          $t4, -0x4($t7)
    MEM_B(-0X4, ctx->r15) = ctx->r12;
L_80378318:
    // 0x80378318: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037831C: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80378320: mflo        $t8
    ctx->r24 = lo;
    // 0x80378324: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80378328: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x8037832C: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x80378330: sb          $t4, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r12;
    // 0x80378334: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x80378338: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8037833C: addu        $t7, $t9, $a0
    ctx->r15 = ADD32(ctx->r25, ctx->r4);
    // 0x80378340: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378344: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80378348: mflo        $t6
    ctx->r14 = lo;
    // 0x8037834C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80378350: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80378354: addu        $t6, $t8, $t2
    ctx->r14 = ADD32(ctx->r24, ctx->r10);
    // 0x80378358: b           L_80378380
    // 0x8037835C: sb          $t4, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r12;
        goto L_80378380;
    // 0x8037835C: sb          $t4, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r12;
L_80378360:
    // 0x80378360: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378364: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80378368: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8037836C: mflo        $t7
    ctx->r15 = lo;
    // 0x80378370: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80378374: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80378378: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x8037837C: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
L_80378380:
    // 0x80378380: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80378384: bnel        $t2, $t0, L_803781F8
    if (ctx->r10 != ctx->r8) {
        // 0x80378388: lh          $t7, 0x2($a3)
        ctx->r15 = MEM_H(ctx->r7, 0X2);
            goto L_803781F8;
    }
    goto skip_0;
    // 0x80378388: lh          $t7, 0x2($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X2);
    skip_0:
L_8037838C:
    // 0x8037838C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80378390: bne         $a0, $t1, L_803781EC
    if (ctx->r4 != ctx->r9) {
        // 0x80378394: nop
    
            goto L_803781EC;
    }
    // 0x80378394: nop

    // 0x80378398: b           L_803787B4
    // 0x8037839C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_803787B4;
    // 0x8037839C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_803783A0:
    // 0x803783A0: blez        $t1, L_803787B0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x803783A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_803787B0;
    }
    // 0x803783A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x803783A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_803783AC:
    // 0x803783AC: blez        $t0, L_80378598
    if (SIGNED(ctx->r8) <= 0) {
        // 0x803783B0: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80378598;
    }
    // 0x803783B0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x803783B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_803783B8:
    // 0x803783B8: lh          $t8, 0x2($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X2);
    // 0x803783BC: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x803783C0: andi        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 & 0X1;
    // 0x803783C4: beq         $t6, $zero, L_80378434
    if (ctx->r14 == 0) {
        // 0x803783C8: nop
    
            goto L_80378434;
    }
    // 0x803783C8: nop

    // 0x803783CC: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x803783D0: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x803783D4: andi        $t7, $t9, 0x2
    ctx->r15 = ctx->r25 & 0X2;
    // 0x803783D8: beq         $t7, $zero, L_80378408
    if (ctx->r15 == 0) {
        // 0x803783DC: nop
    
            goto L_80378408;
    }
    // 0x803783DC: nop

    // 0x803783E0: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803783E4: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x803783E8: mflo        $t6
    ctx->r14 = lo;
    // 0x803783EC: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x803783F0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x803783F4: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x803783F8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x803783FC: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80378400: b           L_8037845C
    // 0x80378404: lhu         $t4, -0x4($t9)
    ctx->r12 = MEM_HU(ctx->r25, -0X4);
        goto L_8037845C;
    // 0x80378404: lhu         $t4, -0x4($t9)
    ctx->r12 = MEM_HU(ctx->r25, -0X4);
L_80378408:
    // 0x80378408: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037840C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80378410: mflo        $t6
    ctx->r14 = lo;
    // 0x80378414: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80378418: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8037841C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80378420: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80378424: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80378428: lhu         $t5, 0x4($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X4);
    // 0x8037842C: b           L_8037845C
    // 0x80378430: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
        goto L_8037845C;
    // 0x80378430: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
L_80378434:
    // 0x80378434: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378438: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x8037843C: mflo        $t6
    ctx->r14 = lo;
    // 0x80378440: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80378444: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80378448: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8037844C: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x80378450: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80378454: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x80378458: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
L_8037845C:
    // 0x8037845C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80378460: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x80378464: andi        $t9, $t3, 0x1
    ctx->r25 = ctx->r11 & 0X1;
    // 0x80378468: beq         $t9, $zero, L_80378564
    if (ctx->r25 == 0) {
        // 0x8037846C: nop
    
            goto L_80378564;
    }
    // 0x8037846C: nop

    // 0x80378470: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80378474: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x80378478: andi        $t6, $t7, 0x2
    ctx->r14 = ctx->r15 & 0X2;
    // 0x8037847C: beq         $t6, $zero, L_8037850C
    if (ctx->r14 == 0) {
        // 0x80378480: nop
    
            goto L_8037850C;
    }
    // 0x80378480: nop

    // 0x80378484: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378488: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8037848C: mflo        $t9
    ctx->r25 = lo;
    // 0x80378490: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80378494: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80378498: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8037849C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x803784A0: addu        $t7, $t8, $s1
    ctx->r15 = ADD32(ctx->r24, ctx->r17);
    // 0x803784A4: sh          $t4, -0x4($t7)
    MEM_H(-0X4, ctx->r15) = ctx->r12;
    // 0x803784A8: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x803784AC: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x803784B0: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x803784B4: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803784B8: mflo        $t7
    ctx->r15 = lo;
    // 0x803784BC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x803784C0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x803784C4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x803784C8: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x803784CC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x803784D0: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x803784D4: sh          $t4, -0x4($t7)
    MEM_H(-0X4, ctx->r15) = ctx->r12;
    // 0x803784D8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x803784DC: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x803784E0: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x803784E4: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803784E8: mflo        $t7
    ctx->r15 = lo;
    // 0x803784EC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x803784F0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x803784F4: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x803784F8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x803784FC: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80378500: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80378504: b           L_8037858C
    // 0x80378508: sh          $t4, -0x4($t7)
    MEM_H(-0X4, ctx->r15) = ctx->r12;
        goto L_8037858C;
    // 0x80378508: sh          $t4, -0x4($t7)
    MEM_H(-0X4, ctx->r15) = ctx->r12;
L_8037850C:
    // 0x8037850C: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378510: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80378514: mflo        $t8
    ctx->r24 = lo;
    // 0x80378518: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8037851C: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80378520: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80378524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80378528: addu        $t6, $t9, $s1
    ctx->r14 = ADD32(ctx->r25, ctx->r17);
    // 0x8037852C: sh          $t4, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r12;
    // 0x80378530: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80378534: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80378538: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8037853C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378540: mflo        $t6
    ctx->r14 = lo;
    // 0x80378544: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80378548: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8037854C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80378550: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80378554: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80378558: addu        $t6, $t8, $s1
    ctx->r14 = ADD32(ctx->r24, ctx->r17);
    // 0x8037855C: b           L_8037858C
    // 0x80378560: sh          $t4, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r12;
        goto L_8037858C;
    // 0x80378560: sh          $t4, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r12;
L_80378564:
    // 0x80378564: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378568: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8037856C: mflo        $t7
    ctx->r15 = lo;
    // 0x80378570: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80378574: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80378578: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8037857C: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80378580: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80378584: addu        $t7, $t8, $s1
    ctx->r15 = ADD32(ctx->r24, ctx->r17);
    // 0x80378588: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
L_8037858C:
    // 0x8037858C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80378590: bne         $t2, $t0, L_803783B8
    if (ctx->r10 != ctx->r8) {
        // 0x80378594: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_803783B8;
    }
    // 0x80378594: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80378598:
    // 0x80378598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037859C: bne         $a0, $t1, L_803783AC
    if (ctx->r4 != ctx->r9) {
        // 0x803785A0: nop
    
            goto L_803783AC;
    }
    // 0x803785A0: nop

    // 0x803785A4: b           L_803787B4
    // 0x803785A8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
        goto L_803787B4;
    // 0x803785A8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_803785AC:
    // 0x803785AC: blez        $t1, L_803787B0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x803785B0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_803787B0;
    }
    // 0x803785B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x803785B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_803785B8:
    // 0x803785B8: blez        $t0, L_803787A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x803785BC: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_803787A4;
    }
    // 0x803785BC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x803785C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_803785C4:
    // 0x803785C4: lh          $t6, 0x2($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X2);
    // 0x803785C8: addu        $t3, $t6, $a0
    ctx->r11 = ADD32(ctx->r14, ctx->r4);
    // 0x803785CC: andi        $t9, $t3, 0x1
    ctx->r25 = ctx->r11 & 0X1;
    // 0x803785D0: beq         $t9, $zero, L_80378640
    if (ctx->r25 == 0) {
        // 0x803785D4: nop
    
            goto L_80378640;
    }
    // 0x803785D4: nop

    // 0x803785D8: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x803785DC: addu        $t8, $t4, $t2
    ctx->r24 = ADD32(ctx->r12, ctx->r10);
    // 0x803785E0: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x803785E4: beq         $t7, $zero, L_80378614
    if (ctx->r15 == 0) {
        // 0x803785E8: nop
    
            goto L_80378614;
    }
    // 0x803785E8: nop

    // 0x803785EC: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803785F0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x803785F4: mflo        $t9
    ctx->r25 = lo;
    // 0x803785F8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x803785FC: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80378600: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80378604: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80378608: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x8037860C: b           L_80378668
    // 0x80378610: lw          $t4, -0x8($t8)
    ctx->r12 = MEM_W(ctx->r24, -0X8);
        goto L_80378668;
    // 0x80378610: lw          $t4, -0x8($t8)
    ctx->r12 = MEM_W(ctx->r24, -0X8);
L_80378614:
    // 0x80378614: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378618: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8037861C: mflo        $t9
    ctx->r25 = lo;
    // 0x80378620: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80378624: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80378628: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8037862C: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80378630: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x80378634: lw          $t5, 0x8($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X8);
    // 0x80378638: b           L_80378668
    // 0x8037863C: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
        goto L_80378668;
    // 0x8037863C: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
L_80378640:
    // 0x80378640: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378644: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80378648: mflo        $t9
    ctx->r25 = lo;
    // 0x8037864C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80378650: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80378654: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80378658: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8037865C: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80378660: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80378664: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
L_80378668:
    // 0x80378668: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8037866C: addu        $t3, $t6, $a0
    ctx->r11 = ADD32(ctx->r14, ctx->r4);
    // 0x80378670: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x80378674: beq         $t8, $zero, L_80378770
    if (ctx->r24 == 0) {
        // 0x80378678: nop
    
            goto L_80378770;
    }
    // 0x80378678: nop

    // 0x8037867C: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80378680: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x80378684: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80378688: beq         $t9, $zero, L_80378718
    if (ctx->r25 == 0) {
        // 0x8037868C: nop
    
            goto L_80378718;
    }
    // 0x8037868C: nop

    // 0x80378690: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378694: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80378698: mflo        $t8
    ctx->r24 = lo;
    // 0x8037869C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x803786A0: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x803786A4: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x803786A8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x803786AC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x803786B0: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
    // 0x803786B4: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x803786B8: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x803786BC: addu        $t6, $t8, $a0
    ctx->r14 = ADD32(ctx->r24, ctx->r4);
    // 0x803786C0: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803786C4: mflo        $t7
    ctx->r15 = lo;
    // 0x803786C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x803786CC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x803786D0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x803786D4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x803786D8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x803786DC: addu        $t7, $t8, $s1
    ctx->r15 = ADD32(ctx->r24, ctx->r17);
    // 0x803786E0: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
    // 0x803786E4: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x803786E8: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x803786EC: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x803786F0: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803786F4: mflo        $t7
    ctx->r15 = lo;
    // 0x803786F8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x803786FC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80378700: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80378704: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80378708: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8037870C: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x80378710: b           L_80378798
    // 0x80378714: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
        goto L_80378798;
    // 0x80378714: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
L_80378718:
    // 0x80378718: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037871C: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80378720: mflo        $t6
    ctx->r14 = lo;
    // 0x80378724: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80378728: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8037872C: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80378730: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80378734: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80378738: sw          $t4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r12;
    // 0x8037873C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80378740: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80378744: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x80378748: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037874C: mflo        $t9
    ctx->r25 = lo;
    // 0x80378750: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80378754: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80378758: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8037875C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80378760: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80378764: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x80378768: b           L_80378798
    // 0x8037876C: sw          $t4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r12;
        goto L_80378798;
    // 0x8037876C: sw          $t4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r12;
L_80378770:
    // 0x80378770: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378774: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80378778: mflo        $t7
    ctx->r15 = lo;
    // 0x8037877C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80378780: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80378784: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80378788: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8037878C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80378790: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80378794: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
L_80378798:
    // 0x80378798: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8037879C: bne         $t2, $t0, L_803785C4
    if (ctx->r10 != ctx->r8) {
        // 0x803787A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_803785C4;
    }
    // 0x803787A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_803787A4:
    // 0x803787A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803787A8: bne         $a0, $t1, L_803785B8
    if (ctx->r4 != ctx->r9) {
        // 0x803787AC: nop
    
            goto L_803785B8;
    }
    // 0x803787AC: nop

L_803787B0:
    // 0x803787B0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_803787B4:
    // 0x803787B4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x803787B8: jr          $ra
    // 0x803787BC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x803787BC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_ovl8_8037C144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C144: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037C148: lw          $a2, -0x1034($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1034);
    // 0x8037C14C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C154: beq         $a2, $zero, L_8037C164
    if (ctx->r6 == 0) {
        // 0x8037C158: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8037C164;
    }
    // 0x8037C158: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8037C15C: jal         0x80375D44
    // 0x8037C160: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_80375D44(rdram, ctx);
        goto after_0;
    // 0x8037C160: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_8037C164:
    // 0x8037C164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C16C: jr          $ra
    // 0x8037C170: nop

    return;
    // 0x8037C170: nop

;}
RECOMP_FUNC void sc1PIntroMakeSky(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131B2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B34: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131B38: jal         0x80009968
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B40: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131B44: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131B48: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131B4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131B50: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B58: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80131B5C: jal         0x80009DF4
    // 0x80131B60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131B60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131B64: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B68: lw          $t7, 0x6058($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6058);
    // 0x80131B6C: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80131B70: addiu       $t8, $t8, 0x4BF0
    ctx->r24 = ADD32(ctx->r24, 0X4BF0);
    // 0x80131B74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131B78: jal         0x800CCFDC
    // 0x80131B7C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131B7C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131B80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131B84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131B88: lui         $at, 0x426C
    ctx->r1 = S32(0X426C << 16);
    // 0x80131B8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131B90: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131B94: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131B9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131BA0: jr          $ra
    // 0x80131BA4: nop

    return;
    // 0x80131BA4: nop

;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D7F0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002D7F4: lw          $v0, -0x2CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2CEC);
    // 0x8002D7F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D800: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002D804: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x8002D808: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002D80C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002D810: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002D814: beq         $a2, $zero, L_8002D84C
    if (ctx->r6 == 0) {
        // 0x8002D818: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002D84C;
    }
    // 0x8002D818: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002D81C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8002D820: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8002D824: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002D828: jal         0x80028C84
    // 0x8002D82C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8002D82C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8002D830: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8002D834: lw          $a1, -0x2CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2CEC);
    // 0x8002D838: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D83C: jal         0x80028C60
    // 0x8002D840: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    alLink(rdram, ctx);
        goto after_1;
    // 0x8002D840: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_1:
    // 0x8002D844: b           L_8002D8CC
    // 0x8002D848: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_8002D8CC;
    // 0x8002D848: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8002D84C:
    // 0x8002D84C: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8002D850: beq         $a2, $zero, L_8002D884
    if (ctx->r6 == 0) {
        // 0x8002D854: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8002D884;
    }
    // 0x8002D854: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002D858: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8002D85C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8002D860: jal         0x80028C84
    // 0x8002D864: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x8002D864: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8002D868: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8002D86C: lw          $a1, -0x2CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2CEC);
    // 0x8002D870: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002D874: jal         0x80028C60
    // 0x8002D878: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    alLink(rdram, ctx);
        goto after_3;
    // 0x8002D878: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_3:
    // 0x8002D87C: b           L_8002D8CC
    // 0x8002D880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_8002D8CC;
    // 0x8002D880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8002D884:
    // 0x8002D884: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x8002D888: beql        $a2, $zero, L_8002D8D0
    if (ctx->r6 == 0) {
        // 0x8002D88C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002D8D0;
    }
    goto skip_0;
    // 0x8002D88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002D890: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
L_8002D894:
    // 0x8002D894: lh          $t7, 0x16($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X16);
    // 0x8002D898: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002D89C: bnel        $at, $zero, L_8002D8C4
    if (ctx->r1 != 0) {
        // 0x8002D8A0: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8002D8C4;
    }
    goto skip_1;
    // 0x8002D8A0: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8002D8A4: lw          $t8, 0x88($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X88);
    // 0x8002D8A8: bnel        $t8, $zero, L_8002D8C4
    if (ctx->r24 != 0) {
        // 0x8002D8AC: lw          $a2, 0x0($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X0);
            goto L_8002D8C4;
    }
    goto skip_2;
    // 0x8002D8AC: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x8002D8B0: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8002D8B4: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8002D8B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002D8BC: lh          $a1, 0x16($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X16);
    // 0x8002D8C0: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
L_8002D8C4:
    // 0x8002D8C4: bnel        $a2, $zero, L_8002D894
    if (ctx->r6 != 0) {
        // 0x8002D8C8: lw          $t6, 0x8($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X8);
            goto L_8002D894;
    }
    goto skip_3;
    // 0x8002D8C8: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    skip_3:
L_8002D8CC:
    // 0x8002D8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002D8D0:
    // 0x8002D8D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D8D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002D8D8: jr          $ra
    // 0x8002D8DC: nop

    return;
    // 0x8002D8DC: nop

;}
RECOMP_FUNC void ftKirbySpecialLwUnkSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161AEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80161AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161AF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80161AF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80161AFC: addiu       $a1, $zero, 0x105
    ctx->r5 = ADD32(0, 0X105);
    // 0x80161B00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161B04: jal         0x800E6F24
    // 0x80161B08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161B08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80161B0C: jal         0x800E0830
    // 0x80161B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80161B14: jal         0x80161360
    // 0x80161B18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialLwUnused(rdram, ctx);
        goto after_2;
    // 0x80161B18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80161B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161B20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80161B24: jr          $ra
    // 0x80161B28: nop

    return;
    // 0x80161B28: nop

;}
RECOMP_FUNC void itBombHeiExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177C38: jal         0x80177BAC
    // 0x80177C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80177C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80177C40: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177C44: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177C4C: jal         0x80172EC8
    // 0x80177C50: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80177C50: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x80177C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177C5C: jr          $ra
    // 0x80177C60: nop

    return;
    // 0x80177C60: nop

;}
RECOMP_FUNC void mnVSResultsMakeHeaderCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136830: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80136834: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80136838: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013683C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80136840: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80136844: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80136848: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8013684C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80136850: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136854: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80136858: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013685C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80136860: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80136864: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136868: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013686C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80136874: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80136878: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013687C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136880: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80136884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136888: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013688C: jal         0x8000B93C
    // 0x80136890: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136890: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136894: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136898: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013689C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801368A0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801368A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801368A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801368AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801368B0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801368B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801368B8: jal         0x80007080
    // 0x801368BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801368BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801368C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801368C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801368C8: jr          $ra
    // 0x801368CC: nop

    return;
    // 0x801368CC: nop

;}
RECOMP_FUNC void ftCommonCaptureWaitKirbyProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BD04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014BD08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014BD0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014BD10: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014BD14: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014BD18: lw          $a2, 0x844($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X844);
    // 0x8014BD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BD20: beql        $a2, $zero, L_8014BDA4
    if (ctx->r6 == 0) {
        // 0x8014BD24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014BDA4;
    }
    goto skip_0;
    // 0x8014BD24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8014BD28: lw          $a1, 0x84($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X84);
    // 0x8014BD2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8014BD30: jal         0x8014BA98
    // 0x8014BD34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    ftCommonCaptureWaitKirbyUpdateBreakoutVars(rdram, ctx);
        goto after_0;
    // 0x8014BD34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014BD38: lw          $t7, 0x26C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X26C);
    // 0x8014BD3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BD40: jal         0x8014E400
    // 0x8014BD44: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_1;
    // 0x8014BD44: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_1:
    // 0x8014BD48: lw          $v0, 0x26C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X26C);
    // 0x8014BD4C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8014BD50: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8014BD54: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014BD58: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8014BD5C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8014BD60: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8014BD64: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8014BD68: sw          $t1, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r9;
    // 0x8014BD6C: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8014BD70: bgtz        $t3, L_8014BDA0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8014BD74: sw          $t3, 0x26C($s0)
        MEM_W(0X26C, ctx->r16) = ctx->r11;
            goto L_8014BDA0;
    }
    // 0x8014BD74: sw          $t3, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r11;
    // 0x8014BD78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014BD7C: jal         0x8014E1D0
    // 0x8014BD80: addiu       $a1, $a1, -0x7900
    ctx->r5 = ADD32(ctx->r5, -0X7900);
    ftCommonCaptureApplyCatchKnockback(rdram, ctx);
        goto after_2;
    // 0x8014BD80: addiu       $a1, $a1, -0x7900
    ctx->r5 = ADD32(ctx->r5, -0X7900);
    after_2:
    // 0x8014BD84: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014BD88: addiu       $a1, $a1, -0x78F0
    ctx->r5 = ADD32(ctx->r5, -0X78F0);
    // 0x8014BD8C: jal         0x8014E2A8
    // 0x8014BD90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftCommonCaptureApplyCaptureKnockback(rdram, ctx);
        goto after_3;
    // 0x8014BD90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8014BD94: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8014BD98: sw          $zero, 0x840($t5)
    MEM_W(0X840, ctx->r13) = 0;
    // 0x8014BD9C: sw          $zero, 0x844($s0)
    MEM_W(0X844, ctx->r16) = 0;
L_8014BDA0:
    // 0x8014BDA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014BDA4:
    // 0x8014BDA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014BDA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014BDAC: jr          $ra
    // 0x8014BDB0: nop

    return;
    // 0x8014BDB0: nop

;}
RECOMP_FUNC void wpFoxBlasterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801688D0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801688D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801688D8: lwc1        $f2, -0x3560($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3560);
    // 0x801688DC: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801688E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801688E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801688E8: nop

    // 0x801688EC: bc1f        L_8016891C
    if (!c1cs) {
        // 0x801688F0: nop
    
            goto L_8016891C;
    }
    // 0x801688F0: nop

    // 0x801688F4: lwc1        $f4, -0x355C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X355C);
    // 0x801688F8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801688FC: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x80168900: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80168904: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80168908: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8016890C: nop

    // 0x80168910: bc1f        L_8016891C
    if (!c1cs) {
        // 0x80168914: nop
    
            goto L_8016891C;
    }
    // 0x80168914: nop

    // 0x80168918: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
L_8016891C:
    // 0x8016891C: jr          $ra
    // 0x80168920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80168920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnCharactersGetMotionKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132DD8: lw          $v0, 0x66C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66C4);
    // 0x80132DDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132DE0: beq         $v0, $zero, L_80132E00
    if (ctx->r2 == 0) {
        // 0x80132DE4: nop
    
            goto L_80132E00;
    }
    // 0x80132DE4: nop

    // 0x80132DE8: beq         $v0, $at, L_80132E08
    if (ctx->r2 == ctx->r1) {
        // 0x80132DEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132E08;
    }
    // 0x80132DEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132DF0: beq         $v0, $at, L_80132E10
    if (ctx->r2 == ctx->r1) {
        // 0x80132DF4: nop
    
            goto L_80132E10;
    }
    // 0x80132DF4: nop

    // 0x80132DF8: b           L_80132E18
    // 0x80132DFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80132E18;
    // 0x80132DFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80132E00:
    // 0x80132E00: jr          $ra
    // 0x80132E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132E08:
    // 0x80132E08: jr          $ra
    // 0x80132E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132E10:
    // 0x80132E10: jr          $ra
    // 0x80132E14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80132E14: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80132E18:
    // 0x80132E18: jr          $ra
    // 0x80132E1C: nop

    return;
    // 0x80132E1C: nop

;}
RECOMP_FUNC void ftKirbySpecialNCopySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163314: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016331C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163320: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80163324: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163328: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016332C: addiu       $a1, $zero, 0x115
    ctx->r5 = ADD32(0, 0X115);
    // 0x80163330: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163334: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163338: jal         0x800E6F24
    // 0x8016333C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016333C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80163340: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80163344: jal         0x800E8098
    // 0x80163348: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x80163348: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x8016334C: jal         0x800E0830
    // 0x80163350: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163350: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016335C: jr          $ra
    // 0x80163360: nop

    return;
    // 0x80163360: nop

;}
RECOMP_FUNC void itTomatoWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801744FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174504: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80174508: jal         0x801735A0
    // 0x8017450C: addiu       $a1, $a1, 0x4588
    ctx->r5 = ADD32(ctx->r5, 0X4588);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017450C: addiu       $a1, $a1, 0x4588
    ctx->r5 = ADD32(ctx->r5, 0X4588);
    after_0:
    // 0x80174510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017451C: jr          $ra
    // 0x80174520: nop

    return;
    // 0x80174520: nop

;}
RECOMP_FUNC void itLinkBombCommonSetHitStatusNone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185CE4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80185CE8: jr          $ra
    // 0x80185CEC: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    return;
    // 0x80185CEC: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
;}
RECOMP_FUNC void ftKirbySpecialAirNWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016296C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162974: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162978: jal         0x800DE6E4
    // 0x8016297C: addiu       $a1, $a1, 0x2DD0
    ctx->r5 = ADD32(ctx->r5, 0X2DD0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8016297C: addiu       $a1, $a1, 0x2DD0
    ctx->r5 = ADD32(ctx->r5, 0X2DD0);
    after_0:
    // 0x80162980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162988: jr          $ra
    // 0x8016298C: nop

    return;
    // 0x8016298C: nop

;}
RECOMP_FUNC void func_ovl8_80371E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E14: jr          $ra
    // 0x80371E18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371E18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_ovl24_80131C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C58: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131C5C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131C60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131C74: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131C78: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80131C7C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80131C80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131C84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C88: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80131C8C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80131C90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131C94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131C98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131C9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131CA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CA4: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80131CA8: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80131CAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131CB0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131CB4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80131CB8: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80131CBC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131CC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131CC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CC8: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80131CCC: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80131CD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131CD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131CD8: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80131CDC: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80131CE0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131CE4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131CE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CEC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80131CF0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80131CF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131CF8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131CFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131D00: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80131D04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D08: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80131D0C: lui         $t9, 0xF64D
    ctx->r25 = S32(0XF64D << 16);
    // 0x80131D10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131D14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131D18: ori         $t9, $t9, 0xC0EC
    ctx->r25 = ctx->r25 | 0XC0EC;
    // 0x80131D1C: ori         $t6, $t6, 0x8028
    ctx->r14 = ctx->r14 | 0X8028;
    // 0x80131D20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131D24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131D28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D2C: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80131D30: lui         $t8, 0xF64D
    ctx->r24 = S32(0XF64D << 16);
    // 0x80131D34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131D38: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131D3C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131D40: ori         $t8, $t8, 0xC39C
    ctx->r24 = ctx->r24 | 0XC39C;
    // 0x80131D44: ori         $t9, $t9, 0x82D8
    ctx->r25 = ctx->r25 | 0X82D8;
    // 0x80131D48: addiu       $t4, $t4, 0x5C28
    ctx->r12 = ADD32(ctx->r12, 0X5C28);
    // 0x80131D4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131D50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131D54: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80131D58: lui         $a2, 0x7F7F
    ctx->r6 = S32(0X7F7F << 16);
    // 0x80131D5C: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x80131D60: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80131D64: beq         $at, $zero, L_80131D94
    if (ctx->r1 == 0) {
        // 0x80131D68: lui         $t6, 0xF627
        ctx->r14 = S32(0XF627 << 16);
            goto L_80131D94;
    }
    // 0x80131D68: lui         $t6, 0xF627
    ctx->r14 = S32(0XF627 << 16);
    // 0x80131D6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D70: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x80131D74: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80131D78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131D7C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131D80: lui         $a2, 0x7F7F
    ctx->r6 = S32(0X7F7F << 16);
    // 0x80131D84: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x80131D88: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80131D8C: b           L_80131DB0
    // 0x80131D90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_80131DB0;
    // 0x80131D90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131D94:
    // 0x80131D94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D98: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x80131D9C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80131DA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131DA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131DA8: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80131DAC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131DB0:
    // 0x80131DB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131DB4: lui         $t7, 0x25
    ctx->r15 = S32(0X25 << 16);
    // 0x80131DB8: ori         $t7, $t7, 0x7C
    ctx->r15 = ctx->r15 | 0X7C;
    // 0x80131DBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131DC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131DC4: ori         $t6, $t6, 0x9C
    ctx->r14 = ctx->r14 | 0X9C;
    // 0x80131DC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131DCC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131DD0: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80131DD4: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80131DD8: beq         $at, $zero, L_80131DF8
    if (ctx->r1 == 0) {
        // 0x80131DDC: lui         $t8, 0xF634
        ctx->r24 = S32(0XF634 << 16);
            goto L_80131DF8;
    }
    // 0x80131DDC: lui         $t8, 0xF634
    ctx->r24 = S32(0XF634 << 16);
    // 0x80131DE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131DE4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131DE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131DEC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80131DF0: b           L_80131E0C
    // 0x80131DF4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_80131E0C;
    // 0x80131DF4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131DF8:
    // 0x80131DF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131DFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131E00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131E04: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80131E08: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131E0C:
    // 0x80131E0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E10: lui         $t9, 0x32
    ctx->r25 = S32(0X32 << 16);
    // 0x80131E14: ori         $t9, $t9, 0x807C
    ctx->r25 = ctx->r25 | 0X807C;
    // 0x80131E18: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131E1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E20: ori         $t8, $t8, 0x809C
    ctx->r24 = ctx->r24 | 0X809C;
    // 0x80131E24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131E28: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131E2C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80131E30: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x80131E34: beq         $at, $zero, L_80131E54
    if (ctx->r1 == 0) {
        // 0x80131E38: lui         $t6, 0xF642
        ctx->r14 = S32(0XF642 << 16);
            goto L_80131E54;
    }
    // 0x80131E38: lui         $t6, 0xF642
    ctx->r14 = S32(0XF642 << 16);
    // 0x80131E3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131E44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E48: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80131E4C: b           L_80131E68
    // 0x80131E50: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_80131E68;
    // 0x80131E50: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131E54:
    // 0x80131E54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131E5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131E60: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80131E64: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80131E68:
    // 0x80131E68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E6C: lui         $t7, 0x40
    ctx->r15 = S32(0X40 << 16);
    // 0x80131E70: ori         $t7, $t7, 0x7C
    ctx->r15 = ctx->r15 | 0X7C;
    // 0x80131E74: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131E78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131E7C: ori         $t6, $t6, 0x9C
    ctx->r14 = ctx->r14 | 0X9C;
    // 0x80131E80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131E84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131E88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131E8C: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80131E90: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80131E94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131E98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131E9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131EA0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80131EA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131EA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131EAC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131EB0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131EB4: jal         0x800CCEAC
    // 0x80131EB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80131EB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_0:
    // 0x80131EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131EC4: jr          $ra
    // 0x80131EC8: nop

    return;
    // 0x80131EC8: nop

;}
RECOMP_FUNC void syControllerUpdateDeviceStatuses(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003CC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80003CC8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80003CCC: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80003CD0: addiu       $s6, $s6, 0x50F0
    ctx->r22 = ADD32(ctx->r22, 0X50F0);
    // 0x80003CD4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80003CD8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80003CDC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80003CE0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80003CE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80003CE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003CEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003CF0: jal         0x80033540
    // 0x80003CF4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    osContStartQuery_recomp(rdram, ctx);
        goto after_0;
    // 0x80003CF4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80003CF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80003CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003D00: jal         0x80030210
    // 0x80003D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80003D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80003D08: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80003D0C: jal         0x800335C4
    // 0x80003D10: addiu       $a0, $a0, 0x5178
    ctx->r4 = ADD32(ctx->r4, 0X5178);
    osContGetQuery_recomp(rdram, ctx);
        goto after_2;
    // 0x80003D10: addiu       $a0, $a0, 0x5178
    ctx->r4 = ADD32(ctx->r4, 0X5178);
    after_2:
    // 0x80003D14: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80003D18: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80003D1C: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80003D20: addiu       $s3, $s3, 0x52C8
    ctx->r19 = ADD32(ctx->r19, 0X52C8);
    // 0x80003D24: addiu       $s1, $s1, 0x51A8
    ctx->r17 = ADD32(ctx->r17, 0X51A8);
    // 0x80003D28: addiu       $s0, $s0, 0x5178
    ctx->r16 = ADD32(ctx->r16, 0X5178);
    // 0x80003D2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80003D30: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80003D34: addiu       $s4, $zero, 0x68
    ctx->r20 = ADD32(0, 0X68);
L_80003D38:
    // 0x80003D38: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x80003D3C: bnel        $v0, $zero, L_80003D94
    if (ctx->r2 != 0) {
        // 0x80003D40: lbu         $t2, 0x2($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X2);
            goto L_80003D94;
    }
    goto skip_0;
    // 0x80003D40: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    skip_0:
    // 0x80003D44: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x80003D48: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80003D4C: beql        $t7, $zero, L_80003D94
    if (ctx->r15 == 0) {
        // 0x80003D50: lbu         $t2, 0x2($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X2);
            goto L_80003D94;
    }
    goto skip_1;
    // 0x80003D50: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    skip_1:
    // 0x80003D54: lbu         $t8, 0x1D($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1D);
    // 0x80003D58: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80003D5C: beq         $t9, $zero, L_80003D70
    if (ctx->r25 == 0) {
        // 0x80003D60: nop
    
            goto L_80003D70;
    }
    // 0x80003D60: nop

    // 0x80003D64: lbu         $t0, 0x1C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1C);
    // 0x80003D68: beql        $t0, $zero, L_80003D94
    if (ctx->r8 == 0) {
        // 0x80003D6C: lbu         $t2, 0x2($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X2);
            goto L_80003D94;
    }
    goto skip_2;
    // 0x80003D6C: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    skip_2:
L_80003D70:
    // 0x80003D70: multu       $s2, $s4
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D74: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80003D78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80003D7C: mflo        $t1
    ctx->r9 = lo;
    // 0x80003D80: addu        $a1, $s3, $t1
    ctx->r5 = ADD32(ctx->r19, ctx->r9);
    // 0x80003D84: jal         0x800318C4
    // 0x80003D88: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80003D88: nop

    after_3:
    // 0x80003D8C: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x80003D90: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
L_80003D94:
    // 0x80003D94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80003D98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80003D9C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80003DA0: sb          $v0, -0x4($s1)
    MEM_B(-0X4, ctx->r17) = ctx->r2;
    // 0x80003DA4: bne         $s2, $s5, L_80003D38
    if (ctx->r18 != ctx->r21) {
        // 0x80003DA8: sb          $t2, -0x3($s1)
        MEM_B(-0X3, ctx->r17) = ctx->r10;
            goto L_80003D38;
    }
    // 0x80003DA8: sb          $t2, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r10;
    // 0x80003DAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80003DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003DB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003DB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003DBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80003DC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003DC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80003DC8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80003DCC: jr          $ra
    // 0x80003DD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80003DD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftFoxSpecialAirHiBoundProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C9E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C9F0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015C9F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C9F8: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x8015C9FC: bne         $t6, $at, L_8015CA4C
    if (ctx->r14 != ctx->r1) {
        // 0x8015CA00: nop
    
            goto L_8015CA4C;
    }
    // 0x8015CA00: nop

    // 0x8015CA04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CA08: jal         0x800DE7D8
    // 0x8015CA0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015CA0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8015CA10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015CA14: beq         $v0, $zero, L_8015CA54
    if (ctx->r2 == 0) {
        // 0x8015CA18: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8015CA54;
    }
    // 0x8015CA18: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CA1C: lhu         $t7, 0xD2($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XD2);
    // 0x8015CA20: andi        $t8, $t7, 0x3000
    ctx->r24 = ctx->r15 & 0X3000;
    // 0x8015CA24: beq         $t8, $zero, L_8015CA3C
    if (ctx->r24 == 0) {
        // 0x8015CA28: nop
    
            goto L_8015CA3C;
    }
    // 0x8015CA28: nop

    // 0x8015CA2C: jal         0x80144C24
    // 0x8015CA30: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015CA30: nop

    after_1:
    // 0x8015CA34: b           L_8015CA58
    // 0x8015CA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CA58;
    // 0x8015CA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CA3C:
    // 0x8015CA3C: jal         0x800DEE98
    // 0x8015CA40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_2;
    // 0x8015CA40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8015CA44: b           L_8015CA58
    // 0x8015CA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CA58;
    // 0x8015CA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CA4C:
    // 0x8015CA4C: jal         0x800DDEC4
    // 0x8015CA50: nop

    mpCommonSetFighterFallOnGroundBreak(rdram, ctx);
        goto after_3;
    // 0x8015CA50: nop

    after_3:
L_8015CA54:
    // 0x8015CA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CA58:
    // 0x8015CA58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CA5C: jr          $ra
    // 0x8015CA60: nop

    return;
    // 0x8015CA60: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwStartUpdateThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151E4C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151E50: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x80151E54: beql        $t6, $zero, L_80151E68
    if (ctx->r14 == 0) {
        // 0x80151E58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80151E68;
    }
    goto skip_0;
    // 0x80151E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80151E5C: jal         0x80151DB0
    // 0x80151E60: nop

    ftPikachuSpecialLwMakeThunder(rdram, ctx);
        goto after_0;
    // 0x80151E60: nop

    after_0:
    // 0x80151E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80151E68:
    // 0x80151E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151E6C: jr          $ra
    // 0x80151E70: nop

    return;
    // 0x80151E70: nop

;}
RECOMP_FUNC void mnPlayersVSMakePuckAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013992C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80139930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139934: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013993C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80139940: jal         0x80009968
    // 0x80139944: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80139944: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80139948: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013994C: addiu       $a1, $a1, -0x6748
    ctx->r5 = ADD32(ctx->r5, -0X6748);
    // 0x80139950: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139954: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139958: jal         0x80008188
    // 0x8013995C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8013995C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80139960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139968: jr          $ra
    // 0x8013996C: nop

    return;
    // 0x8013996C: nop

;}
RECOMP_FUNC void func_ovl8_80381B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381B18: beq         $a0, $zero, L_80381B54
    if (ctx->r4 == 0) {
        // 0x80381B1C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80381B54;
    }
    // 0x80381B1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80381B20: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80381B24: addiu       $t6, $t6, -0x4374
    ctx->r14 = ADD32(ctx->r14, -0X4374);
    // 0x80381B28: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x80381B2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80381B30: jal         0x8038120C
    // 0x80381B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8038120C(rdram, ctx);
        goto after_0;
    // 0x80381B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80381B38: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80381B3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80381B40: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80381B44: beql        $t8, $zero, L_80381B58
    if (ctx->r24 == 0) {
        // 0x80381B48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80381B58;
    }
    goto skip_0;
    // 0x80381B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80381B4C: jal         0x803717C0
    // 0x80381B50: nop

    func_ovl8_803717C0(rdram, ctx);
        goto after_1;
    // 0x80381B50: nop

    after_1:
L_80381B54:
    // 0x80381B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381B58:
    // 0x80381B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381B5C: jr          $ra
    // 0x80381B60: nop

    return;
    // 0x80381B60: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015223C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152240: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152244: jal         0x800DE6E4
    // 0x80152248: addiu       $a1, $a1, 0x229C
    ctx->r5 = ADD32(ctx->r5, 0X229C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80152248: addiu       $a1, $a1, 0x229C
    ctx->r5 = ADD32(ctx->r5, 0X229C);
    after_0:
    // 0x8015224C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152254: jr          $ra
    // 0x80152258: nop

    return;
    // 0x80152258: nop

;}
RECOMP_FUNC void itSwordHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174C64: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80174C68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80174C6C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174C70: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x80174C74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80174C78: jal         0x80172EC8
    // 0x80174C7C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174C7C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80174C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174C88: jr          $ra
    // 0x80174C8C: nop

    return;
    // 0x80174C8C: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016C21C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016C220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016C224: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8016C228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016C22C: lb          $t6, 0x29C($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X29C);
    // 0x8016C230: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8016C234: beql        $t6, $zero, L_8016C2B0
    if (ctx->r14 == 0) {
        // 0x8016C238: lb          $t7, 0x29D($a3)
        ctx->r15 = MEM_B(ctx->r7, 0X29D);
            goto L_8016C2B0;
    }
    goto skip_0;
    // 0x8016C238: lb          $t7, 0x29D($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X29D);
    skip_0:
    // 0x8016C23C: jal         0x80167FE8
    // 0x8016C240: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016C240: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8016C244: beq         $v0, $zero, L_8016C27C
    if (ctx->r2 == 0) {
        // 0x8016C248: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_8016C27C;
    }
    // 0x8016C248: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8016C24C: jal         0x800269C0
    // 0x8016C250: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8016C250: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    after_1:
    // 0x8016C254: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016C258: jal         0x80103A88
    // 0x8016C25C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerYoshiEggExplodeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016C25C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8016C260: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016C264: jal         0x801041A0
    // 0x8016C268: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016C268: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016C26C: jal         0x8016C00C
    // 0x8016C270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpYoshiEggExpireInitVars(rdram, ctx);
        goto after_4;
    // 0x8016C270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8016C274: b           L_8016C2CC
    // 0x8016C278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016C2CC;
    // 0x8016C278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016C27C:
    // 0x8016C27C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8016C280: lwc1        $f6, 0x2A4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X2A4);
    // 0x8016C284: lui         $a1, 0x402C
    ctx->r5 = S32(0X402C << 16);
    // 0x8016C288: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8016C28C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8016C290: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8016C294: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016C298: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x8016C29C: jal         0x80168088
    // 0x8016C2A0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    wpMainApplyGravityClampTVel(rdram, ctx);
        goto after_5;
    // 0x8016C2A0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    after_5:
    // 0x8016C2A4: b           L_8016C2CC
    // 0x8016C2A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016C2CC;
    // 0x8016C2A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C2AC: lb          $t7, 0x29D($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X29D);
L_8016C2B0:
    // 0x8016C2B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8016C2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016C2B8: beql        $t7, $zero, L_8016C2CC
    if (ctx->r15 == 0) {
        // 0x8016C2BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016C2CC;
    }
    goto skip_1;
    // 0x8016C2BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8016C2C0: jal         0x8016C07C
    // 0x8016C2C4: sb          $t8, 0x29C($a3)
    MEM_B(0X29C, ctx->r7) = ctx->r24;
    wpYoshiEggThrowInitVars(rdram, ctx);
        goto after_6;
    // 0x8016C2C4: sb          $t8, 0x29C($a3)
    MEM_B(0X29C, ctx->r7) = ctx->r24;
    after_6:
    // 0x8016C2C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016C2CC:
    // 0x8016C2CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C2D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016C2D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016C2D8: jr          $ra
    // 0x8016C2DC: nop

    return;
    // 0x8016C2DC: nop

;}
RECOMP_FUNC void efManagerStockSnapMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010397C: jal         0x80103918
    // 0x80103980: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    efManagerStockCommonMakeEffectID(rdram, ctx);
        goto after_0;
    // 0x80103980: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    after_0:
    // 0x80103984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010398C: jr          $ra
    // 0x80103990: nop

    return;
    // 0x80103990: nop

;}
RECOMP_FUNC void ftCommonCliffCommon2ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801452B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801452B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801452BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801452C0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801452C4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801452C8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x801452CC: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x801452D0: bnel        $t7, $zero, L_801452EC
    if (ctx->r15 != 0) {
        // 0x801452D4: lw          $v1, 0x74($t8)
        ctx->r3 = MEM_W(ctx->r24, 0X74);
            goto L_801452EC;
    }
    goto skip_0;
    // 0x801452D4: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    skip_0:
    // 0x801452D8: jal         0x800D8C14
    // 0x801452DC: nop

    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_0;
    // 0x801452DC: nop

    after_0:
    // 0x801452E0: b           L_801453E0
    // 0x801452E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801453E0;
    // 0x801452E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801452E8: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
L_801452EC:
    // 0x801452EC: addiu       $t9, $sp, 0x40
    ctx->r25 = ADD32(ctx->r29, 0X40);
    // 0x801452F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801452F4: lw          $t1, 0x1C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1C);
    // 0x801452F8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x801452FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80145300: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80145304: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80145308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014530C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80145310: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80145314: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80145318: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x8014531C: jal         0x800D9260
    // 0x80145320: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    ftPhysicsGetAirVelTransN(rdram, ctx);
        goto after_1;
    // 0x80145320: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x80145324: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80145328: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8014532C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80145330: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80145334: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80145338: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8014533C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80145340: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80145344: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80145348: jal         0x800FA7B8
    // 0x8014534C: lw          $a0, 0xB1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB1C);
    mpCollisionGetSpeedLineID(rdram, ctx);
        goto after_2;
    // 0x8014534C: lw          $a0, 0xB1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB1C);
    after_2:
    // 0x80145350: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80145354: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80145358: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8014535C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80145360: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80145364: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80145368: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8014536C: lw          $a0, 0xB1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB1C);
    // 0x80145370: jal         0x800F3DD8
    // 0x80145374: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_3;
    // 0x80145374: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80145378: beq         $v0, $zero, L_801453D4
    if (ctx->r2 == 0) {
        // 0x8014537C: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_801453D4;
    }
    // 0x8014537C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80145380: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80145384: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80145388: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8014538C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80145390: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80145394: lw          $t2, 0x8EC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8EC);
    // 0x80145398: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8014539C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801453A0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x801453A4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801453A8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801453AC: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x801453B0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801453B4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801453B8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801453BC: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x801453C0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801453C4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801453C8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801453CC: b           L_801453DC
    // 0x801453D0: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
        goto L_801453DC;
    // 0x801453D0: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
L_801453D4:
    // 0x801453D4: jal         0x800D93E4
    // 0x801453D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_4;
    // 0x801453D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_4:
L_801453DC:
    // 0x801453DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801453E0:
    // 0x801453E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801453E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801453E8: jr          $ra
    // 0x801453EC: nop

    return;
    // 0x801453EC: nop

;}

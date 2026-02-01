#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void scStaffrollMakeTextBoxGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801347F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801347F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801347FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80134800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134804: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80134808: jal         0x80009968
    // 0x8013480C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013480C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134810: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80134814: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134818: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013481C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134820: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80134824: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134828: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8013482C: jal         0x80009DF4
    // 0x80134830: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134830: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134834: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80134838: addiu       $a1, $a1, -0x5A68
    ctx->r5 = ADD32(ctx->r5, -0X5A68);
    // 0x8013483C: jal         0x800092D0
    // 0x80134840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80134840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80134844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013484C: jr          $ra
    // 0x80134850: nop

    return;
    // 0x80134850: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160038: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016003C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80160040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80160044: sh          $zero, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = 0;
    // 0x80160048: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8016004C: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    // 0x80160050: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80160054: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80160058: jr          $ra
    // 0x8016005C: swc1        $f4, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8016005C: swc1        $f4, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftPikachuSpecialHiEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015358C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153590: jal         0x800DEEC8
    // 0x80153594: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80153594: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80153598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015359C: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x801535A0: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x801535A4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801535A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801535AC: jal         0x800E6F24
    // 0x801535B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801535B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801535B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801535B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801535BC: jr          $ra
    // 0x801535C0: nop

    return;
    // 0x801535C0: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C15C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015C168: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015C16C: lw          $t7, 0xB28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB28);
    // 0x8015C170: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8015C174: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8015C178: bne         $at, $zero, L_8015C1DC
    if (ctx->r1 != 0) {
        // 0x8015C17C: sw          $t8, 0xB28($v0)
        MEM_W(0XB28, ctx->r2) = ctx->r24;
            goto L_8015C1DC;
    }
    // 0x8015C17C: sw          $t8, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->r24;
    // 0x8015C180: lwc1        $f12, 0xB20($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB20);
    // 0x8015C184: jal         0x80035CD0
    // 0x8015C188: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8015C188: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015C18C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C190: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C194: lwc1        $f4, -0x377C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X377C);
    // 0x8015C198: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x8015C19C: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015C1A0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8015C1A4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015C1A8: lwc1        $f12, 0xB20($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB20);
    // 0x8015C1AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015C1B0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8015C1B4: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8015C1B8: jal         0x800303F0
    // 0x8015C1BC: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015C1BC: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8015C1C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C1C4: lwc1        $f6, -0x3778($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3778);
    // 0x8015C1C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C1CC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8015C1D0: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8015C1D4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8015C1D8: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
L_8015C1DC:
    // 0x8015C1DC: jal         0x8015C054
    // 0x8015C1E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_2;
    // 0x8015C1E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015C1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C1E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C1EC: jr          $ra
    // 0x8015C1F0: nop

    return;
    // 0x8015C1F0: nop

;}
RECOMP_FUNC void ftParamGetCommonKnockback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9D7C: beq         $a3, $zero, L_800E9E70
    if (ctx->r7 == 0) {
        // 0x800E9D80: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800E9E70;
    }
    // 0x800E9D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9D84: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800E9D88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9D8C: lwc1        $f12, -0xF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XF0);
    // 0x800E9D90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E9D94: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800E9D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E9D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9DA0: lwc1        $f16, -0xEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEC);
    // 0x800E9DA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E9DA8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E9DAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E9DB0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E9DB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800E9DB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9DBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9DC0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800E9DC4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800E9DC8: lwc1        $f16, -0xE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE8);
    // 0x800E9DCC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800E9DD0: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x800E9DD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E9DD8: addiu       $v0, $v0, -0x37D0
    ctx->r2 = ADD32(ctx->r2, -0X37D0);
    // 0x800E9DDC: lbu         $t9, 0xB($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XB);
    // 0x800E9DE0: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800E9DE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E9DE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E9DEC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E9DF0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800E9DF4: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800E9DF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E9DFC: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800E9E00: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E9E04: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800E9E08: nop

    // 0x800E9E0C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E9E10: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800E9E14: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800E9E18: nop

    // 0x800E9E1C: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E9E20: bgez        $t9, L_800E9E34
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E9E24: add.s       $f10, $f6, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800E9E34;
    }
    // 0x800E9E24: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800E9E28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E9E2C: nop

    // 0x800E9E30: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800E9E34:
    // 0x800E9E34: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800E9E38: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800E9E3C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800E9E40: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800E9E44: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x800E9E48: lwc1        $f4, -0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, -0X8);
    // 0x800E9E4C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800E9E50: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800E9E54: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800E9E58: lwc1        $f16, -0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, -0X4);
    // 0x800E9E5C: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800E9E60: nop

    // 0x800E9E64: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800E9E68: b           L_800E9F60
    // 0x800E9E6C: nop

        goto L_800E9F60;
    // 0x800E9E6C: nop

L_800E9E70:
    // 0x800E9E70: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800E9E74: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800E9E78: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800E9E7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9E80: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E9E84: lwc1        $f12, -0xE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XE4);
    // 0x800E9E88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9E8C: lwc1        $f16, -0xE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE0);
    // 0x800E9E90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9E94: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E9E98: lwc1        $f10, -0xDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XDC);
    // 0x800E9E9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800E9EA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9EA4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9EA8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800E9EAC: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800E9EB0: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x800E9EB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E9EB8: addiu       $v0, $v0, -0x37D0
    ctx->r2 = ADD32(ctx->r2, -0X37D0);
    // 0x800E9EBC: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x800E9EC0: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800E9EC4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E9EC8: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800E9ECC: lwc1        $f10, -0xD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XD8);
    // 0x800E9ED0: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800E9ED4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800E9ED8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E9EDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E9EE0: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800E9EE4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800E9EE8: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800E9EEC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E9EF0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800E9EF4: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800E9EF8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800E9EFC: nop

    // 0x800E9F00: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E9F04: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E9F08: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800E9F0C: nop

    // 0x800E9F10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E9F14: bgez        $t0, L_800E9F28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800E9F18: add.s       $f16, $f6, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
            goto L_800E9F28;
    }
    // 0x800E9F18: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800E9F1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E9F20: nop

    // 0x800E9F24: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_800E9F28:
    // 0x800E9F28: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E9F2C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800E9F30: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800E9F34: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800E9F38: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800E9F3C: lwc1        $f8, -0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, -0X8);
    // 0x800E9F40: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800E9F44: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800E9F48: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800E9F4C: lwc1        $f10, -0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, -0X4);
    // 0x800E9F50: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E9F54: nop

    // 0x800E9F58: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800E9F5C: nop

L_800E9F60:
    // 0x800E9F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9F64: lwc1        $f0, -0xD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XD4);
    // 0x800E9F68: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800E9F6C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800E9F70: nop

    // 0x800E9F74: bc1f        L_800E9F80
    if (!c1cs) {
        // 0x800E9F78: nop
    
            goto L_800E9F80;
    }
    // 0x800E9F78: nop

    // 0x800E9F7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800E9F80:
    // 0x800E9F80: lbu         $t7, 0x4AC2($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AC2);
    // 0x800E9F84: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800E9F88: beql        $t8, $zero, L_800E9FB0
    if (ctx->r24 == 0) {
        // 0x800E9F8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E9FB0;
    }
    goto skip_0;
    // 0x800E9F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E9F90: jal         0x80018948
    // 0x800E9F94: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x800E9F94: nop

    after_0:
    // 0x800E9F98: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800E9F9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E9FA0: nop

    // 0x800E9FA4: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800E9FA8: nop

    // 0x800E9FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E9FB0:
    // 0x800E9FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9FB4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800E9FB8: jr          $ra
    // 0x800E9FBC: nop

    return;
    // 0x800E9FBC: nop

;}
RECOMP_FUNC void ftMainProcParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E61EC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800E61F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E61F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E61F8: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800E61FC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800E6200: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800E6204: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E6208: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800E620C: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x800E6210: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800E6214: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x800E6218: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    // 0x800E621C: lw          $v0, 0x7AC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7AC);
    // 0x800E6220: beql        $v0, $zero, L_800E6238
    if (ctx->r2 == 0) {
        // 0x800E6224: lw          $t1, 0x18C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X18C);
            goto L_800E6238;
    }
    goto skip_0;
    // 0x800E6224: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
    skip_0:
    // 0x800E6228: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x800E622C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800E6230: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
    // 0x800E6234: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
L_800E6238:
    // 0x800E6238: sll         $t3, $t1, 26
    ctx->r11 = S32(ctx->r9 << 26);
    // 0x800E623C: bltzl       $t3, L_800E6298
    if (SIGNED(ctx->r11) < 0) {
        // 0x800E6240: lw          $t7, 0x34($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X34);
            goto L_800E6298;
    }
    goto skip_1;
    // 0x800E6240: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x800E6244: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    // 0x800E6248: slti        $at, $t4, 0x37
    ctx->r1 = SIGNED(ctx->r12) < 0X37 ? 1 : 0;
    // 0x800E624C: beq         $at, $zero, L_800E6294
    if (ctx->r1 == 0) {
        // 0x800E6250: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800E6294;
    }
    // 0x800E6250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E6254: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E6258: lwc1        $f4, 0x7A8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7A8);
    // 0x800E625C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800E6260: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800E6264: swc1        $f8, 0x7A8($s0)
    MEM_W(0X7A8, ctx->r16) = ctx->f8.u32l;
    // 0x800E6268: lwc1        $f16, 0x7A8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7A8);
    // 0x800E626C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800E6270: nop

    // 0x800E6274: bc1fl       L_800E6298
    if (!c1cs) {
        // 0x800E6278: lw          $t7, 0x34($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X34);
            goto L_800E6298;
    }
    goto skip_2;
    // 0x800E6278: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x800E627C: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x800E6280: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800E6284: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E6288: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800E628C: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x800E6290: swc1        $f18, 0x7A8($s0)
    MEM_W(0X7A8, ctx->r16) = ctx->f18.u32l;
L_800E6294:
    // 0x800E6294: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
L_800E6298:
    // 0x800E6298: lw          $t8, 0x7CC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7CC);
    // 0x800E629C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E62A0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800E62A4: bgtz        $t9, L_800E62D0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800E62A8: sw          $t9, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r25;
            goto L_800E62D0;
    }
    // 0x800E62A8: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x800E62AC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800E62B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800E62B4: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x800E62B8: bne         $t1, $at, L_800E62CC
    if (ctx->r9 != ctx->r1) {
        // 0x800E62BC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800E62CC;
    }
    // 0x800E62BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800E62C0: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x800E62C4: b           L_800E62D0
    // 0x800E62C8: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
        goto L_800E62D0;
    // 0x800E62C8: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
L_800E62CC:
    // 0x800E62CC: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
L_800E62D0:
    // 0x800E62D0: lwc1        $f0, 0x7E0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7E0);
    // 0x800E62D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E62D8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800E62DC: nop

    // 0x800E62E0: bc1tl       L_800E64B8
    if (c1cs) {
        // 0x800E62E4: lw          $t1, 0x7C8($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X7C8);
            goto L_800E64B8;
    }
    goto skip_3;
    // 0x800E62E4: lw          $t1, 0x7C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C8);
    skip_3:
    // 0x800E62E8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E62EC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800E62F0: beq         $v0, $at, L_800E62FC
    if (ctx->r2 == ctx->r1) {
        // 0x800E62F4: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_800E62FC;
    }
    // 0x800E62F4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800E62F8: bne         $v0, $at, L_800E6310
    if (ctx->r2 != ctx->r1) {
        // 0x800E62FC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800E6310;
    }
L_800E62FC:
    // 0x800E62FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E6300: lwc1        $f6, -0x174($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X174);
    // 0x800E6304: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E6308: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800E630C: swc1        $f8, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->f8.u32l;
L_800E6310:
    // 0x800E6310: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800E6314: bne         $v0, $at, L_800E6320
    if (ctx->r2 != ctx->r1) {
        // 0x800E6318: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_800E6320;
    }
    // 0x800E6318: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800E631C: sw          $t4, 0x814($s0)
    MEM_W(0X814, ctx->r16) = ctx->r12;
L_800E6320:
    // 0x800E6320: lwc1        $f2, 0x7E8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7E8);
    // 0x800E6324: lwc1        $f12, 0x7E4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X7E4);
    // 0x800E6328: lwc1        $f0, 0x7E0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7E0);
    // 0x800E632C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800E6330: nop

    // 0x800E6334: bc1fl       L_800E6348
    if (!c1cs) {
        // 0x800E6338: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_800E6348;
    }
    goto skip_4;
    // 0x800E6338: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_4:
    // 0x800E633C: b           L_800E6348
    // 0x800E6340: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
        goto L_800E6348;
    // 0x800E6340: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800E6344: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_800E6348:
    // 0x800E6348: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800E634C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E6350: swc1        $f10, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->f10.u32l;
    // 0x800E6354: lwc1        $f16, 0x7E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7E0);
    // 0x800E6358: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x800E635C: nop

    // 0x800E6360: bc1f        L_800E636C
    if (!c1cs) {
        // 0x800E6364: nop
    
            goto L_800E636C;
    }
    // 0x800E6364: nop

    // 0x800E6368: swc1        $f2, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->f2.u32l;
L_800E636C:
    // 0x800E636C: jal         0x800EA248
    // 0x800E6370: lw          $a1, 0x7F0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7F0);
    ftParamUpdateDamage(rdram, ctx);
        goto after_0;
    // 0x800E6370: lw          $a1, 0x7F0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7F0);
    after_0:
    // 0x800E6374: lw          $v0, 0x9F0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9F0);
    // 0x800E6378: beql        $v0, $zero, L_800E638C
    if (ctx->r2 == 0) {
        // 0x800E637C: lw          $t5, 0x8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X8);
            goto L_800E638C;
    }
    goto skip_5;
    // 0x800E637C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x800E6380: jalr        $v0
    // 0x800E6384: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800E6384: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_1:
    // 0x800E6388: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
L_800E638C:
    // 0x800E638C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800E6390: beq         $t5, $at, L_800E6418
    if (ctx->r13 == ctx->r1) {
        // 0x800E6394: nop
    
            goto L_800E6418;
    }
    // 0x800E6394: nop

    // 0x800E6398: lw          $a1, 0x814($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X814);
    // 0x800E639C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E63A0: beq         $a1, $at, L_800E63C8
    if (ctx->r5 == ctx->r1) {
        // 0x800E63A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800E63C8;
    }
    // 0x800E63A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E63A8: beq         $a1, $at, L_800E63E0
    if (ctx->r5 == ctx->r1) {
        // 0x800E63AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800E63E0;
    }
    // 0x800E63AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E63B0: beq         $a1, $at, L_800E63F0
    if (ctx->r5 == ctx->r1) {
        // 0x800E63B4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800E63F0;
    }
    // 0x800E63B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E63B8: beql        $a1, $at, L_800E642C
    if (ctx->r5 == ctx->r1) {
        // 0x800E63BC: lw          $t6, 0x7DC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7DC);
            goto L_800E642C;
    }
    goto skip_6;
    // 0x800E63BC: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
    skip_6:
    // 0x800E63C0: b           L_800E6408
    // 0x800E63C4: nop

        goto L_800E6408;
    // 0x800E63C4: nop

L_800E63C8:
    // 0x800E63C8: jal         0x800E823C
    // 0x800E63CC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_2;
    // 0x800E63CC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_2:
    // 0x800E63D0: jal         0x80141560
    // 0x800E63D4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_3;
    // 0x800E63D4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_3:
    // 0x800E63D8: b           L_800E642C
    // 0x800E63DC: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
        goto L_800E642C;
    // 0x800E63DC: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
L_800E63E0:
    // 0x800E63E0: jal         0x80141648
    // 0x800E63E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_4;
    // 0x800E63E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_4:
    // 0x800E63E8: b           L_800E642C
    // 0x800E63EC: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
        goto L_800E642C;
    // 0x800E63EC: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
L_800E63F0:
    // 0x800E63F0: jal         0x800E823C
    // 0x800E63F4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_5;
    // 0x800E63F4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_5:
    // 0x800E63F8: jal         0x80140E2C
    // 0x800E63FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonDamageUpdateCatchResist(rdram, ctx);
        goto after_6;
    // 0x800E63FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_6:
    // 0x800E6400: b           L_800E642C
    // 0x800E6404: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
        goto L_800E642C;
    // 0x800E6404: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
L_800E6408:
    // 0x800E6408: jal         0x80141670
    // 0x800E640C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonDamageUpdateMain(rdram, ctx);
        goto after_7;
    // 0x800E640C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_7:
    // 0x800E6410: b           L_800E642C
    // 0x800E6414: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
        goto L_800E642C;
    // 0x800E6414: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
L_800E6418:
    // 0x800E6418: jal         0x80141648
    // 0x800E641C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_8;
    // 0x800E641C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_8:
    // 0x800E6420: jal         0x801586A0
    // 0x800E6424: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftBossCommonUpdateDamageStats(rdram, ctx);
        goto after_9;
    // 0x800E6424: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_9:
    // 0x800E6428: lw          $t6, 0x7DC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7DC);
L_800E642C:
    // 0x800E642C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E6430: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x800E6434: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x800E6438: lw          $t8, 0x7F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7F8);
    // 0x800E643C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E6440: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800E6444: bne         $t8, $at, L_800E6454
    if (ctx->r24 != ctx->r1) {
        // 0x800E6448: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E6454;
    }
    // 0x800E6448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E644C: b           L_800E6458
    // 0x800E6450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800E6458;
    // 0x800E6450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800E6454:
    // 0x800E6454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800E6458:
    // 0x800E6458: lwc1        $f18, 0x7A4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7A4);
    // 0x800E645C: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x800E6460: jal         0x800E7F88
    // 0x800E6464: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    ftParamSetDamageShuffle(rdram, ctx);
        goto after_10;
    // 0x800E6464: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x800E6468: lw          $t9, 0x7F0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7F0);
    // 0x800E646C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800E6470: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E6474: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800E6478: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800E647C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E6480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E6484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E6488: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E648C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800E6490: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800E6494: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800E6498: nop

    // 0x800E649C: blezl       $a2, L_800E667C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800E64A0: lw          $t6, 0x98($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X98);
            goto L_800E667C;
    }
    goto skip_7;
    // 0x800E64A0: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    skip_7:
    // 0x800E64A4: jal         0x800E806C
    // 0x800E64A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_11;
    // 0x800E64A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800E64AC: b           L_800E667C
    // 0x800E64B0: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E64B0: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800E64B4: lw          $t1, 0x7C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C8);
L_800E64B8:
    // 0x800E64B8: beql        $t1, $zero, L_800E64F0
    if (ctx->r9 == 0) {
        // 0x800E64BC: lw          $t3, 0x7BC($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X7BC);
            goto L_800E64F0;
    }
    goto skip_8;
    // 0x800E64BC: lw          $t3, 0x7BC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7BC);
    skip_8:
    // 0x800E64C0: beq         $v1, $zero, L_800E64D8
    if (ctx->r3 == 0) {
        // 0x800E64C4: nop
    
            goto L_800E64D8;
    }
    // 0x800E64C4: nop

    // 0x800E64C8: jal         0x80149510
    // 0x800E64CC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonShieldBreakFlyCommonSetStatus(rdram, ctx);
        goto after_12;
    // 0x800E64CC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_12:
    // 0x800E64D0: b           L_800E64E4
    // 0x800E64D4: lw          $t2, 0x7C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C8);
        goto L_800E64E4;
    // 0x800E64D4: lw          $t2, 0x7C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C8);
L_800E64D8:
    // 0x800E64D8: jal         0x80149108
    // 0x800E64DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonGuardSetOffSetStatus(rdram, ctx);
        goto after_13;
    // 0x800E64DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_13:
    // 0x800E64E0: lw          $t2, 0x7C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C8);
L_800E64E4:
    // 0x800E64E4: b           L_800E6678
    // 0x800E64E8: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
        goto L_800E6678;
    // 0x800E64E8: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800E64EC: lw          $t3, 0x7BC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7BC);
L_800E64F0:
    // 0x800E64F0: beql        $t3, $zero, L_800E655C
    if (ctx->r11 == 0) {
        // 0x800E64F4: lw          $v0, 0x7B0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X7B0);
            goto L_800E655C;
    }
    goto skip_9;
    // 0x800E64F4: lw          $v0, 0x7B0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7B0);
    skip_9:
    // 0x800E64F8: lw          $v0, 0x9F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9F4);
    // 0x800E64FC: beql        $v0, $zero, L_800E6510
    if (ctx->r2 == 0) {
        // 0x800E6500: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800E6510;
    }
    goto skip_10;
    // 0x800E6500: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_10:
    // 0x800E6504: jalr        $v0
    // 0x800E6508: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_14;
    // 0x800E6508: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_14:
    // 0x800E650C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800E6510:
    // 0x800E6510: lwc1        $f8, 0x7C0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C0);
    // 0x800E6514: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800E6518: nop

    // 0x800E651C: bc1tl       L_800E6550
    if (c1cs) {
        // 0x800E6520: lw          $t6, 0x7BC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7BC);
            goto L_800E6550;
    }
    goto skip_11;
    // 0x800E6520: lw          $t6, 0x7BC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7BC);
    skip_11:
    // 0x800E6524: lw          $t4, 0x840($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X840);
    // 0x800E6528: bnel        $t4, $zero, L_800E6550
    if (ctx->r12 != 0) {
        // 0x800E652C: lw          $t6, 0x7BC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7BC);
            goto L_800E6550;
    }
    goto skip_12;
    // 0x800E652C: lw          $t6, 0x7BC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7BC);
    skip_12:
    // 0x800E6530: lw          $t5, 0x844($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X844);
    // 0x800E6534: bnel        $t5, $zero, L_800E6550
    if (ctx->r13 != 0) {
        // 0x800E6538: lw          $t6, 0x7BC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7BC);
            goto L_800E6550;
    }
    goto skip_13;
    // 0x800E6538: lw          $t6, 0x7BC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7BC);
    skip_13:
    // 0x800E653C: jal         0x800E823C
    // 0x800E6540: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_15;
    // 0x800E6540: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_15:
    // 0x800E6544: jal         0x80144AB0
    // 0x800E6548: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonReboundWaitSetStatus(rdram, ctx);
        goto after_16;
    // 0x800E6548: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_16:
    // 0x800E654C: lw          $t6, 0x7BC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7BC);
L_800E6550:
    // 0x800E6550: b           L_800E6678
    // 0x800E6554: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
        goto L_800E6678;
    // 0x800E6554: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x800E6558: lw          $v0, 0x7B0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7B0);
L_800E655C:
    // 0x800E655C: beql        $v0, $zero, L_800E65F4
    if (ctx->r2 == 0) {
        // 0x800E6560: lw          $t0, 0x7D8($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X7D8);
            goto L_800E65F4;
    }
    goto skip_14;
    // 0x800E6560: lw          $t0, 0x7D8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7D8);
    skip_14:
    // 0x800E6564: lw          $v1, 0x9F8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X9F8);
    // 0x800E6568: beql        $v1, $zero, L_800E6580
    if (ctx->r3 == 0) {
        // 0x800E656C: sw          $v0, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r2;
            goto L_800E6580;
    }
    goto skip_15;
    // 0x800E656C: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    skip_15:
    // 0x800E6570: jalr        $v1
    // 0x800E6574: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_17;
    // 0x800E6574: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_17:
    // 0x800E6578: lw          $v0, 0x7B0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7B0);
    // 0x800E657C: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
L_800E6580:
    // 0x800E6580: lw          $t7, 0x28C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28C);
    // 0x800E6584: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800E6588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E658C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x800E6590: bne         $t8, $at, L_800E65A8
    if (ctx->r24 != ctx->r1) {
        // 0x800E6594: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800E65A8;
    }
    // 0x800E6594: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800E6598: jal         0x800E806C
    // 0x800E659C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_18;
    // 0x800E659C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x800E65A0: b           L_800E667C
    // 0x800E65A4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E65A4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
L_800E65A8:
    // 0x800E65A8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800E65AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800E65B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E65B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E65B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800E65BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E65C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E65C4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800E65C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800E65CC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E65D0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800E65D4: nop

    // 0x800E65D8: blezl       $a2, L_800E667C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800E65DC: lw          $t6, 0x98($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X98);
            goto L_800E667C;
    }
    goto skip_16;
    // 0x800E65DC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    skip_16:
    // 0x800E65E0: jal         0x800E806C
    // 0x800E65E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    ftParamMakeRumble(rdram, ctx);
        goto after_19;
    // 0x800E65E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x800E65E8: b           L_800E667C
    // 0x800E65EC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E65EC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800E65F0: lw          $t0, 0x7D8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7D8);
L_800E65F4:
    // 0x800E65F4: beql        $t0, $zero, L_800E6610
    if (ctx->r8 == 0) {
        // 0x800E65F8: lw          $v0, 0x18C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X18C);
            goto L_800E6610;
    }
    goto skip_17;
    // 0x800E65F8: lw          $v0, 0x18C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18C);
    skip_17:
    // 0x800E65FC: jal         0x80149608
    // 0x800E6600: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftCommonShieldBreakFlyReflectorSetStatus(rdram, ctx);
        goto after_20;
    // 0x800E6600: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_20:
    // 0x800E6604: b           L_800E667C
    // 0x800E6608: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E6608: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800E660C: lw          $v0, 0x18C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18C);
L_800E6610:
    // 0x800E6610: sll         $t1, $v0, 6
    ctx->r9 = S32(ctx->r2 << 6);
    // 0x800E6614: sra         $t2, $t1, 30
    ctx->r10 = S32(SIGNED(ctx->r9) >> 30);
    // 0x800E6618: beq         $t2, $zero, L_800E6664
    if (ctx->r10 == 0) {
        // 0x800E661C: sll         $t4, $v0, 9
        ctx->r12 = S32(ctx->r2 << 9);
            goto L_800E6664;
    }
    // 0x800E661C: sll         $t4, $v0, 9
    ctx->r12 = S32(ctx->r2 << 9);
    // 0x800E6620: lw          $t3, 0x850($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X850);
    // 0x800E6624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E6628: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800E662C: beq         $a1, $zero, L_800E6644
    if (ctx->r5 == 0) {
        // 0x800E6630: nop
    
            goto L_800E6644;
    }
    // 0x800E6630: nop

    // 0x800E6634: beq         $a1, $at, L_800E6654
    if (ctx->r5 == ctx->r1) {
        // 0x800E6638: nop
    
            goto L_800E6654;
    }
    // 0x800E6638: nop

    // 0x800E663C: b           L_800E667C
    // 0x800E6640: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E6640: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
L_800E6644:
    // 0x800E6644: jal         0x8015CEE8
    // 0x800E6648: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftFoxSpecialLwHitSetStatus(rdram, ctx);
        goto after_21;
    // 0x800E6648: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_21:
    // 0x800E664C: b           L_800E667C
    // 0x800E6650: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E6650: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
L_800E6654:
    // 0x800E6654: jal         0x800269C0
    // 0x800E6658: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    func_800269C0_275C0(rdram, ctx);
        goto after_22;
    // 0x800E6658: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_22:
    // 0x800E665C: b           L_800E667C
    // 0x800E6660: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
        goto L_800E667C;
    // 0x800E6660: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
L_800E6664:
    // 0x800E6664: sra         $t5, $t4, 30
    ctx->r13 = S32(SIGNED(ctx->r12) >> 30);
    // 0x800E6668: beql        $t5, $zero, L_800E667C
    if (ctx->r13 == 0) {
        // 0x800E666C: lw          $t6, 0x98($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X98);
            goto L_800E667C;
    }
    goto skip_18;
    // 0x800E666C: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    skip_18:
    // 0x800E6670: jal         0x8015521C
    // 0x800E6674: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftNessSpecialLwProcAbsorb(rdram, ctx);
        goto after_23;
    // 0x800E6674: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_23:
L_800E6678:
    // 0x800E6678: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
L_800E667C:
    // 0x800E667C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x800E6680: beq         $t6, $zero, L_800E66CC
    if (ctx->r14 == 0) {
        // 0x800E6684: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800E66CC;
    }
    // 0x800E6684: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800E6688: jal         0x800EA1C0
    // 0x800E668C: lw          $a2, 0x7A4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7A4);
    ftParamGetHitLag(rdram, ctx);
        goto after_24;
    // 0x800E668C: lw          $a2, 0x7A4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7A4);
    after_24:
    // 0x800E6690: beq         $v0, $zero, L_800E66B0
    if (ctx->r2 == 0) {
        // 0x800E6694: sw          $v0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r2;
            goto L_800E66B0;
    }
    // 0x800E6694: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800E6698: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800E669C: beql        $t7, $zero, L_800E66B4
    if (ctx->r15 == 0) {
        // 0x800E66A0: lw          $v0, 0xA04($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XA04);
            goto L_800E66B4;
    }
    goto skip_19;
    // 0x800E66A0: lw          $v0, 0xA04($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA04);
    skip_19:
    // 0x800E66A4: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
    // 0x800E66A8: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x800E66AC: sb          $t0, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r8;
L_800E66B0:
    // 0x800E66B0: lw          $v0, 0xA04($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA04);
L_800E66B4:
    // 0x800E66B4: sh          $zero, 0x1C0($s0)
    MEM_H(0X1C0, ctx->r16) = 0;
    // 0x800E66B8: sh          $zero, 0x1BE($s0)
    MEM_H(0X1BE, ctx->r16) = 0;
    // 0x800E66BC: beql        $v0, $zero, L_800E66D0
    if (ctx->r2 == 0) {
        // 0x800E66C0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800E66D0;
    }
    goto skip_20;
    // 0x800E66C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_20:
    // 0x800E66C4: jalr        $v0
    // 0x800E66C8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_25;
    // 0x800E66C8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_25:
L_800E66CC:
    // 0x800E66CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800E66D0:
    // 0x800E66D0: lb          $t2, 0x18C($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X18C);
    // 0x800E66D4: lb          $t4, 0x18D($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X18D);
    // 0x800E66D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E66DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E66E0: andi        $t3, $t2, 0xFFFC
    ctx->r11 = ctx->r10 & 0XFFFC;
    // 0x800E66E4: andi        $t5, $t4, 0xFF9F
    ctx->r13 = ctx->r12 & 0XFF9F;
    // 0x800E66E8: sw          $zero, 0x7AC($s0)
    MEM_W(0X7AC, ctx->r16) = 0;
    // 0x800E66EC: sw          $zero, 0x7B0($s0)
    MEM_W(0X7B0, ctx->r16) = 0;
    // 0x800E66F0: sw          $zero, 0x7BC($s0)
    MEM_W(0X7BC, ctx->r16) = 0;
    // 0x800E66F4: sw          $zero, 0x7C8($s0)
    MEM_W(0X7C8, ctx->r16) = 0;
    // 0x800E66F8: sw          $zero, 0x7CC($s0)
    MEM_W(0X7CC, ctx->r16) = 0;
    // 0x800E66FC: sw          $zero, 0x7DC($s0)
    MEM_W(0X7DC, ctx->r16) = 0;
    // 0x800E6700: sw          $zero, 0x7F0($s0)
    MEM_W(0X7F0, ctx->r16) = 0;
    // 0x800E6704: sw          $zero, 0x814($s0)
    MEM_W(0X814, ctx->r16) = 0;
    // 0x800E6708: sb          $t3, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r11;
    // 0x800E670C: sw          $zero, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = 0;
    // 0x800E6710: sb          $t5, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r13;
    // 0x800E6714: swc1        $f0, 0x7A0($s0)
    MEM_W(0X7A0, ctx->r16) = ctx->f0.u32l;
    // 0x800E6718: swc1        $f0, 0x7C0($s0)
    MEM_W(0X7C0, ctx->r16) = ctx->f0.u32l;
    // 0x800E671C: swc1        $f0, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->f0.u32l;
    // 0x800E6720: swc1        $f16, 0x7A4($s0)
    MEM_W(0X7A4, ctx->r16) = ctx->f16.u32l;
    // 0x800E6724: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800E6728: bnel        $t6, $zero, L_800E69B4
    if (ctx->r14 != 0) {
        // 0x800E672C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_21;
    // 0x800E672C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
    // 0x800E6730: lb          $t7, 0xA9D($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XA9D);
    // 0x800E6734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6738: beql        $t7, $at, L_800E69B4
    if (ctx->r15 == ctx->r1) {
        // 0x800E673C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_22;
    // 0x800E673C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_22:
    // 0x800E6740: lbu         $a1, 0xA9C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA9C);
    // 0x800E6744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6748: beql        $a1, $zero, L_800E6764
    if (ctx->r5 == 0) {
        // 0x800E674C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800E6764;
    }
    goto skip_23;
    // 0x800E674C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_23:
    // 0x800E6750: beql        $a1, $at, L_800E6874
    if (ctx->r5 == ctx->r1) {
        // 0x800E6754: lw          $v0, 0x84C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84C);
            goto L_800E6874;
    }
    goto skip_24;
    // 0x800E6754: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    skip_24:
    // 0x800E6758: b           L_800E69B4
    // 0x800E675C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E69B4;
    // 0x800E675C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E6760: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800E6764:
    // 0x800E6764: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E6768: bnel        $t8, $at, L_800E69B4
    if (ctx->r24 != ctx->r1) {
        // 0x800E676C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_25;
    // 0x800E676C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
    // 0x800E6770: lb          $t9, 0x98B($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X98B);
    // 0x800E6774: bnel        $t9, $zero, L_800E69B4
    if (ctx->r25 != 0) {
        // 0x800E6778: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_26;
    // 0x800E6778: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_26:
    // 0x800E677C: lw          $a0, 0x914($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X914);
    // 0x800E6780: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800E6784: jal         0x800EDBA4
    // 0x800E6788: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_26;
    // 0x800E6788: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    after_26:
    // 0x800E678C: lbu         $t2, 0xA9E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6790: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800E6794: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800E6798: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E679C: lwc1        $f18, 0x80($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X80);
    // 0x800E67A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E67A4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800E67A8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800E67AC: mflo        $t3
    ctx->r11 = lo;
    // 0x800E67B0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800E67B4: sh          $t1, 0xAA0($t4)
    MEM_H(0XAA0, ctx->r12) = ctx->r9;
    // 0x800E67B8: lbu         $t7, 0xA9E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E67BC: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x800E67C0: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E67C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800E67C8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800E67CC: mflo        $t8
    ctx->r24 = lo;
    // 0x800E67D0: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800E67D4: sh          $t6, 0xAA2($t9)
    MEM_H(0XAA2, ctx->r25) = ctx->r14;
    // 0x800E67D8: lbu         $t3, 0xA9E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E67DC: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x800E67E0: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E67E4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800E67E8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800E67EC: mflo        $t1
    ctx->r9 = lo;
    // 0x800E67F0: addu        $t4, $s0, $t1
    ctx->r12 = ADD32(ctx->r16, ctx->r9);
    // 0x800E67F4: sh          $t2, 0xAA4($t4)
    MEM_H(0XAA4, ctx->r12) = ctx->r10;
    // 0x800E67F8: lbu         $t5, 0xA9E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E67FC: lwc1        $f18, 0x70($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X70);
    // 0x800E6800: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E6804: mflo        $t7
    ctx->r15 = lo;
    // 0x800E6808: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800E680C: swc1        $f18, 0xAA8($t8)
    MEM_W(0XAA8, ctx->r24) = ctx->f18.u32l;
    // 0x800E6810: lbu         $t6, 0xA9E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6814: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x800E6818: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E681C: mflo        $t9
    ctx->r25 = lo;
    // 0x800E6820: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800E6824: swc1        $f4, 0xAAC($t0)
    MEM_W(0XAAC, ctx->r8) = ctx->f4.u32l;
    // 0x800E6828: lbu         $t3, 0xA9E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E682C: lwc1        $f6, 0x78($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X78);
    // 0x800E6830: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E6834: mflo        $t1
    ctx->r9 = lo;
    // 0x800E6838: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x800E683C: swc1        $f6, 0xAB0($t2)
    MEM_W(0XAB0, ctx->r10) = ctx->f6.u32l;
    // 0x800E6840: lbu         $a0, 0xA9E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6844: bne         $a0, $at, L_800E6854
    if (ctx->r4 != ctx->r1) {
        // 0x800E6848: addiu       $t4, $a0, 0x1
        ctx->r12 = ADD32(ctx->r4, 0X1);
            goto L_800E6854;
    }
    // 0x800E6848: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x800E684C: b           L_800E6858
    // 0x800E6850: sb          $zero, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = 0;
        goto L_800E6858;
    // 0x800E6850: sb          $zero, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = 0;
L_800E6854:
    // 0x800E6854: sb          $t4, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = ctx->r12;
L_800E6858:
    // 0x800E6858: lb          $v0, 0xA9D($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA9D);
    // 0x800E685C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800E6860: beq         $at, $zero, L_800E69B0
    if (ctx->r1 == 0) {
        // 0x800E6864: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_800E69B0;
    }
    // 0x800E6864: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800E6868: b           L_800E69B0
    // 0x800E686C: sb          $t5, 0xA9D($s0)
    MEM_B(0XA9D, ctx->r16) = ctx->r13;
        goto L_800E69B0;
    // 0x800E686C: sb          $t5, 0xA9D($s0)
    MEM_B(0XA9D, ctx->r16) = ctx->r13;
    // 0x800E6870: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
L_800E6874:
    // 0x800E6874: beql        $v0, $zero, L_800E69B4
    if (ctx->r2 == 0) {
        // 0x800E6878: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_27;
    // 0x800E6878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_27:
    // 0x800E687C: lw          $t7, 0x190($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X190);
    // 0x800E6880: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x800E6884: bgezl       $t6, L_800E69B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E6888: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_28;
    // 0x800E6888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x800E688C: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x800E6890: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E6894: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800E6898: bnel        $t0, $at, L_800E69B4
    if (ctx->r8 != ctx->r1) {
        // 0x800E689C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E69B4;
    }
    goto skip_29;
    // 0x800E689C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_29:
    // 0x800E68A0: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x800E68A4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800E68A8: lw          $t1, 0x33C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X33C);
    // 0x800E68AC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800E68B0: addu        $t4, $s0, $t2
    ctx->r12 = ADD32(ctx->r16, ctx->r10);
    // 0x800E68B4: jal         0x800C9A38
    // 0x800E68B8: lw          $a1, 0x8E8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8E8);
    func_ovl0_800C9A38(rdram, ctx);
        goto after_27;
    // 0x800E68B8: lw          $a1, 0x8E8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8E8);
    after_27:
    // 0x800E68BC: lbu         $t8, 0xA9E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E68C0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800E68C4: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800E68C8: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E68CC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E68D0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800E68D4: mflo        $t6
    ctx->r14 = lo;
    // 0x800E68D8: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x800E68DC: sh          $t7, 0xAA0($t9)
    MEM_H(0XAA0, ctx->r25) = ctx->r15;
    // 0x800E68E0: lbu         $t1, 0xA9E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E68E4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800E68E8: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E68EC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800E68F0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800E68F4: mflo        $t2
    ctx->r10 = lo;
    // 0x800E68F8: addu        $t4, $s0, $t2
    ctx->r12 = ADD32(ctx->r16, ctx->r10);
    // 0x800E68FC: sh          $t3, 0xAA2($t4)
    MEM_H(0XAA2, ctx->r12) = ctx->r11;
    // 0x800E6900: lbu         $t6, 0xA9E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6904: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800E6908: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E690C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800E6910: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800E6914: mflo        $t7
    ctx->r15 = lo;
    // 0x800E6918: addu        $t9, $s0, $t7
    ctx->r25 = ADD32(ctx->r16, ctx->r15);
    // 0x800E691C: sh          $t8, 0xAA4($t9)
    MEM_H(0XAA4, ctx->r25) = ctx->r24;
    // 0x800E6920: lbu         $t0, 0xA9E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6924: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800E6928: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E692C: mflo        $t1
    ctx->r9 = lo;
    // 0x800E6930: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x800E6934: swc1        $f8, 0xAA8($t2)
    MEM_W(0XAA8, ctx->r10) = ctx->f8.u32l;
    // 0x800E6938: lbu         $t3, 0xA9E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E693C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800E6940: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E6944: mflo        $t4
    ctx->r12 = lo;
    // 0x800E6948: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x800E694C: swc1        $f10, 0xAAC($t5)
    MEM_W(0XAAC, ctx->r13) = ctx->f10.u32l;
    // 0x800E6950: lbu         $t6, 0xA9E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6954: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800E6958: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E695C: mflo        $t7
    ctx->r15 = lo;
    // 0x800E6960: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800E6964: swc1        $f16, 0xAB0($t8)
    MEM_W(0XAB0, ctx->r24) = ctx->f16.u32l;
    // 0x800E6968: lbu         $t9, 0xA9E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E696C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E6970: mflo        $t0
    ctx->r8 = lo;
    // 0x800E6974: addu        $a0, $s0, $t0
    ctx->r4 = ADD32(ctx->r16, ctx->r8);
    // 0x800E6978: jal         0x80018EE0
    // 0x800E697C: addiu       $a0, $a0, 0xAA8
    ctx->r4 = ADD32(ctx->r4, 0XAA8);
    syVectorNorm3D(rdram, ctx);
        goto after_28;
    // 0x800E697C: addiu       $a0, $a0, 0xAA8
    ctx->r4 = ADD32(ctx->r4, 0XAA8);
    after_28:
    // 0x800E6980: lbu         $a0, 0xA9E($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA9E);
    // 0x800E6984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E6988: bne         $a0, $at, L_800E6998
    if (ctx->r4 != ctx->r1) {
        // 0x800E698C: addiu       $t1, $a0, 0x1
        ctx->r9 = ADD32(ctx->r4, 0X1);
            goto L_800E6998;
    }
    // 0x800E698C: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x800E6990: b           L_800E699C
    // 0x800E6994: sb          $zero, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = 0;
        goto L_800E699C;
    // 0x800E6994: sb          $zero, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = 0;
L_800E6998:
    // 0x800E6998: sb          $t1, 0xA9E($s0)
    MEM_B(0XA9E, ctx->r16) = ctx->r9;
L_800E699C:
    // 0x800E699C: lb          $v0, 0xA9D($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XA9D);
    // 0x800E69A0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800E69A4: beq         $at, $zero, L_800E69B0
    if (ctx->r1 == 0) {
        // 0x800E69A8: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_800E69B0;
    }
    // 0x800E69A8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800E69AC: sb          $t2, 0xA9D($s0)
    MEM_B(0XA9D, ctx->r16) = ctx->r10;
L_800E69B0:
    // 0x800E69B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E69B4:
    // 0x800E69B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E69B8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800E69BC: jr          $ra
    // 0x800E69C0: nop

    return;
    // 0x800E69C0: nop

;}
RECOMP_FUNC void ftCommonAttackS3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014F764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F768: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014F76C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014F770: jal         0x80146064
    // 0x8014F774: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014F774: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014F778: bne         $v0, $zero, L_8014F8B0
    if (ctx->r2 != 0) {
        // 0x8014F77C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8014F8B0;
    }
    // 0x8014F77C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8014F780: lw          $t6, 0x9C4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X9C4);
    // 0x8014F784: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x8014F788: lw          $t7, 0x7EC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7EC);
    // 0x8014F78C: beql        $t7, $zero, L_8014F834
    if (ctx->r15 == 0) {
        // 0x8014F790: lw          $t8, 0x7E0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X7E0);
            goto L_8014F834;
    }
    goto skip_0;
    // 0x8014F790: lw          $t8, 0x7E0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7E0);
    skip_0:
    // 0x8014F794: jal         0x800E8000
    // 0x8014F798: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x8014F798: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8014F79C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F7A0: lwc1        $f4, -0x3B60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B60);
    // 0x8014F7A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F7A8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8014F7AC: nop

    // 0x8014F7B0: bc1f        L_8014F7C0
    if (!c1cs) {
        // 0x8014F7B4: nop
    
            goto L_8014F7C0;
    }
    // 0x8014F7B4: nop

    // 0x8014F7B8: b           L_8014F894
    // 0x8014F7BC: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
        goto L_8014F894;
    // 0x8014F7BC: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
L_8014F7C0:
    // 0x8014F7C0: lwc1        $f6, -0x3B5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3B5C);
    // 0x8014F7C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F7C8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8014F7CC: nop

    // 0x8014F7D0: bc1f        L_8014F7E0
    if (!c1cs) {
        // 0x8014F7D4: nop
    
            goto L_8014F7E0;
    }
    // 0x8014F7D4: nop

    // 0x8014F7D8: b           L_8014F894
    // 0x8014F7DC: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
        goto L_8014F894;
    // 0x8014F7DC: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
L_8014F7E0:
    // 0x8014F7E0: lwc1        $f8, -0x3B58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B58);
    // 0x8014F7E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F7E8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8014F7EC: nop

    // 0x8014F7F0: bc1f        L_8014F800
    if (!c1cs) {
        // 0x8014F7F4: nop
    
            goto L_8014F800;
    }
    // 0x8014F7F4: nop

    // 0x8014F7F8: b           L_8014F824
    // 0x8014F7FC: addiu       $v1, $zero, 0xC5
    ctx->r3 = ADD32(0, 0XC5);
        goto L_8014F824;
    // 0x8014F7FC: addiu       $v1, $zero, 0xC5
    ctx->r3 = ADD32(0, 0XC5);
L_8014F800:
    // 0x8014F800: lwc1        $f10, -0x3B54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3B54);
    // 0x8014F804: addiu       $v0, $zero, 0xC3
    ctx->r2 = ADD32(0, 0XC3);
    // 0x8014F808: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8014F80C: nop

    // 0x8014F810: bc1f        L_8014F820
    if (!c1cs) {
        // 0x8014F814: nop
    
            goto L_8014F820;
    }
    // 0x8014F814: nop

    // 0x8014F818: b           L_8014F820
    // 0x8014F81C: addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
        goto L_8014F820;
    // 0x8014F81C: addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
L_8014F820:
    // 0x8014F820: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8014F824:
    // 0x8014F824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8014F828: b           L_8014F894
    // 0x8014F82C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8014F894;
    // 0x8014F82C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014F830: lw          $t8, 0x7E0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7E0);
L_8014F834:
    // 0x8014F834: beql        $t8, $zero, L_8014F894
    if (ctx->r24 == 0) {
        // 0x8014F838: addiu       $a1, $zero, 0xC3
        ctx->r5 = ADD32(0, 0XC3);
            goto L_8014F894;
    }
    goto skip_1;
    // 0x8014F838: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    skip_1:
    // 0x8014F83C: jal         0x800E8000
    // 0x8014F840: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_2;
    // 0x8014F840: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8014F844: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F848: lwc1        $f16, -0x3B50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3B50);
    // 0x8014F84C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F850: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8014F854: nop

    // 0x8014F858: bc1f        L_8014F868
    if (!c1cs) {
        // 0x8014F85C: nop
    
            goto L_8014F868;
    }
    // 0x8014F85C: nop

    // 0x8014F860: b           L_8014F894
    // 0x8014F864: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
        goto L_8014F894;
    // 0x8014F864: addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
L_8014F868:
    // 0x8014F868: lwc1        $f18, -0x3B4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3B4C);
    // 0x8014F86C: addiu       $v0, $zero, 0xC3
    ctx->r2 = ADD32(0, 0XC3);
    // 0x8014F870: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8014F874: nop

    // 0x8014F878: bc1f        L_8014F888
    if (!c1cs) {
        // 0x8014F87C: nop
    
            goto L_8014F888;
    }
    // 0x8014F87C: nop

    // 0x8014F880: b           L_8014F894
    // 0x8014F884: addiu       $a1, $zero, 0xC5
    ctx->r5 = ADD32(0, 0XC5);
        goto L_8014F894;
    // 0x8014F884: addiu       $a1, $zero, 0xC5
    ctx->r5 = ADD32(0, 0XC5);
L_8014F888:
    // 0x8014F888: b           L_8014F894
    // 0x8014F88C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8014F894;
    // 0x8014F88C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014F890: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
L_8014F894:
    // 0x8014F894: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014F898: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014F89C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014F8A0: jal         0x800E6F24
    // 0x8014F8A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x8014F8A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8014F8A8: jal         0x800E0830
    // 0x8014F8AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_4;
    // 0x8014F8AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_8014F8B0:
    // 0x8014F8B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F8B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014F8B8: jr          $ra
    // 0x8014F8BC: nop

    return;
    // 0x8014F8BC: nop

;}
RECOMP_FUNC void itDogasWeaponSmogMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80183148: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018314C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183150: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80183154: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80183158: addiu       $a1, $a1, -0x4CCC
    ctx->r5 = ADD32(ctx->r5, -0X4CCC);
    // 0x8018315C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80183160: jal         0x801655C8
    // 0x80183164: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80183164: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80183168: bne         $v0, $zero, L_80183178
    if (ctx->r2 != 0) {
        // 0x8018316C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80183178;
    }
    // 0x8018316C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80183170: b           L_801831FC
    // 0x80183174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801831FC;
    // 0x80183174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80183178:
    // 0x80183178: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8018317C: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80183180: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80183184: sw          $t6, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r14;
    // 0x80183188: lw          $t7, -0x4CC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CC4);
    // 0x8018318C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80183190: lw          $t9, -0x4CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CC0);
    // 0x80183194: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80183198: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8018319C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801831A0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801831A4: sw          $t0, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->r8;
    // 0x801831A8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x801831AC: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x801831B0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801831B4: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x801831B8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801831BC: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x801831C0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801831C4: sw          $t3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r11;
    // 0x801831C8: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x801831CC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801831D0: jal         0x80008CC0
    // 0x801831D4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x801831D4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x801831D8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x801831DC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801831E0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x801831E4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x801831E8: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x801831EC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801831F0: sw          $t5, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r13;
    // 0x801831F4: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801831F8: sw          $t6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r14;
L_801831FC:
    // 0x801831FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80183204: jr          $ra
    // 0x80183208: nop

    return;
    // 0x80183208: nop

;}
RECOMP_FUNC void func_ovl8_8037C510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C510: jr          $ra
    // 0x8037C514: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    return;
    // 0x8037C514: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
;}
RECOMP_FUNC void mnPlayers1PGameAdjustCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361C8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801361CC: addiu       $t6, $t6, -0x740C
    ctx->r14 = ADD32(ctx->r14, -0X740C);
    // 0x801361D0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801361D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801361D8: addiu       $t0, $sp, 0x14
    ctx->r8 = ADD32(ctx->r29, 0X14);
    // 0x801361DC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801361E0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801361E4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801361E8: addiu       $t1, $t1, -0x7118
    ctx->r9 = ADD32(ctx->r9, -0X7118);
    // 0x801361EC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x801361F0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801361F4: lw          $t9, 0x70($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X70);
    // 0x801361F8: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x801361FC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80136200: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x80136204: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80136208: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x8013620C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80136210: beq         $t9, $zero, L_80136394
    if (ctx->r25 == 0) {
        // 0x80136214: sw          $t7, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->r15;
            goto L_80136394;
    }
    // 0x80136214: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x80136218: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8013621C: lwc1        $f2, 0x68($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X68);
    // 0x80136220: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80136224: lw          $v0, 0x74($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X74);
    // 0x80136228: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8013622C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80136230: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013623C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80136240: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136244: div.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80136248: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8013624C: nop

    // 0x80136250: bc1f        L_80136278
    if (!c1cs) {
        // 0x80136254: nop
    
            goto L_80136278;
    }
    // 0x80136254: nop

    // 0x80136258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013625C: nop

    // 0x80136260: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80136264: nop

    // 0x80136268: bc1f        L_80136278
    if (!c1cs) {
        // 0x8013626C: nop
    
            goto L_80136278;
    }
    // 0x8013626C: nop

    // 0x80136270: b           L_80136278
    // 0x80136274: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136278;
    // 0x80136274: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136278:
    // 0x80136278: beq         $v1, $zero, L_80136288
    if (ctx->r3 == 0) {
        // 0x8013627C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80136288;
    }
    // 0x8013627C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136280: b           L_80136290
    // 0x80136284: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
        goto L_80136290;
    // 0x80136284: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
L_80136288:
    // 0x80136288: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8013628C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
L_80136290:
    // 0x80136290: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80136294: lwc1        $f2, 0x6C($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x80136298: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013629C: lw          $v0, 0x74($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X74);
    // 0x801362A0: lwc1        $f12, 0x5C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801362A4: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801362A8: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801362AC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x801362B0: nop

    // 0x801362B4: bc1f        L_801362DC
    if (!c1cs) {
        // 0x801362B8: nop
    
            goto L_801362DC;
    }
    // 0x801362B8: nop

    // 0x801362BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801362C0: nop

    // 0x801362C4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801362C8: nop

    // 0x801362CC: bc1f        L_801362DC
    if (!c1cs) {
        // 0x801362D0: nop
    
            goto L_801362DC;
    }
    // 0x801362D0: nop

    // 0x801362D4: b           L_801362DC
    // 0x801362D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801362DC;
    // 0x801362D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801362DC:
    // 0x801362DC: beql        $v1, $zero, L_801362F0
    if (ctx->r3 == 0) {
        // 0x801362E0: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_801362F0;
    }
    goto skip_0;
    // 0x801362E0: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_0:
    // 0x801362E4: b           L_801362F4
    // 0x801362E8: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
        goto L_801362F4;
    // 0x801362E8: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x801362EC: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
L_801362F0:
    // 0x801362F0: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
L_801362F4:
    // 0x801362F4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x801362F8: lwc1        $f6, 0x68($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801362FC: lw          $v0, 0x74($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X74);
    // 0x80136300: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136304: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80136308: nop

    // 0x8013630C: bc1fl       L_80136334
    if (!c1cs) {
        // 0x80136310: lw          $t5, 0x28($t1)
        ctx->r13 = MEM_W(ctx->r9, 0X28);
            goto L_80136334;
    }
    goto skip_1;
    // 0x80136310: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
    skip_1:
    // 0x80136314: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x80136318: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013631C: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80136320: nop

    // 0x80136324: bc1fl       L_80136334
    if (!c1cs) {
        // 0x80136328: lw          $t5, 0x28($t1)
        ctx->r13 = MEM_W(ctx->r9, 0X28);
            goto L_80136334;
    }
    goto skip_2;
    // 0x80136328: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
    skip_2:
    // 0x8013632C: sw          $zero, 0x70($t1)
    MEM_W(0X70, ctx->r9) = 0;
    // 0x80136330: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
L_80136334:
    // 0x80136334: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80136338: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8013633C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80136340: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80136344: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136348: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8013634C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80136350: nop

    // 0x80136354: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136358: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013635C: swc1        $f10, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f10.u32l;
    // 0x80136360: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80136364: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80136368: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8013636C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80136370: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80136374: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136378: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8013637C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80136380: nop

    // 0x80136384: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80136388: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013638C: b           L_80136538
    // 0x80136390: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
        goto L_80136538;
    // 0x80136390: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
L_80136394:
    // 0x80136394: lw          $t7, 0x30($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X30);
    // 0x80136398: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8013639C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x801363A0: bne         $t7, $zero, L_80136538
    if (ctx->r15 != 0) {
        // 0x801363A4: sll         $t8, $t8, 1
        ctx->r24 = S32(ctx->r24 << 1);
            goto L_80136538;
    }
    // 0x801363A4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801363A8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x801363AC: addiu       $t9, $t9, 0x5228
    ctx->r25 = ADD32(ctx->r25, 0X5228);
    // 0x801363B0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x801363B4: lb          $a3, 0x8($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X8);
    // 0x801363B8: slti        $at, $a3, -0x8
    ctx->r1 = SIGNED(ctx->r7) < -0X8 ? 1 : 0;
    // 0x801363BC: bne         $at, $zero, L_801363CC
    if (ctx->r1 != 0) {
        // 0x801363C0: slti        $at, $a3, 0x9
        ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
            goto L_801363CC;
    }
    // 0x801363C0: slti        $at, $a3, 0x9
    ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x801363C4: bne         $at, $zero, L_801363D4
    if (ctx->r1 != 0) {
        // 0x801363C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801363D4;
    }
    // 0x801363C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801363CC:
    // 0x801363CC: b           L_801363D4
    // 0x801363D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801363D4;
    // 0x801363D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801363D4:
    // 0x801363D4: beql        $v1, $zero, L_80136478
    if (ctx->r3 == 0) {
        // 0x801363D8: lb          $a1, 0x9($a2)
        ctx->r5 = MEM_B(ctx->r6, 0X9);
            goto L_80136478;
    }
    goto skip_3;
    // 0x801363D8: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
    skip_3:
    // 0x801363DC: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x801363E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801363E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801363E8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801363EC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801363F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801363F4: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x801363F8: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801363FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136400: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80136404: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80136408: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8013640C: nop

    // 0x80136410: bc1f        L_80136438
    if (!c1cs) {
        // 0x80136414: nop
    
            goto L_80136438;
    }
    // 0x80136414: nop

    // 0x80136418: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013641C: nop

    // 0x80136420: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80136424: nop

    // 0x80136428: bc1f        L_80136438
    if (!c1cs) {
        // 0x8013642C: nop
    
            goto L_80136438;
    }
    // 0x8013642C: nop

    // 0x80136430: b           L_80136438
    // 0x80136434: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136438;
    // 0x80136434: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136438:
    // 0x80136438: beql        $v1, $zero, L_80136478
    if (ctx->r3 == 0) {
        // 0x8013643C: lb          $a1, 0x9($a2)
        ctx->r5 = MEM_B(ctx->r6, 0X9);
            goto L_80136478;
    }
    goto skip_4;
    // 0x8013643C: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
    skip_4:
    // 0x80136440: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80136444: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80136448: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013644C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80136450: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80136454: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80136458: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013645C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80136460: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80136464: nop

    // 0x80136468: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013646C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80136470: swc1        $f10, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f10.u32l;
    // 0x80136474: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
L_80136478:
    // 0x80136478: slti        $at, $a1, -0x8
    ctx->r1 = SIGNED(ctx->r5) < -0X8 ? 1 : 0;
    // 0x8013647C: bne         $at, $zero, L_8013648C
    if (ctx->r1 != 0) {
        // 0x80136480: slti        $at, $a1, 0x9
        ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
            goto L_8013648C;
    }
    // 0x80136480: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80136484: bne         $at, $zero, L_80136494
    if (ctx->r1 != 0) {
        // 0x80136488: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80136494;
    }
    // 0x80136488: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013648C:
    // 0x8013648C: b           L_80136494
    // 0x80136490: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136494;
    // 0x80136490: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136494:
    // 0x80136494: beq         $v1, $zero, L_80136538
    if (ctx->r3 == 0) {
        // 0x80136498: nop
    
            goto L_80136538;
    }
    // 0x80136498: nop

    // 0x8013649C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x801364A0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x801364A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801364A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801364AC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801364B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801364B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801364B8: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801364BC: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x801364C0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801364C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801364C8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801364CC: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x801364D0: nop

    // 0x801364D4: bc1f        L_801364FC
    if (!c1cs) {
        // 0x801364D8: nop
    
            goto L_801364FC;
    }
    // 0x801364D8: nop

    // 0x801364DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801364E0: nop

    // 0x801364E4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801364E8: nop

    // 0x801364EC: bc1f        L_801364FC
    if (!c1cs) {
        // 0x801364F0: nop
    
            goto L_801364FC;
    }
    // 0x801364F0: nop

    // 0x801364F4: b           L_801364FC
    // 0x801364F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801364FC;
    // 0x801364F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801364FC:
    // 0x801364FC: beq         $v1, $zero, L_80136538
    if (ctx->r3 == 0) {
        // 0x80136500: nop
    
            goto L_80136538;
    }
    // 0x80136500: nop

    // 0x80136504: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80136508: lw          $t7, 0x28($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X28);
    // 0x8013650C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80136510: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80136514: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80136518: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x8013651C: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136520: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80136524: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80136528: nop

    // 0x8013652C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80136530: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80136534: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_80136538:
    // 0x80136538: jr          $ra
    // 0x8013653C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013653C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonDamageCheckCaptureKeepHold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140EC0: lw          $t6, 0x7F0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7F0);
    // 0x80140EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80140EC8: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80140ECC: beq         $at, $zero, L_80140EDC
    if (ctx->r1 == 0) {
        // 0x80140ED0: nop
    
            goto L_80140EDC;
    }
    // 0x80140ED0: nop

    // 0x80140ED4: jr          $ra
    // 0x80140ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80140ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140EDC:
    // 0x80140EDC: jr          $ra
    // 0x80140EE0: nop

    return;
    // 0x80140EE0: nop

;}
RECOMP_FUNC void mvOpeningCliffMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131CB0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80131CB4: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80131CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131CBC: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80131CC0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80131CC4:
    // 0x80131CC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131CC8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131CCC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131CD0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131CD4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131CD8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131CDC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131CE0: bne         $t7, $t0, L_80131CC4
    if (ctx->r15 != ctx->r8) {
        // 0x80131CE4: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131CC4;
    }
    // 0x80131CE4: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131CE8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131CEC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80131CF0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80131CF4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131CF8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80131CFC: jal         0x800EC0EC
    // 0x80131D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80131D04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131D08: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131D0C: lw          $t2, 0x27C8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X27C8);
    // 0x80131D10: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80131D14: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80131D18: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131D1C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80131D20: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80131D24: jal         0x800D7F3C
    // 0x80131D28: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131D28: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x80131D2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D30: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131D34: sw          $v0, 0x27D4($at)
    MEM_W(0X27D4, ctx->r1) = ctx->r2;
    // 0x80131D38: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x80131D3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D40: jal         0x803905CC
    // 0x80131D44: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131D44: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80131D48: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80131D4C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131D50: jal         0x8000A0D0
    // 0x80131D54: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x80131D54: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x80131D58: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80131D5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131D60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D64: lw          $t3, 0x74($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X74);
    // 0x80131D68: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x80131D6C: lw          $t4, 0x74($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X74);
    // 0x80131D70: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x80131D74: lw          $t5, 0x74($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X74);
    // 0x80131D78: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x80131D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131D80: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131D84: jr          $ra
    // 0x80131D88: nop

    return;
    // 0x80131D88: nop

;}
RECOMP_FUNC void sc1PStageClearMakeBonusPageArrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801335A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801335A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801335AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801335B0: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801335B4: jal         0x80009968
    // 0x801335B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801335B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801335BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801335C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801335C8: sw          $v0, 0x5374($at)
    MEM_W(0X5374, ctx->r1) = ctx->r2;
    // 0x801335CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801335D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801335D4: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x801335D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801335DC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801335E0: jal         0x80009DF4
    // 0x801335E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801335E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801335E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801335EC: addiu       $a1, $a1, 0x3188
    ctx->r5 = ADD32(ctx->r5, 0X3188);
    // 0x801335F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801335F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335F8: jal         0x80008188
    // 0x801335FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801335FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133600: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133604: lw          $t7, 0x52CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X52CC);
    // 0x80133608: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013360C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133610: addiu       $t8, $t7, 0x5A
    ctx->r24 = ADD32(ctx->r15, 0X5A);
    // 0x80133614: sw          $t8, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r24;
    // 0x80133618: lw          $t9, 0x5588($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5588);
    // 0x8013361C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80133620: addiu       $t0, $t0, -0x4958
    ctx->r8 = ADD32(ctx->r8, -0X4958);
    // 0x80133624: jal         0x800CCFDC
    // 0x80133628: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133628: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x8013362C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80133630: lui         $at, 0x4379
    ctx->r1 = S32(0X4379 << 16);
    // 0x80133634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133638: lui         $at, 0x4330
    ctx->r1 = S32(0X4330 << 16);
    // 0x8013363C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133640: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80133644: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133648: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8013364C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80133650: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133654: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013365C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133660: jr          $ra
    // 0x80133664: nop

    return;
    // 0x80133664: nop

;}
RECOMP_FUNC void lbParticleResumeAllID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DE8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D3DEC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3DF0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D3DF4: lw          $v0, 0x6358($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6358);
    // 0x800D3DF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D3DFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800D3E00: beq         $v0, $zero, L_800D3E30
    if (ctx->r2 == 0) {
        // 0x800D3E04: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800D3E30;
    }
    // 0x800D3E04: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D3E08: addiu       $a1, $zero, -0x801
    ctx->r5 = ADD32(0, -0X801);
    // 0x800D3E0C: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
L_800D3E10:
    // 0x800D3E10: bnel        $v1, $t7, L_800D3E28
    if (ctx->r3 != ctx->r15) {
        // 0x800D3E14: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800D3E28;
    }
    goto skip_0;
    // 0x800D3E14: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800D3E18: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    // 0x800D3E1C: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x800D3E20: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800D3E24: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800D3E28:
    // 0x800D3E28: bnel        $v0, $zero, L_800D3E10
    if (ctx->r2 != 0) {
        // 0x800D3E2C: lhu         $t7, 0x4($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X4);
            goto L_800D3E10;
    }
    goto skip_1;
    // 0x800D3E2C: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    skip_1:
L_800D3E30:
    // 0x800D3E30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3E34: lw          $v0, 0x639C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X639C);
    // 0x800D3E38: addiu       $a1, $zero, -0x801
    ctx->r5 = ADD32(0, -0X801);
    // 0x800D3E3C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D3E40: beq         $v0, $zero, L_800D3E6C
    if (ctx->r2 == 0) {
        // 0x800D3E44: nop
    
            goto L_800D3E6C;
    }
    // 0x800D3E44: nop

    // 0x800D3E48: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
L_800D3E4C:
    // 0x800D3E4C: bnel        $v1, $t0, L_800D3E64
    if (ctx->r3 != ctx->r8) {
        // 0x800D3E50: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800D3E64;
    }
    goto skip_2;
    // 0x800D3E50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x800D3E54: lhu         $t1, 0x6($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X6);
    // 0x800D3E58: and         $t2, $t1, $a1
    ctx->r10 = ctx->r9 & ctx->r5;
    // 0x800D3E5C: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x800D3E60: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800D3E64:
    // 0x800D3E64: bnel        $v0, $zero, L_800D3E4C
    if (ctx->r2 != 0) {
        // 0x800D3E68: lhu         $t0, 0x4($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X4);
            goto L_800D3E4C;
    }
    goto skip_3;
    // 0x800D3E68: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    skip_3:
L_800D3E6C:
    // 0x800D3E6C: jr          $ra
    // 0x800D3E70: nop

    return;
    // 0x800D3E70: nop

;}
RECOMP_FUNC void mnVSResultsSetFighterPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331DC: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x801331E0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801331E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801331E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801331EC: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x801331F0: addiu       $t7, $t7, -0x6F34
    ctx->r15 = ADD32(ctx->r15, -0X6F34);
    // 0x801331F4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801331F8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801331FC: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80133200: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133204: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133208: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013320C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133210: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133214: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133218: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8013321C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133220: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80133224: addiu       $t1, $t1, -0x6F14
    ctx->r9 = ADD32(ctx->r9, -0X6F14);
    // 0x80133228: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8013322C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80133230: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80133234: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80133238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013323C: addiu       $t4, $t1, 0x30
    ctx->r12 = ADD32(ctx->r9, 0X30);
    // 0x80133240: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x80133244: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80133248: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
L_8013324C:
    // 0x8013324C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133250: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80133254: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80133258: sw          $t3, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r11;
    // 0x8013325C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80133260: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x80133264: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80133268: bne         $t1, $t4, L_8013324C
    if (ctx->r9 != ctx->r12) {
        // 0x8013326C: sw          $t3, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r11;
            goto L_8013324C;
    }
    // 0x8013326C: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x80133270: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133274: addiu       $t6, $t6, -0x6EE4
    ctx->r14 = ADD32(ctx->r14, -0X6EE4);
    // 0x80133278: addiu       $t9, $t6, 0x3C
    ctx->r25 = ADD32(ctx->r14, 0X3C);
    // 0x8013327C: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
L_80133280:
    // 0x80133280: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133284: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133288: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8013328C: sw          $t8, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r24;
    // 0x80133290: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133294: sw          $t7, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r15;
    // 0x80133298: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013329C: bne         $t6, $t9, L_80133280
    if (ctx->r14 != ctx->r25) {
        // 0x801332A0: sw          $t8, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r24;
            goto L_80133280;
    }
    // 0x801332A0: sw          $t8, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r24;
    // 0x801332A4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801332A8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801332AC: addiu       $t1, $t1, -0x6EA4
    ctx->r9 = ADD32(ctx->r9, -0X6EA4);
    // 0x801332B0: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x801332B4: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x801332B8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801332BC: addiu       $t4, $sp, 0x28
    ctx->r12 = ADD32(ctx->r29, 0X28);
    // 0x801332C0: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x801332C4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x801332C8: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x801332CC: lw          $t0, 0xC($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XC);
    // 0x801332D0: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x801332D4: sw          $t0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r8;
    // 0x801332D8: lw          $t0, 0x14($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X14);
    // 0x801332DC: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801332E0: sw          $t0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r8;
    // 0x801332E4: sw          $t2, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r10;
    // 0x801332E8: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x801332EC: lw          $t0, 0x1C($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X1C);
    // 0x801332F0: sw          $t2, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r10;
    // 0x801332F4: sw          $t0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r8;
    // 0x801332F8: jal         0x8013205C
    // 0x801332FC: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_0;
    // 0x801332FC: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    after_0:
    // 0x80133300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133304: beq         $v0, $at, L_80133328
    if (ctx->r2 == ctx->r1) {
        // 0x80133308: lw          $a1, 0xDC($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XDC);
            goto L_80133328;
    }
    // 0x80133308: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    // 0x8013330C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133310: beq         $v0, $at, L_80133354
    if (ctx->r2 == ctx->r1) {
        // 0x80133314: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80133354;
    }
    // 0x80133314: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133318: beq         $v0, $at, L_80133380
    if (ctx->r2 == ctx->r1) {
        // 0x8013331C: nop
    
            goto L_80133380;
    }
    // 0x8013331C: nop

    // 0x80133320: b           L_80133380
    // 0x80133324: nop

        goto L_80133380;
    // 0x80133324: nop

L_80133328:
    // 0x80133328: jal         0x801321AC
    // 0x8013332C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetPlayerDistanceID(rdram, ctx);
        goto after_1;
    // 0x8013332C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80133330: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80133334: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80133338: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8013333C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80133340: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x80133344: addu        $t7, $sp, $t5
    ctx->r15 = ADD32(ctx->r29, ctx->r13);
    // 0x80133348: lwc1        $f4, 0xB8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XB8);
    // 0x8013334C: b           L_801333A8
    // 0x80133350: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
        goto L_801333A8;
    // 0x80133350: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
L_80133354:
    // 0x80133354: jal         0x801321AC
    // 0x80133358: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetPlayerDistanceID(rdram, ctx);
        goto after_2;
    // 0x80133358: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8013335C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80133360: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80133364: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80133368: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8013336C: addu        $t2, $t4, $t0
    ctx->r10 = ADD32(ctx->r12, ctx->r8);
    // 0x80133370: addu        $t9, $sp, $t2
    ctx->r25 = ADD32(ctx->r29, ctx->r10);
    // 0x80133374: lwc1        $f6, 0x88($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X88);
    // 0x80133378: b           L_801333A8
    // 0x8013337C: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
        goto L_801333A8;
    // 0x8013337C: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
L_80133380:
    // 0x80133380: jal         0x801321AC
    // 0x80133384: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetPlayerDistanceID(rdram, ctx);
        goto after_3;
    // 0x80133384: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80133388: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8013338C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80133390: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80133394: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80133398: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8013339C: addu        $t1, $sp, $t8
    ctx->r9 = ADD32(ctx->r29, ctx->r24);
    // 0x801333A0: lwc1        $f8, 0x48($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X48);
    // 0x801333A4: swc1        $f8, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f8.u32l;
L_801333A8:
    // 0x801333A8: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x801333AC: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x801333B0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x801333B4: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x801333B8: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
    // 0x801333BC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801333C0: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
    // 0x801333C4: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x801333C8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801333CC: swc1        $f16, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f16.u32l;
    // 0x801333D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801333D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801333D8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x801333DC: jr          $ra
    // 0x801333E0: nop

    return;
    // 0x801333E0: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B2C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8016B2CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016B2D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8016B2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B2D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016B2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016B2E0: addiu       $a1, $a1, -0x6E30
    ctx->r5 = ADD32(ctx->r5, -0X6E30);
    // 0x8016B2E4: jal         0x801655C8
    // 0x8016B2E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016B2E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8016B2EC: bne         $v0, $zero, L_8016B2FC
    if (ctx->r2 != 0) {
        // 0x8016B2F0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8016B2FC;
    }
    // 0x8016B2F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8016B2F4: b           L_8016B388
    // 0x8016B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016B388;
    // 0x8016B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B2FC:
    // 0x8016B2FC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8016B300: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B304: lwc1        $f0, -0x34F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X34F0);
    // 0x8016B308: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8016B30C: addiu       $t6, $t6, -0x4D60
    ctx->r14 = ADD32(ctx->r14, -0X4D60);
    // 0x8016B310: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8016B314: sw          $t6, 0x298($v1)
    MEM_W(0X298, ctx->r3) = ctx->r14;
    // 0x8016B318: sw          $t7, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r15;
    // 0x8016B31C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016B320: lbu         $t3, 0x26C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X26C);
    // 0x8016B324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8016B328: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8016B32C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016B330: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8016B334: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x8016B338: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8016B33C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x8016B340: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x8016B344: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8016B348: sw          $zero, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = 0;
    // 0x8016B34C: swc1        $f0, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->f0.u32l;
    // 0x8016B350: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x8016B354: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8016B358: sb          $t4, 0x26C($v1)
    MEM_B(0X26C, ctx->r3) = ctx->r12;
    // 0x8016B35C: sw          $zero, 0x2A8($v1)
    MEM_W(0X2A8, ctx->r3) = 0;
    // 0x8016B360: sw          $t1, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r9;
    // 0x8016B364: sw          $zero, 0x2B4($v0)
    MEM_W(0X2B4, ctx->r2) = 0;
    // 0x8016B368: sw          $zero, 0x2B0($v0)
    MEM_W(0X2B0, ctx->r2) = 0;
    // 0x8016B36C: sw          $zero, 0x2AC($v0)
    MEM_W(0X2AC, ctx->r2) = 0;
    // 0x8016B370: sw          $zero, 0x2A8($v0)
    MEM_W(0X2A8, ctx->r2) = 0;
    // 0x8016B374: lwc1        $f4, 0x2A0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2A0);
    // 0x8016B378: lw          $t6, 0x74($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X74);
    // 0x8016B37C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8016B380: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8016B384: swc1        $f6, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f6.u32l;
L_8016B388:
    // 0x8016B388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B38C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B390: jr          $ra
    // 0x8016B394: nop

    return;
    // 0x8016B394: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801575C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801575CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801575D0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801575D4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801575D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801575DC: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x801575E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801575E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801575E8: jal         0x800E6F24
    // 0x801575EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801575EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801575F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801575F4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801575F8: addiu       $t8, $t8, 0x6E98
    ctx->r24 = ADD32(ctx->r24, 0X6E98);
    // 0x801575FC: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x80157600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157604: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157608: jr          $ra
    // 0x8015760C: nop

    return;
    // 0x8015760C: nop

;}
RECOMP_FUNC void func_80009C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009C94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009C98: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80009C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009CA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009CA4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80009CA8: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x80009CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009CB0: jal         0x80009B48
    // 0x80009CB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMoveGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009CB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80009CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009CC0: jr          $ra
    // 0x80009CC4: nop

    return;
    // 0x80009CC4: nop

;}
RECOMP_FUNC void mvOpeningYoshiMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D97C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D984: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D988: jal         0x80009968
    // 0x8018D98C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D98C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D990: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D994: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D998: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D99C: addiu       $a1, $a1, -0x278C
    ctx->r5 = ADD32(ctx->r5, -0X278C);
    // 0x8018D9A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D9A4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D9A8: jal         0x80009DF4
    // 0x8018D9AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D9AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D9B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D9B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D9B8: jr          $ra
    // 0x8018D9BC: nop

    return;
    // 0x8018D9BC: nop

;}
RECOMP_FUNC void ifCommonBattlePauseMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113EB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80113EB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80113EBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80113EC0: addiu       $a0, $zero, 0x3FB
    ctx->r4 = ADD32(0, 0X3FB);
    // 0x80113EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80113EC8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80113ECC: jal         0x80009968
    // 0x80113ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80113ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80113ED4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80113ED8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80113EDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80113EE0: addiu       $a1, $a1, 0x3AA8
    ctx->r5 = ADD32(ctx->r5, 0X3AA8);
    // 0x80113EE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80113EE8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80113EEC: jal         0x80009DF4
    // 0x80113EF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80113EF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80113EF4: addiu       $a0, $zero, 0x3FB
    ctx->r4 = ADD32(0, 0X3FB);
    // 0x80113EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80113EFC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80113F00: jal         0x80009968
    // 0x80113F04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80113F04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80113F08: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80113F0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80113F10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80113F14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80113F18: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80113F1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80113F20: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80113F24: jal         0x80009DF4
    // 0x80113F28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80113F28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80113F2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80113F30: jal         0x80113CF8
    // 0x80113F34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    ifCommonBattlePausePlayerNumMakeSObj(rdram, ctx);
        goto after_4;
    // 0x80113F34: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80113F38: jal         0x80113E04
    // 0x80113F3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ifCommonBattlePauseMakeSObjsAll(rdram, ctx);
        goto after_5;
    // 0x80113F3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80113F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80113F44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80113F48: jr          $ra
    // 0x80113F4C: nop

    return;
    // 0x80113F4C: nop

;}
RECOMP_FUNC void func_8002AC48_2B848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AC48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002AC4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AC50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AC54: lw          $t1, 0x1C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1C);
    // 0x8002AC58: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002AC5C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002AC60: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8002AC64: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8002AC68: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x8002AC6C: beq         $at, $zero, L_8002AC78
    if (ctx->r1 == 0) {
        // 0x8002AC70: addu        $v1, $v0, $t1
        ctx->r3 = ADD32(ctx->r2, ctx->r9);
            goto L_8002AC78;
    }
    // 0x8002AC70: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x8002AC74: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
L_8002AC78:
    // 0x8002AC78: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x8002AC7C: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x8002AC80: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8002AC84: beq         $at, $zero, L_8002AD44
    if (ctx->r1 == 0) {
        // 0x8002AC88: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_8002AD44;
    }
    // 0x8002AC88: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8002AC8C: subu        $t1, $v1, $a1
    ctx->r9 = SUB32(ctx->r3, ctx->r5);
    // 0x8002AC90: sra         $t1, $t1, 1
    ctx->r9 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8002AC94: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8002AC98: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8002AC9C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8002ACA0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8002ACA4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002ACA8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002ACAC: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8002ACB0: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x8002ACB4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002ACB8: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8002ACBC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8002ACC0: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8002ACC4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8002ACC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8002ACCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002ACD0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8002ACD4: jal         0x80032150
    // 0x8002ACD8: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8002ACD8: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    after_0:
    // 0x8002ACDC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8002ACE0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8002ACE4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002ACE8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002ACEC: subu        $t5, $a2, $v1
    ctx->r13 = SUB32(ctx->r6, ctx->r3);
    // 0x8002ACF0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8002ACF4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002ACF8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8002ACFC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002AD00: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8002AD04: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8002AD08: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002AD0C: addu        $t4, $t2, $t1
    ctx->r12 = ADD32(ctx->r10, ctx->r9);
    // 0x8002AD10: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8002AD14: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x8002AD18: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8002AD1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002AD20: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8002AD24: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002AD28: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8002AD2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002AD30: jal         0x80032150
    // 0x8002AD34: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8002AD34: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x8002AD38: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AD3C: b           L_8002AD7C
    // 0x8002AD40: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
        goto L_8002AD7C;
    // 0x8002AD40: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8002AD44:
    // 0x8002AD44: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8002AD48: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002AD4C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8002AD50: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002AD54: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8002AD58: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8002AD5C: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x8002AD60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002AD64: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8002AD68: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002AD6C: jal         0x80032150
    // 0x8002AD70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8002AD70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8002AD74: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8002AD78: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002AD7C:
    // 0x8002AD7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AD80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002AD84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002AD88: jr          $ra
    // 0x8002AD8C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002AD8C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void itHitokageMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018405C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80184060: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80184064: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80184068: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8018406C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80184070: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80184074: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80184078: addiu       $a1, $a1, -0x4B60
    ctx->r5 = ADD32(ctx->r5, -0X4B60);
    // 0x8018407C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80184080: jal         0x8016E174
    // 0x80184084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80184084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80184088: beq         $v0, $zero, L_80184148
    if (ctx->r2 == 0) {
        // 0x8018408C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80184148;
    }
    // 0x8018408C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80184090: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80184094: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80184098: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018409C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801840A0: sh          $zero, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = 0;
    // 0x801840A4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801840A8: lbu         $t3, 0x2D3($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2D3);
    // 0x801840AC: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x801840B0: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x801840B4: sw          $t1, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r9;
    // 0x801840B8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801840BC: sw          $t9, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r25;
    // 0x801840C0: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x801840C4: sb          $t4, 0x2D3($v1)
    MEM_B(0X2D3, ctx->r3) = ctx->r12;
    // 0x801840C8: sw          $t1, 0x358($v1)
    MEM_W(0X358, ctx->r3) = ctx->r9;
    // 0x801840CC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801840D0: jal         0x80018994
    // 0x801840D4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x801840D4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x801840D8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801840DC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801840E0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801840E4: addiu       $t0, $t0, -0x14A0
    ctx->r8 = ADD32(ctx->r8, -0X14A0);
    // 0x801840E8: sh          $v0, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r2;
    // 0x801840EC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801840F0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x801840F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801840F8: beq         $a0, $a2, L_80184108
    if (ctx->r4 == ctx->r6) {
        // 0x801840FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80184108;
    }
    // 0x801840FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80184100: and         $t5, $a1, $a0
    ctx->r13 = ctx->r5 & ctx->r4;
    // 0x80184104: beq         $t5, $zero, L_8018411C
    if (ctx->r13 == 0) {
        // 0x80184108: addiu       $t7, $a2, 0x1
        ctx->r15 = ADD32(ctx->r6, 0X1);
            goto L_8018411C;
    }
L_80184108:
    // 0x80184108: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x8018410C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80184110: sh          $t7, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r15;
    // 0x80184114: sh          $t8, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r24;
    // 0x80184118: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
L_8018411C:
    // 0x8018411C: bne         $a1, $at, L_80184138
    if (ctx->r5 != ctx->r1) {
        // 0x80184120: addiu       $a0, $zero, 0x229
        ctx->r4 = ADD32(0, 0X229);
            goto L_80184138;
    }
    // 0x80184120: addiu       $a0, $zero, 0x229
    ctx->r4 = ADD32(0, 0X229);
    // 0x80184124: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80184128: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018412C: lw          $t2, 0x80($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X80);
    // 0x80184130: sh          $t9, 0x80($t2)
    MEM_H(0X80, ctx->r10) = ctx->r25;
    // 0x80184134: lhu         $a1, 0x35C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X35C);
L_80184138:
    // 0x80184138: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x8018413C: jal         0x800269C0
    // 0x80184140: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80184140: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80184144: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_80184148:
    // 0x80184148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018414C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80184150: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80184154: jr          $ra
    // 0x80184158: nop

    return;
    // 0x80184158: nop

;}
RECOMP_FUNC void mpProcessSetLastWallCollideStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D95A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D95A8: swc1        $f12, 0xDFC($at)
    MEM_W(0XDFC, ctx->r1) = ctx->f12.u32l;
    // 0x800D95AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D95B0: sw          $a1, 0xE00($at)
    MEM_W(0XE00, ctx->r1) = ctx->r5;
    // 0x800D95B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D95B8: sw          $a2, 0xE04($at)
    MEM_W(0XE04, ctx->r1) = ctx->r6;
    // 0x800D95BC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800D95C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D95C4: addiu       $t6, $t6, 0xE08
    ctx->r14 = ADD32(ctx->r14, 0XE08);
    // 0x800D95C8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D95CC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800D95D0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800D95D4: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800D95D8: jr          $ra
    // 0x800D95DC: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    return;
    // 0x800D95DC: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void func_ovl8_80380048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380048: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8038004C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80380050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380054: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80380058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8038005C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80380060: bne         $a0, $zero, L_80380078
    if (ctx->r4 != 0) {
        // 0x80380064: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80380078;
    }
    // 0x80380064: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80380068: jal         0x803717A0
    // 0x8038006C: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8038006C: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_0:
    // 0x80380070: beq         $v0, $zero, L_80380108
    if (ctx->r2 == 0) {
        // 0x80380074: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80380108;
    }
    // 0x80380074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80380078:
    // 0x80380078: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8038007C: addiu       $a0, $s0, 0xC8
    ctx->r4 = ADD32(ctx->r16, 0XC8);
    // 0x80380080: addiu       $a1, $s0, 0x124
    ctx->r5 = ADD32(ctx->r16, 0X124);
    // 0x80380084: bnel        $t6, $zero, L_803800A8
    if (ctx->r14 != 0) {
        // 0x80380088: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_803800A8;
    }
    goto skip_0;
    // 0x80380088: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x8038008C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80380090: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80380094: jal         0x803717E0
    // 0x80380098: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80380098: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x8038009C: jal         0x8037C2D0
    // 0x803800A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803800A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x803800A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_803800A8:
    // 0x803800A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x803800AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x803800B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x803800B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803800B8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803800BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x803800C0: jal         0x80376530
    // 0x803800C4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_ovl8_80376530(rdram, ctx);
        goto after_3;
    // 0x803800C4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x803800C8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803800CC: addiu       $t9, $t9, -0x4B90
    ctx->r25 = ADD32(ctx->r25, -0X4B90);
    // 0x803800D0: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x803800D4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x803800D8: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803800DC: addiu       $t0, $t0, -0x4AC0
    ctx->r8 = ADD32(ctx->r8, -0X4AC0);
    // 0x803800E0: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x803800E4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x803800E8: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803800EC: addiu       $t2, $t2, -0x4968
    ctx->r10 = ADD32(ctx->r10, -0X4968);
    // 0x803800F0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x803800F4: addiu       $t4, $t4, -0x4940
    ctx->r12 = ADD32(ctx->r12, -0X4940);
    // 0x803800F8: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x803800FC: sw          $t4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r12;
    // 0x80380100: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80380104: sw          $t5, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r13;
L_80380108:
    // 0x80380108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038010C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80380114: jr          $ra
    // 0x80380118: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80380118: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSResultsGetPoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80135DBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80135DC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80135DC4: jr          $ra
    // 0x80135DC8: lw          $v0, -0x6460($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6460);
    return;
    // 0x80135DC8: lw          $v0, -0x6460($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6460);
;}
RECOMP_FUNC void itHarisenCommonSetScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175140: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80175144: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80175148: swc1        $f12, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f12.u32l;
    // 0x8017514C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80175150: swc1        $f12, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f12.u32l;
    // 0x80175154: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80175158: jr          $ra
    // 0x8017515C: swc1        $f12, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f12.u32l;
    return;
    // 0x8017515C: swc1        $f12, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f12.u32l;
;}
RECOMP_FUNC void mnPlayers1PTrainingGetFighterKindCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332DC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801332E0: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x801332E4: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x801332E8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801332EC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801332F0: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x801332F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801332F8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801332FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80133300: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80133304: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x80133308: bne         $a0, $t9, L_80133314
    if (ctx->r4 != ctx->r25) {
        // 0x8013330C: nop
    
            goto L_80133314;
    }
    // 0x8013330C: nop

    // 0x80133310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133314:
    // 0x80133314: lw          $t0, -0x7768($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7768);
    // 0x80133318: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013331C: mflo        $t1
    ctx->r9 = lo;
    // 0x80133320: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80133324: lw          $t3, 0x48($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X48);
    // 0x80133328: bne         $a0, $t3, L_80133334
    if (ctx->r4 != ctx->r11) {
        // 0x8013332C: nop
    
            goto L_80133334;
    }
    // 0x8013332C: nop

    // 0x80133330: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80133334:
    // 0x80133334: beq         $v0, $zero, L_80133348
    if (ctx->r2 == 0) {
        // 0x80133338: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80133348;
    }
    // 0x80133338: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013333C: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80133340: jr          $ra
    // 0x80133344: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80133344: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80133348:
    // 0x80133348: jr          $ra
    // 0x8013334C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013334C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void syControllerSetStatusDelay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000439C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800043A0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800043A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800043A8: jal         0x80004284
    // 0x800043AC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syControllerDispatchEvent(rdram, ctx);
        goto after_0;
    // 0x800043AC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800043B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800043B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800043B8: jr          $ra
    // 0x800043BC: nop

    return;
    // 0x800043BC: nop

;}
RECOMP_FUNC void scAutoDemoFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DFD0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DFD4: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018DFD8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018DFDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DFE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018DFE4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018DFE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018DFEC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018DFF0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018DFF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018DFF8: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018DFFC: jal         0x800FCB70
    // 0x8018E000: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E000: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E00C: jr          $ra
    // 0x8018E010: nop

    return;
    // 0x8018E010: nop

;}
RECOMP_FUNC void ftCommonAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DBE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013DBE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013DBE8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013DBEC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013DBF0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013DBF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013DBF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013DBFC: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8013DC00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013DC04: bne         $v1, $t6, L_8013DC14
    if (ctx->r3 != ctx->r14) {
        // 0x8013DC08: nop
    
            goto L_8013DC14;
    }
    // 0x8013DC08: nop

    // 0x8013DC0C: b           L_8013DC14
    // 0x8013DC10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013DC14;
    // 0x8013DC10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013DC14:
    // 0x8013DC14: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8013DC18: addiu       $a0, $s0, 0x854
    ctx->r4 = ADD32(ctx->r16, 0X854);
    // 0x8013DC1C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8013DC20: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8013DC24: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8013DC28: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8013DC2C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8013DC30: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013DC34: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8013DC38: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8013DC3C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8013DC40: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8013DC44: lw          $t1, 0xEC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XEC);
    // 0x8013DC48: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8013DC4C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8013DC50: sw          $zero, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = 0;
    // 0x8013DC54: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x8013DC58: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8013DC5C: sw          $t0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r8;
    // 0x8013DC60: sw          $t1, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r9;
    // 0x8013DC64: lw          $t5, -0x7B60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7B60);
    // 0x8013DC68: sltiu       $at, $a1, 0x1B
    ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
    // 0x8013DC6C: beq         $at, $zero, L_8013DD68
    if (ctx->r1 == 0) {
        // 0x8013DC70: sw          $t5, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r13;
            goto L_8013DD68;
    }
    // 0x8013DC70: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8013DC74: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013DC78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DC7C: addu        $at, $at, $t6
    gpr jr_addend_8013DC84 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013DC80: lw          $t6, -0x3F9C($at)
    ctx->r14 = ADD32(ctx->r1, -0X3F9C);
    // 0x8013DC84: jr          $t6
    // 0x8013DC88: nop

    switch (jr_addend_8013DC84 >> 2) {
        case 0: goto L_8013DC8C; break;
        case 1: goto L_8013DC9C; break;
        case 2: goto L_8013DCAC; break;
        case 3: goto L_8013DCBC; break;
        case 4: goto L_8013DC8C; break;
        case 5: goto L_8013DCCC; break;
        case 6: goto L_8013DCE4; break;
        case 7: goto L_8013DD14; break;
        case 8: goto L_8013DCF4; break;
        case 9: goto L_8013DD04; break;
        case 10: goto L_8013DD04; break;
        case 11: goto L_8013DD68; break;
        case 12: goto L_8013DD3C; break;
        case 13: goto L_8013DC8C; break;
        case 14: goto L_8013DD68; break;
        case 15: goto L_8013DD68; break;
        case 16: goto L_8013DD68; break;
        case 17: goto L_8013DD68; break;
        case 18: goto L_8013DD68; break;
        case 19: goto L_8013DD68; break;
        case 20: goto L_8013DD68; break;
        case 21: goto L_8013DD68; break;
        case 22: goto L_8013DD68; break;
        case 23: goto L_8013DD68; break;
        case 24: goto L_8013DD68; break;
        case 25: goto L_8013DD68; break;
        case 26: goto L_8013DCAC; break;
        default: switch_error(__func__, 0x8013DC84, 0x8018C064);
    }
    // 0x8013DC88: nop

L_8013DC8C:
    // 0x8013DC8C: jal         0x801036EC
    // 0x8013DC90: nop

    efManagerMarioEntryDokanMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8013DC90: nop

    after_0:
    // 0x8013DC94: b           L_8013DD68
    // 0x8013DC98: nop

        goto L_8013DD68;
    // 0x8013DC98: nop

L_8013DC9C:
    // 0x8013DC9C: jal         0x801037EC
    // 0x8013DCA0: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    efManagerFoxEntryArwingMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8013DCA0: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    after_1:
    // 0x8013DCA4: b           L_8013DD68
    // 0x8013DCA8: nop

        goto L_8013DD68;
    // 0x8013DCA8: nop

L_8013DCAC:
    // 0x8013DCAC: jal         0x80103418
    // 0x8013DCB0: nop

    efManagerDonkeyEntryTaruMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8013DCB0: nop

    after_2:
    // 0x8013DCB4: b           L_8013DD68
    // 0x8013DCB8: nop

        goto L_8013DD68;
    // 0x8013DCB8: nop

L_8013DCBC:
    // 0x8013DCBC: jal         0x80103474
    // 0x8013DCC0: nop

    efManagerSamusEntryPointMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8013DCC0: nop

    after_3:
    // 0x8013DCC4: b           L_8013DD68
    // 0x8013DCC8: nop

        goto L_8013DD68;
    // 0x8013DCC8: nop

L_8013DCCC:
    // 0x8013DCCC: jal         0x80102AE4
    // 0x8013DCD0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    efManagerLinkEntryWaveMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8013DCD0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_4:
    // 0x8013DCD4: jal         0x80102B40
    // 0x8013DCD8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    efManagerLinkEntryBeamMakeEffect(rdram, ctx);
        goto after_5;
    // 0x8013DCD8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8013DCDC: b           L_8013DD68
    // 0x8013DCE0: nop

        goto L_8013DD68;
    // 0x8013DCE0: nop

L_8013DCE4:
    // 0x8013DCE4: jal         0x80102F34
    // 0x8013DCE8: nop

    efManagerYoshiEntryEggMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8013DCE8: nop

    after_6:
    // 0x8013DCEC: b           L_8013DD68
    // 0x8013DCF0: nop

        goto L_8013DD68;
    // 0x8013DCF0: nop

L_8013DCF4:
    // 0x8013DCF4: jal         0x80102B9C
    // 0x8013DCF8: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    efManagerKirbyEntryStarMakeEffect(rdram, ctx);
        goto after_7;
    // 0x8013DCF8: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    after_7:
    // 0x8013DCFC: b           L_8013DD68
    // 0x8013DD00: nop

        goto L_8013DD68;
    // 0x8013DD00: nop

L_8013DD04:
    // 0x8013DD04: jal         0x80102D14
    // 0x8013DD08: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    efManagerMBallThrownMakeEffect(rdram, ctx);
        goto after_8;
    // 0x8013DD08: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    after_8:
    // 0x8013DD0C: b           L_8013DD68
    // 0x8013DD10: nop

        goto L_8013DD68;
    // 0x8013DD10: nop

L_8013DD14:
    // 0x8013DD14: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    // 0x8013DD18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013DD1C: bne         $a1, $at, L_8013DD2C
    if (ctx->r5 != ctx->r1) {
        // 0x8013DD20: nop
    
            goto L_8013DD2C;
    }
    // 0x8013DD20: nop

    // 0x8013DD24: sw          $v1, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r3;
    // 0x8013DD28: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
L_8013DD2C:
    // 0x8013DD2C: jal         0x8010356C
    // 0x8013DD30: nop

    efManagerCaptainEntryCarMakeEffect(rdram, ctx);
        goto after_9;
    // 0x8013DD30: nop

    after_9:
    // 0x8013DD34: b           L_8013DD68
    // 0x8013DD38: nop

        goto L_8013DD68;
    // 0x8013DD38: nop

L_8013DD3C:
    // 0x8013DD3C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8013DD40: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x8013DD44: beql        $v0, $zero, L_8013DD64
    if (ctx->r2 == 0) {
        // 0x8013DD48: lw          $t7, 0xADC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XADC);
            goto L_8013DD64;
    }
    goto skip_0;
    // 0x8013DD48: lw          $t7, 0xADC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XADC);
    skip_0:
L_8013DD4C:
    // 0x8013DD4C: bnel        $v0, $s1, L_8013DD64
    if (ctx->r2 != ctx->r17) {
        // 0x8013DD50: lw          $t7, 0xADC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XADC);
            goto L_8013DD64;
    }
    goto skip_1;
    // 0x8013DD50: lw          $t7, 0xADC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XADC);
    skip_1:
    // 0x8013DD54: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8013DD58: bne         $v0, $zero, L_8013DD4C
    if (ctx->r2 != 0) {
        // 0x8013DD5C: nop
    
            goto L_8013DD4C;
    }
    // 0x8013DD5C: nop

    // 0x8013DD60: lw          $t7, 0xADC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XADC);
L_8013DD64:
    // 0x8013DD64: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_8013DD68:
    // 0x8013DD68: jal         0x800DEEC8
    // 0x8013DD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_10;
    // 0x8013DD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8013DD70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013DD74: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8013DD78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013DD7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013DD80: jal         0x800E6F24
    // 0x8013DD84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_11;
    // 0x8013DD84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x8013DD88: jal         0x8013DBAC
    // 0x8013DD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonAppearInitStatusVars(rdram, ctx);
        goto after_12;
    // 0x8013DD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8013DD90: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8013DD94: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x8013DD98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013DD9C: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
    // 0x8013DDA0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8013DDA4: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8013DDA8: bne         $t9, $at, L_8013DDCC
    if (ctx->r25 != ctx->r1) {
        // 0x8013DDAC: sw          $zero, 0x17C($s0)
        MEM_W(0X17C, ctx->r16) = 0;
            goto L_8013DDCC;
    }
    // 0x8013DDAC: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x8013DDB0: lw          $t0, 0xB1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB1C);
    // 0x8013DDB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013DDB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013DDBC: bnel        $t0, $at, L_8013DDD0
    if (ctx->r8 != ctx->r1) {
        // 0x8013DDC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8013DDD0;
    }
    goto skip_2;
    // 0x8013DDC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8013DDC4: jal         0x800E827C
    // 0x8013DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamMoveDLLink(rdram, ctx);
        goto after_13;
    // 0x8013DDC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_8013DDCC:
    // 0x8013DDCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013DDD0:
    // 0x8013DDD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DDD4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013DDD8: jr          $ra
    // 0x8013DDDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8013DDDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mvOpeningMarioMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DBFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC00: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC08: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC0C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC10: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC14: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC20: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC28: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC2C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC30: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC34: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC38: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC3C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC48: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC4C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC50: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC58: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC5C: jal         0x8000B93C
    // 0x8018DC60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC64: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DC68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DC6C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC70: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC74: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC84: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DC88: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC8C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DC90: jal         0x80007080
    // 0x8018DC94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC98: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DC9C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCA0: lwc1        $f6, -0x1E0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E0C);
    // 0x8018DCA4: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DCA8: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DCAC: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DCB0: lw          $t4, -0x1BDC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1BDC);
    // 0x8018DCB4: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x8018DCB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCBC: jal         0x8000FA3C
    // 0x8018DCC0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCC0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCC4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCC8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCCC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCD4: jal         0x80008188
    // 0x8018DCD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DCD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DCDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DCE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DCE4: jr          $ra
    // 0x8018DCE8: nop

    return;
    // 0x8018DCE8: nop

;}
RECOMP_FUNC void itEggExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018192C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181930: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181934: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80181938: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018193C: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80181940: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80181944: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80181948: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8018194C: bne         $t8, $at, L_80181968
    if (ctx->r24 != ctx->r1) {
        // 0x80181950: sh          $t7, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r15;
            goto L_80181968;
    }
    // 0x80181950: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80181954: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80181958: jal         0x801041A0
    // 0x8018195C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8018195C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80181960: b           L_80181988
    // 0x80181964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80181988;
    // 0x80181964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80181968:
    // 0x80181968: lw          $t9, -0x4F8C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4F8C);
    // 0x8018196C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80181970: addiu       $t1, $t1, 0xB14
    ctx->r9 = ADD32(ctx->r9, 0XB14);
    // 0x80181974: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80181978: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8018197C: jal         0x80173180
    // 0x80181980: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_1;
    // 0x80181980: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x80181984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80181988:
    // 0x80181988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018198C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181990: jr          $ra
    // 0x80181994: nop

    return;
    // 0x80181994: nop

;}
RECOMP_FUNC void ftCommonDamageGetKnockbackAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801409BC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801409C0: addiu       $at, $zero, 0x169
    ctx->r1 = ADD32(0, 0X169);
    // 0x801409C4: beql        $a0, $at, L_801409F8
    if (ctx->r4 == ctx->r1) {
        // 0x801409C8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801409F8;
    }
    goto skip_0;
    // 0x801409C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801409CC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801409D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801409D4: lwc1        $f8, -0x3F1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3F1C);
    // 0x801409D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801409DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801409E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801409E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801409E8: div.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801409EC: jr          $ra
    // 0x801409F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x801409F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801409F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801409F8:
    // 0x801409F8: bne         $a1, $at, L_80140A0C
    if (ctx->r5 != ctx->r1) {
        // 0x801409FC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80140A0C;
    }
    // 0x801409FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140A00: lwc1        $f2, -0x3F18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3F18);
    // 0x80140A04: jr          $ra
    // 0x80140A08: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80140A08: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80140A0C:
    // 0x80140A0C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80140A10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80140A14: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140A18: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80140A1C: nop

    // 0x80140A20: bc1f        L_80140A34
    if (!c1cs) {
        // 0x80140A24: nop
    
            goto L_80140A34;
    }
    // 0x80140A24: nop

    // 0x80140A28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80140A2C: jr          $ra
    // 0x80140A30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80140A30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80140A34:
    // 0x80140A34: lwc1        $f16, -0x3F14($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3F14);
    // 0x80140A38: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80140A3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140A40: lwc1        $f6, -0x3F10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F10);
    // 0x80140A44: lui         $at, 0x422A
    ctx->r1 = S32(0X422A << 16);
    // 0x80140A48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80140A4C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80140A50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80140A54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80140A58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140A5C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80140A60: lwc1        $f8, -0x3F0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3F0C);
    // 0x80140A64: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80140A68: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80140A6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80140A70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80140A74: div.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80140A78: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80140A7C: nop

    // 0x80140A80: bc1f        L_80140A8C
    if (!c1cs) {
        // 0x80140A84: nop
    
            goto L_80140A8C;
    }
    // 0x80140A84: nop

    // 0x80140A88: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_80140A8C:
    // 0x80140A8C: jr          $ra
    // 0x80140A90: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80140A90: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void grWallpaperResumePerspUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104CC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104CC8: jr          $ra
    // 0x80104CCC: sb          $zero, 0x13D0($at)
    MEM_B(0X13D0, ctx->r1) = 0;
    return;
    // 0x80104CCC: sb          $zero, 0x13D0($at)
    MEM_B(0X13D0, ctx->r1) = 0;
;}
RECOMP_FUNC void ftMainClearGroundObstacle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1D9C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1DA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1DA4: addiu       $v0, $v0, 0x1190
    ctx->r2 = ADD32(ctx->r2, 0X1190);
    // 0x800E1DA8: addiu       $v1, $v1, 0x1180
    ctx->r3 = ADD32(ctx->r3, 0X1180);
    // 0x800E1DAC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800E1DB0:
    // 0x800E1DB0: bnel        $a0, $t6, L_800E1DD8
    if (ctx->r4 != ctx->r14) {
        // 0x800E1DB4: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800E1DD8;
    }
    goto skip_0;
    // 0x800E1DB4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_0:
    // 0x800E1DB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1DBC: addiu       $v0, $v0, 0x1198
    ctx->r2 = ADD32(ctx->r2, 0X1198);
    // 0x800E1DC0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800E1DC4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800E1DC8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E1DCC: jr          $ra
    // 0x800E1DD0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800E1DD0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800E1DD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800E1DD8:
    // 0x800E1DD8: bnel        $v1, $v0, L_800E1DB0
    if (ctx->r3 != ctx->r2) {
        // 0x800E1DDC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800E1DB0;
    }
    goto skip_1;
    // 0x800E1DDC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800E1DE0: jr          $ra
    // 0x800E1DE4: nop

    return;
    // 0x800E1DE4: nop

;}
RECOMP_FUNC void syMatrixScaF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B6EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001B6F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B6F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B6F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B6FC: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8001B700: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
    // 0x8001B704: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001B708: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B70C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B710: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8001B714: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8001B718: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001B71C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B720: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001B724: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x8001B728: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_8001B72C:
    // 0x8001B72C: beq         $v0, $zero, L_8001B73C
    if (ctx->r2 == 0) {
        // 0x8001B730: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_8001B73C;
    }
    // 0x8001B730: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8001B734: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8001B738: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
L_8001B73C:
    // 0x8001B73C: beq         $v0, $v1, L_8001B74C
    if (ctx->r2 == ctx->r3) {
        // 0x8001B740: sll         $t8, $v0, 4
        ctx->r24 = S32(ctx->r2 << 4);
            goto L_8001B74C;
    }
    // 0x8001B740: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8001B744: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8001B748: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
L_8001B74C:
    // 0x8001B74C: beq         $v0, $a1, L_8001B75C
    if (ctx->r2 == ctx->r5) {
        // 0x8001B750: sll         $t0, $v0, 4
        ctx->r8 = S32(ctx->r2 << 4);
            goto L_8001B75C;
    }
    // 0x8001B750: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x8001B754: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8001B758: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
L_8001B75C:
    // 0x8001B75C: beq         $v0, $a2, L_8001B76C
    if (ctx->r2 == ctx->r6) {
        // 0x8001B760: sll         $t2, $v0, 4
        ctx->r10 = S32(ctx->r2 << 4);
            goto L_8001B76C;
    }
    // 0x8001B760: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8001B764: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8001B768: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
L_8001B76C:
    // 0x8001B76C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B770: bne         $v0, $a3, L_8001B72C
    if (ctx->r2 != ctx->r7) {
        // 0x8001B774: nop
    
            goto L_8001B72C;
    }
    // 0x8001B774: nop

    // 0x8001B778: jr          $ra
    // 0x8001B77C: nop

    return;
    // 0x8001B77C: nop

;}
RECOMP_FUNC void wpMapProcAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801679A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801679A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801679A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801679AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801679B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801679B4: jal         0x800DB838
    // 0x801679B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x801679B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801679BC: beq         $v0, $zero, L_801679CC
    if (ctx->r2 == 0) {
        // 0x801679C0: nop
    
            goto L_801679CC;
    }
    // 0x801679C0: nop

    // 0x801679C4: jal         0x800DBF58
    // 0x801679C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x801679C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_801679CC:
    // 0x801679CC: jal         0x800DC3C8
    // 0x801679D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x801679D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801679D4: beq         $v0, $zero, L_801679E4
    if (ctx->r2 == 0) {
        // 0x801679D8: nop
    
            goto L_801679E4;
    }
    // 0x801679D8: nop

    // 0x801679DC: jal         0x800DCAE8
    // 0x801679E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_3;
    // 0x801679E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_801679E4:
    // 0x801679E4: jal         0x800DCF58
    // 0x801679E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x801679E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801679EC: beq         $v0, $zero, L_80167A14
    if (ctx->r2 == 0) {
        // 0x801679F0: nop
    
            goto L_80167A14;
    }
    // 0x801679F0: nop

    // 0x801679F4: jal         0x800DD160
    // 0x801679F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x801679F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801679FC: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x80167A00: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80167A04: beq         $t7, $zero, L_80167A14
    if (ctx->r15 == 0) {
        // 0x80167A08: nop
    
            goto L_80167A14;
    }
    // 0x80167A08: nop

    // 0x80167A0C: jal         0x800D99B8
    // 0x80167A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_6;
    // 0x80167A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80167A14:
    // 0x80167A14: jal         0x800DD578
    // 0x80167A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_7;
    // 0x80167A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80167A1C: beql        $v0, $zero, L_80167A48
    if (ctx->r2 == 0) {
        // 0x80167A20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80167A48;
    }
    goto skip_0;
    // 0x80167A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80167A24: jal         0x800DD6A8
    // 0x80167A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollideFloor(rdram, ctx);
        goto after_8;
    // 0x80167A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80167A2C: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x80167A30: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x80167A34: beql        $t9, $zero, L_80167A48
    if (ctx->r25 == 0) {
        // 0x80167A38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80167A48;
    }
    goto skip_1;
    // 0x80167A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80167A3C: jal         0x800D9F84
    // 0x80167A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_9;
    // 0x80167A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80167A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80167A48:
    // 0x80167A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80167A4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80167A50: jr          $ra
    // 0x80167A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80167A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoomFadeOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801322E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801322E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322E8: sw          $zero, 0x432C($at)
    MEM_W(0X432C, ctx->r1) = 0;
    // 0x801322EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322F4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x801322F8: jal         0x80009968
    // 0x801322FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801322FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132300: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132304: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132308: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013230C: sw          $v0, 0x4330($at)
    MEM_W(0X4330, ctx->r1) = ctx->r2;
    // 0x80132310: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132314: addiu       $a1, $a1, 0x21A8
    ctx->r5 = ADD32(ctx->r5, 0X21A8);
    // 0x80132318: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013231C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80132320: jal         0x80009DF4
    // 0x80132324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013232C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132330: jr          $ra
    // 0x80132334: nop

    return;
    // 0x80132334: nop

;}
RECOMP_FUNC void itPakkunCommonSetWaitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CFC0: beq         $a0, $zero, L_8017CFD4
    if (ctx->r4 == 0) {
        // 0x8017CFC4: nop
    
            goto L_8017CFD4;
    }
    // 0x8017CFC4: nop

    // 0x8017CFC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017CFCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017CFD0: sb          $t6, 0x35C($v0)
    MEM_B(0X35C, ctx->r2) = ctx->r14;
L_8017CFD4:
    // 0x8017CFD4: jr          $ra
    // 0x8017CFD8: nop

    return;
    // 0x8017CFD8: nop

;}
RECOMP_FUNC void ftCommonDamageUpdateDamageColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801415F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801415FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141600: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80141604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80141608: jal         0x800EA1B0
    // 0x8014160C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetHitStun(rdram, ctx);
        goto after_0;
    // 0x8014160C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80141610: jal         0x80140A94
    // 0x80141614: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    ftCommonDamageGetDamageLevel(rdram, ctx);
        goto after_1;
    // 0x80141614: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80141618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8014161C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80141620: jal         0x80140BCC
    // 0x80141624: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftCommonDamageCheckElementSetColAnim(rdram, ctx);
        goto after_2;
    // 0x80141624: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80141628: beql        $v0, $zero, L_8014163C
    if (ctx->r2 == 0) {
        // 0x8014162C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014163C;
    }
    goto skip_0;
    // 0x8014162C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80141630: jal         0x800E11C8
    // 0x80141634: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftMainRunUpdateColAnim(rdram, ctx);
        goto after_3;
    // 0x80141634: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80141638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014163C:
    // 0x8014163C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141640: jr          $ra
    // 0x80141644: nop

    return;
    // 0x80141644: nop

;}
RECOMP_FUNC void ftComputerSetupAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A8A8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8013A8AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8013A8B0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8013A8B4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8013A8B8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8013A8BC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8013A8C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8013A8C4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8013A8C8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013A8CC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013A8D0: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8013A8D4: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // 0x8013A8D8: addiu       $s0, $s1, 0x1CC
    ctx->r16 = ADD32(ctx->r17, 0X1CC);
    // 0x8013A8DC: jal         0x800315B0
    // 0x8013A8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x8013A8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013A8E4: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8013A8E8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013A8EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013A8F0: beq         $t6, $at, L_8013ABD4
    if (ctx->r14 == ctx->r1) {
        // 0x8013A8F4: addiu       $v1, $v1, 0x1348
        ctx->r3 = ADD32(ctx->r3, 0X1348);
            goto L_8013ABD4;
    }
    // 0x8013A8F4: addiu       $v1, $v1, 0x1348
    ctx->r3 = ADD32(ctx->r3, 0X1348);
    // 0x8013A8F8: lw          $t7, 0x8E8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8E8);
    // 0x8013A8FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013A900: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8013A904: lwc1        $f0, 0x1C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8013A908: addiu       $s4, $s4, 0x1308
    ctx->r20 = ADD32(ctx->r20, 0X1308);
    // 0x8013A90C: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x8013A910: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x8013A914: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8013A918: lw          $t8, 0x14C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14C);
    // 0x8013A91C: bnel        $t8, $zero, L_8013A93C
    if (ctx->r24 != 0) {
        // 0x8013A920: lw          $t0, 0x8E8($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X8E8);
            goto L_8013A93C;
    }
    goto skip_0;
    // 0x8013A920: lw          $t0, 0x8E8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8E8);
    skip_0:
    // 0x8013A924: lw          $t9, 0x8E8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8E8);
    // 0x8013A928: lwc1        $f0, 0x20($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8013A92C: swc1        $f0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f0.u32l;
    // 0x8013A930: b           L_8013A950
    // 0x8013A934: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
        goto L_8013A950;
    // 0x8013A934: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x8013A938: lw          $t0, 0x8E8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8E8);
L_8013A93C:
    // 0x8013A93C: lwc1        $f6, 0xF0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x8013A940: lwc1        $f4, 0x20($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8013A944: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013A948: swc1        $f0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f0.u32l;
    // 0x8013A94C: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
L_8013A950:
    // 0x8013A950: lw          $t1, 0xEC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XEC);
    // 0x8013A954: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8013A958: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8013A95C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8013A960: sw          $t1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r9;
    // 0x8013A964: lbu         $t2, 0x13($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X13);
    // 0x8013A968: addiu       $t4, $zero, 0x5A0
    ctx->r12 = ADD32(0, 0X5A0);
    // 0x8013A96C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8013A970: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8013A974: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8013A978: subu        $s2, $t4, $t3
    ctx->r18 = SUB32(ctx->r12, ctx->r11);
    // 0x8013A97C: bgezl       $s2, L_8013A98C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8013A980: sh          $s2, 0x14($s0)
        MEM_H(0X14, ctx->r16) = ctx->r18;
            goto L_8013A98C;
    }
    goto skip_1;
    // 0x8013A980: sh          $s2, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r18;
    skip_1:
    // 0x8013A984: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8013A988: sh          $s2, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r18;
L_8013A98C:
    // 0x8013A98C: swc1        $f2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f2.u32l;
    // 0x8013A990: lw          $v0, 0x9C8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9C8);
    // 0x8013A994: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8013A998: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8013A99C: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8013A9A0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8013A9A4: nop

    // 0x8013A9A8: bc1f        L_8013A9F4
    if (!c1cs) {
        // 0x8013A9AC: slti        $at, $s2, 0x7
        ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
            goto L_8013A9F4;
    }
    // 0x8013A9AC: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
L_8013A9B0:
    // 0x8013A9B0: bnel        $at, $zero, L_8013A9C4
    if (ctx->r1 != 0) {
        // 0x8013A9B4: lwc1        $f16, 0x8C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
            goto L_8013A9C4;
    }
    goto skip_2;
    // 0x8013A9B4: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    skip_2:
    // 0x8013A9B8: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8013A9BC: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8013A9C0: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
L_8013A9C4:
    // 0x8013A9C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8013A9C8: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8013A9CC: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8013A9D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013A9D4: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
    // 0x8013A9D8: lw          $v0, 0x9C8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9C8);
    // 0x8013A9DC: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8013A9E0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8013A9E4: nop

    // 0x8013A9E8: bc1tl       L_8013A9B0
    if (c1cs) {
        // 0x8013A9EC: slti        $at, $s2, 0x7
        ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
            goto L_8013A9B0;
    }
    goto skip_3;
    // 0x8013A9EC: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    skip_3:
    // 0x8013A9F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8013A9F4:
    // 0x8013A9F4: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8013A9F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013A9FC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8013AA00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013AA04: swc1        $f10, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
    // 0x8013AA08: lw          $v0, 0x9C8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9C8);
    // 0x8013AA0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013AA10: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8013AA14: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8013AA18: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8013AA1C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013AA20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8013AA24: nop

    // 0x8013AA28: bc1f        L_8013AA50
    if (!c1cs) {
        // 0x8013AA2C: nop
    
            goto L_8013AA50;
    }
    // 0x8013AA2C: nop

L_8013AA30:
    // 0x8013AA30: lw          $t5, 0x9C8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X9C8);
    // 0x8013AA34: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8013AA38: lwc1        $f8, 0x58($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X58);
    // 0x8013AA3C: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8013AA40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8013AA44: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8013AA48: bc1t        L_8013AA30
    if (c1cs) {
        // 0x8013AA4C: swc1        $f16, 0x90($s0)
        MEM_W(0X90, ctx->r16) = ctx->f16.u32l;
            goto L_8013AA30;
    }
    // 0x8013AA4C: swc1        $f16, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f16.u32l;
L_8013AA50:
    // 0x8013AA50: lwc1        $f0, -0x3FD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3FD8);
    // 0x8013AA54: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8013AA58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8013AA5C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8013AA60: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8013AA64: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8013AA68: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8013AA6C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8013AA70: blez        $t6, L_8013ABD4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8013AA74: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_8013ABD4;
    }
    // 0x8013AA74: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8013AA78: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8013AA7C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013AA80: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8013AA84:
    // 0x8013AA84: jal         0x800FC67C
    // 0x8013AA88: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_1;
    // 0x8013AA88: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_1:
    // 0x8013AA8C: beq         $v0, $zero, L_8013ABB8
    if (ctx->r2 == 0) {
        // 0x8013AA90: nop
    
            goto L_8013ABB8;
    }
    // 0x8013AA90: nop

    // 0x8013AA94: jal         0x800FCA18
    // 0x8013AA98: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_2;
    // 0x8013AA98: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_2:
    // 0x8013AA9C: bne         $v0, $zero, L_8013ABB8
    if (ctx->r2 != 0) {
        // 0x8013AAA0: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_8013ABB8;
    }
    // 0x8013AAA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8013AAA4: jal         0x800F4428
    // 0x8013AAA8: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x8013AAA8: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_3:
    // 0x8013AAAC: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8013AAB0: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AAB4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8013AAB8: c.lt.s      $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f18.fl < ctx->f22.fl;
    // 0x8013AABC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x8013AAC0: bc1fl       L_8013AAF4
    if (!c1cs) {
        // 0x8013AAC4: lwc1        $f10, 0x2C($s4)
        ctx->f10.u32l = MEM_W(ctx->r20, 0X2C);
            goto L_8013AAF4;
    }
    goto skip_4;
    // 0x8013AAC4: lwc1        $f10, 0x2C($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X2C);
    skip_4:
    // 0x8013AAC8: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8013AACC: mov.s       $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = ctx->f18.fl;
    // 0x8013AAD0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8013AAD4: nop

    // 0x8013AAD8: bc1f        L_8013AB30
    if (!c1cs) {
        // 0x8013AADC: nop
    
            goto L_8013AB30;
    }
    // 0x8013AADC: nop

    // 0x8013AAE0: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x8013AAE4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AAE8: b           L_8013AB30
    // 0x8013AAEC: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_8013AB30;
    // 0x8013AAEC: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8013AAF0: lwc1        $f10, 0x2C($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X2C);
L_8013AAF4:
    // 0x8013AAF4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AAF8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8013AAFC: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8013AB00: nop

    // 0x8013AB04: bc1f        L_8013AB30
    if (!c1cs) {
        // 0x8013AB08: nop
    
            goto L_8013AB30;
    }
    // 0x8013AB08: nop

    // 0x8013AB0C: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8013AB10: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8013AB14: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8013AB18: nop

    // 0x8013AB1C: bc1f        L_8013AB30
    if (!c1cs) {
        // 0x8013AB20: nop
    
            goto L_8013AB30;
    }
    // 0x8013AB20: nop

    // 0x8013AB24: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x8013AB28: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AB2C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_8013AB30:
    // 0x8013AB30: jal         0x800F4408
    // 0x8013AB34: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x8013AB34: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_4:
    // 0x8013AB38: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8013AB3C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AB40: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x8013AB44: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    // 0x8013AB48: bc1fl       L_8013AB7C
    if (!c1cs) {
        // 0x8013AB4C: lwc1        $f18, 0x28($s4)
        ctx->f18.u32l = MEM_W(ctx->r20, 0X28);
            goto L_8013AB7C;
    }
    goto skip_5;
    // 0x8013AB4C: lwc1        $f18, 0x28($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X28);
    skip_5:
    // 0x8013AB50: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8013AB54: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
    // 0x8013AB58: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8013AB5C: nop

    // 0x8013AB60: bc1f        L_8013ABB8
    if (!c1cs) {
        // 0x8013AB64: nop
    
            goto L_8013ABB8;
    }
    // 0x8013AB64: nop

    // 0x8013AB68: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8013AB6C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AB70: b           L_8013ABB8
    // 0x8013AB74: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_8013ABB8;
    // 0x8013AB74: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x8013AB78: lwc1        $f18, 0x28($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X28);
L_8013AB7C:
    // 0x8013AB7C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013AB80: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8013AB84: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8013AB88: nop

    // 0x8013AB8C: bc1f        L_8013ABB8
    if (!c1cs) {
        // 0x8013AB90: nop
    
            goto L_8013ABB8;
    }
    // 0x8013AB90: nop

    // 0x8013AB94: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8013AB98: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8013AB9C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8013ABA0: nop

    // 0x8013ABA4: bc1f        L_8013ABB8
    if (!c1cs) {
        // 0x8013ABA8: nop
    
            goto L_8013ABB8;
    }
    // 0x8013ABA8: nop

    // 0x8013ABAC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8013ABB0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8013ABB4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8013ABB8:
    // 0x8013ABB8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013ABBC: lhu         $t7, 0x1348($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1348);
    // 0x8013ABC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8013ABC4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8013ABC8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8013ABCC: bne         $at, $zero, L_8013AA84
    if (ctx->r1 != 0) {
        // 0x8013ABD0: nop
    
            goto L_8013AA84;
    }
    // 0x8013ABD0: nop

L_8013ABD4:
    // 0x8013ABD4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8013ABD8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013ABDC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013ABE0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8013ABE4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8013ABE8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8013ABEC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8013ABF0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8013ABF4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8013ABF8: jr          $ra
    // 0x8013ABFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8013ABFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void itMewMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EDE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017EDE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017EDEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017EDF0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017EDF4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017EDF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017EDFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017EE00: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017EE04: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017EE08: addiu       $a1, $a1, -0x53C0
    ctx->r5 = ADD32(ctx->r5, -0X53C0);
    // 0x8017EE0C: jal         0x8016E174
    // 0x8017EE10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017EE10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017EE14: beq         $v0, $zero, L_8017EE90
    if (ctx->r2 == 0) {
        // 0x8017EE18: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017EE90;
    }
    // 0x8017EE18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017EE1C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017EE20: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x8017EE24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017EE28: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017EE2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017EE30: lw          $t8, 0x2D4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017EE34: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x8017EE38: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x8017EE3C: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8017EE40: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017EE44: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017EE48: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8017EE4C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017EE50: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8017EE54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8017EE58: addiu       $t2, $t2, -0x4340
    ctx->r10 = ADD32(ctx->r10, -0X4340);
    // 0x8017EE5C: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8017EE60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017EE64: addiu       $t4, $t4, 0x3624
    ctx->r12 = ADD32(ctx->r12, 0X3624);
    // 0x8017EE68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017EE6C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017EE70: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8017EE74: lw          $t0, 0x2D4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017EE78: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8017EE7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8017EE80: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8017EE84: jal         0x8000BD1C
    // 0x8017EE88: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017EE88: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8017EE8C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8017EE90:
    // 0x8017EE90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EE94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017EE98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8017EE9C: jr          $ra
    // 0x8017EEA0: nop

    return;
    // 0x8017EEA0: nop

;}
RECOMP_FUNC void efGroundUpdatePhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80116208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011620C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80116210: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80116214: addiu       $a3, $a3, 0x1AD8
    ctx->r7 = ADD32(ctx->r7, 0X1AD8);
    // 0x80116218: lw          $t7, 0x18($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X18);
    // 0x8011621C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80116220: sll         $a2, $a1, 6
    ctx->r6 = S32(ctx->r5 << 6);
    // 0x80116224: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80116228: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8011622C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80116230: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80116234: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80116238: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8011623C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80116240: jal         0x80018948
    // 0x80116244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80116244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80116248: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8011624C: addiu       $a3, $a3, 0x1AD8
    ctx->r7 = ADD32(ctx->r7, 0X1AD8);
    // 0x80116250: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    // 0x80116254: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80116258: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8011625C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80116260: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80116264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80116268: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x8011626C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80116270: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80116274: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80116278: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8011627C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80116280: add.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80116284: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x80116288: lw          $t2, 0x18($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X18);
    // 0x8011628C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80116290: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80116294: lwc1        $f2, 0xC($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80116298: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8011629C: swc1        $f2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f2.u32l;
    // 0x801162A0: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    // 0x801162A4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801162A8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x801162AC: bne         $t6, $at, L_801162E8
    if (ctx->r14 != ctx->r1) {
        // 0x801162B0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801162E8;
    }
    // 0x801162B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801162B4: lwc1        $f18, 0xD34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XD34);
    // 0x801162B8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801162BC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801162C0: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x801162C4: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x801162C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801162CC: lh          $t8, 0x7A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X7A);
    // 0x801162D0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801162D4: nop

    // 0x801162D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801162DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801162E0: b           L_8011630C
    // 0x801162E4: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
        goto L_8011630C;
    // 0x801162E4: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
L_801162E8:
    // 0x801162E8: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x801162EC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801162F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801162F4: lh          $t0, 0x78($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X78);
    // 0x801162F8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801162FC: nop

    // 0x80116300: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80116304: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80116308: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_8011630C:
    // 0x8011630C: lw          $t1, 0x18($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X18);
    // 0x80116310: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80116314: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x80116318: lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X14);
    // 0x8011631C: beql        $v0, $zero, L_80116330
    if (ctx->r2 == 0) {
        // 0x80116320: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80116330;
    }
    goto skip_0;
    // 0x80116320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80116324: jalr        $v0
    // 0x80116328: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80116328: nop

    after_1:
    // 0x8011632C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80116330:
    // 0x80116330: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80116334: jr          $ra
    // 0x80116338: nop

    return;
    // 0x80116338: nop

;}
RECOMP_FUNC void ftCommonAttackLw4CheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150798: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8015079C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801507A0: slti        $at, $t6, -0x34
    ctx->r1 = SIGNED(ctx->r14) < -0X34 ? 1 : 0;
    // 0x801507A4: beq         $at, $zero, L_801507C8
    if (ctx->r1 == 0) {
        // 0x801507A8: nop
    
            goto L_801507C8;
    }
    // 0x801507A8: nop

    // 0x801507AC: lhu         $t7, 0x1BE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BE);
    // 0x801507B0: lhu         $t8, 0x1B4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B4);
    // 0x801507B4: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x801507B8: beq         $t9, $zero, L_801507C8
    if (ctx->r25 == 0) {
        // 0x801507BC: nop
    
            goto L_801507C8;
    }
    // 0x801507BC: nop

    // 0x801507C0: jr          $ra
    // 0x801507C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801507C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801507C8:
    // 0x801507C8: jr          $ra
    // 0x801507CC: nop

    return;
    // 0x801507CC: nop

;}
RECOMP_FUNC void ftCommonJumpGetJumpForceButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F6A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013F6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F6A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013F6AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8013F6B0: bgez        $a0, L_8013F6C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8013F6B4: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8013F6C8;
    }
    // 0x8013F6B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8013F6B8: negu        $t6, $a0
    ctx->r14 = SUB32(0, ctx->r4);
    // 0x8013F6BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013F6C0: b           L_8013F6D4
    // 0x8013F6C4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
        goto L_8013F6D4;
    // 0x8013F6C4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
L_8013F6C8:
    // 0x8013F6C8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8013F6CC: nop

    // 0x8013F6D0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
L_8013F6D4:
    // 0x8013F6D4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8013F6D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013F6DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013F6E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013F6E4: div.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8013F6E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013F6EC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8013F6F0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8013F6F4: jal         0x80033510
    // 0x8013F6F8: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8013F6F8: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    after_0:
    // 0x8013F6FC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8013F700: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013F704: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8013F708: bne         $t7, $zero, L_8013F794
    if (ctx->r15 != 0) {
        // 0x8013F70C: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_8013F794;
    }
    // 0x8013F70C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8013F710: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8013F714: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013F718: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8013F71C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013F720: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x8013F724: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013F728: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8013F72C: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8013F730: mul.s       $f14, $f16, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8013F734: nop

    // 0x8013F738: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8013F73C: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8013F740: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8013F744: nop

    // 0x8013F748: bc1f        L_8013F77C
    if (!c1cs) {
        // 0x8013F74C: nop
    
            goto L_8013F77C;
    }
    // 0x8013F74C: nop

    // 0x8013F750: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x8013F754: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013F758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013F75C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8013F760: jal         0x80033510
    // 0x8013F764: sub.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8013F764: sub.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f14.fl;
    after_1:
    // 0x8013F768: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8013F76C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013F770: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013F774: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8013F778: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8013F77C:
    // 0x8013F77C: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8013F780: nop

    // 0x8013F784: bc1fl       L_8013F814
    if (!c1cs) {
        // 0x8013F788: lui         $at, 0x429A
        ctx->r1 = S32(0X429A << 16);
            goto L_8013F814;
    }
    goto skip_0;
    // 0x8013F788: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    skip_0:
    // 0x8013F78C: b           L_8013F810
    // 0x8013F790: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
        goto L_8013F810;
    // 0x8013F790: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
L_8013F794:
    // 0x8013F794: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013F798: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8013F79C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013F7A0: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x8013F7A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013F7A8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013F7AC: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8013F7B0: mul.s       $f14, $f16, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8013F7B4: nop

    // 0x8013F7B8: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8013F7BC: add.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8013F7C0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8013F7C4: nop

    // 0x8013F7C8: bc1f        L_8013F7FC
    if (!c1cs) {
        // 0x8013F7CC: nop
    
            goto L_8013F7FC;
    }
    // 0x8013F7CC: nop

    // 0x8013F7D0: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x8013F7D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013F7D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013F7DC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8013F7E0: jal         0x80033510
    // 0x8013F7E4: sub.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8013F7E4: sub.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f14.fl;
    after_2:
    // 0x8013F7E8: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8013F7EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013F7F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013F7F4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8013F7F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8013F7FC:
    // 0x8013F7FC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8013F800: nop

    // 0x8013F804: bc1fl       L_8013F814
    if (!c1cs) {
        // 0x8013F808: lui         $at, 0x429A
        ctx->r1 = S32(0X429A << 16);
            goto L_8013F814;
    }
    goto skip_1;
    // 0x8013F808: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    skip_1:
    // 0x8013F80C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
L_8013F810:
    // 0x8013F810: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
L_8013F814:
    // 0x8013F814: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013F818: nop

    // 0x8013F81C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8013F820: nop

    // 0x8013F824: bc1f        L_8013F830
    if (!c1cs) {
        // 0x8013F828: nop
    
            goto L_8013F830;
    }
    // 0x8013F828: nop

    // 0x8013F82C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8013F830:
    // 0x8013F830: bltz        $a0, L_8013F84C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8013F834: trunc.w.s   $f10, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
            goto L_8013F84C;
    }
    // 0x8013F834: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8013F838: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8013F83C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8013F840: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8013F844: b           L_8013F864
    // 0x8013F848: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_8013F864;
    // 0x8013F848: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_8013F84C:
    // 0x8013F84C: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8013F850: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8013F854: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013F858: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8013F85C: nop

    // 0x8013F860: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_8013F864:
    // 0x8013F864: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8013F868: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8013F86C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8013F870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013F878: jr          $ra
    // 0x8013F87C: nop

    return;
    // 0x8013F87C: nop

;}
RECOMP_FUNC void grYosterUpdateCloudEvaporate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108814: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80108818: addiu       $t7, $t7, 0x13F0
    ctx->r15 = ADD32(ctx->r15, 0X13F0);
    // 0x8010881C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80108820: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80108824: lbu         $t8, 0x1E($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1E);
    // 0x80108828: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010882C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108830: beq         $t8, $zero, L_80108854
    if (ctx->r24 == 0) {
        // 0x80108834: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80108854;
    }
    // 0x80108834: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80108838: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010883C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80108840: lbu         $a0, -0x14D8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14D8);
    // 0x80108844: jal         0x800FC604
    // 0x80108848: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_0;
    // 0x80108848: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8010884C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80108850: sb          $zero, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = 0;
L_80108854:
    // 0x80108854: lbu         $v1, 0x20($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X20);
    // 0x80108858: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8010885C: bne         $v1, $zero, L_8010887C
    if (ctx->r3 != 0) {
        // 0x80108860: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8010887C;
    }
    // 0x80108860: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80108864: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80108868: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x8010886C: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x80108870: sb          $t9, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r25;
    // 0x80108874: b           L_80108880
    // 0x80108878: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
        goto L_80108880;
    // 0x80108878: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
L_8010887C:
    // 0x8010887C: sb          $t0, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r8;
L_80108880:
    // 0x80108880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108888: jr          $ra
    // 0x8010888C: nop

    return;
    // 0x8010888C: nop

;}
RECOMP_FUNC void func_ovl53_801325CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325CC: jr          $ra
    // 0x801325D0: nop

    return;
    // 0x801325D0: nop

;}
RECOMP_FUNC void mnPlayersVSDetectBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138140: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80138144: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80138148: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013814C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80138150: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138154: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80138158: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013815C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80138160: lw          $t8, 0xB0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB0);
    // 0x80138164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013816C: beq         $t8, $zero, L_801381D8
    if (ctx->r24 == 0) {
        // 0x80138170: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_801381D8;
    }
    // 0x80138170: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80138174: lw          $v1, 0xB8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB8);
    // 0x80138178: beq         $v1, $zero, L_80138208
    if (ctx->r3 == 0) {
        // 0x8013817C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80138208;
    }
    // 0x8013817C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80138180: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x80138184: beq         $at, $zero, L_80138208
    if (ctx->r1 == 0) {
        // 0x80138188: sw          $t9, 0xB8($v0)
        MEM_W(0XB8, ctx->r2) = ctx->r25;
            goto L_80138208;
    }
    // 0x80138188: sw          $t9, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r25;
    // 0x8013818C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80138190: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80138194: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80138198: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8013819C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801381A0: lhu         $t1, 0x5228($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X5228);
    // 0x801381A4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801381A8: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x801381AC: beql        $t2, $zero, L_801381D0
    if (ctx->r10 == 0) {
        // 0x801381B0: sw          $zero, 0xB0($v0)
        MEM_W(0XB0, ctx->r2) = 0;
            goto L_801381D0;
    }
    goto skip_0;
    // 0x801381B0: sw          $zero, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = 0;
    skip_0:
    // 0x801381B4: bnel        $t9, $at, L_8013820C
    if (ctx->r25 != ctx->r1) {
        // 0x801381B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013820C;
    }
    goto skip_1;
    // 0x801381B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801381BC: jal         0x801380F4
    // 0x801381C0: nop

    mnPlayersVSBackToVSMode(rdram, ctx);
        goto after_0;
    // 0x801381C0: nop

    after_0:
    // 0x801381C4: b           L_8013820C
    // 0x801381C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013820C;
    // 0x801381C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801381CC: sw          $zero, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = 0;
L_801381D0:
    // 0x801381D0: b           L_80138208
    // 0x801381D4: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
        goto L_80138208;
    // 0x801381D4: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
L_801381D8:
    // 0x801381D8: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x801381DC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801381E0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x801381E4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801381E8: lhu         $t4, 0x522A($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X522A);
    // 0x801381EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801381F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801381F4: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x801381F8: beql        $t5, $zero, L_80138208
    if (ctx->r13 == 0) {
        // 0x801381FC: sw          $t7, 0xB8($v0)
        MEM_W(0XB8, ctx->r2) = ctx->r15;
            goto L_80138208;
    }
    goto skip_2;
    // 0x801381FC: sw          $t7, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r15;
    skip_2:
    // 0x80138200: sw          $t6, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->r14;
    // 0x80138204: sw          $t7, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->r15;
L_80138208:
    // 0x80138208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013820C:
    // 0x8013820C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138210: jr          $ra
    // 0x80138214: nop

    return;
    // 0x80138214: nop

;}
RECOMP_FUNC void ftKirbySpecialNWaitUpdateLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162F60: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80162F64: lw          $v1, 0x840($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X840);
    // 0x80162F68: beql        $v1, $zero, L_80162F80
    if (ctx->r3 == 0) {
        // 0x80162F6C: lw          $t7, 0x44($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X44);
            goto L_80162F80;
    }
    goto skip_0;
    // 0x80162F6C: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    skip_0:
    // 0x80162F70: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80162F74: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80162F78: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x80162F7C: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
L_80162F80:
    // 0x80162F80: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80162F84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80162F88: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80162F8C: nop

    // 0x80162F90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80162F94: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80162F98: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80162F9C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80162FA0: jr          $ra
    // 0x80162FA4: sw          $t9, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r25;
    return;
    // 0x80162FA4: sw          $t9, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void ftCommonTurnCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EA08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EA0C: jal         0x8013E9D0
    // 0x8013EA10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8013EA10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013EA14: beql        $v0, $zero, L_8013EA30
    if (ctx->r2 == 0) {
        // 0x8013EA18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EA30;
    }
    goto skip_0;
    // 0x8013EA18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013EA1C: jal         0x8013E988
    // 0x8013EA20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonTurnSetStatusCenter(rdram, ctx);
        goto after_1;
    // 0x8013EA20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013EA24: b           L_8013EA30
    // 0x8013EA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013EA30;
    // 0x8013EA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013EA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EA30:
    // 0x8013EA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EA34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EA38: jr          $ra
    // 0x8013EA3C: nop

    return;
    // 0x8013EA3C: nop

;}

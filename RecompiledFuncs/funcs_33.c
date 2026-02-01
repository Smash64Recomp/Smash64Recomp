#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_80374E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374E0C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80374E10: lw          $t6, -0x103C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X103C);
    // 0x80374E14: jr          $ra
    // 0x80374E18: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
    return;
    // 0x80374E18: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
;}
RECOMP_FUNC void mvOpeningStandoffWallpaperProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D38: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131D3C: addiu       $a2, $a2, 0x29D0
    ctx->r6 = ADD32(ctx->r6, 0X29D0);
    // 0x80131D40: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80131D44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131D48: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131D4C: beq         $a1, $at, L_80131D98
    if (ctx->r5 == ctx->r1) {
        // 0x80131D50: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80131D98;
    }
    // 0x80131D50: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80131D54: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80131D58: beq         $v1, $at, L_80131DB0
    if (ctx->r3 == ctx->r1) {
        // 0x80131D5C: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80131DB0;
    }
    // 0x80131D5C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80131D60: beq         $v1, $at, L_80131DD0
    if (ctx->r3 == ctx->r1) {
        // 0x80131D64: addiu       $at, $zero, 0xB4
        ctx->r1 = ADD32(0, 0XB4);
            goto L_80131DD0;
    }
    // 0x80131D64: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80131D68: beq         $v1, $at, L_80131DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80131D6C: addiu       $at, $zero, 0xC3
        ctx->r1 = ADD32(0, 0XC3);
            goto L_80131DE8;
    }
    // 0x80131D6C: addiu       $at, $zero, 0xC3
    ctx->r1 = ADD32(0, 0XC3);
    // 0x80131D70: beq         $v1, $at, L_80131E08
    if (ctx->r3 == ctx->r1) {
        // 0x80131D74: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_80131E08;
    }
    // 0x80131D74: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80131D78: beq         $v1, $at, L_80131E20
    if (ctx->r3 == ctx->r1) {
        // 0x80131D7C: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_80131E20;
    }
    // 0x80131D7C: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80131D80: beq         $v1, $at, L_80131E38
    if (ctx->r3 == ctx->r1) {
        // 0x80131D84: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80131E38;
    }
    // 0x80131D84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131D88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131D8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131D90: b           L_80131E54
    // 0x80131D94: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
        goto L_80131E54;
    // 0x80131D94: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
L_80131D98:
    // 0x80131D98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131D9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131DA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DA4: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131DA8: b           L_80131E54
    // 0x80131DAC: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
        goto L_80131E54;
    // 0x80131DAC: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_80131DB0:
    // 0x80131DB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80131DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DB8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131DC0: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131DC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131DC8: b           L_80131E54
    // 0x80131DCC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
        goto L_80131E54;
    // 0x80131DCC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80131DD0:
    // 0x80131DD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131DD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131DD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DDC: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131DE0: b           L_80131E54
    // 0x80131DE4: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
        goto L_80131E54;
    // 0x80131DE4: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_80131DE8:
    // 0x80131DE8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80131DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131DF8: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131DFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131E00: b           L_80131E54
    // 0x80131E04: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_80131E54;
    // 0x80131E04: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_80131E08:
    // 0x80131E08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131E0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131E10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E14: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131E18: b           L_80131E54
    // 0x80131E1C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
        goto L_80131E54;
    // 0x80131E1C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_80131E20:
    // 0x80131E20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131E24: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131E28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E2C: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131E30: b           L_80131E54
    // 0x80131E34: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
        goto L_80131E54;
    // 0x80131E34: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_80131E38:
    // 0x80131E38: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80131E3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E40: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131E48: addiu       $v1, $v1, 0x29D4
    ctx->r3 = ADD32(ctx->r3, 0X29D4);
    // 0x80131E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131E50: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_80131E54:
    // 0x80131E54: slti        $at, $a1, 0x119
    ctx->r1 = SIGNED(ctx->r5) < 0X119 ? 1 : 0;
    // 0x80131E58: bne         $at, $zero, L_80131E78
    if (ctx->r1 != 0) {
        // 0x80131E5C: slti        $at, $a1, 0x12C
        ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
            goto L_80131E78;
    }
    // 0x80131E5C: slti        $at, $a1, 0x12C
    ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80131E60: beq         $at, $zero, L_80131E78
    if (ctx->r1 == 0) {
        // 0x80131E64: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131E78;
    }
    // 0x80131E64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E68: lwc1        $f16, 0x29B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X29B0);
    // 0x80131E6C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131E70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80131E74: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80131E78:
    // 0x80131E78: slti        $at, $a1, 0x12D
    ctx->r1 = SIGNED(ctx->r5) < 0X12D ? 1 : 0;
    // 0x80131E7C: bne         $at, $zero, L_80131E9C
    if (ctx->r1 != 0) {
        // 0x80131E80: slti        $at, $a1, 0x140
        ctx->r1 = SIGNED(ctx->r5) < 0X140 ? 1 : 0;
            goto L_80131E9C;
    }
    // 0x80131E80: slti        $at, $a1, 0x140
    ctx->r1 = SIGNED(ctx->r5) < 0X140 ? 1 : 0;
    // 0x80131E84: beq         $at, $zero, L_80131E9C
    if (ctx->r1 == 0) {
        // 0x80131E88: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131E9C;
    }
    // 0x80131E88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E8C: lwc1        $f6, 0x29B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X29B4);
    // 0x80131E90: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131E94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131E98: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_80131E9C:
    // 0x80131E9C: slti        $at, $a1, 0x12D
    ctx->r1 = SIGNED(ctx->r5) < 0X12D ? 1 : 0;
    // 0x80131EA0: bnel        $at, $zero, L_80131ECC
    if (ctx->r1 != 0) {
        // 0x80131EA4: lwc1        $f4, 0x58($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
            goto L_80131ECC;
    }
    goto skip_0;
    // 0x80131EA4: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    skip_0:
    // 0x80131EA8: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131EAC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131EB0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80131EB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131EB8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80131EBC: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131EC0: b           L_80131F00
    // 0x80131EC4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
        goto L_80131F00;
    // 0x80131EC4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131EC8: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
L_80131ECC:
    // 0x80131ECC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131ED0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80131ED4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131ED8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131EDC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131EE0: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131EE4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80131EE8: nop

    // 0x80131EEC: bc1fl       L_80131F04
    if (!c1cs) {
        // 0x80131EF0: lw          $a1, 0x0($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X0);
            goto L_80131F04;
    }
    goto skip_1;
    // 0x80131EF0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x80131EF4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80131EF8: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80131EFC: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
L_80131F00:
    // 0x80131F00: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
L_80131F04:
    // 0x80131F04: slti        $at, $a1, 0x5B
    ctx->r1 = SIGNED(ctx->r5) < 0X5B ? 1 : 0;
    // 0x80131F08: bne         $at, $zero, L_80131F14
    if (ctx->r1 != 0) {
        // 0x80131F0C: slti        $at, $a1, 0x69
        ctx->r1 = SIGNED(ctx->r5) < 0X69 ? 1 : 0;
            goto L_80131F14;
    }
    // 0x80131F0C: slti        $at, $a1, 0x69
    ctx->r1 = SIGNED(ctx->r5) < 0X69 ? 1 : 0;
    // 0x80131F10: bne         $at, $zero, L_80131F24
    if (ctx->r1 != 0) {
        // 0x80131F14: slti        $at, $a1, 0xB5
        ctx->r1 = SIGNED(ctx->r5) < 0XB5 ? 1 : 0;
            goto L_80131F24;
    }
L_80131F14:
    // 0x80131F14: slti        $at, $a1, 0xB5
    ctx->r1 = SIGNED(ctx->r5) < 0XB5 ? 1 : 0;
    // 0x80131F18: bne         $at, $zero, L_80131F74
    if (ctx->r1 != 0) {
        // 0x80131F1C: slti        $at, $a1, 0xC3
        ctx->r1 = SIGNED(ctx->r5) < 0XC3 ? 1 : 0;
            goto L_80131F74;
    }
    // 0x80131F1C: slti        $at, $a1, 0xC3
    ctx->r1 = SIGNED(ctx->r5) < 0XC3 ? 1 : 0;
    // 0x80131F20: beq         $at, $zero, L_80131F74
    if (ctx->r1 == 0) {
        // 0x80131F24: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80131F74;
    }
L_80131F24:
    // 0x80131F24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131F28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131F2C: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80131F30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131F34: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80131F38: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80131F3C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80131F40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F44: swc1        $f18, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f18.u32l;
    // 0x80131F48: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131F4C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80131F50: swc1        $f4, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f4.u32l;
    // 0x80131F54: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80131F58: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80131F5C: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80131F60: swc1        $f2, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f2.u32l;
    // 0x80131F64: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80131F68: swc1        $f2, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f2.u32l;
    // 0x80131F6C: jr          $ra
    // 0x80131F70: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80131F70: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80131F74:
    // 0x80131F74: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80131F78: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80131F7C: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    // 0x80131F80: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80131F84: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131F88: swc1        $f10, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f10.u32l;
    // 0x80131F8C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80131F90: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    // 0x80131F94: swc1        $f12, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f12.u32l;
    // 0x80131F98: swc1        $f12, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f12.u32l;
    // 0x80131F9C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80131FA0: swc1        $f12, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f12.u32l;
    // 0x80131FA4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80131FA8: slti        $at, $t4, 0x12C
    ctx->r1 = SIGNED(ctx->r12) < 0X12C ? 1 : 0;
    // 0x80131FAC: beq         $at, $zero, L_80131FC0
    if (ctx->r1 == 0) {
        // 0x80131FB0: nop
    
            goto L_80131FC0;
    }
    // 0x80131FB0: nop

    // 0x80131FB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80131FB8: nop

    // 0x80131FBC: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
L_80131FC0:
    // 0x80131FC0: jr          $ra
    // 0x80131FC4: nop

    return;
    // 0x80131FC4: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155794: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015579C: addiu       $t6, $zero, 0x804
    ctx->r14 = ADD32(0, 0X804);
    // 0x801557A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801557A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801557A8: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x801557AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801557B0: jal         0x800E6F24
    // 0x801557B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801557B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801557B8: jal         0x800E0830
    // 0x801557BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801557BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801557C0: jal         0x801556E0
    // 0x801557C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialLwInitVars(rdram, ctx);
        goto after_2;
    // 0x801557C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801557C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801557CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801557D0: jr          $ra
    // 0x801557D4: nop

    return;
    // 0x801557D4: nop

;}
RECOMP_FUNC void sc1PGameSetCameraZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F3AC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018F3B0: lbu         $t7, 0x4AE3($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AE3);
    // 0x8018F3B4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018F3B8: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018F3BC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018F3C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018F3C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018F3C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018F3CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018F3D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018F3D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018F3D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018F3DC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018F3E0: lw          $s0, 0x78($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X78);
    // 0x8018F3E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8018F3E8: lw          $t0, 0x84($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X84);
    // 0x8018F3EC: jal         0x80018994
    // 0x8018F3F0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8018F3F0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x8018F3F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8018F3F8: jal         0x80018994
    // 0x8018F3FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8018F3FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x8018F400: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F404: lwc1        $f0, 0x2F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2F28);
    // 0x8018F408: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8018F40C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F410: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018F414: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F418: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018F41C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8018F420: lwc1        $f4, 0x2808($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2808);
    // 0x8018F424: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8018F428: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F42C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018F430: lw          $t4, 0x44($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X44);
    // 0x8018F434: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8018F438: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018F43C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018F440: lwc1        $f4, 0x2820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2820);
    // 0x8018F444: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x8018F448: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8018F44C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F450: lw          $t6, 0x9C8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X9C8);
    // 0x8018F454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018F458: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018F45C: lw          $a3, 0x90($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X90);
    // 0x8018F460: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018F464: lwc1        $f8, 0x2F2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2F2C);
    // 0x8018F468: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8018F46C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018F470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F474: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018F478: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018F47C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018F480: div.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8018F484: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018F488: jal         0x8010CF44
    // 0x8018F48C: nop

    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_2;
    // 0x8018F48C: nop

    after_2:
    // 0x8018F490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018F494: jal         0x800E9198
    // 0x8018F498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_3;
    // 0x8018F498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8018F49C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F4A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F4A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018F4A8: jr          $ra
    // 0x8018F4AC: nop

    return;
    // 0x8018F4AC: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ECAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015ECB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015ECB4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015ECB8: jal         0x800DDDDC
    // 0x8015ECBC: addiu       $a1, $a1, -0x13AC
    ctx->r5 = ADD32(ctx->r5, -0X13AC);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015ECBC: addiu       $a1, $a1, -0x13AC
    ctx->r5 = ADD32(ctx->r5, -0X13AC);
    after_0:
    // 0x8015ECC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015ECC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015ECC8: jr          $ra
    // 0x8015ECCC: nop

    return;
    // 0x8015ECCC: nop

;}
RECOMP_FUNC void grYosterMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108C80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108C88: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80108C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108C90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C94: jal         0x80009968
    // 0x80108C98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80108C98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80108C9C: jal         0x801089F4
    // 0x80108CA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    grYosterInitAll(rdram, ctx);
        goto after_1;
    // 0x80108CA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80108CA4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80108CA8: addiu       $a1, $a1, -0x76A0
    ctx->r5 = ADD32(ctx->r5, -0X76A0);
    // 0x80108CAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80108CB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108CB4: jal         0x80008188
    // 0x80108CB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80108CB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80108CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108CC0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80108CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108CC8: jr          $ra
    // 0x80108CCC: nop

    return;
    // 0x80108CCC: nop

;}
RECOMP_FUNC void syTaskmanRunTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005DA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005DA4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80005DA8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80005DAC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80005DB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005DB4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005DB8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80005DBC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80005DC0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005DC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005DC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005DCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005DD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005DD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005DD8: sw          $zero, 0x54BC($at)
    MEM_W(0X54BC, ctx->r1) = 0;
    // 0x80005DDC: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    // 0x80005DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005DE4: jal         0x80030210
    // 0x80005DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80005DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80005DEC: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80005DF0: beq         $v0, $s3, L_80005E10
    if (ctx->r2 == ctx->r19) {
        // 0x80005DF4: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80005E10;
    }
L_80005DF4:
    // 0x80005DF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005DF8: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    // 0x80005DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005E00: jal         0x80030210
    // 0x80005E04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80005E04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80005E08: bne         $v0, $s3, L_80005DF4
    if (ctx->r2 != ctx->r19) {
        // 0x80005E0C: nop
    
            goto L_80005DF4;
    }
    // 0x80005E0C: nop

L_80005E10:
    // 0x80005E10: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005E14: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80005E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005E1C: jal         0x80030210
    // 0x80005E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80005E24: beq         $v0, $s3, L_80005E44
    if (ctx->r2 == ctx->r19) {
        // 0x80005E28: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80005E44;
    }
L_80005E28:
    // 0x80005E28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005E2C: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80005E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005E34: jal         0x80030210
    // 0x80005E38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80005E38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80005E3C: bne         $v0, $s3, L_80005E28
    if (ctx->r2 != ctx->r19) {
        // 0x80005E40: nop
    
            goto L_80005E28;
    }
    // 0x80005E40: nop

L_80005E44:
    // 0x80005E44: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80005E48: addiu       $s1, $s1, 0x54A0
    ctx->r17 = ADD32(ctx->r17, 0X54A0);
    // 0x80005E4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005E54: jal         0x80030210
    // 0x80005E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80005E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80005E5C: beq         $v0, $s3, L_80005E78
    if (ctx->r2 == ctx->r19) {
        // 0x80005E60: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005E78;
    }
    // 0x80005E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005E64:
    // 0x80005E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005E68: jal         0x80030210
    // 0x80005E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80005E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80005E70: bnel        $v0, $s3, L_80005E64
    if (ctx->r2 != ctx->r19) {
        // 0x80005E74: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005E64;
    }
    goto skip_0;
    // 0x80005E74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80005E78:
    // 0x80005E78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005E7C: sw          $zero, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = 0;
    // 0x80005E80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005E84: sw          $s3, 0x65D4($at)
    MEM_W(0X65D4, ctx->r1) = ctx->r19;
    // 0x80005E88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005E8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005E90: sw          $t6, 0x6630($at)
    MEM_W(0X6630, ctx->r1) = ctx->r14;
    // 0x80005E94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005E98: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80005E9C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80005EA0: sw          $zero, 0x4FA4($at)
    MEM_W(0X4FA4, ctx->r1) = 0;
    // 0x80005EA4: addiu       $v1, $v1, 0x6640
    ctx->r3 = ADD32(ctx->r3, 0X6640);
    // 0x80005EA8: addiu       $v0, $v0, 0x6638
    ctx->r2 = ADD32(ctx->r2, 0X6638);
L_80005EAC:
    // 0x80005EAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005EB0: bne         $v0, $v1, L_80005EAC
    if (ctx->r2 != ctx->r3) {
        // 0x80005EB4: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80005EAC;
    }
    // 0x80005EB4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80005EB8: lhu         $t7, 0x0($s6)
    ctx->r15 = MEM_HU(ctx->r22, 0X0);
    // 0x80005EBC: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x80005EC0: addiu       $fp, $fp, -0x4918
    ctx->r30 = ADD32(ctx->r30, -0X4918);
    // 0x80005EC4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80005EC8: beq         $t8, $zero, L_80006054
    if (ctx->r24 == 0) {
        // 0x80005ECC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80006054;
    }
    // 0x80005ECC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80005ED0: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x80005ED4: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80005ED8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80005EDC: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80005EE0: addiu       $s2, $s2, 0x54B8
    ctx->r18 = ADD32(ctx->r18, 0X54B8);
    // 0x80005EE4: addiu       $s4, $s4, 0x660C
    ctx->r20 = ADD32(ctx->r20, 0X660C);
    // 0x80005EE8: addiu       $s5, $s5, -0x491C
    ctx->r21 = ADD32(ctx->r21, -0X491C);
    // 0x80005EEC: addiu       $fp, $fp, -0x4918
    ctx->r30 = ADD32(ctx->r30, -0X4918);
    // 0x80005EF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80005EF4: addiu       $s7, $zero, 0xB9B
    ctx->r23 = ADD32(0, 0XB9B);
L_80005EF8:
    // 0x80005EF8: jal         0x80005D10
    // 0x80005EFC: nop

    func_80005D10(rdram, ctx);
        goto after_6;
    // 0x80005EFC: nop

    after_6:
    // 0x80005F00: jal         0x80000510
    // 0x80005F04: nop

    syMainVerifyStackProbes(rdram, ctx);
        goto after_7;
    // 0x80005F04: nop

    after_7:
    // 0x80005F08: lhu         $t9, 0x0($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X0);
    // 0x80005F0C: blez        $t9, L_80005F34
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80005F10: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005F34;
    }
    // 0x80005F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005F14:
    // 0x80005F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005F18: jal         0x80030210
    // 0x80005F1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80005F1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80005F20: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x80005F24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80005F28: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80005F2C: bnel        $at, $zero, L_80005F14
    if (ctx->r1 != 0) {
        // 0x80005F30: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005F14;
    }
    goto skip_1;
    // 0x80005F30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_80005F34:
    // 0x80005F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005F3C: jal         0x80030210
    // 0x80005F40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80005F40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80005F44: beq         $v0, $s3, L_80005F60
    if (ctx->r2 == ctx->r19) {
        // 0x80005F48: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005F60;
    }
    // 0x80005F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005F4C:
    // 0x80005F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005F50: jal         0x80030210
    // 0x80005F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80005F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80005F58: bnel        $v0, $s3, L_80005F4C
    if (ctx->r2 != ctx->r19) {
        // 0x80005F5C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005F4C;
    }
    goto skip_2;
    // 0x80005F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
L_80005F60:
    // 0x80005F60: jal         0x80033490
    // 0x80005F64: nop

    osGetCount_recomp(rdram, ctx);
        goto after_11;
    // 0x80005F64: nop

    after_11:
    // 0x80005F68: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80005F6C: lw          $t9, 0x8($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X8);
    // 0x80005F70: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80005F74: jalr        $t9
    // 0x80005F78: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x80005F78: nop

    after_12:
    // 0x80005F7C: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80005F80: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80005F84: jal         0x80033490
    // 0x80005F88: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    osGetCount_recomp(rdram, ctx);
        goto after_13;
    // 0x80005F88: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    after_13:
    // 0x80005F8C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80005F90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005F94: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80005F98: divu        $zero, $t4, $s7
    lo = S32(U32(ctx->r12) / U32(ctx->r23)); hi = S32(U32(ctx->r12) % U32(ctx->r23));
    // 0x80005F9C: mflo        $t5
    ctx->r13 = lo;
    // 0x80005FA0: sw          $t5, 0x6610($at)
    MEM_W(0X6610, ctx->r1) = ctx->r13;
    // 0x80005FA4: bne         $s7, $zero, L_80005FB0
    if (ctx->r23 != 0) {
        // 0x80005FA8: nop
    
            goto L_80005FB0;
    }
    // 0x80005FA8: nop

    // 0x80005FAC: break       7
    do_break(2147508140);
L_80005FB0:
    // 0x80005FB0: jal         0x80005C9C
    // 0x80005FB4: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_14;
    // 0x80005FB4: nop

    after_14:
    // 0x80005FB8: bne         $v0, $zero, L_800061D4
    if (ctx->r2 != 0) {
        // 0x80005FBC: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_800061D4;
    }
    // 0x80005FBC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80005FC0: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80005FC4: lhu         $t7, 0x54BA($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X54BA);
    // 0x80005FC8: divu        $zero, $t6, $t7
    lo = S32(U32(ctx->r14) / U32(ctx->r15)); hi = S32(U32(ctx->r14) % U32(ctx->r15));
    // 0x80005FCC: mfhi        $t8
    ctx->r24 = hi;
    // 0x80005FD0: bne         $t7, $zero, L_80005FDC
    if (ctx->r15 != 0) {
        // 0x80005FD4: nop
    
            goto L_80005FDC;
    }
    // 0x80005FD4: nop

    // 0x80005FD8: break       7
    do_break(2147508184);
L_80005FDC:
    // 0x80005FDC: bne         $t8, $zero, L_8000604C
    if (ctx->r24 != 0) {
        // 0x80005FE0: nop
    
            goto L_8000604C;
    }
    // 0x80005FE0: nop

    // 0x80005FE4: jal         0x80005AE4
    // 0x80005FE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syTaskmanSwitchContext(rdram, ctx);
        goto after_15;
    // 0x80005FE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80005FEC: jal         0x80033490
    // 0x80005FF0: nop

    osGetCount_recomp(rdram, ctx);
        goto after_16;
    // 0x80005FF0: nop

    after_16:
    // 0x80005FF4: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80005FF8: lw          $t9, 0x10($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X10);
    // 0x80005FFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80006000: jalr        $t9
    // 0x80006004: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x80006004: nop

    after_17:
    // 0x80006008: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x8000600C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80006010: jal         0x80033490
    // 0x80006014: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    osGetCount_recomp(rdram, ctx);
        goto after_18;
    // 0x80006014: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    after_18:
    // 0x80006018: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8000601C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006020: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80006024: divu        $zero, $t3, $s7
    lo = S32(U32(ctx->r11) / U32(ctx->r23)); hi = S32(U32(ctx->r11) % U32(ctx->r23));
    // 0x80006028: mflo        $t4
    ctx->r12 = lo;
    // 0x8000602C: sw          $t4, 0x6614($at)
    MEM_W(0X6614, ctx->r1) = ctx->r12;
    // 0x80006030: bne         $s7, $zero, L_8000603C
    if (ctx->r23 != 0) {
        // 0x80006034: nop
    
            goto L_8000603C;
    }
    // 0x80006034: nop

    // 0x80006038: break       7
    do_break(2147508280);
L_8000603C:
    // 0x8000603C: jal         0x80005C9C
    // 0x80006040: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_19;
    // 0x80006040: nop

    after_19:
    // 0x80006044: bne         $v0, $zero, L_800061D4
    if (ctx->r2 != 0) {
        // 0x80006048: nop
    
            goto L_800061D4;
    }
    // 0x80006048: nop

L_8000604C:
    // 0x8000604C: b           L_80005EF8
    // 0x80006050: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80005EF8;
    // 0x80006050: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80006054:
    // 0x80006054: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80006058: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8000605C: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80006060: addiu       $s2, $s2, 0x54B8
    ctx->r18 = ADD32(ctx->r18, 0X54B8);
    // 0x80006064: addiu       $s4, $s4, 0x660C
    ctx->r20 = ADD32(ctx->r20, 0X660C);
    // 0x80006068: addiu       $s5, $s5, -0x491C
    ctx->r21 = ADD32(ctx->r21, -0X491C);
    // 0x8000606C: addiu       $s7, $zero, 0xB9B
    ctx->r23 = ADD32(0, 0XB9B);
L_80006070:
    // 0x80006070: jal         0x80005D10
    // 0x80006074: nop

    func_80005D10(rdram, ctx);
        goto after_20;
    // 0x80006074: nop

    after_20:
    // 0x80006078: jal         0x80000510
    // 0x8000607C: nop

    syMainVerifyStackProbes(rdram, ctx);
        goto after_21;
    // 0x8000607C: nop

    after_21:
    // 0x80006080: lhu         $t5, 0x0($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X0);
    // 0x80006084: blez        $t5, L_800060AC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80006088: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800060AC;
    }
    // 0x80006088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000608C:
    // 0x8000608C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006090: jal         0x80030210
    // 0x80006094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_22;
    // 0x80006094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80006098: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    // 0x8000609C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800060A0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800060A4: bnel        $at, $zero, L_8000608C
    if (ctx->r1 != 0) {
        // 0x800060A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000608C;
    }
    goto skip_3;
    // 0x800060A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_800060AC:
    // 0x800060AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800060B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800060B4: jal         0x80030210
    // 0x800060B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_23;
    // 0x800060B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x800060BC: beq         $v0, $s3, L_800060D8
    if (ctx->r2 == ctx->r19) {
        // 0x800060C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800060D8;
    }
    // 0x800060C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800060C4:
    // 0x800060C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800060C8: jal         0x80030210
    // 0x800060CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_24;
    // 0x800060CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x800060D0: bnel        $v0, $s3, L_800060C4
    if (ctx->r2 != ctx->r19) {
        // 0x800060D4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800060C4;
    }
    goto skip_4;
    // 0x800060D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
L_800060D8:
    // 0x800060D8: jal         0x80033490
    // 0x800060DC: nop

    osGetCount_recomp(rdram, ctx);
        goto after_25;
    // 0x800060DC: nop

    after_25:
    // 0x800060E0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x800060E4: lw          $t9, 0x8($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X8);
    // 0x800060E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800060EC: jalr        $t9
    // 0x800060F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_26;
    // 0x800060F0: nop

    after_26:
    // 0x800060F4: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800060F8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800060FC: jal         0x80033490
    // 0x80006100: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    osGetCount_recomp(rdram, ctx);
        goto after_27;
    // 0x80006100: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    after_27:
    // 0x80006104: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80006108: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000610C: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80006110: divu        $zero, $t1, $s7
    lo = S32(U32(ctx->r9) / U32(ctx->r23)); hi = S32(U32(ctx->r9) % U32(ctx->r23));
    // 0x80006114: mflo        $t2
    ctx->r10 = lo;
    // 0x80006118: sw          $t2, 0x6610($at)
    MEM_W(0X6610, ctx->r1) = ctx->r10;
    // 0x8000611C: bne         $s7, $zero, L_80006128
    if (ctx->r23 != 0) {
        // 0x80006120: nop
    
            goto L_80006128;
    }
    // 0x80006120: nop

    // 0x80006124: break       7
    do_break(2147508516);
L_80006128:
    // 0x80006128: jal         0x80005C9C
    // 0x8000612C: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_28;
    // 0x8000612C: nop

    after_28:
    // 0x80006130: bne         $v0, $zero, L_800061D4
    if (ctx->r2 != 0) {
        // 0x80006134: lui         $t4, 0x8004
        ctx->r12 = S32(0X8004 << 16);
            goto L_800061D4;
    }
    // 0x80006134: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80006138: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8000613C: lhu         $t4, 0x54BA($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X54BA);
    // 0x80006140: divu        $zero, $t3, $t4
    lo = S32(U32(ctx->r11) / U32(ctx->r12)); hi = S32(U32(ctx->r11) % U32(ctx->r12));
    // 0x80006144: mfhi        $t5
    ctx->r13 = hi;
    // 0x80006148: bne         $t4, $zero, L_80006154
    if (ctx->r12 != 0) {
        // 0x8000614C: nop
    
            goto L_80006154;
    }
    // 0x8000614C: nop

    // 0x80006150: break       7
    do_break(2147508560);
L_80006154:
    // 0x80006154: bne         $t5, $zero, L_800061CC
    if (ctx->r13 != 0) {
        // 0x80006158: nop
    
            goto L_800061CC;
    }
    // 0x80006158: nop

    // 0x8000615C: jal         0x80005AE4
    // 0x80006160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    syTaskmanSwitchContext(rdram, ctx);
        goto after_29;
    // 0x80006160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x80006164: beq         $v0, $zero, L_800061CC
    if (ctx->r2 == 0) {
        // 0x80006168: nop
    
            goto L_800061CC;
    }
    // 0x80006168: nop

    // 0x8000616C: jal         0x80033490
    // 0x80006170: nop

    osGetCount_recomp(rdram, ctx);
        goto after_30;
    // 0x80006170: nop

    after_30:
    // 0x80006174: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80006178: lw          $t9, 0x10($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X10);
    // 0x8000617C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80006180: jalr        $t9
    // 0x80006184: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_31;
    // 0x80006184: nop

    after_31:
    // 0x80006188: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8000618C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80006190: jal         0x80033490
    // 0x80006194: sw          $t7, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r15;
    osGetCount_recomp(rdram, ctx);
        goto after_32;
    // 0x80006194: sw          $t7, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r15;
    after_32:
    // 0x80006198: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8000619C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800061A0: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x800061A4: divu        $zero, $t0, $s7
    lo = S32(U32(ctx->r8) / U32(ctx->r23)); hi = S32(U32(ctx->r8) % U32(ctx->r23));
    // 0x800061A8: mflo        $t1
    ctx->r9 = lo;
    // 0x800061AC: sw          $t1, 0x6614($at)
    MEM_W(0X6614, ctx->r1) = ctx->r9;
    // 0x800061B0: bne         $s7, $zero, L_800061BC
    if (ctx->r23 != 0) {
        // 0x800061B4: nop
    
            goto L_800061BC;
    }
    // 0x800061B4: nop

    // 0x800061B8: break       7
    do_break(2147508664);
L_800061BC:
    // 0x800061BC: jal         0x80005C9C
    // 0x800061C0: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_33;
    // 0x800061C0: nop

    after_33:
    // 0x800061C4: bne         $v0, $zero, L_800061D4
    if (ctx->r2 != 0) {
        // 0x800061C8: nop
    
            goto L_800061D4;
    }
    // 0x800061C8: nop

L_800061CC:
    // 0x800061CC: b           L_80006070
    // 0x800061D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80006070;
    // 0x800061D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800061D4:
    // 0x800061D4: jal         0x80005BFC
    // 0x800061D8: nop

    func_80005BFC(rdram, ctx);
        goto after_34;
    // 0x800061D8: nop

    after_34:
    // 0x800061DC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800061E0: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    // 0x800061E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800061E8: jal         0x80030210
    // 0x800061EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_35;
    // 0x800061EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x800061F0: beq         $v0, $s3, L_80006210
    if (ctx->r2 == ctx->r19) {
        // 0x800061F4: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80006210;
    }
L_800061F4:
    // 0x800061F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800061F8: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    // 0x800061FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006200: jal         0x80030210
    // 0x80006204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_36;
    // 0x80006204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_36:
    // 0x80006208: bne         $v0, $s3, L_800061F4
    if (ctx->r2 != ctx->r19) {
        // 0x8000620C: nop
    
            goto L_800061F4;
    }
    // 0x8000620C: nop

L_80006210:
    // 0x80006210: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006214: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80006218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000621C: jal         0x80030210
    // 0x80006220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_37;
    // 0x80006220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80006224: beq         $v0, $s3, L_80006244
    if (ctx->r2 == ctx->r19) {
        // 0x80006228: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80006244;
    }
L_80006228:
    // 0x80006228: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000622C: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80006230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006234: jal         0x80030210
    // 0x80006238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_38;
    // 0x80006238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x8000623C: bne         $v0, $s3, L_80006228
    if (ctx->r2 != ctx->r19) {
        // 0x80006240: nop
    
            goto L_80006228;
    }
    // 0x80006240: nop

L_80006244:
    // 0x80006244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80006248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000624C: jal         0x80030210
    // 0x80006250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_39;
    // 0x80006250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_39:
    // 0x80006254: beq         $v0, $s3, L_80006270
    if (ctx->r2 == ctx->r19) {
        // 0x80006258: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80006270;
    }
    // 0x80006258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000625C:
    // 0x8000625C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006260: jal         0x80030210
    // 0x80006264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_40;
    // 0x80006264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_40:
    // 0x80006268: bnel        $v0, $s3, L_8000625C
    if (ctx->r2 != ctx->r19) {
        // 0x8000626C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000625C;
    }
    goto skip_5;
    // 0x8000626C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
L_80006270:
    // 0x80006270: jal         0x80007168
    // 0x80006274: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syRdpSetFuncLights(rdram, ctx);
        goto after_41;
    // 0x80006274: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_41:
    // 0x80006278: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000627C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80006280: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006288: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000628C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006290: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80006294: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80006298: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000629C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800062A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800062A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800062A8: sw          $t2, 0x54BC($at)
    MEM_W(0X54BC, ctx->r1) = ctx->r10;
    // 0x800062AC: jr          $ra
    // 0x800062B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800062B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void scStaffrollJobAndNameInitStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133A14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80133A18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80133A1C: jal         0x80133618
    // 0x80133A20: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    SCStaffrollNameUpdateAlloc(rdram, ctx);
        goto after_0;
    // 0x80133A20: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80133A24: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80133A28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80133A2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80133A30: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80133A34: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80133A38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133A3C: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80133A40: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80133A44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133A48: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80133A4C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80133A50: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80133A54: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80133A58: lw          $t8, -0x5748($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5748);
    // 0x80133A5C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133A60: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80133A64: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80133A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133A70: jr          $ra
    // 0x80133A74: nop

    return;
    // 0x80133A74: nop

;}
RECOMP_FUNC void mpCommonCheckFighterLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE6B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE6BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE6C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE6C4: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE6C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DE6CC: jal         0x800DA034
    // 0x800DE6D0: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE6D0: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE6D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE6DC: jr          $ra
    // 0x800DE6E0: nop

    return;
    // 0x800DE6E0: nop

;}
RECOMP_FUNC void ftCommonGuardUpdateShieldVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148304: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80148308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014830C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80148310: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80148314: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80148318: lw          $t7, 0x18C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18C);
    // 0x8014831C: sll         $t9, $t7, 26
    ctx->r25 = S32(ctx->r15 << 26);
    // 0x80148320: bgezl       $t9, L_801483F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80148324: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801483F8;
    }
    goto skip_0;
    // 0x80148324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80148328: lw          $v0, 0xB1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB1C);
    // 0x8014832C: beq         $v0, $zero, L_80148354
    if (ctx->r2 == 0) {
        // 0x80148330: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80148354;
    }
    // 0x80148330: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80148334: bne         $t0, $zero, L_80148354
    if (ctx->r8 != 0) {
        // 0x80148338: sw          $t0, 0xB1C($s0)
        MEM_W(0XB1C, ctx->r16) = ctx->r8;
            goto L_80148354;
    }
    // 0x80148338: sw          $t0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r8;
    // 0x8014833C: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80148340: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80148344: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80148348: beq         $t3, $zero, L_8014837C
    if (ctx->r11 == 0) {
        // 0x8014834C: sw          $t3, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r11;
            goto L_8014837C;
    }
    // 0x8014834C: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x80148350: sw          $t5, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r13;
L_80148354:
    // 0x80148354: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x80148358: beq         $v0, $zero, L_80148368
    if (ctx->r2 == 0) {
        // 0x8014835C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80148368;
    }
    // 0x8014835C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80148360: sw          $t6, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r14;
    // 0x80148364: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80148368:
    // 0x80148368: bnel        $v0, $zero, L_801483F8
    if (ctx->r2 != 0) {
        // 0x8014836C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801483F8;
    }
    goto skip_1;
    // 0x8014836C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80148370: lw          $t7, 0xB24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB24);
    // 0x80148374: beql        $t7, $zero, L_801483F8
    if (ctx->r15 == 0) {
        // 0x80148378: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801483F8;
    }
    goto skip_2;
    // 0x80148378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8014837C:
    // 0x8014837C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80148380: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148384: bne         $t8, $at, L_801483E0
    if (ctx->r24 != ctx->r1) {
        // 0x80148388: nop
    
            goto L_801483E0;
    }
    // 0x80148388: nop

    // 0x8014838C: jal         0x800E8ECC
    // 0x80148390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftParamResetModelPartAll(rdram, ctx);
        goto after_0;
    // 0x80148390: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x80148394: jal         0x801482E4
    // 0x80148398: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftCommonGuardOffSetHitStatusYoshi(rdram, ctx);
        goto after_1;
    // 0x80148398: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8014839C: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x801483A0: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x801483A4: addiu       $t2, $t2, -0x7940
    ctx->r10 = ADD32(ctx->r10, -0X7940);
    // 0x801483A8: sll         $t1, $t9, 27
    ctx->r9 = S32(ctx->r25 << 27);
    // 0x801483AC: bgez        $t1, L_801483E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801483B0: nop
    
            goto L_801483E0;
    }
    // 0x801483B0: nop

    // 0x801483B4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801483B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801483BC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x801483C0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801483C4: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x801483C8: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801483CC: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x801483D0: jal         0x800EDF24
    // 0x801483D4: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_2;
    // 0x801483D4: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    after_2:
    // 0x801483D8: jal         0x801041A0
    // 0x801483DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_3;
    // 0x801483DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
L_801483E0:
    // 0x801483E0: jal         0x800E9C3C
    // 0x801483E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftParamProcStopEffect(rdram, ctx);
        goto after_4;
    // 0x801483E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x801483E8: lbu         $t5, 0x18F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X18F);
    // 0x801483EC: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x801483F0: sb          $t6, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r14;
    // 0x801483F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801483F8:
    // 0x801483F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801483FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80148400: jr          $ra
    // 0x80148404: nop

    return;
    // 0x80148404: nop

;}
RECOMP_FUNC void ftCommonTaruCannShootFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144038: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8014403C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80144040: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80144044: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80144048: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8014404C: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x80144050: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80144054: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80144058: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8014405C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80144060: addiu       $t8, $t8, 0x14
    ctx->r24 = ADD32(ctx->r24, 0X14);
    // 0x80144064: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80144068: addiu       $t2, $t2, 0xBC
    ctx->r10 = ADD32(ctx->r10, 0XBC);
    // 0x8014406C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80144070: swc1        $f4, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f4.u32l;
    // 0x80144074: addu        $v1, $t9, $t2
    ctx->r3 = ADD32(ctx->r25, ctx->r10);
    // 0x80144078: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8014407C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80144080: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80144084: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80144088: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8014408C: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x80144090: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80144094: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80144098: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8014409C: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x801440A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801440A4: lwc1        $f6, 0x68($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X68);
    // 0x801440A8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x801440AC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801440B0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801440B4: jal         0x800E9FC0
    // 0x801440B8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    ftParamGetGroundHazardKnockback(rdram, ctx);
        goto after_0;
    // 0x801440B8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801440BC: jal         0x8010A12C
    // 0x801440C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    grJungleTaruCannGetRotate(rdram, ctx);
        goto after_1;
    // 0x801440C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801440C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801440C8: lwc1        $f8, -0x3EC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3EC0);
    // 0x801440CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801440D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801440D4: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801440D8: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x801440DC: addiu       $t1, $zero, 0x168
    ctx->r9 = ADD32(0, 0X168);
    // 0x801440E0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x801440E4: negu        $t3, $t0
    ctx->r11 = SUB32(0, ctx->r8);
    // 0x801440E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801440EC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801440F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801440F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801440F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801440FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80144100: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80144104: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80144108: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014410C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80144110: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80144114: nop

    // 0x80144118: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014411C: mflo        $v0
    ctx->r2 = lo;
    // 0x80144120: addiu       $v0, $v0, 0x5A
    ctx->r2 = ADD32(ctx->r2, 0X5A);
    // 0x80144124: nop

    // 0x80144128: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x8014412C: mflo        $t4
    ctx->r12 = lo;
    // 0x80144130: bne         $t1, $zero, L_8014413C
    if (ctx->r9 != 0) {
        // 0x80144134: nop
    
            goto L_8014413C;
    }
    // 0x80144134: nop

    // 0x80144138: break       7
    do_break(2148811064);
L_8014413C:
    // 0x8014413C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80144140: bne         $t1, $at, L_80144154
    if (ctx->r9 != ctx->r1) {
        // 0x80144144: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80144154;
    }
    // 0x80144144: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80144148: bne         $v0, $at, L_80144154
    if (ctx->r2 != ctx->r1) {
        // 0x8014414C: nop
    
            goto L_80144154;
    }
    // 0x8014414C: nop

    // 0x80144150: break       6
    do_break(2148811088);
L_80144154:
    // 0x80144154: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144158: mflo        $t5
    ctx->r13 = lo;
    // 0x8014415C: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80144160: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80144164: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80144168: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8014416C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80144170: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80144174: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80144178: jal         0x80140EE4
    // 0x8014417C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_2;
    // 0x8014417C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_2:
    // 0x80144180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80144184: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80144188: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8014418C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80144190: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144194: jal         0x800EAA2C
    // 0x80144198: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_3;
    // 0x80144198: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x8014419C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801441A0: sw          $zero, 0x174($s0)
    MEM_W(0X174, ctx->r16) = 0;
    // 0x801441A4: sw          $t2, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->r10;
    // 0x801441A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801441AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801441B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801441B4: jr          $ra
    // 0x801441B8: nop

    return;
    // 0x801441B8: nop

;}
RECOMP_FUNC void ftCommonLiftTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014620C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80146210: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80146214: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80146218: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014621C: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    // 0x80146220: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80146224: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80146228: jal         0x800E6F24
    // 0x8014622C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014622C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80146230: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80146234: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80146238: addiu       $t8, $t8, 0x5D28
    ctx->r24 = ADD32(ctx->r24, 0X5D28);
    // 0x8014623C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80146240: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    // 0x80146244: jal         0x80146130
    // 0x80146248: sw          $t9, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r25;
    ftCommonLiftTurnUpdateModelYaw(rdram, ctx);
        goto after_1;
    // 0x80146248: sw          $t9, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r25;
    after_1:
    // 0x8014624C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80146250: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80146254: jr          $ra
    // 0x80146258: nop

    return;
    // 0x80146258: nop

;}
RECOMP_FUNC void sc1PIntroMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132668: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013266C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132670: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132674: addiu       $t7, $t7, 0x4F60
    ctx->r15 = ADD32(ctx->r15, 0X4F60);
    // 0x80132678: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013267C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132680: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132684: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80132688: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8013268C: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
L_80132690:
    // 0x80132690: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132694: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132698: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013269C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801326A0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801326A4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801326A8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801326AC: bne         $t7, $t0, L_80132690
    if (ctx->r15 != ctx->r8) {
        // 0x801326B0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132690;
    }
    // 0x801326B0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801326B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801326B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326BC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x801326C0: jal         0x80009968
    // 0x801326C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801326C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x801326C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326CC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801326D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801326D4: sw          $v0, 0x5C30($at)
    MEM_W(0X5C30, ctx->r1) = ctx->r2;
    // 0x801326D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801326DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801326E0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801326E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326E8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801326EC: jal         0x80009DF4
    // 0x801326F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801326F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x801326F4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801326F8: lw          $t2, 0x5CC8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5CC8);
    // 0x801326FC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132700: lw          $t5, 0x605C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X605C);
    // 0x80132704: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80132708: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8013270C: lw          $t4, 0x28($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X28);
    // 0x80132710: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132714: jal         0x800CCFDC
    // 0x80132718: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132718: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8013271C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132720: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80132724: sb          $s0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r16;
    // 0x80132728: andi        $t6, $t0, 0xFFDF
    ctx->r14 = ctx->r8 & 0XFFDF;
    // 0x8013272C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132730: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x80132734: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132738: sb          $s0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r16;
    // 0x8013273C: sb          $s0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r16;
    // 0x80132740: jal         0x80132634
    // 0x80132744: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    sc1PIntroGetAlliesNum(rdram, ctx);
        goto after_3;
    // 0x80132744: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x80132748: beq         $v0, $zero, L_80132828
    if (ctx->r2 == 0) {
        // 0x8013274C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80132828;
    }
    // 0x8013274C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132750: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132754: lw          $t9, 0x6058($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6058);
    // 0x80132758: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8013275C: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x80132760: jal         0x800CCFDC
    // 0x80132764: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132764: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_4:
    // 0x80132768: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x8013276C: sb          $s0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r16;
    // 0x80132770: sb          $s0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r16;
    // 0x80132774: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132778: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013277C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132780: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132784: sb          $s0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r16;
    // 0x80132788: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013278C: lw          $t0, 0x5CD8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5CD8);
    // 0x80132790: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132794: lw          $t8, 0x605C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X605C);
    // 0x80132798: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8013279C: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x801327A0: lw          $t6, 0x28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X28);
    // 0x801327A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801327A8: jal         0x800CCFDC
    // 0x801327AC: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801327AC: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    after_5:
    // 0x801327B0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801327B4: sb          $s0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r16;
    // 0x801327B8: sb          $s0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r16;
    // 0x801327BC: andi        $t2, $t9, 0xFFDF
    ctx->r10 = ctx->r25 & 0XFFDF;
    // 0x801327C0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801327C4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801327C8: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801327CC: sb          $s0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r16;
    // 0x801327D0: jal         0x80132634
    // 0x801327D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    sc1PIntroGetAlliesNum(rdram, ctx);
        goto after_6;
    // 0x801327D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_6:
    // 0x801327D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801327DC: bne         $v0, $at, L_80132828
    if (ctx->r2 != ctx->r1) {
        // 0x801327E0: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80132828;
    }
    // 0x801327E0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801327E4: lw          $t4, 0x5CE8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5CE8);
    // 0x801327E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801327EC: lw          $t7, 0x605C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X605C);
    // 0x801327F0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801327F4: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x801327F8: lw          $t0, 0x28($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X28);
    // 0x801327FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132800: jal         0x800CCFDC
    // 0x80132804: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80132804: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_7:
    // 0x80132808: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x8013280C: sb          $s0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r16;
    // 0x80132810: sb          $s0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r16;
    // 0x80132814: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x80132818: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x8013281C: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80132820: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132824: sb          $s0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r16;
L_80132828:
    // 0x80132828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013282C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132830: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132834: jr          $ra
    // 0x80132838: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80132838: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void dbBattleActorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013223C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80132240: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132244: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132248: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013224C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80132250: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80132254: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80132258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013225C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132260: addiu       $s3, $s3, 0x3130
    ctx->r19 = ADD32(ctx->r19, 0X3130);
    // 0x80132264: addiu       $s1, $s1, 0x3110
    ctx->r17 = ADD32(ctx->r17, 0X3110);
    // 0x80132268: addiu       $s0, $s0, 0x4D08
    ctx->r16 = ADD32(ctx->r16, 0X4D08);
    // 0x8013226C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80132270:
    // 0x80132270: lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X26);
    // 0x80132274: lbu         $t6, 0x1($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1);
    // 0x80132278: beql        $v0, $t6, L_801322B8
    if (ctx->r2 == ctx->r14) {
        // 0x8013227C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_801322B8;
    }
    goto skip_0;
    // 0x8013227C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    skip_0:
    // 0x80132280: bne         $s2, $v0, L_80132298
    if (ctx->r18 != ctx->r2) {
        // 0x80132284: nop
    
            goto L_80132298;
    }
    // 0x80132284: nop

    // 0x80132288: jal         0x800EC11C
    // 0x8013228C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftParamGetCostumeDebug(rdram, ctx);
        goto after_0;
    // 0x8013228C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_0:
    // 0x80132290: b           L_801322B4
    // 0x80132294: sb          $v0, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r2;
        goto L_801322B4;
    // 0x80132294: sb          $v0, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r2;
L_80132298:
    // 0x80132298: jal         0x800EC11C
    // 0x8013229C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftParamGetCostumeDebug(rdram, ctx);
        goto after_1;
    // 0x8013229C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_1:
    // 0x801322A0: lbu         $t7, 0x26($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X26);
    // 0x801322A4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801322A8: beql        $at, $zero, L_801322B8
    if (ctx->r1 == 0) {
        // 0x801322AC: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_801322B8;
    }
    goto skip_1;
    // 0x801322AC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    skip_1:
    // 0x801322B0: sb          $zero, 0x26($s0)
    MEM_B(0X26, ctx->r16) = 0;
L_801322B4:
    // 0x801322B4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_801322B8:
    // 0x801322B8: bne         $s1, $s3, L_80132270
    if (ctx->r17 != ctx->r19) {
        // 0x801322BC: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_80132270;
    }
    // 0x801322BC: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x801322C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801322C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801322C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801322CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801322D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801322D4: jr          $ra
    // 0x801322D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801322D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_8037CAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CAF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037CAF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037CAF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037CAFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037CB00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037CB04: bne         $a0, $zero, L_8037CB1C
    if (ctx->r4 != 0) {
        // 0x8037CB08: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037CB1C;
    }
    // 0x8037CB08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037CB0C: jal         0x803717A0
    // 0x8037CB10: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037CB10: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x8037CB14: beq         $v0, $zero, L_8037CB8C
    if (ctx->r2 == 0) {
        // 0x8037CB18: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037CB8C;
    }
    // 0x8037CB18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037CB1C:
    // 0x8037CB1C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8037CB20: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x8037CB24: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x8037CB28: bnel        $t6, $zero, L_8037CB4C
    if (ctx->r14 != 0) {
        // 0x8037CB2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037CB4C;
    }
    goto skip_0;
    // 0x8037CB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8037CB30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037CB34: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8037CB38: jal         0x803717E0
    // 0x8037CB3C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037CB3C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037CB40: jal         0x8037C2D0
    // 0x8037CB44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037CB44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037CB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037CB4C:
    // 0x8037CB4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037CB50: jal         0x80373C10
    // 0x8037CB54: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_80373C10(rdram, ctx);
        goto after_3;
    // 0x8037CB54: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037CB58: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037CB5C: addiu       $t7, $t7, -0x5B60
    ctx->r15 = ADD32(ctx->r15, -0X5B60);
    // 0x8037CB60: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x8037CB64: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8037CB68: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037CB6C: addiu       $t8, $t8, -0x5A88
    ctx->r24 = ADD32(ctx->r24, -0X5A88);
    // 0x8037CB70: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8037CB74: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037CB78: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037CB7C: addiu       $t0, $t0, -0x5930
    ctx->r8 = ADD32(ctx->r8, -0X5930);
    // 0x8037CB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037CB84: jal         0x8037CE30
    // 0x8037CB88: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    func_ovl8_8037CE30(rdram, ctx);
        goto after_4;
    // 0x8037CB88: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    after_4:
L_8037CB8C:
    // 0x8037CB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037CB90: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037CB94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037CB98: jr          $ra
    // 0x8037CB9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037CB9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ifCommonPlayerDamageUpdateDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E8F4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8010E8F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010E8FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010E900: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8010E904: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8010E908: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8010E90C: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8010E910: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8010E914: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8010E918: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010E91C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8010E920: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010E924: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8010E928: lw          $t4, 0x6C($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X6C);
    // 0x8010E92C: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8010E930: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8010E934: slti        $at, $t4, 0x3E8
    ctx->r1 = SIGNED(ctx->r12) < 0X3E8 ? 1 : 0;
    // 0x8010E938: bne         $at, $zero, L_8010E944
    if (ctx->r1 != 0) {
        // 0x8010E93C: or          $a2, $t4, $zero
        ctx->r6 = ctx->r12 | 0;
            goto L_8010E944;
    }
    // 0x8010E93C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8010E940: addiu       $a2, $zero, 0x3E7
    ctx->r6 = ADD32(0, 0X3E7);
L_8010E944:
    // 0x8010E944: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8010E948: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8010E94C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8010E950: addiu       $t5, $t5, 0x1598
    ctx->r13 = ADD32(ctx->r13, 0X1598);
    // 0x8010E954: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8010E958: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x8010E95C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8010E960: lwc1        $f14, 0xC($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8010E964: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010E968: subu        $v0, $t4, $t6
    ctx->r2 = SUB32(ctx->r12, ctx->r14);
    // 0x8010E96C: bne         $v0, $zero, L_8010E994
    if (ctx->r2 != 0) {
        // 0x8010E970: nop
    
            goto L_8010E994;
    }
    // 0x8010E970: nop

    // 0x8010E974: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010E978: nop

    // 0x8010E97C: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x8010E980: nop

    // 0x8010E984: bc1fl       L_8010E9DC
    if (!c1cs) {
        // 0x8010E988: lw          $t3, 0x8($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X8);
            goto L_8010E9DC;
    }
    goto skip_0;
    // 0x8010E988: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    skip_0:
    // 0x8010E98C: b           L_8010EC40
    // 0x8010E990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8010EC40;
    // 0x8010E990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010E994:
    // 0x8010E994: bgez        $v0, L_8010E9A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8010E998: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8010E9A8;
    }
    // 0x8010E998: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010E99C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8010E9A0: b           L_8010E9DC
    // 0x8010E9A4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
        goto L_8010E9DC;
    // 0x8010E9A4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
L_8010E9A8:
    // 0x8010E9A8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8010E9AC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010E9B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010E9B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E9B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010E9BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010E9C0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8010E9C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8010E9C8: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8010E9CC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010E9D0: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x8010E9D4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8010E9D8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
L_8010E9DC:
    // 0x8010E9DC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8010E9E0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8010E9E4: beq         $t3, $zero, L_8010E9F4
    if (ctx->r11 == 0) {
        // 0x8010E9E8: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_8010E9F4;
    }
    // 0x8010E9E8: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x8010E9EC: b           L_8010E9F8
    // 0x8010E9F0: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
        goto L_8010E9F8;
    // 0x8010E9F0: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
L_8010E9F4:
    // 0x8010E9F4: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
L_8010E9F8:
    // 0x8010E9F8: lbu         $t5, 0x23($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X23);
    // 0x8010E9FC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8010EA00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010EA04: bne         $t5, $at, L_8010EA64
    if (ctx->r13 != ctx->r1) {
        // 0x8010EA08: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8010EA64;
    }
    // 0x8010EA08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8010EA0C: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8010EA10: subu        $a0, $t6, $a2
    ctx->r4 = SUB32(ctx->r14, ctx->r6);
    // 0x8010EA14: bgez        $a0, L_8010EA20
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8010EA18: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_8010EA20;
    }
    // 0x8010EA18: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x8010EA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8010EA20:
    // 0x8010EA20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010EA24: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x8010EA28: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8010EA2C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8010EA30: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8010EA34: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8010EA38: jal         0x8010E808
    // 0x8010EA3C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    ifCommonPlayerDamageGetHitPointsArrayID(rdram, ctx);
        goto after_0;
    // 0x8010EA3C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8010EA40: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8010EA44: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8010EA48: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8010EA4C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8010EA50: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8010EA54: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010EA58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8010EA5C: b           L_8010EAA0
    // 0x8010EA60: sb          $v0, 0x66($t1)
    MEM_B(0X66, ctx->r9) = ctx->r2;
        goto L_8010EAA0;
    // 0x8010EA60: sb          $v0, 0x66($t1)
    MEM_B(0X66, ctx->r9) = ctx->r2;
L_8010EA64:
    // 0x8010EA64: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x8010EA68: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8010EA6C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8010EA70: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8010EA74: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8010EA78: jal         0x8010E7D4
    // 0x8010EA7C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    ifCommonPlayerDamageGetPercentArrayID(rdram, ctx);
        goto after_1;
    // 0x8010EA7C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8010EA80: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8010EA84: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8010EA88: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8010EA8C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8010EA90: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8010EA94: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010EA98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8010EA9C: sb          $v0, 0x66($t1)
    MEM_B(0X66, ctx->r9) = ctx->r2;
L_8010EAA0:
    // 0x8010EAA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8010EAA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010EAA8: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x8010EAAC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8010EAB0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8010EAB4: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8010EAB8: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8010EABC: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8010EAC0: jal         0x8010E83C
    // 0x8010EAC4: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    ifCommonPlayerDamageGetDigitOffset(rdram, ctx);
        goto after_2;
    // 0x8010EAC4: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8010EAC8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8010EACC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010EAD0: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8010EAD4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010EAD8: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010EADC: addiu       $t0, $t0, 0x1580
    ctx->r8 = ADD32(ctx->r8, 0X1580);
    // 0x8010EAE0: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x8010EAE4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8010EAE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010EAEC: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010EAF0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010EAF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010EAF8: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010EAFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010EB00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010EB04: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8010EB08: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8010EB0C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8010EB10: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8010EB14: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8010EB18: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8010EB1C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8010EB20: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8010EB24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010EB28: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8010EB2C: addiu       $a3, $zero, -0x5
    ctx->r7 = ADD32(0, -0X5);
    // 0x8010EB30: bc1f        L_8010EB5C
    if (!c1cs) {
        // 0x8010EB34: add.s       $f2, $f6, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f18.fl;
            goto L_8010EB5C;
    }
    // 0x8010EB34: add.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8010EB38: bne         $t2, $zero, L_8010EB5C
    if (ctx->r10 != 0) {
        // 0x8010EB3C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8010EB5C;
    }
    // 0x8010EB3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010EB40: lwc1        $f4, 0xC60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC60);
    // 0x8010EB44: sub.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8010EB48: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8010EB4C: nop

    // 0x8010EB50: bc1fl       L_8010EB60
    if (!c1cs) {
        // 0x8010EB54: lw          $t7, 0x74($t6)
        ctx->r15 = MEM_W(ctx->r14, 0X74);
            goto L_8010EB60;
    }
    goto skip_1;
    // 0x8010EB54: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    skip_1:
    // 0x8010EB58: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8010EB5C:
    // 0x8010EB5C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
L_8010EB60:
    // 0x8010EB60: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    // 0x8010EB64: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010EB68: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x8010EB6C: addiu       $a2, $a2, -0x1410
    ctx->r6 = ADD32(ctx->r6, -0X1410);
    // 0x8010EB70: beq         $a0, $zero, L_8010EC0C
    if (ctx->r4 == 0) {
        // 0x8010EB74: nop
    
            goto L_8010EC0C;
    }
    // 0x8010EB74: nop

L_8010EB78:
    // 0x8010EB78: bgez        $a1, L_8010EB90
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8010EB7C: addu        $t5, $s0, $a1
        ctx->r13 = ADD32(ctx->r16, ctx->r5);
            goto L_8010EB90;
    }
    // 0x8010EB7C: addu        $t5, $s0, $a1
    ctx->r13 = ADD32(ctx->r16, ctx->r5);
    // 0x8010EB80: lhu         $t8, 0x24($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X24);
    // 0x8010EB84: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8010EB88: b           L_8010EBFC
    // 0x8010EB8C: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
        goto L_8010EBFC;
    // 0x8010EB8C: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
L_8010EB90:
    // 0x8010EB90: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    // 0x8010EB94: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8010EB98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8010EB9C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8010EBA0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8010EBA4: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x8010EBA8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8010EBAC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8010EBB0: nop

    // 0x8010EBB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010EBB8: mul.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010EBBC: nop

    // 0x8010EBC0: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8010EBC4: sub.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8010EBC8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8010EBCC: lhu         $t9, 0xC($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0XC);
    // 0x8010EBD0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8010EBD4: bgez        $t9, L_8010EBE8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8010EBD8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8010EBE8;
    }
    // 0x8010EBD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010EBDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010EBE0: nop

    // 0x8010EBE4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8010EBE8:
    // 0x8010EBE8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8010EBEC: lhu         $t5, 0x24($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X24);
    // 0x8010EBF0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8010EBF4: and         $t6, $t5, $a3
    ctx->r14 = ctx->r13 & ctx->r7;
    // 0x8010EBF8: sh          $t6, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r14;
L_8010EBFC:
    // 0x8010EBFC: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x8010EC00: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8010EC04: bne         $a0, $zero, L_8010EB78
    if (ctx->r4 != 0) {
        // 0x8010EC08: nop
    
            goto L_8010EB78;
    }
    // 0x8010EC08: nop

L_8010EC0C:
    // 0x8010EC0C: blez        $t2, L_8010EC18
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8010EC10: nop
    
            goto L_8010EC18;
    }
    // 0x8010EC10: nop

    // 0x8010EC14: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_8010EC18:
    // 0x8010EC18: blezl       $t3, L_8010EC28
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8010EC1C: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8010EC28;
    }
    goto skip_2;
    // 0x8010EC1C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x8010EC20: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8010EC24: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_8010EC28:
    // 0x8010EC28: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8010EC2C: swc1        $f14, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f14.u32l;
    // 0x8010EC30: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x8010EC34: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x8010EC38: sb          $t7, 0x64($t1)
    MEM_B(0X64, ctx->r9) = ctx->r15;
    // 0x8010EC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010EC40:
    // 0x8010EC40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010EC44: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8010EC48: jr          $ra
    // 0x8010EC4C: nop

    return;
    // 0x8010EC4C: nop

;}
RECOMP_FUNC void syMatrixPerspFastF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B248: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001B24C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B250: lwc1        $f4, -0x1C54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C54);
    // 0x8001B254: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001B258: lwc1        $f6, -0x1C50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C50);
    // 0x8001B25C: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001B260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B264: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001B268: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001B26C: addiu       $a3, $a3, -0x46B0
    ctx->r7 = ADD32(ctx->r7, -0X46B0);
    // 0x8001B270: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B274: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8001B278: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001B27C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8001B280: nop

    // 0x8001B284: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001B288: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8001B28C: andi        $t7, $a2, 0x7FF
    ctx->r15 = ctx->r6 & 0X7FF;
    // 0x8001B290: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001B294: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8001B298: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8001B29C: addiu       $v0, $a2, 0x400
    ctx->r2 = ADD32(ctx->r6, 0X400);
    // 0x8001B2A0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8001B2A4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001B2A8: andi        $t1, $a2, 0x800
    ctx->r9 = ctx->r6 & 0X800;
    // 0x8001B2AC: bgez        $t0, L_8001B2C0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B2B0: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001B2C0;
    }
    // 0x8001B2B0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001B2B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B2B8: nop

    // 0x8001B2BC: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_8001B2C0:
    // 0x8001B2C0: beq         $t1, $zero, L_8001B2CC
    if (ctx->r9 == 0) {
        // 0x8001B2C4: andi        $t2, $v1, 0x7FF
        ctx->r10 = ctx->r3 & 0X7FF;
            goto L_8001B2CC;
    }
    // 0x8001B2C4: andi        $t2, $v1, 0x7FF
    ctx->r10 = ctx->r3 & 0X7FF;
    // 0x8001B2C8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8001B2CC:
    // 0x8001B2CC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8001B2D0: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x8001B2D4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8001B2D8: andi        $t6, $v1, 0x800
    ctx->r14 = ctx->r3 & 0X800;
    // 0x8001B2DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B2E0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8001B2E4: bgez        $t5, L_8001B2F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001B2E8: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001B2F8;
    }
    // 0x8001B2E8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001B2EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001B2F0: nop

    // 0x8001B2F4: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_8001B2F8:
    // 0x8001B2F8: beq         $t6, $zero, L_8001B304
    if (ctx->r14 == 0) {
        // 0x8001B2FC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8001B304;
    }
    // 0x8001B2FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B300: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8001B304:
    // 0x8001B304: div.s       $f14, $f12, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001B308: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001B30C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001B310: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001B314: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B318: div.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8001B31C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001B320: nop

    // 0x8001B324: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8001B328: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8001B32C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8001B330: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001B334: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8001B338: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8001B33C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8001B340: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8001B344: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001B348: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8001B34C: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001B350: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x8001B354: add.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x8001B358: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x8001B35C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001B360: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001B364: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001B368: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x8001B36C: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8001B370: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x8001B374: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8001B378: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8001B37C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8001B380: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001B384: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x8001B388: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x8001B38C: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x8001B390: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x8001B394: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x8001B398: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B39C: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8001B3A0: beq         $a1, $zero, L_8001B46C
    if (ctx->r5 == 0) {
        // 0x8001B3A4: swc1        $f10, 0x38($a0)
        MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
            goto L_8001B46C;
    }
    // 0x8001B3A4: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001B3A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B3AC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8001B3B0: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x8001B3B4: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8001B3B8: nop

    // 0x8001B3BC: bc1fl       L_8001B3D0
    if (!c1cs) {
        // 0x8001B3C0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8001B3D0;
    }
    goto skip_0;
    // 0x8001B3C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x8001B3C4: b           L_8001B46C
    // 0x8001B3C8: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
        goto L_8001B46C;
    // 0x8001B3C8: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8001B3CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8001B3D0:
    // 0x8001B3D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001B3D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001B3D8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001B3DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B3E0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001B3E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001B3E8: nop

    // 0x8001B3EC: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001B3F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001B3F4: nop

    // 0x8001B3F8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8001B3FC: beql        $t9, $zero, L_8001B44C
    if (ctx->r25 == 0) {
        // 0x8001B400: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8001B44C;
    }
    goto skip_1;
    // 0x8001B400: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x8001B404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B408: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001B40C: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001B410: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001B414: nop

    // 0x8001B418: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001B41C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001B420: nop

    // 0x8001B424: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8001B428: bne         $t9, $zero, L_8001B440
    if (ctx->r25 != 0) {
        // 0x8001B42C: nop
    
            goto L_8001B440;
    }
    // 0x8001B42C: nop

    // 0x8001B430: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8001B434: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B438: b           L_8001B458
    // 0x8001B43C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8001B458;
    // 0x8001B43C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8001B440:
    // 0x8001B440: b           L_8001B458
    // 0x8001B444: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8001B458;
    // 0x8001B444: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001B448: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8001B44C:
    // 0x8001B44C: nop

    // 0x8001B450: bltz        $t9, L_8001B440
    if (SIGNED(ctx->r25) < 0) {
        // 0x8001B454: nop
    
            goto L_8001B440;
    }
    // 0x8001B454: nop

L_8001B458:
    // 0x8001B458: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001B45C: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8001B460: bgtz        $t0, L_8001B46C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001B464: sh          $t9, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r25;
            goto L_8001B46C;
    }
    // 0x8001B464: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8001B468: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
L_8001B46C:
    // 0x8001B46C: jr          $ra
    // 0x8001B470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayersVSCheckTeamSelectInRangeAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135634: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80135638: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013563C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80135640: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80135644: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80135648: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013564C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80135650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80135654: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80135658: addiu       $t7, $t7, -0x4828
    ctx->r15 = ADD32(ctx->r15, -0X4828);
    // 0x8013565C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135660: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80135664: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135668: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013566C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80135670: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80135674: addiu       $t1, $t1, -0x481C
    ctx->r9 = ADD32(ctx->r9, -0X481C);
    // 0x80135678: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013567C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135680: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80135684: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x80135688: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8013568C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80135690: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80135694: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80135698: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8013569C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801356A0: lw          $t4, -0x4258($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4258);
    // 0x801356A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801356A8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801356AC: beq         $t4, $at, L_801356BC
    if (ctx->r12 == ctx->r1) {
        // 0x801356B0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801356BC;
    }
    // 0x801356B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801356B4: b           L_80135784
    // 0x801356B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135784;
    // 0x801356B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801356BC:
    // 0x801356BC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801356C0: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x801356C4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x801356C8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_801356CC:
    // 0x801356CC: lw          $t5, 0x84($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X84);
    // 0x801356D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801356D4: beql        $s2, $t5, L_80135778
    if (ctx->r18 == ctx->r13) {
        // 0x801356D8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80135778;
    }
    goto skip_0;
    // 0x801356D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801356DC: jal         0x80135554
    // 0x801356E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSCheckTeamSelectInRange(rdram, ctx);
        goto after_0;
    // 0x801356E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801356E4: beql        $v0, $zero, L_80135778
    if (ctx->r2 == 0) {
        // 0x801356E8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80135778;
    }
    goto skip_1;
    // 0x801356E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801356EC: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x801356F0: bne         $s2, $v0, L_80135700
    if (ctx->r18 != ctx->r2) {
        // 0x801356F4: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80135700;
    }
    // 0x801356F4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x801356F8: b           L_80135704
    // 0x801356FC: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
        goto L_80135704;
    // 0x801356FC: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
L_80135700:
    // 0x80135700: sw          $t6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r14;
L_80135704:
    // 0x80135704: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x80135708: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8013570C: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    // 0x80135710: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80135714: addu        $a1, $sp, $t8
    ctx->r5 = ADD32(ctx->r29, ctx->r24);
    // 0x80135718: jal         0x801332AC
    // 0x8013571C: lw          $a1, 0x48($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_1;
    // 0x8013571C: lw          $a1, 0x48($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48);
    after_1:
    // 0x80135720: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x80135724: jal         0x80132878
    // 0x80135728: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSUpdateTeamSelect(rdram, ctx);
        goto after_2;
    // 0x80135728: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8013572C: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80135730: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80135734: beq         $a0, $at, L_80135764
    if (ctx->r4 == ctx->r1) {
        // 0x80135738: nop
    
            goto L_80135764;
    }
    // 0x80135738: nop

    // 0x8013573C: jal         0x800EC104
    // 0x80135740: lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X40);
    ftParamGetCostumeTeamID(rdram, ctx);
        goto after_3;
    // 0x80135740: lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X40);
    after_3:
    // 0x80135744: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x80135748: jal         0x80131B78
    // 0x8013574C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_4;
    // 0x8013574C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80135750: sw          $v0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r2;
    // 0x80135754: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80135758: lw          $a1, 0x4C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4C);
    // 0x8013575C: jal         0x800E9248
    // 0x80135760: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_5;
    // 0x80135760: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
L_80135764:
    // 0x80135764: jal         0x800269C0
    // 0x80135768: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80135768: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_6:
    // 0x8013576C: b           L_80135784
    // 0x80135770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135784;
    // 0x80135770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80135774: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80135778:
    // 0x80135778: bne         $s0, $s3, L_801356CC
    if (ctx->r16 != ctx->r19) {
        // 0x8013577C: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_801356CC;
    }
    // 0x8013577C: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x80135780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135784:
    // 0x80135784: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80135788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013578C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80135790: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80135794: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80135798: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8013579C: jr          $ra
    // 0x801357A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801357A0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160B14: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160B18: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80160B1C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80160B20: jr          $ra
    // 0x80160B24: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x80160B24: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void grYosterCheckFighterCloudStand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801085A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801085AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801085B0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801085B4: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x801085B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801085BC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801085C0: addu        $s2, $s2, $a0
    ctx->r18 = ADD32(ctx->r18, ctx->r4);
    // 0x801085C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801085C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801085CC: beq         $s0, $zero, L_80108618
    if (ctx->r16 == 0) {
        // 0x801085D0: lbu         $s2, -0x14D8($s2)
        ctx->r18 = MEM_BU(ctx->r18, -0X14D8);
            goto L_80108618;
    }
    // 0x801085D0: lbu         $s2, -0x14D8($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X14D8);
    // 0x801085D4: addiu       $s1, $zero, -0x2
    ctx->r17 = ADD32(0, -0X2);
    // 0x801085D8: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_801085DC:
    // 0x801085DC: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x801085E0: bnel        $t6, $zero, L_80108610
    if (ctx->r14 != 0) {
        // 0x801085E4: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80108610;
    }
    goto skip_0;
    // 0x801085E4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x801085E8: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    // 0x801085EC: beql        $s1, $a0, L_80108610
    if (ctx->r17 == ctx->r4) {
        // 0x801085F0: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80108610;
    }
    goto skip_1;
    // 0x801085F0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x801085F4: jal         0x800FC72C
    // 0x801085F8: nop

    mpCollisionSetDObjNoID(rdram, ctx);
        goto after_0;
    // 0x801085F8: nop

    after_0:
    // 0x801085FC: bnel        $v0, $s2, L_80108610
    if (ctx->r2 != ctx->r18) {
        // 0x80108600: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80108610;
    }
    goto skip_2;
    // 0x80108600: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80108604: b           L_8010861C
    // 0x80108608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010861C;
    // 0x80108608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010860C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80108610:
    // 0x80108610: bnel        $s0, $zero, L_801085DC
    if (ctx->r16 != 0) {
        // 0x80108614: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_801085DC;
    }
    goto skip_3;
    // 0x80108614: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_3:
L_80108618:
    // 0x80108618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010861C:
    // 0x8010861C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80108620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80108624: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80108628: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010862C: jr          $ra
    // 0x80108630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80108630: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itEggFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018171C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80181728: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8018172C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80181730: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80181734: lbu         $t1, 0x2CF($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2CF);
    // 0x80181738: sw          $t9, 0x248($a0)
    MEM_W(0X248, ctx->r4) = ctx->r25;
    // 0x8018173C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80181740: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80181744: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    // 0x80181748: sw          $zero, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = 0;
    // 0x8018174C: jal         0x80173F78
    // 0x80181750: sb          $t2, 0x2CF($a0)
    MEM_B(0X2CF, ctx->r4) = ctx->r10;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80181750: sb          $t2, 0x2CF($a0)
    MEM_B(0X2CF, ctx->r4) = ctx->r10;
    after_0:
    // 0x80181754: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181758: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x8018175C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80181760: jal         0x80172EC8
    // 0x80181764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80181764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80181768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018176C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181770: jr          $ra
    // 0x80181774: nop

    return;
    // 0x80181774: nop

;}
RECOMP_FUNC void func_ovl3_80140934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140934: jr          $ra
    // 0x80140938: nop

    return;
    // 0x80140938: nop

;}
RECOMP_FUNC void mnPlayers1PGameSetCursorPuckOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D58: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135D5C: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80135D60: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80135D64: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135D68: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80135D6C: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80135D70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135D74: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80135D78: lwc1        $f4, 0x58($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80135D7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135D80: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80135D84: swc1        $f8, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f8.u32l;
    // 0x80135D88: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80135D8C: lwc1        $f10, 0x5C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X5C);
    // 0x80135D90: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80135D94: jr          $ra
    // 0x80135D98: swc1        $f18, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x80135D98: swc1        $f18, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801538C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801538CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801538D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801538D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801538D8: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x801538DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801538E0: jal         0x800E6F24
    // 0x801538E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801538E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801538E8: jal         0x800E0830
    // 0x801538EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801538EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801538F0: jal         0x801538B0
    // 0x801538F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyPikachuSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801538F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801538F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801538FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153900: jr          $ra
    // 0x80153904: nop

    return;
    // 0x80153904: nop

;}
RECOMP_FUNC void ftMainSetHitInteractStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E26BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E26C0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800E26C4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800E26C8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800E26CC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800E26D0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E26D4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800E26D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800E26DC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800E26E0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800E26E4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800E26E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E26EC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800E26F0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_800E26F4:
    // 0x800E26F4: lw          $t6, 0x294($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X294);
    // 0x800E26F8: beql        $t6, $zero, L_800E285C
    if (ctx->r14 == 0) {
        // 0x800E26FC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800E285C;
    }
    goto skip_0;
    // 0x800E26FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800E2700: lw          $t7, 0x298($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X298);
    // 0x800E2704: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800E2708: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800E270C: bne         $a1, $t7, L_800E2858
    if (ctx->r5 != ctx->r15) {
        // 0x800E2710: sll         $t8, $t8, 4
        ctx->r24 = S32(ctx->r24 << 4);
            goto L_800E2858;
    }
    // 0x800E2710: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800E2714: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800E2718: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E271C: addu        $a3, $a0, $t8
    ctx->r7 = ADD32(ctx->r4, ctx->r24);
    // 0x800E2720: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x800E2724: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E2728: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
L_800E272C:
    // 0x800E272C: lw          $t9, 0x2F0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X2F0);
    // 0x800E2730: bnel        $s0, $t9, L_800E2798
    if (ctx->r16 != ctx->r25) {
        // 0x800E2734: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800E2798;
    }
    goto skip_1;
    // 0x800E2734: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    skip_1:
    // 0x800E2738: beql        $s1, $zero, L_800E275C
    if (ctx->r17 == 0) {
        // 0x800E273C: lbu         $t7, 0x2F4($t1)
        ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
            goto L_800E275C;
    }
    goto skip_2;
    // 0x800E273C: lbu         $t7, 0x2F4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
    skip_2:
    // 0x800E2740: beql        $s1, $s2, L_800E276C
    if (ctx->r17 == ctx->r18) {
        // 0x800E2744: lbu         $t6, 0x2F4($t1)
        ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
            goto L_800E276C;
    }
    goto skip_3;
    // 0x800E2744: lbu         $t6, 0x2F4($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
    skip_3:
    // 0x800E2748: beql        $s1, $s3, L_800E277C
    if (ctx->r17 == ctx->r19) {
        // 0x800E274C: lbu         $t7, 0x2F4($t1)
        ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
            goto L_800E277C;
    }
    goto skip_4;
    // 0x800E274C: lbu         $t7, 0x2F4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
    skip_4:
    // 0x800E2750: b           L_800E27A8
    // 0x800E2754: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
        goto L_800E27A8;
    // 0x800E2754: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800E2758: lbu         $t7, 0x2F4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
L_800E275C:
    // 0x800E275C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x800E2760: b           L_800E27A4
    // 0x800E2764: sb          $t8, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r24;
        goto L_800E27A4;
    // 0x800E2764: sb          $t8, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r24;
    // 0x800E2768: lbu         $t6, 0x2F4($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
L_800E276C:
    // 0x800E276C: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800E2770: b           L_800E27A4
    // 0x800E2774: sb          $t7, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r15;
        goto L_800E27A4;
    // 0x800E2774: sb          $t7, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r15;
    // 0x800E2778: lbu         $t7, 0x2F4($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X2F4);
L_800E277C:
    // 0x800E277C: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x800E2780: andi        $t6, $t9, 0xE
    ctx->r14 = ctx->r25 & 0XE;
    // 0x800E2784: andi        $t8, $t7, 0xFFF1
    ctx->r24 = ctx->r15 & 0XFFF1;
    // 0x800E2788: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800E278C: b           L_800E27A4
    // 0x800E2790: sb          $t9, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r25;
        goto L_800E27A4;
    // 0x800E2790: sb          $t9, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r25;
    // 0x800E2794: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_800E2798:
    // 0x800E2798: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x800E279C: bne         $at, $zero, L_800E272C
    if (ctx->r1 != 0) {
        // 0x800E27A0: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800E272C;
    }
    // 0x800E27A0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800E27A4:
    // 0x800E27A4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_800E27A8:
    // 0x800E27A8: bne         $t0, $at, L_800E2838
    if (ctx->r8 != ctx->r1) {
        // 0x800E27AC: or          $t1, $a3, $zero
        ctx->r9 = ctx->r7 | 0;
            goto L_800E2838;
    }
    // 0x800E27AC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x800E27B0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800E27B4:
    // 0x800E27B4: lw          $t7, 0x2F0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X2F0);
    // 0x800E27B8: beql        $t7, $zero, L_800E27D4
    if (ctx->r15 == 0) {
        // 0x800E27BC: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800E27D4;
    }
    goto skip_5;
    // 0x800E27BC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_5:
    // 0x800E27C0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800E27C4: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x800E27C8: bne         $at, $zero, L_800E27B4
    if (ctx->r1 != 0) {
        // 0x800E27CC: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800E27B4;
    }
    // 0x800E27CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800E27D0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_800E27D4:
    // 0x800E27D4: bne         $t0, $at, L_800E27E0
    if (ctx->r8 != ctx->r1) {
        // 0x800E27D8: nop
    
            goto L_800E27E0;
    }
    // 0x800E27D8: nop

    // 0x800E27DC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
L_800E27E0:
    // 0x800E27E0: beq         $s1, $zero, L_800E2800
    if (ctx->r17 == 0) {
        // 0x800E27E4: sw          $s0, 0x2F0($t1)
        MEM_W(0X2F0, ctx->r9) = ctx->r16;
            goto L_800E2800;
    }
    // 0x800E27E4: sw          $s0, 0x2F0($t1)
    MEM_W(0X2F0, ctx->r9) = ctx->r16;
    // 0x800E27E8: beql        $s1, $s2, L_800E2814
    if (ctx->r17 == ctx->r18) {
        // 0x800E27EC: lbu         $t6, 0x2F4($t1)
        ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
            goto L_800E2814;
    }
    goto skip_6;
    // 0x800E27EC: lbu         $t6, 0x2F4($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
    skip_6:
    // 0x800E27F0: beql        $s1, $s3, L_800E2824
    if (ctx->r17 == ctx->r19) {
        // 0x800E27F4: lbu         $t8, 0x2F4($t1)
        ctx->r24 = MEM_BU(ctx->r9, 0X2F4);
            goto L_800E2824;
    }
    goto skip_7;
    // 0x800E27F4: lbu         $t8, 0x2F4($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X2F4);
    skip_7:
    // 0x800E27F8: b           L_800E2838
    // 0x800E27FC: nop

        goto L_800E2838;
    // 0x800E27FC: nop

L_800E2800:
    // 0x800E2800: lbu         $t8, 0x2F4($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X2F4);
    // 0x800E2804: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x800E2808: b           L_800E2838
    // 0x800E280C: sb          $t9, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r25;
        goto L_800E2838;
    // 0x800E280C: sb          $t9, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r25;
    // 0x800E2810: lbu         $t6, 0x2F4($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X2F4);
L_800E2814:
    // 0x800E2814: ori         $t8, $t6, 0x40
    ctx->r24 = ctx->r14 | 0X40;
    // 0x800E2818: b           L_800E2838
    // 0x800E281C: sb          $t8, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r24;
        goto L_800E2838;
    // 0x800E281C: sb          $t8, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r24;
    // 0x800E2820: lbu         $t8, 0x2F4($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X2F4);
L_800E2824:
    // 0x800E2824: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x800E2828: andi        $t6, $t7, 0xE
    ctx->r14 = ctx->r15 & 0XE;
    // 0x800E282C: andi        $t9, $t8, 0xFFF1
    ctx->r25 = ctx->r24 & 0XFFF1;
    // 0x800E2830: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800E2834: sb          $t7, 0x2F4($t1)
    MEM_B(0X2F4, ctx->r9) = ctx->r15;
L_800E2838:
    // 0x800E2838: bne         $t3, $zero, L_800E2850
    if (ctx->r11 != 0) {
        // 0x800E283C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800E2850;
    }
    // 0x800E283C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2840: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2844: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800E2848: b           L_800E2858
    // 0x800E284C: sw          $zero, 0x11A0($at)
    MEM_W(0X11A0, ctx->r1) = 0;
        goto L_800E2858;
    // 0x800E284C: sw          $zero, 0x11A0($at)
    MEM_W(0X11A0, ctx->r1) = 0;
L_800E2850:
    // 0x800E2850: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800E2854: sw          $zero, 0x11B0($at)
    MEM_W(0X11B0, ctx->r1) = 0;
L_800E2858:
    // 0x800E2858: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800E285C:
    // 0x800E285C: bne         $v0, $t5, L_800E26F4
    if (ctx->r2 != ctx->r13) {
        // 0x800E2860: addiu       $v1, $v1, 0xC4
        ctx->r3 = ADD32(ctx->r3, 0XC4);
            goto L_800E26F4;
    }
    // 0x800E2860: addiu       $v1, $v1, 0xC4
    ctx->r3 = ADD32(ctx->r3, 0XC4);
    // 0x800E2864: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800E2868: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800E286C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800E2870: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800E2874: jr          $ra
    // 0x800E2878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E2878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftCaptainSpecialHiProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801605FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160600: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80160604: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80160608: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x8016060C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80160610: sh          $zero, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = 0;
    // 0x80160614: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80160618: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8016061C: sw          $t8, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r24;
    // 0x80160620: swc1        $f0, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f0.u32l;
    // 0x80160624: swc1        $f0, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->f0.u32l;
    // 0x80160628: jr          $ra
    // 0x8016062C: sb          $t7, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r15;
    return;
    // 0x8016062C: sb          $t7, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void syInterpCatromCubicSpline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D610: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8001D614: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D61C: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D620: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D624: mul.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8001D628: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8001D62C: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001D630: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001D634: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001D638: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D63C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D640: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8001D644: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8001D648: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8001D64C: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001D650: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D658: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001D65C: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8001D660: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D664: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001D668: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D66C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D674: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D678: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D67C: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001D680: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001D684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D688: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D68C: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8001D690: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D694: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001D698: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8001D69C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001D6A0: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8001D6A4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D6A8: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8001D6AC: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001D6B0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001D6B4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D6B8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001D6BC: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001D6C0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D6C4: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001D6C8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001D6CC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001D6D0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8001D6D4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D6D8: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001D6DC: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001D6E0: nop

    // 0x8001D6E4: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001D6E8: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001D6EC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001D6F0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001D6F4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001D6F8: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001D6FC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001D700: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001D704: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001D708: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001D70C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8001D710: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D714: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001D718: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001D71C: nop

    // 0x8001D720: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001D724: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001D728: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D72C: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001D730: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D734: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001D738: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D73C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001D740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D744: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001D748: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001D74C: jr          $ra
    // 0x8001D750: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x8001D750: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_ovl8_803822D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803822D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803822DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803822E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803822E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803822E8: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x803822EC: beq         $a2, $zero, L_803822FC
    if (ctx->r6 == 0) {
        // 0x803822F0: nop
    
            goto L_803822FC;
    }
    // 0x803822F0: nop

    // 0x803822F4: jal         0x80371764
    // 0x803822F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x803822F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_803822FC:
    // 0x803822FC: jal         0x80376FBC
    // 0x80382300: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    stringLength(rdram, ctx);
        goto after_1;
    // 0x80382300: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80382304: jal         0x803716D8
    // 0x80382308: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    func_ovl8_803716D8(rdram, ctx);
        goto after_2;
    // 0x80382308: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    after_2:
    // 0x8038230C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80382310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80382314: sw          $v0, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r2;
    // 0x80382318: jal         0x80376FFC
    // 0x8038231C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    stringCopy(rdram, ctx);
        goto after_3;
    // 0x8038231C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80382320: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80382324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80382328: lw          $v1, 0x38($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X38);
    // 0x8038232C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80382330: lh          $t9, 0x118($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X118);
    // 0x80382334: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x80382338: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x8038233C: jalr        $t9
    // 0x80382340: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80382340: nop

    after_4:
    // 0x80382344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038234C: jr          $ra
    // 0x80382350: nop

    return;
    // 0x80382350: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F0A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F0AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F0B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F0B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8015F0B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8015F0BC: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015F0C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8015F0C4: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015F0C8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015F0CC: nop

    // 0x8015F0D0: bc1fl       L_8015F0E4
    if (!c1cs) {
        // 0x8015F0D4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8015F0E4;
    }
    goto skip_0;
    // 0x8015F0D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8015F0D8: b           L_8015F0E4
    // 0x8015F0DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8015F0E4;
    // 0x8015F0DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8015F0E0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8015F0E4:
    // 0x8015F0E4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8015F0E8: nop

    // 0x8015F0EC: bc1fl       L_8015F124
    if (!c1cs) {
        // 0x8015F0F0: lwc1        $f10, 0x4C($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
            goto L_8015F124;
    }
    goto skip_1;
    // 0x8015F0F0: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    skip_1:
    // 0x8015F0F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015F0F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8015F0FC: bc1f        L_8015F10C
    if (!c1cs) {
        // 0x8015F100: nop
    
            goto L_8015F10C;
    }
    // 0x8015F100: nop

    // 0x8015F104: b           L_8015F10C
    // 0x8015F108: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8015F10C;
    // 0x8015F108: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8015F10C:
    // 0x8015F10C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8015F110: nop

    // 0x8015F114: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015F118: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8015F11C: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x8015F120: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
L_8015F124:
    // 0x8015F124: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015F128: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8015F12C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8015F130: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F134: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F138: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8015F13C: jal         0x800E6F24
    // 0x8015F140: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F140: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015F144: jal         0x800E0830
    // 0x8015F148: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F148: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015F14C: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8015F150: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015F154: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015F158: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015F15C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8015F160: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x8015F164: bc1fl       L_8015F174
    if (!c1cs) {
        // 0x8015F168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015F174;
    }
    goto skip_2;
    // 0x8015F168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8015F16C: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x8015F170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015F174:
    // 0x8015F174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F178: jr          $ra
    // 0x8015F17C: nop

    return;
    // 0x8015F17C: nop

;}
RECOMP_FUNC void ftPhysicsApplyGroundFrictionOrTransN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8CD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800D8CD8: lw          $t6, 0x198($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X198);
    // 0x800D8CDC: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800D8CE0: bgez        $t8, L_800D8CF8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D8CE4: nop
    
            goto L_800D8CF8;
    }
    // 0x800D8CE4: nop

    // 0x800D8CE8: jal         0x800D8C14
    // 0x800D8CEC: nop

    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_0;
    // 0x800D8CEC: nop

    after_0:
    // 0x800D8CF0: b           L_800D8D04
    // 0x800D8CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D8D04;
    // 0x800D8CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D8CF8:
    // 0x800D8CF8: jal         0x800D8BB4
    // 0x800D8CFC: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_1;
    // 0x800D8CFC: nop

    after_1:
    // 0x800D8D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D8D04:
    // 0x800D8D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8D08: jr          $ra
    // 0x800D8D0C: nop

    return;
    // 0x800D8D0C: nop

;}
RECOMP_FUNC void mvOpeningPikachuMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D42C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D430: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D434: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D438: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D43C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D440: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D444: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D448: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D44C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D450: addiu       $t6, $t6, -0x1F40
    ctx->r14 = ADD32(ctx->r14, -0X1F40);
    // 0x8018D454: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D458: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $s0, $s0, -0x1DB8
    ctx->r16 = ADD32(ctx->r16, -0X1DB8);
    // 0x8018D460: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D464: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D468: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D46C: addiu       $t9, $t9, -0x1F24
    ctx->r25 = ADD32(ctx->r25, -0X1F24);
    // 0x8018D470: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D474: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D478: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D47C: addiu       $s1, $s1, -0x1D98
    ctx->r17 = ADD32(ctx->r17, -0X1D98);
    // 0x8018D480: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D484: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D48C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D490: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D494: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D498: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D49C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D4A0: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D4A4: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D4A8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D4AC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D4B4: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D4BC: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4C0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4C4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4C8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4CC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4D0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4D4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4D8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4DC: jal         0x8010DB2C
    // 0x8018D4E0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4E0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4E4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4E8: addiu       $v1, $v1, -0x1DC8
    ctx->r3 = ADD32(ctx->r3, -0X1DC8);
    // 0x8018D4EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4F0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4F4: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4FC: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    // 0x8018D500: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018D504: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D508: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D50C: jal         0x80007080
    // 0x8018D510: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D510: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D514: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D518: lwc1        $f6, -0x1DF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DF4);
    // 0x8018D51C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D520: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D524: jal         0x8000B39C
    // 0x8018D528: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D528: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    after_2:
    // 0x8018D52C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D530: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D534: addiu       $a1, $a1, -0x2CCC
    ctx->r5 = ADD32(ctx->r5, -0X2CCC);
    // 0x8018D538: lw          $a0, -0x1DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DC8);
    // 0x8018D53C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D540: jal         0x80008188
    // 0x8018D544: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D544: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D548: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D54C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D550: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D554: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D558: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D55C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D560: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D564: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D568: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D56C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D570: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D574: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D578: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D57C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D580: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D584: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D588: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D58C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D590: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D594: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D598: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D59C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D5A0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D5A4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5A8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D5AC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D5B0: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5B4: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D5B8: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5BC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5C0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5C4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5C8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5CC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5D0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5D4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5D8: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5DC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5E0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5E4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5E8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5EC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5F0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5F4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5F8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5FC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D600: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D604: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D608: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D60C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D610: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D614: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D618: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D61C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D620: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D624: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D628: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D62C: jr          $ra
    // 0x8018D630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftMarioSpecialLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156764: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80156768: jal         0x800DDDDC
    // 0x8015676C: addiu       $a1, $a1, 0x6808
    ctx->r5 = ADD32(ctx->r5, 0X6808);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015676C: addiu       $a1, $a1, 0x6808
    ctx->r5 = ADD32(ctx->r5, 0X6808);
    after_0:
    // 0x80156770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156778: jr          $ra
    // 0x8015677C: nop

    return;
    // 0x8015677C: nop

;}
RECOMP_FUNC void ftCommonDownAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144910: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80144914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144918: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014491C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144920: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144924: jal         0x800E6F24
    // 0x80144928: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144928: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8014492C: jal         0x800E0830
    // 0x80144930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80144930: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80144934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014493C: jr          $ra
    // 0x80144940: nop

    return;
    // 0x80144940: nop

;}
RECOMP_FUNC void wpSamusBombProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801691FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169204: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80169208: jal         0x800269C0
    // 0x8016920C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8016920C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80169210: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80169214: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80169218: jal         0x801005C8
    // 0x8016921C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016921C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80169220: jal         0x80168F2C
    // 0x80169224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpSamusBombExplodeInitVars(rdram, ctx);
        goto after_2;
    // 0x80169224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80169228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016922C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80169230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169234: jr          $ra
    // 0x80169238: nop

    return;
    // 0x80169238: nop

;}
RECOMP_FUNC void mnMapsMakeString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D80: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80131D84: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131D88: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D8C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80131D90: addiu       $t7, $t7, 0x45D0
    ctx->r15 = ADD32(ctx->r15, 0X45D0);
    // 0x80131D94: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80131D98: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80131D9C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80131DA0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80131DA4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80131DA8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80131DAC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80131DB0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80131DB4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80131DB8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80131DBC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80131DC0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80131DC4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80131DC8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80131DCC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131DD0: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x80131DD4: addiu       $t0, $t7, 0x6C
    ctx->r8 = ADD32(ctx->r15, 0X6C);
    // 0x80131DD8: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
L_80131DDC:
    // 0x80131DDC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131DE0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131DE4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131DE8: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131DEC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131DF0: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131DF4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131DF8: bne         $t7, $t0, L_80131DDC
    if (ctx->r15 != ctx->r8) {
        // 0x80131DFC: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131DDC;
    }
    // 0x80131DFC: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131E00: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131E04: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131E08: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80131E0C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131E10: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131E14: lbu         $t1, 0x0($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X0);
    // 0x80131E18: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80131E1C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80131E20: beq         $t1, $zero, L_80131F64
    if (ctx->r9 == 0) {
        // 0x80131E24: andi        $a0, $t1, 0xFF
        ctx->r4 = ctx->r9 & 0XFF;
            goto L_80131F64;
    }
    // 0x80131E24: andi        $a0, $t1, 0xFF
    ctx->r4 = ctx->r9 & 0XFF;
    // 0x80131E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131E2C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80131E30: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131E34: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80131E38: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80131E3C: addiu       $s6, $s6, 0x4E10
    ctx->r22 = ADD32(ctx->r22, 0X4E10);
    // 0x80131E40: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131E44: addiu       $fp, $zero, 0x2E
    ctx->r30 = ADD32(0, 0X2E);
    // 0x80131E48: addiu       $s7, $zero, 0x27
    ctx->r23 = ADD32(0, 0X27);
    // 0x80131E4C: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x80131E50: lw          $s2, 0x108($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X108);
L_80131E54:
    // 0x80131E54: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x80131E58: bne         $at, $zero, L_80131E74
    if (ctx->r1 != 0) {
        // 0x80131E5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131E74;
    }
    // 0x80131E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131E60: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80131E64: beq         $at, $zero, L_80131E74
    if (ctx->r1 == 0) {
        // 0x80131E68: nop
    
            goto L_80131E74;
    }
    // 0x80131E68: nop

    // 0x80131E6C: b           L_80131E74
    // 0x80131E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80131E74;
    // 0x80131E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131E74:
    // 0x80131E74: bne         $v0, $zero, L_80131E84
    if (ctx->r2 != 0) {
        // 0x80131E78: nop
    
            goto L_80131E84;
    }
    // 0x80131E78: nop

    // 0x80131E7C: bne         $s4, $v1, L_80131EA8
    if (ctx->r20 != ctx->r3) {
        // 0x80131E80: nop
    
            goto L_80131EA8;
    }
    // 0x80131E80: nop

L_80131E84:
    // 0x80131E84: bne         $s4, $v1, L_80131E94
    if (ctx->r20 != ctx->r3) {
        // 0x80131E88: addiu       $t2, $v1, -0x30
        ctx->r10 = ADD32(ctx->r3, -0X30);
            goto L_80131E94;
    }
    // 0x80131E88: addiu       $t2, $v1, -0x30
    ctx->r10 = ADD32(ctx->r3, -0X30);
    // 0x80131E8C: b           L_80131F50
    // 0x80131E90: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
        goto L_80131F50;
    // 0x80131E90: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
L_80131E94:
    // 0x80131E94: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80131E98: nop

    // 0x80131E9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131EA0: b           L_80131F50
    // 0x80131EA4: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
        goto L_80131F50;
    // 0x80131EA4: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_80131EA8:
    // 0x80131EA8: jal         0x80131BE4
    // 0x80131EAC: nop

    mnMapsGetCharacterID(rdram, ctx);
        goto after_0;
    // 0x80131EAC: nop

    after_0:
    // 0x80131EB0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80131EB4: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80131EB8: lw          $t4, 0x84($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X84);
    // 0x80131EBC: lw          $t5, 0xC($s6)
    ctx->r13 = MEM_W(ctx->r22, 0XC);
    // 0x80131EC0: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80131EC4: jal         0x800CCFDC
    // 0x80131EC8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131EC8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x80131ECC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131ED0: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x80131ED4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80131ED8: jal         0x80131C5C
    // 0x80131EDC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnMapsGetCharacterSpacing(rdram, ctx);
        goto after_2;
    // 0x80131EDC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80131EE0: lh          $t0, 0x14($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X14);
    // 0x80131EE4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80131EE8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80131EEC: nop

    // 0x80131EF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131EF4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80131EF8: beq         $v0, $s7, L_80131F10
    if (ctx->r2 == ctx->r23) {
        // 0x80131EFC: add.s       $f20, $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
            goto L_80131F10;
    }
    // 0x80131EFC: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80131F00: beql        $v0, $fp, L_80131F20
    if (ctx->r2 == ctx->r30) {
        // 0x80131F04: add.s       $f4, $f22, $f24
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_80131F20;
    }
    goto skip_0;
    // 0x80131F04: add.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
    skip_0:
    // 0x80131F08: b           L_80131F24
    // 0x80131F0C: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
        goto L_80131F24;
    // 0x80131F0C: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
L_80131F10:
    // 0x80131F10: sub.s       $f18, $f22, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x80131F14: b           L_80131F24
    // 0x80131F18: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
        goto L_80131F24;
    // 0x80131F18: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80131F1C: add.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
L_80131F20:
    // 0x80131F20: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_80131F24:
    // 0x80131F24: lhu         $t7, 0x24($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X24);
    // 0x80131F28: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80131F2C: sh          $t8, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r24;
    // 0x80131F30: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131F34: sh          $t9, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r25;
    // 0x80131F38: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80131F3C: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
    // 0x80131F40: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x80131F44: sb          $t2, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r10;
    // 0x80131F48: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x80131F4C: sb          $t3, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r11;
L_80131F50:
    // 0x80131F50: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x80131F54: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80131F58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131F5C: bne         $a0, $zero, L_80131E54
    if (ctx->r4 != 0) {
        // 0x80131F60: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131E54;
    }
    // 0x80131F60: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80131F64:
    // 0x80131F64: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80131F68: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131F6C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80131F70: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80131F74: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80131F78: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80131F7C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F80: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80131F84: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80131F88: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80131F8C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F90: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80131F94: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80131F98: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80131F9C: jr          $ra
    // 0x80131FA0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80131FA0: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void grDisplayLayer3SecProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010530C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80105310: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80105314: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80105318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010531C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105320: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80105324: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80105328: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8010532C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80105330: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80105334: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80105338: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x8010533C: ori         $t5, $t5, 0xFFFE
    ctx->r13 = ctx->r13 | 0XFFFE;
    // 0x80105340: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80105344: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80105348: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8010534C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80105350: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80105354: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80105358: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x8010535C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80105360: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105364: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80105368: ori         $t9, $t9, 0x2048
    ctx->r25 = ctx->r25 | 0X2048;
    // 0x8010536C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80105370: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80105374: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80105378: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8010537C: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80105380: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80105384: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105388: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8010538C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80105390: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80105394: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80105398: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010539C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801053A0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x801053A4: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801053A8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x801053AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801053B0: sw          $ra, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r31;
    // 0x801053B4: jal         0x80014768
    // 0x801053B8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x801053B8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_0:
    // 0x801053BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801053C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801053C4: jr          $ra
    // 0x801053C8: nop

    return;
    // 0x801053C8: nop

;}
RECOMP_FUNC void lbParticleReadUShort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEBF8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800CEBFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CEC00: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800CEC04: beq         $t6, $zero, L_800CEC24
    if (ctx->r14 == 0) {
        // 0x800CEC08: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CEC24;
    }
    // 0x800CEC08: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CEC0C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800CEC10: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800CEC14: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800CEC18: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800CEC1C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800CEC20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800CEC24:
    // 0x800CEC24: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x800CEC28: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800CEC2C: jr          $ra
    // 0x800CEC30: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800CEC30: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void mnPlayers1PTrainingPuckAdjustProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136CD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136CD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136CD8: lw          $a0, -0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X776C);
    // 0x80136CDC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136CE0: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80136CE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80136CE8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136CEC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136CF0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136CF4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136CF8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80136CFC: lw          $t8, 0x58($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X58);
    // 0x80136D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136D04: beql        $t8, $zero, L_80136D40
    if (ctx->r24 == 0) {
        // 0x80136D08: lw          $t1, 0x54($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X54);
            goto L_80136D40;
    }
    goto skip_0;
    // 0x80136D08: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    skip_0:
    // 0x80136D0C: jal         0x80136BE0
    // 0x80136D10: nop

    mnPlayers1PTrainingPuckAdjustRecall(rdram, ctx);
        goto after_0;
    // 0x80136D10: nop

    after_0:
    // 0x80136D14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136D18: lw          $a0, -0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X776C);
    // 0x80136D1C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136D20: addiu       $t0, $t0, -0x7AA8
    ctx->r8 = ADD32(ctx->r8, -0X7AA8);
    // 0x80136D24: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80136D28: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80136D2C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80136D30: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x80136D34: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80136D38: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80136D3C: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
L_80136D40:
    // 0x80136D40: beq         $t1, $zero, L_80136D50
    if (ctx->r9 == 0) {
        // 0x80136D44: nop
    
            goto L_80136D50;
    }
    // 0x80136D44: nop

    // 0x80136D48: jal         0x80136A44
    // 0x80136D4C: nop

    mnPlayers1PTrainingPuckAdjustPlaced(rdram, ctx);
        goto after_1;
    // 0x80136D4C: nop

    after_1:
L_80136D50:
    // 0x80136D50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136D54: lw          $a0, -0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7768);
    // 0x80136D58: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80136D5C: addiu       $t3, $t3, -0x7AA8
    ctx->r11 = ADD32(ctx->r11, -0X7AA8);
    // 0x80136D60: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80136D64: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x80136D68: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80136D6C: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x80136D70: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80136D74: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80136D78: lw          $t4, 0x58($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X58);
    // 0x80136D7C: beql        $t4, $zero, L_80136DB8
    if (ctx->r12 == 0) {
        // 0x80136D80: lw          $t7, 0x54($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X54);
            goto L_80136DB8;
    }
    goto skip_1;
    // 0x80136D80: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
    skip_1:
    // 0x80136D84: jal         0x80136BE0
    // 0x80136D88: nop

    mnPlayers1PTrainingPuckAdjustRecall(rdram, ctx);
        goto after_2;
    // 0x80136D88: nop

    after_2:
    // 0x80136D8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136D90: lw          $a0, -0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7768);
    // 0x80136D94: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136D98: addiu       $t6, $t6, -0x7AA8
    ctx->r14 = ADD32(ctx->r14, -0X7AA8);
    // 0x80136D9C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80136DA0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80136DA4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80136DA8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80136DAC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80136DB0: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80136DB4: lw          $t7, 0x54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X54);
L_80136DB8:
    // 0x80136DB8: beql        $t7, $zero, L_80136DCC
    if (ctx->r15 == 0) {
        // 0x80136DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136DCC;
    }
    goto skip_2;
    // 0x80136DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80136DC0: jal         0x80136A44
    // 0x80136DC4: nop

    mnPlayers1PTrainingPuckAdjustPlaced(rdram, ctx);
        goto after_3;
    // 0x80136DC4: nop

    after_3:
    // 0x80136DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136DCC:
    // 0x80136DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136DD0: jr          $ra
    // 0x80136DD4: nop

    return;
    // 0x80136DD4: nop

;}
RECOMP_FUNC void itTosakintoCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EA98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EAA0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017EAA4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8017EAA8: jal         0x801737B8
    // 0x8017EAAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017EAAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017EAB0: beq         $v0, $zero, L_8017EAC4
    if (ctx->r2 == 0) {
        // 0x8017EAB4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8017EAC4;
    }
    // 0x8017EAB4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EAB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017EABC: nop

    // 0x8017EAC0: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8017EAC4:
    // 0x8017EAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017EACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017EAD0: jr          $ra
    // 0x8017EAD4: nop

    return;
    // 0x8017EAD4: nop

;}
RECOMP_FUNC void mnTitleSetDemoFighterKinds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BC8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131BCC: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80131BD0: lhu         $s2, 0x4938($s2)
    ctx->r18 = MEM_HU(ctx->r18, 0X4938);
    // 0x80131BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131BD8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80131BDC: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80131BE0: lhu         $t7, 0xA($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XA);
    // 0x80131BE4: ori         $s2, $s2, 0x36F
    ctx->r18 = ctx->r18 | 0X36F;
    // 0x80131BE8: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x80131BEC: nor         $t6, $s2, $zero
    ctx->r14 = ~(ctx->r18 | 0);
    // 0x80131BF0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80131BF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131BF8: beq         $t8, $zero, L_80131C04
    if (ctx->r24 == 0) {
        // 0x80131BFC: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80131C04;
    }
    // 0x80131BFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C00: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
L_80131C04:
    // 0x80131C04: jal         0x80131B00
    // 0x80131C08: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_0;
    // 0x80131C08: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_0:
    // 0x80131C0C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131C10: jal         0x80131B00
    // 0x80131C14: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_1;
    // 0x80131C14: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    after_1:
    // 0x80131C18: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80131C1C: bne         $at, $zero, L_80131C28
    if (ctx->r1 != 0) {
        // 0x80131C20: nop
    
            goto L_80131C28;
    }
    // 0x80131C20: nop

    // 0x80131C24: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
L_80131C28:
    // 0x80131C28: jal         0x80131B00
    // 0x80131C2C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_2;
    // 0x80131C2C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_2:
    // 0x80131C30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131C34: jal         0x80131B00
    // 0x80131C38: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_3;
    // 0x80131C38: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    after_3:
    // 0x80131C3C: jal         0x80018994
    // 0x80131C40: subu        $a0, $s1, $v0
    ctx->r4 = SUB32(ctx->r17, ctx->r2);
    syUtilsRandIntRange(rdram, ctx);
        goto after_4;
    // 0x80131C40: subu        $a0, $s1, $v0
    ctx->r4 = SUB32(ctx->r17, ctx->r2);
    after_4:
    // 0x80131C44: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80131C48: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x80131C4C: jal         0x80131B78
    // 0x80131C50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnTitleGetShuffledFighterKind(rdram, ctx);
        goto after_5;
    // 0x80131C50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80131C54: lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XA);
    // 0x80131C58: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80131C5C: bnel        $v1, $zero, L_80131C6C
    if (ctx->r3 != 0) {
        // 0x80131C60: lbu         $t0, 0xD($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0XD);
            goto L_80131C6C;
    }
    goto skip_0;
    // 0x80131C60: lbu         $t0, 0xD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XD);
    skip_0:
    // 0x80131C64: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80131C68: lbu         $t0, 0xD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XD);
L_80131C6C:
    // 0x80131C6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131C70: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80131C74: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80131C78: or          $t3, $v1, $t2
    ctx->r11 = ctx->r3 | ctx->r10;
    // 0x80131C7C: jal         0x80131B00
    // 0x80131C80: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_6;
    // 0x80131C80: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    after_6:
    // 0x80131C84: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131C88: jal         0x80131B00
    // 0x80131C8C: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    mnTitleGetFighterKindsNum(rdram, ctx);
        goto after_7;
    // 0x80131C8C: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    after_7:
    // 0x80131C90: subu        $a0, $s1, $v0
    ctx->r4 = SUB32(ctx->r17, ctx->r2);
    // 0x80131C94: bne         $a0, $zero, L_80131CA8
    if (ctx->r4 != 0) {
        // 0x80131C98: nop
    
            goto L_80131CA8;
    }
    // 0x80131C98: nop

    // 0x80131C9C: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x80131CA0: b           L_80131CDC
    // 0x80131CA4: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
        goto L_80131CDC;
    // 0x80131CA4: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
L_80131CA8:
    // 0x80131CA8: jal         0x80018994
    // 0x80131CAC: nop

    syUtilsRandIntRange(rdram, ctx);
        goto after_8;
    // 0x80131CAC: nop

    after_8:
    // 0x80131CB0: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80131CB4: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x80131CB8: jal         0x80131B78
    // 0x80131CBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnTitleGetShuffledFighterKind(rdram, ctx);
        goto after_9;
    // 0x80131CBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x80131CC0: lhu         $t5, 0xA($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XA);
    // 0x80131CC4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80131CC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131CCC: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80131CD0: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80131CD4: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x80131CD8: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
L_80131CDC:
    // 0x80131CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131CE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CEC: jr          $ra
    // 0x80131CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itBombHeiWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801773F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801773F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801773FC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80177400: jal         0x801735A0
    // 0x80177404: addiu       $a1, $a1, 0x74B0
    ctx->r5 = ADD32(ctx->r5, 0X74B0);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80177404: addiu       $a1, $a1, 0x74B0
    ctx->r5 = ADD32(ctx->r5, 0X74B0);
    after_0:
    // 0x80177408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017740C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177414: jr          $ra
    // 0x80177418: nop

    return;
    // 0x80177418: nop

;}
RECOMP_FUNC void ftPhysicsClampAirVelY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8D10: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8D14: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8D18: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800D8D1C: nop

    // 0x800D8D20: bc1f        L_800D8D2C
    if (!c1cs) {
        // 0x800D8D24: nop
    
            goto L_800D8D2C;
    }
    // 0x800D8D24: nop

    // 0x800D8D28: swc1        $f12, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f12.u32l;
L_800D8D2C:
    // 0x800D8D2C: jr          $ra
    // 0x800D8D30: nop

    return;
    // 0x800D8D30: nop

;}
RECOMP_FUNC void ftShadowProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AE60: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x8013AE64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013AE68: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8013AE6C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8013AE70: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8013AE74: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8013AE78: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013AE7C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013AE80: sw          $a0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r4;
    // 0x8013AE84: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8013AE88: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8013AE8C: addiu       $s3, $s3, 0x65B0
    ctx->r19 = ADD32(ctx->r19, 0X65B0);
    // 0x8013AE90: bne         $t7, $zero, L_8013AF94
    if (ctx->r15 != 0) {
        // 0x8013AE94: lui         $t9, 0xDE00
        ctx->r25 = S32(0XDE00 << 16);
            goto L_8013AF94;
    }
    // 0x8013AE94: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8013AE98: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AE9C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8013AEA0: addiu       $t6, $t6, -0x7BF0
    ctx->r14 = ADD32(ctx->r14, -0X7BF0);
    // 0x8013AEA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013AEA8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013AEAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013AEB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013AEB4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AEB8: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8013AEBC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013AEC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013AEC4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013AEC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013AECC: lw          $t9, 0x13B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X13B4);
    // 0x8013AED0: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8013AED4: addiu       $t6, $t6, 0x3A68
    ctx->r14 = ADD32(ctx->r14, 0X3A68);
    // 0x8013AED8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8013AEDC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013AEE0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AEE4: lui         $t6, 0x705
    ctx->r14 = S32(0X705 << 16);
    // 0x8013AEE8: ori         $t6, $t6, 0x140
    ctx->r14 = ctx->r14 | 0X140;
    // 0x8013AEEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013AEF0: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013AEF4: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8013AEF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013AEFC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013AF00: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF04: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8013AF08: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8013AF0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013AF10: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013AF14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013AF18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013AF1C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF20: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8013AF24: ori         $t7, $t7, 0xF800
    ctx->r15 = ctx->r15 | 0XF800;
    // 0x8013AF28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013AF2C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8013AF30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013AF34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013AF38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF3C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8013AF40: lui         $t7, 0xF580
    ctx->r15 = S32(0XF580 << 16);
    // 0x8013AF44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013AF48: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013AF4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013AF50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013AF54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF58: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x8013AF5C: ori         $t8, $t8, 0x140
    ctx->r24 = ctx->r24 | 0X140;
    // 0x8013AF60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013AF64: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8013AF68: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8013AF6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013AF70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013AF74: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF78: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x8013AF7C: ori         $t7, $t7, 0xC03C
    ctx->r15 = ctx->r15 | 0XC03C;
    // 0x8013AF80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013AF84: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8013AF88: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8013AF8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013AF90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8013AF94:
    // 0x8013AF94: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8013AF98: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013AF9C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8013AFA0: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8013AFA4: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8013AFA8: addiu       $s3, $s3, 0x65B0
    ctx->r19 = ADD32(ctx->r19, 0X65B0);
    // 0x8013AFAC: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x8013AFB0: lw          $t7, 0x100($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X100);
    // 0x8013AFB4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8013AFB8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8013AFBC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013AFC0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013AFC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013AFC8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8013AFCC: lw          $s0, 0x78($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X78);
    // 0x8013AFD0: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x8013AFD4: lhu         $t7, 0x18C($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18C);
    // 0x8013AFD8: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x8013AFDC: bnel        $t6, $zero, L_8013BB38
    if (ctx->r14 != 0) {
        // 0x8013AFE0: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_0;
    // 0x8013AFE0: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_0:
    // 0x8013AFE4: lh          $t9, 0x18E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18E);
    // 0x8013AFE8: bltzl       $t9, L_8013BB38
    if (SIGNED(ctx->r25) < 0) {
        // 0x8013AFEC: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_1;
    // 0x8013AFEC: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_1:
    // 0x8013AFF0: lw          $t7, 0x14C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14C);
    // 0x8013AFF4: addiu       $a1, $sp, 0x124
    ctx->r5 = ADD32(ctx->r29, 0X124);
    // 0x8013AFF8: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x8013AFFC: bne         $t7, $zero, L_8013B01C
    if (ctx->r15 != 0) {
        // 0x8013B000: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8013B01C;
    }
    // 0x8013B000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013B004: lw          $t6, 0xEC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XEC);
    // 0x8013B008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013B00C: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x8013B010: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x8013B014: b           L_8013B03C
    // 0x8013B018: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
        goto L_8013B03C;
    // 0x8013B018: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
L_8013B01C:
    // 0x8013B01C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8013B020: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x8013B024: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013B028: jal         0x800F9348
    // 0x8013B02C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckProjectFloor(rdram, ctx);
        goto after_0;
    // 0x8013B02C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8013B030: bne         $v0, $zero, L_8013B03C
    if (ctx->r2 != 0) {
        // 0x8013B034: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8013B03C;
    }
    // 0x8013B034: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013B038: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_8013B03C:
    // 0x8013B03C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8013B040: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013B044: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x8013B048: beql        $t9, $at, L_8013BB38
    if (ctx->r25 == ctx->r1) {
        // 0x8013B04C: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_2;
    // 0x8013B04C: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_2:
    // 0x8013B050: lw          $t7, 0xEC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XEC);
    // 0x8013B054: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8013B058: beql        $t7, $at, L_8013BB38
    if (ctx->r15 == ctx->r1) {
        // 0x8013B05C: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_3;
    // 0x8013B05C: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_3:
    // 0x8013B060: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x8013B064: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8013B068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013B06C: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8013B070: addiu       $s1, $sp, 0x94
    ctx->r17 = ADD32(ctx->r29, 0X94);
    // 0x8013B074: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x8013B078: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8013B07C: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8013B080: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8013B084: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013B088: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8013B08C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013B090: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8013B094: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x8013B098: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8013B09C: sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // 0x8013B0A0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8013B0A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013B0A8: jal         0x800F7F00
    // 0x8013B0AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x8013B0AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8013B0B0: beq         $v0, $zero, L_8013B0E0
    if (ctx->r2 == 0) {
        // 0x8013B0B4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8013B0E0;
    }
    // 0x8013B0B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013B0B8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x8013B0BC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8013B0C0: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8013B0C4: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8013B0C8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8013B0CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8013B0D0: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8013B0D4: nop

    // 0x8013B0D8: bc1tl       L_8013BB38
    if (c1cs) {
        // 0x8013B0DC: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_4;
    // 0x8013B0DC: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_4:
L_8013B0E0:
    // 0x8013B0E0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8013B0E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8013B0E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013B0EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8013B0F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8013B0F4: jal         0x800F6B58
    // 0x8013B0F8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_2;
    // 0x8013B0F8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8013B0FC: beq         $v0, $zero, L_8013B12C
    if (ctx->r2 == 0) {
        // 0x8013B100: addiu       $s1, $sp, 0x118
        ctx->r17 = ADD32(ctx->r29, 0X118);
            goto L_8013B12C;
    }
    // 0x8013B100: addiu       $s1, $sp, 0x118
    ctx->r17 = ADD32(ctx->r29, 0X118);
    // 0x8013B104: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x8013B108: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8013B10C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8013B110: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8013B114: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8013B118: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8013B11C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8013B120: nop

    // 0x8013B124: bc1tl       L_8013BB38
    if (c1cs) {
        // 0x8013B128: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_5;
    // 0x8013B128: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_5:
L_8013B12C:
    // 0x8013B12C: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8013B130: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x8013B134: lui         $at, 0x44F8
    ctx->r1 = S32(0X44F8 << 16);
    // 0x8013B138: lw          $t9, 0x9C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9C8);
    // 0x8013B13C: lwc1        $f12, 0x1C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8013B140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013B144: lwc1        $f2, 0x7C($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X7C);
    // 0x8013B148: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013B14C: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8013B150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013B154: swc1        $f12, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f12.u32l;
    // 0x8013B158: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x8013B15C: swc1        $f2, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f2.u32l;
    // 0x8013B160: jal         0x800F4428
    // 0x8013B164: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x8013B164: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8013B168: addiu       $s2, $sp, 0x10C
    ctx->r18 = ADD32(ctx->r29, 0X10C);
    // 0x8013B16C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8013B170: jal         0x800F4408
    // 0x8013B174: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x8013B174: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_4:
    // 0x8013B178: lwc1        $f2, 0x134($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8013B17C: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8013B180: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B184: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8013B188: sub.s       $f20, $f12, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8013B18C: add.s       $f14, $f12, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8013B190: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8013B194: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8013B198: bc1fl       L_8013B204
    if (!c1cs) {
        // 0x8013B19C: lwc1        $f18, 0x10C($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
            goto L_8013B204;
    }
    goto skip_6;
    // 0x8013B19C: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    skip_6:
    // 0x8013B1A0: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8013B1A4: lui         $at, 0x4478
    ctx->r1 = S32(0X4478 << 16);
    // 0x8013B1A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013B1AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8013B1B0: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8013B1B4: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8013B1B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013B1BC: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
    // 0x8013B1C0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8013B1C4: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8013B1C8: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8013B1CC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8013B1D0: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x8013B1D4: bc1fl       L_8013B1E4
    if (!c1cs) {
        // 0x8013B1D8: lwc1        $f8, 0x108($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
            goto L_8013B1E4;
    }
    goto skip_7;
    // 0x8013B1D8: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    skip_7:
    // 0x8013B1DC: swc1        $f18, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f18.u32l;
    // 0x8013B1E0: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
L_8013B1E4:
    // 0x8013B1E4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8013B1E8: nop

    // 0x8013B1EC: bc1fl       L_8013B204
    if (!c1cs) {
        // 0x8013B1F0: lwc1        $f18, 0x10C($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
            goto L_8013B204;
    }
    goto skip_8;
    // 0x8013B1F0: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    skip_8:
    // 0x8013B1F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013B1F8: nop

    // 0x8013B1FC: swc1        $f4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f4.u32l;
    // 0x8013B200: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
L_8013B204:
    // 0x8013B204: lui         $at, 0x4478
    ctx->r1 = S32(0X4478 << 16);
    // 0x8013B208: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8013B20C: nop

    // 0x8013B210: bc1fl       L_8013B270
    if (!c1cs) {
        // 0x8013B214: sw          $t7, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r15;
            goto L_8013B270;
    }
    goto skip_9;
    // 0x8013B214: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    skip_9:
    // 0x8013B218: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8013B21C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013B220: mov.s       $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = ctx->f18.fl;
    // 0x8013B224: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8013B228: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013B22C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013B230: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8013B234: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013B238: div.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8013B23C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013B240: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8013B244: nop

    // 0x8013B248: bc1fl       L_8013B25C
    if (!c1cs) {
        // 0x8013B24C: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8013B25C;
    }
    goto skip_10;
    // 0x8013B24C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_10:
    // 0x8013B250: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8013B254: nop

    // 0x8013B258: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8013B25C:
    // 0x8013B25C: swc1        $f14, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f14.u32l;
    // 0x8013B260: bc1fl       L_8013B270
    if (!c1cs) {
        // 0x8013B264: sw          $t7, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r15;
            goto L_8013B270;
    }
    goto skip_11;
    // 0x8013B264: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    skip_11:
    // 0x8013B268: swc1        $f0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f0.u32l;
    // 0x8013B26C: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
L_8013B270:
    // 0x8013B270: jal         0x800FA518
    // 0x8013B274: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetVertexCountLineID(rdram, ctx);
        goto after_5;
    // 0x8013B274: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_5:
    // 0x8013B278: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8013B27C: bne         $at, $zero, L_8013B674
    if (ctx->r1 != 0) {
        // 0x8013B280: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013B674;
    }
    // 0x8013B280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B284: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8013B288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013B28C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8013B290: jal         0x800FA5E8
    // 0x8013B294: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_6;
    // 0x8013B294: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    after_6:
    // 0x8013B298: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8013B29C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013B2A0: jal         0x800FA5E8
    // 0x8013B2A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_7;
    // 0x8013B2A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x8013B2A8: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B2AC: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B2B0: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x8013B2B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013B2B8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8013B2BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8013B2C0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8013B2C4: bc1fl       L_8013B498
    if (!c1cs) {
        // 0x8013B2C8: sw          $t6, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r14;
            goto L_8013B498;
    }
    goto skip_12;
    // 0x8013B2C8: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    skip_12:
    // 0x8013B2CC: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x8013B2D0: bne         $at, $zero, L_8013B698
    if (ctx->r1 != 0) {
        // 0x8013B2D4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8013B698;
    }
    // 0x8013B2D4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8013B2D8:
    // 0x8013B2D8: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8013B2DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013B2E0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8013B2E4: jal         0x800FA5E8
    // 0x8013B2E8: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_8;
    // 0x8013B2E8: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    after_8:
    // 0x8013B2EC: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B2F0: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x8013B2F4: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B2F8: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8013B2FC: nop

    // 0x8013B300: bc1fl       L_8013B470
    if (!c1cs) {
        // 0x8013B304: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8013B470;
    }
    goto skip_13;
    // 0x8013B304: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_13:
    // 0x8013B308: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x8013B30C: nop

    // 0x8013B310: bc1fl       L_8013B470
    if (!c1cs) {
        // 0x8013B314: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8013B470;
    }
    goto skip_14;
    // 0x8013B314: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_14:
    // 0x8013B318: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013B31C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B320: jal         0x8013AE10
    // 0x8013B324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_9;
    // 0x8013B324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x8013B328: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B32C: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x8013B330: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B334: c.le.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl <= ctx->f22.fl;
    // 0x8013B338: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8013B33C: bc1fl       L_8013B36C
    if (!c1cs) {
        // 0x8013B340: sw          $t6, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r14;
            goto L_8013B36C;
    }
    goto skip_15;
    // 0x8013B340: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    skip_15:
    // 0x8013B344: c.le.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl <= ctx->f18.fl;
    // 0x8013B348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B34C: bc1fl       L_8013B36C
    if (!c1cs) {
        // 0x8013B350: sw          $t6, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r14;
            goto L_8013B36C;
    }
    goto skip_16;
    // 0x8013B350: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    skip_16:
    // 0x8013B354: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8013B358: jal         0x8013AE10
    // 0x8013B35C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_10;
    // 0x8013B35C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x8013B360: b           L_8013B698
    // 0x8013B364: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
        goto L_8013B698;
    // 0x8013B364: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8013B368: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
L_8013B36C:
    // 0x8013B36C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8013B370: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x8013B374: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x8013B378: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8013B37C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x8013B380: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8013B384: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8013B388: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8013B38C: jal         0x800FA5E8
    // 0x8013B390: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_11;
    // 0x8013B390: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_11:
    // 0x8013B394: lwc1        $f0, 0x108($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8013B398: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B39C: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8013B3A0: sub.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8013B3A4: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8013B3A8: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B3AC: sub.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x8013B3B0: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x8013B3B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B3B8: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8013B3BC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8013B3C0: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x8013B3C4: c.le.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl <= ctx->f18.fl;
    // 0x8013B3C8: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8013B3CC: div.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8013B3D0: add.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8013B3D4: bc1f        L_8013B3F0
    if (!c1cs) {
        // 0x8013B3D8: swc1        $f4, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
            goto L_8013B3F0;
    }
    // 0x8013B3D8: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8013B3DC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8013B3E0: jal         0x8013AE10
    // 0x8013B3E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_12;
    // 0x8013B3E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x8013B3E8: b           L_8013B698
    // 0x8013B3EC: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
        goto L_8013B698;
    // 0x8013B3EC: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
L_8013B3F0:
    // 0x8013B3F0: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    // 0x8013B3F4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8013B3F8: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8013B3FC: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x8013B400: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8013B404: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x8013B408: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8013B40C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8013B410: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x8013B414: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8013B418: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8013B41C: jal         0x800FA5E8
    // 0x8013B420: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_13;
    // 0x8013B420: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_13:
    // 0x8013B424: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8013B428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B42C: jal         0x8013AE10
    // 0x8013B430: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_14;
    // 0x8013B430: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_14:
    // 0x8013B434: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B438: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013B43C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8013B440: sub.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x8013B444: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8013B448: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8013B44C: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x8013B450: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8013B454: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x8013B458: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8013B45C: div.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8013B460: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013B464: b           L_8013B698
    // 0x8013B468: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
        goto L_8013B698;
    // 0x8013B468: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x8013B46C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8013B470:
    // 0x8013B470: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8013B474: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013B478: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8013B47C: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8013B480: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x8013B484: bne         $s0, $v1, L_8013B2D8
    if (ctx->r16 != ctx->r3) {
        // 0x8013B488: sw          $t7, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r15;
            goto L_8013B2D8;
    }
    // 0x8013B488: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x8013B48C: b           L_8013B69C
    // 0x8013B490: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
        goto L_8013B69C;
    // 0x8013B490: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8013B494: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
L_8013B498:
    // 0x8013B498: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8013B49C: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8013B4A0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8013B4A4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8013B4A8: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8013B4AC: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x8013B4B0: bne         $at, $zero, L_8013B698
    if (ctx->r1 != 0) {
        // 0x8013B4B4: sw          $t9, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r25;
            goto L_8013B698;
    }
    // 0x8013B4B4: sw          $t9, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r25;
L_8013B4B8:
    // 0x8013B4B8: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    // 0x8013B4BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013B4C0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8013B4C4: jal         0x800FA5E8
    // 0x8013B4C8: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_15;
    // 0x8013B4C8: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    after_15:
    // 0x8013B4CC: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B4D0: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x8013B4D4: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B4D8: c.le.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl <= ctx->f22.fl;
    // 0x8013B4DC: nop

    // 0x8013B4E0: bc1fl       L_8013B650
    if (!c1cs) {
        // 0x8013B4E4: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8013B650;
    }
    goto skip_17;
    // 0x8013B4E4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_17:
    // 0x8013B4E8: c.le.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl <= ctx->f18.fl;
    // 0x8013B4EC: nop

    // 0x8013B4F0: bc1fl       L_8013B650
    if (!c1cs) {
        // 0x8013B4F4: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_8013B650;
    }
    goto skip_18;
    // 0x8013B4F4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_18:
    // 0x8013B4F8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8013B4FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B500: jal         0x8013AE10
    // 0x8013B504: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_16;
    // 0x8013B504: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x8013B508: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B50C: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8013B510: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B514: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8013B518: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8013B51C: bc1fl       L_8013B54C
    if (!c1cs) {
        // 0x8013B520: sw          $t7, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r15;
            goto L_8013B54C;
    }
    goto skip_19;
    // 0x8013B520: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    skip_19:
    // 0x8013B524: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x8013B528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B52C: bc1fl       L_8013B54C
    if (!c1cs) {
        // 0x8013B530: sw          $t7, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r15;
            goto L_8013B54C;
    }
    goto skip_20;
    // 0x8013B530: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    skip_20:
    // 0x8013B534: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013B538: jal         0x8013AE10
    // 0x8013B53C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_17;
    // 0x8013B53C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_17:
    // 0x8013B540: b           L_8013B698
    // 0x8013B544: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
        goto L_8013B698;
    // 0x8013B544: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x8013B548: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
L_8013B54C:
    // 0x8013B54C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8013B550: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8013B554: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x8013B558: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8013B55C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8013B560: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8013B564: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8013B568: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x8013B56C: jal         0x800FA5E8
    // 0x8013B570: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_18;
    // 0x8013B570: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_18:
    // 0x8013B574: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B578: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8013B57C: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8013B580: sub.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x8013B584: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8013B588: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8013B58C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8013B590: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x8013B594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B598: sub.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8013B59C: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8013B5A0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8013B5A4: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8013B5A8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
    // 0x8013B5AC: div.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8013B5B0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013B5B4: bc1f        L_8013B5D0
    if (!c1cs) {
        // 0x8013B5B8: swc1        $f10, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
            goto L_8013B5D0;
    }
    // 0x8013B5B8: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x8013B5BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013B5C0: jal         0x8013AE10
    // 0x8013B5C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_19;
    // 0x8013B5C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_19:
    // 0x8013B5C8: b           L_8013B698
    // 0x8013B5CC: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
        goto L_8013B698;
    // 0x8013B5CC: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
L_8013B5D0:
    // 0x8013B5D0: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x8013B5D4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013B5D8: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8013B5DC: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x8013B5E0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8013B5E4: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8013B5E8: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
    // 0x8013B5EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8013B5F0: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
    // 0x8013B5F4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8013B5F8: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8013B5FC: jal         0x800FA5E8
    // 0x8013B600: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_20;
    // 0x8013B600: lw          $a0, 0x124($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X124);
    after_20:
    // 0x8013B604: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013B608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B60C: jal         0x8013AE10
    // 0x8013B610: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_21;
    // 0x8013B610: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x8013B614: lwc1        $f18, 0x10C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8013B618: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8013B61C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8013B620: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x8013B624: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8013B628: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x8013B62C: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x8013B630: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8013B634: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x8013B638: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8013B63C: div.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8013B640: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8013B644: b           L_8013B698
    // 0x8013B648: swc1        $f4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f4.u32l;
        goto L_8013B698;
    // 0x8013B648: swc1        $f4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f4.u32l;
    // 0x8013B64C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_8013B650:
    // 0x8013B650: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8013B654: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013B658: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8013B65C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8013B660: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x8013B664: bne         $s0, $v1, L_8013B4B8
    if (ctx->r16 != ctx->r3) {
        // 0x8013B668: sw          $t9, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r25;
            goto L_8013B4B8;
    }
    // 0x8013B668: sw          $t9, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r25;
    // 0x8013B66C: b           L_8013B69C
    // 0x8013B670: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
        goto L_8013B69C;
    // 0x8013B670: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
L_8013B674:
    // 0x8013B674: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013B678: jal         0x8013AE10
    // 0x8013B67C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_22;
    // 0x8013B67C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x8013B680: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8013B684: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x8013B688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013B68C: jal         0x8013AE10
    // 0x8013B690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftShadowGetAltitude(rdram, ctx);
        goto after_23;
    // 0x8013B690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x8013B694: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
L_8013B698:
    // 0x8013B698: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
L_8013B69C:
    // 0x8013B69C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8013B6A0: beql        $t7, $zero, L_8013BB38
    if (ctx->r15 == 0) {
        // 0x8013B6A4: lw          $t7, 0x148($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X148);
            goto L_8013BB38;
    }
    goto skip_21;
    // 0x8013B6A4: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    skip_21:
    // 0x8013B6A8: lw          $t6, 0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6630);
    // 0x8013B6AC: lw          $a0, 0x144($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X144);
    // 0x8013B6B0: beq         $t6, $zero, L_8013B6C4
    if (ctx->r14 == 0) {
        // 0x8013B6B4: nop
    
            goto L_8013B6C4;
    }
    // 0x8013B6B4: nop

    // 0x8013B6B8: lw          $a0, 0x144($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X144);
    // 0x8013B6BC: b           L_8013B6C4
    // 0x8013B6C0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
        goto L_8013B6C4;
    // 0x8013B6C0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
L_8013B6C4:
    // 0x8013B6C4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013B6C8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8013B6CC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8013B6D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013B6D4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013B6D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013B6DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013B6E0: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x8013B6E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013B6E8: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x8013B6EC: bnel        $t7, $at, L_8013B764
    if (ctx->r15 != ctx->r1) {
        // 0x8013B6F0: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8013B764;
    }
    goto skip_22;
    // 0x8013B6F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_22:
    // 0x8013B6F4: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x8013B6F8: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x8013B6FC: bltzl       $t9, L_8013B764
    if (SIGNED(ctx->r25) < 0) {
        // 0x8013B700: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8013B764;
    }
    goto skip_23;
    // 0x8013B700: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_23:
    // 0x8013B704: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013B708: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8013B70C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013B710: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013B714: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013B718: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8013B71C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013B720: addiu       $t6, $t6, -0x3584
    ctx->r14 = ADD32(ctx->r14, -0X3584);
    // 0x8013B724: lbu         $t9, 0xC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XC);
    // 0x8013B728: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8013B72C: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x8013B730: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8013B734: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x8013B738: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8013B73C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8013B740: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8013B744: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8013B748: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8013B74C: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x8013B750: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8013B754: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8013B758: b           L_8013B7A8
    // 0x8013B75C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_8013B7A8;
    // 0x8013B75C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013B760: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8013B764:
    // 0x8013B764: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013B768: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8013B76C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013B770: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013B774: addiu       $a1, $a1, -0x3588
    ctx->r5 = ADD32(ctx->r5, -0X3588);
    // 0x8013B778: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013B77C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8013B780: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8013B784: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x8013B788: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8013B78C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8013B790: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x8013B794: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8013B798: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8013B79C: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x8013B7A0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8013B7A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8013B7A8:
    // 0x8013B7A8: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8013B7AC: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8013B7B0: addiu       $t4, $zero, -0xC8
    ctx->r12 = ADD32(0, -0XC8);
    // 0x8013B7B4: addiu       $t5, $zero, 0x7C0
    ctx->r13 = ADD32(0, 0X7C0);
    // 0x8013B7B8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8013B7BC: addiu       $t2, $a0, 0x30
    ctx->r10 = ADD32(ctx->r4, 0X30);
    // 0x8013B7C0: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8013B7C4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8013B7C8: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8013B7CC: sh          $t3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r11;
    // 0x8013B7D0: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x8013B7D4: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8013B7D8: trunc.w.s   $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    ctx->f10.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x8013B7DC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8013B7E0: nop

    // 0x8013B7E4: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x8013B7E8: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8013B7EC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8013B7F0: sh          $t4, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r12;
    // 0x8013B7F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8013B7F8: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x8013B7FC: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x8013B800: sh          $a1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r5;
    // 0x8013B804: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8013B808: sh          $a3, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r7;
    // 0x8013B80C: sh          $a2, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r6;
    // 0x8013B810: sh          $a2, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r6;
    // 0x8013B814: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8013B818: sh          $t3, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r11;
    // 0x8013B81C: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x8013B820: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8013B824: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8013B828: nop

    // 0x8013B82C: sh          $t0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r8;
    // 0x8013B830: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8013B834: sh          $t4, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r12;
    // 0x8013B838: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x8013B83C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013B840: sh          $a3, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r7;
    // 0x8013B844: sh          $t0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r8;
    // 0x8013B848: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8013B84C: nop

    // 0x8013B850: sh          $t1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r9;
    // 0x8013B854: sh          $t1, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r9;
    // 0x8013B858: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x8013B85C: lwc1        $f8, 0xE8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8013B860: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x8013B864: bnel        $at, $zero, L_8013BB00
    if (ctx->r1 != 0) {
        // 0x8013B868: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8013BB00;
    }
    goto skip_24;
    // 0x8013B868: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_24:
    // 0x8013B86C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8013B870: addiu       $v1, $t2, 0x10
    ctx->r3 = ADD32(ctx->r10, 0X10);
    // 0x8013B874: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013B878: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8013B87C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8013B880: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013B884: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8013B888: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x8013B88C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8013B890: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8013B894: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8013B898: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013B89C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8013B8A0: nop

    // 0x8013B8A4: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    // 0x8013B8A8: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8013B8AC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8013B8B0: nop

    // 0x8013B8B4: bc1fl       L_8013B8C4
    if (!c1cs) {
        // 0x8013B8B8: lwc1        $f4, 0xF0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
            goto L_8013B8C4;
    }
    goto skip_25;
    // 0x8013B8B8: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    skip_25:
    // 0x8013B8BC: swc1        $f2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f2.u32l;
    // 0x8013B8C0: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
L_8013B8C4:
    // 0x8013B8C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8013B8C8: nop

    // 0x8013B8CC: bc1fl       L_8013B8DC
    if (!c1cs) {
        // 0x8013B8D0: lwc1        $f6, 0xF0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
            goto L_8013B8DC;
    }
    goto skip_26;
    // 0x8013B8D0: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    skip_26:
    // 0x8013B8D4: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x8013B8D8: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
L_8013B8DC:
    // 0x8013B8DC: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x8013B8E0: sh          $a2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r6;
    // 0x8013B8E4: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013B8E8: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    // 0x8013B8EC: sh          $t5, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r13;
    // 0x8013B8F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013B8F4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8013B8F8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8013B8FC: sh          $v0, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r2;
    // 0x8013B900: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    // 0x8013B904: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x8013B908: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8013B90C: bnel        $t6, $at, L_8013BAA0
    if (ctx->r14 != ctx->r1) {
        // 0x8013B910: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8013BAA0;
    }
    goto skip_27;
    // 0x8013B910: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_27:
    // 0x8013B914: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8013B918: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8013B91C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8013B920: nop

    // 0x8013B924: sh          $a3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r7;
    // 0x8013B928: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8013B92C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8013B930: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8013B934: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013B938: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8013B93C: nop

    // 0x8013B940: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x8013B944: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8013B948: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8013B94C: nop

    // 0x8013B950: bc1fl       L_8013B960
    if (!c1cs) {
        // 0x8013B954: lwc1        $f4, 0xEC($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_8013B960;
    }
    goto skip_28;
    // 0x8013B954: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    skip_28:
    // 0x8013B958: swc1        $f2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f2.u32l;
    // 0x8013B95C: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
L_8013B960:
    // 0x8013B960: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8013B964: nop

    // 0x8013B968: bc1fl       L_8013B978
    if (!c1cs) {
        // 0x8013B96C: lwc1        $f6, 0xEC($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
            goto L_8013B978;
    }
    goto skip_29;
    // 0x8013B96C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    skip_29:
    // 0x8013B970: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x8013B974: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
L_8013B978:
    // 0x8013B978: sh          $a3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r7;
    // 0x8013B97C: sh          $t0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r8;
    // 0x8013B980: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8013B984: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    // 0x8013B988: sh          $t5, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r13;
    // 0x8013B98C: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8013B990: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8013B994: ori         $t9, $t9, 0x8010
    ctx->r25 = ctx->r25 | 0X8010;
    // 0x8013B998: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8013B99C: sh          $a1, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r5;
    // 0x8013B9A0: sh          $a1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r5;
    // 0x8013B9A4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013B9A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013B9AC: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8013B9B0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8013B9B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013B9B8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8013B9BC: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8013B9C0: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x8013B9C4: beql        $t7, $zero, L_8013BA38
    if (ctx->r15 == 0) {
        // 0x8013B9C8: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8013BA38;
    }
    goto skip_30;
    // 0x8013B9C8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_30:
    // 0x8013B9CC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013B9D0: ori         $t6, $t6, 0xE
    ctx->r14 = ctx->r14 | 0XE;
    // 0x8013B9D4: addiu       $t9, $zero, 0xC0E
    ctx->r25 = ADD32(0, 0XC0E);
    // 0x8013B9D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013B9DC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013B9E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013B9E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013B9E8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013B9EC: lui         $t6, 0xC
    ctx->r14 = S32(0XC << 16);
    // 0x8013B9F0: lui         $t8, 0x60E
    ctx->r24 = S32(0X60E << 16);
    // 0x8013B9F4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013B9F8: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013B9FC: ori         $t8, $t8, 0xC0A
    ctx->r24 = ctx->r24 | 0XC0A;
    // 0x8013BA00: ori         $t6, $t6, 0x80A
    ctx->r14 = ctx->r14 | 0X80A;
    // 0x8013BA04: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013BA08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013BA0C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BA10: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8013BA14: lui         $t7, 0x60A
    ctx->r15 = S32(0X60A << 16);
    // 0x8013BA18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013BA1C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8013BA20: ori         $t7, $t7, 0x806
    ctx->r15 = ctx->r15 | 0X806;
    // 0x8013BA24: ori         $t8, $t8, 0x406
    ctx->r24 = ctx->r24 | 0X406;
    // 0x8013BA28: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013BA2C: b           L_8013BB34
    // 0x8013BA30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8013BB34;
    // 0x8013BA30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013BA34: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8013BA38:
    // 0x8013BA38: ori         $t9, $t9, 0xA
    ctx->r25 = ctx->r25 | 0XA;
    // 0x8013BA3C: addiu       $t7, $zero, 0x80A
    ctx->r15 = ADD32(0, 0X80A);
    // 0x8013BA40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013BA44: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8013BA48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013BA4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013BA50: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BA54: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8013BA58: lui         $t6, 0x60A
    ctx->r14 = S32(0X60A << 16);
    // 0x8013BA5C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013BA60: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013BA64: ori         $t6, $t6, 0x80E
    ctx->r14 = ctx->r14 | 0X80E;
    // 0x8013BA68: ori         $t9, $t9, 0xC0E
    ctx->r25 = ctx->r25 | 0XC0E;
    // 0x8013BA6C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013BA70: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013BA74: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BA78: lui         $t6, 0xC
    ctx->r14 = S32(0XC << 16);
    // 0x8013BA7C: lui         $t8, 0x60E
    ctx->r24 = S32(0X60E << 16);
    // 0x8013BA80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013BA84: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013BA88: ori         $t8, $t8, 0xC06
    ctx->r24 = ctx->r24 | 0XC06;
    // 0x8013BA8C: ori         $t6, $t6, 0x406
    ctx->r14 = ctx->r14 | 0X406;
    // 0x8013BA90: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013BA94: b           L_8013BB34
    // 0x8013BA98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_8013BB34;
    // 0x8013BA98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013BA9C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8013BAA0:
    // 0x8013BAA0: ori         $t7, $t7, 0x600C
    ctx->r15 = ctx->r15 | 0X600C;
    // 0x8013BAA4: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8013BAA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013BAAC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8013BAB0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8013BAB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013BAB8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BABC: addiu       $t9, $zero, 0x80A
    ctx->r25 = ADD32(0, 0X80A);
    // 0x8013BAC0: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x8013BAC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013BAC8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013BACC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013BAD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013BAD4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BAD8: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8013BADC: lui         $t8, 0x60A
    ctx->r24 = S32(0X60A << 16);
    // 0x8013BAE0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013BAE4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8013BAE8: ori         $t8, $t8, 0x806
    ctx->r24 = ctx->r24 | 0X806;
    // 0x8013BAEC: ori         $t6, $t6, 0x406
    ctx->r14 = ctx->r14 | 0X406;
    // 0x8013BAF0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013BAF4: b           L_8013BB34
    // 0x8013BAF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_8013BB34;
    // 0x8013BAF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013BAFC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8013BB00:
    // 0x8013BB00: ori         $t7, $t7, 0x4008
    ctx->r15 = ctx->r15 | 0X4008;
    // 0x8013BB04: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8013BB08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013BB0C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8013BB10: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8013BB14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013BB18: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BB1C: addiu       $t9, $zero, 0x406
    ctx->r25 = ADD32(0, 0X406);
    // 0x8013BB20: ori         $t6, $t6, 0x6
    ctx->r14 = ctx->r14 | 0X6;
    // 0x8013BB24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013BB28: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8013BB2C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8013BB30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8013BB34:
    // 0x8013BB34: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
L_8013BB38:
    // 0x8013BB38: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8013BB3C: bnel        $t8, $zero, L_8013BB68
    if (ctx->r24 != 0) {
        // 0x8013BB40: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8013BB68;
    }
    goto skip_31;
    // 0x8013BB40: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_31:
    // 0x8013BB44: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8013BB48: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8013BB4C: addiu       $t7, $t7, -0x7BA8
    ctx->r15 = ADD32(ctx->r15, -0X7BA8);
    // 0x8013BB50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013BB54: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8013BB58: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8013BB5C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013BB60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013BB64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8013BB68:
    // 0x8013BB68: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013BB6C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013BB70: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8013BB74: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8013BB78: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8013BB7C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8013BB80: jr          $ra
    // 0x8013BB84: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x8013BB84: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void efManagerNessPKReflectTrailMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010296C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102970: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80102974: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80102978: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010297C: addiu       $a0, $a0, -0x1B94
    ctx->r4 = ADD32(ctx->r4, -0X1B94);
    // 0x80102980: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80102984: jal         0x800FDAFC
    // 0x80102988: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102988: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8010298C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80102990: bne         $v0, $zero, L_801029A0
    if (ctx->r2 != 0) {
        // 0x80102994: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801029A0;
    }
    // 0x80102994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102998: b           L_801029E8
    // 0x8010299C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801029E8;
    // 0x8010299C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801029A0:
    // 0x801029A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801029A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801029A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801029AC: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x801029B0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x801029B4: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801029B8: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x801029BC: lw          $t8, 0x74($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X74);
    // 0x801029C0: lwc1        $f8, 0xA0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA0C);
    // 0x801029C4: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x801029C8: lwc1        $f6, 0x38($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X38);
    // 0x801029CC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801029D0: swc1        $f10, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f10.u32l;
    // 0x801029D4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801029D8: sw          $a0, 0x2B8($t0)
    MEM_W(0X2B8, ctx->r8) = ctx->r4;
    // 0x801029DC: jal         0x801028C0
    // 0x801029E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    efManagerNessPKReflectTrailProcUpdate(rdram, ctx);
        goto after_1;
    // 0x801029E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x801029E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_801029E8:
    // 0x801029E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801029EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801029F0: jr          $ra
    // 0x801029F4: nop

    return;
    // 0x801029F4: nop

;}
RECOMP_FUNC void ftFoxSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BC68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BC6C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015BC70: jr          $ra
    // 0x8015BC74: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015BC74: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void ftCommonYoshiEggProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CF0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014CF10: addiu       $t6, $zero, 0xFA
    ctx->r14 = ADD32(0, 0XFA);
    // 0x8014CF14: sh          $t6, 0xB1E($v0)
    MEM_H(0XB1E, ctx->r2) = ctx->r14;
    // 0x8014CF18: jr          $ra
    // 0x8014CF1C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x8014CF1C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void ftSamusSpecialNProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D33C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D340: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015D344: jal         0x8015D300
    // 0x8015D348: sw          $zero, 0xADC($a0)
    MEM_W(0XADC, ctx->r4) = 0;
    ftSamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_0;
    // 0x8015D348: sw          $zero, 0xADC($a0)
    MEM_W(0XADC, ctx->r4) = 0;
    after_0:
    // 0x8015D34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D354: jr          $ra
    // 0x8015D358: nop

    return;
    // 0x8015D358: nop

;}
RECOMP_FUNC void func_8002909C_29C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002909C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800290A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800290A4: jr          $ra
    // 0x800290A8: sh          $a0, -0x2CE4($at)
    MEM_H(-0X2CE4, ctx->r1) = ctx->r4;
    return;
    // 0x800290A8: sh          $a0, -0x2CE4($at)
    MEM_H(-0X2CE4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void mvOpeningSectorCockpitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013215C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132160: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132164: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132168: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013216C: lwc1        $f4, 0x29FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X29FC);
    // 0x80132170: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80132174: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132178: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8013217C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132180: nop

    // 0x80132184: bc1fl       L_80132194
    if (!c1cs) {
        // 0x80132188: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80132194;
    }
    goto skip_0;
    // 0x80132188: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8013218C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80132190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80132194:
    // 0x80132194: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80132198: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013219C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x801321A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801321A4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801321A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801321AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801321B0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801321B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801321B8: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801321BC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801321C0: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801321C4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801321C8: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801321CC: div.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801321D0: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x801321D4: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801321D8: jr          $ra
    // 0x801321DC: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x801321DC: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void itRShellThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017ABA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017ABA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017ABA8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017ABAC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017ABB0: addiu       $a3, $a3, -0x4F2C
    ctx->r7 = ADD32(ctx->r7, -0X4F2C);
    // 0x8017ABB4: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x8017ABB8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8017ABBC: jal         0x80173C68
    // 0x8017ABC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itMapCheckLanding(rdram, ctx);
        goto after_0;
    // 0x8017ABC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017ABC4: beq         $v0, $zero, L_8017AC2C
    if (ctx->r2 == 0) {
        // 0x8017ABC8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8017AC2C;
    }
    // 0x8017ABC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017ABCC: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017ABD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017ABD4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8017ABD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017ABDC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8017ABE0: nop

    // 0x8017ABE4: bc1fl       L_8017ABF8
    if (!c1cs) {
        // 0x8017ABE8: sw          $t7, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r15;
            goto L_8017ABF8;
    }
    goto skip_0;
    // 0x8017ABE8: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    skip_0:
    // 0x8017ABEC: b           L_8017ABF8
    // 0x8017ABF0: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
        goto L_8017ABF8;
    // 0x8017ABF0: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
    // 0x8017ABF4: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
L_8017ABF8:
    // 0x8017ABF8: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x8017ABFC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8017AC00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017AC04: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8017AC08: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8017AC0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017AC10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017AC14: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017AC18: lwc1        $f8, -0x325C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X325C);
    // 0x8017AC1C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017AC20: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017AC24: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017AC28: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
L_8017AC2C:
    // 0x8017AC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AC30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017AC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017AC38: jr          $ra
    // 0x8017AC3C: nop

    return;
    // 0x8017AC3C: nop

;}

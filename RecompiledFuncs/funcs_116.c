#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnDataMakeOptionTab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C2C: lw          $t6, 0x3160($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3160);
    // 0x80131C30: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C38: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131C3C: addiu       $t7, $t7, 0x1E8
    ctx->r15 = ADD32(ctx->r15, 0X1E8);
    // 0x80131C40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131C44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80131C48: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80131C4C: jal         0x800CCFDC
    // 0x80131C50: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131C50: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80131C54: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C58: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131C5C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80131C60: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131C64: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131C68: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131C6C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131C70: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131C74: addiu       $t3, $t3, 0x330
    ctx->r11 = ADD32(ctx->r11, 0X330);
    // 0x80131C78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131C7C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131C80: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C84: lw          $t2, 0x3160($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3160);
    // 0x80131C88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131C8C: jal         0x800CCFDC
    // 0x80131C90: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131C90: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80131C94: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C98: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80131C9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131CA0: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80131CA4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131CA8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80131CAC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131CB0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131CB4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80131CB8: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x80131CBC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131CC0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131CC4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80131CC8: addiu       $t1, $t1, 0x568
    ctx->r9 = ADD32(ctx->r9, 0X568);
    // 0x80131CCC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131CD0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131CD4: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80131CD8: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80131CDC: sb          $t8, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r24;
    // 0x80131CE0: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80131CE4: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x80131CE8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80131CEC: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x80131CF0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80131CF4: sh          $v1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r3;
    // 0x80131CF8: lw          $t0, 0x3160($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3160);
    // 0x80131CFC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131D00: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80131D04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131D08: jal         0x800CCFDC
    // 0x80131D0C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131D0C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x80131D10: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D14: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80131D18: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D1C: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80131D20: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80131D24: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80131D28: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131D2C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80131D30: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131D34: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80131D38: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131D3C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131D40: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80131D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D4C: jr          $ra
    // 0x80131D50: nop

    return;
    // 0x80131D50: nop

;}
RECOMP_FUNC void itSawamuraCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182B3C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80182B40: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80182B44: jal         0x801737B8
    // 0x80182B48: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80182B48: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80182B4C: beq         $v0, $zero, L_80182B60
    if (ctx->r2 == 0) {
        // 0x80182B50: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80182B60;
    }
    // 0x80182B50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80182B54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182B58: nop

    // 0x80182B5C: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_80182B60:
    // 0x80182B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182B6C: jr          $ra
    // 0x80182B70: nop

    return;
    // 0x80182B70: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMovePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D84: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80135D88: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135D8C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135D90: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135D94: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135D98: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80135D9C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135DA0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80135DA4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80135DA8: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80135DAC: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    // 0x80135DB0: lwc1        $f4, 0x58($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80135DB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135DB8: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80135DBC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80135DC0: lwc1        $f16, 0x90($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X90);
    // 0x80135DC4: lw          $v1, 0x74($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X74);
    // 0x80135DC8: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80135DCC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80135DD0: jr          $ra
    // 0x80135DD4: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x80135DD4: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void wpNessPKReflectHeadProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B87C: jal         0x8016B6A0
    // 0x8016B880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKReflectHeadSetDestroyTrails(rdram, ctx);
        goto after_0;
    // 0x8016B880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016B884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B890: jr          $ra
    // 0x8016B894: nop

    return;
    // 0x8016B894: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeBestTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336B4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801336B8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801336BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801336C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801336C4: addiu       $t7, $t7, 0x73A4
    ctx->r15 = ADD32(ctx->r15, 0X73A4);
    // 0x801336C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801336CC: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x801336D0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801336D4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801336D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801336DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801336E0: addiu       $t1, $t1, 0x73B0
    ctx->r9 = ADD32(ctx->r9, 0X73B0);
    // 0x801336E4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801336E8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801336EC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801336F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801336F4: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x801336F8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801336FC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133700: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133704: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133708: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8013370C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80133710: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80133714: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80133718: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8013371C: jal         0x80134E50
    // 0x80133720: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    mnPlayers1PBonusGetForcePuckFighterKind(rdram, ctx);
        goto after_0;
    // 0x80133720: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x80133724: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133728: lw          $a0, 0x76FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76FC);
    // 0x8013372C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133730: beql        $a0, $zero, L_8013374C
    if (ctx->r4 == 0) {
        // 0x80133734: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_8013374C;
    }
    goto skip_0;
    // 0x80133734: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    skip_0:
    // 0x80133738: jal         0x80009A84
    // 0x8013373C: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8013373C: nop

    after_1:
    // 0x80133740: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133744: sw          $zero, 0x76FC($at)
    MEM_W(0X76FC, ctx->r1) = 0;
    // 0x80133748: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
L_8013374C:
    // 0x8013374C: beql        $s0, $at, L_80133980
    if (ctx->r16 == ctx->r1) {
        // 0x80133750: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80133980;
    }
    goto skip_1;
    // 0x80133750: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80133754: jal         0x80133410
    // 0x80133758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetBestTime(rdram, ctx);
        goto after_2;
    // 0x80133758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013375C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80133760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133768: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8013376C: jal         0x80009968
    // 0x80133770: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80133770: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133774: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133778: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013377C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133780: sw          $v0, 0x76FC($at)
    MEM_W(0X76FC, ctx->r1) = ctx->r2;
    // 0x80133784: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133788: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8013378C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133794: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80133798: jal         0x80009DF4
    // 0x8013379C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8013379C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801337A0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801337A4: lw          $t5, 0x7E0C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7E0C);
    // 0x801337A8: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801337AC: addiu       $t6, $t6, 0x12E0
    ctx->r14 = ADD32(ctx->r14, 0X12E0);
    // 0x801337B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801337B4: jal         0x800CCFDC
    // 0x801337B8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801337B8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x801337BC: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801337C0: lui         $at, 0x4331
    ctx->r1 = S32(0X4331 << 16);
    // 0x801337C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801337C8: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x801337CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801337D0: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801337D4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801337D8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801337DC: addiu       $t1, $zero, 0x7E
    ctx->r9 = ADD32(0, 0X7E);
    // 0x801337E0: addiu       $t2, $zero, 0x7C
    ctx->r10 = ADD32(0, 0X7C);
    // 0x801337E4: addiu       $t3, $zero, 0x77
    ctx->r11 = ADD32(0, 0X77);
    // 0x801337E8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801337EC: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x801337F0: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x801337F4: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x801337F8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801337FC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133800: jal         0x80133488
    // 0x80133804: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PBonusGetMins(rdram, ctx);
        goto after_6;
    // 0x80133804: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80133808: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x8013380C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80133810: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133814: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133818: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8013381C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80133820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133828: lui         $a2, 0x436D
    ctx->r6 = S32(0X436D << 16);
    // 0x8013382C: jal         0x80131CEC
    // 0x80133830: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_7;
    // 0x80133830: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    after_7:
    // 0x80133834: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133838: lw          $t7, 0x7E0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E0C);
    // 0x8013383C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133840: addiu       $t8, $t8, 0x1F48
    ctx->r24 = ADD32(ctx->r24, 0X1F48);
    // 0x80133844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133848: jal         0x800CCFDC
    // 0x8013384C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x8013384C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x80133850: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133854: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x80133858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013385C: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80133860: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133864: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80133868: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013386C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133870: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x80133874: addiu       $t4, $zero, 0x7C
    ctx->r12 = ADD32(0, 0X7C);
    // 0x80133878: addiu       $t5, $zero, 0x77
    ctx->r13 = ADD32(0, 0X77);
    // 0x8013387C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133880: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80133884: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80133888: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x8013388C: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133890: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80133894: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133898: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013389C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801338A0: jal         0x8013349C
    // 0x801338A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PBonusGetSec(rdram, ctx);
        goto after_9;
    // 0x801338A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x801338A8: lui         $a2, 0x4381
    ctx->r6 = S32(0X4381 << 16);
    // 0x801338AC: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x801338B0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801338B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801338B8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801338BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801338C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801338C4: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x801338C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801338CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801338D0: jal         0x80131CEC
    // 0x801338D4: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_10;
    // 0x801338D4: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    after_10:
    // 0x801338D8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801338DC: lw          $t9, 0x7E0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E0C);
    // 0x801338E0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801338E4: addiu       $t0, $t0, 0x1FC8
    ctx->r8 = ADD32(ctx->r8, 0X1FC8);
    // 0x801338E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801338EC: jal         0x800CCFDC
    // 0x801338F0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_11;
    // 0x801338F0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_11:
    // 0x801338F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338F8: lwc1        $f16, 0x75E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75E4);
    // 0x801338FC: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80133900: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80133904: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133908: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x8013390C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133910: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80133914: addiu       $t5, $zero, 0x7E
    ctx->r13 = ADD32(0, 0X7E);
    // 0x80133918: addiu       $t6, $zero, 0x7C
    ctx->r14 = ADD32(0, 0X7C);
    // 0x8013391C: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x80133920: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80133924: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80133928: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8013392C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80133930: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80133934: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80133938: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x8013393C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80133940: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133944: jal         0x801334C0
    // 0x80133948: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PBonusGetCSec(rdram, ctx);
        goto after_12;
    // 0x80133948: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_12:
    // 0x8013394C: lui         $a2, 0x438D
    ctx->r6 = S32(0X438D << 16);
    // 0x80133950: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x80133954: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133958: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013395C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80133960: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80133964: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80133968: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8013396C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133970: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133974: jal         0x80131CEC
    // 0x80133978: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_13;
    // 0x80133978: lui         $a3, 0x4343
    ctx->r7 = S32(0X4343 << 16);
    after_13:
    // 0x8013397C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80133980:
    // 0x80133980: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133984: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80133988: jr          $ra
    // 0x8013398C: nop

    return;
    // 0x8013398C: nop

;}
RECOMP_FUNC void mnOptionMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132484: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132488: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013248C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132498: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013249C: jal         0x80009968
    // 0x801324A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801324A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801324A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801324A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801324AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801324B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801324B4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801324B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801324BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801324C0: jal         0x80009DF4
    // 0x801324C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801324C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801324C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801324CC: lw          $t7, 0x38B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B0);
    // 0x801324D0: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801324D4: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x801324D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324DC: jal         0x800CCFDC
    // 0x801324E0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801324E0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801324E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801324F0: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x801324F4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x801324F8: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x801324FC: lw          $t9, 0x38B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38B0);
    // 0x80132500: addiu       $v1, $v1, 0x2A30
    ctx->r3 = ADD32(ctx->r3, 0X2A30);
    // 0x80132504: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80132508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013250C: jal         0x800CCFDC
    // 0x80132510: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132510: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    after_3:
    // 0x80132514: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80132518: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x8013251C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80132520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132524: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x80132528: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013252C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132530: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132534: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132538: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x8013253C: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80132540: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80132544: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132548: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x8013254C: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132550: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132554: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132558: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013255C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132560: lw          $t7, 0x38B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B0);
    // 0x80132564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132568: jal         0x800CCFDC
    // 0x8013256C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013256C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_4:
    // 0x80132570: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132574: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80132578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013257C: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x80132580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132584: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132588: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8013258C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132590: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80132594: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80132598: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8013259C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801325A0: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801325A4: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801325A8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x801325AC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801325B0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801325B4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801325B8: lw          $t5, 0x38B4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X38B4);
    // 0x801325BC: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x801325C0: addiu       $t6, $t6, -0x46A8
    ctx->r14 = ADD32(ctx->r14, -0X46A8);
    // 0x801325C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801325C8: jal         0x800CCFDC
    // 0x801325CC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801325CC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x801325D0: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801325D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801325D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801325DC: addiu       $v1, $zero, 0x99
    ctx->r3 = ADD32(0, 0X99);
    // 0x801325E0: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801325E4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801325E8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801325EC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801325F0: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801325F4: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801325F8: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801325FC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132600: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013260C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80132610: jr          $ra
    // 0x80132614: nop

    return;
    // 0x80132614: nop

;}
RECOMP_FUNC void itFFlowerFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175B28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175B2C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80175B30: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175B34: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80175B38: jal         0x80172558
    // 0x80175B3C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80175B3C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80175B40: jal         0x801713F4
    // 0x80175B44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80175B44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80175B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175B54: jr          $ra
    // 0x80175B58: nop

    return;
    // 0x80175B58: nop

;}
RECOMP_FUNC void lbBackupIsSramValid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D464C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800D4650: addiu       $a1, $a1, 0x44E0
    ctx->r5 = ADD32(ctx->r5, 0X44E0);
    // 0x800D4654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4658: jal         0x80002DA4
    // 0x800D465C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    syDmaReadSram(rdram, ctx);
        goto after_0;
    // 0x800D465C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    after_0:
    // 0x800D4660: jal         0x800D45A4
    // 0x800D4664: nop

    lbBackupIsChecksumValid(rdram, ctx);
        goto after_1;
    // 0x800D4664: nop

    after_1:
    // 0x800D4668: bne         $v0, $zero, L_800D46E0
    if (ctx->r2 != 0) {
        // 0x800D466C: addiu       $a0, $zero, 0x5F0
        ctx->r4 = ADD32(0, 0X5F0);
            goto L_800D46E0;
    }
    // 0x800D466C: addiu       $a0, $zero, 0x5F0
    ctx->r4 = ADD32(0, 0X5F0);
    // 0x800D4670: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800D4674: addiu       $a1, $a1, 0x44E0
    ctx->r5 = ADD32(ctx->r5, 0X44E0);
    // 0x800D4678: jal         0x80002DA4
    // 0x800D467C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    syDmaReadSram(rdram, ctx);
        goto after_2;
    // 0x800D467C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    after_2:
    // 0x800D4680: jal         0x800D45A4
    // 0x800D4684: nop

    lbBackupIsChecksumValid(rdram, ctx);
        goto after_3;
    // 0x800D4684: nop

    after_3:
    // 0x800D4688: bne         $v0, $zero, L_800D46D8
    if (ctx->r2 != 0) {
        // 0x800D468C: lui         $t6, 0x800A
        ctx->r14 = S32(0X800A << 16);
            goto L_800D46D8;
    }
    // 0x800D468C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D4690: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800D4694: addiu       $t7, $t7, 0x3994
    ctx->r15 = ADD32(ctx->r15, 0X3994);
    // 0x800D4698: addiu       $t0, $t7, 0x5E8
    ctx->r8 = ADD32(ctx->r15, 0X5E8);
    // 0x800D469C: addiu       $t6, $t6, 0x44E0
    ctx->r14 = ADD32(ctx->r14, 0X44E0);
L_800D46A0:
    // 0x800D46A0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D46A4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800D46A8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800D46AC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x800D46B0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800D46B4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x800D46B8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D46BC: bne         $t7, $t0, L_800D46A0
    if (ctx->r15 != ctx->r8) {
        // 0x800D46C0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_800D46A0;
    }
    // 0x800D46C0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x800D46C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D46C8: jal         0x800D45F4
    // 0x800D46CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    lbBackupWrite(rdram, ctx);
        goto after_4;
    // 0x800D46CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    after_4:
    // 0x800D46D0: b           L_800D46E4
    // 0x800D46D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D46E4;
    // 0x800D46D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D46D8:
    // 0x800D46D8: jal         0x800D45F4
    // 0x800D46DC: nop

    lbBackupWrite(rdram, ctx);
        goto after_5;
    // 0x800D46DC: nop

    after_5:
L_800D46E0:
    // 0x800D46E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D46E4:
    // 0x800D46E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D46E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D46EC: jr          $ra
    // 0x800D46F0: nop

    return;
    // 0x800D46F0: nop

;}
RECOMP_FUNC void itHeartWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174788: jal         0x80172E74
    // 0x8017478C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x8017478C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174790: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174794: addiu       $a1, $a1, -0x67FC
    ctx->r5 = ADD32(ctx->r5, -0X67FC);
    // 0x80174798: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017479C: jal         0x80172EC8
    // 0x801747A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801747A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801747A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801747A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801747AC: jr          $ra
    // 0x801747B0: nop

    return;
    // 0x801747B0: nop

;}
RECOMP_FUNC void sc1PStageUpdateBonusStatAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133F54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133F58: lw          $t6, 0x5340($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5340);
    // 0x80133F5C: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x80133F60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133F64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133F68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133F6C: bne         $v0, $t6, L_80133FF8
    if (ctx->r2 != ctx->r14) {
        // 0x80133F70: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80133FF8;
    }
    // 0x80133F70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133F74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133F78: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133F7C: addiu       $s1, $s1, 0x5378
    ctx->r17 = ADD32(ctx->r17, 0X5378);
    // 0x80133F80: addiu       $s0, $s0, 0x5350
    ctx->r16 = ADD32(ctx->r16, 0X5350);
    // 0x80133F84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80133F88:
    // 0x80133F88: beql        $a0, $zero, L_80133F9C
    if (ctx->r4 == 0) {
        // 0x80133F8C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80133F9C;
    }
    goto skip_0;
    // 0x80133F8C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80133F90: jal         0x80009A84
    // 0x80133F94: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133F94: nop

    after_0:
    // 0x80133F98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80133F9C:
    // 0x80133F9C: bnel        $s0, $s1, L_80133F88
    if (ctx->r16 != ctx->r17) {
        // 0x80133FA0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80133F88;
    }
    goto skip_1;
    // 0x80133FA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80133FA4: jal         0x801336F8
    // 0x80133FA8: nop

    sc1PStageClearGetUpdateBonusStatPointsAll(rdram, ctx);
        goto after_1;
    // 0x80133FA8: nop

    after_1:
    // 0x80133FAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133FB0: addiu       $v1, $v1, 0x52E8
    ctx->r3 = ADD32(ctx->r3, 0X52E8);
    // 0x80133FB4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80133FB8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133FBC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133FC0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80133FC4: bgez        $t8, L_80133FD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80133FC8: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80133FD0;
    }
    // 0x80133FC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133FCC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80133FD0:
    // 0x80133FD0: lw          $t0, 0x5330($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5330);
    // 0x80133FD4: lw          $t2, 0x52CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X52CC);
    // 0x80133FD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FDC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80133FE0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80133FE4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80133FE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80133FEC: addiu       $t4, $t3, 0x14
    ctx->r12 = ADD32(ctx->r11, 0X14);
    // 0x80133FF0: b           L_80134068
    // 0x80133FF4: sw          $t4, 0x5344($at)
    MEM_W(0X5344, ctx->r1) = ctx->r12;
        goto L_80134068;
    // 0x80133FF4: sw          $t4, 0x5344($at)
    MEM_W(0X5344, ctx->r1) = ctx->r12;
L_80133FF8:
    // 0x80133FF8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133FFC: lw          $t5, 0x5344($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5344);
    // 0x80134000: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134004: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134008: bne         $v0, $t5, L_80134050
    if (ctx->r2 != ctx->r13) {
        // 0x8013400C: nop
    
            goto L_80134050;
    }
    // 0x8013400C: nop

    // 0x80134010: jal         0x80009A84
    // 0x80134014: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80134014: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_2:
    // 0x80134018: jal         0x80133F00
    // 0x8013401C: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_3;
    // 0x8013401C: nop

    after_3:
    // 0x80134020: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134024: lw          $t7, 0x5338($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5338);
    // 0x80134028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013402C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134030: beq         $t7, $zero, L_80134068
    if (ctx->r15 == 0) {
        // 0x80134034: sw          $t6, 0x5334($at)
        MEM_W(0X5334, ctx->r1) = ctx->r14;
            goto L_80134068;
    }
    // 0x80134034: sw          $t6, 0x5334($at)
    MEM_W(0X5334, ctx->r1) = ctx->r14;
    // 0x80134038: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013403C: lw          $t8, 0x52CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X52CC);
    // 0x80134040: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134044: addiu       $t9, $t8, 0x14
    ctx->r25 = ADD32(ctx->r24, 0X14);
    // 0x80134048: b           L_80134068
    // 0x8013404C: sw          $t9, 0x5348($at)
    MEM_W(0X5348, ctx->r1) = ctx->r25;
        goto L_80134068;
    // 0x8013404C: sw          $t9, 0x5348($at)
    MEM_W(0X5348, ctx->r1) = ctx->r25;
L_80134050:
    // 0x80134050: lw          $t0, 0x5348($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5348);
    // 0x80134054: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134058: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013405C: bnel        $v0, $t0, L_8013406C
    if (ctx->r2 != ctx->r8) {
        // 0x80134060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013406C;
    }
    goto skip_2;
    // 0x80134060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80134064: sw          $t1, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r9;
L_80134068:
    // 0x80134068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013406C:
    // 0x8013406C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134070: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80134074: jr          $ra
    // 0x80134078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80134078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PIntroFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132BDC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132BE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80132BE4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80132BE8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80132BEC: lw          $a1, 0x178($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X178);
    // 0x80132BF0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80132BF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80132BF8: bc1fl       L_80132C38
    if (!c1cs) {
        // 0x80132BFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132C38;
    }
    goto skip_0;
    // 0x80132BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132C00: jal         0x80132B80
    // 0x80132C04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sc1PIntroGetFighterVelocityZ(rdram, ctx);
        goto after_0;
    // 0x80132C04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80132C08: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80132C0C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80132C10: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80132C14: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80132C18: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80132C1C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80132C20: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80132C24: nop

    // 0x80132C28: bc1fl       L_80132C38
    if (!c1cs) {
        // 0x80132C2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132C38;
    }
    goto skip_1;
    // 0x80132C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132C30: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x80132C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132C38:
    // 0x80132C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132C3C: jr          $ra
    // 0x80132C40: nop

    return;
    // 0x80132C40: nop

;}
RECOMP_FUNC void syMatrixLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A37C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8001A380: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001A384: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001A388: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001A38C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001A390: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001A394: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001A398: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001A39C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001A3A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001A3A4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8001A3A8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001A3AC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001A3B0: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8001A3B4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8001A3B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001A3BC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001A3C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001A3C4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001A3C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001A3CC: jal         0x8001A0F0
    // 0x8001A3D0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_0;
    // 0x8001A3D0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001A3D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8001A3D8: jal         0x80019C70
    // 0x8001A3DC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001A3DC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x8001A3E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A3E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8001A3E8: jr          $ra
    // 0x8001A3EC: nop

    return;
    // 0x8001A3EC: nop

;}
RECOMP_FUNC void itFFlowerWeaponFlameProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175E10: jal         0x80167C04
    // 0x80175E14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80175E14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175E18: beq         $v0, $zero, L_80175E38
    if (ctx->r2 == 0) {
        // 0x80175E1C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80175E38;
    }
    // 0x80175E1C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80175E20: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80175E24: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80175E28: jal         0x800FF648
    // 0x80175E2C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80175E2C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80175E30: b           L_80175E3C
    // 0x80175E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80175E3C;
    // 0x80175E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80175E38:
    // 0x80175E38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80175E3C:
    // 0x80175E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175E44: jr          $ra
    // 0x80175E48: nop

    return;
    // 0x80175E48: nop

;}
RECOMP_FUNC void func_ovl8_8037169C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037169C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803716A0: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x803716A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803716A8: beq         $at, $zero, L_803716B4
    if (ctx->r1 == 0) {
        // 0x803716AC: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_803716B4;
    }
    // 0x803716AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803716B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_803716B4:
    // 0x803716B4: addiu       $a0, $a1, 0xF
    ctx->r4 = ADD32(ctx->r5, 0XF);
    // 0x803716B8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x803716BC: jal         0x803714B4
    // 0x803716C0: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    func_ovl8_803714B4(rdram, ctx);
        goto after_0;
    // 0x803716C0: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    after_0:
    // 0x803716C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803716C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803716CC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x803716D0: jr          $ra
    // 0x803716D4: nop

    return;
    // 0x803716D4: nop

;}
RECOMP_FUNC void func_ovl8_8037F300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037F304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F30C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037F310: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037F314: bne         $a0, $zero, L_8037F32C
    if (ctx->r4 != 0) {
        // 0x8037F318: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037F32C;
    }
    // 0x8037F318: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037F31C: jal         0x803717A0
    // 0x8037F320: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037F320: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x8037F324: beq         $v0, $zero, L_8037F394
    if (ctx->r2 == 0) {
        // 0x8037F328: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037F394;
    }
    // 0x8037F328: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037F32C:
    // 0x8037F32C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F330: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037F334: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    // 0x8037F338: bnel        $t6, $zero, L_8037F35C
    if (ctx->r14 != 0) {
        // 0x8037F33C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037F35C;
    }
    goto skip_0;
    // 0x8037F33C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8037F340: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037F344: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8037F348: jal         0x803717E0
    // 0x8037F34C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037F34C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037F350: jal         0x8037C2D0
    // 0x8037F354: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037F354: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037F358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037F35C:
    // 0x8037F35C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F360: jal         0x803733AC
    // 0x8037F364: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803733AC(rdram, ctx);
        goto after_3;
    // 0x8037F364: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037F368: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037F36C: addiu       $t7, $t7, -0x50C8
    ctx->r15 = ADD32(ctx->r15, -0X50C8);
    // 0x8037F370: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x8037F374: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F378: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037F37C: addiu       $t8, $t8, -0x4FE8
    ctx->r24 = ADD32(ctx->r24, -0X4FE8);
    // 0x8037F380: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8037F384: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037F388: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037F38C: addiu       $t0, $t0, -0x4E90
    ctx->r8 = ADD32(ctx->r8, -0X4E90);
    // 0x8037F390: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_8037F394:
    // 0x8037F394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037F398: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037F39C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F3A0: jr          $ra
    // 0x8037F3A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037F3A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftMainUpdateVelDamageGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1FE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E1FE4: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E1FE8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E1FEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800E1FF0: nop

    // 0x800E1FF4: bc1fl       L_800E2024
    if (!c1cs) {
        // 0x800E1FF8: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800E2024;
    }
    goto skip_0;
    // 0x800E1FF8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_0:
    // 0x800E1FFC: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800E2000: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x800E2004: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E2008: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800E200C: nop

    // 0x800E2010: bc1f        L_800E2040
    if (!c1cs) {
        // 0x800E2014: nop
    
            goto L_800E2040;
    }
    // 0x800E2014: nop

    // 0x800E2018: jr          $ra
    // 0x800E201C: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800E201C: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x800E2020: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
L_800E2024:
    // 0x800E2024: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x800E2028: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E202C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800E2030: nop

    // 0x800E2034: bc1f        L_800E2040
    if (!c1cs) {
        // 0x800E2038: nop
    
            goto L_800E2040;
    }
    // 0x800E2038: nop

    // 0x800E203C: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
L_800E2040:
    // 0x800E2040: jr          $ra
    // 0x800E2044: nop

    return;
    // 0x800E2044: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132030: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132034: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132038: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013203C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132040: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80132044: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132048: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8013204C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132050: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132054: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132058: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013205C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132060: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132064: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132068: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013206C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132070: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132074: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132078: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013207C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132080: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132088: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013208C: jal         0x8000B93C
    // 0x80132090: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132090: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132094: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132098: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013209C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801320A0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801320A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801320AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801320B0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801320B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801320B8: jal         0x80007080
    // 0x801320BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801320BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801320C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801320C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801320C8: jr          $ra
    // 0x801320CC: nop

    return;
    // 0x801320CC: nop

;}
RECOMP_FUNC void ftLinkSpecialAirHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163FB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163FB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80163FB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163FBC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80163FC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80163FC4: nop

    // 0x80163FC8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80163FCC: nop

    // 0x80163FD0: bc1fl       L_80164024
    if (!c1cs) {
        // 0x80163FD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80164024;
    }
    goto skip_0;
    // 0x80163FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80163FD8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80163FDC: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    // 0x80163FE0: beq         $v0, $zero, L_80163FF0
    if (ctx->r2 == 0) {
        // 0x80163FE4: nop
    
            goto L_80163FF0;
    }
    // 0x80163FE4: nop

    // 0x80163FE8: jal         0x80163B40
    // 0x80163FEC: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    ftLinkSpecialHiDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x80163FEC: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    after_0:
L_80163FF0:
    // 0x80163FF0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80163FF4: lwc1        $f8, -0x35D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X35D8);
    // 0x80163FF8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80163FFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80164000: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80164004: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80164008: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016400C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80164010: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80164014: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80164018: jal         0x801438F0
    // 0x8016401C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016401C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80164020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80164024:
    // 0x80164024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80164028: jr          $ra
    // 0x8016402C: nop

    return;
    // 0x8016402C: nop

;}
RECOMP_FUNC void scAutoDemoDetectExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D138: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8018D13C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8018D140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D144: addiu       $a0, $a0, 0x5250
    ctx->r4 = ADD32(ctx->r4, 0X5250);
    // 0x8018D148: addiu       $v0, $v0, 0x5228
    ctx->r2 = ADD32(ctx->r2, 0X5228);
    // 0x8018D14C: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
L_8018D150:
    // 0x8018D150: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8018D154: andi        $t6, $v1, 0xD000
    ctx->r14 = ctx->r3 & 0XD000;
    // 0x8018D158: beq         $t6, $zero, L_8018D184
    if (ctx->r14 == 0) {
        // 0x8018D15C: nop
    
            goto L_8018D184;
    }
    // 0x8018D15C: nop

    // 0x8018D160: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D164: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D168: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8018D16C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D170: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8018D174: jal         0x80005C74
    // 0x8018D178: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x8018D178: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_0:
    // 0x8018D17C: b           L_8018D190
    // 0x8018D180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018D190;
    // 0x8018D180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D184:
    // 0x8018D184: bnel        $v0, $a0, L_8018D150
    if (ctx->r2 != ctx->r4) {
        // 0x8018D188: lhu         $v1, 0x2($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X2);
            goto L_8018D150;
    }
    goto skip_0;
    // 0x8018D188: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    skip_0:
    // 0x8018D18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D190:
    // 0x8018D190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D194: jr          $ra
    // 0x8018D198: nop

    return;
    // 0x8018D198: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160B70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160B78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80160B7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80160B80: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    // 0x80160B84: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160B88: jal         0x800E6F24
    // 0x80160B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80160B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80160B90: jal         0x800E0830
    // 0x80160B94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80160B94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80160B98: jal         0x80160B14
    // 0x80160B9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyCaptainSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80160B9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80160BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160BA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80160BA8: jr          $ra
    // 0x80160BAC: nop

    return;
    // 0x80160BAC: nop

;}
RECOMP_FUNC void ftSamusSpecialNStartProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D464: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015D468: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8015D46C: lhu         $v1, 0x1BE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8015D470: lhu         $t6, 0x1B6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8015D474: and         $t7, $v1, $t6
    ctx->r15 = ctx->r3 & ctx->r14;
    // 0x8015D478: bnel        $t7, $zero, L_8015D494
    if (ctx->r15 != 0) {
        // 0x8015D47C: sw          $t0, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r8;
            goto L_8015D494;
    }
    goto skip_0;
    // 0x8015D47C: sw          $t0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x8015D480: lhu         $t8, 0x1B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8015D484: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
    // 0x8015D488: beq         $t9, $zero, L_8015D494
    if (ctx->r25 == 0) {
        // 0x8015D48C: nop
    
            goto L_8015D494;
    }
    // 0x8015D48C: nop

    // 0x8015D490: sw          $t0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r8;
L_8015D494:
    // 0x8015D494: jr          $ra
    // 0x8015D498: nop

    return;
    // 0x8015D498: nop

;}
RECOMP_FUNC void func_ovl8_803748C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803748C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803748C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803748C8: beq         $a1, $zero, L_803748EC
    if (ctx->r5 == 0) {
        // 0x803748CC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_803748EC;
    }
    // 0x803748CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803748D0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x803748D4: lw          $t9, 0x9C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C);
    // 0x803748D8: lh          $t6, 0x98($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X98);
    // 0x803748DC: jalr        $t9
    // 0x803748E0: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803748E0: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x803748E4: b           L_80374904
    // 0x803748E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80374904;
    // 0x803748E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803748EC:
    // 0x803748EC: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x803748F0: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x803748F4: lh          $t7, 0xA0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA0);
    // 0x803748F8: jalr        $t9
    // 0x803748FC: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803748FC: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80374900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80374904:
    // 0x80374904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374908: jr          $ra
    // 0x8037490C: nop

    return;
    // 0x8037490C: nop

;}
RECOMP_FUNC void func_ovl3_801864BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801864BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801864C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801864C4: jal         0x80185B18
    // 0x801864C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl3_80185B18(rdram, ctx);
        goto after_0;
    // 0x801864C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801864CC: jal         0x80186368
    // 0x801864D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_1;
    // 0x801864D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801864D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801864D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801864DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801864E0: jr          $ra
    // 0x801864E4: nop

    return;
    // 0x801864E4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A90: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80133A94: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133A9C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80133AA0: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80133AA4: addiu       $t7, $t7, -0x7D4C
    ctx->r15 = ADD32(ctx->r15, -0X7D4C);
    // 0x80133AA8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133AAC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133AB0: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80133AB4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133AB8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133ABC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133AC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133AC4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133AC8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133ACC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133AD0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133AD4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80133AD8: addiu       $t1, $t1, -0x7D34
    ctx->r9 = ADD32(ctx->r9, -0X7D34);
    // 0x80133ADC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80133AE0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80133AE4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80133AE8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133AEC: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x80133AF0: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133AF4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133AF8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133AFC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133B00: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80133B04: addiu       $t5, $t5, -0x7D24
    ctx->r13 = ADD32(ctx->r13, -0X7D24);
    // 0x80133B08: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133B0C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80133B10: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80133B14: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80133B18: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80133B1C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80133B20: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80133B24: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133B28: addiu       $t9, $t9, -0x7D18
    ctx->r25 = ADD32(ctx->r25, -0X7D18);
    // 0x80133B2C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80133B30: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80133B34: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80133B38: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80133B3C: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80133B40: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80133B44: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80133B48: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80133B4C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80133B50: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80133B54: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80133B58: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80133B5C: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80133B60: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x80133B64: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x80133B68: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80133B6C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80133B70: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80133B74: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80133B78: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80133B7C: jal         0x8000B760
    // 0x80133B80: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80133B80: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80133B84: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80133B88: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80133B8C: lw          $t5, -0x7368($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7368);
    // 0x80133B90: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80133B94: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80133B98: lw          $t4, 0x38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38);
    // 0x80133B9C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80133BA0: jal         0x800CCFDC
    // 0x80133BA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133BA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x80133BA8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80133BAC: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80133BB0: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80133BB4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80133BB8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80133BBC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80133BC0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80133BC4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133BC8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80133BCC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80133BD0: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80133BD4: lw          $t3, -0x7368($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7368);
    // 0x80133BD8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80133BDC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80133BE0: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80133BE4: lw          $t2, 0x44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44);
    // 0x80133BE8: jal         0x800CCFDC
    // 0x80133BEC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133BEC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80133BF0: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80133BF4: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80133BF8: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80133BFC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80133C00: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80133C04: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80133C08: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80133C0C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133C10: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80133C14: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x80133C18: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80133C1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80133C20: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133C24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80133C28: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80133C2C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80133C30: lwc1        $f16, 0x5C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x80133C34: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133C38: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80133C3C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133C40: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80133C44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80133C48: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133C4C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80133C50: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80133C54: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80133C58: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80133C5C: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80133C60: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80133C64: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80133C68: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80133C6C: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80133C70: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80133C74: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x80133C78: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80133C7C: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x80133C80: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x80133C84: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x80133C88: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x80133C8C: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x80133C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133C94: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80133C98: jr          $ra
    // 0x80133C9C: nop

    return;
    // 0x80133C9C: nop

;}
RECOMP_FUNC void func_80010AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010AE8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80010AEC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80010AF0: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80010AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010AF8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80010AFC: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010B00: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80010B04: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010B08: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80010B0C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80010B10: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80010B14: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80010B18: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010B1C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80010B20: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80010B24: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80010B28: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80010B2C: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x80010B30: jal         0x80033510
    // 0x80010B34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80010B34: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80010B38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80010B3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010B40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010B44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80010B48: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80010B4C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80010B50: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010B54: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010B58: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x80010B5C: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x80010B60: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80010B64: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80010B68: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x80010B6C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80010B70: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x80010B74: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80010B78: bc1t        L_80010BB8
    if (c1cs) {
        // 0x80010B7C: swc1        $f18, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
            goto L_80010BB8;
    }
    // 0x80010B7C: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x80010B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010B84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010B88: nop

    // 0x80010B8C: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80010B90: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80010B94: nop

    // 0x80010B98: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80010B9C: neg.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = -ctx->f16.fl;
    // 0x80010BA0: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80010BA4: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
    // 0x80010BA8: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80010BAC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80010BB0: b           L_80010BD4
    // 0x80010BB4: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
        goto L_80010BD4;
    // 0x80010BB4: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
L_80010BB8:
    // 0x80010BB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010BBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010BC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80010BC4: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80010BC8: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80010BCC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80010BD0: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80010BD4:
    // 0x80010BD4: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80010BD8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80010BDC: beql        $t7, $zero, L_80010C04
    if (ctx->r15 == 0) {
        // 0x80010BE0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80010C04;
    }
    goto skip_0;
    // 0x80010BE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80010BE4: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010BE8: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x80010BEC: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80010BF0: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x80010BF4: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80010BF8: b           L_80010C14
    // 0x80010BFC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
        goto L_80010C14;
    // 0x80010BFC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80010C00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80010C04:
    // 0x80010C04: nop

    // 0x80010C08: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80010C0C: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80010C10: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80010C14:
    // 0x80010C14: jal         0x80019EA0
    // 0x80010C18: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x80010C18: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x80010C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010C20: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80010C24: jr          $ra
    // 0x80010C28: nop

    return;
    // 0x80010C28: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageGetSpecialArrayID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E700: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8010E704: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8010E708: bne         $at, $zero, L_8010E75C
    if (ctx->r1 != 0) {
        // 0x8010E70C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8010E75C;
    }
    // 0x8010E70C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010E710: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8010E714:
    // 0x8010E714: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E718: mflo        $v0
    ctx->r2 = lo;
    // 0x8010E71C: nop

    // 0x8010E720: nop

    // 0x8010E724: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x8010E728: bne         $v0, $zero, L_8010E734
    if (ctx->r2 != 0) {
        // 0x8010E72C: nop
    
            goto L_8010E734;
    }
    // 0x8010E72C: nop

    // 0x8010E730: break       7
    do_break(2148591408);
L_8010E734:
    // 0x8010E734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010E738: bne         $v0, $at, L_8010E74C
    if (ctx->r2 != ctx->r1) {
        // 0x8010E73C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010E74C;
    }
    // 0x8010E73C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010E740: bne         $a0, $at, L_8010E74C
    if (ctx->r4 != ctx->r1) {
        // 0x8010E744: nop
    
            goto L_8010E74C;
    }
    // 0x8010E744: nop

    // 0x8010E748: break       6
    do_break(2148591432);
L_8010E74C:
    // 0x8010E74C: mflo        $t6
    ctx->r14 = lo;
    // 0x8010E750: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8010E754: beq         $at, $zero, L_8010E714
    if (ctx->r1 == 0) {
        // 0x8010E758: nop
    
            goto L_8010E714;
    }
    // 0x8010E758: nop

L_8010E75C:
    // 0x8010E75C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8010E760:
    // 0x8010E760: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x8010E764: bne         $v0, $zero, L_8010E770
    if (ctx->r2 != 0) {
        // 0x8010E768: nop
    
            goto L_8010E770;
    }
    // 0x8010E768: nop

    // 0x8010E76C: break       7
    do_break(2148591468);
L_8010E770:
    // 0x8010E770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010E774: bne         $v0, $at, L_8010E788
    if (ctx->r2 != ctx->r1) {
        // 0x8010E778: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010E788;
    }
    // 0x8010E778: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010E77C: bne         $a0, $at, L_8010E788
    if (ctx->r4 != ctx->r1) {
        // 0x8010E780: nop
    
            goto L_8010E788;
    }
    // 0x8010E780: nop

    // 0x8010E784: break       6
    do_break(2148591492);
L_8010E788:
    // 0x8010E788: mflo        $t7
    ctx->r15 = lo;
    // 0x8010E78C: mfhi        $a0
    ctx->r4 = hi;
    // 0x8010E790: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8010E794: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8010E798: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8010E79C: bne         $a2, $zero, L_8010E7A8
    if (ctx->r6 != 0) {
        // 0x8010E7A0: nop
    
            goto L_8010E7A8;
    }
    // 0x8010E7A0: nop

    // 0x8010E7A4: break       7
    do_break(2148591524);
L_8010E7A8:
    // 0x8010E7A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010E7AC: bne         $a2, $at, L_8010E7C0
    if (ctx->r6 != ctx->r1) {
        // 0x8010E7B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010E7C0;
    }
    // 0x8010E7B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010E7B4: bne         $v0, $at, L_8010E7C0
    if (ctx->r2 != ctx->r1) {
        // 0x8010E7B8: nop
    
            goto L_8010E7C0;
    }
    // 0x8010E7B8: nop

    // 0x8010E7BC: break       6
    do_break(2148591548);
L_8010E7C0:
    // 0x8010E7C0: mflo        $v0
    ctx->r2 = lo;
    // 0x8010E7C4: bne         $v0, $zero, L_8010E760
    if (ctx->r2 != 0) {
        // 0x8010E7C8: nop
    
            goto L_8010E760;
    }
    // 0x8010E7C8: nop

    // 0x8010E7CC: jr          $ra
    // 0x8010E7D0: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    return;
    // 0x8010E7D0: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
;}
RECOMP_FUNC void ftParamLinkResetShieldModelParts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E86F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E86F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E86F8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E86FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E8700: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x800E8704: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800E8708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E870C: beq         $v1, $at, L_800E871C
    if (ctx->r3 == ctx->r1) {
        // 0x800E8710: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800E871C;
    }
    // 0x800E8710: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800E8714: bnel        $v1, $at, L_800E8738
    if (ctx->r3 != ctx->r1) {
        // 0x800E8718: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8738;
    }
    goto skip_0;
    // 0x800E8718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800E871C:
    // 0x800E871C: jal         0x800E8EAC
    // 0x800E8720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_0;
    // 0x800E8720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E8724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E8728: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800E872C: jal         0x800E8EAC
    // 0x800E8730: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_1;
    // 0x800E8730: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_1:
    // 0x800E8734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8738:
    // 0x800E8738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E873C: jr          $ra
    // 0x800E8740: nop

    return;
    // 0x800E8740: nop

;}
RECOMP_FUNC void mnMapsSetPreviewCameraPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013390C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80133910: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133914: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x80133918: addiu       $t6, $t6, 0x487C
    ctx->r14 = ADD32(ctx->r14, 0X487C);
    // 0x8013391C: addiu       $t0, $t6, 0x6C
    ctx->r8 = ADD32(ctx->r14, 0X6C);
    // 0x80133920: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80133924:
    // 0x80133924: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133928: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013392C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133930: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133934: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133938: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013393C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133940: bne         $t6, $t0, L_80133924
    if (ctx->r14 != ctx->r8) {
        // 0x80133944: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133924;
    }
    // 0x80133944: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133948: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x8013394C: bne         $a1, $at, L_80133958
    if (ctx->r5 != ctx->r1) {
        // 0x80133950: nop
    
            goto L_80133958;
    }
    // 0x80133950: nop

    // 0x80133954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80133958:
    // 0x80133958: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013395C: lwc1        $f4, 0x4BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4BC0);
    // 0x80133960: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133964: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133968: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8013396C: lwc1        $f6, 0x4BC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4BC4);
    // 0x80133970: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133974: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80133978: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8013397C: lwc1        $f8, 0x4BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4BC8);
    // 0x80133980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133984: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133988: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x8013398C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80133990: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80133994: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x80133998: swc1        $f0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f0.u32l;
    // 0x8013399C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x801339A0: swc1        $f10, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f10.u32l;
    // 0x801339A4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801339A8: swc1        $f16, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f16.u32l;
    // 0x801339AC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801339B0: swc1        $f18, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f18.u32l;
    // 0x801339B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801339B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801339BC: jr          $ra
    // 0x801339C0: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x801339C0: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void gmCollisionCheckFighterAttacksCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFABC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800EFAC0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800EFAC4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800EFAC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800EFACC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EFAD0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800EFAD4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800EFAD8: lw          $a2, 0x24($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X24);
    // 0x800EFADC: addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // 0x800EFAE0: addiu       $v1, $s0, 0x50
    ctx->r3 = ADD32(ctx->r16, 0X50);
    // 0x800EFAE4: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800EFAE8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EFAEC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800EFAF0: addiu       $a1, $s1, 0x50
    ctx->r5 = ADD32(ctx->r17, 0X50);
    // 0x800EFAF4: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x800EFAF8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800EFAFC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800EFB00: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800EFB04: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800EFB08: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800EFB0C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800EFB10: jal         0x800EF5D4
    // 0x800EFB14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800EFB14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800EFB18: bne         $v0, $zero, L_800EFB28
    if (ctx->r2 != 0) {
        // 0x800EFB1C: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_800EFB28;
    }
    // 0x800EFB1C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800EFB20: b           L_800EFB90
    // 0x800EFB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFB90;
    // 0x800EFB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EFB28:
    // 0x800EFB28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EFB2C: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800EFB30: addiu       $t7, $s0, 0xC0
    ctx->r15 = ADD32(ctx->r16, 0XC0);
    // 0x800EFB34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800EFB38: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EFB3C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800EFB40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800EFB44: jal         0x800EE050
    // 0x800EFB48: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800EFB48: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    after_1:
    // 0x800EFB4C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800EFB50: lw          $a2, 0x24($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X24);
    // 0x800EFB54: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800EFB58: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EFB5C: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x800EFB60: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800EFB64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800EFB68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800EFB6C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800EFB70: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800EFB74: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800EFB78: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800EFB7C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800EFB80: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800EFB84: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800EFB88: jal         0x800EEEAC
    // 0x800EFB8C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800EFB8C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800EFB90:
    // 0x800EFB90: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800EFB94: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800EFB98: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800EFB9C: jr          $ra
    // 0x800EFBA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800EFBA0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftPurinSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015147C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151480: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151484: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151488: jal         0x800DEEC8
    // 0x8015148C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015148C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151490: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151494: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80151498: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015149C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801514A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801514A4: jal         0x800E6F24
    // 0x801514A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801514A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801514AC: jal         0x800D8EB8
    // 0x801514B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801514B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801514B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801514B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801514BC: jr          $ra
    // 0x801514C0: nop

    return;
    // 0x801514C0: nop

;}
RECOMP_FUNC void ifCommonInterfaceSetGObjFlagsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113F74: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80113F78: lw          $v0, 0x671C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X671C);
    // 0x80113F7C: beq         $v0, $zero, L_80113F94
    if (ctx->r2 == 0) {
        // 0x80113F80: nop
    
            goto L_80113F94;
    }
    // 0x80113F80: nop

    // 0x80113F84: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
L_80113F88:
    // 0x80113F88: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80113F8C: bnel        $v0, $zero, L_80113F88
    if (ctx->r2 != 0) {
        // 0x80113F90: sw          $a0, 0x7C($v0)
        MEM_W(0X7C, ctx->r2) = ctx->r4;
            goto L_80113F88;
    }
    goto skip_0;
    // 0x80113F90: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    skip_0:
L_80113F94:
    // 0x80113F94: jr          $ra
    // 0x80113F98: nop

    return;
    // 0x80113F98: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeUnderline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80190074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190078: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8019007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190080: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80190084: jal         0x80009968
    // 0x80190088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80190088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8019008C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80190090: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80190094: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80190098: addiu       $a1, $a1, -0x320
    ctx->r5 = ADD32(ctx->r5, -0X320);
    // 0x8019009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801900A0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x801900A4: jal         0x80009DF4
    // 0x801900A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801900A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801900AC: jal         0x8018FE40
    // 0x801900B0: nop

    sc1PTrainingModeUpdateUnderline(rdram, ctx);
        goto after_2;
    // 0x801900B0: nop

    after_2:
    // 0x801900B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801900B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801900BC: jr          $ra
    // 0x801900C0: nop

    return;
    // 0x801900C0: nop

;}
RECOMP_FUNC void itCapsuleFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173F98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173F9C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80173FA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80173FA4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80173FA8: jal         0x80172558
    // 0x80173FAC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80173FAC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80173FB0: jal         0x801713F4
    // 0x80173FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80173FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80173FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173FC4: jr          $ra
    // 0x80173FC8: nop

    return;
    // 0x80173FC8: nop

;}
RECOMP_FUNC void gcAddMObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F8F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F8F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F8FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F900: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F904: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F908: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F90C: lw          $s2, 0x74($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X74);
    // 0x8000F910: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000F914: beql        $s2, $zero, L_8000F970
    if (ctx->r18 == 0) {
        // 0x8000F918: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000F970;
    }
    goto skip_0;
    // 0x8000F918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8000F91C:
    // 0x8000F91C: beq         $s3, $zero, L_8000F95C
    if (ctx->r19 == 0) {
        // 0x8000F920: nop
    
            goto L_8000F95C;
    }
    // 0x8000F920: nop

    // 0x8000F924: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000F928: beql        $v0, $zero, L_8000F95C
    if (ctx->r2 == 0) {
        // 0x8000F92C: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8000F95C;
    }
    goto skip_1;
    // 0x8000F92C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    skip_1:
    // 0x8000F930: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8000F934: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F938: beq         $s1, $zero, L_8000F958
    if (ctx->r17 == 0) {
        // 0x8000F93C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F958;
    }
    // 0x8000F93C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000F940:
    // 0x8000F940: jal         0x800090DC
    // 0x8000F944: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F944: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8000F948: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000F94C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F950: bnel        $s1, $zero, L_8000F940
    if (ctx->r17 != 0) {
        // 0x8000F954: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F940;
    }
    goto skip_2;
    // 0x8000F954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_8000F958:
    // 0x8000F958: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000F95C:
    // 0x8000F95C: jal         0x8000BAA0
    // 0x8000F960: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000F960: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8000F964: bne         $v0, $zero, L_8000F91C
    if (ctx->r2 != 0) {
        // 0x8000F968: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000F91C;
    }
    // 0x8000F968: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000F96C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F970:
    // 0x8000F970: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F974: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F978: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F97C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F980: jr          $ra
    // 0x8000F984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000F984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftParamRunProcEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9B64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E9B68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E9B6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E9B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E9B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E9B78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9B7C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E9B80: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800E9B84: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x800E9B88: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800E9B8C: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x800E9B90: bgezl       $t8, L_800E9BD4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E9B94: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E9BD4;
    }
    goto skip_0;
    // 0x800E9B94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800E9B98: lw          $a0, 0x6708($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6708);
    // 0x800E9B9C: beql        $a0, $zero, L_800E9BD4
    if (ctx->r4 == 0) {
        // 0x800E9BA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E9BD4;
    }
    goto skip_1;
    // 0x800E9BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_800E9BA4:
    // 0x800E9BA4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800E9BA8: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x800E9BAC: beq         $a1, $zero, L_800E9BC8
    if (ctx->r5 == 0) {
        // 0x800E9BB0: nop
    
            goto L_800E9BC8;
    }
    // 0x800E9BB0: nop

    // 0x800E9BB4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800E9BB8: bne         $s1, $t9, L_800E9BC8
    if (ctx->r17 != ctx->r25) {
        // 0x800E9BBC: nop
    
            goto L_800E9BC8;
    }
    // 0x800E9BBC: nop

    // 0x800E9BC0: jalr        $s2
    // 0x800E9BC4: nop

    LOOKUP_FUNC(ctx->r18)(rdram, ctx);
        goto after_0;
    // 0x800E9BC4: nop

    after_0:
L_800E9BC8:
    // 0x800E9BC8: bne         $s0, $zero, L_800E9BA4
    if (ctx->r16 != 0) {
        // 0x800E9BCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E9BA4;
    }
    // 0x800E9BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E9BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E9BD4:
    // 0x800E9BD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E9BD8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9BDC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E9BE0: jr          $ra
    // 0x800E9BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E9BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itProcessUpdateDamageStatFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FB18: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8016FB1C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8016FB20: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8016FB24: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8016FB28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8016FB2C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8016FB30: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8016FB34: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8016FB38: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x8016FB3C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8016FB40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8016FB44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8016FB48: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8016FB4C: jal         0x800E26BC
    // 0x8016FB50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_0;
    // 0x8016FB50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8016FB54: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8016FB58: lw          $t6, 0x7B0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7B0);
    // 0x8016FB5C: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8016FB60: beql        $at, $zero, L_8016FB70
    if (ctx->r1 == 0) {
        // 0x8016FB64: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_8016FB70;
    }
    goto skip_0;
    // 0x8016FB64: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x8016FB68: sw          $a2, 0x7B0($s2)
    MEM_W(0X7B0, ctx->r18) = ctx->r6;
    // 0x8016FB6C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_8016FB70:
    // 0x8016FB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016FB74: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8016FB78: bnel        $t8, $at, L_8016FD2C
    if (ctx->r24 != ctx->r1) {
        // 0x8016FB7C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8016FD2C;
    }
    goto skip_1;
    // 0x8016FB7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x8016FB80: lw          $t9, 0x298($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X298);
    // 0x8016FB84: lw          $t1, 0x290($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X290);
    // 0x8016FB88: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x8016FB8C: slt         $at, $t1, $a2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8016FB90: beq         $at, $zero, L_8016FC14
    if (ctx->r1 == 0) {
        // 0x8016FB94: sw          $t0, 0x298($s0)
        MEM_W(0X298, ctx->r16) = ctx->r8;
            goto L_8016FC14;
    }
    // 0x8016FB94: sw          $t0, 0x298($s0)
    MEM_W(0X298, ctx->r16) = ctx->r8;
    // 0x8016FB98: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8016FB9C: sw          $a2, 0x290($s0)
    MEM_W(0X290, ctx->r16) = ctx->r6;
    // 0x8016FBA0: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x8016FBA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8016FBA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8016FBAC: sw          $t2, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r10;
    // 0x8016FBB0: lw          $t3, 0x10($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X10);
    // 0x8016FBB4: sw          $t3, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->r11;
    // 0x8016FBB8: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8016FBBC: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x8016FBC0: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x8016FBC4: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8016FBC8: lwc1        $f4, 0x1C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8016FBCC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8016FBD0: nop

    // 0x8016FBD4: bc1fl       L_8016FBE8
    if (!c1cs) {
        // 0x8016FBD8: sw          $t8, 0x2A4($s0)
        MEM_W(0X2A4, ctx->r16) = ctx->r24;
            goto L_8016FBE8;
    }
    goto skip_2;
    // 0x8016FBD8: sw          $t8, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r24;
    skip_2:
    // 0x8016FBDC: b           L_8016FBE8
    // 0x8016FBE0: sw          $t7, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r15;
        goto L_8016FBE8;
    // 0x8016FBE0: sw          $t7, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r15;
    // 0x8016FBE4: sw          $t8, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r24;
L_8016FBE8:
    // 0x8016FBE8: sw          $v0, 0x2A8($s0)
    MEM_W(0X2A8, ctx->r16) = ctx->r2;
    // 0x8016FBEC: lbu         $t9, 0xC($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XC);
    // 0x8016FBF0: sb          $t9, 0x2AC($s0)
    MEM_B(0X2AC, ctx->r16) = ctx->r25;
    // 0x8016FBF4: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x8016FBF8: sb          $t0, 0x2AD($s0)
    MEM_B(0X2AD, ctx->r16) = ctx->r8;
    // 0x8016FBFC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x8016FC00: sw          $t1, 0x2B0($s0)
    MEM_W(0X2B0, ctx->r16) = ctx->r9;
    // 0x8016FC04: lbu         $t2, 0x12($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X12);
    // 0x8016FC08: sb          $t2, 0x2B4($s0)
    MEM_B(0X2B4, ctx->r16) = ctx->r10;
    // 0x8016FC0C: lw          $t3, 0xB4C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XB4C);
    // 0x8016FC10: sw          $t3, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r11;
L_8016FC14:
    // 0x8016FC14: lw          $t4, 0x2D0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2D0);
    // 0x8016FC18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016FC1C: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x8016FC20: bgezl       $t6, L_8016FC7C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8016FC24: addiu       $s0, $sp, 0x4C
        ctx->r16 = ADD32(ctx->r29, 0X4C);
            goto L_8016FC7C;
    }
    goto skip_3;
    // 0x8016FC24: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    skip_3:
    // 0x8016FC28: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    // 0x8016FC2C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8016FC30: lw          $a1, 0x298($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X298);
    // 0x8016FC34: lw          $a3, 0x30($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X30);
    // 0x8016FC38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8016FC3C: lw          $t8, 0x34($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X34);
    // 0x8016FC40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016FC44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8016FC48: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8016FC4C: lbu         $t9, 0x12($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X12);
    // 0x8016FC50: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8016FC54: lbu         $t0, 0x16($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X16);
    // 0x8016FC58: jal         0x800E9D78
    // 0x8016FC5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_1;
    // 0x8016FC5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x8016FC60: lwc1        $f10, 0x294($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8016FC64: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8016FC68: nop

    // 0x8016FC6C: bc1fl       L_8016FC7C
    if (!c1cs) {
        // 0x8016FC70: addiu       $s0, $sp, 0x4C
        ctx->r16 = ADD32(ctx->r29, 0X4C);
            goto L_8016FC7C;
    }
    goto skip_4;
    // 0x8016FC70: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    skip_4:
    // 0x8016FC74: swc1        $f0, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->f0.u32l;
    // 0x8016FC78: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
L_8016FC7C:
    // 0x8016FC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016FC80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8016FC84: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8016FC88: jal         0x800F0AF8
    // 0x8016FC8C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    gmCollisionGetFighterAttackItemDamagePosition(rdram, ctx);
        goto after_2;
    // 0x8016FC8C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    after_2:
    // 0x8016FC90: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x8016FC94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016FC98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016FC9C: beq         $v0, $at, L_8016FCCC
    if (ctx->r2 == ctx->r1) {
        // 0x8016FCA0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016FCCC;
    }
    // 0x8016FCA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016FCA4: beq         $v0, $at, L_8016FCDC
    if (ctx->r2 == ctx->r1) {
        // 0x8016FCA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016FCDC;
    }
    // 0x8016FCA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016FCAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016FCB0: beq         $v0, $at, L_8016FCFC
    if (ctx->r2 == ctx->r1) {
        // 0x8016FCB4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8016FCFC;
    }
    // 0x8016FCB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8016FCB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8016FCBC: beq         $v0, $at, L_8016FCEC
    if (ctx->r2 == ctx->r1) {
        // 0x8016FCC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016FCEC;
    }
    // 0x8016FCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016FCC4: b           L_8016FD1C
    // 0x8016FCC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8016FD1C;
    // 0x8016FCC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8016FCCC:
    // 0x8016FCCC: jal         0x800FE2F4
    // 0x8016FCD0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016FCD0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    after_3:
    // 0x8016FCD4: b           L_8016FD2C
    // 0x8016FCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8016FD2C;
    // 0x8016FCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8016FCDC:
    // 0x8016FCDC: jal         0x800FE4EC
    // 0x8016FCE0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8016FCE0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x8016FCE4: b           L_8016FD2C
    // 0x8016FCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8016FD2C;
    // 0x8016FCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8016FCEC:
    // 0x8016FCEC: jal         0x80100ACC
    // 0x8016FCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_5;
    // 0x8016FCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8016FCF4: b           L_8016FD2C
    // 0x8016FCF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8016FD2C;
    // 0x8016FCF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8016FCFC:
    // 0x8016FCFC: jal         0x800F0FC0
    // 0x8016FD00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gmCollisionGetDamageSlashRotation(rdram, ctx);
        goto after_6;
    // 0x8016FD00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8016FD04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8016FD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016FD0C: jal         0x800FE6E4
    // 0x8016FD10: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    efManagerDamageSlashMakeEffect(rdram, ctx);
        goto after_7;
    // 0x8016FD10: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    after_7:
    // 0x8016FD14: b           L_8016FD2C
    // 0x8016FD18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_8016FD2C;
    // 0x8016FD18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8016FD1C:
    // 0x8016FD1C: lbu         $a1, 0xD($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XD);
    // 0x8016FD20: jal         0x800FDC04
    // 0x8016FD24: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_8;
    // 0x8016FD24: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_8:
    // 0x8016FD28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8016FD2C:
    // 0x8016FD2C: jal         0x800E2C24
    // 0x8016FD30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftMainPlayHitSFX(rdram, ctx);
        goto after_9;
    // 0x8016FD30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x8016FD34: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8016FD38: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8016FD3C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8016FD40: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8016FD44: jr          $ra
    // 0x8016FD48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8016FD48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132130: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132134: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132138: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013213C: addiu       $t7, $t7, -0x7F0C
    ctx->r15 = ADD32(ctx->r15, -0X7F0C);
    // 0x80132140: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80132144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132148: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013214C: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80132150: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80132154:
    // 0x80132154: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132158: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8013215C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132160: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132164: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132168: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013216C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132170: bne         $t7, $t0, L_80132154
    if (ctx->r15 != ctx->r8) {
        // 0x80132174: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132154;
    }
    // 0x80132174: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132178: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013217C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132180: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132184: jal         0x80009968
    // 0x80132188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013218C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132190: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132194: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013219C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801321A0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x801321A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801321A8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801321AC: jal         0x80009DF4
    // 0x801321B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801321B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801321B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801321B8: addiu       $a1, $a1, 0x1D90
    ctx->r5 = ADD32(ctx->r5, 0X1D90);
    // 0x801321BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801321C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801321C8: jal         0x80008188
    // 0x801321CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801321CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801321D0: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801321D4: lw          $t2, -0x7350($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7350);
    // 0x801321D8: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801321DC: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x801321E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321E4: jal         0x800CCFDC
    // 0x801321E8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801321E8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x801321EC: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801321F0: bne         $at, $zero, L_80132200
    if (ctx->r1 != 0) {
        // 0x801321F4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80132200;
    }
    // 0x801321F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801321F8: b           L_80132204
    // 0x801321FC: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
        goto L_80132204;
    // 0x801321FC: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
L_80132200:
    // 0x80132200: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80132204:
    // 0x80132204: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80132208: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8013220C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80132210: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80132214: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80132218: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8013221C: addiu       $t5, $t4, 0x19
    ctx->r13 = ADD32(ctx->r12, 0X19);
    // 0x80132220: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80132224: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80132228: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013222C: bne         $at, $zero, L_8013223C
    if (ctx->r1 != 0) {
        // 0x80132230: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_8013223C;
    }
    // 0x80132230: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132234: b           L_80132240
    // 0x80132238: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132240;
    // 0x80132238: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013223C:
    // 0x8013223C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80132240:
    // 0x80132240: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80132244: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132248: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013224C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132250: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132254: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132258: addiu       $t7, $t0, 0x24
    ctx->r15 = ADD32(ctx->r8, 0X24);
    // 0x8013225C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80132260: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80132264: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132268: jal         0x80131E0C
    // 0x8013226C: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    mnPlayers1PTrainingSetPortraitWallpaperPosition(rdram, ctx);
        goto after_4;
    // 0x8013226C: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    after_4:
    // 0x80132270: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132274: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013227C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132280: jal         0x80009968
    // 0x80132284: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80132284: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80132288: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013228C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132290: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132294: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132298: addiu       $a1, $a1, 0x2070
    ctx->r5 = ADD32(ctx->r5, 0X2070);
    // 0x8013229C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322A0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801322A4: jal         0x80009DF4
    // 0x801322A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x801322A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x801322AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801322B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801322B8: jal         0x80008188
    // 0x801322BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x801322BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x801322C0: jal         0x80131FD0
    // 0x801322C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_8;
    // 0x801322C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801322C8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801322CC: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x801322D0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801322D4: lw          $t1, -0x7350($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7350);
    // 0x801322D8: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x801322DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322E0: jal         0x800CCFDC
    // 0x801322E4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x801322E4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_9:
    // 0x801322E8: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x801322EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801322F4: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x801322F8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801322FC: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132300: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132304: jal         0x80131E0C
    // 0x80132308: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    mnPlayers1PTrainingSetPortraitWallpaperPosition(rdram, ctx);
        goto after_10;
    // 0x80132308: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    after_10:
    // 0x8013230C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132314: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132318: jal         0x80009968
    // 0x8013231C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_11;
    // 0x8013231C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_11:
    // 0x80132320: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132324: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132328: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8013232C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132330: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80132334: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132338: jal         0x80009DF4
    // 0x8013233C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_12;
    // 0x8013233C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_12:
    // 0x80132340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132344: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013234C: jal         0x80008188
    // 0x80132350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x80132350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x80132354: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132358: lw          $t7, -0x7350($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7350);
    // 0x8013235C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132360: addiu       $t6, $t6, 0xF68
    ctx->r14 = ADD32(ctx->r14, 0XF68);
    // 0x80132364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132368: jal         0x800CCFDC
    // 0x8013236C: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_14;
    // 0x8013236C: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_14:
    // 0x80132370: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132374: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x80132378: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x8013237C: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80132380: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132384: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132388: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x8013238C: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x80132390: addiu       $t7, $zero, 0xB9
    ctx->r15 = ADD32(0, 0XB9);
    // 0x80132394: addiu       $t6, $zero, 0xA9
    ctx->r14 = ADD32(0, 0XA9);
    // 0x80132398: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013239C: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x801323A0: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x801323A4: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x801323A8: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x801323AC: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801323B0: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801323B4: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x801323B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323BC: jal         0x80131E0C
    // 0x801323C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PTrainingSetPortraitWallpaperPosition(rdram, ctx);
        goto after_15;
    // 0x801323C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x801323C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801323C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801323CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801323D0: jr          $ra
    // 0x801323D4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801323D4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void ftCommonFallSpecialProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80143758: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014375C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80143760: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80143764: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x80143768: jal         0x800D8DB0
    // 0x8014376C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsCheckSetFastFall(rdram, ctx);
        goto after_0;
    // 0x8014376C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80143770: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x80143774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80143778: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8014377C: bgezl       $t8, L_80143798
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80143780: lw          $t9, 0xB2C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XB2C);
            goto L_80143798;
    }
    goto skip_0;
    // 0x80143780: lw          $t9, 0xB2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB2C);
    skip_0:
    // 0x80143784: jal         0x800D8DA0
    // 0x80143788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_1;
    // 0x80143788: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8014378C: b           L_801437C8
    // 0x80143790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801437C8;
    // 0x80143790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80143794: lw          $t9, 0xB2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB2C);
L_80143798:
    // 0x80143798: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8014379C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801437A0: beql        $t9, $zero, L_801437BC
    if (ctx->r25 == 0) {
        // 0x801437A4: lw          $a1, 0x58($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X58);
            goto L_801437BC;
    }
    goto skip_1;
    // 0x801437A4: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    skip_1:
    // 0x801437A8: jal         0x800D8E50
    // 0x801437AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_2;
    // 0x801437AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801437B0: b           L_801437C8
    // 0x801437B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801437C8;
    // 0x801437B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801437B8: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
L_801437BC:
    // 0x801437BC: jal         0x800D8D68
    // 0x801437C0: lw          $a2, 0x60($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X60);
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_3;
    // 0x801437C0: lw          $a2, 0x60($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X60);
    after_3:
    // 0x801437C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801437C8:
    // 0x801437C8: jal         0x800D8EDC
    // 0x801437CC: lw          $a1, 0xB18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB18);
    ftPhysicsCheckClampAirVelXDec(rdram, ctx);
        goto after_4;
    // 0x801437CC: lw          $a1, 0xB18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB18);
    after_4:
    // 0x801437D0: bne         $v0, $zero, L_801437F4
    if (ctx->r2 != 0) {
        // 0x801437D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801437F4;
    }
    // 0x801437D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801437D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801437DC: lw          $a2, 0x4C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4C);
    // 0x801437E0: jal         0x800D8FC8
    // 0x801437E4: lw          $a3, 0xB18($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB18);
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_5;
    // 0x801437E4: lw          $a3, 0xB18($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB18);
    after_5:
    // 0x801437E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801437EC: jal         0x800D9074
    // 0x801437F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_6;
    // 0x801437F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
L_801437F4:
    // 0x801437F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801437F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801437FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80143800: jr          $ra
    // 0x80143804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80143804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpMainClearAttackRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168158: lbu         $t6, 0x218($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X218);
    // 0x8016815C: sw          $zero, 0x21C($a0)
    MEM_W(0X21C, ctx->r4) = 0;
    // 0x80168160: sw          $zero, 0x224($a0)
    MEM_W(0X224, ctx->r4) = 0;
    // 0x80168164: andi        $t0, $t6, 0xFFEF
    ctx->r8 = ctx->r14 & 0XFFEF;
    // 0x80168168: sb          $t0, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r8;
    // 0x8016816C: lw          $v0, 0x218($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X218);
    // 0x80168170: andi        $t1, $t0, 0xDF
    ctx->r9 = ctx->r8 & 0XDF;
    // 0x80168174: sw          $zero, 0x22C($a0)
    MEM_W(0X22C, ctx->r4) = 0;
    // 0x80168178: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8016817C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80168180: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x80168184: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80168188: or          $t5, $t9, $t1
    ctx->r13 = ctx->r25 | ctx->r9;
    // 0x8016818C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x80168190: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x80168194: andi        $t6, $t5, 0xBF
    ctx->r14 = ctx->r13 & 0XBF;
    // 0x80168198: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x8016819C: andi        $t1, $t9, 0x7F
    ctx->r9 = ctx->r25 & 0X7F;
    // 0x801681A0: sb          $t5, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r13;
    // 0x801681A4: sll         $t0, $v0, 7
    ctx->r8 = S32(ctx->r2 << 7);
    // 0x801681A8: lbu         $t8, 0x220($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X220);
    // 0x801681AC: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x801681B0: sb          $t9, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r25;
    // 0x801681B4: sb          $t2, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r10;
    // 0x801681B8: lhu         $t3, 0x218($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X218);
    // 0x801681BC: andi        $t2, $t8, 0xFFEF
    ctx->r10 = ctx->r24 & 0XFFEF;
    // 0x801681C0: sb          $t2, 0x220($a0)
    MEM_B(0X220, ctx->r4) = ctx->r10;
    // 0x801681C4: lw          $v0, 0x220($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X220);
    // 0x801681C8: andi        $t5, $t3, 0xFE07
    ctx->r13 = ctx->r11 & 0XFE07;
    // 0x801681CC: sh          $t5, 0x218($a0)
    MEM_H(0X218, ctx->r4) = ctx->r13;
    // 0x801681D0: lbu         $t6, 0x218($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X218);
    // 0x801681D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801681D8: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x801681DC: sll         $t0, $v0, 5
    ctx->r8 = S32(ctx->r2 << 5);
    // 0x801681E0: ori         $t7, $t6, 0xE
    ctx->r15 = ctx->r14 | 0XE;
    // 0x801681E4: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x801681E8: andi        $t3, $t2, 0xDF
    ctx->r11 = ctx->r10 & 0XDF;
    // 0x801681EC: sb          $t7, 0x218($a0)
    MEM_B(0X218, ctx->r4) = ctx->r15;
    // 0x801681F0: or          $t7, $t1, $t3
    ctx->r15 = ctx->r9 | ctx->r11;
    // 0x801681F4: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x801681F8: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x801681FC: andi        $t8, $t7, 0xBF
    ctx->r24 = ctx->r15 & 0XBF;
    // 0x80168200: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x80168204: andi        $t3, $t1, 0x7F
    ctx->r11 = ctx->r9 & 0X7F;
    // 0x80168208: sb          $t7, 0x220($a0)
    MEM_B(0X220, ctx->r4) = ctx->r15;
    // 0x8016820C: sll         $t2, $v0, 7
    ctx->r10 = S32(ctx->r2 << 7);
    // 0x80168210: lbu         $t0, 0x228($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X228);
    // 0x80168214: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x80168218: sb          $t1, 0x220($a0)
    MEM_B(0X220, ctx->r4) = ctx->r9;
    // 0x8016821C: sb          $t5, 0x220($a0)
    MEM_B(0X220, ctx->r4) = ctx->r13;
    // 0x80168220: lhu         $t4, 0x220($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X220);
    // 0x80168224: andi        $t5, $t0, 0xFFEF
    ctx->r13 = ctx->r8 & 0XFFEF;
    // 0x80168228: sb          $t5, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r13;
    // 0x8016822C: lw          $v0, 0x228($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X228);
    // 0x80168230: andi        $t7, $t4, 0xFE07
    ctx->r15 = ctx->r12 & 0XFE07;
    // 0x80168234: sh          $t7, 0x220($a0)
    MEM_H(0X220, ctx->r4) = ctx->r15;
    // 0x80168238: lbu         $t8, 0x220($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X220);
    // 0x8016823C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80168240: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80168244: sll         $t2, $v0, 5
    ctx->r10 = S32(ctx->r2 << 5);
    // 0x80168248: ori         $t9, $t8, 0xE
    ctx->r25 = ctx->r24 | 0XE;
    // 0x8016824C: sb          $t9, 0x220($a0)
    MEM_B(0X220, ctx->r4) = ctx->r25;
    // 0x80168250: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80168254: andi        $t4, $t5, 0xDF
    ctx->r12 = ctx->r13 & 0XDF;
    // 0x80168258: or          $t9, $t3, $t4
    ctx->r25 = ctx->r11 | ctx->r12;
    // 0x8016825C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x80168260: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80168264: andi        $t0, $t9, 0xBF
    ctx->r8 = ctx->r25 & 0XBF;
    // 0x80168268: or          $t3, $t8, $t0
    ctx->r11 = ctx->r24 | ctx->r8;
    // 0x8016826C: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x80168270: sb          $t9, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r25;
    // 0x80168274: sll         $t5, $v0, 7
    ctx->r13 = S32(ctx->r2 << 7);
    // 0x80168278: lbu         $t2, 0x230($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X230);
    // 0x8016827C: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x80168280: sb          $t3, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r11;
    // 0x80168284: sb          $t7, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r15;
    // 0x80168288: lhu         $t6, 0x228($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X228);
    // 0x8016828C: andi        $t7, $t2, 0xFFEF
    ctx->r15 = ctx->r10 & 0XFFEF;
    // 0x80168290: sb          $t7, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r15;
    // 0x80168294: lw          $v0, 0x230($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X230);
    // 0x80168298: andi        $t9, $t6, 0xFE07
    ctx->r25 = ctx->r14 & 0XFE07;
    // 0x8016829C: sh          $t9, 0x228($a0)
    MEM_H(0X228, ctx->r4) = ctx->r25;
    // 0x801682A0: lbu         $t0, 0x228($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X228);
    // 0x801682A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x801682A8: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x801682AC: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x801682B0: ori         $t1, $t0, 0xE
    ctx->r9 = ctx->r8 | 0XE;
    // 0x801682B4: sb          $t1, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r9;
    // 0x801682B8: andi        $t4, $t5, 0x20
    ctx->r12 = ctx->r13 & 0X20;
    // 0x801682BC: andi        $t6, $t7, 0xDF
    ctx->r14 = ctx->r15 & 0XDF;
    // 0x801682C0: or          $t1, $t4, $t6
    ctx->r9 = ctx->r12 | ctx->r14;
    // 0x801682C4: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x801682C8: andi        $t0, $t8, 0x40
    ctx->r8 = ctx->r24 & 0X40;
    // 0x801682CC: andi        $t2, $t1, 0xBF
    ctx->r10 = ctx->r9 & 0XBF;
    // 0x801682D0: or          $t4, $t0, $t2
    ctx->r12 = ctx->r8 | ctx->r10;
    // 0x801682D4: andi        $t6, $t4, 0x7F
    ctx->r14 = ctx->r12 & 0X7F;
    // 0x801682D8: sb          $t1, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r9;
    // 0x801682DC: sll         $t7, $v0, 7
    ctx->r15 = S32(ctx->r2 << 7);
    // 0x801682E0: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x801682E4: sb          $t4, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r12;
    // 0x801682E8: sb          $t9, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r25;
    // 0x801682EC: lhu         $t8, 0x230($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X230);
    // 0x801682F0: sw          $zero, 0x214($a0)
    MEM_W(0X214, ctx->r4) = 0;
    // 0x801682F4: andi        $t1, $t8, 0xFE07
    ctx->r9 = ctx->r24 & 0XFE07;
    // 0x801682F8: sh          $t1, 0x230($a0)
    MEM_H(0X230, ctx->r4) = ctx->r9;
    // 0x801682FC: lbu         $t2, 0x230($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X230);
    // 0x80168300: ori         $t3, $t2, 0xE
    ctx->r11 = ctx->r10 | 0XE;
    // 0x80168304: jr          $ra
    // 0x80168308: sb          $t3, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r11;
    return;
    // 0x80168308: sb          $t3, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void itHammerCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801762D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801762DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801762E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801762E4: jal         0x80172FE0
    // 0x801762E8: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x801762E8: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x801762EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801762F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801762F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801762F8: jr          $ra
    // 0x801762FC: nop

    return;
    // 0x801762FC: nop

;}
RECOMP_FUNC void gmCameraPlayerZoomFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CAE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010CAE4: lw          $t6, 0x14F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X14F4);
    // 0x8010CAE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CAF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010CAF4: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8010CAF8: jal         0x8010CA7C
    // 0x8010CAFC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    gmCameraCheckPausePlayerOutBounds(rdram, ctx);
        goto after_0;
    // 0x8010CAFC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8010CB00: beq         $v0, $zero, L_8010CB30
    if (ctx->r2 == 0) {
        // 0x8010CB04: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010CB30;
    }
    // 0x8010CB04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010CB08: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010CB0C: lw          $t7, 0x14B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X14B0);
    // 0x8010CB10: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010CB14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8010CB18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8010CB1C: lw          $t9, -0x144C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X144C);
    // 0x8010CB20: jalr        $t9
    // 0x8010CB24: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8010CB24: nop

    after_1:
    // 0x8010CB28: b           L_8010CB3C
    // 0x8010CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010CB3C;
    // 0x8010CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010CB30:
    // 0x8010CB30: jal         0x8010C960
    // 0x8010CB34: nop

    gmCameraUpdatePlayerZoom(rdram, ctx);
        goto after_2;
    // 0x8010CB34: nop

    after_2:
    // 0x8010CB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010CB3C:
    // 0x8010CB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CB40: jr          $ra
    // 0x8010CB44: nop

    return;
    // 0x8010CB44: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801633EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801633F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801633F4: addiu       $t6, $zero, 0x824
    ctx->r14 = ADD32(0, 0X824);
    // 0x801633F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801633FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80163400: addiu       $a1, $zero, 0x117
    ctx->r5 = ADD32(0, 0X117);
    // 0x80163404: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163408: jal         0x800E6F24
    // 0x8016340C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016340C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80163410: jal         0x80161E94
    // 0x80163414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x80163414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80163418: jal         0x800E0830
    // 0x8016341C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8016341C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80163420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163428: jr          $ra
    // 0x8016342C: nop

    return;
    // 0x8016342C: nop

;}
RECOMP_FUNC void ftBossHarauSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801594BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801594C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801594C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801594C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801594CC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x801594D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801594D4: jal         0x800E6F24
    // 0x801594D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801594D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801594DC: jal         0x80157F90
    // 0x801594E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftBossCommonCheckEdgeInvertLR(rdram, ctx);
        goto after_1;
    // 0x801594E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801594E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801594E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801594EC: jr          $ra
    // 0x801594F0: nop

    return;
    // 0x801594F0: nop

;}
RECOMP_FUNC void ftCommonHarisenSwingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146CA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80146CA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80146CA8: lw          $t6, 0x84C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84C);
    // 0x80146CAC: beq         $t6, $zero, L_80146CDC
    if (ctx->r14 == 0) {
        // 0x80146CB0: nop
    
            goto L_80146CDC;
    }
    // 0x80146CB0: nop

    // 0x80146CB4: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80146CB8: beq         $v1, $zero, L_80146CDC
    if (ctx->r3 == 0) {
        // 0x80146CBC: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80146CDC;
    }
    // 0x80146CBC: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80146CC0: bne         $t7, $zero, L_80146CDC
    if (ctx->r15 != 0) {
        // 0x80146CC4: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_80146CDC;
    }
    // 0x80146CC4: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80146CC8: lw          $a0, 0x84C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84C);
    // 0x80146CCC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80146CD0: jal         0x80175140
    // 0x80146CD4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    itHarisenCommonSetScale(rdram, ctx);
        goto after_0;
    // 0x80146CD4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x80146CD8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80146CDC:
    // 0x80146CDC: jal         0x800D94C4
    // 0x80146CE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x80146CE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80146CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146CEC: jr          $ra
    // 0x80146CF0: nop

    return;
    // 0x80146CF0: nop

;}
RECOMP_FUNC void mpCollisionCheckRWallLineCollisionSame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6B58: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800F6B5C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F6B60: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F6B64: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F6B68: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F6B6C: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F6B70: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F6B74: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F6B78: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F6B7C: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F6B80: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F6B84: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F6B88: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F6B8C: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F6B90: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F6B94: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F6B98: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F6B9C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F6BA0: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F6BA4: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F6BA8: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800F6BAC: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800F6BB0: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800F6BB4: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    // 0x800F6BB8: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6BBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6BC0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F6BC4: blez        $t0, L_800F713C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F6BC8: lwc1        $f22, 0x830($at)
        ctx->f22.u32l = MEM_W(ctx->r1, 0X830);
            goto L_800F713C;
    }
    // 0x800F6BC8: lwc1        $f22, 0x830($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X830);
    // 0x800F6BCC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6BD0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6BD4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F6BD8: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F6BDC: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6BE0: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x800F6BE4: lw          $s6, 0x114($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X114);
    // 0x800F6BE8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F6BEC:
    // 0x800F6BEC: addiu       $a0, $t4, 0xA
    ctx->r4 = ADD32(ctx->r12, 0XA);
    // 0x800F6BF0: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800F6BF4: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F6BF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F6BFC: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800F6C00: lhu         $t5, 0xC($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XC);
    // 0x800F6C04: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F6C08: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800F6C0C: beq         $t5, $zero, L_800F7124
    if (ctx->r13 == 0) {
        // 0x800F6C10: lw          $v0, 0x0($t9)
        ctx->r2 = MEM_W(ctx->r25, 0X0);
            goto L_800F7124;
    }
    // 0x800F6C10: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800F6C14: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F6C18: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800F6C1C: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800F6C20: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F6C24: beql        $at, $zero, L_800F7128
    if (ctx->r1 == 0) {
        // 0x800F6C28: lw          $t8, 0xF0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XF0);
            goto L_800F7128;
    }
    goto skip_0;
    // 0x800F6C28: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    skip_0:
    // 0x800F6C2C: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F6C30: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800F6C34: lwc1        $f2, 0x4($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F6C38: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F6C3C: bne         $t8, $zero, L_800F6C4C
    if (ctx->r24 != 0) {
        // 0x800F6C40: lwc1        $f14, 0x4($t6)
        ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
            goto L_800F6C4C;
    }
    // 0x800F6C40: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F6C44: beql        $v1, $zero, L_800F6C74
    if (ctx->r3 == 0) {
        // 0x800F6C48: mov.s       $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
            goto L_800F6C74;
    }
    goto skip_1;
    // 0x800F6C48: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    skip_1:
L_800F6C4C:
    // 0x800F6C4C: lwc1        $f30, 0x20($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F6C50: lwc1        $f28, 0x1C($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F6C54: sub.s       $f4, $f2, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F6C58: sub.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F6C5C: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x800F6C60: sub.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800F6C64: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800F6C68: b           L_800F6C88
    // 0x800F6C6C: sub.s       $f26, $f12, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f12.fl - ctx->f28.fl;
        goto L_800F6C88;
    // 0x800F6C6C: sub.s       $f26, $f12, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f12.fl - ctx->f28.fl;
    // 0x800F6C70: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
L_800F6C74:
    // 0x800F6C74: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    // 0x800F6C78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F6C7C: swc1        $f2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f2.u32l;
    // 0x800F6C80: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800F6C84: swc1        $f14, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f14.u32l;
L_800F6C88:
    // 0x800F6C88: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F6C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6C90: bc1f        L_800F6CBC
    if (!c1cs) {
        // 0x800F6C94: nop
    
            goto L_800F6CBC;
    }
    // 0x800F6C94: nop

    // 0x800F6C98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6C9C: lwc1        $f8, 0x834($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X834);
    // 0x800F6CA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6CA4: lwc1        $f16, 0x838($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X838);
    // 0x800F6CA8: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800F6CAC: add.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x800F6CB0: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x800F6CB4: b           L_800F6CD8
    // 0x800F6CB8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_800F6CD8;
    // 0x800F6CB8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800F6CBC:
    // 0x800F6CBC: lwc1        $f4, 0x83C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X83C);
    // 0x800F6CC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6CC4: lwc1        $f8, 0x840($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X840);
    // 0x800F6CC8: sub.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x800F6CCC: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x800F6CD0: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x800F6CD4: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F6CD8:
    // 0x800F6CD8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F6CDC: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800F6CE0: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800F6CE4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F6CE8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F6CEC: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x800F6CF0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F6CF4: beq         $at, $zero, L_800F7120
    if (ctx->r1 == 0) {
        // 0x800F6CF8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F7120;
    }
    // 0x800F6CF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F6CFC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800F6D00: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
L_800F6D04:
    // 0x800F6D04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F6D08: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F6D0C: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F6D10: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800F6D14: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800F6D18: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800F6D1C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800F6D20: nop

    // 0x800F6D24: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F6D28: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800F6D2C: nop

    // 0x800F6D30: bc1fl       L_800F6D4C
    if (!c1cs) {
        // 0x800F6D34: sw          $v1, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r3;
            goto L_800F6D4C;
    }
    goto skip_2;
    // 0x800F6D34: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
    skip_2:
    // 0x800F6D38: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F6D3C: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800F6D40: b           L_800F7104
    // 0x800F6D44: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
        goto L_800F7104;
    // 0x800F6D44: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x800F6D48: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
L_800F6D4C:
    // 0x800F6D4C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800F6D50: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800F6D54: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F6D58: lw          $s7, 0xC8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6D5C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800F6D60: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F6D64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F6D68: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800F6D6C: nop

    // 0x800F6D70: bc1f        L_800F6D88
    if (!c1cs) {
        // 0x800F6D74: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F6D88;
    }
    // 0x800F6D74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F6D78: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F6D7C: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x800F6D80: b           L_800F7124
    // 0x800F6D84: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
        goto L_800F7124;
    // 0x800F6D84: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F6D88:
    // 0x800F6D88: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F6D8C: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F6D90: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F6D94: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F6D98: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6D9C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F6DA0: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F6DA4: addu        $t7, $t5, $s2
    ctx->r15 = ADD32(ctx->r13, ctx->r18);
    // 0x800F6DA8: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F6DAC: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6DB0: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F6DB4: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800F6DB8: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800F6DBC: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F6DC0: mflo        $t8
    ctx->r24 = lo;
    // 0x800F6DC4: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800F6DC8: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F6DCC: beq         $at, $zero, L_800F70EC
    if (ctx->r1 == 0) {
        // 0x800F6DD0: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F70EC;
    }
    // 0x800F6DD0: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F6DD4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
L_800F6DD8:
    // 0x800F6DD8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F6DDC: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800F6DE0: addu        $t5, $t8, $s2
    ctx->r13 = ADD32(ctx->r24, ctx->r18);
    // 0x800F6DE4: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x800F6DE8: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x800F6DEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F6DF0: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F6DF4: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F6DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F6DFC: mflo        $t6
    ctx->r14 = lo;
    // 0x800F6E00: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800F6E04: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F6E08: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F6E0C: addiu       $t6, $sp, 0xB0
    ctx->r14 = ADD32(ctx->r29, 0XB0);
    // 0x800F6E10: bne         $s0, $s3, L_800F6F68
    if (ctx->r16 != ctx->r19) {
        // 0x800F6E14: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F6F68;
    }
    // 0x800F6E14: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F6E18: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x800F6E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F6E20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F6E24: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F6E28: bc1f        L_800F70BC
    if (!c1cs) {
        // 0x800F6E2C: lwc1        $f18, 0xE0($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
            goto L_800F70BC;
    }
    // 0x800F6E2C: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F6E30: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F6E34: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800F6E38: addiu       $t8, $sp, 0xB0
    ctx->r24 = ADD32(ctx->r29, 0XB0);
    // 0x800F6E3C: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F6E40: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800F6E44: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F6E48: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800F6E4C: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x800F6E50: jal         0x800F7D24
    // 0x800F6E54: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    mpCollisionCheckLRSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F6E54: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800F6E58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6E5C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6E60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F6E64: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6E68: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F6E6C: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F6E70: bne         $v0, $at, L_800F70BC
    if (ctx->r2 != ctx->r1) {
        // 0x800F6E74: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F70BC;
    }
    // 0x800F6E74: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F6E78: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6E7C: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6E80: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F6E84: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F6E88: nop

    // 0x800F6E8C: bc1fl       L_800F6EA4
    if (!c1cs) {
        // 0x800F6E90: sub.s       $f0, $f6, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800F6EA4;
    }
    goto skip_3;
    // 0x800F6E90: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    skip_3:
    // 0x800F6E94: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F6E98: b           L_800F6EA4
    // 0x800F6E9C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F6EA4;
    // 0x800F6E9C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F6EA0: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
L_800F6EA4:
    // 0x800F6EA4: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F6EA8: nop

    // 0x800F6EAC: bc1f        L_800F6ED4
    if (!c1cs) {
        // 0x800F6EB0: nop
    
            goto L_800F6ED4;
    }
    // 0x800F6EB0: nop

    // 0x800F6EB4: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F6EB8: addu        $v0, $t7, $s7
    ctx->r2 = ADD32(ctx->r15, ctx->r23);
    // 0x800F6EBC: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6EC0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6EC4: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F6EC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F6ECC: b           L_800F70DC
    // 0x800F6ED0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F70DC;
    // 0x800F6ED0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F6ED4:
    // 0x800F6ED4: beq         $s5, $zero, L_800F6EF4
    if (ctx->r21 == 0) {
        // 0x800F6ED8: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F6EF4;
    }
    // 0x800F6ED8: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6EDC: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800F6EE0: swc1        $f10, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f10.u32l;
    // 0x800F6EE4: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F6EE8: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F6EEC: add.s       $f16, $f18, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f30.fl;
    // 0x800F6EF0: swc1        $f16, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f16.u32l;
L_800F6EF4:
    // 0x800F6EF4: beq         $t0, $zero, L_800F6F00
    if (ctx->r8 == 0) {
        // 0x800F6EF8: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800F6F00;
    }
    // 0x800F6EF8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6EFC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800F6F00:
    // 0x800F6F00: beq         $s6, $zero, L_800F6F18
    if (ctx->r22 == 0) {
        // 0x800F6F04: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800F6F18;
    }
    // 0x800F6F04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F6F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F6F0C: swc1        $f24, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f24.u32l;
    // 0x800F6F10: swc1        $f24, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f24.u32l;
    // 0x800F6F14: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
L_800F6F18:
    // 0x800F6F18: beql        $fp, $zero, L_800F6F48
    if (ctx->r30 == 0) {
        // 0x800F6F1C: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F6F48;
    }
    goto skip_4;
    // 0x800F6F1C: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    skip_4:
    // 0x800F6F20: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F6F24: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F6F28: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F6F2C: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F6F30: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F6F34: mflo        $t8
    ctx->r24 = lo;
    // 0x800F6F38: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800F6F3C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F6F40: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F6F44: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
L_800F6F48:
    // 0x800F6F48: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x800F6F4C: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800F6F50: bc1f        L_800F6F60
    if (!c1cs) {
        // 0x800F6F54: nop
    
            goto L_800F6F60;
    }
    // 0x800F6F54: nop

    // 0x800F6F58: b           L_800F70BC
    // 0x800F6F5C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F70BC;
    // 0x800F6F5C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F6F60:
    // 0x800F6F60: b           L_800F70BC
    // 0x800F6F64: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F70BC;
    // 0x800F6F64: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F6F68:
    // 0x800F6F68: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F6F6C: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F6F70: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F6F74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800F6F78: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x800F6F7C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800F6F80: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800F6F84: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800F6F88: jal         0x800F7270
    // 0x800F6F8C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckRWallSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F6F8C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800F6F90: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6F94: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F6F9C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6FA0: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F6FA4: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F6FA8: bne         $v0, $at, L_800F70BC
    if (ctx->r2 != ctx->r1) {
        // 0x800F6FAC: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F70BC;
    }
    // 0x800F6FAC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F6FB0: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6FB4: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6FB8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F6FBC: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x800F6FC0: nop

    // 0x800F6FC4: bc1fl       L_800F6FDC
    if (!c1cs) {
        // 0x800F6FC8: sub.s       $f0, $f16, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
            goto L_800F6FDC;
    }
    goto skip_5;
    // 0x800F6FC8: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    skip_5:
    // 0x800F6FCC: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x800F6FD0: b           L_800F6FDC
    // 0x800F6FD4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F6FDC;
    // 0x800F6FD4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F6FD8: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
L_800F6FDC:
    // 0x800F6FDC: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F6FE0: nop

    // 0x800F6FE4: bc1f        L_800F700C
    if (!c1cs) {
        // 0x800F6FE8: nop
    
            goto L_800F700C;
    }
    // 0x800F6FE8: nop

    // 0x800F6FEC: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F6FF0: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F6FF4: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6FF8: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6FFC: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F7000: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F7004: b           L_800F70DC
    // 0x800F7008: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F70DC;
    // 0x800F7008: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F700C:
    // 0x800F700C: beq         $s5, $zero, L_800F702C
    if (ctx->r21 == 0) {
        // 0x800F7010: lwc1        $f4, 0xB0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F702C;
    }
    // 0x800F7010: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F7014: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x800F7018: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x800F701C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F7020: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F7024: add.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800F7028: swc1        $f10, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f10.u32l;
L_800F702C:
    // 0x800F702C: beq         $t0, $zero, L_800F7038
    if (ctx->r8 == 0) {
        // 0x800F7030: lw          $t6, 0xC8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC8);
            goto L_800F7038;
    }
    // 0x800F7030: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800F7034: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_800F7038:
    // 0x800F7038: beq         $s6, $zero, L_800F7070
    if (ctx->r22 == 0) {
        // 0x800F703C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F7070;
    }
    // 0x800F703C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F7040: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800F7044: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F7048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F704C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F7050: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F7054: jal         0x800F71A0
    // 0x800F7058: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRAngle(rdram, ctx);
        goto after_2;
    // 0x800F7058: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F705C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F7060: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F7064: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F7068: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F706C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F7070:
    // 0x800F7070: beql        $fp, $zero, L_800F70A0
    if (ctx->r30 == 0) {
        // 0x800F7074: lwc1        $f18, 0xB0($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F70A0;
    }
    goto skip_6;
    // 0x800F7074: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    skip_6:
    // 0x800F7078: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F707C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800F7080: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F7084: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F7088: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F708C: mflo        $t5
    ctx->r13 = lo;
    // 0x800F7090: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800F7094: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F7098: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F709C: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
L_800F70A0:
    // 0x800F70A0: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x800F70A4: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x800F70A8: bc1fl       L_800F70BC
    if (!c1cs) {
        // 0x800F70AC: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F70BC;
    }
    goto skip_7;
    // 0x800F70AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_7:
    // 0x800F70B0: b           L_800F70BC
    // 0x800F70B4: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F70BC;
    // 0x800F70B4: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F70B8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F70BC:
    // 0x800F70BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F70C0: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F70C4: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F70C8: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F70CC: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800F70D0: addu        $v1, $t8, $t5
    ctx->r3 = ADD32(ctx->r24, ctx->r13);
    // 0x800F70D4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F70D8: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F70DC:
    // 0x800F70DC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F70E0: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F70E4: bnel        $at, $zero, L_800F6DD8
    if (ctx->r1 != 0) {
        // 0x800F70E8: lw          $t8, 0x0($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X0);
            goto L_800F6DD8;
    }
    goto skip_8;
    // 0x800F70E8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    skip_8:
L_800F70EC:
    // 0x800F70EC: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800F70F0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800F70F4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F70F8: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x800F70FC: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x800F7100: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
L_800F7104:
    // 0x800F7104: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F7108: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F710C: bne         $at, $zero, L_800F6D04
    if (ctx->r1 != 0) {
        // 0x800F7110: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F6D04;
    }
    // 0x800F7110: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F7114: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F7118: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F711C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F7120:
    // 0x800F7120: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
L_800F7124:
    // 0x800F7124: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
L_800F7128:
    // 0x800F7128: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x800F712C: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800F7130: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F7134: bne         $at, $zero, L_800F6BEC
    if (ctx->r1 != 0) {
        // 0x800F7138: sw          $t5, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->r13;
            goto L_800F6BEC;
    }
    // 0x800F7138: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
L_800F713C:
    // 0x800F713C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7140: lwc1        $f16, 0x844($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X844);
    // 0x800F7144: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F7148: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F714C: c.eq.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl == ctx->f16.fl;
    // 0x800F7150: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F7154: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F7158: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F715C: bc1f        L_800F716C
    if (!c1cs) {
        // 0x800F7160: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F716C;
    }
    // 0x800F7160: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F7164: b           L_800F7170
    // 0x800F7168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7170;
    // 0x800F7168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F716C:
    // 0x800F716C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F7170:
    // 0x800F7170: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F7174: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F7178: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F717C: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F7180: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F7184: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F7188: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F718C: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F7190: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F7194: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F7198: jr          $ra
    // 0x800F719C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800F719C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void mvOpeningFoxMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB6C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB74: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB78: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DB7C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DB80: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DB84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DB88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DB8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DB90: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DB94: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DB98: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DB9C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DBA0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DBA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DBA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBAC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DBB0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DBB4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBB8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBC0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBC4: jal         0x8000B93C
    // 0x8018DBC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBCC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBD4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBD8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DBDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DBE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DBE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DBE8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DBEC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DBF0: jal         0x80007080
    // 0x8018DBF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DBF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DBF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DBFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DC00: jr          $ra
    // 0x8018DC04: nop

    return;
    // 0x8018DC04: nop

;}
RECOMP_FUNC void func_ovl2_800FB04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB04C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800FB050: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FB054: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800FB058: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FB05C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x800FB060: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800FB064: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800FB068: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800FB06C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800FB070: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800FB074: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800FB078: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800FB07C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800FB080: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800FB084: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800FB088: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800FB08C: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x800FB090: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800FB094: addiu       $ra, $ra, 0x1378
    ctx->r31 = ADD32(ctx->r31, 0X1378);
    // 0x800FB098: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800FB09C: blez        $t7, L_800FB270
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800FB0A0: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800FB270;
    }
    // 0x800FB0A0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800FB0A4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800FB0A8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800FB0AC: addiu       $s3, $s3, 0x136C
    ctx->r19 = ADD32(ctx->r19, 0X136C);
    // 0x800FB0B0: addiu       $s4, $s4, 0x1370
    ctx->r20 = ADD32(ctx->r20, 0X1370);
    // 0x800FB0B4: addiu       $s5, $s5, 0x1374
    ctx->r21 = ADD32(ctx->r21, 0X1374);
    // 0x800FB0B8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
L_800FB0BC:
    // 0x800FB0BC: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800FB0C0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800FB0C4: addiu       $a0, $t8, 0x2
    ctx->r4 = ADD32(ctx->r24, 0X2);
    // 0x800FB0C8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x800FB0CC: lhu         $fp, 0x0($t8)
    ctx->r30 = MEM_HU(ctx->r24, 0X0);
L_800FB0D0:
    // 0x800FB0D0: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800FB0D4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB0D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FB0DC: blez        $t9, L_800FB234
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800FB0E0: lw          $t6, 0x88($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X88);
            goto L_800FB234;
    }
    // 0x800FB0E0: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800FB0E4: sll         $s0, $s6, 2
    ctx->r16 = S32(ctx->r22 << 2);
    // 0x800FB0E8: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x800FB0EC: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800FB0F0: addu        $s7, $t6, $t3
    ctx->r23 = ADD32(ctx->r14, ctx->r11);
    // 0x800FB0F4: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800FB0F8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800FB0FC: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
L_800FB100:
    // 0x800FB100: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800FB104: beq         $at, $zero, L_800FB138
    if (ctx->r1 == 0) {
        // 0x800FB108: addu        $a0, $s2, $t7
        ctx->r4 = ADD32(ctx->r18, ctx->r15);
            goto L_800FB138;
    }
    // 0x800FB108: addu        $a0, $s2, $t7
    ctx->r4 = ADD32(ctx->r18, ctx->r15);
    // 0x800FB10C: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB110: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x800FB114: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x800FB118: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800FB11C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800FB120: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800FB124: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB128: mflo        $t7
    ctx->r15 = lo;
    // 0x800FB12C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800FB130: b           L_800FB160
    // 0x800FB134: lh          $t1, 0x2($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X2);
        goto L_800FB160;
    // 0x800FB134: lh          $t1, 0x2($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X2);
L_800FB138:
    // 0x800FB138: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB13C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x800FB140: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x800FB144: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800FB148: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x800FB14C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800FB150: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB154: mflo        $t8
    ctx->r24 = lo;
    // 0x800FB158: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800FB15C: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
L_800FB160:
    // 0x800FB160: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800FB164: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800FB168: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800FB16C: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x800FB170: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800FB174: beq         $at, $zero, L_800FB1EC
    if (ctx->r1 == 0) {
        // 0x800FB178: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_800FB1EC;
    }
    // 0x800FB178: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800FB17C: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x800FB180: addu        $v1, $t2, $a0
    ctx->r3 = ADD32(ctx->r10, ctx->r4);
    // 0x800FB184: sll         $t1, $t5, 1
    ctx->r9 = S32(ctx->r13 << 1);
L_800FB188:
    // 0x800FB188: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800FB18C: beq         $at, $zero, L_800FB1AC
    if (ctx->r1 == 0) {
        // 0x800FB190: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800FB1AC;
    }
    // 0x800FB190: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800FB194: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800FB198: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB19C: mflo        $t8
    ctx->r24 = lo;
    // 0x800FB1A0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800FB1A4: b           L_800FB1C0
    // 0x800FB1A8: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
        goto L_800FB1C0;
    // 0x800FB1A8: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
L_800FB1AC:
    // 0x800FB1AC: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x800FB1B0: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB1B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800FB1B8: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800FB1BC: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
L_800FB1C0:
    // 0x800FB1C0: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800FB1C4: bnel        $at, $zero, L_800FB1D4
    if (ctx->r1 != 0) {
        // 0x800FB1C8: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800FB1D4;
    }
    goto skip_0;
    // 0x800FB1C8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x800FB1CC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800FB1D0: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_800FB1D4:
    // 0x800FB1D4: bnel        $at, $zero, L_800FB1E4
    if (ctx->r1 != 0) {
        // 0x800FB1D8: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800FB1E4;
    }
    goto skip_1;
    // 0x800FB1D8: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x800FB1DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FB1E0: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
L_800FB1E4:
    // 0x800FB1E4: bne         $at, $zero, L_800FB188
    if (ctx->r1 != 0) {
        // 0x800FB1E8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800FB188;
    }
    // 0x800FB1E8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_800FB1EC:
    // 0x800FB1EC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800FB1F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800FB1F4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800FB1F8: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x800FB1FC: sh          $a3, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r7;
    // 0x800FB200: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800FB204: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800FB208: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800FB20C: sh          $a2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r6;
    // 0x800FB210: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800FB214: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x800FB218: sb          $fp, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r30;
    // 0x800FB21C: lhu         $t7, 0x2($s7)
    ctx->r15 = MEM_HU(ctx->r23, 0X2);
    // 0x800FB220: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800FB224: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800FB228: bnel        $at, $zero, L_800FB100
    if (ctx->r1 != 0) {
        // 0x800FB22C: lw          $t7, 0x0($ra)
        ctx->r15 = MEM_W(ctx->r31, 0X0);
            goto L_800FB100;
    }
    goto skip_2;
    // 0x800FB22C: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    skip_2:
    // 0x800FB230: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_800FB234:
    // 0x800FB234: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800FB238: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800FB23C: bne         $t3, $at, L_800FB0D0
    if (ctx->r11 != ctx->r1) {
        // 0x800FB240: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800FB0D0;
    }
    // 0x800FB240: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800FB244: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FB248: lw          $t8, 0x1368($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1368);
    // 0x800FB24C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800FB250: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800FB254: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x800FB258: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800FB25C: addiu       $t8, $t7, 0x12
    ctx->r24 = ADD32(ctx->r15, 0X12);
    // 0x800FB260: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800FB264: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x800FB268: bne         $at, $zero, L_800FB0BC
    if (ctx->r1 != 0) {
        // 0x800FB26C: sw          $t6, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r14;
            goto L_800FB0BC;
    }
    // 0x800FB26C: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
L_800FB270:
    // 0x800FB270: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB274: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800FB278: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800FB27C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800FB280: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800FB284: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800FB288: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB28C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800FB290: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800FB294: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800FB298: jr          $ra
    // 0x800FB29C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800FB29C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_ovl8_803812BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803812BC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x803812C0: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x803812C4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x803812C8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x803812CC: beq         $at, $zero, L_80381300
    if (ctx->r1 == 0) {
        // 0x803812D0: nop
    
            goto L_80381300;
    }
    // 0x803812D0: nop

    // 0x803812D4: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x803812D8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x803812DC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x803812E0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x803812E4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x803812E8: sw          $t8, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r24;
    // 0x803812EC: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    // 0x803812F0: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x803812F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x803812F8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x803812FC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80381300:
    // 0x80381300: jr          $ra
    // 0x80381304: nop

    return;
    // 0x80381304: nop

;}
RECOMP_FUNC void syMatrixOrthoF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B050: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8001B054: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B058: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B05C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001B060: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8001B064: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B068: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8001B06C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8001B070: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001B074: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001B078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B07C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001B080: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001B084: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001B088: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001B08C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001B090: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B098: div.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001B09C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x8001B0A0: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001B0A4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B0A8: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001B0AC: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8001B0B0: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001B0B4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001B0B8: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001B0BC: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8001B0C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B0C4: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x8001B0C8: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001B0CC: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001B0D0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001B0D4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001B0D8: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001B0DC: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x8001B0E0: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001B0E4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B0E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001B0EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B0F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001B0F4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8001B0F8: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001B0FC: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
L_8001B100:
    // 0x8001B100: beq         $v0, $zero, L_8001B110
    if (ctx->r2 == 0) {
        // 0x8001B104: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_8001B110;
    }
    // 0x8001B104: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8001B108: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8001B10C: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
L_8001B110:
    // 0x8001B110: beq         $v0, $v1, L_8001B120
    if (ctx->r2 == ctx->r3) {
        // 0x8001B114: sll         $t8, $v0, 4
        ctx->r24 = S32(ctx->r2 << 4);
            goto L_8001B120;
    }
    // 0x8001B114: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8001B118: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8001B11C: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
L_8001B120:
    // 0x8001B120: beq         $v0, $a1, L_8001B130
    if (ctx->r2 == ctx->r5) {
        // 0x8001B124: sll         $t0, $v0, 4
        ctx->r8 = S32(ctx->r2 << 4);
            goto L_8001B130;
    }
    // 0x8001B124: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x8001B128: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8001B12C: swc1        $f0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f0.u32l;
L_8001B130:
    // 0x8001B130: beq         $v0, $a2, L_8001B140
    if (ctx->r2 == ctx->r6) {
        // 0x8001B134: sll         $t2, $v0, 4
        ctx->r10 = S32(ctx->r2 << 4);
            goto L_8001B140;
    }
    // 0x8001B134: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8001B138: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8001B13C: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
L_8001B140:
    // 0x8001B140: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B144: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001B148: bne         $at, $zero, L_8001B100
    if (ctx->r1 != 0) {
        // 0x8001B14C: nop
    
            goto L_8001B100;
    }
    // 0x8001B14C: nop

    // 0x8001B150: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001B154: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8001B158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B15C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001B160: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001B164: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B168: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001B16C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001B170: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001B174: beq         $v0, $a0, L_8001B1B8
    if (ctx->r2 == ctx->r4) {
        // 0x8001B178: lwc1        $f16, 0xC($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
            goto L_8001B1B8;
    }
    // 0x8001B178: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
L_8001B17C:
    // 0x8001B17C: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001B180: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8001B184: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8001B188: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001B18C: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8001B190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B194: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001B198: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8001B19C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8001B1A0: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001B1A4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8001B1A8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8001B1AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001B1B0: bne         $v0, $a0, L_8001B17C
    if (ctx->r2 != ctx->r4) {
        // 0x8001B1B4: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8001B17C;
    }
    // 0x8001B1B4: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
L_8001B1B8:
    // 0x8001B1B8: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001B1BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001B1C0: swc1        $f12, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f12.u32l;
    // 0x8001B1C4: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001B1C8: nop

    // 0x8001B1CC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001B1D0: swc1        $f10, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8001B1D4: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x8001B1D8: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8001B1DC: jr          $ra
    // 0x8001B1E0: nop

    return;
    // 0x8001B1E0: nop

;}
RECOMP_FUNC void ftYoshiSpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015EDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EDC8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015EDCC: jal         0x800D9480
    // 0x8015EDD0: addiu       $a1, $a1, -0xF58
    ctx->r5 = ADD32(ctx->r5, -0XF58);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015EDD0: addiu       $a1, $a1, -0xF58
    ctx->r5 = ADD32(ctx->r5, -0XF58);
    after_0:
    // 0x8015EDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015EDDC: jr          $ra
    // 0x8015EDE0: nop

    return;
    // 0x8015EDE0: nop

;}

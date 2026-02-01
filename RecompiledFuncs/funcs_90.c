#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void scStaffrollGetLockOnPositionY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013211C: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x80132120: beq         $at, $zero, L_8013212C
    if (ctx->r1 == 0) {
        // 0x80132124: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8013212C;
    }
    // 0x80132124: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80132128: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_8013212C:
    // 0x8013212C: slti        $at, $a0, 0x1CD
    ctx->r1 = SIGNED(ctx->r4) < 0X1CD ? 1 : 0;
    // 0x80132130: bne         $at, $zero, L_8013213C
    if (ctx->r1 != 0) {
        // 0x80132134: nop
    
            goto L_8013213C;
    }
    // 0x80132134: nop

    // 0x80132138: addiu       $v1, $zero, 0x1CC
    ctx->r3 = ADD32(0, 0X1CC);
L_8013213C:
    // 0x8013213C: jr          $ra
    // 0x80132140: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132140: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_80371790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371790: jr          $ra
    // 0x80371794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80371794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnVSItemSwitchMakeItemList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013208C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132094: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132098: jal         0x80009968
    // 0x8013209C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013209C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801320A0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801320A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801320A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801320AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801320B0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801320B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801320B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801320BC: jal         0x80009DF4
    // 0x801320C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801320C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801320C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801320C8: lw          $t7, 0x3530($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3530);
    // 0x801320CC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801320D0: addiu       $t8, $t8, 0x5E60
    ctx->r24 = ADD32(ctx->r24, 0X5E60);
    // 0x801320D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801320D8: jal         0x800CCFDC
    // 0x801320DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801320DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801320E0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801320E4: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x801320E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320EC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x801320F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801320F4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801320F8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801320FC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132100: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132104: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132108: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013210C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132110: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132114: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132118: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013211C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132120: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132124: jr          $ra
    // 0x80132128: nop

    return;
    // 0x80132128: nop

;}
RECOMP_FUNC void mnMessageMakeMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D9C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80131DA0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131DA8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80131DAC: addiu       $t7, $t7, 0x2548
    ctx->r15 = ADD32(ctx->r15, 0X2548);
    // 0x80131DB0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131DB4: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80131DB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131DBC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131DC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131DC4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131DC8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131DCC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131DD0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80131DD4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131DD8: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80131DDC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80131DE0: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80131DE4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131DE8: addiu       $t1, $t1, 0x2564
    ctx->r9 = ADD32(ctx->r9, 0X2564);
    // 0x80131DEC: addiu       $t4, $t1, 0x30
    ctx->r12 = ADD32(ctx->r9, 0X30);
    // 0x80131DF0: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80131DF4: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80131DF8: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
L_80131DFC:
    // 0x80131DFC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131E00: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131E04: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80131E08: sw          $t3, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r11;
    // 0x80131E0C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80131E10: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x80131E14: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80131E18: bne         $t1, $t4, L_80131DFC
    if (ctx->r9 != ctx->r12) {
        // 0x80131E1C: sw          $t3, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r11;
            goto L_80131DFC;
    }
    // 0x80131E1C: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x80131E20: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131E24: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80131E28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E30: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131E34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131E38: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131E3C: jal         0x80009968
    // 0x80131E40: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E40: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    after_0:
    // 0x80131E44: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131E48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80131E4C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80131E50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80131E54: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E60: jal         0x80009DF4
    // 0x80131E64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131E68: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80131E6C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131E70: lw          $t9, 0x298C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X298C);
    // 0x80131E74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80131E78: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80131E7C: lw          $t8, 0x5C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C);
    // 0x80131E80: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80131E84: jal         0x800CCFDC
    // 0x80131E88: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131E88: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131E8C: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E90: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80131E94: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80131E98: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131E9C: ori         $t2, $t0, 0x1
    ctx->r10 = ctx->r8 | 0X1;
    // 0x80131EA0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131EA4: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80131EA8: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80131EAC: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80131EB0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80131EB4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80131EB8: nop

    // 0x80131EBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131EC0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131EC4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80131EC8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80131ECC: nop

    // 0x80131ED0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131ED4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131ED8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131EDC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80131EE0: jr          $ra
    // 0x80131EE4: nop

    return;
    // 0x80131EE4: nop

;}
RECOMP_FUNC void mpCommonSetFighterGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEE98: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800DEE9C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800DEEA0: lbu         $t7, 0x28E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X28E);
    // 0x800DEEA4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800DEEA8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800DEEAC: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x800DEEB0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DEEB4: sb          $zero, 0x148($a0)
    MEM_B(0X148, ctx->r4) = 0;
    // 0x800DEEB8: sb          $t8, 0x28E($a0)
    MEM_B(0X28E, ctx->r4) = ctx->r24;
    // 0x800DEEBC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800DEEC0: jr          $ra
    // 0x800DEEC4: swc1        $f10, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800DEEC4: swc1        $f10, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void mnVSResultsGetPlacePlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132100: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132104: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80132108: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013210C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132110: beq         $t6, $zero, L_8013212C
    if (ctx->r14 == 0) {
        // 0x80132114: nop
    
            goto L_8013212C;
    }
    // 0x80132114: nop

    // 0x80132118: lw          $t7, -0x6450($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6450);
    // 0x8013211C: bne         $a0, $t7, L_8013212C
    if (ctx->r4 != ctx->r15) {
        // 0x80132120: nop
    
            goto L_8013212C;
    }
    // 0x80132120: nop

    // 0x80132124: jr          $ra
    // 0x80132128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013212C:
    // 0x8013212C: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x80132130: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80132134: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80132138: beq         $t8, $zero, L_80132154
    if (ctx->r24 == 0) {
        // 0x8013213C: nop
    
            goto L_80132154;
    }
    // 0x8013213C: nop

    // 0x80132140: lw          $t9, -0x644C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X644C);
    // 0x80132144: bne         $a0, $t9, L_80132154
    if (ctx->r4 != ctx->r25) {
        // 0x80132148: nop
    
            goto L_80132154;
    }
    // 0x80132148: nop

    // 0x8013214C: jr          $ra
    // 0x80132150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132154:
    // 0x80132154: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x80132158: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013215C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132160: beq         $t0, $zero, L_8013217C
    if (ctx->r8 == 0) {
        // 0x80132164: nop
    
            goto L_8013217C;
    }
    // 0x80132164: nop

    // 0x80132168: lw          $t1, -0x6448($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6448);
    // 0x8013216C: bne         $a0, $t1, L_8013217C
    if (ctx->r4 != ctx->r9) {
        // 0x80132170: nop
    
            goto L_8013217C;
    }
    // 0x80132170: nop

    // 0x80132174: jr          $ra
    // 0x80132178: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80132178: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013217C:
    // 0x8013217C: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x80132180: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80132184: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80132188: beq         $t2, $zero, L_801321A4
    if (ctx->r10 == 0) {
        // 0x8013218C: nop
    
            goto L_801321A4;
    }
    // 0x8013218C: nop

    // 0x80132190: lw          $t3, -0x6444($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6444);
    // 0x80132194: bne         $a0, $t3, L_801321A4
    if (ctx->r4 != ctx->r11) {
        // 0x80132198: nop
    
            goto L_801321A4;
    }
    // 0x80132198: nop

    // 0x8013219C: jr          $ra
    // 0x801321A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801321A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801321A4:
    // 0x801321A4: jr          $ra
    // 0x801321A8: nop

    return;
    // 0x801321A8: nop

;}
RECOMP_FUNC void itLinkBombFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185F40: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80185F44: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80185F48: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80185F4C: addiu       $a3, $a3, 0x5F70
    ctx->r7 = ADD32(ctx->r7, 0X5F70);
    // 0x80185F50: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80185F54: jal         0x80173B24
    // 0x80185F58: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80185F58: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80185F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185F68: jr          $ra
    // 0x80185F6C: nop

    return;
    // 0x80185F6C: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsMainProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801118B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801118B8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x801118BC: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x801118C0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801118C4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801118C8: addiu       $t8, $t8, -0x1108
    ctx->r24 = ADD32(ctx->r24, -0X1108);
    // 0x801118CC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801118D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801118D4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801118D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801118DC: jr          $ra
    // 0x801118E0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x801118E0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mvOpeningYamabukiMakeLegsShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131D84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
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
    // 0x80131DA0: lw          $t6, 0x2658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2658);
    // 0x80131DA4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131DA8: addiu       $t7, $t7, -0x4D50
    ctx->r15 = ADD32(ctx->r15, -0X4D50);
    // 0x80131DAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131DB8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80131DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80131DC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131DC4: jal         0x8000F590
    // 0x80131DC8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80131DC8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131DCC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131DD0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131DD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131DD8: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DE0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131DE4: jal         0x80009DF4
    // 0x80131DE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131DE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131DEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131DF0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131DF4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131DF8: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80131DFC: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131E00: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131E04: addiu       $t3, $t3, -0x4C70
    ctx->r11 = ADD32(ctx->r11, -0X4C70);
    // 0x80131E08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131E0C: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131E10: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E18: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131E1C: lw          $t2, 0x2658($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2658);
    // 0x80131E20: jal         0x8000BD8C
    // 0x80131E24: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131E24: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80131E28: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E2C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E38: jal         0x80008188
    // 0x80131E3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80131E3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80131E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131E44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E4C: jr          $ra
    // 0x80131E50: nop

    return;
    // 0x80131E50: nop

;}
RECOMP_FUNC void ftCommonCliffClimbSlow1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80145248: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014524C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80145250: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80145254: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145258: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014525C: jal         0x800E6F24
    // 0x80145260: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145260: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80145264: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80145268: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8014526C: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x80145270: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x80145274: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x80145278: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8014527C: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x80145280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145288: jr          $ra
    // 0x8014528C: nop

    return;
    // 0x8014528C: nop

;}
RECOMP_FUNC void ftComputerCheckSetTargetEdgeRight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134000: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80134004: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80134008: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8013400C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80134010: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80134014: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80134018: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8013401C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80134020: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80134024: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80134028: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8013402C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80134030: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80134034: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80134038: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013403C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80134040: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80134044: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80134048: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8013404C: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80134050: c.le.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl <= ctx->f4.fl;
    // 0x80134054: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80134058: addiu       $s4, $s2, 0x1CC
    ctx->r20 = ADD32(ctx->r18, 0X1CC);
    // 0x8013405C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80134060: bc1f        L_80134098
    if (!c1cs) {
        // 0x80134064: addiu       $s3, $s3, 0x50E8
        ctx->r19 = ADD32(ctx->r19, 0X50E8);
            goto L_80134098;
    }
    // 0x80134064: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x80134068: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013406C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80134070: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80134074: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80134078: addiu       $s4, $a0, 0x1CC
    ctx->r20 = ADD32(ctx->r4, 0X1CC);
    // 0x8013407C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80134080: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80134084: swc1        $f8, 0x60($s4)
    MEM_W(0X60, ctx->r20) = ctx->f8.u32l;
    // 0x80134088: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013408C: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80134090: b           L_80134324
    // 0x80134094: swc1        $f10, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f10.u32l;
        goto L_80134324;
    // 0x80134094: swc1        $f10, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f10.u32l;
L_80134098:
    // 0x80134098: lwc1        $f16, 0x90($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X90);
    // 0x8013409C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801340A0: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x801340A4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801340A8: mul.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801340AC: bne         $t8, $at, L_801340BC
    if (ctx->r24 != ctx->r1) {
        // 0x801340B0: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_801340BC;
    }
    // 0x801340B0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801340B4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801340B8: nop

L_801340BC:
    // 0x801340BC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801340C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801340C4: addiu       $s5, $s5, 0x1348
    ctx->r21 = ADD32(ctx->r21, 0X1348);
    // 0x801340C8: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x801340CC: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x801340D0: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x801340D4: bnel        $t0, $at, L_801340E8
    if (ctx->r8 != ctx->r1) {
        // 0x801340D8: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_801340E8;
    }
    goto skip_0;
    // 0x801340D8: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_0:
    // 0x801340DC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801340E0: nop

    // 0x801340E4: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
L_801340E8:
    // 0x801340E8: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x801340EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801340F0: blez        $t1, L_80134320
    if (SIGNED(ctx->r9) <= 0) {
        // 0x801340F4: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80134320;
    }
    // 0x801340F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801340F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801340FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80134100: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80134104: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80134108: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013410C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80134110:
    // 0x80134110: jal         0x800FC67C
    // 0x80134114: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x80134114: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_0:
    // 0x80134118: beq         $v0, $zero, L_80134308
    if (ctx->r2 == 0) {
        // 0x8013411C: addiu       $a1, $sp, 0x98
        ctx->r5 = ADD32(ctx->r29, 0X98);
            goto L_80134308;
    }
    // 0x8013411C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80134120: jal         0x800F4408
    // 0x80134124: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x80134124: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_1:
    // 0x80134128: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8013412C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80134130: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x80134134: bnel        $s6, $t3, L_80134184
    if (ctx->r22 != ctx->r11) {
        // 0x80134138: lw          $t4, 0x0($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X0);
            goto L_80134184;
    }
    goto skip_1;
    // 0x80134138: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x8013413C: jal         0x8010850C
    // 0x80134140: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    grZebesAcidGetLevelInfo(rdram, ctx);
        goto after_2;
    // 0x80134140: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_2:
    // 0x80134144: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80134148: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8013414C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80134150: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80134154: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80134158: nop

    // 0x8013415C: bc1tl       L_8013430C
    if (c1cs) {
        // 0x80134160: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_2;
    // 0x80134160: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_2:
    // 0x80134164: mul.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x80134168: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8013416C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80134170: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80134174: nop

    // 0x80134178: bc1tl       L_8013430C
    if (c1cs) {
        // 0x8013417C: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_3;
    // 0x8013417C: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_3:
    // 0x80134180: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80134184:
    // 0x80134184: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x80134188: bnel        $s7, $t5, L_801341A4
    if (ctx->r23 != ctx->r13) {
        // 0x8013418C: lw          $a1, 0x8E8($s2)
        ctx->r5 = MEM_W(ctx->r18, 0X8E8);
            goto L_801341A4;
    }
    goto skip_4;
    // 0x8013418C: lw          $a1, 0x8E8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8E8);
    skip_4:
    // 0x80134190: jal         0x800FCA18
    // 0x80134194: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_3;
    // 0x80134194: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_3:
    // 0x80134198: bnel        $v0, $zero, L_8013430C
    if (ctx->r2 != 0) {
        // 0x8013419C: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_5;
    // 0x8013419C: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_5:
    // 0x801341A0: lw          $a1, 0x8E8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8E8);
L_801341A4:
    // 0x801341A4: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801341A8: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801341AC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801341B0: c.lt.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl < ctx->f12.fl;
    // 0x801341B4: nop

    // 0x801341B8: bc1fl       L_8013430C
    if (!c1cs) {
        // 0x801341BC: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_6;
    // 0x801341BC: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_6:
    // 0x801341C0: lw          $v1, 0x9C8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X9C8);
    // 0x801341C4: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x801341C8: lwc1        $f14, 0x5C($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801341CC: lwc1        $f10, 0x50($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X50);
    // 0x801341D0: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801341D4: neg.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = -ctx->f14.fl;
    // 0x801341D8: div.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801341DC: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x801341E0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801341E4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801341E8: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801341EC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801341F0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801341F4: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801341F8: nop

    // 0x801341FC: bgtz        $a0, L_8013421C
    if (SIGNED(ctx->r4) > 0) {
        // 0x80134200: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8013421C;
    }
    // 0x80134200: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80134204: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80134208: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8013420C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80134210: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80134214: b           L_801342A4
    // 0x80134218: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
        goto L_801342A4;
    // 0x80134218: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
L_8013421C:
    // 0x8013421C: beq         $at, $zero, L_80134260
    if (ctx->r1 == 0) {
        // 0x80134220: nop
    
            goto L_80134260;
    }
    // 0x80134220: nop

    // 0x80134224: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134228: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8013422C: nop

    // 0x80134230: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80134234: mflo        $t8
    ctx->r24 = lo;
    // 0x80134238: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8013423C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80134240: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80134244: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80134248: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8013424C: nop

    // 0x80134250: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80134254: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80134258: b           L_801342A4
    // 0x8013425C: add.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f16.fl;
        goto L_801342A4;
    // 0x8013425C: add.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f16.fl;
L_80134260:
    // 0x80134260: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134264: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80134268: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x8013426C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134270: mflo        $t9
    ctx->r25 = lo;
    // 0x80134274: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80134278: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8013427C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80134280: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80134284: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80134288: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013428C: mul.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80134290: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80134294: mul.s       $f16, $f14, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80134298: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8013429C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801342A0: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
L_801342A4:
    // 0x801342A4: bne         $fp, $zero, L_801342C4
    if (ctx->r30 != 0) {
        // 0x801342A8: lwc1        $f10, 0x9C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_801342C4;
    }
    // 0x801342A8: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801342AC: lwc1        $f6, 0x90($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X90);
    // 0x801342B0: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801342B4: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x801342B8: nop

    // 0x801342BC: bc1tl       L_8013430C
    if (c1cs) {
        // 0x801342C0: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_7;
    // 0x801342C0: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_7:
L_801342C4:
    // 0x801342C4: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801342C8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x801342CC: nop

    // 0x801342D0: bc1fl       L_801342F0
    if (!c1cs) {
        // 0x801342D4: lwc1        $f18, 0x98($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
            goto L_801342F0;
    }
    goto skip_8;
    // 0x801342D4: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    skip_8:
    // 0x801342D8: sub.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x801342DC: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x801342E0: nop

    // 0x801342E4: bc1tl       L_8013430C
    if (c1cs) {
        // 0x801342E8: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_8013430C;
    }
    goto skip_9;
    // 0x801342E8: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_9:
    // 0x801342EC: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
L_801342F0:
    // 0x801342F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801342F4: sub.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x801342F8: swc1        $f10, 0x60($s4)
    MEM_W(0X60, ctx->r20) = ctx->f10.u32l;
    // 0x801342FC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80134300: b           L_80134324
    // 0x80134304: swc1        $f6, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f6.u32l;
        goto L_80134324;
    // 0x80134304: swc1        $f6, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f6.u32l;
L_80134308:
    // 0x80134308: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
L_8013430C:
    // 0x8013430C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80134310: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80134314: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80134318: bne         $at, $zero, L_80134110
    if (ctx->r1 != 0) {
        // 0x8013431C: nop
    
            goto L_80134110;
    }
    // 0x8013431C: nop

L_80134320:
    // 0x80134320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134324:
    // 0x80134324: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80134328: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013432C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80134330: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80134334: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80134338: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8013433C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80134340: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80134344: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80134348: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8013434C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80134350: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80134354: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80134358: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8013435C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80134360: jr          $ra
    // 0x80134364: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80134364: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ftCommonThrownCommonStarProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C280: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014C284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C288: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8014C28C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014C290: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8014C294: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8014C298: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8014C29C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8014C2A0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8014C2A4: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8014C2A8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8014C2AC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8014C2B0: jal         0x800DE6B0
    // 0x8014C2B4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8014C2B4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014C2B8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8014C2BC: beq         $v0, $zero, L_8014C2CC
    if (ctx->r2 == 0) {
        // 0x8014C2C0: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_8014C2CC;
    }
    // 0x8014C2C0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8014C2C4: b           L_8014C34C
    // 0x8014C2C8: addiu       $a1, $v1, 0xF8
    ctx->r5 = ADD32(ctx->r3, 0XF8);
        goto L_8014C34C;
    // 0x8014C2C8: addiu       $a1, $v1, 0xF8
    ctx->r5 = ADD32(ctx->r3, 0XF8);
L_8014C2CC:
    // 0x8014C2CC: lhu         $v0, 0xCE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XCE);
    // 0x8014C2D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014C2D4: andi        $t0, $v0, 0x400
    ctx->r8 = ctx->r2 & 0X400;
    // 0x8014C2D8: beq         $t0, $zero, L_8014C2F4
    if (ctx->r8 == 0) {
        // 0x8014C2DC: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_8014C2F4;
    }
    // 0x8014C2DC: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8014C2E0: lwc1        $f6, 0xB0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x8014C2E4: addiu       $a1, $v1, 0x10C
    ctx->r5 = ADD32(ctx->r3, 0X10C);
    // 0x8014C2E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014C2EC: b           L_8014C34C
    // 0x8014C2F0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
        goto L_8014C34C;
    // 0x8014C2F0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_8014C2F4:
    // 0x8014C2F4: beq         $t1, $zero, L_8014C324
    if (ctx->r9 == 0) {
        // 0x8014C2F8: andi        $t2, $v0, 0x20
        ctx->r10 = ctx->r2 & 0X20;
            goto L_8014C324;
    }
    // 0x8014C2F8: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x8014C2FC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8014C300: lwc1        $f16, 0xBC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x8014C304: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014C308: addiu       $a1, $v1, 0x120
    ctx->r5 = ADD32(ctx->r3, 0X120);
    // 0x8014C30C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8014C310: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8014C314: lwc1        $f6, 0xB4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8014C318: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014C31C: b           L_8014C34C
    // 0x8014C320: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
        goto L_8014C34C;
    // 0x8014C320: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_8014C324:
    // 0x8014C324: beq         $t2, $zero, L_8014C34C
    if (ctx->r10 == 0) {
        // 0x8014C328: lwc1        $f10, 0x2C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8014C34C;
    }
    // 0x8014C328: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8014C32C: lwc1        $f16, 0xBC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x8014C330: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014C334: addiu       $a1, $v1, 0x134
    ctx->r5 = ADD32(ctx->r3, 0X134);
    // 0x8014C338: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8014C33C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8014C340: lwc1        $f6, 0xB4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8014C344: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014C348: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_8014C34C:
    // 0x8014C34C: beq         $a1, $zero, L_8014C414
    if (ctx->r5 == 0) {
        // 0x8014C350: addiu       $a0, $v1, 0x48
        ctx->r4 = ADD32(ctx->r3, 0X48);
            goto L_8014C414;
    }
    // 0x8014C350: addiu       $a0, $v1, 0x48
    ctx->r4 = ADD32(ctx->r3, 0X48);
    // 0x8014C354: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8014C358: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x8014C35C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8014C360: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x8014C364: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8014C368: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8014C36C: sw          $t5, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r13;
    // 0x8014C370: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8014C374: jal         0x800C7B08
    // 0x8014C378: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    lbCommonReflect2D(rdram, ctx);
        goto after_1;
    // 0x8014C378: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014C37C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8014C380: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014C384: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8014C388: lwc1        $f10, 0x48($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8014C38C: lwc1        $f6, 0x4C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8014C390: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8014C394: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014C398: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014C39C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8014C3A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8014C3A4: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8014C3A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8014C3AC: nop

    // 0x8014C3B0: bc1f        L_8014C3E8
    if (!c1cs) {
        // 0x8014C3B4: nop
    
            goto L_8014C3E8;
    }
    // 0x8014C3B4: nop

    // 0x8014C3B8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8014C3BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014C3C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014C3C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8014C3C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014C3CC: nop

    // 0x8014C3D0: bc1fl       L_8014C3E4
    if (!c1cs) {
        // 0x8014C3D4: sh          $t7, 0xB1A($v1)
        MEM_H(0XB1A, ctx->r3) = ctx->r15;
            goto L_8014C3E4;
    }
    goto skip_0;
    // 0x8014C3D4: sh          $t7, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r15;
    skip_0:
    // 0x8014C3D8: b           L_8014C3E4
    // 0x8014C3DC: sh          $t6, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r14;
        goto L_8014C3E4;
    // 0x8014C3DC: sh          $t6, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r14;
    // 0x8014C3E0: sh          $t7, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r15;
L_8014C3E4:
    // 0x8014C3E4: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
L_8014C3E8:
    // 0x8014C3E8: jal         0x801008F4
    // 0x8014C3EC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8014C3EC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x8014C3F0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8014C3F4: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8014C3F8: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8014C3FC: jal         0x8001863C
    // 0x8014C400: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8014C400: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x8014C404: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014C408: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8014C40C: jal         0x800FFD58
    // 0x8014C410: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    efManagerImpactWaveMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8014C410: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
L_8014C414:
    // 0x8014C414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C418: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014C41C: jr          $ra
    // 0x8014C420: nop

    return;
    // 0x8014C420: nop

;}
RECOMP_FUNC void syInterpQuad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E574: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001E578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E57C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001E580: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E584: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001E588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E58C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001E590: jal         0x8001E344
    // 0x8001E594: nop

    syInterpGetFracFrame(rdram, ctx);
        goto after_0;
    // 0x8001E594: nop

    after_0:
    // 0x8001E598: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001E59C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001E5A0: jal         0x8001E020
    // 0x8001E5A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    syInterpQuadSplineTimeFrac(rdram, ctx);
        goto after_1;
    // 0x8001E5A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8001E5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E5AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E5B0: jr          $ra
    // 0x8001E5B4: nop

    return;
    // 0x8001E5B4: nop

;}
RECOMP_FUNC void func_ovl24_80131ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131ECC: jr          $ra
    // 0x80131ED0: nop

    return;
    // 0x80131ED0: nop

;}
RECOMP_FUNC void n_alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE88: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002CE8C: addiu       $v0, $v0, -0x2CF0
    ctx->r2 = ADD32(ctx->r2, -0X2CF0);
    // 0x8002CE90: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002CE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CE9C: bne         $t6, $zero, L_8002CEC4
    if (ctx->r14 != 0) {
        // 0x8002CEA0: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_8002CEC4;
    }
    // 0x8002CEA0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8002CEA4: addiu       $v1, $v1, -0x2CEC
    ctx->r3 = ADD32(ctx->r3, -0X2CEC);
    // 0x8002CEA8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002CEAC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8002CEB0: bnel        $t7, $zero, L_8002CEC8
    if (ctx->r15 != 0) {
        // 0x8002CEB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002CEC8;
    }
    goto skip_0;
    // 0x8002CEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002CEB8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002CEBC: jal         0x8002CB48
    // 0x8002CEC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    n_alSynNew(rdram, ctx);
        goto after_0;
    // 0x8002CEC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_8002CEC4:
    // 0x8002CEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002CEC8:
    // 0x8002CEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CECC: jr          $ra
    // 0x8002CED0: nop

    return;
    // 0x8002CED0: nop

;}
RECOMP_FUNC void grInishiePakkunSetWaitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010972C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80109734: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80109738: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010973C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80109740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109744: addiu       $s1, $s1, 0x13F8
    ctx->r17 = ADD32(ctx->r17, 0X13F8);
    // 0x80109748: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
L_8010974C:
    // 0x8010974C: jal         0x8017CFC0
    // 0x80109750: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    itPakkunCommonSetWaitFighter(rdram, ctx);
        goto after_0;
    // 0x80109750: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_0:
    // 0x80109754: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80109758: bne         $s0, $s1, L_8010974C
    if (ctx->r16 != ctx->r17) {
        // 0x8010975C: nop
    
            goto L_8010974C;
    }
    // 0x8010975C: nop

    // 0x80109760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80109764: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80109768: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010976C: jr          $ra
    // 0x80109770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80109770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PTrainingSelectFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013484C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80134850: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x80134854: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134858: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013485C: addiu       $v0, $v0, -0x7AA8
    ctx->r2 = ADD32(ctx->r2, -0X7AA8);
    // 0x80134860: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80134864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134868: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8013486C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134870: mflo        $t6
    ctx->r14 = lo;
    // 0x80134874: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80134878: lw          $t7, 0x50($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X50);
    // 0x8013487C: beql        $t7, $at, L_80134890
    if (ctx->r15 == ctx->r1) {
        // 0x80134880: lw          $t8, 0x7C($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X7C);
            goto L_80134890;
    }
    goto skip_0;
    // 0x80134880: lw          $t8, 0x7C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X7C);
    skip_0:
    // 0x80134884: b           L_801348E0
    // 0x80134888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801348E0;
    // 0x80134888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013488C: lw          $t8, 0x7C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X7C);
L_80134890:
    // 0x80134890: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80134894: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80134898: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013489C: mflo        $t9
    ctx->r25 = lo;
    // 0x801348A0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x801348A4: lw          $t1, 0x48($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X48);
    // 0x801348A8: beq         $t1, $at, L_801348D4
    if (ctx->r9 == ctx->r1) {
        // 0x801348AC: nop
    
            goto L_801348D4;
    }
    // 0x801348AC: nop

    // 0x801348B0: jal         0x80131B58
    // 0x801348B4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    mnPlayers1PTrainingSelectFighterPuck(rdram, ctx);
        goto after_0;
    // 0x801348B4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x801348B8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801348BC: lw          $t2, -0x7774($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7774);
    // 0x801348C0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801348C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801348C8: addiu       $t3, $t2, 0x1E
    ctx->r11 = ADD32(ctx->r10, 0X1E);
    // 0x801348CC: b           L_801348E0
    // 0x801348D0: sw          $t3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r11;
        goto L_801348E0;
    // 0x801348D0: sw          $t3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r11;
L_801348D4:
    // 0x801348D4: jal         0x800269C0
    // 0x801348D8: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x801348D8: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_1:
    // 0x801348DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801348E0:
    // 0x801348E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801348E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801348E8: jr          $ra
    // 0x801348EC: nop

    return;
    // 0x801348EC: nop

;}
RECOMP_FUNC void itTaruBombExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018528C: jal         0x801851F4
    // 0x80185290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itTaruBombExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80185290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80185294: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80185298: addiu       $a1, $a1, -0x4A2C
    ctx->r5 = ADD32(ctx->r5, -0X4A2C);
    // 0x8018529C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801852A0: jal         0x80172EC8
    // 0x801852A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801852A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801852A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801852AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801852B0: jr          $ra
    // 0x801852B4: nop

    return;
    // 0x801852B4: nop

;}
RECOMP_FUNC void ftCommonAppearSetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013DDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DDE8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DDEC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013DDF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8013DDF4: lbu         $t6, 0x191($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X191);
    // 0x8013DDF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013DDFC: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x8013DE00: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x8013DE04: sb          $t8, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r24;
    // 0x8013DE08: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8013DE0C: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x8013DE10: sw          $t1, 0x854($v0)
    MEM_W(0X854, ctx->r2) = ctx->r9;
    // 0x8013DE14: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8013DE18: sw          $t0, 0x858($v0)
    MEM_W(0X858, ctx->r2) = ctx->r8;
    // 0x8013DE1C: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x8013DE20: sw          $t1, 0x85C($v0)
    MEM_W(0X85C, ctx->r2) = ctx->r9;
    // 0x8013DE24: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x8013DE28: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x8013DE2C: lh          $t2, 0x6C($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6C);
    // 0x8013DE30: lh          $t3, 0x74($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X74);
    // 0x8013DE34: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8013DE38: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8013DE3C: nop

    // 0x8013DE40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013DE44: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013DE48: jal         0x8013F9E0
    // 0x8013DE4C: swc1        $f10, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f10.u32l;
    ftCommonFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013DE4C: swc1        $f10, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f10.u32l;
    after_0:
    // 0x8013DE50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DE54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DE58: jr          $ra
    // 0x8013DE5C: nop

    return;
    // 0x8013DE5C: nop

;}
RECOMP_FUNC void wpLinkSpinAttackProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C9A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8016C9AC: jr          $ra
    // 0x8016C9B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016C9B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_ovl0_800C9714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C971C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9720: jal         0x800C96DC
    // 0x800C9724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_ovl0_800C96DC(rdram, ctx);
        goto after_0;
    // 0x800C9724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800C9728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C972C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C9734: jr          $ra
    // 0x800C9738: nop

    return;
    // 0x800C9738: nop

;}
RECOMP_FUNC void mnVSModeGetArrowSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132524: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80132528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013252C: beq         $v1, $zero, L_80132568
    if (ctx->r3 == 0) {
        // 0x80132530: nop
    
            goto L_80132568;
    }
    // 0x80132530: nop

    // 0x80132534: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80132538: bnel        $a1, $t6, L_8013254C
    if (ctx->r5 != ctx->r14) {
        // 0x8013253C: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_8013254C;
    }
    goto skip_0;
    // 0x8013253C: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x80132540: jr          $ra
    // 0x80132544: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132544: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132548: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_8013254C:
    // 0x8013254C: beq         $a0, $zero, L_80132568
    if (ctx->r4 == 0) {
        // 0x80132550: nop
    
            goto L_80132568;
    }
    // 0x80132550: nop

    // 0x80132554: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80132558: bne         $a1, $t7, L_80132568
    if (ctx->r5 != ctx->r15) {
        // 0x8013255C: nop
    
            goto L_80132568;
    }
    // 0x8013255C: nop

    // 0x80132560: jr          $ra
    // 0x80132564: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80132564: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80132568:
    // 0x80132568: jr          $ra
    // 0x8013256C: nop

    return;
    // 0x8013256C: nop

;}
RECOMP_FUNC void ftParamGetEffectJointPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EAB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EAB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EAB48: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x800EAB4C: lhu         $t2, 0x18E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X18E);
    // 0x800EAB50: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800EAB54: sll         $t7, $t6, 22
    ctx->r15 = S32(ctx->r14 << 22);
    // 0x800EAB58: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800EAB5C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800EAB60: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800EAB64: andi        $t1, $t0, 0x3C0
    ctx->r9 = ctx->r8 & 0X3C0;
    // 0x800EAB68: andi        $t3, $t2, 0xFC3F
    ctx->r11 = ctx->r10 & 0XFC3F;
    // 0x800EAB6C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800EAB70: sh          $t4, 0x18E($a0)
    MEM_H(0X18E, ctx->r4) = ctx->r12;
    // 0x800EAB74: lw          $t5, 0x18C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X18C);
    // 0x800EAB78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EAB7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800EAB80: sll         $t6, $t5, 22
    ctx->r14 = S32(ctx->r13 << 22);
    // 0x800EAB84: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800EAB88: bne         $t7, $at, L_800EAB98
    if (ctx->r15 != ctx->r1) {
        // 0x800EAB8C: lw          $v0, 0x9C8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X9C8);
            goto L_800EAB98;
    }
    // 0x800EAB8C: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x800EAB90: andi        $t9, $t4, 0xFC3F
    ctx->r25 = ctx->r12 & 0XFC3F;
    // 0x800EAB94: sh          $t9, 0x18E($a0)
    MEM_H(0X18E, ctx->r4) = ctx->r25;
L_800EAB98:
    // 0x800EAB98: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x800EAB9C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800EABA0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800EABA4: lw          $t0, 0x18C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X18C);
    // 0x800EABA8: sll         $t2, $t0, 22
    ctx->r10 = S32(ctx->r8 << 22);
    // 0x800EABAC: srl         $t1, $t2, 28
    ctx->r9 = S32(U32(ctx->r10) >> 28);
    // 0x800EABB0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800EABB4: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x800EABB8: lw          $t5, 0x2A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2A4);
    // 0x800EABBC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800EABC0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800EABC4: jal         0x800EDF24
    // 0x800EABC8: lw          $a0, 0x8E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EABC8: lw          $a0, 0x8E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8E8);
    after_0:
    // 0x800EABCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EABD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EABD4: jr          $ra
    // 0x800EABD8: nop

    return;
    // 0x800EABD8: nop

;}
RECOMP_FUNC void func_ovl8_803768E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803768E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803768E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803768E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803768EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803768F0: beq         $a0, $zero, L_80376998
    if (ctx->r4 == 0) {
        // 0x803768F4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80376998;
    }
    // 0x803768F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803768F8: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x803768FC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80376900: addiu       $t6, $t6, -0x6370
    ctx->r14 = ADD32(ctx->r14, -0X6370);
    // 0x80376904: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80376908: addiu       $t7, $t7, -0x62B8
    ctx->r15 = ADD32(ctx->r15, -0X62B8);
    // 0x8037690C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80376910: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80376914: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80376918: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037691C: addiu       $t9, $t9, -0x6160
    ctx->r25 = ADD32(ctx->r25, -0X6160);
    // 0x80376920: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80376924: addiu       $t1, $t1, -0x6138
    ctx->r9 = ADD32(ctx->r9, -0X6138);
    // 0x80376928: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037692C: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x80376930: lw          $a0, 0xA8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA8);
    // 0x80376934: beql        $a0, $zero, L_80376948
    if (ctx->r4 == 0) {
        // 0x80376938: addiu       $a0, $s0, 0x38
        ctx->r4 = ADD32(ctx->r16, 0X38);
            goto L_80376948;
    }
    goto skip_0;
    // 0x80376938: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    skip_0:
    // 0x8037693C: jal         0x8037B3E4
    // 0x80376940: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x80376940: nop

    after_0:
    // 0x80376944: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
L_80376948:
    // 0x80376948: jal         0x803720D4
    // 0x8037694C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803720D4(rdram, ctx);
        goto after_1;
    // 0x8037694C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80376950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376954: jal         0x8037295C
    // 0x80376958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037295C(rdram, ctx);
        goto after_2;
    // 0x80376958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8037695C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80376960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80376964: beql        $t2, $zero, L_80376984
    if (ctx->r10 == 0) {
        // 0x80376968: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80376984;
    }
    goto skip_1;
    // 0x80376968: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8037696C: jal         0x8037C30C
    // 0x80376970: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x80376970: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x80376974: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80376978: jal         0x803718C4
    // 0x8037697C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x8037697C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80376980: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80376984:
    // 0x80376984: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80376988: beql        $t4, $zero, L_8037699C
    if (ctx->r12 == 0) {
        // 0x8037698C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037699C;
    }
    goto skip_2;
    // 0x8037698C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80376990: jal         0x803717C0
    // 0x80376994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x80376994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80376998:
    // 0x80376998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037699C:
    // 0x8037699C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803769A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803769A4: jr          $ra
    // 0x803769A8: nop

    return;
    // 0x803769A8: nop

;}
RECOMP_FUNC void mn1PModeMakeOptionsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132730: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132734: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132738: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013273C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132740: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132744: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132748: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8013274C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132750: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132754: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132758: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013275C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132760: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132764: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132768: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013276C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132770: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132774: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132778: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013277C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132788: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013278C: jal         0x8000B93C
    // 0x80132790: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132790: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132794: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132798: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013279C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801327A0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801327A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801327A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801327AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801327B0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801327B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801327B8: jal         0x80007080
    // 0x801327BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801327BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801327C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801327C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801327C8: jr          $ra
    // 0x801327CC: nop

    return;
    // 0x801327CC: nop

;}
RECOMP_FUNC void ftCommonThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014AAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AAF8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8014AAFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014AB00: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8014AB04: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8014AB08: nop

    // 0x8014AB0C: bc1fl       L_8014AB58
    if (!c1cs) {
        // 0x8014AB10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014AB58;
    }
    goto skip_0;
    // 0x8014AB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014AB14: lw          $t6, 0x844($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X844);
    // 0x8014AB18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014AB1C: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x8014AB20: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014AB24: beq         $v0, $at, L_8014AB3C
    if (ctx->r2 == ctx->r1) {
        // 0x8014AB28: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8014AB3C;
    }
    // 0x8014AB28: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8014AB2C: beq         $v0, $at, L_8014AB3C
    if (ctx->r2 == ctx->r1) {
        // 0x8014AB30: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8014AB3C;
    }
    // 0x8014AB30: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8014AB34: bne         $v0, $at, L_8014AB4C
    if (ctx->r2 != ctx->r1) {
        // 0x8014AB38: nop
    
            goto L_8014AB4C;
    }
    // 0x8014AB38: nop

L_8014AB3C:
    // 0x8014AB3C: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8014AB40: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x8014AB44: beql        $t7, $at, L_8014AB58
    if (ctx->r15 == ctx->r1) {
        // 0x8014AB48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014AB58;
    }
    goto skip_1;
    // 0x8014AB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8014AB4C:
    // 0x8014AB4C: jal         0x8014ACB4
    // 0x8014AB50: lw          $a1, 0xB18($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XB18);
    ftCommonThrownSetStatusImmediate(rdram, ctx);
        goto after_0;
    // 0x8014AB50: lw          $a1, 0xB18($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XB18);
    after_0:
    // 0x8014AB54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014AB58:
    // 0x8014AB58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014AB5C: jr          $ra
    // 0x8014AB60: nop

    return;
    // 0x8014AB60: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateViewOptionSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F424: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F428: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F42C: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x8018F430: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8018F434: lw          $t6, 0x64($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X64);
    // 0x8018F438: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F43C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F440: lw          $t1, 0x68($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X68);
    // 0x8018F444: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018F448: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
    // 0x8018F44C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8018F450:
    // 0x8018F450: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F454: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018F458: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018F45C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018F460: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018F464: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018F468: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018F46C: bne         $t1, $t5, L_8018F450
    if (ctx->r9 != ctx->r13) {
        // 0x8018F470: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018F450;
    }
    // 0x8018F470: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018F474: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F478: addiu       $t7, $zero, 0xBF
    ctx->r15 = ADD32(0, 0XBF);
    // 0x8018F47C: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018F480: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018F484: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018F488: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8018F48C: bgez        $t6, L_8018F49C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018F490: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8018F49C;
    }
    // 0x8018F490: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8018F494: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8018F498: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8018F49C:
    // 0x8018F49C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8018F4A0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018F4A4: nop

    // 0x8018F4A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F4AC: jr          $ra
    // 0x8018F4B0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8018F4B0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void wpNessPKReflectHeadMakeTrail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B65C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016B660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B664: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8016B668: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016B66C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016B670: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8016B674: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8016B678: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8016B67C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8016B680: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8016B684: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8016B688: jal         0x8016BB6C
    // 0x8016B68C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    wpNessPKReflectTrailMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016B68C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8016B690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B694: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016B698: jr          $ra
    // 0x8016B69C: nop

    return;
    // 0x8016B69C: nop

;}
RECOMP_FUNC void scAutoDemoFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0C8: jal         0x8000A5E4
    // 0x8018D0CC: nop

    gcRunAll(rdram, ctx);
        goto after_0;
    // 0x8018D0CC: nop

    after_0:
    // 0x8018D0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D0D8: jr          $ra
    // 0x8018D0DC: nop

    return;
    // 0x8018D0DC: nop

;}
RECOMP_FUNC void ftCommonHammerWalkCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147A34: jal         0x8013E614
    // 0x80147A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWalkCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80147A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80147A3C: beql        $v0, $zero, L_80147A58
    if (ctx->r2 == 0) {
        // 0x80147A40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80147A58;
    }
    goto skip_0;
    // 0x80147A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80147A44: jal         0x801479E0
    // 0x80147A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerWalkSetStatus(rdram, ctx);
        goto after_1;
    // 0x80147A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80147A4C: b           L_80147A58
    // 0x80147A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147A58;
    // 0x80147A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80147A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147A58:
    // 0x80147A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147A5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147A60: jr          $ra
    // 0x80147A64: nop

    return;
    // 0x80147A64: nop

;}
RECOMP_FUNC void syTaskmanSetRdpOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004CB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004CB8: sw          $a0, -0x4920($at)
    MEM_W(-0X4920, ctx->r1) = ctx->r4;
    // 0x80004CBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004CC0: sw          $a1, 0x6618($at)
    MEM_W(0X6618, ctx->r1) = ctx->r5;
    // 0x80004CC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004CC8: sw          $a2, 0x661C($at)
    MEM_W(0X661C, ctx->r1) = ctx->r6;
    // 0x80004CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80004CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004CD8: beq         $a0, $at, L_80004CEC
    if (ctx->r4 == ctx->r1) {
        // 0x80004CDC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80004CEC;
    }
    // 0x80004CDC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80004CE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80004CE4: bnel        $a0, $at, L_80004D0C
    if (ctx->r4 != ctx->r1) {
        // 0x80004CE8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80004D0C;
    }
    goto skip_0;
    // 0x80004CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
L_80004CEC:
    // 0x80004CEC: bnel        $a2, $zero, L_80004D0C
    if (ctx->r6 != 0) {
        // 0x80004CF0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80004D0C;
    }
    goto skip_1;
    // 0x80004CF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x80004CF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004CF8: jal         0x80023624
    // 0x80004CFC: addiu       $a0, $a0, -0x2888
    ctx->r4 = ADD32(ctx->r4, -0X2888);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80004CFC: addiu       $a0, $a0, -0x2888
    ctx->r4 = ADD32(ctx->r4, -0X2888);
    after_0:
L_80004D00:
    // 0x80004D00: b           L_80004D00
    pause_self(rdram);
    // 0x80004D04: nop

    // 0x80004D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80004D0C:
    // 0x80004D0C: bne         $a0, $at, L_80004D1C
    if (ctx->r4 != ctx->r1) {
        // 0x80004D10: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80004D1C;
    }
    // 0x80004D10: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80004D14: jal         0x80004C5C
    // 0x80004D18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    syTaskmanMakeRdpBufferTask(rdram, ctx);
        goto after_1;
    // 0x80004D18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_80004D1C:
    // 0x80004D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004D24: jr          $ra
    // 0x80004D28: nop

    return;
    // 0x80004D28: nop

;}
RECOMP_FUNC void func_ovl8_8037CCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CCC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037CCCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037CCD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037CCD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037CCD8: beq         $a0, $zero, L_8037CD50
    if (ctx->r4 == 0) {
        // 0x8037CCDC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037CD50;
    }
    // 0x8037CCDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037CCE0: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037CCE4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037CCE8: addiu       $t6, $t6, -0x5B60
    ctx->r14 = ADD32(ctx->r14, -0X5B60);
    // 0x8037CCEC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037CCF0: addiu       $t7, $t7, -0x5A88
    ctx->r15 = ADD32(ctx->r15, -0X5A88);
    // 0x8037CCF4: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037CCF8: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037CCFC: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037CD00: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037CD04: addiu       $t9, $t9, -0x5930
    ctx->r25 = ADD32(ctx->r25, -0X5930);
    // 0x8037CD08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CD0C: jal         0x80373D88
    // 0x8037CD10: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80373D88(rdram, ctx);
        goto after_0;
    // 0x8037CD10: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x8037CD14: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8037CD18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CD1C: beql        $t1, $zero, L_8037CD3C
    if (ctx->r9 == 0) {
        // 0x8037CD20: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8037CD3C;
    }
    goto skip_0;
    // 0x8037CD20: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037CD24: jal         0x8037C30C
    // 0x8037CD28: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x8037CD28: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x8037CD2C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037CD30: jal         0x803718C4
    // 0x8037CD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x8037CD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8037CD38: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8037CD3C:
    // 0x8037CD3C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8037CD40: beql        $t3, $zero, L_8037CD54
    if (ctx->r11 == 0) {
        // 0x8037CD44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037CD54;
    }
    goto skip_1;
    // 0x8037CD44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037CD48: jal         0x803717C0
    // 0x8037CD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x8037CD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8037CD50:
    // 0x8037CD50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037CD54:
    // 0x8037CD54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037CD58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037CD5C: jr          $ra
    // 0x8037CD60: nop

    return;
    // 0x8037CD60: nop

;}
RECOMP_FUNC void mnModeSelectMake1PMode(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80131B34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131B38: jal         0x80009968
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131B44: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131B48: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131B4C: sw          $v0, 0x2C8C($at)
    MEM_W(0X2C8C, ctx->r1) = ctx->r2;
    // 0x80131B50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131B54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131B58: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131B64: jal         0x80009DF4
    // 0x80131B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131B6C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B70: lw          $t7, 0x2C88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C88);
    // 0x80131B74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131B78: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131B7C: bne         $t7, $zero, L_80131BE8
    if (ctx->r15 != 0) {
        // 0x80131B80: lui         $t5, 0x0
        ctx->r13 = S32(0X0 << 16);
            goto L_80131BE8;
    }
    // 0x80131B80: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131B84: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B88: lw          $t8, 0x2D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D6C);
    // 0x80131B8C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131B90: addiu       $t9, $t9, 0x1990
    ctx->r25 = ADD32(ctx->r25, 0X1990);
    // 0x80131B94: jal         0x800CCFDC
    // 0x80131B98: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131B98: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131B9C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80131BA0: lui         $at, 0x4329
    ctx->r1 = S32(0X4329 << 16);
    // 0x80131BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131BA8: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80131BAC: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80131BB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131BB4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131BB8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131BBC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80131BC0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131BC4: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131BC8: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131BCC: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131BD0: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131BD4: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131BD8: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131BDC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131BE0: b           L_80131C34
    // 0x80131BE4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80131C34;
    // 0x80131BE4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80131BE8:
    // 0x80131BE8: lw          $t4, 0x2D6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D6C);
    // 0x80131BEC: addiu       $t5, $t5, 0x6048
    ctx->r13 = ADD32(ctx->r13, 0X6048);
    // 0x80131BF0: jal         0x800CCFDC
    // 0x80131BF4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131BF4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80131BF8: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131BFC: lui         $at, 0x4329
    ctx->r1 = S32(0X4329 << 16);
    // 0x80131C00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131C04: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80131C08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131C0C: addiu       $v1, $zero, 0x96
    ctx->r3 = ADD32(0, 0X96);
    // 0x80131C10: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131C14: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131C18: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131C1C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131C20: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131C24: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131C28: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131C2C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131C30: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80131C34:
    // 0x80131C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C3C: jr          $ra
    // 0x80131C40: nop

    return;
    // 0x80131C40: nop

;}
RECOMP_FUNC void syDebugWaitMsec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002272C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022738: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002273C: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80022740: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80022744: jal         0x80030B18
    // 0x80022748: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80022748: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    after_0:
    // 0x8002274C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80022750: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80022754: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80022758: jal         0x80030B18
    // 0x8002275C: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x8002275C: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_1:
    // 0x80022760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80022764: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80022768: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002276C: jal         0x80030A18
    // 0x80022770: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x80022770: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_2:
    // 0x80022774: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80022778: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8002277C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80022780: jal         0x80035E40
    // 0x80022784: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x80022784: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80022788: jal         0x80034D50
    // 0x8002278C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x8002278C: nop

    after_4:
    // 0x80022790: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80022794: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80022798: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x8002279C: bne         $at, $zero, L_800227E4
    if (ctx->r1 != 0) {
        // 0x800227A0: sltu        $at, $v0, $t8
        ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
            goto L_800227E4;
    }
    // 0x800227A0: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800227A4: bne         $at, $zero, L_800227B4
    if (ctx->r1 != 0) {
        // 0x800227A8: sltu        $at, $v1, $t9
        ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
            goto L_800227B4;
    }
    // 0x800227A8: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x800227AC: beql        $at, $zero, L_800227E8
    if (ctx->r1 == 0) {
        // 0x800227B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800227E8;
    }
    goto skip_0;
    // 0x800227B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800227B4:
    // 0x800227B4: jal         0x80034D50
    // 0x800227B8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x800227B8: nop

    after_5:
    // 0x800227BC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800227C0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800227C4: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x800227C8: bne         $at, $zero, L_800227B4
    if (ctx->r1 != 0) {
        // 0x800227CC: nop
    
            goto L_800227B4;
    }
    // 0x800227CC: nop

    // 0x800227D0: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800227D4: bne         $at, $zero, L_800227E4
    if (ctx->r1 != 0) {
        // 0x800227D8: sltu        $at, $v1, $t1
        ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
            goto L_800227E4;
    }
    // 0x800227D8: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x800227DC: bne         $at, $zero, L_800227B4
    if (ctx->r1 != 0) {
        // 0x800227E0: nop
    
            goto L_800227B4;
    }
    // 0x800227E0: nop

L_800227E4:
    // 0x800227E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800227E8:
    // 0x800227E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800227EC: jr          $ra
    // 0x800227F0: nop

    return;
    // 0x800227F0: nop

;}
RECOMP_FUNC void ftNessSpecialHiDecThunderTimers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153C50: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    // 0x80153C54: beq         $v0, $zero, L_80153C60
    if (ctx->r2 == 0) {
        // 0x80153C58: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80153C60;
    }
    // 0x80153C58: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80153C5C: sw          $t6, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r14;
L_80153C60:
    // 0x80153C60: lw          $t7, 0xADC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XADC);
    // 0x80153C64: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80153C68: beq         $t8, $zero, L_80153C80
    if (ctx->r24 == 0) {
        // 0x80153C6C: nop
    
            goto L_80153C80;
    }
    // 0x80153C6C: nop

    // 0x80153C70: lw          $v0, 0xB1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB1C);
    // 0x80153C74: beq         $v0, $zero, L_80153C80
    if (ctx->r2 == 0) {
        // 0x80153C78: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80153C80;
    }
    // 0x80153C78: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80153C7C: sw          $t9, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = ctx->r25;
L_80153C80:
    // 0x80153C80: jr          $ra
    // 0x80153C84: nop

    return;
    // 0x80153C84: nop

;}
RECOMP_FUNC void mnPlayersVSMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134A8C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80134A90: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80134A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134A98: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80134A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80134AA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134AA4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80134AA8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80134AAC: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x80134AB0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80134AB4:
    // 0x80134AB4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134AB8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80134ABC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80134AC0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80134AC4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80134AC8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80134ACC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80134AD0: bne         $t7, $t1, L_80134AB4
    if (ctx->r15 != ctx->r9) {
        // 0x80134AD4: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80134AB4;
    }
    // 0x80134AD4: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80134AD8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134ADC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80134AE0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134AE4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80134AE8: beql        $t2, $at, L_80134C54
    if (ctx->r10 == ctx->r1) {
        // 0x80134AEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134C54;
    }
    goto skip_0;
    // 0x80134AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80134AF0: beql        $s0, $zero, L_80134B1C
    if (ctx->r16 == 0) {
        // 0x80134AF4: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80134B1C;
    }
    goto skip_1;
    // 0x80134AF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x80134AF8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80134AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134B00: lwc1        $f4, 0x34($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X34);
    // 0x80134B04: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80134B08: jal         0x800D78E8
    // 0x80134B0C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    ftManagerDestroyFighter(rdram, ctx);
        goto after_0;
    // 0x80134B0C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80134B10: b           L_80134B24
    // 0x80134B14: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
        goto L_80134B24;
    // 0x80134B14: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80134B18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80134B1C:
    // 0x80134B1C: nop

    // 0x80134B20: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_80134B24:
    // 0x80134B24: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80134B28: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134B2C: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80134B30: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80134B34: subu        $t1, $t1, $t5
    ctx->r9 = SUB32(ctx->r9, ctx->r13);
    // 0x80134B38: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80134B3C: subu        $t1, $t1, $t5
    ctx->r9 = SUB32(ctx->r9, ctx->r13);
    // 0x80134B40: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80134B44: addu        $t0, $t1, $t7
    ctx->r8 = ADD32(ctx->r9, ctx->r15);
    // 0x80134B48: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80134B4C: lw          $t8, 0x50($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X50);
    // 0x80134B50: lw          $t9, 0x34($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X34);
    // 0x80134B54: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80134B58: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80134B5C: sw          $t6, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->r14;
    // 0x80134B60: sb          $a3, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r7;
    // 0x80134B64: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134B68: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80134B6C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80134B70: sb          $t8, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r24;
    // 0x80134B74: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x80134B78: jal         0x800D7F3C
    // 0x80134B7C: sb          $t2, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r10;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80134B7C: sb          $t2, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r10;
    after_1:
    // 0x80134B80: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80134B84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80134B8C: addiu       $a1, $a1, 0x494C
    ctx->r5 = ADD32(ctx->r5, 0X494C);
    // 0x80134B90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80134B98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80134B9C: jal         0x80008188
    // 0x80134BA0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80134BA0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    after_2:
    // 0x80134BA4: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80134BA8: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80134BAC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80134BB0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80134BB4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80134BB8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80134BBC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80134BC0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80134BC4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80134BC8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80134BCC: addiu       $t5, $t4, -0x4E2
    ctx->r13 = ADD32(ctx->r12, -0X4E2);
    // 0x80134BD0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80134BD4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134BD8: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80134BDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134BE0: addiu       $t2, $t2, 0xD90
    ctx->r10 = ADD32(ctx->r10, 0XD90);
    // 0x80134BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80134BEC: swc1        $f10, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f10.u32l;
    // 0x80134BF0: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80134BF4: lwc1        $f16, -0x458C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X458C);
    // 0x80134BF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134BFC: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x80134C00: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80134C04: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80134C08: swc1        $f18, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f18.u32l;
    // 0x80134C0C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80134C10: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80134C14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80134C18: addu        $v1, $t9, $t2
    ctx->r3 = ADD32(ctx->r25, ctx->r10);
    // 0x80134C1C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80134C20: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
    // 0x80134C24: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80134C28: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80134C2C: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x80134C30: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80134C34: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80134C38: swc1        $f8, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f8.u32l;
    // 0x80134C3C: lw          $t1, 0x84($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X84);
    // 0x80134C40: bnel        $t1, $at, L_80134C54
    if (ctx->r9 != ctx->r1) {
        // 0x80134C44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134C54;
    }
    goto skip_2;
    // 0x80134C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80134C48: jal         0x800E9814
    // 0x80134C4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x80134C4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80134C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134C54:
    // 0x80134C54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134C58: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80134C5C: jr          $ra
    // 0x80134C60: nop

    return;
    // 0x80134C60: nop

;}
RECOMP_FUNC void gcInitDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000926C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009270: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80009274: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x80009278: sb          $zero, 0x54($a0)
    MEM_B(0X54, ctx->r4) = 0;
    // 0x8000927C: sb          $zero, 0x55($a0)
    MEM_B(0X55, ctx->r4) = 0;
    // 0x80009280: sb          $zero, 0x56($a0)
    MEM_B(0X56, ctx->r4) = 0;
    // 0x80009284: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x80009288: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8000928C: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x80009290: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x80009294: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
    // 0x80009298: sw          $zero, 0x58($v1)
    MEM_W(0X58, ctx->r3) = 0;
    // 0x8000929C: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x800092A0: sw          $zero, 0x70($a0)
    MEM_W(0X70, ctx->r4) = 0;
    // 0x800092A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800092A8: lwc1        $f4, -0x228C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X228C);
    // 0x800092AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800092B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800092B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800092B8: sw          $zero, 0x80($a0)
    MEM_W(0X80, ctx->r4) = 0;
    // 0x800092BC: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x800092C0: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
    // 0x800092C4: swc1        $f6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f6.u32l;
    // 0x800092C8: jr          $ra
    // 0x800092CC: swc1        $f8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800092CC: swc1        $f8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void efManagerMBallThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102C90: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80102C94: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80102C98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80102C9C: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x80102CA0: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80102CA4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80102CA8: nop

    // 0x80102CAC: bc1fl       L_80102CE0
    if (!c1cs) {
        // 0x80102CB0: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_80102CE0;
    }
    goto skip_0;
    // 0x80102CB0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80102CB4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80102CB8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80102CBC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80102CC0: lbu         $t8, 0xD($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XD);
    // 0x80102CC4: beq         $t8, $at, L_80102CFC
    if (ctx->r24 == ctx->r1) {
        // 0x80102CC8: nop
    
            goto L_80102CFC;
    }
    // 0x80102CC8: nop

    // 0x80102CCC: jal         0x8000A0D0
    // 0x80102CD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80102CD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80102CD4: b           L_80102CFC
    // 0x80102CD8: nop

        goto L_80102CFC;
    // 0x80102CD8: nop

    // 0x80102CDC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_80102CE0:
    // 0x80102CE0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80102CE4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80102CE8: lbu         $t9, 0xD($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XD);
    // 0x80102CEC: beq         $t9, $at, L_80102CFC
    if (ctx->r25 == ctx->r1) {
        // 0x80102CF0: nop
    
            goto L_80102CFC;
    }
    // 0x80102CF0: nop

    // 0x80102CF4: jal         0x8000A0D0
    // 0x80102CF8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x80102CF8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
L_80102CFC:
    // 0x80102CFC: jal         0x800FD568
    // 0x80102D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    efManagerHaveStructProcUpdate(rdram, ctx);
        goto after_2;
    // 0x80102D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80102D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102D0C: jr          $ra
    // 0x80102D10: nop

    return;
    // 0x80102D10: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B35C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B364: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8015B368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015B36C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015B370: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015B374: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B378: jal         0x800E6F24
    // 0x8015B37C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B37C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015B380: jal         0x8015B244
    // 0x8015B384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x8015B384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015B388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B38C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B390: jr          $ra
    // 0x8015B394: nop

    return;
    // 0x8015B394: nop

;}
RECOMP_FUNC void lbParticlePauseAllID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D3D68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3D6C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D3D70: lw          $v0, 0x6358($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6358);
    // 0x800D3D74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D3D78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800D3D7C: beq         $v0, $zero, L_800D3DA8
    if (ctx->r2 == 0) {
        // 0x800D3D80: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800D3DA8;
    }
    // 0x800D3D80: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D3D84: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
L_800D3D88:
    // 0x800D3D88: bnel        $v1, $t7, L_800D3DA0
    if (ctx->r3 != ctx->r15) {
        // 0x800D3D8C: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800D3DA0;
    }
    goto skip_0;
    // 0x800D3D8C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800D3D90: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    // 0x800D3D94: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x800D3D98: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800D3D9C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800D3DA0:
    // 0x800D3DA0: bnel        $v0, $zero, L_800D3D88
    if (ctx->r2 != 0) {
        // 0x800D3DA4: lhu         $t7, 0x4($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X4);
            goto L_800D3D88;
    }
    goto skip_1;
    // 0x800D3DA4: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    skip_1:
L_800D3DA8:
    // 0x800D3DA8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3DAC: lw          $v0, 0x639C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X639C);
    // 0x800D3DB0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D3DB4: beq         $v0, $zero, L_800D3DE0
    if (ctx->r2 == 0) {
        // 0x800D3DB8: nop
    
            goto L_800D3DE0;
    }
    // 0x800D3DB8: nop

    // 0x800D3DBC: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
L_800D3DC0:
    // 0x800D3DC0: bnel        $v1, $t0, L_800D3DD8
    if (ctx->r3 != ctx->r8) {
        // 0x800D3DC4: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800D3DD8;
    }
    goto skip_2;
    // 0x800D3DC4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x800D3DC8: lhu         $t1, 0x6($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X6);
    // 0x800D3DCC: ori         $t2, $t1, 0x800
    ctx->r10 = ctx->r9 | 0X800;
    // 0x800D3DD0: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x800D3DD4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800D3DD8:
    // 0x800D3DD8: bnel        $v0, $zero, L_800D3DC0
    if (ctx->r2 != 0) {
        // 0x800D3DDC: lhu         $t0, 0x4($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X4);
            goto L_800D3DC0;
    }
    goto skip_3;
    // 0x800D3DDC: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    skip_3:
L_800D3DE0:
    // 0x800D3DE0: jr          $ra
    // 0x800D3DE4: nop

    return;
    // 0x800D3DE4: nop

;}
RECOMP_FUNC void efManagerStarSplashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102074: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80102078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010207C: bne         $a1, $at, L_801020A4
    if (ctx->r5 != ctx->r1) {
        // 0x80102080: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801020A4;
    }
    // 0x80102080: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80102084: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102088: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x8010208C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80102090: jal         0x800D35DC
    // 0x80102094: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    lbParticleMakeGenerator(rdram, ctx);
        goto after_0;
    // 0x80102094: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80102098: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8010209C: b           L_801020C0
    // 0x801020A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_801020C0;
    // 0x801020A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801020A4:
    // 0x801020A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801020A8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801020AC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x801020B0: jal         0x800D35DC
    // 0x801020B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    lbParticleMakeGenerator(rdram, ctx);
        goto after_1;
    // 0x801020B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x801020B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801020BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801020C0:
    // 0x801020C0: beql        $v0, $zero, L_801020E4
    if (ctx->r2 == 0) {
        // 0x801020C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801020E4;
    }
    goto skip_0;
    // 0x801020C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801020C8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801020CC: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x801020D0: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801020D4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x801020D8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801020DC: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x801020E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801020E4:
    // 0x801020E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801020E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801020EC: jr          $ra
    // 0x801020F0: nop

    return;
    // 0x801020F0: nop

;}
RECOMP_FUNC void mnCharactersUpdateSceneDemo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133CB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133CBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133CC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133CC4: jal         0x8039076C
    // 0x80133CC8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x80133CC8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x80133CCC: beq         $v0, $zero, L_80133CF0
    if (ctx->r2 == 0) {
        // 0x80133CD0: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_80133CF0;
    }
    // 0x80133CD0: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80133CD4: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80133CD8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80133CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133CE0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80133CE4: sb          $v0, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r2;
    // 0x80133CE8: jal         0x80005C74
    // 0x80133CEC: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80133CEC: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    after_1:
L_80133CF0:
    // 0x80133CF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133CF4: lw          $v0, 0x671C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X671C);
    // 0x80133CF8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80133CFC: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80133D00: bne         $v0, $at, L_80133D38
    if (ctx->r2 != ctx->r1) {
        // 0x80133D04: addiu       $s0, $s0, 0x4AD0
        ctx->r16 = ADD32(ctx->r16, 0X4AD0);
            goto L_80133D38;
    }
    // 0x80133D04: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80133D08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133D0C: jal         0x80131BA8
    // 0x80133D10: lw          $a0, 0x66F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66F8);
    mnCharactersGetPage(rdram, ctx);
        goto after_2;
    // 0x80133D10: lw          $a0, 0x66F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66F8);
    after_2:
    // 0x80133D14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133D18: addiu       $v1, $v1, 0x65F8
    ctx->r3 = ADD32(ctx->r3, 0X65F8);
    // 0x80133D1C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80133D20: jal         0x80131B58
    // 0x80133D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80133D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80133D28: jal         0x8013369C
    // 0x80133D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersChangeFighter(rdram, ctx);
        goto after_4;
    // 0x80133D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80133D30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D34: lw          $v0, 0x671C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X671C);
L_80133D38:
    // 0x80133D38: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x80133D3C: bne         $v0, $at, L_80133D54
    if (ctx->r2 != ctx->r1) {
        // 0x80133D40: addiu       $t8, $zero, 0x3D
        ctx->r24 = ADD32(0, 0X3D);
            goto L_80133D54;
    }
    // 0x80133D40: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x80133D44: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80133D48: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80133D4C: jal         0x80005C74
    // 0x80133D50: sb          $t7, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80133D50: sb          $t7, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r15;
    after_5:
L_80133D54:
    // 0x80133D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133D58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133D5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133D60: jr          $ra
    // 0x80133D64: nop

    return;
    // 0x80133D64: nop

;}
RECOMP_FUNC void mnPlayersVSCursorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801382E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801382E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801382E8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801382EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801382F0: jal         0x801379B8
    // 0x801382F4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    mnPlayersVSAdjustCursor(rdram, ctx);
        goto after_0;
    // 0x801382F4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x801382F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801382FC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80138300: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x80138304: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80138308: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8013830C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80138310: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80138314: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80138318: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8013831C: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80138320: beql        $t0, $zero, L_801384EC
    if (ctx->r8 == 0) {
        // 0x80138324: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_801384EC;
    }
    goto skip_0;
    // 0x80138324: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80138328: jal         0x8013676C
    // 0x8013832C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSCheckPlayerKindSelectAllPlayer(rdram, ctx);
        goto after_1;
    // 0x8013832C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80138330: bne         $v0, $zero, L_801384E8
    if (ctx->r2 != 0) {
        // 0x80138334: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_801384E8;
    }
    // 0x80138334: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80138338: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8013833C: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80138340: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80138344: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80138348: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013834C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80138350: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80138354: lw          $a2, -0x44F8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44F8);
    // 0x80138358: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013835C: jal         0x8013718C
    // 0x80138360: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_2;
    // 0x80138360: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80138364: bne         $v0, $zero, L_801384E8
    if (ctx->r2 != 0) {
        // 0x80138368: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_801384E8;
    }
    // 0x80138368: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013836C: jal         0x801376D0
    // 0x80138370: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    mnPlayersVSCheckCursorPuckGrab(rdram, ctx);
        goto after_3;
    // 0x80138370: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80138374: bnel        $v0, $zero, L_801384EC
    if (ctx->r2 != 0) {
        // 0x80138378: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_801384EC;
    }
    goto skip_1;
    // 0x80138378: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x8013837C: jal         0x80134F64
    // 0x80138380: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSCheckTimeArrowRInRange(rdram, ctx);
        goto after_4;
    // 0x80138380: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80138384: beq         $v0, $zero, L_80138400
    if (ctx->r2 == 0) {
        // 0x80138388: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80138400;
    }
    // 0x80138388: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013838C: lw          $t2, -0x4254($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4254);
    // 0x80138390: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138394: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80138398: bne         $t2, $at, L_801383C8
    if (ctx->r10 != ctx->r1) {
        // 0x8013839C: addiu       $v0, $v0, -0x4280
        ctx->r2 = ADD32(ctx->r2, -0X4280);
            goto L_801383C8;
    }
    // 0x8013839C: addiu       $v0, $v0, -0x4280
    ctx->r2 = ADD32(ctx->r2, -0X4280);
    // 0x801383A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801383A4: jal         0x8013AAF8
    // 0x801383A8: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    mnPlayersVSGetNextTimeValue(rdram, ctx);
        goto after_5;
    // 0x801383A8: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    after_5:
    // 0x801383AC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801383B0: addiu       $v1, $v1, -0x4284
    ctx->r3 = ADD32(ctx->r3, -0X4284);
    // 0x801383B4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801383B8: jal         0x80133FAC
    // 0x801383BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSMakeTimeSelect(rdram, ctx);
        goto after_6;
    // 0x801383BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x801383C0: b           L_801383F0
    // 0x801383C4: nop

        goto L_801383F0;
    // 0x801383C4: nop

L_801383C8:
    // 0x801383C8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801383CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801383D0: slti        $at, $v1, 0x63
    ctx->r1 = SIGNED(ctx->r3) < 0X63 ? 1 : 0;
    // 0x801383D4: bnel        $at, $zero, L_801383E8
    if (ctx->r1 != 0) {
        // 0x801383D8: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_801383E8;
    }
    goto skip_2;
    // 0x801383D8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    skip_2:
    // 0x801383DC: b           L_801383E8
    // 0x801383E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_801383E8;
    // 0x801383E0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801383E4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_801383E8:
    // 0x801383E8: jal         0x80134198
    // 0x801383EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    mnPlayersVSMakeStockSelect(rdram, ctx);
        goto after_7;
    // 0x801383EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_7:
L_801383F0:
    // 0x801383F0: jal         0x800269C0
    // 0x801383F4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801383F4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_8:
    // 0x801383F8: b           L_801384EC
    // 0x801383FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_801384EC;
    // 0x801383FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80138400:
    // 0x80138400: jal         0x8013502C
    // 0x80138404: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSCheckTimeArrowLInRange(rdram, ctx);
        goto after_9;
    // 0x80138404: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x80138408: beq         $v0, $zero, L_80138488
    if (ctx->r2 == 0) {
        // 0x8013840C: lui         $t3, 0x8014
        ctx->r11 = S32(0X8014 << 16);
            goto L_80138488;
    }
    // 0x8013840C: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138410: lw          $t3, -0x4254($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4254);
    // 0x80138414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138418: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013841C: bne         $t3, $at, L_80138450
    if (ctx->r11 != ctx->r1) {
        // 0x80138420: addiu       $v0, $v0, -0x4280
        ctx->r2 = ADD32(ctx->r2, -0X4280);
            goto L_80138450;
    }
    // 0x80138420: addiu       $v0, $v0, -0x4280
    ctx->r2 = ADD32(ctx->r2, -0X4280);
    // 0x80138424: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138428: addiu       $v1, $v1, -0x4284
    ctx->r3 = ADD32(ctx->r3, -0X4284);
    // 0x8013842C: jal         0x8013ABDC
    // 0x80138430: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    mnPlayersVSGetPrevTimeValue(rdram, ctx);
        goto after_10;
    // 0x80138430: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_10:
    // 0x80138434: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138438: addiu       $v1, $v1, -0x4284
    ctx->r3 = ADD32(ctx->r3, -0X4284);
    // 0x8013843C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80138440: jal         0x80133FAC
    // 0x80138444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSMakeTimeSelect(rdram, ctx);
        goto after_11;
    // 0x80138444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80138448: b           L_80138478
    // 0x8013844C: nop

        goto L_80138478;
    // 0x8013844C: nop

L_80138450:
    // 0x80138450: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80138454: addiu       $t4, $zero, 0x62
    ctx->r12 = ADD32(0, 0X62);
    // 0x80138458: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8013845C: bgezl       $v1, L_80138470
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80138460: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_80138470;
    }
    goto skip_3;
    // 0x80138460: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    skip_3:
    // 0x80138464: b           L_80138470
    // 0x80138468: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_80138470;
    // 0x80138468: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8013846C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80138470:
    // 0x80138470: jal         0x80134198
    // 0x80138474: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    mnPlayersVSMakeStockSelect(rdram, ctx);
        goto after_12;
    // 0x80138474: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_12:
L_80138478:
    // 0x80138478: jal         0x800269C0
    // 0x8013847C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_13;
    // 0x8013847C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_13:
    // 0x80138480: b           L_801384EC
    // 0x80138484: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_801384EC;
    // 0x80138484: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80138488:
    // 0x80138488: jal         0x80135270
    // 0x8013848C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSCheckGameModeInRange(rdram, ctx);
        goto after_14;
    // 0x8013848C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x80138490: beq         $v0, $zero, L_801384A8
    if (ctx->r2 == 0) {
        // 0x80138494: nop
    
            goto L_801384A8;
    }
    // 0x80138494: nop

    // 0x80138498: jal         0x80135334
    // 0x8013849C: nop

    mnPlayersVSUpdateGameMode(rdram, ctx);
        goto after_15;
    // 0x8013849C: nop

    after_15:
    // 0x801384A0: b           L_801384EC
    // 0x801384A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_801384EC;
    // 0x801384A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_801384A8:
    // 0x801384A8: jal         0x80138218
    // 0x801384AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSCheckBackInRange(rdram, ctx);
        goto after_16;
    // 0x801384AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x801384B0: beq         $v0, $zero, L_801384D0
    if (ctx->r2 == 0) {
        // 0x801384B4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_801384D0;
    }
    // 0x801384B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801384B8: jal         0x801380F4
    // 0x801384BC: nop

    mnPlayersVSBackToVSMode(rdram, ctx);
        goto after_17;
    // 0x801384BC: nop

    after_17:
    // 0x801384C0: jal         0x800269C0
    // 0x801384C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_18;
    // 0x801384C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_18:
    // 0x801384C8: b           L_801384EC
    // 0x801384CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_801384EC;
    // 0x801384CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_801384D0:
    // 0x801384D0: jal         0x80135634
    // 0x801384D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    mnPlayersVSCheckTeamSelectInRangeAll(rdram, ctx);
        goto after_19;
    // 0x801384D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x801384D8: bne         $v0, $zero, L_801384E8
    if (ctx->r2 != 0) {
        // 0x801384DC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_801384E8;
    }
    // 0x801384DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801384E0: jal         0x801357A4
    // 0x801384E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    mnPlayersVSCheckHandicapArrowInRangeAll(rdram, ctx);
        goto after_20;
    // 0x801384E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_20:
L_801384E8:
    // 0x801384E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_801384EC:
    // 0x801384EC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x801384F0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801384F4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801384F8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801384FC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80138500: lw          $t9, -0x4258($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4258);
    // 0x80138504: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138508: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8013850C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80138510: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80138514: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80138518: lhu         $v1, 0x2($t5)
    ctx->r3 = MEM_HU(ctx->r13, 0X2);
    // 0x8013851C: bne         $t9, $zero, L_80138650
    if (ctx->r25 != 0) {
        // 0x80138520: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80138650;
    }
    // 0x80138520: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80138524: andi        $t0, $v1, 0x8
    ctx->r8 = ctx->r3 & 0X8;
    // 0x80138528: beq         $t0, $zero, L_8013855C
    if (ctx->r8 == 0) {
        // 0x8013852C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8013855C;
    }
    // 0x8013852C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80138530: lw          $a2, 0x80($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X80);
    // 0x80138534: jal         0x8013718C
    // 0x80138538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_21;
    // 0x80138538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x8013853C: bne         $v0, $zero, L_8013855C
    if (ctx->r2 != 0) {
        // 0x80138540: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_8013855C;
    }
    // 0x80138540: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80138544: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x80138548: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013854C: beql        $t2, $zero, L_80138560
    if (ctx->r10 == 0) {
        // 0x80138550: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80138560;
    }
    goto skip_4;
    // 0x80138550: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80138554: jal         0x80137EFC
    // 0x80138558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayersVSUpdateCostume(rdram, ctx);
        goto after_22;
    // 0x80138558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
L_8013855C:
    // 0x8013855C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80138560:
    // 0x80138560: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80138564: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80138568: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x8013856C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80138570: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80138574: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80138578: beql        $t5, $zero, L_801385AC
    if (ctx->r13 == 0) {
        // 0x8013857C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_801385AC;
    }
    goto skip_5;
    // 0x8013857C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80138580: jal         0x8013718C
    // 0x80138584: lw          $a2, 0x80($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X80);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_23;
    // 0x80138584: lw          $a2, 0x80($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X80);
    after_23:
    // 0x80138588: bne         $v0, $zero, L_801385A8
    if (ctx->r2 != 0) {
        // 0x8013858C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_801385A8;
    }
    // 0x8013858C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80138590: lw          $t9, 0x88($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X88);
    // 0x80138594: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80138598: beql        $t9, $zero, L_801385AC
    if (ctx->r25 == 0) {
        // 0x8013859C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_801385AC;
    }
    goto skip_6;
    // 0x8013859C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x801385A0: jal         0x80137EFC
    // 0x801385A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnPlayersVSUpdateCostume(rdram, ctx);
        goto after_24;
    // 0x801385A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
L_801385A8:
    // 0x801385A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_801385AC:
    // 0x801385AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801385B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801385B4: lhu         $t8, 0x2($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X2);
    // 0x801385B8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x801385BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801385C0: andi        $t1, $t8, 0x4
    ctx->r9 = ctx->r24 & 0X4;
    // 0x801385C4: beql        $t1, $zero, L_801385F8
    if (ctx->r9 == 0) {
        // 0x801385C8: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_801385F8;
    }
    goto skip_7;
    // 0x801385C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x801385CC: jal         0x8013718C
    // 0x801385D0: lw          $a2, 0x80($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X80);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_25;
    // 0x801385D0: lw          $a2, 0x80($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X80);
    after_25:
    // 0x801385D4: bne         $v0, $zero, L_801385F4
    if (ctx->r2 != 0) {
        // 0x801385D8: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_801385F4;
    }
    // 0x801385D8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801385DC: lw          $t4, 0x88($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X88);
    // 0x801385E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801385E4: beql        $t4, $zero, L_801385F8
    if (ctx->r12 == 0) {
        // 0x801385E8: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_801385F8;
    }
    goto skip_8;
    // 0x801385E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x801385EC: jal         0x80137EFC
    // 0x801385F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnPlayersVSUpdateCostume(rdram, ctx);
        goto after_26;
    // 0x801385F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
L_801385F4:
    // 0x801385F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_801385F8:
    // 0x801385F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801385FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80138600: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80138604: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80138608: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8013860C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80138610: beql        $t7, $zero, L_80138644
    if (ctx->r15 == 0) {
        // 0x80138614: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80138644;
    }
    goto skip_9;
    // 0x80138614: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80138618: jal         0x8013718C
    // 0x8013861C: lw          $a2, 0x80($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X80);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_27;
    // 0x8013861C: lw          $a2, 0x80($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X80);
    after_27:
    // 0x80138620: bne         $v0, $zero, L_80138640
    if (ctx->r2 != 0) {
        // 0x80138624: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80138640;
    }
    // 0x80138624: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80138628: lw          $t8, 0x88($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X88);
    // 0x8013862C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80138630: beql        $t8, $zero, L_80138644
    if (ctx->r24 == 0) {
        // 0x80138634: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80138644;
    }
    goto skip_10;
    // 0x80138634: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x80138638: jal         0x80137EFC
    // 0x8013863C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    mnPlayersVSUpdateCostume(rdram, ctx);
        goto after_28;
    // 0x8013863C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
L_80138640:
    // 0x80138640: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80138644:
    // 0x80138644: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80138648: b           L_80138678
    // 0x8013864C: lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X2);
        goto L_80138678;
    // 0x8013864C: lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X2);
L_80138650:
    // 0x80138650: andi        $t2, $v1, 0xF
    ctx->r10 = ctx->r3 & 0XF;
    // 0x80138654: beq         $t2, $zero, L_80138678
    if (ctx->r10 == 0) {
        // 0x80138658: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80138678;
    }
    // 0x80138658: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013865C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80138660: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80138664: jal         0x8013718C
    // 0x80138668: lw          $a2, 0x80($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X80);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_29;
    // 0x80138668: lw          $a2, 0x80($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X80);
    after_29:
    // 0x8013866C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80138670: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80138674: lhu         $v1, 0x2($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0X2);
L_80138678:
    // 0x80138678: andi        $t5, $v1, 0x4000
    ctx->r13 = ctx->r3 & 0X4000;
    // 0x8013867C: beql        $t5, $zero, L_801386A0
    if (ctx->r13 == 0) {
        // 0x80138680: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_801386A0;
    }
    goto skip_11;
    // 0x80138680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80138684: jal         0x80137F9C
    // 0x80138688: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSCheckManFighterSelected(rdram, ctx);
        goto after_30;
    // 0x80138688: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_30:
    // 0x8013868C: beql        $v0, $zero, L_801386A0
    if (ctx->r2 == 0) {
        // 0x80138690: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_801386A0;
    }
    goto skip_12;
    // 0x80138690: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80138694: jal         0x80137FF8
    // 0x80138698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    mnPlayersVSRecallPuck(rdram, ctx);
        goto after_31;
    // 0x80138698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_31:
    // 0x8013869C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_801386A0:
    // 0x801386A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801386A4: lw          $v0, 0x5C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X5C);
    // 0x801386A8: bne         $v0, $zero, L_801386C4
    if (ctx->r2 != 0) {
        // 0x801386AC: nop
    
            goto L_801386C4;
    }
    // 0x801386AC: nop

    // 0x801386B0: jal         0x80138140
    // 0x801386B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSDetectBack(rdram, ctx);
        goto after_32;
    // 0x801386B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_32:
    // 0x801386B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801386BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801386C0: lw          $v0, 0x5C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X5C);
L_801386C4:
    // 0x801386C4: bnel        $v0, $zero, L_801386D8
    if (ctx->r2 != 0) {
        // 0x801386C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801386D8;
    }
    goto skip_13;
    // 0x801386C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_13:
    // 0x801386CC: jal         0x80137D4C
    // 0x801386D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSUpdateCursorNoRecall(rdram, ctx);
        goto after_33;
    // 0x801386D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_33:
    // 0x801386D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801386D8:
    // 0x801386D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801386DC: jr          $ra
    // 0x801386E0: nop

    return;
    // 0x801386E0: nop

;}
RECOMP_FUNC void ifCommonBattlePauseInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80113FD0: jal         0x80113F74
    // 0x80113FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_0;
    // 0x80113FD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80113FD8: jal         0x801157EC
    // 0x80113FDC: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_1;
    // 0x80113FDC: nop

    after_1:
    // 0x80113FE0: jal         0x80104CB4
    // 0x80113FE4: nop

    grWallpaperPausePerspUpdate(rdram, ctx);
        goto after_2;
    // 0x80113FE4: nop

    after_2:
    // 0x80113FE8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80113FEC: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80113FF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80113FF4: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
    // 0x80113FF8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80113FFC: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80114000: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80114004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114008: jal         0x80026594
    // 0x8011400C: sb          $t8, 0x17E4($at)
    MEM_B(0X17E4, ctx->r1) = ctx->r24;
    func_80026594_27194(rdram, ctx);
        goto after_3;
    // 0x8011400C: sb          $t8, 0x17E4($at)
    MEM_B(0X17E4, ctx->r1) = ctx->r24;
    after_3:
    // 0x80114010: jal         0x800269C0
    // 0x80114014: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80114014: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    after_4:
    // 0x80114018: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8011401C: jal         0x80020B38
    // 0x80114020: addiu       $a1, $zero, 0x3C00
    ctx->r5 = ADD32(0, 0X3C00);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_5;
    // 0x80114020: addiu       $a1, $zero, 0x3C00
    ctx->r5 = ADD32(0, 0X3C00);
    after_5:
    // 0x80114024: jal         0x80113EB4
    // 0x80114028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ifCommonBattlePauseMakeInterface(rdram, ctx);
        goto after_6;
    // 0x80114028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x8011402C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114034: jr          $ra
    // 0x80114038: nop

    return;
    // 0x80114038: nop

;}
RECOMP_FUNC void itBombHeiCommonCheckMakeDustEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177180: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80177184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177188: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8017718C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177190: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80177194: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x80177198: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x8017719C: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
    // 0x801771A0: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x801771A4: bnel        $t7, $zero, L_801771B8
    if (ctx->r15 != 0) {
        // 0x801771A8: lw          $t9, 0x1C($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X1C);
            goto L_801771B8;
    }
    goto skip_0;
    // 0x801771A8: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    skip_0:
    // 0x801771AC: beql        $a1, $zero, L_801771FC
    if (ctx->r5 == 0) {
        // 0x801771B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801771FC;
    }
    goto skip_1;
    // 0x801771B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801771B4: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
L_801771B8:
    // 0x801771B8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x801771BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801771C0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801771C4: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x801771C8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x801771CC: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x801771D0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x801771D4: lh          $t0, 0x2E($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2E);
    // 0x801771D8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801771DC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x801771E0: nop

    // 0x801771E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801771E8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801771EC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801771F0: jal         0x800FF3F4
    // 0x801771F4: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801771F4: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    after_0:
    // 0x801771F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801771FC:
    // 0x801771FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80177200: jr          $ra
    // 0x80177204: nop

    return;
    // 0x80177204: nop

;}
RECOMP_FUNC void syAudioMakeBGMPlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA00: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8001FA04: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001FA08: addiu       $v1, $v1, -0x2D28
    ctx->r3 = ADD32(ctx->r3, -0X2D28);
    // 0x8001FA0C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8001FA10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FA14: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001FA18: sw          $t6, -0x2D18($at)
    MEM_W(-0X2D18, ctx->r1) = ctx->r14;
    // 0x8001FA1C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8001FA20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FA24: addiu       $v0, $v0, -0x2678
    ctx->r2 = ADD32(ctx->r2, -0X2678);
    // 0x8001FA28: sw          $t7, -0x2D14($at)
    MEM_W(-0X2D14, ctx->r1) = ctx->r15;
    // 0x8001FA2C: lbu         $t8, 0xB($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XB);
    // 0x8001FA30: lbu         $t9, 0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XA);
    // 0x8001FA34: lbu         $t1, 0xC($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XC);
    // 0x8001FA38: lui         $t2, 0x8002
    ctx->r10 = S32(0X8002 << 16);
    // 0x8001FA3C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001FA40: addiu       $t2, $t2, -0x1538
    ctx->r10 = ADD32(ctx->r10, -0X1538);
    // 0x8001FA44: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8001FA48: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8001FA4C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8001FA50: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8001FA54: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8001FA58: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8001FA5C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8001FA60: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8001FA64: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001FA68: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001FA6C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001FA70: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x8001FA74: lhu         $a0, 0x8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X8);
    // 0x8001FA78: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    // 0x8001FA7C: sw          $t9, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r25;
    // 0x8001FA80: jal         0x80035230
    // 0x8001FA84: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x8001FA84: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    after_0:
    // 0x8001FA88: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8001FA8C: lbu         $t4, -0x2648($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2648);
    // 0x8001FA90: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001FA94: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001FA98: addiu       $a0, $a0, -0x34D8
    ctx->r4 = ADD32(ctx->r4, -0X34D8);
    // 0x8001FA9C: addiu       $t3, $t3, -0x2D28
    ctx->r11 = ADD32(ctx->r11, -0X2D28);
    // 0x8001FAA0: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x8001FAA4: sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // 0x8001FAA8: sw          $t3, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r11;
    // 0x8001FAAC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8001FAB0: beq         $at, $zero, L_8001FAC0
    if (ctx->r1 == 0) {
        // 0x8001FAB4: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_8001FAC0;
    }
    // 0x8001FAB4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x8001FAB8: b           L_8001FADC
    // 0x8001FABC: sb          $t4, 0x100($sp)
    MEM_B(0X100, ctx->r29) = ctx->r12;
        goto L_8001FADC;
    // 0x8001FABC: sb          $t4, 0x100($sp)
    MEM_B(0X100, ctx->r29) = ctx->r12;
L_8001FAC0:
    // 0x8001FAC0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001FAC4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001FAC8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001FACC: lw          $t7, -0x3500($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3500);
    // 0x8001FAD0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8001FAD4: sb          $t5, 0x100($sp)
    MEM_B(0X100, ctx->r29) = ctx->r13;
    // 0x8001FAD8: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
L_8001FADC:
    // 0x8001FADC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001FAE0: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    // 0x8001FAE4: jal         0x8002CE88
    // 0x8001FAE8: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    n_alInit(rdram, ctx);
        goto after_1;
    // 0x8001FAE8: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    after_1:
    // 0x8001FAEC: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x8001FAF0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8001FAF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FAF8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001FAFC: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x8001FB00: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001FB04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FB08: addiu       $v1, $v1, -0x26E4
    ctx->r3 = ADD32(ctx->r3, -0X26E4);
    // 0x8001FB0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001FB10: addiu       $v0, $v0, -0x2678
    ctx->r2 = ADD32(ctx->r2, -0X2678);
    // 0x8001FB14: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FB18: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001FB1C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8001FB20: nop

    // 0x8001FB24: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x8001FB28: mflo        $t3
    ctx->r11 = lo;
    // 0x8001FB2C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8001FB30: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8001FB34: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001FB38: bne         $a1, $zero, L_8001FB44
    if (ctx->r5 != 0) {
        // 0x8001FB3C: nop
    
            goto L_8001FB44;
    }
    // 0x8001FB3C: nop

    // 0x8001FB40: break       7
    do_break(2147613504);
L_8001FB44:
    // 0x8001FB44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FB48: bne         $a1, $at, L_8001FB5C
    if (ctx->r5 != ctx->r1) {
        // 0x8001FB4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001FB5C;
    }
    // 0x8001FB4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001FB50: bne         $t2, $at, L_8001FB5C
    if (ctx->r10 != ctx->r1) {
        // 0x8001FB54: nop
    
            goto L_8001FB5C;
    }
    // 0x8001FB54: nop

    // 0x8001FB58: break       6
    do_break(2147613528);
L_8001FB5C:
    // 0x8001FB5C: mflo        $t4
    ctx->r12 = lo;
    // 0x8001FB60: addiu       $t5, $t4, 0xB8
    ctx->r13 = ADD32(ctx->r12, 0XB8);
    // 0x8001FB64: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8001FB68: addiu       $t7, $t5, -0xB8
    ctx->r15 = ADD32(ctx->r13, -0XB8);
    // 0x8001FB6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FB70: sw          $t7, -0x26E0($at)
    MEM_W(-0X26E0, ctx->r1) = ctx->r15;
    // 0x8001FB74: lhu         $a0, 0x34($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X34);
    // 0x8001FB78: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x8001FB7C: lbu         $t9, 0x32($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X32);
    // 0x8001FB80: lbu         $t1, 0x33($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X33);
    // 0x8001FB84: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x8001FB88: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8001FB8C: sh          $t9, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r25;
    // 0x8001FB90: beq         $a0, $zero, L_8001FBA8
    if (ctx->r4 == 0) {
        // 0x8001FB94: sh          $t1, 0x98($sp)
        MEM_H(0X98, ctx->r29) = ctx->r9;
            goto L_8001FBA8;
    }
    // 0x8001FB94: sh          $t1, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r9;
    // 0x8001FB98: lw          $t2, 0x38($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X38);
    // 0x8001FB9C: sh          $a0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r4;
    // 0x8001FBA0: b           L_8001FBC8
    // 0x8001FBA4: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
        goto L_8001FBC8;
    // 0x8001FBA4: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
L_8001FBA8:
    // 0x8001FBA8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001FBAC: lw          $v1, -0x26B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26B0);
    // 0x8001FBB0: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8001FBB4: lh          $t4, 0xE($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XE);
    // 0x8001FBB8: sh          $t4, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r12;
    // 0x8001FBBC: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x8001FBC0: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x8001FBC4: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
L_8001FBC8:
    // 0x8001FBC8: lw          $t7, 0x3C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X3C);
    // 0x8001FBCC: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x8001FBD0: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x8001FBD4: lhu         $t1, 0x48($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X48);
    // 0x8001FBD8: lhu         $t2, 0x4A($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X4A);
    // 0x8001FBDC: lhu         $t3, 0x4C($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4C);
    // 0x8001FBE0: lbu         $t5, 0x12($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X12);
    // 0x8001FBE4: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8001FBE8: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x8001FBEC: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x8001FBF0: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8001FBF4: sh          $t1, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r9;
    // 0x8001FBF8: sh          $t2, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r10;
    // 0x8001FBFC: addiu       $t4, $t4, -0x2D28
    ctx->r12 = ADD32(ctx->r12, -0X2D28);
    // 0x8001FC00: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8001FC04: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8001FC08: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8001FC0C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8001FC10: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8001FC14: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8001FC18: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x8001FC1C: sh          $t6, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r14;
    // 0x8001FC20: sh          $t7, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r15;
    // 0x8001FC24: sh          $t8, 0xBE($sp)
    MEM_H(0XBE, ctx->r29) = ctx->r24;
    // 0x8001FC28: sh          $t9, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r25;
    // 0x8001FC2C: sh          $t1, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r9;
    // 0x8001FC30: sh          $t2, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r10;
    // 0x8001FC34: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8001FC38: sh          $t3, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r11;
    // 0x8001FC3C: jal         0x80026204
    // 0x8001FC40: sb          $t5, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r13;
    func_80026204_26E04(rdram, ctx);
        goto after_2;
    // 0x8001FC40: sb          $t5, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001FC44: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001FC48: lbu         $t3, -0x2645($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2645);
    // 0x8001FC4C: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FC50: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FC54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001FC58: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8001FC5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FC64: jal         0x8001E5F4
    // 0x8001FC68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x8001FC68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8001FC6C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8001FC70: addiu       $t0, $t0, -0x2678
    ctx->r8 = ADD32(ctx->r8, -0X2678);
    // 0x8001FC74: lbu         $t5, 0x33($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X33);
    // 0x8001FC78: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001FC7C: addiu       $v1, $v1, -0x26AC
    ctx->r3 = ADD32(ctx->r3, -0X26AC);
    // 0x8001FC80: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001FC84: blez        $t5, L_8001FCB8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8001FC88: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001FCB8;
    }
    // 0x8001FC88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001FC8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001FC90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8001FC94:
    // 0x8001FC94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001FC98: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8001FC9C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001FCA0: lbu         $t8, 0x33($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X33);
    // 0x8001FCA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FCA8: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001FCAC: bnel        $at, $zero, L_8001FC94
    if (ctx->r1 != 0) {
        // 0x8001FCB0: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8001FC94;
    }
    goto skip_0;
    // 0x8001FCB0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8001FCB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001FCB8:
    // 0x8001FCB8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FCBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001FCC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001FCC4: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FCC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FCCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FCD0: jal         0x8001E5F4
    // 0x8001FCD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8001FCD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8001FCD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FCDC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FCE0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001FCE4: sw          $v0, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = ctx->r2;
    // 0x8001FCE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001FCEC: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FCF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FCF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FCF8: jal         0x8001E5F4
    // 0x8001FCFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x8001FCFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8001FD00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FD04: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8001FD08: lbu         $t2, -0x2665($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2665);
    // 0x8001FD0C: sw          $v0, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r2;
    // 0x8001FD10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001FD14: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FD18: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8001FD1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8001FD20: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FD24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FD28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FD2C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x8001FD30: jal         0x8001E5F4
    // 0x8001FD34: sb          $t2, -0x2698($at)
    MEM_B(-0X2698, ctx->r1) = ctx->r10;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x8001FD34: sb          $t2, -0x2698($at)
    MEM_B(-0X2698, ctx->r1) = ctx->r10;
    after_6:
    // 0x8001FD38: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001FD3C: addiu       $a0, $a0, -0x2608
    ctx->r4 = ADD32(ctx->r4, -0X2608);
    // 0x8001FD40: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001FD44: addiu       $t4, $v0, 0x14
    ctx->r12 = ADD32(ctx->r2, 0X14);
    // 0x8001FD48: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001FD4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FD50: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8001FD54: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x8001FD58: addiu       $t5, $v0, 0x28
    ctx->r13 = ADD32(ctx->r2, 0X28);
    // 0x8001FD5C: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x8001FD60: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FD64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001FD68: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8001FD6C: addiu       $t6, $v0, 0x3C
    ctx->r14 = ADD32(ctx->r2, 0X3C);
    // 0x8001FD70: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
L_8001FD74:
    // 0x8001FD74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FD78: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FD7C: addiu       $t8, $t7, 0x14
    ctx->r24 = ADD32(ctx->r15, 0X14);
    // 0x8001FD80: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FD84: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001FD88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FD8C: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FD90: addiu       $t2, $t1, 0x28
    ctx->r10 = ADD32(ctx->r9, 0X28);
    // 0x8001FD94: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FD98: sw          $t2, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r10;
    // 0x8001FD9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FDA0: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FDA4: addiu       $t5, $t4, 0x3C
    ctx->r13 = ADD32(ctx->r12, 0X3C);
    // 0x8001FDA8: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FDAC: sw          $t5, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r13;
    // 0x8001FDB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FDB4: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FDB8: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FDBC: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x8001FDC0: addiu       $t8, $t7, 0x50
    ctx->r24 = ADD32(ctx->r15, 0X50);
    // 0x8001FDC4: bne         $v1, $a1, L_8001FD74
    if (ctx->r3 != ctx->r5) {
        // 0x8001FDC8: sw          $t8, 0x3C($t9)
        MEM_W(0X3C, ctx->r25) = ctx->r24;
            goto L_8001FD74;
    }
    // 0x8001FDC8: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
    // 0x8001FDCC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001FDD0: lui         $t3, 0x8002
    ctx->r11 = S32(0X8002 << 16);
    // 0x8001FDD4: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001FDD8: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8001FDDC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8001FDE0: lui         $t4, 0x8002
    ctx->r12 = S32(0X8002 << 16);
    // 0x8001FDE4: lui         $at, 0x46F0
    ctx->r1 = S32(0X46F0 << 16);
    // 0x8001FDE8: addiu       $t4, $t4, -0xBD4
    ctx->r12 = ADD32(ctx->r12, -0XBD4);
    // 0x8001FDEC: addiu       $v0, $v0, -0x1148
    ctx->r2 = ADD32(ctx->r2, -0X1148);
    // 0x8001FDF0: addiu       $t3, $t3, -0x141C
    ctx->r11 = ADD32(ctx->r11, -0X141C);
    // 0x8001FDF4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8001FDF8: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8001FDFC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8001FE00: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x8001FE04: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x8001FE08: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001FE0C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FE10: addiu       $s7, $s7, -0x2680
    ctx->r23 = ADD32(ctx->r23, -0X2680);
    // 0x8001FE14: addiu       $s6, $s6, -0x2684
    ctx->r22 = ADD32(ctx->r22, -0X2684);
    // 0x8001FE18: addiu       $s5, $s5, -0x2688
    ctx->r21 = ADD32(ctx->r21, -0X2688);
    // 0x8001FE1C: addiu       $s4, $s4, -0x269C
    ctx->r20 = ADD32(ctx->r20, -0X269C);
    // 0x8001FE20: addiu       $s2, $s2, -0x26A0
    ctx->r18 = ADD32(ctx->r18, -0X26A0);
    // 0x8001FE24: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8001FE28: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8001FE2C: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x8001FE30: addiu       $s3, $s3, -0x2678
    ctx->r19 = ADD32(ctx->r19, -0X2678);
    // 0x8001FE34: addiu       $fp, $sp, 0xC8
    ctx->r30 = ADD32(ctx->r29, 0XC8);
L_8001FE38:
    // 0x8001FE38: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001FE3C: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8001FE40: lbu         $t5, 0xF($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0XF);
    // 0x8001FE44: lbu         $t6, -0x266B($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X266B);
    // 0x8001FE48: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8001FE4C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8001FE50: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FE54: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FE58: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8001FE5C: addiu       $t1, $zero, 0x88
    ctx->r9 = ADD32(0, 0X88);
    // 0x8001FE60: sb          $t7, 0xD0($sp)
    MEM_B(0XD0, ctx->r29) = ctx->r15;
    // 0x8001FE64: sw          $a2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r6;
    // 0x8001FE68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001FE6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FE70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FE74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001FE78: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    // 0x8001FE7C: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x8001FE80: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x8001FE84: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
    // 0x8001FE88: jal         0x8001E5F4
    // 0x8001FE8C: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x8001FE8C: sw          $t9, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r25;
    after_7:
    // 0x8001FE90: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8001FE94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001FE98: jal         0x8002C3D0
    // 0x8001FE9C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_8002C3D0_2CFD0(rdram, ctx);
        goto after_8;
    // 0x8001FE9C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_8:
    // 0x8001FEA0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001FEA4: lw          $a1, -0x26A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26A8);
    // 0x8001FEA8: jal         0x8002FBD0
    // 0x8001FEAC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    alCSPSetBank(rdram, ctx);
        goto after_9;
    // 0x8001FEAC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8001FEB0: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001FEB4: addiu       $t2, $zero, 0xF8
    ctx->r10 = ADD32(0, 0XF8);
    // 0x8001FEB8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001FEBC: addiu       $a2, $a2, -0x2D28
    ctx->r6 = ADD32(ctx->r6, -0X2D28);
    // 0x8001FEC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001FEC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001FEC8: jal         0x8001E5F4
    // 0x8001FECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x8001FECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x8001FED0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8001FED4: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001FED8: lw          $t3, -0x2690($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2690);
    // 0x8001FEDC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001FEE0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001FEE4: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8001FEE8: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8001FEEC: lw          $t6, -0x268C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X268C);
    // 0x8001FEF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001FEF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FEF8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8001FEFC: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8001FF00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001FF04: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001FF08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001FF0C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8001FF10: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8001FF14: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8001FF18: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8001FF1C: sw          $zero, -0x4($s5)
    MEM_W(-0X4, ctx->r21) = 0;
    // 0x8001FF20: swc1        $f20, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->f20.u32l;
    // 0x8001FF24: bne         $s1, $at, L_8001FE38
    if (ctx->r17 != ctx->r1) {
        // 0x8001FF28: swc1        $f22, -0x4($s7)
        MEM_W(-0X4, ctx->r23) = ctx->f22.u32l;
            goto L_8001FE38;
    }
    // 0x8001FF28: swc1        $f22, -0x4($s7)
    MEM_W(-0X4, ctx->r23) = ctx->f22.u32l;
    // 0x8001FF2C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8001FF30: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001FF34: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001FF38: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001FF3C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8001FF40: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8001FF44: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8001FF48: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001FF4C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8001FF50: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8001FF54: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8001FF58: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8001FF5C: jr          $ra
    // 0x8001FF60: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x8001FF60: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void itMBallWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C7D0: jal         0x80172E74
    // 0x8017C7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x8017C7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017C7D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C7DC: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017C7E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017C7E4: jal         0x80172EC8
    // 0x8017C7E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017C7E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017C7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C7F4: jr          $ra
    // 0x8017C7F8: nop

    return;
    // 0x8017C7F8: nop

;}
RECOMP_FUNC void ftCommonStarRodSwingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146CF4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80146CF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80146CFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80146D00: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80146D04: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80146D08: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x80146D0C: beq         $v0, $zero, L_80146D50
    if (ctx->r2 == 0) {
        // 0x80146D10: nop
    
            goto L_80146D50;
    }
    // 0x80146D10: nop

    // 0x80146D14: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
    // 0x80146D18: beq         $a1, $zero, L_80146D50
    if (ctx->r5 == 0) {
        // 0x80146D1C: nop
    
            goto L_80146D50;
    }
    // 0x80146D1C: nop

    // 0x80146D20: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80146D24: lhu         $t7, 0x33E($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X33E);
    // 0x80146D28: beq         $t7, $zero, L_80146D40
    if (ctx->r15 == 0) {
        // 0x80146D2C: nop
    
            goto L_80146D40;
    }
    // 0x80146D2C: nop

    // 0x80146D30: jal         0x800269C0
    // 0x80146D34: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80146D34: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x80146D38: b           L_80146D4C
    // 0x80146D3C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
        goto L_80146D4C;
    // 0x80146D3C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80146D40:
    // 0x80146D40: jal         0x800269C0
    // 0x80146D44: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80146D44: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_1:
    // 0x80146D48: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80146D4C:
    // 0x80146D4C: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
L_80146D50:
    // 0x80146D50: beq         $v0, $zero, L_80146E78
    if (ctx->r2 == 0) {
        // 0x80146D54: nop
    
            goto L_80146E78;
    }
    // 0x80146D54: nop

    // 0x80146D58: lw          $t8, 0x17C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X17C);
    // 0x80146D5C: beq         $t8, $zero, L_80146E78
    if (ctx->r24 == 0) {
        // 0x80146D60: nop
    
            goto L_80146E78;
    }
    // 0x80146D60: nop

    // 0x80146D64: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80146D68: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80146D6C: addiu       $t0, $t0, -0x7A00
    ctx->r8 = ADD32(ctx->r8, -0X7A00);
    // 0x80146D70: lhu         $t9, 0x33E($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X33E);
    // 0x80146D74: beq         $t9, $zero, L_80146E20
    if (ctx->r25 == 0) {
        // 0x80146D78: nop
    
            goto L_80146E20;
    }
    // 0x80146D78: nop

    // 0x80146D7C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80146D80: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80146D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80146D88: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80146D8C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80146D90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80146D94: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80146D98: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80146D9C: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x80146DA0: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x80146DA4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80146DA8: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80146DAC: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80146DB0: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80146DB4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80146DB8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80146DBC: nop

    // 0x80146DC0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80146DC4: nop

    // 0x80146DC8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80146DCC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80146DD0: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80146DD4: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80146DD8: lw          $t4, 0x9C8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X9C8);
    // 0x80146DDC: lw          $t5, 0x33C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X33C);
    // 0x80146DE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80146DE4: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80146DE8: jal         0x800EDF24
    // 0x80146DEC: lw          $a0, 0x8E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_2;
    // 0x80146DEC: lw          $a0, 0x8E8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8E8);
    after_2:
    // 0x80146DF0: lw          $t8, 0x17C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X17C);
    // 0x80146DF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80146DF8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80146DFC: bne         $t8, $at, L_80146E0C
    if (ctx->r24 != ctx->r1) {
        // 0x80146E00: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_80146E0C;
    }
    // 0x80146E00: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80146E04: b           L_80146E10
    // 0x80146E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80146E10;
    // 0x80146E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146E0C:
    // 0x80146E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80146E10:
    // 0x80146E10: jal         0x80178594
    // 0x80146E14: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    itStarRodMakeStar(rdram, ctx);
        goto after_3;
    // 0x80146E14: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x80146E18: b           L_80146E78
    // 0x80146E1C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
        goto L_80146E78;
    // 0x80146E1C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_80146E20:
    // 0x80146E20: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80146E24: addiu       $t9, $t9, -0x79F4
    ctx->r25 = ADD32(ctx->r25, -0X79F4);
    // 0x80146E28: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80146E2C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80146E30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80146E34: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80146E38: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80146E3C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80146E40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80146E44: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80146E48: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80146E4C: lw          $t2, 0x9C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X9C8);
    // 0x80146E50: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80146E54: lw          $a2, 0x33C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X33C);
    // 0x80146E58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80146E5C: lw          $t3, 0x44($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X44);
    // 0x80146E60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80146E64: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80146E68: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80146E6C: jal         0x800EABDC
    // 0x80146E70: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    ftParamMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80146E70: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_4:
    // 0x80146E74: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_80146E78:
    // 0x80146E78: jal         0x800D94C4
    // 0x80146E7C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    ftAnimEndSetWait(rdram, ctx);
        goto after_5;
    // 0x80146E7C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_5:
    // 0x80146E80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80146E84: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80146E88: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80146E8C: jr          $ra
    // 0x80146E90: nop

    return;
    // 0x80146E90: nop

;}
RECOMP_FUNC void itHarisenDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017539C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801753A0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801753A4: addiu       $a3, $a3, 0x51F4
    ctx->r7 = ADD32(ctx->r7, 0X51F4);
    // 0x801753A8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801753AC: jal         0x80173B24
    // 0x801753B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801753B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x801753B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801753B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801753BC: jr          $ra
    // 0x801753C0: nop

    return;
    // 0x801753C0: nop

;}
RECOMP_FUNC void syMatrixTraRotD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D3C4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001D3C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D3CC: lwc1        $f6, -0x1C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C30);
    // 0x8001D3D0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001D3D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D3D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D3DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001D3E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D3E4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D3E8: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001D3EC: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001D3F0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001D3F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D3F8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D3FC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001D400: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D404: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D408: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001D40C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D410: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8001D414: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8001D418: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8001D41C: jal         0x8001BC44
    // 0x8001D420: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syMatrixTraRotRF(rdram, ctx);
        goto after_0;
    // 0x8001D420: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8001D424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D428: jal         0x80019EA0
    // 0x8001D42C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D42C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001D430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D434: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001D438: jr          $ra
    // 0x8001D43C: nop

    return;
    // 0x8001D43C: nop

;}

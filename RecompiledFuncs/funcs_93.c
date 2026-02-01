#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void dbBattleGetFighterKindsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131D78: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80131D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131D80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131D84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_80131D88:
    // 0x80131D88: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80131D8C: beq         $t6, $zero, L_80131D98
    if (ctx->r14 == 0) {
        // 0x80131D90: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80131D98;
    }
    // 0x80131D90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80131D94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131D98:
    // 0x80131D98: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131D9C: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131DA0: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80131DA4: beq         $t7, $zero, L_80131DB0
    if (ctx->r15 == 0) {
        // 0x80131DA8: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80131DB0;
    }
    // 0x80131DA8: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131DAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131DB0:
    // 0x80131DB0: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131DB4: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80131DB8: beq         $t8, $zero, L_80131DC4
    if (ctx->r24 == 0) {
        // 0x80131DBC: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80131DC4;
    }
    // 0x80131DBC: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131DC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131DC4:
    // 0x80131DC4: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131DC8: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x80131DCC: beq         $t9, $zero, L_80131DD8
    if (ctx->r25 == 0) {
        // 0x80131DD0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80131DD8;
    }
    // 0x80131DD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80131DD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131DD8:
    // 0x80131DD8: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131DDC: bne         $v0, $a2, L_80131D88
    if (ctx->r2 != ctx->r6) {
        // 0x80131DE0: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80131D88;
    }
    // 0x80131DE0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80131DE4: jr          $ra
    // 0x80131DE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131DE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnVSModeMakeButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132028: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013202C: lw          $t6, 0x4A48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4A48);
    // 0x80132030: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132038: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013203C: addiu       $t7, $t7, 0x1E8
    ctx->r15 = ADD32(ctx->r15, 0X1E8);
    // 0x80132040: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132044: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80132048: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8013204C: jal         0x800CCFDC
    // 0x80132050: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132050: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132054: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132058: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013205C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132060: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132064: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132068: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8013206C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132070: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80132074: addiu       $t3, $t3, 0x330
    ctx->r11 = ADD32(ctx->r11, 0X330);
    // 0x80132078: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013207C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80132080: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132084: lw          $t2, 0x4A48($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4A48);
    // 0x80132088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013208C: jal         0x800CCFDC
    // 0x80132090: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132090: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80132094: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80132098: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8013209C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801320A0: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x801320A4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801320A8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x801320AC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801320B0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801320B4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801320B8: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x801320BC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801320C0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801320C4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801320C8: addiu       $t1, $t1, 0x568
    ctx->r9 = ADD32(ctx->r9, 0X568);
    // 0x801320CC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x801320D0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801320D4: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x801320D8: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x801320DC: sb          $t8, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r24;
    // 0x801320E0: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x801320E4: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x801320E8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x801320EC: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x801320F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x801320F4: sh          $v1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r3;
    // 0x801320F8: lw          $t0, 0x4A48($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4A48);
    // 0x801320FC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80132100: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80132104: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80132108: jal         0x800CCFDC
    // 0x8013210C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013210C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x80132110: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80132114: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80132118: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x8013211C: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80132120: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132124: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132128: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013212C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132130: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132134: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80132138: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8013213C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80132140: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013214C: jr          $ra
    // 0x80132150: nop

    return;
    // 0x80132150: nop

;}
RECOMP_FUNC void ftKirbySpecialHiLandingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160D40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160D48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80160D4C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160D50: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x80160D54: beq         $t7, $zero, L_80160DD0
    if (ctx->r15 == 0) {
        // 0x80160D58: nop
    
            goto L_80160DD0;
    }
    // 0x80160D58: nop

    // 0x80160D5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80160D60: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80160D64: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80160D68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80160D6C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80160D70: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80160D74: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x80160D78: jal         0x800EDF24
    // 0x80160D7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80160D7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80160D80: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80160D84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80160D88: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80160D8C: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80160D90: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80160D94: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80160D98: bne         $t8, $at, L_80160DB4
    if (ctx->r24 != ctx->r1) {
        // 0x80160D9C: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80160DB4;
    }
    // 0x80160D9C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80160DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80160DA4: nop

    // 0x80160DA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80160DAC: b           L_80160DC8
    // 0x80160DB0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
        goto L_80160DC8;
    // 0x80160DB0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
L_80160DB4:
    // 0x80160DB4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80160DB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80160DBC: nop

    // 0x80160DC0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80160DC4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
L_80160DC8:
    // 0x80160DC8: jal         0x8016BE8C
    // 0x80160DCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    wpKirbyCutterMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80160DCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
L_80160DD0:
    // 0x80160DD0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80160DD4: addiu       $a1, $a1, -0x1E38
    ctx->r5 = ADD32(ctx->r5, -0X1E38);
    // 0x80160DD8: jal         0x800D9480
    // 0x80160DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x80160DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80160DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80160DE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160DE8: jr          $ra
    // 0x80160DEC: nop

    return;
    // 0x80160DEC: nop

;}
RECOMP_FUNC void sc1PManagerGetShuffledFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6508: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D650C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800D6510: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D6514: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800D6518: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800D651C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D6520: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D6524:
    // 0x800D6524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6528: sllv        $a0, $t6, $v1
    ctx->r4 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x800D652C: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x800D6530: beq         $t7, $zero, L_800D6544
    if (ctx->r15 == 0) {
        // 0x800D6534: and         $t8, $a1, $a0
        ctx->r24 = ctx->r5 & ctx->r4;
            goto L_800D6544;
    }
    // 0x800D6534: and         $t8, $a1, $a0
    ctx->r24 = ctx->r5 & ctx->r4;
    // 0x800D6538: bne         $t8, $zero, L_800D6544
    if (ctx->r24 != 0) {
        // 0x800D653C: nop
    
            goto L_800D6544;
    }
    // 0x800D653C: nop

    // 0x800D6540: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800D6544:
    // 0x800D6544: bnel        $a2, $zero, L_800D6524
    if (ctx->r6 != 0) {
        // 0x800D6548: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D6524;
    }
    goto skip_0;
    // 0x800D6548: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800D654C: jr          $ra
    // 0x800D6550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D6550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl3_801436F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801436F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801436F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801436F8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801436FC: addiu       $t6, $zero, 0x108
    ctx->r14 = ADD32(0, 0X108);
    // 0x80143700: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80143704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80143708: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8014370C: jal         0x800E6F24
    // 0x80143710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80143710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80143714: jal         0x80143630
    // 0x80143718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDamageFallClampRumble(rdram, ctx);
        goto after_1;
    // 0x80143718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8014371C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143724: jr          $ra
    // 0x80143728: nop

    return;
    // 0x80143728: nop

;}
RECOMP_FUNC void wpDisplayDObjDLLinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801675F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801675F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801675FC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80167600: jal         0x80167520
    // 0x80167604: addiu       $a1, $a1, 0x43FC
    ctx->r5 = ADD32(ctx->r5, 0X43FC);
    wpDisplayMain(rdram, ctx);
        goto after_0;
    // 0x80167604: addiu       $a1, $a1, 0x43FC
    ctx->r5 = ADD32(ctx->r5, 0X43FC);
    after_0:
    // 0x80167608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016760C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167610: jr          $ra
    // 0x80167614: nop

    return;
    // 0x80167614: nop

;}
RECOMP_FUNC void mpCommonRunWeaponCollisionDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF09C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DF0A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF0A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DF0A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DF0AC: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    // 0x800DF0B0: jal         0x800DEFBC
    // 0x800DF0B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCopyCollDataStats(rdram, ctx);
        goto after_0;
    // 0x800DF0B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DF0B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DF0BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800DF0C0: jal         0x800DEEF4
    // 0x800DF0C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mpCommonRunDefaultCollision(rdram, ctx);
        goto after_1;
    // 0x800DF0C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800DF0C8: jal         0x800DEFF8
    // 0x800DF0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonResetCollDataStats(rdram, ctx);
        goto after_2;
    // 0x800DF0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800DF0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF0D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DF0D8: jr          $ra
    // 0x800DF0DC: nop

    return;
    // 0x800DF0DC: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161B70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161B78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161B7C: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80161B80: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    // 0x80161B84: lw          $t6, 0x190($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X190);
    // 0x80161B88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161B8C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80161B90: sll         $t7, $t6, 10
    ctx->r15 = S32(ctx->r14 << 10);
    // 0x80161B94: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80161B98: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80161B9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161BA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161BA4: jal         0x800E6F24
    // 0x80161BA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161BA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80161BAC: jal         0x800E0830
    // 0x80161BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161BB4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80161BB8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80161BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80161BC0: lbu         $t2, 0x191($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X191);
    // 0x80161BC4: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80161BC8: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80161BCC: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x80161BD0: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x80161BD4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80161BD8: beq         $v1, $zero, L_80161BEC
    if (ctx->r3 == 0) {
        // 0x80161BDC: sb          $t4, 0x191($v0)
        MEM_B(0X191, ctx->r2) = ctx->r12;
            goto L_80161BEC;
    }
    // 0x80161BDC: sb          $t4, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r12;
    // 0x80161BE0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80161BE4: b           L_80161BF4
    // 0x80161BE8: sw          $t5, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r13;
        goto L_80161BF4;
    // 0x80161BE8: sw          $t5, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r13;
L_80161BEC:
    // 0x80161BEC: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80161BF0: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
L_80161BF4:
    // 0x80161BF4: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80161BF8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80161BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161C00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161C04: jr          $ra
    // 0x80161C08: nop

    return;
    // 0x80161C08: nop

;}
RECOMP_FUNC void ftCommonCliffCommon2InitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014557C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80145580: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x80145584: bne         $t6, $zero, L_80145598
    if (ctx->r14 != 0) {
        // 0x80145588: nop
    
            goto L_80145598;
    }
    // 0x80145588: nop

    // 0x8014558C: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
    // 0x80145590: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80145594: sb          $t9, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r25;
L_80145598:
    // 0x80145598: jr          $ra
    // 0x8014559C: nop

    return;
    // 0x8014559C: nop

;}
RECOMP_FUNC void mnDataMakeLink3Camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132538: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013253C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132540: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132544: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80132548: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013254C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80132550: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132554: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132558: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013255C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132560: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132564: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132568: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013256C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132570: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132574: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132578: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013257C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132580: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132584: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013258C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132590: jal         0x8000B93C
    // 0x80132594: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132594: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132598: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013259C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801325A0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801325A4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801325A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801325B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801325B4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801325B8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801325BC: jal         0x80007080
    // 0x801325C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801325C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801325C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801325C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801325CC: jr          $ra
    // 0x801325D0: nop

    return;
    // 0x801325D0: nop

;}
RECOMP_FUNC void func_ovl52_80131C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C30: jr          $ra
    // 0x80131C34: nop

    return;
    // 0x80131C34: nop

;}
RECOMP_FUNC void grHyruleTwisterUpdateStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A824: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8010A828: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x8010A82C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A834: beq         $v0, $zero, L_8010A858
    if (ctx->r2 == 0) {
        // 0x8010A838: addiu       $a0, $zero, 0x3C
        ctx->r4 = ADD32(0, 0X3C);
            goto L_8010A858;
    }
    // 0x8010A838: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x8010A83C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_8010A840:
    // 0x8010A840: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x8010A844: beql        $a0, $t6, L_8010A8A8
    if (ctx->r4 == ctx->r14) {
        // 0x8010A848: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010A8A8;
    }
    goto skip_0;
    // 0x8010A848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010A84C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8010A850: bnel        $v0, $zero, L_8010A840
    if (ctx->r2 != 0) {
        // 0x8010A854: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_8010A840;
    }
    goto skip_1;
    // 0x8010A854: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_1:
L_8010A858:
    // 0x8010A858: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010A85C: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010A860: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8010A864: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8010A868: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x8010A86C: sh          $t8, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r24;
    // 0x8010A870: jal         0x800E1D9C
    // 0x8010A874: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    ftMainClearGroundObstacle(rdram, ctx);
        goto after_0;
    // 0x8010A874: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x8010A878: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010A87C: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010A880: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8010A884: beq         $v1, $zero, L_8010A89C
    if (ctx->r3 == 0) {
        // 0x8010A888: addiu       $a0, $v1, 0x4
        ctx->r4 = ADD32(ctx->r3, 0X4);
            goto L_8010A89C;
    }
    // 0x8010A888: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x8010A88C: jal         0x8010A140
    // 0x8010A890: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    grHyruleTwisterMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8010A890: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x8010A894: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010A898: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
L_8010A89C:
    // 0x8010A89C: jal         0x80009A84
    // 0x8010A8A0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8010A8A0: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_2:
    // 0x8010A8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A8A8:
    // 0x8010A8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A8AC: jr          $ra
    // 0x8010A8B0: nop

    return;
    // 0x8010A8B0: nop

;}
RECOMP_FUNC void ftCommonTwisterProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143A20: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80143A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80143A28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80143A2C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80143A30: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80143A34: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x80143A38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80143A3C: lw          $v0, 0xB1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB1C);
    // 0x80143A40: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80143A44: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x80143A48: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80143A4C: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x80143A50: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80143A54: lw          $t0, 0x24($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X24);
    // 0x80143A58: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x80143A5C: lw          $t1, 0xB18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB18);
    // 0x80143A60: lwc1        $f8, -0x3ED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3ED0);
    // 0x80143A64: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80143A68: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80143A6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80143A70: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80143A74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80143A78: lwc1        $f18, -0x3ECC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3ECC);
    // 0x80143A7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80143A80: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80143A84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80143A88: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80143A8C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80143A90: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80143A94: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80143A98: jal         0x800C78B8
    // 0x80143A9C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    lbCommonCos(rdram, ctx);
        goto after_0;
    // 0x80143A9C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80143AA0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80143AA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80143AA8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80143AAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80143AB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80143AB4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80143AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80143ABC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80143AC0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80143AC4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80143AC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80143ACC: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80143AD0: nop

    // 0x80143AD4: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80143AD8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80143ADC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80143AE0: jal         0x800C7840
    // 0x80143AE4: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    lbCommonSin(rdram, ctx);
        goto after_1;
    // 0x80143AE4: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80143AE8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80143AEC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80143AF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80143AF4: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80143AF8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80143AFC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80143B00: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80143B04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80143B08: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80143B0C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80143B10: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80143B14: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80143B18: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80143B1C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80143B20: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80143B24: lw          $a2, 0x74($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X74);
    // 0x80143B28: jal         0x8001902C
    // 0x80143B2C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_2;
    // 0x80143B2C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_2:
    // 0x80143B30: jal         0x80018F7C
    // 0x80143B34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    syVectorMag3D(rdram, ctx);
        goto after_3;
    // 0x80143B34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80143B38: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80143B3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80143B40: nop

    // 0x80143B44: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80143B48: nop

    // 0x80143B4C: bc1fl       L_80143B6C
    if (!c1cs) {
        // 0x80143B50: addiu       $t3, $sp, 0x40
        ctx->r11 = ADD32(ctx->r29, 0X40);
            goto L_80143B6C;
    }
    goto skip_0;
    // 0x80143B50: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    skip_0:
    // 0x80143B54: div.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80143B58: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80143B5C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80143B60: jal         0x800190B0
    // 0x80143B64: nop

    syVectorScale3D(rdram, ctx);
        goto after_4;
    // 0x80143B64: nop

    after_4:
    // 0x80143B68: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
L_80143B6C:
    // 0x80143B6C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80143B70: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x80143B74: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80143B78: sw          $t5, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r13;
    // 0x80143B7C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80143B80: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80143B84: sw          $t4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r12;
    // 0x80143B88: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80143B8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80143B90: sw          $t5, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r13;
    // 0x80143B94: lwc1        $f18, -0x3EC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3EC8);
    // 0x80143B98: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80143B9C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80143BA0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80143BA4: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80143BA8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80143BAC: swc1        $f6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f6.u32l;
    // 0x80143BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143BB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80143BB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80143BBC: jr          $ra
    // 0x80143BC0: nop

    return;
    // 0x80143BC0: nop

;}
RECOMP_FUNC void ftCommonHammerTurnUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147A78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80147A7C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80147A80: lw          $v1, 0x180($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X180);
    // 0x80147A84: beq         $v1, $zero, L_80147AC0
    if (ctx->r3 == 0) {
        // 0x80147A88: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80147AC0;
    }
    // 0x80147A88: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80147A8C: bne         $t6, $at, L_80147AA0
    if (ctx->r14 != ctx->r1) {
        // 0x80147A90: sw          $t6, 0x180($v0)
        MEM_W(0X180, ctx->r2) = ctx->r14;
            goto L_80147AA0;
    }
    // 0x80147A90: sw          $t6, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r14;
    // 0x80147A94: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80147A98: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80147A9C: sw          $t9, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r25;
L_80147AA0:
    // 0x80147AA0: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x80147AA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80147AA8: lwc1        $f6, -0x3E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3E30);
    // 0x80147AAC: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80147AB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80147AB4: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
    // 0x80147AB8: jal         0x800EB528
    // 0x80147ABC: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x80147ABC: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_0:
L_80147AC0:
    // 0x80147AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147AC8: jr          $ra
    // 0x80147ACC: nop

    return;
    // 0x80147ACC: nop

;}
RECOMP_FUNC void itSpearCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801801D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801801DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801801E0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801801E4: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x801801E8: jal         0x801737B8
    // 0x801801EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x801801EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801801F0: beq         $v0, $zero, L_80180204
    if (ctx->r2 == 0) {
        // 0x801801F4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80180204;
    }
    // 0x801801F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801801F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801801FC: nop

    // 0x80180200: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_80180204:
    // 0x80180204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180210: jr          $ra
    // 0x80180214: nop

    return;
    // 0x80180214: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateControllerOrders(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A2A4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8013A2A8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8013A2AC: lb          $a1, 0x51A4($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X51A4);
    // 0x8013A2B0: addiu       $v1, $v1, -0x4270
    ctx->r3 = ADD32(ctx->r3, -0X4270);
    // 0x8013A2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013A2B8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8013A2BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8013A2C0:
    // 0x8013A2C0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8013A2C4: beq         $t0, $a1, L_8013A2F8
    if (ctx->r8 == ctx->r5) {
        // 0x8013A2C8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8013A2F8;
    }
    // 0x8013A2C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013A2CC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8013A2D0: addiu       $a2, $t6, 0x51A4
    ctx->r6 = ADD32(ctx->r14, 0X51A4);
    // 0x8013A2D4: lb          $a3, 0x0($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X0);
L_8013A2D8:
    // 0x8013A2D8: bnel        $v0, $a3, L_8013A2E8
    if (ctx->r2 != ctx->r7) {
        // 0x8013A2DC: lb          $a3, 0x1($a2)
        ctx->r7 = MEM_B(ctx->r6, 0X1);
            goto L_8013A2E8;
    }
    goto skip_0;
    // 0x8013A2DC: lb          $a3, 0x1($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X1);
    skip_0:
    // 0x8013A2E0: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8013A2E4: lb          $a3, 0x1($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X1);
L_8013A2E8:
    // 0x8013A2E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8013A2EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013A2F0: bne         $t0, $a3, L_8013A2D8
    if (ctx->r8 != ctx->r7) {
        // 0x8013A2F4: nop
    
            goto L_8013A2D8;
    }
    // 0x8013A2F4: nop

L_8013A2F8:
    // 0x8013A2F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013A2FC: bne         $v0, $t1, L_8013A2C0
    if (ctx->r2 != ctx->r9) {
        // 0x8013A300: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8013A2C0;
    }
    // 0x8013A300: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8013A304: jr          $ra
    // 0x8013A308: nop

    return;
    // 0x8013A308: nop

;}
RECOMP_FUNC void ftCommonDamageFallClampRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143638: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014363C: jal         0x800D8EB8
    // 0x80143640: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_0;
    // 0x80143640: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80143644: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80143648: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014364C: jal         0x800E806C
    // 0x80143650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_1;
    // 0x80143650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80143654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143658: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014365C: jr          $ra
    // 0x80143660: nop

    return;
    // 0x80143660: nop

;}
RECOMP_FUNC void func_ovl147_80132424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132424: jr          $ra
    // 0x80132428: nop

    return;
    // 0x80132428: nop

;}
RECOMP_FUNC void ftKirbySpecialNCatchEatSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801630A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801630A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801630A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801630AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801630B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801630B4: addiu       $t6, $zero, 0x864
    ctx->r14 = ADD32(0, 0X864);
    // 0x801630B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801630BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801630C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801630C4: jal         0x800E6F24
    // 0x801630C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801630C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801630CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801630D0: jal         0x800E8098
    // 0x801630D4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801630D4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x801630D8: lbu         $t8, 0x192($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X192);
    // 0x801630DC: lw          $v0, 0x9E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9E8);
    // 0x801630E0: lw          $t7, 0x830($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X830);
    // 0x801630E4: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x801630E8: sb          $t9, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r25;
    // 0x801630EC: beq         $v0, $zero, L_801630FC
    if (ctx->r2 == 0) {
        // 0x801630F0: sw          $t7, 0x840($s0)
        MEM_W(0X840, ctx->r16) = ctx->r15;
            goto L_801630FC;
    }
    // 0x801630F0: sw          $t7, 0x840($s0)
    MEM_W(0X840, ctx->r16) = ctx->r15;
    // 0x801630F4: jalr        $v0
    // 0x801630F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x801630F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_801630FC:
    // 0x801630FC: jal         0x800E0830
    // 0x80163100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x80163100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80163104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80163108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8016310C: jal         0x80161DA8
    // 0x80163110: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftKirbySpecialNAddCaptureDistance(rdram, ctx);
        goto after_4;
    // 0x80163110: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80163114: lw          $v0, 0x840($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X840);
    // 0x80163118: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8016311C: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x80163120: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80163124: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80163128: swc1        $f8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f8.u32l;
    // 0x8016312C: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80163130: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80163134: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80163138: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8016313C: swc1        $f18, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f18.u32l;
    // 0x80163140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80163144: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80163148: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8016314C: jr          $ra
    // 0x80163150: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80163150: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayers1PBonusMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135EE8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80135EEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80135EF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80135EF4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80135EF8: addiu       $t7, $t7, 0x74C0
    ctx->r15 = ADD32(ctx->r15, 0X74C0);
    // 0x80135EFC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135F00: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135F04: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80135F08: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135F0C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135F10: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80135F14: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80135F18: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80135F1C: addiu       $t0, $t0, 0x74D0
    ctx->r8 = ADD32(ctx->r8, 0X74D0);
    // 0x80135F20: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135F24: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135F28: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80135F2C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80135F30: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80135F34: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80135F38: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80135F3C: addiu       $t3, $t3, -0x3100
    ctx->r11 = ADD32(ctx->r11, -0X3100);
    // 0x80135F40: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80135F44: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80135F48: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80135F4C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80135F50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135F54: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80135F58: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80135F5C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80135F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135F64: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x80135F68: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80135F6C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80135F70: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80135F74: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80135F78: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80135F7C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80135F80: lw          $t0, 0x7DF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DF8);
    // 0x80135F84: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80135F88: addiu       $t1, $t1, 0x76E8
    ctx->r9 = ADD32(ctx->r9, 0X76E8);
    // 0x80135F8C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80135F90: addiu       $t4, $t4, 0x5950
    ctx->r12 = ADD32(ctx->r12, 0X5950);
    // 0x80135F94: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80135F98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80135F9C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80135FA0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80135FA4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80135FA8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80135FAC: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80135FB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135FB4: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80135FB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80135FBC: jal         0x800CD050
    // 0x80135FC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80135FC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80135FC4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80135FC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135FCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135FD0: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x80135FD4: sw          $v0, 0x7648($at)
    MEM_W(0X7648, ctx->r1) = ctx->r2;
    // 0x80135FD8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80135FDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135FE0: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80135FE4: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80135FE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135FEC: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x80135FF0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80135FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80135FF8: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x80135FFC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136000: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80136004: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80136008: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x8013600C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136010: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x80136014: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80136018: jal         0x80134364
    // 0x8013601C: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x8013601C: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    after_1:
    // 0x80136020: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80136024: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136028: sw          $zero, 0x7674($at)
    MEM_W(0X7674, ctx->r1) = 0;
    // 0x8013602C: jr          $ra
    // 0x80136030: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80136030: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_8037F260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037F264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F26C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037F270: beq         $a0, $zero, L_8037F2E8
    if (ctx->r4 == 0) {
        // 0x8037F274: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037F2E8;
    }
    // 0x8037F274: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037F278: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037F27C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037F280: addiu       $t6, $t6, -0x5490
    ctx->r14 = ADD32(ctx->r14, -0X5490);
    // 0x8037F284: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037F288: addiu       $t7, $t7, -0x53B8
    ctx->r15 = ADD32(ctx->r15, -0X53B8);
    // 0x8037F28C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037F290: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037F294: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037F298: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037F29C: addiu       $t9, $t9, -0x5260
    ctx->r25 = ADD32(ctx->r25, -0X5260);
    // 0x8037F2A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037F2A4: jal         0x80373D88
    // 0x8037F2A8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80373D88(rdram, ctx);
        goto after_0;
    // 0x8037F2A8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x8037F2AC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8037F2B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037F2B4: beql        $t1, $zero, L_8037F2D4
    if (ctx->r9 == 0) {
        // 0x8037F2B8: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8037F2D4;
    }
    goto skip_0;
    // 0x8037F2B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037F2BC: jal         0x8037C30C
    // 0x8037F2C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x8037F2C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x8037F2C4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037F2C8: jal         0x803718C4
    // 0x8037F2CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x8037F2CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8037F2D0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8037F2D4:
    // 0x8037F2D4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8037F2D8: beql        $t3, $zero, L_8037F2EC
    if (ctx->r11 == 0) {
        // 0x8037F2DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037F2EC;
    }
    goto skip_1;
    // 0x8037F2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037F2E0: jal         0x803717C0
    // 0x8037F2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x8037F2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8037F2E8:
    // 0x8037F2E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037F2EC:
    // 0x8037F2EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F2F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037F2F4: jr          $ra
    // 0x8037F2F8: nop

    return;
    // 0x8037F2F8: nop

;}
RECOMP_FUNC void mvOpeningYoshiMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D61C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D620: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D624: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D628: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D62C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D630: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D634: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D638: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D63C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D640: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D644: jal         0x80104BDC
    // 0x8018D648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D64C: jal         0x80105600
    // 0x8018D650: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D650: nop

    after_1:
    // 0x8018D654: jal         0x800FC7A4
    // 0x8018D658: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D658: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D65C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D660: beq         $v0, $at, L_8018D688
    if (ctx->r2 == ctx->r1) {
        // 0x8018D664: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D688;
    }
    // 0x8018D664: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D668: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D66C: addiu       $s0, $s0, -0x1E10
    ctx->r16 = ADD32(ctx->r16, -0X1E10);
L_8018D670:
    // 0x8018D670: jal         0x80023624
    // 0x8018D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D678: jal         0x800A3040
    // 0x8018D67C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D67C: nop

    after_4:
    // 0x8018D680: b           L_8018D670
    // 0x8018D684: nop

        goto L_8018D670;
    // 0x8018D684: nop

L_8018D688:
    // 0x8018D688: jal         0x800FC814
    // 0x8018D68C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D68C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D690: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D694: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D698: jal         0x800FC894
    // 0x8018D69C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D69C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D6A0: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8018D6A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D6A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8018D6AC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D6B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D6B4: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D6B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D6BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D6C0: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x8018D6C4: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x8018D6C8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6CC: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D6D0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D6D4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D6D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D6DC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6E0: jal         0x8018D40C
    // 0x8018D6E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningYoshiMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6E8: jal         0x801156E4
    // 0x8018D6EC: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6EC: nop

    after_8:
    // 0x8018D6F0: jal         0x801653E0
    // 0x8018D6F4: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6F4: nop

    after_9:
    // 0x8018D6F8: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6FC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D700: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D704: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D708: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D70C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D710: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D714: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D718: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D71C:
    // 0x8018D71C: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D720: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D724: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D728:
    // 0x8018D728: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D72C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D730: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D734: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D738: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D73C: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D740: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D744: bne         $t0, $t2, L_8018D728
    if (ctx->r8 != ctx->r10) {
        // 0x8018D748: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D728;
    }
    // 0x8018D748: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D74C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D750: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D754: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D758: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D75C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D760: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D764: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D768: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D76C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D770: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D774: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D778: beql        $s7, $t4, L_8018D83C
    if (ctx->r23 == ctx->r12) {
        // 0x8018D77C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D83C;
    }
    goto skip_0;
    // 0x8018D77C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D780: jal         0x800D786C
    // 0x8018D784: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D784: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D788: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D78C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D790: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D794: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D798: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D79C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D7A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D7A4: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D7A8: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8018D7AC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018D7B0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D7B4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D7B8: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D7BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D7C0: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D7C4: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D7C8: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D7CC: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D7D0: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D7D4: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D7D8: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D7DC: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7E0: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D7E4: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7E8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D7EC: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7F0: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7F4: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7F8: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7FC: jal         0x800D78B4
    // 0x8018D800: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D800: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D804: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D808: jal         0x800D7F3C
    // 0x8018D80C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D80C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D810: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D814: sw          $v0, -0x1DD0($at)
    MEM_W(-0X1DD0, ctx->r1) = ctx->r2;
    // 0x8018D818: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D81C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D820: jal         0x800E7C4C
    // 0x8018D824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D828: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D82C: addiu       $a1, $a1, -0x1F08
    ctx->r5 = ADD32(ctx->r5, -0X1F08);
    // 0x8018D830: jal         0x800E9B30
    // 0x8018D834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D838: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D83C:
    // 0x8018D83C: bne         $s1, $fp, L_8018D71C
    if (ctx->r17 != ctx->r30) {
        // 0x8018D840: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D71C;
    }
    // 0x8018D840: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D844: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D848: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D84C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D850: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D854: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D858: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D85C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D860: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D864: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D868: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D86C: jr          $ra
    // 0x8018D870: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D870: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void mnPlayers1PGameGetTotalBonusCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134CB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134CBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134CC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134CC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134CC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134CCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80134CD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80134CD4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80134CD8:
    // 0x80134CD8: jal         0x80134968
    // 0x80134CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetBonusCount(rdram, ctx);
        goto after_0;
    // 0x80134CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80134CE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80134CE4: bne         $s0, $s2, L_80134CD8
    if (ctx->r16 != ctx->r18) {
        // 0x80134CE8: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_80134CD8;
    }
    // 0x80134CE8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80134CEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134CF0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80134CF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134CF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134CFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134D00: jr          $ra
    // 0x80134D04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80134D04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void grYamabukiMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B2EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B2F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B2F4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010B2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010B2FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B300: jal         0x80009968
    // 0x8010B304: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010B304: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010B308: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010B30C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8010B310: addiu       $a1, $a1, -0x4ED0
    ctx->r5 = ADD32(ctx->r5, -0X4ED0);
    // 0x8010B314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010B318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B31C: jal         0x80008188
    // 0x8010B320: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8010B320: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010B324: jal         0x8010B250
    // 0x8010B328: nop

    grYamabukiInitGroundVars(rdram, ctx);
        goto after_2;
    // 0x8010B328: nop

    after_2:
    // 0x8010B32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B330: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010B338: jr          $ra
    // 0x8010B33C: nop

    return;
    // 0x8010B33C: nop

;}
RECOMP_FUNC void grCastleMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B4B4: jal         0x8010B378
    // 0x8010B4B8: nop

    grCastleInitAll(rdram, ctx);
        goto after_0;
    // 0x8010B4B8: nop

    after_0:
    // 0x8010B4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B4C8: jr          $ra
    // 0x8010B4CC: nop

    return;
    // 0x8010B4CC: nop

;}
RECOMP_FUNC void gcRemoveAObjFromDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008EE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008EEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80008EF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80008EF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80008EF8: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x80008EFC: beql        $s0, $zero, L_80008F1C
    if (ctx->r16 == 0) {
        // 0x80008F00: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80008F1C;
    }
    goto skip_0;
    // 0x80008F00: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_80008F04:
    // 0x80008F04: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80008F08: jal         0x80007EB0
    // 0x80008F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x80008F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80008F10: bne         $s1, $zero, L_80008F04
    if (ctx->r17 != 0) {
        // 0x80008F14: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80008F04;
    }
    // 0x80008F14: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80008F18: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80008F1C:
    // 0x80008F1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80008F20: sw          $zero, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = 0;
    // 0x80008F24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80008F28: lwc1        $f4, -0x229C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X229C);
    // 0x80008F2C: swc1        $f4, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f4.u32l;
    // 0x80008F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008F34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80008F38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80008F3C: jr          $ra
    // 0x80008F40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80008F40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801537DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801537E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801537E4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801537E8: jal         0x800DE6E4
    // 0x801537EC: addiu       $a1, $a1, 0x3800
    ctx->r5 = ADD32(ctx->r5, 0X3800);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801537EC: addiu       $a1, $a1, 0x3800
    ctx->r5 = ADD32(ctx->r5, 0X3800);
    after_0:
    // 0x801537F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801537F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801537F8: jr          $ra
    // 0x801537FC: nop

    return;
    // 0x801537FC: nop

;}
RECOMP_FUNC void itManagerGetCurrentAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EB00: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8016EB04: jr          $ra
    // 0x8016EB08: lw          $v0, -0x2F6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F6C);
    return;
    // 0x8016EB08: lw          $v0, -0x2F6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F6C);
;}
RECOMP_FUNC void func_ovl8_80371ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371ACC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80371AD0: jr          $ra
    // 0x80371AD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80371AD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void sc1PGameTeamStockDisplayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018EBBC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018EBC0: lbu         $v1, 0x2FA1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2FA1);
    // 0x8018EBC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EBC8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8018EBCC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018EBD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018EBD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018EBD8: beq         $v1, $zero, L_8018EE28
    if (ctx->r3 == 0) {
        // 0x8018EBDC: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8018EE28;
    }
    // 0x8018EBDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018EBE0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EBE4: addiu       $a1, $a1, 0x38C8
    ctx->r5 = ADD32(ctx->r5, 0X38C8);
    // 0x8018EBE8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8018EBEC: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018EBF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018EBF4: beq         $t6, $v1, L_8018EE20
    if (ctx->r14 == ctx->r3) {
        // 0x8018EBF8: nop
    
            goto L_8018EE20;
    }
    // 0x8018EBF8: nop

    // 0x8018EBFC: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8018EC00: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018EC04: lbu         $a2, 0x2FA0($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X2FA0);
    // 0x8018EC08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018EC0C: beq         $v0, $zero, L_8018EE20
    if (ctx->r2 == 0) {
        // 0x8018EC10: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8018EE20;
    }
    // 0x8018EC10: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8018EC14: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x8018EC18: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018EC1C: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x8018EC20: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018EC24: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018EC28: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018EC2C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EC30: addiu       $a1, $a1, 0x38CC
    ctx->r5 = ADD32(ctx->r5, 0X38CC);
    // 0x8018EC34: addiu       $t1, $t1, 0x2FA4
    ctx->r9 = ADD32(ctx->r9, 0X2FA4);
    // 0x8018EC38: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
    // 0x8018EC3C: addiu       $s0, $s0, 0x3064
    ctx->r16 = ADD32(ctx->r16, 0X3064);
    // 0x8018EC40: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8018EC44: addiu       $s2, $s2, 0x3060
    ctx->r18 = ADD32(ctx->r18, 0X3060);
    // 0x8018EC48: addiu       $s3, $s3, 0x2FB0
    ctx->r19 = ADD32(ctx->r19, 0X2FB0);
    // 0x8018EC4C: addiu       $ra, $zero, -0x5
    ctx->r31 = ADD32(0, -0X5);
    // 0x8018EC50: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8018EC54: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8018EC58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018EC5C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8018EC60: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
L_8018EC64:
    // 0x8018EC64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018EC68: sllv        $t9, $t8, $a2
    ctx->r25 = S32(ctx->r24 << (ctx->r6 & 31));
    // 0x8018EC6C: and         $t7, $t9, $t6
    ctx->r15 = ctx->r25 & ctx->r14;
    // 0x8018EC70: beq         $t7, $zero, L_8018EC88
    if (ctx->r15 == 0) {
        // 0x8018EC74: nop
    
            goto L_8018EC88;
    }
    // 0x8018EC74: nop

    // 0x8018EC78: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018EC7C: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8018EC80: b           L_8018EE10
    // 0x8018EC84: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
        goto L_8018EE10;
    // 0x8018EC84: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
L_8018EC88:
    // 0x8018EC88: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018EC8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8018EC90: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8018EC94: mflo        $t6
    ctx->r14 = lo;
    // 0x8018EC98: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x8018EC9C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018ECA0: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018ECA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018ECA8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018ECAC: mflo        $t8
    ctx->r24 = lo;
    // 0x8018ECB0: addiu       $t9, $t8, 0x14
    ctx->r25 = ADD32(ctx->r24, 0X14);
    // 0x8018ECB4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8018ECB8: nop

    // 0x8018ECBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018ECC0: bne         $at, $zero, L_8018ECD0
    if (ctx->r1 != 0) {
        // 0x8018ECC4: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_8018ECD0;
    }
    // 0x8018ECC4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8018ECC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018ECCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8018ECD0:
    // 0x8018ECD0: lbu         $v1, 0x17($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X17);
    // 0x8018ECD4: beql        $v1, $t3, L_8018ECF8
    if (ctx->r3 == ctx->r11) {
        // 0x8018ECD8: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_8018ECF8;
    }
    goto skip_0;
    // 0x8018ECD8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x8018ECDC: beql        $v1, $t4, L_8018ED60
    if (ctx->r3 == ctx->r12) {
        // 0x8018ECE0: lw          $t6, 0x0($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X0);
            goto L_8018ED60;
    }
    goto skip_1;
    // 0x8018ECE0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x8018ECE4: beql        $v1, $t5, L_8018EDC4
    if (ctx->r3 == ctx->r13) {
        // 0x8018ECE8: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8018EDC4;
    }
    goto skip_2;
    // 0x8018ECE8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8018ECEC: b           L_8018EE08
    // 0x8018ECF0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
        goto L_8018EE08;
    // 0x8018ECF0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8018ECF4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_8018ECF8:
    // 0x8018ECF8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018ECFC: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x8018ED00: addiu       $at, $t7, 0x3C
    ctx->r1 = ADD32(ctx->r15, 0X3C);
L_8018ED04:
    // 0x8018ED04: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018ED08: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018ED0C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018ED10: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8018ED14: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8018ED18: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8018ED1C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8018ED20: bne         $t7, $at, L_8018ED04
    if (ctx->r15 != ctx->r1) {
        // 0x8018ED24: sw          $t9, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->r25;
            goto L_8018ED04;
    }
    // 0x8018ED24: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8018ED28: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018ED2C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018ED30: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018ED34: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018ED38: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8018ED3C: addu        $t8, $s3, $a2
    ctx->r24 = ADD32(ctx->r19, ctx->r6);
    // 0x8018ED40: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8018ED44: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8018ED48: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8018ED4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018ED50: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8018ED54: b           L_8018EE04
    // 0x8018ED58: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_8018EE04;
    // 0x8018ED58: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x8018ED5C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
L_8018ED60:
    // 0x8018ED60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018ED64: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x8018ED68: addiu       $at, $t7, 0x3C
    ctx->r1 = ADD32(ctx->r15, 0X3C);
L_8018ED6C:
    // 0x8018ED6C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018ED70: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018ED74: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018ED78: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8018ED7C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8018ED80: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8018ED84: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8018ED88: bne         $t7, $at, L_8018ED6C
    if (ctx->r15 != ctx->r1) {
        // 0x8018ED8C: sw          $t9, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->r25;
            goto L_8018ED6C;
    }
    // 0x8018ED8C: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8018ED90: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018ED94: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018ED98: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018ED9C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018EDA0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8018EDA4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8018EDA8: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8018EDAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018EDB0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8018EDB4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8018EDB8: b           L_8018EE04
    // 0x8018EDBC: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
        goto L_8018EE04;
    // 0x8018EDBC: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
    // 0x8018EDC0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8018EDC4:
    // 0x8018EDC4: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x8018EDC8: addiu       $at, $t9, 0x3C
    ctx->r1 = ADD32(ctx->r25, 0X3C);
    // 0x8018EDCC: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_8018EDD0:
    // 0x8018EDD0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8018EDD4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018EDD8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018EDDC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018EDE0: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x8018EDE4: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x8018EDE8: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8018EDEC: bne         $t9, $at, L_8018EDD0
    if (ctx->r25 != ctx->r1) {
        // 0x8018EDF0: sw          $t8, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->r24;
            goto L_8018EDD0;
    }
    // 0x8018EDF0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018EDF4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8018EDF8: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    // 0x8018EDFC: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8018EE00: sw          $t7, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r15;
L_8018EE04:
    // 0x8018EE04: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
L_8018EE08:
    // 0x8018EE08: and         $t6, $t9, $ra
    ctx->r14 = ctx->r25 & ctx->r31;
    // 0x8018EE0C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
L_8018EE10:
    // 0x8018EE10: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8018EE14: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8018EE18: bnel        $v0, $zero, L_8018EC64
    if (ctx->r2 != 0) {
        // 0x8018EE1C: lw          $t6, 0x0($t1)
        ctx->r14 = MEM_W(ctx->r9, 0X0);
            goto L_8018EC64;
    }
    goto skip_3;
    // 0x8018EE1C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    skip_3:
L_8018EE20:
    // 0x8018EE20: jal         0x800CCF00
    // 0x8018EE24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_0;
    // 0x8018EE24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
L_8018EE28:
    // 0x8018EE28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018EE2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018EE30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018EE34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EE38: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8018EE3C: jr          $ra
    // 0x8018EE40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018EE40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mpCollisionGetEdgeLeftDLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAEA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAEA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FAEAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FAEB0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FAEB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAEB8: beq         $a0, $at, L_800FAECC
    if (ctx->r4 == ctx->r1) {
        // 0x800FAEBC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAECC;
    }
    // 0x800FAEBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAEC0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAEC4: bne         $a0, $at, L_800FAEF0
    if (ctx->r4 != ctx->r1) {
        // 0x800FAEC8: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FAEF0;
    }
    // 0x800FAEC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAECC:
    // 0x800FAECC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAED0: addiu       $s0, $s0, 0x644
    ctx->r16 = ADD32(ctx->r16, 0X644);
    // 0x800FAED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAED8:
    // 0x800FAED8: jal         0x80023624
    // 0x800FAEDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAEDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FAEE0: jal         0x800A3040
    // 0x800FAEE4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FAEE4: nop

    after_1:
    // 0x800FAEE8: b           L_800FAED8
    // 0x800FAEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAED8;
    // 0x800FAEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAEF0:
    // 0x800FAEF0: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FAEF4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FAEF8: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FAEFC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAF00: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAF04: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAF08: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAF0C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAF10: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAF14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAF18: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAF1C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FAF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAF24: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FAF28: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FAF2C: bnel        $at, $zero, L_800FAF58
    if (ctx->r1 != 0) {
        // 0x800FAF30: lh          $v0, 0x8($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X8);
            goto L_800FAF58;
    }
    goto skip_0;
    // 0x800FAF30: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x800FAF34: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAF38: addiu       $s0, $s0, 0x660
    ctx->r16 = ADD32(ctx->r16, 0X660);
L_800FAF3C:
    // 0x800FAF3C: jal         0x80023624
    // 0x800FAF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAF44: jal         0x800A3040
    // 0x800FAF48: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAF48: nop

    after_3:
    // 0x800FAF4C: b           L_800FAF3C
    // 0x800FAF50: nop

        goto L_800FAF3C;
    // 0x800FAF50: nop

    // 0x800FAF54: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
L_800FAF58:
    // 0x800FAF58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAF5C: jr          $ra
    // 0x800FAF60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAF60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftNessSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153AEC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153AF0: jal         0x800DE6E4
    // 0x80153AF4: addiu       $a1, $a1, 0x3B08
    ctx->r5 = ADD32(ctx->r5, 0X3B08);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80153AF4: addiu       $a1, $a1, 0x3B08
    ctx->r5 = ADD32(ctx->r5, 0X3B08);
    after_0:
    // 0x80153AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153B00: jr          $ra
    // 0x80153B04: nop

    return;
    // 0x80153B04: nop

;}
RECOMP_FUNC void sc1PTrainingModeFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190260: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80190264: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80190268: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8019026C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80190270: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80190274: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80190278: jal         0x8018DA98
    // 0x8019027C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    sc1PTrainingModeInitVars(rdram, ctx);
        goto after_0;
    // 0x8019027C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x80190280: jal         0x801906D0
    // 0x80190284: nop

    sc1PTrainingModeSetupFiles(rdram, ctx);
        goto after_1;
    // 0x80190284: nop

    after_1:
    // 0x80190288: jal         0x8018DD0C
    // 0x8019028C: nop

    sc1PTrainingModeLoadSprites(rdram, ctx);
        goto after_2;
    // 0x8019028C: nop

    after_2:
    // 0x80190290: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80190294: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80190298: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8019029C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801902A0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801902A4: jal         0x8000B9FC
    // 0x801902A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_3;
    // 0x801902A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801902AC: jal         0x80115890
    // 0x801902B0: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x801902B0: nop

    after_4:
    // 0x801902B4: jal         0x800EC130
    // 0x801902B8: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x801902B8: nop

    after_5:
    // 0x801902BC: jal         0x800FC284
    // 0x801902C0: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x801902C0: nop

    after_6:
    // 0x801902C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801902C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801902CC: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x801902D0: jal         0x8010E598
    // 0x801902D4: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x801902D4: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x801902D8: jal         0x8010DB54
    // 0x801902DC: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x801902DC: nop

    after_8:
    // 0x801902E0: jal         0x80104BDC
    // 0x801902E4: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_9;
    // 0x801902E4: nop

    after_9:
    // 0x801902E8: jal         0x8010DB00
    // 0x801902EC: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_10;
    // 0x801902EC: nop

    after_10:
    // 0x801902F0: jal         0x8016DEA0
    // 0x801902F4: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x801902F4: nop

    after_11:
    // 0x801902F8: jal         0x80105600
    // 0x801902FC: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_12;
    // 0x801902FC: nop

    after_12:
    // 0x80190300: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80190304: jal         0x800D7194
    // 0x80190308: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_13;
    // 0x80190308: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x8019030C: jal         0x801654B0
    // 0x80190310: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_14;
    // 0x80190310: nop

    after_14:
    // 0x80190314: jal         0x800FD300
    // 0x80190318: nop

    efManagerInitEffects(rdram, ctx);
        goto after_15;
    // 0x80190318: nop

    after_15:
    // 0x8019031C: jal         0x80115DE8
    // 0x80190320: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_16;
    // 0x80190320: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_16:
    // 0x80190324: jal         0x801156E4
    // 0x80190328: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_17;
    // 0x80190328: nop

    after_17:
    // 0x8019032C: jal         0x801653E0
    // 0x80190330: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_18;
    // 0x80190330: nop

    after_18:
    // 0x80190334: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80190338: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x8019033C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80190340: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80190344: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
L_80190348:
    // 0x80190348: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8019034C: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80190350: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x80190354: or          $t0, $s4, $zero
    ctx->r8 = ctx->r20 | 0;
L_80190358:
    // 0x80190358: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8019035C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80190360: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80190364: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x80190368: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8019036C: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x80190370: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80190374: bne         $t7, $t1, L_80190358
    if (ctx->r15 != ctx->r9) {
        // 0x80190378: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_80190358;
    }
    // 0x80190378: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x8019037C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80190380: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80190384: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80190388: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8019038C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80190390: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80190394: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80190398: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x8019039C: lbu         $t3, 0x22($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X22);
    // 0x801903A0: addiu       $t5, $t5, 0x5228
    ctx->r13 = ADD32(ctx->r13, 0X5228);
    // 0x801903A4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x801903A8: beq         $t3, $at, L_801904A0
    if (ctx->r11 == ctx->r1) {
        // 0x801903AC: addu        $s2, $t4, $t5
        ctx->r18 = ADD32(ctx->r12, ctx->r13);
            goto L_801904A0;
    }
    // 0x801903AC: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x801903B0: jal         0x800D786C
    // 0x801903B4: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_19;
    // 0x801903B4: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    after_19:
    // 0x801903B8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801903BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801903C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x801903C4: addu        $t1, $t6, $s1
    ctx->r9 = ADD32(ctx->r14, ctx->r17);
    // 0x801903C8: lbu         $t7, 0x23($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X23);
    // 0x801903CC: jal         0x800FAF64
    // 0x801903D0: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_20;
    // 0x801903D0: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    after_20:
    // 0x801903D4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801903D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801903DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801903E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801903E4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801903E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801903EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801903F0: bc1fl       L_80190404
    if (!c1cs) {
        // 0x801903F4: sw          $t8, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r24;
            goto L_80190404;
    }
    goto skip_0;
    // 0x801903F4: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    skip_0:
    // 0x801903F8: b           L_80190404
    // 0x801903FC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
        goto L_80190404;
    // 0x801903FC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80190400: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
L_80190404:
    // 0x80190404: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80190408: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8019040C: lbu         $t9, 0x24($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X24);
    // 0x80190410: sb          $s0, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r16;
    // 0x80190414: sb          $t9, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r25;
    // 0x80190418: lbu         $t3, 0x5($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X5);
    // 0x8019041C: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x80190420: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80190424: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80190428: beql        $at, $zero, L_8019043C
    if (ctx->r1 == 0) {
        // 0x8019042C: sb          $t6, 0x72($sp)
        MEM_B(0X72, ctx->r29) = ctx->r14;
            goto L_8019043C;
    }
    goto skip_1;
    // 0x8019042C: sb          $t6, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r14;
    skip_1:
    // 0x80190430: b           L_8019043C
    // 0x80190434: sb          $t5, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r13;
        goto L_8019043C;
    // 0x80190434: sb          $t5, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r13;
    // 0x80190438: sb          $t6, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r14;
L_8019043C:
    // 0x8019043C: lbu         $t1, 0x26($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X26);
    // 0x80190440: sb          $t1, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r9;
    // 0x80190444: lbu         $t7, 0x27($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X27);
    // 0x80190448: sb          $t7, 0x74($sp)
    MEM_B(0X74, ctx->r29) = ctx->r15;
    // 0x8019044C: lbu         $t0, 0x21($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X21);
    // 0x80190450: sb          $t0, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r8;
    // 0x80190454: lbu         $t8, 0x20($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X20);
    // 0x80190458: sb          $t8, 0x76($sp)
    MEM_B(0X76, ctx->r29) = ctx->r24;
    // 0x8019045C: lbu         $t9, 0x7($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7);
    // 0x80190460: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80190464: sb          $t9, 0x77($sp)
    MEM_B(0X77, ctx->r29) = ctx->r25;
    // 0x80190468: lbu         $t2, 0x22($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X22);
    // 0x8019046C: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80190470: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x80190474: jal         0x800D78B4
    // 0x80190478: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_21;
    // 0x80190478: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    after_21:
    // 0x8019047C: lbu         $t4, 0x7B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X7B);
    // 0x80190480: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80190484: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80190488: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x8019048C: jal         0x800D7F3C
    // 0x80190490: sb          $t5, 0x7B($sp)
    MEM_B(0X7B, ctx->r29) = ctx->r13;
    ftManagerMakeFighter(rdram, ctx);
        goto after_22;
    // 0x80190490: sb          $t5, 0x7B($sp)
    MEM_B(0X7B, ctx->r29) = ctx->r13;
    after_22:
    // 0x80190494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80190498: jal         0x800E7C4C
    // 0x8019049C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_23;
    // 0x8019049C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
L_801904A0:
    // 0x801904A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801904A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801904A8: bne         $s0, $at, L_80190348
    if (ctx->r16 != ctx->r1) {
        // 0x801904AC: addiu       $s1, $s1, 0x74
        ctx->r17 = ADD32(ctx->r17, 0X74);
            goto L_80190348;
    }
    // 0x801904AC: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x801904B0: jal         0x801901F4
    // 0x801904B4: nop

    sc1PTrainingModeUpdateDummyBehavior(rdram, ctx);
        goto after_24;
    // 0x801904B4: nop

    after_24:
    // 0x801904B8: jal         0x800D782C
    // 0x801904BC: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_25;
    // 0x801904BC: nop

    after_25:
    // 0x801904C0: jal         0x801901A0
    // 0x801904C4: nop

    sc1PTrainingModeSetGameStatusGo(rdram, ctx);
        goto after_26;
    // 0x801904C4: nop

    after_26:
    // 0x801904C8: jal         0x8010E2D4
    // 0x801904CC: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_27;
    // 0x801904CC: nop

    after_27:
    // 0x801904D0: jal         0x801118E4
    // 0x801904D4: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_28;
    // 0x801904D4: nop

    after_28:
    // 0x801904D8: jal         0x8010E1A4
    // 0x801904DC: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_29;
    // 0x801904DC: nop

    after_29:
    // 0x801904E0: jal         0x8018DE60
    // 0x801904E4: nop

    sc1PTrainingModeInitDisplayVars(rdram, ctx);
        goto after_30;
    // 0x801904E4: nop

    after_30:
    // 0x801904E8: jal         0x8010DDC4
    // 0x801904EC: nop

    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_31;
    // 0x801904EC: nop

    after_31:
    // 0x801904F0: jal         0x8010E374
    // 0x801904F4: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_32;
    // 0x801904F4: nop

    after_32:
    // 0x801904F8: jal         0x8010E498
    // 0x801904FC: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_33;
    // 0x801904FC: nop

    after_33:
    // 0x80190500: jal         0x80111BE4
    // 0x80190504: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_34;
    // 0x80190504: nop

    after_34:
    // 0x80190508: jal         0x8010F3A0
    // 0x8019050C: nop

    ifCommonPlayerDamageSetDigitPositions(rdram, ctx);
        goto after_35;
    // 0x8019050C: nop

    after_35:
    // 0x80190510: jal         0x8010F3C0
    // 0x80190514: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_36;
    // 0x80190514: nop

    after_36:
    // 0x80190518: jal         0x8010E690
    // 0x8019051C: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_37;
    // 0x8019051C: nop

    after_37:
    // 0x80190520: jal         0x80110514
    // 0x80190524: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_38;
    // 0x80190524: nop

    after_38:
    // 0x80190528: jal         0x8018EB64
    // 0x8019052C: nop

    sc1PTrainingModeMakeStatDisplayAll(rdram, ctx);
        goto after_39;
    // 0x8019052C: nop

    after_39:
    // 0x80190530: jal         0x801900C4
    // 0x80190534: nop

    sc1PTrainingModeMakeMenuAll(rdram, ctx);
        goto after_40;
    // 0x80190534: nop

    after_40:
    // 0x80190538: jal         0x80190164
    // 0x8019053C: nop

    sc1PTrainingModeSetPlayDefaultBGM(rdram, ctx);
        goto after_41;
    // 0x8019053C: nop

    after_41:
    // 0x80190540: jal         0x800266A0
    // 0x80190544: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_42;
    // 0x80190544: nop

    after_42:
    // 0x80190548: jal         0x800269C0
    // 0x8019054C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_43;
    // 0x8019054C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_43:
    // 0x80190550: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190554: addiu       $t6, $t6, 0x86C
    ctx->r14 = ADD32(ctx->r14, 0X86C);
    // 0x80190558: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8019055C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80190560: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80190564: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80190568: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019056C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80190570: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80190574: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80190578: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8019057C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80190580: jal         0x800D4060
    // 0x80190584: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_44;
    // 0x80190584: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_44:
    // 0x80190588: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019058C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80190590: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80190594: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80190598: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8019059C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801905A0: jr          $ra
    // 0x801905A4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801905A4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void ftCommonAttack13ProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E9EC: jal         0x8014F4EC
    // 0x8014E9F0: nop

    ftCommonAttack100StartCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014E9F0: nop

    after_0:
    // 0x8014E9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014E9F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E9FC: jr          $ra
    // 0x8014EA00: nop

    return;
    // 0x8014EA00: nop

;}
RECOMP_FUNC void ftCommonDamageAirCommonProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014070C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140714: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80140718: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8014071C: bnel        $t6, $zero, L_80140738
    if (ctx->r14 != 0) {
        // 0x80140720: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140738;
    }
    goto skip_0;
    // 0x80140720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80140724: lbu         $t7, 0x18F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18F);
    // 0x80140728: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8014072C: jal         0x80143560
    // 0x80140730: sb          $t8, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r24;
    ftCommonDamageFallProcInterrupt(rdram, ctx);
        goto after_0;
    // 0x80140730: sb          $t8, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r24;
    after_0:
    // 0x80140734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140738:
    // 0x80140738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014073C: jr          $ra
    // 0x80140740: nop

    return;
    // 0x80140740: nop

;}
RECOMP_FUNC void sc1PGameBossLockPlayerControl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F5AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F5B4: jal         0x800E7F14
    // 0x8018F5B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamLockPlayerControl(rdram, ctx);
        goto after_0;
    // 0x8018F5B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018F5BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F5C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F5C4: jr          $ra
    // 0x8018F5C8: nop

    return;
    // 0x8018F5C8: nop

;}
RECOMP_FUNC void mvOpeningSectorFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_ovl8_8037CE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CE30: jr          $ra
    // 0x8037CE34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8037CE34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void efManagerDamageSpawnMDustMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801003D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801003D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801003DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801003E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801003E4: jal         0x800FDAFC
    // 0x801003E8: addiu       $a0, $a0, -0x1F74
    ctx->r4 = ADD32(ctx->r4, -0X1F74);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x801003E8: addiu       $a0, $a0, -0x1F74
    ctx->r4 = ADD32(ctx->r4, -0X1F74);
    after_0:
    // 0x801003EC: bne         $v0, $zero, L_801003FC
    if (ctx->r2 != 0) {
        // 0x801003F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801003FC;
    }
    // 0x801003F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801003F4: b           L_80100430
    // 0x801003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100430;
    // 0x801003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801003FC:
    // 0x801003FC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80100400: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80100404: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80100408: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010040C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80100410: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80100414: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80100418: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x8010041C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80100420: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x80100424: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x80100428: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8010042C: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
L_80100430:
    // 0x80100430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100438: jr          $ra
    // 0x8010043C: nop

    return;
    // 0x8010043C: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132508: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013250C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132510: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132514: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132518: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8013251C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132520: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80132524: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132528: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013252C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132530: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132534: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132538: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013253C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132540: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132544: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013254C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132550: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132554: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013255C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132564: jal         0x8000B93C
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013256C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132570: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132574: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132578: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013257C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132580: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132584: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132588: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013258C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132590: jal         0x80007080
    // 0x80132594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132598: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013259C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801325A0: jr          $ra
    // 0x801325A4: nop

    return;
    // 0x801325A4: nop

;}
RECOMP_FUNC void func_ovl8_80376530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376530: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80376534: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80376538: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8037653C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80376540: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80376544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80376548: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8037654C: bne         $a0, $zero, L_80376564
    if (ctx->r4 != 0) {
        // 0x80376550: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_80376564;
    }
    // 0x80376550: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80376554: jal         0x803717A0
    // 0x80376558: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80376558: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x8037655C: beq         $v0, $zero, L_80376830
    if (ctx->r2 == 0) {
        // 0x80376560: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80376830;
    }
    // 0x80376560: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80376564:
    // 0x80376564: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80376568: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037656C: addiu       $a1, $s0, 0xAC
    ctx->r5 = ADD32(ctx->r16, 0XAC);
    // 0x80376570: bnel        $t6, $zero, L_80376594
    if (ctx->r14 != 0) {
        // 0x80376574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80376594;
    }
    goto skip_0;
    // 0x80376574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80376578: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8037657C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80376580: jal         0x803717E0
    // 0x80376584: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80376584: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    after_1:
    // 0x80376588: jal         0x8037C2D0
    // 0x8037658C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037658C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80376590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80376594:
    // 0x80376594: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80376598: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8037659C: jal         0x80372844
    // 0x803765A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_ovl8_80372844(rdram, ctx);
        goto after_3;
    // 0x803765A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x803765A4: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x803765A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x803765AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x803765B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x803765B4: jal         0x8037203C
    // 0x803765B8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_ovl8_8037203C(rdram, ctx);
        goto after_4;
    // 0x803765B8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x803765BC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803765C0: addiu       $t7, $t7, -0x6370
    ctx->r15 = ADD32(ctx->r15, -0X6370);
    // 0x803765C4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x803765C8: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x803765CC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x803765D0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803765D4: addiu       $t8, $t8, -0x62B8
    ctx->r24 = ADD32(ctx->r24, -0X62B8);
    // 0x803765D8: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x803765DC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x803765E0: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803765E4: addiu       $t0, $t0, -0x6160
    ctx->r8 = ADD32(ctx->r8, -0X6160);
    // 0x803765E8: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803765EC: addiu       $t2, $t2, -0x6138
    ctx->r10 = ADD32(ctx->r10, -0X6138);
    // 0x803765F0: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x803765F4: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x803765F8: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x803765FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80376600: ori         $at, $at, 0x574E
    ctx->r1 = ctx->r1 | 0X574E;
    // 0x80376604: beq         $v1, $at, L_80376618
    if (ctx->r3 == ctx->r1) {
        // 0x80376608: lui         $at, 0x4246
        ctx->r1 = S32(0X4246 << 16);
            goto L_80376618;
    }
    // 0x80376608: lui         $at, 0x4246
    ctx->r1 = S32(0X4246 << 16);
    // 0x8037660C: ori         $at, $at, 0x4857
    ctx->r1 = ctx->r1 | 0X4857;
    // 0x80376610: bnel        $v1, $at, L_80376634
    if (ctx->r3 != ctx->r1) {
        // 0x80376614: lhu         $v0, 0x10($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X10);
            goto L_80376634;
    }
    goto skip_1;
    // 0x80376614: lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X10);
    skip_1:
L_80376618:
    // 0x80376618: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8037661C: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80376620: lh          $t3, 0x20($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X20);
    // 0x80376624: jalr        $t9
    // 0x80376628: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80376628: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    after_5:
    // 0x8037662C: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80376630: lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X10);
L_80376634:
    // 0x80376634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80376638: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8037663C: bne         $v0, $at, L_80376658
    if (ctx->r2 != ctx->r1) {
        // 0x80376640: addiu       $t5, $zero, 0x40
        ctx->r13 = ADD32(0, 0X40);
            goto L_80376658;
    }
    // 0x80376640: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80376644: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80376648: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8037664C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80376650: b           L_8037669C
    // 0x80376654: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_8037669C;
    // 0x80376654: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80376658:
    // 0x80376658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8037665C: bne         $v0, $at, L_8037667C
    if (ctx->r2 != ctx->r1) {
        // 0x80376660: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8037667C;
    }
    // 0x80376660: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80376664: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80376668: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8037666C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80376670: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80376674: b           L_8037669C
    // 0x80376678: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
        goto L_8037669C;
    // 0x80376678: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8037667C:
    // 0x8037667C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80376680: bne         $v0, $at, L_8037669C
    if (ctx->r2 != ctx->r1) {
        // 0x80376684: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8037669C;
    }
    // 0x80376684: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80376688: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8037668C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80376690: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80376694: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80376698: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_8037669C:
    // 0x8037669C: bne         $a2, $zero, L_803767BC
    if (ctx->r6 != 0) {
        // 0x803766A0: sw          $zero, 0xA8($s0)
        MEM_W(0XA8, ctx->r16) = 0;
            goto L_803767BC;
    }
    // 0x803766A0: sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // 0x803766A4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x803766A8: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x803766AC: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x803766B0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x803766B4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x803766B8: jal         0x8037ACAC
    // 0x803766BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_6;
    // 0x803766BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_6:
    // 0x803766C0: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x803766C4: sw          $v0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r2;
    // 0x803766C8: lhu         $t4, 0x10($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X10);
    // 0x803766CC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x803766D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x803766D4: bnel        $t4, $at, L_80376728
    if (ctx->r12 != ctx->r1) {
        // 0x803766D8: lwl         $t3, 0x0($s1)
        ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r17, 0X0);
            goto L_80376728;
    }
    goto skip_2;
    // 0x803766D8: lwl         $t3, 0x0($s1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r17, 0X0);
    skip_2:
    // 0x803766DC: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x803766E0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x803766E4: jal         0x80376B60
    // 0x803766E8: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_ovl8_80376B60(rdram, ctx);
        goto after_7;
    // 0x803766E8: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_7:
    // 0x803766EC: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x803766F0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x803766F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x803766F8: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x803766FC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80376700: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x80376704: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80376708: jal         0x80376B60
    // 0x8037670C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_ovl8_80376B60(rdram, ctx);
        goto after_8;
    // 0x8037670C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_8:
    // 0x80376710: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x80376714: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80376718: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x8037671C: b           L_80376760
    // 0x80376720: sh          $t8, 0x1FE($t1)
    MEM_H(0X1FE, ctx->r9) = ctx->r24;
        goto L_80376760;
    // 0x80376720: sh          $t8, 0x1FE($t1)
    MEM_H(0X1FE, ctx->r9) = ctx->r24;
    // 0x80376724: lwl         $t3, 0x0($s1)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r17, 0X0);
L_80376728:
    // 0x80376728: lwr         $t3, 0x3($s1)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r17, 0X3);
    // 0x8037672C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80376730: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    // 0x80376734: swl         $t3, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r11);
    // 0x80376738: swr         $t3, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r11);
    // 0x8037673C: lwl         $t2, 0x4($s1)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r17, 0X4);
    // 0x80376740: lwr         $t2, 0x7($s1)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r17, 0X7);
    // 0x80376744: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80376748: swl         $t2, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r10);
    // 0x8037674C: swr         $t2, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r10);
    // 0x80376750: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80376754: sh          $zero, 0x46($sp)
    MEM_H(0X46, ctx->r29) = 0;
    // 0x80376758: jal         0x80377AEC
    // 0x8037675C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_9;
    // 0x8037675C: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    after_9:
L_80376760:
    // 0x80376760: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80376764: lui         $t9, 0x8038
    ctx->r25 = S32(0X8038 << 16);
    // 0x80376768: addiu       $t9, $t9, -0x416C
    ctx->r25 = ADD32(ctx->r25, -0X416C);
    // 0x8037676C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80376770: lui         $a3, 0x8038
    ctx->r7 = S32(0X8038 << 16);
    // 0x80376774: addiu       $a3, $a3, -0x41CC
    ctx->r7 = ADD32(ctx->r7, -0X41CC);
    // 0x80376778: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8037677C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80376780: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80376784: jal         0x803723AC
    // 0x80376788: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_ovl8_803723AC(rdram, ctx);
        goto after_10;
    // 0x80376788: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_10:
    // 0x8037678C: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80376790: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x80376794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376798: sh          $t6, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r14;
    // 0x8037679C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x803767A0: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x803767A4: sh          $t7, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r15;
    // 0x803767A8: lh          $a2, 0x2($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X2);
    // 0x803767AC: jal         0x80376AA4
    // 0x803767B0: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    func_ovl8_80376AA4(rdram, ctx);
        goto after_11;
    // 0x803767B0: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    after_11:
    // 0x803767B4: b           L_8037681C
    // 0x803767B8: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
        goto L_8037681C;
    // 0x803767B8: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
L_803767BC:
    // 0x803767BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x803767C0: beq         $a2, $at, L_80376818
    if (ctx->r6 == ctx->r1) {
        // 0x803767C4: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80376818;
    }
    // 0x803767C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x803767C8: sw          $a2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r6;
    // 0x803767CC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x803767D0: lui         $t8, 0x8038
    ctx->r24 = S32(0X8038 << 16);
    // 0x803767D4: addiu       $t8, $t8, -0x416C
    ctx->r24 = ADD32(ctx->r24, -0X416C);
    // 0x803767D8: lui         $a3, 0x8038
    ctx->r7 = S32(0X8038 << 16);
    // 0x803767DC: addiu       $a3, $a3, -0x41CC
    ctx->r7 = ADD32(ctx->r7, -0X41CC);
    // 0x803767E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x803767E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x803767E8: jal         0x803723AC
    // 0x803767EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_ovl8_803723AC(rdram, ctx);
        goto after_12;
    // 0x803767EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_12:
    // 0x803767F0: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x803767F4: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x803767F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803767FC: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80376800: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x80376804: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x80376808: sh          $t9, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r25;
    // 0x8037680C: lh          $a2, 0x2($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X2);
    // 0x80376810: jal         0x80376AA4
    // 0x80376814: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    func_ovl8_80376AA4(rdram, ctx);
        goto after_13;
    // 0x80376814: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    after_13:
L_80376818:
    // 0x80376818: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
L_8037681C:
    // 0x8037681C: addiu       $at, $zero, -0x2710
    ctx->r1 = ADD32(0, -0X2710);
    // 0x80376820: bnel        $t6, $at, L_80376834
    if (ctx->r14 != ctx->r1) {
        // 0x80376824: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80376834;
    }
    goto skip_3;
    // 0x80376824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80376828: jal         0x803772AC
    // 0x8037682C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803772AC(rdram, ctx);
        goto after_14;
    // 0x8037682C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80376830:
    // 0x80376830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80376834:
    // 0x80376834: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80376838: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8037683C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80376840: jr          $ra
    // 0x80376844: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80376844: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonRunSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EEE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013EEEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013EEF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013EEF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013EEF8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8013EEFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013EF00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013EF04: jal         0x800E6F24
    // 0x8013EF08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013EF08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013EF0C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013EF10: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x8013EF14: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8013EF18: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x8013EF1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013EF20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013EF24: jr          $ra
    // 0x8013EF28: nop

    return;
    // 0x8013EF28: nop

;}
RECOMP_FUNC void syMatrixTraRotRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BC48: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BC4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BC50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001BC54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001BC58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001BC5C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001BC60: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8001BC64: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001BC68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001BC6C: jal         0x8001BA78
    // 0x8001BC70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixRotRF(rdram, ctx);
        goto after_0;
    // 0x8001BC70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001BC74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001BC78: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001BC7C: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x8001BC80: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001BC84: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x8001BC88: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001BC8C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001BC90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BC94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001BC98: jr          $ra
    // 0x8001BC9C: nop

    return;
    // 0x8001BC9C: nop

;}
RECOMP_FUNC void itMSBombAttachedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176A68: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80176A6C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80176A70: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80176A74: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80176A78: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80176A7C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80176A80: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80176A84: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80176A88: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80176A8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176A90: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80176A94: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80176A98: lhu         $v1, 0x33E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X33E);
    // 0x80176A9C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80176AA0: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x80176AA4: beq         $at, $zero, L_80176AB4
    if (ctx->r1 == 0) {
        // 0x80176AA8: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_80176AB4;
    }
    // 0x80176AA8: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80176AAC: b           L_80176B68
    // 0x80176AB0: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
        goto L_80176B68;
    // 0x80176AB0: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
L_80176AB4:
    // 0x80176AB4: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80176AB8: addiu       $s4, $a1, 0x1C
    ctx->r20 = ADD32(ctx->r5, 0X1C);
    // 0x80176ABC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80176AC0: beq         $s0, $zero, L_80176B68
    if (ctx->r16 == 0) {
        // 0x80176AC4: addiu       $s2, $sp, 0x64
        ctx->r18 = ADD32(ctx->r29, 0X64);
            goto L_80176B68;
    }
    // 0x80176AC4: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x80176AC8: lwc1        $f22, -0x32D8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X32D8);
    // 0x80176ACC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80176AD0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80176AD4: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80176AD8: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_80176ADC:
    // 0x80176ADC: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x80176AE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80176AE4: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x80176AE8: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x80176AEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80176AF0: lwc1        $f4, 0x9C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X9C);
    // 0x80176AF4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80176AF8: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x80176AFC: mul.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80176B00: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80176B04: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80176B08: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x80176B0C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x80176B10: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80176B14: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80176B18: jal         0x8001902C
    // 0x80176B1C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80176B1C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80176B20: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80176B24: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80176B28: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80176B2C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80176B30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80176B34: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80176B38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80176B3C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80176B40: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80176B44: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x80176B48: nop

    // 0x80176B4C: bc1fl       L_80176B60
    if (!c1cs) {
        // 0x80176B50: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80176B60;
    }
    goto skip_0;
    // 0x80176B50: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80176B54: jal         0x801769AC
    // 0x80176B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itMSBombExplodeInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80176B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80176B5C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80176B60:
    // 0x80176B60: bnel        $s0, $zero, L_80176ADC
    if (ctx->r16 != 0) {
        // 0x80176B64: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_80176ADC;
    }
    goto skip_1;
    // 0x80176B64: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_1:
L_80176B68:
    // 0x80176B68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80176B6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80176B70: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80176B74: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80176B78: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80176B7C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80176B80: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80176B84: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80176B88: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80176B8C: jr          $ra
    // 0x80176B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80176B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E11C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002E120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E124: lw          $a3, 0x58($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X58);
    // 0x8002E128: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8002E12C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002E130: beq         $a3, $zero, L_8002E1B0
    if (ctx->r7 == 0) {
        // 0x8002E134: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8002E1B0;
    }
    // 0x8002E134: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002E138: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8002E13C:
    // 0x8002E13C: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    // 0x8002E140: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8002E144: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8002E148: bne         $a0, $t6, L_8002E1A8
    if (ctx->r4 != ctx->r14) {
        // 0x8002E14C: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_8002E1A8;
    }
    // 0x8002E14C: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8002E150: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x8002E154: bne         $a1, $t7, L_8002E1A8
    if (ctx->r5 != ctx->r15) {
        // 0x8002E158: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8002E1A8;
    }
    // 0x8002E158: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002E15C: beq         $at, $zero, L_8002E1A0
    if (ctx->r1 == 0) {
        // 0x8002E160: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8002E1A0;
    }
    // 0x8002E160: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8002E164: beql        $v0, $zero, L_8002E17C
    if (ctx->r2 == 0) {
        // 0x8002E168: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8002E17C;
    }
    goto skip_0;
    // 0x8002E168: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x8002E16C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8002E170: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8002E174: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x8002E178: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_8002E17C:
    // 0x8002E17C: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x8002E180: jal         0x80028C84
    // 0x8002E184: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8002E184: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x8002E188: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8002E18C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E190: jal         0x80028C60
    // 0x8002E194: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    alLink(rdram, ctx);
        goto after_1;
    // 0x8002E194: addiu       $a1, $t2, 0x50
    ctx->r5 = ADD32(ctx->r10, 0X50);
    after_1:
    // 0x8002E198: b           L_8002E1B0
    // 0x8002E19C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_8002E1B0;
    // 0x8002E19C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_8002E1A0:
    // 0x8002E1A0: b           L_8002E1B0
    // 0x8002E1A4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8002E1B0;
    // 0x8002E1A4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8002E1A8:
    // 0x8002E1A8: bne         $v0, $zero, L_8002E13C
    if (ctx->r2 != 0) {
        // 0x8002E1AC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8002E13C;
    }
    // 0x8002E1AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8002E1B0:
    // 0x8002E1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E1B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002E1B8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8002E1BC: jr          $ra
    // 0x8002E1C0: nop

    return;
    // 0x8002E1C0: nop

;}
RECOMP_FUNC void alLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C60: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80028C64: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80028C68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80028C6C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80028C70: beq         $v0, $zero, L_80028C7C
    if (ctx->r2 == 0) {
        // 0x80028C74: nop
    
            goto L_80028C7C;
    }
    // 0x80028C74: nop

    // 0x80028C78: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_80028C7C:
    // 0x80028C7C: jr          $ra
    // 0x80028C80: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x80028C80: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void ftDonkeySpecialAirNLoopSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B28C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015B290: jal         0x800DEE98
    // 0x8015B294: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015B294: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015B298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015B29C: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x8015B2A0: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015B2A4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B2A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B2AC: jal         0x800E6F24
    // 0x8015B2B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B2B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B2B4: jal         0x8015B244
    // 0x8015B2B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x8015B2B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015B2BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B2C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B2C4: jr          $ra
    // 0x8015B2C8: nop

    return;
    // 0x8015B2C8: nop

;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028CB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80028CB8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80028CBC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80028CC0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80028CC4: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x80028CC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028CCC: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80028CD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80028CD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80028CD8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80028CDC: jal         0x80030350
    // 0x80028CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80028CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80028CE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80028CE8: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80028CEC: beq         $s0, $zero, L_80028D4C
    if (ctx->r16 == 0) {
        // 0x80028CF0: nop
    
            goto L_80028D4C;
    }
    // 0x80028CF0: nop

L_80028CF4:
    // 0x80028CF4: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x80028CF8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80028CFC: bne         $s3, $t6, L_80028D44
    if (ctx->r19 != ctx->r14) {
        // 0x80028D00: nop
    
            goto L_80028D44;
    }
    // 0x80028D00: nop

    // 0x80028D04: beq         $s1, $zero, L_80028D1C
    if (ctx->r17 == 0) {
        // 0x80028D08: nop
    
            goto L_80028D1C;
    }
    // 0x80028D08: nop

    // 0x80028D0C: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80028D10: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80028D14: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80028D18: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_80028D1C:
    // 0x80028D1C: jal         0x80028C84
    // 0x80028D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80028D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80028D24: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80028D28: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80028D2C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80028D30: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80028D34: beql        $v0, $zero, L_80028D44
    if (ctx->r2 == 0) {
        // 0x80028D38: sw          $s0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r16;
            goto L_80028D44;
    }
    goto skip_0;
    // 0x80028D38: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    skip_0:
    // 0x80028D3C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80028D40: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
L_80028D44:
    // 0x80028D44: bne         $s1, $zero, L_80028CF4
    if (ctx->r17 != 0) {
        // 0x80028D48: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80028CF4;
    }
    // 0x80028D48: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80028D4C:
    // 0x80028D4C: jal         0x80030350
    // 0x80028D50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80028D50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80028D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80028D58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80028D5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80028D60: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D64: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80028D68: jr          $ra
    // 0x80028D6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80028D6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonThrownReleaseThrownUpdateStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AFD0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8014AFD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014AFD8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8014AFDC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8014AFE0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8014AFE4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8014AFE8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8014AFEC: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8014AFF0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014AFF4: lwc1        $f0, 0x7E8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X7E8);
    // 0x8014AFF8: lwc1        $f2, 0x7E4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X7E4);
    // 0x8014AFFC: lw          $v0, 0x844($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X844);
    // 0x8014B000: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8014B004: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x8014B008: bc1fl       L_8014B01C
    if (!c1cs) {
        // 0x8014B00C: swc1        $f0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
            goto L_8014B01C;
    }
    goto skip_0;
    // 0x8014B00C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    skip_0:
    // 0x8014B010: b           L_8014B01C
    // 0x8014B014: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
        goto L_8014B01C;
    // 0x8014B014: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8014B018: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_8014B01C:
    // 0x8014B01C: sw          $a2, -0x3080($at)
    MEM_W(-0X3080, ctx->r1) = ctx->r6;
    // 0x8014B020: lw          $t7, 0x5B8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5B8);
    // 0x8014B024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014B028: beql        $t7, $at, L_8014B040
    if (ctx->r15 == ctx->r1) {
        // 0x8014B02C: lw          $t8, 0x190($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X190);
            goto L_8014B040;
    }
    goto skip_1;
    // 0x8014B02C: lw          $t8, 0x190($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X190);
    skip_1:
    // 0x8014B030: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8014B034: jal         0x800E8A24
    // 0x8014B038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_0;
    // 0x8014B038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8014B03C: lw          $t8, 0x190($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X190);
L_8014B040:
    // 0x8014B040: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x8014B044: bltz        $t0, L_8014B054
    if (SIGNED(ctx->r8) < 0) {
        // 0x8014B048: nop
    
            goto L_8014B054;
    }
    // 0x8014B048: nop

    // 0x8014B04C: jal         0x8014ADB0
    // 0x8014B050: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_1;
    // 0x8014B050: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_1:
L_8014B054:
    // 0x8014B054: jal         0x800DEEC8
    // 0x8014B058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_2;
    // 0x8014B058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8014B05C: lw          $v1, 0x848($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X848);
    // 0x8014B060: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x8014B064: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8014B068: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8014B06C: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x8014B070: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8014B074: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x8014B078: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8014B07C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8014B080: lw          $t3, 0x9C8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X9C8);
    // 0x8014B084: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8014B088: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8014B08C: lbu         $t4, 0x12($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X12);
    // 0x8014B090: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8014B094: lbu         $t5, 0x12($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X12);
    // 0x8014B098: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x8014B09C: jal         0x800E9D78
    // 0x8014B0A0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_3;
    // 0x8014B0A0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_3:
    // 0x8014B0A4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8014B0A8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8014B0AC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8014B0B0: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8014B0B4: bc1fl       L_8014B0C8
    if (!c1cs) {
        // 0x8014B0B8: lbu         $a0, 0xD($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0XD);
            goto L_8014B0C8;
    }
    goto skip_2;
    // 0x8014B0B8: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    skip_2:
    // 0x8014B0BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8014B0C0: nop

    // 0x8014B0C4: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
L_8014B0C8:
    // 0x8014B0C8: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8014B0CC: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x8014B0D0: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    // 0x8014B0D4: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8014B0D8: jal         0x800EA54C
    // 0x8014B0DC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    ftParamGetStaledDamage(rdram, ctx);
        goto after_4;
    // 0x8014B0DC: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_4:
    // 0x8014B0E0: lw          $t6, 0x190($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X190);
    // 0x8014B0E4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8014B0E8: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8014B0EC: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x8014B0F0: bgez        $t8, L_8014B124
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8014B0F4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8014B124;
    }
    // 0x8014B0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014B0F8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8014B0FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014B100: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014B104: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014B108: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014B10C: lwc1        $f4, -0x3DF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3DF0);
    // 0x8014B110: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014B114: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8014B118: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8014B11C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8014B120: nop

L_8014B124:
    // 0x8014B124: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8014B128: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x8014B12C: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x8014B130: jal         0x800E8AAC
    // 0x8014B134: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_5;
    // 0x8014B134: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8014B138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014B13C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8014B140: beq         $v0, $at, L_8014B14C
    if (ctx->r2 == ctx->r1) {
        // 0x8014B144: lwc1        $f2, 0x54($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
            goto L_8014B14C;
    }
    // 0x8014B144: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8014B148: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8014B14C:
    // 0x8014B14C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8014B150: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8014B154: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8014B158: beq         $t0, $zero, L_8014B16C
    if (ctx->r8 == 0) {
        // 0x8014B15C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8014B16C;
    }
    // 0x8014B15C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014B160: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8014B164: addiu       $t1, $t1, -0x5068
    ctx->r9 = ADD32(ctx->r9, -0X5068);
    // 0x8014B168: sw          $t1, 0xA0C($s1)
    MEM_W(0XA0C, ctx->r17) = ctx->r9;
L_8014B16C:
    // 0x8014B16C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8014B170: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8014B174: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8014B178: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8014B17C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014B180: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8014B184: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x8014B188: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014B18C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014B190: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8014B194: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x8014B198: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8014B19C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8014B1A0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8014B1A4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8014B1A8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8014B1AC: jal         0x80140EE4
    // 0x8014B1B0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_6;
    // 0x8014B1B0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_6:
    // 0x8014B1B4: lhu         $t0, 0x28E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X28E);
    // 0x8014B1B8: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B1BC: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8014B1C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8014B1C4: lhu         $t1, 0x290($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X290);
    // 0x8014B1C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014B1CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014B1D0: jal         0x800EAA2C
    // 0x8014B1D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_7;
    // 0x8014B1D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_7:
    // 0x8014B1D8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8014B1DC: beql        $a1, $zero, L_8014B298
    if (ctx->r5 == 0) {
        // 0x8014B1E0: sw          $zero, 0x844($s1)
        MEM_W(0X844, ctx->r17) = 0;
            goto L_8014B298;
    }
    goto skip_3;
    // 0x8014B1E0: sw          $zero, 0x844($s1)
    MEM_W(0X844, ctx->r17) = 0;
    skip_3:
    // 0x8014B1E4: jal         0x800EA248
    // 0x8014B1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamUpdateDamage(rdram, ctx);
        goto after_8;
    // 0x8014B1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8014B1EC: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B1F0: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B1F4: jal         0x800EA98C
    // 0x8014B1F8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_9;
    // 0x8014B1F8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_9:
    // 0x8014B1FC: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B200: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B204: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x8014B208: jal         0x800EA614
    // 0x8014B20C: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_10;
    // 0x8014B20C: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    after_10:
    // 0x8014B210: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8014B214: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8014B218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014B21C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8014B220: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8014B224: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014B228: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014B22C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014B230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014B234: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8014B238: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8014B23C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8014B240: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8014B244: nop

    // 0x8014B248: blezl       $a2, L_8014B260
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8014B24C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8014B260;
    }
    goto skip_4;
    // 0x8014B24C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_4:
    // 0x8014B250: jal         0x800E806C
    // 0x8014B254: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    ftParamMakeRumble(rdram, ctx);
        goto after_11;
    // 0x8014B254: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8014B258: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8014B25C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_8014B260:
    // 0x8014B260: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014B264: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8014B268: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014B26C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8014B270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014B274: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8014B278: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014B27C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8014B280: nop

    // 0x8014B284: blezl       $a2, L_8014B298
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8014B288: sw          $zero, 0x844($s1)
        MEM_W(0X844, ctx->r17) = 0;
            goto L_8014B298;
    }
    goto skip_5;
    // 0x8014B288: sw          $zero, 0x844($s1)
    MEM_W(0X844, ctx->r17) = 0;
    skip_5:
    // 0x8014B28C: jal         0x800E806C
    // 0x8014B290: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    ftParamMakeRumble(rdram, ctx);
        goto after_12;
    // 0x8014B290: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x8014B294: sw          $zero, 0x844($s1)
    MEM_W(0X844, ctx->r17) = 0;
L_8014B298:
    // 0x8014B298: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014B29C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8014B2A0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8014B2A4: jr          $ra
    // 0x8014B2A8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8014B2A8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void itNBumperAttachedSetModelPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B874: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B87C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017B880: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B884: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x8017B888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8017B88C: lw          $t9, 0xB8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB8);
    // 0x8017B890: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8017B894: lw          $t8, 0xBC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XBC);
    // 0x8017B898: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8017B89C: lw          $t9, 0xC0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC0);
    // 0x8017B8A0: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8017B8A4: lw          $t0, 0xAC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XAC);
    // 0x8017B8A8: sh          $t0, 0x2D0($v0)
    MEM_H(0X2D0, ctx->r2) = ctx->r8;
    // 0x8017B8AC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017B8B0: jal         0x8001863C
    // 0x8017B8B4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8017B8B4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8017B8B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017B8BC: lwc1        $f4, -0x3248($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3248);
    // 0x8017B8C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017B8C4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8017B8C8: swc1        $f6, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f6.u32l;
    // 0x8017B8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B8D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017B8D4: jr          $ra
    // 0x8017B8D8: nop

    return;
    // 0x8017B8D8: nop

;}

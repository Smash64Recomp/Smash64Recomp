#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnMapsSaveSceneData2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133D68: jal         0x80133B78
    // 0x80133D6C: nop

    mnMapsSaveSceneData(rdram, ctx);
        goto after_0;
    // 0x80133D6C: nop

    after_0:
    // 0x80133D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133D78: jr          $ra
    // 0x80133D7C: nop

    return;
    // 0x80133D7C: nop

;}
RECOMP_FUNC void ftParamGetCostumeCommonID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC0EC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800EC0F0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800EC0F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EC0F8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800EC0FC: jr          $ra
    // 0x800EC100: lbu         $v0, -0x47D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47D0);
    return;
    // 0x800EC100: lbu         $v0, -0x47D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47D0);
;}
RECOMP_FUNC void mnVSRecordGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DA0: bne         $a1, $zero, L_80131DB0
    if (ctx->r5 != 0) {
        // 0x80131DA4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131DB0;
    }
    // 0x80131DA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131DA8: jr          $ra
    // 0x80131DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131DB0:
    // 0x80131DB0: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131DB4: bne         $at, $zero, L_80131E34
    if (ctx->r1 != 0) {
        // 0x80131DB8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131E34;
    }
    // 0x80131DB8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131DBC: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131DC0: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131DC4: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131DC8: beq         $a3, $zero, L_80131DEC
    if (ctx->r7 == 0) {
        // 0x80131DCC: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131DEC;
    }
    // 0x80131DCC: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131DD0:
    // 0x80131DD0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131DD4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131DD8: mflo        $v1
    ctx->r3 = lo;
    // 0x80131DDC: bne         $a2, $v0, L_80131DD0
    if (ctx->r6 != ctx->r2) {
        // 0x80131DE0: nop
    
            goto L_80131DD0;
    }
    // 0x80131DE0: nop

    // 0x80131DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131DE8: beq         $v0, $a1, L_80131E34
    if (ctx->r2 == ctx->r5) {
        // 0x80131DEC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131E34;
    }
L_80131DEC:
    // 0x80131DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131DF0:
    // 0x80131DF0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131DF4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131DF8: mflo        $v1
    ctx->r3 = lo;
    // 0x80131DFC: nop

    // 0x80131E00: nop

    // 0x80131E04: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131E08: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E0C: nop

    // 0x80131E10: nop

    // 0x80131E14: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131E18: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E1C: nop

    // 0x80131E20: nop

    // 0x80131E24: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131E28: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E2C: bne         $v0, $a1, L_80131DF0
    if (ctx->r2 != ctx->r5) {
        // 0x80131E30: nop
    
            goto L_80131DF0;
    }
    // 0x80131E30: nop

L_80131E34:
    // 0x80131E34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131E38: jr          $ra
    // 0x80131E3C: nop

    return;
    // 0x80131E3C: nop

;}
RECOMP_FUNC void ftParamRefreshAttackCollID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E866C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800E8670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8674: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800E8678: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x800E867C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800E8680: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800E8684: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E8688: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E868C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800E8690: sw          $t6, 0x294($t8)
    MEM_W(0X294, ctx->r24) = ctx->r14;
    // 0x800E8694: lbu         $t0, 0x18C($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X18C);
    // 0x800E8698: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x800E869C: jal         0x800E853C
    // 0x800E86A0: sb          $t1, 0x18C($a0)
    MEM_B(0X18C, ctx->r4) = ctx->r9;
    ftParamClearAttackRecordID(rdram, ctx);
        goto after_0;
    // 0x800E86A0: sb          $t1, 0x18C($a0)
    MEM_B(0X18C, ctx->r4) = ctx->r9;
    after_0:
    // 0x800E86A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E86A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E86AC: jr          $ra
    // 0x800E86B0: nop

    return;
    // 0x800E86B0: nop

;}
RECOMP_FUNC void lbCommonAdd2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AB8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7ABC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7AC0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7AC4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C7AC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C7ACC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800C7AD0: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7AD4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C7AD8: jr          $ra
    // 0x800C7ADC: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800C7ADC: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void itMSBombExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80176EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176EEC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176EF0: jal         0x80176C14
    // 0x80176EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMSBombExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80176EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80176EF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80176EFC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80176F00: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80176F04: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80176F08: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80176F0C: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80176F10: bne         $t8, $at, L_80176F20
    if (ctx->r24 != ctx->r1) {
        // 0x80176F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80176F20;
    }
    // 0x80176F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176F18: b           L_80176F24
    // 0x80176F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80176F24;
    // 0x80176F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80176F20:
    // 0x80176F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80176F24:
    // 0x80176F24: jr          $ra
    // 0x80176F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80176F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gcInitDLs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014430: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80014434: addiu       $v0, $v0, 0x70C8
    ctx->r2 = ADD32(ctx->r2, 0X70C8);
    // 0x80014438: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001443C: sw          $v0, 0x70B0($at)
    MEM_W(0X70B0, ctx->r1) = ctx->r2;
    // 0x80014440: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014444: sw          $v0, 0x70B8($at)
    MEM_W(0X70B8, ctx->r1) = ctx->r2;
    // 0x80014448: sw          $v0, 0x70BC($at)
    MEM_W(0X70BC, ctx->r1) = ctx->r2;
    // 0x8001444C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014450: sw          $v0, 0x70C0($at)
    MEM_W(0X70C0, ctx->r1) = ctx->r2;
    // 0x80014454: jr          $ra
    // 0x80014458: sw          $v0, 0x70C4($at)
    MEM_W(0X70C4, ctx->r1) = ctx->r2;
    return;
    // 0x80014458: sw          $v0, 0x70C4($at)
    MEM_W(0X70C4, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void scStaffrollUpdateCameraAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EA8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80134EAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134EB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134EB4: lwc1        $f6, -0x572C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X572C);
    // 0x80134EB8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134EBC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134EC0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80134EC4: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80134EC8: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80134ECC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80134ED0: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x80134ED4: lwc1        $f18, -0x5728($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5728);
    // 0x80134ED8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80134EDC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80134EE0: jr          $ra
    // 0x80134EE4: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80134EE4: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void itMLuckyAppearProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181158: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018115C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80181160: jal         0x80173680
    // 0x80181164: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80181164: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80181168: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8018116C: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x80181170: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80181174: beql        $t7, $zero, L_8018119C
    if (ctx->r15 == 0) {
        // 0x80181178: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018119C;
    }
    goto skip_0;
    // 0x80181178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018117C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80181180: nop

    // 0x80181184: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x80181188: jal         0x801813A8
    // 0x8018118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMLuckyMakeEggSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80181190: jal         0x80180FC0
    // 0x80181194: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMLuckyMakeEggInitVars(rdram, ctx);
        goto after_2;
    // 0x80181194: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80181198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018119C:
    // 0x8018119C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801811A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801811A4: jr          $ra
    // 0x801811A8: nop

    return;
    // 0x801811A8: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeUpperLLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FABA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FABA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FABAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FABB0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FABB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FABB8: beq         $a0, $at, L_800FABCC
    if (ctx->r4 == ctx->r1) {
        // 0x800FABBC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FABCC;
    }
    // 0x800FABBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FABC0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FABC4: bne         $a0, $at, L_800FABF0
    if (ctx->r4 != ctx->r1) {
        // 0x800FABC8: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FABF0;
    }
    // 0x800FABC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FABCC:
    // 0x800FABCC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FABD0: addiu       $s0, $s0, 0x538
    ctx->r16 = ADD32(ctx->r16, 0X538);
    // 0x800FABD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FABD8:
    // 0x800FABD8: jal         0x80023624
    // 0x800FABDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FABDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FABE0: jal         0x800A3040
    // 0x800FABE4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FABE4: nop

    after_1:
    // 0x800FABE8: b           L_800FABD8
    // 0x800FABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FABD8;
    // 0x800FABEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FABF0:
    // 0x800FABF0: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FABF4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FABF8: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FABFC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAC00: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAC04: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAC08: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAC0C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAC10: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAC14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAC18: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAC1C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FAC20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAC24: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FAC28: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FAC2C: bnel        $at, $zero, L_800FAC58
    if (ctx->r1 != 0) {
        // 0x800FAC30: lh          $v0, 0x8($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X8);
            goto L_800FAC58;
    }
    goto skip_0;
    // 0x800FAC30: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x800FAC34: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAC38: addiu       $s0, $s0, 0x558
    ctx->r16 = ADD32(ctx->r16, 0X558);
L_800FAC3C:
    // 0x800FAC3C: jal         0x80023624
    // 0x800FAC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAC44: jal         0x800A3040
    // 0x800FAC48: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAC48: nop

    after_3:
    // 0x800FAC4C: b           L_800FAC3C
    // 0x800FAC50: nop

        goto L_800FAC3C;
    // 0x800FAC50: nop

    // 0x800FAC54: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
L_800FAC58:
    // 0x800FAC58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAC5C: jr          $ra
    // 0x800FAC60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAC60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dbBattleStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132638: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013263C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132640: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132644: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132648: addiu       $a0, $a0, 0x2934
    ctx->r4 = ADD32(ctx->r4, 0X2934);
    // 0x8013264C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132650: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132654: jal         0x80007024
    // 0x80132658: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132658: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013265C: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x80132660: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132664: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132668: addiu       $t9, $t9, 0x3130
    ctx->r25 = ADD32(ctx->r25, 0X3130);
    // 0x8013266C: addiu       $t8, $t8, -0x6DC0
    ctx->r24 = ADD32(ctx->r24, -0X6DC0);
    // 0x80132670: addiu       $a0, $a0, 0x2950
    ctx->r4 = ADD32(ctx->r4, 0X2950);
    // 0x80132674: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132678: jal         0x8000683C
    // 0x8013267C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8013267C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132688: jr          $ra
    // 0x8013268C: nop

    return;
    // 0x8013268C: nop

;}
RECOMP_FUNC void ftCommonOttottoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142B08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80142B0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142B14: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142B18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80142B1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142B20: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80142B24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80142B28: jal         0x800E6F24
    // 0x80142B2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80142B2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80142B30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80142B34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80142B38: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x80142B3C: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80142B40: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80142B44: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80142B48: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    // 0x80142B4C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80142B50: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80142B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142B58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142B5C: jr          $ra
    // 0x80142B60: nop

    return;
    // 0x80142B60: nop

;}
RECOMP_FUNC void mnVSRecordGetSDPercent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134A24: jal         0x80131C0C
    // 0x80134A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnVSRecordGetTKO(rdram, ctx);
        goto after_0;
    // 0x80134A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80134A2C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80134A30: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80134A34: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80134A38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80134A3C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80134A40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134A44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80134A48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80134A4C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80134A50: lhu         $t8, 0x4506($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X4506);
    // 0x80134A54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80134A58: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134A5C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80134A60: bgez        $t8, L_80134A78
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80134A64: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80134A78;
    }
    // 0x80134A64: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134A68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80134A6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134A70: nop

    // 0x80134A74: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_80134A78:
    // 0x80134A78: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80134A7C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80134A80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134A88: bc1tl       L_80134A9C
    if (c1cs) {
        // 0x80134A8C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80134A9C;
    }
    goto skip_0;
    // 0x80134A8C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_0:
    // 0x80134A90: b           L_80134A9C
    // 0x80134A94: div.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
        goto L_80134A9C;
    // 0x80134A94: div.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80134A98: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80134A9C:
    // 0x80134A9C: mul.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80134AA0: jr          $ra
    // 0x80134AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80134AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itTaruBombRollSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184E4C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80184E50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80184E54: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80184E58: addiu       $a1, $a1, -0x4A2C
    ctx->r5 = ADD32(ctx->r5, -0X4A2C);
    // 0x80184E5C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80184E60: jal         0x80172EC8
    // 0x80184E64: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80184E64: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x80184E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80184E70: jr          $ra
    // 0x80184E74: nop

    return;
    // 0x80184E74: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeScene2Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133470: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133474: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80133478: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013347C: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x80133480: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80133484: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133488: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8013348C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80133490: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133498: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8013349C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801334A0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801334A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801334A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801334AC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801334B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801334B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x801334B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801334BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801334C0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801334C4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801334C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801334CC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801334D0: jal         0x8000B93C
    // 0x801334D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801334D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801334D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801334DC: sw          $v0, 0x4CE8($at)
    MEM_W(0X4CE8, ctx->r1) = ctx->r2;
    // 0x801334E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801334E4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801334E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801334EC: jal         0x80008CF0
    // 0x801334F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x801334F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801334F4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x801334F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801334FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133500: jal         0x80008CF0
    // 0x80133504: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x80133504: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    after_2:
    // 0x80133508: jal         0x801333DC
    // 0x8013350C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    mvOpeningRoomInitScene2Cameras(rdram, ctx);
        goto after_3;
    // 0x8013350C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x80133510: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80133514: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80133518: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8013351C: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80133520: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80133524: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133528: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013352C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133530: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133534: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80133538: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8013353C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80133540: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80133544: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133548: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013354C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133550: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133558: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013355C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133560: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133564: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133568: jal         0x8000B93C
    // 0x8013356C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcMakeCameraGObj(rdram, ctx);
        goto after_4;
    // 0x8013356C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80133570: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133574: sw          $v0, 0x4CEC($at)
    MEM_W(0X4CEC, ctx->r1) = ctx->r2;
    // 0x80133578: jal         0x801333DC
    // 0x8013357C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRoomInitScene2Cameras(rdram, ctx);
        goto after_5;
    // 0x8013357C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80133580: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133584: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133588: jr          $ra
    // 0x8013358C: nop

    return;
    // 0x8013358C: nop

;}
RECOMP_FUNC void itBombHeiWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177304: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80177308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017730C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80177310: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80177314: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80177318: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8017731C: lw          $t7, 0x2D4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2D4);
    // 0x80177320: addiu       $t9, $t9, 0x33F8
    ctx->r25 = ADD32(ctx->r25, 0X33F8);
    // 0x80177324: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80177328: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017732C: addiu       $t1, $t1, 0x34C0
    ctx->r9 = ADD32(ctx->r9, 0X34C0);
    // 0x80177330: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80177334: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80177338: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8017733C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80177340: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80177344: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80177348: bnel        $a1, $at, L_801773DC
    if (ctx->r5 != ctx->r1) {
        // 0x8017734C: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_801773DC;
    }
    goto skip_0;
    // 0x8017734C: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80177350: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80177354: jal         0x80177260
    // 0x80177358: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    itBombHeiWalkGetLR(rdram, ctx);
        goto after_0;
    // 0x80177358: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017735C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80177360: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80177364: bne         $v0, $zero, L_80177388
    if (ctx->r2 != 0) {
        // 0x80177368: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80177388;
    }
    // 0x80177368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8017736C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80177370: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80177374: jal         0x80018994
    // 0x80177378: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80177378: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x8017737C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80177380: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80177384: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
L_80177388:
    // 0x80177388: bgez        $a0, L_801773A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8017738C: lui         $at, 0xC1C0
        ctx->r1 = S32(0XC1C0 << 16);
            goto L_801773A8;
    }
    // 0x8017738C: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x80177390: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80177394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177398: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8017739C: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    // 0x801773A0: b           L_801773C4
    // 0x801773A4: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
        goto L_801773C4;
    // 0x801773A4: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
L_801773A8:
    // 0x801773A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801773AC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801773B0: swc1        $f6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f6.u32l;
    // 0x801773B4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x801773B8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801773BC: sw          $t4, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r12;
    // 0x801773C0: sw          $t6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r14;
L_801773C4:
    // 0x801773C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801773C8: jal         0x801779A8
    // 0x801773CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    itBombHeiWalkSetStatus(rdram, ctx);
        goto after_2;
    // 0x801773CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x801773D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801773D4: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x801773D8: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
L_801773DC:
    // 0x801773DC: sh          $t7, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r15;
    // 0x801773E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801773E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801773E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801773EC: jr          $ra
    // 0x801773F0: nop

    return;
    // 0x801773F0: nop

;}
RECOMP_FUNC void ftKirbySpecialHiLandingProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160E74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160E78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80160E7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80160E80: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160E84: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x80160E88: jal         0x80160BB0
    // 0x80160E8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialHiUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80160E8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160E90: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x80160E94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80160E98: bne         $t6, $zero, L_80160EB0
    if (ctx->r14 != 0) {
        // 0x80160E9C: nop
    
            goto L_80160EB0;
    }
    // 0x80160E9C: nop

    // 0x80160EA0: jal         0x800D8C14
    // 0x80160EA4: nop

    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_1;
    // 0x80160EA4: nop

    after_1:
    // 0x80160EA8: b           L_80160F00
    // 0x80160EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80160F00;
    // 0x80160EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80160EB0:
    // 0x80160EB0: jal         0x800D9414
    // 0x80160EB4: nop

    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_2;
    // 0x80160EB4: nop

    after_2:
    // 0x80160EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160EBC: jal         0x800D8FA8
    // 0x80160EC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_3;
    // 0x80160EC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80160EC4: bne         $v0, $zero, L_80160EFC
    if (ctx->r2 != 0) {
        // 0x80160EC8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80160EFC;
    }
    // 0x80160EC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80160ECC: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80160ED0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80160ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160ED8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80160EDC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80160EE0: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x80160EE4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80160EE8: jal         0x800D8FC8
    // 0x80160EEC: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_4;
    // 0x80160EEC: nop

    after_4:
    // 0x80160EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160EF4: jal         0x800D9074
    // 0x80160EF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_5;
    // 0x80160EF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
L_80160EFC:
    // 0x80160EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80160F00:
    // 0x80160F00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80160F04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80160F08: jr          $ra
    // 0x80160F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80160F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gcPlayCObjCamAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010344: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80010348: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001034C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80010350: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80010354: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80010358: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001035C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80010360: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010364: lwc1        $f4, -0x1F74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1F74);
    // 0x80010368: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8001036C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80010370: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80010374: nop

    // 0x80010378: bc1tl       L_80010564
    if (c1cs) {
        // 0x8001037C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80010564;
    }
    goto skip_0;
    // 0x8001037C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80010380: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x80010384: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010388: beq         $s0, $zero, L_8001053C
    if (ctx->r16 == 0) {
        // 0x8001038C: nop
    
            goto L_8001053C;
    }
    // 0x8001038C: nop

    // 0x80010390: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80010394: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80010398: nop

    // 0x8001039C: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_800103A0:
    // 0x800103A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800103A4: beql        $t6, $zero, L_80010530
    if (ctx->r14 == 0) {
        // 0x800103A8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80010530;
    }
    goto skip_1;
    // 0x800103A8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800103AC: lwc1        $f6, -0x1F70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1F70);
    // 0x800103B0: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800103B4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800103B8: nop

    // 0x800103BC: bc1tl       L_800103D8
    if (c1cs) {
        // 0x800103C0: lw          $t7, 0x4($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X4);
            goto L_800103D8;
    }
    goto skip_2;
    // 0x800103C0: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x800103C4: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800103C8: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800103CC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800103D0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800103D4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
L_800103D8:
    // 0x800103D8: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800103DC: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800103E0: bnel        $t9, $zero, L_80010530
    if (ctx->r25 != 0) {
        // 0x800103E4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80010530;
    }
    goto skip_3;
    // 0x800103E4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800103E8: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    // 0x800103EC: addiu       $t1, $t0, -0x19
    ctx->r9 = ADD32(ctx->r8, -0X19);
    // 0x800103F0: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x800103F4: beq         $at, $zero, L_8001052C
    if (ctx->r1 == 0) {
        // 0x800103F8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8001052C;
    }
    // 0x800103F8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800103FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010400: addu        $at, $at, $t1
    gpr jr_addend_80010408 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80010404: lw          $t1, -0x1F6C($at)
    ctx->r9 = ADD32(ctx->r1, -0X1F6C);
    // 0x80010408: jr          $t1
    // 0x8001040C: nop

    switch (jr_addend_80010408 >> 2) {
        case 0: goto L_80010410; break;
        case 1: goto L_80010420; break;
        case 2: goto L_80010430; break;
        case 3: goto L_80010440; break;
        case 4: goto L_80010490; break;
        case 5: goto L_800104A0; break;
        case 6: goto L_800104B0; break;
        case 7: goto L_800104C0; break;
        case 8: goto L_80010510; break;
        case 9: goto L_80010520; break;
        default: switch_error(__func__, 0x80010408, 0x8003E094);
    }
    // 0x8001040C: nop

L_80010410:
    // 0x80010410: jal         0x8000CB94
    // 0x80010414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_0;
    // 0x80010414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80010418: b           L_8001052C
    // 0x8001041C: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x8001041C: swc1        $f0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f0.u32l;
L_80010420:
    // 0x80010420: jal         0x8000CB94
    // 0x80010424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_1;
    // 0x80010424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80010428: b           L_8001052C
    // 0x8001042C: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x8001042C: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_80010430:
    // 0x80010430: jal         0x8000CB94
    // 0x80010434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_2;
    // 0x80010434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80010438: b           L_8001052C
    // 0x8001043C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x8001043C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_80010440:
    // 0x80010440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010444: jal         0x8000CB94
    // 0x80010448: addiu       $s2, $s1, 0x3C
    ctx->r18 = ADD32(ctx->r17, 0X3C);
    gcGetAObjValue(rdram, ctx);
        goto after_3;
    // 0x80010448: addiu       $s2, $s1, 0x3C
    ctx->r18 = ADD32(ctx->r17, 0X3C);
    after_3:
    // 0x8001044C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80010450: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80010454: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80010458: bc1fl       L_8001046C
    if (!c1cs) {
        // 0x8001045C: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_8001046C;
    }
    goto skip_4;
    // 0x8001045C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_4:
    // 0x80010460: b           L_8001047C
    // 0x80010464: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_8001047C;
    // 0x80010464: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x80010468: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_8001046C:
    // 0x8001046C: nop

    // 0x80010470: bc1fl       L_80010480
    if (!c1cs) {
        // 0x80010474: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80010480;
    }
    goto skip_5;
    // 0x80010474: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_5:
    // 0x80010478: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_8001047C:
    // 0x8001047C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80010480:
    // 0x80010480: jal         0x8001E530
    // 0x80010484: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    syInterpCubic(rdram, ctx);
        goto after_4;
    // 0x80010484: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x80010488: b           L_80010530
    // 0x8001048C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_80010530;
    // 0x8001048C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80010490:
    // 0x80010490: jal         0x8000CB94
    // 0x80010494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_5;
    // 0x80010494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80010498: b           L_8001052C
    // 0x8001049C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x8001049C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
L_800104A0:
    // 0x800104A0: jal         0x8000CB94
    // 0x800104A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_6;
    // 0x800104A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800104A8: b           L_8001052C
    // 0x800104AC: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x800104AC: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
L_800104B0:
    // 0x800104B0: jal         0x8000CB94
    // 0x800104B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_7;
    // 0x800104B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800104B8: b           L_8001052C
    // 0x800104BC: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x800104BC: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
L_800104C0:
    // 0x800104C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800104C4: jal         0x8000CB94
    // 0x800104C8: addiu       $s2, $s1, 0x48
    ctx->r18 = ADD32(ctx->r17, 0X48);
    gcGetAObjValue(rdram, ctx);
        goto after_8;
    // 0x800104C8: addiu       $s2, $s1, 0x48
    ctx->r18 = ADD32(ctx->r17, 0X48);
    after_8:
    // 0x800104CC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800104D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800104D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800104D8: bc1fl       L_800104EC
    if (!c1cs) {
        // 0x800104DC: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_800104EC;
    }
    goto skip_6;
    // 0x800104DC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_6:
    // 0x800104E0: b           L_800104FC
    // 0x800104E4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_800104FC;
    // 0x800104E4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800104E8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_800104EC:
    // 0x800104EC: nop

    // 0x800104F0: bc1fl       L_80010500
    if (!c1cs) {
        // 0x800104F4: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80010500;
    }
    goto skip_7;
    // 0x800104F4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_7:
    // 0x800104F8: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_800104FC:
    // 0x800104FC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80010500:
    // 0x80010500: jal         0x8001E530
    // 0x80010504: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    syInterpCubic(rdram, ctx);
        goto after_9;
    // 0x80010504: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_9:
    // 0x80010508: b           L_80010530
    // 0x8001050C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_80010530;
    // 0x8001050C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80010510:
    // 0x80010510: jal         0x8000CB94
    // 0x80010514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_10;
    // 0x80010514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80010518: b           L_8001052C
    // 0x8001051C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
        goto L_8001052C;
    // 0x8001051C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
L_80010520:
    // 0x80010520: jal         0x8000CB94
    // 0x80010524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_11;
    // 0x80010524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80010528: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_8001052C:
    // 0x8001052C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80010530:
    // 0x80010530: bnel        $s0, $zero, L_800103A0
    if (ctx->r16 != 0) {
        // 0x80010534: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_800103A0;
    }
    goto skip_8;
    // 0x80010534: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_8:
    // 0x80010538: lwc1        $f0, 0x74($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X74);
L_8001053C:
    // 0x8001053C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010540: lwc1        $f4, -0x1F44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1F44);
    // 0x80010544: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010548: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8001054C: nop

    // 0x80010550: bc1fl       L_80010564
    if (!c1cs) {
        // 0x80010554: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80010564;
    }
    goto skip_9;
    // 0x80010554: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_9:
    // 0x80010558: lwc1        $f6, -0x1F40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1F40);
    // 0x8001055C: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x80010560: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80010564:
    // 0x80010564: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80010568: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001056C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80010570: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80010574: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80010578: jr          $ra
    // 0x8001057C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001057C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftCommonCliffClimbQuick2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801455A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801455A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801455A8: jal         0x80145490
    // 0x801455AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x801455AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801455B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801455B4: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x801455B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801455BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801455C0: jal         0x800E6F24
    // 0x801455C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801455C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801455C8: jal         0x8014557C
    // 0x801455CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801455CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801455D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801455D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801455D8: jr          $ra
    // 0x801455DC: nop

    return;
    // 0x801455DC: nop

;}
RECOMP_FUNC void func_8000A2B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A2B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A2BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A2C0: jal         0x80007CF4
    // 0x8000A2C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A2C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A2C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A2CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A2D0: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x8000A2D4: jal         0x80007B98
    // 0x8000A2D8: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A2D8: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    after_1:
    // 0x8000A2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A2E4: jr          $ra
    // 0x8000A2E8: nop

    return;
    // 0x8000A2E8: nop

;}
RECOMP_FUNC void itGShellWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017874C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178754: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80178758: jal         0x801735A0
    // 0x8017875C: addiu       $a1, $a1, -0x76D0
    ctx->r5 = ADD32(ctx->r5, -0X76D0);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017875C: addiu       $a1, $a1, -0x76D0
    ctx->r5 = ADD32(ctx->r5, -0X76D0);
    after_0:
    // 0x80178760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017876C: jr          $ra
    // 0x80178770: nop

    return;
    // 0x80178770: nop

;}
RECOMP_FUNC void ftCommonAttackS4CheckInterruptDash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801501E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801501E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801501E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801501EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801501F0: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x801501F4: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x801501F8: lw          $a1, 0x9C8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X9C8);
    // 0x801501FC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80150200: mflo        $t8
    ctx->r24 = lo;
    // 0x80150204: slti        $at, $t8, 0x38
    ctx->r1 = SIGNED(ctx->r24) < 0X38 ? 1 : 0;
    // 0x80150208: bnel        $at, $zero, L_801502FC
    if (ctx->r1 != 0) {
        // 0x8015020C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801502FC;
    }
    goto skip_0;
    // 0x8015020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80150210: lhu         $t9, 0x1BE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80150214: lhu         $t0, 0x1B4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80150218: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8015021C: beql        $t1, $zero, L_801502FC
    if (ctx->r9 == 0) {
        // 0x80150220: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801502FC;
    }
    goto skip_1;
    // 0x80150220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80150224: lw          $a0, 0x84C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84C);
    // 0x80150228: beql        $a0, $zero, L_801502DC
    if (ctx->r4 == 0) {
        // 0x8015022C: lw          $t5, 0x100($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X100);
            goto L_801502DC;
    }
    goto skip_2;
    // 0x8015022C: lw          $t5, 0x100($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X100);
    skip_2:
    // 0x80150230: lhu         $t2, 0x1BC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X1BC);
    // 0x80150234: lhu         $t3, 0x1B8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X1B8);
    // 0x80150238: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015023C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80150240: bnel        $t4, $zero, L_80150284
    if (ctx->r12 != 0) {
        // 0x80150244: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80150284;
    }
    goto skip_3;
    // 0x80150244: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_3:
    // 0x80150248: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8015024C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80150250: beq         $v0, $at, L_80150280
    if (ctx->r2 == ctx->r1) {
        // 0x80150254: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80150280;
    }
    // 0x80150254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80150258: bnel        $v0, $at, L_80150298
    if (ctx->r2 != ctx->r1) {
        // 0x8015025C: lw          $v0, 0x10($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X10);
            goto L_80150298;
    }
    goto skip_4;
    // 0x8015025C: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x80150260: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80150264: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80150268: jal         0x80172890
    // 0x8015026C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    itMainCheckShootNoAmmo(rdram, ctx);
        goto after_0;
    // 0x8015026C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80150270: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80150274: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80150278: beq         $v0, $zero, L_80150294
    if (ctx->r2 == 0) {
        // 0x8015027C: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80150294;
    }
    // 0x8015027C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80150280:
    // 0x80150280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80150284:
    // 0x80150284: jal         0x80146690
    // 0x80150288: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80150288: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_1:
    // 0x8015028C: b           L_801502FC
    // 0x80150290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801502FC;
    // 0x80150290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150294:
    // 0x80150294: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_80150298:
    // 0x80150298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015029C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801502A0: beq         $v0, $at, L_801502B8
    if (ctx->r2 == ctx->r1) {
        // 0x801502A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801502B8;
    }
    // 0x801502A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801502A8: beq         $v0, $at, L_801502C8
    if (ctx->r2 == ctx->r1) {
        // 0x801502AC: nop
    
            goto L_801502C8;
    }
    // 0x801502AC: nop

    // 0x801502B0: b           L_801502DC
    // 0x801502B4: lw          $t5, 0x100($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X100);
        goto L_801502DC;
    // 0x801502B4: lw          $t5, 0x100($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X100);
L_801502B8:
    // 0x801502B8: jal         0x80146E94
    // 0x801502BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_2;
    // 0x801502BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x801502C0: b           L_801502FC
    // 0x801502C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801502FC;
    // 0x801502C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801502C8:
    // 0x801502C8: jal         0x80147844
    // 0x801502CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonItemShootSetStatus(rdram, ctx);
        goto after_3;
    // 0x801502CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x801502D0: b           L_801502FC
    // 0x801502D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801502FC;
    // 0x801502D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801502D8: lw          $t5, 0x100($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X100);
L_801502DC:
    // 0x801502DC: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x801502E0: bgezl       $t7, L_801502FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801502E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801502FC;
    }
    goto skip_5;
    // 0x801502E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x801502E8: jal         0x8014FFE0
    // 0x801502EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttackS4SetStatus(rdram, ctx);
        goto after_4;
    // 0x801502EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x801502F0: b           L_801502FC
    // 0x801502F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801502FC;
    // 0x801502F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801502F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801502FC:
    // 0x801502FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80150304: jr          $ra
    // 0x80150308: nop

    return;
    // 0x80150308: nop

;}
RECOMP_FUNC void syRdpResetSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007174: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80007178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000717C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80007180: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80007184: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x80007188: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8000718C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80007190: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80007194: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80007198: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8000719C: jal         0x800048F8
    // 0x800071A0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    syTaskmanInitSegmentF(rdram, ctx);
        goto after_0;
    // 0x800071A0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    after_0:
    // 0x800071A4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800071A8: lui         $t6, 0xFE00
    ctx->r14 = S32(0XFE00 << 16);
    // 0x800071AC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800071B0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800071B4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800071B8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800071BC: lw          $t7, 0x6670($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6670);
    // 0x800071C0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800071C4: addiu       $a0, $a0, 0x66A0
    ctx->r4 = ADD32(ctx->r4, 0X66A0);
    // 0x800071C8: jal         0x8000711C
    // 0x800071CC: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    syRdpSetDefaultViewport(rdram, ctx);
        goto after_1;
    // 0x800071CC: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    after_1:
    // 0x800071D0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800071D4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800071D8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800071DC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800071E0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800071E4: addiu       $t5, $t5, -0x4868
    ctx->r13 = ADD32(ctx->r13, -0X4868);
    // 0x800071E8: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x800071EC: addiu       $t0, $t0, 0x6678
    ctx->r8 = ADD32(ctx->r8, 0X6678);
    // 0x800071F0: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x800071F4: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x800071F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800071FC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80007200: addiu       $t1, $zero, 0x140
    ctx->r9 = ADD32(0, 0X140);
    // 0x80007204: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80007208: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8000720C: mflo        $t9
    ctx->r25 = lo;
    // 0x80007210: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80007214: addiu       $t2, $t2, 0x667C
    ctx->r10 = ADD32(ctx->r10, 0X667C);
    // 0x80007218: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000721C: addiu       $t3, $zero, 0xF0
    ctx->r11 = ADD32(0, 0XF0);
    // 0x80007220: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80007224: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80007228: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8000722C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80007230: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80007234: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80007238: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8000723C: mflo        $t4
    ctx->r12 = lo;
    // 0x80007240: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80007244: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80007248: bne         $t1, $zero, L_80007254
    if (ctx->r9 != 0) {
        // 0x8000724C: nop
    
            goto L_80007254;
    }
    // 0x8000724C: nop

    // 0x80007250: break       7
    do_break(2147512912);
L_80007254:
    // 0x80007254: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80007258: bne         $t1, $at, L_8000726C
    if (ctx->r9 != ctx->r1) {
        // 0x8000725C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000726C;
    }
    // 0x8000725C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007260: bne         $t8, $at, L_8000726C
    if (ctx->r24 != ctx->r1) {
        // 0x80007264: nop
    
            goto L_8000726C;
    }
    // 0x80007264: nop

    // 0x80007268: break       6
    do_break(2147512936);
L_8000726C:
    // 0x8000726C: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x80007270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80007274: mflo        $t5
    ctx->r13 = lo;
    // 0x80007278: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x8000727C: nop

    // 0x80007280: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007284: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80007288: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000728C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80007290: nop

    // 0x80007294: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80007298: mflo        $t6
    ctx->r14 = lo;
    // 0x8000729C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800072A0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800072A4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800072A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800072AC: bne         $t3, $zero, L_800072B8
    if (ctx->r11 != 0) {
        // 0x800072B0: nop
    
            goto L_800072B8;
    }
    // 0x800072B0: nop

    // 0x800072B4: break       7
    do_break(2147513012);
L_800072B8:
    // 0x800072B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800072BC: bne         $t3, $at, L_800072D0
    if (ctx->r11 != ctx->r1) {
        // 0x800072C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800072D0;
    }
    // 0x800072C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800072C4: bne         $t4, $at, L_800072D0
    if (ctx->r12 != ctx->r1) {
        // 0x800072C8: nop
    
            goto L_800072D0;
    }
    // 0x800072C8: nop

    // 0x800072CC: break       6
    do_break(2147513036);
L_800072D0:
    // 0x800072D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800072D4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800072D8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800072DC: nop

    // 0x800072E0: andi        $t4, $t8, 0xFFF
    ctx->r12 = ctx->r24 & 0XFFF;
    // 0x800072E4: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800072E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800072EC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800072F0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x800072F4: div         $zero, $a0, $t1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r9)));
    // 0x800072F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800072FC: bne         $t1, $zero, L_80007308
    if (ctx->r9 != 0) {
        // 0x80007300: nop
    
            goto L_80007308;
    }
    // 0x80007300: nop

    // 0x80007304: break       7
    do_break(2147513092);
L_80007308:
    // 0x80007308: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000730C: bne         $t1, $at, L_80007320
    if (ctx->r9 != ctx->r1) {
        // 0x80007310: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80007320;
    }
    // 0x80007310: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007314: bne         $a0, $at, L_80007320
    if (ctx->r4 != ctx->r1) {
        // 0x80007318: nop
    
            goto L_80007320;
    }
    // 0x80007318: nop

    // 0x8000731C: break       6
    do_break(2147513116);
L_80007320:
    // 0x80007320: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007324: mflo        $t7
    ctx->r15 = lo;
    // 0x80007328: subu        $t8, $a0, $t7
    ctx->r24 = SUB32(ctx->r4, ctx->r15);
    // 0x8000732C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80007330: div         $zero, $a1, $t3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r11)));
    // 0x80007334: mflo        $t7
    ctx->r15 = lo;
    // 0x80007338: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000733C: nop

    // 0x80007340: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007344: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80007348: mflo        $t8
    ctx->r24 = lo;
    // 0x8000734C: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x80007350: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80007354: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80007358: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000735C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80007360: nop

    // 0x80007364: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x80007368: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8000736C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80007370: bne         $t3, $zero, L_8000737C
    if (ctx->r11 != 0) {
        // 0x80007374: nop
    
            goto L_8000737C;
    }
    // 0x80007374: nop

    // 0x80007378: break       7
    do_break(2147513208);
L_8000737C:
    // 0x8000737C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80007380: bne         $t3, $at, L_80007394
    if (ctx->r11 != ctx->r1) {
        // 0x80007384: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80007394;
    }
    // 0x80007384: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007388: bne         $a1, $at, L_80007394
    if (ctx->r5 != ctx->r1) {
        // 0x8000738C: nop
    
            goto L_80007394;
    }
    // 0x8000738C: nop

    // 0x80007390: break       6
    do_break(2147513232);
L_80007394:
    // 0x80007394: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80007398: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8000739C: nop

    // 0x800073A0: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x800073A4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800073A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800073AC: lw          $a3, -0x48B0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X48B0);
    // 0x800073B0: beql        $a3, $zero, L_800073C4
    if (ctx->r7 == 0) {
        // 0x800073B4: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_800073C4;
    }
    goto skip_0;
    // 0x800073B4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800073B8: jalr        $a3
    // 0x800073BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_2;
    // 0x800073BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x800073C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800073C4:
    // 0x800073C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800073C8: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800073CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800073D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800073D4: jr          $ra
    // 0x800073D8: nop

    return;
    // 0x800073D8: nop

;}
RECOMP_FUNC void wpMapCheckAllRebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167C38: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80167C3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80167C40: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80167C44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80167C48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80167C4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80167C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80167C54: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80167C58: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80167C5C: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x80167C60: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x80167C64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80167C68: lhu         $v0, 0x82($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X82);
    // 0x80167C6C: lhu         $t6, 0x80($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X80);
    // 0x80167C70: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // 0x80167C74: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x80167C78: xor         $t7, $t6, $v0
    ctx->r15 = ctx->r14 ^ ctx->r2;
    // 0x80167C7C: and         $v1, $t7, $v0
    ctx->r3 = ctx->r15 & ctx->r2;
    // 0x80167C80: andi        $v1, $v1, 0xC21
    ctx->r3 = ctx->r3 & 0XC21;
    // 0x80167C84: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80167C88: and         $t8, $v1, $a1
    ctx->r24 = ctx->r3 & ctx->r5;
    // 0x80167C8C: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x80167C90: beq         $t0, $zero, L_80167CF0
    if (ctx->r8 == 0) {
        // 0x80167C94: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_80167CF0;
    }
    // 0x80167C94: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80167C98: addiu       $s1, $s2, 0x2C
    ctx->r17 = ADD32(ctx->r18, 0X2C);
    // 0x80167C9C: addiu       $a1, $s1, 0xA8
    ctx->r5 = ADD32(ctx->r17, 0XA8);
    // 0x80167CA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80167CA4: jal         0x800C7C0C
    // 0x80167CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonSim2D(rdram, ctx);
        goto after_0;
    // 0x80167CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80167CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80167CB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80167CB4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80167CB8: nop

    // 0x80167CBC: bc1fl       L_80167CF4
    if (!c1cs) {
        // 0x80167CC0: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80167CF4;
    }
    goto skip_0;
    // 0x80167CC0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80167CC4: jal         0x800C7B08
    // 0x80167CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonReflect2D(rdram, ctx);
        goto after_1;
    // 0x80167CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80167CCC: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80167CD0: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80167CD4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80167CD8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80167CDC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80167CE0: lwc1        $f18, 0x3C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80167CE4: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80167CE8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80167CEC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
L_80167CF0:
    // 0x80167CF0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80167CF4:
    // 0x80167CF4: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // 0x80167CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167CFC: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x80167D00: beq         $t2, $zero, L_80167D58
    if (ctx->r10 == 0) {
        // 0x80167D04: addiu       $s1, $s2, 0x2C
        ctx->r17 = ADD32(ctx->r18, 0X2C);
            goto L_80167D58;
    }
    // 0x80167D04: addiu       $s1, $s2, 0x2C
    ctx->r17 = ADD32(ctx->r18, 0X2C);
    // 0x80167D08: addiu       $a1, $s1, 0xBC
    ctx->r5 = ADD32(ctx->r17, 0XBC);
    // 0x80167D0C: jal         0x800C7C0C
    // 0x80167D10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_2;
    // 0x80167D10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_2:
    // 0x80167D14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80167D18: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80167D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167D20: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80167D24: nop

    // 0x80167D28: bc1fl       L_80167D5C
    if (!c1cs) {
        // 0x80167D2C: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80167D5C;
    }
    goto skip_1;
    // 0x80167D2C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80167D30: jal         0x800C7B08
    // 0x80167D34: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x80167D34: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_3:
    // 0x80167D38: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80167D3C: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80167D40: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80167D44: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80167D48: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80167D4C: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80167D50: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80167D54: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
L_80167D58:
    // 0x80167D58: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_80167D5C:
    // 0x80167D5C: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // 0x80167D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167D64: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80167D68: beq         $t4, $zero, L_80167DB8
    if (ctx->r12 == 0) {
        // 0x80167D6C: addiu       $s1, $s2, 0x2C
        ctx->r17 = ADD32(ctx->r18, 0X2C);
            goto L_80167DB8;
    }
    // 0x80167D6C: addiu       $s1, $s2, 0x2C
    ctx->r17 = ADD32(ctx->r18, 0X2C);
    // 0x80167D70: addiu       $a1, $s1, 0x94
    ctx->r5 = ADD32(ctx->r17, 0X94);
    // 0x80167D74: jal         0x800C7C0C
    // 0x80167D78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_4;
    // 0x80167D78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_4:
    // 0x80167D7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80167D80: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80167D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167D88: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80167D8C: nop

    // 0x80167D90: bc1fl       L_80167DBC
    if (!c1cs) {
        // 0x80167D94: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_80167DBC;
    }
    goto skip_2;
    // 0x80167D94: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80167D98: jal         0x800C7B08
    // 0x80167D9C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    lbCommonReflect2D(rdram, ctx);
        goto after_5;
    // 0x80167D9C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_5:
    // 0x80167DA0: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80167DA4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80167DA8: lwc1        $f18, 0x38($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80167DAC: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80167DB0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80167DB4: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
L_80167DB8:
    // 0x80167DB8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_80167DBC:
    // 0x80167DBC: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // 0x80167DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167DC4: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x80167DC8: beq         $t6, $zero, L_80167E18
    if (ctx->r14 == 0) {
        // 0x80167DCC: addiu       $s1, $s2, 0x2C
        ctx->r17 = ADD32(ctx->r18, 0X2C);
            goto L_80167E18;
    }
    // 0x80167DCC: addiu       $s1, $s2, 0x2C
    ctx->r17 = ADD32(ctx->r18, 0X2C);
    // 0x80167DD0: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x80167DD4: jal         0x800C7C0C
    // 0x80167DD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_6;
    // 0x80167DD8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_6:
    // 0x80167DDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80167DE0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80167DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167DE8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80167DEC: nop

    // 0x80167DF0: bc1f        L_80167E18
    if (!c1cs) {
        // 0x80167DF4: nop
    
            goto L_80167E18;
    }
    // 0x80167DF4: nop

    // 0x80167DF8: jal         0x800C7B08
    // 0x80167DFC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    lbCommonReflect2D(rdram, ctx);
        goto after_7;
    // 0x80167DFC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_7:
    // 0x80167E00: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80167E04: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80167E08: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80167E0C: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80167E10: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80167E14: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
L_80167E18:
    // 0x80167E18: beq         $s4, $zero, L_80167E54
    if (ctx->r20 == 0) {
        // 0x80167E1C: addiu       $a0, $s2, 0x20
        ctx->r4 = ADD32(ctx->r18, 0X20);
            goto L_80167E54;
    }
    // 0x80167E1C: addiu       $a0, $s2, 0x20
    ctx->r4 = ADD32(ctx->r18, 0X20);
    // 0x80167E20: jal         0x800C7AE0
    // 0x80167E24: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    lbCommonScale2D(rdram, ctx);
        goto after_8;
    // 0x80167E24: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_8:
    // 0x80167E28: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80167E2C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80167E30: beql        $t7, $zero, L_80167E58
    if (ctx->r15 == 0) {
        // 0x80167E34: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80167E58;
    }
    goto skip_3;
    // 0x80167E34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80167E38: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80167E3C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80167E40: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80167E44: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x80167E48: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80167E4C: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80167E50: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
L_80167E54:
    // 0x80167E54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80167E58:
    // 0x80167E58: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80167E5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80167E60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80167E64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80167E68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80167E6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80167E70: jr          $ra
    // 0x80167E74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80167E74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void syMatrixTraRotDF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D35C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D360: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D364: lwc1        $f6, -0x1C34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C34);
    // 0x8001D368: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001D36C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D370: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D374: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001D378: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D37C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D380: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001D384: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001D388: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001D38C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D390: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D394: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D398: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D39C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D3A0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8001D3A4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8001D3A8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8001D3AC: jal         0x8001BC44
    // 0x8001D3B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syMatrixTraRotRF(rdram, ctx);
        goto after_0;
    // 0x8001D3B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8001D3B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D3B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D3BC: jr          $ra
    // 0x8001D3C0: nop

    return;
    // 0x8001D3C0: nop

;}
RECOMP_FUNC void itDogasMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182FD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80182FD8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80182FDC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80182FE0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80182FE4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80182FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80182FEC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80182FF0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182FF4: addiu       $a1, $a1, -0x4D40
    ctx->r5 = ADD32(ctx->r5, -0X4D40);
    // 0x80182FF8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80182FFC: jal         0x8016E174
    // 0x80183000: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80183000: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80183004: beq         $v0, $zero, L_801830C8
    if (ctx->r2 == 0) {
        // 0x80183008: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801830C8;
    }
    // 0x80183008: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018300C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80183010: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80183014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80183018: jal         0x80008CC0
    // 0x8018301C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8018301C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80183020: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80183024: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80183028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018302C: jal         0x80008CC0
    // 0x80183030: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80183030: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    after_2:
    // 0x80183034: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80183038: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8018303C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80183040: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80183044: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80183048: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018304C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
    // 0x80183050: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80183054: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80183058: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8018305C: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x80183060: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80183064: lwc1        $f4, 0x20($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80183068: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8018306C: sw          $t0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r8;
    // 0x80183070: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80183074: addiu       $t7, $t7, 0x2820
    ctx->r15 = ADD32(ctx->r15, 0X2820);
    // 0x80183078: addiu       $t9, $t9, 0x3624
    ctx->r25 = ADD32(ctx->r25, 0X3624);
    // 0x8018307C: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x80183080: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80183084: lw          $t2, 0x2D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2D4);
    // 0x80183088: lh          $t3, 0x2E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2E);
    // 0x8018308C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80183090: nop

    // 0x80183094: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80183098: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018309C: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x801830A0: lw          $t5, 0x2D4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2D4);
    // 0x801830A4: sh          $t4, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r12;
    // 0x801830A8: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x801830AC: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x801830B0: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x801830B4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801830B8: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x801830BC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x801830C0: jal         0x8000BD1C
    // 0x801830C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_3;
    // 0x801830C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
L_801830C8:
    // 0x801830C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801830CC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801830D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801830D4: jr          $ra
    // 0x801830D8: nop

    return;
    // 0x801830D8: nop

;}
RECOMP_FUNC void gmCameraMakeInterfaceCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E374: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010E378: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8010E37C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010E380: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8010E384: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8010E388: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010E38C: lui         $t9, 0x180
    ctx->r25 = S32(0X180 << 16);
    // 0x8010E390: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8010E394: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010E398: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8010E39C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8010E3A0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8010E3A4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8010E3A8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010E3AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010E3B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010E3B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010E3B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010E3BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010E3C0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010E3C4: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8010E3C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E3CC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010E3D0: jal         0x8000B93C
    // 0x8010E3D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010E3D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010E3D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010E3DC: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010E3E0: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x8010E3E4: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    // 0x8010E3E8: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x8010E3EC: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8010E3F0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8010E3F4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8010E3F8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8010E3FC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010E400: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010E404: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8010E408: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x8010E40C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E410: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010E414: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8010E418: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8010E41C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010E420: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010E424: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010E428: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010E42C: jal         0x80007080
    // 0x8010E430: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8010E430: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8010E434: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8010E438: lw          $t8, 0x80($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X80);
    // 0x8010E43C: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8010E440: sw          $t9, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r25;
    // 0x8010E444: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E448: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8010E44C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010E450: jr          $ra
    // 0x8010E454: nop

    return;
    // 0x8010E454: nop

;}
RECOMP_FUNC void ftCommonDokanEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801426D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801426D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801426D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801426DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801426E0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801426E4: jal         0x800DEE98
    // 0x801426E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801426E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801426EC: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x801426F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801426F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801426F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801426FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80142700: jal         0x800E6F24
    // 0x80142704: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80142704: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80142708: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8014270C: lw          $t0, 0xB2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB2C);
    // 0x80142710: addiu       $t1, $s0, 0xF8
    ctx->r9 = ADD32(ctx->r16, 0XF8);
    // 0x80142714: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80142718: addiu       $a1, $s0, 0xEC
    ctx->r5 = ADD32(ctx->r16, 0XEC);
    // 0x8014271C: addiu       $a2, $s0, 0xF0
    ctx->r6 = ADD32(ctx->r16, 0XF0);
    // 0x80142720: sw          $t0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r8;
    // 0x80142724: lw          $t9, 0xB30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB30);
    // 0x80142728: addiu       $a3, $s0, 0xF4
    ctx->r7 = ADD32(ctx->r16, 0XF4);
    // 0x8014272C: sw          $t9, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r25;
    // 0x80142730: lw          $t0, 0xB34($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB34);
    // 0x80142734: sw          $t0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r8;
    // 0x80142738: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8014273C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80142740: jal         0x800F9348
    // 0x80142744: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckProjectFloor(rdram, ctx);
        goto after_2;
    // 0x80142744: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x80142748: lbu         $t3, 0x18F($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18F);
    // 0x8014274C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80142750: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80142754: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80142758: sb          $t4, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r12;
    // 0x8014275C: beq         $v0, $zero, L_801427AC
    if (ctx->r2 == 0) {
        // 0x80142760: sw          $t5, 0xB3C($s0)
        MEM_W(0XB3C, ctx->r16) = ctx->r13;
            goto L_801427AC;
    }
    // 0x80142760: sw          $t5, 0xB3C($s0)
    MEM_W(0XB3C, ctx->r16) = ctx->r13;
    // 0x80142764: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80142768: beq         $v0, $at, L_801427AC
    if (ctx->r2 == ctx->r1) {
        // 0x8014276C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_801427AC;
    }
    // 0x8014276C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80142770: beq         $v0, $at, L_801427AC
    if (ctx->r2 == ctx->r1) {
        // 0x80142774: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801427AC;
    }
    // 0x80142774: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80142778: beq         $v0, $at, L_801427AC
    if (ctx->r2 == ctx->r1) {
        // 0x8014277C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_801427AC;
    }
    // 0x8014277C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80142780: beql        $v0, $at, L_801427B0
    if (ctx->r2 == ctx->r1) {
        // 0x80142784: sw          $zero, 0xB40($s0)
        MEM_W(0XB40, ctx->r16) = 0;
            goto L_801427B0;
    }
    goto skip_0;
    // 0x80142784: sw          $zero, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = 0;
    skip_0:
    // 0x80142788: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014278C: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x80142790: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80142794: sw          $t6, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = ctx->r14;
    // 0x80142798: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x8014279C: jal         0x800EB528
    // 0x801427A0: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_3;
    // 0x801427A0: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    after_3:
    // 0x801427A4: b           L_801427B0
    // 0x801427A8: nop

        goto L_801427B0;
    // 0x801427A8: nop

L_801427AC:
    // 0x801427AC: sw          $zero, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = 0;
L_801427B0:
    // 0x801427B0: jal         0x800269C0
    // 0x801427B4: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x801427B4: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    after_4:
    // 0x801427B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801427BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801427C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801427C4: jr          $ra
    // 0x801427C8: nop

    return;
    // 0x801427C8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeHiScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133BD4: jal         0x80134E50
    // 0x80133BD8: nop

    mnPlayers1PBonusGetForcePuckFighterKind(rdram, ctx);
        goto after_0;
    // 0x80133BD8: nop

    after_0:
    // 0x80133BDC: jal         0x80133B7C
    // 0x80133BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusCheckBonusComplete(rdram, ctx);
        goto after_1;
    // 0x80133BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80133BE4: beq         $v0, $zero, L_80133BFC
    if (ctx->r2 == 0) {
        // 0x80133BE8: nop
    
            goto L_80133BFC;
    }
    // 0x80133BE8: nop

    // 0x80133BEC: jal         0x801336B4
    // 0x80133BF0: nop

    mnPlayers1PBonusMakeBestTime(rdram, ctx);
        goto after_2;
    // 0x80133BF0: nop

    after_2:
    // 0x80133BF4: b           L_80133C08
    // 0x80133BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133C08;
    // 0x80133BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133BFC:
    // 0x80133BFC: jal         0x801339C8
    // 0x80133C00: nop

    mnPlayers1PBonusMakeBestTaskCount(rdram, ctx);
        goto after_3;
    // 0x80133C00: nop

    after_3:
    // 0x80133C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133C08:
    // 0x80133C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133C0C: jr          $ra
    // 0x80133C10: nop

    return;
    // 0x80133C10: nop

;}
RECOMP_FUNC void mnCharactersMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C40: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80132C44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132C48: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80132C4C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80132C50: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x80132C54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132C58: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80132C5C: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x80132C60: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_80132C64:
    // 0x80132C64: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132C68: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132C6C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132C70: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132C74: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132C78: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132C7C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132C80: bne         $t6, $t0, L_80132C64
    if (ctx->r14 != ctx->r8) {
        // 0x80132C84: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132C64;
    }
    // 0x80132C84: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132C88: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132C8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C90: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80132C94: jal         0x80131B58
    // 0x80132C98: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132C98: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_0:
    // 0x80132C9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132CA0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80132CA4: jal         0x80131B58
    // 0x80132CA8: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80132CA8: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_1:
    // 0x80132CAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132CB0: jal         0x800EC0EC
    // 0x80132CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_2;
    // 0x80132CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80132CB8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132CBC: lw          $t1, 0x66EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X66EC);
    // 0x80132CC0: sb          $v0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r2;
    // 0x80132CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132CC8: jal         0x800D7F3C
    // 0x80132CCC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    ftManagerMakeFighter(rdram, ctx);
        goto after_3;
    // 0x80132CCC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_3:
    // 0x80132CD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132CD8: sw          $v0, 0x660C($at)
    MEM_W(0X660C, ctx->r1) = ctx->r2;
    // 0x80132CDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132CE0: addiu       $a1, $a1, 0x29E8
    ctx->r5 = ADD32(ctx->r5, 0X29E8);
    // 0x80132CE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132CEC: jal         0x80008188
    // 0x80132CF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80132CF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80132CF4: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x80132CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132CFC: lbu         $t3, 0x190($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X190);
    // 0x80132D00: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80132D04: sb          $t4, 0x190($v1)
    MEM_B(0X190, ctx->r3) = ctx->r12;
    // 0x80132D08: jal         0x80132494
    // 0x80132D0C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    mnCharactersSetFighterScale(rdram, ctx);
        goto after_5;
    // 0x80132D0C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_5:
    // 0x80132D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D14: jal         0x801324CC
    // 0x80132D18: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    mnCharactersSetFighterPosition(rdram, ctx);
        goto after_6;
    // 0x80132D18: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_6:
    // 0x80132D1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132D20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D24: jal         0x80132794
    // 0x80132D28: sw          $t5, 0x66D4($at)
    MEM_W(0X66D4, ctx->r1) = ctx->r13;
    mnCharactersInitRecentMotionKinds(rdram, ctx);
        goto after_7;
    // 0x80132D28: sw          $t5, 0x66D4($at)
    MEM_W(0X66D4, ctx->r1) = ctx->r13;
    after_7:
    // 0x80132D2C: jal         0x801327FC
    // 0x80132D30: nop

    mnCharactersRandMotionKind(rdram, ctx);
        goto after_8;
    // 0x80132D30: nop

    after_8:
    // 0x80132D34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132D38: addiu       $v1, $v1, 0x66C4
    ctx->r3 = ADD32(ctx->r3, 0X66C4);
    // 0x80132D3C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80132D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D44: sw          $zero, 0x66FC($at)
    MEM_W(0X66FC, ctx->r1) = 0;
    // 0x80132D48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D4C: sw          $zero, 0x6704($at)
    MEM_W(0X6704, ctx->r1) = 0;
    // 0x80132D50: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80132D54: jal         0x8013286C
    // 0x80132D58: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    mnCharactersSetMotion(rdram, ctx);
        goto after_9;
    // 0x80132D58: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80132D5C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80132D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132D68: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132D6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80132D70: jal         0x800E6F24
    // 0x80132D74: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    ftMainSetStatus(rdram, ctx);
        goto after_10;
    // 0x80132D74: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_10:
    // 0x80132D78: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80132D7C: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x80132D80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132D84: beq         $v0, $at, L_80132DA0
    if (ctx->r2 == ctx->r1) {
        // 0x80132D88: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80132DA0;
    }
    // 0x80132D88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D90: sw          $t6, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = ctx->r14;
    // 0x80132D94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D98: b           L_80132DB0
    // 0x80132D9C: sw          $v0, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r2;
        goto L_80132DB0;
    // 0x80132D9C: sw          $v0, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r2;
L_80132DA0:
    // 0x80132DA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DA4: sw          $zero, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = 0;
    // 0x80132DA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DAC: sw          $zero, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = 0;
L_80132DB0:
    // 0x80132DB0: jal         0x80132E20
    // 0x80132DB4: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    mnCharactersUpdateMotionName(rdram, ctx);
        goto after_11;
    // 0x80132DB4: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    after_11:
    // 0x80132DB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132DBC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132DC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132DC8: sw          $t9, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = ctx->r25;
    // 0x80132DCC: jr          $ra
    // 0x80132DD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80132DD0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void mvOpeningSectorMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131DF0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80131DF4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80131DF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131DFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80131E00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80131E04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E0C: jal         0x80009968
    // 0x80131E10: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E10: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80131E14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E18: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131E1C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131E20: sw          $v0, 0x2A20($at)
    MEM_W(0X2A20, ctx->r1) = ctx->r2;
    // 0x80131E24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131E28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131E2C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E34: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131E38: jal         0x80009DF4
    // 0x80131E3C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E3C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80131E40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E44: addiu       $a1, $a1, 0x1B58
    ctx->r5 = ADD32(ctx->r5, 0X1B58);
    // 0x80131E48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131E4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E50: jal         0x80008188
    // 0x80131E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80131E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80131E58: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131E5C: lw          $t7, 0x2C08($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C08);
    // 0x80131E60: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x80131E64: addiu       $s0, $s0, 0x6C88
    ctx->r16 = ADD32(ctx->r16, 0X6C88);
    // 0x80131E68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131E6C: jal         0x800CCFDC
    // 0x80131E70: addu        $a1, $t7, $s0
    ctx->r5 = ADD32(ctx->r15, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131E70: addu        $a1, $t7, $s0
    ctx->r5 = ADD32(ctx->r15, ctx->r16);
    after_3:
    // 0x80131E74: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131E78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131E7C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E80: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131E84: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131E88: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80131E8C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131E90: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131E94: lw          $t0, 0x2C08($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2C08);
    // 0x80131E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131E9C: jal         0x800CCFDC
    // 0x80131EA0: addu        $a1, $t0, $s0
    ctx->r5 = ADD32(ctx->r8, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131EA0: addu        $a1, $t0, $s0
    ctx->r5 = ADD32(ctx->r8, ctx->r16);
    after_4:
    // 0x80131EA4: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80131EA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131EAC: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131EB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131EB8: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80131EBC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131EC0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131EC4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131EC8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131ECC: lw          $t3, 0x2C08($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2C08);
    // 0x80131ED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131ED4: jal         0x800CCFDC
    // 0x80131ED8: addu        $a1, $t3, $s0
    ctx->r5 = ADD32(ctx->r11, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131ED8: addu        $a1, $t3, $s0
    ctx->r5 = ADD32(ctx->r11, ctx->r16);
    after_5:
    // 0x80131EDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131EE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131EE4: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EE8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131EEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131EF0: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x80131EF4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131EF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131EFC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131F00: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131F04: lw          $t6, 0x2C08($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C08);
    // 0x80131F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80131F0C: jal         0x800CCFDC
    // 0x80131F10: addu        $a1, $t6, $s0
    ctx->r5 = ADD32(ctx->r14, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80131F10: addu        $a1, $t6, $s0
    ctx->r5 = ADD32(ctx->r14, ctx->r16);
    after_6:
    // 0x80131F14: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80131F18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131F1C: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F20: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131F24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131F28: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80131F2C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131F30: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131F34: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131F3C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80131F40: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F44: jr          $ra
    // 0x80131F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _n_freeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A050: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002A054: addiu       $v0, $v0, -0x2CEC
    ctx->r2 = ADD32(ctx->r2, -0X2CEC);
    // 0x8002A058: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002A05C: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x8002A060: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8002A064: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002A068: jr          $ra
    // 0x8002A06C: sw          $a0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r4;
    return;
    // 0x8002A06C: sw          $a0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r4;
;}
RECOMP_FUNC void scSubsysControllerGetPlayerStickLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8039089C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803908A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803908A4: sll         $s1, $a0, 24
    ctx->r17 = S32(ctx->r4 << 24);
    // 0x803908A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x803908AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x803908B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803908B4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x803908B8: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x803908BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803908C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803908C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x803908C8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_803908CC:
    // 0x803908CC: jal         0x80390700
    // 0x803908D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x803908D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x803908D4: beq         $v0, $zero, L_80390924
    if (ctx->r2 == 0) {
        // 0x803908D8: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_80390924;
    }
    // 0x803908D8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x803908DC: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x803908E0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x803908E4: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x803908E8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x803908EC: beq         $s2, $zero, L_8039090C
    if (ctx->r18 == 0) {
        // 0x803908F0: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_8039090C;
    }
    // 0x803908F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x803908F4: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x803908F8: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x803908FC: beql        $at, $zero, L_80390928
    if (ctx->r1 == 0) {
        // 0x80390900: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390928;
    }
    goto skip_0;
    // 0x80390900: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80390904: b           L_80390934
    // 0x80390908: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80390934;
    // 0x80390908: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8039090C:
    // 0x8039090C: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x80390910: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80390914: beql        $at, $zero, L_80390928
    if (ctx->r1 == 0) {
        // 0x80390918: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390928;
    }
    goto skip_1;
    // 0x80390918: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8039091C: b           L_80390934
    // 0x80390920: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80390934;
    // 0x80390920: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80390924:
    // 0x80390924: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80390928:
    // 0x80390928: bne         $s0, $s3, L_803908CC
    if (ctx->r16 != ctx->r19) {
        // 0x8039092C: nop
    
            goto L_803908CC;
    }
    // 0x8039092C: nop

    // 0x80390930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80390934:
    // 0x80390934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80390938: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8039093C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80390940: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80390944: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80390948: jr          $ra
    // 0x8039094C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8039094C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PTrainingGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131FD4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131FD8: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131FDC: addiu       $t6, $t6, -0x7F6C
    ctx->r14 = ADD32(ctx->r14, -0X7F6C);
    // 0x80131FE0: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131FE4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131FE8:
    // 0x80131FE8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131FEC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131FF0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131FF4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131FF8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131FFC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132000: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132004: bne         $t6, $t0, L_80131FE8
    if (ctx->r14 != ctx->r8) {
        // 0x80132008: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131FE8;
    }
    // 0x80132008: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013200C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80132010: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80132014: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80132018: jr          $ra
    // 0x8013201C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013201C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028D78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80028D7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80028D80: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80028D84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80028D88: jal         0x80030350
    // 0x80028D8C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80028D8C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80028D90: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80028D94: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80028D98: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80028D9C: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80028DA0: bne         $t0, $zero, L_80028DB8
    if (ctx->r8 != 0) {
        // 0x80028DA4: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80028DB8;
    }
    // 0x80028DA4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80028DA8: jal         0x80030350
    // 0x80028DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80028DAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80028DB0: b           L_80028EB4
    // 0x80028DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80028EB4;
    // 0x80028DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028DB8:
    // 0x80028DB8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80028DBC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80028DC0: jal         0x80028C84
    // 0x80028DC4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x80028DC4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x80028DC8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80028DCC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80028DD0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80028DD4: jal         0x80035740
    // 0x80028DD8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x80028DD8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x80028DDC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80028DE0: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80028DE4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80028DE8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80028DEC: bne         $a3, $at, L_80028DFC
    if (ctx->r7 != ctx->r1) {
        // 0x80028DF0: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80028DFC;
    }
    // 0x80028DF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80028DF4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80028DF8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80028DFC:
    // 0x80028DFC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80028E00: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80028E04: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80028E08: beq         $v0, $at, L_80028EA8
    if (ctx->r2 == ctx->r1) {
        // 0x80028E0C: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_80028EA8;
    }
    // 0x80028E0C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_80028E10:
    // 0x80028E10: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80028E14: bnel        $v0, $zero, L_80028E58
    if (ctx->r2 != 0) {
        // 0x80028E18: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80028E58;
    }
    goto skip_0;
    // 0x80028E18: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80028E1C: beql        $t8, $zero, L_80028E30
    if (ctx->r24 == 0) {
        // 0x80028E20: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_80028E30;
    }
    goto skip_1;
    // 0x80028E20: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x80028E24: b           L_80028E30
    // 0x80028E28: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_80028E30;
    // 0x80028E28: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x80028E2C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_80028E30:
    // 0x80028E30: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80028E34: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x80028E38: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80028E3C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80028E40: beq         $v0, $zero, L_80028E4C
    if (ctx->r2 == 0) {
        // 0x80028E44: nop
    
            goto L_80028E4C;
    }
    // 0x80028E44: nop

    // 0x80028E48: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_80028E4C:
    // 0x80028E4C: b           L_80028EA8
    // 0x80028E50: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80028EA8;
    // 0x80028E50: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80028E54: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80028E58:
    // 0x80028E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80028E5C: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80028E60: beql        $at, $zero, L_80028EA0
    if (ctx->r1 == 0) {
        // 0x80028E64: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80028EA0;
    }
    goto skip_2;
    // 0x80028E64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x80028E68: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x80028E6C: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80028E70: subu        $t3, $t2, $a3
    ctx->r11 = SUB32(ctx->r10, ctx->r7);
    // 0x80028E74: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x80028E78: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80028E7C: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x80028E80: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80028E84: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80028E88: beq         $v0, $zero, L_80028E94
    if (ctx->r2 == 0) {
        // 0x80028E8C: nop
    
            goto L_80028E94;
    }
    // 0x80028E8C: nop

    // 0x80028E90: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_80028E94:
    // 0x80028E94: b           L_80028EA8
    // 0x80028E98: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80028EA8;
    // 0x80028E98: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80028E9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80028EA0:
    // 0x80028EA0: bne         $v0, $zero, L_80028E10
    if (ctx->r2 != 0) {
        // 0x80028EA4: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_80028E10;
    }
    // 0x80028EA4: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_80028EA8:
    // 0x80028EA8: jal         0x80030350
    // 0x80028EAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x80028EAC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x80028EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028EB4:
    // 0x80028EB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028EB8: jr          $ra
    // 0x80028EBC: nop

    return;
    // 0x80028EBC: nop

;}
RECOMP_FUNC void itBoxThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017982C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179838: jal         0x801737B8
    // 0x8017983C: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017983C: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    after_0:
    // 0x80179840: beql        $v0, $zero, L_8017986C
    if (ctx->r2 == 0) {
        // 0x80179844: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8017986C;
    }
    goto skip_0;
    // 0x80179844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80179848: jal         0x80179424
    // 0x8017984C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBoxCommonCheckSpawnItems(rdram, ctx);
        goto after_1;
    // 0x8017984C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179850: beq         $v0, $zero, L_80179860
    if (ctx->r2 == 0) {
        // 0x80179854: nop
    
            goto L_80179860;
    }
    // 0x80179854: nop

    // 0x80179858: b           L_8017986C
    // 0x8017985C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017986C;
    // 0x8017985C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179860:
    // 0x80179860: jal         0x80179B08
    // 0x80179864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBoxExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_2;
    // 0x80179864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80179868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017986C:
    // 0x8017986C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179874: jr          $ra
    // 0x80179878: nop

    return;
    // 0x80179878: nop

;}
RECOMP_FUNC void mnOptionSetOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B28: addiu       $t6, $t6, 0x3668
    ctx->r14 = ADD32(ctx->r14, 0X3668);
    // 0x80131B2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B34: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80131B38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B3C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80131B40: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131B44: addiu       $t9, $t9, 0x3670
    ctx->r25 = ADD32(ctx->r25, 0X3670);
    // 0x80131B48: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80131B4C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131B50: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80131B54: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131B58: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80131B5C: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80131B60: addiu       $t2, $t2, 0x3678
    ctx->r10 = ADD32(ctx->r10, 0X3678);
    // 0x80131B64: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x80131B68: sh          $t1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r9;
    // 0x80131B6C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131B74: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80131B78: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x80131B7C: beq         $a1, $zero, L_80131BA4
    if (ctx->r5 == 0) {
        // 0x80131B80: sh          $t4, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r12;
            goto L_80131BA4;
    }
    // 0x80131B80: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x80131B84: beq         $a1, $at, L_80131B9C
    if (ctx->r5 == ctx->r1) {
        // 0x80131B88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80131B9C;
    }
    // 0x80131B88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131B8C: beq         $a1, $at, L_80131BAC
    if (ctx->r5 == ctx->r1) {
        // 0x80131B90: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80131BAC;
    }
    // 0x80131B90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131B94: b           L_80131BAC
    // 0x80131B98: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
        goto L_80131BAC;
    // 0x80131B98: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_80131B9C:
    // 0x80131B9C: b           L_80131BAC
    // 0x80131BA0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80131BAC;
    // 0x80131BA0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80131BA4:
    // 0x80131BA4: b           L_80131BAC
    // 0x80131BA8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80131BAC;
    // 0x80131BA8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80131BAC:
    // 0x80131BAC: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80131BB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80131BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80131BB8:
    // 0x80131BB8: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80131BBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80131BC0: sb          $t5, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r13;
    // 0x80131BC4: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80131BC8: sb          $t6, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r14;
    // 0x80131BCC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x80131BD0: sb          $t7, 0x62($v1)
    MEM_B(0X62, ctx->r3) = ctx->r15;
    // 0x80131BD4: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80131BD8: sb          $t8, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r24;
    // 0x80131BDC: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80131BE0: sb          $t9, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r25;
    // 0x80131BE4: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    // 0x80131BE8: sb          $t0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r8;
    // 0x80131BEC: bne         $a1, $a0, L_80131BB8
    if (ctx->r5 != ctx->r4) {
        // 0x80131BF0: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_80131BB8;
    }
    // 0x80131BF0: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80131BF4: jr          $ra
    // 0x80131BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itMSBombAttachedUpdateSurface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176708: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017670C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176710: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80176714: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80176718: lhu         $t6, 0x8E($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X8E);
    // 0x8017671C: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
    // 0x80176720: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80176724: bnel        $t7, $zero, L_80176740
    if (ctx->r15 != 0) {
        // 0x80176728: addiu       $v0, $a1, 0x38
        ctx->r2 = ADD32(ctx->r5, 0X38);
            goto L_80176740;
    }
    goto skip_0;
    // 0x80176728: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
    skip_0:
    // 0x8017672C: lhu         $v1, 0x56($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X56);
    // 0x80176730: andi        $t8, $v1, 0x800
    ctx->r24 = ctx->r3 & 0X800;
    // 0x80176734: beq         $t8, $zero, L_801767AC
    if (ctx->r24 == 0) {
        // 0x80176738: andi        $t9, $v1, 0x1
        ctx->r25 = ctx->r3 & 0X1;
            goto L_801767AC;
    }
    // 0x80176738: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8017673C: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
L_80176740:
    // 0x80176740: lhu         $v1, 0x56($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X56);
    // 0x80176744: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x80176748: beql        $t9, $zero, L_8017677C
    if (ctx->r25 == 0) {
        // 0x8017674C: andi        $t4, $v1, 0x800
        ctx->r12 = ctx->r3 & 0X800;
            goto L_8017677C;
    }
    goto skip_1;
    // 0x8017674C: andi        $t4, $v1, 0x800
    ctx->r12 = ctx->r3 & 0X800;
    skip_1:
    // 0x80176750: lw          $t2, 0x94($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X94);
    // 0x80176754: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80176758: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8017675C: lw          $t1, 0x98($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X98);
    // 0x80176760: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x80176764: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x80176768: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8017676C: lw          $t3, 0x8C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8C);
    // 0x80176770: sh          $t3, 0x2D0($a1)
    MEM_H(0X2D0, ctx->r5) = ctx->r11;
    // 0x80176774: lhu         $v1, 0x56($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X56);
    // 0x80176778: andi        $t4, $v1, 0x800
    ctx->r12 = ctx->r3 & 0X800;
L_8017677C:
    // 0x8017677C: beql        $t4, $zero, L_80176810
    if (ctx->r12 == 0) {
        // 0x80176780: lwc1        $f12, 0x28($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80176810;
    }
    goto skip_2;
    // 0x80176780: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80176784: lw          $t7, 0x80($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X80);
    // 0x80176788: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x8017678C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80176790: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80176794: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80176798: lw          $t7, 0x88($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X88);
    // 0x8017679C: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
    // 0x801767A0: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x801767A4: b           L_8017680C
    // 0x801767A8: sh          $t8, 0x2D0($a1)
    MEM_H(0X2D0, ctx->r5) = ctx->r24;
        goto L_8017680C;
    // 0x801767A8: sh          $t8, 0x2D0($a1)
    MEM_H(0X2D0, ctx->r5) = ctx->r24;
L_801767AC:
    // 0x801767AC: beql        $t9, $zero, L_801767E0
    if (ctx->r25 == 0) {
        // 0x801767B0: andi        $t4, $v1, 0x20
        ctx->r12 = ctx->r3 & 0X20;
            goto L_801767E0;
    }
    goto skip_3;
    // 0x801767B0: andi        $t4, $v1, 0x20
    ctx->r12 = ctx->r3 & 0X20;
    skip_3:
    // 0x801767B4: lw          $t2, 0xA8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XA8);
    // 0x801767B8: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x801767BC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801767C0: lw          $t1, 0xAC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XAC);
    // 0x801767C4: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x801767C8: lw          $t2, 0xB0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XB0);
    // 0x801767CC: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x801767D0: lw          $t3, 0xA0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XA0);
    // 0x801767D4: sh          $t3, 0x2D0($a1)
    MEM_H(0X2D0, ctx->r5) = ctx->r11;
    // 0x801767D8: lhu         $v1, 0x56($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X56);
    // 0x801767DC: andi        $t4, $v1, 0x20
    ctx->r12 = ctx->r3 & 0X20;
L_801767E0:
    // 0x801767E0: beql        $t4, $zero, L_80176810
    if (ctx->r12 == 0) {
        // 0x801767E4: lwc1        $f12, 0x28($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80176810;
    }
    goto skip_4;
    // 0x801767E4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x801767E8: lw          $t7, 0xBC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XBC);
    // 0x801767EC: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x801767F0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x801767F4: lw          $t6, 0xC0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC0);
    // 0x801767F8: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x801767FC: lw          $t7, 0xC4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC4);
    // 0x80176800: sw          $t7, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r15;
    // 0x80176804: lw          $t8, 0xB4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB4);
    // 0x80176808: sh          $t8, 0x2D0($a1)
    MEM_H(0X2D0, ctx->r5) = ctx->r24;
L_8017680C:
    // 0x8017680C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
L_80176810:
    // 0x80176810: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80176814: jal         0x8001863C
    // 0x80176818: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80176818: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017681C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80176820: lwc1        $f4, -0x32E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32E0);
    // 0x80176824: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80176828: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8017682C: swc1        $f6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f6.u32l;
    // 0x80176830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80176838: jr          $ra
    // 0x8017683C: nop

    return;
    // 0x8017683C: nop

;}
RECOMP_FUNC void _n_collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C59C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C5A0: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8002C5A4: addiu       $s1, $s1, -0x2CEC
    ctx->r17 = ADD32(ctx->r17, -0X2CEC);
    // 0x8002C5A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C5AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C5B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C5B4: lw          $s0, 0x20($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X20);
    // 0x8002C5B8: beql        $s0, $zero, L_8002C608
    if (ctx->r16 == 0) {
        // 0x8002C5BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002C608;
    }
    goto skip_0;
    // 0x8002C5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8002C5C0:
    // 0x8002C5C0: jal         0x80028C84
    // 0x8002C5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8002C5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8002C5C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002C5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C5D0: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x8002C5D4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002C5D8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8002C5DC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8002C5E0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002C5E4: beql        $v1, $zero, L_8002C5F4
    if (ctx->r3 == 0) {
        // 0x8002C5E8: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_8002C5F4;
    }
    goto skip_1;
    // 0x8002C5E8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    skip_1:
    // 0x8002C5EC: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8002C5F0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8002C5F4:
    // 0x8002C5F4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C5F8: lw          $s0, 0x20($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X20);
    // 0x8002C5FC: bne         $s0, $zero, L_8002C5C0
    if (ctx->r16 != 0) {
        // 0x8002C600: nop
    
            goto L_8002C5C0;
    }
    // 0x8002C600: nop

    // 0x8002C604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002C608:
    // 0x8002C608: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002C60C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002C610: jr          $ra
    // 0x8002C614: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002C614: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftPikachuSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151CB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80151CB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151CB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151CBC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151CC0: jal         0x800DEEC8
    // 0x80151CC4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80151CC4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151CC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151CCC: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80151CD0: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x80151CD4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151CD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151CDC: jal         0x800E6F24
    // 0x80151CE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151CE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151CE4: jal         0x800D8EB8
    // 0x80151CE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80151CE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80151CEC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80151CF0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80151CF4: addiu       $t8, $t8, 0x1B50
    ctx->r24 = ADD32(ctx->r24, 0X1B50);
    // 0x80151CF8: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80151CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151D00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151D04: jr          $ra
    // 0x80151D08: nop

    return;
    // 0x80151D08: nop

;}
RECOMP_FUNC void mnVSModeSaveSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801337BC: lw          $t6, 0x4950($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4950);
    // 0x801337C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801337C4: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x801337C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801337CC: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
    // 0x801337D0: lw          $t7, 0x4954($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4954);
    // 0x801337D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801337D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801337DC: sb          $t7, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r15;
    // 0x801337E0: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x801337E4: beql        $v0, $zero, L_80133820
    if (ctx->r2 == 0) {
        // 0x801337E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80133820;
    }
    goto skip_0;
    // 0x801337E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x801337EC: beq         $v0, $at, L_80133810
    if (ctx->r2 == ctx->r1) {
        // 0x801337F0: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80133810;
    }
    // 0x801337F0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801337F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801337F8: beq         $v0, $at, L_8013383C
    if (ctx->r2 == ctx->r1) {
        // 0x801337FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8013383C;
    }
    // 0x801337FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133800: beq         $v0, $at, L_8013382C
    if (ctx->r2 == ctx->r1) {
        // 0x80133804: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8013382C;
    }
    // 0x80133804: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133808: jr          $ra
    // 0x8013380C: nop

    return;
    // 0x8013380C: nop

L_80133810:
    // 0x80133810: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80133814: jr          $ra
    // 0x80133818: sb          $t8, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r24;
    return;
    // 0x80133818: sb          $t8, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r24;
    // 0x8013381C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133820:
    // 0x80133820: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80133824: jr          $ra
    // 0x80133828: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    return;
    // 0x80133828: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
L_8013382C:
    // 0x8013382C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133830: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80133834: jr          $ra
    // 0x80133838: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    return;
    // 0x80133838: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
L_8013383C:
    // 0x8013383C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133840: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80133844: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80133848: jr          $ra
    // 0x8013384C: nop

    return;
    // 0x8013384C: nop

;}
RECOMP_FUNC void itHitokageDamagedProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183F88: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80183F8C: jr          $ra
    // 0x80183F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80183F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void mnPlayers1PBonusSetSceneData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136998: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013699C: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x801369A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801369A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801369A8: lw          $t6, 0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X76F8);
    // 0x801369AC: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x801369B0: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801369B4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801369B8: sb          $t6, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r14;
    // 0x801369BC: sb          $t7, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r15;
    // 0x801369C0: jr          $ra
    // 0x801369C4: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    return;
    // 0x801369C4: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void itFFlowerThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175C58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175C5C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80175C60: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80175C64: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80175C68: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175C6C: bne         $t6, $zero, L_80175C84
    if (ctx->r14 != 0) {
        // 0x80175C70: nop
    
            goto L_80175C84;
    }
    // 0x80175C70: nop

    // 0x80175C74: jal         0x80173DF4
    // 0x80175C78: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x80175C78: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80175C7C: b           L_80175C90
    // 0x80175C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80175C90;
    // 0x80175C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175C84:
    // 0x80175C84: jal         0x80173B24
    // 0x80175C88: addiu       $a3, $a3, 0x5BB0
    ctx->r7 = ADD32(ctx->r7, 0X5BB0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x80175C88: addiu       $a3, $a3, 0x5BB0
    ctx->r7 = ADD32(ctx->r7, 0X5BB0);
    after_1:
    // 0x80175C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175C90:
    // 0x80175C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175C94: jr          $ra
    // 0x80175C98: nop

    return;
    // 0x80175C98: nop

;}
RECOMP_FUNC void _bcopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035430: beq         $a2, $zero, L_8003549C
    if (ctx->r6 == 0) {
        // 0x80035434: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8003549C;
    }
    // 0x80035434: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80035438: beq         $a0, $a1, L_8003549C
    if (ctx->r4 == ctx->r5) {
        // 0x8003543C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003549C;
    }
    // 0x8003543C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80035440: bnel        $at, $zero, L_80035464
    if (ctx->r1 != 0) {
        // 0x80035444: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80035464;
    }
    goto skip_0;
    // 0x80035444: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x80035448: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8003544C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80035450: beql        $at, $zero, L_80035464
    if (ctx->r1 == 0) {
        // 0x80035454: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80035464;
    }
    goto skip_1;
    // 0x80035454: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x80035458: b           L_800355C8
    // 0x8003545C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800355C8;
    // 0x8003545C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80035460: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80035464:
    // 0x80035464: bne         $at, $zero, L_8003547C
    if (ctx->r1 != 0) {
        // 0x80035468: nop
    
            goto L_8003547C;
    }
    // 0x80035468: nop

    // 0x8003546C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80035470: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80035474: beq         $v0, $v1, L_800354A4
    if (ctx->r2 == ctx->r3) {
        // 0x80035478: nop
    
            goto L_800354A4;
    }
    // 0x80035478: nop

L_8003547C:
    // 0x8003547C: beq         $a2, $zero, L_8003549C
    if (ctx->r6 == 0) {
        // 0x80035480: nop
    
            goto L_8003549C;
    }
    // 0x80035480: nop

    // 0x80035484: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80035488:
    // 0x80035488: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003548C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80035490: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80035494: bne         $a0, $v1, L_80035488
    if (ctx->r4 != ctx->r3) {
        // 0x80035498: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80035488;
    }
    // 0x80035498: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8003549C:
    // 0x8003549C: jr          $ra
    // 0x800354A0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800354A0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800354A4:
    // 0x800354A4: beq         $v0, $zero, L_80035508
    if (ctx->r2 == 0) {
        // 0x800354A8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80035508;
    }
    // 0x800354A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800354AC: beq         $v0, $at, L_800354EC
    if (ctx->r2 == ctx->r1) {
        // 0x800354B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800354EC;
    }
    // 0x800354B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800354B4: beql        $v0, $at, L_800354D8
    if (ctx->r2 == ctx->r1) {
        // 0x800354B8: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800354D8;
    }
    goto skip_2;
    // 0x800354B8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800354BC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800354C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800354C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800354C8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800354CC: b           L_80035508
    // 0x800354D0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_80035508;
    // 0x800354D0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800354D4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800354D8:
    // 0x800354D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800354DC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800354E0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800354E4: b           L_80035508
    // 0x800354E8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_80035508;
    // 0x800354E8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800354EC:
    // 0x800354EC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800354F0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800354F4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800354F8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800354FC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80035500: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x80035504: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_80035508:
    // 0x80035508: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8003550C: bnel        $at, $zero, L_80035568
    if (ctx->r1 != 0) {
        // 0x80035510: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80035568;
    }
    goto skip_3;
    // 0x80035510: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x80035514: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80035518: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8003551C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80035520: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80035524: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80035528: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8003552C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x80035530: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x80035534: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80035538: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8003553C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80035540: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x80035544: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x80035548: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8003554C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x80035550: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x80035554: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x80035558: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8003555C: b           L_80035508
    // 0x80035560: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_80035508;
    // 0x80035560: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80035564:
    // 0x80035564: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80035568:
    // 0x80035568: bnel        $at, $zero, L_800355A4
    if (ctx->r1 != 0) {
        // 0x8003556C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800355A4;
    }
    goto skip_4;
    // 0x8003556C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80035570: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80035574: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80035578: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8003557C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80035580: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80035584: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80035588: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8003558C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80035590: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80035594: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80035598: b           L_80035564
    // 0x8003559C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80035564;
    // 0x8003559C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800355A0:
    // 0x800355A0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800355A4:
    // 0x800355A4: bne         $at, $zero, L_8003547C
    if (ctx->r1 != 0) {
        // 0x800355A8: nop
    
            goto L_8003547C;
    }
    // 0x800355A8: nop

    // 0x800355AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800355B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800355B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800355B8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800355BC: b           L_800355A0
    // 0x800355C0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800355A0;
    // 0x800355C0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800355C4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800355C8:
    // 0x800355C8: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800355CC: bne         $at, $zero, L_800355E4
    if (ctx->r1 != 0) {
        // 0x800355D0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800355E4;
    }
    // 0x800355D0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800355D4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800355D8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800355DC: beq         $v0, $v1, L_80035614
    if (ctx->r2 == ctx->r3) {
        // 0x800355E0: nop
    
            goto L_80035614;
    }
    // 0x800355E0: nop

L_800355E4:
    // 0x800355E4: beq         $a2, $zero, L_8003549C
    if (ctx->r6 == 0) {
        // 0x800355E8: nop
    
            goto L_8003549C;
    }
    // 0x800355E8: nop

    // 0x800355EC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800355F0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800355F4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800355F8:
    // 0x800355F8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800355FC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80035600: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80035604: bne         $a0, $v1, L_800355F8
    if (ctx->r4 != ctx->r3) {
        // 0x80035608: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800355F8;
    }
    // 0x80035608: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x8003560C: jr          $ra
    // 0x80035610: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80035610: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80035614:
    // 0x80035614: beq         $v0, $zero, L_80035678
    if (ctx->r2 == 0) {
        // 0x80035618: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80035678;
    }
    // 0x80035618: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003561C: beq         $v0, $at, L_8003565C
    if (ctx->r2 == ctx->r1) {
        // 0x80035620: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003565C;
    }
    // 0x80035620: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035624: beql        $v0, $at, L_80035648
    if (ctx->r2 == ctx->r1) {
        // 0x80035628: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_80035648;
    }
    goto skip_5;
    // 0x80035628: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8003562C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80035630: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80035634: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80035638: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003563C: b           L_80035678
    // 0x80035640: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80035678;
    // 0x80035640: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80035644: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_80035648:
    // 0x80035648: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8003564C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80035650: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80035654: b           L_80035678
    // 0x80035658: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80035678;
    // 0x80035658: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8003565C:
    // 0x8003565C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80035660: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80035664: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80035668: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8003566C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80035670: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80035674: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80035678:
    // 0x80035678: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8003567C: bnel        $at, $zero, L_800356D8
    if (ctx->r1 != 0) {
        // 0x80035680: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800356D8;
    }
    goto skip_6;
    // 0x80035680: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80035684: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80035688: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8003568C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80035690: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80035694: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80035698: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8003569C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800356A0: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800356A4: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800356A8: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800356AC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800356B0: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800356B4: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800356B8: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800356BC: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800356C0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800356C4: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800356C8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800356CC: b           L_80035678
    // 0x800356D0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80035678;
    // 0x800356D0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800356D4:
    // 0x800356D4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800356D8:
    // 0x800356D8: bnel        $at, $zero, L_80035714
    if (ctx->r1 != 0) {
        // 0x800356DC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80035714;
    }
    goto skip_7;
    // 0x800356DC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800356E0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800356E4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800356E8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800356EC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800356F0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800356F4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800356F8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800356FC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80035700: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80035704: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80035708: b           L_800356D4
    // 0x8003570C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800356D4;
    // 0x8003570C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80035710:
    // 0x80035710: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80035714:
    // 0x80035714: bne         $at, $zero, L_800355E4
    if (ctx->r1 != 0) {
        // 0x80035718: nop
    
            goto L_800355E4;
    }
    // 0x80035718: nop

    // 0x8003571C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80035720: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80035724: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80035728: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003572C: b           L_80035710
    // 0x80035730: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80035710;
    // 0x80035730: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void mvOpeningPikachuMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC20: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC24: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC2C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC30: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC34: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC38: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC3C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC4C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC50: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC54: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC58: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC6C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC70: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC74: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC7C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC80: jal         0x8000B93C
    // 0x8018DC84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DC8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DC90: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC94: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC98: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DCA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DCA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DCA8: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DCAC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DCB0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DCB4: jal         0x80007080
    // 0x8018DCB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DCB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DCBC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DCC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCC4: lwc1        $f6, -0x1DEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DEC);
    // 0x8018DCC8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DCCC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DCD0: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DCD4: lw          $t4, -0x1BBC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1BBC);
    // 0x8018DCD8: addiu       $t5, $t5, 0x120
    ctx->r13 = ADD32(ctx->r13, 0X120);
    // 0x8018DCDC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCE0: jal         0x8000FA3C
    // 0x8018DCE4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCE4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCE8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCEC: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCF0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCF8: jal         0x80008188
    // 0x8018DCFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DCFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DD00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD08: jr          $ra
    // 0x8018DD0C: nop

    return;
    // 0x8018DD0C: nop

;}
RECOMP_FUNC void ftCommonCliffCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144C1C: jr          $ra
    // 0x80144C20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80144C20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void grWallpaperMakeSector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104ABC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80104AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104AC4: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80104AC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80104ACC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80104AD0: jal         0x80009968
    // 0x80104AD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80104AD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80104AD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104ADC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80104AE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80104AE4: sw          $v0, 0x13D8($at)
    MEM_W(0X13D8, ctx->r1) = ctx->r2;
    // 0x80104AE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80104AEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80104AF0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80104AF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80104AFC: jal         0x80009DF4
    // 0x80104B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80104B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80104B04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80104B08: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x80104B0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80104B10: jal         0x800CCFDC
    // 0x80104B14: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80104B14: lw          $a1, 0x48($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X48);
    after_2:
    // 0x80104B18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80104B1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80104B20: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x80104B24: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80104B28: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80104B2C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80104B30: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80104B34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80104B38: addiu       $a1, $a1, 0x4998
    ctx->r5 = ADD32(ctx->r5, 0X4998);
    // 0x80104B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80104B40: jal         0x80008188
    // 0x80104B44: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80104B44: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80104B48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80104B50: jr          $ra
    // 0x80104B54: nop

    return;
    // 0x80104B54: nop

;}
RECOMP_FUNC void sc1PStageClearMakeDamageTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801328D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801328D4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801328D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801328DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801328E0: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801328E4: jal         0x80009968
    // 0x801328E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801328E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801328EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801328F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801328F4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801328F8: sw          $v0, 0x5300($at)
    MEM_W(0X5300, ctx->r1) = ctx->r2;
    // 0x801328FC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80132900: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132904: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013290C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132910: jal         0x80009DF4
    // 0x80132914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132918: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013291C: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x80132920: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132924: addiu       $t8, $t8, 0x2B48
    ctx->r24 = ADD32(ctx->r24, 0X2B48);
    // 0x80132928: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8013292C: jal         0x800CCFDC
    // 0x80132930: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132930: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132934: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132938: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8013293C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132940: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132944: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132948: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013294C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132950: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132954: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80132958: addiu       $t4, $zero, 0xB7
    ctx->r12 = ADD32(0, 0XB7);
    // 0x8013295C: addiu       $t5, $zero, 0xE4
    ctx->r13 = ADD32(0, 0XE4);
    // 0x80132960: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80132964: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132968: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x8013296C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132970: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80132974: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132978: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x8013297C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80132980: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132984: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132988: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013298C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132990: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132994: addiu       $t8, $t8, 0x2120
    ctx->r24 = ADD32(ctx->r24, 0X2120);
    // 0x80132998: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x8013299C: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x801329A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801329A4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801329A8: jal         0x800CCFDC
    // 0x801329AC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801329AC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x801329B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801329B4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801329B8: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x801329BC: addiu       $t3, $v1, 0x2
    ctx->r11 = ADD32(ctx->r3, 0X2);
    // 0x801329C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801329C4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801329C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801329CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801329D0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801329D4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801329D8: addiu       $t4, $zero, 0xB7
    ctx->r12 = ADD32(0, 0XB7);
    // 0x801329DC: addiu       $t5, $zero, 0xE4
    ctx->r13 = ADD32(0, 0XE4);
    // 0x801329E0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801329E4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801329E8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801329EC: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801329F0: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801329F4: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801329F8: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x801329FC: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132A00: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132A04: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80132A08: jal         0x800269C0
    // 0x80132A0C: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80132A0C: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    after_4:
    // 0x80132A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80132A18: jr          $ra
    // 0x80132A1C: nop

    return;
    // 0x80132A1C: nop

;}
RECOMP_FUNC void itGShellSpinProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178C18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80178C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80178C20: jal         0x801735A0
    // 0x80178C24: addiu       $a1, $a1, -0x76D0
    ctx->r5 = ADD32(ctx->r5, -0X76D0);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80178C24: addiu       $a1, $a1, -0x76D0
    ctx->r5 = ADD32(ctx->r5, -0X76D0);
    after_0:
    // 0x80178C28: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80178C2C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80178C30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80178C34: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80178C38: jal         0x801737EC
    // 0x80178C3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80178C3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80178C40: beql        $v0, $zero, L_80178C5C
    if (ctx->r2 == 0) {
        // 0x80178C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80178C5C;
    }
    goto skip_0;
    // 0x80178C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80178C48: jal         0x80172508
    // 0x80178C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80178C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80178C50: jal         0x8017279C
    // 0x80178C54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainClearOwnerStats(rdram, ctx);
        goto after_3;
    // 0x80178C54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80178C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178C5C:
    // 0x80178C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178C64: jr          $ra
    // 0x80178C68: nop

    return;
    // 0x80178C68: nop

;}

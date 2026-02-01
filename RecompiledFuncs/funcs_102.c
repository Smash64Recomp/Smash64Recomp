#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSResultsMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013392C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80133930: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80133934: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80133938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013393C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80133940: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80133944: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80133948:
    // 0x80133948: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013394C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133950: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133954: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133958: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013395C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133960: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133964: bne         $t7, $t0, L_80133948
    if (ctx->r15 != ctx->r8) {
        // 0x80133968: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133948;
    }
    // 0x80133968: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013396C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133970: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80133974: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133978: jal         0x80133148
    // 0x8013397C: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x8013397C: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    after_0:
    // 0x80133980: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80133984: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80133988: addiu       $t2, $t2, 0x4D08
    ctx->r10 = ADD32(ctx->r10, 0X4D08);
    // 0x8013398C: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80133990: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80133994: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80133998: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x8013399C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801339A0: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x801339A4: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801339A8: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x801339AC: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x801339B0: lbu         $t3, 0x26($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X26);
    // 0x801339B4: lbu         $t4, 0x27($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X27);
    // 0x801339B8: lw          $t5, -0x6400($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6400);
    // 0x801339BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801339C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801339C4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x801339C8: sb          $t3, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r11;
    // 0x801339CC: sb          $t4, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r12;
    // 0x801339D0: jal         0x800D7F3C
    // 0x801339D4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801339D4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_1:
    // 0x801339D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801339DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801339E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801339E4: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x801339E8: sw          $v0, -0x6420($at)
    MEM_W(-0X6420, ctx->r1) = ctx->r2;
    // 0x801339EC: jr          $ra
    // 0x801339F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801339F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void itDogasDisappearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182C80: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182C88: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182C8C: bne         $a1, $zero, L_80182C9C
    if (ctx->r5 != 0) {
        // 0x80182C90: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80182C9C;
    }
    // 0x80182C90: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80182C94: jr          $ra
    // 0x80182C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80182C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80182C9C:
    // 0x80182C9C: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182CA0: jr          $ra
    // 0x80182CA4: nop

    return;
    // 0x80182CA4: nop

;}
RECOMP_FUNC void ftCommonSpecialLwCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801511E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801511E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801511E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801511EC: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x801511F0: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x801511F4: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x801511F8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801511FC: beql        $t8, $zero, L_8015124C
    if (ctx->r24 == 0) {
        // 0x80151200: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015124C;
    }
    goto skip_0;
    // 0x80151200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80151204: lw          $t9, 0x100($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X100);
    // 0x80151208: sll         $t1, $t9, 18
    ctx->r9 = S32(ctx->r25 << 18);
    // 0x8015120C: bgezl       $t1, L_8015124C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80151210: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015124C;
    }
    goto skip_1;
    // 0x80151210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80151214: lb          $t2, 0x1C3($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1C3);
    // 0x80151218: slti        $at, $t2, -0x27
    ctx->r1 = SIGNED(ctx->r10) < -0X27 ? 1 : 0;
    // 0x8015121C: beql        $at, $zero, L_8015124C
    if (ctx->r1 == 0) {
        // 0x80151220: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015124C;
    }
    goto skip_2;
    // 0x80151220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80151224: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80151228: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8015122C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80151230: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80151234: lw          $t9, -0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72B0);
    // 0x80151238: jalr        $t9
    // 0x8015123C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8015123C: nop

    after_0:
    // 0x80151240: b           L_8015124C
    // 0x80151244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015124C;
    // 0x80151244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80151248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015124C:
    // 0x8015124C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151254: jr          $ra
    // 0x80151258: nop

    return;
    // 0x80151258: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPortraitAddCross(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131E70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131E74: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131E78: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131E7C: lw          $t6, -0x7350($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7350);
    // 0x80131E80: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131E84: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131E88: addiu       $t7, $t7, 0x2B8
    ctx->r15 = ADD32(ctx->r15, 0X2B8);
    // 0x80131E8C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80131E90: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131E94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80131E98: jal         0x800CCFDC
    // 0x80131E9C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131E9C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80131EA0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131EA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131EA8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80131EAC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80131EB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131EB4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131EB8: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EBC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80131EC0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131EC4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80131EC8: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131ECC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131ED0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80131ED4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131ED8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131EDC: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80131EE0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131EE4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131EE8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131EF4: jr          $ra
    // 0x80131EF8: nop

    return;
    // 0x80131EF8: nop

;}
RECOMP_FUNC void func_ovl2_800FD5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD5D0: jr          $ra
    // 0x800FD5D4: nop

    return;
    // 0x800FD5D4: nop

;}
RECOMP_FUNC void lbCommonGetBitmapDecodeNibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB644: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CB648: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CB64C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800CB650: addiu       $t6, $t6, 0x5D44
    ctx->r14 = ADD32(ctx->r14, 0X5D44);
    // 0x800CB654: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800CB658: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x800CB65C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800CB660: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x800CB664: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CB668: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800CB66C: jr          $ra
    // 0x800CB670: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CB670: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ftKirbySpecialAirNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162908: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016290C: jal         0x800DE6E4
    // 0x80162910: addiu       $a1, $a1, 0x2C40
    ctx->r5 = ADD32(ctx->r5, 0X2C40);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80162910: addiu       $a1, $a1, 0x2C40
    ctx->r5 = ADD32(ctx->r5, 0X2C40);
    after_0:
    // 0x80162914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016291C: jr          $ra
    // 0x80162920: nop

    return;
    // 0x80162920: nop

;}
RECOMP_FUNC void mpCommonSetFighterFallOnGroundBreak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDEC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDEC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDECC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800DDED0: jal         0x800DDDDC
    // 0x800DDED4: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x800DDED4: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    after_0:
    // 0x800DDED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDEE0: jr          $ra
    // 0x800DDEE4: nop

    return;
    // 0x800DDEE4: nop

;}
RECOMP_FUNC void alEvtqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028EC8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80028ECC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80028ED0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80028ED4: jal         0x80030350
    // 0x80028ED8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80028ED8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80028EDC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80028EE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80028EE4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80028EE8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x80028EEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80028EF0: beq         $a3, $zero, L_80028F48
    if (ctx->r7 == 0) {
        // 0x80028EF4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80028F48;
    }
    // 0x80028EF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80028EF8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80028EFC: jal         0x80028C84
    // 0x80028F00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80028F00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_1:
    // 0x80028F04: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80028F08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80028F0C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80028F10: jal         0x80035740
    // 0x80028F14: addiu       $a0, $a3, 0xC
    ctx->r4 = ADD32(ctx->r7, 0XC);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x80028F14: addiu       $a0, $a3, 0xC
    ctx->r4 = ADD32(ctx->r7, 0XC);
    after_2:
    // 0x80028F18: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80028F1C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80028F20: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80028F24: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80028F28: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80028F2C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80028F30: beql        $v0, $zero, L_80028F40
    if (ctx->r2 == 0) {
        // 0x80028F34: sw          $a3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r7;
            goto L_80028F40;
    }
    goto skip_0;
    // 0x80028F34: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    skip_0:
    // 0x80028F38: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80028F3C: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
L_80028F40:
    // 0x80028F40: b           L_80028F50
    // 0x80028F44: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
        goto L_80028F50;
    // 0x80028F44: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
L_80028F48:
    // 0x80028F48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80028F4C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_80028F50:
    // 0x80028F50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80028F54: jal         0x80030350
    // 0x80028F58: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80028F58: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x80028F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028F60: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80028F64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80028F68: jr          $ra
    // 0x80028F6C: nop

    return;
    // 0x80028F6C: nop

;}
RECOMP_FUNC void ftDonkeyThrowFWalkSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D68C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014D698: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8014D69C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D6A0: jal         0x8013E340
    // 0x8014D6A4: lb          $a0, 0x1C2($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1C2);
    ftCommonWalkGetWalkStatus(rdram, ctx);
        goto after_0;
    // 0x8014D6A4: lb          $a0, 0x1C2($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1C2);
    after_0:
    // 0x8014D6A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014D6AC: addiu       $a1, $v0, 0xE1
    ctx->r5 = ADD32(ctx->r2, 0XE1);
    // 0x8014D6B0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8014D6B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014D6B8: jal         0x800E6F24
    // 0x8014D6BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014D6BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014D6C0: jal         0x800E0830
    // 0x8014D6C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014D6C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014D6C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D6CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D6D0: jr          $ra
    // 0x8014D6D4: nop

    return;
    // 0x8014D6D4: nop

;}
RECOMP_FUNC void func_ovl2_80103280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103280: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103284: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80103288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010328C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103290: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103294: lw          $a0, 0x1080($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1080);
    // 0x80103298: jal         0x800CE9E8
    // 0x8010329C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x8010329C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x801032A0: beq         $v0, $zero, L_80103308
    if (ctx->r2 == 0) {
        // 0x801032A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80103308;
    }
    // 0x801032A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801032A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801032AC: jal         0x800CE1DC
    // 0x801032B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801032B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801032B4: beq         $v0, $zero, L_801032FC
    if (ctx->r2 == 0) {
        // 0x801032B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801032FC;
    }
    // 0x801032B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801032BC: jal         0x800CEA14
    // 0x801032C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x801032C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801032C4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801032C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801032CC: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x801032D0: bnel        $t6, $zero, L_801032E4
    if (ctx->r14 != 0) {
        // 0x801032D4: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_801032E4;
    }
    goto skip_0;
    // 0x801032D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x801032D8: b           L_8010330C
    // 0x801032DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010330C;
    // 0x801032DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801032E0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_801032E4:
    // 0x801032E4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801032E8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801032EC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801032F0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801032F4: b           L_80103308
    // 0x801032F8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80103308;
    // 0x801032F8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_801032FC:
    // 0x801032FC: jal         0x800CEA40
    // 0x80103300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80103300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80103304: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80103308:
    // 0x80103308: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010330C:
    // 0x8010330C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103318: jr          $ra
    // 0x8010331C: nop

    return;
    // 0x8010331C: nop

;}
RECOMP_FUNC void ftDonkeySpecialLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BAA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BAA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BAAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015BAB0: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x8015BAB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BAB8: jal         0x800E6F24
    // 0x8015BABC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BABC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015BAC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BAC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BAC8: jr          $ra
    // 0x8015BACC: nop

    return;
    // 0x8015BACC: nop

;}
RECOMP_FUNC void mnPlayers1PGameUpdateCursorGrabPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135C88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135C8C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135C94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80135C98: addiu       $t6, $t6, -0x742C
    ctx->r14 = ADD32(ctx->r14, -0X742C);
    // 0x80135C9C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80135CA0: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80135CA4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80135CA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80135CAC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80135CB0: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80135CB4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80135CB8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80135CBC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80135CC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80135CC4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80135CC8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80135CCC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80135CD0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80135CD4: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80135CD8: lw          $a0, -0x7114($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7114);
    // 0x80135CDC: jal         0x8000A0D0
    // 0x80135CE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80135CE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_0:
    // 0x80135CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80135CEC: jr          $ra
    // 0x80135CF0: nop

    return;
    // 0x80135CF0: nop

;}
RECOMP_FUNC void func_ovl8_80373980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373980: jr          $ra
    // 0x80373984: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    return;
    // 0x80373984: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
;}
RECOMP_FUNC void wpDisplayDLHead1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801675D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801675D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801675D8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801675DC: jal         0x80167520
    // 0x801675E0: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    wpDisplayMain(rdram, ctx);
        goto after_0;
    // 0x801675E0: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    after_0:
    // 0x801675E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801675E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801675EC: jr          $ra
    // 0x801675F0: nop

    return;
    // 0x801675F0: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151860: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151864: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80151868: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015186C: jr          $ra
    // 0x80151870: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x80151870: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void syDmaCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A90: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80002A94: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002A98: lbu         $fp, 0x73($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X73);
    // 0x80002A9C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002AA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002AA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002AAC: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80002AB0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80002AB4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80002AB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002ABC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002AC0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002AC4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002AC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002ACC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002AD0: bne         $fp, $at, L_80002AEC
    if (ctx->r30 != ctx->r1) {
        // 0x80002AD4: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_80002AEC;
    }
    // 0x80002AD4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80002AD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80002ADC: jal         0x800321D0
    // 0x80002AE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80002AE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80002AE4: b           L_80002AFC
    // 0x80002AE8: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
        goto L_80002AFC;
    // 0x80002AE8: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
L_80002AEC:
    // 0x80002AEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80002AF0: jal         0x80034530
    // 0x80002AF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80002AF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80002AF8: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
L_80002AFC:
    // 0x80002AFC: ori         $s4, $s4, 0x1
    ctx->r20 = ctx->r20 | 0X1;
    // 0x80002B00: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80002B04: addiu       $s7, $s7, 0x50C0
    ctx->r23 = ADD32(ctx->r23, 0X50C0);
    // 0x80002B08: lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
    // 0x80002B0C: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x80002B10: sb          $zero, 0x4A($sp)
    MEM_B(0X4A, ctx->r29) = 0;
    // 0x80002B14: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80002B18: bne         $at, $zero, L_80002B70
    if (ctx->r1 != 0) {
        // 0x80002B1C: sw          $s0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r16;
            goto L_80002B70;
    }
    // 0x80002B1C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80002B20: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80002B24: addiu       $s5, $s5, 0x5020
    ctx->r21 = ADD32(ctx->r21, 0X5020);
    // 0x80002B28: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
L_80002B2C:
    // 0x80002B2C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80002B30: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80002B34: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80002B38: bne         $t6, $zero, L_80002B4C
    if (ctx->r14 != 0) {
        // 0x80002B3C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80002B4C;
    }
    // 0x80002B3C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80002B40: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80002B44: jal         0x80034300
    // 0x80002B48: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x80002B48: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_2:
L_80002B4C:
    // 0x80002B4C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80002B50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002B54: jal         0x80030210
    // 0x80002B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80002B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80002B5C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80002B60: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x80002B64: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80002B68: beq         $at, $zero, L_80002B2C
    if (ctx->r1 == 0) {
        // 0x80002B6C: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_80002B2C;
    }
    // 0x80002B6C: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_80002B70:
    // 0x80002B70: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80002B74: addiu       $s5, $s5, 0x5020
    ctx->r21 = ADD32(ctx->r21, 0X5020);
    // 0x80002B78: beq         $s1, $zero, L_80002BB4
    if (ctx->r17 == 0) {
        // 0x80002B7C: addiu       $s6, $sp, 0x48
        ctx->r22 = ADD32(ctx->r29, 0X48);
            goto L_80002BB4;
    }
    // 0x80002B7C: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x80002B80: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80002B84: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80002B88: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80002B8C: bne         $t7, $zero, L_80002BA4
    if (ctx->r15 != 0) {
        // 0x80002B90: sw          $s1, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r17;
            goto L_80002BA4;
    }
    // 0x80002B90: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80002B94: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80002B98: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80002B9C: jal         0x80034300
    // 0x80002BA0: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x80002BA0: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_4:
L_80002BA4:
    // 0x80002BA4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80002BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002BAC: jal         0x80030210
    // 0x80002BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80002BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80002BB4:
    // 0x80002BB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002BBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002BC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002BC4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80002BC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002BCC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002BD0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002BD4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80002BD8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002BDC: jr          $ra
    // 0x80002BE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80002BE0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void gcGetGObjsActiveNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800078CC: lw          $v0, 0x67FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67FC);
    // 0x800078D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800078D4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800078D8: beq         $v0, $zero, L_800078F0
    if (ctx->r2 == 0) {
        // 0x800078DC: nop
    
            goto L_800078F0;
    }
    // 0x800078DC: nop

    // 0x800078E0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_800078E4:
    // 0x800078E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800078E8: bnel        $v0, $zero, L_800078E4
    if (ctx->r2 != 0) {
        // 0x800078EC: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_800078E4;
    }
    goto skip_0;
    // 0x800078EC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
L_800078F0:
    // 0x800078F0: lw          $t6, 0x6A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A0C);
    // 0x800078F4: jr          $ra
    // 0x800078F8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    return;
    // 0x800078F8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
;}
RECOMP_FUNC void mnVSResultMakeTeamName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134480: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80134484: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134488: addiu       $t7, $t7, -0x6A80
    ctx->r15 = ADD32(ctx->r15, -0X6A80);
    // 0x8013448C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134490: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80134494: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
L_80134498:
    // 0x80134498: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013449C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801344A0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801344A4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801344A8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801344AC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801344B0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801344B4: bne         $t7, $t0, L_80134498
    if (ctx->r15 != ctx->r8) {
        // 0x801344B8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80134498;
    }
    // 0x801344B8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801344BC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801344C0: addiu       $t2, $t2, -0x6A5C
    ctx->r10 = ADD32(ctx->r10, -0X6A5C);
    // 0x801344C4: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x801344C8: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
L_801344CC:
    // 0x801344CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801344D0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x801344D4: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x801344D8: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x801344DC: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x801344E0: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x801344E4: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x801344E8: bne         $t2, $t5, L_801344CC
    if (ctx->r10 != ctx->r13) {
        // 0x801344EC: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_801344CC;
    }
    // 0x801344EC: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x801344F0: jal         0x80132A2C
    // 0x801344F4: nop

    mnVSResultsGetWinTeam(rdram, ctx);
        goto after_0;
    // 0x801344F4: nop

    after_0:
    // 0x801344F8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801344FC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80134500: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134508: addu        $a0, $sp, $v1
    ctx->r4 = ADD32(ctx->r29, ctx->r3);
    // 0x8013450C: addu        $t0, $sp, $v1
    ctx->r8 = ADD32(ctx->r29, ctx->r3);
    // 0x80134510: lw          $a1, 0x24($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X24);
    // 0x80134514: lw          $a0, 0x48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48);
    // 0x80134518: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x8013451C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80134520: jal         0x80133F6C
    // 0x80134524: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mnVSResultsMakeString(rdram, ctx);
        goto after_1;
    // 0x80134524: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134528: jal         0x8013423C
    // 0x8013452C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    mnVSResultsMakeWinnerText(rdram, ctx);
        goto after_2;
    // 0x8013452C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x80134530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134534: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80134538: jr          $ra
    // 0x8013453C: nop

    return;
    // 0x8013453C: nop

;}
RECOMP_FUNC void itMainCopyDamageStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801727BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801727C0: lw          $t6, 0x2A8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2A8);
    // 0x801727C4: lbu         $t7, 0x2AC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2AC);
    // 0x801727C8: lbu         $t8, 0x2AD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2AD);
    // 0x801727CC: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x801727D0: lbu         $t0, 0x2B4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2B4);
    // 0x801727D4: lw          $t1, 0x2B8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2B8);
    // 0x801727D8: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x801727DC: sb          $t7, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r15;
    // 0x801727E0: sb          $t8, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r24;
    // 0x801727E4: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x801727E8: sb          $t0, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r8;
    // 0x801727EC: jr          $ra
    // 0x801727F0: sw          $t1, 0x374($v0)
    MEM_W(0X374, ctx->r2) = ctx->r9;
    return;
    // 0x801727F0: sw          $t1, 0x374($v0)
    MEM_W(0X374, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void mnMessageMakeExclaim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D14: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80131D18: jal         0x80009968
    // 0x80131D1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D24: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D30: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131D34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131D3C: jal         0x80009DF4
    // 0x80131D40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D44: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D48: lw          $t7, 0x298C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X298C);
    // 0x80131D4C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131D50: addiu       $t8, $t8, 0x5300
    ctx->r24 = ADD32(ctx->r24, 0X5300);
    // 0x80131D54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131D58: jal         0x800CCFDC
    // 0x80131D5C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131D5C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131D60: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D64: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80131D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131D6C: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x80131D70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131D74: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131D78: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131D7C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131D80: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131D84: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131D88: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D94: jr          $ra
    // 0x80131D98: nop

    return;
    // 0x80131D98: nop

;}
RECOMP_FUNC void mnVSOptionsUnderlineProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F2C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80132F30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132F34: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80132F38: addiu       $t7, $t7, 0x478C
    ctx->r15 = ADD32(ctx->r15, 0X478C);
    // 0x80132F3C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80132F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132F44: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80132F48: addiu       $t4, $t7, 0x30
    ctx->r12 = ADD32(ctx->r15, 0X30);
    // 0x80132F4C: addiu       $t6, $sp, 0x90
    ctx->r14 = ADD32(ctx->r29, 0X90);
L_80132F50:
    // 0x80132F50: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132F54: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132F58: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132F5C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132F60: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132F64: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132F68: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132F6C: bne         $t7, $t4, L_80132F50
    if (ctx->r15 != ctx->r12) {
        // 0x80132F70: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132F50;
    }
    // 0x80132F70: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132F74: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132F78: addiu       $t4, $t4, 0x47BC
    ctx->r12 = ADD32(ctx->r12, 0X47BC);
    // 0x80132F7C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80132F80: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80132F84: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x80132F88: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80132F8C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80132F90: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x80132F94: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80132F98: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132F9C: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80132FA0: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
    // 0x80132FA4: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x80132FA8: lw          $t7, 0x14($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X14);
    // 0x80132FAC: addiu       $t9, $t9, 0x47DC
    ctx->r25 = ADD32(ctx->r25, 0X47DC);
    // 0x80132FB0: sw          $t6, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r14;
    // 0x80132FB4: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
    // 0x80132FB8: lw          $t7, 0x1C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X1C);
    // 0x80132FBC: lw          $t6, 0x18($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X18);
    // 0x80132FC0: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x80132FC4: sw          $t7, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r15;
    // 0x80132FC8: sw          $t6, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r14;
    // 0x80132FCC: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80132FD0: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80132FD4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80132FD8: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x80132FDC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80132FE0: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x80132FE4: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80132FE8: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80132FEC: sw          $t4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r12;
    // 0x80132FF0: sw          $t5, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r13;
    // 0x80132FF4: lw          $t5, 0x14($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X14);
    // 0x80132FF8: lw          $t4, 0x10($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X10);
    // 0x80132FFC: ori         $a0, $a0, 0x28FF
    ctx->r4 = ctx->r4 | 0X28FF;
    // 0x80133000: sw          $t5, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r13;
    // 0x80133004: sw          $t4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r12;
    // 0x80133008: lw          $t4, 0x18($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X18);
    // 0x8013300C: lw          $t5, 0x1C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X1C);
    // 0x80133010: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80133014: sw          $t4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r12;
    // 0x80133018: sw          $t5, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r13;
    // 0x8013301C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80133020: lui         $t5, 0x30
    ctx->r13 = S32(0X30 << 16);
    // 0x80133024: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80133028: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013302C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80133030: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133038: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8013303C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80133040: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80133044: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133048: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8013304C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133050: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80133054: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80133058: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x8013305C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80133060: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80133064: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133068: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013306C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80133070: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133074: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80133078: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013307C: jal         0x80006D70
    // 0x80133080: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x80133080: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80133084: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80133088: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013308C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80133090: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80133094: lw          $v1, 0x48E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X48E0);
    // 0x80133098: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8013309C: addiu       $t1, $sp, 0x90
    ctx->r9 = ADD32(ctx->r29, 0X90);
    // 0x801330A0: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x801330A4: beq         $v1, $zero, L_801330C8
    if (ctx->r3 == 0) {
        // 0x801330A8: addiu       $t3, $sp, 0x50
        ctx->r11 = ADD32(ctx->r29, 0X50);
            goto L_801330C8;
    }
    // 0x801330A8: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x801330AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801330B0: beq         $v1, $at, L_80133160
    if (ctx->r3 == ctx->r1) {
        // 0x801330B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80133160;
    }
    // 0x801330B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801330B8: beq         $v1, $at, L_801331FC
    if (ctx->r3 == ctx->r1) {
        // 0x801330BC: nop
    
            goto L_801331FC;
    }
    // 0x801330BC: nop

    // 0x801330C0: b           L_80133298
    // 0x801330C4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
        goto L_80133298;
    // 0x801330C4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_801330C8:
    // 0x801330C8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801330CC: lw          $t9, 0x4904($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4904);
    // 0x801330D0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801330D4: addiu       $a3, $a3, 0x48E4
    ctx->r7 = ADD32(ctx->r7, 0X48E4);
    // 0x801330D8: beq         $t9, $zero, L_801330E8
    if (ctx->r25 == 0) {
        // 0x801330DC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_801330E8;
    }
    // 0x801330DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x801330E0: b           L_801330E8
    // 0x801330E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_801330E8;
    // 0x801330E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801330E8:
    // 0x801330E8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x801330EC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801330F0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x801330F4: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x801330F8: addu        $v1, $t1, $t7
    ctx->r3 = ADD32(ctx->r9, ctx->r15);
    // 0x801330FC: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80133100: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80133104: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80133108: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x8013310C: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80133110: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80133114: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80133118: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x8013311C: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80133120: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80133124: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80133128: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013312C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80133130: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80133134: addu        $v1, $t1, $t7
    ctx->r3 = ADD32(ctx->r9, ctx->r15);
    // 0x80133138: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8013313C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80133140: addu        $t4, $t6, $a0
    ctx->r12 = ADD32(ctx->r14, ctx->r4);
    // 0x80133144: andi        $t8, $t4, 0x3FF
    ctx->r24 = ctx->r12 & 0X3FF;
    // 0x80133148: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x8013314C: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x80133150: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80133154: or          $t4, $t9, $t6
    ctx->r12 = ctx->r25 | ctx->r14;
    // 0x80133158: b           L_80133294
    // 0x8013315C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80133294;
    // 0x8013315C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80133160:
    // 0x80133160: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133164: lw          $t8, 0x4904($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4904);
    // 0x80133168: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8013316C: addiu       $a3, $a3, 0x48E8
    ctx->r7 = ADD32(ctx->r7, 0X48E8);
    // 0x80133170: beql        $t8, $zero, L_80133184
    if (ctx->r24 == 0) {
        // 0x80133174: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80133184;
    }
    goto skip_0;
    // 0x80133174: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    skip_0:
    // 0x80133178: b           L_80133184
    // 0x8013317C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80133184;
    // 0x8013317C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133180: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
L_80133184:
    // 0x80133184: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80133188: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8013318C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80133190: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80133194: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x80133198: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8013319C: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x801331A0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801331A4: addu        $t4, $t6, $a0
    ctx->r12 = ADD32(ctx->r14, ctx->r4);
    // 0x801331A8: andi        $t8, $t4, 0x3FF
    ctx->r24 = ctx->r12 & 0X3FF;
    // 0x801331AC: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x801331B0: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x801331B4: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x801331B8: sll         $t4, $t6, 14
    ctx->r12 = S32(ctx->r14 << 14);
    // 0x801331BC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x801331C0: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x801331C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801331C8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801331CC: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x801331D0: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x801331D4: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x801331D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801331DC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x801331E0: andi        $t4, $t7, 0x3FF
    ctx->r12 = ctx->r15 & 0X3FF;
    // 0x801331E4: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x801331E8: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x801331EC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x801331F0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x801331F4: b           L_80133294
    // 0x801331F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_80133294;
    // 0x801331F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_801331FC:
    // 0x801331FC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133200: lw          $t4, 0x4904($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4904);
    // 0x80133204: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133208: addiu       $a3, $a3, 0x48EC
    ctx->r7 = ADD32(ctx->r7, 0X48EC);
    // 0x8013320C: beql        $t4, $zero, L_80133220
    if (ctx->r12 == 0) {
        // 0x80133210: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80133220;
    }
    goto skip_1;
    // 0x80133210: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    skip_1:
    // 0x80133214: b           L_80133220
    // 0x80133218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80133220;
    // 0x80133218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013321C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80133220:
    // 0x80133220: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80133224: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80133228: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8013322C: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80133230: addu        $v1, $t3, $t8
    ctx->r3 = ADD32(ctx->r11, ctx->r24);
    // 0x80133234: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80133238: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8013323C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80133240: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80133244: andi        $t4, $t7, 0x3FF
    ctx->r12 = ctx->r15 & 0X3FF;
    // 0x80133248: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8013324C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133250: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x80133254: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80133258: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8013325C: or          $t4, $t9, $t7
    ctx->r12 = ctx->r25 | ctx->r15;
    // 0x80133260: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80133264: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80133268: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x8013326C: addu        $v1, $t3, $t8
    ctx->r3 = ADD32(ctx->r11, ctx->r24);
    // 0x80133270: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80133274: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80133278: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x8013327C: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x80133280: andi        $t8, $t5, 0x3FF
    ctx->r24 = ctx->r13 & 0X3FF;
    // 0x80133284: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80133288: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8013328C: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x80133290: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80133294:
    // 0x80133294: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
L_80133298:
    // 0x80133298: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8013329C: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x801332A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801332A4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801332A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801332AC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801332B0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801332B4: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x801332B8: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x801332BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801332C0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801332C4: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x801332C8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801332CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801332D0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801332D4: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801332D8: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x801332DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801332E0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801332E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801332E8: jal         0x800CCEAC
    // 0x801332EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x801332EC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_1:
    // 0x801332F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801332F4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x801332F8: jr          $ra
    // 0x801332FC: nop

    return;
    // 0x801332FC: nop

;}
RECOMP_FUNC void ifCommonCountdownThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801122F4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801122F8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801122FC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80112300: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112304: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80112308: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8011230C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80112310: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80112314: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80112318: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8011231C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80112320: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80112324: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80112328: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8011232C: lwc1        $f0, 0xC78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC78);
    // 0x80112330: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80112334: lw          $s0, 0x74($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X74);
L_80112338:
    // 0x80112338: beq         $s0, $zero, L_80112358
    if (ctx->r16 == 0) {
        // 0x8011233C: nop
    
            goto L_80112358;
    }
    // 0x8011233C: nop

    // 0x80112340: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
L_80112344:
    // 0x80112344: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80112348: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    // 0x8011234C: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80112350: bnel        $s0, $zero, L_80112344
    if (ctx->r16 != 0) {
        // 0x80112354: lwc1        $f4, 0x5C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
            goto L_80112344;
    }
    goto skip_0;
    // 0x80112354: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    skip_0:
L_80112358:
    // 0x80112358: jal         0x8000B1E8
    // 0x8011235C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x8011235C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80112360: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112364: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80112368: lwc1        $f0, 0xC7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC7C);
    // 0x8011236C: slti        $at, $s4, 0x3C
    ctx->r1 = SIGNED(ctx->r20) < 0X3C ? 1 : 0;
    // 0x80112370: bnel        $at, $zero, L_80112338
    if (ctx->r1 != 0) {
        // 0x80112374: lw          $s0, 0x74($s5)
        ctx->r16 = MEM_W(ctx->r21, 0X74);
            goto L_80112338;
    }
    goto skip_1;
    // 0x80112374: lw          $s0, 0x74($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X74);
    skip_1:
    // 0x80112378: lw          $s0, 0x84($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X84);
    // 0x8011237C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80112380: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80112384: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80112388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8011238C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80112390: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80112394: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80112398: lwc1        $f20, 0x50($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8011239C: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x801123A0: lw          $s1, 0x8($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X8);
    // 0x801123A4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
L_801123A8:
    // 0x801123A8: beq         $s4, $at, L_801123E4
    if (ctx->r20 == ctx->r1) {
        // 0x801123AC: addiu       $a0, $zero, 0x1D6
        ctx->r4 = ADD32(0, 0X1D6);
            goto L_801123E4;
    }
    // 0x801123AC: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    // 0x801123B0: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x801123B4: beq         $s4, $at, L_801123F8
    if (ctx->r20 == ctx->r1) {
        // 0x801123B8: addiu       $a0, $zero, 0x1D5
        ctx->r4 = ADD32(0, 0X1D5);
            goto L_801123F8;
    }
    // 0x801123B8: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    // 0x801123BC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x801123C0: beq         $s4, $at, L_8011240C
    if (ctx->r20 == ctx->r1) {
        // 0x801123C4: addiu       $a0, $zero, 0x1D3
        ctx->r4 = ADD32(0, 0X1D3);
            goto L_8011240C;
    }
    // 0x801123C4: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    // 0x801123C8: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x801123CC: beq         $s4, $at, L_80112420
    if (ctx->r20 == ctx->r1) {
        // 0x801123D0: addiu       $at, $zero, 0x168
        ctx->r1 = ADD32(0, 0X168);
            goto L_80112420;
    }
    // 0x801123D0: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x801123D4: beql        $s4, $at, L_801125D4
    if (ctx->r20 == ctx->r1) {
        // 0x801123D8: slti        $at, $s4, 0x1A4
        ctx->r1 = SIGNED(ctx->r20) < 0X1A4 ? 1 : 0;
            goto L_801125D4;
    }
    goto skip_2;
    // 0x801123D8: slti        $at, $s4, 0x1A4
    ctx->r1 = SIGNED(ctx->r20) < 0X1A4 ? 1 : 0;
    skip_2:
    // 0x801123DC: b           L_80112444
    // 0x801123E0: nop

        goto L_80112444;
    // 0x801123E0: nop

L_801123E4:
    // 0x801123E4: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x801123E8: jal         0x800269C0
    // 0x801123EC: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x801123EC: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    after_1:
    // 0x801123F0: b           L_80112444
    // 0x801123F4: nop

        goto L_80112444;
    // 0x801123F4: nop

L_801123F8:
    // 0x801123F8: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x801123FC: jal         0x800269C0
    // 0x80112400: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80112400: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    after_2:
    // 0x80112404: b           L_80112444
    // 0x80112408: nop

        goto L_80112444;
    // 0x80112408: nop

L_8011240C:
    // 0x8011240C: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80112410: jal         0x800269C0
    // 0x80112414: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80112414: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    after_3:
    // 0x80112418: b           L_80112444
    // 0x8011241C: nop

        goto L_80112444;
    // 0x8011241C: nop

L_80112420:
    // 0x80112420: jal         0x801120D4
    // 0x80112424: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
    ifCommonAnnounceGoMakeInterface(rdram, ctx);
        goto after_4;
    // 0x80112424: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
    after_4:
    // 0x80112428: jal         0x801121C4
    // 0x8011242C: nop

    ifCommonAnnounceGoSetStatus(rdram, ctx);
        goto after_5;
    // 0x8011242C: nop

    after_5:
    // 0x80112430: jal         0x8010E690
    // 0x80112434: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_6;
    // 0x80112434: nop

    after_6:
    // 0x80112438: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x8011243C: jal         0x800269C0
    // 0x80112440: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80112440: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_7:
L_80112444:
    // 0x80112444: beql        $s3, $s6, L_801125BC
    if (ctx->r19 == ctx->r22) {
        // 0x80112448: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_801125BC;
    }
    goto skip_3;
    // 0x80112448: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_3:
    // 0x8011244C: beql        $s2, $s6, L_80112514
    if (ctx->r18 == ctx->r22) {
        // 0x80112450: c.eq.s      $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
            goto L_80112514;
    }
    goto skip_4;
    // 0x80112450: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    skip_4:
    // 0x80112454: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80112458: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x8011245C: jal         0x800096EC
    // 0x80112460: addiu       $s2, $s3, 0x5
    ctx->r18 = ADD32(ctx->r19, 0X5);
    gcEjectSObj(rdram, ctx);
        goto after_8;
    // 0x80112460: addiu       $s2, $s3, 0x5
    ctx->r18 = ADD32(ctx->r19, 0X5);
    after_8:
    // 0x80112464: jal         0x800096EC
    // 0x80112468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectSObj(rdram, ctx);
        goto after_9;
    // 0x80112468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8011246C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80112470: jal         0x80112234
    // 0x80112474: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    ifCommonTrafficMakeSObj(rdram, ctx);
        goto after_10;
    // 0x80112474: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_10:
    // 0x80112478: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8011247C: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
    // 0x80112480: swc1        $f24, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f24.u32l;
    // 0x80112484: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80112488: jal         0x80112234
    // 0x8011248C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ifCommonTrafficMakeSObj(rdram, ctx);
        goto after_11;
    // 0x8011248C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x80112490: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80112494: bne         $s3, $at, L_80112510
    if (ctx->r19 != ctx->r1) {
        // 0x80112498: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80112510;
    }
    // 0x80112498: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8011249C: lbu         $t7, -0x1333($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1333);
    // 0x801124A0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801124A4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801124A8: sb          $t7, 0x28($s1)
    MEM_B(0X28, ctx->r17) = ctx->r15;
    // 0x801124AC: lbu         $t8, -0x132F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X132F);
    // 0x801124B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801124B4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801124B8: sb          $t8, 0x29($s1)
    MEM_B(0X29, ctx->r17) = ctx->r24;
    // 0x801124BC: lbu         $t9, -0x132B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X132B);
    // 0x801124C0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x801124C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801124C8: sb          $t9, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r25;
    // 0x801124CC: lbu         $t0, -0x1327($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1327);
    // 0x801124D0: sb          $t0, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r8;
    // 0x801124D4: lbu         $t1, -0x1323($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1323);
    // 0x801124D8: sb          $t1, 0x61($s1)
    MEM_B(0X61, ctx->r17) = ctx->r9;
    // 0x801124DC: lbu         $t2, -0x131F($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X131F);
    // 0x801124E0: beq         $v1, $zero, L_801124F0
    if (ctx->r3 == 0) {
        // 0x801124E4: sb          $t2, 0x62($s1)
        MEM_B(0X62, ctx->r17) = ctx->r10;
            goto L_801124F0;
    }
    // 0x801124E4: sb          $t2, 0x62($s1)
    MEM_B(0X62, ctx->r17) = ctx->r10;
    // 0x801124E8: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x801124EC: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
L_801124F0:
    // 0x801124F0: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x801124F4: beql        $v1, $zero, L_80112508
    if (ctx->r3 == 0) {
        // 0x801124F8: sw          $s1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r17;
            goto L_80112508;
    }
    goto skip_5;
    // 0x801124F8: sw          $s1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r17;
    skip_5:
    // 0x801124FC: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x80112500: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80112504: sw          $s1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r17;
L_80112508:
    // 0x80112508: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8011250C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
L_80112510:
    // 0x80112510: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
L_80112514:
    // 0x80112514: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112518: bc1tl       L_801125BC
    if (c1cs) {
        // 0x8011251C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_801125BC;
    }
    goto skip_6;
    // 0x8011251C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_6:
    // 0x80112520: lwc1        $f8, 0xC80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC80);
    // 0x80112524: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x80112528: subu        $t5, $t5, $s3
    ctx->r13 = SUB32(ctx->r13, ctx->r19);
    // 0x8011252C: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x80112530: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80112534: addiu       $t6, $t6, -0x131C
    ctx->r14 = ADD32(ctx->r14, -0X131C);
    // 0x80112538: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8011253C: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80112540: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80112544: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80112548: bc1fl       L_8011255C
    if (!c1cs) {
        // 0x8011254C: lh          $t8, 0x14($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X14);
            goto L_8011255C;
    }
    goto skip_7;
    // 0x8011254C: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
    skip_7:
    // 0x80112550: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80112554: nop

    // 0x80112558: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
L_8011255C:
    // 0x8011255C: sub.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80112560: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80112564: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80112568: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8011256C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x80112570: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80112574: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x80112578: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8011257C: lh          $t0, 0x16($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X16);
    // 0x80112580: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80112584: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80112588: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8011258C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80112590: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80112594: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80112598: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8011259C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x801125A0: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x801125A4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801125A8: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801125AC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801125B0: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801125B4: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
    // 0x801125B8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_801125BC:
    // 0x801125BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801125C0: jal         0x8000B1E8
    // 0x801125C4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_12;
    // 0x801125C4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    after_12:
    // 0x801125C8: b           L_801123A8
    // 0x801125CC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
        goto L_801123A8;
    // 0x801125CC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x801125D0: slti        $at, $s4, 0x1A4
    ctx->r1 = SIGNED(ctx->r20) < 0X1A4 ? 1 : 0;
L_801125D4:
    // 0x801125D4: beq         $at, $zero, L_80112624
    if (ctx->r1 == 0) {
        // 0x801125D8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80112624;
    }
    // 0x801125D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801125DC: lwc1        $f0, 0xC84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC84);
    // 0x801125E0: lw          $s0, 0x74($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X74);
L_801125E4:
    // 0x801125E4: beq         $s0, $zero, L_80112604
    if (ctx->r16 == 0) {
        // 0x801125E8: nop
    
            goto L_80112604;
    }
    // 0x801125E8: nop

    // 0x801125EC: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
L_801125F0:
    // 0x801125F0: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801125F4: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x801125F8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x801125FC: bnel        $s0, $zero, L_801125F0
    if (ctx->r16 != 0) {
        // 0x80112600: lwc1        $f18, 0x5C($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
            goto L_801125F0;
    }
    goto skip_8;
    // 0x80112600: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    skip_8:
L_80112604:
    // 0x80112604: jal         0x8000B1E8
    // 0x80112608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_13;
    // 0x80112608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8011260C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112610: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80112614: lwc1        $f0, 0xC88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC88);
    // 0x80112618: slti        $at, $s4, 0x1A4
    ctx->r1 = SIGNED(ctx->r20) < 0X1A4 ? 1 : 0;
    // 0x8011261C: bnel        $at, $zero, L_801125E4
    if (ctx->r1 != 0) {
        // 0x80112620: lw          $s0, 0x74($s5)
        ctx->r16 = MEM_W(ctx->r21, 0X74);
            goto L_801125E4;
    }
    goto skip_9;
    // 0x80112620: lw          $s0, 0x74($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X74);
    skip_9:
L_80112624:
    // 0x80112624: jal         0x80009A84
    // 0x80112628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_14;
    // 0x80112628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8011262C: jal         0x8000B1E8
    // 0x80112630: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_15;
    // 0x80112630: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80112634: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80112638: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8011263C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80112640: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80112644: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80112648: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8011264C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80112650: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80112654: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80112658: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8011265C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80112660: jr          $ra
    // 0x80112664: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80112664: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sc1PTrainingModeCheckUpdateOptionID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D40C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D410: lhu         $v0, 0xC20($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XC20);
    // 0x8018D414: andi        $t6, $v0, 0x300
    ctx->r14 = ctx->r2 & 0X300;
    // 0x8018D418: beq         $t6, $zero, L_8018D46C
    if (ctx->r14 == 0) {
        // 0x8018D41C: andi        $t7, $v0, 0x200
        ctx->r15 = ctx->r2 & 0X200;
            goto L_8018D46C;
    }
    // 0x8018D41C: andi        $t7, $v0, 0x200
    ctx->r15 = ctx->r2 & 0X200;
    // 0x8018D420: beql        $t7, $zero, L_8018D450
    if (ctx->r15 == 0) {
        // 0x8018D424: lw          $t2, 0x0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X0);
            goto L_8018D450;
    }
    goto skip_0;
    // 0x8018D424: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8018D428: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8018D42C: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x8018D430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018D434: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018D438: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8018D43C: beq         $at, $zero, L_8018D464
    if (ctx->r1 == 0) {
        // 0x8018D440: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8018D464;
    }
    // 0x8018D440: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8018D444: jr          $ra
    // 0x8018D448: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    return;
    // 0x8018D448: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8018D44C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
L_8018D450:
    // 0x8018D450: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8018D454: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8018D458: bne         $at, $zero, L_8018D464
    if (ctx->r1 != 0) {
        // 0x8018D45C: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_8018D464;
    }
    // 0x8018D45C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8018D460: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8018D464:
    // 0x8018D464: jr          $ra
    // 0x8018D468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8018D468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D46C:
    // 0x8018D46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D470: jr          $ra
    // 0x8018D474: nop

    return;
    // 0x8018D474: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetNumberDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131C48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131C50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C58: blez        $a1, L_80131CD0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131C5C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131CD0;
    }
    // 0x80131C5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131C60:
    // 0x80131C60: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131C64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131C68: jal         0x80131B58
    // 0x80131C6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnPlayers1PBonusGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131C6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131C70: beq         $v0, $zero, L_80131CB8
    if (ctx->r2 == 0) {
        // 0x80131C74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131CB8;
    }
    // 0x80131C74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131C78: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131C7C: jal         0x80131B58
    // 0x80131C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131C84: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131C88: mflo        $v1
    ctx->r3 = lo;
    // 0x80131C8C: bne         $v0, $zero, L_80131C98
    if (ctx->r2 != 0) {
        // 0x80131C90: nop
    
            goto L_80131C98;
    }
    // 0x80131C90: nop

    // 0x80131C94: break       7
    do_break(2148736148);
L_80131C98:
    // 0x80131C98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131C9C: bne         $v0, $at, L_80131CB0
    if (ctx->r2 != ctx->r1) {
        // 0x80131CA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131CB0;
    }
    // 0x80131CA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131CA4: bne         $s2, $at, L_80131CB0
    if (ctx->r18 != ctx->r1) {
        // 0x80131CA8: nop
    
            goto L_80131CB0;
    }
    // 0x80131CA8: nop

    // 0x80131CAC: break       6
    do_break(2148736172);
L_80131CB0:
    // 0x80131CB0: b           L_80131CB8
    // 0x80131CB4: nop

        goto L_80131CB8;
    // 0x80131CB4: nop

L_80131CB8:
    // 0x80131CB8: beq         $v1, $zero, L_80131CC8
    if (ctx->r3 == 0) {
        // 0x80131CBC: nop
    
            goto L_80131CC8;
    }
    // 0x80131CBC: nop

    // 0x80131CC0: b           L_80131CD4
    // 0x80131CC4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131CD4;
    // 0x80131CC4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131CC8:
    // 0x80131CC8: bne         $s0, $zero, L_80131C60
    if (ctx->r16 != 0) {
        // 0x80131CCC: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131C60;
    }
    // 0x80131CCC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131CD0:
    // 0x80131CD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131CD4:
    // 0x80131CD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CE4: jr          $ra
    // 0x80131CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PStageClearMakeTimerDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013263C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132640: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132644: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x80132648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013264C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132650: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132654: jal         0x80009968
    // 0x80132658: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132658: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013265C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132660: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132664: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132668: sw          $v0, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = ctx->r2;
    // 0x8013266C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132670: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132674: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132678: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013267C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132680: jal         0x80009DF4
    // 0x80132684: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132684: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132688: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013268C: lw          $t7, 0x5594($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5594);
    // 0x80132690: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132694: addiu       $t8, $t8, 0x1018
    ctx->r24 = ADD32(ctx->r24, 0X1018);
    // 0x80132698: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8013269C: jal         0x800CCFDC
    // 0x801326A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801326A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801326A4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801326A8: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
    // 0x801326AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801326B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801326B8: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801326BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801326C0: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x801326C4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801326C8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801326CC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801326D0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801326D4: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x801326D8: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801326DC: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801326E0: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801326E4: sb          $a0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r4;
    // 0x801326E8: sb          $a0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r4;
    // 0x801326EC: sb          $a0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r4;
    // 0x801326F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801326F4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801326F8: lw          $v1, 0x52EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52EC);
    // 0x801326FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132700: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132704: beq         $v1, $at, L_80132728
    if (ctx->r3 == ctx->r1) {
        // 0x80132708: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80132728;
    }
    // 0x80132708: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013270C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132710: beq         $v1, $at, L_80132728
    if (ctx->r3 == ctx->r1) {
        // 0x80132714: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80132728;
    }
    // 0x80132714: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80132718: beql        $v1, $at, L_8013273C
    if (ctx->r3 == ctx->r1) {
        // 0x8013271C: lui         $at, 0x4376
        ctx->r1 = S32(0X4376 << 16);
            goto L_8013273C;
    }
    goto skip_0;
    // 0x8013271C: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    skip_0:
    // 0x80132720: b           L_80132748
    // 0x80132724: lui         $at, 0x4369
    ctx->r1 = S32(0X4369 << 16);
        goto L_80132748;
    // 0x80132724: lui         $at, 0x4369
    ctx->r1 = S32(0X4369 << 16);
L_80132728:
    // 0x80132728: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    // 0x8013272C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132730: b           L_80132750
    // 0x80132734: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
        goto L_80132750;
    // 0x80132734: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80132738: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
L_8013273C:
    // 0x8013273C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132740: b           L_80132750
    // 0x80132744: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
        goto L_80132750;
    // 0x80132744: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
L_80132748:
    // 0x80132748: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013274C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
L_80132750:
    // 0x80132750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132754: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132758: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013275C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80132760: sub.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80132764: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80132768: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013276C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80132770: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80132774: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80132778: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8013277C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80132780: jal         0x80131E10
    // 0x80132784: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_3;
    // 0x80132784: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_3:
    // 0x80132788: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8013278C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132790: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132794: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80132798: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8013279C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801327A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801327A4: lw          $a1, 0x52DC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X52DC);
    // 0x801327A8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x801327AC: lui         $a2, 0x432B
    ctx->r6 = S32(0X432B << 16);
    // 0x801327B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801327B4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801327B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801327BC: jal         0x80131E10
    // 0x801327C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_4;
    // 0x801327C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_4:
    // 0x801327C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801327C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801327CC: jr          $ra
    // 0x801327D0: nop

    return;
    // 0x801327D0: nop

;}
RECOMP_FUNC void efManagerPikachuThunderTrailProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101AA8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80101AAC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80101AB0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101ABC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101AC0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80101AC4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80101AC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101ACC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101AD0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101AD4: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80101AD8: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x80101ADC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101AE0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80101AE4: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x80101AE8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80101AEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101AF0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80101AF4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101AF8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80101AFC: ori         $t2, $t2, 0x1E01
    ctx->r10 = ctx->r10 | 0X1E01;
    // 0x80101B00: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80101B04: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80101B08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101B0C: jal         0x800143FC
    // 0x80101B10: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80101B10: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x80101B14: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80101B18: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80101B1C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101B20: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80101B24: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80101B28: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80101B2C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80101B30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101B34: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80101B38: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101B3C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80101B40: ori         $t7, $t7, 0x4340
    ctx->r15 = ctx->r15 | 0X4340;
    // 0x80101B44: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80101B48: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80101B4C: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80101B50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101B54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101B58: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80101B5C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80101B60: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x80101B64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101B68: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80101B6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80101B70: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80101B74: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101B80: jr          $ra
    // 0x80101B84: nop

    return;
    // 0x80101B84: nop

;}
RECOMP_FUNC void func_ovl8_80383510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383510: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80383514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80383518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038351C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80383520: beq         $a0, $zero, L_803835B0
    if (ctx->r4 == 0) {
        // 0x80383524: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803835B0;
    }
    // 0x80383524: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80383528: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8038352C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80383530: addiu       $t6, $t6, -0x35F0
    ctx->r14 = ADD32(ctx->r14, -0X35F0);
    // 0x80383534: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80383538: addiu       $t7, $t7, -0x34A8
    ctx->r15 = ADD32(ctx->r15, -0X34A8);
    // 0x8038353C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80383540: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80383544: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80383548: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8038354C: addiu       $t9, $t9, -0x3350
    ctx->r25 = ADD32(ctx->r25, -0X3350);
    // 0x80383550: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80383554: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x80383558: beql        $a0, $zero, L_8038356C
    if (ctx->r4 == 0) {
        // 0x8038355C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8038356C;
    }
    goto skip_0;
    // 0x8038355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80383560: jal         0x80371764
    // 0x80383564: nop

    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x80383564: nop

    after_0:
    // 0x80383568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8038356C:
    // 0x8038356C: jal         0x8037354C
    // 0x80383570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037354C(rdram, ctx);
        goto after_1;
    // 0x80383570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80383574: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80383578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038357C: beql        $t1, $zero, L_8038359C
    if (ctx->r9 == 0) {
        // 0x80383580: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8038359C;
    }
    goto skip_1;
    // 0x80383580: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80383584: jal         0x8037C30C
    // 0x80383588: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x80383588: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x8038358C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80383590: jal         0x803718C4
    // 0x80383594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x80383594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80383598: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8038359C:
    // 0x8038359C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x803835A0: beql        $t3, $zero, L_803835B4
    if (ctx->r11 == 0) {
        // 0x803835A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803835B4;
    }
    goto skip_2;
    // 0x803835A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803835A8: jal         0x803717C0
    // 0x803835AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x803835AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_803835B0:
    // 0x803835B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803835B4:
    // 0x803835B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803835B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803835BC: jr          $ra
    // 0x803835C0: nop

    return;
    // 0x803835C0: nop

;}
RECOMP_FUNC void scAutoDemoStartBattle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D0E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D0E8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8018D0EC: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8018D0F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D0F4: beq         $s0, $zero, L_8018D110
    if (ctx->r16 == 0) {
        // 0x8018D0F8: nop
    
            goto L_8018D110;
    }
    // 0x8018D0F8: nop

L_8018D0FC:
    // 0x8018D0FC: jal         0x800E7F68
    // 0x8018D100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_0;
    // 0x8018D100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018D104: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8018D108: bne         $s0, $zero, L_8018D0FC
    if (ctx->r16 != 0) {
        // 0x8018D10C: nop
    
            goto L_8018D0FC;
    }
    // 0x8018D10C: nop

L_8018D110:
    // 0x8018D110: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018D114: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018D118: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D11C: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x8018D120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D124: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D12C: jr          $ra
    // 0x8018D130: nop

    return;
    // 0x8018D130: nop

;}
RECOMP_FUNC void func_ovl3_80134964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134964: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80134968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013496C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134970: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x80134974: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80134978: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013497C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x80134980: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134984: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80134988: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013498C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80134990: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    // 0x80134994: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134998: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8013499C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801349A0: lbu         $t1, 0x216($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X216);
    // 0x801349A4: lb          $t4, 0x215($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X215);
    // 0x801349A8: sw          $t0, 0x228($a0)
    MEM_W(0X228, ctx->r4) = ctx->r8;
    // 0x801349AC: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x801349B0: bltz        $t4, L_80134B30
    if (SIGNED(ctx->r12) < 0) {
        // 0x801349B4: sb          $t2, 0x216($a0)
        MEM_B(0X216, ctx->r4) = ctx->r10;
            goto L_80134B30;
    }
    // 0x801349B4: sb          $t2, 0x216($a0)
    MEM_B(0X216, ctx->r4) = ctx->r10;
    // 0x801349B8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801349BC: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801349C0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801349C4: nop

    // 0x801349C8: bc1f        L_80134B30
    if (!c1cs) {
        // 0x801349CC: nop
    
            goto L_80134B30;
    }
    // 0x801349CC: nop

    // 0x801349D0: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x801349D4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x801349D8: nop

    // 0x801349DC: bc1f        L_80134B30
    if (!c1cs) {
        // 0x801349E0: nop
    
            goto L_80134B30;
    }
    // 0x801349E0: nop

    // 0x801349E4: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801349E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801349EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801349F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801349F4: nop

    // 0x801349F8: bc1f        L_80134A48
    if (!c1cs) {
        // 0x801349FC: nop
    
            goto L_80134A48;
    }
    // 0x801349FC: nop

    // 0x80134A00: jal         0x80134000
    // 0x80134A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftComputerCheckSetTargetEdgeRight(rdram, ctx);
        goto after_0;
    // 0x80134A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80134A08: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A10: jal         0x80134368
    // 0x80134A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftComputerCheckSetTargetEdgeLeft(rdram, ctx);
        goto after_1;
    // 0x80134A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80134A18: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A20: jal         0x80134000
    // 0x80134A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerCheckSetTargetEdgeRight(rdram, ctx);
        goto after_2;
    // 0x80134A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80134A28: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A30: jal         0x80134368
    // 0x80134A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerCheckSetTargetEdgeLeft(rdram, ctx);
        goto after_3;
    // 0x80134A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80134A38: beql        $v0, $zero, L_80134A8C
    if (ctx->r2 == 0) {
        // 0x80134A3C: lwc1        $f0, 0x28($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80134A8C;
    }
    goto skip_0;
    // 0x80134A3C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80134A40: b           L_80134B3C
    // 0x80134A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134B3C;
    // 0x80134A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134A48:
    // 0x80134A48: jal         0x80134368
    // 0x80134A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerCheckSetTargetEdgeLeft(rdram, ctx);
        goto after_4;
    // 0x80134A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80134A50: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A58: jal         0x80134000
    // 0x80134A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftComputerCheckSetTargetEdgeRight(rdram, ctx);
        goto after_5;
    // 0x80134A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80134A60: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A68: jal         0x80134368
    // 0x80134A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerCheckSetTargetEdgeLeft(rdram, ctx);
        goto after_6;
    // 0x80134A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80134A70: bne         $v0, $zero, L_80134B38
    if (ctx->r2 != 0) {
        // 0x80134A74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134B38;
    }
    // 0x80134A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134A78: jal         0x80134000
    // 0x80134A7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftComputerCheckSetTargetEdgeRight(rdram, ctx);
        goto after_7;
    // 0x80134A7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80134A80: bnel        $v0, $zero, L_80134B3C
    if (ctx->r2 != 0) {
        // 0x80134A84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134B3C;
    }
    goto skip_1;
    // 0x80134A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80134A88: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
L_80134A8C:
    // 0x80134A8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80134A90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80134A94: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80134A98: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80134A9C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80134AA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134AA4: bc1fl       L_80134AB4
    if (!c1cs) {
        // 0x80134AA8: mtc1        $t5, $f4
        ctx->f4.u32l = ctx->r13;
            goto L_80134AB4;
    }
    goto skip_2;
    // 0x80134AA8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    skip_2:
    // 0x80134AAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80134AB0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
L_80134AB4:
    // 0x80134AB4: nop

    // 0x80134AB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134ABC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80134AC0: c.eq.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl == ctx->f8.fl;
    // 0x80134AC4: nop

    // 0x80134AC8: bc1tl       L_80134AE8
    if (c1cs) {
        // 0x80134ACC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80134AE8;
    }
    goto skip_3;
    // 0x80134ACC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_3:
    // 0x80134AD0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80134AD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134AD8: addiu       $v0, $s0, 0x1CC
    ctx->r2 = ADD32(ctx->r16, 0X1CC);
    // 0x80134ADC: b           L_80134AF0
    // 0x80134AE0: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
        goto L_80134AF0;
    // 0x80134AE0: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    // 0x80134AE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80134AE8:
    // 0x80134AE8: addiu       $v0, $s0, 0x1CC
    ctx->r2 = ADD32(ctx->r16, 0X1CC);
    // 0x80134AEC: swc1        $f18, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f18.u32l;
L_80134AF0:
    // 0x80134AF0: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80134AF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134AF8: lwc1        $f6, -0x425C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X425C);
    // 0x80134AFC: lh          $t7, 0x6C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6C);
    // 0x80134B00: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80134B04: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80134B08: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80134B0C: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134B10: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80134B14: nop

    // 0x80134B18: bc1f        L_80134B28
    if (!c1cs) {
        // 0x80134B1C: nop
    
            goto L_80134B28;
    }
    // 0x80134B1C: nop

    // 0x80134B20: b           L_80134B38
    // 0x80134B24: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
        goto L_80134B38;
    // 0x80134B24: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
L_80134B28:
    // 0x80134B28: b           L_80134B38
    // 0x80134B2C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
        goto L_80134B38;
    // 0x80134B2C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_80134B30:
    // 0x80134B30: jal         0x801346D4
    // 0x80134B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl3_801346D4(rdram, ctx);
        goto after_8;
    // 0x80134B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80134B38:
    // 0x80134B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134B3C:
    // 0x80134B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134B40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80134B44: jr          $ra
    // 0x80134B48: nop

    return;
    // 0x80134B48: nop

;}
RECOMP_FUNC void ftMainPlayHitSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E2C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2C2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E2C30: lw          $a2, 0xA10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XA10);
    // 0x800E2C34: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800E2C38: beql        $a2, $zero, L_800E2C6C
    if (ctx->r6 == 0) {
        // 0x800E2C3C: sw          $zero, 0xA10($a3)
        MEM_W(0XA10, ctx->r7) = 0;
            goto L_800E2C6C;
    }
    goto skip_0;
    // 0x800E2C3C: sw          $zero, 0xA10($a3)
    MEM_W(0XA10, ctx->r7) = 0;
    skip_0:
    // 0x800E2C40: lhu         $v0, 0x26($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X26);
    // 0x800E2C44: beql        $v0, $zero, L_800E2C6C
    if (ctx->r2 == 0) {
        // 0x800E2C48: sw          $zero, 0xA10($a3)
        MEM_W(0XA10, ctx->r7) = 0;
            goto L_800E2C6C;
    }
    goto skip_1;
    // 0x800E2C48: sw          $zero, 0xA10($a3)
    MEM_W(0XA10, ctx->r7) = 0;
    skip_1:
    // 0x800E2C4C: lhu         $t6, 0xA14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA14);
    // 0x800E2C50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E2C54: bnel        $t6, $v0, L_800E2C6C
    if (ctx->r14 != ctx->r2) {
        // 0x800E2C58: sw          $zero, 0xA10($a3)
        MEM_W(0XA10, ctx->r7) = 0;
            goto L_800E2C6C;
    }
    goto skip_2;
    // 0x800E2C58: sw          $zero, 0xA10($a3)
    MEM_W(0XA10, ctx->r7) = 0;
    skip_2:
    // 0x800E2C5C: jal         0x80026738
    // 0x800E2C60: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x800E2C60: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E2C64: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800E2C68: sw          $zero, 0xA10($a3)
    MEM_W(0XA10, ctx->r7) = 0;
L_800E2C6C:
    // 0x800E2C6C: sh          $zero, 0xA14($a3)
    MEM_H(0XA14, ctx->r7) = 0;
    // 0x800E2C70: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2C74: lw          $t4, 0x8E8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8E8);
    // 0x800E2C78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E2C7C: lw          $v0, 0x3C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X3C);
    // 0x800E2C80: lw          $a1, 0x1C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X1C);
    // 0x800E2C84: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800E2C88: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800E2C8C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800E2C90: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800E2C94: srl         $t1, $v0, 29
    ctx->r9 = S32(U32(ctx->r2) >> 29);
    // 0x800E2C98: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800E2C9C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800E2CA0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800E2CA4: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800E2CA8: jal         0x800C8654
    // 0x800E2CAC: lhu         $a0, -0x7300($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7300);
    lbCommonMakePositionFGM(rdram, ctx);
        goto after_1;
    // 0x800E2CAC: lhu         $a0, -0x7300($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X7300);
    after_1:
    // 0x800E2CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2CB8: jr          $ra
    // 0x800E2CBC: nop

    return;
    // 0x800E2CBC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136704: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80136708: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013670C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80136710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136718: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8013671C: jal         0x80009968
    // 0x80136720: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80136720: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136724: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80136728: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013672C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80136730: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80136734: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80136738: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013673C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136740: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80136744: jal         0x80009DF4
    // 0x80136748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80136748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013674C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136750: addiu       $a1, $a1, 0x6698
    ctx->r5 = ADD32(ctx->r5, 0X6698);
    // 0x80136754: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80136758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013675C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136760: jal         0x80008188
    // 0x80136764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80136764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80136768: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013676C: lw          $t7, 0x7DF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DF8);
    // 0x80136770: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80136774: addiu       $t8, $t8, -0xAD0
    ctx->r24 = ADD32(ctx->r24, -0XAD0);
    // 0x80136778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013677C: jal         0x800CCFDC
    // 0x80136780: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80136780: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80136784: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80136788: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x8013678C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80136790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136794: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80136798: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013679C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801367A0: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x801367A4: addiu       $t4, $zero, 0x56
    ctx->r12 = ADD32(0, 0X56);
    // 0x801367A8: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x801367AC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x801367B0: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x801367B4: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x801367B8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801367BC: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801367C0: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801367C4: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801367C8: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x801367CC: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x801367D0: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x801367D4: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x801367D8: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x801367DC: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x801367E0: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x801367E4: sh          $t7, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r15;
    // 0x801367E8: sh          $t8, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r24;
    // 0x801367EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801367F0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801367F4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801367F8: lw          $t9, 0x7DF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DF8);
    // 0x801367FC: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80136800: addiu       $t0, $t0, -0xBB8
    ctx->r8 = ADD32(ctx->r8, -0XBB8);
    // 0x80136804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136808: jal         0x800CCFDC
    // 0x8013680C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013680C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80136810: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80136814: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80136818: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013681C: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x80136820: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80136824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80136828: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8013682C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80136830: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80136834: addiu       $t5, $zero, 0xCA
    ctx->r13 = ADD32(0, 0XCA);
    // 0x80136838: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8013683C: addiu       $t7, $zero, 0x9D
    ctx->r15 = ADD32(0, 0X9D);
    // 0x80136840: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80136844: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80136848: sb          $t5, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r13;
    // 0x8013684C: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x80136850: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80136854: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80136858: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x8013685C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136864: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80136868: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013686C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80136870: jal         0x80009968
    // 0x80136874: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80136874: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x80136878: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013687C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80136880: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80136884: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136888: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8013688C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80136890: jal         0x80009DF4
    // 0x80136894: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80136894: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x80136898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013689C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801368A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801368A4: jal         0x80008188
    // 0x801368A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x801368A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x801368AC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801368B0: lw          $t9, 0x7DF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DF8);
    // 0x801368B4: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801368B8: addiu       $t0, $t0, 0x14D8
    ctx->r8 = ADD32(ctx->r8, 0X14D8);
    // 0x801368BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801368C0: jal         0x800CCFDC
    // 0x801368C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x801368C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_8:
    // 0x801368C8: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801368CC: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x801368D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801368D4: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x801368D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801368DC: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801368E0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801368E4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801368E8: addiu       $t5, $zero, 0xD6
    ctx->r13 = ADD32(0, 0XD6);
    // 0x801368EC: addiu       $t6, $zero, 0xDD
    ctx->r14 = ADD32(0, 0XDD);
    // 0x801368F0: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x801368F4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801368F8: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x801368FC: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80136900: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80136904: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80136908: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013690C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80136910: lw          $t8, 0x7DF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DF8);
    // 0x80136914: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80136918: addiu       $t9, $t9, 0x1378
    ctx->r25 = ADD32(ctx->r25, 0X1378);
    // 0x8013691C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136920: jal         0x800CCFDC
    // 0x80136924: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x80136924: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80136928: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x8013692C: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x80136930: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136934: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x80136938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013693C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80136940: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80136944: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80136948: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013694C: addiu       $t5, $zero, 0x56
    ctx->r13 = ADD32(0, 0X56);
    // 0x80136950: addiu       $t6, $zero, 0x92
    ctx->r14 = ADD32(0, 0X92);
    // 0x80136954: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80136958: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x8013695C: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80136960: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80136964: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80136968: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013696C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136970: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80136974: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80136978: jr          $ra
    // 0x8013697C: nop

    return;
    // 0x8013697C: nop

;}
RECOMP_FUNC void mnCharactersMakeMotionName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132FA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132FAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FB0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80132FB4: jal         0x80009968
    // 0x80132FB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132FB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132FBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FC0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132FC4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132FC8: sw          $v0, 0x66DC($at)
    MEM_W(0X66DC, ctx->r1) = ctx->r2;
    // 0x80132FCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132FD0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132FD8: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80132FDC: jal         0x80009DF4
    // 0x80132FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132FE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132FE8: jal         0x80132E20
    // 0x80132FEC: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    mnCharactersUpdateMotionName(rdram, ctx);
        goto after_2;
    // 0x80132FEC: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    after_2:
    // 0x80132FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132FF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132FF8: jr          $ra
    // 0x80132FFC: nop

    return;
    // 0x80132FFC: nop

;}
RECOMP_FUNC void ftBossOkuhikouki3ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159788: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015978C: jal         0x800D9480
    // 0x80159790: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159790: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015979C: jr          $ra
    // 0x801597A0: nop

    return;
    // 0x801597A0: nop

;}
RECOMP_FUNC void itPakkunMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D4D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D4DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8017D4E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8017D4E4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017D4E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017D4EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017D4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D4F4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017D4F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8017D4FC: addiu       $a1, $a1, -0x5650
    ctx->r5 = ADD32(ctx->r5, -0X5650);
    // 0x8017D500: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8017D504: jal         0x8016E174
    // 0x8017D508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017D508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017D50C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8017D510: beq         $v0, $zero, L_8017D574
    if (ctx->r2 == 0) {
        // 0x8017D514: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8017D574;
    }
    // 0x8017D514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8017D518: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017D51C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8017D520: addiu       $t2, $zero, 0xB4
    ctx->r10 = ADD32(0, 0XB4);
    // 0x8017D524: sw          $t8, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r24;
    // 0x8017D528: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x8017D52C: sw          $t7, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r15;
    // 0x8017D530: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8017D534: sw          $t8, 0x358($v1)
    MEM_W(0X358, ctx->r3) = ctx->r24;
    // 0x8017D538: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8017D53C: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x8017D540: sw          $t1, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r9;
    // 0x8017D544: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x8017D548: sw          $t0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r8;
    // 0x8017D54C: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x8017D550: sw          $t1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r9;
    // 0x8017D554: lbu         $t4, 0x2D3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2D3);
    // 0x8017D558: lbu         $t7, 0x158($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X158);
    // 0x8017D55C: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x8017D560: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8017D564: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8017D568: sb          $t5, 0x2D3($v1)
    MEM_B(0X2D3, ctx->r3) = ctx->r13;
    // 0x8017D56C: sb          $zero, 0x35C($v1)
    MEM_B(0X35C, ctx->r3) = 0;
    // 0x8017D570: sb          $t8, 0x158($v1)
    MEM_B(0X158, ctx->r3) = ctx->r24;
L_8017D574:
    // 0x8017D574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D57C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8017D580: jr          $ra
    // 0x8017D584: nop

    return;
    // 0x8017D584: nop

;}
RECOMP_FUNC void itSawamuraAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182958: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018295C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80182960: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80182964: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80182968: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018296C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80182970: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80182974: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80182978: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018297C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80182980: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80182984: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x80182988: lw          $s4, 0x74($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X74);
    // 0x8018298C: beq         $s0, $zero, L_80182A2C
    if (ctx->r16 == 0) {
        // 0x80182990: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80182A2C;
    }
    // 0x80182990: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80182994: lwc1        $f20, 0x58($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80182998: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x8018299C: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
L_801829A0:
    // 0x801829A0: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x801829A4: beql        $s0, $t7, L_80182A20
    if (ctx->r16 == ctx->r15) {
        // 0x801829A8: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80182A20;
    }
    goto skip_0;
    // 0x801829A8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x801829AC: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x801829B0: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x801829B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801829B8: beql        $t8, $t9, L_80182A20
    if (ctx->r24 == ctx->r25) {
        // 0x801829BC: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80182A20;
    }
    goto skip_1;
    // 0x801829BC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x801829C0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x801829C4: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    // 0x801829C8: jal         0x8001902C
    // 0x801829CC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x801829CC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x801829D0: bne         $s1, $zero, L_801829E8
    if (ctx->r17 != 0) {
        // 0x801829D4: lwc1        $f2, 0x4C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_801829E8;
    }
    // 0x801829D4: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801829D8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801829DC: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801829E0: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x801829E4: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
L_801829E8:
    // 0x801829E8: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801829EC: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801829F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801829F4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801829F8: nop

    // 0x801829FC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80182A00: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80182A04: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80182A08: nop

    // 0x80182A0C: bc1f        L_80182A1C
    if (!c1cs) {
        // 0x80182A10: nop
    
            goto L_80182A1C;
    }
    // 0x80182A10: nop

    // 0x80182A14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80182A18: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
L_80182A1C:
    // 0x80182A1C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80182A20:
    // 0x80182A20: bnel        $s0, $zero, L_801829A0
    if (ctx->r16 != 0) {
        // 0x80182A24: lw          $t7, 0x8($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X8);
            goto L_801829A0;
    }
    goto skip_2;
    // 0x80182A24: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    skip_2:
    // 0x80182A28: swc1        $f20, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f20.u32l;
L_80182A2C:
    // 0x80182A2C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80182A30: jal         0x8018285C
    // 0x80182A34: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    itSawamuraAttackSetFollowPlayerLR(rdram, ctx);
        goto after_1;
    // 0x80182A34: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_1:
    // 0x80182A38: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x80182A3C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80182A40: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80182A44: bnel        $t0, $at, L_80182A78
    if (ctx->r8 != ctx->r1) {
        // 0x80182A48: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80182A78;
    }
    goto skip_3;
    // 0x80182A48: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_3:
    // 0x80182A4C: lw          $t1, 0x2D4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X2D4);
    // 0x80182A50: addiu       $t3, $t3, 0x1F40
    ctx->r11 = ADD32(ctx->r11, 0X1F40);
    // 0x80182A54: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80182A58: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80182A5C: addiu       $t5, $t5, 0x2340
    ctx->r13 = ADD32(ctx->r13, 0X2340);
    // 0x80182A60: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80182A64: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80182A68: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80182A6C: jal         0x800269C0
    // 0x80182A70: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80182A70: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
    after_2:
    // 0x80182A74: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_80182A78:
    // 0x80182A78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80182A7C: addiu       $t6, $zero, 0x258
    ctx->r14 = ADD32(0, 0X258);
    // 0x80182A80: sh          $t6, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r14;
    // 0x80182A84: swc1        $f16, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f16.u32l;
    // 0x80182A88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80182A8C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80182A90: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80182A94: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80182A98: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80182A9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80182AA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80182AA4: jr          $ra
    // 0x80182AA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80182AA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_ovl8_8037C4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C4AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037C4B0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8037C4B4: beq         $v0, $zero, L_8037C4C4
    if (ctx->r2 == 0) {
        // 0x8037C4B8: nop
    
            goto L_8037C4C4;
    }
    // 0x8037C4B8: nop

    // 0x8037C4BC: jalr        $v0
    // 0x8037C4C0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8037C4C0: nop

    after_0:
L_8037C4C4:
    // 0x8037C4C4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037C4C8: lw          $a0, -0x5E40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E40);
    // 0x8037C4CC: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037C4D0: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037C4D4: beql        $a0, $zero, L_8037C500
    if (ctx->r4 == 0) {
        // 0x8037C4D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037C500;
    }
    goto skip_0;
    // 0x8037C4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037C4DC: lbu         $a1, -0x1030($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1030);
    // 0x8037C4E0: jal         0x80009CC8
    // 0x8037C4E4: lw          $a2, -0x102C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X102C);
    func_80009CC8(rdram, ctx);
        goto after_1;
    // 0x8037C4E4: lw          $a2, -0x102C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X102C);
    after_1:
    // 0x8037C4E8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C4EC: sw          $zero, -0x5E40($at)
    MEM_W(-0X5E40, ctx->r1) = 0;
    // 0x8037C4F0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C4F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037C4F8: sw          $t6, -0x5E48($at)
    MEM_W(-0X5E48, ctx->r1) = ctx->r14;
    // 0x8037C4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037C500:
    // 0x8037C500: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C504: sw          $zero, -0x5E44($at)
    MEM_W(-0X5E44, ctx->r1) = 0;
    // 0x8037C508: jr          $ra
    // 0x8037C50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8037C50C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcRemoveGObjFromDLLinkedList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007CF4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80007CF8: beql        $v0, $zero, L_80007D10
    if (ctx->r2 == 0) {
        // 0x80007CFC: lbu         $t8, 0xD($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0XD);
            goto L_80007D10;
    }
    goto skip_0;
    // 0x80007CFC: lbu         $t8, 0xD($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XD);
    skip_0:
    // 0x80007D00: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80007D04: b           L_80007D24
    // 0x80007D08: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
        goto L_80007D24;
    // 0x80007D08: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x80007D0C: lbu         $t8, 0xD($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XD);
L_80007D10:
    // 0x80007D10: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80007D14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007D18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80007D1C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80007D20: sw          $t7, 0x6800($at)
    MEM_W(0X6800, ctx->r1) = ctx->r15;
L_80007D24:
    // 0x80007D24: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80007D28: beql        $v0, $zero, L_80007D40
    if (ctx->r2 == 0) {
        // 0x80007D2C: lbu         $t2, 0xD($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0XD);
            goto L_80007D40;
    }
    goto skip_1;
    // 0x80007D2C: lbu         $t2, 0xD($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XD);
    skip_1:
    // 0x80007D30: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x80007D34: jr          $ra
    // 0x80007D38: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    return;
    // 0x80007D38: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x80007D3C: lbu         $t2, 0xD($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XD);
L_80007D40:
    // 0x80007D40: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x80007D44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007D48: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80007D4C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80007D50: sw          $t1, 0x6908($at)
    MEM_W(0X6908, ctx->r1) = ctx->r9;
    // 0x80007D54: jr          $ra
    // 0x80007D58: nop

    return;
    // 0x80007D58: nop

;}
RECOMP_FUNC void itKabigonJumpInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E608: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017E60C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    // 0x8017E610: jal         0x800269C0
    // 0x8017E614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017E614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017E618: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E61C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8017E620: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E624: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8017E628: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017E62C: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x8017E630: sw          $t7, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r15;
    // 0x8017E634: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017E638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E63C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E640: jr          $ra
    // 0x8017E644: nop

    return;
    // 0x8017E644: nop

;}
RECOMP_FUNC void grBonus3FinishProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B700: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8010B704: lbu         $t7, 0x4AE3($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AE3);
    // 0x8010B708: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010B70C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010B710: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8010B714: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8010B718: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010B71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B720: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8010B724: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010B728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B72C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B730: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8010B734: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x8010B738: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x8010B73C: lw          $t1, 0x14C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14C);
    // 0x8010B740: bnel        $t1, $zero, L_8010B778
    if (ctx->r9 != 0) {
        // 0x8010B744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010B778;
    }
    goto skip_0;
    // 0x8010B744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010B748: lw          $t2, 0xF4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XF4);
    // 0x8010B74C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8010B750: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x8010B754: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8010B758: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8010B75C: bnel        $t3, $at, L_8010B778
    if (ctx->r11 != ctx->r1) {
        // 0x8010B760: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010B778;
    }
    goto skip_1;
    // 0x8010B760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8010B764: jal         0x80114D58
    // 0x8010B768: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    ifCommonAnnounceCompleteInitInterface(rdram, ctx);
        goto after_0;
    // 0x8010B768: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    after_0:
    // 0x8010B76C: jal         0x80113804
    // 0x8010B770: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    ifCommonBattleEndAddSoundQueueID(rdram, ctx);
        goto after_1;
    // 0x8010B770: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_1:
    // 0x8010B774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B778:
    // 0x8010B778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B77C: jr          $ra
    // 0x8010B780: nop

    return;
    // 0x8010B780: nop

;}
RECOMP_FUNC void mnPlayersVSPuckAdjustRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801397CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801397D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801397D4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801397D8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801397DC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801397E0: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x801397E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801397E8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801397EC: lw          $t8, 0x78($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X78);
    // 0x801397F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801397F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801397F8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801397FC: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x80139800: sw          $t9, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r25;
    // 0x80139804: beq         $at, $zero, L_80139870
    if (ctx->r1 == 0) {
        // 0x80139808: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_80139870;
    }
    // 0x80139808: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8013980C: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80139810: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80139814: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80139818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013981C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80139820: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80139824: beq         $at, $zero, L_80139848
    if (ctx->r1 == 0) {
        // 0x80139828: div.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_80139848;
    }
    // 0x80139828: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8013982C: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80139830: lwc1        $f18, 0x6C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80139834: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80139838: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013983C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80139840: b           L_80139860
    // 0x80139844: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
        goto L_80139860;
    // 0x80139844: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
L_80139848:
    // 0x80139848: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8013984C: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80139850: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80139854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139858: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8013985C: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_80139860:
    // 0x80139860: swc1        $f2, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f2.u32l;
    // 0x80139864: swc1        $f0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f0.u32l;
    // 0x80139868: b           L_80139898
    // 0x8013986C: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
        goto L_80139898;
    // 0x8013986C: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
L_80139870:
    // 0x80139870: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80139874: bne         $v1, $at, L_80139898
    if (ctx->r3 != ctx->r1) {
        // 0x80139878: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80139898;
    }
    // 0x80139878: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8013987C: jal         0x8013760C
    // 0x80139880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnPlayersVSSetCursorGrab(rdram, ctx);
        goto after_0;
    // 0x80139880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80139884: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80139888: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013988C: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
    // 0x80139890: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x80139894: swc1        $f0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f0.u32l;
L_80139898:
    // 0x80139898: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8013989C: bnel        $v1, $at, L_801398AC
    if (ctx->r3 != ctx->r1) {
        // 0x801398A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801398AC;
    }
    goto skip_0;
    // 0x801398A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801398A4: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x801398A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801398AC:
    // 0x801398AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801398B0: jr          $ra
    // 0x801398B4: nop

    return;
    // 0x801398B4: nop

;}
RECOMP_FUNC void sySchedulerAddMainQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C64: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80000C68: addiu       $a1, $a1, 0x4EC8
    ctx->r5 = ADD32(ctx->r5, 0X4EC8);
    // 0x80000C6C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80000C70: beq         $v0, $zero, L_80000CA8
    if (ctx->r2 == 0) {
        // 0x80000C74: nop
    
            goto L_80000CA8;
    }
    // 0x80000C74: nop

    // 0x80000C78: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80000C7C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80000C80: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80000C84: beq         $at, $zero, L_80000CA8
    if (ctx->r1 == 0) {
        // 0x80000C88: nop
    
            goto L_80000CA8;
    }
    // 0x80000C88: nop

    // 0x80000C8C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_80000C90:
    // 0x80000C90: beq         $v0, $zero, L_80000CA8
    if (ctx->r2 == 0) {
        // 0x80000C94: nop
    
            goto L_80000CA8;
    }
    // 0x80000C94: nop

    // 0x80000C98: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80000C9C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80000CA0: bnel        $at, $zero, L_80000C90
    if (ctx->r1 != 0) {
        // 0x80000CA4: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_80000C90;
    }
    goto skip_0;
    // 0x80000CA4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
L_80000CA8:
    // 0x80000CA8: beq         $v0, $zero, L_80000CC0
    if (ctx->r2 == 0) {
        // 0x80000CAC: sw          $v0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r2;
            goto L_80000CC0;
    }
    // 0x80000CAC: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80000CB0: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80000CB4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x80000CB8: b           L_80000CD4
    // 0x80000CBC: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80000CD4;
    // 0x80000CBC: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
L_80000CC0:
    // 0x80000CC0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000CC4: addiu       $v0, $v0, 0x4EC4
    ctx->r2 = ADD32(ctx->r2, 0X4EC4);
    // 0x80000CC8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000CCC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x80000CD0: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80000CD4:
    // 0x80000CD4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000CD8: beql        $v0, $zero, L_80000CEC
    if (ctx->r2 == 0) {
        // 0x80000CDC: sw          $a0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r4;
            goto L_80000CEC;
    }
    goto skip_1;
    // 0x80000CDC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    skip_1:
    // 0x80000CE0: jr          $ra
    // 0x80000CE4: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    return;
    // 0x80000CE4: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x80000CE8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
L_80000CEC:
    // 0x80000CEC: jr          $ra
    // 0x80000CF0: nop

    return;
    // 0x80000CF0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCheckPuckInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133D44: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80133D48: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80133D4C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133D50: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80133D54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80133D58: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133D5C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133D60: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80133D64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80133D68: lw          $t7, -0x7AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AA4);
    // 0x80133D6C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80133D70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133D74: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80133D78: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x80133D7C: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80133D80: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80133D84: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80133D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133D8C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80133D90: nop

    // 0x80133D94: bc1f        L_80133DC0
    if (!c1cs) {
        // 0x80133D98: nop
    
            goto L_80133DC0;
    }
    // 0x80133D98: nop

    // 0x80133D9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133DA0: nop

    // 0x80133DA4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80133DA8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80133DAC: nop

    // 0x80133DB0: bc1f        L_80133DC0
    if (!c1cs) {
        // 0x80133DB4: nop
    
            goto L_80133DC0;
    }
    // 0x80133DB4: nop

    // 0x80133DB8: b           L_80133DC0
    // 0x80133DBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80133DC0;
    // 0x80133DBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80133DC0:
    // 0x80133DC0: beq         $a0, $zero, L_80133E24
    if (ctx->r4 == 0) {
        // 0x80133DC4: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80133E24;
    }
    // 0x80133DC4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80133DC8: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80133DCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133DD0: lwc1        $f2, 0x5C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80133DD4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80133DD8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80133DDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133DE0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80133DE4: nop

    // 0x80133DE8: bc1f        L_80133E14
    if (!c1cs) {
        // 0x80133DEC: nop
    
            goto L_80133E14;
    }
    // 0x80133DEC: nop

    // 0x80133DF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133DF4: nop

    // 0x80133DF8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80133DFC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80133E00: nop

    // 0x80133E04: bc1f        L_80133E14
    if (!c1cs) {
        // 0x80133E08: nop
    
            goto L_80133E14;
    }
    // 0x80133E08: nop

    // 0x80133E0C: b           L_80133E14
    // 0x80133E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80133E14;
    // 0x80133E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80133E14:
    // 0x80133E14: beql        $a0, $zero, L_80133E28
    if (ctx->r4 == 0) {
        // 0x80133E18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133E28;
    }
    goto skip_0;
    // 0x80133E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80133E1C: jr          $ra
    // 0x80133E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80133E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133E24:
    // 0x80133E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133E28:
    // 0x80133E28: jr          $ra
    // 0x80133E2C: nop

    return;
    // 0x80133E2C: nop

;}
RECOMP_FUNC void mnOptionMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132CC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132CC4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132CC8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132CCC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132CD0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80132CD4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132CD8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132CDC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132CE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132CE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132CE8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132CEC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132CF0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132CF4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132CF8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132CFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132D00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D04: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132D08: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132D0C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132D10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132D1C: jal         0x8000B93C
    // 0x80132D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D24: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132D28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132D2C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132D30: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132D3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132D40: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132D44: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132D48: jal         0x80007080
    // 0x80132D4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132D4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132D50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132D54: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132D58: jr          $ra
    // 0x80132D5C: nop

    return;
    // 0x80132D5C: nop

;}
RECOMP_FUNC void scVSBattleSetScoreCheckSuddenDeath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5E0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018D5E4: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8018D5E8: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8018D5EC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8018D5F0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8018D5F4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8018D5F8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8018D5FC: lbu         $t6, 0x3($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3);
    // 0x8018D600: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018D604: addiu       $a0, $a0, 0x4EF8
    ctx->r4 = ADD32(ctx->r4, 0X4EF8);
    // 0x8018D608: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8018D60C: bne         $t7, $zero, L_8018D61C
    if (ctx->r15 != 0) {
        // 0x8018D610: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_8018D61C;
    }
    // 0x8018D610: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8018D614: b           L_8018DE08
    // 0x8018D618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018DE08;
    // 0x8018D618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018D61C:
    // 0x8018D61C: addiu       $t8, $t8, 0x4D08
    ctx->r24 = ADD32(ctx->r24, 0X4D08);
    // 0x8018D620: addiu       $at, $t8, 0x1EC
    ctx->r1 = ADD32(ctx->r24, 0X1EC);
    // 0x8018D624: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
L_8018D628:
    // 0x8018D628: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8018D62C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018D630: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018D634: sw          $t6, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r14;
    // 0x8018D638: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8018D63C: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x8018D640: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x8018D644: bne         $t8, $at, L_8018D628
    if (ctx->r24 != ctx->r1) {
        // 0x8018D648: sw          $t6, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r14;
            goto L_8018D628;
    }
    // 0x8018D648: sw          $t6, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r14;
    // 0x8018D64C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8018D650: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D654: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018D658: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8018D65C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8018D660: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x8018D664: addiu       $a1, $a1, 0x50C8
    ctx->r5 = ADD32(ctx->r5, 0X50C8);
    // 0x8018D668: addiu       $v0, $v0, 0x4EF8
    ctx->r2 = ADD32(ctx->r2, 0X4EF8);
    // 0x8018D66C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018D670:
    // 0x8018D670: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
    // 0x8018D674: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8018D678: bne         $at, $zero, L_8018D670
    if (ctx->r1 != 0) {
        // 0x8018D67C: sb          $v1, -0x52($v0)
        MEM_B(-0X52, ctx->r2) = ctx->r3;
            goto L_8018D670;
    }
    // 0x8018D67C: sb          $v1, -0x52($v0)
    MEM_B(-0X52, ctx->r2) = ctx->r3;
    // 0x8018D680: lbu         $v0, 0x2($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X2);
    // 0x8018D684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D68C: beq         $v0, $zero, L_8018D6A8
    if (ctx->r2 == 0) {
        // 0x8018D690: or          $s0, $t5, $zero
        ctx->r16 = ctx->r13 | 0;
            goto L_8018D6A8;
    }
    // 0x8018D690: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8018D694: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D698: beq         $v0, $t3, L_8018DA34
    if (ctx->r2 == ctx->r11) {
        // 0x8018D69C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8018DA34;
    }
    // 0x8018D69C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D6A0: b           L_8018DDEC
    // 0x8018D6A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8018DDEC;
    // 0x8018D6A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8018D6A8:
    // 0x8018D6A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018D6AC: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8018D6B0: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x8018D6B4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8018D6B8:
    // 0x8018D6B8: lbu         $t7, 0x22($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D6BC: beql        $a3, $t7, L_8018D710
    if (ctx->r7 == ctx->r15) {
        // 0x8018D6C0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8018D710;
    }
    goto skip_0;
    // 0x8018D6C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x8018D6C4: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D6C8: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x8018D6CC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x8018D6D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018D6D4: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x8018D6D8: mflo        $t9
    ctx->r25 = lo;
    // 0x8018D6DC: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8018D6E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D6E4: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x8018D6E8: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8018D6EC: sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // 0x8018D6F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018D6F4: lbu         $t6, 0x22($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D6F8: bnel        $t6, $zero, L_8018D70C
    if (ctx->r14 != 0) {
        // 0x8018D6FC: sb          $zero, 0xA($v0)
        MEM_B(0XA, ctx->r2) = 0;
            goto L_8018D70C;
    }
    goto skip_1;
    // 0x8018D6FC: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    skip_1:
    // 0x8018D700: b           L_8018D70C
    // 0x8018D704: sb          $t4, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r12;
        goto L_8018D70C;
    // 0x8018D704: sb          $t4, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r12;
    // 0x8018D708: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
L_8018D70C:
    // 0x8018D70C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8018D710:
    // 0x8018D710: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8018D714: bne         $at, $zero, L_8018D6B8
    if (ctx->r1 != 0) {
        // 0x8018D718: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_8018D6B8;
    }
    // 0x8018D718: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x8018D71C: blez        $a2, L_8018D7D8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8018D720: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8018D7D8;
    }
    // 0x8018D720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D724: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_8018D728:
    // 0x8018D728: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x8018D72C: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8018D730: beq         $at, $zero, L_8018D7CC
    if (ctx->r1 == 0) {
        // 0x8018D734: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8018D7CC;
    }
    // 0x8018D734: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8018D738: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018D73C: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x8018D740: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8018D744: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8018D748: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8018D74C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8018D750: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8018D754: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D758: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D75C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018D760: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D764: addu        $s1, $t9, $t7
    ctx->r17 = ADD32(ctx->r25, ctx->r15);
    // 0x8018D768: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D76C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8018D770:
    // 0x8018D770: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8018D774: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8018D778: beql        $at, $zero, L_8018D7C4
    if (ctx->r1 == 0) {
        // 0x8018D77C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8018D7C4;
    }
    goto skip_2;
    // 0x8018D77C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x8018D780: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8018D784: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8018D788: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8018D78C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D790: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8018D794: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8018D798: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x8018D79C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D7A0: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8018D7A4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8018D7A8: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8018D7AC: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8018D7B0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8018D7B4: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8018D7B8: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8018D7BC: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x8018D7C0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8018D7C4:
    // 0x8018D7C4: bnel        $s1, $a3, L_8018D770
    if (ctx->r17 != ctx->r7) {
        // 0x8018D7C8: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8018D770;
    }
    goto skip_3;
    // 0x8018D7C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_3:
L_8018D7CC:
    // 0x8018D7CC: bne         $t2, $a2, L_8018D728
    if (ctx->r10 != ctx->r6) {
        // 0x8018D7D0: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_8018D728;
    }
    // 0x8018D7D0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8018D7D4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018D7D8:
    // 0x8018D7D8: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8018D7DC: sb          $t4, 0x4D($sp)
    MEM_B(0X4D, ctx->r29) = ctx->r12;
    // 0x8018D7E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D7E4: bne         $at, $zero, L_8018D8CC
    if (ctx->r1 != 0) {
        // 0x8018D7E8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8018D8CC;
    }
    // 0x8018D7E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8018D7EC: addiu       $s0, $a2, -0x1
    ctx->r16 = ADD32(ctx->r6, -0X1);
    // 0x8018D7F0: andi        $s0, $s0, 0x3
    ctx->r16 = ctx->r16 & 0X3;
    // 0x8018D7F4: beq         $s0, $zero, L_8018D838
    if (ctx->r16 == 0) {
        // 0x8018D7F8: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_8018D838;
    }
    // 0x8018D7F8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8018D7FC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018D800: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8018D804: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D808: addiu       $t9, $sp, 0x44
    ctx->r25 = ADD32(ctx->r29, 0X44);
    // 0x8018D80C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
L_8018D810:
    // 0x8018D810: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8018D814: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018D818: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018D81C: bne         $t6, $t7, L_8018D82C
    if (ctx->r14 != ctx->r15) {
        // 0x8018D820: nop
    
            goto L_8018D82C;
    }
    // 0x8018D820: nop

    // 0x8018D824: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x8018D828: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8018D82C:
    // 0x8018D82C: bne         $v0, $a1, L_8018D810
    if (ctx->r2 != ctx->r5) {
        // 0x8018D830: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_8018D810;
    }
    // 0x8018D830: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018D834: beq         $a1, $a2, L_8018D8C8
    if (ctx->r5 == ctx->r6) {
        // 0x8018D838: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8018D8C8;
    }
L_8018D838:
    // 0x8018D838: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018D83C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8018D840: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8018D844: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8018D848: addiu       $t9, $sp, 0x44
    ctx->r25 = ADD32(ctx->r29, 0X44);
    // 0x8018D84C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D850: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018D854: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x8018D858: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8018D85C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8018D860:
    // 0x8018D860: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018D864: bnel        $t7, $t8, L_8018D878
    if (ctx->r15 != ctx->r24) {
        // 0x8018D868: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8018D878;
    }
    goto skip_4;
    // 0x8018D868: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x8018D86C: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x8018D870: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018D874: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8018D878:
    // 0x8018D878: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8018D87C: bnel        $t6, $t9, L_8018D890
    if (ctx->r14 != ctx->r25) {
        // 0x8018D880: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_8018D890;
    }
    goto skip_5;
    // 0x8018D880: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x8018D884: sb          $t4, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r12;
    // 0x8018D888: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018D88C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8018D890:
    // 0x8018D890: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8018D894: bnel        $t7, $t8, L_8018D8A8
    if (ctx->r15 != ctx->r24) {
        // 0x8018D898: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8018D8A8;
    }
    goto skip_6;
    // 0x8018D898: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x8018D89C: sb          $t4, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r12;
    // 0x8018D8A0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018D8A4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8018D8A8:
    // 0x8018D8A8: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x8018D8AC: bnel        $t6, $t9, L_8018D8C0
    if (ctx->r14 != ctx->r25) {
        // 0x8018D8B0: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8018D8C0;
    }
    goto skip_7;
    // 0x8018D8B0: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_7:
    // 0x8018D8B4: sb          $t4, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r12;
    // 0x8018D8B8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018D8BC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_8018D8C0:
    // 0x8018D8C0: bnel        $v1, $v0, L_8018D860
    if (ctx->r3 != ctx->r2) {
        // 0x8018D8C4: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_8018D860;
    }
    goto skip_8;
    // 0x8018D8C4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_8:
L_8018D8C8:
    // 0x8018D8C8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018D8CC:
    // 0x8018D8CC: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8018D8D0: beq         $at, $zero, L_8018D8E0
    if (ctx->r1 == 0) {
        // 0x8018D8D4: nop
    
            goto L_8018D8E0;
    }
    // 0x8018D8D4: nop

    // 0x8018D8D8: b           L_8018DE08
    // 0x8018D8DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018DE08;
    // 0x8018D8DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018D8E0:
    // 0x8018D8E0: blez        $t2, L_8018DDEC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018D8E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8018DDEC;
    }
    // 0x8018D8E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D8E8: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x8018D8EC: beq         $v0, $zero, L_8018D954
    if (ctx->r2 == 0) {
        // 0x8018D8F0: lbu         $t7, 0x4C($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X4C);
            goto L_8018D954;
    }
    // 0x8018D8F0: lbu         $t7, 0x4C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4C);
    // 0x8018D8F4: addiu       $t1, $zero, 0x74
    ctx->r9 = ADD32(0, 0X74);
    // 0x8018D8F8: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D8FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D900: mflo        $v1
    ctx->r3 = lo;
    // 0x8018D904: addu        $t8, $t5, $v1
    ctx->r24 = ADD32(ctx->r13, ctx->r3);
    // 0x8018D908: lbu         $t6, 0x22($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X22);
    // 0x8018D90C: addu        $a1, $a0, $v1
    ctx->r5 = ADD32(ctx->r4, ctx->r3);
    // 0x8018D910: andi        $a2, $t6, 0xFF
    ctx->r6 = ctx->r14 & 0XFF;
    // 0x8018D914: beq         $a2, $zero, L_8018D92C
    if (ctx->r6 == 0) {
        // 0x8018D918: sb          $t6, 0x22($a1)
        MEM_B(0X22, ctx->r5) = ctx->r14;
            goto L_8018D92C;
    }
    // 0x8018D918: sb          $t6, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r14;
    // 0x8018D91C: beql        $a2, $t3, L_8018D944
    if (ctx->r6 == ctx->r11) {
        // 0x8018D920: lbu         $t8, 0x5($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X5);
            goto L_8018D944;
    }
    goto skip_9;
    // 0x8018D920: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
    skip_9:
    // 0x8018D924: b           L_8018D94C
    // 0x8018D928: nop

        goto L_8018D94C;
    // 0x8018D928: nop

L_8018D92C:
    // 0x8018D92C: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x8018D930: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D934: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8018D938: b           L_8018D94C
    // 0x8018D93C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
        goto L_8018D94C;
    // 0x8018D93C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x8018D940: lbu         $t8, 0x5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5);
L_8018D944:
    // 0x8018D944: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8018D948: sb          $t6, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r14;
L_8018D94C:
    // 0x8018D94C: beq         $t3, $t2, L_8018DA2C
    if (ctx->r11 == ctx->r10) {
        // 0x8018D950: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_8018DA2C;
    }
    // 0x8018D950: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_8018D954:
    // 0x8018D954: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8018D958: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8018D95C: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8018D960: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8018D964: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x8018D968: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D96C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D970: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D974: addu        $v1, $t9, $t7
    ctx->r3 = ADD32(ctx->r25, ctx->r15);
    // 0x8018D978: addiu       $t1, $zero, 0x74
    ctx->r9 = ADD32(0, 0X74);
    // 0x8018D97C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D980: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
L_8018D984:
    // 0x8018D984: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D988: mflo        $a1
    ctx->r5 = lo;
    // 0x8018D98C: addu        $t9, $t5, $a1
    ctx->r25 = ADD32(ctx->r13, ctx->r5);
    // 0x8018D990: lbu         $t8, 0x22($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X22);
    // 0x8018D994: addu        $a2, $a0, $a1
    ctx->r6 = ADD32(ctx->r4, ctx->r5);
    // 0x8018D998: andi        $a3, $t8, 0xFF
    ctx->r7 = ctx->r24 & 0XFF;
    // 0x8018D99C: beq         $a3, $zero, L_8018D9B4
    if (ctx->r7 == 0) {
        // 0x8018D9A0: sb          $t8, 0x22($a2)
        MEM_B(0X22, ctx->r6) = ctx->r24;
            goto L_8018D9B4;
    }
    // 0x8018D9A0: sb          $t8, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r24;
    // 0x8018D9A4: beql        $a3, $t3, L_8018D9C8
    if (ctx->r7 == ctx->r11) {
        // 0x8018D9A8: lbu         $t9, 0x5($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X5);
            goto L_8018D9C8;
    }
    goto skip_10;
    // 0x8018D9A8: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    skip_10:
    // 0x8018D9AC: b           L_8018D9D4
    // 0x8018D9B0: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
        goto L_8018D9D4;
    // 0x8018D9B0: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
L_8018D9B4:
    // 0x8018D9B4: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x8018D9B8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8018D9BC: b           L_8018D9D0
    // 0x8018D9C0: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
        goto L_8018D9D0;
    // 0x8018D9C0: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    // 0x8018D9C4: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
L_8018D9C8:
    // 0x8018D9C8: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8018D9CC: sb          $t8, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r24;
L_8018D9D0:
    // 0x8018D9D0: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
L_8018D9D4:
    // 0x8018D9D4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8018D9D8: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D9DC: mflo        $a1
    ctx->r5 = lo;
    // 0x8018D9E0: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8018D9E4: lbu         $t9, 0x22($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X22);
    // 0x8018D9E8: addu        $a2, $a0, $a1
    ctx->r6 = ADD32(ctx->r4, ctx->r5);
    // 0x8018D9EC: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8018D9F0: beq         $v0, $zero, L_8018DA08
    if (ctx->r2 == 0) {
        // 0x8018D9F4: sb          $t9, 0x22($a2)
        MEM_B(0X22, ctx->r6) = ctx->r25;
            goto L_8018DA08;
    }
    // 0x8018D9F4: sb          $t9, 0x22($a2)
    MEM_B(0X22, ctx->r6) = ctx->r25;
    // 0x8018D9F8: beql        $v0, $t3, L_8018DA1C
    if (ctx->r2 == ctx->r11) {
        // 0x8018D9FC: lbu         $t6, 0x5($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X5);
            goto L_8018DA1C;
    }
    goto skip_11;
    // 0x8018D9FC: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    skip_11:
    // 0x8018DA00: b           L_8018DA24
    // 0x8018DA04: nop

        goto L_8018DA24;
    // 0x8018DA04: nop

L_8018DA08:
    // 0x8018DA08: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x8018DA0C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8018DA10: b           L_8018DA24
    // 0x8018DA14: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
        goto L_8018DA24;
    // 0x8018DA14: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x8018DA18: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
L_8018DA1C:
    // 0x8018DA1C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8018DA20: sb          $t9, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r25;
L_8018DA24:
    // 0x8018DA24: bnel        $v1, $t0, L_8018D984
    if (ctx->r3 != ctx->r8) {
        // 0x8018DA28: lbu         $t6, 0x8($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X8);
            goto L_8018D984;
    }
    goto skip_12;
    // 0x8018DA28: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
    skip_12:
L_8018DA2C:
    // 0x8018DA2C: b           L_8018DDEC
    // 0x8018DA30: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8018DDEC;
    // 0x8018DA30: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018DA34:
    // 0x8018DA34: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8018DA38: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8018DA3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018DA40: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8018DA44: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x8018DA48: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8018DA4C:
    // 0x8018DA4C: lbu         $t8, 0x22($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X22);
    // 0x8018DA50: addiu       $t2, $t2, 0x74
    ctx->r10 = ADD32(ctx->r10, 0X74);
    // 0x8018DA54: slti        $at, $t2, 0x1D0
    ctx->r1 = SIGNED(ctx->r10) < 0X1D0 ? 1 : 0;
    // 0x8018DA58: beq         $a3, $t8, L_8018DB28
    if (ctx->r7 == ctx->r24) {
        // 0x8018DA5C: nop
    
            goto L_8018DB28;
    }
    // 0x8018DA5C: nop

    // 0x8018DA60: blez        $a2, L_8018DAD4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8018DA64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018DAD4;
    }
    // 0x8018DA64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018DA68: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x8018DA6C: lbu         $a1, 0x24($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X24);
L_8018DA70:
    // 0x8018DA70: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8018DA74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018DA78: bne         $a1, $t7, L_8018DACC
    if (ctx->r5 != ctx->r15) {
        // 0x8018DA7C: nop
    
            goto L_8018DACC;
    }
    // 0x8018DA7C: nop

    // 0x8018DA80: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8018DA84: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x8018DA88: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8018DA8C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018DA90: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x8018DA94: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018DA98: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x8018DA9C: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8018DAA0: lbu         $t6, 0xA($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XA);
    // 0x8018DAA4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8018DAA8: bne         $t6, $zero, L_8018DABC
    if (ctx->r14 != 0) {
        // 0x8018DAAC: sw          $t7, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r15;
            goto L_8018DABC;
    }
    // 0x8018DAAC: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x8018DAB0: lbu         $t9, 0x22($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X22);
    // 0x8018DAB4: bne         $t9, $zero, L_8018DAC4
    if (ctx->r25 != 0) {
        // 0x8018DAB8: nop
    
            goto L_8018DAC4;
    }
    // 0x8018DAB8: nop

L_8018DABC:
    // 0x8018DABC: b           L_8018DB28
    // 0x8018DAC0: sb          $t4, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r12;
        goto L_8018DB28;
    // 0x8018DAC0: sb          $t4, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r12;
L_8018DAC4:
    // 0x8018DAC4: b           L_8018DB28
    // 0x8018DAC8: sb          $zero, 0xA($s1)
    MEM_B(0XA, ctx->r17) = 0;
        goto L_8018DB28;
    // 0x8018DAC8: sb          $zero, 0xA($s1)
    MEM_B(0XA, ctx->r17) = 0;
L_8018DACC:
    // 0x8018DACC: bne         $v0, $a2, L_8018DA70
    if (ctx->r2 != ctx->r6) {
        // 0x8018DAD0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8018DA70;
    }
    // 0x8018DAD0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8018DAD4:
    // 0x8018DAD4: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018DAD8: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x8018DADC: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x8018DAE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018DAE4: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x8018DAE8: mflo        $t8
    ctx->r24 = lo;
    // 0x8018DAEC: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x8018DAF0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018DAF4: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x8018DAF8: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x8018DAFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018DB00: lbu         $t7, 0x24($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X24);
    // 0x8018DB04: sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // 0x8018DB08: bne         $t6, $zero, L_8018DB1C
    if (ctx->r14 != 0) {
        // 0x8018DB0C: sb          $t7, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r15;
            goto L_8018DB1C;
    }
    // 0x8018DB0C: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    // 0x8018DB10: lbu         $t9, 0x22($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X22);
    // 0x8018DB14: bnel        $t9, $zero, L_8018DB28
    if (ctx->r25 != 0) {
        // 0x8018DB18: sb          $zero, 0xA($v0)
        MEM_B(0XA, ctx->r2) = 0;
            goto L_8018DB28;
    }
    goto skip_13;
    // 0x8018DB18: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    skip_13:
L_8018DB1C:
    // 0x8018DB1C: b           L_8018DB28
    // 0x8018DB20: sb          $t4, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r12;
        goto L_8018DB28;
    // 0x8018DB20: sb          $t4, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r12;
    // 0x8018DB24: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
L_8018DB28:
    // 0x8018DB28: bne         $at, $zero, L_8018DA4C
    if (ctx->r1 != 0) {
        // 0x8018DB2C: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_8018DA4C;
    }
    // 0x8018DB2C: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x8018DB30: blez        $a2, L_8018DBF0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8018DB34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8018DBF0;
    }
    // 0x8018DB34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DB38: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_8018DB3C:
    // 0x8018DB3C: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x8018DB40: slt         $at, $t2, $a2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8018DB44: beq         $at, $zero, L_8018DBE4
    if (ctx->r1 == 0) {
        // 0x8018DB48: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8018DBE4;
    }
    // 0x8018DB48: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8018DB4C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018DB50: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8018DB54: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8018DB58: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8018DB5C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8018DB60: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8018DB64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DB68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DB6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DB70: addiu       $t9, $sp, 0x44
    ctx->r25 = ADD32(ctx->r29, 0X44);
    // 0x8018DB74: addu        $s0, $t6, $t9
    ctx->r16 = ADD32(ctx->r14, ctx->r25);
    // 0x8018DB78: addu        $s1, $t0, $t7
    ctx->r17 = ADD32(ctx->r8, ctx->r15);
    // 0x8018DB7C: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x8018DB80: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8018DB84:
    // 0x8018DB84: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8018DB88: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8018DB8C: beql        $at, $zero, L_8018DBDC
    if (ctx->r1 == 0) {
        // 0x8018DB90: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8018DBDC;
    }
    goto skip_14;
    // 0x8018DB90: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_14:
    // 0x8018DB94: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8018DB98: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018DB9C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8018DBA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018DBA4: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x8018DBA8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8018DBAC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8018DBB0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018DBB4: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8018DBB8: sw          $t9, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r25;
    // 0x8018DBBC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018DBC0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8018DBC4: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8018DBC8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018DBCC: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x8018DBD0: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8018DBD4: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8018DBD8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8018DBDC:
    // 0x8018DBDC: bnel        $s1, $s0, L_8018DB84
    if (ctx->r17 != ctx->r16) {
        // 0x8018DBE0: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8018DB84;
    }
    goto skip_15;
    // 0x8018DBE0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_15:
L_8018DBE4:
    // 0x8018DBE4: bne         $t2, $a2, L_8018DB3C
    if (ctx->r10 != ctx->r6) {
        // 0x8018DBE8: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_8018DB3C;
    }
    // 0x8018DBE8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8018DBEC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018DBF0:
    // 0x8018DBF0: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8018DBF4: sb          $t4, 0x4D($sp)
    MEM_B(0X4D, ctx->r29) = ctx->r12;
    // 0x8018DBF8: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8018DBFC: bne         $at, $zero, L_8018DCE0
    if (ctx->r1 != 0) {
        // 0x8018DC00: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_8018DCE0;
    }
    // 0x8018DC00: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8018DC04: addiu       $s0, $a2, -0x1
    ctx->r16 = ADD32(ctx->r6, -0X1);
    // 0x8018DC08: andi        $s0, $s0, 0x3
    ctx->r16 = ctx->r16 & 0X3;
    // 0x8018DC0C: beq         $s0, $zero, L_8018DC4C
    if (ctx->r16 == 0) {
        // 0x8018DC10: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_8018DC4C;
    }
    // 0x8018DC10: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8018DC14: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8018DC18: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8018DC1C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DC20: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
L_8018DC24:
    // 0x8018DC24: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8018DC28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018DC2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018DC30: bne         $t7, $t6, L_8018DC40
    if (ctx->r15 != ctx->r14) {
        // 0x8018DC34: nop
    
            goto L_8018DC40;
    }
    // 0x8018DC34: nop

    // 0x8018DC38: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x8018DC3C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8018DC40:
    // 0x8018DC40: bne         $v0, $a1, L_8018DC24
    if (ctx->r2 != ctx->r5) {
        // 0x8018DC44: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_8018DC24;
    }
    // 0x8018DC44: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018DC48: beq         $a1, $a2, L_8018DCDC
    if (ctx->r5 == ctx->r6) {
        // 0x8018DC4C: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_8018DCDC;
    }
L_8018DC4C:
    // 0x8018DC4C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8018DC50: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8018DC54: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8018DC58: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8018DC5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018DC60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DC64: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x8018DC68: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DC6C: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8018DC70: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8018DC74:
    // 0x8018DC74: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018DC78: bnel        $t6, $t9, L_8018DC8C
    if (ctx->r14 != ctx->r25) {
        // 0x8018DC7C: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8018DC8C;
    }
    goto skip_16;
    // 0x8018DC7C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_16:
    // 0x8018DC80: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x8018DC84: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018DC88: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8018DC8C:
    // 0x8018DC8C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8018DC90: bnel        $t8, $t7, L_8018DCA4
    if (ctx->r24 != ctx->r15) {
        // 0x8018DC94: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8018DCA4;
    }
    goto skip_17;
    // 0x8018DC94: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    skip_17:
    // 0x8018DC98: sb          $t4, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r12;
    // 0x8018DC9C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018DCA0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8018DCA4:
    // 0x8018DCA4: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x8018DCA8: bnel        $t6, $t9, L_8018DCBC
    if (ctx->r14 != ctx->r25) {
        // 0x8018DCAC: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_8018DCBC;
    }
    goto skip_18;
    // 0x8018DCAC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    skip_18:
    // 0x8018DCB0: sb          $t4, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r12;
    // 0x8018DCB4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018DCB8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_8018DCBC:
    // 0x8018DCBC: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8018DCC0: bnel        $t8, $t7, L_8018DCD4
    if (ctx->r24 != ctx->r15) {
        // 0x8018DCC4: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_8018DCD4;
    }
    goto skip_19;
    // 0x8018DCC4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_19:
    // 0x8018DCC8: sb          $t4, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r12;
    // 0x8018DCCC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8018DCD0: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_8018DCD4:
    // 0x8018DCD4: bnel        $v1, $v0, L_8018DC74
    if (ctx->r3 != ctx->r2) {
        // 0x8018DCD8: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8018DC74;
    }
    goto skip_20;
    // 0x8018DCD8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    skip_20:
L_8018DCDC:
    // 0x8018DCDC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018DCE0:
    // 0x8018DCE0: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8018DCE4: beq         $at, $zero, L_8018DCF4
    if (ctx->r1 == 0) {
        // 0x8018DCE8: nop
    
            goto L_8018DCF4;
    }
    // 0x8018DCE8: nop

    // 0x8018DCEC: b           L_8018DE08
    // 0x8018DCF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018DE08;
    // 0x8018DCF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018DCF4:
    // 0x8018DCF4: blez        $t2, L_8018DDEC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018DCF8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8018DDEC;
    }
    // 0x8018DCF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DCFC: addiu       $s3, $zero, 0x1D0
    ctx->r19 = ADD32(0, 0X1D0);
    // 0x8018DD00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018DD04:
    // 0x8018DD04: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8018DD08:
    // 0x8018DD08: lbu         $s0, 0x22($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X22);
    // 0x8018DD0C: beql        $a3, $s0, L_8018DD70
    if (ctx->r7 == ctx->r16) {
        // 0x8018DD10: lbu         $s0, 0x96($a2)
        ctx->r16 = MEM_BU(ctx->r6, 0X96);
            goto L_8018DD70;
    }
    goto skip_21;
    // 0x8018DD10: lbu         $s0, 0x96($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X96);
    skip_21:
    // 0x8018DD14: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018DD18: lbu         $t6, 0x24($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X24);
    // 0x8018DD1C: addu        $s1, $a0, $v1
    ctx->r17 = ADD32(ctx->r4, ctx->r3);
    // 0x8018DD20: andi        $s2, $s0, 0xFF
    ctx->r18 = ctx->r16 & 0XFF;
    // 0x8018DD24: mflo        $t9
    ctx->r25 = lo;
    // 0x8018DD28: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x8018DD2C: lbu         $t7, 0x8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X8);
    // 0x8018DD30: bnel        $t6, $t7, L_8018DD70
    if (ctx->r14 != ctx->r15) {
        // 0x8018DD34: lbu         $s0, 0x96($a2)
        ctx->r16 = MEM_BU(ctx->r6, 0X96);
            goto L_8018DD70;
    }
    goto skip_22;
    // 0x8018DD34: lbu         $s0, 0x96($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X96);
    skip_22:
    // 0x8018DD38: beq         $s2, $zero, L_8018DD50
    if (ctx->r18 == 0) {
        // 0x8018DD3C: sb          $s0, 0x22($s1)
        MEM_B(0X22, ctx->r17) = ctx->r16;
            goto L_8018DD50;
    }
    // 0x8018DD3C: sb          $s0, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r16;
    // 0x8018DD40: beql        $s2, $t3, L_8018DD64
    if (ctx->r18 == ctx->r11) {
        // 0x8018DD44: lbu         $t6, 0x5($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X5);
            goto L_8018DD64;
    }
    goto skip_23;
    // 0x8018DD44: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    skip_23:
    // 0x8018DD48: b           L_8018DD70
    // 0x8018DD4C: lbu         $s0, 0x96($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X96);
        goto L_8018DD70;
    // 0x8018DD4C: lbu         $s0, 0x96($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X96);
L_8018DD50:
    // 0x8018DD50: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x8018DD54: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8018DD58: b           L_8018DD6C
    // 0x8018DD5C: sb          $t8, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r24;
        goto L_8018DD6C;
    // 0x8018DD5C: sb          $t8, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r24;
    // 0x8018DD60: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
L_8018DD64:
    // 0x8018DD64: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DD68: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
L_8018DD6C:
    // 0x8018DD6C: lbu         $s0, 0x96($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X96);
L_8018DD70:
    // 0x8018DD70: beql        $a3, $s0, L_8018DDD4
    if (ctx->r7 == ctx->r16) {
        // 0x8018DD74: addiu       $v1, $v1, 0xE8
        ctx->r3 = ADD32(ctx->r3, 0XE8);
            goto L_8018DDD4;
    }
    goto skip_24;
    // 0x8018DD74: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
    skip_24:
    // 0x8018DD78: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018DD7C: lbu         $t9, 0x98($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X98);
    // 0x8018DD80: addu        $s1, $a0, $v1
    ctx->r17 = ADD32(ctx->r4, ctx->r3);
    // 0x8018DD84: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8018DD88: mflo        $t8
    ctx->r24 = lo;
    // 0x8018DD8C: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x8018DD90: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x8018DD94: bnel        $t9, $t7, L_8018DDD4
    if (ctx->r25 != ctx->r15) {
        // 0x8018DD98: addiu       $v1, $v1, 0xE8
        ctx->r3 = ADD32(ctx->r3, 0XE8);
            goto L_8018DDD4;
    }
    goto skip_25;
    // 0x8018DD98: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
    skip_25:
    // 0x8018DD9C: beq         $v0, $zero, L_8018DDB4
    if (ctx->r2 == 0) {
        // 0x8018DDA0: sb          $s0, 0x96($s1)
        MEM_B(0X96, ctx->r17) = ctx->r16;
            goto L_8018DDB4;
    }
    // 0x8018DDA0: sb          $s0, 0x96($s1)
    MEM_B(0X96, ctx->r17) = ctx->r16;
    // 0x8018DDA4: beql        $v0, $t3, L_8018DDC8
    if (ctx->r2 == ctx->r11) {
        // 0x8018DDA8: lbu         $t9, 0x5($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X5);
            goto L_8018DDC8;
    }
    goto skip_26;
    // 0x8018DDA8: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    skip_26:
    // 0x8018DDAC: b           L_8018DDD4
    // 0x8018DDB0: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
        goto L_8018DDD4;
    // 0x8018DDB0: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
L_8018DDB4:
    // 0x8018DDB4: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x8018DDB8: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8018DDBC: b           L_8018DDD0
    // 0x8018DDC0: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
        goto L_8018DDD0;
    // 0x8018DDC0: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    // 0x8018DDC4: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
L_8018DDC8:
    // 0x8018DDC8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8018DDCC: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
L_8018DDD0:
    // 0x8018DDD0: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
L_8018DDD4:
    // 0x8018DDD4: bne         $v1, $s3, L_8018DD08
    if (ctx->r3 != ctx->r19) {
        // 0x8018DDD8: addiu       $a2, $a2, 0xE8
        ctx->r6 = ADD32(ctx->r6, 0XE8);
            goto L_8018DD08;
    }
    // 0x8018DDD8: addiu       $a2, $a2, 0xE8
    ctx->r6 = ADD32(ctx->r6, 0XE8);
    // 0x8018DDDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018DDE0: bnel        $a1, $t2, L_8018DD04
    if (ctx->r5 != ctx->r10) {
        // 0x8018DDE4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8018DD04;
    }
    goto skip_27;
    // 0x8018DDE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_27:
    // 0x8018DDE8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018DDEC:
    // 0x8018DDEC: lbu         $t8, 0x1D($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1D);
    // 0x8018DDF0: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x8018DDF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018DDF8: andi        $t6, $t8, 0xFF7F
    ctx->r14 = ctx->r24 & 0XFF7F;
    // 0x8018DDFC: sb          $t6, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r14;
    // 0x8018DE00: sb          $t4, 0x4AE0($at)
    MEM_B(0X4AE0, ctx->r1) = ctx->r12;
    // 0x8018DE04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DE08:
    // 0x8018DE08: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8018DE0C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8018DE10: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8018DE14: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE18: jr          $ra
    // 0x8018DE1C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8018DE1C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ftLinkSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801638AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801638B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801638B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801638B8: jal         0x800DEEC8
    // 0x801638BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801638BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801638C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801638C4: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x801638C8: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x801638CC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801638D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801638D4: jal         0x800E6F24
    // 0x801638D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801638D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801638DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801638E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801638E4: jr          $ra
    // 0x801638E8: nop

    return;
    // 0x801638E8: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160B30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160B34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160B38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80160B3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80160B40: addiu       $a1, $zero, 0x127
    ctx->r5 = ADD32(0, 0X127);
    // 0x80160B44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160B48: jal         0x800E6F24
    // 0x80160B4C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80160B4C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80160B50: jal         0x800E0830
    // 0x80160B54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80160B54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80160B58: jal         0x80160B14
    // 0x80160B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyCaptainSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80160B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80160B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80160B68: jr          $ra
    // 0x80160B6C: nop

    return;
    // 0x80160B6C: nop

;}
RECOMP_FUNC void grHyruleTwisterUpdateSleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A36C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010A370: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010A374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A37C: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8010A380: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8010A384: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A388: beq         $t7, $zero, L_8010A3A4
    if (ctx->r15 == 0) {
        // 0x8010A38C: addiu       $a0, $zero, 0x4B0
        ctx->r4 = ADD32(0, 0X4B0);
            goto L_8010A3A4;
    }
    // 0x8010A38C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    // 0x8010A390: jal         0x80018994
    // 0x8010A394: sb          $t8, 0x1418($at)
    MEM_B(0X1418, ctx->r1) = ctx->r24;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010A394: sb          $t8, 0x1418($at)
    MEM_B(0X1418, ctx->r1) = ctx->r24;
    after_0:
    // 0x8010A398: addiu       $t9, $v0, 0x640
    ctx->r25 = ADD32(ctx->r2, 0X640);
    // 0x8010A39C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A3A0: sh          $t9, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r25;
L_8010A3A4:
    // 0x8010A3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A3A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A3AC: jr          $ra
    // 0x8010A3B0: nop

    return;
    // 0x8010A3B0: nop

;}
RECOMP_FUNC void gmCollisionGetItemAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F095C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F0960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F0964: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x800F0968: bne         $t6, $at, L_800F099C
    if (ctx->r14 != ctx->r1) {
        // 0x800F096C: subu        $t1, $t1, $a2
        ctx->r9 = SUB32(ctx->r9, ctx->r6);
            goto L_800F099C;
    }
    // 0x800F096C: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x800F0970: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800F0974: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800F0978: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800F097C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800F0980: lw          $t0, 0x58($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X58);
    // 0x800F0984: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800F0988: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x800F098C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800F0990: lw          $t0, 0x60($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X60);
    // 0x800F0994: jr          $ra
    // 0x800F0998: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    return;
    // 0x800F0998: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
L_800F099C:
    // 0x800F099C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800F09A0: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800F09A4: lwc1        $f4, 0x64($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800F09A8: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x800F09AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F09B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F09B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F09B8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F09BC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800F09C0: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x800F09C4: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800F09C8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F09CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F09D0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800F09D4: lwc1        $f10, 0x60($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X60);
    // 0x800F09D8: lwc1        $f8, 0x6C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x800F09DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F09E0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800F09E4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800F09E8: jr          $ra
    // 0x800F09EC: nop

    return;
    // 0x800F09EC: nop

;}
RECOMP_FUNC void func_ovl8_80383FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383FD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80383FD4: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80383FD8: lh          $a1, 0x1C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1C);
    // 0x80383FDC: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80383FE0: lh          $t6, 0x118($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X118);
    // 0x80383FE4: jalr        $t9
    // 0x80383FE8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383FE8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80383FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383FF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80383FF8: jr          $ra
    // 0x80383FFC: nop

    return;
    // 0x80383FFC: nop

;}

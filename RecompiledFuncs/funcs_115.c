#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PTrainingGetFreeCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801335F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801335F8: jal         0x80133408
    // 0x801335FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PTrainingGetFreeCostumeRoyal(rdram, ctx);
        goto after_0;
    // 0x801335FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80133600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133604: jal         0x800EC0EC
    // 0x80133608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x80133608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8013360C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133614: jr          $ra
    // 0x80133618: nop

    return;
    // 0x80133618: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchUpdateProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F1B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F1B8: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8015F1BC: beql        $t6, $zero, L_8015F1D4
    if (ctx->r14 == 0) {
        // 0x8015F1C0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8015F1D4;
    }
    goto skip_0;
    // 0x8015F1C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8015F1C4: lw          $t7, 0x840($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X840);
    // 0x8015F1C8: bne         $t7, $zero, L_8015F1E8
    if (ctx->r15 != 0) {
        // 0x8015F1CC: nop
    
            goto L_8015F1E8;
    }
    // 0x8015F1CC: nop

    // 0x8015F1D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8015F1D4:
    // 0x8015F1D4: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015F1D8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015F1DC: nop

    // 0x8015F1E0: bc1fl       L_8015F1F4
    if (!c1cs) {
        // 0x8015F1E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015F1F4;
    }
    goto skip_1;
    // 0x8015F1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_8015F1E8:
    // 0x8015F1E8: jalr        $a1
    // 0x8015F1EC: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x8015F1EC: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    after_0:
    // 0x8015F1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015F1F4:
    // 0x8015F1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F1F8: jr          $ra
    // 0x8015F1FC: nop

    return;
    // 0x8015F1FC: nop

;}
RECOMP_FUNC void func_ovl8_80377F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80377F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377F58: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80377F5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80377F60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80377F64: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80377F68: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80377F6C: sh          $t9, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r25;
    // 0x80377F70: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x80377F74: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80377F78: jal         0x80377B40
    // 0x80377F7C: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
    func_ovl8_80377B40(rdram, ctx);
        goto after_0;
    // 0x80377F7C: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80377F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80377F88: jr          $ra
    // 0x80377F8C: nop

    return;
    // 0x80377F8C: nop

;}
RECOMP_FUNC void func_800267F4_273F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800267F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800267F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800267FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026800: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80026804: jal         0x80030350
    // 0x80026808: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026808: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002680C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80026810: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026814: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80026818: beq         $a1, $zero, L_8002682C
    if (ctx->r5 == 0) {
        // 0x8002681C: addiu       $v0, $v0, -0x1230
        ctx->r2 = ADD32(ctx->r2, -0X1230);
            goto L_8002682C;
    }
    // 0x8002681C: addiu       $v0, $v0, -0x1230
    ctx->r2 = ADD32(ctx->r2, -0X1230);
    // 0x80026820: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x80026824: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80026828: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
L_8002682C:
    // 0x8002682C: jal         0x80030350
    // 0x80026830: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026830: nop

    after_1:
    // 0x80026834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002683C: jr          $ra
    // 0x80026840: nop

    return;
    // 0x80026840: nop

;}
RECOMP_FUNC void mnOptionSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132174: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80132178: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8013217C: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80132180: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132184: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80132188: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013218C: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132190: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132194: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x80132198: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8013219C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x801321A0: jr          $ra
    // 0x801321A4: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x801321A4: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftParamUpdateDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA248: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EA24C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA250: lbu         $t9, 0xD($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XD);
    // 0x800EA254: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
    // 0x800EA258: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800EA25C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EA260: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800EA264: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800EA268: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x800EA26C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800EA270: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800EA274: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800EA278: mflo        $t1
    ctx->r9 = lo;
    // 0x800EA27C: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x800EA280: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x800EA284: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800EA288: sw          $t3, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r11;
    // 0x800EA28C: lw          $v1, 0x2C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X2C);
    // 0x800EA290: slti        $at, $v1, 0x3E8
    ctx->r1 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // 0x800EA294: bnel        $at, $zero, L_800EA2A8
    if (ctx->r1 != 0) {
        // 0x800EA298: lbu         $t6, 0xD($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0XD);
            goto L_800EA2A8;
    }
    goto skip_0;
    // 0x800EA298: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    skip_0:
    // 0x800EA29C: addiu       $v1, $zero, 0x3E7
    ctx->r3 = ADD32(0, 0X3E7);
    // 0x800EA2A0: sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
    // 0x800EA2A4: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
L_800EA2A8:
    // 0x800EA2A8: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800EA2AC: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EA2B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800EA2B4: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800EA2B8: sw          $v1, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->r3;
    // 0x800EA2BC: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    // 0x800EA2C0: beql        $a0, $zero, L_800EA3C8
    if (ctx->r4 == 0) {
        // 0x800EA2C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EA3C8;
    }
    goto skip_1;
    // 0x800EA2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800EA2C8: lwc1        $f0, 0x7E0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X7E0);
    // 0x800EA2CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EA2D0: nop

    // 0x800EA2D4: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800EA2D8: nop

    // 0x800EA2DC: bc1tl       L_800EA3C8
    if (c1cs) {
        // 0x800EA2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EA3C8;
    }
    goto skip_2;
    // 0x800EA2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800EA2E4: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x800EA2E8: beql        $t8, $zero, L_800EA328
    if (ctx->r24 == 0) {
        // 0x800EA2EC: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_800EA328;
    }
    goto skip_3;
    // 0x800EA2EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    skip_3:
    // 0x800EA2F0: lw          $t1, 0x190($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X190);
    // 0x800EA2F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800EA2F8: sll         $t3, $t1, 22
    ctx->r11 = S32(ctx->r9 << 22);
    // 0x800EA2FC: bgezl       $t3, L_800EA328
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800EA300: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_800EA328;
    }
    goto skip_4;
    // 0x800EA300: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    skip_4:
    // 0x800EA304: lwc1        $f6, 0x7EC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X7EC);
    // 0x800EA308: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EA30C: nop

    // 0x800EA310: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EA314: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800EA318: nop

    // 0x800EA31C: bc1tl       L_800EA3C8
    if (c1cs) {
        // 0x800EA320: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EA3C8;
    }
    goto skip_5;
    // 0x800EA320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800EA324: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
L_800EA328:
    // 0x800EA328: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800EA32C: lbu         $t4, 0x2CE($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2CE);
    // 0x800EA330: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x800EA334: bnel        $t6, $zero, L_800EA360
    if (ctx->r14 != 0) {
        // 0x800EA338: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800EA360;
    }
    goto skip_6;
    // 0x800EA338: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_6:
    // 0x800EA33C: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800EA340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EA344: beq         $v0, $at, L_800EA3C4
    if (ctx->r2 == ctx->r1) {
        // 0x800EA348: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800EA3C4;
    }
    // 0x800EA348: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800EA34C: beq         $v0, $at, L_800EA3C4
    if (ctx->r2 == ctx->r1) {
        // 0x800EA350: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_800EA3C4;
    }
    // 0x800EA350: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x800EA354: beql        $v0, $at, L_800EA3C8
    if (ctx->r2 == ctx->r1) {
        // 0x800EA358: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EA3C8;
    }
    goto skip_7;
    // 0x800EA358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x800EA35C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_800EA360:
    // 0x800EA360: jal         0x80018994
    // 0x800EA364: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x800EA364: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EA368: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800EA36C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800EA370: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800EA374: bnel        $at, $zero, L_800EA3A8
    if (ctx->r1 != 0) {
        // 0x800EA378: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800EA3A8;
    }
    goto skip_8;
    // 0x800EA378: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_8:
    // 0x800EA37C: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    // 0x800EA380: jal         0x80172890
    // 0x800EA384: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    itMainCheckShootNoAmmo(rdram, ctx);
        goto after_1;
    // 0x800EA384: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x800EA388: beq         $v0, $zero, L_800EA3C4
    if (ctx->r2 == 0) {
        // 0x800EA38C: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_800EA3C4;
    }
    // 0x800EA38C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800EA390: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800EA394: jal         0x80018994
    // 0x800EA398: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x800EA398: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x800EA39C: bne         $v0, $zero, L_800EA3C4
    if (ctx->r2 != 0) {
        // 0x800EA3A0: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_800EA3C4;
    }
    // 0x800EA3A0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800EA3A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800EA3A8:
    // 0x800EA3A8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800EA3AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800EA3B0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800EA3B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800EA3B8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800EA3BC: jal         0x80172AEC
    // 0x800EA3C0: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_3;
    // 0x800EA3C0: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    after_3:
L_800EA3C4:
    // 0x800EA3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EA3C8:
    // 0x800EA3C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EA3CC: jr          $ra
    // 0x800EA3D0: nop

    return;
    // 0x800EA3D0: nop

;}
RECOMP_FUNC void grInishieScaleUpdateFighterStatsGA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108CD0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80108CD4: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x80108CD8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80108CDC: addiu       $a3, $a3, 0x13F0
    ctx->r7 = ADD32(ctx->r7, 0X13F0);
    // 0x80108CE0: beq         $v0, $zero, L_80108D48
    if (ctx->r2 == 0) {
        // 0x80108CE4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80108D48;
    }
    // 0x80108CE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80108CE8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_80108CEC:
    // 0x80108CEC: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
    // 0x80108CF0: lbu         $a0, 0xD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD);
    // 0x80108CF4: bne         $a1, $zero, L_80108D30
    if (ctx->r5 != 0) {
        // 0x80108CF8: addu        $a2, $a3, $a0
        ctx->r6 = ADD32(ctx->r7, ctx->r4);
            goto L_80108D30;
    }
    // 0x80108CF8: addu        $a2, $a3, $a0
    ctx->r6 = ADD32(ctx->r7, ctx->r4);
    // 0x80108CFC: addu        $a2, $a3, $a0
    ctx->r6 = ADD32(ctx->r7, ctx->r4);
    // 0x80108D00: lbu         $t6, 0x37($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X37);
    // 0x80108D04: beql        $t6, $zero, L_80108D1C
    if (ctx->r14 == 0) {
        // 0x80108D08: lbu         $a0, 0x33($a2)
        ctx->r4 = MEM_BU(ctx->r6, 0X33);
            goto L_80108D1C;
    }
    goto skip_0;
    // 0x80108D08: lbu         $a0, 0x33($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X33);
    skip_0:
    // 0x80108D0C: sb          $t0, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r8;
    // 0x80108D10: b           L_80108D38
    // 0x80108D14: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
        goto L_80108D38;
    // 0x80108D14: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
    // 0x80108D18: lbu         $a0, 0x33($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X33);
L_80108D1C:
    // 0x80108D1C: beq         $a0, $zero, L_80108D38
    if (ctx->r4 == 0) {
        // 0x80108D20: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80108D38;
    }
    // 0x80108D20: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x80108D24: sb          $t7, 0x33($a2)
    MEM_B(0X33, ctx->r6) = ctx->r15;
    // 0x80108D28: b           L_80108D38
    // 0x80108D2C: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
        goto L_80108D38;
    // 0x80108D2C: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
L_80108D30:
    // 0x80108D30: sb          $zero, 0x33($a2)
    MEM_B(0X33, ctx->r6) = 0;
    // 0x80108D34: lw          $a1, 0x14C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14C);
L_80108D38:
    // 0x80108D38: sb          $a1, 0x37($a2)
    MEM_B(0X37, ctx->r6) = ctx->r5;
    // 0x80108D3C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80108D40: bnel        $v0, $zero, L_80108CEC
    if (ctx->r2 != 0) {
        // 0x80108D44: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_80108CEC;
    }
    goto skip_1;
    // 0x80108D44: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_1:
L_80108D48:
    // 0x80108D48: jr          $ra
    // 0x80108D4C: nop

    return;
    // 0x80108D4C: nop

;}
RECOMP_FUNC void efManagerDustDashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF7D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FF7DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FF7E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF7E4: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF7E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF7EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FF7F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF7F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800FF7F8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x800FF7FC: jal         0x800CE9E8
    // 0x800FF800: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x800FF800: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x800FF804: beq         $v0, $zero, L_800FF8A8
    if (ctx->r2 == 0) {
        // 0x800FF808: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF8A8;
    }
    // 0x800FF808: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FF80C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FF810: jal         0x800CE1DC
    // 0x800FF814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x800FF814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800FF818: beq         $v0, $zero, L_800FF89C
    if (ctx->r2 == 0) {
        // 0x800FF81C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FF89C;
    }
    // 0x800FF81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF820: jal         0x800CEA14
    // 0x800FF824: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x800FF824: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x800FF828: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800FF82C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800FF830: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FF834: bnel        $t6, $zero, L_800FF848
    if (ctx->r14 != 0) {
        // 0x800FF838: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_800FF848;
    }
    goto skip_0;
    // 0x800FF838: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x800FF83C: b           L_800FF8AC
    // 0x800FF840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF8AC;
    // 0x800FF840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FF844: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_800FF848:
    // 0x800FF848: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800FF84C: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x800FF850: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800FF854: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800FF858: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF85C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FF860: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800FF864: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FF868: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800FF86C: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x800FF870: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FF874: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x800FF878: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800FF87C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800FF880: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800FF884: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF888: bne         $t0, $at, L_800FF8A8
    if (ctx->r8 != ctx->r1) {
        // 0x800FF88C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800FF8A8;
    }
    // 0x800FF88C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF890: lwc1        $f10, 0x994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X994);
    // 0x800FF894: b           L_800FF8A8
    // 0x800FF898: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
        goto L_800FF8A8;
    // 0x800FF898: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
L_800FF89C:
    // 0x800FF89C: jal         0x800CEA40
    // 0x800FF8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x800FF8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FF8A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800FF8A8:
    // 0x800FF8A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800FF8AC:
    // 0x800FF8AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF8B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF8B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FF8B8: jr          $ra
    // 0x800FF8BC: nop

    return;
    // 0x800FF8BC: nop

;}
RECOMP_FUNC void func_ovl8_80376C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376C40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376C44: beq         $a0, $at, L_80376C60
    if (ctx->r4 == ctx->r1) {
        // 0x80376C48: srl         $t6, $a1, 11
        ctx->r14 = S32(U32(ctx->r5) >> 11);
            goto L_80376C60;
    }
    // 0x80376C48: srl         $t6, $a1, 11
    ctx->r14 = S32(U32(ctx->r5) >> 11);
    // 0x80376C4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80376C50: beq         $a0, $at, L_80376EC0
    if (ctx->r4 == ctx->r1) {
        // 0x80376C54: srl         $t0, $a1, 24
        ctx->r8 = S32(U32(ctx->r5) >> 24);
            goto L_80376EC0;
    }
    // 0x80376C54: srl         $t0, $a1, 24
    ctx->r8 = S32(U32(ctx->r5) >> 24);
    // 0x80376C58: jr          $ra
    // 0x80376C5C: nop

    return;
    // 0x80376C5C: nop

L_80376C60:
    // 0x80376C60: lui         $at, 0x403F
    ctx->r1 = S32(0X403F << 16);
    // 0x80376C64: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x80376C68: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80376C6C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80376C70: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80376C74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80376C78: ldc1        $f2, -0x1200($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1200);
    // 0x80376C7C: bgez        $t7, L_80376C94
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80376C80: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80376C94;
    }
    // 0x80376C80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80376C84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80376C8C: nop

    // 0x80376C90: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80376C94:
    // 0x80376C94: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80376C98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80376C9C: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x80376CA0: srl         $t0, $a1, 6
    ctx->r8 = S32(U32(ctx->r5) >> 6);
    // 0x80376CA4: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80376CA8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80376CAC: andi        $t1, $t0, 0x1F
    ctx->r9 = ctx->r8 & 0X1F;
    // 0x80376CB0: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x80376CB4: mul.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x80376CB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80376CBC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80376CC0: nop

    // 0x80376CC4: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x80376CC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80376CCC: nop

    // 0x80376CD0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80376CD4: beql        $t9, $zero, L_80376D28
    if (ctx->r25 == 0) {
        // 0x80376CD8: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_80376D28;
    }
    goto skip_0;
    // 0x80376CD8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80376CDC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80376CE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80376CE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80376CE8: sub.d       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = ctx->f18.d - ctx->f4.d;
    // 0x80376CEC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80376CF0: nop

    // 0x80376CF4: cvt.w.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_D(ctx->f4.d);
    // 0x80376CF8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80376CFC: nop

    // 0x80376D00: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80376D04: bne         $t9, $zero, L_80376D1C
    if (ctx->r25 != 0) {
        // 0x80376D08: nop
    
            goto L_80376D1C;
    }
    // 0x80376D08: nop

    // 0x80376D0C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80376D10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80376D14: b           L_80376D34
    // 0x80376D18: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80376D34;
    // 0x80376D18: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80376D1C:
    // 0x80376D1C: b           L_80376D34
    // 0x80376D20: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80376D34;
    // 0x80376D20: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80376D24: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_80376D28:
    // 0x80376D28: nop

    // 0x80376D2C: bltz        $t9, L_80376D1C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80376D30: nop
    
            goto L_80376D1C;
    }
    // 0x80376D30: nop

L_80376D34:
    // 0x80376D34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80376D38: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80376D3C: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80376D40: bgez        $t1, L_80376D58
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80376D44: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80376D58;
    }
    // 0x80376D44: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80376D48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80376D50: nop

    // 0x80376D54: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80376D58:
    // 0x80376D58: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80376D5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80376D60: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x80376D64: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80376D68: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80376D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80376D70: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80376D74: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80376D78: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80376D7C: nop

    // 0x80376D80: cvt.w.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_D(ctx->f4.d);
    // 0x80376D84: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80376D88: nop

    // 0x80376D8C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80376D90: beql        $t3, $zero, L_80376DE4
    if (ctx->r11 == 0) {
        // 0x80376D94: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_80376DE4;
    }
    goto skip_1;
    // 0x80376D94: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x80376D98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80376D9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80376DA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80376DA4: sub.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d - ctx->f8.d;
    // 0x80376DA8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80376DAC: nop

    // 0x80376DB0: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x80376DB4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80376DB8: nop

    // 0x80376DBC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80376DC0: bne         $t3, $zero, L_80376DD8
    if (ctx->r11 != 0) {
        // 0x80376DC4: nop
    
            goto L_80376DD8;
    }
    // 0x80376DC4: nop

    // 0x80376DC8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80376DCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80376DD0: b           L_80376DF0
    // 0x80376DD4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80376DF0;
    // 0x80376DD4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80376DD8:
    // 0x80376DD8: b           L_80376DF0
    // 0x80376DDC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80376DF0;
    // 0x80376DDC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80376DE0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_80376DE4:
    // 0x80376DE4: nop

    // 0x80376DE8: bltz        $t3, L_80376DD8
    if (SIGNED(ctx->r11) < 0) {
        // 0x80376DEC: nop
    
            goto L_80376DD8;
    }
    // 0x80376DEC: nop

L_80376DF0:
    // 0x80376DF0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80376DF4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80376DF8: sb          $t3, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r11;
    // 0x80376DFC: bgez        $t5, L_80376E14
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80376E00: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80376E14;
    }
    // 0x80376E00: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80376E04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376E08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80376E0C: nop

    // 0x80376E10: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80376E14:
    // 0x80376E14: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80376E18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80376E1C: div.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80376E20: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80376E24: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80376E28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80376E2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80376E30: nop

    // 0x80376E34: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80376E38: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80376E3C: nop

    // 0x80376E40: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80376E44: beql        $t7, $zero, L_80376E98
    if (ctx->r15 == 0) {
        // 0x80376E48: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_80376E98;
    }
    goto skip_2;
    // 0x80376E48: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x80376E4C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80376E50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80376E54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80376E58: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x80376E5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80376E60: nop

    // 0x80376E64: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80376E68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80376E6C: nop

    // 0x80376E70: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80376E74: bne         $t7, $zero, L_80376E8C
    if (ctx->r15 != 0) {
        // 0x80376E78: nop
    
            goto L_80376E8C;
    }
    // 0x80376E78: nop

    // 0x80376E7C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80376E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80376E84: b           L_80376EA4
    // 0x80376E88: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80376EA4;
    // 0x80376E88: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80376E8C:
    // 0x80376E8C: b           L_80376EA4
    // 0x80376E90: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80376EA4;
    // 0x80376E90: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80376E94: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_80376E98:
    // 0x80376E98: nop

    // 0x80376E9C: bltz        $t7, L_80376E8C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80376EA0: nop
    
            goto L_80376E8C;
    }
    // 0x80376EA0: nop

L_80376EA4:
    // 0x80376EA4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80376EA8: beq         $t8, $zero, L_80376EB8
    if (ctx->r24 == 0) {
        // 0x80376EAC: sb          $t7, 0x2($a2)
        MEM_B(0X2, ctx->r6) = ctx->r15;
            goto L_80376EB8;
    }
    // 0x80376EAC: sb          $t7, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r15;
    // 0x80376EB0: b           L_80376EB8
    // 0x80376EB4: addiu       $v0, $zero, 0x255
    ctx->r2 = ADD32(0, 0X255);
        goto L_80376EB8;
    // 0x80376EB4: addiu       $v0, $zero, 0x255
    ctx->r2 = ADD32(0, 0X255);
L_80376EB8:
    // 0x80376EB8: jr          $ra
    // 0x80376EBC: sb          $v0, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r2;
    return;
    // 0x80376EBC: sb          $v0, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r2;
L_80376EC0:
    // 0x80376EC0: srl         $t2, $a1, 16
    ctx->r10 = S32(U32(ctx->r5) >> 16);
    // 0x80376EC4: srl         $t4, $a1, 8
    ctx->r12 = S32(U32(ctx->r5) >> 8);
    // 0x80376EC8: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x80376ECC: sb          $t2, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r10;
    // 0x80376ED0: sb          $t4, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r12;
    // 0x80376ED4: sb          $a1, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r5;
    // 0x80376ED8: jr          $ra
    // 0x80376EDC: nop

    return;
    // 0x80376EDC: nop

;}
RECOMP_FUNC void mpCollisionCheckRWallLineCollisionDiff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F769C: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800F76A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F76A4: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F76A8: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F76AC: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F76B0: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F76B4: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F76B8: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F76BC: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F76C0: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F76C4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F76C8: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F76CC: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F76D0: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F76D4: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F76D8: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F76DC: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F76E0: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F76E4: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F76E8: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x800F76EC: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x800F76F0: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800F76F4: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F76F8: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F76FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7700: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x800F7704: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7708: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F770C: lwc1        $f22, 0x874($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X874);
    // 0x800F7710: blez        $t0, L_800F7CC0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F7714: lw          $fp, 0x118($sp)
        ctx->r30 = MEM_W(ctx->r29, 0X118);
            goto L_800F7CC0;
    }
    // 0x800F7714: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x800F7718: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F771C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F7720: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800F7724: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F7728: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F772C: lw          $s6, 0x11C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X11C);
    // 0x800F7730: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F7734:
    // 0x800F7734: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800F7738: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F773C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F7740: addiu       $a0, $t7, 0xA
    ctx->r4 = ADD32(ctx->r15, 0XA);
    // 0x800F7744: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F7748: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x800F774C: lhu         $t5, 0xC($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0XC);
    // 0x800F7750: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800F7754: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800F7758: beq         $t5, $zero, L_800F7CA0
    if (ctx->r13 == 0) {
        // 0x800F775C: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_800F7CA0;
    }
    // 0x800F775C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800F7760: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800F7764: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x800F7768: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x800F776C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800F7770: beql        $at, $zero, L_800F7CA4
    if (ctx->r1 == 0) {
        // 0x800F7774: lw          $t6, 0xF8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF8);
            goto L_800F7CA4;
    }
    goto skip_0;
    // 0x800F7774: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    skip_0:
    // 0x800F7778: lw          $t9, 0x70($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X70);
    // 0x800F777C: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F7780: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F7784: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800F7788: bne         $t9, $zero, L_800F7794
    if (ctx->r25 != 0) {
        // 0x800F778C: lwc1        $f16, 0x4($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F7794;
    }
    // 0x800F778C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800F7790: beq         $v0, $zero, L_800F77E8
    if (ctx->r2 == 0) {
        // 0x800F7794: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800F77E8;
    }
L_800F7794:
    // 0x800F7794: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F7798: lwc1        $f30, 0x1C($v1)
    ctx->f30.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800F779C: lw          $t4, 0x137C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X137C);
    // 0x800F77A0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F77A4: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800F77A8: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800F77AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F77B0: sub.s       $f4, $f2, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F77B4: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x800F77B8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F77BC: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800F77C0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F77C4: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x800F77C8: add.s       $f24, $f4, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800F77CC: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x800F77D0: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800F77D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F77D8: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x800F77DC: sub.s       $f28, $f14, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f28.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F77E0: b           L_800F7804
    // 0x800F77E4: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
        goto L_800F7804;
    // 0x800F77E4: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F77E8:
    // 0x800F77E8: swc1        $f26, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f26.u32l;
    // 0x800F77EC: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    // 0x800F77F0: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    // 0x800F77F4: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    // 0x800F77F8: swc1        $f12, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f12.u32l;
    // 0x800F77FC: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x800F7800: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
L_800F7804:
    // 0x800F7804: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F7808: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F780C: bc1f        L_800F7838
    if (!c1cs) {
        // 0x800F7810: nop
    
            goto L_800F7838;
    }
    // 0x800F7810: nop

    // 0x800F7814: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7818: lwc1        $f6, 0x878($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X878);
    // 0x800F781C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7820: lwc1        $f10, 0x87C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X87C);
    // 0x800F7824: sub.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800F7828: add.s       $f4, $f28, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x800F782C: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x800F7830: b           L_800F784C
    // 0x800F7834: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
        goto L_800F784C;
    // 0x800F7834: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_800F7838:
    // 0x800F7838: lwc1        $f0, 0x880($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X880);
    // 0x800F783C: sub.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f0.fl;
    // 0x800F7840: add.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x800F7844: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800F7848: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_800F784C:
    // 0x800F784C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F7850: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x800F7854: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F7858: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800F785C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F7860: beq         $at, $zero, L_800F7CA0
    if (ctx->r1 == 0) {
        // 0x800F7864: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F7CA0;
    }
    // 0x800F7864: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F7868: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F786C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
L_800F7870:
    // 0x800F7870: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F7874: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F7878: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F787C: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800F7880: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800F7884: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800F7888: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F788C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F7890: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F7894: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800F7898: nop

    // 0x800F789C: bc1fl       L_800F78B8
    if (!c1cs) {
        // 0x800F78A0: sw          $v1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r3;
            goto L_800F78B8;
    }
    goto skip_1;
    // 0x800F78A0: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800F78A4: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F78A8: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800F78AC: b           L_800F7C84
    // 0x800F78B0: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
        goto L_800F7C84;
    // 0x800F78B0: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x800F78B4: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
L_800F78B8:
    // 0x800F78B8: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
    // 0x800F78BC: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800F78C0: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800F78C4: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x800F78C8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800F78CC: nop

    // 0x800F78D0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F78D4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800F78D8: nop

    // 0x800F78DC: bc1f        L_800F78F0
    if (!c1cs) {
        // 0x800F78E0: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800F78F0;
    }
    // 0x800F78E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F78E4: lw          $t8, 0x1368($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1368);
    // 0x800F78E8: b           L_800F7CA0
    // 0x800F78EC: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
        goto L_800F7CA0;
    // 0x800F78EC: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
L_800F78F0:
    // 0x800F78F0: lw          $t9, 0x1378($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1378);
    // 0x800F78F4: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F78F8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F78FC: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x800F7900: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7904: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F7908: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800F790C: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F7910: addu        $t5, $t7, $s2
    ctx->r13 = ADD32(ctx->r15, ctx->r18);
    // 0x800F7914: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800F7918: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800F791C: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800F7920: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F7924: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F7928: mflo        $t8
    ctx->r24 = lo;
    // 0x800F792C: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x800F7930: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F7934: beq         $at, $zero, L_800F7C6C
    if (ctx->r1 == 0) {
        // 0x800F7938: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F7C6C;
    }
    // 0x800F7938: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F793C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
L_800F7940:
    // 0x800F7940: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800F7944: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800F7948: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F794C: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x800F7950: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x800F7954: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F7958: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F795C: addiu       $t9, $sp, 0xB0
    ctx->r25 = ADD32(ctx->r29, 0XB0);
    // 0x800F7960: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800F7964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7968: mflo        $t7
    ctx->r15 = lo;
    // 0x800F796C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800F7970: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F7974: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F7978: bne         $s0, $s3, L_800F7ADC
    if (ctx->r16 != ctx->r19) {
        // 0x800F797C: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F7ADC;
    }
    // 0x800F797C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F7980: c.lt.s      $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f28.fl < ctx->f24.fl;
    // 0x800F7984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F7988: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F798C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F7990: bc1f        L_800F7C3C
    if (!c1cs) {
        // 0x800F7994: lwc1        $f6, 0xE8($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
            goto L_800F7C3C;
    }
    // 0x800F7994: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F7998: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F799C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800F79A0: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x800F79A4: addiu       $t4, $sp, 0xB0
    ctx->r12 = ADD32(ctx->r29, 0XB0);
    // 0x800F79A8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800F79AC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800F79B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800F79B4: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x800F79B8: jal         0x800F7D24
    // 0x800F79BC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    mpCollisionCheckLRSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F79BC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800F79C0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F79C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F79C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F79CC: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F79D0: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F79D4: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F79D8: bne         $v0, $at, L_800F7C3C
    if (ctx->r2 != ctx->r1) {
        // 0x800F79DC: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F7C3C;
    }
    // 0x800F79DC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F79E0: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F79E4: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F79E8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F79EC: sub.s       $f20, $f24, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800F79F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F79F4: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F79F8: nop

    // 0x800F79FC: bc1fl       L_800F7A14
    if (!c1cs) {
        // 0x800F7A00: sub.s       $f0, $f6, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800F7A14;
    }
    goto skip_2;
    // 0x800F7A00: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    skip_2:
    // 0x800F7A04: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F7A08: b           L_800F7A14
    // 0x800F7A0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F7A14;
    // 0x800F7A0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F7A10: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
L_800F7A14:
    // 0x800F7A14: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F7A18: nop

    // 0x800F7A1C: bc1f        L_800F7A44
    if (!c1cs) {
        // 0x800F7A20: nop
    
            goto L_800F7A44;
    }
    // 0x800F7A20: nop

    // 0x800F7A24: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F7A28: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F7A2C: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F7A30: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7A34: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F7A38: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F7A3C: b           L_800F7C5C
    // 0x800F7A40: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F7C5C;
    // 0x800F7A40: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F7A44:
    // 0x800F7A44: beq         $s5, $zero, L_800F7A68
    if (ctx->r21 == 0) {
        // 0x800F7A48: lwc1        $f8, 0xB4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F7A68;
    }
    // 0x800F7A48: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F7A4C: add.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800F7A50: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    // 0x800F7A54: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F7A58: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F7A5C: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F7A60: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800F7A64: swc1        $f8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f8.u32l;
L_800F7A68:
    // 0x800F7A68: beq         $t0, $zero, L_800F7A74
    if (ctx->r8 == 0) {
        // 0x800F7A6C: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800F7A74;
    }
    // 0x800F7A6C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800F7A70: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800F7A74:
    // 0x800F7A74: beq         $s6, $zero, L_800F7A8C
    if (ctx->r22 == 0) {
        // 0x800F7A78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800F7A8C;
    }
    // 0x800F7A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F7A7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F7A80: swc1        $f26, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f26.u32l;
    // 0x800F7A84: swc1        $f26, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f26.u32l;
    // 0x800F7A88: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
L_800F7A8C:
    // 0x800F7A8C: beql        $fp, $zero, L_800F7ABC
    if (ctx->r30 == 0) {
        // 0x800F7A90: lwc1        $f10, 0xB4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F7ABC;
    }
    goto skip_3;
    // 0x800F7A90: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    skip_3:
    // 0x800F7A94: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800F7A98: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F7A9C: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F7AA0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F7AA4: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F7AA8: mflo        $t6
    ctx->r14 = lo;
    // 0x800F7AAC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800F7AB0: lhu         $t4, 0x4($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X4);
    // 0x800F7AB4: sw          $t4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r12;
    // 0x800F7AB8: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
L_800F7ABC:
    // 0x800F7ABC: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F7AC0: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F7AC4: bc1f        L_800F7AD4
    if (!c1cs) {
        // 0x800F7AC8: nop
    
            goto L_800F7AD4;
    }
    // 0x800F7AC8: nop

    // 0x800F7ACC: b           L_800F7C3C
    // 0x800F7AD0: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F7C3C;
    // 0x800F7AD0: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F7AD4:
    // 0x800F7AD4: b           L_800F7C3C
    // 0x800F7AD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F7C3C;
    // 0x800F7AD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F7ADC:
    // 0x800F7ADC: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F7AE0: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F7AE4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F7AE8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800F7AEC: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800F7AF0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800F7AF4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800F7AF8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800F7AFC: jal         0x800F7270
    // 0x800F7B00: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    mpCollisionCheckRWallSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F7B00: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F7B04: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F7B08: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F7B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F7B10: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F7B14: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F7B18: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F7B1C: bne         $v0, $at, L_800F7C3C
    if (ctx->r2 != ctx->r1) {
        // 0x800F7B20: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F7C3C;
    }
    // 0x800F7B20: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F7B24: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F7B28: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F7B2C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F7B30: sub.s       $f20, $f24, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800F7B34: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F7B38: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F7B3C: nop

    // 0x800F7B40: bc1fl       L_800F7B58
    if (!c1cs) {
        // 0x800F7B44: sub.s       $f0, $f6, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800F7B58;
    }
    goto skip_4;
    // 0x800F7B44: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    skip_4:
    // 0x800F7B48: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F7B4C: b           L_800F7B58
    // 0x800F7B50: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F7B58;
    // 0x800F7B50: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F7B54: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
L_800F7B58:
    // 0x800F7B58: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F7B5C: nop

    // 0x800F7B60: bc1f        L_800F7B88
    if (!c1cs) {
        // 0x800F7B64: nop
    
            goto L_800F7B88;
    }
    // 0x800F7B64: nop

    // 0x800F7B68: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F7B6C: addu        $v0, $t5, $s7
    ctx->r2 = ADD32(ctx->r13, ctx->r23);
    // 0x800F7B70: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x800F7B74: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7B78: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800F7B7C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F7B80: b           L_800F7C5C
    // 0x800F7B84: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F7C5C;
    // 0x800F7B84: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F7B88:
    // 0x800F7B88: beq         $s5, $zero, L_800F7BAC
    if (ctx->r21 == 0) {
        // 0x800F7B8C: lwc1        $f8, 0xB4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F7BAC;
    }
    // 0x800F7B8C: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F7B90: add.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800F7B94: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    // 0x800F7B98: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F7B9C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F7BA0: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F7BA4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800F7BA8: swc1        $f8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f8.u32l;
L_800F7BAC:
    // 0x800F7BAC: beq         $t0, $zero, L_800F7BB8
    if (ctx->r8 == 0) {
        // 0x800F7BB0: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_800F7BB8;
    }
    // 0x800F7BB0: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800F7BB4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800F7BB8:
    // 0x800F7BB8: beq         $s6, $zero, L_800F7BF0
    if (ctx->r22 == 0) {
        // 0x800F7BBC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F7BF0;
    }
    // 0x800F7BBC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F7BC0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F7BC4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800F7BC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F7BCC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F7BD0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F7BD4: jal         0x800F71A0
    // 0x800F7BD8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRAngle(rdram, ctx);
        goto after_2;
    // 0x800F7BD8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F7BDC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F7BE0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F7BE4: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F7BE8: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F7BEC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F7BF0:
    // 0x800F7BF0: beql        $fp, $zero, L_800F7C20
    if (ctx->r30 == 0) {
        // 0x800F7BF4: lwc1        $f4, 0xB4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F7C20;
    }
    goto skip_5;
    // 0x800F7BF4: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    skip_5:
    // 0x800F7BF8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F7BFC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F7C00: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800F7C04: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F7C08: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F7C0C: mflo        $t4
    ctx->r12 = lo;
    // 0x800F7C10: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800F7C14: lhu         $t5, 0x4($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X4);
    // 0x800F7C18: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x800F7C1C: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
L_800F7C20:
    // 0x800F7C20: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F7C24: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F7C28: bc1fl       L_800F7C3C
    if (!c1cs) {
        // 0x800F7C2C: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F7C3C;
    }
    goto skip_6;
    // 0x800F7C2C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_6:
    // 0x800F7C30: b           L_800F7C3C
    // 0x800F7C34: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F7C3C;
    // 0x800F7C34: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F7C38: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F7C3C:
    // 0x800F7C3C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F7C40: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F7C44: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F7C48: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F7C4C: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7C50: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F7C54: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F7C58: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F7C5C:
    // 0x800F7C5C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F7C60: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F7C64: bnel        $at, $zero, L_800F7940
    if (ctx->r1 != 0) {
        // 0x800F7C68: lw          $t4, 0x0($t2)
        ctx->r12 = MEM_W(ctx->r10, 0X0);
            goto L_800F7940;
    }
    goto skip_7;
    // 0x800F7C68: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    skip_7:
L_800F7C6C:
    // 0x800F7C6C: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x800F7C70: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800F7C74: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F7C78: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800F7C7C: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800F7C80: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
L_800F7C84:
    // 0x800F7C84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F7C88: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F7C8C: bne         $at, $zero, L_800F7870
    if (ctx->r1 != 0) {
        // 0x800F7C90: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F7870;
    }
    // 0x800F7C90: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F7C94: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F7C98: lw          $t5, 0x1368($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1368);
    // 0x800F7C9C: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
L_800F7CA0:
    // 0x800F7CA0: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
L_800F7CA4:
    // 0x800F7CA4: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800F7CA8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800F7CAC: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F7CB0: addiu       $t4, $t9, 0x12
    ctx->r12 = ADD32(ctx->r25, 0X12);
    // 0x800F7CB4: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x800F7CB8: bne         $at, $zero, L_800F7734
    if (ctx->r1 != 0) {
        // 0x800F7CBC: sw          $t7, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r15;
            goto L_800F7734;
    }
    // 0x800F7CBC: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
L_800F7CC0:
    // 0x800F7CC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7CC4: lwc1        $f10, 0x884($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X884);
    // 0x800F7CC8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F7CCC: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F7CD0: c.eq.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl == ctx->f10.fl;
    // 0x800F7CD4: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F7CD8: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F7CDC: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F7CE0: bc1f        L_800F7CF0
    if (!c1cs) {
        // 0x800F7CE4: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F7CF0;
    }
    // 0x800F7CE4: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F7CE8: b           L_800F7CF4
    // 0x800F7CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7CF4;
    // 0x800F7CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F7CF0:
    // 0x800F7CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F7CF4:
    // 0x800F7CF4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F7CF8: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F7CFC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F7D00: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F7D04: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F7D08: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F7D0C: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F7D10: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F7D14: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F7D18: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F7D1C: jr          $ra
    // 0x800F7D20: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800F7D20: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void ifCommonTimerProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112C18: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80112C1C: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80112C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112C28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80112C2C: lw          $v0, 0x14($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X14);
    // 0x80112C30: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80112C34: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80112C38: bne         $v0, $zero, L_80112D28
    if (ctx->r2 != 0) {
        // 0x80112C3C: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_80112D28;
    }
    // 0x80112C3C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80112C40: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80112C44: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80112C48: addiu       $t2, $t2, 0xD40
    ctx->r10 = ADD32(ctx->r10, 0XD40);
    // 0x80112C4C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80112C50: addiu       $t1, $t1, -0x116C
    ctx->r9 = ADD32(ctx->r9, -0X116C);
    // 0x80112C54: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80112C58: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80112C5C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80112C60: lw          $v1, 0x8($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X8);
    // 0x80112C64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80112C68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80112C6C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80112C70: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80112C74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80112C78: addiu       $t3, $t3, -0x11AC
    ctx->r11 = ADD32(ctx->r11, -0X11AC);
    // 0x80112C7C: addiu       $t6, $t7, 0x3C
    ctx->r14 = ADD32(ctx->r15, 0X3C);
    // 0x80112C80: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
L_80112C84:
    // 0x80112C84: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80112C88: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80112C8C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80112C90: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80112C94: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80112C98: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x80112C9C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80112CA0: bne         $t7, $t6, L_80112C84
    if (ctx->r15 != ctx->r14) {
        // 0x80112CA4: sw          $t9, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r25;
            goto L_80112C84;
    }
    // 0x80112CA4: sw          $t9, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r25;
    // 0x80112CA8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80112CAC: sw          $t9, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r25;
    // 0x80112CB0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80112CB4: sw          $t8, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r24;
    // 0x80112CB8: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80112CBC: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80112CC0: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x80112CC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80112CC8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80112CCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80112CD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80112CD4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80112CD8: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80112CDC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80112CE0: nop

    // 0x80112CE4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80112CE8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80112CEC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80112CF0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80112CF4: nop

    // 0x80112CF8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80112CFC: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80112D00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80112D04: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80112D08: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x80112D0C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80112D10: nop

    // 0x80112D14: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80112D18: nop

    // 0x80112D1C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80112D20: b           L_80112EA4
    // 0x80112D24: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
        goto L_80112EA4;
    // 0x80112D24: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
L_80112D28:
    // 0x80112D28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80112D2C: lw          $t5, 0x17E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X17E0);
    // 0x80112D30: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80112D34: addiu       $a3, $a3, -0x10C8
    ctx->r7 = ADD32(ctx->r7, -0X10C8);
    // 0x80112D38: bne         $t5, $v0, L_80112D48
    if (ctx->r13 != ctx->r2) {
        // 0x80112D3C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80112D48;
    }
    // 0x80112D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112D40: b           L_80112D4C
    // 0x80112D44: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
        goto L_80112D4C;
    // 0x80112D44: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_80112D48:
    // 0x80112D48: addiu       $t0, $v0, 0x3B
    ctx->r8 = ADD32(ctx->r2, 0X3B);
L_80112D4C:
    // 0x80112D4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80112D50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80112D54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80112D58: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80112D5C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80112D60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80112D64: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80112D68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80112D6C: addiu       $t1, $t1, -0x116C
    ctx->r9 = ADD32(ctx->r9, -0X116C);
    // 0x80112D70: addiu       $t2, $t2, 0xD40
    ctx->r10 = ADD32(ctx->r10, 0XD40);
    // 0x80112D74: addiu       $t3, $t3, -0x11AC
    ctx->r11 = ADD32(ctx->r11, -0X11AC);
    // 0x80112D78: addiu       $a2, $a2, 0x17C8
    ctx->r6 = ADD32(ctx->r6, 0X17C8);
    // 0x80112D7C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80112D80:
    // 0x80112D80: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80112D84: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80112D88: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80112D8C: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x80112D90: mflo        $a0
    ctx->r4 = lo;
    // 0x80112D94: bne         $v0, $zero, L_80112DA0
    if (ctx->r2 != 0) {
        // 0x80112D98: nop
    
            goto L_80112DA0;
    }
    // 0x80112D98: nop

    // 0x80112D9C: break       7
    do_break(2148609436);
L_80112DA0:
    // 0x80112DA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80112DA4: bne         $v0, $at, L_80112DB8
    if (ctx->r2 != ctx->r1) {
        // 0x80112DA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80112DB8;
    }
    // 0x80112DA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80112DAC: bne         $t0, $at, L_80112DB8
    if (ctx->r8 != ctx->r1) {
        // 0x80112DB0: nop
    
            goto L_80112DB8;
    }
    // 0x80112DB0: nop

    // 0x80112DB4: break       6
    do_break(2148609460);
L_80112DB8:
    // 0x80112DB8: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80112DBC: mflo        $t8
    ctx->r24 = lo;
    // 0x80112DC0: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80112DC4: beql        $a0, $t9, L_80112E98
    if (ctx->r4 == ctx->r25) {
        // 0x80112DC8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80112E98;
    }
    goto skip_0;
    // 0x80112DC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80112DCC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80112DD0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80112DD4: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x80112DD8: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x80112DDC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80112DE0: addiu       $t8, $t9, 0x3C
    ctx->r24 = ADD32(ctx->r25, 0X3C);
    // 0x80112DE4: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
L_80112DE8:
    // 0x80112DE8: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80112DEC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80112DF0: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80112DF4: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80112DF8: lw          $t6, -0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X8);
    // 0x80112DFC: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
    // 0x80112E00: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x80112E04: bne         $t9, $t8, L_80112DE8
    if (ctx->r25 != ctx->r24) {
        // 0x80112E08: sw          $t7, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r15;
            goto L_80112DE8;
    }
    // 0x80112E08: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x80112E0C: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80112E10: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80112E14: sw          $t7, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r15;
    // 0x80112E18: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x80112E1C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x80112E20: sw          $t6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r14;
    // 0x80112E24: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x80112E28: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80112E2C: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x80112E30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80112E34: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80112E38: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80112E3C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80112E40: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80112E44: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80112E48: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80112E4C: nop

    // 0x80112E50: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80112E54: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80112E58: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80112E5C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80112E60: nop

    // 0x80112E64: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80112E68: sub.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80112E6C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80112E70: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80112E74: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80112E78: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80112E7C: nop

    // 0x80112E80: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80112E84: nop

    // 0x80112E88: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80112E8C: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
    // 0x80112E90: sb          $a0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r4;
    // 0x80112E94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80112E98:
    // 0x80112E98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80112E9C: bne         $a1, $t4, L_80112D80
    if (ctx->r5 != ctx->r12) {
        // 0x80112EA0: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_80112D80;
    }
    // 0x80112EA0: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
L_80112EA4:
    // 0x80112EA4: jal         0x800CCF00
    // 0x80112EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_0;
    // 0x80112EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80112EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112EB4: jr          $ra
    // 0x80112EB8: nop

    return;
    // 0x80112EB8: nop

;}
RECOMP_FUNC void ftLinkSpecialHiMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163D94: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80163D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163D9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80163DA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80163DA4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80163DA8: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x80163DAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80163DB0: lw          $t6, 0x17C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X17C);
    // 0x80163DB4: beql        $t6, $zero, L_80163EEC
    if (ctx->r14 == 0) {
        // 0x80163DB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80163EEC;
    }
    goto skip_0;
    // 0x80163DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80163DBC: lw          $t7, 0xB18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XB18);
    // 0x80163DC0: bnel        $t7, $zero, L_80163EEC
    if (ctx->r15 != 0) {
        // 0x80163DC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80163EEC;
    }
    goto skip_1;
    // 0x80163DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80163DC8: jal         0x80103378
    // 0x80163DCC: sw          $zero, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = 0;
    efManagerLinkSpinAttackMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80163DCC: sw          $zero, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = 0;
    after_0:
    // 0x80163DD0: beql        $v0, $zero, L_80163DE8
    if (ctx->r2 == 0) {
        // 0x80163DD4: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_80163DE8;
    }
    goto skip_2;
    // 0x80163DD4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80163DD8: lbu         $t9, 0x18F($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X18F);
    // 0x80163DDC: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80163DE0: sb          $t0, 0x18F($s1)
    MEM_B(0X18F, ctx->r17) = ctx->r8;
    // 0x80163DE4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80163DE8:
    // 0x80163DE8: bnel        $t1, $zero, L_80163EEC
    if (ctx->r9 != 0) {
        // 0x80163DEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80163EEC;
    }
    goto skip_3;
    // 0x80163DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80163DF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80163DF4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80163DF8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80163DFC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80163E00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80163E04: jal         0x800EDF24
    // 0x80163E08: lw          $a0, 0x8E8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_1;
    // 0x80163E08: lw          $a0, 0x8E8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8E8);
    after_1:
    // 0x80163E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80163E10: jal         0x8016CB1C
    // 0x80163E14: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    wpLinkSpinAttackMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x80163E14: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80163E18: beq         $v0, $zero, L_80163EE8
    if (ctx->r2 == 0) {
        // 0x80163E1C: sw          $v0, 0xB18($s1)
        MEM_W(0XB18, ctx->r17) = ctx->r2;
            goto L_80163EE8;
    }
    // 0x80163E1C: sw          $v0, 0xB18($s1)
    MEM_W(0XB18, ctx->r17) = ctx->r2;
    // 0x80163E20: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80163E24: sw          $zero, 0x100($v1)
    MEM_W(0X100, ctx->r3) = 0;
    // 0x80163E28: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80163E2C: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80163E30: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80163E34: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80163E38: nop

    // 0x80163E3C: sh          $t5, 0x29C($v1)
    MEM_H(0X29C, ctx->r3) = ctx->r13;
    // 0x80163E40: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80163E44: lwc1        $f8, 0x20($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80163E48: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80163E4C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80163E50: nop

    // 0x80163E54: sh          $t8, 0x2A4($v1)
    MEM_H(0X2A4, ctx->r3) = ctx->r24;
    // 0x80163E58: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80163E5C: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80163E60: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80163E64: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80163E68: nop

    // 0x80163E6C: sh          $t1, 0x29E($v1)
    MEM_H(0X29E, ctx->r3) = ctx->r9;
    // 0x80163E70: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80163E74: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80163E78: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80163E7C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80163E80: nop

    // 0x80163E84: sh          $t4, 0x2A6($v1)
    MEM_H(0X2A6, ctx->r3) = ctx->r12;
    // 0x80163E88: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80163E8C: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80163E90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80163E94: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80163E98: nop

    // 0x80163E9C: sh          $t7, 0x2A0($v1)
    MEM_H(0X2A0, ctx->r3) = ctx->r15;
    // 0x80163EA0: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80163EA4: lwc1        $f16, 0x20($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80163EA8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80163EAC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80163EB0: nop

    // 0x80163EB4: sh          $t0, 0x2A8($v1)
    MEM_H(0X2A8, ctx->r3) = ctx->r8;
    // 0x80163EB8: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80163EBC: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80163EC0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80163EC4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80163EC8: nop

    // 0x80163ECC: sh          $t3, 0x2A2($v1)
    MEM_H(0X2A2, ctx->r3) = ctx->r11;
    // 0x80163ED0: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80163ED4: lwc1        $f8, 0x20($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80163ED8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80163EDC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80163EE0: nop

    // 0x80163EE4: sh          $t6, 0x2AA($v1)
    MEM_H(0X2AA, ctx->r3) = ctx->r14;
L_80163EE8:
    // 0x80163EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80163EEC:
    // 0x80163EEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80163EF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80163EF4: jr          $ra
    // 0x80163EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80163EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnVSItemSwitchCheckAllTogglesOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132988: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013298C: lw          $t6, 0x3424($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3424);
    // 0x80132990: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132994: beq         $t6, $zero, L_801329A4
    if (ctx->r14 == 0) {
        // 0x80132998: nop
    
            goto L_801329A4;
    }
    // 0x80132998: nop

    // 0x8013299C: jr          $ra
    // 0x801329A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801329A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801329A4:
    // 0x801329A4: lw          $t7, 0x3428($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3428);
    // 0x801329A8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801329AC: beq         $t7, $zero, L_801329BC
    if (ctx->r15 == 0) {
        // 0x801329B0: nop
    
            goto L_801329BC;
    }
    // 0x801329B0: nop

    // 0x801329B4: jr          $ra
    // 0x801329B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801329B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801329BC:
    // 0x801329BC: lw          $t8, 0x342C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X342C);
    // 0x801329C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801329C4: addiu       $v1, $v1, 0x3430
    ctx->r3 = ADD32(ctx->r3, 0X3430);
    // 0x801329C8: beq         $t8, $zero, L_801329D8
    if (ctx->r24 == 0) {
        // 0x801329CC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801329D8;
    }
    // 0x801329CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801329D0: jr          $ra
    // 0x801329D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801329D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801329D8:
    // 0x801329D8: addiu       $v0, $v0, 0x3460
    ctx->r2 = ADD32(ctx->r2, 0X3460);
    // 0x801329DC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_801329E0:
    // 0x801329E0: beql        $t9, $zero, L_801329F4
    if (ctx->r25 == 0) {
        // 0x801329E4: lw          $t0, 0x4($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X4);
            goto L_801329F4;
    }
    goto skip_0;
    // 0x801329E4: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x801329E8: jr          $ra
    // 0x801329EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801329EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801329F0: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
L_801329F4:
    // 0x801329F4: beql        $t0, $zero, L_80132A08
    if (ctx->r8 == 0) {
        // 0x801329F8: lw          $t1, 0x8($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X8);
            goto L_80132A08;
    }
    goto skip_1;
    // 0x801329F8: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x801329FC: jr          $ra
    // 0x80132A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132A04: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
L_80132A08:
    // 0x80132A08: beql        $t1, $zero, L_80132A1C
    if (ctx->r9 == 0) {
        // 0x80132A0C: lw          $t2, 0xC($v1)
        ctx->r10 = MEM_W(ctx->r3, 0XC);
            goto L_80132A1C;
    }
    goto skip_2;
    // 0x80132A0C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x80132A10: jr          $ra
    // 0x80132A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132A14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132A18: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
L_80132A1C:
    // 0x80132A1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80132A20: beq         $t2, $zero, L_80132A30
    if (ctx->r10 == 0) {
        // 0x80132A24: nop
    
            goto L_80132A30;
    }
    // 0x80132A24: nop

    // 0x80132A28: jr          $ra
    // 0x80132A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132A30:
    // 0x80132A30: bnel        $v1, $v0, L_801329E0
    if (ctx->r3 != ctx->r2) {
        // 0x80132A34: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_801329E0;
    }
    goto skip_3;
    // 0x80132A34: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x80132A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132A3C: jr          $ra
    // 0x80132A40: nop

    return;
    // 0x80132A40: nop

;}
RECOMP_FUNC void mnVSRecordRankingHighlightProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801346D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801346DC: lw          $t6, 0x6C18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C18);
    // 0x801346E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801346E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801346E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801346EC: bne         $t6, $at, L_80134858
    if (ctx->r14 != ctx->r1) {
        // 0x801346F0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80134858;
    }
    // 0x801346F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801346F4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801346F8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801346FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134700: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80134704: lui         $ra, 0xE300
    ctx->r31 = S32(0XE300 << 16);
    // 0x80134708: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013470C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134710: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134714: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134718: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013471C: ori         $ra, $ra, 0xA01
    ctx->r31 = ctx->r31 | 0XA01;
    // 0x80134720: lui         $t7, 0x2700
    ctx->r15 = S32(0X2700 << 16);
    // 0x80134724: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134728: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013472C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134730: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134734: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134738: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8013473C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80134740: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80134744: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80134748: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013474C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80134750: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134754: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80134758: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8013475C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134760: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134764: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80134768: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8013476C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80134770: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80134774: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134778: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8013477C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80134780: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134784: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134788: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x8013478C: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80134790: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80134794: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80134798: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013479C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801347A0: lui         $at, 0xF649
    ctx->r1 = S32(0XF649 << 16);
    // 0x801347A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801347A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801347AC: lw          $t7, 0x6CB8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6CB8);
    // 0x801347B0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801347B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801347B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801347BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801347C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801347C4: addiu       $t9, $t8, 0x4A
    ctx->r25 = ADD32(ctx->r24, 0X4A);
    // 0x801347C8: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x801347CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801347D0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801347D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801347D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801347DC: lw          $t9, 0x6CB8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CB8);
    // 0x801347E0: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x801347E4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801347E8: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x801347EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801347F0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x801347F4: addiu       $t7, $t6, 0x3E
    ctx->r15 = ADD32(ctx->r14, 0X3E);
    // 0x801347F8: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x801347FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80134800: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80134804: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80134808: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013480C: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80134810: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80134814: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134818: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013481C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134820: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134824: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134828: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8013482C: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80134830: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134834: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134838: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013483C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80134840: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134844: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134848: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013484C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134850: jal         0x800CCEAC
    // 0x80134854: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80134854: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    after_0:
L_80134858:
    // 0x80134858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013485C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134860: jr          $ra
    // 0x80134864: nop

    return;
    // 0x80134864: nop

;}
RECOMP_FUNC void unref_8001810C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001810C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80018110: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80018114: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80018118: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001811C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80018120: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80018124: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80018128: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001812C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018130: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80018134: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80018138: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001813C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80018140: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80018144: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80018148: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x8001814C: addiu       $s7, $s7, 0x72C0
    ctx->r23 = ADD32(ctx->r23, 0X72C0);
    // 0x80018150: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    // 0x80018154: addiu       $s0, $s0, 0x65B4
    ctx->r16 = ADD32(ctx->r16, 0X65B4);
    // 0x80018158: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001815C: lui         $s6, 0xDE00
    ctx->r22 = S32(0XDE00 << 16);
    // 0x80018160: lui         $fp, 0xDF00
    ctx->r30 = S32(0XDF00 << 16);
    // 0x80018164: lw          $s5, 0x74($t6)
    ctx->r21 = MEM_W(ctx->r14, 0X74);
L_80018168:
    // 0x80018168: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8001816C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80018170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80018174: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x80018178: bne         $v1, $s1, L_8001818C
    if (ctx->r3 != ctx->r17) {
        // 0x8001817C: addiu       $t8, $s1, 0x8
        ctx->r24 = ADD32(ctx->r17, 0X8);
            goto L_8001818C;
    }
    // 0x8001817C: addiu       $t8, $s1, 0x8
    ctx->r24 = ADD32(ctx->r17, 0X8);
    // 0x80018180: addiu       $t7, $s1, -0x8
    ctx->r15 = ADD32(ctx->r17, -0X8);
    // 0x80018184: b           L_800181F8
    // 0x80018188: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_800181F8;
    // 0x80018188: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8001818C:
    // 0x8001818C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80018190: addiu       $v0, $v1, -0x8
    ctx->r2 = ADD32(ctx->r3, -0X8);
    // 0x80018194: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80018198: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8001819C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800181A0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800181A4: jal         0x80016338
    // 0x800181A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_80016338(rdram, ctx);
        goto after_0;
    // 0x800181A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x800181AC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800181B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800181B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800181B8: addiu       $t0, $s1, 0x8
    ctx->r8 = ADD32(ctx->r17, 0X8);
    // 0x800181BC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800181C0: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
    // 0x800181C4: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800181C8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800181CC: jal         0x8001783C
    // 0x800181D0: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    gcRunFuncCamera(rdram, ctx);
        goto after_1;
    // 0x800181D0: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    after_1:
    // 0x800181D4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800181D8: lui         $t4, 0xDE01
    ctx->r12 = S32(0XDE01 << 16);
    // 0x800181DC: addiu       $t3, $s1, 0x8
    ctx->r11 = ADD32(ctx->r17, 0X8);
    // 0x800181E0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800181E4: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800181E8: sw          $fp, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r30;
    // 0x800181EC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800181F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800181F4: sw          $t5, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r13;
L_800181F8:
    // 0x800181F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800181FC: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x80018200: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80018204: bne         $at, $zero, L_80018168
    if (ctx->r1 != 0) {
        // 0x80018208: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80018168;
    }
    // 0x80018208: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001820C: jal         0x800053CC
    // 0x80018210: nop

    func_800053CC(rdram, ctx);
        goto after_2;
    // 0x80018210: nop

    after_2:
    // 0x80018214: jal         0x80004F78
    // 0x80018218: nop

    func_80004F78(rdram, ctx);
        goto after_3;
    // 0x80018218: nop

    after_3:
    // 0x8001821C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80018220: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80018224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80018228: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8001822C: jal         0x8001663C
    // 0x80018230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001663C(rdram, ctx);
        goto after_4;
    // 0x80018230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80018234: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80018238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001823C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80018240: addiu       $t6, $s1, 0x8
    ctx->r14 = ADD32(ctx->r17, 0X8);
    // 0x80018244: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80018248: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
    // 0x8001824C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80018250: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80018254: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80018258: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8001825C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80018260: jal         0x80016EDC
    // 0x80018264: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_5;
    // 0x80018264: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    after_5:
    // 0x80018268: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8001826C: lui         $t2, 0xDE01
    ctx->r10 = S32(0XDE01 << 16);
    // 0x80018270: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80018274: addiu       $t1, $s1, 0x8
    ctx->r9 = ADD32(ctx->r17, 0X8);
    // 0x80018278: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8001827C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80018280: sw          $fp, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r30;
    // 0x80018284: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x80018288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001828C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80018290: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80018294: jal         0x8001783C
    // 0x80018298: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    gcRunFuncCamera(rdram, ctx);
        goto after_6;
    // 0x80018298: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    after_6:
    // 0x8001829C: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x800182A0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800182A4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800182A8: addiu       $v0, $v0, 0x65C0
    ctx->r2 = ADD32(ctx->r2, 0X65C0);
    // 0x800182AC: addiu       $s0, $s0, 0x65B4
    ctx->r16 = ADD32(ctx->r16, 0X65B4);
    // 0x800182B0: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
L_800182B4:
    // 0x800182B4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800182B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800182BC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800182C0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800182C4: sw          $t5, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r13;
    // 0x800182C8: bne         $s0, $v0, L_800182B4
    if (ctx->r16 != ctx->r2) {
        // 0x800182CC: sw          $t5, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r13;
            goto L_800182B4;
    }
    // 0x800182CC: sw          $t5, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r13;
    // 0x800182D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800182D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800182D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800182DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800182E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800182E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800182E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800182EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800182F0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800182F4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800182F8: jr          $ra
    // 0x800182FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800182FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnMapsMakeIconsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013372C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133730: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133734: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133738: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013373C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80133740: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133744: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133748: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013374C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133750: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133754: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133758: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013375C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133760: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133764: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133768: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013376C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133770: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133774: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133778: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013377C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133784: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133788: jal         0x8000B93C
    // 0x8013378C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013378C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133790: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133794: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133798: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013379C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801337A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801337A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801337A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801337AC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801337B0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801337B4: jal         0x80007080
    // 0x801337B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801337B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801337BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801337C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801337C4: jr          $ra
    // 0x801337C8: nop

    return;
    // 0x801337C8: nop

;}
RECOMP_FUNC void ftManagerInitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D79F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D79F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D79F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D79FC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800D7A00: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800D7A04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D7A08: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x800D7A0C: sw          $t6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r14;
    // 0x800D7A10: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x800D7A14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D7A18: lw          $a2, 0x9C8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X9C8);
    // 0x800D7A1C: beq         $t8, $at, L_800D7A4C
    if (ctx->r24 == ctx->r1) {
        // 0x800D7A20: sw          $t7, 0x2C($v1)
        MEM_W(0X2C, ctx->r3) = ctx->r15;
            goto L_800D7A4C;
    }
    // 0x800D7A20: sw          $t7, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r15;
    // 0x800D7A24: lbu         $t4, 0xD($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XD);
    // 0x800D7A28: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800D7A2C: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x800D7A30: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800D7A34: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800D7A38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800D7A3C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800D7A40: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800D7A44: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800D7A48: sw          $t7, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r15;
L_800D7A4C:
    // 0x800D7A4C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800D7A50: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D7A54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D7A58: bne         $t7, $at, L_800D7A6C
    if (ctx->r15 != ctx->r1) {
        // 0x800D7A5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D7A6C;
    }
    // 0x800D7A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7A60: addiu       $t8, $zero, 0x37
    ctx->r24 = ADD32(0, 0X37);
    // 0x800D7A64: b           L_800D7A74
    // 0x800D7A68: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
        goto L_800D7A74;
    // 0x800D7A68: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
L_800D7A6C:
    // 0x800D7A6C: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
    // 0x800D7A70: sw          $t4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r12;
L_800D7A74:
    // 0x800D7A74: lbu         $t3, 0x192($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X192);
    // 0x800D7A78: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x800D7A7C: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x800D7A80: andi        $t5, $t3, 0xFFFD
    ctx->r13 = ctx->r11 & 0XFFFD;
    // 0x800D7A84: sb          $t5, 0x192($v1)
    MEM_B(0X192, ctx->r3) = ctx->r13;
    // 0x800D7A88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D7A8C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D7A90: jal         0x800D9444
    // 0x800D7A94: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_0;
    // 0x800D7A94: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800D7A98: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D7A9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D7AA0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800D7AA4: lbu         $t9, 0x18C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18C);
    // 0x800D7AA8: lbu         $t7, 0x18D($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18D);
    // 0x800D7AAC: lbu         $t4, 0x18F($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X18F);
    // 0x800D7AB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D7AB4: andi        $t6, $t9, 0xFFFB
    ctx->r14 = ctx->r25 & 0XFFFB;
    // 0x800D7AB8: sb          $t6, 0x18C($v1)
    MEM_B(0X18C, ctx->r3) = ctx->r14;
    // 0x800D7ABC: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x800D7AC0: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x800D7AC4: andi        $t6, $t5, 0xEF
    ctx->r14 = ctx->r13 & 0XEF;
    // 0x800D7AC8: sb          $t8, 0x18D($v1)
    MEM_B(0X18D, ctx->r3) = ctx->r24;
    // 0x800D7ACC: lb          $t9, 0x18D($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X18D);
    // 0x800D7AD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D7AD4: sb          $t5, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r13;
    // 0x800D7AD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7ADC: lbu         $t8, 0x192($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X192);
    // 0x800D7AE0: andi        $t7, $t6, 0xF7
    ctx->r15 = ctx->r14 & 0XF7;
    // 0x800D7AE4: sb          $t6, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r14;
    // 0x800D7AE8: lb          $t3, 0x18C($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X18C);
    // 0x800D7AEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800D7AF0: sb          $t7, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r15;
    // 0x800D7AF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D7AF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D7AFC: andi        $t7, $t9, 0xFF9F
    ctx->r15 = ctx->r25 & 0XFF9F;
    // 0x800D7B00: andi        $t4, $t8, 0xFFEF
    ctx->r12 = ctx->r24 & 0XFFEF;
    // 0x800D7B04: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D7B08: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D7B0C: andi        $t8, $t7, 0xF7
    ctx->r24 = ctx->r15 & 0XF7;
    // 0x800D7B10: sb          $t7, 0x18D($v1)
    MEM_B(0X18D, ctx->r3) = ctx->r15;
    // 0x800D7B14: andi        $t5, $t3, 0xFFFC
    ctx->r13 = ctx->r11 & 0XFFFC;
    // 0x800D7B18: addiu       $v0, $v0, 0xD90
    ctx->r2 = ADD32(ctx->r2, 0XD90);
    // 0x800D7B1C: sb          $zero, 0x148($v1)
    MEM_B(0X148, ctx->r3) = 0;
    // 0x800D7B20: sw          $zero, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = 0;
    // 0x800D7B24: sw          $zero, 0x160($v1)
    MEM_W(0X160, ctx->r3) = 0;
    // 0x800D7B28: sw          $zero, 0x164($v1)
    MEM_W(0X164, ctx->r3) = 0;
    // 0x800D7B2C: sw          $zero, 0x168($v1)
    MEM_W(0X168, ctx->r3) = 0;
    // 0x800D7B30: sw          $zero, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = 0;
    // 0x800D7B34: sw          $zero, 0x170($v1)
    MEM_W(0X170, ctx->r3) = 0;
    // 0x800D7B38: sw          $zero, 0x7AC($v1)
    MEM_W(0X7AC, ctx->r3) = 0;
    // 0x800D7B3C: sw          $zero, 0x7B0($v1)
    MEM_W(0X7B0, ctx->r3) = 0;
    // 0x800D7B40: sh          $zero, 0x7B8($v1)
    MEM_H(0X7B8, ctx->r3) = 0;
    // 0x800D7B44: sw          $zero, 0x7BC($v1)
    MEM_W(0X7BC, ctx->r3) = 0;
    // 0x800D7B48: sw          $zero, 0x7C8($v1)
    MEM_W(0X7C8, ctx->r3) = 0;
    // 0x800D7B4C: sw          $zero, 0x7DC($v1)
    MEM_W(0X7DC, ctx->r3) = 0;
    // 0x800D7B50: sw          $zero, 0x7F0($v1)
    MEM_W(0X7F0, ctx->r3) = 0;
    // 0x800D7B54: sw          $t1, 0x80C($v1)
    MEM_W(0X80C, ctx->r3) = ctx->r9;
    // 0x800D7B58: sw          $zero, 0x820($v1)
    MEM_W(0X820, ctx->r3) = 0;
    // 0x800D7B5C: sw          $zero, 0x824($v1)
    MEM_W(0X824, ctx->r3) = 0;
    // 0x800D7B60: sh          $zero, 0x810($v1)
    MEM_H(0X810, ctx->r3) = 0;
    // 0x800D7B64: sw          $zero, 0x814($v1)
    MEM_W(0X814, ctx->r3) = 0;
    // 0x800D7B68: sw          $zero, 0x818($v1)
    MEM_W(0X818, ctx->r3) = 0;
    // 0x800D7B6C: sw          $zero, 0x804($v1)
    MEM_W(0X804, ctx->r3) = 0;
    // 0x800D7B70: sw          $zero, 0x5A4($v1)
    MEM_W(0X5A4, ctx->r3) = 0;
    // 0x800D7B74: sw          $zero, 0x5A8($v1)
    MEM_W(0X5A8, ctx->r3) = 0;
    // 0x800D7B78: sw          $zero, 0x5B0($v1)
    MEM_W(0X5B0, ctx->r3) = 0;
    // 0x800D7B7C: sw          $t0, 0x5B8($v1)
    MEM_W(0X5B8, ctx->r3) = ctx->r8;
    // 0x800D7B80: sw          $t0, 0x5B4($v1)
    MEM_W(0X5B4, ctx->r3) = ctx->r8;
    // 0x800D7B84: sw          $t0, 0x5AC($v1)
    MEM_W(0X5AC, ctx->r3) = ctx->r8;
    // 0x800D7B88: sw          $zero, 0x278($v1)
    MEM_W(0X278, ctx->r3) = 0;
    // 0x800D7B8C: sw          $zero, 0x840($v1)
    MEM_W(0X840, ctx->r3) = 0;
    // 0x800D7B90: sw          $zero, 0x844($v1)
    MEM_W(0X844, ctx->r3) = 0;
    // 0x800D7B94: sb          $t4, 0x192($v1)
    MEM_B(0X192, ctx->r3) = ctx->r12;
    // 0x800D7B98: sw          $zero, 0x84C($v1)
    MEM_W(0X84C, ctx->r3) = 0;
    // 0x800D7B9C: sb          $t5, 0x18C($v1)
    MEM_B(0X18C, ctx->r3) = ctx->r13;
    // 0x800D7BA0: sw          $zero, 0x7D8($v1)
    MEM_W(0X7D8, ctx->r3) = 0;
    // 0x800D7BA4: sw          $zero, 0x850($v1)
    MEM_W(0X850, ctx->r3) = 0;
    // 0x800D7BA8: sb          $t8, 0x18D($v1)
    MEM_B(0X18D, ctx->r3) = ctx->r24;
    // 0x800D7BAC: swc1        $f0, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BB0: swc1        $f0, 0x7A0($v1)
    MEM_W(0X7A0, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BB4: swc1        $f0, 0x7B4($v1)
    MEM_W(0X7B4, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BB8: swc1        $f0, 0x7C0($v1)
    MEM_W(0X7C0, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BBC: swc1        $f0, 0x7EC($v1)
    MEM_W(0X7EC, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BC0: swc1        $f0, 0x7E8($v1)
    MEM_W(0X7E8, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BC4: swc1        $f0, 0x7E4($v1)
    MEM_W(0X7E4, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BC8: swc1        $f0, 0x7E0($v1)
    MEM_W(0X7E0, ctx->r3) = ctx->f0.u32l;
    // 0x800D7BCC: swc1        $f4, 0x7A4($v1)
    MEM_W(0X7A4, ctx->r3) = ctx->f4.u32l;
    // 0x800D7BD0: swc1        $f6, 0x7A8($v1)
    MEM_W(0X7A8, ctx->r3) = ctx->f6.u32l;
    // 0x800D7BD4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800D7BD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D7BDC: addiu       $a1, $v1, 0xEC
    ctx->r5 = ADD32(ctx->r3, 0XEC);
    // 0x800D7BE0: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
    // 0x800D7BE4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800D7BE8: addiu       $a3, $v1, 0xF4
    ctx->r7 = ADD32(ctx->r3, 0XF4);
    // 0x800D7BEC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x800D7BF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800D7BF4: lbu         $t9, 0x18F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18F);
    // 0x800D7BF8: lbu         $t7, 0x190($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X190);
    // 0x800D7BFC: lbu         $t3, 0x192($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X192);
    // 0x800D7C00: andi        $t6, $t9, 0xFFFE
    ctx->r14 = ctx->r25 & 0XFFFE;
    // 0x800D7C04: lhu         $t9, 0x28E($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X28E);
    // 0x800D7C08: sb          $t6, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r14;
    // 0x800D7C0C: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x800D7C10: andi        $t6, $t9, 0xFC00
    ctx->r14 = ctx->r25 & 0XFC00;
    // 0x800D7C14: sh          $t6, 0x28E($v1)
    MEM_H(0X28E, ctx->r3) = ctx->r14;
    // 0x800D7C18: lbu         $t7, 0x28E($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X28E);
    // 0x800D7C1C: andi        $t5, $t3, 0xFFF7
    ctx->r13 = ctx->r11 & 0XFFF7;
    // 0x800D7C20: sb          $t5, 0x192($v1)
    MEM_B(0X192, ctx->r3) = ctx->r13;
    // 0x800D7C24: andi        $t5, $t7, 0xFFFB
    ctx->r13 = ctx->r15 & 0XFFFB;
    // 0x800D7C28: sh          $zero, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = 0;
    // 0x800D7C2C: sb          $t5, 0x28E($v1)
    MEM_B(0X28E, ctx->r3) = ctx->r13;
    // 0x800D7C30: lw          $v0, 0x28C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28C);
    // 0x800D7C34: andi        $t9, $t5, 0xF7
    ctx->r25 = ctx->r13 & 0XF7;
    // 0x800D7C38: sb          $t8, 0x190($v1)
    MEM_B(0X190, ctx->r3) = ctx->r24;
    // 0x800D7C3C: sll         $v0, $v0, 21
    ctx->r2 = S32(ctx->r2 << 21);
    // 0x800D7C40: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800D7C44: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800D7C48: andi        $t3, $t4, 0x8
    ctx->r11 = ctx->r12 & 0X8;
    // 0x800D7C4C: or          $t4, $t3, $t9
    ctx->r12 = ctx->r11 | ctx->r25;
    // 0x800D7C50: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800D7C54: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800D7C58: andi        $t5, $t4, 0xEF
    ctx->r13 = ctx->r12 & 0XEF;
    // 0x800D7C5C: or          $t3, $t8, $t5
    ctx->r11 = ctx->r24 | ctx->r13;
    // 0x800D7C60: sb          $t4, 0x28E($v1)
    MEM_B(0X28E, ctx->r3) = ctx->r12;
    // 0x800D7C64: sb          $t3, 0x28E($v1)
    MEM_B(0X28E, ctx->r3) = ctx->r11;
    // 0x800D7C68: lhu         $t7, 0x28E($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X28E);
    // 0x800D7C6C: sb          $zero, 0x272($v1)
    MEM_B(0X272, ctx->r3) = 0;
    // 0x800D7C70: sb          $zero, 0x273($v1)
    MEM_B(0X273, ctx->r3) = 0;
    // 0x800D7C74: sb          $zero, 0x274($v1)
    MEM_B(0X274, ctx->r3) = 0;
    // 0x800D7C78: sh          $zero, 0x276($v1)
    MEM_H(0X276, ctx->r3) = 0;
    // 0x800D7C7C: sw          $zero, 0x288($v1)
    MEM_W(0X288, ctx->r3) = 0;
    // 0x800D7C80: sh          $zero, 0x290($v1)
    MEM_H(0X290, ctx->r3) = 0;
    // 0x800D7C84: sh          $zero, 0x82A($v1)
    MEM_H(0X82A, ctx->r3) = 0;
    // 0x800D7C88: sb          $zero, 0xA9E($v1)
    MEM_B(0XA9E, ctx->r3) = 0;
    // 0x800D7C8C: swc1        $f0, 0x82C($v1)
    MEM_W(0X82C, ctx->r3) = ctx->f0.u32l;
    // 0x800D7C90: sh          $t7, 0x828($v1)
    MEM_H(0X828, ctx->r3) = ctx->r15;
    // 0x800D7C94: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x800D7C98: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800D7C9C: sw          $t5, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r13;
    // 0x800D7CA0: lw          $t8, 0x8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X8);
    // 0x800D7CA4: sw          $t8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r24;
    // 0x800D7CA8: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800D7CAC: sw          $t5, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r13;
    // 0x800D7CB0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x800D7CB4: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800D7CB8: addiu       $a2, $v1, 0xF0
    ctx->r6 = ADD32(ctx->r3, 0XF0);
    // 0x800D7CBC: addiu       $t4, $v1, 0xF8
    ctx->r12 = ADD32(ctx->r3, 0XF8);
    // 0x800D7CC0: swc1        $f0, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f0.u32l;
    // 0x800D7CC4: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x800D7CC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D7CCC: swc1        $f0, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f0.u32l;
    // 0x800D7CD0: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x800D7CD4: swc1        $f0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f0.u32l;
    // 0x800D7CD8: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x800D7CDC: beql        $t7, $at, L_800D7D78
    if (ctx->r15 == ctx->r1) {
        // 0x800D7CE0: sw          $t0, 0x14C($v1)
        MEM_W(0X14C, ctx->r3) = ctx->r8;
            goto L_800D7D78;
    }
    goto skip_0;
    // 0x800D7CE0: sw          $t0, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r8;
    skip_0:
    // 0x800D7CE4: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800D7CE8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800D7CEC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800D7CF0: jal         0x800F9348
    // 0x800D7CF4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckProjectFloor(rdram, ctx);
        goto after_1;
    // 0x800D7CF4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x800D7CF8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D7CFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D7D00: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D7D04: bne         $v0, $zero, L_800D7D10
    if (ctx->r2 != 0) {
        // 0x800D7D08: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_800D7D10;
    }
    // 0x800D7D08: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800D7D0C: sw          $t1, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = ctx->r9;
L_800D7D10:
    // 0x800D7D10: beq         $v0, $zero, L_800D7D64
    if (ctx->r2 == 0) {
        // 0x800D7D14: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_800D7D64;
    }
    // 0x800D7D14: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x800D7D18: lwc1        $f0, 0xF0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF0);
    // 0x800D7D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7D20: nop

    // 0x800D7D24: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800D7D28: nop

    // 0x800D7D2C: bc1fl       L_800D7D68
    if (!c1cs) {
        // 0x800D7D30: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800D7D68;
    }
    goto skip_1;
    // 0x800D7D30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_1:
    // 0x800D7D34: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800D7D38: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800D7D3C: beql        $t8, $at, L_800D7D68
    if (ctx->r24 == ctx->r1) {
        // 0x800D7D40: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800D7D68;
    }
    goto skip_2;
    // 0x800D7D40: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_2:
    // 0x800D7D44: sw          $zero, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = 0;
    // 0x800D7D48: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x800D7D4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D7D50: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800D7D54: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800D7D58: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x800D7D5C: b           L_800D7D7C
    // 0x800D7D60: swc1        $f18, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f18.u32l;
        goto L_800D7D7C;
    // 0x800D7D60: swc1        $f18, 0xF0($v1)
    MEM_W(0XF0, ctx->r3) = ctx->f18.u32l;
L_800D7D64:
    // 0x800D7D64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_800D7D68:
    // 0x800D7D68: sw          $t0, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r8;
    // 0x800D7D6C: b           L_800D7D7C
    // 0x800D7D70: sb          $t5, 0x148($v1)
    MEM_B(0X148, ctx->r3) = ctx->r13;
        goto L_800D7D7C;
    // 0x800D7D70: sb          $t5, 0x148($v1)
    MEM_B(0X148, ctx->r3) = ctx->r13;
    // 0x800D7D74: sw          $t0, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r8;
L_800D7D78:
    // 0x800D7D78: sb          $t3, 0x148($v1)
    MEM_B(0X148, ctx->r3) = ctx->r11;
L_800D7D7C:
    // 0x800D7D7C: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x800D7D80: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800D7D84: lw          $t7, 0x1C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X1C);
    // 0x800D7D88: sltiu       $at, $t4, 0x1B
    ctx->r1 = ctx->r12 < 0X1B ? 1 : 0;
    // 0x800D7D8C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800D7D90: sw          $t7, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r15;
    // 0x800D7D94: lw          $t6, 0x20($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X20);
    // 0x800D7D98: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800D7D9C: lw          $t7, 0x24($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X24);
    // 0x800D7DA0: beq         $at, $zero, L_800D7F0C
    if (ctx->r1 == 0) {
        // 0x800D7DA4: sw          $t7, 0x88($v1)
        MEM_W(0X88, ctx->r3) = ctx->r15;
            goto L_800D7F0C;
    }
    // 0x800D7DA4: sw          $t7, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r15;
    // 0x800D7DA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7DAC: addu        $at, $at, $t4
    gpr jr_addend_800D7DB4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800D7DB0: lw          $t4, -0x56C($at)
    ctx->r12 = ADD32(ctx->r1, -0X56C);
    // 0x800D7DB4: jr          $t4
    // 0x800D7DB8: nop

    switch (jr_addend_800D7DB4 >> 2) {
        case 0: goto L_800D7DCC; break;
        case 1: goto L_800D7F0C; break;
        case 2: goto L_800D7DE4; break;
        case 3: goto L_800D7DEC; break;
        case 4: goto L_800D7DF8; break;
        case 5: goto L_800D7E8C; break;
        case 6: goto L_800D7F0C; break;
        case 7: goto L_800D7E00; break;
        case 8: goto L_800D7E08; break;
        case 9: goto L_800D7F0C; break;
        case 10: goto L_800D7EB8; break;
        case 11: goto L_800D7F0C; break;
        case 12: goto L_800D7EC0; break;
        case 13: goto L_800D7DBC; break;
        case 14: goto L_800D7DCC; break;
        case 15: goto L_800D7F0C; break;
        case 16: goto L_800D7DE4; break;
        case 17: goto L_800D7DEC; break;
        case 18: goto L_800D7DF8; break;
        case 19: goto L_800D7E8C; break;
        case 20: goto L_800D7F0C; break;
        case 21: goto L_800D7E00; break;
        case 22: goto L_800D7E08; break;
        case 23: goto L_800D7F0C; break;
        case 24: goto L_800D7EB8; break;
        case 25: goto L_800D7F0C; break;
        case 26: goto L_800D7DD4; break;
        default: switch_error(__func__, 0x800D7DB4, 0x8012FA94);
    }
    // 0x800D7DB8: nop

L_800D7DBC:
    // 0x800D7DBC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D7DC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7DC4: nop

    // 0x800D7DC8: swc1        $f4, 0x7E4($v1)
    MEM_W(0X7E4, ctx->r3) = ctx->f4.u32l;
L_800D7DCC:
    // 0x800D7DCC: b           L_800D7F0C
    // 0x800D7DD0: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7DD0: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_800D7DD4:
    // 0x800D7DD4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x800D7DD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D7DDC: nop

    // 0x800D7DE0: swc1        $f6, 0x7E4($v1)
    MEM_W(0X7E4, ctx->r3) = ctx->f6.u32l;
L_800D7DE4:
    // 0x800D7DE4: b           L_800D7F0C
    // 0x800D7DE8: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7DE8: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_800D7DEC:
    // 0x800D7DEC: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
    // 0x800D7DF0: b           L_800D7F0C
    // 0x800D7DF4: sw          $zero, 0xAE0($v1)
    MEM_W(0XAE0, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7DF4: sw          $zero, 0xAE0($v1)
    MEM_W(0XAE0, ctx->r3) = 0;
L_800D7DF8:
    // 0x800D7DF8: b           L_800D7F0C
    // 0x800D7DFC: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7DFC: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_800D7E00:
    // 0x800D7E00: b           L_800D7F0C
    // 0x800D7E04: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7E04: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_800D7E08:
    // 0x800D7E08: lw          $t8, 0x20($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X20);
    // 0x800D7E0C: sw          $zero, 0xAE0($v1)
    MEM_W(0XAE0, ctx->r3) = 0;
    // 0x800D7E10: sw          $zero, 0xAE4($v1)
    MEM_W(0XAE4, ctx->r3) = 0;
    // 0x800D7E14: sw          $zero, 0xAE8($v1)
    MEM_W(0XAE8, ctx->r3) = 0;
    // 0x800D7E18: sw          $zero, 0xAEC($v1)
    MEM_W(0XAEC, ctx->r3) = 0;
    // 0x800D7E1C: sw          $zero, 0xAF0($v1)
    MEM_W(0XAF0, ctx->r3) = 0;
    // 0x800D7E20: sw          $zero, 0xAF8($v1)
    MEM_W(0XAF8, ctx->r3) = 0;
    // 0x800D7E24: sw          $t8, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r24;
    // 0x800D7E28: lw          $t5, 0x20($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X20);
    // 0x800D7E2C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800D7E30: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D7E34: bne         $v0, $t5, L_800D7E44
    if (ctx->r2 != ctx->r13) {
        // 0x800D7E38: lui         $t6, 0x0
        ctx->r14 = S32(0X0 << 16);
            goto L_800D7E44;
    }
    // 0x800D7E38: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x800D7E3C: b           L_800D7E48
    // 0x800D7E40: sw          $zero, 0xAF4($v1)
    MEM_W(0XAF4, ctx->r3) = 0;
        goto L_800D7E48;
    // 0x800D7E40: sw          $zero, 0xAF4($v1)
    MEM_W(0XAF4, ctx->r3) = 0;
L_800D7E44:
    // 0x800D7E44: sw          $t0, 0xAF4($v1)
    MEM_W(0XAF4, ctx->r3) = ctx->r8;
L_800D7E48:
    // 0x800D7E48: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800D7E4C: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x800D7E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7E54: bne         $v0, $t3, L_800D7F0C
    if (ctx->r2 != ctx->r11) {
        // 0x800D7E58: nop
    
            goto L_800D7F0C;
    }
    // 0x800D7E58: nop

    // 0x800D7E5C: lw          $t7, 0xADC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XADC);
    // 0x800D7E60: lw          $t9, 0x1074($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1074);
    // 0x800D7E64: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D7E68: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800D7E6C: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x800D7E70: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800D7E74: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800D7E78: addu        $t8, $v0, $t4
    ctx->r24 = ADD32(ctx->r2, ctx->r12);
    // 0x800D7E7C: jal         0x800E8EAC
    // 0x800D7E80: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_2;
    // 0x800D7E80: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    after_2:
    // 0x800D7E84: b           L_800D7F0C
    // 0x800D7E88: nop

        goto L_800D7F0C;
    // 0x800D7E88: nop

L_800D7E8C:
    // 0x800D7E8C: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
    // 0x800D7E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7E94: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x800D7E98: jal         0x800E8EAC
    // 0x800D7E9C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_3;
    // 0x800D7E9C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x800D7EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7EA4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800D7EA8: jal         0x800E8EAC
    // 0x800D7EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_4;
    // 0x800D7EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800D7EB0: b           L_800D7F0C
    // 0x800D7EB4: nop

        goto L_800D7F0C;
    // 0x800D7EB4: nop

L_800D7EB8:
    // 0x800D7EB8: b           L_800D7F0C
    // 0x800D7EBC: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
        goto L_800D7F0C;
    // 0x800D7EBC: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_800D7EC0:
    // 0x800D7EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D7EC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7EC8: addiu       $v0, $v1, 0xAE0
    ctx->r2 = ADD32(ctx->r3, 0XAE0);
    // 0x800D7ECC: sw          $v0, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r2;
    // 0x800D7ED0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800D7ED4: lw          $t5, 0xADC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XADC);
    // 0x800D7ED8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D7EDC: sb          $t1, 0x14($t5)
    MEM_B(0X14, ctx->r13) = ctx->r9;
    // 0x800D7EE0: lw          $t3, 0xADC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XADC);
    // 0x800D7EE4: sb          $t1, 0x15($t3)
    MEM_B(0X15, ctx->r11) = ctx->r9;
    // 0x800D7EE8: lw          $t9, 0xADC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XADC);
    // 0x800D7EEC: sb          $zero, 0x16($t9)
    MEM_B(0X16, ctx->r25) = 0;
    // 0x800D7EF0: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x800D7EF4: beq         $t6, $at, L_800D7F0C
    if (ctx->r14 == ctx->r1) {
        // 0x800D7EF8: nop
    
            goto L_800D7F0C;
    }
    // 0x800D7EF8: nop

    // 0x800D7EFC: jal         0x80158428
    // 0x800D7F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetNextAttackWait(rdram, ctx);
        goto after_5;
    // 0x800D7F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800D7F04: jal         0x80158634
    // 0x800D7F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetDefaultLineID(rdram, ctx);
        goto after_6;
    // 0x800D7F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800D7F0C:
    // 0x800D7F0C: jal         0x800E8518
    // 0x800D7F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamClearAttackCollAll(rdram, ctx);
        goto after_7;
    // 0x800D7F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800D7F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7F18: jal         0x800E880C
    // 0x800D7F1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusPartAll(rdram, ctx);
        goto after_8;
    // 0x800D7F1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x800D7F20: jal         0x800E98B0
    // 0x800D7F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamResetFighterColAnim(rdram, ctx);
        goto after_9;
    // 0x800D7F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800D7F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D7F2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D7F30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D7F34: jr          $ra
    // 0x800D7F38: nop

    return;
    // 0x800D7F38: nop

;}
RECOMP_FUNC void itRShellCommonClearAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A734: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017A738: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8017A73C: sw          $zero, 0x94($t7)
    MEM_W(0X94, ctx->r15) = 0;
    // 0x8017A740: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8017A744: jr          $ra
    // 0x8017A748: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
    return;
    // 0x8017A748: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
;}
RECOMP_FUNC void itBatMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801750B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801750BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801750C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801750C4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801750C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801750CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801750D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801750D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801750D8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801750DC: addiu       $a1, $a1, -0x6670
    ctx->r5 = ADD32(ctx->r5, -0X6670);
    // 0x801750E0: jal         0x8016E174
    // 0x801750E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801750E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801750E8: beq         $v0, $zero, L_80175128
    if (ctx->r2 == 0) {
        // 0x801750EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80175128;
    }
    // 0x801750EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801750F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801750F4: lwc1        $f4, -0x3328($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3328);
    // 0x801750F8: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x801750FC: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80175100: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x80175104: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80175108: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8017510C: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x80175110: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80175114: jal         0x80111EC0
    // 0x80175118: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80175118: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017511C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80175120: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80175124: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_80175128:
    // 0x80175128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017512C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80175130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80175134: jr          $ra
    // 0x80175138: nop

    return;
    // 0x80175138: nop

;}
RECOMP_FUNC void scSubsysFighterApplyVelTransN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8039069C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x803906A0: lw          $v1, 0x8EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8EC);
    // 0x803906A4: lwc1        $f6, 0x19C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X19C);
    // 0x803906A8: lw          $a1, 0x8E8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8E8);
    // 0x803906AC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x803906B0: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x803906B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x803906B8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x803906BC: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x803906C0: swc1        $f16, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f16.u32l;
    // 0x803906C4: lwc1        $f4, 0x1A0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x803906C8: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x803906CC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x803906D0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x803906D4: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x803906D8: swc1        $f8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f8.u32l;
    // 0x803906DC: lwc1        $f18, 0x1A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1A4);
    // 0x803906E0: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
    // 0x803906E4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x803906E8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x803906EC: jr          $ra
    // 0x803906F0: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x803906F0: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnVSResultsDrawResultsTimeRoyal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136290: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136294: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013629C: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x801362A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801362A4: bne         $v0, $at, L_801362BC
    if (ctx->r2 != ctx->r1) {
        // 0x801362A8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801362BC;
    }
    // 0x801362A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801362AC: jal         0x80134DA0
    // 0x801362B0: nop

    mnVSResultsMakeTint(rdram, ctx);
        goto after_0;
    // 0x801362B0: nop

    after_0:
    // 0x801362B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801362B8: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_801362BC:
    // 0x801362BC: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x801362C0: bnel        $v0, $at, L_801362E4
    if (ctx->r2 != ctx->r1) {
        // 0x801362C4: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_801362E4;
    }
    goto skip_0;
    // 0x801362C4: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    skip_0:
    // 0x801362C8: jal         0x8013549C
    // 0x801362CC: nop

    mnVSResultsMakeHeader(rdram, ctx);
        goto after_1;
    // 0x801362CC: nop

    after_1:
    // 0x801362D0: jal         0x8013569C
    // 0x801362D4: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    mnVSResultsMakeKOs(rdram, ctx);
        goto after_2;
    // 0x801362D4: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x801362D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801362DC: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801362E0: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
L_801362E4:
    // 0x801362E4: bnel        $v0, $at, L_80136300
    if (ctx->r2 != ctx->r1) {
        // 0x801362E8: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80136300;
    }
    goto skip_1;
    // 0x801362E8: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    skip_1:
    // 0x801362EC: jal         0x801358F0
    // 0x801362F0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    mnVSResultsMakeTKO(rdram, ctx);
        goto after_3;
    // 0x801362F0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_3:
    // 0x801362F4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801362F8: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801362FC: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
L_80136300:
    // 0x80136300: bnel        $v0, $at, L_8013631C
    if (ctx->r2 != ctx->r1) {
        // 0x80136304: addiu       $at, $zero, 0x10E
        ctx->r1 = ADD32(0, 0X10E);
            goto L_8013631C;
    }
    goto skip_2;
    // 0x80136304: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    skip_2:
    // 0x80136308: jal         0x80135D58
    // 0x8013630C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    mnVSResultsMakeBar(rdram, ctx);
        goto after_4;
    // 0x8013630C: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_4:
    // 0x80136310: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136314: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136318: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
L_8013631C:
    // 0x8013631C: bnel        $v0, $at, L_80136338
    if (ctx->r2 != ctx->r1) {
        // 0x80136320: addiu       $at, $zero, 0x122
        ctx->r1 = ADD32(0, 0X122);
            goto L_80136338;
    }
    goto skip_3;
    // 0x80136320: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    skip_3:
    // 0x80136324: jal         0x80135DCC
    // 0x80136328: nop

    mnVSResultsMakePointsRow(rdram, ctx);
        goto after_5;
    // 0x80136328: nop

    after_5:
    // 0x8013632C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136330: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136334: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
L_80136338:
    // 0x80136338: bnel        $v0, $at, L_8013634C
    if (ctx->r2 != ctx->r1) {
        // 0x8013633C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013634C;
    }
    goto skip_4;
    // 0x8013633C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80136340: jal         0x80136100
    // 0x80136344: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    mnVSResultsMakePlaceRow(rdram, ctx);
        goto after_6;
    // 0x80136344: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_6:
    // 0x80136348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013634C:
    // 0x8013634C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136350: jr          $ra
    // 0x80136354: nop

    return;
    // 0x80136354: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA98: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA9C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DAA0: addiu       $a1, $a1, 0x968
    ctx->r5 = ADD32(ctx->r5, 0X968);
    // 0x8018DAA4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018DAA8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018DAAC: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DAB0: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018DAB4: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018DAB8: addiu       $t1, $t6, 0x1EC
    ctx->r9 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DABC: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
L_8018DAC0:
    // 0x8018DAC0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAC4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DAC8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DACC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DAD0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DAD4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DAD8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DADC: bne         $t6, $t1, L_8018DAC0
    if (ctx->r14 != ctx->r9) {
        // 0x8018DAE0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DAC0;
    }
    // 0x8018DAE0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAE4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAE8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8018DAEC: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8018DAF0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAF4: lbu         $t9, 0x1D($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1D);
    // 0x8018DAF8: lbu         $t4, 0xF($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0XF);
    // 0x8018DAFC: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x8018DB00: andi        $t7, $t9, 0xFF7F
    ctx->r15 = ctx->r25 & 0XFF7F;
    // 0x8018DB04: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x8018DB08: sb          $t1, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r9;
    // 0x8018DB0C: sb          $t7, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r15;
    // 0x8018DB10: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x8018DB14: sb          $t4, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r12;
    // 0x8018DB18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8018DB1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018DB20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018DB24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8018DB28:
    // 0x8018DB28: lbu         $t2, 0x13($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X13);
    // 0x8018DB2C: bnel        $v1, $t2, L_8018DB80
    if (ctx->r3 != ctx->r10) {
        // 0x8018DB30: lw          $t5, 0x0($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X0);
            goto L_8018DB80;
    }
    goto skip_0;
    // 0x8018DB30: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x8018DB34: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB38: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x8018DB3C: sb          $zero, 0x22($t4)
    MEM_B(0X22, ctx->r12) = 0;
    // 0x8018DB40: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB44: lbu         $t5, 0x3B($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X3B);
    // 0x8018DB48: addu        $t6, $t1, $a0
    ctx->r14 = ADD32(ctx->r9, ctx->r4);
    // 0x8018DB4C: sb          $t5, 0x23($t6)
    MEM_B(0X23, ctx->r14) = ctx->r13;
    // 0x8018DB50: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB54: lbu         $t9, 0x3C($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X3C);
    // 0x8018DB58: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8018DB5C: sb          $t9, 0x26($t8)
    MEM_B(0X26, ctx->r24) = ctx->r25;
    // 0x8018DB60: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB64: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x8018DB68: sb          $zero, 0x24($t3)
    MEM_B(0X24, ctx->r11) = 0;
    // 0x8018DB6C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB70: addu        $t1, $t4, $a0
    ctx->r9 = ADD32(ctx->r12, ctx->r4);
    // 0x8018DB74: b           L_8018DB88
    // 0x8018DB78: sb          $v1, 0x28($t1)
    MEM_B(0X28, ctx->r9) = ctx->r3;
        goto L_8018DB88;
    // 0x8018DB78: sb          $v1, 0x28($t1)
    MEM_B(0X28, ctx->r9) = ctx->r3;
    // 0x8018DB7C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
L_8018DB80:
    // 0x8018DB80: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8018DB84: sb          $v0, 0x22($t6)
    MEM_B(0X22, ctx->r14) = ctx->r2;
L_8018DB88:
    // 0x8018DB88: lbu         $t9, 0x13($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X13);
    // 0x8018DB8C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8018DB90: bnel        $t7, $t9, L_8018DBE8
    if (ctx->r15 != ctx->r25) {
        // 0x8018DB94: lw          $t1, 0x0($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X0);
            goto L_8018DBE8;
    }
    goto skip_1;
    // 0x8018DB94: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8018DB98: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018DB9C: addu        $t2, $t8, $a0
    ctx->r10 = ADD32(ctx->r24, ctx->r4);
    // 0x8018DBA0: sb          $zero, 0x96($t2)
    MEM_B(0X96, ctx->r10) = 0;
    // 0x8018DBA4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8018DBA8: lbu         $t3, 0x3B($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X3B);
    // 0x8018DBAC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8018DBB0: addu        $t1, $t4, $a0
    ctx->r9 = ADD32(ctx->r12, ctx->r4);
    // 0x8018DBB4: sb          $t3, 0x97($t1)
    MEM_B(0X97, ctx->r9) = ctx->r11;
    // 0x8018DBB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018DBBC: lbu         $t5, 0x3C($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X3C);
    // 0x8018DBC0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8018DBC4: sb          $t5, 0x9A($t7)
    MEM_B(0X9A, ctx->r15) = ctx->r13;
    // 0x8018DBC8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018DBCC: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x8018DBD0: sb          $zero, 0x98($t8)
    MEM_B(0X98, ctx->r24) = 0;
    // 0x8018DBD4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8018DBD8: addu        $t3, $t4, $a0
    ctx->r11 = ADD32(ctx->r12, ctx->r4);
    // 0x8018DBDC: b           L_8018DBF0
    // 0x8018DBE0: sb          $t2, 0x9C($t3)
    MEM_B(0X9C, ctx->r11) = ctx->r10;
        goto L_8018DBF0;
    // 0x8018DBE0: sb          $t2, 0x9C($t3)
    MEM_B(0X9C, ctx->r11) = ctx->r10;
    // 0x8018DBE4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
L_8018DBE8:
    // 0x8018DBE8: addu        $t6, $t1, $a0
    ctx->r14 = ADD32(ctx->r9, ctx->r4);
    // 0x8018DBEC: sb          $v0, 0x96($t6)
    MEM_B(0X96, ctx->r14) = ctx->r2;
L_8018DBF0:
    // 0x8018DBF0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8018DBF4: bne         $v1, $a1, L_8018DB28
    if (ctx->r3 != ctx->r5) {
        // 0x8018DBF8: addiu       $a0, $a0, 0xE8
        ctx->r4 = ADD32(ctx->r4, 0XE8);
            goto L_8018DB28;
    }
    // 0x8018DBF8: addiu       $a0, $a0, 0xE8
    ctx->r4 = ADD32(ctx->r4, 0XE8);
    // 0x8018DBFC: lbu         $t5, 0x13($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X13);
    // 0x8018DC00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018DC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018DC08: bne         $t5, $zero, L_8018DC18
    if (ctx->r13 != 0) {
        // 0x8018DC0C: nop
    
            goto L_8018DC18;
    }
    // 0x8018DC0C: nop

    // 0x8018DC10: b           L_8018DC18
    // 0x8018DC14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DC18;
    // 0x8018DC14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DC18:
    // 0x8018DC18: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8018DC1C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8018DC20: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC24: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018DC28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8018DC2C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018DC30: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8018DC34: sb          $a0, 0x22($t9)
    MEM_B(0X22, ctx->r25) = ctx->r4;
    // 0x8018DC38: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8018DC40: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8018DC44: addu        $t4, $t8, $v1
    ctx->r12 = ADD32(ctx->r24, ctx->r3);
    // 0x8018DC48: sb          $a1, 0x2A($t4)
    MEM_B(0X2A, ctx->r12) = ctx->r5;
    // 0x8018DC4C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC50: lbu         $t2, 0x3D($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X3D);
    // 0x8018DC54: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018DC58: addu        $t1, $t3, $v1
    ctx->r9 = ADD32(ctx->r11, ctx->r3);
    // 0x8018DC5C: sb          $t2, 0x23($t1)
    MEM_B(0X23, ctx->r9) = ctx->r10;
    // 0x8018DC60: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC64: lbu         $t6, 0x3E($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3E);
    // 0x8018DC68: addiu       $t0, $t0, 0xB58
    ctx->r8 = ADD32(ctx->r8, 0XB58);
    // 0x8018DC6C: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8018DC70: sb          $t6, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r14;
    // 0x8018DC74: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC78: addu        $t4, $t8, $v1
    ctx->r12 = ADD32(ctx->r24, ctx->r3);
    // 0x8018DC7C: sb          $t9, 0x20($t4)
    MEM_B(0X20, ctx->r12) = ctx->r25;
    // 0x8018DC80: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC84: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018DC88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DC8C: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x8018DC90: sb          $a0, 0x24($t2)
    MEM_B(0X24, ctx->r10) = ctx->r4;
    // 0x8018DC94: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8018DC98: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8018DC9C: addu        $t5, $t1, $v1
    ctx->r13 = ADD32(ctx->r9, ctx->r3);
    // 0x8018DCA0: sb          $a1, 0x28($t5)
    MEM_B(0X28, ctx->r13) = ctx->r5;
    // 0x8018DCA4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018DCA8: sb          $a0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r4;
    // 0x8018DCAC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8018DCB0: sb          $a0, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r4;
    // 0x8018DCB4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8018DCB8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8018DCBC: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8018DCC0: sw          $t8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r24;
    // 0x8018DCC4: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x8018DCC8: sw          $zero, 0x18($t0)
    MEM_W(0X18, ctx->r8) = 0;
    // 0x8018DCCC: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x8018DCD0: sb          $zero, 0xD3($t0)
    MEM_B(0XD3, ctx->r8) = 0;
    // 0x8018DCD4: sb          $zero, 0xD4($t0)
    MEM_B(0XD4, ctx->r8) = 0;
    // 0x8018DCD8: sb          $zero, 0xD5($t0)
    MEM_B(0XD5, ctx->r8) = 0;
    // 0x8018DCDC: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x8018DCE0: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8018DCE4: sh          $zero, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = 0;
    // 0x8018DCE8: sh          $zero, 0xC6($t0)
    MEM_H(0XC6, ctx->r8) = 0;
    // 0x8018DCEC: sh          $zero, 0xC8($t0)
    MEM_H(0XC8, ctx->r8) = 0;
    // 0x8018DCF0: sw          $t2, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->r10;
    // 0x8018DCF4: sb          $zero, 0xD0($t0)
    MEM_B(0XD0, ctx->r8) = 0;
    // 0x8018DCF8: sb          $zero, 0xD1($t0)
    MEM_B(0XD1, ctx->r8) = 0;
    // 0x8018DCFC: sb          $zero, 0xD2($t0)
    MEM_B(0XD2, ctx->r8) = 0;
    // 0x8018DD00: sh          $zero, 0xD6($t0)
    MEM_H(0XD6, ctx->r8) = 0;
    // 0x8018DD04: jr          $ra
    // 0x8018DD08: sb          $zero, 0xD8($t0)
    MEM_B(0XD8, ctx->r8) = 0;
    return;
    // 0x8018DD08: sb          $zero, 0xD8($t0)
    MEM_B(0XD8, ctx->r8) = 0;
;}
RECOMP_FUNC void gcCaptureTaggedGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017868: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001786C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017870: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80017874: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80017878: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x8001787C: lw          $s0, 0x6800($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6800);
    // 0x80017880: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80017884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017888: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8001788C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80017890: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80017894: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80017898: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001789C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800178A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800178A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800178A8: beq         $s0, $zero, L_80017948
    if (ctx->r16 == 0) {
        // 0x800178AC: sw          $s3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r19;
            goto L_80017948;
    }
    // 0x800178AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800178B0: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x800178B4: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x800178B8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800178BC: addiu       $s3, $s3, -0x478C
    ctx->r19 = ADD32(ctx->r19, -0X478C);
    // 0x800178C0: addiu       $s6, $s6, 0x6A5C
    ctx->r22 = ADD32(ctx->r22, 0X6A5C);
    // 0x800178C4: addiu       $fp, $fp, -0x4918
    ctx->r30 = ADD32(ctx->r30, -0X4918);
    // 0x800178C8: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800178CC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800178D0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800178D4: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
L_800178D8:
    // 0x800178D8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800178DC: bnel        $t8, $zero, L_80017940
    if (ctx->r24 != 0) {
        // 0x800178E0: lw          $s0, 0x20($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X20);
            goto L_80017940;
    }
    goto skip_0;
    // 0x800178E0: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x800178E4: bne         $s1, $zero, L_80017900
    if (ctx->r17 != 0) {
        // 0x800178E8: nop
    
            goto L_80017900;
    }
    // 0x800178E8: nop

    // 0x800178EC: lw          $t9, 0x38($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X38);
    // 0x800178F0: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x800178F4: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800178F8: bnel        $t1, $zero, L_8001791C
    if (ctx->r9 != 0) {
        // 0x800178FC: sw          $s5, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r21;
            goto L_8001791C;
    }
    goto skip_1;
    // 0x800178FC: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
    skip_1:
L_80017900:
    // 0x80017900: bnel        $s1, $s4, L_80017940
    if (ctx->r17 != ctx->r20) {
        // 0x80017904: lw          $s0, 0x20($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X20);
            goto L_80017940;
    }
    goto skip_2;
    // 0x80017904: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
    skip_2:
    // 0x80017908: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8001790C: lw          $t3, 0x38($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X38);
    // 0x80017910: bnel        $t2, $t3, L_80017940
    if (ctx->r10 != ctx->r11) {
        // 0x80017914: lw          $s0, 0x20($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X20);
            goto L_80017940;
    }
    goto skip_3;
    // 0x80017914: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
    skip_3:
    // 0x80017918: sw          $s5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r21;
L_8001791C:
    // 0x8001791C: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x80017920: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80017924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017928: jalr        $t9
    // 0x8001792C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001792C: nop

    after_0:
    // 0x80017930: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80017934: sw          $s7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r23;
    // 0x80017938: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
    // 0x8001793C: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
L_80017940:
    // 0x80017940: bnel        $s0, $zero, L_800178D8
    if (ctx->r16 != 0) {
        // 0x80017944: lw          $t7, 0x7C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X7C);
            goto L_800178D8;
    }
    goto skip_4;
    // 0x80017944: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    skip_4:
L_80017948:
    // 0x80017948: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001794C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017950: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017954: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80017958: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001795C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80017960: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80017964: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80017968: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001796C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80017970: jr          $ra
    // 0x80017974: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80017974: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftYoshiSpecialHiUpdateEggVectors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E9E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E9E8: lw          $t6, 0xB18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB18);
    // 0x8015E9EC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8015E9F0: beql        $t6, $zero, L_8015EA50
    if (ctx->r14 == 0) {
        // 0x8015E9F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015EA50;
    }
    goto skip_0;
    // 0x8015E9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015E9F8: jal         0x8015E9B0
    // 0x8015E9FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftYoshiSpecialHiGetEggPosition(rdram, ctx);
        goto after_0;
    // 0x8015E9FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EA00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015EA04: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x8015EA08: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8015EA0C: lw          $t7, 0xB18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB18);
    // 0x8015EA10: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8015EA14: sw          $t1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r9;
    // 0x8015EA18: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8015EA1C: sw          $t0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r8;
    // 0x8015EA20: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8015EA24: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x8015EA28: lw          $t4, 0x8F4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8F4);
    // 0x8015EA2C: lw          $t2, 0xB18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XB18);
    // 0x8015EA30: lw          $t6, 0x40($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X40);
    // 0x8015EA34: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8015EA38: sw          $t6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->r14;
    // 0x8015EA3C: lw          $t5, 0x44($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X44);
    // 0x8015EA40: sw          $t5, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->r13;
    // 0x8015EA44: lw          $t6, 0x48($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X48);
    // 0x8015EA48: sw          $t6, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->r14;
    // 0x8015EA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015EA50:
    // 0x8015EA50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015EA54: jr          $ra
    // 0x8015EA58: nop

    return;
    // 0x8015EA58: nop

;}
RECOMP_FUNC void itMSBombFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017653C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80176544: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80176548: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017654C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80176550: jal         0x80173F78
    // 0x80176554: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80176554: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80176558: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017655C: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x80176560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176564: jal         0x80172EC8
    // 0x80176568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176568: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017656C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176574: jr          $ra
    // 0x80176578: nop

    return;
    // 0x80176578: nop

;}
RECOMP_FUNC void func_ovl8_80372E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372E44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372E48: jal         0x80373160
    // 0x80372E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x80372E4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80372E50: beq         $v0, $zero, L_80372E84
    if (ctx->r2 == 0) {
        // 0x80372E54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80372E84;
    }
    // 0x80372E54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80372E58: beql        $v0, $zero, L_80372E88
    if (ctx->r2 == 0) {
        // 0x80372E5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80372E88;
    }
    goto skip_0;
    // 0x80372E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80372E60: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_80372E64:
    // 0x80372E64: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80372E68: lw          $t9, 0x104($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X104);
    // 0x80372E6C: lh          $t6, 0x100($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X100);
    // 0x80372E70: jalr        $t9
    // 0x80372E74: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372E74: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x80372E78: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    // 0x80372E7C: bnel        $s0, $zero, L_80372E64
    if (ctx->r16 != 0) {
        // 0x80372E80: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80372E64;
    }
    goto skip_1;
    // 0x80372E80: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_1:
L_80372E84:
    // 0x80372E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80372E88:
    // 0x80372E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80372E8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80372E90: jr          $ra
    // 0x80372E94: nop

    return;
    // 0x80372E94: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015264C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152650: jal         0x800DDE84
    // 0x80152654: addiu       $a1, $a1, 0x26CC
    ctx->r5 = ADD32(ctx->r5, 0X26CC);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80152654: addiu       $a1, $a1, 0x26CC
    ctx->r5 = ADD32(ctx->r5, 0X26CC);
    after_0:
    // 0x80152658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015265C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152660: jr          $ra
    // 0x80152664: nop

    return;
    // 0x80152664: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133140: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133144: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80133148: lw          $t8, -0x7354($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7354);
    // 0x8013314C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80133150: addiu       $t9, $t9, 0x758
    ctx->r25 = ADD32(ctx->r25, 0X758);
    // 0x80133154: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80133158: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013315C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133160: addiu       $t0, $t0, -0x3100
    ctx->r8 = ADD32(ctx->r8, -0X3100);
    // 0x80133164: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x80133168: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013316C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133170: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133174: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80133178: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8013317C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80133180: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80133184: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133188: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8013318C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80133190: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80133194: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80133198: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8013319C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801331A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801331A4: jal         0x800CD050
    // 0x801331A8: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x801331A8: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_0:
    // 0x801331AC: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x801331B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801331B4: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x801331B8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801331BC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801331C0: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x801331C4: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801331C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801331CC: addiu       $t1, $zero, 0xE3
    ctx->r9 = ADD32(0, 0XE3);
    // 0x801331D0: addiu       $t3, $zero, 0xAC
    ctx->r11 = ADD32(0, 0XAC);
    // 0x801331D4: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x801331D8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801331DC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801331E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801331E4: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801331E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801331EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801331F0: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801331F4: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801331F8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801331FC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80133200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133204: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80133208: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8013320C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133210: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80133214: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x80133218: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013321C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80133220: sb          $t1, 0x28($t2)
    MEM_B(0X28, ctx->r10) = ctx->r9;
    // 0x80133224: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80133228: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8013322C: addiu       $t1, $t1, 0x15C8
    ctx->r9 = ADD32(ctx->r9, 0X15C8);
    // 0x80133230: sb          $t3, 0x29($t4)
    MEM_B(0X29, ctx->r12) = ctx->r11;
    // 0x80133234: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80133238: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013323C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133240: sb          $t5, 0x2A($t6)
    MEM_B(0X2A, ctx->r14) = ctx->r13;
    // 0x80133244: lw          $t9, -0x7368($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7368);
    // 0x80133248: sw          $v0, -0x7790($at)
    MEM_W(-0X7790, ctx->r1) = ctx->r2;
    // 0x8013324C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80133250: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80133254: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80133258: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8013325C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80133260: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80133264: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80133268: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013326C: jal         0x800CD050
    // 0x80133270: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_1;
    // 0x80133270: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x80133274: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x80133278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013327C: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80133280: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80133284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133288: swc1        $f8, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f8.u32l;
    // 0x8013328C: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80133290: swc1        $f10, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f10.u32l;
    // 0x80133294: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133298: lhu         $t7, 0x24($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X24);
    // 0x8013329C: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x801332A0: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
    // 0x801332A4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801332A8: lhu         $t9, 0x24($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X24);
    // 0x801332AC: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x801332B0: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    // 0x801332B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801332B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801332BC: jr          $ra
    // 0x801332C0: nop

    return;
    // 0x801332C0: nop

;}
RECOMP_FUNC void mvOpeningRoomSetSpotlightPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FCC: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80132FD0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80132FD4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132FD8: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    // 0x80132FDC: addiu       $t6, $t6, 0x4A70
    ctx->r14 = ADD32(ctx->r14, 0X4A70);
    // 0x80132FE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132FE4: addiu       $t0, $sp, 0x0
    ctx->r8 = ADD32(ctx->r29, 0X0);
    // 0x80132FE8: addiu       $t1, $t6, 0x90
    ctx->r9 = ADD32(ctx->r14, 0X90);
    // 0x80132FEC: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
L_80132FF0:
    // 0x80132FF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132FF4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132FF8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132FFC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133000: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133004: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133008: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013300C: bne         $t6, $t1, L_80132FF0
    if (ctx->r14 != ctx->r9) {
        // 0x80133010: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132FF0;
    }
    // 0x80133010: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133014: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133018: addiu       $t2, $t2, 0x4B00
    ctx->r10 = ADD32(ctx->r10, 0X4B00);
    // 0x8013301C: addiu       $t1, $t2, 0x90
    ctx->r9 = ADD32(ctx->r10, 0X90);
    // 0x80133020: or          $t5, $t0, $zero
    ctx->r13 = ctx->r8 | 0;
L_80133024:
    // 0x80133024: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80133028: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8013302C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80133030: sw          $t4, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r12;
    // 0x80133034: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80133038: sw          $t3, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r11;
    // 0x8013303C: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80133040: bne         $t2, $t1, L_80133024
    if (ctx->r10 != ctx->r9) {
        // 0x80133044: sw          $t4, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r12;
            goto L_80133024;
    }
    // 0x80133044: sw          $t4, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r12;
    // 0x80133048: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8013304C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80133050: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80133054: addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // 0x80133058: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8013305C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80133060: addu        $a2, $t0, $v0
    ctx->r6 = ADD32(ctx->r8, ctx->r2);
    // 0x80133064: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80133068: swc1        $f6, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f6.u32l;
    // 0x8013306C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80133070: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80133074: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80133078: swc1        $f10, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f10.u32l;
    // 0x8013307C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80133080: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80133084: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80133088: swc1        $f18, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f18.u32l;
    // 0x8013308C: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80133090: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80133094: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
    // 0x80133098: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8013309C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801330A0: swc1        $f6, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f6.u32l;
    // 0x801330A4: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x801330A8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801330AC: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    // 0x801330B0: jr          $ra
    // 0x801330B4: swc1        $f8, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f8.u32l;
    return;
    // 0x801330B4: swc1        $f8, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f8.u32l;
;}
RECOMP_FUNC void gcGetAObjRate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000CC44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000CC48: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8000CC4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CC50: beq         $v0, $at, L_8000CCA4
    if (ctx->r2 == ctx->r1) {
        // 0x8000CC54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000CCA4;
    }
    // 0x8000CC54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CC58: beq         $v0, $at, L_8000CC70
    if (ctx->r2 == ctx->r1) {
        // 0x8000CC5C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000CC70;
    }
    // 0x8000CC5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000CC60: beql        $v0, $at, L_8000CC7C
    if (ctx->r2 == ctx->r1) {
        // 0x8000CC64: lwc1        $f4, 0x18($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
            goto L_8000CC7C;
    }
    goto skip_0;
    // 0x8000CC64: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x8000CC68: b           L_8000CCB0
    // 0x8000CC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000CCB0;
    // 0x8000CC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CC70:
    // 0x8000CC70: b           L_8000CCAC
    // 0x8000CC74: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
        goto L_8000CCAC;
    // 0x8000CC74: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000CC78: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
L_8000CC7C:
    // 0x8000CC7C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000CC80: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CC84: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8000CC88: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x8000CC8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000CC90: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CC94: jal         0x8000CADC
    // 0x8000CC98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    gcGetInterpRateCubic(rdram, ctx);
        goto after_0;
    // 0x8000CC98: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8000CC9C: b           L_8000CCB0
    // 0x8000CCA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000CCB0;
    // 0x8000CCA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CCA4:
    // 0x8000CCA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000CCA8: nop

L_8000CCAC:
    // 0x8000CCAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CCB0:
    // 0x8000CCB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000CCB4: jr          $ra
    // 0x8000CCB8: nop

    return;
    // 0x8000CCB8: nop

;}
RECOMP_FUNC void itManagerMakeAppearActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EC40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8016EC44: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8016EC48: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8016EC4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EC50: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x8016EC54: beql        $t6, $zero, L_8016EF30
    if (ctx->r14 == 0) {
        // 0x8016EC58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016EF30;
    }
    goto skip_0;
    // 0x8016EC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8016EC5C: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8016EC60: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8016EC64: beql        $a2, $zero, L_8016EF30
    if (ctx->r6 == 0) {
        // 0x8016EC68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016EF30;
    }
    goto skip_1;
    // 0x8016EC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8016EC6C: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x8016EC70: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8016EC74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016EC78: lw          $a3, 0x84($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X84);
    // 0x8016EC7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016EC80: beq         $a3, $zero, L_8016EF2C
    if (ctx->r7 == 0) {
        // 0x8016EC84: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8016EF2C;
    }
    // 0x8016EC84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8016EC88:
    // 0x8016EC88: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8016EC8C: beq         $t8, $zero, L_8016EC9C
    if (ctx->r24 == 0) {
        // 0x8016EC90: addu        $t9, $a0, $v1
        ctx->r25 = ADD32(ctx->r4, ctx->r3);
            goto L_8016EC9C;
    }
    // 0x8016EC90: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x8016EC94: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x8016EC98: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
L_8016EC9C:
    // 0x8016EC9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8016ECA0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8016ECA4: bne         $at, $zero, L_8016EC88
    if (ctx->r1 != 0) {
        // 0x8016ECA8: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_8016EC88;
    }
    // 0x8016ECA8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8016ECAC: bne         $a1, $zero, L_8016ECBC
    if (ctx->r5 != 0) {
        // 0x8016ECB0: lui         $t0, 0x8019
        ctx->r8 = S32(0X8019 << 16);
            goto L_8016ECBC;
    }
    // 0x8016ECB0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016ECB4: b           L_8016EF30
    // 0x8016ECB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016EF30;
    // 0x8016ECB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016ECBC:
    // 0x8016ECBC: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016ECC0: sh          $a1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r5;
    // 0x8016ECC4: jal         0x800FC7A4
    // 0x8016ECC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_0;
    // 0x8016ECC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8016ECCC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016ECD0: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016ECD4: bne         $v0, $zero, L_8016ECE4
    if (ctx->r2 != 0) {
        // 0x8016ECD8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8016ECE4;
    }
    // 0x8016ECD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8016ECDC: b           L_8016EF30
    // 0x8016ECE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016EF30;
    // 0x8016ECE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016ECE4:
    // 0x8016ECE4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8016ECE8: bne         $at, $zero, L_8016ED10
    if (ctx->r1 != 0) {
        // 0x8016ECEC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8016ED10;
    }
    // 0x8016ECEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8016ECF0:
    // 0x8016ECF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8016ECF4: addiu       $a0, $a0, -0x3420
    ctx->r4 = ADD32(ctx->r4, -0X3420);
    // 0x8016ECF8: jal         0x80023624
    // 0x8016ECFC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8016ECFC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x8016ED00: jal         0x800A3040
    // 0x8016ED04: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x8016ED04: nop

    after_2:
    // 0x8016ED08: b           L_8016ECF0
    // 0x8016ED0C: nop

        goto L_8016ECF0;
    // 0x8016ED0C: nop

L_8016ED10:
    // 0x8016ED10: sb          $a2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r6;
    // 0x8016ED14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016ED18: jal         0x80004980
    // 0x8016ED1C: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    syTaskmanMalloc(rdram, ctx);
        goto after_3;
    // 0x8016ED1C: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    after_3:
    // 0x8016ED20: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016ED24: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016ED28: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8016ED2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8016ED30: jal         0x800FC814
    // 0x8016ED34: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_4;
    // 0x8016ED34: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x8016ED38: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x8016ED3C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016ED40: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016ED44: blez        $a2, L_8016EDE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8016ED48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8016EDE0;
    }
    // 0x8016ED48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016ED4C: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x8016ED50: beq         $a1, $zero, L_8016ED84
    if (ctx->r5 == 0) {
        // 0x8016ED54: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8016ED84;
    }
    // 0x8016ED54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8016ED58: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x8016ED5C: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x8016ED60: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_8016ED64:
    // 0x8016ED64: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8016ED68: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8016ED6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8016ED70: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8016ED74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8016ED78: bne         $a0, $v1, L_8016ED64
    if (ctx->r4 != ctx->r3) {
        // 0x8016ED7C: sb          $t5, 0x0($t7)
        MEM_B(0X0, ctx->r15) = ctx->r13;
            goto L_8016ED64;
    }
    // 0x8016ED7C: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x8016ED80: beq         $v1, $a2, L_8016EDDC
    if (ctx->r3 == ctx->r6) {
        // 0x8016ED84: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8016EDDC;
    }
L_8016ED84:
    // 0x8016ED84: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8016ED88: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x8016ED8C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_8016ED90:
    // 0x8016ED90: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8016ED94: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8016ED98: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8016ED9C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8016EDA0: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
    // 0x8016EDA4: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8016EDA8: lw          $t6, -0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, -0XC);
    // 0x8016EDAC: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8016EDB0: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x8016EDB4: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8016EDB8: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x8016EDBC: addu        $t3, $t9, $v1
    ctx->r11 = ADD32(ctx->r25, ctx->r3);
    // 0x8016EDC0: sb          $t8, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r24;
    // 0x8016EDC4: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8016EDC8: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x8016EDCC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8016EDD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8016EDD4: bne         $v1, $a2, L_8016ED90
    if (ctx->r3 != ctx->r6) {
        // 0x8016EDD8: sb          $t2, 0x3($t5)
        MEM_B(0X3, ctx->r13) = ctx->r10;
            goto L_8016ED90;
    }
    // 0x8016EDD8: sb          $t2, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r10;
L_8016EDDC:
    // 0x8016EDDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8016EDE0:
    // 0x8016EDE0: addiu       $a0, $zero, 0x3F5
    ctx->r4 = ADD32(0, 0X3F5);
    // 0x8016EDE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016EDE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8016EDEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8016EDF0: jal         0x80009968
    // 0x8016EDF4: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x8016EDF4: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    after_5:
    // 0x8016EDF8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016EDFC: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x8016EE00: addiu       $a1, $a1, -0x1488
    ctx->r5 = ADD32(ctx->r5, -0X1488);
    // 0x8016EE04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016EE08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016EE0C: jal         0x80008188
    // 0x8016EE10: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x8016EE10: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x8016EE14: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8016EE18: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8016EE1C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8016EE20: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x8016EE24: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EE28: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016EE2C: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x8016EE30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016EE34: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x8016EE38: lw          $a3, 0x84($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X84);
L_8016EE3C:
    // 0x8016EE3C: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x8016EE40: beq         $t9, $zero, L_8016EE58
    if (ctx->r25 == 0) {
        // 0x8016EE44: addu        $t8, $a3, $v1
        ctx->r24 = ADD32(ctx->r7, ctx->r3);
            goto L_8016EE58;
    }
    // 0x8016EE44: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x8016EE48: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
    // 0x8016EE4C: beql        $t3, $zero, L_8016EE5C
    if (ctx->r11 == 0) {
        // 0x8016EE50: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8016EE5C;
    }
    goto skip_2;
    // 0x8016EE50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8016EE54: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8016EE58:
    // 0x8016EE58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8016EE5C:
    // 0x8016EE5C: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8016EE60: bne         $at, $zero, L_8016EE3C
    if (ctx->r1 != 0) {
        // 0x8016EE64: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016EE3C;
    }
    // 0x8016EE64: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016EE68: sb          $a2, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r6;
    // 0x8016EE6C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8016EE70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016EE74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016EE78: jal         0x80004980
    // 0x8016EE7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    syTaskmanMalloc(rdram, ctx);
        goto after_7;
    // 0x8016EE7C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_7:
    // 0x8016EE80: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016EE84: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EE88: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016EE8C: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x8016EE90: sw          $v0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r2;
    // 0x8016EE94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016EE98: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8016EE9C: jal         0x80004980
    // 0x8016EEA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    syTaskmanMalloc(rdram, ctx);
        goto after_8;
    // 0x8016EEA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8016EEA4: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EEA8: addiu       $t0, $t0, -0x2F68
    ctx->r8 = ADD32(ctx->r8, -0X2F68);
    // 0x8016EEAC: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8016EEB0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8016EEB4: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x8016EEB8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016EEBC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8016EEC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016EEC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016EEC8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8016EECC: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
L_8016EED0:
    // 0x8016EED0: andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // 0x8016EED4: beq         $t2, $zero, L_8016EF10
    if (ctx->r10 == 0) {
        // 0x8016EED8: addu        $v0, $a3, $v1
        ctx->r2 = ADD32(ctx->r7, ctx->r3);
            goto L_8016EF10;
    }
    // 0x8016EED8: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x8016EEDC: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8016EEE0: beql        $t5, $zero, L_8016EF14
    if (ctx->r13 == 0) {
        // 0x8016EEE4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8016EF14;
    }
    goto skip_3;
    // 0x8016EEE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x8016EEE8: lw          $t6, 0x18($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X18);
    // 0x8016EEEC: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8016EEF0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8016EEF4: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x8016EEF8: lw          $t9, 0x20($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X20);
    // 0x8016EEFC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8016EF00: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x8016EF04: sh          $a1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r5;
    // 0x8016EF08: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8016EF0C: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
L_8016EF10:
    // 0x8016EF10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8016EF14:
    // 0x8016EF14: bne         $v1, $t1, L_8016EED0
    if (ctx->r3 != ctx->r9) {
        // 0x8016EF18: srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
            goto L_8016EED0;
    }
    // 0x8016EF18: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8016EF1C: jal         0x8016EB0C
    // 0x8016EF20: nop

    itManagerSetItemSpawnWait(rdram, ctx);
        goto after_9;
    // 0x8016EF20: nop

    after_9:
    // 0x8016EF24: b           L_8016EF30
    // 0x8016EF28: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
        goto L_8016EF30;
    // 0x8016EF28: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
L_8016EF2C:
    // 0x8016EF2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016EF30:
    // 0x8016EF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016EF34: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x8016EF38: jr          $ra
    // 0x8016EF3C: nop

    return;
    // 0x8016EF3C: nop

;}
RECOMP_FUNC void itGLuckyDamagedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C248: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C24C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017C250: addiu       $a1, $a1, -0x579C
    ctx->r5 = ADD32(ctx->r5, -0X579C);
    // 0x8017C254: jal         0x80172EC8
    // 0x8017C258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017C258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8017C25C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017C260: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017C264: addiu       $t6, $t6, -0x3ADC
    ctx->r14 = ADD32(ctx->r14, -0X3ADC);
    // 0x8017C268: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x8017C26C: sw          $t6, 0x398($t8)
    MEM_W(0X398, ctx->r24) = ctx->r14;
    // 0x8017C270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C278: jr          $ra
    // 0x8017C27C: nop

    return;
    // 0x8017C27C: nop

;}
RECOMP_FUNC void gmRumbleStopRumbleID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80115634: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80115638: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8011563C: addiu       $t8, $t8, 0x19F0
    ctx->r24 = ADD32(ctx->r24, 0X19F0);
    // 0x80115640: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80115644: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x80115648: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8011564C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80115650: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80115654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80115658: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011565C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80115660: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80115664: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80115668: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8011566C: beql        $t0, $zero, L_801156D0
    if (ctx->r8 == 0) {
        // 0x80115670: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801156D0;
    }
    goto skip_0;
    // 0x80115670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80115674: beql        $v1, $zero, L_801156C0
    if (ctx->r3 == 0) {
        // 0x80115678: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801156C0;
    }
    goto skip_1;
    // 0x80115678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8011567C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80115680:
    // 0x80115680: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115684: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80115688: beql        $t1, $zero, L_801156C0
    if (ctx->r9 == 0) {
        // 0x8011568C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801156C0;
    }
    goto skip_2;
    // 0x8011568C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x80115690: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80115694: bnel        $s2, $t2, L_801156B4
    if (ctx->r18 != ctx->r10) {
        // 0x80115698: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_801156B4;
    }
    goto skip_3;
    // 0x80115698: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8011569C: jal         0x80115090
    // 0x801156A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmRumbleAddLinkAfter(rdram, ctx);
        goto after_0;
    // 0x801156A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801156A4: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x801156A8: b           L_801156B4
    // 0x801156AC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
        goto L_801156B4;
    // 0x801156AC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x801156B0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_801156B4:
    // 0x801156B4: bnel        $s0, $zero, L_80115680
    if (ctx->r16 != 0) {
        // 0x801156B8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80115680;
    }
    goto skip_4;
    // 0x801156B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x801156BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_801156C0:
    // 0x801156C0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801156C4: jal         0x801151F4
    // 0x801156C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    gmRumbleGetMotorUpdateStatus(rdram, ctx);
        goto after_1;
    // 0x801156C8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801156CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801156D0:
    // 0x801156D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801156D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801156D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801156DC: jr          $ra
    // 0x801156E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801156E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800266A0_272A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800266A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800266A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800266A8: jal         0x80030350
    // 0x800266AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800266AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800266B0: jal         0x800264A4
    // 0x800266B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800264A4_270A4(rdram, ctx);
        goto after_1;
    // 0x800266B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800266B8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800266BC: addiu       $a2, $a2, -0x1230
    ctx->r6 = ADD32(ctx->r6, -0X1230);
    // 0x800266C0: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x800266C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800266C8: beq         $a0, $zero, L_80026704
    if (ctx->r4 == 0) {
        // 0x800266CC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80026704;
    }
    // 0x800266CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800266D0: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
L_800266D4:
    // 0x800266D4: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x800266D8: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x800266DC: beq         $a0, $zero, L_800266F0
    if (ctx->r4 == 0) {
        // 0x800266E0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800266F0;
    }
    // 0x800266E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800266E4: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x800266E8: sb          $a1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r5;
    // 0x800266EC: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
L_800266F0:
    // 0x800266F0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800266F4: bnel        $v1, $zero, L_800266D4
    if (ctx->r3 != 0) {
        // 0x800266F8: lw          $a0, 0x28($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X28);
            goto L_800266D4;
    }
    goto skip_0;
    // 0x800266F8: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    skip_0:
    // 0x800266FC: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80026700: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80026704:
    // 0x80026704: beq         $a0, $zero, L_80026720
    if (ctx->r4 == 0) {
        // 0x80026708: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80026720;
    }
    // 0x80026708: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8002670C: lw          $t6, 0x38($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X38);
    // 0x80026710: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80026714: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x80026718: sw          $zero, 0x40($a2)
    MEM_W(0X40, ctx->r6) = 0;
    // 0x8002671C: sw          $t7, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r15;
L_80026720:
    // 0x80026720: jal         0x80030350
    // 0x80026724: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80026724: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80026728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002672C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026730: jr          $ra
    // 0x80026734: nop

    return;
    // 0x80026734: nop

;}
RECOMP_FUNC void itDogasAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182F14: jal         0x80182E78
    // 0x80182F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itDogasAttackInitVars(rdram, ctx);
        goto after_0;
    // 0x80182F18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80182F1C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182F20: addiu       $a1, $a1, -0x4D0C
    ctx->r5 = ADD32(ctx->r5, -0X4D0C);
    // 0x80182F24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80182F28: jal         0x80172EC8
    // 0x80182F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80182F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80182F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182F38: jr          $ra
    // 0x80182F3C: nop

    return;
    // 0x80182F3C: nop

;}
RECOMP_FUNC void mnBackupClearApplyOptionID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013251C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132520: sltiu       $at, $a0, 0x6
    ctx->r1 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x80132524: beq         $at, $zero, L_801325A4
    if (ctx->r1 == 0) {
        // 0x80132528: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801325A4;
    }
    // 0x80132528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013252C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80132530: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132534: addu        $at, $at, $t6
    gpr jr_addend_8013253C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80132538: lw          $t6, 0x3070($at)
    ctx->r14 = ADD32(ctx->r1, 0X3070);
    // 0x8013253C: jr          $t6
    // 0x80132540: nop

    switch (jr_addend_8013253C >> 2) {
        case 0: goto L_80132544; break;
        case 1: goto L_80132554; break;
        case 2: goto L_80132574; break;
        case 3: goto L_80132564; break;
        case 4: goto L_80132584; break;
        case 5: goto L_80132594; break;
        default: switch_error(__func__, 0x8013253C, 0x80133070);
    }
    // 0x80132540: nop

L_80132544:
    // 0x80132544: jal         0x800D48E0
    // 0x80132548: nop

    lbBackupClearNewcomers(rdram, ctx);
        goto after_0;
    // 0x80132548: nop

    after_0:
    // 0x8013254C: b           L_801325A4
    // 0x80132550: nop

        goto L_801325A4;
    // 0x80132550: nop

L_80132554:
    // 0x80132554: jal         0x800D4914
    // 0x80132558: nop

    lbBackupClear1PHighScore(rdram, ctx);
        goto after_1;
    // 0x80132558: nop

    after_1:
    // 0x8013255C: b           L_801325A4
    // 0x80132560: nop

        goto L_801325A4;
    // 0x80132560: nop

L_80132564:
    // 0x80132564: jal         0x800D49E0
    // 0x80132568: nop

    lbBackupClearVSRecord(rdram, ctx);
        goto after_2;
    // 0x80132568: nop

    after_2:
    // 0x8013256C: b           L_801325A4
    // 0x80132570: nop

        goto L_801325A4;
    // 0x80132570: nop

L_80132574:
    // 0x80132574: jal         0x800D4B60
    // 0x80132578: nop

    lbBackupClearBonusStageTime(rdram, ctx);
        goto after_3;
    // 0x80132578: nop

    after_3:
    // 0x8013257C: b           L_801325A4
    // 0x80132580: nop

        goto L_801325A4;
    // 0x80132580: nop

L_80132584:
    // 0x80132584: jal         0x800D4C0C
    // 0x80132588: nop

    lbBackupClearPrize(rdram, ctx);
        goto after_4;
    // 0x80132588: nop

    after_4:
    // 0x8013258C: b           L_801325A4
    // 0x80132590: nop

        goto L_801325A4;
    // 0x80132590: nop

L_80132594:
    // 0x80132594: jal         0x800D4C48
    // 0x80132598: nop

    lbBackupClearAllData(rdram, ctx);
        goto after_5;
    // 0x80132598: nop

    after_5:
    // 0x8013259C: jal         0x800D46F4
    // 0x801325A0: nop

    lbBackupApplyOptions(rdram, ctx);
        goto after_6;
    // 0x801325A0: nop

    after_6:
L_801325A4:
    // 0x801325A4: jal         0x800D473C
    // 0x801325A8: nop

    lbBackupCorrectErrors(rdram, ctx);
        goto after_7;
    // 0x801325A8: nop

    after_7:
    // 0x801325AC: jal         0x800D45F4
    // 0x801325B0: nop

    lbBackupWrite(rdram, ctx);
        goto after_8;
    // 0x801325B0: nop

    after_8:
    // 0x801325B4: jal         0x800269C0
    // 0x801325B8: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x801325B8: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_9:
    // 0x801325BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801325C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801325C4: jr          $ra
    // 0x801325C8: nop

    return;
    // 0x801325C8: nop

;}
RECOMP_FUNC void mnPlayersVSGetFighterKindCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134608: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013460C: lw          $t6, -0x4530($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4530);
    // 0x80134610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134614: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134618: bne         $a0, $t6, L_80134624
    if (ctx->r4 != ctx->r14) {
        // 0x8013461C: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_80134624;
    }
    // 0x8013461C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80134620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134624:
    // 0x80134624: lw          $t7, -0x4474($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4474);
    // 0x80134628: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013462C: bne         $a0, $t7, L_80134638
    if (ctx->r4 != ctx->r15) {
        // 0x80134630: nop
    
            goto L_80134638;
    }
    // 0x80134630: nop

    // 0x80134634: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80134638:
    // 0x80134638: lw          $t8, -0x43B8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X43B8);
    // 0x8013463C: bne         $a0, $t8, L_80134648
    if (ctx->r4 != ctx->r24) {
        // 0x80134640: nop
    
            goto L_80134648;
    }
    // 0x80134640: nop

    // 0x80134644: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80134648:
    // 0x80134648: lw          $t9, -0x42FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X42FC);
    // 0x8013464C: bne         $a0, $t9, L_80134658
    if (ctx->r4 != ctx->r25) {
        // 0x80134650: nop
    
            goto L_80134658;
    }
    // 0x80134650: nop

    // 0x80134654: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80134658:
    // 0x80134658: beq         $v0, $zero, L_8013466C
    if (ctx->r2 == 0) {
        // 0x8013465C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8013466C;
    }
    // 0x8013465C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80134660: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80134664: jr          $ra
    // 0x80134668: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80134668: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013466C:
    // 0x8013466C: jr          $ra
    // 0x80134670: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80134670: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftYoshiSpecialAirNReleaseProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015E484: jal         0x8015E3D8
    // 0x8015E488: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftYoshiSpecialNCatchUpdateCaptureVars(rdram, ctx);
        goto after_0;
    // 0x8015E488: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E48C: jal         0x800D94E8
    // 0x8015E490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x8015E490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015E494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E49C: jr          $ra
    // 0x8015E4A0: nop

    return;
    // 0x8015E4A0: nop

;}
RECOMP_FUNC void itBombHeiCommonUpdateAttackEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177A24: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177A28: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80177A2C: lw          $t6, -0x6064($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6064);
    // 0x80177A30: lw          $a1, 0x340($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X340);
    // 0x80177A34: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80177A38: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80177A3C: addiu       $t8, $t8, 0x46C
    ctx->r24 = ADD32(ctx->r24, 0X46C);
    // 0x80177A40: srl         $a1, $a1, 28
    ctx->r5 = S32(U32(ctx->r5) >> 28);
    // 0x80177A44: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80177A48: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80177A4C: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x80177A50: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x80177A54: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80177A58: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x80177A5C: bne         $t0, $t1, L_80177B08
    if (ctx->r8 != ctx->r9) {
        // 0x80177A60: nop
    
            goto L_80177B08;
    }
    // 0x80177A60: nop

    // 0x80177A64: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80177A68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80177A6C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80177A70: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x80177A74: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x80177A78: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80177A7C: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x80177A80: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x80177A84: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x80177A88: lhu         $t8, 0x4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X4);
    // 0x80177A8C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80177A90: bgez        $t8, L_80177AA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80177A94: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80177AA4;
    }
    // 0x80177A94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80177A98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80177A9C: nop

    // 0x80177AA0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80177AA4:
    // 0x80177AA4: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x80177AA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80177AAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80177AB0: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x80177AB4: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x80177AB8: andi        $t4, $t2, 0xF7
    ctx->r12 = ctx->r10 & 0XF7;
    // 0x80177ABC: lbu         $t2, 0x340($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X340);
    // 0x80177AC0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80177AC4: sb          $t4, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r12;
    // 0x80177AC8: andi        $t6, $t4, 0xFB
    ctx->r14 = ctx->r12 & 0XFB;
    // 0x80177ACC: andi        $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 & 0XF0;
    // 0x80177AD0: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80177AD4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80177AD8: sb          $t4, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r12;
    // 0x80177ADC: lw          $t5, 0x340($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X340);
    // 0x80177AE0: sb          $t6, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r14;
    // 0x80177AE4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x80177AE8: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80177AEC: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x80177AF0: sb          $t7, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r15;
    // 0x80177AF4: bne         $t6, $at, L_80177B08
    if (ctx->r14 != ctx->r1) {
        // 0x80177AF8: sw          $t8, 0x11C($v0)
        MEM_W(0X11C, ctx->r2) = ctx->r24;
            goto L_80177B08;
    }
    // 0x80177AF8: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
    // 0x80177AFC: andi        $t8, $t4, 0xF
    ctx->r24 = ctx->r12 & 0XF;
    // 0x80177B00: ori         $t9, $t8, 0x30
    ctx->r25 = ctx->r24 | 0X30;
    // 0x80177B04: sb          $t9, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r25;
L_80177B08:
    // 0x80177B08: jr          $ra
    // 0x80177B0C: nop

    return;
    // 0x80177B0C: nop

;}
RECOMP_FUNC void func_ovl8_803868EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803868EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803868F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803868F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803868F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803868FC: beq         $a0, $zero, L_80386980
    if (ctx->r4 == 0) {
        // 0x80386900: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80386980;
    }
    // 0x80386900: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80386904: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80386908: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038690C: addiu       $t6, $t6, -0x1A60
    ctx->r14 = ADD32(ctx->r14, -0X1A60);
    // 0x80386910: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80386914: addiu       $t7, $t7, -0x19A0
    ctx->r15 = ADD32(ctx->r15, -0X19A0);
    // 0x80386918: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8038691C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80386920: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80386924: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80386928: addiu       $t9, $t9, -0x1848
    ctx->r25 = ADD32(ctx->r25, -0X1848);
    // 0x8038692C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80386930: addiu       $t1, $t1, -0x1820
    ctx->r9 = ADD32(ctx->r9, -0X1820);
    // 0x80386934: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80386938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038693C: jal         0x803761F4
    // 0x80386940: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    func_ovl8_803761F4(rdram, ctx);
        goto after_0;
    // 0x80386940: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    after_0:
    // 0x80386944: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80386948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038694C: beql        $t2, $zero, L_8038696C
    if (ctx->r10 == 0) {
        // 0x80386950: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8038696C;
    }
    goto skip_0;
    // 0x80386950: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80386954: jal         0x8037C30C
    // 0x80386958: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x80386958: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x8038695C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80386960: jal         0x803718C4
    // 0x80386964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80386964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80386968: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8038696C:
    // 0x8038696C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80386970: beql        $t4, $zero, L_80386984
    if (ctx->r12 == 0) {
        // 0x80386974: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80386984;
    }
    goto skip_1;
    // 0x80386974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80386978: jal         0x803717C0
    // 0x8038697C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x8038697C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80386980:
    // 0x80386980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80386984:
    // 0x80386984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80386988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038698C: jr          $ra
    // 0x80386990: nop

    return;
    // 0x80386990: nop

;}
RECOMP_FUNC void ftKirbySpecialNStopEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161FC4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161FC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80161FCC: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x80161FD0: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x80161FD4: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80161FD8: bnel        $t8, $at, L_80161FEC
    if (ctx->r24 != ctx->r1) {
        // 0x80161FDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80161FEC;
    }
    goto skip_0;
    // 0x80161FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80161FE0: jal         0x800E9C3C
    // 0x80161FE4: nop

    ftParamProcStopEffect(rdram, ctx);
        goto after_0;
    // 0x80161FE4: nop

    after_0:
    // 0x80161FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80161FEC:
    // 0x80161FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161FF0: jr          $ra
    // 0x80161FF4: nop

    return;
    // 0x80161FF4: nop

;}
RECOMP_FUNC void itNBumperFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B63C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017B640: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017B644: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017B648: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x8017B64C: jal         0x80173F78
    // 0x8017B650: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017B650: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x8017B654: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B658: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017B65C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017B660: jal         0x80172EC8
    // 0x8017B664: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017B664: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017B668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B670: jr          $ra
    // 0x8017B674: nop

    return;
    // 0x8017B674: nop

;}
RECOMP_FUNC void mnPlayers1PGameBackTo1PMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136CB8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80136CBC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80136CC0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80136CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136CCC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80136CD0: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80136CD4: jal         0x80137F10
    // 0x80136CD8: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    mnPlayers1PGameSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80136CD8: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_0:
    // 0x80136CDC: jal         0x80020A74
    // 0x80136CE0: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_1;
    // 0x80136CE0: nop

    after_1:
    // 0x80136CE4: jal         0x800266A0
    // 0x80136CE8: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x80136CE8: nop

    after_2:
    // 0x80136CEC: jal         0x80005C74
    // 0x80136CF0: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80136CF0: nop

    after_3:
    // 0x80136CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136CFC: jr          $ra
    // 0x80136D00: nop

    return;
    // 0x80136D00: nop

;}
RECOMP_FUNC void itKamexAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180A58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80180A5C: bne         $a1, $zero, L_80180AC0
    if (ctx->r5 != 0) {
        // 0x80180A60: lw          $v1, 0x74($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X74);
            goto L_80180AC0;
    }
    // 0x80180A60: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80180A64: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80180A68: addiu       $t6, $zero, 0x168
    ctx->r14 = ADD32(0, 0X168);
    // 0x80180A6C: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80180A70: bne         $t7, $at, L_80180AC0
    if (ctx->r15 != ctx->r1) {
        // 0x80180A74: sh          $t6, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r14;
            goto L_80180AC0;
    }
    // 0x80180A74: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x80180A78: lw          $t8, 0x2D4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2D4);
    // 0x80180A7C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80180A80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180A84: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80180A88: addiu       $t0, $t0, -0x15A0
    ctx->r8 = ADD32(ctx->r8, -0X15A0);
    // 0x80180A8C: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80180A90: lwc1        $f0, -0x3170($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3170);
    // 0x80180A94: addiu       $t2, $t2, -0x12A0
    ctx->r10 = ADD32(ctx->r10, -0X12A0);
    // 0x80180A98: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80180A9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80180AA0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x80180AA4: sw          $a0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r4;
    // 0x80180AA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180AAC: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80180AB0: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x80180AB4: lwc1        $f6, -0x316C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X316C);
    // 0x80180AB8: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x80180ABC: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
L_80180AC0:
    // 0x80180AC0: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x80180AC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80180AC8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180ACC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80180AD0: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80180AD4: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80180AD8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80180ADC: lwc1        $f16, -0x3168($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3168);
    // 0x80180AE0: sw          $zero, 0x350($v0)
    MEM_W(0X350, ctx->r2) = 0;
    // 0x80180AE4: sw          $zero, 0x358($v0)
    MEM_W(0X358, ctx->r2) = 0;
    // 0x80180AE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80180AEC: jr          $ra
    // 0x80180AF0: swc1        $f18, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80180AF0: swc1        $f18, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mnVSRecordSortData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133FE8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80133FEC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80133FF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133FF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133FF8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80133FFC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80134000: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80134004: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80134008: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8013400C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134010: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
    // 0x80134014: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80134018:
    // 0x80134018: jal         0x80131B24
    // 0x8013401C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetFighterKindByIndex(rdram, ctx);
        goto after_0;
    // 0x8013401C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80134020: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80134024: slti        $at, $s2, 0xC
    ctx->r1 = SIGNED(ctx->r18) < 0XC ? 1 : 0;
    // 0x80134028: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8013402C: bne         $at, $zero, L_80134018
    if (ctx->r1 != 0) {
        // 0x80134030: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80134018;
    }
    // 0x80134030: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80134034: beq         $s6, $zero, L_8013405C
    if (ctx->r22 == 0) {
        // 0x80134038: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8013405C;
    }
    // 0x80134038: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8013403C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134040: beq         $s6, $at, L_8013408C
    if (ctx->r22 == ctx->r1) {
        // 0x80134044: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8013408C;
    }
    // 0x80134044: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80134048: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013404C: beq         $s6, $at, L_801341DC
    if (ctx->r22 == ctx->r1) {
        // 0x80134050: nop
    
            goto L_801341DC;
    }
    // 0x80134050: nop

    // 0x80134054: b           L_80134228
    // 0x80134058: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
        goto L_80134228;
    // 0x80134058: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_8013405C:
    // 0x8013405C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80134060: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_80134064:
    // 0x80134064: jal         0x80131B74
    // 0x80134068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetKOs(rdram, ctx);
        goto after_1;
    // 0x80134068: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8013406C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80134070: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80134074: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80134078: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8013407C: bne         $s2, $s5, L_80134064
    if (ctx->r18 != ctx->r21) {
        // 0x80134080: sdc1        $f6, -0x8($s0)
        CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X8, ctx->r16);
            goto L_80134064;
    }
    // 0x80134080: sdc1        $f6, -0x8($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X8, ctx->r16);
    // 0x80134084: b           L_80134228
    // 0x80134088: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
        goto L_80134228;
    // 0x80134088: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_8013408C:
    // 0x8013408C: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80134090: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80134094: addiu       $s1, $s1, 0x6CC0
    ctx->r17 = ADD32(ctx->r17, 0X6CC0);
    // 0x80134098: addiu       $s3, $s3, 0x44E0
    ctx->r19 = ADD32(ctx->r19, 0X44E0);
    // 0x8013409C: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x801340A0: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x801340A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_801340A8:
    // 0x801340A8: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x801340AC: beq         $at, $zero, L_801341C8
    if (ctx->r1 == 0) {
        // 0x801340B0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801341C8;
    }
    // 0x801340B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801340B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340B8: addu        $at, $at, $t6
    gpr jr_addend_801340C0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801340BC: lw          $t6, 0x6BD0($at)
    ctx->r14 = ADD32(ctx->r1, 0X6BD0);
    // 0x801340C0: jr          $t6
    // 0x801340C4: nop

    switch (jr_addend_801340C0 >> 2) {
        case 0: goto L_801340C8; break;
        case 1: goto L_801340E4; break;
        case 2: goto L_80134108; break;
        case 3: goto L_8013412C; break;
        case 4: goto L_80134148; break;
        case 5: goto L_80134194; break;
        case 6: goto L_801341B0; break;
        default: switch_error(__func__, 0x801340C0, 0x80136BD0);
    }
    // 0x801340C4: nop

L_801340C8:
    // 0x801340C8: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x801340CC: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x801340D0: jal         0x80131D38
    // 0x801340D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetWinPercent(rdram, ctx);
        goto after_2;
    // 0x801340D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x801340D8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x801340DC: b           L_801341C8
    // 0x801340E0: sdc1        $f8, 0x0($s0)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X0, ctx->r16);
        goto L_801341C8;
    // 0x801340E0: sdc1        $f8, 0x0($s0)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X0, ctx->r16);
L_801340E4:
    // 0x801340E4: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x801340E8: addu        $s0, $s4, $t8
    ctx->r16 = ADD32(ctx->r20, ctx->r24);
    // 0x801340EC: jal         0x80131B74
    // 0x801340F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetKOs(rdram, ctx);
        goto after_3;
    // 0x801340F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x801340F4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x801340F8: nop

    // 0x801340FC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80134100: b           L_801341C8
    // 0x80134104: sdc1        $f16, 0x0($s0)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X0, ctx->r16);
        goto L_801341C8;
    // 0x80134104: sdc1        $f16, 0x0($s0)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X0, ctx->r16);
L_80134108:
    // 0x80134108: sll         $t9, $s2, 3
    ctx->r25 = S32(ctx->r18 << 3);
    // 0x8013410C: addu        $s0, $s4, $t9
    ctx->r16 = ADD32(ctx->r20, ctx->r25);
    // 0x80134110: jal         0x80131C0C
    // 0x80134114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetTKO(rdram, ctx);
        goto after_4;
    // 0x80134114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80134118: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8013411C: nop

    // 0x80134120: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80134124: b           L_801341C8
    // 0x80134128: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_801341C8;
    // 0x80134128: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
L_8013412C:
    // 0x8013412C: sll         $t0, $s2, 3
    ctx->r8 = S32(ctx->r18 << 3);
    // 0x80134130: addu        $s0, $s4, $t0
    ctx->r16 = ADD32(ctx->r20, ctx->r8);
    // 0x80134134: jal         0x80134A1C
    // 0x80134138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetSDPercent(rdram, ctx);
        goto after_5;
    // 0x80134138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8013413C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80134140: b           L_801341C8
    // 0x80134144: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
        goto L_801341C8;
    // 0x80134144: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_80134148:
    // 0x80134148: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8013414C: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80134150: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80134154: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80134158: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013415C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80134160: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80134164: sll         $t4, $s2, 3
    ctx->r12 = S32(ctx->r18 << 3);
    // 0x80134168: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x8013416C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80134170: bgez        $t3, L_8013418C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80134174: cvt.d.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
            goto L_8013418C;
    }
    // 0x80134174: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80134178: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8013417C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80134180: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80134184: nop

    // 0x80134188: add.d       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f10.d + ctx->f16.d;
L_8013418C:
    // 0x8013418C: b           L_801341C8
    // 0x80134190: sdc1        $f10, 0x0($t5)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X0, ctx->r13);
        goto L_801341C8;
    // 0x80134190: sdc1        $f10, 0x0($t5)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X0, ctx->r13);
L_80134194:
    // 0x80134194: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x80134198: addu        $s0, $s4, $t6
    ctx->r16 = ADD32(ctx->r20, ctx->r14);
    // 0x8013419C: jal         0x80134978
    // 0x801341A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetUsePercent(rdram, ctx);
        goto after_6;
    // 0x801341A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x801341A4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x801341A8: b           L_801341C8
    // 0x801341AC: sdc1        $f18, 0x0($s0)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X0, ctx->r16);
        goto L_801341C8;
    // 0x801341AC: sdc1        $f18, 0x0($s0)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0X0, ctx->r16);
L_801341B0:
    // 0x801341B0: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x801341B4: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x801341B8: jal         0x801348B4
    // 0x801341BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordGetAvg(rdram, ctx);
        goto after_7;
    // 0x801341BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x801341C0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801341C4: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
L_801341C8:
    // 0x801341C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801341CC: bnel        $s2, $s5, L_801340A8
    if (ctx->r18 != ctx->r21) {
        // 0x801341D0: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_801340A8;
    }
    goto skip_0;
    // 0x801341D0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801341D4: b           L_8013422C
    // 0x801341D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8013422C;
    // 0x801341D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_801341DC:
    // 0x801341DC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801341E0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801341E4: addiu       $s1, $s1, 0x6C58
    ctx->r17 = ADD32(ctx->r17, 0X6C58);
    // 0x801341E8: addiu       $s3, $s3, 0x6CB8
    ctx->r19 = ADD32(ctx->r19, 0X6CB8);
    // 0x801341EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801341F0: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x801341F4: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_801341F8:
    // 0x801341F8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801341FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80134200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80134204: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80134208: jal         0x8013531C
    // 0x8013420C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    mnVSRecordGetWinPercentAgainst(rdram, ctx);
        goto after_8;
    // 0x8013420C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_8:
    // 0x80134210: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80134214: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80134218: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8013421C: bne         $s2, $s5, L_801341F8
    if (ctx->r18 != ctx->r21) {
        // 0x80134220: sdc1        $f6, -0x8($s0)
        CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X8, ctx->r16);
            goto L_801341F8;
    }
    // 0x80134220: sdc1        $f6, -0x8($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, -0X8, ctx->r16);
    // 0x80134224: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_80134228:
    // 0x80134228: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8013422C:
    // 0x8013422C: addiu       $s3, $sp, 0xE8
    ctx->r19 = ADD32(ctx->r29, 0XE8);
L_80134230:
    // 0x80134230: addiu       $s5, $s2, 0x1
    ctx->r21 = ADD32(ctx->r18, 0X1);
    // 0x80134234: slti        $at, $s5, 0xC
    ctx->r1 = SIGNED(ctx->r21) < 0XC ? 1 : 0;
    // 0x80134238: beq         $at, $zero, L_801342C0
    if (ctx->r1 == 0) {
        // 0x8013423C: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_801342C0;
    }
    // 0x8013423C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80134240: addiu       $t2, $sp, 0xB8
    ctx->r10 = ADD32(ctx->r29, 0XB8);
    // 0x80134244: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80134248: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8013424C: addu        $s0, $t3, $t2
    ctx->r16 = ADD32(ctx->r11, ctx->r10);
    // 0x80134250: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
L_80134254:
    // 0x80134254: jal         0x801326EC
    // 0x80134258: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_9;
    // 0x80134258: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x8013425C: beql        $v0, $zero, L_801342A8
    if (ctx->r2 == 0) {
        // 0x80134260: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_801342A8;
    }
    goto skip_1;
    // 0x80134260: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80134264: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80134268: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8013426C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80134270: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80134274: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x80134278: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8013427C: ldc1        $f16, 0x0($t8)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r24, 0X0);
    // 0x80134280: ldc1        $f8, 0x0($t6)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r14, 0X0);
    // 0x80134284: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80134288: nop

    // 0x8013428C: bc1fl       L_801342B8
    if (!c1cs) {
        // 0x80134290: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801342B8;
    }
    goto skip_2;
    // 0x80134290: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x80134294: jal         0x801326EC
    // 0x80134298: nop

    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_10;
    // 0x80134298: nop

    after_10:
    // 0x8013429C: beql        $v0, $zero, L_801342B8
    if (ctx->r2 == 0) {
        // 0x801342A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_801342B8;
    }
    goto skip_3;
    // 0x801342A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_3:
    // 0x801342A4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_801342A8:
    // 0x801342A8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801342AC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801342B0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x801342B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_801342B8:
    // 0x801342B8: bne         $s0, $s3, L_80134254
    if (ctx->r16 != ctx->r19) {
        // 0x801342BC: nop
    
            goto L_80134254;
    }
    // 0x801342BC: nop

L_801342C0:
    // 0x801342C0: slti        $at, $s5, 0xC
    ctx->r1 = SIGNED(ctx->r21) < 0XC ? 1 : 0;
    // 0x801342C4: bne         $at, $zero, L_80134230
    if (ctx->r1 != 0) {
        // 0x801342C8: or          $s2, $s5, $zero
        ctx->r18 = ctx->r21 | 0;
            goto L_80134230;
    }
    // 0x801342C8: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x801342CC: beq         $s6, $zero, L_801342F0
    if (ctx->r22 == 0) {
        // 0x801342D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801342F0;
    }
    // 0x801342D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801342D4: beq         $s6, $at, L_80134338
    if (ctx->r22 == ctx->r1) {
        // 0x801342D8: addiu       $s1, $sp, 0xB8
        ctx->r17 = ADD32(ctx->r29, 0XB8);
            goto L_80134338;
    }
    // 0x801342D8: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
    // 0x801342DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801342E0: beq         $s6, $at, L_8013437C
    if (ctx->r22 == ctx->r1) {
        // 0x801342E4: addiu       $s1, $sp, 0xB8
        ctx->r17 = ADD32(ctx->r29, 0XB8);
            goto L_8013437C;
    }
    // 0x801342E4: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
    // 0x801342E8: b           L_801343BC
    // 0x801342EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801343BC;
    // 0x801342EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801342F0:
    // 0x801342F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801342F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801342F8: addiu       $v1, $v1, 0x6C58
    ctx->r3 = ADD32(ctx->r3, 0X6C58);
    // 0x801342FC: addiu       $v0, $v0, 0x6C28
    ctx->r2 = ADD32(ctx->r2, 0X6C28);
    // 0x80134300: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
L_80134304:
    // 0x80134304: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80134308: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x8013430C: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    // 0x80134310: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80134314: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80134318: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8013431C: sw          $t1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r9;
    // 0x80134320: sw          $t3, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r11;
    // 0x80134324: sw          $t2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r10;
    // 0x80134328: bne         $v0, $v1, L_80134304
    if (ctx->r2 != ctx->r3) {
        // 0x8013432C: sw          $t0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r8;
            goto L_80134304;
    }
    // 0x8013432C: sw          $t0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r8;
    // 0x80134330: b           L_801343BC
    // 0x80134334: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801343BC;
    // 0x80134334: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80134338:
    // 0x80134338: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013433C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134340: addiu       $v1, $v1, 0x6C88
    ctx->r3 = ADD32(ctx->r3, 0X6C88);
    // 0x80134344: addiu       $v0, $v0, 0x6C58
    ctx->r2 = ADD32(ctx->r2, 0X6C58);
L_80134348:
    // 0x80134348: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x8013434C: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x80134350: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x80134354: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134358: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8013435C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80134360: sw          $t5, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r13;
    // 0x80134364: sw          $t6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r14;
    // 0x80134368: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8013436C: bne         $v0, $v1, L_80134348
    if (ctx->r2 != ctx->r3) {
        // 0x80134370: sw          $t4, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r12;
            goto L_80134348;
    }
    // 0x80134370: sw          $t4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r12;
    // 0x80134374: b           L_801343BC
    // 0x80134378: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801343BC;
    // 0x80134378: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8013437C:
    // 0x8013437C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134380: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134384: addiu       $v1, $v1, 0x6CB8
    ctx->r3 = ADD32(ctx->r3, 0X6CB8);
    // 0x80134388: addiu       $v0, $v0, 0x6C88
    ctx->r2 = ADD32(ctx->r2, 0X6C88);
L_8013438C:
    // 0x8013438C: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80134390: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x80134394: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x80134398: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8013439C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801343A0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x801343A4: sw          $t9, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r25;
    // 0x801343A8: sw          $t0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r8;
    // 0x801343AC: sw          $t1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r9;
    // 0x801343B0: bne         $v0, $v1, L_8013438C
    if (ctx->r2 != ctx->r3) {
        // 0x801343B4: sw          $t8, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->r24;
            goto L_8013438C;
    }
    // 0x801343B4: sw          $t8, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r24;
    // 0x801343B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801343BC:
    // 0x801343BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801343C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801343C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801343C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801343CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801343D0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801343D4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801343D8: jr          $ra
    // 0x801343DC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x801343DC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void itNBumperWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B608: jal         0x80172E74
    // 0x8017B60C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x8017B60C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017B610: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B614: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017B618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017B61C: jal         0x80172EC8
    // 0x8017B620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017B620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017B624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B62C: jr          $ra
    // 0x8017B630: nop

    return;
    // 0x8017B630: nop

;}
RECOMP_FUNC void func_ovl8_80384F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384F90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80384F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384F98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80384F9C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80384FA0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384FA4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80384FA8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80384FAC: lh          $t6, 0xB0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB0);
    // 0x80384FB0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80384FB4: lw          $t9, 0xB4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB4);
    // 0x80384FB8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x80384FBC: jalr        $t9
    // 0x80384FC0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384FC0: nop

    after_0:
    // 0x80384FC4: lh          $v0, 0x36($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X36);
    // 0x80384FC8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80384FCC: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x80384FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384FD4: lh          $t7, 0x44($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X44);
    // 0x80384FD8: lh          $t0, 0x3C($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X3C);
    // 0x80384FDC: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x80384FE0: bne         $t7, $zero, L_80384FEC
    if (ctx->r15 != 0) {
        // 0x80384FE4: nop
    
            goto L_80384FEC;
    }
    // 0x80384FE4: nop

    // 0x80384FE8: break       7
    do_break(2151174120);
L_80384FEC:
    // 0x80384FEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80384FF0: bne         $t7, $at, L_80385004
    if (ctx->r15 != ctx->r1) {
        // 0x80384FF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80385004;
    }
    // 0x80384FF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80384FF8: bne         $v0, $at, L_80385004
    if (ctx->r2 != ctx->r1) {
        // 0x80384FFC: nop
    
            goto L_80385004;
    }
    // 0x80384FFC: nop

    // 0x80385000: break       6
    do_break(2151174144);
L_80385004:
    // 0x80385004: mflo        $t8
    ctx->r24 = lo;
    // 0x80385008: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8038500C: beq         $at, $zero, L_80385018
    if (ctx->r1 == 0) {
        // 0x80385010: addu        $v1, $t8, $t0
        ctx->r3 = ADD32(ctx->r24, ctx->r8);
            goto L_80385018;
    }
    // 0x80385010: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x80385014: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80385018:
    // 0x80385018: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8038501C: jr          $ra
    // 0x80385020: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80385020: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_8037EBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EBC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8037EBCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037EBD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037EBD4: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x8037EBD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037EBDC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8037EBE0: beql        $t6, $zero, L_8037EDE4
    if (ctx->r14 == 0) {
        // 0x8037EBE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037EDE4;
    }
    goto skip_0;
    // 0x8037EBE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8037EBE8: jal         0x8037E7A8
    // 0x8037EBEC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_0;
    // 0x8037EBEC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8037EBF0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8037EBF4: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8037EBF8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037EBFC: lh          $t7, 0x20($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X20);
    // 0x8037EC00: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x8037EC04: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x8037EC08: jalr        $t9
    // 0x8037EC0C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037EC0C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_1:
    // 0x8037EC10: jal         0x8037D95C
    // 0x8037EC14: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_ovl8_8037D95C(rdram, ctx);
        goto after_2;
    // 0x8037EC14: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x8037EC18: jal         0x8037D990
    // 0x8037EC1C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_3;
    // 0x8037EC1C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x8037EC20: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8037EC24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8037EC28: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037EC2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037EC30: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8037EC34: nop

    // 0x8037EC38: bc1fl       L_8037ED14
    if (!c1cs) {
        // 0x8037EC3C: lw          $a3, 0x38($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X38);
            goto L_8037ED14;
    }
    goto skip_1;
    // 0x8037EC3C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x8037EC40: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8037EC44: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    // 0x8037EC48: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037EC4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037EC50: jal         0x8037B434
    // 0x8037EC54: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B434(rdram, ctx);
        goto after_4;
    // 0x8037EC54: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_4:
    // 0x8037EC58: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037EC5C: jal         0x8037D9D0
    // 0x8037EC60: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_5;
    // 0x8037EC60: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    after_5:
    // 0x8037EC64: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8037EC68: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8037EC6C: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
    // 0x8037EC70: sh          $t8, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r24;
    // 0x8037EC74: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    // 0x8037EC78: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8037EC7C: jal         0x8037A5B8
    // 0x8037EC80: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_6;
    // 0x8037EC80: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x8037EC84: jal         0x8037D9B4
    // 0x8037EC88: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_7;
    // 0x8037EC88: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x8037EC8C: jal         0x8037E80C
    // 0x8037EC90: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_8;
    // 0x8037EC90: nop

    after_8:
    // 0x8037EC94: lhu         $t1, 0x54($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X54);
    // 0x8037EC98: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8037EC9C: lhu         $t5, 0x56($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X56);
    // 0x8037ECA0: bgez        $t1, L_8037ECB0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8037ECA4: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8037ECB0;
    }
    // 0x8037ECA4: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8037ECA8: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8037ECAC: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8037ECB0:
    // 0x8037ECB0: bgez        $t3, L_8037ECC0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8037ECB4: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8037ECC0;
    }
    // 0x8037ECB4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8037ECB8: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8037ECBC: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8037ECC0:
    // 0x8037ECC0: subu        $a0, $t2, $t4
    ctx->r4 = SUB32(ctx->r10, ctx->r12);
    // 0x8037ECC4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037ECC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037ECCC: bgez        $t5, L_8037ECDC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8037ECD0: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8037ECDC;
    }
    // 0x8037ECD0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8037ECD4: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8037ECD8: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8037ECDC:
    // 0x8037ECDC: bgez        $v0, L_8037ECEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8037ECE0: sra         $t7, $v0, 1
        ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8037ECEC;
    }
    // 0x8037ECE0: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8037ECE4: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8037ECE8: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8037ECEC:
    // 0x8037ECEC: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x8037ECF0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037ECF4: jal         0x8037DFCC
    // 0x8037ECF8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_9;
    // 0x8037ECF8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_9:
    // 0x8037ECFC: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    // 0x8037ED00: jal         0x8037DD60
    // 0x8037ED04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_10;
    // 0x8037ED04: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x8037ED08: b           L_8037EDD8
    // 0x8037ED0C: nop

        goto L_8037EDD8;
    // 0x8037ED0C: nop

    // 0x8037ED10: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
L_8037ED14:
    // 0x8037ED14: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x8037ED18: jal         0x8037B434
    // 0x8037ED1C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B434(rdram, ctx);
        goto after_11;
    // 0x8037ED1C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_11:
    // 0x8037ED20: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037ED24: jal         0x8037D9D0
    // 0x8037ED28: addiu       $a0, $a0, -0x60B0
    ctx->r4 = ADD32(ctx->r4, -0X60B0);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_12;
    // 0x8037ED28: addiu       $a0, $a0, -0x60B0
    ctx->r4 = ADD32(ctx->r4, -0X60B0);
    after_12:
    // 0x8037ED2C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8037ED30: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8037ED34: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x8037ED38: sh          $t9, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r25;
    // 0x8037ED3C: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x8037ED40: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8037ED44: jal         0x8037A5B8
    // 0x8037ED48: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_13;
    // 0x8037ED48: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_13:
    // 0x8037ED4C: jal         0x8037D9B4
    // 0x8037ED50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_14;
    // 0x8037ED50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_14:
    // 0x8037ED54: jal         0x8037E80C
    // 0x8037ED58: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_15;
    // 0x8037ED58: nop

    after_15:
    // 0x8037ED5C: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x8037ED60: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8037ED64: lhu         $t4, 0x56($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X56);
    // 0x8037ED68: bgez        $t0, L_8037ED78
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8037ED6C: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8037ED78;
    }
    // 0x8037ED6C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8037ED70: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8037ED74: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8037ED78:
    // 0x8037ED78: bgez        $t3, L_8037ED88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8037ED7C: sra         $t2, $t3, 1
        ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8037ED88;
    }
    // 0x8037ED7C: sra         $t2, $t3, 1
    ctx->r10 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8037ED80: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8037ED84: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8037ED88:
    // 0x8037ED88: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    // 0x8037ED8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037ED90: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037ED94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037ED98: bgez        $t4, L_8037EDA8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8037ED9C: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8037EDA8;
    }
    // 0x8037ED9C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8037EDA0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8037EDA4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8037EDA8:
    // 0x8037EDA8: bgez        $v0, L_8037EDB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8037EDAC: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8037EDB8;
    }
    // 0x8037EDAC: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8037EDB0: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8037EDB4: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8037EDB8:
    // 0x8037EDB8: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    // 0x8037EDBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037EDC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037EDC4: jal         0x8037DFCC
    // 0x8037EDC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_16;
    // 0x8037EDC8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_16:
    // 0x8037EDCC: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x8037EDD0: jal         0x8037DD60
    // 0x8037EDD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_17;
    // 0x8037EDD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
L_8037EDD8:
    // 0x8037EDD8: jal         0x8037D908
    // 0x8037EDDC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_ovl8_8037D908(rdram, ctx);
        goto after_18;
    // 0x8037EDDC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_18:
    // 0x8037EDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037EDE4:
    // 0x8037EDE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037EDE8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8037EDEC: jr          $ra
    // 0x8037EDF0: nop

    return;
    // 0x8037EDF0: nop

;}
RECOMP_FUNC void wpPikachuThunderTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A8D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016A8DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A8E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016A8E4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016A8E8: jal         0x80167FE8
    // 0x8016A8EC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016A8EC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016A8F0: beq         $v0, $zero, L_8016A900
    if (ctx->r2 == 0) {
        // 0x8016A8F4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8016A900;
    }
    // 0x8016A8F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A8F8: b           L_8016A940
    // 0x8016A8FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A940;
    // 0x8016A8FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A900:
    // 0x8016A900: lw          $t7, 0x268($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X268);
    // 0x8016A904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016A908: slti        $at, $t7, 0x6
    ctx->r1 = SIGNED(ctx->r15) < 0X6 ? 1 : 0;
    // 0x8016A90C: beq         $at, $zero, L_8016A924
    if (ctx->r1 == 0) {
        // 0x8016A910: nop
    
            goto L_8016A924;
    }
    // 0x8016A910: nop

    // 0x8016A914: jal         0x8016A680
    // 0x8016A918: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    wpPikachuThunderHeadMakeTrailEffect(rdram, ctx);
        goto after_1;
    // 0x8016A918: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x8016A91C: b           L_8016A940
    // 0x8016A920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A940;
    // 0x8016A920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A924:
    // 0x8016A924: jal         0x80018994
    // 0x8016A928: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8016A928: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8016A92C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016A930: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x8016A934: lw          $t0, 0x80($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X80);
    // 0x8016A938: sh          $v0, 0x80($t0)
    MEM_H(0X80, ctx->r8) = ctx->r2;
    // 0x8016A93C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A940:
    // 0x8016A940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016A948: jr          $ra
    // 0x8016A94C: nop

    return;
    // 0x8016A94C: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C46C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015C470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C474: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015C478: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015C47C: lw          $t7, 0x9C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C8);
    // 0x8015C480: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8015C484: jal         0x800DEEC8
    // 0x8015C488: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015C488: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8015C48C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015C490: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8015C494: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8015C498: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015C49C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8015C4A0: jal         0x800E6F24
    // 0x8015C4A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015C4A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015C4A8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8015C4AC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8015C4B0: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8015C4B4: sb          $t0, 0x148($t1)
    MEM_B(0X148, ctx->r9) = ctx->r8;
    // 0x8015C4B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C4BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015C4C0: jr          $ra
    // 0x8015C4C4: nop

    return;
    // 0x8015C4C4: nop

;}

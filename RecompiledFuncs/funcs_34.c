#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningYosterMakeFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BEC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80131BF0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131BF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131BF8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80131BFC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80131C00: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80131C04: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80131C08: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80131C0C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80131C10: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80131C14: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80131C18: addiu       $t7, $t7, 0x2368
    ctx->r15 = ADD32(ctx->r15, 0X2368);
    // 0x80131C1C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C20: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131C24: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x80131C28: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131C2C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131C30: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131C34: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131C38: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80131C3C: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x80131C40: addiu       $t0, $t0, 0x6DD0
    ctx->r8 = ADD32(ctx->r8, 0X6DD0);
    // 0x80131C44: addiu       $t4, $t0, 0x3C
    ctx->r12 = ADD32(ctx->r8, 0X3C);
    // 0x80131C48: or          $t3, $s4, $zero
    ctx->r11 = ctx->r20 | 0;
    // 0x80131C4C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131C50: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_80131C54:
    // 0x80131C54: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80131C58: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80131C5C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80131C60: sw          $t2, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r10;
    // 0x80131C64: lw          $t1, -0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X8);
    // 0x80131C68: sw          $t1, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r9;
    // 0x80131C6C: lw          $t2, -0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, -0X4);
    // 0x80131C70: bne         $t0, $t4, L_80131C54
    if (ctx->r8 != ctx->r12) {
        // 0x80131C74: sw          $t2, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r10;
            goto L_80131C54;
    }
    // 0x80131C74: sw          $t2, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r10;
    // 0x80131C78: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80131C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C80: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80131C84: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131C88: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80131C8C: addiu       $s2, $s2, 0x2428
    ctx->r18 = ADD32(ctx->r18, 0X2428);
    // 0x80131C90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131C94: addiu       $s3, $sp, 0x8C
    ctx->r19 = ADD32(ctx->r29, 0X8C);
    // 0x80131C98: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80131C9C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_80131CA0:
    // 0x80131CA0: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80131CA4: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80131CA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80131CAC: jal         0x800EC0EC
    // 0x80131CB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131CB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80131CB4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80131CB8: sb          $v0, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r2;
    // 0x80131CBC: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x80131CC0: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80131CC4: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x80131CC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80131CCC: jal         0x800D7F3C
    // 0x80131CD0: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131CD0: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    after_1:
    // 0x80131CD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131CD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CDC: jal         0x803905CC
    // 0x80131CE0: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131CE0: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x80131CE4: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x80131CE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131CEC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80131CF0: swc1        $f22, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f22.u32l;
    // 0x80131CF4: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x80131CF8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80131CFC: swc1        $f22, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f22.u32l;
    // 0x80131D00: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80131D04: bne         $s0, $s5, L_80131CA0
    if (ctx->r16 != ctx->r21) {
        // 0x80131D08: swc1        $f22, 0x48($t9)
        MEM_W(0X48, ctx->r25) = ctx->f22.u32l;
            goto L_80131CA0;
    }
    // 0x80131D08: swc1        $f22, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f22.u32l;
    // 0x80131D0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131D10: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80131D14: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80131D18: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80131D1C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80131D20: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80131D24: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80131D28: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80131D2C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80131D30: jr          $ra
    // 0x80131D34: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80131D34: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void mvOpeningSamusInitName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8018D164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D168: sb          $v0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r2;
    // 0x8018D16C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x8018D170: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8018D174: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8018D178: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x8018D17C: sb          $v0, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r2;
    // 0x8018D180: sb          $v0, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r2;
    // 0x8018D184: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8018D188: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x8018D18C: jr          $ra
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void itGLuckyCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C4AC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017C4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C4B4: jr          $ra
    // 0x8017C4B8: sw          $zero, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = 0;
    return;
    // 0x8017C4B8: sw          $zero, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = 0;
;}
RECOMP_FUNC void ftPikachuSpecialAirLwHitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015242C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152430: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80152434: beql        $t6, $zero, L_80152448
    if (ctx->r14 == 0) {
        // 0x80152438: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80152448;
    }
    goto skip_0;
    // 0x80152438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015243C: jal         0x80152764
    // 0x80152440: nop

    ftPikachuSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152440: nop

    after_0:
    // 0x80152444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152448:
    // 0x80152448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015244C: jr          $ra
    // 0x80152450: nop

    return;
    // 0x80152450: nop

;}
RECOMP_FUNC void mvOpeningDonkeyMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB54: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB5C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB60: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DB64: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DB68: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DB6C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DB70: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DB74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DB78: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DB7C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DB80: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DB84: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DB88: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DB8C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DB90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DB94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DB98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DB9C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBA0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBA8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBAC: jal         0x8000B93C
    // 0x8018DBB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBBC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBC0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DBC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DBC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DBCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DBD0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DBD4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DBD8: jal         0x80007080
    // 0x8018DBDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DBDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DBE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DBE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DBE8: jr          $ra
    // 0x8018DBEC: nop

    return;
    // 0x8018DBEC: nop

;}
RECOMP_FUNC void mnVSResultsMakeConfetti(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138830: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80138834: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80138838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013883C: addiu       $t7, $t7, -0x6908
    ctx->r15 = ADD32(ctx->r15, -0X6908);
    // 0x80138840: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80138844: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80138848: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013884C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80138850: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80138854: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80138858: addiu       $t0, $t0, -0x68FC
    ctx->r8 = ADD32(ctx->r8, -0X68FC);
    // 0x8013885C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80138860: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80138864: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80138868: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8013886C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138870: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80138874: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80138878: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8013887C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80138880: jal         0x80104554
    // 0x80138884: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    efManagerConfettiMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80138884: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    after_0:
    // 0x80138888: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8013888C: jal         0x80104554
    // 0x80138890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    efManagerConfettiMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80138890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80138894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80138898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013889C: jr          $ra
    // 0x801388A0: nop

    return;
    // 0x801388A0: nop

;}
RECOMP_FUNC void itHitokageCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183DE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80183DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183DE8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80183DEC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80183DF0: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x80183DF4: lwc1        $f6, 0x350($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X350);
    // 0x80183DF8: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80183DFC: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80183E00: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x80183E04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80183E08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80183E0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80183E10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80183E14: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80183E18: lwc1        $f16, 0x354($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X354);
    // 0x80183E1C: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80183E20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80183E24: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80183E28: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80183E2C: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80183E30: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80183E34: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80183E38: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80183E3C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80183E40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80183E44: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80183E48: lhu         $a1, 0x35C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X35C);
    // 0x80183E4C: beq         $a1, $at, L_80183E90
    if (ctx->r5 == ctx->r1) {
        // 0x80183E50: andi        $t8, $a1, 0x1
        ctx->r24 = ctx->r5 & 0X1;
            goto L_80183E90;
    }
    // 0x80183E50: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80183E54: beq         $t8, $zero, L_80183ED8
    if (ctx->r24 == 0) {
        // 0x80183E58: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80183ED8;
    }
    // 0x80183E58: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80183E5C: lwc1        $f0, 0x7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80183E60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80183E64: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80183E68: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80183E6C: nop

    // 0x80183E70: bc1fl       L_80183EDC
    if (!c1cs) {
        // 0x80183E74: lw          $t3, 0x80($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X80);
            goto L_80183EDC;
    }
    goto skip_0;
    // 0x80183E74: lw          $t3, 0x80($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X80);
    skip_0:
    // 0x80183E78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80183E7C: nop

    // 0x80183E80: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80183E84: nop

    // 0x80183E88: bc1fl       L_80183EDC
    if (!c1cs) {
        // 0x80183E8C: lw          $t3, 0x80($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X80);
            goto L_80183EDC;
    }
    goto skip_1;
    // 0x80183E8C: lw          $t3, 0x80($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X80);
    skip_1:
L_80183E90:
    // 0x80183E90: lw          $t0, 0x80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X80);
    // 0x80183E94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80183E98: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80183E9C: sh          $t9, 0x80($t0)
    MEM_H(0X80, ctx->r8) = ctx->r25;
    // 0x80183EA0: lhu         $a0, 0x35E($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X35E);
    // 0x80183EA4: bgtz        $a0, L_80183ED0
    if (SIGNED(ctx->r4) > 0) {
        // 0x80183EA8: addiu       $t2, $a0, -0x1
        ctx->r10 = ADD32(ctx->r4, -0X1);
            goto L_80183ED0;
    }
    // 0x80183EA8: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x80183EAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80183EB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80183EB4: jal         0x801843C4
    // 0x80183EB8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    itHitokageCommonMakeFlame(rdram, ctx);
        goto after_0;
    // 0x80183EB8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80183EBC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80183EC0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80183EC4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80183EC8: b           L_80183EE0
    // 0x80183ECC: sh          $t1, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r9;
        goto L_80183EE0;
    // 0x80183ECC: sh          $t1, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r9;
L_80183ED0:
    // 0x80183ED0: b           L_80183EE0
    // 0x80183ED4: sh          $t2, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r10;
        goto L_80183EE0;
    // 0x80183ED4: sh          $t2, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r10;
L_80183ED8:
    // 0x80183ED8: lw          $t3, 0x80($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X80);
L_80183EDC:
    // 0x80183EDC: sh          $zero, 0x80($t3)
    MEM_H(0X80, ctx->r11) = 0;
L_80183EE0:
    // 0x80183EE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80183EE4: lwc1        $f18, -0x30F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X30F0);
    // 0x80183EE8: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80183EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80183EF0: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80183EF4: nop

    // 0x80183EF8: bc1f        L_80183F10
    if (!c1cs) {
        // 0x80183EFC: nop
    
            goto L_80183F10;
    }
    // 0x80183EFC: nop

    // 0x80183F00: jal         0x8010B0B8
    // 0x80183F04: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_1;
    // 0x80183F04: nop

    after_1:
    // 0x80183F08: b           L_80183F10
    // 0x80183F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80183F10;
    // 0x80183F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80183F10:
    // 0x80183F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183F14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80183F18: jr          $ra
    // 0x80183F1C: nop

    return;
    // 0x80183F1C: nop

;}
RECOMP_FUNC void func_ovl8_80377134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377138: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037713C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80377140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377148: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037714C: addiu       $a2, $a2, -0x609C
    ctx->r6 = ADD32(ctx->r6, -0X609C);
    // 0x80377150: jal         0x80376B60
    // 0x80377154: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_ovl8_80376B60(rdram, ctx);
        goto after_0;
    // 0x80377154: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80377158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037715C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377160: jr          $ra
    // 0x80377164: nop

    return;
    // 0x80377164: nop

;}
RECOMP_FUNC void mnVSResultsInitRankings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801373B4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801373B8: lbu         $t6, 0x4D0B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D0B);
    // 0x801373BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801373C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801373C4: bne         $t6, $at, L_801373F4
    if (ctx->r14 != ctx->r1) {
        // 0x801373C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801373F4;
    }
    // 0x801373C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801373CC: jal         0x80136A9C
    // 0x801373D0: nop

    mnVSResultsSetKOs(rdram, ctx);
        goto after_0;
    // 0x801373D0: nop

    after_0:
    // 0x801373D4: jal         0x80136B1C
    // 0x801373D8: nop

    mnVSResultsSetTKO(rdram, ctx);
        goto after_1;
    // 0x801373D8: nop

    after_1:
    // 0x801373DC: jal         0x80136B9C
    // 0x801373E0: nop

    mnVSResultsSetPoints(rdram, ctx);
        goto after_2;
    // 0x801373E0: nop

    after_2:
    // 0x801373E4: jal         0x80137334
    // 0x801373E8: nop

    mnVSResultsSetPlaceStock(rdram, ctx);
        goto after_3;
    // 0x801373E8: nop

    after_3:
    // 0x801373EC: b           L_80137414
    // 0x801373F0: nop

        goto L_80137414;
    // 0x801373F0: nop

L_801373F4:
    // 0x801373F4: jal         0x80136A9C
    // 0x801373F8: nop

    mnVSResultsSetKOs(rdram, ctx);
        goto after_4;
    // 0x801373F8: nop

    after_4:
    // 0x801373FC: jal         0x80136B1C
    // 0x80137400: nop

    mnVSResultsSetTKO(rdram, ctx);
        goto after_5;
    // 0x80137400: nop

    after_5:
    // 0x80137404: jal         0x80136B9C
    // 0x80137408: nop

    mnVSResultsSetPoints(rdram, ctx);
        goto after_6;
    // 0x80137408: nop

    after_6:
    // 0x8013740C: jal         0x801372F4
    // 0x80137410: nop

    mnVSResultsSetPlaceTime(rdram, ctx);
        goto after_7;
    // 0x80137410: nop

    after_7:
L_80137414:
    // 0x80137414: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137418: lw          $t7, -0x63F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63F0);
    // 0x8013741C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80137420: bne         $t7, $at, L_8013743C
    if (ctx->r15 != ctx->r1) {
        // 0x80137424: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_8013743C;
    }
    // 0x80137424: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137428: sw          $zero, -0x644C($at)
    MEM_W(-0X644C, ctx->r1) = 0;
    // 0x8013742C: sw          $zero, -0x6450($at)
    MEM_W(-0X6450, ctx->r1) = 0;
    // 0x80137430: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137434: sw          $zero, -0x6448($at)
    MEM_W(-0X6448, ctx->r1) = 0;
    // 0x80137438: sw          $zero, -0x6444($at)
    MEM_W(-0X6444, ctx->r1) = 0;
L_8013743C:
    // 0x8013743C: jal         0x8013315C
    // 0x80137440: nop

    mnVSResultsSetFighterKindAll(rdram, ctx);
        goto after_8;
    // 0x80137440: nop

    after_8:
    // 0x80137444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013744C: jr          $ra
    // 0x80137450: nop

    return;
    // 0x80137450: nop

;}
RECOMP_FUNC void ftPurinSpecialHiSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151654: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80151658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015165C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151660: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151664: jal         0x800DEEC8
    // 0x80151668: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80151668: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015166C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151670: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x80151674: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80151678: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015167C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151680: jal         0x800E6F24
    // 0x80151684: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151684: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151688: jal         0x800D8EB8
    // 0x8015168C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015168C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80151690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151694: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151698: jr          $ra
    // 0x8015169C: nop

    return;
    // 0x8015169C: nop

;}
RECOMP_FUNC void mnPlayers1PGameCursorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136D58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80136D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136D60: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80136D64: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80136D68: jal         0x801361C8
    // 0x80136D6C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    mnPlayers1PGameAdjustCursor(rdram, ctx);
        goto after_0;
    // 0x80136D6C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80136D70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136D74: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80136D78: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x80136D7C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80136D80: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80136D84: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80136D88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80136D8C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80136D90: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80136D94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136D98: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80136D9C: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80136DA0: beq         $t0, $zero, L_80136E84
    if (ctx->r8 == 0) {
        // 0x80136DA4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80136E84;
    }
    // 0x80136DA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80136DA8: jal         0x80135C04
    // 0x80136DAC: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    mnPlayers1PGameCheckSelectFighter(rdram, ctx);
        goto after_1;
    // 0x80136DAC: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    after_1:
    // 0x80136DB0: bne         $v0, $zero, L_80136E84
    if (ctx->r2 != 0) {
        // 0x80136DB4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80136E84;
    }
    // 0x80136DB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136DB8: jal         0x80135E2C
    // 0x80136DBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    mnPlayers1PGameCheckCursorPuckGrab(rdram, ctx);
        goto after_2;
    // 0x80136DBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80136DC0: bnel        $v0, $zero, L_80136E88
    if (ctx->r2 != 0) {
        // 0x80136DC4: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80136E88;
    }
    goto skip_0;
    // 0x80136DC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80136DC8: jal         0x801354CC
    // 0x80136DCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameCheckTimeArrowRInRange(rdram, ctx);
        goto after_3;
    // 0x80136DCC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80136DD0: beq         $v0, $zero, L_80136E04
    if (ctx->r2 == 0) {
        // 0x80136DD4: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80136E04;
    }
    // 0x80136DD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136DD8: jal         0x80138118
    // 0x80136DDC: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    mnPlayers1PGameGetNextTimeValue(rdram, ctx);
        goto after_4;
    // 0x80136DDC: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_4:
    // 0x80136DE0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136DE4: addiu       $v1, $v1, -0x7080
    ctx->r3 = ADD32(ctx->r3, -0X7080);
    // 0x80136DE8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80136DEC: jal         0x80133804
    // 0x80136DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameMakeTimeSelect(rdram, ctx);
        goto after_5;
    // 0x80136DF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80136DF4: jal         0x800269C0
    // 0x80136DF8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80136DF8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_6:
    // 0x80136DFC: b           L_80136E88
    // 0x80136E00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_80136E88;
    // 0x80136E00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80136E04:
    // 0x80136E04: jal         0x80135594
    // 0x80136E08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameCheckTimeArrowLInRange(rdram, ctx);
        goto after_7;
    // 0x80136E08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80136E0C: beq         $v0, $zero, L_80136E44
    if (ctx->r2 == 0) {
        // 0x80136E10: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80136E44;
    }
    // 0x80136E10: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136E14: addiu       $v1, $v1, -0x7080
    ctx->r3 = ADD32(ctx->r3, -0X7080);
    // 0x80136E18: jal         0x80138134
    // 0x80136E1C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    mnPlayers1PGameGetPrevTimeValue(rdram, ctx);
        goto after_8;
    // 0x80136E1C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_8:
    // 0x80136E20: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136E24: addiu       $v1, $v1, -0x7080
    ctx->r3 = ADD32(ctx->r3, -0X7080);
    // 0x80136E28: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80136E2C: jal         0x80133804
    // 0x80136E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameMakeTimeSelect(rdram, ctx);
        goto after_9;
    // 0x80136E30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80136E34: jal         0x800269C0
    // 0x80136E38: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80136E38: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_10:
    // 0x80136E3C: b           L_80136E88
    // 0x80136E40: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_80136E88;
    // 0x80136E40: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80136E44:
    // 0x80136E44: jal         0x8013565C
    // 0x80136E48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameCheckBackInRange(rdram, ctx);
        goto after_11;
    // 0x80136E48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x80136E4C: beq         $v0, $zero, L_80136E6C
    if (ctx->r2 == 0) {
        // 0x80136E50: nop
    
            goto L_80136E6C;
    }
    // 0x80136E50: nop

    // 0x80136E54: jal         0x80136CB8
    // 0x80136E58: nop

    mnPlayers1PGameBackTo1PMode(rdram, ctx);
        goto after_12;
    // 0x80136E58: nop

    after_12:
    // 0x80136E5C: jal         0x800269C0
    // 0x80136E60: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_13;
    // 0x80136E60: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_13:
    // 0x80136E64: b           L_80136E88
    // 0x80136E68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_80136E88;
    // 0x80136E68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80136E6C:
    // 0x80136E6C: jal         0x8013684C
    // 0x80136E70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameCheckLevelArrowPress(rdram, ctx);
        goto after_14;
    // 0x80136E70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_14:
    // 0x80136E74: bnel        $v0, $zero, L_80136E88
    if (ctx->r2 != 0) {
        // 0x80136E78: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80136E88;
    }
    goto skip_1;
    // 0x80136E78: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80136E7C: jal         0x80136A84
    // 0x80136E80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameCheckStockArrowPress(rdram, ctx);
        goto after_15;
    // 0x80136E80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_15:
L_80136E84:
    // 0x80136E84: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80136E88:
    // 0x80136E88: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136E8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136E90: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x80136E94: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80136E98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80136E9C: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80136EA0: beql        $t3, $zero, L_80136ED4
    if (ctx->r11 == 0) {
        // 0x80136EA4: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_80136ED4;
    }
    goto skip_2;
    // 0x80136EA4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80136EA8: jal         0x80135C04
    // 0x80136EAC: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    mnPlayers1PGameCheckSelectFighter(rdram, ctx);
        goto after_16;
    // 0x80136EAC: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    after_16:
    // 0x80136EB0: bne         $v0, $zero, L_80136ED0
    if (ctx->r2 != 0) {
        // 0x80136EB4: lui         $t4, 0x8014
        ctx->r12 = S32(0X8014 << 16);
            goto L_80136ED0;
    }
    // 0x80136EB4: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80136EB8: lw          $t4, -0x70C0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X70C0);
    // 0x80136EBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80136EC0: beql        $t4, $zero, L_80136ED4
    if (ctx->r12 == 0) {
        // 0x80136EC4: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_80136ED4;
    }
    goto skip_3;
    // 0x80136EC4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80136EC8: jal         0x80136B44
    // 0x80136ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PGameUpdateCostume(rdram, ctx);
        goto after_17;
    // 0x80136ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
L_80136ED0:
    // 0x80136ED0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_80136ED4:
    // 0x80136ED4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136ED8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136EDC: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80136EE0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80136EE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80136EE8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80136EEC: beql        $t7, $zero, L_80136F20
    if (ctx->r15 == 0) {
        // 0x80136EF0: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80136F20;
    }
    goto skip_4;
    // 0x80136EF0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80136EF4: jal         0x80135C04
    // 0x80136EF8: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    mnPlayers1PGameCheckSelectFighter(rdram, ctx);
        goto after_18;
    // 0x80136EF8: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    after_18:
    // 0x80136EFC: bne         $v0, $zero, L_80136F1C
    if (ctx->r2 != 0) {
        // 0x80136F00: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_80136F1C;
    }
    // 0x80136F00: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136F04: lw          $t8, -0x70C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X70C0);
    // 0x80136F08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80136F0C: beql        $t8, $zero, L_80136F20
    if (ctx->r24 == 0) {
        // 0x80136F10: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80136F20;
    }
    goto skip_5;
    // 0x80136F10: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80136F14: jal         0x80136B44
    // 0x80136F18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnPlayers1PGameUpdateCostume(rdram, ctx);
        goto after_19;
    // 0x80136F18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
L_80136F1C:
    // 0x80136F1C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80136F20:
    // 0x80136F20: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136F24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136F28: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x80136F2C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80136F30: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80136F34: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80136F38: beql        $t1, $zero, L_80136F6C
    if (ctx->r9 == 0) {
        // 0x80136F3C: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_80136F6C;
    }
    goto skip_6;
    // 0x80136F3C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80136F40: jal         0x80135C04
    // 0x80136F44: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    mnPlayers1PGameCheckSelectFighter(rdram, ctx);
        goto after_20;
    // 0x80136F44: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    after_20:
    // 0x80136F48: bne         $v0, $zero, L_80136F68
    if (ctx->r2 != 0) {
        // 0x80136F4C: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80136F68;
    }
    // 0x80136F4C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136F50: lw          $t2, -0x70C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X70C0);
    // 0x80136F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80136F58: beql        $t2, $zero, L_80136F6C
    if (ctx->r10 == 0) {
        // 0x80136F5C: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_80136F6C;
    }
    goto skip_7;
    // 0x80136F5C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80136F60: jal         0x80136B44
    // 0x80136F64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnPlayers1PGameUpdateCostume(rdram, ctx);
        goto after_21;
    // 0x80136F64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
L_80136F68:
    // 0x80136F68: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80136F6C:
    // 0x80136F6C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136F70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80136F74: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80136F78: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80136F7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80136F80: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80136F84: beql        $t5, $zero, L_80136FB8
    if (ctx->r13 == 0) {
        // 0x80136F88: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80136FB8;
    }
    goto skip_8;
    // 0x80136F88: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80136F8C: jal         0x80135C04
    // 0x80136F90: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    mnPlayers1PGameCheckSelectFighter(rdram, ctx);
        goto after_22;
    // 0x80136F90: lw          $a2, -0x70C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X70C4);
    after_22:
    // 0x80136F94: bne         $v0, $zero, L_80136FB4
    if (ctx->r2 != 0) {
        // 0x80136F98: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_80136FB4;
    }
    // 0x80136F98: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136F9C: lw          $t6, -0x70C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X70C0);
    // 0x80136FA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80136FA4: beql        $t6, $zero, L_80136FB8
    if (ctx->r14 == 0) {
        // 0x80136FA8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80136FB8;
    }
    goto skip_9;
    // 0x80136FA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80136FAC: jal         0x80136B44
    // 0x80136FB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    mnPlayers1PGameUpdateCostume(rdram, ctx);
        goto after_23;
    // 0x80136FB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
L_80136FB4:
    // 0x80136FB4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80136FB8:
    // 0x80136FB8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136FBC: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80136FC0: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80136FC4: beq         $t9, $zero, L_80136FE4
    if (ctx->r25 == 0) {
        // 0x80136FC8: nop
    
            goto L_80136FE4;
    }
    // 0x80136FC8: nop

    // 0x80136FCC: jal         0x80136BAC
    // 0x80136FD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PGameCheckManFighterSelected(rdram, ctx);
        goto after_24;
    // 0x80136FD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_24:
    // 0x80136FD4: beq         $v0, $zero, L_80136FE4
    if (ctx->r2 == 0) {
        // 0x80136FD8: nop
    
            goto L_80136FE4;
    }
    // 0x80136FD8: nop

    // 0x80136FDC: jal         0x80136BD4
    // 0x80136FE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayers1PGameRecallPuck(rdram, ctx);
        goto after_25;
    // 0x80136FE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_25:
L_80136FE4:
    // 0x80136FE4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136FE8: lw          $v0, -0x70E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X70E8);
    // 0x80136FEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80136FF0: bne         $v0, $zero, L_8013700C
    if (ctx->r2 != 0) {
        // 0x80136FF4: nop
    
            goto L_8013700C;
    }
    // 0x80136FF4: nop

    // 0x80136FF8: jal         0x80136D04
    // 0x80136FFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PGameDetectBack(rdram, ctx);
        goto after_26;
    // 0x80136FFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_26:
    // 0x80137000: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137004: lw          $v0, -0x70E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X70E8);
    // 0x80137008: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_8013700C:
    // 0x8013700C: bnel        $v0, $zero, L_80137020
    if (ctx->r2 != 0) {
        // 0x80137010: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80137020;
    }
    goto skip_10;
    // 0x80137010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80137014: jal         0x80136540
    // 0x80137018: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mnPlayers1PGameUpdateCursorNoRecall(rdram, ctx);
        goto after_27;
    // 0x80137018: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_27:
    // 0x8013701C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137020:
    // 0x80137020: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80137024: jr          $ra
    // 0x80137028: nop

    return;
    // 0x80137028: nop

;}
RECOMP_FUNC void sc1PIntroMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013442C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134430: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80134434: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134438: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013443C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80134440: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134444: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80134448: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013444C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134450: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134454: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80134458: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013445C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134460: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134464: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134468: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013446C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134470: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134474: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134478: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013447C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80134480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134484: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134488: jal         0x8000B93C
    // 0x8013448C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013448C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134490: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134494: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134498: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013449C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801344A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801344A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801344A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801344AC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801344B0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801344B4: jal         0x80007080
    // 0x801344B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801344B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801344BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801344C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801344C4: jr          $ra
    // 0x801344C8: nop

    return;
    // 0x801344C8: nop

;}
RECOMP_FUNC void ftPhysicsApplyAirVelTransNAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D93E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D93E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D93EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D93F0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x800D93F4: addiu       $a1, $a0, 0x48
    ctx->r5 = ADD32(ctx->r4, 0X48);
    // 0x800D93F8: addiu       $a2, $a0, 0x4C
    ctx->r6 = ADD32(ctx->r4, 0X4C);
    // 0x800D93FC: jal         0x800D9260
    // 0x800D9400: addiu       $a3, $a0, 0x50
    ctx->r7 = ADD32(ctx->r4, 0X50);
    ftPhysicsGetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x800D9400: addiu       $a3, $a0, 0x50
    ctx->r7 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x800D9404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D940C: jr          $ra
    // 0x800D9410: nop

    return;
    // 0x800D9410: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AEA8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8016AEAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016AEB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016AEB4: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8016AEB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016AEBC: lw          $v0, 0x29C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X29C);
    // 0x8016AEC0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8016AEC4: beql        $t6, $zero, L_8016AEF4
    if (ctx->r14 == 0) {
        // 0x8016AEC8: lw          $t7, 0x8($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X8);
            goto L_8016AEF4;
    }
    goto skip_0;
    // 0x8016AEC8: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    skip_0:
    // 0x8016AECC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016AED0: lw          $a1, 0x104($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X104);
    // 0x8016AED4: jal         0x800FE068
    // 0x8016AED8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016AED8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016AEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016AEE0: jal         0x8016AD30
    // 0x8016AEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_1;
    // 0x8016AEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8016AEE8: b           L_8016B184
    // 0x8016AEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B184;
    // 0x8016AEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016AEF0: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
L_8016AEF4:
    // 0x8016AEF4: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8016AEF8: beq         $t8, $zero, L_8016AF24
    if (ctx->r24 == 0) {
        // 0x8016AEFC: lw          $a2, 0x84($t7)
        ctx->r6 = MEM_W(ctx->r15, 0X84);
            goto L_8016AF24;
    }
    // 0x8016AEFC: lw          $a2, 0x84($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X84);
    // 0x8016AF00: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016AF04: lw          $a1, 0x104($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X104);
    // 0x8016AF08: jal         0x800FE068
    // 0x8016AF0C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016AF0C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8016AF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016AF14: jal         0x8016AD30
    // 0x8016AF18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_3;
    // 0x8016AF18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8016AF1C: b           L_8016B184
    // 0x8016AF20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B184;
    // 0x8016AF20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016AF24:
    // 0x8016AF24: lw          $t9, 0x268($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X268);
    // 0x8016AF28: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016AF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016AF30: bne         $t9, $at, L_8016AF4C
    if (ctx->r25 != ctx->r1) {
        // 0x8016AF34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8016AF4C;
    }
    // 0x8016AF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016AF38: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8016AF3C: jal         0x8016AE64
    // 0x8016AF40: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    wpNessPKThunderHeadMakeTrail(rdram, ctx);
        goto after_4;
    // 0x8016AF40: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_4:
    // 0x8016AF44: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8016AF48: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
L_8016AF4C:
    // 0x8016AF4C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8016AF50: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8016AF54: jal         0x80167FE8
    // 0x8016AF58: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_5;
    // 0x8016AF58: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_5:
    // 0x8016AF5C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8016AF60: beq         $v0, $zero, L_8016AF8C
    if (ctx->r2 == 0) {
        // 0x8016AF64: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_8016AF8C;
    }
    // 0x8016AF64: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8016AF68: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016AF6C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016AF70: jal         0x800FF648
    // 0x8016AF74: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8016AF74: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_6:
    // 0x8016AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016AF7C: jal         0x8016AD30
    // 0x8016AF80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_7;
    // 0x8016AF80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8016AF84: b           L_8016B184
    // 0x8016AF88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B184;
    // 0x8016AF88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016AF8C:
    // 0x8016AF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016AF90: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8016AF94: jal         0x8016ADF4
    // 0x8016AF98: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    wpNessPKThunderTrailUpdatePositions(rdram, ctx);
        goto after_8;
    // 0x8016AF98: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_8:
    // 0x8016AF9C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8016AFA0: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x8016AFA4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8016AFA8: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8016AFAC: beq         $v0, $at, L_8016AFBC
    if (ctx->r2 == ctx->r1) {
        // 0x8016AFB0: addiu       $at, $zero, 0xE9
        ctx->r1 = ADD32(0, 0XE9);
            goto L_8016AFBC;
    }
    // 0x8016AFB0: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x8016AFB4: bnel        $v0, $at, L_8016B160
    if (ctx->r2 != ctx->r1) {
        // 0x8016AFB8: lw          $a0, 0x74($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X74);
            goto L_8016B160;
    }
    goto skip_1;
    // 0x8016AFB8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    skip_1:
L_8016AFBC:
    // 0x8016AFBC: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    // 0x8016AFC0: bgez        $v1, L_8016AFD0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8016AFC4: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_8016AFD0;
    }
    // 0x8016AFC4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8016AFC8: b           L_8016AFD0
    // 0x8016AFCC: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
        goto L_8016AFD0;
    // 0x8016AFCC: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_8016AFD0:
    // 0x8016AFD0: lb          $v0, 0x1C3($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C3);
    // 0x8016AFD4: bgez        $v0, L_8016AFE4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8016AFD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016AFE4;
    }
    // 0x8016AFD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016AFDC: b           L_8016AFE4
    // 0x8016AFE0: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_8016AFE4;
    // 0x8016AFE0: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8016AFE4:
    // 0x8016AFE4: addu        $t0, $a0, $a1
    ctx->r8 = ADD32(ctx->r4, ctx->r5);
    // 0x8016AFE8: slti        $at, $t0, 0x2E
    ctx->r1 = SIGNED(ctx->r8) < 0X2E ? 1 : 0;
    // 0x8016AFEC: bnel        $at, $zero, L_8016B184
    if (ctx->r1 != 0) {
        // 0x8016AFF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016B184;
    }
    goto skip_2;
    // 0x8016AFF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8016AFF4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8016AFF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8016AFFC: addiu       $a0, $a3, 0x20
    ctx->r4 = ADD32(ctx->r7, 0X20);
    // 0x8016B000: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016B004: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8016B008: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8016B00C: lb          $t1, 0x1C3($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X1C3);
    // 0x8016B010: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8016B014: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8016B018: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8016B01C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8016B020: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016B024: jal         0x800191FC
    // 0x8016B028: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_9;
    // 0x8016B028: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8016B02C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8016B030: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8016B034: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8016B038: jal         0x80019980
    // 0x8016B03C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    syVectorNormCross3D(rdram, ctx);
        goto after_10;
    // 0x8016B03C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8016B040: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B044: lwc1        $f0, -0x3500($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3500);
    // 0x8016B048: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8016B04C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8016B050: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8016B054: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8016B058: nop

    // 0x8016B05C: bc1fl       L_8016B0A8
    if (!c1cs) {
        // 0x8016B060: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8016B0A8;
    }
    goto skip_3;
    // 0x8016B060: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x8016B064: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8016B068: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B06C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8016B070: nop

    // 0x8016B074: bc1fl       L_8016B098
    if (!c1cs) {
        // 0x8016B078: lwc1        $f16, 0x2A0($a3)
        ctx->f16.u32l = MEM_W(ctx->r7, 0X2A0);
            goto L_8016B098;
    }
    goto skip_4;
    // 0x8016B078: lwc1        $f16, 0x2A0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X2A0);
    skip_4:
    // 0x8016B07C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B080: lwc1        $f8, -0x34FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X34FC);
    // 0x8016B084: lwc1        $f6, 0x2A0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X2A0);
    // 0x8016B088: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8016B08C: b           L_8016B0A4
    // 0x8016B090: swc1        $f10, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f10.u32l;
        goto L_8016B0A4;
    // 0x8016B090: swc1        $f10, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f10.u32l;
    // 0x8016B094: lwc1        $f16, 0x2A0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X2A0);
L_8016B098:
    // 0x8016B098: lwc1        $f18, -0x34F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X34F8);
    // 0x8016B09C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8016B0A0: swc1        $f4, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f4.u32l;
L_8016B0A4:
    // 0x8016B0A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8016B0A8:
    // 0x8016B0A8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8016B0AC: bc1fl       L_8016B100
    if (!c1cs) {
        // 0x8016B0B0: lwc1        $f12, 0x2A0($a3)
        ctx->f12.u32l = MEM_W(ctx->r7, 0X2A0);
            goto L_8016B100;
    }
    goto skip_5;
    // 0x8016B0B0: lwc1        $f12, 0x2A0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X2A0);
    skip_5:
    // 0x8016B0B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8016B0B8: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x8016B0BC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8016B0C0: nop

    // 0x8016B0C4: bc1fl       L_8016B0EC
    if (!c1cs) {
        // 0x8016B0C8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8016B0EC;
    }
    goto skip_6;
    // 0x8016B0C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_6:
    // 0x8016B0CC: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x8016B0D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016B0D4: lwc1        $f10, 0x2A0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X2A0);
    // 0x8016B0D8: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8016B0DC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8016B0E0: b           L_8016B0FC
    // 0x8016B0E4: swc1        $f4, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f4.u32l;
        goto L_8016B0FC;
    // 0x8016B0E4: swc1        $f4, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f4.u32l;
    // 0x8016B0E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8016B0EC:
    // 0x8016B0EC: lwc1        $f6, 0x2A0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X2A0);
    // 0x8016B0F0: div.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8016B0F4: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8016B0F8: swc1        $f10, 0x2A0($a3)
    MEM_W(0X2A0, ctx->r7) = ctx->f10.u32l;
L_8016B0FC:
    // 0x8016B0FC: lwc1        $f12, 0x2A0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X2A0);
L_8016B100:
    // 0x8016B100: jal         0x80035CD0
    // 0x8016B104: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    __cosf_recomp(rdram, ctx);
        goto after_11;
    // 0x8016B104: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_11:
    // 0x8016B108: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8016B10C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016B110: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8016B114: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8016B118: lwc1        $f12, 0x2A0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X2A0);
    // 0x8016B11C: jal         0x800303F0
    // 0x8016B120: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x8016B120: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    after_12:
    // 0x8016B124: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8016B128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016B12C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8016B130: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8016B134: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016B138: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B13C: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x8016B140: lwc1        $f10, 0x2A0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X2A0);
    // 0x8016B144: swc1        $f6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f6.u32l;
    // 0x8016B148: lwc1        $f18, -0x34F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X34F4);
    // 0x8016B14C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x8016B150: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8016B154: b           L_8016B180
    // 0x8016B158: swc1        $f4, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f4.u32l;
        goto L_8016B180;
    // 0x8016B158: swc1        $f4, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f4.u32l;
    // 0x8016B15C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
L_8016B160:
    // 0x8016B160: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016B164: jal         0x800FF648
    // 0x8016B168: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_13;
    // 0x8016B168: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_13:
    // 0x8016B16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016B170: jal         0x8016AD30
    // 0x8016B174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_14;
    // 0x8016B174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8016B178: b           L_8016B184
    // 0x8016B17C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B184;
    // 0x8016B17C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016B180:
    // 0x8016B180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B184:
    // 0x8016B184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016B188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016B18C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8016B190: jr          $ra
    // 0x8016B194: nop

    return;
    // 0x8016B194: nop

;}
RECOMP_FUNC void ifCommonBattleEndAddSoundQueueID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113804: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80113808: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8011380C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80113810: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80113814: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80113818: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011381C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80113820: bne         $t7, $at, L_8011384C
    if (ctx->r15 != ctx->r1) {
        // 0x80113824: addiu       $v1, $v1, 0x1829
        ctx->r3 = ADD32(ctx->r3, 0X1829);
            goto L_8011384C;
    }
    // 0x80113824: addiu       $v1, $v1, 0x1829
    ctx->r3 = ADD32(ctx->r3, 0X1829);
    // 0x80113828: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8011382C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80113830: beq         $at, $zero, L_8011384C
    if (ctx->r1 == 0) {
        // 0x80113834: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_8011384C;
    }
    // 0x80113834: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80113838: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011383C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80113840: sh          $a0, 0x1808($at)
    MEM_H(0X1808, ctx->r1) = ctx->r4;
    // 0x80113844: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80113848: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_8011384C:
    // 0x8011384C: jr          $ra
    // 0x80113850: nop

    return;
    // 0x80113850: nop

;}
RECOMP_FUNC void func_ovl8_80372A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372A3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80372A40: jr          $ra
    // 0x80372A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80372A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void itBombHeiWalkGetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177260: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80177264: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80177268: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8017726C: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80177270: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80177274: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80177278: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8017727C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80177280: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80177284: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80177288: beq         $s0, $zero, L_801772E0
    if (ctx->r16 == 0) {
        // 0x8017728C: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_801772E0;
    }
    // 0x8017728C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80177290: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80177294: addiu       $s3, $v0, 0x1C
    ctx->r19 = ADD32(ctx->r2, 0X1C);
    // 0x80177298: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x8017729C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_801772A0:
    // 0x801772A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801772A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x801772A8: jal         0x8001902C
    // 0x801772AC: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x801772AC: addiu       $a2, $v0, 0x1C
    ctx->r6 = ADD32(ctx->r2, 0X1C);
    after_0:
    // 0x801772B0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801772B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801772B8: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x801772BC: nop

    // 0x801772C0: bc1f        L_801772D0
    if (!c1cs) {
        // 0x801772C4: nop
    
            goto L_801772D0;
    }
    // 0x801772C4: nop

    // 0x801772C8: b           L_801772D0
    // 0x801772CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_801772D0;
    // 0x801772CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801772D0:
    // 0x801772D0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x801772D4: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x801772D8: bnel        $s0, $zero, L_801772A0
    if (ctx->r16 != 0) {
        // 0x801772DC: lw          $v0, 0x74($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X74);
            goto L_801772A0;
    }
    goto skip_0;
    // 0x801772DC: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    skip_0:
L_801772E0:
    // 0x801772E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801772E4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801772E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801772EC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801772F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801772F4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801772F8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801772FC: jr          $ra
    // 0x80177300: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80177300: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mnVSOptionsMakeStageSelectOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132804: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132808: lw          $t6, 0x4904($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4904);
    // 0x8013280C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132810: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132814: beq         $t6, $zero, L_80132828
    if (ctx->r14 == 0) {
        // 0x80132818: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80132828;
    }
    // 0x80132818: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013281C: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x80132820: b           L_80132830
    // 0x80132824: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80132830;
    // 0x80132824: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80132828:
    // 0x80132828: addiu       $t8, $zero, 0x81
    ctx->r24 = ADD32(0, 0X81);
    // 0x8013282C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80132830:
    // 0x80132830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132838: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013283C: jal         0x80009968
    // 0x80132840: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132840: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132844: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132848: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013284C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80132850: sw          $v0, 0x48C8($at)
    MEM_W(0X48C8, ctx->r1) = ctx->r2;
    // 0x80132854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132858: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013285C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132864: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132868: jal         0x80009DF4
    // 0x8013286C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013286C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132870: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132874: lw          $t0, 0x49DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X49DC);
    // 0x80132878: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8013287C: addiu       $t1, $t1, 0x33D8
    ctx->r9 = ADD32(ctx->r9, 0X33D8);
    // 0x80132880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132884: jal         0x800CCFDC
    // 0x80132888: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132888: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x8013288C: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132890: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x80132894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132898: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x8013289C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801328A0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801328A4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801328A8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801328AC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801328B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801328B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328B8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801328BC: nop

    // 0x801328C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801328C4: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x801328C8: lw          $a1, 0x48E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E0);
    // 0x801328CC: xori        $a1, $a1, 0x2
    ctx->r5 = ctx->r5 ^ 0X2;
    // 0x801328D0: jal         0x80131F74
    // 0x801328D4: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x801328D4: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x801328D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801328DC: lw          $t7, 0x49DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49DC);
    // 0x801328E0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801328E4: addiu       $t8, $t8, 0x3CF8
    ctx->r24 = ADD32(ctx->r24, 0X3CF8);
    // 0x801328E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328EC: jal         0x800CCFDC
    // 0x801328F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801328F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x801328F4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801328F8: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x801328FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132900: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132904: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132908: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013290C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132910: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80132914: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80132918: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x8013291C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132920: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80132924: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80132928: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013292C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132930: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132934: lui         $a1, 0x4350
    ctx->r5 = S32(0X4350 << 16);
    // 0x80132938: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013293C: jal         0x80132078
    // 0x80132940: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    mnVSOptionsMakeOnOffToggle(rdram, ctx);
        goto after_5;
    // 0x80132940: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    after_5:
    // 0x80132944: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132948: lw          $a1, 0x48EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48EC);
    // 0x8013294C: jal         0x80131FFC
    // 0x80132950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_6;
    // 0x80132950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80132954: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132958: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013295C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80132960: jr          $ra
    // 0x80132964: nop

    return;
    // 0x80132964: nop

;}
RECOMP_FUNC void ftCommonWalkGetWalkStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E340: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013E344: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8013E348: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8013E34C: bgezl       $a0, L_8013E364
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8013E350: slti        $at, $a0, 0x3E
        ctx->r1 = SIGNED(ctx->r4) < 0X3E ? 1 : 0;
            goto L_8013E364;
    }
    goto skip_0;
    // 0x8013E350: slti        $at, $a0, 0x3E
    ctx->r1 = SIGNED(ctx->r4) < 0X3E ? 1 : 0;
    skip_0:
    // 0x8013E354: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8013E358: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8013E35C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8013E360: slti        $at, $a0, 0x3E
    ctx->r1 = SIGNED(ctx->r4) < 0X3E ? 1 : 0;
L_8013E364:
    // 0x8013E364: bnel        $at, $zero, L_8013E378
    if (ctx->r1 != 0) {
        // 0x8013E368: slti        $at, $a0, 0x1A
        ctx->r1 = SIGNED(ctx->r4) < 0X1A ? 1 : 0;
            goto L_8013E378;
    }
    goto skip_1;
    // 0x8013E368: slti        $at, $a0, 0x1A
    ctx->r1 = SIGNED(ctx->r4) < 0X1A ? 1 : 0;
    skip_1:
    // 0x8013E36C: jr          $ra
    // 0x8013E370: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    return;
    // 0x8013E370: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8013E374: slti        $at, $a0, 0x1A
    ctx->r1 = SIGNED(ctx->r4) < 0X1A ? 1 : 0;
L_8013E378:
    // 0x8013E378: bne         $at, $zero, L_8013E388
    if (ctx->r1 != 0) {
        // 0x8013E37C: addiu       $v1, $zero, 0xB
        ctx->r3 = ADD32(0, 0XB);
            goto L_8013E388;
    }
    // 0x8013E37C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x8013E380: jr          $ra
    // 0x8013E384: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x8013E384: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8013E388:
    // 0x8013E388: jr          $ra
    // 0x8013E38C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013E38C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itKabigonFallInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E25C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017E260: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017E264: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8017E268: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8017E26C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017E270: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x8017E274: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017E278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E27C: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8017E280: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8017E284: jal         0x80018948
    // 0x8017E288: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8017E288: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x8017E28C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8017E290: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E294: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8017E298: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E29C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8017E2A0: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8017E2A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8017E2A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017E2AC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8017E2B0: jal         0x8017275C
    // 0x8017E2B4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_1;
    // 0x8017E2B4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x8017E2B8: sw          $zero, 0x354($s0)
    MEM_W(0X354, ctx->r16) = 0;
    // 0x8017E2BC: jal         0x800269C0
    // 0x8017E2C0: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017E2C0: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_2:
    // 0x8017E2C4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8017E2C8: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8017E2CC: bne         $t6, $at, L_8017E300
    if (ctx->r14 != ctx->r1) {
        // 0x8017E2D0: nop
    
            goto L_8017E300;
    }
    // 0x8017E2D0: nop

    // 0x8017E2D4: jal         0x800269C0
    // 0x8017E2D8: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8017E2D8: addiu       $a0, $zero, 0x137
    ctx->r4 = ADD32(0, 0X137);
    after_3:
    // 0x8017E2DC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017E2E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017E2E4: nop

    // 0x8017E2E8: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x8017E2EC: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x8017E2F0: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8017E2F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8017E2F8: b           L_8017E31C
    // 0x8017E2FC: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
        goto L_8017E31C;
    // 0x8017E2FC: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
L_8017E300:
    // 0x8017E300: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017E304: lwc1        $f0, -0x31C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X31C0);
    // 0x8017E308: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x8017E30C: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x8017E310: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8017E314: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8017E318: swc1        $f18, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f18.u32l;
L_8017E31C:
    // 0x8017E31C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8017E320: addiu       $t7, $t7, -0x1F00
    ctx->r15 = ADD32(ctx->r15, -0X1F00);
    // 0x8017E324: sw          $t7, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r15;
    // 0x8017E328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8017E32C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8017E330: jal         0x8000A14C
    // 0x8017E334: lw          $a2, 0x28($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X28);
    gcMoveGObjDLHead(rdram, ctx);
        goto after_4;
    // 0x8017E334: lw          $a2, 0x28($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X28);
    after_4:
    // 0x8017E338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017E33C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017E340: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E344: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8017E348: jr          $ra
    // 0x8017E34C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8017E34C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonHammerLandingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148058: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014805C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80148060: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80148064: lwc1        $f4, 0xB18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x80148068: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8014806C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80148070: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80148074: swc1        $f8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f8.u32l;
    // 0x80148078: lwc1        $f16, 0xB18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x8014807C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80148080: nop

    // 0x80148084: bc1fl       L_80148098
    if (!c1cs) {
        // 0x80148088: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80148098;
    }
    goto skip_0;
    // 0x80148088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014808C: jal         0x800F3938
    // 0x80148090: nop

    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_0;
    // 0x80148090: nop

    after_0:
    // 0x80148094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148098:
    // 0x80148098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014809C: jr          $ra
    // 0x801480A0: nop

    return;
    // 0x801480A0: nop

;}
RECOMP_FUNC void ftDonkeyThrowFJumpSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DAF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014DAFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014DB00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014DB04: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8014DB08: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014DB0C: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014DB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014DB14: jal         0x800DEEC8
    // 0x8014DB18: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014DB18: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_0:
    // 0x8014DB1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014DB20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014DB24: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8014DB28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014DB2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014DB30: jal         0x800E6F24
    // 0x8014DB34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DB34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014DB38: lw          $v0, 0xB20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB20);
    // 0x8014DB3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014DB40: beq         $v0, $at, L_8014DB68
    if (ctx->r2 == ctx->r1) {
        // 0x8014DB44: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014DB68;
    }
    // 0x8014DB44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014DB48: bne         $v0, $at, L_8014DB68
    if (ctx->r2 != ctx->r1) {
        // 0x8014DB4C: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_8014DB68;
    }
    // 0x8014DB4C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8014DB50: lb          $a0, 0x1C2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C2);
    // 0x8014DB54: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8014DB58: jal         0x8013F6A0
    // 0x8014DB5C: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    ftCommonJumpGetJumpForceButton(rdram, ctx);
        goto after_2;
    // 0x8014DB5C: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    after_2:
    // 0x8014DB60: b           L_8014DB88
    // 0x8014DB64: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
        goto L_8014DB88;
    // 0x8014DB64: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
L_8014DB68:
    // 0x8014DB68: lb          $t8, 0x1C2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1C2);
    // 0x8014DB6C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8014DB70: lwc1        $f4, 0xB18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB18);
    // 0x8014DB74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014DB78: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8014DB7C: nop

    // 0x8014DB80: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8014DB84: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
L_8014DB88:
    // 0x8014DB88: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8014DB8C: addiu       $t3, $zero, 0xFE
    ctx->r11 = ADD32(0, 0XFE);
    // 0x8014DB90: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8014DB94: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8014DB98: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8014DB9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014DBA0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014DBA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8014DBA8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8014DBAC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8014DBB0: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8014DBB4: sb          $t3, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r11;
    // 0x8014DBB8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8014DBBC: nop

    // 0x8014DBC0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014DBC4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014DBC8: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8014DBCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014DBD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014DBD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014DBD8: jr          $ra
    // 0x8014DBDC: nop

    return;
    // 0x8014DBDC: nop

;}
RECOMP_FUNC void itTosakintoBounceProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E8CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E8D4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017E8D8: jal         0x80173680
    // 0x8017E8DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8017E8DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017E8E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E8E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8017E8E8: lhu         $t6, 0x8E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8E);
    // 0x8017E8EC: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8017E8F0: beql        $t7, $zero, L_8017E92C
    if (ctx->r15 == 0) {
        // 0x8017E8F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017E92C;
    }
    goto skip_0;
    // 0x8017E8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017E8F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E8FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8017E900: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017E904: jal         0x80018994
    // 0x8017E908: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8017E908: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017E90C: beq         $v0, $zero, L_8017E920
    if (ctx->r2 == 0) {
        // 0x8017E910: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8017E920;
    }
    // 0x8017E910: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E914: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017E918: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8017E91C: swc1        $f8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f8.u32l;
L_8017E920:
    // 0x8017E920: jal         0x800269C0
    // 0x8017E924: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017E924: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_2:
    // 0x8017E928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017E92C:
    // 0x8017E92C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E934: jr          $ra
    // 0x8017E938: nop

    return;
    // 0x8017E938: nop

;}
RECOMP_FUNC void ftCommonDamageUpdateCatchResist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140E34: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80140E38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80140E3C: lwc1        $f0, 0x7E0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7E0);
    // 0x80140E40: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80140E44: nop

    // 0x80140E48: bc1t        L_80140E90
    if (c1cs) {
        // 0x80140E4C: nop
    
            goto L_80140E90;
    }
    // 0x80140E4C: nop

    // 0x80140E50: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x80140E54: beq         $t6, $zero, L_80140EA0
    if (ctx->r14 == 0) {
        // 0x80140E58: nop
    
            goto L_80140EA0;
    }
    // 0x80140E58: nop

    // 0x80140E5C: lw          $t7, 0x190($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X190);
    // 0x80140E60: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80140E64: sll         $t9, $t7, 22
    ctx->r25 = S32(ctx->r15 << 22);
    // 0x80140E68: bgez        $t9, L_80140EA0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80140E6C: nop
    
            goto L_80140EA0;
    }
    // 0x80140E6C: nop

    // 0x80140E70: lwc1        $f6, 0x7EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7EC);
    // 0x80140E74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80140E78: nop

    // 0x80140E7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80140E80: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80140E84: nop

    // 0x80140E88: bc1f        L_80140EA0
    if (!c1cs) {
        // 0x80140E8C: nop
    
            goto L_80140EA0;
    }
    // 0x80140E8C: nop

L_80140E90:
    // 0x80140E90: jal         0x80141648
    // 0x80140E94: nop

    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_0;
    // 0x80140E94: nop

    after_0:
    // 0x80140E98: b           L_80140EB4
    // 0x80140E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140EB4;
    // 0x80140E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140EA0:
    // 0x80140EA0: jal         0x800E823C
    // 0x80140EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_1;
    // 0x80140EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80140EA8: jal         0x8014E0E0
    // 0x80140EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFDamageSetStatus(rdram, ctx);
        goto after_2;
    // 0x80140EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80140EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140EB4:
    // 0x80140EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140EB8: jr          $ra
    // 0x80140EBC: nop

    return;
    // 0x80140EBC: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeOptionArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F738: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018F73C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F740: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018F744: jal         0x80009968
    // 0x8018F748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018F748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018F74C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F750: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018F754: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018F758: sw          $v0, 0xBC0($at)
    MEM_W(0XBC0, ctx->r1) = ctx->r2;
    // 0x8018F75C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018F760: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F764: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018F768: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F76C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018F770: jal         0x80009DF4
    // 0x8018F774: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018F774: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018F778: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018F77C: lw          $t7, 0xB88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XB88);
    // 0x8018F780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F784: jal         0x800CCFDC
    // 0x8018F788: lw          $a1, 0x70($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X70);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018F788: lw          $a1, 0x70($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X70);
    after_2:
    // 0x8018F78C: jal         0x8018F608
    // 0x8018F790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sc1PTrainingModeInitOptionArrowSpriteColors(rdram, ctx);
        goto after_3;
    // 0x8018F790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8018F794: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018F798: lw          $t8, 0xB88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XB88);
    // 0x8018F79C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F7A0: jal         0x800CCFDC
    // 0x8018F7A4: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8018F7A4: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    after_4:
    // 0x8018F7A8: jal         0x8018F608
    // 0x8018F7AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sc1PTrainingModeInitOptionArrowSpriteColors(rdram, ctx);
        goto after_5;
    // 0x8018F7AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8018F7B0: jal         0x8018F630
    // 0x8018F7B4: nop

    sc1PTrainingModeUpdateOptionArrows(rdram, ctx);
        goto after_6;
    // 0x8018F7B4: nop

    after_6:
    // 0x8018F7B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F7BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F7C0: jr          $ra
    // 0x8018F7C4: nop

    return;
    // 0x8018F7C4: nop

;}
RECOMP_FUNC void __getTrackByte(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028468: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8002846C: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x80028470: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80028474: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x80028478: beql        $t6, $zero, L_800284B0
    if (ctx->r14 == 0) {
        // 0x8002847C: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_800284B0;
    }
    goto skip_0;
    // 0x8002847C: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x80028480: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80028484: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x80028488: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x8002848C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80028490: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x80028494: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x80028498: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x8002849C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800284A0: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800284A4: jr          $ra
    // 0x800284A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800284A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800284AC: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_800284B0:
    // 0x800284B0: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800284B4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800284B8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800284BC: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800284C0: bne         $t0, $v1, L_80028524
    if (ctx->r8 != ctx->r3) {
        // 0x800284C4: nop
    
            goto L_80028524;
    }
    // 0x800284C4: nop

    // 0x800284C8: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800284CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800284D0: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800284D4: beq         $t0, $a0, L_80028524
    if (ctx->r8 == ctx->r4) {
        // 0x800284D8: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_80028524;
    }
    // 0x800284D8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800284DC: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800284E0: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800284E4: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800284E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800284EC: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800284F0: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800284F4: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800284F8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800284FC: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x80028500: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x80028504: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x80028508: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x8002850C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80028510: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x80028514: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x80028518: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x8002851C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80028520: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_80028524:
    // 0x80028524: jr          $ra
    // 0x80028528: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80028528: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeTextCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133868: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013386C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133870: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133874: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133878: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8013387C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133880: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80133884: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133888: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013388C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133890: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133894: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133898: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013389C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801338A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801338A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801338A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801338AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801338B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801338B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801338B8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801338BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801338C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801338C4: jal         0x8000B93C
    // 0x801338C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801338C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801338CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801338D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801338D4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801338D8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801338DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801338E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801338E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801338E8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801338EC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801338F0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x801338F4: jal         0x80007080
    // 0x801338F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801338F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801338FC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80133900: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80133904: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x80133908: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013390C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133910: jr          $ra
    // 0x80133914: nop

    return;
    // 0x80133914: nop

;}
RECOMP_FUNC void ftParamHideModelPartAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E90F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E90FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E9100: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E9104: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E9108: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E910C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E9110: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E9114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E9118: lw          $s4, 0x84($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X84);
    // 0x800E911C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800E9120: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800E9124: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x800E9128: addiu       $s2, $s4, 0x10
    ctx->r18 = ADD32(ctx->r20, 0X10);
L_800E912C:
    // 0x800E912C: lw          $s0, 0x8E8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8E8);
    // 0x800E9130: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x800E9134: addu        $v0, $s4, $t6
    ctx->r2 = ADD32(ctx->r20, ctx->r14);
    // 0x800E9138: beql        $s0, $zero, L_800E9160
    if (ctx->r16 == 0) {
        // 0x800E913C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800E9160;
    }
    goto skip_0;
    // 0x800E913C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800E9140: lb          $t7, 0x975($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X975);
    // 0x800E9144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E9148: beql        $s3, $t7, L_800E9160
    if (ctx->r19 == ctx->r15) {
        // 0x800E914C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800E9160;
    }
    goto skip_1;
    // 0x800E914C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800E9150: jal         0x800091F4
    // 0x800E9154: sb          $s3, 0x975($v0)
    MEM_B(0X975, ctx->r2) = ctx->r19;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x800E9154: sb          $s3, 0x975($v0)
    MEM_B(0X975, ctx->r2) = ctx->r19;
    after_0:
    // 0x800E9158: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x800E915C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800E9160:
    // 0x800E9160: bne         $s1, $s5, L_800E912C
    if (ctx->r17 != ctx->r21) {
        // 0x800E9164: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800E912C;
    }
    // 0x800E9164: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800E9168: lbu         $t9, 0x18C($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X18C);
    // 0x800E916C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x800E9170: sb          $t0, 0x18C($s4)
    MEM_B(0X18C, ctx->r20) = ctx->r8;
    // 0x800E9174: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9178: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E917C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E9180: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E9184: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9188: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E918C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E9190: jr          $ra
    // 0x800E9194: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E9194: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcSetGObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800079A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800079AC: addiu       $v0, $v0, 0x67FC
    ctx->r2 = ADD32(ctx->r2, 0X67FC);
    // 0x800079B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800079B4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800079B8: addiu       $v1, $v1, 0x6A0C
    ctx->r3 = ADD32(ctx->r3, 0X6A0C);
    // 0x800079BC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800079C0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800079C4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800079C8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800079CC: jr          $ra
    // 0x800079D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x800079D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void itLinkBombDroppedProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801862E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801862E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801862E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801862EC: lhu         $t6, 0x352($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X352);
    // 0x801862F0: bnel        $t6, $zero, L_80186304
    if (ctx->r14 != 0) {
        // 0x801862F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80186304;
    }
    goto skip_0;
    // 0x801862F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801862F8: jal         0x80185B84
    // 0x801862FC: nop

    itLinkBombCommonProcDamage(rdram, ctx);
        goto after_0;
    // 0x801862FC: nop

    after_0:
    // 0x80186300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80186304:
    // 0x80186304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80186308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018630C: jr          $ra
    // 0x80186310: nop

    return;
    // 0x80186310: nop

;}
RECOMP_FUNC void efManagerHealSparklesMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102E90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102E94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80102E98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102E9C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80102EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102EA8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80102EAC: jal         0x800CE9E8
    // 0x80102EB0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80102EB0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x80102EB4: beq         $v0, $zero, L_80102F1C
    if (ctx->r2 == 0) {
        // 0x80102EB8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80102F1C;
    }
    // 0x80102EB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80102EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102EC0: jal         0x800CE1DC
    // 0x80102EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80102EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80102EC8: beq         $v0, $zero, L_80102F10
    if (ctx->r2 == 0) {
        // 0x80102ECC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80102F10;
    }
    // 0x80102ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80102ED0: jal         0x800CEA14
    // 0x80102ED4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80102ED4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80102ED8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80102EDC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80102EE0: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80102EE4: bnel        $t6, $zero, L_80102EF8
    if (ctx->r14 != 0) {
        // 0x80102EE8: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80102EF8;
    }
    goto skip_0;
    // 0x80102EE8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80102EEC: b           L_80102F20
    // 0x80102EF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102F20;
    // 0x80102EF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102EF4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80102EF8:
    // 0x80102EF8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80102EFC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80102F00: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80102F04: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80102F08: b           L_80102F1C
    // 0x80102F0C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80102F1C;
    // 0x80102F0C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80102F10:
    // 0x80102F10: jal         0x800CEA40
    // 0x80102F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80102F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80102F18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80102F1C:
    // 0x80102F1C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80102F20:
    // 0x80102F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80102F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80102F2C: jr          $ra
    // 0x80102F30: nop

    return;
    // 0x80102F30: nop

;}
RECOMP_FUNC void ftComputerSetControlPKThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131BA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131BAC: jal         0x80131B44
    // 0x80131BB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    ftComputerGetOwnWeaponPositionKind(rdram, ctx);
        goto after_0;
    // 0x80131BB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80131BB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131BB8: beq         $v0, $zero, L_80131C50
    if (ctx->r2 == 0) {
        // 0x80131BBC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80131C50;
    }
    // 0x80131BBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80131BC0: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x80131BC4: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80131BC8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131BCC: lwc1        $f8, 0x64($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80131BD0: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80131BD4: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80131BD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131BDC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80131BE0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80131BE4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80131BE8: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80131BEC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80131BF0: jal         0x80033510
    // 0x80131BF4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80131BF4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x80131BF8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80131BFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131C00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131C08: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80131C0C: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80131C10: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80131C14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131C18: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80131C1C: nop

    // 0x80131C20: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80131C24: nop

    // 0x80131C28: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80131C2C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80131C30: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80131C34: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80131C38: nop

    // 0x80131C3C: sb          $t7, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r15;
    // 0x80131C40: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80131C44: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80131C48: b           L_80131C58
    // 0x80131C4C: sb          $t9, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r25;
        goto L_80131C58;
    // 0x80131C4C: sb          $t9, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r25;
L_80131C50:
    // 0x80131C50: sb          $zero, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = 0;
    // 0x80131C54: sb          $zero, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = 0;
L_80131C58:
    // 0x80131C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C60: jr          $ra
    // 0x80131C64: nop

    return;
    // 0x80131C64: nop

;}
RECOMP_FUNC void itIwarkWeaponRockProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DCAC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017DCB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017DCB4: lw          $t6, 0x2AC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2AC);
    // 0x8017DCB8: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8017DCBC: lhu         $t7, 0x35E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X35E);
    // 0x8017DCC0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017DCC4: jr          $ra
    // 0x8017DCC8: sh          $t8, 0x35E($a1)
    MEM_H(0X35E, ctx->r5) = ctx->r24;
    return;
    // 0x8017DCC8: sh          $t8, 0x35E($a1)
    MEM_H(0X35E, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void ftLinkSpecialHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016419C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801641A0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801641A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801641A8: jal         0x800DDDDC
    // 0x801641AC: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801641AC: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    after_0:
    // 0x801641B0: bnel        $v0, $zero, L_801641C4
    if (ctx->r2 != 0) {
        // 0x801641B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801641C4;
    }
    goto skip_0;
    // 0x801641B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801641B8: jal         0x80163EFC
    // 0x801641BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftLinkSpecialHiProcDamage(rdram, ctx);
        goto after_1;
    // 0x801641BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801641C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801641C4:
    // 0x801641C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801641C8: jr          $ra
    // 0x801641CC: nop

    return;
    // 0x801641CC: nop

;}
RECOMP_FUNC void ftCommonSquatRvSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801434CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801434D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801434D4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801434D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801434DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801434E0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x801434E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801434E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801434EC: jal         0x800E6F24
    // 0x801434F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801434F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801434F4: jal         0x800E0830
    // 0x801434F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801434F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801434FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80143500: lbu         $t8, 0x192($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X192);
    // 0x80143504: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80143508: sb          $t9, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r25;
    // 0x8014350C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143510: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80143514: jr          $ra
    // 0x80143518: nop

    return;
    // 0x80143518: nop

;}
RECOMP_FUNC void gmCollisionCopyMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECD80: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ECD84: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800ECD88: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ECD8C: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800ECD90: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ECD94: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800ECD98: lwc1        $f10, 0x30($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800ECD9C: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800ECDA0: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ECDA4: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x800ECDA8: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ECDAC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800ECDB0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ECDB4: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x800ECDB8: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800ECDBC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800ECDC0: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ECDC4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800ECDC8: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ECDCC: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800ECDD0: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ECDD4: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x800ECDD8: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800ECDDC: jr          $ra
    // 0x800ECDE0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800ECDE0: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void mvOpeningPikachuMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D334: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D338: lw          $t6, -0x1DD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1DD8);
    // 0x8018D33C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D340: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D344: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D348: bne         $at, $zero, L_8018D424
    if (ctx->r1 != 0) {
        // 0x8018D34C: addiu       $v1, $v1, -0x1D98
        ctx->r3 = ADD32(ctx->r3, -0X1D98);
            goto L_8018D424;
    }
    // 0x8018D34C: addiu       $v1, $v1, -0x1D98
    ctx->r3 = ADD32(ctx->r3, -0X1D98);
    // 0x8018D350: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D354: addiu       $a0, $a0, -0x1DB8
    ctx->r4 = ADD32(ctx->r4, -0X1DB8);
    // 0x8018D358: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D35C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D360: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D364: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D368: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D36C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D370: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D374: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D378: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D37C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D380: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D384: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D388: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D38C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D390: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D394: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D398: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D39C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D3A0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D3A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3AC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3B0: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D3B4: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B8: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D3BC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D3C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3C4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3CC: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D3D0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3D4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3D8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3DC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3E0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3E4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3E8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3EC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3F0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3F4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3FC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D400: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D404: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D408: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D40C: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D410: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D414: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D418: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D41C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D420: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D424:
    // 0x8018D424: jr          $ra
    // 0x8018D428: nop

    return;
    // 0x8018D428: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160A48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80160A4C: jal         0x800DEE98
    // 0x80160A50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80160A50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80160A54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80160A58: addiu       $t7, $zero, 0x4006
    ctx->r15 = ADD32(0, 0X4006);
    // 0x80160A5C: addiu       $a1, $zero, 0x127
    ctx->r5 = ADD32(0, 0X127);
    // 0x80160A60: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80160A64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80160A68: jal         0x800E6F24
    // 0x80160A6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80160A6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80160A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80160A78: jr          $ra
    // 0x80160A7C: nop

    return;
    // 0x80160A7C: nop

;}
RECOMP_FUNC void itGShellSpinAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178670: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80178674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178678: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017867C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178680: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x80178684: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80178688: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017868C: addiu       $v1, $v1, 0x5F88
    ctx->r3 = ADD32(ctx->r3, 0X5F88);
    // 0x80178690: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80178694: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80178698: addiu       $t0, $t0, 0x6018
    ctx->r8 = ADD32(ctx->r8, 0X6018);
    // 0x8017869C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801786A0: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x801786A4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x801786A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801786AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801786B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x801786B4: jal         0x8000BD1C
    // 0x801786B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x801786B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x801786BC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x801786C0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801786C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801786C8: lw          $t1, 0x2D4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2D4);
    // 0x801786CC: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801786D0: addiu       $t4, $t4, 0x6048
    ctx->r12 = ADD32(ctx->r12, 0X6048);
    // 0x801786D4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801786D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801786DC: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
    // 0x801786E0: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x801786E4: jal         0x8000BD54
    // 0x801786E8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x801786E8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x801786EC: jal         0x8000DF34
    // 0x801786F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x801786F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x801786F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801786F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801786FC: jr          $ra
    // 0x80178700: nop

    return;
    // 0x80178700: nop

;}
RECOMP_FUNC void itLizardonAttackProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F7E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F7EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F7F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017F7F4: jal         0x801735A0
    // 0x8017F7F8: addiu       $a1, $a1, -0xA3C
    ctx->r5 = ADD32(ctx->r5, -0XA3C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017F7F8: addiu       $a1, $a1, -0xA3C
    ctx->r5 = ADD32(ctx->r5, -0XA3C);
    after_0:
    // 0x8017F7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F808: jr          $ra
    // 0x8017F80C: nop

    return;
    // 0x8017F80C: nop

;}
RECOMP_FUNC void func_ovl8_80373B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373B28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373B30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80373B34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373B38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80373B3C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80373B40: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80373B44: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373B48: lw          $t9, 0xB4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB4);
    // 0x80373B4C: lh          $t6, 0xB0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB0);
    // 0x80373B50: jalr        $t9
    // 0x80373B54: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373B54: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80373B58: lwl         $t7, 0x2C($sp)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r29, 0X2C);
    // 0x80373B5C: lwr         $t7, 0x2F($sp)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r29, 0X2F);
    // 0x80373B60: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80373B64: swl         $t7, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r15);
    // 0x80373B68: swr         $t7, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r15);
    // 0x80373B6C: jal         0x80377168
    // 0x80373B70: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    func_ovl8_80377168(rdram, ctx);
        goto after_1;
    // 0x80373B70: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_1:
    // 0x80373B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80373B7C: jr          $ra
    // 0x80373B80: nop

    return;
    // 0x80373B80: nop

;}
RECOMP_FUNC void gmCollisionCheckFighterInFighterRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF364: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EF368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF36C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EF370: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EF374: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800EF378: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x800EF37C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EF380: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF384: bne         $t7, $at, L_800EF3AC
    if (ctx->r15 != ctx->r1) {
        // 0x800EF388: lw          $v1, 0x9C8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X9C8);
            goto L_800EF3AC;
    }
    // 0x800EF388: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x800EF38C: lw          $a1, 0x74($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X74);
    // 0x800EF390: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x800EF394: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF398: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800EF39C: jal         0x800EF2D0
    // 0x800EF3A0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_0;
    // 0x800EF3A0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x800EF3A4: b           L_800EF404
    // 0x800EF3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800EF404;
    // 0x800EF3A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF3AC:
    // 0x800EF3AC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800EF3B0: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF3B4: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800EF3B8: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    // 0x800EF3BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800EF3C0: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800EF3C4: jal         0x800EF2D0
    // 0x800EF3C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_1;
    // 0x800EF3C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x800EF3CC: bne         $v0, $zero, L_800EF3F4
    if (ctx->r2 != 0) {
        // 0x800EF3D0: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_800EF3F4;
    }
    // 0x800EF3D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800EF3D4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800EF3D8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800EF3DC: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800EF3E0: lw          $a1, 0x74($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X74);
    // 0x800EF3E4: jal         0x800EF2D0
    // 0x800EF3E8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800EF3E8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x800EF3EC: beql        $v0, $zero, L_800EF400
    if (ctx->r2 == 0) {
        // 0x800EF3F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800EF400;
    }
    goto skip_0;
    // 0x800EF3F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800EF3F4:
    // 0x800EF3F4: b           L_800EF400
    // 0x800EF3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EF400;
    // 0x800EF3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF400:
    // 0x800EF400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF404:
    // 0x800EF404: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF408: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EF40C: jr          $ra
    // 0x800EF410: nop

    return;
    // 0x800EF410: nop

;}
RECOMP_FUNC void itManagerMakeItemSetupCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EA78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016EA7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8016EA80: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8016EA84: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8016EA88: addiu       $t8, $t8, -0x6B94
    ctx->r24 = ADD32(ctx->r24, -0X6B94);
    // 0x8016EA8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016EA90: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8016EA94: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8016EA98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8016EA9C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8016EAA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EAA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8016EAA8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8016EAAC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8016EAB0: jalr        $t9
    // 0x8016EAB4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8016EAB4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8016EAB8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8016EABC: beq         $v0, $zero, L_8016EAEC
    if (ctx->r2 == 0) {
        // 0x8016EAC0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_8016EAEC;
    }
    // 0x8016EAC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8016EAC4: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016EAC8: addiu       $t0, $t0, -0x6B44
    ctx->r8 = ADD32(ctx->r8, -0X6B44);
    // 0x8016EACC: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8016EAD0: beql        $at, $zero, L_8016EAF0
    if (ctx->r1 == 0) {
        // 0x8016EAD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016EAF0;
    }
    goto skip_0;
    // 0x8016EAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8016EAD8: jal         0x801044B4
    // 0x8016EADC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerItemSpawnSwirlMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016EADC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8016EAE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016EAE4: jal         0x80172394
    // 0x8016EAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itMainSetAppearSpin(rdram, ctx);
        goto after_2;
    // 0x8016EAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8016EAEC:
    // 0x8016EAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016EAF0:
    // 0x8016EAF0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016EAF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016EAF8: jr          $ra
    // 0x8016EAFC: nop

    return;
    // 0x8016EAFC: nop

;}
RECOMP_FUNC void ftKirbySpecialNAddCaptureDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161DA8: lw          $t6, 0x74($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X74);
    // 0x80161DAC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80161DB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80161DB4: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x80161DB8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80161DBC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80161DC0: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80161DC4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80161DC8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80161DCC: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x80161DD0: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80161DD4: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x80161DD8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80161DDC: nop

    // 0x80161DE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80161DE4: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80161DE8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80161DEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80161DF0: nop

    // 0x80161DF4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80161DF8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80161DFC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80161E00: jr          $ra
    // 0x80161E04: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    return;
    // 0x80161E04: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftCommonSleepProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D6D0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013D6D4: addiu       $t5, $t5, 0x50E8
    ctx->r13 = ADD32(ctx->r13, 0X50E8);
    // 0x8013D6D8: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8013D6DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013D6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D6E4: lbu         $t6, 0x3($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X3);
    // 0x8013D6E8: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8013D6EC: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8013D6F0: beql        $t7, $zero, L_8013D8A4
    if (ctx->r15 == 0) {
        // 0x8013D6F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013D8A4;
    }
    goto skip_0;
    // 0x8013D6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013D6F8: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x8013D6FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013D700: bnel        $t8, $at, L_8013D8A4
    if (ctx->r24 != ctx->r1) {
        // 0x8013D704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013D8A4;
    }
    goto skip_1;
    // 0x8013D704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013D708: lw          $v0, 0xB18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB18);
    // 0x8013D70C: beq         $v0, $zero, L_8013D750
    if (ctx->r2 == 0) {
        // 0x8013D710: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8013D750;
    }
    // 0x8013D710: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013D714: bne         $t9, $zero, L_8013D8A0
    if (ctx->r25 != 0) {
        // 0x8013D718: sw          $t9, 0xB18($a3)
        MEM_W(0XB18, ctx->r7) = ctx->r25;
            goto L_8013D8A0;
    }
    // 0x8013D718: sw          $t9, 0xB18($a3)
    MEM_W(0XB18, ctx->r7) = ctx->r25;
    // 0x8013D71C: lbu         $t8, 0xD($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XD);
    // 0x8013D720: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
    // 0x8013D724: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8013D728: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8013D72C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8013D730: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013D734: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8013D738: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013D73C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8013D740: jal         0x8013CF60
    // 0x8013D744: sb          $zero, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = 0;
    ftCommonRebirthDownSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D744: sb          $zero, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = 0;
    after_0:
    // 0x8013D748: b           L_8013D8A4
    // 0x8013D74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013D8A4;
    // 0x8013D74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013D750:
    // 0x8013D750: lhu         $t8, 0x1BE($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X1BE);
    // 0x8013D754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013D758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013D75C: andi        $t7, $t8, 0x1000
    ctx->r15 = ctx->r24 & 0X1000;
    // 0x8013D760: beq         $t7, $zero, L_8013D8A0
    if (ctx->r15 == 0) {
        // 0x8013D764: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013D8A0;
    }
    // 0x8013D764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013D768: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x8013D76C: addiu       $t3, $zero, 0x74
    ctx->r11 = ADD32(0, 0X74);
    // 0x8013D770: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8013D774: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013D778: lbu         $t9, 0xD($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD);
L_8013D77C:
    // 0x8013D77C: beql        $v0, $t9, L_8013D7DC
    if (ctx->r2 == ctx->r25) {
        // 0x8013D780: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8013D7DC;
    }
    goto skip_2;
    // 0x8013D780: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8013D784: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D788: mflo        $t6
    ctx->r14 = lo;
    // 0x8013D78C: addu        $v1, $t2, $t6
    ctx->r3 = ADD32(ctx->r10, ctx->r14);
    // 0x8013D790: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x8013D794: beql        $t0, $t8, L_8013D7DC
    if (ctx->r8 == ctx->r24) {
        // 0x8013D798: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8013D7DC;
    }
    goto skip_3;
    // 0x8013D798: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_3:
    // 0x8013D79C: lbu         $t7, 0xC($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0XC);
    // 0x8013D7A0: lbu         $t9, 0x25($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X25);
    // 0x8013D7A4: bnel        $t7, $t9, L_8013D7DC
    if (ctx->r15 != ctx->r25) {
        // 0x8013D7A8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8013D7DC;
    }
    goto skip_4;
    // 0x8013D7A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_4:
    // 0x8013D7AC: lb          $a0, 0x2B($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X2B);
    // 0x8013D7B0: blez        $a0, L_8013D7D8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8013D7B4: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8013D7D8;
    }
    // 0x8013D7B4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8013D7B8: beql        $at, $zero, L_8013D7CC
    if (ctx->r1 == 0) {
        // 0x8013D7BC: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_8013D7CC;
    }
    goto skip_5;
    // 0x8013D7BC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    skip_5:
    // 0x8013D7C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013D7C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013D7C8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
L_8013D7CC:
    // 0x8013D7CC: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8013D7D0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8013D7D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8013D7D8:
    // 0x8013D7D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8013D7DC:
    // 0x8013D7DC: bnel        $v0, $t1, L_8013D77C
    if (ctx->r2 != ctx->r9) {
        // 0x8013D7E0: lbu         $t9, 0xD($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0XD);
            goto L_8013D77C;
    }
    goto skip_6;
    // 0x8013D7E0: lbu         $t9, 0xD($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD);
    skip_6:
    // 0x8013D7E4: beq         $a1, $zero, L_8013D8A0
    if (ctx->r5 == 0) {
        // 0x8013D7E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8013D8A0;
    }
    // 0x8013D7E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8013D7EC: jal         0x80018994
    // 0x8013D7F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8013D7F0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8013D7F4: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x8013D7F8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8013D7FC: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x8013D800: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013D804: addiu       $t3, $zero, 0x74
    ctx->r11 = ADD32(0, 0X74);
    // 0x8013D808: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013D80C: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D810: addiu       $t5, $t5, 0x50E8
    ctx->r13 = ADD32(ctx->r13, 0X50E8);
    // 0x8013D814: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8013D818: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8013D81C: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x8013D820: mflo        $t8
    ctx->r24 = lo;
    // 0x8013D824: addu        $a2, $t9, $t8
    ctx->r6 = ADD32(ctx->r25, ctx->r24);
    // 0x8013D828: lb          $t7, 0x2B($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X2B);
    // 0x8013D82C: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x8013D830: sb          $t6, 0x2B($a2)
    MEM_B(0X2B, ctx->r6) = ctx->r14;
    // 0x8013D834: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8013D838: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8013D83C: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D840: mflo        $t7
    ctx->r15 = lo;
    // 0x8013D844: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8013D848: lw          $t1, 0x78($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X78);
    // 0x8013D84C: lw          $t0, 0x84($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X84);
    // 0x8013D850: lb          $t8, 0x14($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X14);
    // 0x8013D854: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8013D858: sb          $t9, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r25;
    // 0x8013D85C: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x8013D860: sb          $t2, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r10;
    // 0x8013D864: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8013D868: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8013D86C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8013D870: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013D874: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8013D878: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013D87C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8013D880: sb          $t2, 0x2B($t9)
    MEM_B(0X2B, ctx->r25) = ctx->r10;
    // 0x8013D884: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8013D888: sw          $t6, 0xB18($a3)
    MEM_W(0XB18, ctx->r7) = ctx->r14;
    // 0x8013D88C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8013D890: jal         0x801102B0
    // 0x8013D894: lbu         $a0, 0xD($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0XD);
    ifCommonPlayerStockStealMakeInterface(rdram, ctx);
        goto after_2;
    // 0x8013D894: lbu         $a0, 0xD($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0XD);
    after_2:
    // 0x8013D898: jal         0x800269C0
    // 0x8013D89C: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8013D89C: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    after_3:
L_8013D8A0:
    // 0x8013D8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013D8A4:
    // 0x8013D8A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013D8A8: jr          $ra
    // 0x8013D8AC: nop

    return;
    // 0x8013D8AC: nop

;}
RECOMP_FUNC void ftCommonThrownKirbyEscape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BE24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014BE28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014BE2C: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8014BE30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014BE34: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8014BE38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014BE3C: jal         0x800E6F24
    // 0x8014BE40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014BE40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8014BE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014BE4C: jr          $ra
    // 0x8014BE50: nop

    return;
    // 0x8014BE50: nop

;}
RECOMP_FUNC void wpMapSetGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167E78: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80167E7C: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80167E80: sw          $zero, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = 0;
    // 0x80167E84: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80167E88: nop

    // 0x80167E8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80167E90: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80167E94: jr          $ra
    // 0x80167E98: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80167E98: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void ftBossDefaultProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158750: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80158754: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80158758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015875C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80158760: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80158764: beql        $t7, $zero, L_80158778
    if (ctx->r15 == 0) {
        // 0x80158768: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80158778;
    }
    goto skip_0;
    // 0x80158768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015876C: jal         0x80159040
    // 0x80158770: nop

    ftBossWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x80158770: nop

    after_0:
    // 0x80158774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158778:
    // 0x80158778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015877C: jr          $ra
    // 0x80158780: nop

    return;
    // 0x80158780: nop

;}
RECOMP_FUNC void sc1PTrainingModeSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801906D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801906D4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801906D8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801906DC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x801906E0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801906E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801906E8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801906EC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801906F0: addiu       $t8, $t8, 0xC40
    ctx->r24 = ADD32(ctx->r24, 0XC40);
    // 0x801906F4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801906F8: addiu       $t0, $t0, 0xF60
    ctx->r8 = ADD32(ctx->r8, 0XF60);
    // 0x801906FC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80190700: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80190704: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80190708: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8019070C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80190710: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80190714: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80190718: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8019071C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80190720: jal         0x800CDF78
    // 0x80190724: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80190724: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80190728: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8019072C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x80190730: jal         0x800CDEEC
    // 0x80190734: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80190734: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80190738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8019073C: jal         0x80004980
    // 0x80190740: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80190740: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80190744: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80190748: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8019074C: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x80190750: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x80190754: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80190758: jal         0x800CDE04
    // 0x8019075C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8019075C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80190760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190764: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80190768: jr          $ra
    // 0x8019076C: nop

    return;
    // 0x8019076C: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016176C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161774: jal         0x801616F0
    // 0x80161778: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftKirbySpecialLwHoldDecideNextStatus(rdram, ctx);
        goto after_0;
    // 0x80161778: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016177C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80161780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161784: jr          $ra
    // 0x80161788: nop

    return;
    // 0x80161788: nop

;}

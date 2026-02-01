#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itGBumperCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D63C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D640: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017D644: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8017D648: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D64C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8017D650: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x8017D654: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x8017D658: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D65C: sh          $t6, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r14;
    // 0x8017D660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D664: lw          $t7, 0x80($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X80);
    // 0x8017D668: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8017D66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017D670: swc1        $f4, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->f4.u32l;
    // 0x8017D674: jr          $ra
    // 0x8017D678: sh          $t8, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r24;
    return;
    // 0x8017D678: sh          $t8, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftCommonDeadCheckRebirth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BF94: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013BF98: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8013BF9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BFA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BFA4: lbu         $a1, 0x3($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X3);
    // 0x8013BFA8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013BFAC: andi        $t6, $a1, 0x2
    ctx->r14 = ctx->r5 & 0X2;
    // 0x8013BFB0: beq         $t6, $zero, L_8013BFD8
    if (ctx->r14 == 0) {
        // 0x8013BFB4: andi        $t8, $a1, 0x8
        ctx->r24 = ctx->r5 & 0X8;
            goto L_8013BFD8;
    }
    // 0x8013BFB4: andi        $t8, $a1, 0x8
    ctx->r24 = ctx->r5 & 0X8;
    // 0x8013BFB8: lb          $t7, 0x14($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X14);
    // 0x8013BFBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013BFC0: bne         $t7, $at, L_8013C038
    if (ctx->r15 != ctx->r1) {
        // 0x8013BFC4: nop
    
            goto L_8013C038;
    }
    // 0x8013BFC4: nop

    // 0x8013BFC8: jal         0x8013D8B0
    // 0x8013BFCC: nop

    ftCommonSleepSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013BFCC: nop

    after_0:
    // 0x8013BFD0: b           L_8013C044
    // 0x8013BFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C044;
    // 0x8013BFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013BFD8:
    // 0x8013BFD8: beq         $t8, $zero, L_8013C038
    if (ctx->r24 == 0) {
        // 0x8013BFDC: nop
    
            goto L_8013C038;
    }
    // 0x8013BFDC: nop

    // 0x8013BFE0: lbu         $t9, 0xD($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XD);
    // 0x8013BFE4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8013BFE8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8013BFEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013BFF0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8013BFF4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013BFF8: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8013BFFC: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x8013C000: beql        $t2, $zero, L_8013C01C
    if (ctx->r10 == 0) {
        // 0x8013C004: lb          $t3, 0x14($v0)
        ctx->r11 = MEM_B(ctx->r2, 0X14);
            goto L_8013C01C;
    }
    goto skip_0;
    // 0x8013C004: lb          $t3, 0x14($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X14);
    skip_0:
    // 0x8013C008: jal         0x8018E18C
    // 0x8013C00C: nop

    sc1PGameSpawnEnemyTeamNext(rdram, ctx);
        goto after_1;
    // 0x8013C00C: nop

    after_1:
    // 0x8013C010: b           L_8013C044
    // 0x8013C014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C044;
    // 0x8013C014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C018: lb          $t3, 0x14($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X14);
L_8013C01C:
    // 0x8013C01C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013C020: bne         $t3, $at, L_8013C038
    if (ctx->r11 != ctx->r1) {
        // 0x8013C024: nop
    
            goto L_8013C038;
    }
    // 0x8013C024: nop

    // 0x8013C028: jal         0x8013D8B0
    // 0x8013C02C: nop

    ftCommonSleepSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013C02C: nop

    after_2:
    // 0x8013C030: b           L_8013C044
    // 0x8013C034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013C044;
    // 0x8013C034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C038:
    // 0x8013C038: jal         0x8013CF60
    // 0x8013C03C: nop

    ftCommonRebirthDownSetStatus(rdram, ctx);
        goto after_3;
    // 0x8013C03C: nop

    after_3:
    // 0x8013C040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C044:
    // 0x8013C044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013C048: jr          $ra
    // 0x8013C04C: nop

    return;
    // 0x8013C04C: nop

;}
RECOMP_FUNC void ftBossOkuhikouki2ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801595A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801595A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801595A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801595AC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801595B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801595B4: nop

    // 0x801595B8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801595BC: nop

    // 0x801595C0: bc1fl       L_801595E4
    if (!c1cs) {
        // 0x801595C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801595E4;
    }
    goto skip_0;
    // 0x801595C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801595C8: jal         0x8010CF20
    // 0x801595CC: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_0;
    // 0x801595CC: nop

    after_0:
    // 0x801595D0: jal         0x801597A4
    // 0x801595D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossOkuhikouki3SetStatus(rdram, ctx);
        goto after_1;
    // 0x801595D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801595D8: jal         0x80158620
    // 0x801595DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossCommonSetDisableFogColor(rdram, ctx);
        goto after_2;
    // 0x801595DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801595E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801595E4:
    // 0x801595E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801595E8: jr          $ra
    // 0x801595EC: nop

    return;
    // 0x801595EC: nop

;}
RECOMP_FUNC void sc1PGameBossSetCameraZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F4B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018F4B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018F4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F4BC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8018F4C0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018F4C4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8018F4C8: lw          $t6, 0x804($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X804);
    // 0x8018F4CC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8018F4D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018F4D4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8018F4D8: jal         0x800EDF24
    // 0x8018F4DC: lw          $a0, 0x8E8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8018F4DC: lw          $a0, 0x8E8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8E8);
    after_0:
    // 0x8018F4E0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8018F4E4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8018F4E8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018F4EC: addiu       $t9, $t9, 0x2FD0
    ctx->r25 = ADD32(ctx->r25, 0X2FD0);
    // 0x8018F4F0: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8018F4F4: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8018F4F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F4FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8018F500: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x8018F504: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8018F508: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x8018F50C: lwc1        $f10, 0x2F30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2F30);
    // 0x8018F510: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018F514: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018F518: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018F51C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F520: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018F524: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8018F528: jal         0x8010D0A4
    // 0x8018F52C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    gmCameraSetStatusMapZoom(rdram, ctx);
        goto after_1;
    // 0x8018F52C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8018F530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018F538: jr          $ra
    // 0x8018F53C: nop

    return;
    // 0x8018F53C: nop

;}
RECOMP_FUNC void syMatrixTraRotPyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CDDC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001CDE0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CDE4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CDE8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001CDEC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001CDF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CDF4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001CDF8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CDFC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CE00: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001CE04: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001CE08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001CE0C: jal         0x8001CD8C
    // 0x8001CE10: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    syMatrixTraRotPyRF(rdram, ctx);
        goto after_0;
    // 0x8001CE10: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8001CE14: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001CE18: jal         0x80019EA0
    // 0x8001CE1C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CE1C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001CE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CE24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001CE28: jr          $ra
    // 0x8001CE2C: nop

    return;
    // 0x8001CE2C: nop

;}
RECOMP_FUNC void itPippiMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80183694: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80183698: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8018369C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801836A0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801836A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801836A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801836AC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801836B0: addiu       $a1, $a1, -0x4C60
    ctx->r5 = ADD32(ctx->r5, -0X4C60);
    // 0x801836B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801836B8: jal         0x8016E174
    // 0x801836BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801836BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801836C0: beq         $v0, $zero, L_8018378C
    if (ctx->r2 == 0) {
        // 0x801836C4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8018378C;
    }
    // 0x801836C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x801836C8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801836CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801836D0: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801836D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801836D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801836DC: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x801836E0: sh          $t7, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r15;
    // 0x801836E4: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x801836E8: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x801836EC: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x801836F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801836F4: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x801836F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801836FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80183700: jal         0x80008CC0
    // 0x80183704: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80183704: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80183708: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8018370C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80183710: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80183714: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80183718: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8018371C: addiu       $t5, $t5, 0x3598
    ctx->r13 = ADD32(ctx->r13, 0X3598);
    // 0x80183720: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x80183724: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80183728: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8018372C: addiu       $t7, $t7, 0x3624
    ctx->r15 = ADD32(ctx->r15, 0X3624);
    // 0x80183730: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80183734: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80183738: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8018373C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80183740: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x80183744: lw          $t1, 0x2D4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2D4);
    // 0x80183748: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x8018374C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80183750: nop

    // 0x80183754: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80183758: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018375C: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x80183760: lw          $t3, 0x2D4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2D4);
    // 0x80183764: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80183768: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8018376C: jal         0x8000BD1C
    // 0x80183770: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80183770: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80183774: jal         0x800269C0
    // 0x80183778: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80183778: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_3:
    // 0x8018377C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80183780: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80183784: addiu       $t8, $t8, 0x3344
    ctx->r24 = ADD32(ctx->r24, 0X3344);
    // 0x80183788: sw          $t8, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r24;
L_8018378C:
    // 0x8018378C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80183790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80183794: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80183798: jr          $ra
    // 0x8018379C: nop

    return;
    // 0x8018379C: nop

;}
RECOMP_FUNC void mvEndingMakeRoomPencils(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D44: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131D48: jal         0x80009968
    // 0x80131D4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D54: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131D58: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131D5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D60: addiu       $t7, $t7, -0x5148
    ctx->r15 = ADD32(ctx->r15, -0X5148);
    // 0x80131D64: sw          $v0, 0x2BEC($at)
    MEM_W(0X2BEC, ctx->r1) = ctx->r2;
    // 0x80131D68: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131D74: jal         0x8000F120
    // 0x80131D78: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131D78: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131D7C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131D80: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131D84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131D88: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131D8C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131D90: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131D94: jal         0x80009DF4
    // 0x80131D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131D9C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131DA0: lw          $t9, 0x2F70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2F70);
    // 0x80131DA4: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131DA8: addiu       $t0, $t0, -0x5090
    ctx->r8 = ADD32(ctx->r8, -0X5090);
    // 0x80131DAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131DB0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80131DB4: jal         0x8000BD8C
    // 0x80131DB8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131DB8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131DBC: jal         0x8000DF34
    // 0x80131DC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcPlayAnimAll(rdram, ctx);
        goto after_4;
    // 0x80131DC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80131DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131DCC: jr          $ra
    // 0x80131DD0: nop

    return;
    // 0x80131DD0: nop

;}
RECOMP_FUNC void dbUiNodeTypeFindIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381C2C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80381C30: lhu         $a1, -0x42F0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X42F0);
    // 0x80381C34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80381C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80381C3C: blez        $a1, L_80381C78
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80381C40: lui         $a2, 0x8039
        ctx->r6 = S32(0X8039 << 16);
            goto L_80381C78;
    }
    // 0x80381C40: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80381C44: addiu       $a2, $a2, -0x440
    ctx->r6 = ADD32(ctx->r6, -0X440);
    // 0x80381C48: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_80381C4C:
    // 0x80381C4C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80381C50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80381C54: bnel        $a0, $t8, L_80381C68
    if (ctx->r4 != ctx->r24) {
        // 0x80381C58: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80381C68;
    }
    goto skip_0;
    // 0x80381C58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80381C5C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80381C60: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80381C64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80381C68:
    // 0x80381C68: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80381C6C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80381C70: bnel        $at, $zero, L_80381C4C
    if (ctx->r1 != 0) {
        // 0x80381C74: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_80381C4C;
    }
    goto skip_1;
    // 0x80381C74: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    skip_1:
L_80381C78:
    // 0x80381C78: jr          $ra
    // 0x80381C7C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    return;
    // 0x80381C7C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
;}
RECOMP_FUNC void ftPikachuSpecialLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015236C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152370: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152374: jal         0x80152328
    // 0x80152378: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwLoopUpdateThunder(rdram, ctx);
        goto after_0;
    // 0x80152378: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015237C: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80152380: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80152384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152388: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015238C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80152390: jal         0x800E6F24
    // 0x80152394: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152394: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80152398: jal         0x800E0830
    // 0x8015239C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015239C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801523A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801523A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801523A8: jr          $ra
    // 0x801523AC: nop

    return;
    // 0x801523AC: nop

;}
RECOMP_FUNC void syAudioSetBGMReverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020C60: sltiu       $at, $a1, 0x80
    ctx->r1 = ctx->r5 < 0X80 ? 1 : 0;
    // 0x80020C64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80020C68: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80020C6C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80020C70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80020C74: bne         $at, $zero, L_80020C80
    if (ctx->r1 != 0) {
        // 0x80020C78: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80020C80;
    }
    // 0x80020C78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80020C7C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_80020C80:
    // 0x80020C80: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020C84: addiu       $t7, $t7, -0x26A0
    ctx->r15 = ADD32(ctx->r15, -0X26A0);
    // 0x80020C88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80020C8C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80020C90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020C94: andi        $s2, $a1, 0xFF
    ctx->r18 = ctx->r5 & 0XFF;
    // 0x80020C98: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80020C9C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80020CA0:
    // 0x80020CA0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80020CA4: jal         0x80026010
    // 0x80020CA8: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    alCSPSetChlFXMix(rdram, ctx);
        goto after_0;
    // 0x80020CA8: andi        $a2, $s2, 0xFF
    ctx->r6 = ctx->r18 & 0XFF;
    after_0:
    // 0x80020CAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020CB0: bnel        $s0, $s3, L_80020CA0
    if (ctx->r16 != ctx->r19) {
        // 0x80020CB4: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80020CA0;
    }
    goto skip_0;
    // 0x80020CB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80020CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80020CBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80020CC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80020CC4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80020CC8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80020CCC: jr          $ra
    // 0x80020CD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80020CD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftSamusSpecialNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D4A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D4A4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015D4A8: jal         0x800DDE84
    // 0x8015D4AC: addiu       $a1, $a1, -0x2AC0
    ctx->r5 = ADD32(ctx->r5, -0X2AC0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015D4AC: addiu       $a1, $a1, -0x2AC0
    ctx->r5 = ADD32(ctx->r5, -0X2AC0);
    after_0:
    // 0x8015D4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D4B8: jr          $ra
    // 0x8015D4BC: nop

    return;
    // 0x8015D4BC: nop

;}
RECOMP_FUNC void ftCommonCliffAttackQuick1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801456B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801456B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801456BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801456C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801456C4: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x801456C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801456CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801456D0: jal         0x800E6F24
    // 0x801456D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801456D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801456D8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801456DC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801456E0: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x801456E4: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x801456E8: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x801456EC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801456F0: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x801456F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801456F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801456FC: jr          $ra
    // 0x80145700: nop

    return;
    // 0x80145700: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingArrowThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013438C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80134390: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80134394: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80134398: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8013439C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801343A0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801343A4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801343A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801343AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801343B0: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x801343B4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801343B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801343BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801343C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801343C4: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x801343C8: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x801343CC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801343D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801343D4: lw          $s3, 0x84($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X84);
    // 0x801343D8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x801343DC: addiu       $fp, $fp, -0x7AA8
    ctx->r30 = ADD32(ctx->r30, -0X7AA8);
    // 0x801343E0: addiu       $s6, $s6, -0x7368
    ctx->r22 = ADD32(ctx->r22, -0X7368);
    // 0x801343E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801343E8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801343EC: addiu       $s7, $zero, -0x21
    ctx->r23 = ADD32(0, -0X21);
    // 0x801343F0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_801343F4:
    // 0x801343F4: bne         $s2, $zero, L_80134418
    if (ctx->r18 != 0) {
        // 0x801343F8: sll         $t7, $s3, 2
        ctx->r15 = S32(ctx->r19 << 2);
            goto L_80134418;
    }
    // 0x801343F8: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x801343FC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80134400: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80134404: bnel        $s4, $t6, L_80134418
    if (ctx->r20 != ctx->r14) {
        // 0x80134408: sw          $s4, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r20;
            goto L_80134418;
    }
    goto skip_0;
    // 0x80134408: sw          $s4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r20;
    skip_0:
    // 0x8013440C: b           L_80134418
    // 0x80134410: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_80134418;
    // 0x80134410: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80134414: sw          $s4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r20;
L_80134418:
    // 0x80134418: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x8013441C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134420: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80134424: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80134428: addu        $v0, $fp, $t7
    ctx->r2 = ADD32(ctx->r30, ctx->r15);
    // 0x8013442C: lw          $t8, 0x80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X80);
    // 0x80134430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134438: bnel        $t8, $zero, L_8013444C
    if (ctx->r24 != 0) {
        // 0x8013443C: lw          $s1, 0x38($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X38);
            goto L_8013444C;
    }
    goto skip_1;
    // 0x8013443C: lw          $s1, 0x38($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X38);
    skip_1:
    // 0x80134440: b           L_8013444C
    // 0x80134444: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
        goto L_8013444C;
    // 0x80134444: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x80134448: lw          $s1, 0x38($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X38);
L_8013444C:
    // 0x8013444C: bne         $s1, $s5, L_80134474
    if (ctx->r17 != ctx->r21) {
        // 0x80134450: nop
    
            goto L_80134474;
    }
    // 0x80134450: nop

    // 0x80134454: jal         0x80134340
    // 0x80134458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingGetArrowSObj(rdram, ctx);
        goto after_0;
    // 0x80134458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013445C: beq         $v0, $zero, L_801344D4
    if (ctx->r2 == 0) {
        // 0x80134460: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801344D4;
    }
    // 0x80134460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134464: jal         0x800096EC
    // 0x80134468: nop

    gcEjectSObj(rdram, ctx);
        goto after_1;
    // 0x80134468: nop

    after_1:
    // 0x8013446C: b           L_801344D8
    // 0x80134470: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
        goto L_801344D8;
    // 0x80134470: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_80134474:
    // 0x80134474: jal         0x80134340
    // 0x80134478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PTrainingGetArrowSObj(rdram, ctx);
        goto after_2;
    // 0x80134478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8013447C: bne         $v0, $zero, L_801344D4
    if (ctx->r2 != 0) {
        // 0x80134480: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801344D4;
    }
    // 0x80134480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134484: sll         $t1, $s3, 4
    ctx->r9 = S32(ctx->r19 << 4);
    // 0x80134488: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x8013448C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80134490: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x80134494: addiu       $t2, $t1, 0x19
    ctx->r10 = ADD32(ctx->r9, 0X19);
    // 0x80134498: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013449C: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x801344A0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801344A4: addiu       $t0, $t0, -0x1318
    ctx->r8 = ADD32(ctx->r8, -0X1318);
    // 0x801344A8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x801344AC: jal         0x800CCFDC
    // 0x801344B0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801344B0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x801344B4: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x801344B8: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x801344BC: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x801344C0: and         $t5, $t3, $s7
    ctx->r13 = ctx->r11 & ctx->r23;
    // 0x801344C4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801344C8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x801344CC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801344D0: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_801344D4:
    // 0x801344D4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_801344D8:
    // 0x801344D8: bne         $s1, $at, L_80134504
    if (ctx->r17 != ctx->r1) {
        // 0x801344DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134504;
    }
    // 0x801344DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801344E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801344E4: jal         0x80134340
    // 0x801344E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayers1PTrainingGetArrowSObj(rdram, ctx);
        goto after_4;
    // 0x801344E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x801344EC: beq         $v0, $zero, L_80134564
    if (ctx->r2 == 0) {
        // 0x801344F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80134564;
    }
    // 0x801344F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801344F4: jal         0x800096EC
    // 0x801344F8: nop

    gcEjectSObj(rdram, ctx);
        goto after_5;
    // 0x801344F8: nop

    after_5:
    // 0x801344FC: b           L_80134564
    // 0x80134500: nop

        goto L_80134564;
    // 0x80134500: nop

L_80134504:
    // 0x80134504: jal         0x80134340
    // 0x80134508: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayers1PTrainingGetArrowSObj(rdram, ctx);
        goto after_6;
    // 0x80134508: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x8013450C: bne         $v0, $zero, L_80134564
    if (ctx->r2 != 0) {
        // 0x80134510: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80134564;
    }
    // 0x80134510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134514: sll         $t9, $s3, 4
    ctx->r25 = S32(ctx->r19 << 4);
    // 0x80134518: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x8013451C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80134520: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x80134524: addiu       $t0, $t9, 0x4F
    ctx->r8 = ADD32(ctx->r25, 0X4F);
    // 0x80134528: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8013452C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80134530: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80134534: addiu       $t8, $t8, -0x1238
    ctx->r24 = ADD32(ctx->r24, -0X1238);
    // 0x80134538: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8013453C: jal         0x800CCFDC
    // 0x80134540: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80134540: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    after_7:
    // 0x80134544: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80134548: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x8013454C: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x80134550: and         $t3, $t1, $s7
    ctx->r11 = ctx->r9 & ctx->r23;
    // 0x80134554: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80134558: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8013455C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80134560: sw          $s5, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r21;
L_80134564:
    // 0x80134564: jal         0x8000B1E8
    // 0x80134568: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x80134568: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x8013456C: b           L_801343F4
    // 0x80134570: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_801343F4;
    // 0x80134570: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80134574: nop

    // 0x80134578: nop

    // 0x8013457C: nop

    // 0x80134580: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80134584: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80134588: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013458C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80134590: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80134594: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80134598: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8013459C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801345A0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801345A4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801345A8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801345AC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801345B0: jr          $ra
    // 0x801345B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801345B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void lbCommonSin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7840: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7844: lwc1        $f4, 0x5E60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E60);
    // 0x800C7848: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C784C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C7850: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C7854: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C7858: nop

    // 0x800C785C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C7860: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C7864: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
    // 0x800C7868: beq         $t7, $zero, L_800C788C
    if (ctx->r15 == 0) {
        // 0x800C786C: andi        $t3, $v0, 0x800
        ctx->r11 = ctx->r2 & 0X800;
            goto L_800C788C;
    }
    // 0x800C786C: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x800C7870: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x800C7874: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C7878: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x800C787C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7880: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C7884: b           L_800C789C
    // 0x800C7888: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
        goto L_800C789C;
    // 0x800C7888: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
L_800C788C:
    // 0x800C788C: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x800C7890: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C7894: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C7898: lwc1        $f2, 0x4CA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4CA0);
L_800C789C:
    // 0x800C789C: beql        $t3, $zero, L_800C78B0
    if (ctx->r11 == 0) {
        // 0x800C78A0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800C78B0;
    }
    goto skip_0;
    // 0x800C78A0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x800C78A4: jr          $ra
    // 0x800C78A8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    return;
    // 0x800C78A8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800C78AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800C78B0:
    // 0x800C78B0: jr          $ra
    // 0x800C78B4: nop

    return;
    // 0x800C78B4: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9F0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D9F4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D9F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D9FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DA00: lbu         $v0, 0x11($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X11);
    // 0x8018DA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DA08: beq         $v0, $at, L_8018DA20
    if (ctx->r2 == ctx->r1) {
        // 0x8018DA0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018DA20;
    }
    // 0x8018DA0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018DA10: beq         $v0, $at, L_8018DA30
    if (ctx->r2 == ctx->r1) {
        // 0x8018DA14: nop
    
            goto L_8018DA30;
    }
    // 0x8018DA14: nop

    // 0x8018DA18: b           L_8018DA38
    // 0x8018DA1C: nop

        goto L_8018DA38;
    // 0x8018DA1C: nop

L_8018DA20:
    // 0x8018DA20: jal         0x8018D0E8
    // 0x8018DA24: nop

    sc1PTrainingModeCheckEnterMenu(rdram, ctx);
        goto after_0;
    // 0x8018DA24: nop

    after_0:
    // 0x8018DA28: b           L_8018DA38
    // 0x8018DA2C: nop

        goto L_8018DA38;
    // 0x8018DA2C: nop

L_8018DA30:
    // 0x8018DA30: jal         0x8018D91C
    // 0x8018DA34: nop

    sc1PTrainingModeUpdateMenu(rdram, ctx);
        goto after_1;
    // 0x8018DA34: nop

    after_1:
L_8018DA38:
    // 0x8018DA38: jal         0x8018D974
    // 0x8018DA3C: nop

    sc1PTrainingModeCheckLagTic(rdram, ctx);
        goto after_2;
    // 0x8018DA3C: nop

    after_2:
    // 0x8018DA40: bne         $v0, $zero, L_8018DA58
    if (ctx->r2 != 0) {
        // 0x8018DA44: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8018DA58;
    }
    // 0x8018DA44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DA48: jal         0x8000A5E4
    // 0x8018DA4C: nop

    gcRunAll(rdram, ctx);
        goto after_3;
    // 0x8018DA4C: nop

    after_3:
    // 0x8018DA50: b           L_8018DA60
    // 0x8018DA54: nop

        goto L_8018DA60;
    // 0x8018DA54: nop

L_8018DA58:
    // 0x8018DA58: jal         0x8010CECC
    // 0x8018DA5C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    gmCameraRunFuncCamera(rdram, ctx);
        goto after_4;
    // 0x8018DA5C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    after_4:
L_8018DA60:
    // 0x8018DA60: jal         0x80114800
    // 0x8018DA64: nop

    ifCommonSetMaxNumGObj(rdram, ctx);
        goto after_5;
    // 0x8018DA64: nop

    after_5:
    // 0x8018DA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DA6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DA70: jr          $ra
    // 0x8018DA74: nop

    return;
    // 0x8018DA74: nop

;}
RECOMP_FUNC void gmCollisionCheckFighterAttackShieldCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFCC0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800EFCC4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800EFCC8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EFCCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EFCD0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EFCD4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800EFCD8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800EFCDC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800EFCE0: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x800EFCE4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800EFCE8: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800EFCEC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800EFCF0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800EFCF4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800EFCF8: lw          $t6, 0x84($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X84);
    // 0x800EFCFC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800EFD00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EFD04: jal         0x800EDE00
    // 0x800EFD08: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EFD08: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    after_0:
    // 0x800EFD0C: jal         0x800EDE5C
    // 0x800EFD10: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800EFD10: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x800EFD14: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x800EFD18: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x800EFD1C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800EFD20: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x800EFD24: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EFD28: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x800EFD2C: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x800EFD30: addiu       $t7, $v1, 0x9C
    ctx->r15 = ADD32(ctx->r3, 0X9C);
    // 0x800EFD34: addiu       $t0, $v1, 0x90
    ctx->r8 = ADD32(ctx->r3, 0X90);
    // 0x800EFD38: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800EFD3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800EFD40: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800EFD44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800EFD48: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800EFD4C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800EFD50: addiu       $a0, $v0, 0x44
    ctx->r4 = ADD32(ctx->r2, 0X44);
    // 0x800EFD54: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    // 0x800EFD58: jal         0x800EE750
    // 0x800EFD5C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    gmCollisionTestSphere(rdram, ctx);
        goto after_2;
    // 0x800EFD5C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_2:
    // 0x800EFD60: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800EFD64: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800EFD68: jr          $ra
    // 0x800EFD6C: nop

    return;
    // 0x800EFD6C: nop

;}
RECOMP_FUNC void mvOpeningRoomEjectCameraGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013418C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134190: jal         0x80009A84
    // 0x80134194: lw          $a0, 0x4CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CE8);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80134194: lw          $a0, 0x4CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CE8);
    after_0:
    // 0x80134198: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013419C: jal         0x80009A84
    // 0x801341A0: lw          $a0, 0x4CEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CEC);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x801341A0: lw          $a0, 0x4CEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CEC);
    after_1:
    // 0x801341A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801341A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801341AC: jr          $ra
    // 0x801341B0: nop

    return;
    // 0x801341B0: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157C30: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80157C34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80157C38: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80157C3C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80157C40: nop

    // 0x80157C44: bc1fl       L_80157C60
    if (!c1cs) {
        // 0x80157C48: lw          $v0, 0x24($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X24);
            goto L_80157C60;
    }
    goto skip_0;
    // 0x80157C48: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    skip_0:
    // 0x80157C4C: jal         0x800DEE54
    // 0x80157C50: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_0;
    // 0x80157C50: nop

    after_0:
    // 0x80157C54: b           L_80157D0C
    // 0x80157C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80157D0C;
    // 0x80157C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157C5C: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
L_80157C60:
    // 0x80157C60: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80157C64: beq         $v0, $at, L_80157C74
    if (ctx->r2 == ctx->r1) {
        // 0x80157C68: addiu       $at, $zero, 0xF7
        ctx->r1 = ADD32(0, 0XF7);
            goto L_80157C74;
    }
    // 0x80157C68: addiu       $at, $zero, 0xF7
    ctx->r1 = ADD32(0, 0XF7);
    // 0x80157C6C: bnel        $v0, $at, L_80157D0C
    if (ctx->r2 != ctx->r1) {
        // 0x80157C70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157D0C;
    }
    goto skip_1;
    // 0x80157C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80157C74:
    // 0x80157C74: lw          $t6, 0x294($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X294);
    // 0x80157C78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80157C7C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80157C80: bne         $a0, $t6, L_80157C9C
    if (ctx->r4 != ctx->r14) {
        // 0x80157C84: addiu       $v1, $v0, 0x294
        ctx->r3 = ADD32(ctx->r2, 0X294);
            goto L_80157C9C;
    }
    // 0x80157C84: addiu       $v1, $v0, 0x294
    ctx->r3 = ADD32(ctx->r2, 0X294);
    // 0x80157C88: lw          $t8, 0xB1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XB1C);
    // 0x80157C8C: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80157C90: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80157C94: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80157C98: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
L_80157C9C:
    // 0x80157C9C: lw          $t1, 0x358($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X358);
    // 0x80157CA0: addiu       $v1, $v0, 0x358
    ctx->r3 = ADD32(ctx->r2, 0X358);
    // 0x80157CA4: bnel        $a0, $t1, L_80157CC4
    if (ctx->r4 != ctx->r9) {
        // 0x80157CA8: lw          $t6, 0x41C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X41C);
            goto L_80157CC4;
    }
    goto skip_2;
    // 0x80157CA8: lw          $t6, 0x41C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X41C);
    skip_2:
    // 0x80157CAC: lw          $t3, 0xB1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XB1C);
    // 0x80157CB0: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80157CB4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80157CB8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80157CBC: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80157CC0: lw          $t6, 0x41C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X41C);
L_80157CC4:
    // 0x80157CC4: addiu       $v1, $v0, 0x41C
    ctx->r3 = ADD32(ctx->r2, 0X41C);
    // 0x80157CC8: bnel        $a0, $t6, L_80157CE8
    if (ctx->r4 != ctx->r14) {
        // 0x80157CCC: lw          $t1, 0x4E0($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X4E0);
            goto L_80157CE8;
    }
    goto skip_3;
    // 0x80157CCC: lw          $t1, 0x4E0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4E0);
    skip_3:
    // 0x80157CD0: lw          $t7, 0xB1C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB1C);
    // 0x80157CD4: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80157CD8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80157CDC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80157CE0: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80157CE4: lw          $t1, 0x4E0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4E0);
L_80157CE8:
    // 0x80157CE8: addiu       $v1, $v0, 0x4E0
    ctx->r3 = ADD32(ctx->r2, 0X4E0);
    // 0x80157CEC: bnel        $a0, $t1, L_80157D0C
    if (ctx->r4 != ctx->r9) {
        // 0x80157CF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157D0C;
    }
    goto skip_4;
    // 0x80157CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80157CF4: lw          $t2, 0xB1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XB1C);
    // 0x80157CF8: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x80157CFC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80157D00: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80157D04: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80157D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157D0C:
    // 0x80157D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157D10: jr          $ra
    // 0x80157D14: nop

    return;
    // 0x80157D14: nop

;}
RECOMP_FUNC void mpCommonCheckFighterProject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE72C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE730: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE734: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE738: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE73C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800DE740: jal         0x800DA034
    // 0x800DE744: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE744: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE74C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE750: jr          $ra
    // 0x800DE754: nop

    return;
    // 0x800DE754: nop

;}
RECOMP_FUNC void itRShellSpinAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B1A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B1A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B1AC: jal         0x8017B108
    // 0x8017B1B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itRShellSpinAirInitVars(rdram, ctx);
        goto after_0;
    // 0x8017B1B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017B1B4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B1B8: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017B1BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1C0: jal         0x80172EC8
    // 0x8017B1C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017B1C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x8017B1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B1D0: jr          $ra
    // 0x8017B1D4: nop

    return;
    // 0x8017B1D4: nop

;}
RECOMP_FUNC void ifCommonEntryFocusThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112880: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80112884: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80112888: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8011288C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80112890: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80112894: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80112898: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8011289C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801128A0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801128A4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801128A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801128AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801128B0: addiu       $t7, $t7, -0x11B4
    ctx->r15 = ADD32(ctx->r15, -0X11B4);
    // 0x801128B4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x801128B8: addu        $s4, $t6, $t7
    ctx->r20 = ADD32(ctx->r14, ctx->r15);
    // 0x801128BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801128C0: bne         $v0, $at, L_801128D0
    if (ctx->r2 != ctx->r1) {
        // 0x801128C4: lhu         $s2, 0x0($s4)
        ctx->r18 = MEM_HU(ctx->r20, 0X0);
            goto L_801128D0;
    }
    // 0x801128C4: lhu         $s2, 0x0($s4)
    ctx->r18 = MEM_HU(ctx->r20, 0X0);
    // 0x801128C8: jal         0x8000B1E8
    // 0x801128CC: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x801128CC: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
L_801128D0:
    // 0x801128D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801128D4: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x801128D8: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x801128DC: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    // 0x801128E0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x801128E4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x801128E8: beq         $at, $zero, L_801128F8
    if (ctx->r1 == 0) {
        // 0x801128EC: nop
    
            goto L_801128F8;
    }
    // 0x801128EC: nop

    // 0x801128F0: jal         0x8000B1E8
    // 0x801128F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x801128F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
L_801128F8:
    // 0x801128F8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801128FC: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80112900: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80112904: addiu       $s3, $s3, -0x11B0
    ctx->r19 = ADD32(ctx->r19, -0X11B0);
    // 0x80112908: beq         $s0, $zero, L_80112980
    if (ctx->r16 == 0) {
        // 0x8011290C: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80112980;
    }
    // 0x8011290C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80112910: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80112914: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112918: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8011291C: lwc1        $f22, 0xC8C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0XC8C);
L_80112920:
    // 0x80112920: jal         0x8013DBE0
    // 0x80112924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppearSetStatus(rdram, ctx);
        goto after_2;
    // 0x80112924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80112928: bne         $s4, $s3, L_8011296C
    if (ctx->r20 != ctx->r19) {
        // 0x8011292C: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_8011296C;
    }
    // 0x8011292C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80112930: jal         0x8000B1E8
    // 0x80112934: addiu       $s1, $s2, -0x1E
    ctx->r17 = ADD32(ctx->r18, -0X1E);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x80112934: addiu       $s1, $s2, -0x1E
    ctx->r17 = ADD32(ctx->r18, -0X1E);
    after_3:
    // 0x80112938: lw          $t0, 0x84($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X84);
    // 0x8011293C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80112940: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80112944: lw          $t1, 0x9C8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X9C8);
    // 0x80112948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011294C: lw          $a3, 0x90($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X90);
    // 0x80112950: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80112954: jal         0x8010CF44
    // 0x80112958: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_4;
    // 0x80112958: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_4:
    // 0x8011295C: jal         0x8000B1E8
    // 0x80112960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80112960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80112964: b           L_80112978
    // 0x80112968: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
        goto L_80112978;
    // 0x80112968: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_8011296C:
    // 0x8011296C: jal         0x8000B1E8
    // 0x80112970: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_6;
    // 0x80112970: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80112974: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80112978:
    // 0x80112978: bne         $s0, $zero, L_80112920
    if (ctx->r16 != 0) {
        // 0x8011297C: nop
    
            goto L_80112920;
    }
    // 0x8011297C: nop

L_80112980:
    // 0x80112980: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80112984: addiu       $t2, $t2, -0x11B0
    ctx->r10 = ADD32(ctx->r10, -0X11B0);
    // 0x80112988: bne         $s4, $t2, L_801129A0
    if (ctx->r20 != ctx->r10) {
        // 0x8011298C: nop
    
            goto L_801129A0;
    }
    // 0x8011298C: nop

    // 0x80112990: jal         0x8000B1E8
    // 0x80112994: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_7;
    // 0x80112994: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_7:
    // 0x80112998: jal         0x8010CF20
    // 0x8011299C: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_8;
    // 0x8011299C: nop

    after_8:
L_801129A0:
    // 0x801129A0: jal         0x80009A84
    // 0x801129A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_9;
    // 0x801129A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x801129A8: jal         0x8000B1E8
    // 0x801129AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_10;
    // 0x801129AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x801129B0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801129B4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801129B8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801129BC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801129C0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801129C4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801129C8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801129CC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801129D0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801129D4: jr          $ra
    // 0x801129D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801129D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftFoxSpecialLwEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015D13C: jal         0x8015CBA4
    // 0x8015D140: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftFoxSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015D140: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015D144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8015D148: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015D14C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015D150: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015D154: nop

    // 0x8015D158: bc1fl       L_8015D174
    if (!c1cs) {
        // 0x8015D15C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015D174;
    }
    goto skip_0;
    // 0x8015D15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015D160: jal         0x800E9C3C
    // 0x8015D164: nop

    ftParamProcStopEffect(rdram, ctx);
        goto after_1;
    // 0x8015D164: nop

    after_1:
    // 0x8015D168: jal         0x800DEE54
    // 0x8015D16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x8015D16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015D170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D174:
    // 0x8015D174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D178: jr          $ra
    // 0x8015D17C: nop

    return;
    // 0x8015D17C: nop

;}
RECOMP_FUNC void efManagerStarRodSparkProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFE08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFE0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFE10: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800FFE14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FFE18: jal         0x8000DF34
    // 0x800FFE1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FFE1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FFE20: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FFE24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FFE28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFE2C: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x800FFE30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800FFE34: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FFE38: nop

    // 0x800FFE3C: bc1fl       L_800FFE60
    if (!c1cs) {
        // 0x800FFE40: lw          $v0, 0x30($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X30);
            goto L_800FFE60;
    }
    goto skip_0;
    // 0x800FFE40: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    skip_0:
    // 0x800FFE44: jal         0x800FD4F8
    // 0x800FFE48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FFE48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800FFE4C: jal         0x80009A84
    // 0x800FFE50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FFE50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FFE54: b           L_800FFE98
    // 0x800FFE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FFE98;
    // 0x800FFE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFE5C: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
L_800FFE60:
    // 0x800FFE60: beql        $v0, $zero, L_800FFE84
    if (ctx->r2 == 0) {
        // 0x800FFE64: lw          $v0, 0x74($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X74);
            goto L_800FFE84;
    }
    goto skip_1;
    // 0x800FFE64: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    skip_1:
    // 0x800FFE68: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FFE6C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800FFE70: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800FFE74: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x800FFE78: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FFE7C: swc1        $f16, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f16.u32l;
    // 0x800FFE80: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
L_800FFE84:
    // 0x800FFE84: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FFE88: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FFE8C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800FFE90: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x800FFE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FFE98:
    // 0x800FFE98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FFE9C: jr          $ra
    // 0x800FFEA0: nop

    return;
    // 0x800FFEA0: nop

;}
RECOMP_FUNC void func_ovl8_803722A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803722A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803722A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803722A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803722AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803722B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x803722B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x803722B8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x803722BC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x803722C0: lh          $t7, 0x48($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X48);
    // 0x803722C4: jalr        $t9
    // 0x803722C8: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803722C8: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_0:
    // 0x803722CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x803722D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x803722D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x803722D8: jal         0x803787C0
    // 0x803722DC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_ovl8_803787C0(rdram, ctx);
        goto after_1;
    // 0x803722DC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x803722E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803722E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803722E8: jr          $ra
    // 0x803722EC: nop

    return;
    // 0x803722EC: nop

;}
RECOMP_FUNC void ftPhysicsSetGroundVelAbsStickRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8A70: lb          $v0, 0x1C2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1C2);
    // 0x800D8A74: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8A78: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D8A7C: bgez        $v0, L_800D8A8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D8A80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D8A8C;
    }
    // 0x800D8A80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D8A84: b           L_800D8A8C
    // 0x800D8A88: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_800D8A8C;
    // 0x800D8A88: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800D8A8C:
    // 0x800D8A8C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D8A90: lwc1        $f2, 0x60($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8A94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D8A98: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D8A9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800D8AA0: nop

    // 0x800D8AA4: bc1fl       L_800D8AB8
    if (!c1cs) {
        // 0x800D8AA8: sub.s       $f8, $f2, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_800D8AB8;
    }
    goto skip_0;
    // 0x800D8AA8: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    skip_0:
    // 0x800D8AAC: jr          $ra
    // 0x800D8AB0: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800D8AB0: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    // 0x800D8AB4: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
L_800D8AB8:
    // 0x800D8AB8: swc1        $f8, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f8.u32l;
    // 0x800D8ABC: lwc1        $f10, 0x60($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8AC0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800D8AC4: nop

    // 0x800D8AC8: bc1f        L_800D8AD4
    if (!c1cs) {
        // 0x800D8ACC: nop
    
            goto L_800D8AD4;
    }
    // 0x800D8ACC: nop

    // 0x800D8AD0: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
L_800D8AD4:
    // 0x800D8AD4: jr          $ra
    // 0x800D8AD8: nop

    return;
    // 0x800D8AD8: nop

;}
RECOMP_FUNC void ftPhysicsApplyClampGroundVelStickRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D89E0: lb          $v0, 0x1C2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1C2);
    // 0x800D89E4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800D89E8: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800D89EC: bgez        $v0, L_800D89FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D89F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D89FC;
    }
    // 0x800D89F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D89F4: b           L_800D89FC
    // 0x800D89F8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_800D89FC;
    // 0x800D89F8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800D89FC:
    // 0x800D89FC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D8A00: bne         $at, $zero, L_800D8A68
    if (ctx->r1 != 0) {
        // 0x800D8A04: nop
    
            goto L_800D8A68;
    }
    // 0x800D8A04: nop

    // 0x800D8A08: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D8A0C: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800D8A10: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x800D8A14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D8A18: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D8A1C: lwc1        $f4, 0x60($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8A20: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D8A24: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D8A28: nop

    // 0x800D8A2C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800D8A30: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800D8A34: swc1        $f6, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f6.u32l;
    // 0x800D8A38: lwc1        $f0, 0x60($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8A3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D8A40: nop

    // 0x800D8A44: bc1f        L_800D8A54
    if (!c1cs) {
        // 0x800D8A48: nop
    
            goto L_800D8A54;
    }
    // 0x800D8A48: nop

    // 0x800D8A4C: jr          $ra
    // 0x800D8A50: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D8A50: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
L_800D8A54:
    // 0x800D8A54: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800D8A58: nop

    // 0x800D8A5C: bc1f        L_800D8A68
    if (!c1cs) {
        // 0x800D8A60: nop
    
            goto L_800D8A68;
    }
    // 0x800D8A60: nop

    // 0x800D8A64: swc1        $f14, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f14.u32l;
L_800D8A68:
    // 0x800D8A68: jr          $ra
    // 0x800D8A6C: nop

    return;
    // 0x800D8A6C: nop

;}
RECOMP_FUNC void func_ovl8_80372B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372B74: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80372B78: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x80372B7C: lh          $t6, 0x88($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X88);
    // 0x80372B80: jalr        $t9
    // 0x80372B84: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372B84: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80372B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372B90: jr          $ra
    // 0x80372B94: nop

    return;
    // 0x80372B94: nop

;}
RECOMP_FUNC void mnPlayersVSCheckNoPuckOnPortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A534: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A538: lw          $t6, -0x4578($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4578);
    // 0x8013A53C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A540: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A544: beq         $t6, $zero, L_8013A564
    if (ctx->r14 == 0) {
        // 0x8013A548: nop
    
            goto L_8013A564;
    }
    // 0x8013A548: nop

    // 0x8013A54C: lw          $t7, -0x4524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4524);
    // 0x8013A550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013A554: bne         $v0, $t7, L_8013A564
    if (ctx->r2 != ctx->r15) {
        // 0x8013A558: nop
    
            goto L_8013A564;
    }
    // 0x8013A558: nop

    // 0x8013A55C: jr          $ra
    // 0x8013A560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A564:
    // 0x8013A564: lw          $t8, -0x44BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44BC);
    // 0x8013A568: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013A56C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013A570: beq         $t8, $zero, L_8013A58C
    if (ctx->r24 == 0) {
        // 0x8013A574: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8013A58C;
    }
    // 0x8013A574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013A578: lw          $t9, -0x4468($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4468);
    // 0x8013A57C: bne         $v0, $t9, L_8013A58C
    if (ctx->r2 != ctx->r25) {
        // 0x8013A580: nop
    
            goto L_8013A58C;
    }
    // 0x8013A580: nop

    // 0x8013A584: jr          $ra
    // 0x8013A588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A58C:
    // 0x8013A58C: lw          $t0, -0x4400($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4400);
    // 0x8013A590: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013A594: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013A598: beq         $t0, $zero, L_8013A5B4
    if (ctx->r8 == 0) {
        // 0x8013A59C: nop
    
            goto L_8013A5B4;
    }
    // 0x8013A59C: nop

    // 0x8013A5A0: lw          $t1, -0x43AC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X43AC);
    // 0x8013A5A4: bne         $v0, $t1, L_8013A5B4
    if (ctx->r2 != ctx->r9) {
        // 0x8013A5A8: nop
    
            goto L_8013A5B4;
    }
    // 0x8013A5A8: nop

    // 0x8013A5AC: jr          $ra
    // 0x8013A5B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A5B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A5B4:
    // 0x8013A5B4: lw          $t2, -0x4344($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4344);
    // 0x8013A5B8: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x8013A5BC: beql        $t2, $zero, L_8013A5DC
    if (ctx->r10 == 0) {
        // 0x8013A5C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8013A5DC;
    }
    goto skip_0;
    // 0x8013A5C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8013A5C4: lw          $t3, -0x42F0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X42F0);
    // 0x8013A5C8: bnel        $v0, $t3, L_8013A5DC
    if (ctx->r2 != ctx->r11) {
        // 0x8013A5CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8013A5DC;
    }
    goto skip_1;
    // 0x8013A5CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8013A5D0: jr          $ra
    // 0x8013A5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013A5DC:
    // 0x8013A5DC: jr          $ra
    // 0x8013A5E0: nop

    return;
    // 0x8013A5E0: nop

;}
RECOMP_FUNC void ftMarioSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801560A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801560A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801560A8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801560AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801560B0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x801560B4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801560B8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801560BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801560C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801560C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801560C8: bc1f        L_801560E4
    if (!c1cs) {
        // 0x801560CC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801560E4;
    }
    // 0x801560CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801560D0: lwc1        $f8, -0x3980($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3980);
    // 0x801560D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801560D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801560DC: jal         0x801438F0
    // 0x801560E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x801560E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
L_801560E4:
    // 0x801560E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801560E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801560EC: jr          $ra
    // 0x801560F0: nop

    return;
    // 0x801560F0: nop

;}
RECOMP_FUNC void sc1PGameBossProcDisplayFadeAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191798: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019179C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801917A0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x801917A4: addiu       $v0, $v0, 0x38F0
    ctx->r2 = ADD32(ctx->r2, 0X38F0);
    // 0x801917A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801917AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801917B0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801917B4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801917B8: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x801917BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801917C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801917C4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801917C8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801917CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801917D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801917D4: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x801917D8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801917DC: nop

    // 0x801917E0: bc1fl       L_801917F4
    if (!c1cs) {
        // 0x801917E4: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801917F4;
    }
    goto skip_0;
    // 0x801917E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x801917E8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x801917EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801917F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801917F4:
    // 0x801917F4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801917F8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801917FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191800: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80191804: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191808: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019180C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191810: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80191814: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80191818: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019181C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80191820: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191824: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191828: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019182C: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80191830: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80191834: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191838: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019183C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80191840: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80191844: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191848: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8019184C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80191850: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80191854: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80191858: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8019185C: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80191860: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191864: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191868: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019186C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80191870: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80191874: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191878: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019187C: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80191880: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80191884: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191888: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019188C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191890: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80191894: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80191898: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019189C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801918A0: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x801918A4: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x801918A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801918AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801918B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801918B4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801918B8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801918BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801918C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801918C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801918C8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801918CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801918D0: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x801918D4: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x801918D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801918DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801918E0: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801918E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801918E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801918EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801918F0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x801918F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801918F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801918FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191900: jr          $ra
    // 0x80191904: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x80191904: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void mnPlayers1PBonusRecallPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013565C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135660: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80135664: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    // 0x80135668: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8013566C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80135670: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x80135674: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80135678: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8013567C: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x80135680: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80135684: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80135688: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8013568C: lwc1        $f4, 0x58($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80135690: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135694: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135698: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x8013569C: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x801356A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801356A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801356A8: lwc1        $f6, 0x5C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x801356AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801356B0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x801356B4: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x801356B8: lwc1        $f8, 0x58($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X58);
    // 0x801356BC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x801356C0: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x801356C4: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x801356C8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801356CC: nop

    // 0x801356D0: bc1fl       L_801356E0
    if (!c1cs) {
        // 0x801356D4: lw          $t0, 0x74($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X74);
            goto L_801356E0;
    }
    goto skip_0;
    // 0x801356D4: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    skip_0:
    // 0x801356D8: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x801356DC: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
L_801356E0:
    // 0x801356E0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x801356E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801356E8: lwc1        $f18, 0x5C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x801356EC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801356F0: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x801356F4: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x801356F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801356FC: nop

    // 0x80135700: bc1fl       L_80135714
    if (!c1cs) {
        // 0x80135704: lwc1        $f2, 0x40($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
            goto L_80135714;
    }
    goto skip_1;
    // 0x80135704: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x80135708: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x8013570C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80135710: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
L_80135714:
    // 0x80135714: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80135718: nop

    // 0x8013571C: bc1fl       L_80135734
    if (!c1cs) {
        // 0x80135720: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_80135734;
    }
    goto skip_2;
    // 0x80135720: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x80135724: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80135728: jr          $ra
    // 0x8013572C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8013572C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x80135730: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_80135734:
    // 0x80135734: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x80135738: jr          $ra
    // 0x8013573C: nop

    return;
    // 0x8013573C: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160AD4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80160AD8: jal         0x800DDE84
    // 0x80160ADC: addiu       $a1, $a1, 0xA80
    ctx->r5 = ADD32(ctx->r5, 0XA80);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80160ADC: addiu       $a1, $a1, 0xA80
    ctx->r5 = ADD32(ctx->r5, 0XA80);
    after_0:
    // 0x80160AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80160AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80160AE8: jr          $ra
    // 0x80160AEC: nop

    return;
    // 0x80160AEC: nop

;}
RECOMP_FUNC void ftNessSpecialLwProcAbsorb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015521C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155224: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155228: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015522C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80155230: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x80155234: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x80155238: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8015523C: sra         $t8, $t7, 30
    ctx->r24 = S32(SIGNED(ctx->r15) >> 30);
    // 0x80155240: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x80155244: lwc1        $f6, -0x39F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X39F0);
    // 0x80155248: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8015524C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80155250: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
    // 0x80155254: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x80155258: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8015525C: jal         0x800EB528
    // 0x80155260: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x80155260: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80155264: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80155268: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8015526C: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x80155270: bne         $t9, $zero, L_80155288
    if (ctx->r25 != 0) {
        // 0x80155274: nop
    
            goto L_80155288;
    }
    // 0x80155274: nop

    // 0x80155278: jal         0x80155948
    // 0x8015527C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftNessSpecialLwHitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015527C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80155280: b           L_80155294
    // 0x80155284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80155294;
    // 0x80155284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155288:
    // 0x80155288: jal         0x8015598C
    // 0x8015528C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftNessSpecialAirLwHitSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015528C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80155290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155294:
    // 0x80155294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155298: jr          $ra
    // 0x8015529C: nop

    return;
    // 0x8015529C: nop

;}
RECOMP_FUNC void ftMarioSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015635C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156360: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80156364: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80156368: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8015636C: bne         $t6, $at, L_80156400
    if (ctx->r14 != ctx->r1) {
        // 0x80156370: nop
    
            goto L_80156400;
    }
    // 0x80156370: nop

    // 0x80156374: lw          $t7, 0x180($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X180);
    // 0x80156378: beq         $t7, $zero, L_801563A0
    if (ctx->r15 == 0) {
        // 0x8015637C: nop
    
            goto L_801563A0;
    }
    // 0x8015637C: nop

    // 0x80156380: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80156384: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80156388: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015638C: addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // 0x80156390: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80156394: nop

    // 0x80156398: bc1fl       L_801563B4
    if (!c1cs) {
        // 0x8015639C: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_801563B4;
    }
    goto skip_0;
    // 0x8015639C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
L_801563A0:
    // 0x801563A0: jal         0x800DE724
    // 0x801563A4: nop

    mpCommonCheckFighterProject(rdram, ctx);
        goto after_0;
    // 0x801563A4: nop

    after_0:
    // 0x801563A8: b           L_8015640C
    // 0x801563AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015640C;
    // 0x801563AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801563B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_801563B4:
    // 0x801563B4: jal         0x800DE798
    // 0x801563B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mpCommonCheckFighterPassCliff(rdram, ctx);
        goto after_1;
    // 0x801563B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x801563BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801563C0: beq         $v0, $zero, L_80156408
    if (ctx->r2 == 0) {
        // 0x801563C4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80156408;
    }
    // 0x801563C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801563C8: lhu         $t8, 0xD2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XD2);
    // 0x801563CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801563D0: lui         $a2, 0x3E8F
    ctx->r6 = S32(0X3E8F << 16);
    // 0x801563D4: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x801563D8: beq         $t9, $zero, L_801563F0
    if (ctx->r25 == 0) {
        // 0x801563DC: nop
    
            goto L_801563F0;
    }
    // 0x801563DC: nop

    // 0x801563E0: jal         0x80144C24
    // 0x801563E4: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x801563E4: nop

    after_2:
    // 0x801563E8: b           L_8015640C
    // 0x801563EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015640C;
    // 0x801563EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801563F0:
    // 0x801563F0: jal         0x80142E3C
    // 0x801563F4: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    ftCommonLandingFallSpecialSetStatus(rdram, ctx);
        goto after_3;
    // 0x801563F4: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    after_3:
    // 0x801563F8: b           L_8015640C
    // 0x801563FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015640C;
    // 0x801563FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156400:
    // 0x80156400: jal         0x800DDF44
    // 0x80156404: nop

    mpCommonSetFighterFallOnEdgeBreak(rdram, ctx);
        goto after_4;
    // 0x80156404: nop

    after_4:
L_80156408:
    // 0x80156408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015640C:
    // 0x8015640C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156410: jr          $ra
    // 0x80156414: nop

    return;
    // 0x80156414: nop

;}
RECOMP_FUNC void lbCommonPlayTranslateScaledDObjAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9488: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C948C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C9490: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800C9494: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800C9498: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800C949C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800C94A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800C94A4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800C94A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C94AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C94B0: lwc1        $f4, 0x5E88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E88);
    // 0x800C94B4: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800C94B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C94BC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C94C0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800C94C4: nop

    // 0x800C94C8: bc1tl       L_800C96B8
    if (c1cs) {
        // 0x800C94CC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800C96B8;
    }
    goto skip_0;
    // 0x800C94CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800C94D0: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x800C94D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C94D8: beq         $s0, $zero, L_800C9690
    if (ctx->r16 == 0) {
        // 0x800C94DC: nop
    
            goto L_800C9690;
    }
    // 0x800C94DC: nop

    // 0x800C94E0: lwc1        $f24, 0x5E8C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5E8C);
    // 0x800C94E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C94E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800C94EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C94F0: nop

    // 0x800C94F4: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_800C94F8:
    // 0x800C94F8: beql        $t6, $zero, L_800C9684
    if (ctx->r14 == 0) {
        // 0x800C94FC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C9684;
    }
    goto skip_1;
    // 0x800C94FC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800C9500: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800C9504: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x800C9508: nop

    // 0x800C950C: bc1tl       L_800C9528
    if (c1cs) {
        // 0x800C9510: lw          $t7, 0x4($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X4);
            goto L_800C9528;
    }
    goto skip_2;
    // 0x800C9510: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x800C9514: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C9518: lwc1        $f10, 0x78($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800C951C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C9520: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800C9524: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
L_800C9528:
    // 0x800C9528: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800C952C: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800C9530: bnel        $t9, $zero, L_800C9684
    if (ctx->r25 != 0) {
        // 0x800C9534: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C9684;
    }
    goto skip_3;
    // 0x800C9534: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800C9538: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
    // 0x800C953C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800C9540: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x800C9544: beq         $at, $zero, L_800C9680
    if (ctx->r1 == 0) {
        // 0x800C9548: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_800C9680;
    }
    // 0x800C9548: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C954C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C9550: addu        $at, $at, $t1
    gpr jr_addend_800C9558 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800C9554: lw          $t1, 0x5E90($at)
    ctx->r9 = ADD32(ctx->r1, 0X5E90);
    // 0x800C9558: jr          $t1
    // 0x800C955C: nop

    switch (jr_addend_800C9558 >> 2) {
        case 0: goto L_800C9560; break;
        case 1: goto L_800C9570; break;
        case 2: goto L_800C9580; break;
        case 3: goto L_800C9590; break;
        case 4: goto L_800C960C; break;
        case 5: goto L_800C9624; break;
        case 6: goto L_800C963C; break;
        case 7: goto L_800C9654; break;
        case 8: goto L_800C9664; break;
        case 9: goto L_800C9674; break;
        default: switch_error(__func__, 0x800C9558, 0x800D5E90);
    }
    // 0x800C955C: nop

L_800C9560:
    // 0x800C9560: jal         0x8000CB94
    // 0x800C9564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_0;
    // 0x800C9564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C9568: b           L_800C9680
    // 0x800C956C: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
        goto L_800C9680;
    // 0x800C956C: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
L_800C9570:
    // 0x800C9570: jal         0x8000CB94
    // 0x800C9574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_1;
    // 0x800C9574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9578: b           L_800C9680
    // 0x800C957C: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
        goto L_800C9680;
    // 0x800C957C: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
L_800C9580:
    // 0x800C9580: jal         0x8000CB94
    // 0x800C9584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_2;
    // 0x800C9584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800C9588: b           L_800C9680
    // 0x800C958C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
        goto L_800C9680;
    // 0x800C958C: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_800C9590:
    // 0x800C9590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9594: jal         0x8000CB94
    // 0x800C9598: addiu       $s2, $s1, 0x1C
    ctx->r18 = ADD32(ctx->r17, 0X1C);
    gcGetAObjValue(rdram, ctx);
        goto after_3;
    // 0x800C9598: addiu       $s2, $s1, 0x1C
    ctx->r18 = ADD32(ctx->r17, 0X1C);
    after_3:
    // 0x800C959C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C95A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800C95A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C95A8: bc1fl       L_800C95BC
    if (!c1cs) {
        // 0x800C95AC: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_800C95BC;
    }
    goto skip_4;
    // 0x800C95AC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_4:
    // 0x800C95B0: b           L_800C95CC
    // 0x800C95B4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_800C95CC;
    // 0x800C95B4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800C95B8: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_800C95BC:
    // 0x800C95BC: nop

    // 0x800C95C0: bc1fl       L_800C95D0
    if (!c1cs) {
        // 0x800C95C4: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_800C95D0;
    }
    goto skip_5;
    // 0x800C95C4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_5:
    // 0x800C95C8: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_800C95CC:
    // 0x800C95CC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_800C95D0:
    // 0x800C95D0: jal         0x8001E530
    // 0x800C95D4: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    syInterpCubic(rdram, ctx);
        goto after_4;
    // 0x800C95D4: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x800C95D8: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800C95DC: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C95E0: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800C95E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C95E8: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800C95EC: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x800C95F0: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800C95F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C95F8: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x800C95FC: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800C9600: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C9604: b           L_800C9680
    // 0x800C9608: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
        goto L_800C9680;
    // 0x800C9608: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_800C960C:
    // 0x800C960C: jal         0x8000CB94
    // 0x800C9610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_5;
    // 0x800C9610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C9614: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C9618: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C961C: b           L_800C9680
    // 0x800C9620: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
        goto L_800C9680;
    // 0x800C9620: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
L_800C9624:
    // 0x800C9624: jal         0x8000CB94
    // 0x800C9628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_6;
    // 0x800C9628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800C962C: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800C9630: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C9634: b           L_800C9680
    // 0x800C9638: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
        goto L_800C9680;
    // 0x800C9638: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_800C963C:
    // 0x800C963C: jal         0x8000CB94
    // 0x800C9640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_7;
    // 0x800C9640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800C9644: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800C9648: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C964C: b           L_800C9680
    // 0x800C9650: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
        goto L_800C9680;
    // 0x800C9650: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_800C9654:
    // 0x800C9654: jal         0x8000CB94
    // 0x800C9658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_8;
    // 0x800C9658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800C965C: b           L_800C9680
    // 0x800C9660: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
        goto L_800C9680;
    // 0x800C9660: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
L_800C9664:
    // 0x800C9664: jal         0x8000CB94
    // 0x800C9668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_9;
    // 0x800C9668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800C966C: b           L_800C9680
    // 0x800C9670: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
        goto L_800C9680;
    // 0x800C9670: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_800C9674:
    // 0x800C9674: jal         0x8000CB94
    // 0x800C9678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetAObjValue(rdram, ctx);
        goto after_10;
    // 0x800C9678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800C967C: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
L_800C9680:
    // 0x800C9680: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C9684:
    // 0x800C9684: bnel        $s0, $zero, L_800C94F8
    if (ctx->r16 != 0) {
        // 0x800C9688: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_800C94F8;
    }
    goto skip_6;
    // 0x800C9688: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_6:
    // 0x800C968C: lwc1        $f0, 0x74($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X74);
L_800C9690:
    // 0x800C9690: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C9694: lwc1        $f24, 0x5EB8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5EB8);
    // 0x800C9698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C969C: c.eq.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl == ctx->f0.fl;
    // 0x800C96A0: nop

    // 0x800C96A4: bc1fl       L_800C96B8
    if (!c1cs) {
        // 0x800C96A8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800C96B8;
    }
    goto skip_7;
    // 0x800C96A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x800C96AC: lwc1        $f8, 0x5EBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5EBC);
    // 0x800C96B0: swc1        $f8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f8.u32l;
    // 0x800C96B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800C96B8:
    // 0x800C96B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C96BC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800C96C0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800C96C4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800C96C8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800C96CC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800C96D0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800C96D4: jr          $ra
    // 0x800C96D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C96D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnVSResultsMakeTint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134DA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134DA8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134DAC: sw          $zero, -0x6440($at)
    MEM_W(-0X6440, ctx->r1) = 0;
    // 0x80134DB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134DB8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80134DBC: jal         0x80009968
    // 0x80134DC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134DC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134DC4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134DC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134DCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134DD0: addiu       $a1, $a1, 0x4C5C
    ctx->r5 = ADD32(ctx->r5, 0X4C5C);
    // 0x80134DD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134DD8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80134DDC: jal         0x80009DF4
    // 0x80134DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134DE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134DEC: jr          $ra
    // 0x80134DF0: nop

    return;
    // 0x80134DF0: nop

;}
RECOMP_FUNC void mnVSModeMakeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CA0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80131CA4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80131CA8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CAC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80131CB0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80131CB4: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80131CB8: addiu       $t6, $t6, 0x47F8
    ctx->r14 = ADD32(ctx->r14, 0X47F8);
    // 0x80131CBC: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80131CC0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131CC4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80131CC8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80131CCC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80131CD0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80131CD4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80131CD8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80131CDC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80131CE0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80131CE4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131CE8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131CEC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131CF0: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x80131CF4: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131CF8: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80131CFC:
    // 0x80131CFC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D00: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131D04: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131D08: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131D0C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131D10: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131D14: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131D18: bne         $t6, $t0, L_80131CFC
    if (ctx->r14 != ctx->r8) {
        // 0x80131D1C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131CFC;
    }
    // 0x80131D1C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131D20: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D24: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131D28: addiu       $t2, $t2, 0x4820
    ctx->r10 = ADD32(ctx->r10, 0X4820);
    // 0x80131D2C: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x80131D30: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x80131D34: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80131D38:
    // 0x80131D38: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131D3C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80131D40: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131D44: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80131D48: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80131D4C: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80131D50: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80131D54: bne         $t2, $t5, L_80131D38
    if (ctx->r10 != ctx->r13) {
        // 0x80131D58: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80131D38;
    }
    // 0x80131D58: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80131D5C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131D60: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80131D64: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80131D68: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80131D6C: bgez        $s3, L_80131D78
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80131D70: lwc1        $f20, 0xC8($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XC8);
            goto L_80131D78;
    }
    // 0x80131D70: lwc1        $f20, 0xC8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80131D74: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131D78:
    // 0x80131D78: div         $zero, $s3, $s6
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r22)));
    // 0x80131D7C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80131D80: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80131D84: addiu       $s7, $s7, 0x4A48
    ctx->r23 = ADD32(ctx->r23, 0X4A48);
    // 0x80131D88: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x80131D8C: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80131D90: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80131D94: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131D98: bne         $s6, $zero, L_80131DA4
    if (ctx->r22 != 0) {
        // 0x80131D9C: nop
    
            goto L_80131DA4;
    }
    // 0x80131D9C: nop

    // 0x80131DA0: break       7
    do_break(2148736416);
L_80131DA4:
    // 0x80131DA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131DA8: bne         $s6, $at, L_80131DBC
    if (ctx->r22 != ctx->r1) {
        // 0x80131DAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131DBC;
    }
    // 0x80131DAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131DB0: bne         $s3, $at, L_80131DBC
    if (ctx->r19 != ctx->r1) {
        // 0x80131DB4: nop
    
            goto L_80131DBC;
    }
    // 0x80131DB4: nop

    // 0x80131DB8: break       6
    do_break(2148736440);
L_80131DBC:
    // 0x80131DBC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80131DC0: jal         0x800CCFDC
    // 0x80131DC4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131DC4: nop

    after_0:
    // 0x80131DC8: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x80131DCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DD4: jal         0x80131BC4
    // 0x80131DD8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnVSModeSetTextureColors(rdram, ctx);
        goto after_1;
    // 0x80131DD8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80131DDC: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80131DE0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80131DE4: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80131DE8: lw          $s5, 0xD8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD8);
    // 0x80131DEC: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131DF0: sub.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80131DF4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80131DF8: beq         $s5, $zero, L_80131E0C
    if (ctx->r21 == 0) {
        // 0x80131DFC: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131E0C;
    }
    // 0x80131DFC: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131E00: lw          $s2, 0xD4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD4);
    // 0x80131E04: b           L_80131E20
    // 0x80131E08: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131E20;
    // 0x80131E08: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131E0C:
    // 0x80131E0C: lw          $s2, 0xD4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD4);
    // 0x80131E10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131E14: jal         0x80131BF4
    // 0x80131E18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSModeGetNumberOfDigits(rdram, ctx);
        goto after_2;
    // 0x80131E18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80131E1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131E20:
    // 0x80131E20: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131E24: bne         $at, $zero, L_80131F10
    if (ctx->r1 != 0) {
        // 0x80131E28: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131F10;
    }
    // 0x80131E28: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80131E2C:
    // 0x80131E2C: jal         0x80131B24
    // 0x80131E30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnVSModePow(rdram, ctx);
        goto after_3;
    // 0x80131E30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80131E34: beq         $v0, $zero, L_80131E7C
    if (ctx->r2 == 0) {
        // 0x80131E38: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131E7C;
    }
    // 0x80131E38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131E3C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80131E40: jal         0x80131B24
    // 0x80131E44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnVSModePow(rdram, ctx);
        goto after_4;
    // 0x80131E44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80131E48: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80131E4C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E50: bne         $v0, $zero, L_80131E5C
    if (ctx->r2 != 0) {
        // 0x80131E54: nop
    
            goto L_80131E5C;
    }
    // 0x80131E54: nop

    // 0x80131E58: break       7
    do_break(2148736600);
L_80131E5C:
    // 0x80131E5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131E60: bne         $v0, $at, L_80131E74
    if (ctx->r2 != ctx->r1) {
        // 0x80131E64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131E74;
    }
    // 0x80131E64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131E68: bne         $s3, $at, L_80131E74
    if (ctx->r19 != ctx->r1) {
        // 0x80131E6C: nop
    
            goto L_80131E74;
    }
    // 0x80131E6C: nop

    // 0x80131E70: break       6
    do_break(2148736624);
L_80131E74:
    // 0x80131E74: b           L_80131E7C
    // 0x80131E78: nop

        goto L_80131E7C;
    // 0x80131E78: nop

L_80131E7C:
    // 0x80131E7C: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80131E80: mfhi        $t5
    ctx->r13 = hi;
    // 0x80131E84: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80131E88: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x80131E8C: lw          $t1, 0x98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X98);
    // 0x80131E90: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80131E94: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80131E98: bne         $s6, $zero, L_80131EA4
    if (ctx->r22 != 0) {
        // 0x80131E9C: nop
    
            goto L_80131EA4;
    }
    // 0x80131E9C: nop

    // 0x80131EA0: break       7
    do_break(2148736672);
L_80131EA4:
    // 0x80131EA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131EA8: bne         $s6, $at, L_80131EBC
    if (ctx->r22 != ctx->r1) {
        // 0x80131EAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131EBC;
    }
    // 0x80131EAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131EB0: bne         $v1, $at, L_80131EBC
    if (ctx->r3 != ctx->r1) {
        // 0x80131EB4: nop
    
            goto L_80131EBC;
    }
    // 0x80131EB4: nop

    // 0x80131EB8: break       6
    do_break(2148736696);
L_80131EBC:
    // 0x80131EBC: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x80131EC0: jal         0x800CCFDC
    // 0x80131EC4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80131EC4: nop

    after_5:
    // 0x80131EC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131ECC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131ED0: jal         0x80131BC4
    // 0x80131ED4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnVSModeSetTextureColors(rdram, ctx);
        goto after_6;
    // 0x80131ED4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80131ED8: sub.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80131EDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131EE0: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131EE4: beq         $s5, $zero, L_80131EF4
    if (ctx->r21 == 0) {
        // 0x80131EE8: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80131EF4;
    }
    // 0x80131EE8: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131EEC: b           L_80131F04
    // 0x80131EF0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F04;
    // 0x80131EF0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131EF4:
    // 0x80131EF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131EF8: jal         0x80131BF4
    // 0x80131EFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSModeGetNumberOfDigits(rdram, ctx);
        goto after_7;
    // 0x80131EFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80131F00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F04:
    // 0x80131F04: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131F08: bnel        $at, $zero, L_80131E2C
    if (ctx->r1 != 0) {
        // 0x80131F0C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131E2C;
    }
    goto skip_0;
    // 0x80131F0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80131F10:
    // 0x80131F10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80131F14: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131F18: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80131F1C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80131F20: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131F24: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80131F28: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80131F2C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F30: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80131F34: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80131F38: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80131F3C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F40: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80131F44: jr          $ra
    // 0x80131F48: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80131F48: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void ftParamGetStale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA470: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800EA474: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800EA478: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800EA47C: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x800EA480: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800EA484: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800EA488: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800EA48C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800EA490: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800EA494: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800EA498: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800EA49C: andi        $s0, $a2, 0xFFFF
    ctx->r16 = ctx->r6 & 0XFFFF;
    // 0x800EA4A0: beq         $a1, $zero, L_800EA534
    if (ctx->r5 == 0) {
        // 0x800EA4A4: lw          $v0, 0x7C($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X7C);
            goto L_800EA534;
    }
    // 0x800EA4A4: lw          $v0, 0x7C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X7C);
    // 0x800EA4A8: beq         $v0, $zero, L_800EA4B8
    if (ctx->r2 == 0) {
        // 0x800EA4AC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800EA4B8;
    }
    // 0x800EA4AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800EA4B0: b           L_800EA4BC
    // 0x800EA4B4: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
        goto L_800EA4BC;
    // 0x800EA4B4: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_800EA4B8:
    // 0x800EA4B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_800EA4BC:
    // 0x800EA4BC: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800EA4C0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800EA4C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800EA4C8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800EA4CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800EA4D0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800EA4D4: addu        $t0, $v1, $t8
    ctx->r8 = ADD32(ctx->r3, ctx->r24);
    // 0x800EA4D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
L_800EA4DC:
    // 0x800EA4DC: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x800EA4E0: lhu         $t1, 0x80($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X80);
    // 0x800EA4E4: bne         $a1, $t1, L_800EA514
    if (ctx->r5 != ctx->r9) {
        // 0x800EA4E8: nop
    
            goto L_800EA514;
    }
    // 0x800EA4E8: nop

    // 0x800EA4EC: lhu         $t2, 0x82($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X82);
    // 0x800EA4F0: beq         $s0, $t2, L_800EA508
    if (ctx->r16 == ctx->r10) {
        // 0x800EA4F4: sll         $t3, $a3, 2
        ctx->r11 = S32(ctx->r7 << 2);
            goto L_800EA508;
    }
    // 0x800EA4F4: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x800EA4F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA4FC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800EA500: b           L_800EA540
    // 0x800EA504: lwc1        $f0, -0x47E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X47E0);
        goto L_800EA540;
    // 0x800EA504: lwc1        $f0, -0x47E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X47E0);
L_800EA508:
    // 0x800EA508: bne         $v0, $a2, L_800EA514
    if (ctx->r2 != ctx->r6) {
        // 0x800EA50C: nop
    
            goto L_800EA514;
    }
    // 0x800EA50C: nop

    // 0x800EA510: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_800EA514:
    // 0x800EA514: beq         $v0, $zero, L_800EA524
    if (ctx->r2 == 0) {
        // 0x800EA518: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800EA524;
    }
    // 0x800EA518: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800EA51C: b           L_800EA528
    // 0x800EA520: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800EA528;
    // 0x800EA520: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800EA524:
    // 0x800EA524: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800EA528:
    // 0x800EA528: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800EA52C: bnel        $at, $zero, L_800EA4DC
    if (ctx->r1 != 0) {
        // 0x800EA530: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_800EA4DC;
    }
    goto skip_0;
    // 0x800EA530: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    skip_0:
L_800EA534:
    // 0x800EA534: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EA538: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800EA53C: nop

L_800EA540:
    // 0x800EA540: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800EA544: jr          $ra
    // 0x800EA548: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800EA548: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_ovl3_80149B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149B48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149B50: jal         0x800DDDA8
    // 0x80149B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80149B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80149B58: bnel        $v0, $zero, L_80149B6C
    if (ctx->r2 != 0) {
        // 0x80149B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149B6C;
    }
    goto skip_0;
    // 0x80149B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80149B60: jal         0x80149AC8
    // 0x80149B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonCatchCaptureSetStatusRelease(rdram, ctx);
        goto after_1;
    // 0x80149B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80149B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80149B6C:
    // 0x80149B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149B70: jr          $ra
    // 0x80149B74: nop

    return;
    // 0x80149B74: nop

;}
RECOMP_FUNC void scAutoDemoGetShuffledFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D874: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D878: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8018D87C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D880: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8018D884: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8018D888: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018D88C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D890:
    // 0x8018D890: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D894: sllv        $a0, $t6, $v1
    ctx->r4 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8018D898: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x8018D89C: beq         $t7, $zero, L_8018D8B0
    if (ctx->r15 == 0) {
        // 0x8018D8A0: and         $t8, $a1, $a0
        ctx->r24 = ctx->r5 & ctx->r4;
            goto L_8018D8B0;
    }
    // 0x8018D8A0: and         $t8, $a1, $a0
    ctx->r24 = ctx->r5 & ctx->r4;
    // 0x8018D8A4: bne         $t8, $zero, L_8018D8B0
    if (ctx->r24 != 0) {
        // 0x8018D8A8: nop
    
            goto L_8018D8B0;
    }
    // 0x8018D8A8: nop

    // 0x8018D8AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8018D8B0:
    // 0x8018D8B0: bnel        $a2, $zero, L_8018D890
    if (ctx->r6 != 0) {
        // 0x8018D8B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8018D890;
    }
    goto skip_0;
    // 0x8018D8B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8018D8B8: jr          $ra
    // 0x8018D8BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D8BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mvOpeningJungleMakeGroundViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D16C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D174: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D178: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018D17C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018D180: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8018D184: addiu       $t7, $t7, -0x2790
    ctx->r15 = ADD32(ctx->r15, -0X2790);
    // 0x8018D188: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D18C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D190: addiu       $t6, $t6, -0x2598
    ctx->r14 = ADD32(ctx->r14, -0X2598);
    // 0x8018D194: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D198: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D19C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1A0: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1A4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1A8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1AC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1B0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1B4: addiu       $t1, $t1, -0x2774
    ctx->r9 = ADD32(ctx->r9, -0X2774);
    // 0x8018D1B8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1BC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D1C0: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8018D1C4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018D1C8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D1CC: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D1D8: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8018D1DC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D1E0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D1E4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D1E8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D1EC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D1F0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D1F4: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D1F8: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8018D1FC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8018D200: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x8018D204: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8018D208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D20C: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8018D210: jal         0x8010DB2C
    // 0x8018D214: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D214: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D218: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D21C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D220: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D224: addiu       $v1, $v1, -0x25A8
    ctx->r3 = ADD32(ctx->r3, -0X25A8);
    // 0x8018D228: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D22C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D230: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x8018D234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D238: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D23C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D240: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D244: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8018D248: jal         0x80007080
    // 0x8018D24C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D24C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D250: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D254: lwc1        $f6, -0x25D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x8018D258: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D25C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8018D260: jal         0x8000B39C
    // 0x8018D264: lw          $a0, -0x25A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25A8);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D264: lw          $a0, -0x25A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25A8);
    after_2:
    // 0x8018D268: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018D26C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D270: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D274: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018D278: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x8018D27C: lwc1        $f10, -0x25D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25D4);
    // 0x8018D280: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8018D284: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8018D288: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8018D28C: lw          $t5, -0x239C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X239C);
    // 0x8018D290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018D298: jal         0x8000FA3C
    // 0x8018D29C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_3;
    // 0x8018D29C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x8018D2A0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D2A4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018D2A8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018D2AC: lw          $a0, -0x25A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25A8);
    // 0x8018D2B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D2B4: jal         0x80008188
    // 0x8018D2B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018D2B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018D2BC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D2C0: jal         0x80010580
    // 0x8018D2C4: lw          $a0, -0x25A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25A8);
    gcPlayCamAnim(rdram, ctx);
        goto after_5;
    // 0x8018D2C4: lw          $a0, -0x25A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X25A8);
    after_5:
    // 0x8018D2C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D2CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D2D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D2D4: jr          $ra
    // 0x8018D2D8: nop

    return;
    // 0x8018D2D8: nop

;}
RECOMP_FUNC void wpSamusBombExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168F2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168F30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80168F34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80168F38: lbu         $t8, 0x148($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X148);
    // 0x80168F3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80168F40: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80168F44: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x80168F48: andi        $t1, $t0, 0xF7
    ctx->r9 = ctx->r8 & 0XF7;
    // 0x80168F4C: sb          $t0, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r8;
    // 0x80168F50: sw          $t6, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r14;
    // 0x80168F54: sb          $t1, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r9;
    // 0x80168F58: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80168F5C: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80168F60: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80168F64: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x80168F68: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80168F6C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80168F70: addiu       $t3, $t3, -0x7100
    ctx->r11 = ADD32(ctx->r11, -0X7100);
    // 0x80168F74: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x80168F78: sw          $t3, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->r11;
    // 0x80168F7C: sw          $zero, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = 0;
    // 0x80168F80: sw          $zero, 0x280($v0)
    MEM_W(0X280, ctx->r2) = 0;
    // 0x80168F84: sw          $zero, 0x284($v0)
    MEM_W(0X284, ctx->r2) = 0;
    // 0x80168F88: sw          $zero, 0x288($v0)
    MEM_W(0X288, ctx->r2) = 0;
    // 0x80168F8C: sw          $zero, 0x28C($v0)
    MEM_W(0X28C, ctx->r2) = 0;
    // 0x80168F90: jr          $ra
    // 0x80168F94: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
    return;
    // 0x80168F94: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
;}
RECOMP_FUNC void sc1PTrainingModeUpdateMenuInputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2F0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018D2F4: lbu         $v1, 0x4AE3($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4AE3);
    // 0x8018D2F8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8018D2FC: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x8018D300: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8018D304: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8018D308: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8018D30C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D310: lb          $a1, 0x8($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X8);
    // 0x8018D314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D318: slti        $at, $a1, 0x29
    ctx->r1 = SIGNED(ctx->r5) < 0X29 ? 1 : 0;
    // 0x8018D31C: bnel        $at, $zero, L_8018D32C
    if (ctx->r1 != 0) {
        // 0x8018D320: slti        $at, $a1, -0x28
        ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
            goto L_8018D32C;
    }
    goto skip_0;
    // 0x8018D320: slti        $at, $a1, -0x28
    ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
    skip_0:
    // 0x8018D324: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8018D328: slti        $at, $a1, -0x28
    ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
L_8018D32C:
    // 0x8018D32C: beq         $at, $zero, L_8018D33C
    if (ctx->r1 == 0) {
        // 0x8018D330: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D33C;
    }
    // 0x8018D330: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D334: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x8018D338: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8018D33C:
    // 0x8018D33C: lb          $v1, 0x9($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X9);
    // 0x8018D340: addiu       $a1, $a1, 0xB58
    ctx->r5 = ADD32(ctx->r5, 0XB58);
    // 0x8018D344: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x8018D348: bnel        $at, $zero, L_8018D35C
    if (ctx->r1 != 0) {
        // 0x8018D34C: slti        $at, $v1, -0x28
        ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
            goto L_8018D35C;
    }
    goto skip_1;
    // 0x8018D34C: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
    skip_1:
    // 0x8018D350: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x8018D354: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8018D358: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
L_8018D35C:
    // 0x8018D35C: beql        $at, $zero, L_8018D370
    if (ctx->r1 == 0) {
        // 0x8018D360: lbu         $t8, 0xD8($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0XD8);
            goto L_8018D370;
    }
    goto skip_2;
    // 0x8018D360: lbu         $t8, 0xD8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XD8);
    skip_2:
    // 0x8018D364: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8018D368: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8018D36C: lbu         $t8, 0xD8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XD8);
L_8018D370:
    // 0x8018D370: bnel        $t8, $zero, L_8018D38C
    if (ctx->r24 != 0) {
        // 0x8018D374: lhu         $t0, 0xC4($a1)
        ctx->r8 = MEM_HU(ctx->r5, 0XC4);
            goto L_8018D38C;
    }
    goto skip_3;
    // 0x8018D374: lhu         $t0, 0xC4($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0XC4);
    skip_3:
    // 0x8018D378: bne         $v0, $zero, L_8018D3D4
    if (ctx->r2 != 0) {
        // 0x8018D37C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018D3D4;
    }
    // 0x8018D37C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D380: jr          $ra
    // 0x8018D384: sb          $t9, 0xD8($a1)
    MEM_B(0XD8, ctx->r5) = ctx->r25;
    return;
    // 0x8018D384: sb          $t9, 0xD8($a1)
    MEM_B(0XD8, ctx->r5) = ctx->r25;
    // 0x8018D388: lhu         $t0, 0xC4($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0XC4);
L_8018D38C:
    // 0x8018D38C: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8018D390: xor         $a0, $v0, $t0
    ctx->r4 = ctx->r2 ^ ctx->r8;
    // 0x8018D394: and         $t1, $a0, $v0
    ctx->r9 = ctx->r4 & ctx->r2;
    // 0x8018D398: beq         $a0, $zero, L_8018D3AC
    if (ctx->r4 == 0) {
        // 0x8018D39C: sh          $t1, 0xC6($a1)
        MEM_H(0XC6, ctx->r5) = ctx->r9;
            goto L_8018D3AC;
    }
    // 0x8018D39C: sh          $t1, 0xC6($a1)
    MEM_H(0XC6, ctx->r5) = ctx->r9;
    // 0x8018D3A0: sh          $t1, 0xC8($a1)
    MEM_H(0XC8, ctx->r5) = ctx->r9;
    // 0x8018D3A4: b           L_8018D3D0
    // 0x8018D3A8: sw          $t3, 0xCC($a1)
    MEM_W(0XCC, ctx->r5) = ctx->r11;
        goto L_8018D3D0;
    // 0x8018D3A8: sw          $t3, 0xCC($a1)
    MEM_W(0XCC, ctx->r5) = ctx->r11;
L_8018D3AC:
    // 0x8018D3AC: lw          $t4, 0xCC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XCC);
    // 0x8018D3B0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8018D3B4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8018D3B8: blez        $t5, L_8018D3C8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8018D3BC: sw          $t5, 0xCC($a1)
        MEM_W(0XCC, ctx->r5) = ctx->r13;
            goto L_8018D3C8;
    }
    // 0x8018D3BC: sw          $t5, 0xCC($a1)
    MEM_W(0XCC, ctx->r5) = ctx->r13;
    // 0x8018D3C0: b           L_8018D3D0
    // 0x8018D3C4: sh          $zero, 0xC8($a1)
    MEM_H(0XC8, ctx->r5) = 0;
        goto L_8018D3D0;
    // 0x8018D3C4: sh          $zero, 0xC8($a1)
    MEM_H(0XC8, ctx->r5) = 0;
L_8018D3C8:
    // 0x8018D3C8: sh          $v0, 0xC8($a1)
    MEM_H(0XC8, ctx->r5) = ctx->r2;
    // 0x8018D3CC: sw          $t7, 0xCC($a1)
    MEM_W(0XCC, ctx->r5) = ctx->r15;
L_8018D3D0:
    // 0x8018D3D0: sh          $v0, 0xC4($a1)
    MEM_H(0XC4, ctx->r5) = ctx->r2;
L_8018D3D4:
    // 0x8018D3D4: jr          $ra
    // 0x8018D3D8: nop

    return;
    // 0x8018D3D8: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper3ProcDisplay0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801916A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801916AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801916B0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801916B4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801916B8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801916BC: beq         $v0, $zero, L_801916E0
    if (ctx->r2 == 0) {
        // 0x801916C0: lui         $t9, 0xE200
        ctx->r25 = S32(0XE200 << 16);
            goto L_801916E0;
    }
    // 0x801916C0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801916C4: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
L_801916C8:
    // 0x801916C8: beql        $v1, $zero, L_801916D8
    if (ctx->r3 == 0) {
        // 0x801916CC: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_801916D8;
    }
    goto skip_0;
    // 0x801916CC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x801916D0: sb          $a1, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r5;
    // 0x801916D4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_801916D8:
    // 0x801916D8: bnel        $v0, $zero, L_801916C8
    if (ctx->r2 != 0) {
        // 0x801916DC: lw          $v1, 0x80($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X80);
            goto L_801916C8;
    }
    goto skip_1;
    // 0x801916DC: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    skip_1:
L_801916E0:
    // 0x801916E0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801916E4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801916E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801916EC: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x801916F0: ori         $t1, $t1, 0x41C8
    ctx->r9 = ctx->r9 | 0X41C8;
    // 0x801916F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801916F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801916FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191700: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191704: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191708: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8019170C: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x80191710: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191714: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80191718: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019171C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191720: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191724: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80191728: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8019172C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80191730: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80191734: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80191738: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019173C: jal         0x80014038
    // 0x80191740: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80191740: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    after_0:
    // 0x80191744: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80191748: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8019174C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191750: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80191754: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80191758: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019175C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80191760: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80191764: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80191768: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019176C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191770: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80191774: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80191778: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019177C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80191780: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191784: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80191788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019178C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191790: jr          $ra
    // 0x80191794: nop

    return;
    // 0x80191794: nop

;}
RECOMP_FUNC void ftCommonThrownCommonStarUpdatePhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BF04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014BF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014BF0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014BF10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014BF14: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014BF18: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8014BF1C: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x8014BF20: beql        $t7, $zero, L_8014BFFC
    if (ctx->r15 == 0) {
        // 0x8014BF24: lw          $v0, 0x184($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X184);
            goto L_8014BFFC;
    }
    goto skip_0;
    // 0x8014BF24: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x8014BF28: lw          $t8, 0x184($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X184);
    // 0x8014BF2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014BF30: beql        $t8, $at, L_8014BFFC
    if (ctx->r24 == ctx->r1) {
        // 0x8014BF34: lw          $v0, 0x184($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X184);
            goto L_8014BFFC;
    }
    goto skip_1;
    // 0x8014BF34: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    skip_1:
    // 0x8014BF38: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8014BF3C: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8014BF40: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8014BF44: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8014BF48: nop

    // 0x8014BF4C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8014BF50: jal         0x80033510
    // 0x8014BF54: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8014BF54: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8014BF58: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8014BF5C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8014BF60: nop

    // 0x8014BF64: bc1fl       L_8014BFC4
    if (!c1cs) {
        // 0x8014BF68: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_8014BFC4;
    }
    goto skip_2;
    // 0x8014BF68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_2:
    // 0x8014BF6C: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8014BF70: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8014BF74: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8014BF78: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014BF7C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8014BF80: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8014BF84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014BF88: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8014BF8C: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8014BF90: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8014BF94: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8014BF98: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8014BF9C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8014BFA0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8014BFA4: nop

    // 0x8014BFA8: bc1f        L_8014BFB8
    if (!c1cs) {
        // 0x8014BFAC: nop
    
            goto L_8014BFB8;
    }
    // 0x8014BFAC: nop

    // 0x8014BFB0: b           L_8014BFD0
    // 0x8014BFB4: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
        goto L_8014BFD0;
    // 0x8014BFB4: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
L_8014BFB8:
    // 0x8014BFB8: b           L_8014BFD0
    // 0x8014BFBC: sw          $t0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r8;
        goto L_8014BFD0;
    // 0x8014BFBC: sw          $t0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r8;
    // 0x8014BFC0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_8014BFC4:
    // 0x8014BFC4: nop

    // 0x8014BFC8: swc1        $f12, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f12.u32l;
    // 0x8014BFCC: swc1        $f12, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f12.u32l;
L_8014BFD0:
    // 0x8014BFD0: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x8014BFD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BFD8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8014BFDC: jal         0x8014E400
    // 0x8014BFE0: sw          $t2, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r10;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_1;
    // 0x8014BFE0: sw          $t2, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r10;
    after_1:
    // 0x8014BFE4: lw          $t3, 0x26C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X26C);
    // 0x8014BFE8: bgtzl       $t3, L_8014C250
    if (SIGNED(ctx->r11) > 0) {
        // 0x8014BFEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014C250;
    }
    goto skip_3;
    // 0x8014BFEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8014BFF0: b           L_8014C24C
    // 0x8014BFF4: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
        goto L_8014C24C;
    // 0x8014BFF4: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8014BFF8: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
L_8014BFFC:
    // 0x8014BFFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014C000: bnel        $v0, $at, L_8014C0D0
    if (ctx->r2 != ctx->r1) {
        // 0x8014C004: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014C0D0;
    }
    goto skip_4;
    // 0x8014C004: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_4:
    // 0x8014C008: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014C00C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8014C010: beq         $v0, $at, L_8014C020
    if (ctx->r2 == ctx->r1) {
        // 0x8014C014: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8014C020;
    }
    // 0x8014C014: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8014C018: bnel        $v0, $at, L_8014C058
    if (ctx->r2 != ctx->r1) {
        // 0x8014C01C: lbu         $t6, 0x18D($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X18D);
            goto L_8014C058;
    }
    goto skip_5;
    // 0x8014C01C: lbu         $t6, 0x18D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18D);
    skip_5:
L_8014C020:
    // 0x8014C020: lh          $t4, 0xB1C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB1C);
    // 0x8014C024: beql        $t4, $zero, L_8014C058
    if (ctx->r12 == 0) {
        // 0x8014C028: lbu         $t6, 0x18D($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X18D);
            goto L_8014C058;
    }
    goto skip_6;
    // 0x8014C028: lbu         $t6, 0x18D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18D);
    skip_6:
    // 0x8014C02C: jal         0x80161EB4
    // 0x8014C030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftKirbySpecialNInitPassiveVars(rdram, ctx);
        goto after_2;
    // 0x8014C030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8014C034: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8014C038: sw          $t5, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r13;
    // 0x8014C03C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014C040: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8014C044: jal         0x800E8EAC
    // 0x8014C048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_3;
    // 0x8014C048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8014C04C: jal         0x800E8ECC
    // 0x8014C050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamResetModelPartAll(rdram, ctx);
        goto after_4;
    // 0x8014C050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8014C054: lbu         $t6, 0x18D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18D);
L_8014C058:
    // 0x8014C058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C05C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8014C060: sb          $t7, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r15;
    // 0x8014C064: jal         0x800E8A24
    // 0x8014C068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_5;
    // 0x8014C068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8014C06C: jal         0x800E9C3C
    // 0x8014C070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamProcStopEffect(rdram, ctx);
        goto after_6;
    // 0x8014C070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8014C074: jal         0x8014BE24
    // 0x8014C078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonThrownKirbyEscape(rdram, ctx);
        goto after_7;
    // 0x8014C078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8014C07C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8014C080: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014C084: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8014C088: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8014C08C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C090: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8014C094: nop

    // 0x8014C098: bc1f        L_8014C0A8
    if (!c1cs) {
        // 0x8014C09C: nop
    
            goto L_8014C0A8;
    }
    // 0x8014C09C: nop

    // 0x8014C0A0: b           L_8014C0A8
    // 0x8014C0A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8014C0A8;
    // 0x8014C0A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8014C0A8:
    // 0x8014C0A8: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x8014C0AC: jal         0x80102070
    // 0x8014C0B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_8;
    // 0x8014C0B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_8:
    // 0x8014C0B4: beql        $v0, $zero, L_8014C250
    if (ctx->r2 == 0) {
        // 0x8014C0B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014C250;
    }
    goto skip_7;
    // 0x8014C0B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8014C0BC: lbu         $t0, 0x18F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18F);
    // 0x8014C0C0: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8014C0C4: b           L_8014C24C
    // 0x8014C0C8: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
        goto L_8014C24C;
    // 0x8014C0C8: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
    // 0x8014C0CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8014C0D0:
    // 0x8014C0D0: bne         $v0, $at, L_8014C1C0
    if (ctx->r2 != ctx->r1) {
        // 0x8014C0D4: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8014C1C0;
    }
    // 0x8014C0D4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8014C0D8: lh          $v0, 0xB1A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB1A);
    // 0x8014C0DC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8014C0E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014C0E4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8014C0E8: sw          $t2, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r10;
    // 0x8014C0EC: sw          $t3, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->r11;
    // 0x8014C0F0: beq         $v0, $zero, L_8014C114
    if (ctx->r2 == 0) {
        // 0x8014C0F4: swc1        $f4, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
            goto L_8014C114;
    }
    // 0x8014C0F4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8014C0F8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8014C0FC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8014C100: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014C104: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014C108: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8014C10C: b           L_8014C150
    // 0x8014C110: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_8014C150;
    // 0x8014C110: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_8014C114:
    // 0x8014C114: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8014C118: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014C11C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C120: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8014C124: nop

    // 0x8014C128: bc1f        L_8014C138
    if (!c1cs) {
        // 0x8014C12C: nop
    
            goto L_8014C138;
    }
    // 0x8014C12C: nop

    // 0x8014C130: b           L_8014C138
    // 0x8014C134: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8014C138;
    // 0x8014C134: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8014C138:
    // 0x8014C138: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8014C13C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8014C140: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014C144: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014C148: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8014C14C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_8014C150:
    // 0x8014C150: jal         0x800E9C3C
    // 0x8014C154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamProcStopEffect(rdram, ctx);
        goto after_9;
    // 0x8014C154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8014C158: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8014C15C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014C160: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8014C164: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8014C168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C16C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014C170: nop

    // 0x8014C174: bc1f        L_8014C184
    if (!c1cs) {
        // 0x8014C178: nop
    
            goto L_8014C184;
    }
    // 0x8014C178: nop

    // 0x8014C17C: b           L_8014C184
    // 0x8014C180: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8014C184;
    // 0x8014C180: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8014C184:
    // 0x8014C184: lw          $a0, 0x74($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X74);
    // 0x8014C188: jal         0x80102070
    // 0x8014C18C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_10;
    // 0x8014C18C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_10:
    // 0x8014C190: beql        $v0, $zero, L_8014C1A8
    if (ctx->r2 == 0) {
        // 0x8014C194: lbu         $t8, 0x18D($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X18D);
            goto L_8014C1A8;
    }
    goto skip_8;
    // 0x8014C194: lbu         $t8, 0x18D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18D);
    skip_8:
    // 0x8014C198: lbu         $t6, 0x18F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18F);
    // 0x8014C19C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8014C1A0: sb          $t7, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r15;
    // 0x8014C1A4: lbu         $t8, 0x18D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18D);
L_8014C1A8:
    // 0x8014C1A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C1AC: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x8014C1B0: sb          $t9, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r25;
    // 0x8014C1B4: jal         0x800E8A24
    // 0x8014C1B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_11;
    // 0x8014C1B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8014C1BC: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
L_8014C1C0:
    // 0x8014C1C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014C1C4: bne         $v0, $at, L_8014C24C
    if (ctx->r2 != ctx->r1) {
        // 0x8014C1C8: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_8014C24C;
    }
    // 0x8014C1C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8014C1CC: lw          $t2, 0x180($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X180);
    // 0x8014C1D0: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x8014C1D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8014C1D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8014C1DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014C1E0: lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X10);
    // 0x8014C1E4: bgez        $t2, L_8014C1FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014C1E8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8014C1FC;
    }
    // 0x8014C1E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014C1EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014C1F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014C1F4: nop

    // 0x8014C1F8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8014C1FC:
    // 0x8014C1FC: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8014C200: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8014C204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014C208: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014C20C: lwc1        $f10, -0x3DD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3DD8);
    // 0x8014C210: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8014C214: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014C218: lwc1        $f18, -0x3DD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3DD4);
    // 0x8014C21C: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8014C220: add.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8014C224: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8014C228: swc1        $f2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f2.u32l;
    // 0x8014C22C: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    // 0x8014C230: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    // 0x8014C234: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8014C238: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8014C23C: beq         $a1, $zero, L_8014C24C
    if (ctx->r5 == 0) {
        // 0x8014C240: sw          $t3, 0x180($s0)
        MEM_W(0X180, ctx->r16) = ctx->r11;
            goto L_8014C24C;
    }
    // 0x8014C240: sw          $t3, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r11;
    // 0x8014C244: jal         0x8014BE24
    // 0x8014C248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonThrownKirbyEscape(rdram, ctx);
        goto after_12;
    // 0x8014C248: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
L_8014C24C:
    // 0x8014C24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014C250:
    // 0x8014C250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014C254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014C258: jr          $ra
    // 0x8014C25C: nop

    return;
    // 0x8014C25C: nop

;}
RECOMP_FUNC void mnTitleFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801320F4: addiu       $v1, $v1, 0x4460
    ctx->r3 = ADD32(ctx->r3, 0X4460);
    // 0x801320F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132104: bne         $v0, $zero, L_80132118
    if (ctx->r2 != 0) {
        // 0x80132108: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80132118;
    }
    // 0x80132108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013210C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80132110: b           L_80132200
    // 0x80132114: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80132200;
    // 0x80132114: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80132118:
    // 0x80132118: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013211C: lw          $t7, 0x4470($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4470);
    // 0x80132120: beq         $t7, $zero, L_8013214C
    if (ctx->r15 == 0) {
        // 0x80132124: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8013214C;
    }
    // 0x80132124: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132128: addiu       $v0, $v0, 0x4474
    ctx->r2 = ADD32(ctx->r2, 0X4474);
    // 0x8013212C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80132130: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80132134: bne         $t9, $zero, L_80132200
    if (ctx->r25 != 0) {
        // 0x80132138: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_80132200;
    }
    // 0x80132138: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013213C: jal         0x80005C74
    // 0x80132140: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x80132140: nop

    after_0:
    // 0x80132144: b           L_80132204
    // 0x80132148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132204;
    // 0x80132148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013214C:
    // 0x8013214C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132150: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80132154: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132158: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8013215C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132160: addiu       $a1, $a1, 0x4450
    ctx->r5 = ADD32(ctx->r5, 0X4450);
    // 0x80132164: addiu       $a2, $a2, 0x4AD0
    ctx->r6 = ADD32(ctx->r6, 0X4AD0);
    // 0x80132168: addiu       $a3, $a3, 0x30C
    ctx->r7 = ADD32(ctx->r7, 0X30C);
    // 0x8013216C: addiu       $t0, $t0, 0x5250
    ctx->r8 = ADD32(ctx->r8, 0X5250);
    // 0x80132170: addiu       $v1, $v1, 0x5228
    ctx->r3 = ADD32(ctx->r3, 0X5228);
    // 0x80132174: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
L_80132178:
    // 0x80132178: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8013217C: andi        $t2, $a0, 0xD000
    ctx->r10 = ctx->r4 & 0XD000;
    // 0x80132180: beq         $t2, $zero, L_801321F8
    if (ctx->r10 == 0) {
        // 0x80132184: nop
    
            goto L_801321F8;
    }
    // 0x80132184: nop

    // 0x80132188: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8013218C: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80132190: beql        $t3, $zero, L_801321CC
    if (ctx->r11 == 0) {
        // 0x80132194: addiu       $t7, $zero, 0xA9
        ctx->r15 = ADD32(0, 0XA9);
            goto L_801321CC;
    }
    goto skip_0;
    // 0x80132194: addiu       $t7, $zero, 0xA9
    ctx->r15 = ADD32(0, 0XA9);
    skip_0:
    // 0x80132198: lbu         $t4, 0x44($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X44);
    // 0x8013219C: bne         $t4, $zero, L_801321B0
    if (ctx->r12 != 0) {
        // 0x801321A0: nop
    
            goto L_801321B0;
    }
    // 0x801321A0: nop

    // 0x801321A4: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x801321A8: beq         $t5, $zero, L_801321F8
    if (ctx->r13 == 0) {
        // 0x801321AC: nop
    
            goto L_801321F8;
    }
    // 0x801321AC: nop

L_801321B0:
    // 0x801321B0: bne         $t6, $zero, L_801321F8
    if (ctx->r14 != 0) {
        // 0x801321B4: nop
    
            goto L_801321F8;
    }
    // 0x801321B4: nop

    // 0x801321B8: jal         0x80132090
    // 0x801321BC: nop

    mnTitleProceedModeSelect(rdram, ctx);
        goto after_1;
    // 0x801321BC: nop

    after_1:
    // 0x801321C0: b           L_80132204
    // 0x801321C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132204;
    // 0x801321C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801321C8: addiu       $t7, $zero, 0xA9
    ctx->r15 = ADD32(0, 0XA9);
L_801321CC:
    // 0x801321CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801321D0: sw          $t7, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->r15;
    // 0x801321D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801321D8: jal         0x80132320
    // 0x801321DC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    mnTitleTransitionFromFireLogo(rdram, ctx);
        goto after_2;
    // 0x801321DC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    after_2:
    // 0x801321E0: jal         0x80020A74
    // 0x801321E4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_3;
    // 0x801321E4: nop

    after_3:
    // 0x801321E8: jal         0x800266A0
    // 0x801321EC: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_4;
    // 0x801321EC: nop

    after_4:
    // 0x801321F0: b           L_80132204
    // 0x801321F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132204;
    // 0x801321F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801321F8:
    // 0x801321F8: bnel        $v1, $t0, L_80132178
    if (ctx->r3 != ctx->r8) {
        // 0x801321FC: lhu         $a0, 0x2($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X2);
            goto L_80132178;
    }
    goto skip_1;
    // 0x801321FC: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    skip_1:
L_80132200:
    // 0x80132200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132204:
    // 0x80132204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132208: jr          $ra
    // 0x8013220C: nop

    return;
    // 0x8013220C: nop

;}
RECOMP_FUNC void func_ovl2_80107958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010795C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80107960: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80107964: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80107968: lbu         $v1, 0x4B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4B);
    // 0x8010796C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107970: bnel        $v1, $zero, L_80107A30
    if (ctx->r3 != 0) {
        // 0x80107974: lhu         $v0, 0x50($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X50);
            goto L_80107A30;
    }
    goto skip_0;
    // 0x80107974: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x80107978: lb          $t6, 0x53($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X53);
    // 0x8010797C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80107980: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80107984: bnel        $t6, $at, L_801079D4
    if (ctx->r14 != ctx->r1) {
        // 0x80107988: lbu         $t9, 0x56($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X56);
            goto L_801079D4;
    }
    goto skip_1;
    // 0x80107988: lbu         $t9, 0x56($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X56);
    skip_1:
    // 0x8010798C: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80107990: bnel        $v0, $zero, L_801079A8
    if (ctx->r2 != 0) {
        // 0x80107994: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801079A8;
    }
    goto skip_2;
    // 0x80107994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_2:
    // 0x80107998: lhu         $t7, 0x44($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X44);
    // 0x8010799C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801079A0: beq         $t7, $at, L_801079C0
    if (ctx->r15 == ctx->r1) {
        // 0x801079A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801079C0;
    }
    // 0x801079A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801079A8:
    // 0x801079A8: bne         $v0, $at, L_80107A14
    if (ctx->r2 != ctx->r1) {
        // 0x801079AC: nop
    
            goto L_80107A14;
    }
    // 0x801079AC: nop

    // 0x801079B0: lhu         $t8, 0x44($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X44);
    // 0x801079B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801079B8: bne         $t8, $at, L_80107A14
    if (ctx->r24 != ctx->r1) {
        // 0x801079BC: nop
    
            goto L_80107A14;
    }
    // 0x801079BC: nop

L_801079C0:
    // 0x801079C0: jal         0x80106F2C
    // 0x801079C4: nop

    grSectorArwingPrepareLaserCount(rdram, ctx);
        goto after_0;
    // 0x801079C4: nop

    after_0:
    // 0x801079C8: b           L_80107A14
    // 0x801079CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80107A14;
    // 0x801079CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801079D0: lbu         $t9, 0x56($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X56);
L_801079D4:
    // 0x801079D4: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801079D8: bnel        $t9, $zero, L_801079F0
    if (ctx->r25 != 0) {
        // 0x801079DC: lhu         $t1, 0x4E($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X4E);
            goto L_801079F0;
    }
    goto skip_3;
    // 0x801079DC: lhu         $t1, 0x4E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4E);
    skip_3:
    // 0x801079E0: sh          $t0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r8;
    // 0x801079E4: b           L_80107A14
    // 0x801079E8: sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
        goto L_80107A14;
    // 0x801079E8: sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
    // 0x801079EC: lhu         $t1, 0x4E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X4E);
L_801079F0:
    // 0x801079F0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801079F4: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x801079F8: bne         $t3, $zero, L_80107A14
    if (ctx->r11 != 0) {
        // 0x801079FC: sh          $t2, 0x4E($s0)
        MEM_H(0X4E, ctx->r16) = ctx->r10;
            goto L_80107A14;
    }
    // 0x801079FC: sh          $t2, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r10;
    // 0x80107A00: jal         0x80106F5C
    // 0x80107A04: nop

    grSectorArwingGetLaserAmmoCount(rdram, ctx);
        goto after_1;
    // 0x80107A04: nop

    after_1:
    // 0x80107A08: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80107A0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80107A10: sh          $t4, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r12;
L_80107A14:
    // 0x80107A14: beql        $v1, $zero, L_80107B20
    if (ctx->r3 == 0) {
        // 0x80107A18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80107B20;
    }
    goto skip_4;
    // 0x80107A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80107A1C: sb          $v1, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r3;
    // 0x80107A20: sh          $zero, 0x50($s0)
    MEM_H(0X50, ctx->r16) = 0;
    // 0x80107A24: b           L_80107B1C
    // 0x80107A28: sb          $zero, 0x52($s0)
    MEM_B(0X52, ctx->r16) = 0;
        goto L_80107B1C;
    // 0x80107A28: sb          $zero, 0x52($s0)
    MEM_B(0X52, ctx->r16) = 0;
    // 0x80107A2C: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
L_80107A30:
    // 0x80107A30: bne         $v0, $zero, L_80107B04
    if (ctx->r2 != 0) {
        // 0x80107A34: nop
    
            goto L_80107B04;
    }
    // 0x80107A34: nop

    // 0x80107A38: lbu         $t5, 0x52($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X52);
    // 0x80107A3C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80107A40: addiu       $t6, $t6, 0x1B84
    ctx->r14 = ADD32(ctx->r14, 0X1B84);
    // 0x80107A44: bnel        $t5, $zero, L_80107A90
    if (ctx->r13 != 0) {
        // 0x80107A48: lw          $t9, 0x18($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X18);
            goto L_80107A90;
    }
    goto skip_5;
    // 0x80107A48: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    skip_5:
    // 0x80107A4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80107A50: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80107A54: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80107A58: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x80107A5C: jal         0x80106A40
    // 0x80107A60: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    grSectorArwingAddAnim(rdram, ctx);
        goto after_2;
    // 0x80107A60: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80107A64: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80107A68: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80107A6C: jal         0x80106A40
    // 0x80107A70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_3;
    // 0x80107A70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80107A74: lbu         $t7, 0x52($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X52);
    // 0x80107A78: lbu         $v1, 0x4B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4B);
    // 0x80107A7C: lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X50);
    // 0x80107A80: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80107A84: b           L_80107B04
    // 0x80107A88: sb          $t8, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r24;
        goto L_80107B04;
    // 0x80107A88: sb          $t8, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r24;
    // 0x80107A8C: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
L_80107A90:
    // 0x80107A90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107A94: lwc1        $f4, 0xAF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAF0);
    // 0x80107A98: lwc1        $f6, 0x74($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X74);
    // 0x80107A9C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80107AA0: nop

    // 0x80107AA4: bc1f        L_80107B04
    if (!c1cs) {
        // 0x80107AA8: nop
    
            goto L_80107B04;
    }
    // 0x80107AA8: nop

    // 0x80107AAC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80107AB0: jal         0x80107910
    // 0x80107AB4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_ovl2_80107910(rdram, ctx);
        goto after_4;
    // 0x80107AB4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_4:
    // 0x80107AB8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80107ABC: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80107AC0: addiu       $t2, $t2, 0x1B34
    ctx->r10 = ADD32(ctx->r10, 0X1B34);
    // 0x80107AC4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x80107AC8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80107ACC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80107AD0: jal         0x80106A40
    // 0x80107AD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_5;
    // 0x80107AD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x80107AD8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80107ADC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80107AE0: jal         0x80106A40
    // 0x80107AE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_6;
    // 0x80107AE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x80107AE8: lbu         $t4, 0x4B($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4B);
    // 0x80107AEC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80107AF0: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x80107AF4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80107AF8: sb          $t5, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r13;
    // 0x80107AFC: andi        $v1, $t5, 0xFF
    ctx->r3 = ctx->r13 & 0XFF;
    // 0x80107B00: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
L_80107B04:
    // 0x80107B04: beq         $v0, $zero, L_80107B10
    if (ctx->r2 == 0) {
        // 0x80107B08: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80107B10;
    }
    // 0x80107B08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80107B0C: sh          $t6, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r14;
L_80107B10:
    // 0x80107B10: bne         $v1, $zero, L_80107B1C
    if (ctx->r3 != 0) {
        // 0x80107B14: addiu       $t7, $zero, 0xF0
        ctx->r15 = ADD32(0, 0XF0);
            goto L_80107B1C;
    }
    // 0x80107B14: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x80107B18: sh          $t7, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r15;
L_80107B1C:
    // 0x80107B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80107B20:
    // 0x80107B20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80107B28: jr          $ra
    // 0x80107B2C: nop

    return;
    // 0x80107B2C: nop

;}
RECOMP_FUNC void __n_lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E348: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002E34C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002E350: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8002E354: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002E358: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8002E35C: beq         $v1, $zero, L_8002E3AC
    if (ctx->r3 == 0) {
        // 0x8002E360: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8002E3AC;
    }
    // 0x8002E360: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002E364: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8002E368: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002E36C: lbu         $t6, 0x32($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X32);
L_8002E370:
    // 0x8002E370: bnel        $v0, $t6, L_8002E3A4
    if (ctx->r2 != ctx->r14) {
        // 0x8002E374: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_8002E3A4;
    }
    goto skip_0;
    // 0x8002E374: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8002E378: lbu         $t7, 0x31($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X31);
    // 0x8002E37C: bnel        $a2, $t7, L_8002E3A4
    if (ctx->r6 != ctx->r15) {
        // 0x8002E380: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_8002E3A4;
    }
    goto skip_1;
    // 0x8002E380: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8002E384: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x8002E388: beql        $a1, $a0, L_8002E3A4
    if (ctx->r5 == ctx->r4) {
        // 0x8002E38C: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_8002E3A4;
    }
    goto skip_2;
    // 0x8002E38C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x8002E390: beql        $a3, $a0, L_8002E3A4
    if (ctx->r7 == ctx->r4) {
        // 0x8002E394: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_8002E3A4;
    }
    goto skip_3;
    // 0x8002E394: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x8002E398: jr          $ra
    // 0x8002E39C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002E39C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002E3A0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_8002E3A4:
    // 0x8002E3A4: bnel        $v1, $zero, L_8002E370
    if (ctx->r3 != 0) {
        // 0x8002E3A8: lbu         $t6, 0x32($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X32);
            goto L_8002E370;
    }
    goto skip_4;
    // 0x8002E3A8: lbu         $t6, 0x32($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X32);
    skip_4:
L_8002E3AC:
    // 0x8002E3AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E3B0: jr          $ra
    // 0x8002E3B4: nop

    return;
    // 0x8002E3B4: nop

;}
RECOMP_FUNC void mpProcessSetMultiWallLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D951C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D9520: addiu       $a2, $a2, 0xDE0
    ctx->r6 = ADD32(ctx->r6, 0XDE0);
    // 0x800D9524: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800D9528: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D952C: addiu       $a1, $a1, 0xDE8
    ctx->r5 = ADD32(ctx->r5, 0XDE8);
    // 0x800D9530: blez        $v1, L_800D9554
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D9534: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D9554;
    }
    // 0x800D9534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D9538:
    // 0x800D9538: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800D953C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D9540: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D9544: beq         $a0, $t6, L_800D9574
    if (ctx->r4 == ctx->r14) {
        // 0x800D9548: nop
    
            goto L_800D9574;
    }
    // 0x800D9548: nop

    // 0x800D954C: bne         $at, $zero, L_800D9538
    if (ctx->r1 != 0) {
        // 0x800D9550: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800D9538;
    }
    // 0x800D9550: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800D9554:
    // 0x800D9554: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D9558: beq         $v1, $at, L_800D9574
    if (ctx->r3 == ctx->r1) {
        // 0x800D955C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800D9574;
    }
    // 0x800D955C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800D9560: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D9564: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D9568: sw          $a0, 0xDE8($at)
    MEM_W(0XDE8, ctx->r1) = ctx->r4;
    // 0x800D956C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D9570: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800D9574:
    // 0x800D9574: jr          $ra
    // 0x800D9578: nop

    return;
    // 0x800D9578: nop

;}
RECOMP_FUNC void mnTitleUpdateLabelsPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132704: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132708: lw          $t6, 0x4450($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4450);
    // 0x8013270C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132714: bne         $t6, $zero, L_8013272C
    if (ctx->r14 != 0) {
        // 0x80132718: lw          $a3, 0x74($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X74);
            goto L_8013272C;
    }
    // 0x80132718: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8013271C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80132720: lbu         $t7, 0x4AD1($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AD1);
    // 0x80132724: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132728: beq         $t7, $at, L_80132754
    if (ctx->r15 == ctx->r1) {
        // 0x8013272C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132754;
    }
L_8013272C:
    // 0x8013272C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132730: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80132734: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132738: jal         0x80132764
    // 0x8013273C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    mnTitleSetPosition(rdram, ctx);
        goto after_0;
    // 0x8013273C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80132740: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80132744: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132748: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8013274C: jal         0x80132764
    // 0x80132750: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    mnTitleSetPosition(rdram, ctx);
        goto after_1;
    // 0x80132750: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    after_1:
L_80132754:
    // 0x80132754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013275C: jr          $ra
    // 0x80132760: nop

    return;
    // 0x80132760: nop

;}

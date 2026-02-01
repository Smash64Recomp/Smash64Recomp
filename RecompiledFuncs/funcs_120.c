#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftDonkeySpecialNLoopSetProcDamageAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B24C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B250: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015B254: addiu       $t6, $t6, -0x50F0
    ctx->r14 = ADD32(ctx->r14, -0X50F0);
    // 0x8015B258: lw          $t7, 0xADC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B25C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8015B260: sw          $t6, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r14;
    // 0x8015B264: bnel        $t7, $at, L_8015B278
    if (ctx->r15 != ctx->r1) {
        // 0x8015B268: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B278;
    }
    goto skip_0;
    // 0x8015B268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015B26C: jal         0x8000BB04
    // 0x8015B270: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    gcSetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x8015B270: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x8015B274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015B278:
    // 0x8015B278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B27C: jr          $ra
    // 0x8015B280: nop

    return;
    // 0x8015B280: nop

;}
RECOMP_FUNC void mvOpeningFoxStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E02C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E034: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E038: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E03C: addiu       $a0, $a0, -0x1EF0
    ctx->r4 = ADD32(ctx->r4, -0X1EF0);
    // 0x8018E040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E044: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E048: jal         0x80007024
    // 0x8018E04C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E04C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E050: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E054: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E058: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E05C: addiu       $t9, $t9, -0x19F0
    ctx->r25 = ADD32(ctx->r25, -0X19F0);
    // 0x8018E060: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E064: addiu       $a0, $a0, -0x1ED4
    ctx->r4 = ADD32(ctx->r4, -0X1ED4);
    // 0x8018E068: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E06C: jal         0x8000683C
    // 0x8018E070: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E070: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E07C: jr          $ra
    // 0x8018E080: nop

    return;
    // 0x8018E080: nop

;}
RECOMP_FUNC void func_ovl2_8010183C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010183C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101840: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101848: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010184C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80101850: jal         0x800FDAFC
    // 0x80101854: addiu       $a0, $a0, -0x1E2C
    ctx->r4 = ADD32(ctx->r4, -0X1E2C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101854: addiu       $a0, $a0, -0x1E2C
    ctx->r4 = ADD32(ctx->r4, -0X1E2C);
    after_0:
    // 0x80101858: bne         $v0, $zero, L_80101868
    if (ctx->r2 != 0) {
        // 0x8010185C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80101868;
    }
    // 0x8010185C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80101860: b           L_80101898
    // 0x80101864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101898;
    // 0x80101864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101868:
    // 0x80101868: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x8010186C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80101870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101874: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80101878: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8010187C: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x80101880: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80101884: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
    // 0x80101888: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010188C: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x80101890: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80101894: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
L_80101898:
    // 0x80101898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010189C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801018A0: jr          $ra
    // 0x801018A4: nop

    return;
    // 0x801018A4: nop

;}
RECOMP_FUNC void ftManagerGetNextPartsAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7604: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D7608: addiu       $a1, $a1, 0xD88
    ctx->r5 = ADD32(ctx->r5, 0XD88);
    // 0x800D760C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800D7610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D7614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D7618: bne         $v1, $zero, L_800D7640
    if (ctx->r3 != 0) {
        // 0x800D761C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800D7640;
    }
    // 0x800D761C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D7620: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D7624: addiu       $s0, $s0, -0x590
    ctx->r16 = ADD32(ctx->r16, -0X590);
L_800D7628:
    // 0x800D7628: jal         0x80023624
    // 0x800D762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800D762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D7630: jal         0x800A3040
    // 0x800D7634: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800D7634: nop

    after_1:
    // 0x800D7638: b           L_800D7628
    // 0x800D763C: nop

        goto L_800D7628;
    // 0x800D763C: nop

L_800D7640:
    // 0x800D7640: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800D7644: andi        $a0, $zero, 0xFF
    ctx->r4 = 0 & 0XFF;
    // 0x800D7648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D764C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D7650: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800D7654: sb          $a0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r4;
    // 0x800D7658: sb          $zero, 0x7($v1)
    MEM_B(0X7, ctx->r3) = 0;
    // 0x800D765C: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
    // 0x800D7660: sw          $zero, 0xDC($v1)
    MEM_W(0XDC, ctx->r3) = 0;
    // 0x800D7664: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x800D7668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D766C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D7670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D7674: jr          $ra
    // 0x800D7678: nop

    return;
    // 0x800D7678: nop

;}
RECOMP_FUNC void syDmaFillVpk0Buf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003604: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80003608: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000360C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80003610: lw          $a2, 0x50DC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X50DC);
    // 0x80003614: lw          $a1, 0x50D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50D8);
    // 0x80003618: jal         0x80002CA0
    // 0x8000361C: lw          $a0, 0x50E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50E0);
    syDmaReadRom(rdram, ctx);
        goto after_0;
    // 0x8000361C: lw          $a0, 0x50E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50E0);
    after_0:
    // 0x80003620: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80003624: addiu       $v0, $v0, 0x50E0
    ctx->r2 = ADD32(ctx->r2, 0X50E0);
    // 0x80003628: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000362C: lw          $t7, 0x50DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50DC);
    // 0x80003630: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80003634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000363C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80003640: jr          $ra
    // 0x80003644: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80003644: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_ovl0_800CB2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB2F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB2F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB2FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB300: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x800CB304: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CB308: jal         0x800EDBA4
    // 0x800CB30C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800CB30C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CB310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CB314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB318: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800CB31C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800CB320: lwc1        $f6, 0x58($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X58);
    // 0x800CB324: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800CB328: nop

    // 0x800CB32C: bc1fl       L_800CB344
    if (!c1cs) {
        // 0x800CB330: lwc1        $f10, 0x30($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
            goto L_800CB344;
    }
    goto skip_0;
    // 0x800CB330: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    skip_0:
    // 0x800CB334: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800CB338: b           L_800CB34C
    // 0x800CB33C: swc1        $f8, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f8.u32l;
        goto L_800CB34C;
    // 0x800CB33C: swc1        $f8, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f8.u32l;
    // 0x800CB340: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
L_800CB344:
    // 0x800CB344: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800CB348: swc1        $f16, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f16.u32l;
L_800CB34C:
    // 0x800CB34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB358: jr          $ra
    // 0x800CB35C: nop

    return;
    // 0x800CB35C: nop

;}
RECOMP_FUNC void ftKirbySpecialNWaitSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162D80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162D84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162D8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162D90: jal         0x800DEEC8
    // 0x80162D94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162D94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162D98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162D9C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162DA0: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    // 0x80162DA4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162DA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162DAC: jal         0x800E6F24
    // 0x80162DB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162DB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162DB4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162DB8: jal         0x800E8098
    // 0x80162DBC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162DBC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162DC8: jr          $ra
    // 0x80162DCC: nop

    return;
    // 0x80162DCC: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetHiScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134758: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x8013475C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134760: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80134764: jr          $ra
    // 0x80134768: lw          $v0, 0x493C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X493C);
    return;
    // 0x80134768: lw          $v0, 0x493C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X493C);
;}
RECOMP_FUNC void func_ovl8_803769AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803769AC: jr          $ra
    // 0x803769B0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    return;
    // 0x803769B0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
;}
RECOMP_FUNC void itPorygonMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183D00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80183D04: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80183D08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80183D0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80183D10: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80183D14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80183D18: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80183D1C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80183D20: addiu       $a1, $a1, -0x4BA0
    ctx->r5 = ADD32(ctx->r5, -0X4BA0);
    // 0x80183D24: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80183D28: jal         0x8016E174
    // 0x80183D2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80183D2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80183D30: beq         $v0, $zero, L_80183D84
    if (ctx->r2 == 0) {
        // 0x80183D34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80183D84;
    }
    // 0x80183D34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80183D38: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80183D3C: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x80183D40: addiu       $a0, $zero, 0x22C
    ctx->r4 = ADD32(0, 0X22C);
    // 0x80183D44: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80183D48: lbu         $t1, 0x2D3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2D3);
    // 0x80183D4C: lbu         $t3, 0x340($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X340);
    // 0x80183D50: sw          $t9, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r25;
    // 0x80183D54: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80183D58: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80183D5C: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80183D60: sw          $t8, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r24;
    // 0x80183D64: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80183D68: sb          $t2, 0x2D3($v0)
    MEM_B(0X2D3, ctx->r2) = ctx->r10;
    // 0x80183D6C: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80183D70: sb          $t4, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r12;
    // 0x80183D74: sw          $t9, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r25;
    // 0x80183D78: jal         0x800269C0
    // 0x80183D7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80183D7C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80183D80: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80183D84:
    // 0x80183D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80183D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80183D8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80183D90: jr          $ra
    // 0x80183D94: nop

    return;
    // 0x80183D94: nop

;}
RECOMP_FUNC void mvOpeningYosterMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131F94: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80131F98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131F9C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80131FA0: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80131FA4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131FA8: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80131FAC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131FB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131FB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131FB8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80131FBC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80131FC0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131FC4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131FC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131FCC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131FD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FD4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131FD8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131FDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131FE0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80131FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80131FEC: jal         0x8000B93C
    // 0x80131FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131FF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FFC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132000: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132008: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013200C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132010: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132014: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132018: jal         0x80007080
    // 0x8013201C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013201C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132020: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132024: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132028: jr          $ra
    // 0x8013202C: nop

    return;
    // 0x8013202C: nop

;}
RECOMP_FUNC void ftKirbyCopyNessSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155D48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155D4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155D50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155D54: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155D58: jal         0x800DEEC8
    // 0x80155D5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80155D5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155D60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155D64: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80155D68: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80155D6C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155D70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155D74: jal         0x800E6F24
    // 0x80155D78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155D78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155D7C: jal         0x800D8EB8
    // 0x80155D80: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80155D80: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80155D84: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80155D88: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80155D8C: addiu       $t8, $t8, 0x5B40
    ctx->r24 = ADD32(ctx->r24, 0X5B40);
    // 0x80155D90: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80155D94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155D9C: jr          $ra
    // 0x80155DA0: nop

    return;
    // 0x80155DA0: nop

;}
RECOMP_FUNC void ftCommonWalkGetWalkAnimLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E2E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013E2E4: beq         $a1, $at, L_8013E308
    if (ctx->r5 == ctx->r1) {
        // 0x8013E2E8: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8013E308;
    }
    // 0x8013E2E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8013E2EC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013E2F0: beq         $a1, $at, L_8013E318
    if (ctx->r5 == ctx->r1) {
        // 0x8013E2F4: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8013E318;
    }
    // 0x8013E2F4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8013E2F8: beql        $a1, $at, L_8013E32C
    if (ctx->r5 == ctx->r1) {
        // 0x8013E2FC: lw          $t8, 0x9C8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X9C8);
            goto L_8013E32C;
    }
    goto skip_0;
    // 0x8013E2FC: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
    skip_0:
    // 0x8013E300: b           L_8013E338
    // 0x8013E304: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
        goto L_8013E338;
    // 0x8013E304: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8013E308:
    // 0x8013E308: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x8013E30C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8013E310: b           L_8013E334
    // 0x8013E314: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
        goto L_8013E334;
    // 0x8013E314: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8013E318:
    // 0x8013E318: lw          $t7, 0x9C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C8);
    // 0x8013E31C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8013E320: b           L_8013E334
    // 0x8013E324: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_8013E334;
    // 0x8013E324: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x8013E328: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
L_8013E32C:
    // 0x8013E32C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8013E330: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_8013E334:
    // 0x8013E334: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8013E338:
    // 0x8013E338: jr          $ra
    // 0x8013E33C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8013E33C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_ovl8_8037B85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B85C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037B860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037B864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037B868: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037B86C: bne         $a0, $at, L_8037B87C
    if (ctx->r4 != ctx->r1) {
        // 0x8037B870: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8037B87C;
    }
    // 0x8037B870: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037B874: b           L_8037B894
    // 0x8037B878: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
        goto L_8037B894;
    // 0x8037B878: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8037B87C:
    // 0x8037B87C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037B880: bne         $a0, $at, L_8037B890
    if (ctx->r4 != ctx->r1) {
        // 0x8037B884: addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
            goto L_8037B890;
    }
    // 0x8037B884: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8037B888: b           L_8037B890
    // 0x8037B88C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
        goto L_8037B890;
    // 0x8037B88C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_8037B890:
    // 0x8037B890: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8037B894:
    // 0x8037B894: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8037B898: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8037B89C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8037B8A0: jal         0x80033510
    // 0x8037B8A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8037B8A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8037B8A8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8037B8AC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8037B8B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8037B8B4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8037B8B8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8037B8BC: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B8C0: mflo        $t6
    ctx->r14 = lo;
    // 0x8037B8C4: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8037B8C8: beq         $at, $zero, L_8037B97C
    if (ctx->r1 == 0) {
        // 0x8037B8CC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8037B97C;
    }
    // 0x8037B8CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037B8D0: bne         $at, $zero, L_8037B910
    if (ctx->r1 != 0) {
        // 0x8037B8D4: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8037B910;
    }
    // 0x8037B8D4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8037B8D8: div         $zero, $a2, $v1
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r3)));
    // 0x8037B8DC: mflo        $a1
    ctx->r5 = lo;
    // 0x8037B8E0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8037B8E4: bne         $v1, $zero, L_8037B8F0
    if (ctx->r3 != 0) {
        // 0x8037B8E8: nop
    
            goto L_8037B8F0;
    }
    // 0x8037B8E8: nop

    // 0x8037B8EC: break       7
    do_break(2151135468);
L_8037B8F0:
    // 0x8037B8F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037B8F4: bne         $v1, $at, L_8037B908
    if (ctx->r3 != ctx->r1) {
        // 0x8037B8F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037B908;
    }
    // 0x8037B8F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037B8FC: bne         $a2, $at, L_8037B908
    if (ctx->r6 != ctx->r1) {
        // 0x8037B900: nop
    
            goto L_8037B908;
    }
    // 0x8037B900: nop

    // 0x8037B904: break       6
    do_break(2151135492);
L_8037B908:
    // 0x8037B908: b           L_8037B944
    // 0x8037B90C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
        goto L_8037B944;
    // 0x8037B90C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_8037B910:
    // 0x8037B910: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x8037B914: mflo        $a0
    ctx->r4 = lo;
    // 0x8037B918: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037B91C: bne         $v0, $zero, L_8037B928
    if (ctx->r2 != 0) {
        // 0x8037B920: nop
    
            goto L_8037B928;
    }
    // 0x8037B920: nop

    // 0x8037B924: break       7
    do_break(2151135524);
L_8037B928:
    // 0x8037B928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037B92C: bne         $v0, $at, L_8037B940
    if (ctx->r2 != ctx->r1) {
        // 0x8037B930: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037B940;
    }
    // 0x8037B930: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037B934: bne         $a2, $at, L_8037B940
    if (ctx->r6 != ctx->r1) {
        // 0x8037B938: nop
    
            goto L_8037B940;
    }
    // 0x8037B938: nop

    // 0x8037B93C: break       6
    do_break(2151135548);
L_8037B940:
    // 0x8037B940: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_8037B944:
    // 0x8037B944: nop

    // 0x8037B948: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8037B94C: beql        $at, $zero, L_8037B95C
    if (ctx->r1 == 0) {
        // 0x8037B950: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8037B95C;
    }
    goto skip_0;
    // 0x8037B950: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    skip_0:
    // 0x8037B954: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037B958: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_8037B95C:
    // 0x8037B95C: beql        $at, $zero, L_8037B96C
    if (ctx->r1 == 0) {
        // 0x8037B960: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_8037B96C;
    }
    goto skip_1;
    // 0x8037B960: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    skip_1:
    // 0x8037B964: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037B968: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
L_8037B96C:
    // 0x8037B96C: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x8037B970: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8037B974: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8037B978: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_8037B97C:
    // 0x8037B97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037B980: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037B984: jr          $ra
    // 0x8037B988: nop

    return;
    // 0x8037B988: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D7F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D7F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016D7F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016D7FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016D800: lwc1        $f6, 0x250($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X250);
    // 0x8016D804: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8016D808: nop

    // 0x8016D80C: bc1fl       L_8016D838
    if (!c1cs) {
        // 0x8016D810: lwc1        $f6, 0x244($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X244);
            goto L_8016D838;
    }
    goto skip_0;
    // 0x8016D810: lwc1        $f6, 0x244($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X244);
    skip_0:
    // 0x8016D814: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016D818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016D81C: lwc1        $f8, 0x244($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8016D820: lwc1        $f18, 0x2A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2A4);
    // 0x8016D824: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8016D828: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8016D82C: b           L_8016D84C
    // 0x8016D830: swc1        $f4, 0x2A4($v0)
    MEM_W(0X2A4, ctx->r2) = ctx->f4.u32l;
        goto L_8016D84C;
    // 0x8016D830: swc1        $f4, 0x2A4($v0)
    MEM_W(0X2A4, ctx->r2) = ctx->f4.u32l;
    // 0x8016D834: lwc1        $f6, 0x244($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X244);
L_8016D838:
    // 0x8016D838: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016D83C: lwc1        $f18, 0x2A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2A4);
    // 0x8016D840: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016D844: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8016D848: swc1        $f16, 0x2A4($v0)
    MEM_W(0X2A4, ctx->r2) = ctx->f16.u32l;
L_8016D84C:
    // 0x8016D84C: jal         0x8016CC50
    // 0x8016D850: addiu       $a0, $v0, 0x2A4
    ctx->r4 = ADD32(ctx->r2, 0X2A4);
    wpLinkBoomerangClampAngle360(rdram, ctx);
        goto after_0;
    // 0x8016D850: addiu       $a0, $v0, 0x2A4
    ctx->r4 = ADD32(ctx->r2, 0X2A4);
    after_0:
    // 0x8016D854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016D858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016D860: jr          $ra
    // 0x8016D864: nop

    return;
    // 0x8016D864: nop

;}
RECOMP_FUNC void unref_8000A2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A2F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A2F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A2F8: jal         0x80007CF4
    // 0x8000A2FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A2FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A300: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A308: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x8000A30C: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x8000A310: jal         0x80007B98
    // 0x8000A314: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A314: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x8000A318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A320: jr          $ra
    // 0x8000A324: nop

    return;
    // 0x8000A324: nop

;}
RECOMP_FUNC void ftBossOkuhikouki1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159508: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015950C: jal         0x800D9480
    // 0x80159510: addiu       $a1, $a1, -0x6950
    ctx->r5 = ADD32(ctx->r5, -0X6950);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159510: addiu       $a1, $a1, -0x6950
    ctx->r5 = ADD32(ctx->r5, -0X6950);
    after_0:
    // 0x80159514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015951C: jr          $ra
    // 0x80159520: nop

    return;
    // 0x80159520: nop

;}
RECOMP_FUNC void syMatrixLookAtReflectF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A744: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001A748: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001A74C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A750: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001A754: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8001A758: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A75C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001A760: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A764: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8001A768: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A76C: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001A770: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001A774: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A778: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8001A77C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001A780: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001A784: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A788: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001A78C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8001A790: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8001A794: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001A798: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A79C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8001A7A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001A7A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001A7A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8001A7AC: jal         0x80033510
    // 0x8001A7B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A7B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8001A7B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001A7B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A7BC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A7C0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001A7C4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A7C8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001A7CC: nop

    // 0x8001A7D0: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001A7D4: nop

    // 0x8001A7D8: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8001A7DC: nop

    // 0x8001A7E0: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8001A7E4: nop

    // 0x8001A7E8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8001A7EC: sub.s       $f26, $f4, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001A7F0: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001A7F4: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A7F8: mul.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8001A7FC: sub.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A800: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8001A804: nop

    // 0x8001A808: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001A80C: sub.s       $f30, $f4, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A810: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001A814: nop

    // 0x8001A818: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8001A81C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A820: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8001A824: jal         0x80033510
    // 0x8001A828: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001A828: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8001A82C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A830: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A834: nop

    // 0x8001A838: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A83C: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8001A840: nop

    // 0x8001A844: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x8001A848: nop

    // 0x8001A84C: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8001A850: nop

    // 0x8001A854: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x8001A858: nop

    // 0x8001A85C: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x8001A860: nop

    // 0x8001A864: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x8001A868: nop

    // 0x8001A86C: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x8001A870: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001A874: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x8001A878: nop

    // 0x8001A87C: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x8001A880: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8001A884: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001A888: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001A88C: nop

    // 0x8001A890: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001A894: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x8001A898: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001A89C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8001A8A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001A8A4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x8001A8A8: jal         0x80033510
    // 0x8001A8AC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001A8AC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_2:
    // 0x8001A8B0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001A8B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001A8B8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8001A8BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001A8C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A8C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001A8C8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A8CC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A8D0: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001A8D4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8001A8D8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001A8DC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8001A8E0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001A8E4: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001A8E8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001A8EC: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8001A8F0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001A8F4: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8001A8F8: mul.s       $f14, $f26, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x8001A8FC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x8001A900: mul.s       $f2, $f28, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f16.fl);
    // 0x8001A904: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8001A908: nop

    // 0x8001A90C: bc1fl       L_8001A920
    if (!c1cs) {
        // 0x8001A910: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001A920;
    }
    goto skip_0;
    // 0x8001A910: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8001A914: b           L_8001A920
    // 0x8001A918: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8001A920;
    // 0x8001A918: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8001A91C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001A920:
    // 0x8001A920: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A924: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001A928: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001A92C: bc1f        L_8001A93C
    if (!c1cs) {
        // 0x8001A930: sb          $t8, 0x8($a1)
        MEM_B(0X8, ctx->r5) = ctx->r24;
            goto L_8001A93C;
    }
    // 0x8001A930: sb          $t8, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r24;
    // 0x8001A934: b           L_8001A940
    // 0x8001A938: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001A940;
    // 0x8001A938: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001A93C:
    // 0x8001A93C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001A940:
    // 0x8001A940: mul.s       $f2, $f30, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x8001A944: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A948: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001A94C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8001A950: bc1f        L_8001A960
    if (!c1cs) {
        // 0x8001A954: sb          $t1, 0x9($a1)
        MEM_B(0X9, ctx->r5) = ctx->r9;
            goto L_8001A960;
    }
    // 0x8001A954: sb          $t1, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r9;
    // 0x8001A958: b           L_8001A964
    // 0x8001A95C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001A964;
    // 0x8001A95C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001A960:
    // 0x8001A960: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001A964:
    // 0x8001A964: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A968: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8001A96C: nop

    // 0x8001A970: sb          $t4, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r12;
    // 0x8001A974: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A978: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001A97C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001A980: nop

    // 0x8001A984: bc1fl       L_8001A998
    if (!c1cs) {
        // 0x8001A988: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001A998;
    }
    goto skip_1;
    // 0x8001A988: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x8001A98C: b           L_8001A998
    // 0x8001A990: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001A998;
    // 0x8001A990: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001A994: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001A998:
    // 0x8001A998: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A99C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8001A9A0: nop

    // 0x8001A9A4: sb          $t7, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r15;
    // 0x8001A9A8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A9AC: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001A9B0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001A9B4: nop

    // 0x8001A9B8: bc1fl       L_8001A9CC
    if (!c1cs) {
        // 0x8001A9BC: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001A9CC;
    }
    goto skip_2;
    // 0x8001A9BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x8001A9C0: b           L_8001A9CC
    // 0x8001A9C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001A9CC;
    // 0x8001A9C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001A9C8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001A9CC:
    // 0x8001A9CC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001A9D0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8001A9D4: nop

    // 0x8001A9D8: sb          $t0, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r8;
    // 0x8001A9DC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001A9E0: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001A9E4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001A9E8: nop

    // 0x8001A9EC: bc1fl       L_8001AA00
    if (!c1cs) {
        // 0x8001A9F0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001AA00;
    }
    goto skip_3;
    // 0x8001A9F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_3:
    // 0x8001A9F4: b           L_8001AA00
    // 0x8001A9F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001AA00;
    // 0x8001A9F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001A9FC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AA00:
    // 0x8001AA00: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AA04: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8001AA08: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x8001AA0C: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x8001AA10: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8001AA14: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x8001AA18: sb          $zero, 0x4($a1)
    MEM_B(0X4, ctx->r5) = 0;
    // 0x8001AA1C: sb          $zero, 0x5($a1)
    MEM_B(0X5, ctx->r5) = 0;
    // 0x8001AA20: sb          $zero, 0x6($a1)
    MEM_B(0X6, ctx->r5) = 0;
    // 0x8001AA24: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8001AA28: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x8001AA2C: sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // 0x8001AA30: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
    // 0x8001AA34: sb          $zero, 0x13($a1)
    MEM_B(0X13, ctx->r5) = 0;
    // 0x8001AA38: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
    // 0x8001AA3C: sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // 0x8001AA40: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
    // 0x8001AA44: sb          $zero, 0x17($a1)
    MEM_B(0X17, ctx->r5) = 0;
    // 0x8001AA48: sb          $t3, 0x1A($a1)
    MEM_B(0X1A, ctx->r5) = ctx->r11;
    // 0x8001AA4C: swc1        $f26, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f26.u32l;
    // 0x8001AA50: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001AA54: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001AA58: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AA5C: mul.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8001AA60: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001AA64: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001AA68: mul.s       $f8, $f16, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8001AA6C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001AA70: swc1        $f28, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f28.u32l;
    // 0x8001AA74: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8001AA78: swc1        $f30, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f30.u32l;
    // 0x8001AA7C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8001AA80: swc1        $f22, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f22.u32l;
    // 0x8001AA84: swc1        $f24, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f24.u32l;
    // 0x8001AA88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001AA8C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001AA90: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x8001AA94: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x8001AA98: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001AA9C: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001AAA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001AAA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001AAA8: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001AAAC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001AAB0: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x8001AAB4: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001AAB8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001AABC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001AAC0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8001AAC4: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8001AAC8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001AACC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001AAD0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001AAD4: nop

    // 0x8001AAD8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8001AADC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AAE0: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001AAE4: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001AAE8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8001AAEC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001AAF0: mul.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8001AAF4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001AAF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001AAFC: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8001AB00: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8001AB04: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001AB08: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001AB0C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8001AB10: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8001AB14: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8001AB18: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8001AB1C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8001AB20: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001AB24: jr          $ra
    // 0x8001AB28: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001AB28: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeScoreDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131F9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131FA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80131FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FAC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80131FB0: jal         0x80009968
    // 0x80131FB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FBC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FC0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FC4: sw          $v0, 0x4368($at)
    MEM_W(0X4368, ctx->r1) = ctx->r2;
    // 0x80131FC8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131FCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FD0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FD8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131FDC: jal         0x80009DF4
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131FE4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FE8: lw          $t7, 0x452C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X452C);
    // 0x80131FEC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131FF0: addiu       $t8, $t8, 0x408
    ctx->r24 = ADD32(ctx->r24, 0X408);
    // 0x80131FF4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131FF8: jal         0x800CCFDC
    // 0x80131FFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131FFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132000: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132004: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80132008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013200C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80132010: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132014: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132018: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8013201C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132020: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132024: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80132028: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013202C: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80132030: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132034: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132038: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013203C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132040: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132044: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132048: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013204C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80132050: lui         $a2, 0x4393
    ctx->r6 = S32(0X4393 << 16);
    // 0x80132054: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80132058: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8013205C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132060: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80132064: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80132068: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013206C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80132070: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80132074: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132078: lui         $a3, 0x4345
    ctx->r7 = S32(0X4345 << 16);
    // 0x8013207C: jal         0x80131D40
    // 0x80132080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    mnPlayers1PGameContinueMakeScoreDigits(rdram, ctx);
        goto after_3;
    // 0x80132080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80132084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013208C: jr          $ra
    // 0x80132090: nop

    return;
    // 0x80132090: nop

;}
RECOMP_FUNC void func_80004DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004DB4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80004DB8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80004DBC: lw          $v1, 0x6640($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6640);
    // 0x80004DC0: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80004DC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004DC8: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80004DCC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80004DD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80004DD4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80004DD8: blez        $v1, L_80004E7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80004DDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004E7C;
    }
    // 0x80004DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004DE0: sll         $a2, $a1, 4
    ctx->r6 = S32(ctx->r5 << 4);
    // 0x80004DE4: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x80004DE8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004DEC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80004DF0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80004DF4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80004DF8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80004DFC: addiu       $s1, $s1, 0x6568
    ctx->r17 = ADD32(ctx->r17, 0X6568);
    // 0x80004E00: addiu       $t4, $t4, 0x6560
    ctx->r12 = ADD32(ctx->r12, 0X6560);
    // 0x80004E04: addiu       $t2, $t2, 0x6558
    ctx->r10 = ADD32(ctx->r10, 0X6558);
    // 0x80004E08: addiu       $t1, $t1, 0x6550
    ctx->r9 = ADD32(ctx->r9, 0X6550);
    // 0x80004E0C: addiu       $a0, $a0, 0x6548
    ctx->r4 = ADD32(ctx->r4, 0X6548);
    // 0x80004E10: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80004E14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80004E18: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80004E1C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
L_80004E20:
    // 0x80004E20: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80004E24: multu       $a2, $t3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80004E28: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80004E2C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80004E30: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80004E34: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80004E38: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80004E3C: sw          $a3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r7;
    // 0x80004E40: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80004E44: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    // 0x80004E48: addiu       $s2, $s2, 0x38
    ctx->r18 = ADD32(ctx->r18, 0X38);
    // 0x80004E4C: mflo        $t6
    ctx->r14 = lo;
    // 0x80004E50: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80004E54: addiu       $t5, $t5, 0x2C
    ctx->r13 = ADD32(ctx->r13, 0X2C);
    // 0x80004E58: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x80004E5C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80004E60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80004E64: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80004E68: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80004E6C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80004E70: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80004E74: bne         $at, $zero, L_80004E20
    if (ctx->r1 != 0) {
        // 0x80004E78: sw          $t7, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r15;
            goto L_80004E20;
    }
    // 0x80004E78: sw          $t7, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r15;
L_80004E7C:
    // 0x80004E7C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80004E80: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80004E84: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80004E88: jr          $ra
    // 0x80004E8C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80004E8C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void syInterpQuadSpline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D754: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001D758: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D75C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D760: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001D764: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001D768: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001D76C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8001D770: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D774: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D778: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001D77C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D780: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001D784: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001D788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D78C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D790: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D794: nop

    // 0x8001D798: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001D79C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001D7A0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001D7A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D7A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D7AC: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001D7B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D7B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D7B8: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001D7BC: sub.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8001D7C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D7C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D7C8: sub.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8001D7CC: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8001D7D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D7D4: nop

    // 0x8001D7D8: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001D7DC: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001D7E0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D7E4: add.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f8.fl;
    // 0x8001D7E8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001D7EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D7F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D7F4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001D7F8: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8001D7FC: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001D800: add.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f8.fl;
    // 0x8001D804: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x8001D808: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D80C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D810: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001D814: sub.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8001D818: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D81C: nop

    // 0x8001D820: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001D824: nop

    // 0x8001D828: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D82C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001D830: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001D834: add.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8001D838: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001D83C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D840: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001D844: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D848: nop

    // 0x8001D84C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8001D850: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001D854: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001D858: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001D85C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D860: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001D864: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001D868: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001D86C: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001D870: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D874: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001D878: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001D87C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D880: nop

    // 0x8001D884: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001D888: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D88C: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001D890: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8001D894: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001D898: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001D89C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8001D8A0: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8001D8A4: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001D8A8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001D8AC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001D8B0: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001D8B4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001D8B8: nop

    // 0x8001D8BC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001D8C0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001D8C4: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001D8C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D8CC: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001D8D0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001D8D4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D8D8: jr          $ra
    // 0x8001D8DC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8001D8DC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void ftCommonHammerWalkSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801479E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801479E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801479E8: jal         0x800F3828
    // 0x801479EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_0;
    // 0x801479EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x801479F0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801479F4: jal         0x800F385C
    // 0x801479F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_1;
    // 0x801479F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x801479FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80147A00: addiu       $a1, $zero, 0x93
    ctx->r5 = ADD32(0, 0X93);
    // 0x80147A04: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80147A08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147A0C: jal         0x800E6F24
    // 0x80147A10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80147A10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80147A14: jal         0x800F388C
    // 0x80147A18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftHammerSetColAnim(rdram, ctx);
        goto after_3;
    // 0x80147A18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80147A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147A20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80147A24: jr          $ra
    // 0x80147A28: nop

    return;
    // 0x80147A28: nop

;}
RECOMP_FUNC void grWallpaperCalcPersp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104620: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80104624: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x80104628: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8010462C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104630: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80104634: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80104638: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8010463C: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x80104640: jal         0x8001902C
    // 0x80104644: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80104644: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    after_0:
    // 0x80104648: jal         0x80018F7C
    // 0x8010464C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x8010464C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x80104650: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80104654: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80104658: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8010465C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80104660: nop

    // 0x80104664: bc1f        L_80104678
    if (!c1cs) {
        // 0x80104668: nop
    
            goto L_80104678;
    }
    // 0x80104668: nop

    // 0x8010466C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80104670: b           L_80104694
    // 0x80104674: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
        goto L_80104694;
    // 0x80104674: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
L_80104678:
    // 0x80104678: jal         0x8001863C
    // 0x8010467C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x8010467C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_2:
    // 0x80104680: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80104684: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80104688: jal         0x8001863C
    // 0x8010468C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8010468C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x80104690: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
L_80104694:
    // 0x80104694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104698: lwc1        $f12, 0xA30($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XA30);
    // 0x8010469C: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x801046A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801046A4: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801046A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801046AC: lwc1        $f10, 0xA34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA34);
    // 0x801046B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801046B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801046B8: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x801046BC: div.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801046C0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801046C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801046C8: bc1fl       L_801046DC
    if (!c1cs) {
        // 0x801046CC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_801046DC;
    }
    goto skip_0;
    // 0x801046CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x801046D0: b           L_801046F4
    // 0x801046D4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_801046F4;
    // 0x801046D4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x801046D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_801046DC:
    // 0x801046DC: nop

    // 0x801046E0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801046E4: nop

    // 0x801046E8: bc1fl       L_801046F8
    if (!c1cs) {
        // 0x801046EC: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_801046F8;
    }
    goto skip_1;
    // 0x801046EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_1:
    // 0x801046F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_801046F4:
    // 0x801046F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801046F8:
    // 0x801046F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801046FC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80104700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80104704: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80104708: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8010470C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104710: lwc1        $f10, 0xA38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA38);
    // 0x80104714: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80104718: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010471C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80104720: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80104724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80104728: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010472C: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80104730: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80104734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80104738: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8010473C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80104740: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80104744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80104748: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010474C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80104750: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80104754: lwc1        $f6, 0xA3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA3C);
    // 0x80104758: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8010475C: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80104760: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80104764: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x80104768: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010476C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80104770: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80104774: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80104778: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010477C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80104780: nop

    // 0x80104784: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80104788: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010478C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80104790: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80104794: bc1f        L_801047A4
    if (!c1cs) {
        // 0x80104798: lwc1        $f6, 0x1C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_801047A4;
    }
    // 0x80104798: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010479C: b           L_801047D0
    // 0x801047A0: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
        goto L_801047D0;
    // 0x801047A0: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_801047A4:
    // 0x801047A4: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x801047A8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x801047AC: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801047B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801047B4: nop

    // 0x801047B8: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801047BC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801047C0: nop

    // 0x801047C4: bc1fl       L_801047D4
    if (!c1cs) {
        // 0x801047C8: c.lt.s      $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
            goto L_801047D4;
    }
    goto skip_2;
    // 0x801047C8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    skip_2:
    // 0x801047CC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_801047D0:
    // 0x801047D0: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
L_801047D4:
    // 0x801047D4: nop

    // 0x801047D8: bc1fl       L_801047EC
    if (!c1cs) {
        // 0x801047DC: neg.s       $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
            goto L_801047EC;
    }
    goto skip_3;
    // 0x801047DC: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    skip_3:
    // 0x801047E0: b           L_80104814
    // 0x801047E4: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
        goto L_80104814;
    // 0x801047E4: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x801047E8: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
L_801047EC:
    // 0x801047EC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801047F0: sub.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x801047F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801047F8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801047FC: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80104800: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80104804: nop

    // 0x80104808: bc1fl       L_80104818
    if (!c1cs) {
        // 0x8010480C: swc1        $f18, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
            goto L_80104818;
    }
    goto skip_4;
    // 0x8010480C: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    skip_4:
    // 0x80104810: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
L_80104814:
    // 0x80104814: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
L_80104818:
    // 0x80104818: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010481C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80104820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104824: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80104828: jr          $ra
    // 0x8010482C: nop

    return;
    // 0x8010482C: nop

;}
RECOMP_FUNC void func_80020FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020FFC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80021000: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x80021004: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80021008: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002100C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80021010: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80021014: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80021018: beq         $v0, $zero, L_80021024
    if (ctx->r2 == 0) {
        // 0x8002101C: nop
    
            goto L_80021024;
    }
    // 0x8002101C: nop

    // 0x80021020: sb          $a1, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r5;
L_80021024:
    // 0x80021024: jr          $ra
    // 0x80021028: nop

    return;
    // 0x80021028: nop

;}
RECOMP_FUNC void mnVSResultsGetHundredsDigit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134688: bgez        $a0, L_801346A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8013468C: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801346A8;
    }
    // 0x8013468C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134690: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134694: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134698: mflo        $v0
    ctx->r2 = lo;
    // 0x8013469C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x801346A0: jr          $ra
    // 0x801346A4: nop

    return;
    // 0x801346A4: nop

L_801346A8:
    // 0x801346A8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801346AC: mflo        $v0
    ctx->r2 = lo;
    // 0x801346B0: nop

    // 0x801346B4: nop

    // 0x801346B8: jr          $ra
    // 0x801346BC: nop

    return;
    // 0x801346BC: nop

;}
RECOMP_FUNC void gcSetupObjman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A6E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A6E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A6E8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8000A6EC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8000A6F0: addiu       $t0, $t0, 0x66BC
    ctx->r8 = ADD32(ctx->r8, 0X66BC);
    // 0x8000A6F4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8000A6F8: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8000A6FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A700: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000A704: sw          $t7, 0x66C0($at)
    MEM_W(0X66C0, ctx->r1) = ctx->r15;
    // 0x8000A708: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8000A70C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A714: beq         $t8, $zero, L_8000A768
    if (ctx->r24 == 0) {
        // 0x8000A718: nop
    
            goto L_8000A768;
    }
    // 0x8000A718: nop

    // 0x8000A71C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000A720: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A728: sw          $v1, 0x66B0($at)
    MEM_W(0X66B0, ctx->r1) = ctx->r3;
    // 0x8000A72C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8000A730: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8000A734: blez        $t3, L_8000A760
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000A738: addiu       $v0, $v1, 0x1C0
        ctx->r2 = ADD32(ctx->r3, 0X1C0);
            goto L_8000A760;
    }
    // 0x8000A738: addiu       $v0, $v1, 0x1C0
    ctx->r2 = ADD32(ctx->r3, 0X1C0);
L_8000A73C:
    // 0x8000A73C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A740: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x8000A744: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A748: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000A74C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000A750: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000A754: bnel        $at, $zero, L_8000A73C
    if (ctx->r1 != 0) {
        // 0x8000A758: addiu       $v0, $v1, 0x1C0
        ctx->r2 = ADD32(ctx->r3, 0X1C0);
            goto L_8000A73C;
    }
    goto skip_0;
    // 0x8000A758: addiu       $v0, $v1, 0x1C0
    ctx->r2 = ADD32(ctx->r3, 0X1C0);
    skip_0:
    // 0x8000A75C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000A760:
    // 0x8000A760: b           L_8000A76C
    // 0x8000A764: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000A76C;
    // 0x8000A764: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000A768:
    // 0x8000A768: sw          $zero, 0x66B0($at)
    MEM_W(0X66B0, ctx->r1) = 0;
L_8000A76C:
    // 0x8000A76C: lw          $t6, 0x10($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X10);
    // 0x8000A770: beq         $t6, $zero, L_8000A82C
    if (ctx->r14 == 0) {
        // 0x8000A774: nop
    
            goto L_8000A82C;
    }
    // 0x8000A774: nop

    // 0x8000A778: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x8000A77C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8000A780: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000A784: beq         $t7, $zero, L_8000A82C
    if (ctx->r15 == 0) {
        // 0x8000A788: nop
    
            goto L_8000A82C;
    }
    // 0x8000A788: nop

    // 0x8000A78C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8000A790: jal         0x80004980
    // 0x8000A794: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x8000A794: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000A798: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A79C: addiu       $a0, $a0, 0x66C4
    ctx->r4 = ADD32(ctx->r4, 0X66C4);
    // 0x8000A7A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000A7A4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000A7A8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A7AC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8000A7B0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000A7B4: addiu       $t0, $t0, 0x66BC
    ctx->r8 = ADD32(ctx->r8, 0X66BC);
    // 0x8000A7B8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000A7BC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8000A7C0: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x8000A7C4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8000A7C8: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x8000A7CC: sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // 0x8000A7D0: lw          $t5, 0x10($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X10);
    // 0x8000A7D4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8000A7D8: beql        $t6, $zero, L_8000A820
    if (ctx->r14 == 0) {
        // 0x8000A7DC: lw          $t5, 0x0($t0)
        ctx->r13 = MEM_W(ctx->r8, 0X0);
            goto L_8000A820;
    }
    goto skip_1;
    // 0x8000A7DC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x8000A7E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_8000A7E4:
    // 0x8000A7E4: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8000A7E8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8000A7EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000A7F0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000A7F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A7F8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8000A7FC: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x8000A800: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8000A804: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000A808: sltu        $at, $a2, $t4
    ctx->r1 = ctx->r6 < ctx->r12 ? 1 : 0;
    // 0x8000A80C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000A810: bne         $at, $zero, L_8000A7E4
    if (ctx->r1 != 0) {
        // 0x8000A814: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8000A7E4;
    }
    // 0x8000A814: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000A818: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A81C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
L_8000A820:
    // 0x8000A820: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A824: b           L_8000A838
    // 0x8000A828: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
        goto L_8000A838;
    // 0x8000A828: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8000A82C:
    // 0x8000A82C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A830: addiu       $a0, $a0, 0x66C4
    ctx->r4 = ADD32(ctx->r4, 0X66C4);
    // 0x8000A834: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8000A838:
    // 0x8000A838: lw          $t6, 0x1C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C);
    // 0x8000A83C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A840: addiu       $a0, $a0, 0x6774
    ctx->r4 = ADD32(ctx->r4, 0X6774);
    // 0x8000A844: beq         $t6, $zero, L_8000A890
    if (ctx->r14 == 0) {
        // 0x8000A848: nop
    
            goto L_8000A890;
    }
    // 0x8000A848: nop

    // 0x8000A84C: lw          $v1, 0x18($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X18);
    // 0x8000A850: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A854: sw          $v1, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = ctx->r3;
    // 0x8000A858: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x8000A85C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8000A860: blez        $t8, L_8000A888
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8000A864: addiu       $v0, $v1, 0x24
        ctx->r2 = ADD32(ctx->r3, 0X24);
            goto L_8000A888;
    }
    // 0x8000A864: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
L_8000A868:
    // 0x8000A868: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A86C: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x8000A870: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A874: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000A878: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8000A87C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000A880: bnel        $at, $zero, L_8000A868
    if (ctx->r1 != 0) {
        // 0x8000A884: addiu       $v0, $v1, 0x24
        ctx->r2 = ADD32(ctx->r3, 0X24);
            goto L_8000A868;
    }
    goto skip_2;
    // 0x8000A884: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    skip_2:
L_8000A888:
    // 0x8000A888: b           L_8000A898
    // 0x8000A88C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000A898;
    // 0x8000A88C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000A890:
    // 0x8000A890: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A894: sw          $zero, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = 0;
L_8000A898:
    // 0x8000A898: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000A89C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000A8A0: addiu       $v1, $v1, 0x66E8
    ctx->r3 = ADD32(ctx->r3, 0X66E8);
    // 0x8000A8A4: addiu       $v0, $v0, 0x66D0
    ctx->r2 = ADD32(ctx->r2, 0X66D0);
L_8000A8A8:
    // 0x8000A8A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000A8AC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8000A8B0: bne         $at, $zero, L_8000A8A8
    if (ctx->r1 != 0) {
        // 0x8000A8B4: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8000A8A8;
    }
    // 0x8000A8B4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000A8B8: lw          $t4, 0x24($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X24);
    // 0x8000A8BC: beq         $t4, $zero, L_8000A918
    if (ctx->r12 == 0) {
        // 0x8000A8C0: nop
    
            goto L_8000A918;
    }
    // 0x8000A8C0: nop

    // 0x8000A8C4: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8000A8C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A8CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A8D0: sw          $v0, 0x67FC($at)
    MEM_W(0X67FC, ctx->r1) = ctx->r2;
    // 0x8000A8D4: lw          $t5, 0x24($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X24);
    // 0x8000A8D8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8000A8DC: blez        $t6, L_8000A910
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000A8E0: nop
    
            goto L_8000A910;
    }
    // 0x8000A8E0: nop

    // 0x8000A8E4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
L_8000A8E8:
    // 0x8000A8E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A8EC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8000A8F0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000A8F4: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x8000A8F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000A8FC: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8000A900: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000A904: bnel        $at, $zero, L_8000A8E8
    if (ctx->r1 != 0) {
        // 0x8000A908: lw          $t7, 0x28($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X28);
            goto L_8000A8E8;
    }
    goto skip_3;
    // 0x8000A908: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    skip_3:
    // 0x8000A90C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000A910:
    // 0x8000A910: b           L_8000A924
    // 0x8000A914: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
        goto L_8000A924;
    // 0x8000A914: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000A918:
    // 0x8000A918: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A91C: sw          $zero, 0x67FC($at)
    MEM_W(0X67FC, ctx->r1) = 0;
    // 0x8000A920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000A924:
    // 0x8000A924: lw          $t4, 0x28($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X28);
    // 0x8000A928: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A92C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000A930: sh          $t4, 0x6A10($at)
    MEM_H(0X6A10, ctx->r1) = ctx->r12;
    // 0x8000A934: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A938: sh          $t5, 0x6A12($at)
    MEM_H(0X6A12, ctx->r1) = ctx->r13;
    // 0x8000A93C: lw          $t6, 0x34($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X34);
    // 0x8000A940: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A944: sw          $t6, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r14;
    // 0x8000A948: lw          $t7, 0x30($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X30);
    // 0x8000A94C: beq         $t7, $zero, L_8000A99C
    if (ctx->r15 == 0) {
        // 0x8000A950: nop
    
            goto L_8000A99C;
    }
    // 0x8000A950: nop

    // 0x8000A954: lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C);
    // 0x8000A958: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A95C: sw          $v1, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = ctx->r3;
    // 0x8000A960: lw          $t8, 0x30($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X30);
    // 0x8000A964: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000A968: blez        $t9, L_8000A994
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000A96C: addiu       $v0, $v1, 0x48
        ctx->r2 = ADD32(ctx->r3, 0X48);
            goto L_8000A994;
    }
    // 0x8000A96C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
L_8000A970:
    // 0x8000A970: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A974: lw          $t3, 0x30($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X30);
    // 0x8000A978: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A97C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000A980: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000A984: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000A988: bnel        $at, $zero, L_8000A970
    if (ctx->r1 != 0) {
        // 0x8000A98C: addiu       $v0, $v1, 0x48
        ctx->r2 = ADD32(ctx->r3, 0X48);
            goto L_8000A970;
    }
    goto skip_4;
    // 0x8000A98C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    skip_4:
    // 0x8000A990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000A994:
    // 0x8000A994: b           L_8000A9A4
    // 0x8000A998: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000A9A4;
    // 0x8000A998: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000A99C:
    // 0x8000A99C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A9A0: sw          $zero, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = 0;
L_8000A9A4:
    // 0x8000A9A4: lw          $t5, 0x3C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X3C);
    // 0x8000A9A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A9AC: beq         $t5, $zero, L_8000A9FC
    if (ctx->r13 == 0) {
        // 0x8000A9B0: nop
    
            goto L_8000A9FC;
    }
    // 0x8000A9B0: nop

    // 0x8000A9B4: lw          $v1, 0x38($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X38);
    // 0x8000A9B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A9BC: sw          $v1, 0x6A20($at)
    MEM_W(0X6A20, ctx->r1) = ctx->r3;
    // 0x8000A9C0: lw          $t6, 0x3C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X3C);
    // 0x8000A9C4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000A9C8: blez        $t7, L_8000A9F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A9CC: addiu       $v0, $v1, 0x24
        ctx->r2 = ADD32(ctx->r3, 0X24);
            goto L_8000A9F4;
    }
    // 0x8000A9CC: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
L_8000A9D0:
    // 0x8000A9D0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A9D4: lw          $t8, 0x3C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X3C);
    // 0x8000A9D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000A9DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000A9E0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000A9E4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000A9E8: bnel        $at, $zero, L_8000A9D0
    if (ctx->r1 != 0) {
        // 0x8000A9EC: addiu       $v0, $v1, 0x24
        ctx->r2 = ADD32(ctx->r3, 0X24);
            goto L_8000A9D0;
    }
    goto skip_5;
    // 0x8000A9EC: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
    skip_5:
    // 0x8000A9F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000A9F4:
    // 0x8000A9F4: b           L_8000AA00
    // 0x8000A9F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000AA00;
    // 0x8000A9F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000A9FC:
    // 0x8000A9FC: sw          $zero, 0x6A20($at)
    MEM_W(0X6A20, ctx->r1) = 0;
L_8000AA00:
    // 0x8000AA00: lw          $t3, 0x44($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X44);
    // 0x8000AA04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AA08: beq         $t3, $zero, L_8000AA58
    if (ctx->r11 == 0) {
        // 0x8000AA0C: nop
    
            goto L_8000AA58;
    }
    // 0x8000AA0C: nop

    // 0x8000AA10: lw          $v1, 0x40($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X40);
    // 0x8000AA14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AA18: sw          $v1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r3;
    // 0x8000AA1C: lw          $t4, 0x44($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X44);
    // 0x8000AA20: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000AA24: blez        $t5, L_8000AA50
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8000AA28: addiu       $v0, $v1, 0xA8
        ctx->r2 = ADD32(ctx->r3, 0XA8);
            goto L_8000AA50;
    }
    // 0x8000AA28: addiu       $v0, $v1, 0xA8
    ctx->r2 = ADD32(ctx->r3, 0XA8);
L_8000AA2C:
    // 0x8000AA2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000AA30: lw          $t6, 0x44($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X44);
    // 0x8000AA34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000AA38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000AA3C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000AA40: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000AA44: bnel        $at, $zero, L_8000AA2C
    if (ctx->r1 != 0) {
        // 0x8000AA48: addiu       $v0, $v1, 0xA8
        ctx->r2 = ADD32(ctx->r3, 0XA8);
            goto L_8000AA2C;
    }
    goto skip_6;
    // 0x8000AA48: addiu       $v0, $v1, 0xA8
    ctx->r2 = ADD32(ctx->r3, 0XA8);
    skip_6:
    // 0x8000AA4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000AA50:
    // 0x8000AA50: b           L_8000AA5C
    // 0x8000AA54: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8000AA5C;
    // 0x8000AA54: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000AA58:
    // 0x8000AA58: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
L_8000AA5C:
    // 0x8000AA5C: lw          $t8, 0x4C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4C);
    // 0x8000AA60: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000AA64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AA68: beq         $t8, $zero, L_8000AAC0
    if (ctx->r24 == 0) {
        // 0x8000AA6C: addiu       $v1, $v1, 0x6778
        ctx->r3 = ADD32(ctx->r3, 0X6778);
            goto L_8000AAC0;
    }
    // 0x8000AA6C: addiu       $v1, $v1, 0x6778
    ctx->r3 = ADD32(ctx->r3, 0X6778);
    // 0x8000AA70: lw          $v0, 0x48($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X48);
    // 0x8000AA74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AA78: sw          $v0, 0x6A30($at)
    MEM_W(0X6A30, ctx->r1) = ctx->r2;
    // 0x8000AA7C: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x8000AA80: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8000AA84: blez        $t3, L_8000AAB8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000AA88: nop
    
            goto L_8000AAB8;
    }
    // 0x8000AA88: nop

    // 0x8000AA8C: lw          $t4, 0x50($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X50);
L_8000AA90:
    // 0x8000AA90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000AA94: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8000AA98: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000AA9C: lw          $t6, 0x4C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4C);
    // 0x8000AAA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8000AAA4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000AAA8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000AAAC: bnel        $at, $zero, L_8000AA90
    if (ctx->r1 != 0) {
        // 0x8000AAB0: lw          $t4, 0x50($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X50);
            goto L_8000AA90;
    }
    goto skip_7;
    // 0x8000AAB0: lw          $t4, 0x50($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X50);
    skip_7:
    // 0x8000AAB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000AAB8:
    // 0x8000AAB8: b           L_8000AAC4
    // 0x8000AABC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8000AAC4;
    // 0x8000AABC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8000AAC0:
    // 0x8000AAC0: sw          $zero, 0x6A30($at)
    MEM_W(0X6A30, ctx->r1) = 0;
L_8000AAC4:
    // 0x8000AAC4: lw          $t8, 0x50($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X50);
    // 0x8000AAC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AACC: sh          $t8, 0x6A38($at)
    MEM_H(0X6A38, ctx->r1) = ctx->r24;
    // 0x8000AAD0: lw          $t9, 0x58($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X58);
    // 0x8000AAD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AAD8: beq         $t9, $zero, L_8000AB30
    if (ctx->r25 == 0) {
        // 0x8000AADC: nop
    
            goto L_8000AB30;
    }
    // 0x8000AADC: nop

    // 0x8000AAE0: lw          $v0, 0x54($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X54);
    // 0x8000AAE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AAE8: sw          $v0, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = ctx->r2;
    // 0x8000AAEC: lw          $t3, 0x58($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X58);
    // 0x8000AAF0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AAF4: blez        $t4, L_8000AB28
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000AAF8: nop
    
            goto L_8000AB28;
    }
    // 0x8000AAF8: nop

    // 0x8000AAFC: lw          $t5, 0x5C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X5C);
L_8000AB00:
    // 0x8000AB00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000AB04: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000AB08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000AB0C: lw          $t7, 0x58($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X58);
    // 0x8000AB10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000AB14: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8000AB18: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000AB1C: bnel        $at, $zero, L_8000AB00
    if (ctx->r1 != 0) {
        // 0x8000AB20: lw          $t5, 0x5C($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X5C);
            goto L_8000AB00;
    }
    goto skip_8;
    // 0x8000AB20: lw          $t5, 0x5C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X5C);
    skip_8:
    // 0x8000AB24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000AB28:
    // 0x8000AB28: b           L_8000AB34
    // 0x8000AB2C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8000AB34;
    // 0x8000AB2C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8000AB30:
    // 0x8000AB30: sw          $zero, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = 0;
L_8000AB34:
    // 0x8000AB34: lw          $t9, 0x5C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X5C);
    // 0x8000AB38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AB3C: sh          $t9, 0x6A44($at)
    MEM_H(0X6A44, ctx->r1) = ctx->r25;
    // 0x8000AB40: lw          $t3, 0x64($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X64);
    // 0x8000AB44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AB48: beq         $t3, $zero, L_8000AB9C
    if (ctx->r11 == 0) {
        // 0x8000AB4C: nop
    
            goto L_8000AB9C;
    }
    // 0x8000AB4C: nop

    // 0x8000AB50: lw          $v0, 0x60($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X60);
    // 0x8000AB54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AB58: sw          $v0, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r2;
    // 0x8000AB5C: lw          $t4, 0x64($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X64);
    // 0x8000AB60: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000AB64: blez        $t5, L_8000AB94
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8000AB68: nop
    
            goto L_8000AB94;
    }
    // 0x8000AB68: nop

    // 0x8000AB6C: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
L_8000AB70:
    // 0x8000AB70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000AB74: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8000AB78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000AB7C: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
    // 0x8000AB80: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8000AB84: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000AB88: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000AB8C: bnel        $at, $zero, L_8000AB70
    if (ctx->r1 != 0) {
        // 0x8000AB90: lw          $t6, 0x68($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X68);
            goto L_8000AB70;
    }
    goto skip_9;
    // 0x8000AB90: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    skip_9:
L_8000AB94:
    // 0x8000AB94: b           L_8000ABA0
    // 0x8000AB98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8000ABA0;
    // 0x8000AB98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8000AB9C:
    // 0x8000AB9C: sw          $zero, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = 0;
L_8000ABA0:
    // 0x8000ABA0: lw          $t3, 0x68($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X68);
    // 0x8000ABA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ABA8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000ABAC: addiu       $v0, $v0, 0x66F0
    ctx->r2 = ADD32(ctx->r2, 0X66F0);
    // 0x8000ABB0: sh          $t3, 0x6A50($at)
    MEM_H(0X6A50, ctx->r1) = ctx->r11;
L_8000ABB4:
    // 0x8000ABB4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000ABB8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000ABBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000ABC0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000ABC4: bne         $at, $zero, L_8000ABB4
    if (ctx->r1 != 0) {
        // 0x8000ABC8: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8000ABB4;
    }
    // 0x8000ABC8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000ABCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ABD0: sw          $zero, 0x6908($at)
    MEM_W(0X6908, ctx->r1) = 0;
    // 0x8000ABD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ABD8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000ABDC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000ABE0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000ABE4: addiu       $a0, $a0, 0x6904
    ctx->r4 = ADD32(ctx->r4, 0X6904);
    // 0x8000ABE8: addiu       $v0, $v0, 0x6804
    ctx->r2 = ADD32(ctx->r2, 0X6804);
    // 0x8000ABEC: addiu       $v1, $v1, 0x690C
    ctx->r3 = ADD32(ctx->r3, 0X690C);
    // 0x8000ABF0: sw          $zero, 0x6800($at)
    MEM_W(0X6800, ctx->r1) = 0;
L_8000ABF4:
    // 0x8000ABF4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000ABF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000ABFC: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8000AC00: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8000AC04: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8000AC08: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8000AC0C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000AC10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8000AC14: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8000AC18: bne         $v0, $a0, L_8000ABF4
    if (ctx->r2 != ctx->r4) {
        // 0x8000AC1C: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8000ABF4;
    }
    // 0x8000AC1C: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8000AC20: jal         0x80014430
    // 0x8000AC24: nop

    gcInitDLs(rdram, ctx);
        goto after_1;
    // 0x8000AC24: nop

    after_1:
    // 0x8000AC28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000AC2C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000AC30: addiu       $a1, $a1, 0x6A68
    ctx->r5 = ADD32(ctx->r5, 0X6A68);
    // 0x8000AC34: addiu       $a0, $a0, 0x6A70
    ctx->r4 = ADD32(ctx->r4, 0X6A70);
    // 0x8000AC38: jal         0x80034480
    // 0x8000AC3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8000AC3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8000AC40: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000AC44: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000AC48: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000AC4C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000AC50: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8000AC54: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8000AC58: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8000AC5C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8000AC60: addiu       $t2, $t2, 0x66B4
    ctx->r10 = ADD32(ctx->r10, 0X66B4);
    // 0x8000AC64: addiu       $t1, $t1, 0x66E8
    ctx->r9 = ADD32(ctx->r9, 0X66E8);
    // 0x8000AC68: addiu       $t0, $t0, 0x6A0C
    ctx->r8 = ADD32(ctx->r8, 0X6A0C);
    // 0x8000AC6C: addiu       $a3, $a3, 0x6A18
    ctx->r7 = ADD32(ctx->r7, 0X6A18);
    // 0x8000AC70: addiu       $a2, $a2, 0x6A24
    ctx->r6 = ADD32(ctx->r6, 0X6A24);
    // 0x8000AC74: addiu       $a1, $a1, 0x6A34
    ctx->r5 = ADD32(ctx->r5, 0X6A34);
    // 0x8000AC78: addiu       $v1, $v1, 0x6A40
    ctx->r3 = ADD32(ctx->r3, 0X6A40);
    // 0x8000AC7C: addiu       $v0, $v0, 0x6A4C
    ctx->r2 = ADD32(ctx->r2, 0X6A4C);
    // 0x8000AC80: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000AC84: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000AC88: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000AC8C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000AC90: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8000AC94: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8000AC98: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000AC9C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8000ACA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ACA4: sw          $zero, 0x66B8($at)
    MEM_W(0X66B8, ctx->r1) = 0;
    // 0x8000ACA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ACAC: sw          $zero, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = 0;
    // 0x8000ACB0: jal         0x80017830
    // 0x8000ACB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcSetCameraMatrixMode(rdram, ctx);
        goto after_3;
    // 0x8000ACB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8000ACB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ACBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000ACC0: sw          $zero, -0x478C($at)
    MEM_W(-0X478C, ctx->r1) = 0;
    // 0x8000ACC4: jr          $ra
    // 0x8000ACC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000ACC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftComputerProcStand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137A20: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80137A24: jal         0x80136D0C
    // 0x80137A28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137A28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80137A2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80137A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137A34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137A38: addiu       $v1, $a1, 0x1CC
    ctx->r3 = ADD32(ctx->r5, 0X1CC);
    // 0x80137A3C: lbu         $t6, 0x4A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4A);
    // 0x80137A40: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80137A44: beq         $v0, $zero, L_80137A54
    if (ctx->r2 == 0) {
        // 0x80137A48: sb          $t7, 0x4A($v1)
        MEM_B(0X4A, ctx->r3) = ctx->r15;
            goto L_80137A54;
    }
    // 0x80137A48: sb          $t7, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r15;
    // 0x80137A4C: bnel        $v0, $at, L_80137A60
    if (ctx->r2 != ctx->r1) {
        // 0x80137A50: lw          $t8, 0x24($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X24);
            goto L_80137A60;
    }
    goto skip_0;
    // 0x80137A50: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
    skip_0:
L_80137A54:
    // 0x80137A54: b           L_80137A94
    // 0x80137A58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80137A94;
    // 0x80137A58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80137A5C: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
L_80137A60:
    // 0x80137A60: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80137A64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80137A68: bne         $t8, $at, L_80137A90
    if (ctx->r24 != ctx->r1) {
        // 0x80137A6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80137A90;
    }
    // 0x80137A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137A70: lwc1        $f4, 0x70($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80137A74: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80137A78: lw          $t9, 0x88($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X88);
    // 0x80137A7C: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80137A80: swc1        $f4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
    // 0x80137A84: swc1        $f6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f6.u32l;
    // 0x80137A88: b           L_80137A94
    // 0x80137A8C: sw          $t9, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r25;
        goto L_80137A94;
    // 0x80137A8C: sw          $t9, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r25;
L_80137A90:
    // 0x80137A90: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80137A94:
    // 0x80137A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80137A9C: jr          $ra
    // 0x80137AA0: nop

    return;
    // 0x80137AA0: nop

;}
RECOMP_FUNC void func_ovl8_80377AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377AF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377AF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80377AF8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80377AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377B00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377B04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80377B08: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80377B0C: addiu       $a2, $a2, -0x60A4
    ctx->r6 = ADD32(ctx->r6, -0X60A4);
    // 0x80377B10: jal         0x80376B60
    // 0x80377B14: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    func_ovl8_80376B60(rdram, ctx);
        goto after_0;
    // 0x80377B14: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    after_0:
    // 0x80377B18: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80377B1C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80377B24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80377B28: jal         0x80377B40
    // 0x80377B2C: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    func_ovl8_80377B40(rdram, ctx);
        goto after_1;
    // 0x80377B2C: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    after_1:
    // 0x80377B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377B38: jr          $ra
    // 0x80377B3C: nop

    return;
    // 0x80377B3C: nop

;}
RECOMP_FUNC void ifCommonAnnounceGoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801121C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801121C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801121CC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801121D0: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x801121D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801121D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801121DC: beq         $s0, $zero, L_80112208
    if (ctx->r16 == 0) {
        // 0x801121E0: nop
    
            goto L_80112208;
    }
    // 0x801121E0: nop

    // 0x801121E4: lw          $s1, 0x84($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X84);
L_801121E8:
    // 0x801121E8: jal         0x800E7F68
    // 0x801121EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_0;
    // 0x801121EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801121F0: lbu         $t6, 0x191($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X191);
    // 0x801121F4: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x801121F8: sb          $t7, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r15;
    // 0x801121FC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x80112200: bnel        $s0, $zero, L_801121E8
    if (ctx->r16 != 0) {
        // 0x80112204: lw          $s1, 0x84($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X84);
            goto L_801121E8;
    }
    goto skip_0;
    // 0x80112204: lw          $s1, 0x84($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X84);
    skip_0:
L_80112208:
    // 0x80112208: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8011220C: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x80112210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80112214: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112218: sb          $v0, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r2;
    // 0x8011221C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80112220: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80112224: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80112228: sb          $v0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r2;
    // 0x8011222C: jr          $ra
    // 0x80112230: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80112230: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mpProcessCheckFloorEdgeCollisionR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9CC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D9CC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9CC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D9CCC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D9CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D9CD4: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x800D9CD8: jal         0x800FA964
    // 0x800D9CDC: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_0;
    // 0x800D9CDC: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_0:
    // 0x800D9CE0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800D9CE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D9CE8: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9CEC: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9CF0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D9CF4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D9CF8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9CFC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9D00: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9D08: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    // 0x800D9D0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9D10: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800D9D14: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9D18: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9D1C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D9D20: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800D9D24: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9D28: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9D2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9D30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9D34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9D38: jal         0x800F6B58
    // 0x800D9D3C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D9D3C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800D9D40: beq         $v0, $zero, L_800D9D60
    if (ctx->r2 == 0) {
        // 0x800D9D44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D9D60;
    }
    // 0x800D9D44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D9D48: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9D4C: lw          $t7, 0x60($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X60);
    // 0x800D9D50: beql        $t6, $t7, L_800D9D64
    if (ctx->r14 == ctx->r15) {
        // 0x800D9D54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D9D64;
    }
    goto skip_0;
    // 0x800D9D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D9D58: b           L_800D9D64
    // 0x800D9D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D9D64;
    // 0x800D9D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9D60:
    // 0x800D9D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D9D64:
    // 0x800D9D64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D9D68: jr          $ra
    // 0x800D9D6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D9D6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_ovl8_80371B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371BA0: lwl         $t7, 0x0($a1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r5, 0X0);
    // 0x80371BA4: lwr         $t7, 0x3($a1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r5, 0X3);
    // 0x80371BA8: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x80371BAC: swl         $t7, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r15);
    // 0x80371BB0: swr         $t7, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r15);
    // 0x80371BB4: jal         0x80377168
    // 0x80371BB8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    func_ovl8_80377168(rdram, ctx);
        goto after_0;
    // 0x80371BB8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_0:
    // 0x80371BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371BC4: jr          $ra
    // 0x80371BC8: nop

    return;
    // 0x80371BC8: nop

;}
RECOMP_FUNC void ftCommonHammerFallProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147BE0: jr          $ra
    // 0x80147BE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80147BE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ftCommonGuardSetStatusFromEscape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148E30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148E34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80148E38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80148E3C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80148E40: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80148E44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80148E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80148E4C: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80148E50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80148E54: jal         0x800E6F24
    // 0x80148E58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80148E58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80148E5C: jal         0x800E0830
    // 0x80148E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80148E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80148E64: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80148E68: beq         $t6, $zero, L_80148EBC
    if (ctx->r14 == 0) {
        // 0x80148E6C: nop
    
            goto L_80148EBC;
    }
    // 0x80148E6C: nop

    // 0x80148E70: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80148E74: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148E78: bne         $t7, $at, L_80148EA4
    if (ctx->r15 != ctx->r1) {
        // 0x80148E7C: nop
    
            goto L_80148EA4;
    }
    // 0x80148E7C: nop

    // 0x80148E80: jal         0x80101374
    // 0x80148E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerYoshiShieldMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80148E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80148E88: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x80148E8C: jal         0x800E90F8
    // 0x80148E90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamHideModelPartAll(rdram, ctx);
        goto after_3;
    // 0x80148E90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80148E94: jal         0x80148214
    // 0x80148E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardSetHitStatusYoshi(rdram, ctx);
        goto after_4;
    // 0x80148E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80148E9C: b           L_80148EB4
    // 0x80148EA0: lbu         $t9, 0x18F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18F);
        goto L_80148EB4;
    // 0x80148EA0: lbu         $t9, 0x18F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18F);
L_80148EA4:
    // 0x80148EA4: jal         0x80101108
    // 0x80148EA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerShieldMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80148EA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80148EAC: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x80148EB0: lbu         $t9, 0x18F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18F);
L_80148EB4:
    // 0x80148EB4: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x80148EB8: sb          $t0, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r8;
L_80148EBC:
    // 0x80148EBC: jal         0x80148714
    // 0x80148EC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_6;
    // 0x80148EC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80148EC4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80148EC8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80148ECC: sw          $t1, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r9;
    // 0x80148ED0: sw          $t2, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r10;
    // 0x80148ED4: sw          $zero, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = 0;
    // 0x80148ED8: sw          $zero, 0xB38($s0)
    MEM_W(0XB38, ctx->r16) = 0;
    // 0x80148EDC: sw          $zero, 0xB3C($s0)
    MEM_W(0XB3C, ctx->r16) = 0;
    // 0x80148EE0: addiu       $t3, $zero, 0x34
    ctx->r11 = ADD32(0, 0X34);
    // 0x80148EE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80148EE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80148EEC: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    // 0x80148EF0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80148EF4: jal         0x800E6F24
    // 0x80148EF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_7;
    // 0x80148EF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80148EFC: jal         0x8014889C
    // 0x80148F00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardInitJoints(rdram, ctx);
        goto after_8;
    // 0x80148F00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80148F04: lbu         $t5, 0x18F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X18F);
    // 0x80148F08: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x80148F0C: sb          $t6, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r14;
    // 0x80148F10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80148F14: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80148F18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80148F1C: jr          $ra
    // 0x80148F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80148F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_803719A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803719A4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x803719A8: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x803719AC: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x803719B0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x803719B4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x803719B8: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x803719BC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x803719C0: jr          $ra
    // 0x803719C4: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    return;
    // 0x803719C4: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void mnVSResultsMakeWallpaperTint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134FD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134FD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134FD8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80134FDC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134FE0: sw          $t6, -0x643C($at)
    MEM_W(-0X643C, ctx->r1) = ctx->r14;
    // 0x80134FE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134FEC: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80134FF0: jal         0x80009968
    // 0x80134FF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134FF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134FF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134FFC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80135000: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80135004: addiu       $a1, $a1, 0x4E94
    ctx->r5 = ADD32(ctx->r5, 0X4E94);
    // 0x80135008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013500C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80135010: jal         0x80009DF4
    // 0x80135014: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135014: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80135018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013501C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80135020: jr          $ra
    // 0x80135024: nop

    return;
    // 0x80135024: nop

;}
RECOMP_FUNC void grYamabukiGateUpdateOpen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AFF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010AFF8: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010AFFC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8010B000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B008: bnel        $v1, $zero, L_8010B024
    if (ctx->r3 != 0) {
        // 0x8010B00C: lbu         $t6, 0x1D($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X1D);
            goto L_8010B024;
    }
    goto skip_0;
    // 0x8010B00C: lbu         $t6, 0x1D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1D);
    skip_0:
    // 0x8010B010: jal         0x8010B0B8
    // 0x8010B014: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_0;
    // 0x8010B014: nop

    after_0:
    // 0x8010B018: b           L_8010B0A0
    // 0x8010B01C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010B0A0;
    // 0x8010B01C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B020: lbu         $t6, 0x1D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1D);
L_8010B024:
    // 0x8010B024: bnel        $t6, $zero, L_8010B0A0
    if (ctx->r14 != 0) {
        // 0x8010B028: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010B0A0;
    }
    goto skip_1;
    // 0x8010B028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8010B02C: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x8010B030: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x8010B034: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010B038: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8010B03C: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8010B040: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8010B044: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8010B048: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010B04C: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x8010B050: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8010B054: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8010B058: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x8010B05C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8010B060: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8010B064: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010B068: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8010B06C: bc1f        L_8010B080
    if (!c1cs) {
        // 0x8010B070: swc1        $f10, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
            goto L_8010B080;
    }
    // 0x8010B070: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8010B074: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8010B078: b           L_8010B09C
    // 0x8010B07C: sb          $t0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r8;
        goto L_8010B09C;
    // 0x8010B07C: sb          $t0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r8;
L_8010B080:
    // 0x8010B080: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8010B084: nop

    // 0x8010B088: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010B08C: nop

    // 0x8010B090: bc1fl       L_8010B0A0
    if (!c1cs) {
        // 0x8010B094: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010B0A0;
    }
    goto skip_2;
    // 0x8010B094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010B098: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
L_8010B09C:
    // 0x8010B09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B0A0:
    // 0x8010B0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B0A4: jr          $ra
    // 0x8010B0A8: nop

    return;
    // 0x8010B0A8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusAnnounceFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134A50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80134A54: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134A5C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80134A60: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80134A64: addiu       $t7, $t7, 0x745C
    ctx->r15 = ADD32(ctx->r15, 0X745C);
    // 0x80134A68: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134A6C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134A70: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80134A74: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134A78: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134A7C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134A80: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134A84: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134A88: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80134A8C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80134A90: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80134A94: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80134A98: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80134A9C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80134AA0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80134AA4: lw          $a0, 0x74($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X74);
    // 0x80134AA8: beq         $a0, $zero, L_80134AD0
    if (ctx->r4 == 0) {
        // 0x80134AAC: nop
    
            goto L_80134AD0;
    }
    // 0x80134AAC: nop

    // 0x80134AB0: lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X26);
    // 0x80134AB4: beq         $v0, $zero, L_80134AD0
    if (ctx->r2 == 0) {
        // 0x80134AB8: nop
    
            goto L_80134AD0;
    }
    // 0x80134AB8: nop

    // 0x80134ABC: lhu         $t0, 0x78($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X78);
    // 0x80134AC0: bne         $t0, $v0, L_80134AD0
    if (ctx->r8 != ctx->r2) {
        // 0x80134AC4: nop
    
            goto L_80134AD0;
    }
    // 0x80134AC4: nop

    // 0x80134AC8: jal         0x80026738
    // 0x80134ACC: nop

    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80134ACC: nop

    after_0:
L_80134AD0:
    // 0x80134AD0: jal         0x800269C0
    // 0x80134AD4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80134AD4: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x80134AD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134ADC: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80134AE0: lw          $t1, 0x20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X20);
    // 0x80134AE4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80134AE8: addu        $a0, $sp, $t2
    ctx->r4 = ADD32(ctx->r29, ctx->r10);
    // 0x80134AEC: jal         0x800269C0
    // 0x80134AF0: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80134AF0: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    after_2:
    // 0x80134AF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134AF8: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80134AFC: beq         $v0, $zero, L_80134B0C
    if (ctx->r2 == 0) {
        // 0x80134B00: sw          $v0, 0x74($v1)
        MEM_W(0X74, ctx->r3) = ctx->r2;
            goto L_80134B0C;
    }
    // 0x80134B00: sw          $v0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r2;
    // 0x80134B04: lhu         $t3, 0x26($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X26);
    // 0x80134B08: sh          $t3, 0x78($v1)
    MEM_H(0X78, ctx->r3) = ctx->r11;
L_80134B0C:
    // 0x80134B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134B10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80134B14: jr          $ra
    // 0x80134B18: nop

    return;
    // 0x80134B18: nop

;}
RECOMP_FUNC void func_ovl27_80137EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137EE8: jr          $ra
    // 0x80137EEC: nop

    return;
    // 0x80137EEC: nop

;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035CD0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80035CD4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80035CD8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80035CDC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80035CE0: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80035CE4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80035CE8: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x80035CEC: beql        $at, $zero, L_80035E14
    if (ctx->r1 == 0) {
        // 0x80035CF0: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_80035E14;
    }
    goto skip_0;
    // 0x80035CF0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x80035CF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035CF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80035CFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80035D00: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80035D04: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80035D08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80035D0C: bc1fl       L_80035D20
    if (!c1cs) {
        // 0x80035D10: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_80035D20;
    }
    goto skip_1;
    // 0x80035D10: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x80035D14: b           L_80035D20
    // 0x80035D18: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_80035D20;
    // 0x80035D18: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x80035D1C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80035D20:
    // 0x80035D20: ldc1        $f8, -0xCB8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XCB8);
    // 0x80035D24: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x80035D28: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80035D2C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x80035D30: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80035D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035D38: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x80035D3C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x80035D40: nop

    // 0x80035D44: bc1fl       L_80035D64
    if (!c1cs) {
        // 0x80035D48: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_80035D64;
    }
    goto skip_2;
    // 0x80035D48: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x80035D4C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x80035D50: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80035D54: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80035D58: b           L_80035D74
    // 0x80035D5C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_80035D74;
    // 0x80035D5C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80035D60: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_80035D64:
    // 0x80035D64: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80035D68: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80035D6C: nop

    // 0x80035D70: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_80035D74:
    // 0x80035D74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80035D78: ldc1        $f10, -0xCB0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0XCB0);
    // 0x80035D7C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80035D80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80035D84: ldc1        $f6, -0xCA8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0XCA8);
    // 0x80035D88: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80035D8C: addiu       $v1, $v1, -0xCE0
    ctx->r3 = ADD32(ctx->r3, -0XCE0);
    // 0x80035D90: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x80035D94: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80035D98: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80035D9C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x80035DA0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80035DA4: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x80035DA8: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x80035DAC: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x80035DB0: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80035DB4: nop

    // 0x80035DB8: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80035DBC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80035DC0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80035DC4: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80035DC8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80035DCC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80035DD0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80035DD4: bne         $t0, $zero, L_80035DF4
    if (ctx->r8 != 0) {
        // 0x80035DD8: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_80035DF4;
    }
    // 0x80035DD8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x80035DDC: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80035DE0: nop

    // 0x80035DE4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80035DE8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x80035DEC: jr          $ra
    // 0x80035DF0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80035DF0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80035DF4:
    // 0x80035DF4: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x80035DF8: nop

    // 0x80035DFC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80035E00: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x80035E04: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80035E08: jr          $ra
    // 0x80035E0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80035E0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80035E10: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_80035E14:
    // 0x80035E14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80035E18: bc1t        L_80035E2C
    if (c1cs) {
        // 0x80035E1C: nop
    
            goto L_80035E2C;
    }
    // 0x80035E1C: nop

    // 0x80035E20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80035E24: jr          $ra
    // 0x80035E28: lwc1        $f0, -0xC90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC90);
    return;
    // 0x80035E28: lwc1        $f0, -0xC90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC90);
L_80035E2C:
    // 0x80035E2C: lwc1        $f0, -0xCA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XCA0);
    // 0x80035E30: jr          $ra
    // 0x80035E34: nop

    return;
    // 0x80035E34: nop

;}
RECOMP_FUNC void wpMainApplyGravityClampTVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016808C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80168094: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80168098: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8016809C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x801680A0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x801680A4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801680A8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x801680AC: jal         0x800C7A84
    // 0x801680B0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_0;
    // 0x801680B0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801680B4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801680B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801680BC: nop

    // 0x801680C0: bc1fl       L_801680E0
    if (!c1cs) {
        // 0x801680C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801680E0;
    }
    goto skip_0;
    // 0x801680C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801680C8: jal         0x800C7A00
    // 0x801680CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    lbCommonNormDist2D(rdram, ctx);
        goto after_1;
    // 0x801680CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x801680D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801680D4: jal         0x800C7AE0
    // 0x801680D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    lbCommonScale2D(rdram, ctx);
        goto after_2;
    // 0x801680D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801680DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801680E0:
    // 0x801680E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801680E4: jr          $ra
    // 0x801680E8: nop

    return;
    // 0x801680E8: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E83C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E844: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E848: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015E84C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015E850: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E854: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015E858: jal         0x800E6F24
    // 0x8015E85C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E85C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015E860: jal         0x800E0830
    // 0x8015E864: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E864: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015E868: jal         0x8015E7F8
    // 0x8015E86C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialNCatchInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E86C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015E870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E878: jr          $ra
    // 0x8015E87C: nop

    return;
    // 0x8015E87C: nop

;}
RECOMP_FUNC void ftYoshiSpecialNReleaseSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E708: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E70C: jal         0x800DEEC8
    // 0x8015E710: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015E710: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E714: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E718: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015E71C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x8015E720: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E724: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E728: jal         0x800E6F24
    // 0x8015E72C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E72C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E734: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E738: jr          $ra
    // 0x8015E73C: nop

    return;
    // 0x8015E73C: nop

;}
RECOMP_FUNC void sc1PStageClearMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133AC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133AC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133AD0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80133AD4: jal         0x80009968
    // 0x80133AD8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133AD8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133ADC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133AE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133AE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133AE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133AEC: addiu       $a1, $a1, 0x39C0
    ctx->r5 = ADD32(ctx->r5, 0X39C0);
    // 0x80133AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133AF4: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80133AF8: jal         0x80009DF4
    // 0x80133AFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133AFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133B00: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133B04: lw          $t7, 0x55A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X55A0);
    // 0x80133B08: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80133B0C: addiu       $t8, $t8, 0x718
    ctx->r24 = ADD32(ctx->r24, 0X718);
    // 0x80133B10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133B14: jal         0x800CCFDC
    // 0x80133B18: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133B18: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80133B1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133B20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133B24: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133B28: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80133B2C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80133B30: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80133B34: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133B3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133B40: jr          $ra
    // 0x80133B44: nop

    return;
    // 0x80133B44: nop

;}
RECOMP_FUNC void mnVSResultsAudioThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801377C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801377C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801377C8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x801377CC: addiu       $s0, $s0, -0x26A0
    ctx->r16 = ADD32(ctx->r16, -0X26A0);
    // 0x801377D0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801377D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801377D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801377DC: lw          $v0, 0x34($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X34);
    // 0x801377E0: bne         $v0, $zero, L_80137800
    if (ctx->r2 != 0) {
        // 0x801377E4: nop
    
            goto L_80137800;
    }
    // 0x801377E4: nop

L_801377E8:
    // 0x801377E8: jal         0x8000B1E8
    // 0x801377EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x801377EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801377F0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801377F4: lw          $v0, 0x34($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X34);
    // 0x801377F8: beq         $v0, $zero, L_801377E8
    if (ctx->r2 == 0) {
        // 0x801377FC: nop
    
            goto L_801377E8;
    }
    // 0x801377FC: nop

L_80137800:
    // 0x80137800: bne         $v0, $zero, L_80137818
    if (ctx->r2 != 0) {
        // 0x80137804: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80137818;
    }
    // 0x80137804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137808: jal         0x80020AB4
    // 0x8013780C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    syAudioPlayBGM(rdram, ctx);
        goto after_1;
    // 0x8013780C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_1:
    // 0x80137810: jal         0x80009A84
    // 0x80137814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80137814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_80137818:
    // 0x80137818: jal         0x8000B1E8
    // 0x8013781C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x8013781C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80137820: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80137824: lw          $t8, -0x26A0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26A0);
    // 0x80137828: b           L_80137800
    // 0x8013782C: lw          $v0, 0x34($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X34);
        goto L_80137800;
    // 0x8013782C: lw          $v0, 0x34($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X34);
    // 0x80137830: nop

    // 0x80137834: nop

    // 0x80137838: nop

    // 0x8013783C: nop

    // 0x80137840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80137844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013784C: jr          $ra
    // 0x80137850: nop

    return;
    // 0x80137850: nop

;}
RECOMP_FUNC void itNBumperThrownProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B780: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B784: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B788: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8017B78C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017B790: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x8017B794: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x8017B798: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8017B79C: nop

    // 0x8017B7A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017B7A4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017B7A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8017B7AC: nop

    // 0x8017B7B0: bc1f        L_8017B7C0
    if (!c1cs) {
        // 0x8017B7B4: nop
    
            goto L_8017B7C0;
    }
    // 0x8017B7B4: nop

    // 0x8017B7B8: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8017B7BC: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
L_8017B7C0:
    // 0x8017B7C0: jal         0x8017279C
    // 0x8017B7C4: nop

    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x8017B7C4: nop

    after_0:
    // 0x8017B7C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B7CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B7D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B7D4: jr          $ra
    // 0x8017B7D8: nop

    return;
    // 0x8017B7D8: nop

;}
RECOMP_FUNC void ftCommonPassCheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141E60: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x80141E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80141E68: slti        $at, $t6, -0x34
    ctx->r1 = SIGNED(ctx->r14) < -0X34 ? 1 : 0;
    // 0x80141E6C: beq         $at, $zero, L_80141E9C
    if (ctx->r1 == 0) {
        // 0x80141E70: nop
    
            goto L_80141E9C;
    }
    // 0x80141E70: nop

    // 0x80141E74: lbu         $t7, 0x269($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X269);
    // 0x80141E78: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80141E7C: beq         $at, $zero, L_80141E9C
    if (ctx->r1 == 0) {
        // 0x80141E80: nop
    
            goto L_80141E9C;
    }
    // 0x80141E80: nop

    // 0x80141E84: lw          $t8, 0xF4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XF4);
    // 0x80141E88: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80141E8C: beq         $t9, $zero, L_80141E9C
    if (ctx->r25 == 0) {
        // 0x80141E90: nop
    
            goto L_80141E9C;
    }
    // 0x80141E90: nop

    // 0x80141E94: jr          $ra
    // 0x80141E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80141E98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141E9C:
    // 0x80141E9C: jr          $ra
    // 0x80141EA0: nop

    return;
    // 0x80141EA0: nop

;}
RECOMP_FUNC void func_ovl8_8037D45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D45C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037D460: addiu       $v0, $v0, -0x1020
    ctx->r2 = ADD32(ctx->r2, -0X1020);
    // 0x8037D464: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8037D468: jr          $ra
    // 0x8037D46C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x8037D46C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void sc1PStageClearUpdateBonusScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133F08: jal         0x801323F8
    // 0x80133F0C: nop

    sc1PStageClearMakeScoreSObjs(rdram, ctx);
        goto after_0;
    // 0x80133F0C: nop

    after_0:
    // 0x80133F10: jal         0x800269C0
    // 0x80133F14: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80133F14: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_1:
    // 0x80133F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133F20: jr          $ra
    // 0x80133F24: nop

    return;
    // 0x80133F24: nop

;}
RECOMP_FUNC void ftPublicMakeActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801653E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801653E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801653E8: addiu       $a0, $zero, 0x3FA
    ctx->r4 = ADD32(0, 0X3FA);
    // 0x801653EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801653F0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x801653F4: jal         0x80009968
    // 0x801653F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801653F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801653FC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80165400: addiu       $a1, $a1, 0x5134
    ctx->r5 = ADD32(ctx->r5, 0X5134);
    // 0x80165404: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80165408: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016540C: jal         0x80008188
    // 0x80165410: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80165410: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80165414: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80165418: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016541C: sw          $t6, -0x3070($at)
    MEM_W(-0X3070, ctx->r1) = ctx->r14;
    // 0x80165420: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80165424: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165428: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8016542C: sw          $t7, -0x306C($at)
    MEM_W(-0X306C, ctx->r1) = ctx->r15;
    // 0x80165430: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165434: swc1        $f4, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = ctx->f4.u32l;
    // 0x80165438: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016543C: sw          $zero, -0x3064($at)
    MEM_W(-0X3064, ctx->r1) = 0;
    // 0x80165440: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165444: sh          $zero, -0x3060($at)
    MEM_H(-0X3060, ctx->r1) = 0;
    // 0x80165448: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016544C: sw          $zero, -0x305C($at)
    MEM_W(-0X305C, ctx->r1) = 0;
    // 0x80165450: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165454: addiu       $t8, $zero, 0x4B0
    ctx->r24 = ADD32(0, 0X4B0);
    // 0x80165458: sw          $t8, -0x3058($at)
    MEM_W(-0X3058, ctx->r1) = ctx->r24;
    // 0x8016545C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165460: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80165464: sw          $t9, -0x3054($at)
    MEM_W(-0X3054, ctx->r1) = ctx->r25;
    // 0x80165468: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016546C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80165470: sw          $t0, -0x3048($at)
    MEM_W(-0X3048, ctx->r1) = ctx->r8;
    // 0x80165474: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165478: sw          $zero, -0x3040($at)
    MEM_W(-0X3040, ctx->r1) = 0;
    // 0x8016547C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165480: sw          $zero, -0x301C($at)
    MEM_W(-0X301C, ctx->r1) = 0;
    // 0x80165484: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016548C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80165490: sh          $zero, -0x3018($at)
    MEM_H(-0X3018, ctx->r1) = 0;
    // 0x80165494: addiu       $v1, $v1, -0x3020
    ctx->r3 = ADD32(ctx->r3, -0X3020);
    // 0x80165498: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8016549C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801654A0: sw          $zero, -0x3024($at)
    MEM_W(-0X3024, ctx->r1) = 0;
    // 0x801654A4: jr          $ra
    // 0x801654A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801654A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftBossWalkLoopCheckPlayerInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801598C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801598C4: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801598C8: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x801598CC: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x801598D0: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801598D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801598D8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801598DC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801598E0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x801598E4: lw          $a1, 0x74($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X74);
    // 0x801598E8: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801598EC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x801598F0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801598F4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801598F8: nop

    // 0x801598FC: bc1fl       L_8015995C
    if (!c1cs) {
        // 0x80159900: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015995C;
    }
    goto skip_0;
    // 0x80159900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80159904: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80159908: nop

    // 0x8015990C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80159910: nop

    // 0x80159914: bc1fl       L_8015995C
    if (!c1cs) {
        // 0x80159918: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015995C;
    }
    goto skip_1;
    // 0x80159918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8015991C: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80159920: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80159924: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80159928: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8015992C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80159930: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80159934: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80159938: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8015993C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80159940: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80159944: nop

    // 0x80159948: bc1fl       L_8015995C
    if (!c1cs) {
        // 0x8015994C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015995C;
    }
    goto skip_2;
    // 0x8015994C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80159950: jr          $ra
    // 0x80159954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80159954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80159958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015995C:
    // 0x8015995C: jr          $ra
    // 0x80159960: nop

    return;
    // 0x80159960: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801327BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801327C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801327C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801327CC: jal         0x80009968
    // 0x801327D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801327D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801327D4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801327D8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801327DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801327E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801327E4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801327E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801327F0: jal         0x80009DF4
    // 0x801327F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801327F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801327F8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801327FC: lw          $t7, 0x6D8C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D8C);
    // 0x80132800: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132804: addiu       $t8, $t8, 0xB40
    ctx->r24 = ADD32(ctx->r24, 0XB40);
    // 0x80132808: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013280C: jal         0x800CCFDC
    // 0x80132810: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132810: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132814: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132818: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8013281C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132820: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80132824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132828: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013282C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132830: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132834: addiu       $t3, $zero, 0x5F
    ctx->r11 = ADD32(0, 0X5F);
    // 0x80132838: addiu       $t4, $zero, 0x58
    ctx->r12 = ADD32(0, 0X58);
    // 0x8013283C: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80132840: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132844: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132848: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x8013284C: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132850: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132854: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132858: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013285C: lw          $t6, 0x6D88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D88);
    // 0x80132860: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132864: addiu       $t7, $t7, 0x5428
    ctx->r15 = ADD32(ctx->r15, 0X5428);
    // 0x80132868: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013286C: jal         0x800CCFDC
    // 0x80132870: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132870: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80132874: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132878: lui         $at, 0x42C6
    ctx->r1 = S32(0X42C6 << 16);
    // 0x8013287C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132880: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80132884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132888: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x8013288C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132890: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132894: addiu       $t2, $zero, 0xF2
    ctx->r10 = ADD32(0, 0XF2);
    // 0x80132898: addiu       $t3, $zero, 0xC7
    ctx->r11 = ADD32(0, 0XC7);
    // 0x8013289C: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x801328A0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801328A4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801328A8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801328AC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801328B0: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801328B4: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801328B8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x801328BC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801328C0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801328C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801328C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801328CC: jr          $ra
    // 0x801328D0: nop

    return;
    // 0x801328D0: nop

;}
RECOMP_FUNC void ftBossOkupunch1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A7C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015A7C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A7CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015A7D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A7D4: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x8015A7D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A7DC: jal         0x800E6F24
    // 0x8015A7E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A7E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A7E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8015A7E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8015A7EC: lw          $a2, 0x84($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X84);
    // 0x8015A7F0: lw          $a0, 0xADC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XADC);
    // 0x8015A7F4: addiu       $a1, $a2, 0xB18
    ctx->r5 = ADD32(ctx->r6, 0XB18);
    // 0x8015A7F8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8015A7FC: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x8015A800: lw          $v1, 0xEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XEC);
    // 0x8015A804: beq         $v1, $at, L_8015A81C
    if (ctx->r3 == ctx->r1) {
        // 0x8015A808: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8015A81C;
    }
    // 0x8015A808: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8015A80C: beql        $v1, $at, L_8015A820
    if (ctx->r3 == ctx->r1) {
        // 0x8015A810: lw          $a3, 0x8($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X8);
            goto L_8015A820;
    }
    goto skip_0;
    // 0x8015A810: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8015A814: b           L_8015A820
    // 0x8015A818: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8015A820;
    // 0x8015A818: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8015A81C:
    // 0x8015A81C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
L_8015A820:
    // 0x8015A820: jal         0x8015839C
    // 0x8015A824: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftBossCommonGetPositionCenter(rdram, ctx);
        goto after_1;
    // 0x8015A824: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8015A828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A82C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015A830: jr          $ra
    // 0x8015A834: nop

    return;
    // 0x8015A834: nop

;}
RECOMP_FUNC void grYamabukiGateCheckPlayersNear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AD18: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8010AD1C: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x8010AD20: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8010AD24: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8010AD28: beq         $v0, $zero, L_8010AD64
    if (ctx->r2 == 0) {
        // 0x8010AD2C: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8010AD64;
    }
    // 0x8010AD2C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8010AD30: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_8010AD34:
    // 0x8010AD34: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8010AD38: bnel        $t6, $zero, L_8010AD5C
    if (ctx->r14 != 0) {
        // 0x8010AD3C: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8010AD5C;
    }
    goto skip_0;
    // 0x8010AD3C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8010AD40: lw          $t7, 0xF4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XF4);
    // 0x8010AD44: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x8010AD48: bnel        $a0, $t8, L_8010AD5C
    if (ctx->r4 != ctx->r24) {
        // 0x8010AD4C: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8010AD5C;
    }
    goto skip_1;
    // 0x8010AD4C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8010AD50: jr          $ra
    // 0x8010AD54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8010AD54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010AD58: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_8010AD5C:
    // 0x8010AD5C: bnel        $v0, $zero, L_8010AD34
    if (ctx->r2 != 0) {
        // 0x8010AD60: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_8010AD34;
    }
    goto skip_2;
    // 0x8010AD60: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_2:
L_8010AD64:
    // 0x8010AD64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010AD68: jr          $ra
    // 0x8010AD6C: nop

    return;
    // 0x8010AD6C: nop

;}
RECOMP_FUNC void gcDrawDObjDLHead2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013EB8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80013EBC: jal         0x80013D90
    // 0x80013EC0: addiu       $a1, $a1, 0x65B8
    ctx->r5 = ADD32(ctx->r5, 0X65B8);
    gcDrawDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80013EC0: addiu       $a1, $a1, 0x65B8
    ctx->r5 = ADD32(ctx->r5, 0X65B8);
    after_0:
    // 0x80013EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013ECC: jr          $ra
    // 0x80013ED0: nop

    return;
    // 0x80013ED0: nop

;}
RECOMP_FUNC void mnSoundTestFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013224C: jal         0x80131B00
    // 0x80132250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnSoundTestUpdateOptionColors(rdram, ctx);
        goto after_0;
    // 0x80132250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132254: jal         0x8039076C
    // 0x80132258: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_1;
    // 0x80132258: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x8013225C: beq         $v0, $zero, L_80132298
    if (ctx->r2 == 0) {
        // 0x80132260: addiu       $t7, $zero, 0x3A
        ctx->r15 = ADD32(0, 0X3A);
            goto L_80132298;
    }
    // 0x80132260: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x80132264: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132268: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013226C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80132270: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80132274: jal         0x80020A74
    // 0x80132278: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x80132278: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_2:
    // 0x8013227C: jal         0x800266A0
    // 0x80132280: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_3;
    // 0x80132280: nop

    after_3:
    // 0x80132284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132288: jal         0x80020B38
    // 0x8013228C: addiu       $a1, $zero, 0x7000
    ctx->r5 = ADD32(0, 0X7000);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_4;
    // 0x8013228C: addiu       $a1, $zero, 0x7000
    ctx->r5 = ADD32(0, 0X7000);
    after_4:
    // 0x80132290: jal         0x80005C74
    // 0x80132294: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80132294: nop

    after_5:
L_80132298:
    // 0x80132298: jal         0x80131B80
    // 0x8013229C: nop

    mnSoundTestUpdateControllerInputs(rdram, ctx);
        goto after_6;
    // 0x8013229C: nop

    after_6:
    // 0x801322A0: jal         0x801320B4
    // 0x801322A4: nop

    mnSoundTestUpdateFunctions(rdram, ctx);
        goto after_7;
    // 0x801322A4: nop

    after_7:
    // 0x801322A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801322AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801322B0: jr          $ra
    // 0x801322B4: nop

    return;
    // 0x801322B4: nop

;}
RECOMP_FUNC void gcDrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A340: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A344: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000A348: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8000A34C: addiu       $s3, $s3, 0x6A58
    ctx->r19 = ADD32(ctx->r19, 0X6A58);
    // 0x8000A350: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8000A354: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000A358: lw          $v1, -0x4918($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4918);
    // 0x8000A35C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A360: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000A364: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A368: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A36C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000A370: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000A374: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000A378: sw          $zero, 0x6A5C($at)
    MEM_W(0X6A5C, ctx->r1) = 0;
    // 0x8000A37C: addiu       $a0, $a0, 0x6F88
    ctx->r4 = ADD32(ctx->r4, 0X6F88);
    // 0x8000A380: addiu       $v0, $v0, 0x6A88
    ctx->r2 = ADD32(ctx->r2, 0X6A88);
    // 0x8000A384: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_8000A388:
    // 0x8000A388: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8000A38C: sb          $v1, -0x3C($v0)
    MEM_B(-0X3C, ctx->r2) = ctx->r3;
    // 0x8000A390: sb          $v1, -0x28($v0)
    MEM_B(-0X28, ctx->r2) = ctx->r3;
    // 0x8000A394: sb          $v1, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = ctx->r3;
    // 0x8000A398: bne         $v0, $a0, L_8000A388
    if (ctx->r2 != ctx->r4) {
        // 0x8000A39C: sb          $v1, -0x50($v0)
        MEM_B(-0X50, ctx->r2) = ctx->r3;
            goto L_8000A388;
    }
    // 0x8000A39C: sb          $v1, -0x50($v0)
    MEM_B(-0X50, ctx->r2) = ctx->r3;
    // 0x8000A3A0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8000A3A4: lw          $s0, 0x6900($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6900);
    // 0x8000A3A8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000A3AC: addiu       $s1, $s1, -0x478C
    ctx->r17 = ADD32(ctx->r17, -0X478C);
    // 0x8000A3B0: beq         $s0, $zero, L_8000A3F0
    if (ctx->r16 == 0) {
        // 0x8000A3B4: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_8000A3F0;
    }
    // 0x8000A3B4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8000A3B8: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_8000A3BC:
    // 0x8000A3BC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000A3C0: bnel        $t7, $zero, L_8000A3E8
    if (ctx->r15 != 0) {
        // 0x8000A3C4: lw          $s0, 0x20($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X20);
            goto L_8000A3E8;
    }
    goto skip_0;
    // 0x8000A3C4: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x8000A3C8: sw          $s2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r18;
    // 0x8000A3CC: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x8000A3D0: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8000A3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000A3D8: jalr        $t9
    // 0x8000A3DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8000A3DC: nop

    after_0:
    // 0x8000A3E0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8000A3E4: lw          $s0, 0x20($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X20);
L_8000A3E8:
    // 0x8000A3E8: bnel        $s0, $zero, L_8000A3BC
    if (ctx->r16 != 0) {
        // 0x8000A3EC: lw          $t6, 0x7C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7C);
            goto L_8000A3BC;
    }
    goto skip_1;
    // 0x8000A3EC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    skip_1:
L_8000A3F0:
    // 0x8000A3F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A3F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000A3F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000A3FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A400: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000A404: jr          $ra
    // 0x8000A408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000A408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mpCollisionSetPlayBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC3E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC3EC: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x800FC3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC3F8: lw          $a1, 0x7C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X7C);
    // 0x800FC3FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FC400: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, 0X13A0);
    // 0x800FC404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FC408: jal         0x80020AB4
    // 0x800FC40C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    syAudioPlayBGM(rdram, ctx);
        goto after_0;
    // 0x800FC40C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_0:
    // 0x800FC410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC414: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FC418: lw          $t8, 0x13A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X13A0);
    // 0x800FC41C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC424: jr          $ra
    // 0x800FC428: sw          $t8, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r24;
    return;
    // 0x800FC428: sw          $t8, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void mvOpeningStandoffMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131FCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FD8: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131FDC: jal         0x80009968
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FE8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FEC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131FF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FF4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131FF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FFC: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132000: jal         0x80009DF4
    // 0x80132004: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132004: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132008: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013200C: addiu       $a1, $a1, 0x1D38
    ctx->r5 = ADD32(ctx->r5, 0X1D38);
    // 0x80132010: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132018: jal         0x80008188
    // 0x8013201C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8013201C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132020: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132024: lw          $t7, 0x2B9C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2B9C);
    // 0x80132028: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8013202C: addiu       $v1, $v1, -0x4B00
    ctx->r3 = ADD32(ctx->r3, -0X4B00);
    // 0x80132030: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80132034: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132038: jal         0x800CCFDC
    // 0x8013203C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013203C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_3:
    // 0x80132040: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80132044: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132048: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013204C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80132050: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132054: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132058: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8013205C: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80132060: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132064: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80132068: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x8013206C: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80132070: lw          $t0, 0x2B9C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2B9C);
    // 0x80132074: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132078: jal         0x800CCFDC
    // 0x8013207C: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013207C: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    after_4:
    // 0x80132080: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132088: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x8013208C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80132090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132094: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80132098: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x8013209C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801320A0: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801320A4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801320A8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801320AC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801320B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801320B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801320B8: jr          $ra
    // 0x801320BC: nop

    return;
    // 0x801320BC: nop

;}
RECOMP_FUNC void itBatDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017507C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175084: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    // 0x80175088: jal         0x80172EC8
    // 0x8017508C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017508C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80175090: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80175094: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80175098: lwc1        $f4, -0x332C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X332C);
    // 0x8017509C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x801750A0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801750A4: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x801750A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801750AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801750B0: jr          $ra
    // 0x801750B4: nop

    return;
    // 0x801750B4: nop

;}
RECOMP_FUNC void syDebugFramebufferPrintFCSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002287C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022884: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80022888: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8002288C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022890: addiu       $a2, $a2, -0x19C4
    ctx->r6 = ADD32(ctx->r6, -0X19C4);
    // 0x80022894: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80022898: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8002289C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800228A0: jal         0x80022664
    // 0x800228A4: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_0;
    // 0x800228A4: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    after_0:
    // 0x800228A8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800228AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800228B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800228B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800228B8:
    // 0x800228B8: and         $t6, $a3, $v1
    ctx->r14 = ctx->r7 & ctx->r3;
    // 0x800228BC: beq         $t6, $zero, L_800228EC
    if (ctx->r14 == 0) {
        // 0x800228C0: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800228EC;
    }
    // 0x800228C0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800228C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800228C8: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800228CC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800228D0: addiu       $a2, $a2, -0x19B8
    ctx->r6 = ADD32(ctx->r6, -0X19B8);
    // 0x800228D4: lw          $a3, -0x2FBC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2FBC);
    // 0x800228D8: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    // 0x800228DC: jal         0x80022664
    // 0x800228E0: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_1;
    // 0x800228E0: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    after_1:
    // 0x800228E4: b           L_800228FC
    // 0x800228E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800228FC;
    // 0x800228E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800228EC:
    // 0x800228EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800228F0: bne         $v0, $a0, L_800228B8
    if (ctx->r2 != ctx->r4) {
        // 0x800228F4: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_800228B8;
    }
    // 0x800228F4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x800228F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800228FC:
    // 0x800228FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022900: jr          $ra
    // 0x80022904: nop

    return;
    // 0x80022904: nop

;}
RECOMP_FUNC void func_ovl8_8037EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EB00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037EB04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037EB08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037EB0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037EB10: beq         $a0, $zero, L_8037EBB4
    if (ctx->r4 == 0) {
        // 0x8037EB14: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037EBB4;
    }
    // 0x8037EB14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037EB18: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037EB1C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037EB20: addiu       $t6, $t6, -0x5760
    ctx->r14 = ADD32(ctx->r14, -0X5760);
    // 0x8037EB24: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037EB28: addiu       $t7, $t7, -0x5680
    ctx->r15 = ADD32(ctx->r15, -0X5680);
    // 0x8037EB2C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037EB30: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037EB34: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037EB38: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037EB3C: addiu       $t9, $t9, -0x5528
    ctx->r25 = ADD32(ctx->r25, -0X5528);
    // 0x8037EB40: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037EB44: addiu       $t1, $t1, -0x5500
    ctx->r9 = ADD32(ctx->r9, -0X5500);
    // 0x8037EB48: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037EB4C: sw          $t1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r9;
    // 0x8037EB50: lw          $a0, 0xB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XB0);
    // 0x8037EB54: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8037EB58: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
    // 0x8037EB5C: beq         $a0, $zero, L_8037EB6C
    if (ctx->r4 == 0) {
        // 0x8037EB60: sw          $zero, 0xB4($s0)
        MEM_W(0XB4, ctx->r16) = 0;
            goto L_8037EB6C;
    }
    // 0x8037EB60: sw          $zero, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = 0;
    // 0x8037EB64: jal         0x8037B3E4
    // 0x8037EB68: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x8037EB68: nop

    after_0:
L_8037EB6C:
    // 0x8037EB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EB70: jal         0x8037C92C
    // 0x8037EB74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037C92C(rdram, ctx);
        goto after_1;
    // 0x8037EB74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8037EB78: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8037EB7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EB80: beql        $t2, $zero, L_8037EBA0
    if (ctx->r10 == 0) {
        // 0x8037EB84: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8037EBA0;
    }
    goto skip_0;
    // 0x8037EB84: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037EB88: jal         0x8037C30C
    // 0x8037EB8C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x8037EB8C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x8037EB90: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037EB94: jal         0x803718C4
    // 0x8037EB98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x8037EB98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8037EB9C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8037EBA0:
    // 0x8037EBA0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8037EBA4: beql        $t4, $zero, L_8037EBB8
    if (ctx->r12 == 0) {
        // 0x8037EBA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037EBB8;
    }
    goto skip_1;
    // 0x8037EBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037EBAC: jal         0x803717C0
    // 0x8037EBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x8037EBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8037EBB4:
    // 0x8037EBB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037EBB8:
    // 0x8037EBB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037EBBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037EBC0: jr          $ra
    // 0x8037EBC4: nop

    return;
    // 0x8037EBC4: nop

;}
RECOMP_FUNC void func_ovl8_8037C30C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C30C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C310: beq         $a0, $zero, L_8037C334
    if (ctx->r4 == 0) {
        // 0x8037C314: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8037C334;
    }
    // 0x8037C314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C318: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C31C: addiu       $t6, $t6, -0x5E90
    ctx->r14 = ADD32(ctx->r14, -0X5E90);
    // 0x8037C320: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8037C324: beq         $t7, $zero, L_8037C334
    if (ctx->r15 == 0) {
        // 0x8037C328: sw          $t6, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r14;
            goto L_8037C334;
    }
    // 0x8037C328: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8037C32C: jal         0x803717C0
    // 0x8037C330: nop

    func_ovl8_803717C0(rdram, ctx);
        goto after_0;
    // 0x8037C330: nop

    after_0:
L_8037C334:
    // 0x8037C334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C33C: jr          $ra
    // 0x8037C340: nop

    return;
    // 0x8037C340: nop

;}
RECOMP_FUNC void mnDataMakeOptionsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801325D8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801325DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801325E0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801325E4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801325E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801325EC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801325F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801325F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801325F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801325FC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132600: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132604: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132608: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013260C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132610: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132614: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132618: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013261C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132620: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013262C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132630: jal         0x8000B93C
    // 0x80132634: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132634: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132638: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013263C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132640: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132644: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132648: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013264C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132650: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132654: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132658: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013265C: jal         0x80007080
    // 0x80132660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132664: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132668: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013266C: jr          $ra
    // 0x80132670: nop

    return;
    // 0x80132670: nop

;}
RECOMP_FUNC void ftCommonSquatProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142EE0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80142EE4: jal         0x800D9480
    // 0x80142EE8: addiu       $a1, $a1, 0x329C
    ctx->r5 = ADD32(ctx->r5, 0X329C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80142EE8: addiu       $a1, $a1, 0x329C
    ctx->r5 = ADD32(ctx->r5, 0X329C);
    after_0:
    // 0x80142EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142EF4: jr          $ra
    // 0x80142EF8: nop

    return;
    // 0x80142EF8: nop

;}
RECOMP_FUNC void sc1PIntroMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C98: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80132C9C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80132CA0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80132CA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80132CA8: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x80132CAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132CB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80132CB4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80132CB8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80132CBC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80132CC0: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x80132CC4: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_80132CC8:
    // 0x80132CC8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132CCC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132CD0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132CD4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132CD8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132CDC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132CE0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132CE4: bne         $t6, $t0, L_80132CC8
    if (ctx->r14 != ctx->r8) {
        // 0x80132CE8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132CC8;
    }
    // 0x80132CE8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132CEC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132CF0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132CF4: addiu       $t2, $t2, 0x4FC0
    ctx->r10 = ADD32(ctx->r10, 0X4FC0);
    // 0x80132CF8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80132CFC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80132D00: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132D04: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80132D08: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80132D0C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80132D10: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80132D14: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80132D18: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80132D1C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80132D20: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80132D24: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80132D28: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80132D2C: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    // 0x80132D30: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80132D34: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80132D38: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80132D3C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80132D40: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80132D44: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x80132D48: sb          $t6, 0x50($sp)
    MEM_B(0X50, ctx->r29) = ctx->r14;
    // 0x80132D4C: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80132D50: sb          $zero, 0x4D($sp)
    MEM_B(0X4D, ctx->r29) = 0;
    // 0x80132D54: jal         0x800D7F3C
    // 0x80132D58: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    ftManagerMakeFighter(rdram, ctx);
        goto after_0;
    // 0x80132D58: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    after_0:
    // 0x80132D5C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80132D60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132D64: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x80132D68: jal         0x803905CC
    // 0x80132D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x80132D6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80132D70: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80132D74: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80132D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D7C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80132D80: addu        $a1, $sp, $t8
    ctx->r5 = ADD32(ctx->r29, ctx->r24);
    // 0x80132D84: sw          $v1, 0x178($v0)
    MEM_W(0X178, ctx->r2) = ctx->r3;
    // 0x80132D88: lbu         $a1, 0x23($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X23);
    // 0x80132D8C: jal         0x8000A0D0
    // 0x80132D90: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x80132D90: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    after_2:
    // 0x80132D94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D98: addiu       $a1, $a1, 0x2BD4
    ctx->r5 = ADD32(ctx->r5, 0X2BD4);
    // 0x80132D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132DA4: jal         0x80008188
    // 0x80132DA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80132DA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80132DAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132DB0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80132DB4: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80132DB8: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80132DBC: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x80132DC0: jal         0x80132C44
    // 0x80132DC4: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    sc1PIntroGetFighterPositionZ(rdram, ctx);
        goto after_4;
    // 0x80132DC4: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_4:
    // 0x80132DC8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80132DCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132DD0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132DD4: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    // 0x80132DD8: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80132DDC: swc1        $f2, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f2.u32l;
    // 0x80132DE0: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80132DE4: swc1        $f2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f2.u32l;
    // 0x80132DE8: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80132DEC: swc1        $f2, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f2.u32l;
    // 0x80132DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132DF8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80132DFC: jr          $ra
    // 0x80132E00: nop

    return;
    // 0x80132E00: nop

;}
RECOMP_FUNC void mnDataMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801322AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801322B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801322BC: jal         0x80009968
    // 0x801322C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801322C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801322C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801322C8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801322CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801322D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801322D4: addiu       $a1, $a1, 0x2164
    ctx->r5 = ADD32(ctx->r5, 0X2164);
    // 0x801322D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801322E0: jal         0x80009DF4
    // 0x801322E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801322E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801322E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801322EC: lw          $t7, 0x3160($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3160);
    // 0x801322F0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801322F4: addiu       $t8, $t8, 0x31F8
    ctx->r24 = ADD32(ctx->r24, 0X31F8);
    // 0x801322F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801322FC: jal         0x800CCFDC
    // 0x80132300: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132300: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132304: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132308: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x8013230C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132310: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x80132314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132318: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013231C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132320: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132324: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132328: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x8013232C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132330: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132334: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132338: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013233C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132340: lw          $t3, 0x3164($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3164);
    // 0x80132344: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132348: addiu       $t4, $t4, 0x23A8
    ctx->r12 = ADD32(ctx->r12, 0X23A8);
    // 0x8013234C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132350: jal         0x800CCFDC
    // 0x80132354: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132354: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80132358: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8013235C: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x80132360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132364: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x80132368: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013236C: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80132370: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132374: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80132378: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x8013237C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132380: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132384: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132388: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013238C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132394: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132398: jr          $ra
    // 0x8013239C: nop

    return;
    // 0x8013239C: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakeCaptain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131D2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131D30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D3C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131D40: jal         0x80009968
    // 0x80131D44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131D4C: jal         0x80131B58
    // 0x80131D50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    mvOpeningNewcomersCheckLocked(rdram, ctx);
        goto after_1;
    // 0x80131D50: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x80131D54: beq         $v0, $zero, L_80131D80
    if (ctx->r2 == 0) {
        // 0x80131D58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80131D80;
    }
    // 0x80131D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D5C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D60: lw          $t6, 0x2914($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2914);
    // 0x80131D64: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x80131D68: addiu       $t7, $t7, 0x55C0
    ctx->r15 = ADD32(ctx->r15, 0X55C0);
    // 0x80131D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D70: jal         0x800092D0
    // 0x80131D74: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131D74: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80131D78: b           L_80131D9C
    // 0x80131D7C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80131D9C;
    // 0x80131D7C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131D80:
    // 0x80131D80: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131D84: lw          $t8, 0x2914($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2914);
    // 0x80131D88: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80131D8C: addiu       $t9, $t9, -0x3DC8
    ctx->r25 = ADD32(ctx->r25, -0X3DC8);
    // 0x80131D90: jal         0x800092D0
    // 0x80131D94: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131D94: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80131D98: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131D9C:
    // 0x80131D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131DA0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131DA4: jal         0x80008CC0
    // 0x80131DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80131DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80131DAC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131DB0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131DB4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80131DB8: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80131DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DC0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131DC4: jal         0x80009DF4
    // 0x80131DC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x80131DC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131DCC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131DD0: lw          $t1, 0x2914($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2914);
    // 0x80131DD4: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80131DD8: addiu       $t2, $t2, -0x362C
    ctx->r10 = ADD32(ctx->r10, -0X362C);
    // 0x80131DDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131DE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131DE4: jal         0x8000BD1C
    // 0x80131DE8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_6;
    // 0x80131DE8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80131DEC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131DF0: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131DFC: jal         0x80008188
    // 0x80131E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131E08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131E0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131E10: jr          $ra
    // 0x80131E14: nop

    return;
    // 0x80131E14: nop

;}
RECOMP_FUNC void mnVSOptionsMakeHandicapToggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801322BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801322C0: lw          $t6, 0x49D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X49D8);
    // 0x801322C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801322C8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801322CC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x801322D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801322D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801322D8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801322DC: addiu       $t7, $t7, -0x47E8
    ctx->r15 = ADD32(ctx->r15, -0X47E8);
    // 0x801322E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801322E4: jal         0x800CCFDC
    // 0x801322E8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x801322E8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x801322EC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801322F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801322F4: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x801322F8: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801322FC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132300: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132304: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132308: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8013230C: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132310: addiu       $t3, $t3, -0x20B8
    ctx->r11 = ADD32(ctx->r11, -0X20B8);
    // 0x80132314: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132318: lw          $t2, 0x49D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X49D8);
    // 0x8013231C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132320: jal         0x800CCFDC
    // 0x80132324: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132324: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80132328: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x8013232C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80132330: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132334: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80132338: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013233C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80132340: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132344: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80132348: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8013234C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132350: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80132354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132358: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013235C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132360: add.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80132364: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80132368: addiu       $t9, $t9, -0x46A8
    ctx->r25 = ADD32(ctx->r25, -0X46A8);
    // 0x8013236C: add.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80132370: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132378: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x8013237C: lw          $t8, 0x49D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X49D8);
    // 0x80132380: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80132384: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80132388: jal         0x800CCFDC
    // 0x8013238C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013238C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80132390: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80132394: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80132398: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013239C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801323A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801323A4: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801323A8: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801323AC: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801323B0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801323B4: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x801323B8: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x801323BC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801323C0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801323C4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801323C8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801323CC: lw          $t4, 0x49D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49D8);
    // 0x801323D0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x801323D4: addiu       $a2, $a2, -0x45D8
    ctx->r6 = ADD32(ctx->r6, -0X45D8);
    // 0x801323D8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801323DC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x801323E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323E4: jal         0x800CCFDC
    // 0x801323E8: addu        $a1, $t4, $a2
    ctx->r5 = ADD32(ctx->r12, ctx->r6);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801323E8: addu        $a1, $t4, $a2
    ctx->r5 = ADD32(ctx->r12, ctx->r6);
    after_3:
    // 0x801323EC: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x801323F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801323F4: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x801323F8: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x801323FC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132400: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80132404: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132408: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8013240C: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132410: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132414: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132418: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x8013241C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132420: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80132424: lw          $t9, 0x49D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X49D8);
    // 0x80132428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013242C: jal         0x800CCFDC
    // 0x80132430: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132430: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    after_4:
    // 0x80132434: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132438: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x8013243C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132440: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132444: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132448: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013244C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80132450: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132454: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132458: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013245C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132460: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013246C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132470: jr          $ra
    // 0x80132474: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80132474: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itTaruBombFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184EDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80184EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80184EE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80184EE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80184EEC: jal         0x80184E78
    // 0x80184EF0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itTaruBombFallCheckCollideGround(rdram, ctx);
        goto after_0;
    // 0x80184EF0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80184EF4: beql        $v0, $zero, L_80184F98
    if (ctx->r2 == 0) {
        // 0x80184EF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80184F98;
    }
    goto skip_0;
    // 0x80184EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80184EFC: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x80184F00: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80184F04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80184F08: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80184F0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80184F10: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80184F14: nop

    // 0x80184F18: bc1fl       L_80184F34
    if (!c1cs) {
        // 0x80184F1C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80184F34;
    }
    goto skip_1;
    // 0x80184F1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80184F20: jal         0x80184DC4
    // 0x80184F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itTaruBombCommonProcHit(rdram, ctx);
        goto after_1;
    // 0x80184F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80184F28: b           L_80184F98
    // 0x80184F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80184F98;
    // 0x80184F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80184F30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80184F34:
    // 0x80184F34: addiu       $a0, $v1, 0x2C
    ctx->r4 = ADD32(ctx->r3, 0X2C);
    // 0x80184F38: addiu       $a1, $v1, 0xB8
    ctx->r5 = ADD32(ctx->r3, 0XB8);
    // 0x80184F3C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80184F40: nop

    // 0x80184F44: bc1f        L_80184F5C
    if (!c1cs) {
        // 0x80184F48: nop
    
            goto L_80184F5C;
    }
    // 0x80184F48: nop

    // 0x80184F4C: jal         0x80184E44
    // 0x80184F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itTaruBombRollSetStatus(rdram, ctx);
        goto after_2;
    // 0x80184F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80184F54: b           L_80184F84
    // 0x80184F58: nop

        goto L_80184F84;
    // 0x80184F58: nop

L_80184F5C:
    // 0x80184F5C: jal         0x800C7B08
    // 0x80184F60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x80184F60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80184F64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80184F68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184F6C: lwc1        $f10, -0x30B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30B8);
    // 0x80184F70: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80184F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80184F78: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80184F7C: jal         0x80172508
    // 0x80184F80: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_4;
    // 0x80184F80: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    after_4:
L_80184F84:
    // 0x80184F84: jal         0x800269C0
    // 0x80184F88: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80184F88: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_5:
    // 0x80184F8C: jal         0x8017279C
    // 0x80184F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_6;
    // 0x80184F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80184F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80184F98:
    // 0x80184F98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80184F9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80184FA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80184FA4: jr          $ra
    // 0x80184FA8: nop

    return;
    // 0x80184FA8: nop

;}
RECOMP_FUNC void ftParamPlayVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E80F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E80F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E80F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E80FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E8100: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800E8104: jal         0x800269C0
    // 0x800E8108: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x800E8108: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800E810C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E8110: beq         $v0, $zero, L_800E8124
    if (ctx->r2 == 0) {
        // 0x800E8114: sw          $v0, 0xA18($a2)
        MEM_W(0XA18, ctx->r6) = ctx->r2;
            goto L_800E8124;
    }
    // 0x800E8114: sw          $v0, 0xA18($a2)
    MEM_W(0XA18, ctx->r6) = ctx->r2;
    // 0x800E8118: lhu         $t7, 0x26($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X26);
    // 0x800E811C: b           L_800E8128
    // 0x800E8120: sh          $t7, 0xA1C($a2)
    MEM_H(0XA1C, ctx->r6) = ctx->r15;
        goto L_800E8128;
    // 0x800E8120: sh          $t7, 0xA1C($a2)
    MEM_H(0XA1C, ctx->r6) = ctx->r15;
L_800E8124:
    // 0x800E8124: sh          $zero, 0xA1C($a2)
    MEM_H(0XA1C, ctx->r6) = 0;
L_800E8128:
    // 0x800E8128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E812C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8130: jr          $ra
    // 0x800E8134: nop

    return;
    // 0x800E8134: nop

;}
RECOMP_FUNC void itLizardonFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F53C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F544: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017F548: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8017F54C: jal         0x80172558
    // 0x8017F550: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017F550: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x8017F554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F55C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F560: jr          $ra
    // 0x8017F564: nop

    return;
    // 0x8017F564: nop

;}
RECOMP_FUNC void lbParticleMakeGenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D35DC: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x800D35E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D35E4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800D35E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D35EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D35F0: bne         $at, $zero, L_800D3600
    if (ctx->r1 != 0) {
        // 0x800D35F4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800D3600;
    }
    // 0x800D35F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D35F8: b           L_800D3874
    // 0x800D35FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D35FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3600:
    // 0x800D3600: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800D3604: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D3608: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800D360C: lw          $t6, 0x63C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C0);
    // 0x800D3610: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D3614: bnel        $at, $zero, L_800D3628
    if (ctx->r1 != 0) {
        // 0x800D3618: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800D3628;
    }
    goto skip_0;
    // 0x800D3618: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x800D361C: b           L_800D3874
    // 0x800D3620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D3620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D3624: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_800D3628:
    // 0x800D3628: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D362C: jal         0x800D353C
    // 0x800D3630: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    lbParticleGetGenerator(rdram, ctx);
        goto after_0;
    // 0x800D3630: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D3634: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3638: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800D363C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800D3640: beq         $v0, $zero, L_800D3870
    if (ctx->r2 == 0) {
        // 0x800D3644: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_800D3870;
    }
    // 0x800D3644: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D3648: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D364C: addiu       $t7, $t7, 0x6400
    ctx->r15 = ADD32(ctx->r15, 0X6400);
    // 0x800D3650: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800D3654: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800D3658: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x800D365C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D3660: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800D3664: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800D3668: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800D366C: sb          $a2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r6;
    // 0x800D3670: sb          $t1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r9;
    // 0x800D3674: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800D3678: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800D367C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800D3680: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800D3684: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x800D3688: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D368C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800D3690: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D3694: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x800D3698: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x800D369C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D36A0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800D36A4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800D36A8: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x800D36AC: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x800D36B0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800D36B4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800D36B8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800D36BC: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800D36C0: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800D36C4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800D36C8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800D36CC: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x800D36D0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800D36D4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800D36D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800D36DC: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800D36E0: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x800D36E4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D36E8: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800D36EC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800D36F0: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800D36F4: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x800D36F8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800D36FC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800D3700: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800D3704: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800D3708: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x800D370C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800D3710: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800D3714: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D3718: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800D371C: swc1        $f10, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f10.u32l;
    // 0x800D3720: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D3724: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800D3728: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800D372C: lwc1        $f16, 0x10($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800D3730: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
    // 0x800D3734: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800D3738: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800D373C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800D3740: lwc1        $f18, 0x2C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x800D3744: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x800D3748: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D374C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800D3750: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D3754: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800D3758: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x800D375C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D3760: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D3764: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800D3768: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800D376C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800D3770: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800D3774: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800D3778: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800D377C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800D3780: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800D3784: lwc1        $f6, 0x24($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X24);
    // 0x800D3788: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800D378C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D3790: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800D3794: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D3798: lwc1        $f8, 0x28($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X28);
    // 0x800D379C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x800D37A0: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x800D37A4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D37A8: lw          $t9, 0x6420($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6420);
    // 0x800D37AC: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x800D37B0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800D37B4: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x800D37B8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800D37BC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800D37C0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800D37C4: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800D37C8: beql        $t7, $zero, L_800D37E0
    if (ctx->r15 == 0) {
        // 0x800D37CC: lbu         $t1, 0x8($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X8);
            goto L_800D37E0;
    }
    goto skip_1;
    // 0x800D37CC: lbu         $t1, 0x8($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X8);
    skip_1:
    // 0x800D37D0: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    // 0x800D37D4: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x800D37D8: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
    // 0x800D37DC: lbu         $t1, 0x8($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X8);
L_800D37E0:
    // 0x800D37E0: sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // 0x800D37E4: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x800D37E8: beq         $at, $zero, L_800D3858
    if (ctx->r1 == 0) {
        // 0x800D37EC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_800D3858;
    }
    // 0x800D37EC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D37F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D37F4: addu        $at, $at, $t1
    gpr jr_addend_800D37FC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800D37F8: lw          $t1, 0x6284($at)
    ctx->r9 = ADD32(ctx->r1, 0X6284);
    // 0x800D37FC: jr          $t1
    // 0x800D3800: nop

    switch (jr_addend_800D37FC >> 2) {
        case 0: goto L_800D3804; break;
        case 1: goto L_800D381C; break;
        case 2: goto L_800D3850; break;
        case 3: goto L_800D3804; break;
        case 4: goto L_800D3804; break;
        default: switch_error(__func__, 0x800D37FC, 0x800D6284);
    }
    // 0x800D3800: nop

L_800D3804:
    // 0x800D3804: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D3808: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D380C: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x800D3810: lwc1        $f16, 0x6298($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6298);
    // 0x800D3814: b           L_800D3870
    // 0x800D3818: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
        goto L_800D3870;
    // 0x800D3818: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
L_800D381C:
    // 0x800D381C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800D3820: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800D3824: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800D3828: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800D382C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800D3830: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800D3834: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800D3838: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D383C: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x800D3840: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800D3844: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
    // 0x800D3848: b           L_800D3870
    // 0x800D384C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_800D3870;
    // 0x800D384C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_800D3850:
    // 0x800D3850: b           L_800D3870
    // 0x800D3854: sh          $zero, 0x54($v0)
    MEM_H(0X54, ctx->r2) = 0;
        goto L_800D3870;
    // 0x800D3854: sh          $zero, 0x54($v0)
    MEM_H(0X54, ctx->r2) = 0;
L_800D3858:
    // 0x800D3858: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D385C: lw          $v0, 0x6444($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6444);
    // 0x800D3860: beql        $v0, $zero, L_800D3874
    if (ctx->r2 == 0) {
        // 0x800D3864: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800D3874;
    }
    goto skip_2;
    // 0x800D3864: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800D3868: jalr        $v0
    // 0x800D386C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800D386C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
L_800D3870:
    // 0x800D3870: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800D3874:
    // 0x800D3874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3878: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D387C: jr          $ra
    // 0x800D3880: nop

    return;
    // 0x800D3880: nop

;}
RECOMP_FUNC void mnVSResultsWallpaperTintProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E94: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80134E98: addiu       $t4, $t4, -0x643C
    ctx->r12 = ADD32(ctx->r12, -0X643C);
    // 0x80134E9C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80134EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134EA8: blez        $v0, L_80134EC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80134EAC: addiu       $t6, $v0, -0x5
        ctx->r14 = ADD32(ctx->r2, -0X5);
            goto L_80134EC8;
    }
    // 0x80134EAC: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x80134EB0: bgez        $t6, L_80134EC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80134EB4: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_80134EC8;
    }
    // 0x80134EB4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80134EB8: jal         0x80009A84
    // 0x80134EBC: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80134EBC: nop

    after_0:
    // 0x80134EC0: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80134EC4: addiu       $t4, $t4, -0x643C
    ctx->r12 = ADD32(ctx->r12, -0X643C);
L_80134EC8:
    // 0x80134EC8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80134ECC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80134ED0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134ED4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80134ED8: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80134EDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134EE0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134EE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134EE8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134EEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134EF0: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80134EF4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80134EF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80134EFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80134F00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134F04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80134F08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134F0C: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80134F10: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80134F14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134F18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134F1C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80134F20: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80134F24: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80134F28: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80134F2C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80134F30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80134F34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134F38: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80134F3C: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80134F40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134F44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134F48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80134F4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80134F50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134F54: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80134F58: ori         $t7, $t7, 0x41C8
    ctx->r15 = ctx->r15 | 0X41C8;
    // 0x80134F5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80134F60: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80134F64: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80134F68: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134F6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134F70: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x80134F74: lui         $t9, 0xF64D
    ctx->r25 = S32(0XF64D << 16);
    // 0x80134F78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134F7C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134F80: ori         $t9, $t9, 0x8398
    ctx->r25 = ctx->r25 | 0X8398;
    // 0x80134F84: ori         $t6, $t6, 0x8028
    ctx->r14 = ctx->r14 | 0X8028;
    // 0x80134F88: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80134F8C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80134F90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134F94: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80134F98: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80134F9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134FA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134FA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134FA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134FAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134FB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134FB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134FB8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80134FBC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134FC8: jr          $ra
    // 0x80134FCC: nop

    return;
    // 0x80134FCC: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DA98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014DA9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DAA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014DAA4: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x8014DAA8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8014DAAC: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x8014DAB0: bnel        $t8, $zero, L_8014DAC4
    if (ctx->r24 != 0) {
        // 0x8014DAB4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8014DAC4;
    }
    goto skip_0;
    // 0x8014DAB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8014DAB8: jal         0x800DEEC8
    // 0x8014DABC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014DABC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8014DAC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8014DAC4:
    // 0x8014DAC4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8014DAC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014DACC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014DAD0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014DAD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014DAD8: jal         0x800E6F24
    // 0x8014DADC: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DADC: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    after_1:
    // 0x8014DAE0: jal         0x800D8EB8
    // 0x8014DAE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8014DAE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8014DAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DAEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014DAF0: jr          $ra
    // 0x8014DAF4: nop

    return;
    // 0x8014DAF4: nop

;}
RECOMP_FUNC void itHammerFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017619C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801761A0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801761A4: addiu       $a3, $a3, 0x61C4
    ctx->r7 = ADD32(ctx->r7, 0X61C4);
    // 0x801761A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801761AC: jal         0x80173B24
    // 0x801761B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801761B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x801761B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801761B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801761BC: jr          $ra
    // 0x801761C0: nop

    return;
    // 0x801761C0: nop

;}
RECOMP_FUNC void grSectorArwingUpdateSleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A98: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80106A9C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80106AA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80106AA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106AA8: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80106AAC: beq         $t7, $zero, L_80106AB8
    if (ctx->r15 == 0) {
        // 0x80106AB0: nop
    
            goto L_80106AB8;
    }
    // 0x80106AB0: nop

    // 0x80106AB4: sb          $t8, 0x1438($at)
    MEM_B(0X1438, ctx->r1) = ctx->r24;
L_80106AB8:
    // 0x80106AB8: jr          $ra
    // 0x80106ABC: nop

    return;
    // 0x80106ABC: nop

;}
RECOMP_FUNC void func_ovl8_803864CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803864CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803864D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803864D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803864D8: lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24);
    // 0x803864DC: jal         0x8037E7A8
    // 0x803864E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_0;
    // 0x803864E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x803864E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x803864E8: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x803864EC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803864F0: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803864F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x803864F8: lhu         $t6, -0x1E1C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X1E1C);
    // 0x803864FC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80386500: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80386504: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80386508: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x8038650C: sh          $v1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r3;
    // 0x80386510: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    // 0x80386514: mflo        $t7
    ctx->r15 = lo;
    // 0x80386518: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8038651C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80386520: addiu       $t1, $t0, -0x4
    ctx->r9 = ADD32(ctx->r8, -0X4);
    // 0x80386524: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80386528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80386530: jr          $ra
    // 0x80386534: nop

    return;
    // 0x80386534: nop

;}
RECOMP_FUNC void func_ovl8_803846F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803846F0: jr          $ra
    // 0x803846F4: lh          $v0, 0x3E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X3E);
    return;
    // 0x803846F4: lh          $v0, 0x3E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X3E);
;}
RECOMP_FUNC void func_ovl3_80181894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018189C: jal         0x80172FE0
    // 0x801818A0: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x801818A0: nop

    after_0:
    // 0x801818A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801818A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801818AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801818B0: jr          $ra
    // 0x801818B4: nop

    return;
    // 0x801818B4: nop

;}
RECOMP_FUNC void mnPlayers1PGamePuckAdjustProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013799C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801379A0: lw          $t6, -0x70E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X70E8);
    // 0x801379A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801379A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801379AC: beq         $t6, $zero, L_801379C0
    if (ctx->r14 == 0) {
        // 0x801379B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801379C0;
    }
    // 0x801379B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801379B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801379B8: jal         0x801378C8
    // 0x801379BC: lw          $a0, -0x7058($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7058);
    mnPlayers1PGamePuckAdjustRecall(rdram, ctx);
        goto after_0;
    // 0x801379BC: lw          $a0, -0x7058($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7058);
    after_0:
L_801379C0:
    // 0x801379C0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801379C4: lw          $t7, -0x70EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X70EC);
    // 0x801379C8: beql        $t7, $zero, L_801379DC
    if (ctx->r15 == 0) {
        // 0x801379CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801379DC;
    }
    goto skip_0;
    // 0x801379CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801379D0: jal         0x801378A8
    // 0x801379D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnPlayers1PGamePuckAdjustPlaced(rdram, ctx);
        goto after_1;
    // 0x801379D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x801379D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801379DC:
    // 0x801379DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801379E0: jr          $ra
    // 0x801379E4: nop

    return;
    // 0x801379E4: nop

;}
RECOMP_FUNC void scExplainMakeTapSpark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DA08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DA0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DA10: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DA14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DA18: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018DA1C: jal         0x80009968
    // 0x8018DA20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DA20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DA24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA28: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DA2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DA30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DA34: addiu       $a1, $a1, -0x27F8
    ctx->r5 = ADD32(ctx->r5, -0X27F8);
    // 0x8018DA38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DA3C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018DA40: jal         0x80009DF4
    // 0x8018DA44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018DA44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DA48: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DA4C: lw          $t7, -0x1620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1620);
    // 0x8018DA50: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018DA54: addiu       $t8, $t8, 0x5B68
    ctx->r24 = ADD32(ctx->r24, 0X5B68);
    // 0x8018DA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DA5C: jal         0x800092D0
    // 0x8018DA60: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018DA60: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8018DA64: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8018DA68: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8018DA6C: jal         0x80008CC0
    // 0x8018DA70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8018DA70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8018DA74: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018DA78: lw          $t9, -0x1620($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1620);
    // 0x8018DA7C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8018DA80: addiu       $t0, $t0, 0x5A98
    ctx->r8 = ADD32(ctx->r8, 0X5A98);
    // 0x8018DA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DA88: jal         0x8000F8F4
    // 0x8018DA8C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_4;
    // 0x8018DA8C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x8018DA90: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA94: addiu       $a1, $a1, -0x264C
    ctx->r5 = ADD32(ctx->r5, -0X264C);
    // 0x8018DA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DA9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DAA0: jal         0x80008188
    // 0x8018DAA4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x8018DAA4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_5:
    // 0x8018DAA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DAAC: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8018DAB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018DAB4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8018DAB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DABC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018DAC0: sb          $zero, -0x15DF($at)
    MEM_B(-0X15DF, ctx->r1) = 0;
    // 0x8018DAC4: jr          $ra
    // 0x8018DAC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018DAC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningCliffMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132368: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013236C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132370: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132374: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132378: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x8013237C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132380: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80132384: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132388: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013238C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132390: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132394: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132398: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013239C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801323A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801323A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801323A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801323B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801323B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801323B8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801323BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801323C4: jal         0x8000B93C
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801323D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801323D4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801323D8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801323DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801323E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801323E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801323E8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801323EC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801323F0: jal         0x80007080
    // 0x801323F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801323F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801323F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801323FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132400: jr          $ra
    // 0x80132404: nop

    return;
    // 0x80132404: nop

;}
RECOMP_FUNC void sc1PIntroMakeBannersCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013438C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134390: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80134394: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134398: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013439C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801343A0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801343A4: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x801343A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801343AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801343B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801343B4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801343B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801343BC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801343C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801343C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801343C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801343CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801343D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801343D4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801343D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801343DC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801343E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801343E4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801343E8: jal         0x8000B93C
    // 0x801343EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801343EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801343F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801343F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801343F8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801343FC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134404: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134408: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013440C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134410: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134414: jal         0x80007080
    // 0x80134418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013441C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134424: jr          $ra
    // 0x80134428: nop

    return;
    // 0x80134428: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151A38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151A40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151A44: jal         0x800DEE98
    // 0x80151A48: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151A48: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80151A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151A50: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80151A54: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    // 0x80151A58: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151A5C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151A60: jal         0x800E6F24
    // 0x80151A64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151A64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151A6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151A70: jr          $ra
    // 0x80151A74: nop

    return;
    // 0x80151A74: nop

;}
RECOMP_FUNC void mvUnknownMarioSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018D0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018D0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018D0E0: addiu       $t8, $t8, -0x2988
    ctx->r24 = ADD32(ctx->r24, -0X2988);
    // 0x8018D0E4: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8018D0E8: addiu       $t0, $t0, -0x28E8
    ctx->r8 = ADD32(ctx->r8, -0X28E8);
    // 0x8018D0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018D0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018D0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018D0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018D104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018D10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D110: jal         0x800CDF78
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018D118: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018D11C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8018D128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D12C: jal         0x80004980
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D134: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018D138: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018D13C: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018D140: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018D144: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018D148: jal         0x800CDE04
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D158: jr          $ra
    // 0x8018D15C: nop

    return;
    // 0x8018D15C: nop

;}
RECOMP_FUNC void mpCollisionCheckCeilLineCollisionDiff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F64D4: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800F64D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F64DC: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F64E0: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F64E4: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F64E8: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F64EC: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F64F0: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F64F4: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F64F8: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F64FC: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F6500: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F6504: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F6508: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F650C: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F6510: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F6514: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F6518: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F651C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F6520: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x800F6524: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x800F6528: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800F652C: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F6530: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F6534: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6538: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x800F653C: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6540: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F6544: lwc1        $f22, 0x81C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X81C);
    // 0x800F6548: blez        $t0, L_800F6AF4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F654C: lw          $fp, 0x118($sp)
        ctx->r30 = MEM_W(ctx->r29, 0X118);
            goto L_800F6AF4;
    }
    // 0x800F654C: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x800F6550: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6554: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6558: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800F655C: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F6560: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6564: lw          $s6, 0x11C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X11C);
    // 0x800F6568: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F656C:
    // 0x800F656C: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800F6570: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F6574: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F6578: addiu       $a0, $t7, 0x6
    ctx->r4 = ADD32(ctx->r15, 0X6);
    // 0x800F657C: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F6580: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x800F6584: lhu         $t5, 0x8($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X8);
    // 0x800F6588: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800F658C: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800F6590: beq         $t5, $zero, L_800F6AD4
    if (ctx->r13 == 0) {
        // 0x800F6594: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_800F6AD4;
    }
    // 0x800F6594: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800F6598: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800F659C: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x800F65A0: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x800F65A4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800F65A8: beql        $at, $zero, L_800F6AD8
    if (ctx->r1 == 0) {
        // 0x800F65AC: lw          $t6, 0xF8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF8);
            goto L_800F6AD8;
    }
    goto skip_0;
    // 0x800F65AC: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    skip_0:
    // 0x800F65B0: lw          $t9, 0x70($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X70);
    // 0x800F65B4: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F65B8: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F65BC: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800F65C0: bne         $t9, $zero, L_800F65CC
    if (ctx->r25 != 0) {
        // 0x800F65C4: lwc1        $f16, 0x4($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F65CC;
    }
    // 0x800F65C4: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800F65C8: beq         $v0, $zero, L_800F6620
    if (ctx->r2 == 0) {
        // 0x800F65CC: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800F6620;
    }
L_800F65CC:
    // 0x800F65CC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F65D0: lwc1        $f30, 0x1C($v1)
    ctx->f30.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800F65D4: lw          $t4, 0x137C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X137C);
    // 0x800F65D8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F65DC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800F65E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F65E4: sub.s       $f6, $f2, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F65E8: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x800F65EC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F65F0: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800F65F4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F65F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F65FC: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x800F6600: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x800F6604: sub.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F6608: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800F660C: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800F6610: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800F6614: sub.s       $f28, $f16, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800F6618: b           L_800F663C
    // 0x800F661C: add.s       $f24, $f10, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f18.fl;
        goto L_800F663C;
    // 0x800F661C: add.s       $f24, $f10, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f18.fl;
L_800F6620:
    // 0x800F6620: swc1        $f26, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f26.u32l;
    // 0x800F6624: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    // 0x800F6628: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    // 0x800F662C: swc1        $f2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f2.u32l;
    // 0x800F6630: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x800F6634: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x800F6638: mov.s       $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    ctx->f28.fl = ctx->f16.fl;
L_800F663C:
    // 0x800F663C: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F6640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6644: bc1f        L_800F6670
    if (!c1cs) {
        // 0x800F6648: nop
    
            goto L_800F6670;
    }
    // 0x800F6648: nop

    // 0x800F664C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6650: lwc1        $f6, 0x820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X820);
    // 0x800F6654: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6658: lwc1        $f10, 0x824($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X824);
    // 0x800F665C: sub.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800F6660: add.s       $f4, $f28, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x800F6664: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x800F6668: b           L_800F6684
    // 0x800F666C: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
        goto L_800F6684;
    // 0x800F666C: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_800F6670:
    // 0x800F6670: lwc1        $f0, 0x828($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X828);
    // 0x800F6674: sub.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f0.fl;
    // 0x800F6678: add.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x800F667C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800F6680: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_800F6684:
    // 0x800F6684: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F6688: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x800F668C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F6690: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800F6694: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F6698: beq         $at, $zero, L_800F6AD4
    if (ctx->r1 == 0) {
        // 0x800F669C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F6AD4;
    }
    // 0x800F669C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F66A0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F66A4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
L_800F66A8:
    // 0x800F66A8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F66AC: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F66B0: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800F66B4: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800F66B8: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800F66BC: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800F66C0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800F66C4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F66C8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F66CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800F66D0: nop

    // 0x800F66D4: bc1fl       L_800F66F0
    if (!c1cs) {
        // 0x800F66D8: sw          $v1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r3;
            goto L_800F66F0;
    }
    goto skip_1;
    // 0x800F66D8: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800F66DC: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F66E0: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800F66E4: b           L_800F6AB8
    // 0x800F66E8: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
        goto L_800F6AB8;
    // 0x800F66E8: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x800F66EC: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
L_800F66F0:
    // 0x800F66F0: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
    // 0x800F66F4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800F66F8: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F66FC: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x800F6700: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800F6704: nop

    // 0x800F6708: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F670C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800F6710: nop

    // 0x800F6714: bc1f        L_800F6728
    if (!c1cs) {
        // 0x800F6718: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800F6728;
    }
    // 0x800F6718: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F671C: lw          $t8, 0x1368($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1368);
    // 0x800F6720: b           L_800F6AD4
    // 0x800F6724: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
        goto L_800F6AD4;
    // 0x800F6724: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
L_800F6728:
    // 0x800F6728: lw          $t9, 0x1378($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1378);
    // 0x800F672C: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F6730: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F6734: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x800F6738: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F673C: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6740: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800F6744: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F6748: addu        $t5, $t7, $s2
    ctx->r13 = ADD32(ctx->r15, ctx->r18);
    // 0x800F674C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800F6750: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800F6754: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800F6758: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F675C: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F6760: mflo        $t8
    ctx->r24 = lo;
    // 0x800F6764: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x800F6768: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F676C: beq         $at, $zero, L_800F6AA0
    if (ctx->r1 == 0) {
        // 0x800F6770: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F6AA0;
    }
    // 0x800F6770: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F6774: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
L_800F6778:
    // 0x800F6778: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800F677C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800F6780: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F6784: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x800F6788: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800F678C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F6790: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F6794: addiu       $t9, $sp, 0xB0
    ctx->r25 = ADD32(ctx->r29, 0XB0);
    // 0x800F6798: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800F679C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F67A0: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F67A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800F67A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800F67AC: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F67B0: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F67B4: bne         $s0, $s4, L_800F6914
    if (ctx->r16 != ctx->r20) {
        // 0x800F67B8: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F6914;
    }
    // 0x800F67B8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F67BC: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F67C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F67C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F67C8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F67CC: bc1f        L_800F6A70
    if (!c1cs) {
        // 0x800F67D0: lw          $a3, 0xEC($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XEC);
            goto L_800F6A70;
    }
    // 0x800F67D0: lw          $a3, 0xEC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XEC);
    // 0x800F67D4: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F67D8: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x800F67DC: addiu       $t4, $sp, 0xB0
    ctx->r12 = ADD32(ctx->r29, 0XB0);
    // 0x800F67E0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800F67E4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800F67E8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800F67EC: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800F67F0: jal         0x800F58A0
    // 0x800F67F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckFCSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F67F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800F67F8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F67FC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6800: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F6804: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6808: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F680C: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F6810: bne         $v0, $at, L_800F6A70
    if (ctx->r2 != ctx->r1) {
        // 0x800F6814: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F6A70;
    }
    // 0x800F6814: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F6818: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F681C: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6820: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6824: sub.s       $f20, $f24, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x800F6828: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F682C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F6830: nop

    // 0x800F6834: bc1fl       L_800F684C
    if (!c1cs) {
        // 0x800F6838: sub.s       $f0, $f4, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
            goto L_800F684C;
    }
    goto skip_2;
    // 0x800F6838: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    skip_2:
    // 0x800F683C: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F6840: b           L_800F684C
    // 0x800F6844: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F684C;
    // 0x800F6844: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F6848: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
L_800F684C:
    // 0x800F684C: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F6850: nop

    // 0x800F6854: bc1f        L_800F687C
    if (!c1cs) {
        // 0x800F6858: nop
    
            goto L_800F687C;
    }
    // 0x800F6858: nop

    // 0x800F685C: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F6860: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F6864: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6868: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F686C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F6870: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F6874: b           L_800F6A90
    // 0x800F6878: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F6A90;
    // 0x800F6878: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F687C:
    // 0x800F687C: beq         $s5, $zero, L_800F68A0
    if (ctx->r21 == 0) {
        // 0x800F6880: lwc1        $f6, 0xB4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F68A0;
    }
    // 0x800F6880: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F6884: add.s       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F6888: swc1        $f10, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f10.u32l;
    // 0x800F688C: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F6890: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6894: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F6898: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F689C: swc1        $f6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f6.u32l;
L_800F68A0:
    // 0x800F68A0: beq         $t0, $zero, L_800F68AC
    if (ctx->r8 == 0) {
        // 0x800F68A4: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800F68AC;
    }
    // 0x800F68A4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800F68A8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800F68AC:
    // 0x800F68AC: beq         $s6, $zero, L_800F68C4
    if (ctx->r22 == 0) {
        // 0x800F68B0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800F68C4;
    }
    // 0x800F68B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F68B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F68B8: swc1        $f26, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f26.u32l;
    // 0x800F68BC: swc1        $f26, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f26.u32l;
    // 0x800F68C0: swc1        $f10, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f10.u32l;
L_800F68C4:
    // 0x800F68C4: beql        $fp, $zero, L_800F68F4
    if (ctx->r30 == 0) {
        // 0x800F68C8: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F68F4;
    }
    goto skip_3;
    // 0x800F68C8: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    skip_3:
    // 0x800F68CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800F68D0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F68D4: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F68D8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F68DC: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F68E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800F68E4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800F68E8: lhu         $t4, 0x4($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X4);
    // 0x800F68EC: sw          $t4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r12;
    // 0x800F68F0: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
L_800F68F4:
    // 0x800F68F4: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F68F8: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F68FC: bc1f        L_800F690C
    if (!c1cs) {
        // 0x800F6900: nop
    
            goto L_800F690C;
    }
    // 0x800F6900: nop

    // 0x800F6904: b           L_800F6A70
    // 0x800F6908: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F6A70;
    // 0x800F6908: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F690C:
    // 0x800F690C: b           L_800F6A70
    // 0x800F6910: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F6A70;
    // 0x800F6910: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F6914:
    // 0x800F6914: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F6918: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F691C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800F6920: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800F6924: swc1        $f28, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f28.u32l;
    // 0x800F6928: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800F692C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800F6930: jal         0x800F5A64
    // 0x800F6934: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckCeilSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F6934: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F6938: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F693C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F6944: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6948: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F694C: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F6950: bne         $v0, $at, L_800F6A70
    if (ctx->r2 != ctx->r1) {
        // 0x800F6954: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F6A70;
    }
    // 0x800F6954: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F6958: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F695C: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6960: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6964: sub.s       $f20, $f24, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x800F6968: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F696C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F6970: nop

    // 0x800F6974: bc1fl       L_800F698C
    if (!c1cs) {
        // 0x800F6978: sub.s       $f0, $f4, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
            goto L_800F698C;
    }
    goto skip_4;
    // 0x800F6978: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    skip_4:
    // 0x800F697C: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F6980: b           L_800F698C
    // 0x800F6984: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F698C;
    // 0x800F6984: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F6988: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
L_800F698C:
    // 0x800F698C: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F6990: nop

    // 0x800F6994: bc1f        L_800F69BC
    if (!c1cs) {
        // 0x800F6998: nop
    
            goto L_800F69BC;
    }
    // 0x800F6998: nop

    // 0x800F699C: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F69A0: addu        $v0, $t5, $s7
    ctx->r2 = ADD32(ctx->r13, ctx->r23);
    // 0x800F69A4: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x800F69A8: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800F69AC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800F69B0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F69B4: b           L_800F6A90
    // 0x800F69B8: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F6A90;
    // 0x800F69B8: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F69BC:
    // 0x800F69BC: beq         $s5, $zero, L_800F69E0
    if (ctx->r21 == 0) {
        // 0x800F69C0: lwc1        $f6, 0xB4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F69E0;
    }
    // 0x800F69C0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F69C4: add.s       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F69C8: swc1        $f10, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f10.u32l;
    // 0x800F69CC: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F69D0: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F69D4: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F69D8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F69DC: swc1        $f6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f6.u32l;
L_800F69E0:
    // 0x800F69E0: beq         $t0, $zero, L_800F69EC
    if (ctx->r8 == 0) {
        // 0x800F69E4: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_800F69EC;
    }
    // 0x800F69E4: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800F69E8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800F69EC:
    // 0x800F69EC: beq         $s6, $zero, L_800F6A24
    if (ctx->r22 == 0) {
        // 0x800F69F0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F6A24;
    }
    // 0x800F69F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F69F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800F69F8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800F69FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F6A00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800F6A04: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F6A08: jal         0x800F46D0
    // 0x800F6A0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_2;
    // 0x800F6A0C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F6A10: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6A14: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6A18: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F6A1C: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F6A20: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F6A24:
    // 0x800F6A24: beql        $fp, $zero, L_800F6A54
    if (ctx->r30 == 0) {
        // 0x800F6A28: lwc1        $f10, 0xB0($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F6A54;
    }
    goto skip_5;
    // 0x800F6A28: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    skip_5:
    // 0x800F6A2C: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F6A30: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F6A34: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800F6A38: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F6A3C: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F6A40: mflo        $t4
    ctx->r12 = lo;
    // 0x800F6A44: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800F6A48: lhu         $t5, 0x4($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X4);
    // 0x800F6A4C: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x800F6A50: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
L_800F6A54:
    // 0x800F6A54: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F6A58: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F6A5C: bc1fl       L_800F6A70
    if (!c1cs) {
        // 0x800F6A60: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F6A70;
    }
    goto skip_6;
    // 0x800F6A60: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_6:
    // 0x800F6A64: b           L_800F6A70
    // 0x800F6A68: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F6A70;
    // 0x800F6A68: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F6A6C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F6A70:
    // 0x800F6A70: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F6A74: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F6A78: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F6A7C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6A80: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6A84: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F6A88: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F6A8C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F6A90:
    // 0x800F6A90: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F6A94: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F6A98: bnel        $at, $zero, L_800F6778
    if (ctx->r1 != 0) {
        // 0x800F6A9C: lw          $t4, 0x0($t2)
        ctx->r12 = MEM_W(ctx->r10, 0X0);
            goto L_800F6778;
    }
    goto skip_7;
    // 0x800F6A9C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    skip_7:
L_800F6AA0:
    // 0x800F6AA0: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x800F6AA4: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800F6AA8: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F6AAC: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800F6AB0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800F6AB4: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
L_800F6AB8:
    // 0x800F6AB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F6ABC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F6AC0: bne         $at, $zero, L_800F66A8
    if (ctx->r1 != 0) {
        // 0x800F6AC4: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F66A8;
    }
    // 0x800F6AC4: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F6AC8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F6ACC: lw          $t5, 0x1368($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1368);
    // 0x800F6AD0: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
L_800F6AD4:
    // 0x800F6AD4: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
L_800F6AD8:
    // 0x800F6AD8: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800F6ADC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800F6AE0: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F6AE4: addiu       $t4, $t9, 0x12
    ctx->r12 = ADD32(ctx->r25, 0X12);
    // 0x800F6AE8: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x800F6AEC: bne         $at, $zero, L_800F656C
    if (ctx->r1 != 0) {
        // 0x800F6AF0: sw          $t7, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r15;
            goto L_800F656C;
    }
    // 0x800F6AF0: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
L_800F6AF4:
    // 0x800F6AF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6AF8: lwc1        $f8, 0x82C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X82C);
    // 0x800F6AFC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F6B00: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F6B04: c.eq.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl == ctx->f8.fl;
    // 0x800F6B08: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F6B0C: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F6B10: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F6B14: bc1f        L_800F6B24
    if (!c1cs) {
        // 0x800F6B18: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F6B24;
    }
    // 0x800F6B18: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F6B1C: b           L_800F6B28
    // 0x800F6B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F6B28;
    // 0x800F6B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6B24:
    // 0x800F6B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6B28:
    // 0x800F6B28: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F6B2C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F6B30: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F6B34: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F6B38: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F6B3C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F6B40: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F6B44: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F6B48: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F6B4C: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F6B50: jr          $ra
    // 0x800F6B54: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800F6B54: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void grSectorInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107E7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80107E80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80107E84: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80107E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80107E8C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80107E90: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80107E94: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x80107E98: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80107E9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80107EA0: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80107EA4: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80107EA8: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x80107EAC: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80107EB0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80107EB4: jal         0x800CD6FC
    // 0x80107EB8: addiu       $a0, $a0, 0xA1
    ctx->r4 = ADD32(ctx->r4, 0XA1);
    lbRelocGetForceStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x80107EB8: addiu       $a0, $a0, 0xA1
    ctx->r4 = ADD32(ctx->r4, 0XA1);
    after_0:
    // 0x80107EBC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80107EC0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80107EC4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80107EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107ECC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80107ED0: jal         0x80009968
    // 0x80107ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80107ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80107ED8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80107EDC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80107EE0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80107EE4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80107EE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80107EEC: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80107EF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80107EF4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80107EF8: jal         0x80009DF4
    // 0x80107EFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80107EFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80107F00: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80107F04: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80107F08: addiu       $t2, $t2, 0x2C30
    ctx->r10 = ADD32(ctx->r10, 0X2C30);
    // 0x80107F0C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80107F10: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80107F14: addiu       $a3, $a3, -0x1634
    ctx->r7 = ADD32(ctx->r7, -0X1634);
    // 0x80107F18: addiu       $a2, $a2, 0x13F8
    ctx->r6 = ADD32(ctx->r6, 0X13F8);
    // 0x80107F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F20: jal         0x80105760
    // 0x80107F24: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    grModelSetupGroundDObjs(rdram, ctx);
        goto after_3;
    // 0x80107F24: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x80107F28: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80107F2C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80107F30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80107F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80107F38: jal         0x80008188
    // 0x80107F3C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80107F3C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80107F40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80107F44: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80107F48: addiu       $t3, $zero, 0x258
    ctx->r11 = ADD32(0, 0X258);
    // 0x80107F4C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80107F50: sb          $zero, 0x48($s0)
    MEM_B(0X48, ctx->r16) = 0;
    // 0x80107F54: sb          $v1, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r3;
    // 0x80107F58: sh          $t3, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r11;
    // 0x80107F5C: sb          $t4, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r12;
    // 0x80107F60: sb          $v1, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r3;
    // 0x80107F64: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    // 0x80107F68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80107F6C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80107F70: sw          $t5, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r13;
    // 0x80107F74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80107F78: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80107F7C: addiu       $t7, $t7, 0x2E74
    ctx->r15 = ADD32(ctx->r15, 0X2E74);
    // 0x80107F80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80107F84: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80107F88: jal         0x8000BD1C
    // 0x80107F8C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_5;
    // 0x80107F8C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_5:
    // 0x80107F90: jal         0x8000DF34
    // 0x80107F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x80107F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80107F98: jal         0x800FC604
    // 0x80107F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_7;
    // 0x80107F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80107FA0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80107FA4: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x80107FA8: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80107FAC: addiu       $t9, $t9, 0x14
    ctx->r25 = ADD32(ctx->r25, 0X14);
    // 0x80107FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80107FB4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80107FB8: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x80107FBC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80107FC0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80107FC4: jr          $ra
    // 0x80107FC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80107FC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftParamGetMotionCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA5BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA5C0: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x800EA5C4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800EA5C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EA5CC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800EA5D0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800EA5D4: bne         $t7, $zero, L_800EA5E0
    if (ctx->r15 != 0) {
        // 0x800EA5D8: sh          $t6, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r14;
            goto L_800EA5E0;
    }
    // 0x800EA5D8: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800EA5DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_800EA5E0:
    // 0x800EA5E0: jr          $ra
    // 0x800EA5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EA5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_80371AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371AE0: lw          $a3, 0x4C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4C);
    // 0x80371AE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80371AE8: beql        $a3, $zero, L_80371B14
    if (ctx->r7 == 0) {
        // 0x80371AEC: lw          $v0, 0x58($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X58);
            goto L_80371B14;
    }
    goto skip_0;
    // 0x80371AEC: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    skip_0:
    // 0x80371AF0: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x80371AF4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80371AF8: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x80371AFC: lh          $t6, 0x78($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X78);
    // 0x80371B00: jalr        $t9
    // 0x80371B04: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371B04: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80371B08: b           L_80371B28
    // 0x80371B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80371B28;
    // 0x80371B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371B10: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
L_80371B14:
    // 0x80371B14: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80371B18: lh          $t7, 0x40($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X40);
    // 0x80371B1C: jalr        $t9
    // 0x80371B20: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80371B20: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80371B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80371B28:
    // 0x80371B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371B2C: jr          $ra
    // 0x80371B30: nop

    return;
    // 0x80371B30: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015729C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801572A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801572A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801572A8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801572AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801572B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801572B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801572B8: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x801572BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801572C0: jal         0x800E6F24
    // 0x801572C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801572C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801572C8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x801572CC: addiu       $t7, $t7, 0x6E98
    ctx->r15 = ADD32(ctx->r15, 0X6E98);
    // 0x801572D0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801572D4: sw          $t7, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r15;
    // 0x801572D8: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
    // 0x801572DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801572E0: jal         0x80156EBC
    // 0x801572E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    ftKirbyCopySamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_1;
    // 0x801572E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x801572E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801572EC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801572F0: lw          $a2, 0xAE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XAE0);
    // 0x801572F4: jal         0x80168DDC
    // 0x801572F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    wpSamusChargeShotMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x801572F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x801572FC: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x80157300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80157304: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80157308: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8015730C: jr          $ra
    // 0x80157310: nop

    return;
    // 0x80157310: nop

;}
RECOMP_FUNC void sc1PGameAppendBonusStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FD5C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018FD60: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018FD64: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018FD68: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8018FD6C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8018FD70: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8018FD74: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018FD78: addiu       $t5, $t5, 0x38B0
    ctx->r13 = ADD32(ctx->r13, 0X38B0);
    // 0x8018FD7C: divu        $zero, $t7, $v0
    lo = S32(U32(ctx->r15) / U32(ctx->r2)); hi = S32(U32(ctx->r15) % U32(ctx->r2));
    // 0x8018FD80: mflo        $t8
    ctx->r24 = lo;
    // 0x8018FD84: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8018FD88: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8018FD8C: lw          $t9, 0xD64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD64);
    // 0x8018FD90: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018FD94: lw          $t0, 0x36A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X36A0);
    // 0x8018FD98: divu        $zero, $t9, $v0
    lo = S32(U32(ctx->r25) / U32(ctx->r2)); hi = S32(U32(ctx->r25) % U32(ctx->r2));
    // 0x8018FD9C: bne         $v0, $zero, L_8018FDA8
    if (ctx->r2 != 0) {
        // 0x8018FDA0: nop
    
            goto L_8018FDA8;
    }
    // 0x8018FDA0: nop

    // 0x8018FDA4: break       7
    do_break(2149121444);
L_8018FDA8:
    // 0x8018FDA8: mflo        $t6
    ctx->r14 = lo;
    // 0x8018FDAC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FDB0: bne         $v0, $zero, L_8018FDBC
    if (ctx->r2 != 0) {
        // 0x8018FDB4: nop
    
            goto L_8018FDBC;
    }
    // 0x8018FDB4: nop

    // 0x8018FDB8: break       7
    do_break(2149121464);
L_8018FDBC:
    // 0x8018FDBC: sw          $t6, 0x38B4($at)
    MEM_W(0X38B4, ctx->r1) = ctx->r14;
    // 0x8018FDC0: beq         $t0, $zero, L_8018FE64
    if (ctx->r8 == 0) {
        // 0x8018FDC4: lui         $t3, 0x8019
        ctx->r11 = S32(0X8019 << 16);
            goto L_8018FE64;
    }
    // 0x8018FDC4: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018FDC8: blez        $t0, L_8018FE20
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8018FDCC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8018FE20;
    }
    // 0x8018FDCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018FDD0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018FDD4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018FDD8: addiu       $v0, $v0, 0x33D0
    ctx->r2 = ADD32(ctx->r2, 0X33D0);
    // 0x8018FDDC: lbu         $v1, 0x4AE3($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4AE3);
    // 0x8018FDE0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018FDE4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8018FDE8:
    // 0x8018FDE8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8018FDEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018FDF0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8018FDF4: bne         $v1, $t7, L_8018FE0C
    if (ctx->r3 != ctx->r15) {
        // 0x8018FDF8: nop
    
            goto L_8018FE0C;
    }
    // 0x8018FDF8: nop

    // 0x8018FDFC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8018FE00: beq         $t1, $a0, L_8018FE18
    if (ctx->r9 == ctx->r4) {
        // 0x8018FE04: nop
    
            goto L_8018FE18;
    }
    // 0x8018FE04: nop

    // 0x8018FE08: beq         $a3, $a0, L_8018FE18
    if (ctx->r7 == ctx->r4) {
        // 0x8018FE0C: lui         $t2, 0x800A
        ctx->r10 = S32(0X800A << 16);
            goto L_8018FE18;
    }
L_8018FE0C:
    // 0x8018FE0C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018FE10: b           L_8018FE74
    // 0x8018FE14: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
        goto L_8018FE74;
    // 0x8018FE14: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
L_8018FE18:
    // 0x8018FE18: bne         $at, $zero, L_8018FDE8
    if (ctx->r1 != 0) {
        // 0x8018FE1C: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_8018FDE8;
    }
    // 0x8018FE1C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_8018FE20:
    // 0x8018FE20: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018FE24: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
    // 0x8018FE28: lbu         $v0, 0x17($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X17);
    // 0x8018FE2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018FE30: beq         $v0, $at, L_8018FE58
    if (ctx->r2 == ctx->r1) {
        // 0x8018FE34: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8018FE58;
    }
    // 0x8018FE34: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018FE38: beq         $v0, $at, L_8018FE58
    if (ctx->r2 == ctx->r1) {
        // 0x8018FE3C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018FE58;
    }
    // 0x8018FE3C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018FE40: beql        $v0, $at, L_8018FE5C
    if (ctx->r2 == ctx->r1) {
        // 0x8018FE44: lw          $t6, 0x2C($t2)
        ctx->r14 = MEM_W(ctx->r10, 0X2C);
            goto L_8018FE5C;
    }
    goto skip_0;
    // 0x8018FE44: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    skip_0:
    // 0x8018FE48: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x8018FE4C: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8018FE50: b           L_8018FE64
    // 0x8018FE54: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
        goto L_8018FE64;
    // 0x8018FE54: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
L_8018FE58:
    // 0x8018FE58: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
L_8018FE5C:
    // 0x8018FE5C: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x8018FE60: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
L_8018FE64:
    // 0x8018FE64: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018FE68: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
    // 0x8018FE6C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8018FE70: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_8018FE74:
    // 0x8018FE74: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018FE78: addiu       $a1, $t8, 0x3894
    ctx->r5 = ADD32(ctx->r24, 0X3894);
    // 0x8018FE7C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018FE80: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018FE84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018FE88: addiu       $a0, $a0, 0x3844
    ctx->r4 = ADD32(ctx->r4, 0X3844);
    // 0x8018FE8C: addiu       $v0, $v0, 0x37B4
    ctx->r2 = ADD32(ctx->r2, 0X37B4);
    // 0x8018FE90: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8018FE94: addiu       $t3, $t3, 0x3898
    ctx->r11 = ADD32(ctx->r11, 0X3898);
    // 0x8018FE98: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_8018FE9C:
    // 0x8018FE9C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8018FEA0: beql        $t9, $zero, L_8018FEC8
    if (ctx->r25 == 0) {
        // 0x8018FEA4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018FEC8;
    }
    goto skip_1;
    // 0x8018FEA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x8018FEA8: bne         $at, $zero, L_8018FEBC
    if (ctx->r1 != 0) {
        // 0x8018FEAC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8018FEBC;
    }
    // 0x8018FEAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018FEB0: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8018FEB4: bne         $at, $zero, L_8018FEC4
    if (ctx->r1 != 0) {
        // 0x8018FEB8: nop
    
            goto L_8018FEC4;
    }
    // 0x8018FEB8: nop

L_8018FEBC:
    // 0x8018FEBC: bnel        $v0, $a2, L_8018FEEC
    if (ctx->r2 != ctx->r6) {
        // 0x8018FEC0: lw          $v0, 0x2C($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X2C);
            goto L_8018FEEC;
    }
    goto skip_2;
    // 0x8018FEC0: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    skip_2:
L_8018FEC4:
    // 0x8018FEC4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8018FEC8:
    // 0x8018FEC8: sltu        $at, $v0, $t3
    ctx->r1 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x8018FECC: bnel        $at, $zero, L_8018FE9C
    if (ctx->r1 != 0) {
        // 0x8018FED0: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_8018FE9C;
    }
    goto skip_3;
    // 0x8018FED0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x8018FED4: beql        $v1, $zero, L_8018FEEC
    if (ctx->r3 == 0) {
        // 0x8018FED8: lw          $v0, 0x2C($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X2C);
            goto L_8018FEEC;
    }
    goto skip_4;
    // 0x8018FED8: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    skip_4:
    // 0x8018FEDC: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x8018FEE0: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x8018FEE4: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x8018FEE8: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
L_8018FEEC:
    // 0x8018FEEC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8018FEF0: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x8018FEF4: bne         $t8, $zero, L_8018FF90
    if (ctx->r24 != 0) {
        // 0x8018FEF8: nop
    
            goto L_8018FF90;
    }
    // 0x8018FEF8: nop

    // 0x8018FEFC: lbu         $t6, 0x1C($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1C);
    // 0x8018FF00: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018FF04: beq         $t6, $zero, L_8018FF90
    if (ctx->r14 == 0) {
        // 0x8018FF08: nop
    
            goto L_8018FF90;
    }
    // 0x8018FF08: nop

    // 0x8018FF0C: lbu         $t3, 0x36A8($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X36A8);
    // 0x8018FF10: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018FF14: bne         $t3, $zero, L_8018FF90
    if (ctx->r11 != 0) {
        // 0x8018FF18: nop
    
            goto L_8018FF90;
    }
    // 0x8018FF18: nop

    // 0x8018FF1C: lbu         $t4, 0x36A9($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X36A9);
    // 0x8018FF20: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018FF24: bne         $t4, $zero, L_8018FF90
    if (ctx->r12 != 0) {
        // 0x8018FF28: nop
    
            goto L_8018FF90;
    }
    // 0x8018FF28: nop

    // 0x8018FF2C: lbu         $t7, 0x36AA($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X36AA);
    // 0x8018FF30: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018FF34: addiu       $v1, $v1, 0x3744
    ctx->r3 = ADD32(ctx->r3, 0X3744);
    // 0x8018FF38: bne         $t7, $zero, L_8018FF90
    if (ctx->r15 != 0) {
        // 0x8018FF3C: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_8018FF90;
    }
    // 0x8018FF3C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018FF40: addiu       $a0, $a0, 0x3794
    ctx->r4 = ADD32(ctx->r4, 0X3794);
    // 0x8018FF44: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8018FF48:
    // 0x8018FF48: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018FF4C: beq         $t8, $zero, L_8018FF64
    if (ctx->r24 == 0) {
        // 0x8018FF50: nop
    
            goto L_8018FF64;
    }
    // 0x8018FF50: nop

    // 0x8018FF54: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018FF58: addiu       $v1, $v1, 0x37B0
    ctx->r3 = ADD32(ctx->r3, 0X37B0);
    // 0x8018FF5C: b           L_8018FFAC
    // 0x8018FF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8018FFAC;
    // 0x8018FF60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8018FF64:
    // 0x8018FF64: bnel        $v1, $a0, L_8018FF48
    if (ctx->r3 != ctx->r4) {
        // 0x8018FF68: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8018FF48;
    }
    goto skip_5;
    // 0x8018FF68: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x8018FF6C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018FF70: addiu       $v1, $v1, 0x37B0
    ctx->r3 = ADD32(ctx->r3, 0X37B0);
    // 0x8018FF74: lw          $t9, 0xE4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE4);
    // 0x8018FF78: ori         $t6, $v0, 0x4
    ctx->r14 = ctx->r2 | 0X4;
    // 0x8018FF7C: beql        $t9, $zero, L_8018FF90
    if (ctx->r25 == 0) {
        // 0x8018FF80: sw          $t6, 0x2C($t2)
        MEM_W(0X2C, ctx->r10) = ctx->r14;
            goto L_8018FF90;
    }
    goto skip_6;
    // 0x8018FF80: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
    skip_6:
    // 0x8018FF84: b           L_8018FFAC
    // 0x8018FF88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8018FFAC;
    // 0x8018FF88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018FF8C: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
L_8018FF90:
    // 0x8018FF90: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018FF94: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018FF98: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018FF9C: addiu       $v1, $v1, 0x37B0
    ctx->r3 = ADD32(ctx->r3, 0X37B0);
    // 0x8018FFA0: lbu         $t4, 0x36A9($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X36A9);
    // 0x8018FFA4: lbu         $t3, 0x36A8($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X36A8);
    // 0x8018FFA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8018FFAC:
    // 0x8018FFAC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018FFB0: lbu         $t7, 0x36AB($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X36AB);
    // 0x8018FFB4: beql        $t7, $zero, L_8018FFCC
    if (ctx->r15 == 0) {
        // 0x8018FFB8: lw          $t6, 0x8C($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X8C);
            goto L_8018FFCC;
    }
    goto skip_7;
    // 0x8018FFB8: lw          $t6, 0x8C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8C);
    skip_7:
    // 0x8018FFBC: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x8018FFC0: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8018FFC4: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
    // 0x8018FFC8: lw          $t6, 0x8C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8C);
L_8018FFCC:
    // 0x8018FFCC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8018FFD0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8018FFD4: bne         $t6, $zero, L_8018FFE8
    if (ctx->r14 != 0) {
        // 0x8018FFD8: addiu       $v0, $zero, 0x3A
        ctx->r2 = ADD32(0, 0X3A);
            goto L_8018FFE8;
    }
    // 0x8018FFD8: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // 0x8018FFDC: lw          $t7, 0x90($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X90);
    // 0x8018FFE0: beql        $t7, $zero, L_8019002C
    if (ctx->r15 == 0) {
        // 0x8018FFE4: addiu       $a0, $zero, 0x23
        ctx->r4 = ADD32(0, 0X23);
            goto L_8019002C;
    }
    goto skip_8;
    // 0x8018FFE4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    skip_8:
L_8018FFE8:
    // 0x8018FFE8: beql        $a2, $a0, L_80190014
    if (ctx->r6 == ctx->r4) {
        // 0x8018FFEC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80190014;
    }
    goto skip_9;
    // 0x8018FFEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_9:
    // 0x8018FFF0: beq         $a2, $a1, L_80190010
    if (ctx->r6 == ctx->r5) {
        // 0x8018FFF4: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80190010;
    }
    // 0x8018FFF4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8018FFF8: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8018FFFC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80190000: beql        $t6, $zero, L_80190014
    if (ctx->r14 == 0) {
        // 0x80190004: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80190014;
    }
    goto skip_10;
    // 0x80190004: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_10:
    // 0x80190008: b           L_80190030
    // 0x8019000C: nop

        goto L_80190030;
    // 0x8019000C: nop

L_80190010:
    // 0x80190010: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80190014:
    // 0x80190014: bne         $a2, $v0, L_8018FFE8
    if (ctx->r6 != ctx->r2) {
        // 0x80190018: nop
    
            goto L_8018FFE8;
    }
    // 0x80190018: nop

    // 0x8019001C: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x80190020: ori         $t7, $v0, 0x10
    ctx->r15 = ctx->r2 | 0X10;
    // 0x80190024: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x80190028: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
L_8019002C:
    // 0x8019002C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_80190030:
    // 0x80190030: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80190034: addiu       $v0, $v0, 0x38A0
    ctx->r2 = ADD32(ctx->r2, 0X38A0);
    // 0x80190038: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8019003C: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80190040: addiu       $a2, $a2, 0x37E8
    ctx->r6 = ADD32(ctx->r6, 0X37E8);
    // 0x80190044: beq         $t8, $zero, L_80190064
    if (ctx->r24 == 0) {
        // 0x80190048: nop
    
            goto L_80190064;
    }
    // 0x80190048: nop

    // 0x8019004C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80190050: bne         $t9, $zero, L_80190064
    if (ctx->r25 != 0) {
        // 0x80190054: nop
    
            goto L_80190064;
    }
    // 0x80190054: nop

    // 0x80190058: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x8019005C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80190060: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
L_80190064:
    // 0x80190064: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80190068: addiu       $v0, $v0, 0x38A8
    ctx->r2 = ADD32(ctx->r2, 0X38A8);
    // 0x8019006C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80190070: beq         $t8, $zero, L_80190090
    if (ctx->r24 == 0) {
        // 0x80190074: nop
    
            goto L_80190090;
    }
    // 0x80190074: nop

    // 0x80190078: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019007C: bne         $t9, $zero, L_80190090
    if (ctx->r25 != 0) {
        // 0x80190080: nop
    
            goto L_80190090;
    }
    // 0x80190080: nop

    // 0x80190084: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x80190088: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8019008C: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
L_80190090:
    // 0x80190090: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80190094: addiu       $v0, $v0, 0x37B4
    ctx->r2 = ADD32(ctx->r2, 0X37B4);
    // 0x80190098: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_8019009C:
    // 0x8019009C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801900A0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x801900A4: bne         $t8, $zero, L_801900B4
    if (ctx->r24 != 0) {
        // 0x801900A8: nop
    
            goto L_801900B4;
    }
    // 0x801900A8: nop

    // 0x801900AC: b           L_80190268
    // 0x801900B0: nop

        goto L_80190268;
    // 0x801900B0: nop

L_801900B4:
    // 0x801900B4: bnel        $at, $zero, L_8019009C
    if (ctx->r1 != 0) {
        // 0x801900B8: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_8019009C;
    }
    goto skip_11;
    // 0x801900B8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_11:
    // 0x801900BC: lbu         $t9, 0x14($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X14);
    // 0x801900C0: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x801900C4: beq         $at, $zero, L_8019025C
    if (ctx->r1 == 0) {
        // 0x801900C8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8019025C;
    }
    // 0x801900C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801900CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801900D0: addu        $at, $at, $t9
    gpr jr_addend_801900D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801900D4: lw          $t9, 0x2F34($at)
    ctx->r25 = ADD32(ctx->r1, 0X2F34);
    // 0x801900D8: jr          $t9
    // 0x801900DC: nop

    switch (jr_addend_801900D8 >> 2) {
        case 0: goto L_801900E0; break;
        case 1: goto L_80190108; break;
        case 2: goto L_80190130; break;
        case 3: goto L_80190144; break;
        case 4: goto L_80190158; break;
        case 5: goto L_80190180; break;
        case 6: goto L_801901BC; break;
        case 7: goto L_801901D0; break;
        case 8: goto L_8019020C; break;
        case 9: goto L_8019025C; break;
        case 10: goto L_80190234; break;
        case 11: goto L_80190248; break;
        default: switch_error(__func__, 0x801900D8, 0x80192F34);
    }
    // 0x801900DC: nop

L_801900E0:
    // 0x801900E0: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x801900E4: bnel        $t6, $zero, L_801900F8
    if (ctx->r14 != 0) {
        // 0x801900E8: lw          $t7, 0x3C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X3C);
            goto L_801900F8;
    }
    goto skip_12;
    // 0x801900E8: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    skip_12:
    // 0x801900EC: b           L_80190268
    // 0x801900F0: nop

        goto L_80190268;
    // 0x801900F0: nop

    // 0x801900F4: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
L_801900F8:
    // 0x801900F8: bnel        $t7, $zero, L_80190260
    if (ctx->r15 != 0) {
        // 0x801900FC: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_13;
    // 0x801900FC: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_13:
    // 0x80190100: b           L_80190268
    // 0x80190104: nop

        goto L_80190268;
    // 0x80190104: nop

L_80190108:
    // 0x80190108: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x8019010C: bnel        $t8, $zero, L_80190120
    if (ctx->r24 != 0) {
        // 0x80190110: lw          $t9, 0x40($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X40);
            goto L_80190120;
    }
    goto skip_14;
    // 0x80190110: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    skip_14:
    // 0x80190114: b           L_80190268
    // 0x80190118: nop

        goto L_80190268;
    // 0x80190118: nop

    // 0x8019011C: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
L_80190120:
    // 0x80190120: bnel        $t9, $zero, L_80190260
    if (ctx->r25 != 0) {
        // 0x80190124: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_15;
    // 0x80190124: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_15:
    // 0x80190128: b           L_80190268
    // 0x8019012C: nop

        goto L_80190268;
    // 0x8019012C: nop

L_80190130:
    // 0x80190130: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80190134: bnel        $t6, $zero, L_80190260
    if (ctx->r14 != 0) {
        // 0x80190138: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_16;
    // 0x80190138: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_16:
    // 0x8019013C: b           L_80190268
    // 0x80190140: nop

        goto L_80190268;
    // 0x80190140: nop

L_80190144:
    // 0x80190144: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x80190148: bnel        $t7, $zero, L_80190260
    if (ctx->r15 != 0) {
        // 0x8019014C: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_17;
    // 0x8019014C: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_17:
    // 0x80190150: b           L_80190268
    // 0x80190154: nop

        goto L_80190268;
    // 0x80190154: nop

L_80190158:
    // 0x80190158: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x8019015C: bnel        $t8, $zero, L_80190170
    if (ctx->r24 != 0) {
        // 0x80190160: lw          $t9, 0x3C($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X3C);
            goto L_80190170;
    }
    goto skip_18;
    // 0x80190160: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
    skip_18:
    // 0x80190164: b           L_80190268
    // 0x80190168: nop

        goto L_80190268;
    // 0x80190168: nop

    // 0x8019016C: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
L_80190170:
    // 0x80190170: bnel        $t9, $zero, L_80190260
    if (ctx->r25 != 0) {
        // 0x80190174: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_19;
    // 0x80190174: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_19:
    // 0x80190178: b           L_80190268
    // 0x8019017C: nop

        goto L_80190268;
    // 0x8019017C: nop

L_80190180:
    // 0x80190180: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80190184: bnel        $t6, $zero, L_80190198
    if (ctx->r14 != 0) {
        // 0x80190188: lw          $t7, 0x3C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X3C);
            goto L_80190198;
    }
    goto skip_20;
    // 0x80190188: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    skip_20:
    // 0x8019018C: b           L_80190268
    // 0x80190190: nop

        goto L_80190268;
    // 0x80190190: nop

    // 0x80190194: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
L_80190198:
    // 0x80190198: bnel        $t7, $zero, L_801901AC
    if (ctx->r15 != 0) {
        // 0x8019019C: lw          $t8, 0x40($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X40);
            goto L_801901AC;
    }
    goto skip_21;
    // 0x8019019C: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    skip_21:
    // 0x801901A0: b           L_80190268
    // 0x801901A4: nop

        goto L_80190268;
    // 0x801901A4: nop

    // 0x801901A8: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
L_801901AC:
    // 0x801901AC: bnel        $t8, $zero, L_80190260
    if (ctx->r24 != 0) {
        // 0x801901B0: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_22;
    // 0x801901B0: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_22:
    // 0x801901B4: b           L_80190268
    // 0x801901B8: nop

        goto L_80190268;
    // 0x801901B8: nop

L_801901BC:
    // 0x801901BC: lw          $t9, 0x38($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X38);
    // 0x801901C0: bnel        $t9, $zero, L_80190260
    if (ctx->r25 != 0) {
        // 0x801901C4: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_23;
    // 0x801901C4: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_23:
    // 0x801901C8: b           L_80190268
    // 0x801901CC: nop

        goto L_80190268;
    // 0x801901CC: nop

L_801901D0:
    // 0x801901D0: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x801901D4: bnel        $t6, $zero, L_801901E8
    if (ctx->r14 != 0) {
        // 0x801901D8: lw          $t7, 0x3C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X3C);
            goto L_801901E8;
    }
    goto skip_24;
    // 0x801901D8: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    skip_24:
    // 0x801901DC: b           L_80190268
    // 0x801901E0: nop

        goto L_80190268;
    // 0x801901E0: nop

    // 0x801901E4: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
L_801901E8:
    // 0x801901E8: bnel        $t7, $zero, L_801901FC
    if (ctx->r15 != 0) {
        // 0x801901EC: lw          $t8, 0x40($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X40);
            goto L_801901FC;
    }
    goto skip_25;
    // 0x801901EC: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    skip_25:
    // 0x801901F0: b           L_80190268
    // 0x801901F4: nop

        goto L_80190268;
    // 0x801901F4: nop

    // 0x801901F8: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
L_801901FC:
    // 0x801901FC: bnel        $t8, $zero, L_80190260
    if (ctx->r24 != 0) {
        // 0x80190200: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_26;
    // 0x80190200: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_26:
    // 0x80190204: b           L_80190268
    // 0x80190208: nop

        goto L_80190268;
    // 0x80190208: nop

L_8019020C:
    // 0x8019020C: lw          $t9, 0x38($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X38);
    // 0x80190210: bnel        $t9, $zero, L_80190224
    if (ctx->r25 != 0) {
        // 0x80190214: lw          $t6, 0x40($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X40);
            goto L_80190224;
    }
    goto skip_27;
    // 0x80190214: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    skip_27:
    // 0x80190218: b           L_80190268
    // 0x8019021C: nop

        goto L_80190268;
    // 0x8019021C: nop

    // 0x80190220: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
L_80190224:
    // 0x80190224: bnel        $t6, $zero, L_80190260
    if (ctx->r14 != 0) {
        // 0x80190228: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_28;
    // 0x80190228: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_28:
    // 0x8019022C: b           L_80190268
    // 0x80190230: nop

        goto L_80190268;
    // 0x80190230: nop

L_80190234:
    // 0x80190234: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x80190238: bnel        $t7, $zero, L_80190260
    if (ctx->r15 != 0) {
        // 0x8019023C: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_29;
    // 0x8019023C: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_29:
    // 0x80190240: b           L_80190268
    // 0x80190244: nop

        goto L_80190268;
    // 0x80190244: nop

L_80190248:
    // 0x80190248: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x8019024C: bnel        $t8, $zero, L_80190260
    if (ctx->r24 != 0) {
        // 0x80190250: lw          $t9, 0x2C($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X2C);
            goto L_80190260;
    }
    goto skip_30;
    // 0x80190250: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    skip_30:
    // 0x80190254: b           L_80190268
    // 0x80190258: nop

        goto L_80190268;
    // 0x80190258: nop

L_8019025C:
    // 0x8019025C: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
L_80190260:
    // 0x80190260: ori         $t6, $t9, 0x100
    ctx->r14 = ctx->r25 | 0X100;
    // 0x80190264: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
L_80190268:
    // 0x80190268: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8019026C: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80190270: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80190274: addiu       $a2, $a2, 0x3890
    ctx->r6 = ADD32(ctx->r6, 0X3890);
    // 0x80190278: addiu       $v0, $v0, 0x37B4
    ctx->r2 = ADD32(ctx->r2, 0X37B4);
    // 0x8019027C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_80190280:
    // 0x80190280: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190284: addiu       $t8, $t8, 0x3898
    ctx->r24 = ADD32(ctx->r24, 0X3898);
    // 0x80190288: beql        $t7, $zero, L_801902AC
    if (ctx->r15 == 0) {
        // 0x8019028C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801902AC;
    }
    goto skip_31;
    // 0x8019028C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_31:
    // 0x80190290: bne         $v0, $a2, L_801902A0
    if (ctx->r2 != ctx->r6) {
        // 0x80190294: nop
    
            goto L_801902A0;
    }
    // 0x80190294: nop

    // 0x80190298: b           L_801902A8
    // 0x8019029C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801902A8;
    // 0x8019029C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801902A0:
    // 0x801902A0: b           L_801902CC
    // 0x801902A4: nop

        goto L_801902CC;
    // 0x801902A4: nop

L_801902A8:
    // 0x801902A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_801902AC:
    // 0x801902AC: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x801902B0: bnel        $at, $zero, L_80190280
    if (ctx->r1 != 0) {
        // 0x801902B4: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_80190280;
    }
    goto skip_32;
    // 0x801902B4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_32:
    // 0x801902B8: beq         $v1, $zero, L_801902CC
    if (ctx->r3 == 0) {
        // 0x801902BC: nop
    
            goto L_801902CC;
    }
    // 0x801902BC: nop

    // 0x801902C0: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    // 0x801902C4: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x801902C8: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
L_801902CC:
    // 0x801902CC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x801902D0: addiu       $v1, $v1, 0x3898
    ctx->r3 = ADD32(ctx->r3, 0X3898);
    // 0x801902D4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801902D8: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x801902DC: addiu       $a2, $a2, 0x37F4
    ctx->r6 = ADD32(ctx->r6, 0X37F4);
    // 0x801902E0: beq         $v0, $zero, L_80190300
    if (ctx->r2 == 0) {
        // 0x801902E4: nop
    
            goto L_80190300;
    }
    // 0x801902E4: nop

    // 0x801902E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801902EC: bne         $t7, $zero, L_80190300
    if (ctx->r15 != 0) {
        // 0x801902F0: nop
    
            goto L_80190300;
    }
    // 0x801902F0: nop

    // 0x801902F4: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x801902F8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801902FC: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190300:
    // 0x80190300: bne         $v0, $zero, L_80190320
    if (ctx->r2 != 0) {
        // 0x80190304: nop
    
            goto L_80190320;
    }
    // 0x80190304: nop

    // 0x80190308: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8019030C: beq         $t6, $zero, L_80190320
    if (ctx->r14 == 0) {
        // 0x80190310: nop
    
            goto L_80190320;
    }
    // 0x80190310: nop

    // 0x80190314: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x80190318: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8019031C: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
L_80190320:
    // 0x80190320: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80190324: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80190328: addiu       $v0, $v0, 0x37B4
    ctx->r2 = ADD32(ctx->r2, 0X37B4);
    // 0x8019032C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80190330:
    // 0x80190330: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80190334: addiu       $t7, $t7, 0x3898
    ctx->r15 = ADD32(ctx->r15, 0X3898);
    // 0x80190338: beq         $t9, $zero, L_80190368
    if (ctx->r25 == 0) {
        // 0x8019033C: sltu        $at, $v0, $a2
        ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
            goto L_80190368;
    }
    // 0x8019033C: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80190340: bne         $at, $zero, L_80190360
    if (ctx->r1 != 0) {
        // 0x80190344: lui         $t6, 0x8019
        ctx->r14 = S32(0X8019 << 16);
            goto L_80190360;
    }
    // 0x80190344: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190348: addiu       $t6, $t6, 0x382C
    ctx->r14 = ADD32(ctx->r14, 0X382C);
    // 0x8019034C: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80190350: beq         $at, $zero, L_80190360
    if (ctx->r1 == 0) {
        // 0x80190354: nop
    
            goto L_80190360;
    }
    // 0x80190354: nop

    // 0x80190358: b           L_80190368
    // 0x8019035C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80190368;
    // 0x8019035C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80190360:
    // 0x80190360: b           L_801903A8
    // 0x80190364: lbu         $a2, 0x13($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X13);
        goto L_801903A8;
    // 0x80190364: lbu         $a2, 0x13($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X13);
L_80190368:
    // 0x80190368: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019036C: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x80190370: bnel        $at, $zero, L_80190330
    if (ctx->r1 != 0) {
        // 0x80190374: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80190330;
    }
    goto skip_33;
    // 0x80190374: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_33:
    // 0x80190378: beq         $v1, $zero, L_801903A4
    if (ctx->r3 == 0) {
        // 0x8019037C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801903A4;
    }
    // 0x8019037C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190380: bnel        $v1, $at, L_8019039C
    if (ctx->r3 != ctx->r1) {
        // 0x80190384: lw          $t6, 0x30($t2)
        ctx->r14 = MEM_W(ctx->r10, 0X30);
            goto L_8019039C;
    }
    goto skip_34;
    // 0x80190384: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
    skip_34:
    // 0x80190388: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x8019038C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80190390: b           L_801903A4
    // 0x80190394: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
        goto L_801903A4;
    // 0x80190394: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
    // 0x80190398: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
L_8019039C:
    // 0x8019039C: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x801903A0: sw          $t7, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r15;
L_801903A4:
    // 0x801903A4: lbu         $a2, 0x13($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X13);
L_801903A8:
    // 0x801903A8: addiu       $v0, $zero, 0x74
    ctx->r2 = ADD32(0, 0X74);
    // 0x801903AC: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801903B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801903B4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801903B8: mflo        $t8
    ctx->r24 = lo;
    // 0x801903BC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801903C0: lw          $t6, 0x6C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X6C);
    // 0x801903C4: slti        $at, $t6, 0xC8
    ctx->r1 = SIGNED(ctx->r14) < 0XC8 ? 1 : 0;
    // 0x801903C8: bnel        $at, $zero, L_801903E0
    if (ctx->r1 != 0) {
        // 0x801903CC: lw          $t9, 0x0($t5)
        ctx->r25 = MEM_W(ctx->r13, 0X0);
            goto L_801903E0;
    }
    goto skip_35;
    // 0x801903CC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    skip_35:
    // 0x801903D0: lw          $t7, 0x2C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X2C);
    // 0x801903D4: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801903D8: sw          $t8, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r24;
    // 0x801903DC: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
L_801903E0:
    // 0x801903E0: sltiu       $at, $t9, 0x1F
    ctx->r1 = ctx->r25 < 0X1F ? 1 : 0;
    // 0x801903E4: beql        $at, $zero, L_801903FC
    if (ctx->r1 == 0) {
        // 0x801903E8: lbu         $t8, 0x13($t2)
        ctx->r24 = MEM_BU(ctx->r10, 0X13);
            goto L_801903FC;
    }
    goto skip_36;
    // 0x801903E8: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
    skip_36:
    // 0x801903EC: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x801903F0: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x801903F4: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x801903F8: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
L_801903FC:
    // 0x801903FC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190400: mflo        $t9
    ctx->r25 = lo;
    // 0x80190404: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80190408: lw          $t7, 0x54($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X54);
    // 0x8019040C: bne         $t7, $zero, L_80190424
    if (ctx->r15 != 0) {
        // 0x80190410: nop
    
            goto L_80190424;
    }
    // 0x80190410: nop

    // 0x80190414: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x80190418: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8019041C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80190420: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
L_80190424:
    // 0x80190424: lw          $a2, 0xD68($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XD68);
    // 0x80190428: bnel        $a2, $zero, L_80190444
    if (ctx->r6 != 0) {
        // 0x8019042C: lbu         $t8, 0x13($t2)
        ctx->r24 = MEM_BU(ctx->r10, 0X13);
            goto L_80190444;
    }
    goto skip_37;
    // 0x8019042C: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
    skip_37:
    // 0x80190430: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x80190434: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80190438: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8019043C: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x80190440: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
L_80190444:
    // 0x80190444: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190448: mflo        $t9
    ctx->r25 = lo;
    // 0x8019044C: addu        $t5, $v1, $t9
    ctx->r13 = ADD32(ctx->r3, ctx->r25);
    // 0x80190450: lw          $t6, 0x30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X30);
    // 0x80190454: bnel        $t6, $zero, L_80190498
    if (ctx->r14 != 0) {
        // 0x80190458: lw          $t8, 0x6C($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X6C);
            goto L_80190498;
    }
    goto skip_38;
    // 0x80190458: lw          $t8, 0x6C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X6C);
    skip_38:
    // 0x8019045C: lw          $t7, 0x58($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X58);
    // 0x80190460: bnel        $t7, $zero, L_80190498
    if (ctx->r15 != 0) {
        // 0x80190464: lw          $t8, 0x6C($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X6C);
            goto L_80190498;
    }
    goto skip_39;
    // 0x80190464: lw          $t8, 0x6C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X6C);
    skip_39:
    // 0x80190468: lbu         $t6, 0x13($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X13);
    // 0x8019046C: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x80190470: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80190474: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80190478: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019047C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80190480: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80190484: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80190488: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8019048C: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
    // 0x80190490: addu        $t5, $v1, $t7
    ctx->r13 = ADD32(ctx->r3, ctx->r15);
    // 0x80190494: lw          $t8, 0x6C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X6C);
L_80190498:
    // 0x80190498: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8019049C: bne         $t8, $zero, L_801904B4
    if (ctx->r24 != 0) {
        // 0x801904A0: nop
    
            goto L_801904B4;
    }
    // 0x801904A0: nop

    // 0x801904A4: lw          $t9, 0x2C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X2C);
    // 0x801904A8: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x801904AC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x801904B0: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
L_801904B4:
    // 0x801904B4: lw          $t7, 0x33CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X33CC);
    // 0x801904B8: beql        $t7, $zero, L_801904D4
    if (ctx->r15 == 0) {
        // 0x801904BC: slti        $at, $t3, 0x3
        ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
            goto L_801904D4;
    }
    goto skip_40;
    // 0x801904BC: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    skip_40:
    // 0x801904C0: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x801904C4: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x801904C8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801904CC: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
    // 0x801904D0: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
L_801904D4:
    // 0x801904D4: bnel        $at, $zero, L_801904F0
    if (ctx->r1 != 0) {
        // 0x801904D8: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_801904F0;
    }
    goto skip_41;
    // 0x801904D8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    skip_41:
    // 0x801904DC: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x801904E0: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x801904E4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801904E8: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x801904EC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
L_801904F0:
    // 0x801904F0: bne         $at, $zero, L_80190508
    if (ctx->r1 != 0) {
        // 0x801904F4: lui         $t6, 0x8019
        ctx->r14 = S32(0X8019 << 16);
            goto L_80190508;
    }
    // 0x801904F4: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x801904F8: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x801904FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80190500: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80190504: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
L_80190508:
    // 0x80190508: lbu         $t6, 0x36AD($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X36AD);
    // 0x8019050C: beq         $t6, $zero, L_80190524
    if (ctx->r14 == 0) {
        // 0x80190510: nop
    
            goto L_80190524;
    }
    // 0x80190510: nop

    // 0x80190514: lw          $t7, 0x2C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X2C);
    // 0x80190518: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8019051C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80190520: sw          $t8, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r24;
L_80190524:
    // 0x80190524: beq         $t0, $zero, L_801905A4
    if (ctx->r8 == 0) {
        // 0x80190528: sw          $a2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r6;
            goto L_801905A4;
    }
    // 0x80190528: sw          $a2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r6;
    // 0x8019052C: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x80190530: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190534: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80190538: addiu       $t4, $t4, 0x33D0
    ctx->r12 = ADD32(ctx->r12, 0X33D0);
    // 0x8019053C: lbu         $t6, 0x13($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X13);
    // 0x80190540: mflo        $t9
    ctx->r25 = lo;
    // 0x80190544: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x80190548: lw          $t7, -0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X10);
    // 0x8019054C: bnel        $t6, $t7, L_801905A8
    if (ctx->r14 != ctx->r15) {
        // 0x80190550: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_801905A8;
    }
    goto skip_42;
    // 0x80190550: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    skip_42:
    // 0x80190554: lw          $a2, -0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, -0XC);
    // 0x80190558: bne         $a3, $a2, L_80190578
    if (ctx->r7 != ctx->r6) {
        // 0x8019055C: nop
    
            goto L_80190578;
    }
    // 0x8019055C: nop

    // 0x80190560: lw          $v0, -0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X8);
    // 0x80190564: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80190568: bne         $at, $zero, L_80190578
    if (ctx->r1 != 0) {
        // 0x8019056C: slti        $at, $v0, 0x2D
        ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
            goto L_80190578;
    }
    // 0x8019056C: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x80190570: bnel        $at, $zero, L_8019059C
    if (ctx->r1 != 0) {
        // 0x80190574: lw          $t8, 0x30($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X30);
            goto L_8019059C;
    }
    goto skip_43;
    // 0x80190574: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    skip_43:
L_80190578:
    // 0x80190578: bnel        $t1, $a2, L_801905A8
    if (ctx->r9 != ctx->r6) {
        // 0x8019057C: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_801905A8;
    }
    goto skip_44;
    // 0x8019057C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    skip_44:
    // 0x80190580: lw          $v0, -0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X8);
    // 0x80190584: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x80190588: bne         $at, $zero, L_801905A4
    if (ctx->r1 != 0) {
        // 0x8019058C: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_801905A4;
    }
    // 0x8019058C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80190590: beql        $at, $zero, L_801905A8
    if (ctx->r1 == 0) {
        // 0x80190594: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_801905A8;
    }
    goto skip_45;
    // 0x80190594: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    skip_45:
    // 0x80190598: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
L_8019059C:
    // 0x8019059C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x801905A0: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_801905A4:
    // 0x801905A4: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_801905A8:
    // 0x801905A8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x801905AC: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x801905B0: addiu       $t4, $t4, 0x33D0
    ctx->r12 = ADD32(ctx->r12, 0X33D0);
    // 0x801905B4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801905B8: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x801905BC: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x801905C0: beq         $t0, $zero, L_80190610
    if (ctx->r8 == 0) {
        // 0x801905C4: lw          $v0, -0x10($v1)
        ctx->r2 = MEM_W(ctx->r3, -0X10);
            goto L_80190610;
    }
    // 0x801905C4: lw          $v0, -0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X10);
    // 0x801905C8: lbu         $t7, 0x13($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X13);
    // 0x801905CC: bne         $t7, $v0, L_80190610
    if (ctx->r15 != ctx->r2) {
        // 0x801905D0: nop
    
            goto L_80190610;
    }
    // 0x801905D0: nop

    // 0x801905D4: lw          $t8, -0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, -0XC);
    // 0x801905D8: bne         $a3, $t8, L_80190610
    if (ctx->r7 != ctx->r24) {
        // 0x801905DC: nop
    
            goto L_80190610;
    }
    // 0x801905DC: nop

    // 0x801905E0: lw          $t9, -0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X8);
    // 0x801905E4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801905E8: bne         $t9, $at, L_80190610
    if (ctx->r25 != ctx->r1) {
        // 0x801905EC: nop
    
            goto L_80190610;
    }
    // 0x801905EC: nop

    // 0x801905F0: lhu         $t6, -0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, -0X4);
    // 0x801905F4: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x801905F8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x801905FC: bne         $t7, $at, L_80190610
    if (ctx->r15 != ctx->r1) {
        // 0x80190600: nop
    
            goto L_80190610;
    }
    // 0x80190600: nop

    // 0x80190604: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x80190608: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8019060C: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190610:
    // 0x80190610: beq         $t0, $zero, L_8019064C
    if (ctx->r8 == 0) {
        // 0x80190614: nop
    
            goto L_8019064C;
    }
    // 0x80190614: nop

    // 0x80190618: lbu         $t6, 0x13($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X13);
    // 0x8019061C: bne         $t6, $v0, L_8019064C
    if (ctx->r14 != ctx->r2) {
        // 0x80190620: nop
    
            goto L_8019064C;
    }
    // 0x80190620: nop

    // 0x80190624: lhu         $a2, -0x4($v1)
    ctx->r6 = MEM_HU(ctx->r3, -0X4);
    // 0x80190628: andi        $a2, $a2, 0x3FF
    ctx->r6 = ctx->r6 & 0X3FF;
    // 0x8019062C: beql        $a0, $a2, L_80190640
    if (ctx->r4 == ctx->r6) {
        // 0x80190630: lw          $t7, 0x2C($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X2C);
            goto L_80190640;
    }
    goto skip_46;
    // 0x80190630: lw          $t7, 0x2C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X2C);
    skip_46:
    // 0x80190634: bne         $a1, $a2, L_8019064C
    if (ctx->r5 != ctx->r6) {
        // 0x80190638: nop
    
            goto L_8019064C;
    }
    // 0x80190638: nop

    // 0x8019063C: lw          $t7, 0x2C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X2C);
L_80190640:
    // 0x80190640: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80190644: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80190648: sw          $t8, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r24;
L_8019064C:
    // 0x8019064C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80190650: lw          $a0, 0x33C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33C8);
    // 0x80190654: addiu       $at, $zero, 0xBD
    ctx->r1 = ADD32(0, 0XBD);
    // 0x80190658: bne         $a0, $at, L_8019066C
    if (ctx->r4 != ctx->r1) {
        // 0x8019065C: nop
    
            goto L_8019066C;
    }
    // 0x8019065C: nop

    // 0x80190660: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80190664: ori         $t6, $t9, 0x40
    ctx->r14 = ctx->r25 | 0X40;
    // 0x80190668: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
L_8019066C:
    // 0x8019066C: beql        $a0, $zero, L_80190684
    if (ctx->r4 == 0) {
        // 0x80190670: lw          $t7, 0x30($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X30);
            goto L_80190684;
    }
    goto skip_47;
    // 0x80190670: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    skip_47:
    // 0x80190674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190678: bne         $a0, $at, L_8019068C
    if (ctx->r4 != ctx->r1) {
        // 0x8019067C: nop
    
            goto L_8019068C;
    }
    // 0x8019067C: nop

    // 0x80190680: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
L_80190684:
    // 0x80190684: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80190688: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
L_8019068C:
    // 0x8019068C: bne         $t1, $a0, L_801906A0
    if (ctx->r9 != ctx->r4) {
        // 0x80190690: nop
    
            goto L_801906A0;
    }
    // 0x80190690: nop

    // 0x80190694: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80190698: ori         $t6, $t9, 0x100
    ctx->r14 = ctx->r25 | 0X100;
    // 0x8019069C: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
L_801906A0:
    // 0x801906A0: beq         $t0, $zero, L_801906D8
    if (ctx->r8 == 0) {
        // 0x801906A4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_801906D8;
    }
    // 0x801906A4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801906A8: beq         $a0, $v0, L_801906D8
    if (ctx->r4 == ctx->r2) {
        // 0x801906AC: nop
    
            goto L_801906D8;
    }
    // 0x801906AC: nop

    // 0x801906B0: lw          $t7, -0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XC);
    // 0x801906B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801906B8: bne         $t7, $at, L_801906D8
    if (ctx->r15 != ctx->r1) {
        // 0x801906BC: nop
    
            goto L_801906D8;
    }
    // 0x801906BC: nop

    // 0x801906C0: lw          $t8, -0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X8);
    // 0x801906C4: bne         $t8, $zero, L_801906D8
    if (ctx->r24 != 0) {
        // 0x801906C8: nop
    
            goto L_801906D8;
    }
    // 0x801906C8: nop

    // 0x801906CC: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x801906D0: ori         $t6, $t9, 0x200
    ctx->r14 = ctx->r25 | 0X200;
    // 0x801906D4: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
L_801906D8:
    // 0x801906D8: beq         $t0, $zero, L_80190704
    if (ctx->r8 == 0) {
        // 0x801906DC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80190704;
    }
    // 0x801906DC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801906E0: beql        $a0, $v0, L_80190708
    if (ctx->r4 == ctx->r2) {
        // 0x801906E4: lbu         $t9, 0x13($t2)
        ctx->r25 = MEM_BU(ctx->r10, 0X13);
            goto L_80190708;
    }
    goto skip_48;
    // 0x801906E4: lbu         $t9, 0x13($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X13);
    skip_48:
    // 0x801906E8: lw          $t7, -0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, -0XC);
    // 0x801906EC: bnel        $a3, $t7, L_80190708
    if (ctx->r7 != ctx->r15) {
        // 0x801906F0: lbu         $t9, 0x13($t2)
        ctx->r25 = MEM_BU(ctx->r10, 0X13);
            goto L_80190708;
    }
    goto skip_49;
    // 0x801906F0: lbu         $t9, 0x13($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X13);
    skip_49:
    // 0x801906F4: lw          $t8, -0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X8);
    // 0x801906F8: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x801906FC: beql        $t8, $at, L_80190730
    if (ctx->r24 == ctx->r1) {
        // 0x80190700: lw          $t8, 0x30($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X30);
            goto L_80190730;
    }
    goto skip_50;
    // 0x80190700: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    skip_50:
L_80190704:
    // 0x80190704: lbu         $t9, 0x13($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X13);
L_80190708:
    // 0x80190708: bne         $t9, $v0, L_80190738
    if (ctx->r25 != ctx->r2) {
        // 0x8019070C: nop
    
            goto L_80190738;
    }
    // 0x8019070C: nop

    // 0x80190710: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x80190714: bne         $a3, $t6, L_80190738
    if (ctx->r7 != ctx->r14) {
        // 0x80190718: nop
    
            goto L_80190738;
    }
    // 0x80190718: nop

    // 0x8019071C: lw          $t7, -0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X8);
    // 0x80190720: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80190724: bne         $t7, $at, L_80190738
    if (ctx->r15 != ctx->r1) {
        // 0x80190728: nop
    
            goto L_80190738;
    }
    // 0x80190728: nop

    // 0x8019072C: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
L_80190730:
    // 0x80190730: ori         $t9, $t8, 0x400
    ctx->r25 = ctx->r24 | 0X400;
    // 0x80190734: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190738:
    // 0x80190738: beq         $t0, $zero, L_80190770
    if (ctx->r8 == 0) {
        // 0x8019073C: nop
    
            goto L_80190770;
    }
    // 0x8019073C: nop

    // 0x80190740: beq         $a0, $v0, L_80190770
    if (ctx->r4 == ctx->r2) {
        // 0x80190744: nop
    
            goto L_80190770;
    }
    // 0x80190744: nop

    // 0x80190748: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x8019074C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80190750: bne         $t6, $at, L_80190770
    if (ctx->r14 != ctx->r1) {
        // 0x80190754: nop
    
            goto L_80190770;
    }
    // 0x80190754: nop

    // 0x80190758: lw          $t7, -0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, -0X8);
    // 0x8019075C: bne         $t1, $t7, L_80190770
    if (ctx->r9 != ctx->r15) {
        // 0x80190760: nop
    
            goto L_80190770;
    }
    // 0x80190760: nop

    // 0x80190764: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x80190768: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x8019076C: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190770:
    // 0x80190770: beql        $t0, $zero, L_801907B8
    if (ctx->r8 == 0) {
        // 0x80190774: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_801907B8;
    }
    goto skip_51;
    // 0x80190774: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    skip_51:
    // 0x80190778: beql        $a0, $v0, L_801907B8
    if (ctx->r4 == ctx->r2) {
        // 0x8019077C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_801907B8;
    }
    goto skip_52;
    // 0x8019077C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    skip_52:
    // 0x80190780: lw          $t6, -0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, -0XC);
    // 0x80190784: bnel        $t1, $t6, L_801907B8
    if (ctx->r9 != ctx->r14) {
        // 0x80190788: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_801907B8;
    }
    goto skip_53;
    // 0x80190788: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    skip_53:
    // 0x8019078C: lw          $v0, -0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X8);
    // 0x80190790: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80190794: beql        $v0, $at, L_801907AC
    if (ctx->r2 == ctx->r1) {
        // 0x80190798: lw          $t7, 0x30($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X30);
            goto L_801907AC;
    }
    goto skip_54;
    // 0x80190798: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    skip_54:
    // 0x8019079C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801907A0: bnel        $v0, $at, L_801907B8
    if (ctx->r2 != ctx->r1) {
        // 0x801907A4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_801907B8;
    }
    goto skip_55;
    // 0x801907A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    skip_55:
    // 0x801907A8: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
L_801907AC:
    // 0x801907AC: ori         $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 | 0X1000;
    // 0x801907B0: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
    // 0x801907B4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_801907B8:
    // 0x801907B8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x801907BC: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x801907C0: beq         $v0, $a0, L_801907EC
    if (ctx->r2 == ctx->r4) {
        // 0x801907C4: nop
    
            goto L_801907EC;
    }
    // 0x801907C4: nop

    // 0x801907C8: lw          $t9, 0x1C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X1C);
    // 0x801907CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801907D0: bne         $t9, $at, L_801907EC
    if (ctx->r25 != ctx->r1) {
        // 0x801907D4: nop
    
            goto L_801907EC;
    }
    // 0x801907D4: nop

    // 0x801907D8: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
    // 0x801907DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801907E0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801907E4: sw          $t7, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r15;
    // 0x801907E8: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
L_801907EC:
    // 0x801907EC: beql        $v0, $a0, L_80190818
    if (ctx->r2 == ctx->r4) {
        // 0x801907F0: lbu         $t7, 0x13($t2)
        ctx->r15 = MEM_BU(ctx->r10, 0X13);
            goto L_80190818;
    }
    goto skip_56;
    // 0x801907F0: lbu         $t7, 0x13($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X13);
    skip_56:
    // 0x801907F4: lw          $t8, 0x1C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X1C);
    // 0x801907F8: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x801907FC: bnel        $t8, $at, L_80190818
    if (ctx->r24 != ctx->r1) {
        // 0x80190800: lbu         $t7, 0x13($t2)
        ctx->r15 = MEM_BU(ctx->r10, 0X13);
            goto L_80190818;
    }
    goto skip_57;
    // 0x80190800: lbu         $t7, 0x13($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X13);
    skip_57:
    // 0x80190804: lw          $t9, 0x30($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X30);
    // 0x80190808: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8019080C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80190810: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x80190814: lbu         $t7, 0x13($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X13);
L_80190818:
    // 0x80190818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019081C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80190820: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80190824: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80190828: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019082C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80190830: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80190834: lw          $a0, 0x6C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X6C);
    // 0x80190838: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x8019083C: mflo        $a3
    ctx->r7 = lo;
    // 0x80190840: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80190844: bne         $v0, $zero, L_80190850
    if (ctx->r2 != 0) {
        // 0x80190848: nop
    
            goto L_80190850;
    }
    // 0x80190848: nop

    // 0x8019084C: break       7
    do_break(2149124172);
L_80190850:
    // 0x80190850: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80190854: bne         $v0, $at, L_80190868
    if (ctx->r2 != ctx->r1) {
        // 0x80190858: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80190868;
    }
    // 0x80190858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019085C: bne         $a0, $at, L_80190868
    if (ctx->r4 != ctx->r1) {
        // 0x80190860: nop
    
            goto L_80190868;
    }
    // 0x80190860: nop

    // 0x80190864: break       6
    do_break(2149124196);
L_80190868:
    // 0x80190868: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019086C: mflo        $t6
    ctx->r14 = lo;
    // 0x80190870: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x80190874: beq         $a3, $zero, L_801908CC
    if (ctx->r7 == 0) {
        // 0x80190878: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_801908CC;
    }
    // 0x80190878: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019087C: div         $zero, $a0, $a3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r7)));
    // 0x80190880: mflo        $v0
    ctx->r2 = lo;
    // 0x80190884: bne         $a3, $zero, L_80190890
    if (ctx->r7 != 0) {
        // 0x80190888: nop
    
            goto L_80190890;
    }
    // 0x80190888: nop

    // 0x8019088C: break       7
    do_break(2149124236);
L_80190890:
    // 0x80190890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80190894: bne         $a3, $at, L_801908A8
    if (ctx->r7 != ctx->r1) {
        // 0x80190898: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801908A8;
    }
    // 0x80190898: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019089C: bne         $a0, $at, L_801908A8
    if (ctx->r4 != ctx->r1) {
        // 0x801908A0: nop
    
            goto L_801908A8;
    }
    // 0x801908A0: nop

    // 0x801908A4: break       6
    do_break(2149124260);
L_801908A8:
    // 0x801908A8: bne         $a2, $v0, L_8019091C
    if (ctx->r6 != ctx->r2) {
        // 0x801908AC: nop
    
            goto L_8019091C;
    }
    // 0x801908AC: nop

    // 0x801908B0: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801908B4: mflo        $t7
    ctx->r15 = lo;
    // 0x801908B8: subu        $t8, $a0, $t7
    ctx->r24 = SUB32(ctx->r4, ctx->r15);
    // 0x801908BC: bne         $v0, $t8, L_8019091C
    if (ctx->r2 != ctx->r24) {
        // 0x801908C0: nop
    
            goto L_8019091C;
    }
    // 0x801908C0: nop

    // 0x801908C4: b           L_8019091C
    // 0x801908C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8019091C;
    // 0x801908C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801908CC:
    // 0x801908CC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x801908D0: div         $zero, $a0, $a3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r7)));
    // 0x801908D4: mflo        $v0
    ctx->r2 = lo;
    // 0x801908D8: bne         $a3, $zero, L_801908E4
    if (ctx->r7 != 0) {
        // 0x801908DC: nop
    
            goto L_801908E4;
    }
    // 0x801908DC: nop

    // 0x801908E0: break       7
    do_break(2149124320);
L_801908E4:
    // 0x801908E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801908E8: bne         $a3, $at, L_801908FC
    if (ctx->r7 != ctx->r1) {
        // 0x801908EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801908FC;
    }
    // 0x801908EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801908F0: bne         $a0, $at, L_801908FC
    if (ctx->r4 != ctx->r1) {
        // 0x801908F4: nop
    
            goto L_801908FC;
    }
    // 0x801908F4: nop

    // 0x801908F8: break       6
    do_break(2149124344);
L_801908FC:
    // 0x801908FC: beq         $v0, $zero, L_8019091C
    if (ctx->r2 == 0) {
        // 0x80190900: nop
    
            goto L_8019091C;
    }
    // 0x80190900: nop

    // 0x80190904: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190908: mflo        $t9
    ctx->r25 = lo;
    // 0x8019090C: subu        $t6, $a0, $t9
    ctx->r14 = SUB32(ctx->r4, ctx->r25);
    // 0x80190910: bne         $v0, $t6, L_8019091C
    if (ctx->r2 != ctx->r14) {
        // 0x80190914: nop
    
            goto L_8019091C;
    }
    // 0x80190914: nop

    // 0x80190918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8019091C:
    // 0x8019091C: beql        $a1, $zero, L_80190938
    if (ctx->r5 == 0) {
        // 0x80190920: lbu         $t3, 0x17($t2)
        ctx->r11 = MEM_BU(ctx->r10, 0X17);
            goto L_80190938;
    }
    goto skip_58;
    // 0x80190920: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    skip_58:
    // 0x80190924: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x80190928: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8019092C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80190930: sw          $t8, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r24;
    // 0x80190934: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
L_80190938:
    // 0x80190938: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019093C: bne         $t3, $at, L_80190A5C
    if (ctx->r11 != ctx->r1) {
        // 0x80190940: lui         $t9, 0x8019
        ctx->r25 = S32(0X8019 << 16);
            goto L_80190A5C;
    }
    // 0x80190940: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80190944: lbu         $t9, 0x2FA1($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2FA1);
    // 0x80190948: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8019094C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80190950: bne         $t9, $zero, L_80190A5C
    if (ctx->r25 != 0) {
        // 0x80190954: addiu       $a1, $a1, 0x2FB0
        ctx->r5 = ADD32(ctx->r5, 0X2FB0);
            goto L_80190A5C;
    }
    // 0x80190954: addiu       $a1, $a1, 0x2FB0
    ctx->r5 = ADD32(ctx->r5, 0X2FB0);
    // 0x80190958: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8019095C: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190960: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190964: lw          $t6, 0x33D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X33D0);
    // 0x80190968: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8019096C: lw          $t9, 0x33E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33E8);
    // 0x80190970: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80190974: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80190978: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x8019097C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80190980: sb          $t8, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r24;
    // 0x80190984: mflo        $t8
    ctx->r24 = lo;
    // 0x80190988: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
    // 0x8019098C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80190990: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x80190994: sb          $t7, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r15;
    // 0x80190998: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x8019099C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x801909A0: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x801909A4: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x801909A8: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x801909AC: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x801909B0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x801909B4: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x801909B8: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    // 0x801909BC: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x801909C0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x801909C4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x801909C8: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x801909CC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x801909D0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801909D4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801909D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801909DC: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x801909E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801909E4: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x801909E8: beq         $at, $zero, L_80190A40
    if (ctx->r1 == 0) {
        // 0x801909EC: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_80190A40;
    }
    // 0x801909EC: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
    // 0x801909F0: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x801909F4: addu        $a2, $t0, $t9
    ctx->r6 = ADD32(ctx->r8, ctx->r25);
    // 0x801909F8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x801909FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80190A00:
    // 0x80190A00: addu        $t9, $t1, $a0
    ctx->r25 = ADD32(ctx->r9, ctx->r4);
    // 0x80190A04: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80190A08: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80190A0C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80190A10: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80190A14: beq         $t8, $t6, L_80190A20
    if (ctx->r24 == ctx->r14) {
        // 0x80190A18: nop
    
            goto L_80190A20;
    }
    // 0x80190A18: nop

    // 0x80190A1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80190A20:
    // 0x80190A20: bne         $a0, $t0, L_80190A30
    if (ctx->r4 != ctx->r8) {
        // 0x80190A24: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80190A30;
    }
    // 0x80190A24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80190A28: b           L_80190A34
    // 0x80190A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80190A34;
    // 0x80190A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80190A30:
    // 0x80190A30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80190A34:
    // 0x80190A34: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x80190A38: bnel        $at, $zero, L_80190A00
    if (ctx->r1 != 0) {
        // 0x80190A3C: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80190A00;
    }
    goto skip_59;
    // 0x80190A3C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_59:
L_80190A40:
    // 0x80190A40: beql        $a3, $zero, L_80190A60
    if (ctx->r7 == 0) {
        // 0x80190A44: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80190A60;
    }
    goto skip_60;
    // 0x80190A44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_60:
    // 0x80190A48: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x80190A4C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80190A50: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    // 0x80190A54: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80190A58: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190A5C:
    // 0x80190A5C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80190A60:
    // 0x80190A60: bne         $t3, $at, L_80190B84
    if (ctx->r11 != ctx->r1) {
        // 0x80190A64: lui         $t8, 0x8019
        ctx->r24 = S32(0X8019 << 16);
            goto L_80190B84;
    }
    // 0x80190A64: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190A68: lbu         $t8, 0x2FA1($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2FA1);
    // 0x80190A6C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80190A70: addiu       $v1, $v1, 0x2800
    ctx->r3 = ADD32(ctx->r3, 0X2800);
    // 0x80190A74: bne         $t8, $zero, L_80190B84
    if (ctx->r24 != 0) {
        // 0x80190A78: lui         $t6, 0x8019
        ctx->r14 = S32(0X8019 << 16);
            goto L_80190B84;
    }
    // 0x80190A78: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190A7C: lw          $t6, 0x33D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X33D0);
    // 0x80190A80: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190A84: lbu         $t8, 0x2800($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2800);
    // 0x80190A88: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80190A8C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80190A90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80190A94: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190A98: beq         $t9, $t8, L_80190AA4
    if (ctx->r25 == ctx->r24) {
        // 0x80190A9C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80190AA4;
    }
    // 0x80190A9C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80190AA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80190AA4:
    // 0x80190AA4: lw          $t6, 0x33E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X33E8);
    // 0x80190AA8: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190AAC: lbu         $t8, 0x2801($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2801);
    // 0x80190AB0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80190AB4: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80190AB8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80190ABC: beq         $t9, $t8, L_80190AC8
    if (ctx->r25 == ctx->r24) {
        // 0x80190AC0: nop
    
            goto L_80190AC8;
    }
    // 0x80190AC0: nop

    // 0x80190AC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80190AC8:
    // 0x80190AC8: lw          $t6, 0x3400($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3400);
    // 0x80190ACC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190AD0: lbu         $t8, 0x2802($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2802);
    // 0x80190AD4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80190AD8: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80190ADC: beq         $t9, $t8, L_80190AE8
    if (ctx->r25 == ctx->r24) {
        // 0x80190AE0: nop
    
            goto L_80190AE8;
    }
    // 0x80190AE0: nop

    // 0x80190AE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80190AE8:
    // 0x80190AE8: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80190AEC: addu        $a0, $v1, $a2
    ctx->r4 = ADD32(ctx->r3, ctx->r6);
    // 0x80190AF0: mflo        $t6
    ctx->r14 = lo;
    // 0x80190AF4: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x80190AF8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80190AFC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80190B00: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x80190B04: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80190B08: beql        $t8, $t6, L_80190B18
    if (ctx->r24 == ctx->r14) {
        // 0x80190B0C: lw          $t7, 0x18($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X18);
            goto L_80190B18;
    }
    goto skip_61;
    // 0x80190B0C: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    skip_61:
    // 0x80190B10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80190B14: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
L_80190B18:
    // 0x80190B18: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80190B1C: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x80190B20: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80190B24: beql        $t8, $t6, L_80190B34
    if (ctx->r24 == ctx->r14) {
        // 0x80190B28: lw          $t7, 0x30($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X30);
            goto L_80190B34;
    }
    goto skip_62;
    // 0x80190B28: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    skip_62:
    // 0x80190B2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80190B30: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
L_80190B34:
    // 0x80190B34: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x80190B38: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x80190B3C: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80190B40: beql        $t8, $t6, L_80190B50
    if (ctx->r24 == ctx->r14) {
        // 0x80190B44: lw          $t7, 0x48($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X48);
            goto L_80190B50;
    }
    goto skip_63;
    // 0x80190B44: lw          $t7, 0x48($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X48);
    skip_63:
    // 0x80190B48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80190B4C: lw          $t7, 0x48($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X48);
L_80190B50:
    // 0x80190B50: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x80190B54: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x80190B58: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80190B5C: beq         $t8, $t6, L_80190B68
    if (ctx->r24 == ctx->r14) {
        // 0x80190B60: nop
    
            goto L_80190B68;
    }
    // 0x80190B60: nop

    // 0x80190B64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80190B68:
    // 0x80190B68: beql        $a3, $zero, L_80190B88
    if (ctx->r7 == 0) {
        // 0x80190B6C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80190B88;
    }
    goto skip_64;
    // 0x80190B6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_64:
    // 0x80190B70: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    // 0x80190B74: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80190B78: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    // 0x80190B7C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80190B80: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190B84:
    // 0x80190B84: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80190B88:
    // 0x80190B88: bne         $t3, $at, L_80190C08
    if (ctx->r11 != ctx->r1) {
        // 0x80190B8C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80190C08;
    }
    // 0x80190B8C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80190B90: lbu         $t8, 0x18($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X18);
    // 0x80190B94: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80190B98: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80190B9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190BA0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80190BA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190BA8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80190BAC: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80190BB0: bne         $t7, $zero, L_80190BE8
    if (ctx->r15 != 0) {
        // 0x80190BB4: nop
    
            goto L_80190BE8;
    }
    // 0x80190BB4: nop

    // 0x80190BB8: lw          $t9, 0x58($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X58);
    // 0x80190BBC: bnel        $t9, $zero, L_80190BDC
    if (ctx->r25 != 0) {
        // 0x80190BC0: lw          $t7, 0x30($t2)
        ctx->r15 = MEM_W(ctx->r10, 0X30);
            goto L_80190BDC;
    }
    goto skip_65;
    // 0x80190BC0: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
    skip_65:
    // 0x80190BC4: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x80190BC8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80190BCC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80190BD0: b           L_80190BE8
    // 0x80190BD4: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
        goto L_80190BE8;
    // 0x80190BD4: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x80190BD8: lw          $t7, 0x30($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X30);
L_80190BDC:
    // 0x80190BDC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80190BE0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80190BE4: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190BE8:
    // 0x80190BE8: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80190BEC: lw          $t8, 0x36A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X36A4);
    // 0x80190BF0: beql        $t8, $zero, L_80190C0C
    if (ctx->r24 == 0) {
        // 0x80190BF4: lbu         $t3, 0x17($t2)
        ctx->r11 = MEM_BU(ctx->r10, 0X17);
            goto L_80190C0C;
    }
    goto skip_66;
    // 0x80190BF4: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    skip_66:
    // 0x80190BF8: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
    // 0x80190BFC: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x80190C00: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80190C04: sw          $t7, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r15;
L_80190C08:
    // 0x80190C08: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
L_80190C0C:
    // 0x80190C0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80190C10: bnel        $t3, $at, L_80190CB4
    if (ctx->r11 != ctx->r1) {
        // 0x80190C14: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80190CB4;
    }
    goto skip_67;
    // 0x80190C14: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_67:
    // 0x80190C18: lbu         $t8, 0x18($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X18);
    // 0x80190C1C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80190C20: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80190C24: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80190C28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190C2C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80190C30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190C34: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80190C38: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80190C3C: bnel        $t7, $zero, L_80190CB4
    if (ctx->r15 != 0) {
        // 0x80190C40: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80190CB4;
    }
    goto skip_68;
    // 0x80190C40: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_68:
    // 0x80190C44: lbu         $t8, 0x19($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X19);
    // 0x80190C48: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80190C4C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80190C50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190C54: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80190C58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190C5C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80190C60: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80190C64: bnel        $t7, $zero, L_80190CB4
    if (ctx->r15 != 0) {
        // 0x80190C68: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80190CB4;
    }
    goto skip_69;
    // 0x80190C68: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_69:
    // 0x80190C6C: lw          $t8, 0x58($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X58);
    // 0x80190C70: bnel        $t8, $zero, L_80190CA0
    if (ctx->r24 != 0) {
        // 0x80190C74: lw          $t8, 0x30($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X30);
            goto L_80190CA0;
    }
    goto skip_70;
    // 0x80190C74: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    skip_70:
    // 0x80190C78: lw          $t9, 0x58($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X58);
    // 0x80190C7C: bnel        $t9, $zero, L_80190CA0
    if (ctx->r25 != 0) {
        // 0x80190C80: lw          $t8, 0x30($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X30);
            goto L_80190CA0;
    }
    goto skip_71;
    // 0x80190C80: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    skip_71:
    // 0x80190C84: lw          $t6, 0x30($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X30);
    // 0x80190C88: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80190C8C: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    // 0x80190C90: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80190C94: b           L_80190CB0
    // 0x80190C98: sw          $t7, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r15;
        goto L_80190CB0;
    // 0x80190C98: sw          $t7, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r15;
    // 0x80190C9C: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
L_80190CA0:
    // 0x80190CA0: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x80190CA4: lbu         $t3, 0x17($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X17);
    // 0x80190CA8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80190CAC: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
L_80190CB0:
    // 0x80190CB0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_80190CB4:
    // 0x80190CB4: bnel        $t3, $at, L_80190D48
    if (ctx->r11 != ctx->r1) {
        // 0x80190CB8: lw          $v1, 0x30($t2)
        ctx->r3 = MEM_W(ctx->r10, 0X30);
            goto L_80190D48;
    }
    goto skip_72;
    // 0x80190CB8: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    skip_72:
    // 0x80190CBC: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x80190CC0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80190CC4: lui         $at, 0x40
    ctx->r1 = S32(0X40 << 16);
    // 0x80190CC8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80190CCC: bne         $t8, $zero, L_80190CE0
    if (ctx->r24 != 0) {
        // 0x80190CD0: sw          $t7, 0x2C($t2)
        MEM_W(0X2C, ctx->r10) = ctx->r15;
            goto L_80190CE0;
    }
    // 0x80190CD0: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x80190CD4: lui         $at, 0x80
    ctx->r1 = S32(0X80 << 16);
    // 0x80190CD8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80190CDC: sw          $t6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r14;
L_80190CE0:
    // 0x80190CE0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80190CE4: lw          $t7, 0xD6C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD6C);
    // 0x80190CE8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80190CEC: bne         $t7, $zero, L_80190D04
    if (ctx->r15 != 0) {
        // 0x80190CF0: nop
    
            goto L_80190D04;
    }
    // 0x80190CF0: nop

    // 0x80190CF4: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x80190CF8: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80190CFC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80190D00: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
L_80190D04:
    // 0x80190D04: lw          $v0, 0x38B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38B4);
    // 0x80190D08: sltiu       $at, $v0, 0x1E1
    ctx->r1 = ctx->r2 < 0X1E1 ? 1 : 0;
    // 0x80190D0C: beql        $at, $zero, L_80190D2C
    if (ctx->r1 == 0) {
        // 0x80190D10: sltiu       $at, $v0, 0x2D1
        ctx->r1 = ctx->r2 < 0X2D1 ? 1 : 0;
            goto L_80190D2C;
    }
    goto skip_73;
    // 0x80190D10: sltiu       $at, $v0, 0x2D1
    ctx->r1 = ctx->r2 < 0X2D1 ? 1 : 0;
    skip_73:
    // 0x80190D14: lw          $t6, 0x2C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X2C);
    // 0x80190D18: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80190D1C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80190D20: b           L_80190D44
    // 0x80190D24: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
        goto L_80190D44;
    // 0x80190D24: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
    // 0x80190D28: sltiu       $at, $v0, 0x2D1
    ctx->r1 = ctx->r2 < 0X2D1 ? 1 : 0;
L_80190D2C:
    // 0x80190D2C: beql        $at, $zero, L_80190D48
    if (ctx->r1 == 0) {
        // 0x80190D30: lw          $v1, 0x30($t2)
        ctx->r3 = MEM_W(ctx->r10, 0X30);
            goto L_80190D48;
    }
    goto skip_74;
    // 0x80190D30: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
    skip_74:
    // 0x80190D34: lw          $t8, 0x2C($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X2C);
    // 0x80190D38: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80190D3C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80190D40: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
L_80190D44:
    // 0x80190D44: lw          $v1, 0x30($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X30);
L_80190D48:
    // 0x80190D48: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
    // 0x80190D4C: bne         $t6, $zero, L_80190E50
    if (ctx->r14 != 0) {
        // 0x80190D50: andi        $t7, $v1, 0x4
        ctx->r15 = ctx->r3 & 0X4;
            goto L_80190E50;
    }
    // 0x80190D50: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x80190D54: bne         $t7, $zero, L_80190E50
    if (ctx->r15 != 0) {
        // 0x80190D58: nop
    
            goto L_80190E50;
    }
    // 0x80190D58: nop

    // 0x80190D5C: lw          $v0, 0x2C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2C);
    // 0x80190D60: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80190D64: bne         $t8, $zero, L_80190E50
    if (ctx->r24 != 0) {
        // 0x80190D68: andi        $t9, $v0, 0x10
        ctx->r25 = ctx->r2 & 0X10;
            goto L_80190E50;
    }
    // 0x80190D68: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x80190D6C: bne         $t9, $zero, L_80190E50
    if (ctx->r25 != 0) {
        // 0x80190D70: andi        $t6, $v0, 0x40
        ctx->r14 = ctx->r2 & 0X40;
            goto L_80190E50;
    }
    // 0x80190D70: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x80190D74: bne         $t6, $zero, L_80190E50
    if (ctx->r14 != 0) {
        // 0x80190D78: andi        $t7, $v0, 0x100
        ctx->r15 = ctx->r2 & 0X100;
            goto L_80190E50;
    }
    // 0x80190D78: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80190D7C: bne         $t7, $zero, L_80190E50
    if (ctx->r15 != 0) {
        // 0x80190D80: andi        $t8, $v0, 0x200
        ctx->r24 = ctx->r2 & 0X200;
            goto L_80190E50;
    }
    // 0x80190D80: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80190D84: bne         $t8, $zero, L_80190E50
    if (ctx->r24 != 0) {
        // 0x80190D88: andi        $t9, $v0, 0x800
        ctx->r25 = ctx->r2 & 0X800;
            goto L_80190E50;
    }
    // 0x80190D88: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x80190D8C: bne         $t9, $zero, L_80190E50
    if (ctx->r25 != 0) {
        // 0x80190D90: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_80190E50;
    }
    // 0x80190D90: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80190D94: bne         $t6, $zero, L_80190E50
    if (ctx->r14 != 0) {
        // 0x80190D98: sll         $t7, $v0, 14
        ctx->r15 = S32(ctx->r2 << 14);
            goto L_80190E50;
    }
    // 0x80190D98: sll         $t7, $v0, 14
    ctx->r15 = S32(ctx->r2 << 14);
    // 0x80190D9C: bltz        $t7, L_80190E50
    if (SIGNED(ctx->r15) < 0) {
        // 0x80190DA0: andi        $t8, $v1, 0x1
        ctx->r24 = ctx->r3 & 0X1;
            goto L_80190E50;
    }
    // 0x80190DA0: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x80190DA4: bne         $t8, $zero, L_80190E50
    if (ctx->r24 != 0) {
        // 0x80190DA8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80190E50;
    }
    // 0x80190DA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80190DAC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80190DB0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80190DB4: addiu       $a1, $a1, 0x3798
    ctx->r5 = ADD32(ctx->r5, 0X3798);
    // 0x80190DB8: addiu       $v1, $v1, 0x36B4
    ctx->r3 = ADD32(ctx->r3, 0X36B4);
L_80190DBC:
    // 0x80190DBC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80190DC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80190DC4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80190DC8: bne         $at, $zero, L_80190DBC
    if (ctx->r1 != 0) {
        // 0x80190DCC: addu        $a0, $a0, $t9
        ctx->r4 = ADD32(ctx->r4, ctx->r25);
            goto L_80190DBC;
    }
    // 0x80190DCC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80190DD0: beq         $a0, $zero, L_80190E50
    if (ctx->r4 == 0) {
        // 0x80190DD4: lui         $v1, 0x8019
        ctx->r3 = S32(0X8019 << 16);
            goto L_80190E50;
    }
    // 0x80190DD4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80190DD8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80190DDC: addiu       $v1, $v1, 0x36B4
    ctx->r3 = ADD32(ctx->r3, 0X36B4);
    // 0x80190DE0: bgez        $a0, L_80190DF8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80190DE4: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80190DF8;
    }
    // 0x80190DE4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80190DE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190DF0: nop

    // 0x80190DF4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80190DF8:
    // 0x80190DF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80190DFC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80190E00: addiu       $a0, $a0, 0x3798
    ctx->r4 = ADD32(ctx->r4, 0X3798);
    // 0x80190E04: lwc1        $f2, 0x2F64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X2F64);
    // 0x80190E08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80190E0C:
    // 0x80190E0C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80190E10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190E14: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80190E18: bgez        $t6, L_80190E2C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80190E1C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80190E2C;
    }
    // 0x80190E1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80190E20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190E24: nop

    // 0x80190E28: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80190E2C:
    // 0x80190E2C: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80190E30: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x80190E34: nop

    // 0x80190E38: bc1f        L_80190E48
    if (!c1cs) {
        // 0x80190E3C: ori         $t7, $v0, 0x1
        ctx->r15 = ctx->r2 | 0X1;
            goto L_80190E48;
    }
    // 0x80190E3C: ori         $t7, $v0, 0x1
    ctx->r15 = ctx->r2 | 0X1;
    // 0x80190E40: b           L_80190E50
    // 0x80190E44: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
        goto L_80190E50;
    // 0x80190E44: sw          $t7, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r15;
L_80190E48:
    // 0x80190E48: bnel        $v1, $a0, L_80190E0C
    if (ctx->r3 != ctx->r4) {
        // 0x80190E4C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80190E0C;
    }
    goto skip_75;
    // 0x80190E4C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_75:
L_80190E50:
    // 0x80190E50: jr          $ra
    // 0x80190E54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80190E54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mnPlayersVSPortraitFlashThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801363DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801363E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801363E4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801363E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801363EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801363F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801363F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801363F8: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x801363FC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80136400: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80136404: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80136408:
    // 0x80136408: bne         $s2, $zero, L_80136418
    if (ctx->r18 != 0) {
        // 0x8013640C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80136418;
    }
    // 0x8013640C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80136410: jal         0x80136388
    // 0x80136414: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    mnPlayersVSDestroyPortraitFlash(rdram, ctx);
        goto after_0;
    // 0x80136414: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    after_0:
L_80136418:
    // 0x80136418: bne         $s0, $zero, L_8013643C
    if (ctx->r16 != 0) {
        // 0x8013641C: nop
    
            goto L_8013643C;
    }
    // 0x8013641C: nop

    // 0x80136420: lw          $t6, 0x7C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X7C);
    // 0x80136424: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80136428: bnel        $s3, $t6, L_8013643C
    if (ctx->r19 != ctx->r14) {
        // 0x8013642C: sw          $s3, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->r19;
            goto L_8013643C;
    }
    goto skip_0;
    // 0x8013642C: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
    skip_0:
    // 0x80136430: b           L_8013643C
    // 0x80136434: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
        goto L_8013643C;
    // 0x80136434: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x80136438: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
L_8013643C:
    // 0x8013643C: jal         0x8000B1E8
    // 0x80136440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x80136440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80136444: b           L_80136408
    // 0x80136448: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80136408;
    // 0x80136448: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8013644C: nop

    // 0x80136450: nop

    // 0x80136454: nop

    // 0x80136458: nop

    // 0x8013645C: nop

    // 0x80136460: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136464: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013646C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80136470: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80136474: jr          $ra
    // 0x80136478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80136478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayersVSUpdateCursorDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801361FC: beq         $a0, $zero, L_801362F0
    if (ctx->r4 == 0) {
        // 0x80136200: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801362F0;
    }
    // 0x80136200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136204: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80136208: lui         $at, 0x42F4
    ctx->r1 = S32(0X42F4 << 16);
    // 0x8013620C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136210: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x80136214: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80136218: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8013621C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80136220: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80136224: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80136228: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8013622C: bc1t        L_80136258
    if (c1cs) {
        // 0x80136230: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80136258;
    }
    // 0x80136230: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80136234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136238: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8013623C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80136240: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80136244: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80136248: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8013624C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80136250: bc1f        L_80136288
    if (!c1cs) {
        // 0x80136254: lui         $t1, 0x8014
        ctx->r9 = S32(0X8014 << 16);
            goto L_80136288;
    }
    // 0x80136254: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
L_80136258:
    // 0x80136258: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013625C: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x80136260: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80136264: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80136268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013626C: beql        $t9, $zero, L_801362F4
    if (ctx->r25 == 0) {
        // 0x80136270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801362F4;
    }
    goto skip_0;
    // 0x80136270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80136274: jal         0x80134D54
    // 0x80136278: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_0;
    // 0x80136278: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013627C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80136280: b           L_801362F0
    // 0x80136284: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
        goto L_801362F0;
    // 0x80136284: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_80136288:
    // 0x80136288: addiu       $t1, $t1, -0x4578
    ctx->r9 = ADD32(ctx->r9, -0X4578);
    // 0x8013628C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80136290: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x80136294: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80136298: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8013629C: beq         $v1, $t2, L_801362B4
    if (ctx->r3 == ctx->r10) {
        // 0x801362A0: nop
    
            goto L_801362B4;
    }
    // 0x801362A0: nop

    // 0x801362A4: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x801362A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801362AC: bnel        $t3, $at, L_801362D0
    if (ctx->r11 != ctx->r1) {
        // 0x801362B0: lw          $t5, 0x54($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X54);
            goto L_801362D0;
    }
    goto skip_1;
    // 0x801362B0: lw          $t5, 0x54($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X54);
    skip_1:
L_801362B4:
    // 0x801362B4: jal         0x80134D54
    // 0x801362B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x801362B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801362BC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801362C0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801362C4: b           L_801362F0
    // 0x801362C8: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
        goto L_801362F0;
    // 0x801362C8: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
    // 0x801362CC: lw          $t5, 0x54($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X54);
L_801362D0:
    // 0x801362D0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x801362D4: beql        $v1, $t5, L_801362F4
    if (ctx->r3 == ctx->r13) {
        // 0x801362D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801362F4;
    }
    goto skip_2;
    // 0x801362D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801362DC: jal         0x80134D54
    // 0x801362E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x801362E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x801362E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801362E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801362EC: sw          $v1, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r3;
L_801362F0:
    // 0x801362F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801362F4:
    // 0x801362F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801362F8: jr          $ra
    // 0x801362FC: nop

    return;
    // 0x801362FC: nop

;}
RECOMP_FUNC void itBombHeiExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177BB4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177BB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80177BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177BC0: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80177BC4: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80177BC8: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80177BCC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80177BD0: jal         0x80177A24
    // 0x80177BD4: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    itBombHeiCommonUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80177BD4: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    after_0:
    // 0x80177BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177BE0: jr          $ra
    // 0x80177BE4: nop

    return;
    // 0x80177BE4: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetTotalSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801335E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801335E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801335E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801335EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801335F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801335F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801335F8: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_801335FC:
    // 0x801335FC: jal         0x801322BC
    // 0x80133600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_0;
    // 0x80133600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133604: bnel        $v0, $zero, L_80133624
    if (ctx->r2 != 0) {
        // 0x80133608: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133624;
    }
    goto skip_0;
    // 0x80133608: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8013360C: jal         0x80133410
    // 0x80133610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetBestTime(rdram, ctx);
        goto after_1;
    // 0x80133610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80133614: jal         0x8013349C
    // 0x80133618: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusGetSec(rdram, ctx);
        goto after_2;
    // 0x80133618: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8013361C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80133620: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133624:
    // 0x80133624: bne         $s0, $s2, L_801335FC
    if (ctx->r16 != ctx->r18) {
        // 0x80133628: nop
    
            goto L_801335FC;
    }
    // 0x80133628: nop

    // 0x8013362C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133630: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80133634: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133638: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013363C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133640: jr          $ra
    // 0x80133644: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80133644: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void dbBattleFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F3C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80131F40: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80131F44: lhu         $t6, 0x5472($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5472);
    // 0x80131F48: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80131F4C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80131F50: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80131F54: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80131F58: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80131F5C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80131F60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F64: beq         $t7, $zero, L_80131FA8
    if (ctx->r15 == 0) {
        // 0x80131F68: sw          $a0, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r4;
            goto L_80131FA8;
    }
    // 0x80131F68: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80131F6C: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x80131F70: lw          $t8, 0x1420($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1420);
    // 0x80131F74: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80131F78: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80131F7C: beq         $t8, $zero, L_80131F94
    if (ctx->r24 == 0) {
        // 0x80131F80: addiu       $a2, $zero, 0x55
        ctx->r6 = ADD32(0, 0X55);
            goto L_80131F94;
    }
    // 0x80131F80: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x80131F84: jal         0x80131B58
    // 0x80131F88: nop

    dbBattleStartBattle(rdram, ctx);
        goto after_0;
    // 0x80131F88: nop

    after_0:
    // 0x80131F8C: b           L_80131FA8
    // 0x80131F90: nop

        goto L_80131FA8;
    // 0x80131F90: nop

L_80131F94:
    // 0x80131F94: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131F98: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80131F9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80131FA0: jal         0x80369D78
    // 0x80131FA4: addiu       $a3, $a3, 0x2780
    ctx->r7 = ADD32(ctx->r7, 0X2780);
    dbMenuMakeMenu(rdram, ctx);
        goto after_1;
    // 0x80131FA4: addiu       $a3, $a3, 0x2780
    ctx->r7 = ADD32(ctx->r7, 0X2780);
    after_1:
L_80131FA8:
    // 0x80131FA8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80131FAC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80131FB0: addiu       $s1, $s1, 0x3110
    ctx->r17 = ADD32(ctx->r17, 0X3110);
    // 0x80131FB4: addiu       $s0, $s0, 0x4D08
    ctx->r16 = ADD32(ctx->r16, 0X4D08);
    // 0x80131FB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80131FBC: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
L_80131FC0:
    // 0x80131FC0: lbu         $t0, 0x23($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X23);
    // 0x80131FC4: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80131FC8: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80131FCC: addiu       $t2, $t2, 0x6DD0
    ctx->r10 = ADD32(ctx->r10, 0X6DD0);
    // 0x80131FD0: beq         $t0, $t1, L_80132098
    if (ctx->r8 == ctx->r9) {
        // 0x80131FD4: or          $t5, $s4, $zero
        ctx->r13 = ctx->r20 | 0;
            goto L_80132098;
    }
    // 0x80131FD4: or          $t5, $s4, $zero
    ctx->r13 = ctx->r20 | 0;
    // 0x80131FD8: addiu       $t6, $t2, 0x3C
    ctx->r14 = ADD32(ctx->r10, 0X3C);
L_80131FDC:
    // 0x80131FDC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131FE0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80131FE4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80131FE8: sw          $t4, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r12;
    // 0x80131FEC: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80131FF0: sw          $t3, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r11;
    // 0x80131FF4: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80131FF8: bne         $t2, $t6, L_80131FDC
    if (ctx->r10 != ctx->r14) {
        // 0x80131FFC: sw          $t4, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r12;
            goto L_80131FDC;
    }
    // 0x80131FFC: sw          $t4, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r12;
    // 0x80132000: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132004: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80132008: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8013200C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80132010: jal         0x800D78E8
    // 0x80132014: lw          $s3, 0x9D0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X9D0);
    ftManagerDestroyFighter(rdram, ctx);
        goto after_2;
    // 0x80132014: lw          $s3, 0x9D0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X9D0);
    after_2:
    // 0x80132018: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8013201C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80132020: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132024: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132028: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8013202C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132030: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    // 0x80132034: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80132038: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8013203C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80132040: jal         0x800EC11C
    // 0x80132044: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    ftParamGetCostumeDebug(rdram, ctx);
        goto after_3;
    // 0x80132044: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80132048: lbu         $v1, 0x26($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X26);
    // 0x8013204C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80132050: beql        $at, $zero, L_8013206C
    if (ctx->r1 == 0) {
        // 0x80132054: sb          $v1, 0x5F($sp)
        MEM_B(0X5F, ctx->r29) = ctx->r3;
            goto L_8013206C;
    }
    goto skip_0;
    // 0x80132054: sb          $v1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r3;
    skip_0:
    // 0x80132058: jal         0x800EC11C
    // 0x8013205C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftParamGetCostumeDebug(rdram, ctx);
        goto after_4;
    // 0x8013205C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_4:
    // 0x80132060: sb          $v0, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r2;
    // 0x80132064: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80132068: sb          $v1, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r3;
L_8013206C:
    // 0x8013206C: jal         0x80131CD8
    // 0x80132070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    dbBattleGetSetShade(rdram, ctx);
        goto after_5;
    // 0x80132070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80132074: sb          $v0, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r2;
    // 0x80132078: sw          $s3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r19;
    // 0x8013207C: jal         0x800D7F3C
    // 0x80132080: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_6;
    // 0x80132080: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x80132084: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x80132088: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8013208C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80132090: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80132094: sb          $t8, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r24;
L_80132098:
    // 0x80132098: lbu         $t9, 0x26($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X26);
    // 0x8013209C: lbu         $t0, 0x1($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1);
    // 0x801320A0: beql        $t9, $t0, L_801320CC
    if (ctx->r25 == ctx->r8) {
        // 0x801320A4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801320CC;
    }
    goto skip_1;
    // 0x801320A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x801320A8: jal         0x80131CD8
    // 0x801320AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    dbBattleGetSetShade(rdram, ctx);
        goto after_7;
    // 0x801320AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x801320B0: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x801320B4: lbu         $a1, 0x26($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X26);
    // 0x801320B8: jal         0x800E9248
    // 0x801320BC: lbu         $a2, 0x27($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X27);
    ftParamInitAllParts(rdram, ctx);
        goto after_8;
    // 0x801320BC: lbu         $a2, 0x27($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X27);
    after_8:
    // 0x801320C0: lbu         $t1, 0x26($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X26);
    // 0x801320C4: sb          $t1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r9;
    // 0x801320C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801320CC:
    // 0x801320CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801320D0: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x801320D4: bne         $s2, $at, L_80131FC0
    if (ctx->r18 != ctx->r1) {
        // 0x801320D8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80131FC0;
    }
    // 0x801320D8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x801320DC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x801320E0: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
    // 0x801320E4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801320E8: addiu       $s0, $s0, 0x2698
    ctx->r16 = ADD32(ctx->r16, 0X2698);
    // 0x801320EC: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x801320F0: beq         $t6, $zero, L_80132118
    if (ctx->r14 == 0) {
        // 0x801320F4: nop
    
            goto L_80132118;
    }
    // 0x801320F4: nop

    // 0x801320F8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801320FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132100: lw          $a0, 0x311C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X311C);
    // 0x80132104: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x80132108: jal         0x803905CC
    // 0x8013210C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_9;
    // 0x8013210C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    after_9:
    // 0x80132110: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80132114: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
L_80132118:
    // 0x80132118: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8013211C: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80132120: beq         $t5, $zero, L_80132140
    if (ctx->r13 == 0) {
        // 0x80132124: addiu       $s0, $s0, 0x2698
        ctx->r16 = ADD32(ctx->r16, 0X2698);
            goto L_80132140;
    }
    // 0x80132124: addiu       $s0, $s0, 0x2698
    ctx->r16 = ADD32(ctx->r16, 0X2698);
    // 0x80132128: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8013212C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132130: lw          $a0, 0x311C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X311C);
    // 0x80132134: addiu       $t3, $a1, -0x1
    ctx->r11 = ADD32(ctx->r5, -0X1);
    // 0x80132138: jal         0x803905CC
    // 0x8013213C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_10;
    // 0x8013213C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    after_10:
L_80132140:
    // 0x80132140: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132144: lw          $t4, 0x2690($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2690);
    // 0x80132148: beql        $t4, $zero, L_8013221C
    if (ctx->r12 == 0) {
        // 0x8013214C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8013221C;
    }
    goto skip_2;
    // 0x8013214C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80132150: jal         0x80369EC0
    // 0x80132154: nop

    dbMenuDestroyMenu(rdram, ctx);
        goto after_11;
    // 0x80132154: nop

    after_11:
    // 0x80132158: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8013215C: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80132160: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80132164: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132168: sb          $t7, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r15;
    // 0x8013216C: lbu         $t8, 0x2694($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2694);
    // 0x80132170: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80132174: beq         $at, $zero, L_80132210
    if (ctx->r1 == 0) {
        // 0x80132178: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80132210;
    }
    // 0x80132178: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013217C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132180: addu        $at, $at, $t8
    gpr jr_addend_80132188 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80132184: lw          $t8, 0x2C04($at)
    ctx->r24 = ADD32(ctx->r1, 0X2C04);
    // 0x80132188: jr          $t8
    // 0x8013218C: nop

    switch (jr_addend_80132188 >> 2) {
        case 0: goto L_80132190; break;
        case 1: goto L_8013219C; break;
        case 2: goto L_801321C4; break;
        case 3: goto L_801321D0; break;
        case 4: goto L_801321E8; break;
        case 5: goto L_80132208; break;
        default: switch_error(__func__, 0x80132188, 0x80132C04);
    }
    // 0x8013218C: nop

L_80132190:
    // 0x80132190: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80132194: b           L_80132210
    // 0x80132198: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_80132210;
    // 0x80132198: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8013219C:
    // 0x8013219C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801321A0: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x801321A4: lbu         $t1, 0x23($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X23);
    // 0x801321A8: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x801321AC: addiu       $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
    // 0x801321B0: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x801321B4: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x801321B8: sb          $t1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r9;
    // 0x801321BC: b           L_80132210
    // 0x801321C0: sb          $t6, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r14;
        goto L_80132210;
    // 0x801321C0: sb          $t6, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r14;
L_801321C4:
    // 0x801321C4: addiu       $t2, $zero, 0x38
    ctx->r10 = ADD32(0, 0X38);
    // 0x801321C8: b           L_80132210
    // 0x801321CC: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
        goto L_80132210;
    // 0x801321CC: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
L_801321D0:
    // 0x801321D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801321D4: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x801321D8: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x801321DC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x801321E0: b           L_80132210
    // 0x801321E4: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
        goto L_80132210;
    // 0x801321E4: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
L_801321E8:
    // 0x801321E8: jal         0x80131E38
    // 0x801321EC: nop

    dbBattleSetDemoFighterKinds(rdram, ctx);
        goto after_12;
    // 0x801321EC: nop

    after_12:
    // 0x801321F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801321F4: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x801321F8: addiu       $t3, $zero, 0x3D
    ctx->r11 = ADD32(0, 0X3D);
    // 0x801321FC: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x80132200: b           L_80132210
    // 0x80132204: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
        goto L_80132210;
    // 0x80132204: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
L_80132208:
    // 0x80132208: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
    // 0x8013220C: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_80132210:
    // 0x80132210: jal         0x80005C74
    // 0x80132214: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_13;
    // 0x80132214: nop

    after_13:
    // 0x80132218: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8013221C:
    // 0x8013221C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132220: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80132224: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80132228: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8013222C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80132230: jr          $ra
    // 0x80132234: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80132234: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void ftMainUpdateAttackStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E35BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E35C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E35C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E35C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E35CC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800E35D0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E35D4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800E35D8: jal         0x801727F4
    // 0x800E35DC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x800E35DC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E35E0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800E35E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800E35E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E35EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800E35F0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E35F4: jal         0x800F0E70
    // 0x800E35F8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gmCollisionGetItemAttackFighterAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800E35F8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800E35FC: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800E3600: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3604: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E3608: addiu       $t6, $v1, -0xA
    ctx->r14 = ADD32(ctx->r3, -0XA);
    // 0x800E360C: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800E3610: beq         $at, $zero, L_800E3650
    if (ctx->r1 == 0) {
        // 0x800E3614: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800E3650;
    }
    // 0x800E3614: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800E3618: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800E361C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E3620: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E3624: jal         0x800E26BC
    // 0x800E3628: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_2;
    // 0x800E3628: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800E362C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800E3630: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3634: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E3638: jal         0x800E287C
    // 0x800E363C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    ftMainSetHitRebound(rdram, ctx);
        goto after_3;
    // 0x800E363C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800E3640: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E3644: jal         0x80100BF0
    // 0x800E3648: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x800E3648: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_4:
    // 0x800E364C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_800E3650:
    // 0x800E3650: addiu       $t0, $s1, -0xA
    ctx->r8 = ADD32(ctx->r17, -0XA);
    // 0x800E3654: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E3658: beq         $at, $zero, L_800E36E4
    if (ctx->r1 == 0) {
        // 0x800E365C: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_800E36E4;
    }
    // 0x800E365C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800E3660: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800E3664: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800E3668: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800E366C: jal         0x8016F930
    // 0x800E3670: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_5;
    // 0x800E3670: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x800E3674: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800E3678: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E367C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E3680: lw          $t8, 0x270($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X270);
    // 0x800E3684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E3688: slt         $at, $t8, $s1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800E368C: beq         $at, $zero, L_800E3698
    if (ctx->r1 == 0) {
        // 0x800E3690: nop
    
            goto L_800E3698;
    }
    // 0x800E3690: nop

    // 0x800E3694: sw          $s1, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->r17;
L_800E3698:
    // 0x800E3698: jal         0x80100BF0
    // 0x800E369C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x800E369C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_6:
    // 0x800E36A0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800E36A4: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x800E36A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E36AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E36B0: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800E36B4: bne         $t1, $at, L_800E36E4
    if (ctx->r9 != ctx->r1) {
        // 0x800E36B8: slti        $at, $t0, 0xA
        ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
            goto L_800E36E4;
    }
    // 0x800E36B8: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800E36BC: bne         $at, $zero, L_800E36E4
    if (ctx->r1 != 0) {
        // 0x800E36C0: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_800E36E4;
    }
    // 0x800E36C0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800E36C4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800E36C8: lbu         $t2, 0x4AE3($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4AE3);
    // 0x800E36CC: lbu         $t4, 0xD($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XD);
    // 0x800E36D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E36D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800E36D8: bnel        $t2, $t4, L_800E36E8
    if (ctx->r10 != ctx->r12) {
        // 0x800E36DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E36E8;
    }
    goto skip_0;
    // 0x800E36DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800E36E0: sb          $t5, 0x36AC($at)
    MEM_B(0X36AC, ctx->r1) = ctx->r13;
L_800E36E4:
    // 0x800E36E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E36E8:
    // 0x800E36E8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E36EC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E36F0: jr          $ra
    // 0x800E36F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E36F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonDokanWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801424BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801424C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801424C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801424C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801424CC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801424D0: jal         0x800DEEC8
    // 0x801424D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801424D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801424D8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x801424DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801424E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801424E4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x801424E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801424EC: jal         0x800E6F24
    // 0x801424F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801424F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801424F4: lbu         $t9, 0x18D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18D);
    // 0x801424F8: lbu         $t2, 0x18E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18E);
    // 0x801424FC: lbu         $t8, 0x191($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X191);
    // 0x80142500: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80142504: sb          $t0, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r8;
    // 0x80142508: lw          $t0, 0xB18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB18);
    // 0x8014250C: ori         $t5, $t2, 0x10
    ctx->r13 = ctx->r10 | 0X10;
    // 0x80142510: sb          $t5, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r13;
    // 0x80142514: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80142518: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8014251C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80142520: sb          $t6, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r14;
    // 0x80142524: sw          $zero, 0xB38($s0)
    MEM_W(0XB38, ctx->r16) = 0;
    // 0x80142528: bne         $t0, $at, L_8014253C
    if (ctx->r8 != ctx->r1) {
        // 0x8014252C: sb          $t9, 0x191($s0)
        MEM_B(0X191, ctx->r16) = ctx->r25;
            goto L_8014253C;
    }
    // 0x8014252C: sb          $t9, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r25;
    // 0x80142530: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80142534: b           L_80142544
    // 0x80142538: sw          $t1, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r9;
        goto L_80142544;
    // 0x80142538: sw          $t1, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r9;
L_8014253C:
    // 0x8014253C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80142540: sw          $t2, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r10;
L_80142544:
    // 0x80142544: lw          $a0, 0xB1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB1C);
    // 0x80142548: jal         0x800FC814
    // 0x8014254C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_2;
    // 0x8014254C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80142550: addiu       $a1, $s0, 0xB2C
    ctx->r5 = ADD32(ctx->r16, 0XB2C);
    // 0x80142554: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80142558: jal         0x800FC894
    // 0x8014255C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_3;
    // 0x8014255C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80142560: jal         0x80018948
    // 0x80142564: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_4;
    // 0x80142564: nop

    after_4:
    // 0x80142568: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8014256C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80142570: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80142574: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80142578: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8014257C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80142580: bc1fl       L_801425D4
    if (!c1cs) {
        // 0x80142584: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801425D4;
    }
    goto skip_0;
    // 0x80142584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80142588: jal         0x800FC814
    // 0x8014258C: sw          $t3, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r11;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8014258C: sw          $t3, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r11;
    after_5:
    // 0x80142590: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80142594: jal         0x800FC894
    // 0x80142598: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x80142598: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8014259C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801425A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801425A4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801425A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801425AC: jal         0x800F9C30
    // 0x801425B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionCheckProjectRWall(rdram, ctx);
        goto after_7;
    // 0x801425B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x801425B4: beq         $v0, $zero, L_801425D0
    if (ctx->r2 == 0) {
        // 0x801425B8: lwc1        $f6, 0x30($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
            goto L_801425D0;
    }
    // 0x801425B8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801425BC: lwc1        $f8, 0xBC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x801425C0: lwc1        $f16, 0xB2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB2C);
    // 0x801425C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801425C8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801425CC: swc1        $f18, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->f18.u32l;
L_801425D0:
    // 0x801425D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801425D4:
    // 0x801425D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801425D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801425DC: jr          $ra
    // 0x801425E0: nop

    return;
    // 0x801425E0: nop

;}
RECOMP_FUNC void mnVSRecordMakeIndivTableValues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135484: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80135488: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013548C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80135490: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80135494: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80135498: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8013549C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801354A0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x801354A4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x801354A8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x801354AC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x801354B0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801354B4: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x801354B8: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x801354BC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801354C0: addiu       $t7, $t7, 0x6974
    ctx->r15 = ADD32(ctx->r15, 0X6974);
    // 0x801354C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801354C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801354CC: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x801354D0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801354D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801354D8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801354DC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801354E0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801354E4: addiu       $t0, $t0, 0x6984
    ctx->r8 = ADD32(ctx->r8, 0X6984);
    // 0x801354E8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801354EC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801354F0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801354F4: addiu       $s3, $sp, 0x9C
    ctx->r19 = ADD32(ctx->r29, 0X9C);
    // 0x801354F8: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801354FC: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80135500: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80135504: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013550C: sw          $t1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r9;
    // 0x80135510: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80135514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135518: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8013551C: sw          $t2, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r10;
    // 0x80135520: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80135524: sw          $t1, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r9;
    // 0x80135528: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8013552C: sw          $t2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r10;
    // 0x80135530: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80135534: jal         0x80009968
    // 0x80135538: sw          $t1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r9;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135538: sw          $t1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r9;
    after_0:
    // 0x8013553C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80135540: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80135544: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80135548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8013554C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80135550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135554: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80135558: jal         0x80009DF4
    // 0x8013555C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013555C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80135560: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80135564: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80135568: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013556C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80135570: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80135574: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80135578: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8013557C: addiu       $s4, $s4, 0x6C58
    ctx->r20 = ADD32(ctx->r20, 0X6C58);
    // 0x80135580: addiu       $s5, $s5, 0x6CB8
    ctx->r21 = ADD32(ctx->r21, 0X6CB8);
    // 0x80135584: addiu       $fp, $fp, 0x6C58
    ctx->r30 = ADD32(ctx->r30, 0X6C58);
    // 0x80135588: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8013558C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80135590:
    // 0x80135590: jal         0x801326EC
    // 0x80135594: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_2;
    // 0x80135594: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_2:
    // 0x80135598: beq         $v0, $zero, L_80135730
    if (ctx->r2 == 0) {
        // 0x8013559C: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80135730;
    }
    // 0x8013559C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801355A0: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x801355A4: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x801355A8: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x801355AC: addiu       $t7, $t7, 0x6C88
    ctx->r15 = ADD32(ctx->r15, 0X6C88);
    // 0x801355B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801355B4: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x801355B8: addu        $s0, $s7, $t7
    ctx->r16 = ADD32(ctx->r23, ctx->r15);
    // 0x801355BC: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x801355C0: subu        $s2, $s2, $s1
    ctx->r18 = SUB32(ctx->r18, ctx->r17);
    // 0x801355C4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801355C8: jal         0x8013531C
    // 0x801355CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mnVSRecordGetWinPercentAgainst(rdram, ctx);
        goto after_3;
    // 0x801355CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x801355D0: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x801355D4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801355D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801355DC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801355E0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801355E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801355E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801355EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801355F0: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x801355F4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x801355F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801355FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80135600: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80135604: add.s       $f20, $f10, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x80135608: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8013560C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80135610: jal         0x80131F34
    // 0x80135614: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_4;
    // 0x80135614: nop

    after_4:
    // 0x80135618: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x8013561C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80135620: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80135624: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80135628: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x8013562C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80135630: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80135634: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80135638: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8013563C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80135640: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80135644: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80135648: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8013564C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80135650: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80135654: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80135658: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013565C: lhu         $a1, 0x44E0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X44E0);
    // 0x80135660: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80135664: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80135668: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8013566C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80135670: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135674: jal         0x80131F34
    // 0x80135678: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_5;
    // 0x80135678: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    after_5:
    // 0x8013567C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80135680: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80135684: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80135688: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8013568C: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80135690: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80135694: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80135698: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8013569C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801356A0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801356A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801356A8: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x801356AC: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x801356B0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x801356B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801356B8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801356BC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801356C0: lhu         $a1, 0x44E0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X44E0);
    // 0x801356C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801356C8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801356CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801356D0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x801356D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801356D8: jal         0x80131F34
    // 0x801356DC: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_6;
    // 0x801356DC: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    after_6:
    // 0x801356E0: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x801356E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801356E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801356EC: addu        $t2, $s4, $t0
    ctx->r10 = ADD32(ctx->r20, ctx->r8);
    // 0x801356F0: jal         0x801353F4
    // 0x801356F4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    mnVSRecordGetAvgAgainst(rdram, ctx);
        goto after_7;
    // 0x801356F4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_7:
    // 0x801356F8: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801356FC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80135700: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80135704: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80135708: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8013570C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80135710: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135714: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80135718: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8013571C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80135720: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80135724: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80135728: jal         0x80131F34
    // 0x8013572C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_8;
    // 0x8013572C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_8:
L_80135730:
    // 0x80135730: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80135734: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80135738: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8013573C: bne         $s1, $at, L_80135590
    if (ctx->r17 != ctx->r1) {
        // 0x80135740: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_80135590;
    }
    // 0x80135740: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80135744: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80135748: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8013574C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80135750: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80135754: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80135758: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8013575C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80135760: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80135764: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80135768: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8013576C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80135770: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80135774: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80135778: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8013577C: jr          $ra
    // 0x80135780: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80135780: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_ovl8_80371EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371EA0: lui         $t6, 0x5041
    ctx->r14 = S32(0X5041 << 16);
    // 0x80371EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80371EA8: ori         $t6, $t6, 0x4E45
    ctx->r14 = ctx->r14 | 0X4E45;
    // 0x80371EAC: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x80371EB0: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x80371EB4: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80371EB8: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x80371EBC: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x80371EC0: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80371EC4: jr          $ra
    // 0x80371EC8: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    return;
    // 0x80371EC8: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
;}

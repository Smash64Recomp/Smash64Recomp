#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F6F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F6F8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F6FC: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015F700: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015F704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F708: addiu       $a1, $zero, 0x12D
    ctx->r5 = ADD32(0, 0X12D);
    // 0x8015F70C: jal         0x800E6F24
    // 0x8015F710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F710: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015F714: jal         0x800E0830
    // 0x8015F718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015F71C: jal         0x8015F668
    // 0x8015F720: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyYoshiSpecialNCatchInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015F720: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015F724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F72C: jr          $ra
    // 0x8015F730: nop

    return;
    // 0x8015F730: nop

;}
RECOMP_FUNC void func_ovl8_803868C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803868C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803868C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803868C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803868CC: jal         0x8037319C
    // 0x803868D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_ovl8_8037319C(rdram, ctx);
        goto after_0;
    // 0x803868D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x803868D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x803868D8: sw          $v0, 0xAC($t6)
    MEM_W(0XAC, ctx->r14) = ctx->r2;
    // 0x803868DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803868E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803868E4: jr          $ra
    // 0x803868E8: nop

    return;
    // 0x803868E8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137354: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80137358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013735C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80137360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137368: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8013736C: jal         0x80009968
    // 0x80137370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80137370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137374: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137378: addiu       $a1, $a1, 0x7254
    ctx->r5 = ADD32(ctx->r5, 0X7254);
    // 0x8013737C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80137380: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137384: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80137388: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013738C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137390: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80137394: jal         0x80009DF4
    // 0x80137398: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80137398: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013739C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801373A0: addiu       $a1, $a1, 0x72D4
    ctx->r5 = ADD32(ctx->r5, 0X72D4);
    // 0x801373A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x801373A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801373AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801373B0: jal         0x80008188
    // 0x801373B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801373B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801373B8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801373BC: lw          $t7, -0x7368($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7368);
    // 0x801373C0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x801373C4: addiu       $t8, $t8, -0xAD0
    ctx->r24 = ADD32(ctx->r24, -0XAD0);
    // 0x801373C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801373CC: jal         0x800CCFDC
    // 0x801373D0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801373D0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x801373D4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801373D8: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x801373DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801373E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801373E4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801373E8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801373EC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801373F0: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x801373F4: addiu       $t4, $zero, 0x56
    ctx->r12 = ADD32(0, 0X56);
    // 0x801373F8: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x801373FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80137400: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80137404: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x80137408: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013740C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80137410: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80137414: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80137418: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x8013741C: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80137420: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80137424: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80137428: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x8013742C: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x80137430: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80137434: sh          $t7, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r15;
    // 0x80137438: sh          $t8, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r24;
    // 0x8013743C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137440: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80137444: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80137448: lw          $t9, -0x7368($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7368);
    // 0x8013744C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80137450: addiu       $t0, $t0, -0xBB8
    ctx->r8 = ADD32(ctx->r8, -0XBB8);
    // 0x80137454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137458: jal         0x800CCFDC
    // 0x8013745C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013745C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80137460: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80137464: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80137468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013746C: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x80137470: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80137474: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137478: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8013747C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80137480: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80137484: addiu       $t5, $zero, 0xCA
    ctx->r13 = ADD32(0, 0XCA);
    // 0x80137488: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8013748C: addiu       $t7, $zero, 0x9D
    ctx->r15 = ADD32(0, 0X9D);
    // 0x80137490: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80137494: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80137498: sb          $t5, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r13;
    // 0x8013749C: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x801374A0: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801374A4: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801374A8: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x801374AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801374B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801374B4: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x801374B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801374BC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801374C0: jal         0x80009968
    // 0x801374C4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x801374C4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x801374C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801374CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801374D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801374D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801374D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801374DC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x801374E0: jal         0x80009DF4
    // 0x801374E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x801374E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x801374E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801374EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801374F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801374F4: jal         0x80008188
    // 0x801374F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x801374F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x801374FC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137500: lw          $t9, -0x7368($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7368);
    // 0x80137504: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80137508: addiu       $t0, $t0, 0x14D8
    ctx->r8 = ADD32(ctx->r8, 0X14D8);
    // 0x8013750C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137510: jal         0x800CCFDC
    // 0x80137514: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x80137514: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_8:
    // 0x80137518: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x8013751C: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x80137520: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137524: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x80137528: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013752C: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80137530: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80137534: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80137538: addiu       $t5, $zero, 0xD6
    ctx->r13 = ADD32(0, 0XD6);
    // 0x8013753C: addiu       $t6, $zero, 0xDD
    ctx->r14 = ADD32(0, 0XDD);
    // 0x80137540: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x80137544: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80137548: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x8013754C: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80137550: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80137554: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137558: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013755C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80137560: lw          $t8, -0x7368($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7368);
    // 0x80137564: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80137568: addiu       $t9, $t9, 0x1378
    ctx->r25 = ADD32(ctx->r25, 0X1378);
    // 0x8013756C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137570: jal         0x800CCFDC
    // 0x80137574: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x80137574: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80137578: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x8013757C: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x80137580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137584: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x80137588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013758C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80137590: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80137594: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80137598: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013759C: addiu       $t5, $zero, 0x56
    ctx->r13 = ADD32(0, 0X56);
    // 0x801375A0: addiu       $t6, $zero, 0x92
    ctx->r14 = ADD32(0, 0X92);
    // 0x801375A4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801375A8: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x801375AC: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x801375B0: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801375B4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801375B8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801375BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801375C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801375C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801375C8: jr          $ra
    // 0x801375CC: nop

    return;
    // 0x801375CC: nop

;}
RECOMP_FUNC void sc1PTrainingModeCheckLeaveMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D1F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D1F4: lbu         $v0, 0x4AE3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AE3);
    // 0x8018D1F8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8018D1FC: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x8018D200: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8018D204: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8018D208: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8018D20C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D210: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x8018D214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D21C: andi        $t9, $t8, 0x5000
    ctx->r25 = ctx->r24 & 0X5000;
    // 0x8018D220: beq         $t9, $zero, L_8018D2E0
    if (ctx->r25 == 0) {
        // 0x8018D224: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018D2E0;
    }
    // 0x8018D224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D228: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018D22C: jal         0x80113F74
    // 0x8018D230: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_0;
    // 0x8018D230: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018D234: jal         0x8018D0C0
    // 0x8018D238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sc1PTrainingModeSetMenuGObjFlags(rdram, ctx);
        goto after_1;
    // 0x8018D238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8018D23C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D240: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018D244: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8018D248: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018D24C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018D250: sb          $t0, 0x11($t1)
    MEM_B(0X11, ctx->r9) = ctx->r8;
    // 0x8018D254: lw          $t3, 0xB78($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XB78);
    // 0x8018D258: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8018D25C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8018D260: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D264: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D268: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D26C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D270: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8018D274: jal         0x800E7F68
    // 0x8018D278: lw          $a0, 0x78($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X78);
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_2;
    // 0x8018D278: lw          $a0, 0x78($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X78);
    after_2:
    // 0x8018D27C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8018D280: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D284: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D288: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018D28C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018D290: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D294: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D298: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D29C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018D2A0: lw          $a0, 0x78($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X78);
    // 0x8018D2A4: jal         0x800E7F68
    // 0x8018D2A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_3;
    // 0x8018D2A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x8018D2AC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8018D2B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8018D2B4: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    // 0x8018D2B8: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x8018D2BC: andi        $t3, $t1, 0x4000
    ctx->r11 = ctx->r9 & 0X4000;
    // 0x8018D2C0: beq         $t3, $zero, L_8018D2D8
    if (ctx->r11 == 0) {
        // 0x8018D2C4: nop
    
            goto L_8018D2D8;
    }
    // 0x8018D2C4: nop

    // 0x8018D2C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018D2CC: lhu         $t2, 0x1BC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X1BC);
    // 0x8018D2D0: ori         $t4, $t2, 0x4000
    ctx->r12 = ctx->r10 | 0X4000;
    // 0x8018D2D4: sh          $t4, 0x1BC($v0)
    MEM_H(0X1BC, ctx->r2) = ctx->r12;
L_8018D2D8:
    // 0x8018D2D8: jal         0x80020B38
    // 0x8018D2DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioSetBGMVolume(rdram, ctx);
        goto after_4;
    // 0x8018D2DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
L_8018D2E0:
    // 0x8018D2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D2E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D2E8: jr          $ra
    // 0x8018D2EC: nop

    return;
    // 0x8018D2EC: nop

;}
RECOMP_FUNC void mvOpeningRunFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132268: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013226C: addiu       $v1, $v1, 0x273C
    ctx->r3 = ADD32(ctx->r3, 0X273C);
    // 0x80132270: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013227C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132280: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132288: bne         $at, $zero, L_8013236C
    if (ctx->r1 != 0) {
        // 0x8013228C: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8013236C;
    }
    // 0x8013228C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132290: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132294: addiu       $a2, $a2, 0x2740
    ctx->r6 = ADD32(ctx->r6, 0X2740);
    // 0x80132298: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8013229C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801322A0: beq         $v0, $zero, L_801322AC
    if (ctx->r2 == 0) {
        // 0x801322A4: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801322AC;
    }
    // 0x801322A4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801322A8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_801322AC:
    // 0x801322AC: jal         0x80390A04
    // 0x801322B0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x801322B0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x801322B4: beq         $v0, $zero, L_801322D0
    if (ctx->r2 == 0) {
        // 0x801322B8: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_801322D0;
    }
    // 0x801322B8: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801322BC: jal         0x80390AC0
    // 0x801322C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x801322C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x801322C4: beq         $v0, $zero, L_801322D0
    if (ctx->r2 == 0) {
        // 0x801322C8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801322D0;
    }
    // 0x801322C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322CC: sw          $zero, 0x2740($at)
    MEM_W(0X2740, ctx->r1) = 0;
L_801322D0:
    // 0x801322D0: jal         0x8039076C
    // 0x801322D4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x801322D4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x801322D8: beq         $v0, $zero, L_801322F8
    if (ctx->r2 == 0) {
        // 0x801322DC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801322F8;
    }
    // 0x801322DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801322E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801322E4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801322E8: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801322EC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801322F0: jal         0x80005C74
    // 0x801322F4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801322F4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_801322F8:
    // 0x801322F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801322FC: lw          $v1, 0x273C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X273C);
    // 0x80132300: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80132304: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132308: bne         $v1, $at, L_80132324
    if (ctx->r3 != ctx->r1) {
        // 0x8013230C: lui         $a1, 0x1
        ctx->r5 = S32(0X1 << 16);
            goto L_80132324;
    }
    // 0x8013230C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80132310: lw          $a0, 0x2738($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2738);
    // 0x80132314: jal         0x803905CC
    // 0x80132318: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_4;
    // 0x80132318: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    after_4:
    // 0x8013231C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132320: lw          $v1, 0x273C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X273C);
L_80132324:
    // 0x80132324: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x80132328: bnel        $v1, $at, L_8013234C
    if (ctx->r3 != ctx->r1) {
        // 0x8013232C: addiu       $at, $zero, 0xDC
        ctx->r1 = ADD32(0, 0XDC);
            goto L_8013234C;
    }
    goto skip_0;
    // 0x8013232C: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    skip_0:
    // 0x80132330: jal         0x80131F80
    // 0x80132334: nop

    mvOpeningRunMakeCrash(rdram, ctx);
        goto after_5;
    // 0x80132334: nop

    after_5:
    // 0x80132338: jal         0x800269C0
    // 0x8013233C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x8013233C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80132340: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132344: lw          $v1, 0x273C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X273C);
    // 0x80132348: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
L_8013234C:
    // 0x8013234C: bne         $v1, $at, L_8013236C
    if (ctx->r3 != ctx->r1) {
        // 0x80132350: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8013236C;
    }
    // 0x80132350: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132354: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132358: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8013235C: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x80132360: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80132364: jal         0x80005C74
    // 0x80132368: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_7;
    // 0x80132368: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    after_7:
L_8013236C:
    // 0x8013236C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132374: jr          $ra
    // 0x80132378: nop

    return;
    // 0x80132378: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169D08: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80169D0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80169D10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80169D14: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80169D18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80169D1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80169D20: lw          $v0, 0x29C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X29C);
    // 0x80169D24: beql        $v0, $zero, L_80169D48
    if (ctx->r2 == 0) {
        // 0x80169D28: lw          $a0, 0xA0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XA0);
            goto L_80169D48;
    }
    goto skip_0;
    // 0x80169D28: lw          $a0, 0xA0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA0);
    skip_0:
    // 0x80169D2C: beq         $v0, $at, L_8016A180
    if (ctx->r2 == ctx->r1) {
        // 0x80169D30: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8016A180;
    }
    // 0x80169D30: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80169D34: beql        $v0, $a3, L_80169FA4
    if (ctx->r2 == ctx->r7) {
        // 0x80169D38: lw          $a0, 0xCC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XCC);
            goto L_80169FA4;
    }
    goto skip_1;
    // 0x80169D38: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
    skip_1:
    // 0x80169D3C: b           L_8016A360
    // 0x80169D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x80169D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169D44: lw          $a0, 0xA0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA0);
L_80169D48:
    // 0x80169D48: jal         0x800FC67C
    // 0x80169D4C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x80169D4C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80169D50: bne         $v0, $zero, L_80169D70
    if (ctx->r2 != 0) {
        // 0x80169D54: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_80169D70;
    }
    // 0x80169D54: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169D58: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80169D5C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169D60: jal         0x800FF648
    // 0x80169D64: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80169D64: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80169D68: b           L_8016A360
    // 0x80169D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x80169D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169D70:
    // 0x80169D70: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169D74: lw          $a0, 0xA0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA0);
    // 0x80169D78: addiu       $t6, $v1, 0x2A0
    ctx->r14 = ADD32(ctx->r3, 0X2A0);
    // 0x80169D7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80169D80: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80169D84: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80169D88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169D8C: jal         0x800F3DD8
    // 0x80169D90: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x80169D90: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x80169D94: beq         $v0, $zero, L_80169DE4
    if (ctx->r2 == 0) {
        // 0x80169D98: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_80169DE4;
    }
    // 0x80169D98: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169D9C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80169DA0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80169DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80169DA8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80169DAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80169DB0: jal         0x8016981C
    // 0x80169DB4: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_3;
    // 0x80169DB4: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    after_3:
    // 0x80169DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80169DBC: bne         $v0, $at, L_80169DDC
    if (ctx->r2 != ctx->r1) {
        // 0x80169DC0: nop
    
            goto L_80169DDC;
    }
    // 0x80169DC0: nop

    // 0x80169DC4: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80169DC8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169DCC: jal         0x800FF648
    // 0x80169DD0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80169DD0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_4:
    // 0x80169DD4: b           L_8016A360
    // 0x80169DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x80169DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169DDC:
    // 0x80169DDC: b           L_8016A360
    // 0x80169DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x80169DE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80169DE4:
    // 0x80169DE4: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80169DE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169DEC: bnel        $v0, $at, L_80169E10
    if (ctx->r2 != ctx->r1) {
        // 0x80169DF0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80169E10;
    }
    goto skip_2;
    // 0x80169DF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_2:
    // 0x80169DF4: lw          $a0, 0xA0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA0);
    // 0x80169DF8: jal         0x800FA964
    // 0x80169DFC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_5;
    // 0x80169DFC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80169E00: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169E04: b           L_80169E30
    // 0x80169E08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80169E30;
    // 0x80169E08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80169E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80169E10:
    // 0x80169E10: bne         $v0, $at, L_80169E30
    if (ctx->r2 != ctx->r1) {
        // 0x80169E14: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80169E30;
    }
    // 0x80169E14: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80169E18: lw          $a0, 0xA0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA0);
    // 0x80169E1C: jal         0x800FAA24
    // 0x80169E20: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_6;
    // 0x80169E20: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80169E24: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169E28: b           L_80169E30
    // 0x80169E2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80169E30;
    // 0x80169E2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80169E30:
    // 0x80169E30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80169E34: beq         $a0, $at, L_80169E44
    if (ctx->r4 == ctx->r1) {
        // 0x80169E38: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80169E44;
    }
    // 0x80169E38: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80169E3C: bnel        $a0, $at, L_80169E7C
    if (ctx->r4 != ctx->r1) {
        // 0x80169E40: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_80169E7C;
    }
    goto skip_3;
    // 0x80169E40: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    skip_3:
L_80169E44:
    // 0x80169E44: jal         0x8016981C
    // 0x80169E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_7;
    // 0x80169E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80169E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169E50: beq         $v0, $at, L_80169E70
    if (ctx->r2 == ctx->r1) {
        // 0x80169E54: nop
    
            goto L_80169E70;
    }
    // 0x80169E54: nop

    // 0x80169E58: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80169E5C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169E60: jal         0x800FF648
    // 0x80169E64: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_8;
    // 0x80169E64: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_8:
    // 0x80169E68: b           L_8016A360
    // 0x80169E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x80169E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169E70:
    // 0x80169E70: b           L_8016A360
    // 0x80169E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x80169E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169E78: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_80169E7C:
    // 0x80169E7C: jal         0x800FA8A4
    // 0x80169E80: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_9;
    // 0x80169E80: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_9:
    // 0x80169E84: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169E88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169E8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80169E90: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80169E94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80169E98: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80169E9C: bne         $t7, $at, L_80169F0C
    if (ctx->r15 != ctx->r1) {
        // 0x80169EA0: nop
    
            goto L_80169F0C;
    }
    // 0x80169EA0: nop

    // 0x80169EA4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80169EA8: bne         $v0, $a3, L_80169EDC
    if (ctx->r2 != ctx->r7) {
        // 0x80169EAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80169EDC;
    }
    // 0x80169EAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80169EB0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80169EB4: sw          $a0, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r4;
    // 0x80169EB8: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x80169EBC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x80169EC0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169EC4: jal         0x800F4670
    // 0x80169EC8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLWallEdgeD(rdram, ctx);
        goto after_10;
    // 0x80169EC8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_10:
    // 0x80169ECC: jal         0x80169BF0
    // 0x80169ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_11;
    // 0x80169ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80169ED4: b           L_8016A364
    // 0x80169ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x80169ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80169EDC:
    // 0x80169EDC: bne         $v0, $at, L_80169F6C
    if (ctx->r2 != ctx->r1) {
        // 0x80169EE0: nop
    
            goto L_80169F6C;
    }
    // 0x80169EE0: nop

    // 0x80169EE4: sw          $a0, 0xE0($v1)
    MEM_W(0XE0, ctx->r3) = ctx->r4;
    // 0x80169EE8: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x80169EEC: sw          $a3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r7;
    // 0x80169EF0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169EF4: jal         0x800F4690
    // 0x80169EF8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_12;
    // 0x80169EF8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_12:
    // 0x80169EFC: jal         0x80169BF0
    // 0x80169F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_13;
    // 0x80169F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80169F04: b           L_8016A364
    // 0x80169F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x80169F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80169F0C:
    // 0x80169F0C: bne         $v0, $a3, L_80169F3C
    if (ctx->r2 != ctx->r7) {
        // 0x80169F10: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80169F3C;
    }
    // 0x80169F10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80169F14: sw          $a0, 0xCC($v1)
    MEM_W(0XCC, ctx->r3) = ctx->r4;
    // 0x80169F18: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x80169F1C: sw          $a3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r7;
    // 0x80169F20: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169F24: jal         0x800F4650
    // 0x80169F28: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_14;
    // 0x80169F28: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_14:
    // 0x80169F2C: jal         0x80169BF0
    // 0x80169F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_15;
    // 0x80169F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80169F34: b           L_8016A364
    // 0x80169F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x80169F38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80169F3C:
    // 0x80169F3C: bne         $v0, $at, L_80169F6C
    if (ctx->r2 != ctx->r1) {
        // 0x80169F40: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80169F6C;
    }
    // 0x80169F40: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80169F44: sw          $a0, 0xE0($v1)
    MEM_W(0XE0, ctx->r3) = ctx->r4;
    // 0x80169F48: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x80169F4C: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x80169F50: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169F54: jal         0x800F46B0
    // 0x80169F58: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetRWallEdgeD(rdram, ctx);
        goto after_16;
    // 0x80169F58: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_16:
    // 0x80169F5C: jal         0x80169BF0
    // 0x80169F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_17;
    // 0x80169F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80169F64: b           L_8016A364
    // 0x80169F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x80169F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80169F6C:
    // 0x80169F6C: jal         0x8016981C
    // 0x80169F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_18;
    // 0x80169F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80169F74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169F78: beq         $v0, $at, L_80169F98
    if (ctx->r2 == ctx->r1) {
        // 0x80169F7C: nop
    
            goto L_80169F98;
    }
    // 0x80169F7C: nop

    // 0x80169F80: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80169F84: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169F88: jal         0x800FF648
    // 0x80169F8C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_19;
    // 0x80169F8C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_19:
    // 0x80169F90: b           L_8016A360
    // 0x80169F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x80169F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169F98:
    // 0x80169F98: b           L_8016A360
    // 0x80169F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x80169F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169FA0: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
L_80169FA4:
    // 0x80169FA4: jal         0x800FC67C
    // 0x80169FA8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_20;
    // 0x80169FA8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_20:
    // 0x80169FAC: bne         $v0, $zero, L_80169FCC
    if (ctx->r2 != 0) {
        // 0x80169FB0: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_80169FCC;
    }
    // 0x80169FB0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169FB4: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80169FB8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169FBC: jal         0x800FF648
    // 0x80169FC0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_21;
    // 0x80169FC0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_21:
    // 0x80169FC4: b           L_8016A360
    // 0x80169FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x80169FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169FCC:
    // 0x80169FCC: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169FD0: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
    // 0x80169FD4: addiu       $t0, $v1, 0x2A0
    ctx->r8 = ADD32(ctx->r3, 0X2A0);
    // 0x80169FD8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80169FDC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80169FE0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80169FE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169FE8: jal         0x800F4194
    // 0x80169FEC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_22;
    // 0x80169FEC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_22:
    // 0x80169FF0: beq         $v0, $zero, L_8016A040
    if (ctx->r2 == 0) {
        // 0x80169FF4: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_8016A040;
    }
    // 0x80169FF4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80169FF8: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80169FFC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8016A000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A004: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8016A008: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016A00C: jal         0x8016981C
    // 0x8016A010: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_23;
    // 0x8016A010: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    after_23:
    // 0x8016A014: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A018: bne         $v0, $at, L_8016A038
    if (ctx->r2 != ctx->r1) {
        // 0x8016A01C: nop
    
            goto L_8016A038;
    }
    // 0x8016A01C: nop

    // 0x8016A020: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A024: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A028: jal         0x800FF648
    // 0x8016A02C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_24;
    // 0x8016A02C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_24:
    // 0x8016A030: b           L_8016A360
    // 0x8016A034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A038:
    // 0x8016A038: b           L_8016A360
    // 0x8016A03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A040:
    // 0x8016A040: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x8016A044: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A048: bnel        $t1, $at, L_8016A06C
    if (ctx->r9 != ctx->r1) {
        // 0x8016A04C: lw          $a0, 0xCC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XCC);
            goto L_8016A06C;
    }
    goto skip_4;
    // 0x8016A04C: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
    skip_4:
    // 0x8016A050: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
    // 0x8016A054: jal         0x800FAC64
    // 0x8016A058: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeRightULineID(rdram, ctx);
        goto after_25;
    // 0x8016A058: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_25:
    // 0x8016A05C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A060: b           L_8016A07C
    // 0x8016A064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8016A07C;
    // 0x8016A064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016A068: lw          $a0, 0xCC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XCC);
L_8016A06C:
    // 0x8016A06C: jal         0x800FAD24
    // 0x8016A070: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeRightDLineID(rdram, ctx);
        goto after_26;
    // 0x8016A070: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_26:
    // 0x8016A074: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8016A07C:
    // 0x8016A07C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016A080: beq         $v0, $at, L_8016A090
    if (ctx->r2 == ctx->r1) {
        // 0x8016A084: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8016A090;
    }
    // 0x8016A084: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8016A088: bnel        $v0, $at, L_8016A0C8
    if (ctx->r2 != ctx->r1) {
        // 0x8016A08C: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_8016A0C8;
    }
    goto skip_5;
    // 0x8016A08C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    skip_5:
L_8016A090:
    // 0x8016A090: jal         0x8016981C
    // 0x8016A094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_27;
    // 0x8016A094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8016A098: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016A09C: beq         $v0, $at, L_8016A0BC
    if (ctx->r2 == ctx->r1) {
        // 0x8016A0A0: nop
    
            goto L_8016A0BC;
    }
    // 0x8016A0A0: nop

    // 0x8016A0A4: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A0A8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A0AC: jal         0x800FF648
    // 0x8016A0B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_28;
    // 0x8016A0B0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_28:
    // 0x8016A0B4: b           L_8016A360
    // 0x8016A0B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A0B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A0BC:
    // 0x8016A0BC: b           L_8016A360
    // 0x8016A0C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A0C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016A0C4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8016A0C8:
    // 0x8016A0C8: jal         0x800FA8A4
    // 0x8016A0CC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_29;
    // 0x8016A0CC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_29:
    // 0x8016A0D0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A0D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A0D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8016A0DC: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x8016A0E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8016A0E4: bne         $t2, $at, L_8016A11C
    if (ctx->r10 != ctx->r1) {
        // 0x8016A0E8: nop
    
            goto L_8016A11C;
    }
    // 0x8016A0E8: nop

    // 0x8016A0EC: bne         $v0, $zero, L_8016A14C
    if (ctx->r2 != 0) {
        // 0x8016A0F0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8016A14C;
    }
    // 0x8016A0F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8016A0F4: sw          $a0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r4;
    // 0x8016A0F8: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016A0FC: sw          $t3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r11;
    // 0x8016A100: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8016A104: jal         0x800F4428
    // 0x8016A108: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_30;
    // 0x8016A108: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_30:
    // 0x8016A10C: jal         0x80169BF0
    // 0x8016A110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_31;
    // 0x8016A110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8016A114: b           L_8016A364
    // 0x8016A118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x8016A118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016A11C:
    // 0x8016A11C: bne         $v0, $zero, L_8016A14C
    if (ctx->r2 != 0) {
        // 0x8016A120: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_8016A14C;
    }
    // 0x8016A120: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8016A124: sw          $a0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r4;
    // 0x8016A128: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016A12C: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
    // 0x8016A130: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8016A134: jal         0x800F4408
    // 0x8016A138: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_32;
    // 0x8016A138: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_32:
    // 0x8016A13C: jal         0x80169BF0
    // 0x8016A140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_33;
    // 0x8016A140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x8016A144: b           L_8016A364
    // 0x8016A148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x8016A148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016A14C:
    // 0x8016A14C: jal         0x8016981C
    // 0x8016A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_34;
    // 0x8016A150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8016A154: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016A158: beq         $v0, $at, L_8016A178
    if (ctx->r2 == ctx->r1) {
        // 0x8016A15C: nop
    
            goto L_8016A178;
    }
    // 0x8016A15C: nop

    // 0x8016A160: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A164: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A168: jal         0x800FF648
    // 0x8016A16C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_35;
    // 0x8016A16C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_35:
    // 0x8016A170: b           L_8016A360
    // 0x8016A174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A178:
    // 0x8016A178: b           L_8016A360
    // 0x8016A17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A180:
    // 0x8016A180: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
    // 0x8016A184: jal         0x800FC67C
    // 0x8016A188: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_36;
    // 0x8016A188: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_36:
    // 0x8016A18C: bne         $v0, $zero, L_8016A1AC
    if (ctx->r2 != 0) {
        // 0x8016A190: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_8016A1AC;
    }
    // 0x8016A190: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A194: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A198: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A19C: jal         0x800FF648
    // 0x8016A1A0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_37;
    // 0x8016A1A0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_37:
    // 0x8016A1A4: b           L_8016A360
    // 0x8016A1A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A1A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A1AC:
    // 0x8016A1AC: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8016A1B0: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
    // 0x8016A1B4: addiu       $t5, $v1, 0x2A0
    ctx->r13 = ADD32(ctx->r3, 0X2A0);
    // 0x8016A1B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8016A1BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8016A1C0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8016A1C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016A1C8: jal         0x800F41C0
    // 0x8016A1CC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_38;
    // 0x8016A1CC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_38:
    // 0x8016A1D0: beq         $v0, $zero, L_8016A220
    if (ctx->r2 == 0) {
        // 0x8016A1D4: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_8016A220;
    }
    // 0x8016A1D4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A1D8: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8016A1DC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8016A1E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016A1E4: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8016A1E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016A1EC: jal         0x8016981C
    // 0x8016A1F0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_39;
    // 0x8016A1F0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    after_39:
    // 0x8016A1F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A1F8: bne         $v0, $at, L_8016A218
    if (ctx->r2 != ctx->r1) {
        // 0x8016A1FC: nop
    
            goto L_8016A218;
    }
    // 0x8016A1FC: nop

    // 0x8016A200: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A204: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A208: jal         0x800FF648
    // 0x8016A20C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_40;
    // 0x8016A20C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_40:
    // 0x8016A210: b           L_8016A360
    // 0x8016A214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A218:
    // 0x8016A218: b           L_8016A360
    // 0x8016A21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A220:
    // 0x8016A220: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x8016A224: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A228: bnel        $t6, $at, L_8016A24C
    if (ctx->r14 != ctx->r1) {
        // 0x8016A22C: lw          $a0, 0xE0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XE0);
            goto L_8016A24C;
    }
    goto skip_6;
    // 0x8016A22C: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
    skip_6:
    // 0x8016A230: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
    // 0x8016A234: jal         0x800FADE4
    // 0x8016A238: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeLeftULineID(rdram, ctx);
        goto after_41;
    // 0x8016A238: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_41:
    // 0x8016A23C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A240: b           L_8016A25C
    // 0x8016A244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8016A25C;
    // 0x8016A244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016A248: lw          $a0, 0xE0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XE0);
L_8016A24C:
    // 0x8016A24C: jal         0x800FAEA4
    // 0x8016A250: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    mpCollisionGetEdgeLeftDLineID(rdram, ctx);
        goto after_42;
    // 0x8016A250: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_42:
    // 0x8016A254: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8016A25C:
    // 0x8016A25C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016A260: beq         $v0, $at, L_8016A270
    if (ctx->r2 == ctx->r1) {
        // 0x8016A264: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8016A270;
    }
    // 0x8016A264: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8016A268: bnel        $v0, $at, L_8016A2A8
    if (ctx->r2 != ctx->r1) {
        // 0x8016A26C: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_8016A2A8;
    }
    goto skip_7;
    // 0x8016A26C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    skip_7:
L_8016A270:
    // 0x8016A270: jal         0x8016981C
    // 0x8016A274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_43;
    // 0x8016A274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8016A278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016A27C: beq         $v0, $at, L_8016A29C
    if (ctx->r2 == ctx->r1) {
        // 0x8016A280: nop
    
            goto L_8016A29C;
    }
    // 0x8016A280: nop

    // 0x8016A284: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A288: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A28C: jal         0x800FF648
    // 0x8016A290: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_44;
    // 0x8016A290: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_44:
    // 0x8016A294: b           L_8016A360
    // 0x8016A298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A29C:
    // 0x8016A29C: b           L_8016A360
    // 0x8016A2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016A2A4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8016A2A8:
    // 0x8016A2A8: jal         0x800FA8A4
    // 0x8016A2AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_45;
    // 0x8016A2AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_45:
    // 0x8016A2B0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8016A2B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016A2B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8016A2BC: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x8016A2C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8016A2C4: bne         $t7, $at, L_8016A2FC
    if (ctx->r15 != ctx->r1) {
        // 0x8016A2C8: nop
    
            goto L_8016A2FC;
    }
    // 0x8016A2C8: nop

    // 0x8016A2CC: bne         $v0, $zero, L_8016A32C
    if (ctx->r2 != 0) {
        // 0x8016A2D0: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8016A32C;
    }
    // 0x8016A2D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8016A2D4: sw          $a0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r4;
    // 0x8016A2D8: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016A2DC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8016A2E0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8016A2E4: jal         0x800F4408
    // 0x8016A2E8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_46;
    // 0x8016A2E8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_46:
    // 0x8016A2EC: jal         0x80169BF0
    // 0x8016A2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_47;
    // 0x8016A2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x8016A2F4: b           L_8016A364
    // 0x8016A2F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x8016A2F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016A2FC:
    // 0x8016A2FC: bne         $v0, $zero, L_8016A32C
    if (ctx->r2 != 0) {
        // 0x8016A300: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8016A32C;
    }
    // 0x8016A300: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8016A304: sw          $a0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r4;
    // 0x8016A308: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016A30C: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x8016A310: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8016A314: jal         0x800F4428
    // 0x8016A318: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_48;
    // 0x8016A318: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_48:
    // 0x8016A31C: jal         0x80169BF0
    // 0x8016A320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundCheckDestroy(rdram, ctx);
        goto after_49;
    // 0x8016A320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8016A324: b           L_8016A364
    // 0x8016A328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016A364;
    // 0x8016A328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016A32C:
    // 0x8016A32C: jal         0x8016981C
    // 0x8016A330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpPikachuThunderJoltGroundGetStatus(rdram, ctx);
        goto after_50;
    // 0x8016A330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x8016A334: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016A338: beq         $v0, $at, L_8016A358
    if (ctx->r2 == ctx->r1) {
        // 0x8016A33C: nop
    
            goto L_8016A358;
    }
    // 0x8016A33C: nop

    // 0x8016A340: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016A344: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016A348: jal         0x800FF648
    // 0x8016A34C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_51;
    // 0x8016A34C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_51:
    // 0x8016A350: b           L_8016A360
    // 0x8016A354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016A360;
    // 0x8016A354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016A358:
    // 0x8016A358: b           L_8016A360
    // 0x8016A35C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A360;
    // 0x8016A35C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A360:
    // 0x8016A360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016A364:
    // 0x8016A364: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8016A368: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8016A36C: jr          $ra
    // 0x8016A370: nop

    return;
    // 0x8016A370: nop

;}
RECOMP_FUNC void mvUnknownMarioFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D4C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D4C4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018D4C8: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018D4CC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018D4D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D4D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018D4D8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018D4DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018D4E0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018D4E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D4E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018D4EC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018D4F0: jal         0x800FCB70
    // 0x8018D4F4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018D4F4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018D4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D500: jr          $ra
    // 0x8018D504: nop

    return;
    // 0x8018D504: nop

;}
RECOMP_FUNC void func_ovl27_801376F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801376F0: jr          $ra
    // 0x801376F4: nop

    return;
    // 0x801376F4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingSetCursorGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134CC8: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x80134CCC: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134CD0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80134CD4: addiu       $v1, $v1, -0x7AA8
    ctx->r3 = ADD32(ctx->r3, -0X7AA8);
    // 0x80134CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134CDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134CE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134CE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134CE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80134CEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134CF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134CF4: mflo        $t6
    ctx->r14 = lo;
    // 0x80134CF8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80134CFC: sw          $a0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r4;
    // 0x80134D00: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134D04: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80134D08: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80134D0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80134D10: mflo        $t7
    ctx->r15 = lo;
    // 0x80134D14: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
    // 0x80134D18: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x80134D1C: sw          $a1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r5;
    // 0x80134D20: jal         0x80133E30
    // 0x80134D24: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    mnPlayers1PTrainingUpdateFighter(rdram, ctx);
        goto after_0;
    // 0x80134D24: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    after_0:
    // 0x80134D28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80134D2C: jal         0x801348F0
    // 0x80134D30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PTrainingUpdateCursorGrabPriorities(rdram, ctx);
        goto after_1;
    // 0x80134D30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80134D34: jal         0x80134C64
    // 0x80134D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PTrainingSetCursorPuckOffset(rdram, ctx);
        goto after_2;
    // 0x80134D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80134D3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80134D40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80134D44: jal         0x80133A90
    // 0x80134D48: lw          $a2, 0x50($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X50);
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_3;
    // 0x80134D48: lw          $a2, 0x50($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X50);
    after_3:
    // 0x80134D4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80134D50: sw          $t9, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r25;
    // 0x80134D54: jal         0x800269C0
    // 0x80134D58: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80134D58: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_4:
    // 0x80134D5C: jal         0x801342B8
    // 0x80134D60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayers1PTrainingDestroyHandicapLevel(rdram, ctx);
        goto after_5;
    // 0x80134D60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80134D64: jal         0x80133F68
    // 0x80134D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayers1PTrainingDestroyPortraitFlash(rdram, ctx);
        goto after_6;
    // 0x80134D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80134D6C: jal         0x80133EE0
    // 0x80134D70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayers1PTrainingUpdateNameAndEmblem(rdram, ctx);
        goto after_7;
    // 0x80134D70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80134D74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134D78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134D7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134D80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134D84: jr          $ra
    // 0x80134D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80134D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PGameUpdateNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801358C8: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x801358CC: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x801358D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801358D4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801358D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801358DC: bne         $t6, $at, L_80135900
    if (ctx->r14 != ctx->r1) {
        // 0x801358E0: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80135900;
    }
    // 0x801358E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801358E4: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x801358E8: bnel        $t7, $zero, L_80135904
    if (ctx->r15 != 0) {
        // 0x801358EC: lw          $t0, 0xC($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XC);
            goto L_80135904;
    }
    goto skip_0;
    // 0x801358EC: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x801358F0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x801358F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801358F8: b           L_80135914
    // 0x801358FC: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
        goto L_80135914;
    // 0x801358FC: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
L_80135900:
    // 0x80135900: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
L_80135904:
    // 0x80135904: sw          $zero, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = 0;
    // 0x80135908: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x8013590C: jal         0x80132DA0
    // 0x80135910: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    mnPlayers1PGameMakeNameAndEmblem(rdram, ctx);
        goto after_0;
    // 0x80135910: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    after_0:
L_80135914:
    // 0x80135914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013591C: jr          $ra
    // 0x80135920: nop

    return;
    // 0x80135920: nop

;}
RECOMP_FUNC void ftParamGetPlayerNumGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7ED4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800E7ED8: lw          $v1, 0x66FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66FC);
    // 0x800E7EDC: beql        $v1, $zero, L_800E7F0C
    if (ctx->r3 == 0) {
        // 0x800E7EE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E7F0C;
    }
    goto skip_0;
    // 0x800E7EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800E7EE4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
L_800E7EE8:
    // 0x800E7EE8: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x800E7EEC: bnel        $a0, $t6, L_800E7F00
    if (ctx->r4 != ctx->r14) {
        // 0x800E7EF0: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800E7F00;
    }
    goto skip_1;
    // 0x800E7EF0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x800E7EF4: jr          $ra
    // 0x800E7EF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E7EF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E7EFC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_800E7F00:
    // 0x800E7F00: bnel        $v1, $zero, L_800E7EE8
    if (ctx->r3 != 0) {
        // 0x800E7F04: lw          $v0, 0x84($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X84);
            goto L_800E7EE8;
    }
    goto skip_2;
    // 0x800E7F04: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    skip_2:
    // 0x800E7F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E7F0C:
    // 0x800E7F0C: jr          $ra
    // 0x800E7F10: nop

    return;
    // 0x800E7F10: nop

;}
RECOMP_FUNC void func_ovl8_8037FBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FBC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037FBC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037FBC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037FBCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037FBD0: jal         0x803717A0
    // 0x8037FBD4: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037FBD4: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x8037FBD8: beq         $v0, $zero, L_8037FC04
    if (ctx->r2 == 0) {
        // 0x8037FBDC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037FC04;
    }
    // 0x8037FBDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037FBE0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8037FBE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037FBE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037FBEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8037FBF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8037FBF4: jal         0x8037FCD8
    // 0x8037FBF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_8037FCD8(rdram, ctx);
        goto after_1;
    // 0x8037FBF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8037FBFC: b           L_8037FC08
    // 0x8037FC00: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8037FC08;
    // 0x8037FC00: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8037FC04:
    // 0x8037FC04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037FC08:
    // 0x8037FC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037FC0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037FC10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037FC14: jr          $ra
    // 0x8037FC18: nop

    return;
    // 0x8037FC18: nop

;}
RECOMP_FUNC void wpLinkBoomerangAddVelSqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016CE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016CE98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8016CE9C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8016CEA0: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8016CEA4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8016CEA8: nop

    // 0x8016CEAC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016CEB0: jal         0x80033510
    // 0x8016CEB4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016CEB4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8016CEB8: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8016CEBC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8016CEC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8016CEC4: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8016CEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016CECC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8016CED0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8016CED4: bc1fl       L_8016CEE4
    if (!c1cs) {
        // 0x8016CED8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8016CEE4;
    }
    goto skip_0;
    // 0x8016CED8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8016CEDC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8016CEE0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8016CEE4:
    // 0x8016CEE4: jr          $ra
    // 0x8016CEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8016CEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_ovl8_80381308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381308: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8038130C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80381310: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80381314: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80381318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038131C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80381320: bnel        $t6, $zero, L_80381334
    if (ctx->r14 != 0) {
        // 0x80381324: lw          $v1, 0x4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X4);
            goto L_80381334;
    }
    goto skip_0;
    // 0x80381324: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80381328: b           L_803816FC
    // 0x8038132C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_803816FC;
    // 0x8038132C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80381330: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_80381334:
    // 0x80381334: beql        $v1, $zero, L_80381344
    if (ctx->r3 == 0) {
        // 0x80381338: lhu         $a3, 0x24($v1)
        ctx->r7 = MEM_HU(ctx->r3, 0X24);
            goto L_80381344;
    }
    goto skip_1;
    // 0x80381338: lhu         $a3, 0x24($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X24);
    skip_1:
    // 0x8038133C: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x80381340: lhu         $a3, 0x24($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X24);
L_80381344:
    // 0x80381344: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80381348: beq         $a3, $at, L_8038136C
    if (ctx->r7 == ctx->r1) {
        // 0x8038134C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8038136C;
    }
    // 0x8038134C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80381350: beq         $a3, $at, L_8038137C
    if (ctx->r7 == ctx->r1) {
        // 0x80381354: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8038137C;
    }
    // 0x80381354: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80381358: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8038135C: beq         $a3, $at, L_80381388
    if (ctx->r7 == ctx->r1) {
        // 0x80381360: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_80381388;
    }
    // 0x80381360: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80381364: b           L_80381394
    // 0x80381368: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
        goto L_80381394;
    // 0x80381368: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
L_8038136C:
    // 0x8038136C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80381370: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381374: b           L_80381390
    // 0x80381378: sh          $t7, -0x430C($at)
    MEM_H(-0X430C, ctx->r1) = ctx->r15;
        goto L_80381390;
    // 0x80381378: sh          $t7, -0x430C($at)
    MEM_H(-0X430C, ctx->r1) = ctx->r15;
L_8038137C:
    // 0x8038137C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80381380: b           L_80381390
    // 0x80381384: sh          $t8, -0x430C($at)
    MEM_H(-0X430C, ctx->r1) = ctx->r24;
        goto L_80381390;
    // 0x80381384: sh          $t8, -0x430C($at)
    MEM_H(-0X430C, ctx->r1) = ctx->r24;
L_80381388:
    // 0x80381388: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038138C: sh          $t9, -0x430C($at)
    MEM_H(-0X430C, ctx->r1) = ctx->r25;
L_80381390:
    // 0x80381390: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
L_80381394:
    // 0x80381394: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80381398: addiu       $a1, $a1, -0x431C
    ctx->r5 = ADD32(ctx->r5, -0X431C);
    // 0x8038139C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x803813A0: lh          $t2, 0xA($a2)
    ctx->r10 = MEM_H(ctx->r6, 0XA);
    // 0x803813A4: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x803813A8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x803813AC: beql        $v1, $zero, L_803813BC
    if (ctx->r3 == 0) {
        // 0x803813B0: lwl         $t5, 0x14($v1)
        ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r3, 0X14);
            goto L_803813BC;
    }
    goto skip_2;
    // 0x803813B0: lwl         $t5, 0x14($v1)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r3, 0X14);
    skip_2:
    // 0x803813B4: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x803813B8: lwl         $t5, 0x14($v1)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r3, 0X14);
L_803813BC:
    // 0x803813BC: lwr         $t5, 0x17($v1)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r3, 0X17);
    // 0x803813C0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x803813C4: addiu       $t3, $t3, -0x4314
    ctx->r11 = ADD32(ctx->r11, -0X4314);
    // 0x803813C8: swl         $t5, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r13);
    // 0x803813CC: swr         $t5, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r13);
    // 0x803813D0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x803813D4: beql        $v1, $zero, L_803813E4
    if (ctx->r3 == 0) {
        // 0x803813D8: lwl         $t8, 0x18($v1)
        ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r3, 0X18);
            goto L_803813E4;
    }
    goto skip_3;
    // 0x803813D8: lwl         $t8, 0x18($v1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r3, 0X18);
    skip_3:
    // 0x803813DC: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x803813E0: lwl         $t8, 0x18($v1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r3, 0X18);
L_803813E4:
    // 0x803813E4: lwr         $t8, 0x1B($v1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r3, 0X1B);
    // 0x803813E8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803813EC: addiu       $t6, $t6, -0x4310
    ctx->r14 = ADD32(ctx->r14, -0X4310);
    // 0x803813F0: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x803813F4: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    // 0x803813F8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803813FC: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
    // 0x80381400: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80381404: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80381408: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x8038140C: lh          $t1, 0x28($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X28);
    // 0x80381410: jalr        $t9
    // 0x80381414: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80381414: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    after_0:
    // 0x80381418: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8038141C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80381420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80381424: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80381428: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8038142C: sw          $t2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r10;
    // 0x80381430: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x80381434: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80381438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8038143C: lw          $v0, 0x38($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X38);
    // 0x80381440: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x80381444: lw          $t9, 0x11C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X11C);
    // 0x80381448: lh          $t5, 0x118($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X118);
    // 0x8038144C: jalr        $t9
    // 0x80381450: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80381450: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    after_1:
    // 0x80381454: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80381458: beq         $t6, $zero, L_803814A4
    if (ctx->r14 == 0) {
        // 0x8038145C: nop
    
            goto L_803814A4;
    }
    // 0x8038145C: nop

    // 0x80381460: jal         0x803717A0
    // 0x80381464: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_ovl8_803717A0(rdram, ctx);
        goto after_2;
    // 0x80381464: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_2:
    // 0x80381468: beq         $v0, $zero, L_80381498
    if (ctx->r2 == 0) {
        // 0x8038146C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80381498;
    }
    // 0x8038146C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80381470: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80381474: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x80381478: addiu       $a3, $a3, -0x431C
    ctx->r7 = ADD32(ctx->r7, -0X431C);
    // 0x8038147C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80381480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80381484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80381488: jal         0x80380B6C
    // 0x8038148C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80380B6C(rdram, ctx);
        goto after_3;
    // 0x8038148C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80381490: b           L_803814E4
    // 0x80381494: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_803814E4;
    // 0x80381494: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80381498:
    // 0x80381498: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8038149C: b           L_803814E4
    // 0x803814A0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
        goto L_803814E4;
    // 0x803814A0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_803814A4:
    // 0x803814A4: jal         0x803717A0
    // 0x803814A8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_ovl8_803717A0(rdram, ctx);
        goto after_4;
    // 0x803814A8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_4:
    // 0x803814AC: beq         $v0, $zero, L_803814DC
    if (ctx->r2 == 0) {
        // 0x803814B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803814DC;
    }
    // 0x803814B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803814B4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803814B8: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803814BC: addiu       $a3, $a3, -0x431C
    ctx->r7 = ADD32(ctx->r7, -0X431C);
    // 0x803814C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x803814C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803814C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803814CC: jal         0x80380048
    // 0x803814D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_ovl8_80380048(rdram, ctx);
        goto after_5;
    // 0x803814D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x803814D4: b           L_803814E0
    // 0x803814D8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_803814E0;
    // 0x803814D8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_803814DC:
    // 0x803814DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803814E0:
    // 0x803814E0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_803814E4:
    // 0x803814E4: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x803814E8: lh          $t1, 0xB0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XB0);
    // 0x803814EC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x803814F0: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x803814F4: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x803814F8: jalr        $t9
    // 0x803814FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x803814FC: nop

    after_6:
    // 0x80381500: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80381504: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80381508: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8038150C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80381510: nop

    // 0x80381514: sw          $t3, 0xAC($a2)
    MEM_W(0XAC, ctx->r6) = ctx->r11;
    // 0x80381518: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8038151C: beql        $v1, $zero, L_8038152C
    if (ctx->r3 == 0) {
        // 0x80381520: lw          $t4, 0x20($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X20);
            goto L_8038152C;
    }
    goto skip_4;
    // 0x80381520: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
    skip_4:
    // 0x80381524: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
    // 0x80381528: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
L_8038152C:
    // 0x8038152C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80381530: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80381534: sw          $t6, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->r14;
    // 0x80381538: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x8038153C: sw          $t5, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r13;
    // 0x80381540: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x80381544: sw          $t6, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r14;
    // 0x80381548: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    // 0x8038154C: sw          $t5, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r13;
    // 0x80381550: lw          $t6, 0x3C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X3C);
    // 0x80381554: sw          $t6, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r14;
    // 0x80381558: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x8038155C: sw          $t5, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->r13;
    // 0x80381560: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x80381564: sw          $t6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r14;
    // 0x80381568: jal         0x80380414
    // 0x8038156C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_ovl8_80380414(rdram, ctx);
        goto after_7;
    // 0x8038156C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_7:
    // 0x80381570: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80381574: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80381578: bgez        $v0, L_80381590
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8038157C: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80381590;
    }
    // 0x8038157C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80381580: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80381584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80381588: nop

    // 0x8038158C: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_80381590:
    // 0x80381590: beql        $a2, $zero, L_803815C0
    if (ctx->r6 == 0) {
        // 0x80381594: sw          $zero, 0x18($s0)
        MEM_W(0X18, ctx->r16) = 0;
            goto L_803815C0;
    }
    goto skip_5;
    // 0x80381594: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    skip_5:
    // 0x80381598: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x8038159C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x803815A0: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x803815A4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x803815A8: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x803815AC: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    // 0x803815B0: jalr        $t9
    // 0x803815B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x803815B4: nop

    after_8:
    // 0x803815B8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x803815BC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
L_803815C0:
    // 0x803815C0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x803815C4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x803815C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803815CC: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x803815D0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x803815D4: lw          $v0, 0x38($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X38);
    // 0x803815D8: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x803815DC: lh          $t2, 0x118($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X118);
    // 0x803815E0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x803815E4: lw          $t9, 0x11C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X11C);
    // 0x803815E8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    // 0x803815EC: jalr        $t9
    // 0x803815F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x803815F0: nop

    after_9:
    // 0x803815F4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x803815F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x803815FC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80381600: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80381604: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    // 0x80381608: bc1tl       L_80381660
    if (c1cs) {
        // 0x8038160C: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_80381660;
    }
    goto skip_6;
    // 0x8038160C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_6:
    // 0x80381610: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80381614: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80381618: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8038161C: lh          $t4, 0x40($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X40);
    // 0x80381620: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80381624: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x80381628: addu        $a0, $t4, $v0
    ctx->r4 = ADD32(ctx->r12, ctx->r2);
    // 0x8038162C: jalr        $t9
    // 0x80381630: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x80381630: nop

    after_10:
    // 0x80381634: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80381638: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8038163C: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80381640: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80381644: lw          $t9, 0x94($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X94);
    // 0x80381648: lh          $t5, 0x90($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X90);
    // 0x8038164C: jalr        $t9
    // 0x80381650: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x80381650: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    after_11:
    // 0x80381654: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80381658: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8038165C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_80381660:
    // 0x80381660: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80381664: bc1tl       L_803816C0
    if (c1cs) {
        // 0x80381668: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_803816C0;
    }
    goto skip_7;
    // 0x80381668: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_7:
    // 0x8038166C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80381670: nop

    // 0x80381674: bc1fl       L_803816C0
    if (!c1cs) {
        // 0x80381678: c.eq.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
            goto L_803816C0;
    }
    goto skip_8;
    // 0x80381678: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    skip_8:
    // 0x8038167C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80381680: beq         $v0, $zero, L_8038168C
    if (ctx->r2 == 0) {
        // 0x80381684: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8038168C;
    }
    // 0x80381684: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80381688: lw          $v1, 0x38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38);
L_8038168C:
    // 0x8038168C: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80381690: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80381694: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80381698: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8038169C: lh          $t6, 0x18($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X18);
    // 0x803816A0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x803816A4: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x803816A8: addu        $a0, $t6, $t0
    ctx->r4 = ADD32(ctx->r14, ctx->r8);
    // 0x803816AC: jalr        $t9
    // 0x803816B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x803816B0: nop

    after_12:
    // 0x803816B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x803816B8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x803816BC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
L_803816C0:
    // 0x803816C0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x803816C4: bc1fl       L_803816FC
    if (!c1cs) {
        // 0x803816C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_803816FC;
    }
    goto skip_9;
    // 0x803816C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_9:
    // 0x803816CC: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x803816D0: nop

    // 0x803816D4: bc1fl       L_803816FC
    if (!c1cs) {
        // 0x803816D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_803816FC;
    }
    goto skip_10;
    // 0x803816D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_10:
    // 0x803816DC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x803816E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x803816E4: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x803816E8: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x803816EC: lh          $t7, 0x40($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X40);
    // 0x803816F0: jalr        $t9
    // 0x803816F4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x803816F4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    after_13:
    // 0x803816F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_803816FC:
    // 0x803816FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80381700: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80381704: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80381708: jr          $ra
    // 0x8038170C: nop

    return;
    // 0x8038170C: nop

;}
RECOMP_FUNC void func_800062B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062B4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800062B8: lw          $t9, 0x6668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6668);
    // 0x800062BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800062C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800062C4: jalr        $t9
    // 0x800062C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800062C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800062CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800062D0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800062D4: jalr        $t9
    // 0x800062D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800062D8: nop

    after_1:
    // 0x800062DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800062E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800062E4: jr          $ra
    // 0x800062E8: nop

    return;
    // 0x800062E8: nop

;}
RECOMP_FUNC void func_ovl8_80371C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371C8C: lwl         $t7, 0x2($a0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r4, 0X2);
    // 0x80371C90: lwr         $t7, 0x5($a0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r4, 0X5);
    // 0x80371C94: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x80371C98: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x80371C9C: lwl         $t6, 0x6($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, 0X6);
    // 0x80371CA0: lwr         $t6, 0x9($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, 0X9);
    // 0x80371CA4: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80371CA8: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80371CAC: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x80371CB0: jr          $ra
    // 0x80371CB4: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    return;
    // 0x80371CB4: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
;}
RECOMP_FUNC void mvOpeningCliffFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132414: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132418: addiu       $v1, $v1, 0x27CC
    ctx->r3 = ADD32(ctx->r3, 0X27CC);
    // 0x8013241C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132428: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013242C: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132434: bne         $at, $zero, L_801324D0
    if (ctx->r1 != 0) {
        // 0x80132438: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_801324D0;
    }
    // 0x80132438: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013243C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132440: addiu       $a2, $a2, 0x27DC
    ctx->r6 = ADD32(ctx->r6, 0X27DC);
    // 0x80132444: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132448: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x8013244C: beq         $v0, $zero, L_80132458
    if (ctx->r2 == 0) {
        // 0x80132450: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132458;
    }
    // 0x80132450: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132454: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132458:
    // 0x80132458: jal         0x80390A04
    // 0x8013245C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x8013245C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132460: beq         $v0, $zero, L_8013247C
    if (ctx->r2 == 0) {
        // 0x80132464: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_8013247C;
    }
    // 0x80132464: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132468: jal         0x80390AC0
    // 0x8013246C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x8013246C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132470: beq         $v0, $zero, L_8013247C
    if (ctx->r2 == 0) {
        // 0x80132474: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8013247C;
    }
    // 0x80132474: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132478: sw          $zero, 0x27DC($at)
    MEM_W(0X27DC, ctx->r1) = 0;
L_8013247C:
    // 0x8013247C: jal         0x8039076C
    // 0x80132480: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132480: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80132484: beq         $v0, $zero, L_801324A4
    if (ctx->r2 == 0) {
        // 0x80132488: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801324A4;
    }
    // 0x80132488: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013248C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132490: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132494: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80132498: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8013249C: jal         0x80005C74
    // 0x801324A0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801324A0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_801324A4:
    // 0x801324A4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801324A8: lw          $t2, 0x27CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X27CC);
    // 0x801324AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801324B0: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x801324B4: bne         $t2, $at, L_801324D0
    if (ctx->r10 != ctx->r1) {
        // 0x801324B8: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_801324D0;
    }
    // 0x801324B8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801324BC: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x801324C0: addiu       $t4, $zero, 0x2A
    ctx->r12 = ADD32(0, 0X2A);
    // 0x801324C4: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801324C8: jal         0x80005C74
    // 0x801324CC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x801324CC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_4:
L_801324D0:
    // 0x801324D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801324D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801324D8: jr          $ra
    // 0x801324DC: nop

    return;
    // 0x801324DC: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015700C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157010: jal         0x800DDE84
    // 0x80157014: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, 0X70A8);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80157014: addiu       $a1, $a1, 0x70A8
    ctx->r5 = ADD32(ctx->r5, 0X70A8);
    after_0:
    // 0x80157018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015701C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157020: jr          $ra
    // 0x80157024: nop

    return;
    // 0x80157024: nop

;}
RECOMP_FUNC void mnBackupClearSetOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D44: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80131D48: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D4C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131D50: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80131D54: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80131D58: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80131D5C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80131D60: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80131D64: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80131D68: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80131D6C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80131D70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131D74: addiu       $t7, $t7, 0x2F40
    ctx->r15 = ADD32(ctx->r15, 0X2F40);
    // 0x80131D78: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131D7C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131D80: addiu       $t6, $sp, 0xA8
    ctx->r14 = ADD32(ctx->r29, 0XA8);
    // 0x80131D84: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131D88: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131D8C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131D90: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131D94: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131D98: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131D9C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131DA0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80131DA4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80131DA8: addiu       $t1, $t1, 0x2F58
    ctx->r9 = ADD32(ctx->r9, 0X2F58);
    // 0x80131DAC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80131DB0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80131DB4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80131DB8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131DBC: addiu       $t0, $sp, 0x90
    ctx->r8 = ADD32(ctx->r29, 0X90);
    // 0x80131DC0: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80131DC4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131DC8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80131DCC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80131DD0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80131DD4: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80131DD8: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80131DDC: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80131DE0: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80131DE4: addiu       $t5, $t5, 0x2F70
    ctx->r13 = ADD32(ctx->r13, 0X2F70);
    // 0x80131DE8: addiu       $t8, $t5, 0x30
    ctx->r24 = ADD32(ctx->r13, 0X30);
    // 0x80131DEC: addiu       $t4, $sp, 0x60
    ctx->r12 = ADD32(ctx->r29, 0X60);
    // 0x80131DF0: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80131DF4: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
L_80131DF8:
    // 0x80131DF8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80131DFC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80131E00: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80131E04: sw          $t7, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r15;
    // 0x80131E08: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x80131E0C: sw          $t6, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r14;
    // 0x80131E10: lw          $t7, -0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X4);
    // 0x80131E14: bne         $t5, $t8, L_80131DF8
    if (ctx->r13 != ctx->r24) {
        // 0x80131E18: sw          $t7, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r15;
            goto L_80131DF8;
    }
    // 0x80131E18: sw          $t7, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r15;
    // 0x80131E1C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80131E20: addiu       $t9, $t9, -0x3100
    ctx->r25 = ADD32(ctx->r25, -0X3100);
    // 0x80131E24: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80131E28: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80131E2C: addiu       $s6, $s6, 0x31B0
    ctx->r22 = ADD32(ctx->r22, 0X31B0);
    // 0x80131E30: addiu       $fp, $fp, 0x30C0
    ctx->r30 = ADD32(ctx->r30, 0X30C0);
    // 0x80131E34: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80131E38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131E3C: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x80131E40: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x80131E44: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80131E48: addiu       $s7, $zero, -0x21
    ctx->r23 = ADD32(0, -0X21);
    // 0x80131E4C: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
L_80131E50:
    // 0x80131E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131E5C: jal         0x80009968
    // 0x80131E60: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E60: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x80131E64: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80131E68: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80131E6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131E70: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80131E74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131E78: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80131E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131E84: jal         0x80009DF4
    // 0x80131E88: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E88: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_1:
    // 0x80131E8C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80131E90: lw          $t3, 0x4($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X4);
    // 0x80131E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E98: jal         0x800CCFDC
    // 0x80131E9C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131E9C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80131EA0: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EAC: and         $t4, $t8, $s7
    ctx->r12 = ctx->r24 & ctx->r23;
    // 0x80131EB0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131EB4: ori         $t6, $t4, 0x1
    ctx->r14 = ctx->r12 | 0X1;
    // 0x80131EB8: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131EBC: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80131EC0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131EC4: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80131EC8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131ECC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80131ED0: bne         $s1, $t7, L_80131EE8
    if (ctx->r17 != ctx->r15) {
        // 0x80131ED4: nop
    
            goto L_80131EE8;
    }
    // 0x80131ED4: nop

    // 0x80131ED8: jal         0x80131CE4
    // 0x80131EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_3;
    // 0x80131EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80131EE0: b           L_80131EF4
    // 0x80131EE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80131EF4;
    // 0x80131EE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80131EE8:
    // 0x80131EE8: jal         0x80131CE4
    // 0x80131EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_4;
    // 0x80131EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80131EF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80131EF4:
    // 0x80131EF4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80131EF8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80131EFC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80131F00: bne         $s1, $at, L_80131E50
    if (ctx->r17 != ctx->r1) {
        // 0x80131F04: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80131E50;
    }
    // 0x80131F04: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80131F08: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80131F0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131F10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80131F14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80131F18: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F1C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80131F20: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80131F24: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80131F28: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F2C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80131F30: jr          $ra
    // 0x80131F34: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80131F34: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void itMainSetSpinVelLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017250C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172510: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172514: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80172518: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8017251C: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80172520: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80172524: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80172528: nop

    // 0x8017252C: bc1fl       L_80172540
    if (!c1cs) {
        // 0x80172530: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_80172540;
    }
    goto skip_0;
    // 0x80172530: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    skip_0:
    // 0x80172534: b           L_80172540
    // 0x80172538: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
        goto L_80172540;
    // 0x80172538: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8017253C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
L_80172540:
    // 0x80172540: jal         0x80172310
    // 0x80172544: nop

    itMainSetCommonSpin(rdram, ctx);
        goto after_0;
    // 0x80172544: nop

    after_0:
    // 0x80172548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017254C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80172550: jr          $ra
    // 0x80172554: nop

    return;
    // 0x80172554: nop

;}
RECOMP_FUNC void spSetZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023880: jr          $ra
    // 0x80023884: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
    return;
    // 0x80023884: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void itSawamuraCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182AE8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182AEC: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182AF0: bnel        $a1, $zero, L_80182B1C
    if (ctx->r5 != 0) {
        // 0x80182AF4: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_80182B1C;
    }
    goto skip_0;
    // 0x80182AF4: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80182AF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182AFC: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80182B00: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182B04: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80182B08: jal         0x801826A8
    // 0x80182B0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itSawamuraFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x80182B0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80182B10: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80182B14: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182B18: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
L_80182B1C:
    // 0x80182B1C: sh          $t7, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r15;
    // 0x80182B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182B2C: jr          $ra
    // 0x80182B30: nop

    return;
    // 0x80182B30: nop

;}
RECOMP_FUNC void lbParticleGetPosVelDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D27F8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800D27FC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800D2800: addiu       $s5, $sp, 0xB8
    ctx->r21 = ADD32(ctx->r29, 0XB8);
    // 0x800D2804: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D2808: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800D280C: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800D2810: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D2814: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x800D2818: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800D281C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800D2820: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800D2824: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800D2828: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800D282C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800D2830: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800D2834: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x800D2838: jal         0x80032A40
    // 0x800D283C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800D283C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x800D2840: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2844: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800D2848: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800D284C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800D2850: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800D2854: addiu       $s4, $sp, 0x78
    ctx->r20 = ADD32(ctx->r29, 0X78);
    // 0x800D2858: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x800D285C: lwc1        $f0, 0x40($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X40);
L_800D2860:
    // 0x800D2860: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2864: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800D2868: nop

    // 0x800D286C: bc1fl       L_800D28A0
    if (!c1cs) {
        // 0x800D2870: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D28A0;
    }
    goto skip_0;
    // 0x800D2870: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x800D2874: lwc1        $f4, 0x44($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X44);
    // 0x800D2878: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x800D287C: nop

    // 0x800D2880: bc1fl       L_800D28A0
    if (!c1cs) {
        // 0x800D2884: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D28A0;
    }
    goto skip_1;
    // 0x800D2884: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x800D2888: lwc1        $f6, 0x48($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X48);
    // 0x800D288C: c.eq.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl == ctx->f6.fl;
    // 0x800D2890: nop

    // 0x800D2894: bc1tl       L_800D28C0
    if (c1cs) {
        // 0x800D2898: lwc1        $f0, 0x30($s3)
        ctx->f0.u32l = MEM_W(ctx->r19, 0X30);
            goto L_800D28C0;
    }
    goto skip_2;
    // 0x800D2898: lwc1        $f0, 0x30($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X30);
    skip_2:
    // 0x800D289C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D28A0:
    // 0x800D28A0: lw          $a2, 0x44($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X44);
    // 0x800D28A4: jal         0x8001B6EC
    // 0x800D28A8: lw          $a3, 0x48($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X48);
    syMatrixScaF(rdram, ctx);
        goto after_1;
    // 0x800D28A8: lw          $a3, 0x48($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X48);
    after_1:
    // 0x800D28AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D28B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D28B4: jal         0x80034980
    // 0x800D28B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x800D28B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x800D28BC: lwc1        $f0, 0x30($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X30);
L_800D28C0:
    // 0x800D28C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D28C4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800D28C8: nop

    // 0x800D28CC: bc1fl       L_800D2900
    if (!c1cs) {
        // 0x800D28D0: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2900;
    }
    goto skip_3;
    // 0x800D28D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_3:
    // 0x800D28D4: lwc1        $f8, 0x34($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X34);
    // 0x800D28D8: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x800D28DC: nop

    // 0x800D28E0: bc1fl       L_800D2900
    if (!c1cs) {
        // 0x800D28E4: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2900;
    }
    goto skip_4;
    // 0x800D28E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_4:
    // 0x800D28E8: lwc1        $f10, 0x38($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X38);
    // 0x800D28EC: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x800D28F0: nop

    // 0x800D28F4: bc1tl       L_800D2920
    if (c1cs) {
        // 0x800D28F8: lwc1        $f0, 0x1C($s3)
        ctx->f0.u32l = MEM_W(ctx->r19, 0X1C);
            goto L_800D2920;
    }
    goto skip_5;
    // 0x800D28F8: lwc1        $f0, 0x1C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X1C);
    skip_5:
    // 0x800D28FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D2900:
    // 0x800D2900: lw          $a2, 0x34($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X34);
    // 0x800D2904: jal         0x8001BDEC
    // 0x800D2908: lw          $a3, 0x38($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X38);
    syMatrixRotRpyRF(rdram, ctx);
        goto after_3;
    // 0x800D2908: lw          $a3, 0x38($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X38);
    after_3:
    // 0x800D290C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2910: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2914: jal         0x80034980
    // 0x800D2918: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_4;
    // 0x800D2918: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x800D291C: lwc1        $f0, 0x1C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X1C);
L_800D2920:
    // 0x800D2920: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2924: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800D2928: nop

    // 0x800D292C: bc1fl       L_800D2960
    if (!c1cs) {
        // 0x800D2930: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2960;
    }
    goto skip_6;
    // 0x800D2930: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_6:
    // 0x800D2934: lwc1        $f16, 0x20($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800D2938: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x800D293C: nop

    // 0x800D2940: bc1fl       L_800D2960
    if (!c1cs) {
        // 0x800D2944: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2960;
    }
    goto skip_7;
    // 0x800D2944: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_7:
    // 0x800D2948: lwc1        $f18, 0x24($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800D294C: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x800D2950: nop

    // 0x800D2954: bc1tl       L_800D2980
    if (c1cs) {
        // 0x800D2958: lw          $v0, 0x4C($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X4C);
            goto L_800D2980;
    }
    goto skip_8;
    // 0x800D2958: lw          $v0, 0x4C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4C);
    skip_8:
    // 0x800D295C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D2960:
    // 0x800D2960: lw          $a2, 0x20($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X20);
    // 0x800D2964: jal         0x8001B924
    // 0x800D2968: lw          $a3, 0x24($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X24);
    syMatrixTraF(rdram, ctx);
        goto after_5;
    // 0x800D2968: lw          $a3, 0x24($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X24);
    after_5:
    // 0x800D296C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2970: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2974: jal         0x80034980
    // 0x800D2978: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_6;
    // 0x800D2978: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x800D297C: lw          $v0, 0x4C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4C);
L_800D2980:
    // 0x800D2980: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D2984: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D2988: beq         $v0, $zero, L_800D2B2C
    if (ctx->r2 == 0) {
        // 0x800D298C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800D2B2C;
    }
    // 0x800D298C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800D2990: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x800D2994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D2998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D299C:
    // 0x800D299C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800D29A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D29A4: beq         $v0, $zero, L_800D29EC
    if (ctx->r2 == 0) {
        // 0x800D29A8: nop
    
            goto L_800D29EC;
    }
    // 0x800D29A8: nop

    // 0x800D29AC: beql        $v0, $s6, L_800D29D0
    if (ctx->r2 == ctx->r22) {
        // 0x800D29B0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800D29D0;
    }
    goto skip_9;
    // 0x800D29B0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_9:
    // 0x800D29B4: beql        $v0, $s7, L_800D29DC
    if (ctx->r2 == ctx->r23) {
        // 0x800D29B8: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800D29DC;
    }
    goto skip_10;
    // 0x800D29B8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_10:
    // 0x800D29BC: beql        $v0, $s2, L_800D29E8
    if (ctx->r2 == ctx->r18) {
        // 0x800D29C0: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800D29E8;
    }
    goto skip_11;
    // 0x800D29C0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    skip_11:
    // 0x800D29C4: b           L_800D29EC
    // 0x800D29C8: nop

        goto L_800D29EC;
    // 0x800D29C8: nop

    // 0x800D29CC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800D29D0:
    // 0x800D29D0: b           L_800D29EC
    // 0x800D29D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_800D29EC;
    // 0x800D29D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D29D8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800D29DC:
    // 0x800D29DC: b           L_800D29EC
    // 0x800D29E0: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
        goto L_800D29EC;
    // 0x800D29E0: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x800D29E4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800D29E8:
    // 0x800D29E8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800D29EC:
    // 0x800D29EC: bne         $a0, $s2, L_800D299C
    if (ctx->r4 != ctx->r18) {
        // 0x800D29F0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800D299C;
    }
    // 0x800D29F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D29F4: beq         $t0, $zero, L_800D2A5C
    if (ctx->r8 == 0) {
        // 0x800D29F8: nop
    
            goto L_800D2A5C;
    }
    // 0x800D29F8: nop

    // 0x800D29FC: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D2A00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2A04: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x800D2A08: nop

    // 0x800D2A0C: bc1fl       L_800D2A40
    if (!c1cs) {
        // 0x800D2A10: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2A40;
    }
    goto skip_12;
    // 0x800D2A10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_12:
    // 0x800D2A14: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800D2A18: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x800D2A1C: nop

    // 0x800D2A20: bc1fl       L_800D2A40
    if (!c1cs) {
        // 0x800D2A24: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2A40;
    }
    goto skip_13;
    // 0x800D2A24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_13:
    // 0x800D2A28: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800D2A2C: c.eq.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl == ctx->f6.fl;
    // 0x800D2A30: nop

    // 0x800D2A34: bc1t        L_800D2A5C
    if (c1cs) {
        // 0x800D2A38: nop
    
            goto L_800D2A5C;
    }
    // 0x800D2A38: nop

    // 0x800D2A3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D2A40:
    // 0x800D2A40: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800D2A44: jal         0x8001B6EC
    // 0x800D2A48: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    syMatrixScaF(rdram, ctx);
        goto after_7;
    // 0x800D2A48: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    after_7:
    // 0x800D2A4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2A50: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2A54: jal         0x80034980
    // 0x800D2A58: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_8;
    // 0x800D2A58: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_8:
L_800D2A5C:
    // 0x800D2A5C: beq         $s0, $zero, L_800D2AC4
    if (ctx->r16 == 0) {
        // 0x800D2A60: nop
    
            goto L_800D2AC4;
    }
    // 0x800D2A60: nop

    // 0x800D2A64: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D2A68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2A6C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800D2A70: nop

    // 0x800D2A74: bc1fl       L_800D2AA8
    if (!c1cs) {
        // 0x800D2A78: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2AA8;
    }
    goto skip_14;
    // 0x800D2A78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_14:
    // 0x800D2A7C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D2A80: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x800D2A84: nop

    // 0x800D2A88: bc1fl       L_800D2AA8
    if (!c1cs) {
        // 0x800D2A8C: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2AA8;
    }
    goto skip_15;
    // 0x800D2A8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_15:
    // 0x800D2A90: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800D2A94: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x800D2A98: nop

    // 0x800D2A9C: bc1t        L_800D2AC4
    if (c1cs) {
        // 0x800D2AA0: nop
    
            goto L_800D2AC4;
    }
    // 0x800D2AA0: nop

    // 0x800D2AA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D2AA8:
    // 0x800D2AA8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800D2AAC: jal         0x8001BDEC
    // 0x800D2AB0: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    syMatrixRotRpyRF(rdram, ctx);
        goto after_9;
    // 0x800D2AB0: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    after_9:
    // 0x800D2AB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2AB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2ABC: jal         0x80034980
    // 0x800D2AC0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_10;
    // 0x800D2AC0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_10:
L_800D2AC4:
    // 0x800D2AC4: beql        $s1, $zero, L_800D2B30
    if (ctx->r17 == 0) {
        // 0x800D2AC8: lw          $s3, 0x14($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X14);
            goto L_800D2B30;
    }
    goto skip_16;
    // 0x800D2AC8: lw          $s3, 0x14($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X14);
    skip_16:
    // 0x800D2ACC: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D2AD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D2AD4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800D2AD8: nop

    // 0x800D2ADC: bc1fl       L_800D2B10
    if (!c1cs) {
        // 0x800D2AE0: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2B10;
    }
    goto skip_17;
    // 0x800D2AE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_17:
    // 0x800D2AE4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800D2AE8: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x800D2AEC: nop

    // 0x800D2AF0: bc1fl       L_800D2B10
    if (!c1cs) {
        // 0x800D2AF4: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_800D2B10;
    }
    goto skip_18;
    // 0x800D2AF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_18:
    // 0x800D2AF8: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800D2AFC: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x800D2B00: nop

    // 0x800D2B04: bc1tl       L_800D2B30
    if (c1cs) {
        // 0x800D2B08: lw          $s3, 0x14($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X14);
            goto L_800D2B30;
    }
    goto skip_19;
    // 0x800D2B08: lw          $s3, 0x14($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X14);
    skip_19:
    // 0x800D2B0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_800D2B10:
    // 0x800D2B10: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x800D2B14: jal         0x8001B924
    // 0x800D2B18: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    syMatrixTraF(rdram, ctx);
        goto after_11;
    // 0x800D2B18: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    after_11:
    // 0x800D2B1C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2B20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D2B24: jal         0x80034980
    // 0x800D2B28: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_12;
    // 0x800D2B28: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_12:
L_800D2B2C:
    // 0x800D2B2C: lw          $s3, 0x14($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X14);
L_800D2B30:
    // 0x800D2B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2B34: bnel        $s3, $at, L_800D2860
    if (ctx->r19 != ctx->r1) {
        // 0x800D2B38: lwc1        $f0, 0x40($s3)
        ctx->f0.u32l = MEM_W(ctx->r19, 0X40);
            goto L_800D2860;
    }
    goto skip_20;
    // 0x800D2B38: lwc1        $f0, 0x40($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X40);
    skip_20:
    // 0x800D2B3C: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800D2B40: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800D2B44: lw          $v0, 0xFC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XFC);
    // 0x800D2B48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D2B4C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800D2B50: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800D2B54: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800D2B58: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    // 0x800D2B5C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800D2B60: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800D2B64: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800D2B68: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800D2B6C: lwc1        $f22, 0x4($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800D2B70: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800D2B74: jal         0x80035380
    // 0x800D2B78: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    guNormalize(rdram, ctx);
        goto after_13;
    // 0x800D2B78: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x800D2B7C: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x800D2B80: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x800D2B84: jal         0x80035380
    // 0x800D2B88: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    guNormalize(rdram, ctx);
        goto after_14;
    // 0x800D2B88: addiu       $a2, $sp, 0xDC
    ctx->r6 = ADD32(ctx->r29, 0XDC);
    after_14:
    // 0x800D2B8C: addiu       $a0, $sp, 0xC0
    ctx->r4 = ADD32(ctx->r29, 0XC0);
    // 0x800D2B90: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x800D2B94: jal         0x80035380
    // 0x800D2B98: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    guNormalize(rdram, ctx);
        goto after_15;
    // 0x800D2B98: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    after_15:
    // 0x800D2B9C: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800D2BA0: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800D2BA4: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D2BA8: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800D2BAC: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800D2BB0: lw          $v0, 0xFC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XFC);
    // 0x800D2BB4: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800D2BB8: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800D2BBC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D2BC0: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800D2BC4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800D2BC8: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D2BCC: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D2BD0: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D2BD4: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800D2BD8: nop

    // 0x800D2BDC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800D2BE0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800D2BE4: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D2BE8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800D2BEC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800D2BF0: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D2BF4: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800D2BF8: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800D2BFC: mul.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D2C00: nop

    // 0x800D2C04: mul.s       $f18, $f4, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800D2C08: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D2C0C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D2C10: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D2C14: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800D2C18: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D2C1C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800D2C20: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800D2C24: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800D2C28: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800D2C2C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800D2C30: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800D2C34: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800D2C38: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800D2C3C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800D2C40: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800D2C44: jr          $ra
    // 0x800D2C48: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x800D2C48: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void mnVSRecordGetWinPercent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131D40: jal         0x80131B74
    // 0x80131D44: nop

    mnVSRecordGetKOs(rdram, ctx);
        goto after_0;
    // 0x80131D44: nop

    after_0:
    // 0x80131D48: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80131D4C: nop

    // 0x80131D50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131D54: jal         0x80131CD4
    // 0x80131D58: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    mnVSRecordGetTotalTKO(rdram, ctx);
        goto after_1;
    // 0x80131D58: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80131D5C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80131D60: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80131D64: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80131D68: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131D6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131D74: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80131D78: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80131D7C: nop

    // 0x80131D80: bc1tl       L_80131D94
    if (c1cs) {
        // 0x80131D84: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80131D94;
    }
    goto skip_0;
    // 0x80131D84: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_0:
    // 0x80131D88: b           L_80131D94
    // 0x80131D8C: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
        goto L_80131D94;
    // 0x80131D8C: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80131D90: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80131D94:
    // 0x80131D94: mul.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80131D98: jr          $ra
    // 0x80131D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80131D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PBonusMakePortraitWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132CB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132CB8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132CBC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132CC0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132CC4: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132CC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132CCC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132CD0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132CD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132CDC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132CE0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132CE4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132CE8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132CEC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132CF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132CF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132CF8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132CFC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132D00: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132D04: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D0C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132D10: jal         0x8000B93C
    // 0x80132D14: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132D14: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132D1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132D20: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132D24: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132D28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132D30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132D34: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132D38: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132D3C: jal         0x80007080
    // 0x80132D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132D40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132D44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132D48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132D4C: jr          $ra
    // 0x80132D50: nop

    return;
    // 0x80132D50: nop

;}
RECOMP_FUNC void grSectorArwingUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106AC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80106AC8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80106ACC: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80106AD0: lhu         $v0, 0x44($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X44);
    // 0x80106AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106AD8: beq         $v0, $zero, L_80106AE8
    if (ctx->r2 == 0) {
        // 0x80106ADC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80106AE8;
    }
    // 0x80106ADC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80106AE0: b           L_80106C14
    // 0x80106AE4: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
        goto L_80106C14;
    // 0x80106AE4: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
L_80106AE8:
    // 0x80106AE8: lbu         $t7, 0x4A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4A);
    // 0x80106AEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80106AF0: beq         $t7, $zero, L_80106B5C
    if (ctx->r15 == 0) {
        // 0x80106AF4: swc1        $f4, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
            goto L_80106B5C;
    }
    // 0x80106AF4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80106AF8: jal         0x80018994
    // 0x80106AFC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80106AFC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80106B00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80106B04: bne         $v0, $at, L_80106B34
    if (ctx->r2 != ctx->r1) {
        // 0x80106B08: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80106B34;
    }
    // 0x80106B08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80106B0C: jal         0x80018994
    // 0x80106B10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80106B10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80106B14: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80106B18: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80106B1C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80106B20: lh          $t9, -0x1688($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X1688);
    // 0x80106B24: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80106B28: nop

    // 0x80106B2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80106B30: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_80106B34:
    // 0x80106B34: lbu         $t0, 0x4A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4A);
    // 0x80106B38: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    // 0x80106B3C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80106B40: jal         0x80018994
    // 0x80106B44: sb          $t1, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r9;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80106B44: sb          $t1, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r9;
    after_2:
    // 0x80106B48: addiu       $t2, $v0, 0xB4
    ctx->r10 = ADD32(ctx->r2, 0XB4);
    // 0x80106B4C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80106B50: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80106B54: b           L_80106BA0
    // 0x80106B58: sb          $t3, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r11;
        goto L_80106BA0;
    // 0x80106B58: sb          $t3, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r11;
L_80106B5C:
    // 0x80106B5C: jal         0x80018994
    // 0x80106B60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80106B60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80106B64: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x80106B68: jal         0x80018910
    // 0x80106B6C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    syUtilsRandUShort(rdram, ctx);
        goto after_4;
    // 0x80106B6C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_4:
    // 0x80106B70: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80106B74: beq         $t5, $zero, L_80106B8C
    if (ctx->r13 == 0) {
        // 0x80106B78: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80106B8C;
    }
    // 0x80106B78: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80106B7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80106B80: addiu       $t7, $t6, -0x5
    ctx->r15 = ADD32(ctx->r14, -0X5);
    // 0x80106B84: b           L_80106B94
    // 0x80106B88: sb          $t7, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r15;
        goto L_80106B94;
    // 0x80106B88: sb          $t7, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r15;
L_80106B8C:
    // 0x80106B8C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80106B90: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
L_80106B94:
    // 0x80106B94: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80106B98: sb          $t9, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r25;
    // 0x80106B9C: sb          $t0, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r8;
L_80106BA0:
    // 0x80106BA0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80106BA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80106BA8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80106BAC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80106BB0: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x80106BB4: sb          $t2, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r10;
    // 0x80106BB8: sh          $t3, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r11;
    // 0x80106BBC: sb          $t1, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r9;
    // 0x80106BC0: swc1        $f10, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f10.u32l;
    // 0x80106BC4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80106BC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80106BCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80106BD0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80106BD4: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    // 0x80106BD8: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80106BDC: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80106BE0: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    // 0x80106BE4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80106BE8: swc1        $f16, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f16.u32l;
    // 0x80106BEC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80106BF0: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80106BF4: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80106BF8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80106BFC: swc1        $f0, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f0.u32l;
    // 0x80106C00: sb          $zero, 0x59($s0)
    MEM_B(0X59, ctx->r16) = 0;
    // 0x80106C04: sb          $t8, 0x58($s0)
    MEM_B(0X58, ctx->r16) = ctx->r24;
    // 0x80106C08: sb          $zero, 0x57($s0)
    MEM_B(0X57, ctx->r16) = 0;
    // 0x80106C0C: jal         0x800269C0
    // 0x80106C10: sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80106C10: sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
    after_5:
L_80106C14:
    // 0x80106C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80106C18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80106C1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80106C20: jr          $ra
    // 0x80106C24: nop

    return;
    // 0x80106C24: nop

;}
RECOMP_FUNC void ftBossDrillProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A0E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A0EC: jal         0x800D9414
    // 0x8015A0F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x8015A0F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015A0F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8015A0F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8015A0FC: addiu       $t0, $t0, -0x5EC8
    ctx->r8 = ADD32(ctx->r8, -0X5EC8);
    // 0x8015A100: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015A104: addiu       $t1, $zero, 0x27
    ctx->r9 = ADD32(0, 0X27);
    // 0x8015A108: lh          $t7, 0xB18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A10C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8015A110: sh          $t8, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r24;
    // 0x8015A114: lh          $t9, 0xB18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A118: bnel        $t9, $zero, L_8015A12C
    if (ctx->r25 != 0) {
        // 0x8015A11C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015A12C;
    }
    goto skip_0;
    // 0x8015A11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015A120: sw          $t0, 0x9E0($v0)
    MEM_W(0X9E0, ctx->r2) = ctx->r8;
    // 0x8015A124: sh          $t1, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r9;
    // 0x8015A128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A12C:
    // 0x8015A12C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A130: jr          $ra
    // 0x8015A134: nop

    return;
    // 0x8015A134: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeSpeedOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F354: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F35C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018F360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F364: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018F368: jal         0x80009968
    // 0x8018F36C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018F36C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018F370: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F374: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018F378: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018F37C: sw          $v0, 0xBB8($at)
    MEM_W(0XBB8, ctx->r1) = ctx->r2;
    // 0x8018F380: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018F384: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F388: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018F38C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F390: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018F394: jal         0x80009DF4
    // 0x8018F398: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018F398: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018F39C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F3A0: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F3A4: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x8018F3A8: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8018F3AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F3B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F3B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F3B8: jal         0x800CCFDC
    // 0x8018F3BC: lw          $a1, 0x44($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X44);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018F3BC: lw          $a1, 0x44($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X44);
    after_2:
    // 0x8018F3C0: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8018F3C4: addiu       $t3, $zero, 0xBF
    ctx->r11 = ADD32(0, 0XBF);
    // 0x8018F3C8: addiu       $t5, $zero, 0x4A
    ctx->r13 = ADD32(0, 0X4A);
    // 0x8018F3CC: bgez        $t1, L_8018F3DC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018F3D0: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8018F3DC;
    }
    // 0x8018F3D0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8018F3D4: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8018F3D8: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8018F3DC:
    // 0x8018F3DC: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8018F3E0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F3E4: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x8018F3E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F3EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F3F0: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8018F3F4: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x8018F3F8: sb          $t5, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r13;
    // 0x8018F3FC: sb          $t6, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r14;
    // 0x8018F400: sb          $t8, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r24;
    // 0x8018F404: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F408: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8018F40C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F410: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F414: jr          $ra
    // 0x8018F418: nop

    return;
    // 0x8018F418: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015580C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155810: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155814: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80155818: beql        $t6, $zero, L_8015582C
    if (ctx->r14 == 0) {
        // 0x8015581C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015582C;
    }
    goto skip_0;
    // 0x8015581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80155820: jal         0x80155794
    // 0x80155824: nop

    ftNessSpecialAirLwHoldSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155824: nop

    after_0:
    // 0x80155828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015582C:
    // 0x8015582C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155830: jr          $ra
    // 0x80155834: nop

    return;
    // 0x80155834: nop

;}
RECOMP_FUNC void ifCommonBattleInterfaceProcSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801142B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801142B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801142BC: jal         0x80113F74
    // 0x801142C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_0;
    // 0x801142C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801142C4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x801142C8: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x801142CC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x801142D0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801142D4: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x801142D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801142DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801142E0: sh          $t8, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r24;
    // 0x801142E4: jr          $ra
    // 0x801142E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801142E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftKirbySpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161E08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80161E0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161E10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80161E14: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80161E18: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80161E1C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80161E20: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80161E24: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80161E28: sh          $t6, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r14;
    // 0x80161E2C: sh          $t7, 0xB1A($v0)
    MEM_H(0XB1A, ctx->r2) = ctx->r15;
    // 0x80161E30: swc1        $f0, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f0.u32l;
    // 0x80161E34: jr          $ra
    // 0x80161E38: swc1        $f0, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x80161E38: swc1        $f0, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void ftPikachuSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152B54: jal         0x80152AA0
    // 0x80152B58: nop

    ftPikachuSpecialHiUpdateModelPitchScale(rdram, ctx);
        goto after_0;
    // 0x80152B58: nop

    after_0:
    // 0x80152B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152B64: jr          $ra
    // 0x80152B68: nop

    return;
    // 0x80152B68: nop

;}
RECOMP_FUNC void dbBattleStartBattle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131B5C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80131B60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131B64: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x80131B68: sw          $a2, 0x2690($at)
    MEM_W(0X2690, ctx->r1) = ctx->r6;
    // 0x80131B6C: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80131B70: sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // 0x80131B74: sb          $zero, 0x5($a3)
    MEM_B(0X5, ctx->r7) = 0;
    // 0x80131B78: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80131B7C: lbu         $a0, 0x4D2A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4D2A);
    // 0x80131B80: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80131B84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131B88: beql        $a0, $zero, L_80131BA4
    if (ctx->r4 == 0) {
        // 0x80131B8C: lbu         $t6, 0x4($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X4);
            goto L_80131BA4;
    }
    goto skip_0;
    // 0x80131B8C: lbu         $t6, 0x4($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4);
    skip_0:
    // 0x80131B90: beq         $a0, $a2, L_80131BB0
    if (ctx->r4 == ctx->r6) {
        // 0x80131B94: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80131BB0;
    }
    // 0x80131B94: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80131B98: b           L_80131BB4
    // 0x80131B9C: nop

        goto L_80131BB4;
    // 0x80131B9C: nop

    // 0x80131BA0: lbu         $t6, 0x4($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4);
L_80131BA4:
    // 0x80131BA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80131BA8: b           L_80131BB4
    // 0x80131BAC: sb          $t7, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r15;
        goto L_80131BB4;
    // 0x80131BAC: sb          $t7, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r15;
L_80131BB0:
    // 0x80131BB0: sb          $t8, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r24;
L_80131BB4:
    // 0x80131BB4: sb          $zero, 0x4D2C($at)
    MEM_B(0X4D2C, ctx->r1) = 0;
    // 0x80131BB8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131BBC: sb          $zero, 0x4D30($at)
    MEM_B(0X4D30, ctx->r1) = 0;
    // 0x80131BC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131BC4: sb          $zero, 0x4D32($at)
    MEM_B(0X4D32, ctx->r1) = 0;
    // 0x80131BC8: lbu         $v1, 0x4D9E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4D9E);
    // 0x80131BCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131BD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80131BD4: beq         $v1, $zero, L_80131BEC
    if (ctx->r3 == 0) {
        // 0x80131BD8: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80131BEC;
    }
    // 0x80131BD8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80131BDC: beql        $v1, $a2, L_80131C00
    if (ctx->r3 == ctx->r6) {
        // 0x80131BE0: lbu         $t1, 0x5($a3)
        ctx->r9 = MEM_BU(ctx->r7, 0X5);
            goto L_80131C00;
    }
    goto skip_1;
    // 0x80131BE0: lbu         $t1, 0x5($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X5);
    skip_1:
    // 0x80131BE4: b           L_80131C08
    // 0x80131BE8: nop

        goto L_80131C08;
    // 0x80131BE8: nop

L_80131BEC:
    // 0x80131BEC: lbu         $t9, 0x4($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4);
    // 0x80131BF0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80131BF4: b           L_80131C08
    // 0x80131BF8: sb          $t0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r8;
        goto L_80131C08;
    // 0x80131BF8: sb          $t0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r8;
    // 0x80131BFC: lbu         $t1, 0x5($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X5);
L_80131C00:
    // 0x80131C00: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80131C04: sb          $t2, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r10;
L_80131C08:
    // 0x80131C08: sb          $a2, 0x4DA0($at)
    MEM_B(0X4DA0, ctx->r1) = ctx->r6;
    // 0x80131C0C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C10: sb          $a2, 0x4DA4($at)
    MEM_B(0X4DA4, ctx->r1) = ctx->r6;
    // 0x80131C14: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C18: sb          $a2, 0x4DA6($at)
    MEM_B(0X4DA6, ctx->r1) = ctx->r6;
    // 0x80131C1C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80131C20: lbu         $v1, 0x4E12($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4E12);
    // 0x80131C24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C28: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80131C2C: beql        $v1, $zero, L_80131C48
    if (ctx->r3 == 0) {
        // 0x80131C30: lbu         $t3, 0x4($a3)
        ctx->r11 = MEM_BU(ctx->r7, 0X4);
            goto L_80131C48;
    }
    goto skip_2;
    // 0x80131C30: lbu         $t3, 0x4($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X4);
    skip_2:
    // 0x80131C34: beql        $v1, $a2, L_80131C58
    if (ctx->r3 == ctx->r6) {
        // 0x80131C38: lbu         $t5, 0x5($a3)
        ctx->r13 = MEM_BU(ctx->r7, 0X5);
            goto L_80131C58;
    }
    goto skip_3;
    // 0x80131C38: lbu         $t5, 0x5($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X5);
    skip_3:
    // 0x80131C3C: b           L_80131C60
    // 0x80131C40: nop

        goto L_80131C60;
    // 0x80131C40: nop

    // 0x80131C44: lbu         $t3, 0x4($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X4);
L_80131C48:
    // 0x80131C48: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80131C4C: b           L_80131C60
    // 0x80131C50: sb          $t4, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r12;
        goto L_80131C60;
    // 0x80131C50: sb          $t4, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r12;
    // 0x80131C54: lbu         $t5, 0x5($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X5);
L_80131C58:
    // 0x80131C58: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80131C5C: sb          $t6, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r14;
L_80131C60:
    // 0x80131C60: sb          $t7, 0x4E14($at)
    MEM_B(0X4E14, ctx->r1) = ctx->r15;
    // 0x80131C64: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C68: sb          $t8, 0x4E18($at)
    MEM_B(0X4E18, ctx->r1) = ctx->r24;
    // 0x80131C6C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C70: sb          $t9, 0x4E1A($at)
    MEM_B(0X4E1A, ctx->r1) = ctx->r25;
    // 0x80131C74: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80131C78: lbu         $v1, 0x4E86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4E86);
    // 0x80131C7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131C80: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80131C84: beq         $v1, $zero, L_80131C9C
    if (ctx->r3 == 0) {
        // 0x80131C88: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80131C9C;
    }
    // 0x80131C88: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80131C8C: beql        $v1, $a2, L_80131CB0
    if (ctx->r3 == ctx->r6) {
        // 0x80131C90: lbu         $t2, 0x5($a3)
        ctx->r10 = MEM_BU(ctx->r7, 0X5);
            goto L_80131CB0;
    }
    goto skip_4;
    // 0x80131C90: lbu         $t2, 0x5($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X5);
    skip_4:
    // 0x80131C94: b           L_80131CB8
    // 0x80131C98: nop

        goto L_80131CB8;
    // 0x80131C98: nop

L_80131C9C:
    // 0x80131C9C: lbu         $t0, 0x4($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X4);
    // 0x80131CA0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80131CA4: b           L_80131CB8
    // 0x80131CA8: sb          $t1, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r9;
        goto L_80131CB8;
    // 0x80131CA8: sb          $t1, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r9;
    // 0x80131CAC: lbu         $t2, 0x5($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X5);
L_80131CB0:
    // 0x80131CB0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80131CB4: sb          $t3, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r11;
L_80131CB8:
    // 0x80131CB8: sb          $t4, 0x4E88($at)
    MEM_B(0X4E88, ctx->r1) = ctx->r12;
    // 0x80131CBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131CC0: sb          $t5, 0x4E8C($at)
    MEM_B(0X4E8C, ctx->r1) = ctx->r13;
    // 0x80131CC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80131CC8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80131CCC: sb          $t6, 0x4E8E($at)
    MEM_B(0X4E8E, ctx->r1) = ctx->r14;
    // 0x80131CD0: jr          $ra
    // 0x80131CD4: sb          $zero, 0x2($a3)
    MEM_B(0X2, ctx->r7) = 0;
    return;
    // 0x80131CD4: sb          $zero, 0x2($a3)
    MEM_B(0X2, ctx->r7) = 0;
;}
RECOMP_FUNC void mnPlayers1PGameCheckLevelArrowPress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013684C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136854: jal         0x801366C4
    // 0x80136858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PGameCheckLevelArrowRInRange(rdram, ctx);
        goto after_0;
    // 0x80136858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013685C: beq         $v0, $zero, L_801368A0
    if (ctx->r2 == 0) {
        // 0x80136860: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_801368A0;
    }
    // 0x80136860: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136864: addiu       $v1, $v1, -0x704C
    ctx->r3 = ADD32(ctx->r3, -0X704C);
    // 0x80136868: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013686C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80136870: beq         $at, $zero, L_80136898
    if (ctx->r1 == 0) {
        // 0x80136874: nop
    
            goto L_80136898;
    }
    // 0x80136874: nop

    // 0x80136878: jal         0x800269C0
    // 0x8013687C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8013687C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_1:
    // 0x80136880: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136884: addiu       $v1, $v1, -0x704C
    ctx->r3 = ADD32(ctx->r3, -0X704C);
    // 0x80136888: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8013688C: addiu       $a0, $t7, 0x1
    ctx->r4 = ADD32(ctx->r15, 0X1);
    // 0x80136890: jal         0x80133D9C
    // 0x80136894: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mnPlayers1PGameMakeLevel(rdram, ctx);
        goto after_2;
    // 0x80136894: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_2:
L_80136898:
    // 0x80136898: b           L_801368EC
    // 0x8013689C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801368EC;
    // 0x8013689C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801368A0:
    // 0x801368A0: jal         0x80136788
    // 0x801368A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameCheckLevelArrowLInRange(rdram, ctx);
        goto after_3;
    // 0x801368A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801368A8: beq         $v0, $zero, L_801368E8
    if (ctx->r2 == 0) {
        // 0x801368AC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_801368E8;
    }
    // 0x801368AC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801368B0: addiu       $v1, $v1, -0x704C
    ctx->r3 = ADD32(ctx->r3, -0X704C);
    // 0x801368B4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801368B8: blez        $t9, L_801368E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x801368BC: nop
    
            goto L_801368E0;
    }
    // 0x801368BC: nop

    // 0x801368C0: jal         0x800269C0
    // 0x801368C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x801368C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_4:
    // 0x801368C8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801368CC: addiu       $v1, $v1, -0x704C
    ctx->r3 = ADD32(ctx->r3, -0X704C);
    // 0x801368D0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801368D4: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // 0x801368D8: jal         0x80133D9C
    // 0x801368DC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mnPlayers1PGameMakeLevel(rdram, ctx);
        goto after_5;
    // 0x801368DC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_5:
L_801368E0:
    // 0x801368E0: b           L_801368EC
    // 0x801368E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801368EC;
    // 0x801368E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801368E8:
    // 0x801368E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801368EC:
    // 0x801368EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801368F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801368F4: jr          $ra
    // 0x801368F8: nop

    return;
    // 0x801368F8: nop

;}
RECOMP_FUNC void func_ovl8_8037345C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037345C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80373464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80373468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037346C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373470: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80373474: bne         $a0, $zero, L_8037348C
    if (ctx->r4 != 0) {
        // 0x80373478: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8037348C;
    }
    // 0x80373478: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8037347C: jal         0x803717A0
    // 0x80373480: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80373480: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_0:
    // 0x80373484: beq         $v0, $zero, L_80373538
    if (ctx->r2 == 0) {
        // 0x80373488: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373538;
    }
    // 0x80373488: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037348C:
    // 0x8037348C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80373490: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80373494: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x80373498: bnel        $t6, $zero, L_803734BC
    if (ctx->r14 != 0) {
        // 0x8037349C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_803734BC;
    }
    goto skip_0;
    // 0x8037349C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x803734A0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x803734A4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803734A8: jal         0x803717E0
    // 0x803734AC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803734AC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x803734B0: jal         0x8037C2D0
    // 0x803734B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803734B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x803734B8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_803734BC:
    // 0x803734BC: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803734C0: addiu       $t9, $t9, -0x6F60
    ctx->r25 = ADD32(ctx->r25, -0X6F60);
    // 0x803734C4: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
    // 0x803734C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x803734CC: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x803734D0: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803734D4: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x803734D8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x803734DC: addiu       $t0, $t0, -0x6E90
    ctx->r8 = ADD32(ctx->r8, -0X6E90);
    // 0x803734E0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803734E4: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x803734E8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x803734EC: addiu       $t2, $t2, -0x6D38
    ctx->r10 = ADD32(ctx->r10, -0X6D38);
    // 0x803734F0: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x803734F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803734F8: jal         0x80371ECC
    // 0x803734FC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_ovl8_80371ECC(rdram, ctx);
        goto after_3;
    // 0x803734FC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80373500: jal         0x803735E4
    // 0x80373504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803735E4(rdram, ctx);
        goto after_4;
    // 0x80373504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80373508: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8037350C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80373510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80373514: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x80373518: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8037351C: lh          $t5, 0x1C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1C);
    // 0x80373520: sh          $t5, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r13;
    // 0x80373524: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80373528: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x8037352C: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x80373530: jalr        $t9
    // 0x80373534: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80373534: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_5:
L_80373538:
    // 0x80373538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037353C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80373540: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373544: jr          $ra
    // 0x80373548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80373548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftParamSetHealDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA3D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA3D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA3DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EA3E0: lw          $t6, 0x818($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X818);
    // 0x800EA3E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EA3E8: addu        $t8, $t6, $a1
    ctx->r24 = ADD32(ctx->r14, ctx->r5);
    // 0x800EA3EC: sw          $t8, 0x818($a0)
    MEM_W(0X818, ctx->r4) = ctx->r24;
    // 0x800EA3F0: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x800EA3F4: jal         0x800E9814
    // 0x800EA3F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800EA3F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x800EA3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA404: jr          $ra
    // 0x800EA408: nop

    return;
    // 0x800EA408: nop

;}
RECOMP_FUNC void gcAddDObj3TransformsKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F300: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000F304: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000F308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F30C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F310: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000F314: beq         $a1, $zero, L_8000F324
    if (ctx->r5 == 0) {
        // 0x8000F318: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8000F324;
    }
    // 0x8000F318: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000F31C: jal         0x80008CC0
    // 0x8000F320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8000F320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8000F324:
    // 0x8000F324: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8000F328: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000F32C: beq         $t6, $zero, L_8000F33C
    if (ctx->r14 == 0) {
        // 0x8000F330: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8000F33C;
    }
    // 0x8000F330: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000F334: jal         0x80008CC0
    // 0x8000F338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8000F338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8000F33C:
    // 0x8000F33C: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x8000F340: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000F344: beq         $t7, $zero, L_8000F354
    if (ctx->r15 == 0) {
        // 0x8000F348: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_8000F354;
    }
    // 0x8000F348: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000F34C: jal         0x80008CC0
    // 0x8000F350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8000F350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8000F354:
    // 0x8000F354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F35C: jr          $ra
    // 0x8000F360: nop

    return;
    // 0x8000F360: nop

;}
RECOMP_FUNC void ftCommonDamageFallSetStatusFromCliffWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801436A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801436A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801436A8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801436AC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801436B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801436B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801436B8: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x801436BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801436C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801436C4: jal         0x800E6F24
    // 0x801436C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801436C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801436CC: jal         0x80143630
    // 0x801436D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonDamageFallClampRumble(rdram, ctx);
        goto after_1;
    // 0x801436D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801436D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801436D8: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x801436DC: sw          $t8, 0x160($t9)
    MEM_W(0X160, ctx->r25) = ctx->r24;
    // 0x801436E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801436E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801436E8: jr          $ra
    // 0x801436EC: nop

    return;
    // 0x801436EC: nop

;}
RECOMP_FUNC void func_ovl8_80373218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037321C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373220: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80373224: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80373228: jal         0x80373168
    // 0x8037322C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_ovl8_80373168(rdram, ctx);
        goto after_0;
    // 0x8037322C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80373230: bne         $v0, $zero, L_80373240
    if (ctx->r2 != 0) {
        // 0x80373234: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373240;
    }
    // 0x80373234: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80373238: b           L_8037329C
    // 0x8037323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037329C;
    // 0x8037323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80373240:
    // 0x80373240: beq         $v0, $zero, L_80373298
    if (ctx->r2 == 0) {
        // 0x80373244: addiu       $s1, $sp, 0x24
        ctx->r17 = ADD32(ctx->r29, 0X24);
            goto L_80373298;
    }
    // 0x80373244: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x80373248: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_8037324C:
    // 0x8037324C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80373250: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373254: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x80373258: lh          $t6, 0x88($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X88);
    // 0x8037325C: jalr        $t9
    // 0x80373260: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80373260: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x80373264: beql        $v0, $zero, L_80373290
    if (ctx->r2 == 0) {
        // 0x80373268: lw          $s0, 0x24($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X24);
            goto L_80373290;
    }
    goto skip_0;
    // 0x80373268: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x8037326C: beq         $s0, $zero, L_80373278
    if (ctx->r16 == 0) {
        // 0x80373270: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80373278;
    }
    // 0x80373270: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80373274: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_80373278:
    // 0x80373278: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8037327C: beql        $t7, $zero, L_80373290
    if (ctx->r15 == 0) {
        // 0x80373280: lw          $s0, 0x24($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X24);
            goto L_80373290;
    }
    goto skip_1;
    // 0x80373280: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x80373284: b           L_8037329C
    // 0x80373288: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8037329C;
    // 0x80373288: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037328C: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
L_80373290:
    // 0x80373290: bnel        $s0, $zero, L_8037324C
    if (ctx->r16 != 0) {
        // 0x80373294: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_8037324C;
    }
    goto skip_2;
    // 0x80373294: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_2:
L_80373298:
    // 0x80373298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037329C:
    // 0x8037329C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803732A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803732A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803732A8: jr          $ra
    // 0x803732AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x803732AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbySpecialLwUpdateColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016136C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161370: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161374: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80161378: slti        $at, $v1, 0x16
    ctx->r1 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // 0x8016137C: beq         $at, $zero, L_801613E4
    if (ctx->r1 == 0) {
        // 0x80161380: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_801613E4;
    }
    // 0x80161380: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80161384: beql        $at, $zero, L_801613BC
    if (ctx->r1 == 0) {
        // 0x80161388: lh          $t8, 0xB1C($v0)
        ctx->r24 = MEM_H(ctx->r2, 0XB1C);
            goto L_801613BC;
    }
    goto skip_0;
    // 0x80161388: lh          $t8, 0xB1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB1C);
    skip_0:
    // 0x8016138C: lh          $t6, 0xB1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB1C);
    // 0x80161390: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80161394: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // 0x80161398: beq         $t6, $at, L_8016140C
    if (ctx->r14 == ctx->r1) {
        // 0x8016139C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8016140C;
    }
    // 0x8016139C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801613A0: jal         0x800E9814
    // 0x801613A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x801613A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801613A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801613AC: addiu       $t7, $zero, 0x35
    ctx->r15 = ADD32(0, 0X35);
    // 0x801613B0: b           L_8016140C
    // 0x801613B4: sh          $t7, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r15;
        goto L_8016140C;
    // 0x801613B4: sh          $t7, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r15;
    // 0x801613B8: lh          $t8, 0xB1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB1C);
L_801613BC:
    // 0x801613BC: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x801613C0: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x801613C4: beq         $t8, $at, L_8016140C
    if (ctx->r24 == ctx->r1) {
        // 0x801613C8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8016140C;
    }
    // 0x801613C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801613CC: jal         0x800E9814
    // 0x801613D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_1;
    // 0x801613D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801613D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801613D8: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x801613DC: b           L_8016140C
    // 0x801613E0: sh          $t9, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r25;
        goto L_8016140C;
    // 0x801613E0: sh          $t9, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r25;
L_801613E4:
    // 0x801613E4: lh          $t0, 0xB1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB1C);
    // 0x801613E8: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801613EC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x801613F0: beq         $t0, $at, L_8016140C
    if (ctx->r8 == ctx->r1) {
        // 0x801613F4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8016140C;
    }
    // 0x801613F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801613F8: jal         0x800E9814
    // 0x801613FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x801613FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80161400: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80161404: addiu       $t1, $zero, 0x33
    ctx->r9 = ADD32(0, 0X33);
    // 0x80161408: sh          $t1, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r9;
L_8016140C:
    // 0x8016140C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80161410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80161414: jr          $ra
    // 0x80161418: nop

    return;
    // 0x80161418: nop

;}
RECOMP_FUNC void itManagerSetupItemDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DFF4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8016DFF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8016DFFC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8016E000: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8016E004: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8016E008: andi        $s4, $a3, 0xFF
    ctx->r20 = ctx->r7 & 0XFF;
    // 0x8016E00C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8016E010: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8016E014: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8016E018: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8016E01C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8016E020: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8016E024: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8016E028: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8016E02C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8016E030: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8016E034: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x8016E038: addiu       $v1, $sp, 0x9C
    ctx->r3 = ADD32(ctx->r29, 0X9C);
L_8016E03C:
    // 0x8016E03C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8016E040: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8016E044: bne         $at, $zero, L_8016E03C
    if (ctx->r1 != 0) {
        // 0x8016E048: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8016E03C;
    }
    // 0x8016E048: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8016E04C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8016E050: addiu       $s6, $zero, 0x12
    ctx->r22 = ADD32(0, 0X12);
    // 0x8016E054: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8016E058: beq         $s6, $v0, L_8016E144
    if (ctx->r22 == ctx->r2) {
        // 0x8016E05C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8016E144;
    }
    // 0x8016E05C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8016E060: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x8016E064: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_8016E068:
    // 0x8016E068: beq         $v1, $zero, L_8016E08C
    if (ctx->r3 == 0) {
        // 0x8016E06C: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8016E08C;
    }
    // 0x8016E06C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8016E070: addu        $s1, $s7, $t6
    ctx->r17 = ADD32(ctx->r23, ctx->r14);
    // 0x8016E074: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    // 0x8016E078: jal         0x800093F4
    // 0x8016E07C: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8016E07C: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_0:
    // 0x8016E080: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8016E084: b           L_8016E0A0
    // 0x8016E088: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8016E0A0;
    // 0x8016E088: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8016E08C:
    // 0x8016E08C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8016E090: jal         0x800092D0
    // 0x8016E094: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x8016E094: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_1:
    // 0x8016E098: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8016E09C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8016E0A0:
    // 0x8016E0A0: bne         $s3, $fp, L_8016E0C4
    if (ctx->r19 != ctx->r30) {
        // 0x8016E0A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016E0C4;
    }
    // 0x8016E0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016E0A8: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x8016E0AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016E0B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016E0B4: jal         0x8000F364
    // 0x8016E0B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x8016E0B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8016E0BC: b           L_8016E0DC
    // 0x8016E0C0: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
        goto L_8016E0DC;
    // 0x8016E0C0: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
L_8016E0C4:
    // 0x8016E0C4: beq         $s4, $zero, L_8016E0D8
    if (ctx->r20 == 0) {
        // 0x8016E0C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016E0D8;
    }
    // 0x8016E0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016E0CC: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x8016E0D0: jal         0x80008CC0
    // 0x8016E0D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8016E0D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_8016E0D8:
    // 0x8016E0D8: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
L_8016E0DC:
    // 0x8016E0DC: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x8016E0E0: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x8016E0E4: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x8016E0E8: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x8016E0EC: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8016E0F0: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x8016E0F4: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x8016E0F8: lw          $t0, 0x14($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X14);
    // 0x8016E0FC: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x8016E100: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x8016E104: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x8016E108: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x8016E10C: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x8016E110: lw          $t2, 0x20($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X20);
    // 0x8016E114: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x8016E118: lw          $t1, 0x24($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X24);
    // 0x8016E11C: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x8016E120: lw          $t2, 0x28($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X28);
    // 0x8016E124: beq         $s5, $zero, L_8016E130
    if (ctx->r21 == 0) {
        // 0x8016E128: sw          $t2, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r10;
            goto L_8016E130;
    }
    // 0x8016E128: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x8016E12C: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
L_8016E130:
    // 0x8016E130: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    // 0x8016E134: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8016E138: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8016E13C: bnel        $s6, $v0, L_8016E068
    if (ctx->r22 != ctx->r2) {
        // 0x8016E140: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_8016E068;
    }
    goto skip_0;
    // 0x8016E140: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_0:
L_8016E144:
    // 0x8016E144: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8016E148: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8016E14C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8016E150: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8016E154: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8016E158: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8016E15C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8016E160: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8016E164: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8016E168: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8016E16C: jr          $ra
    // 0x8016E170: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8016E170: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void lbRelocGetFileSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDBD0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800CDBD4: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x800CDBD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDBDC: sw          $t6, 0x633C($at)
    MEM_W(0X633C, ctx->r1) = ctx->r14;
    // 0x800CDBE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDBE4: sw          $zero, 0x6340($at)
    MEM_W(0X6340, ctx->r1) = 0;
    // 0x800CDBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CDBEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDBF0: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800CDBF4: jal         0x800CDA38
    // 0x800CDBF8: sw          $t7, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = ctx->r15;
    lbRelocGetExternBytesNum(rdram, ctx);
        goto after_0;
    // 0x800CDBF8: sw          $t7, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = ctx->r15;
    after_0:
    // 0x800CDBFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CDC00: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x800CDC04: jr          $ra
    // 0x800CDC08: nop

    return;
    // 0x800CDC08: nop

;}
RECOMP_FUNC void sc1PGameFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F7B4: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8018F7B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018F7BC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018F7C0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018F7C4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018F7C8: jal         0x8018D60C
    // 0x8018F7CC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    sc1PGameSetupStageAll(rdram, ctx);
        goto after_0;
    // 0x8018F7CC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018F7D0: jal         0x8018D0C0
    // 0x8018F7D4: nop

    sc1PGameSetupFiles(rdram, ctx);
        goto after_1;
    // 0x8018F7D4: nop

    after_1:
    // 0x8018F7D8: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018F7DC: addiu       $s3, $s3, 0x44E0
    ctx->r19 = ADD32(ctx->r19, 0X44E0);
    // 0x8018F7E0: lbu         $t6, 0x5E2($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X5E2);
    // 0x8018F7E4: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8018F7E8: bnel        $t7, $zero, L_8018F890
    if (ctx->r15 != 0) {
        // 0x8018F7EC: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018F890;
    }
    goto skip_0;
    // 0x8018F7EC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_0:
    // 0x8018F7F0: lbu         $t8, 0x5E3($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X5E3);
    // 0x8018F7F4: addiu       $a0, $zero, 0xF10
    ctx->r4 = ADD32(0, 0XF10);
    // 0x8018F7F8: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x8018F7FC: slti        $at, $t8, 0x5D
    ctx->r1 = SIGNED(ctx->r24) < 0X5D ? 1 : 0;
    // 0x8018F800: bnel        $at, $zero, L_8018F890
    if (ctx->r1 != 0) {
        // 0x8018F804: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018F890;
    }
    goto skip_1;
    // 0x8018F804: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_1:
    // 0x8018F808: jal         0x80002CA0
    // 0x8018F80C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    syDmaReadRom(rdram, ctx);
        goto after_2;
    // 0x8018F80C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x8018F810: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018F814: addiu       $s0, $s0, 0xC8
    ctx->r16 = ADD32(ctx->r16, 0XC8);
    // 0x8018F818: jal         0x800CDBD0
    // 0x8018F81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_3;
    // 0x8018F81C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018F820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F824: jal         0x80004980
    // 0x8018F828: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x8018F828: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x8018F82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018F830: jal         0x800CDC88
    // 0x8018F834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_5;
    // 0x8018F834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8018F838: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8018F83C: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x8018F840: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8018F844: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x8018F848: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x8018F84C: addu        $t0, $v0, $s1
    ctx->r8 = ADD32(ctx->r2, ctx->r17);
    // 0x8018F850: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8018F854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018F858: jal         0x800321D0
    // 0x8018F85C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_6;
    // 0x8018F85C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_6:
    // 0x8018F860: addu        $t1, $s2, $s1
    ctx->r9 = ADD32(ctx->r18, ctx->r17);
    // 0x8018F864: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8018F868: jal         0x800344B0
    // 0x8018F86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osInvalICache_recomp(rdram, ctx);
        goto after_7;
    // 0x8018F86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8018F870: jalr        $s0
    // 0x8018F874: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    LOOKUP_FUNC(ctx->r16)(rdram, ctx);
        goto after_8;
    // 0x8018F874: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    after_8:
    // 0x8018F878: bnel        $v0, $zero, L_8018F890
    if (ctx->r2 != 0) {
        // 0x8018F87C: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_8018F890;
    }
    goto skip_2;
    // 0x8018F87C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    skip_2:
    // 0x8018F880: lbu         $t2, 0x5E2($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X5E2);
    // 0x8018F884: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x8018F888: sb          $t3, 0x5E2($s3)
    MEM_B(0X5E2, ctx->r19) = ctx->r11;
    // 0x8018F88C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8018F890:
    // 0x8018F890: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018F894: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018F898: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018F89C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018F8A0: jal         0x8000B9FC
    // 0x8018F8A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_9;
    // 0x8018F8A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x8018F8A8: jal         0x80115890
    // 0x8018F8AC: nop

    efParticleInitAll(rdram, ctx);
        goto after_10;
    // 0x8018F8AC: nop

    after_10:
    // 0x8018F8B0: jal         0x800EC130
    // 0x8018F8B4: nop

    ftParamInitGame(rdram, ctx);
        goto after_11;
    // 0x8018F8B4: nop

    after_11:
    // 0x8018F8B8: jal         0x800FC284
    // 0x8018F8BC: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_12;
    // 0x8018F8BC: nop

    after_12:
    // 0x8018F8C0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018F8C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018F8C8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018F8CC: jal         0x8010E598
    // 0x8018F8D0: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_13;
    // 0x8018F8D0: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_13:
    // 0x8018F8D4: jal         0x8010DB54
    // 0x8018F8D8: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_14;
    // 0x8018F8D8: nop

    after_14:
    // 0x8018F8DC: jal         0x80104BDC
    // 0x8018F8E0: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_15;
    // 0x8018F8E0: nop

    after_15:
    // 0x8018F8E4: jal         0x8010DB00
    // 0x8018F8E8: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_16;
    // 0x8018F8E8: nop

    after_16:
    // 0x8018F8EC: jal         0x8016DEA0
    // 0x8018F8F0: nop

    itManagerInitItems(rdram, ctx);
        goto after_17;
    // 0x8018F8F0: nop

    after_17:
    // 0x8018F8F4: jal         0x80105600
    // 0x8018F8F8: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_18;
    // 0x8018F8F8: nop

    after_18:
    // 0x8018F8FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018F900: jal         0x800D7194
    // 0x8018F904: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_19;
    // 0x8018F904: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x8018F908: jal         0x801654B0
    // 0x8018F90C: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_20;
    // 0x8018F90C: nop

    after_20:
    // 0x8018F910: jal         0x800FD300
    // 0x8018F914: nop

    efManagerInitEffects(rdram, ctx);
        goto after_21;
    // 0x8018F914: nop

    after_21:
    // 0x8018F918: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8018F91C: lbu         $t5, 0x4AE7($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4AE7);
    // 0x8018F920: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018F924: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8018F928: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8018F92C: jal         0x80115DE8
    // 0x8018F930: lbu         $a0, 0x29BC($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X29BC);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_22;
    // 0x8018F930: lbu         $a0, 0x29BC($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X29BC);
    after_22:
    // 0x8018F934: jal         0x801156E4
    // 0x8018F938: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_23;
    // 0x8018F938: nop

    after_23:
    // 0x8018F93C: jal         0x801653E0
    // 0x8018F940: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_24;
    // 0x8018F940: nop

    after_24:
    // 0x8018F944: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018F948: lbu         $v0, 0x4AE7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AE7);
    // 0x8018F94C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018F950: beq         $v0, $at, L_8018F96C
    if (ctx->r2 == ctx->r1) {
        // 0x8018F954: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018F96C;
    }
    // 0x8018F954: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018F958: beq         $v0, $at, L_8018F9BC
    if (ctx->r2 == ctx->r1) {
        // 0x8018F95C: addiu       $s1, $zero, 0xE
        ctx->r17 = ADD32(0, 0XE);
            goto L_8018F9BC;
    }
    // 0x8018F95C: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x8018F960: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018F964: b           L_8018FA74
    // 0x8018F968: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
        goto L_8018FA74;
    // 0x8018F968: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
L_8018F96C:
    // 0x8018F96C: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x8018F970: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8018F974: addiu       $s1, $s1, 0xE6
    ctx->r17 = ADD32(ctx->r17, 0XE6);
    // 0x8018F978: lw          $s0, 0x6E3C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6E3C);
    // 0x8018F97C: jal         0x800CDBD0
    // 0x8018F980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_25;
    // 0x8018F980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x8018F984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F988: jal         0x80004980
    // 0x8018F98C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_26;
    // 0x8018F98C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_26:
    // 0x8018F990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018F994: jal         0x800CDC88
    // 0x8018F998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_27;
    // 0x8018F998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x8018F99C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8018F9A0: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x8018F9A4: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x8018F9A8: jal         0x801159F8
    // 0x8018F9AC: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_28;
    // 0x8018F9AC: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    after_28:
    // 0x8018F9B0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018F9B4: b           L_8018FA74
    // 0x8018F9B8: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
        goto L_8018FA74;
    // 0x8018F9B8: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
L_8018F9BC:
    // 0x8018F9BC: jal         0x800D786C
    // 0x8018F9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_29;
    // 0x8018F9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x8018F9C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018F9C8: slti        $at, $s1, 0x1A
    ctx->r1 = SIGNED(ctx->r17) < 0X1A ? 1 : 0;
    // 0x8018F9CC: bne         $at, $zero, L_8018F9BC
    if (ctx->r1 != 0) {
        // 0x8018F9D0: nop
    
            goto L_8018F9BC;
    }
    // 0x8018F9D0: nop

    // 0x8018F9D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8018F9D8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8018F9DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018F9E0: addiu       $a1, $a1, 0x6E78
    ctx->r5 = ADD32(ctx->r5, 0X6E78);
    // 0x8018F9E4: addiu       $v0, $v0, 0x6E48
    ctx->r2 = ADD32(ctx->r2, 0X6E48);
    // 0x8018F9E8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_8018F9EC:
    // 0x8018F9EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018F9F0: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x8018F9F4: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x8018F9F8: beql        $at, $zero, L_8018FA08
    if (ctx->r1 == 0) {
        // 0x8018F9FC: sltu        $at, $v0, $a1
        ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
            goto L_8018FA08;
    }
    goto skip_3;
    // 0x8018F9FC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    skip_3:
    // 0x8018FA00: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8018FA04: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
L_8018FA08:
    // 0x8018FA08: bnel        $at, $zero, L_8018F9EC
    if (ctx->r1 != 0) {
        // 0x8018FA0C: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_8018F9EC;
    }
    goto skip_4;
    // 0x8018FA0C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_4:
    // 0x8018FA10: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018FA14: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x8018FA18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018FA1C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8018FA20:
    // 0x8018FA20: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8018FA24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018FA28: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x8018FA2C: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x8018FA30: beql        $t9, $at, L_8018FA68
    if (ctx->r25 == ctx->r1) {
        // 0x8018FA34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018FA68;
    }
    goto skip_5;
    // 0x8018FA34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8018FA38: lbu         $t0, 0x2C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2C);
    // 0x8018FA3C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8018FA40: sll         $t1, $s1, 5
    ctx->r9 = S32(ctx->r17 << 5);
    // 0x8018FA44: beq         $t0, $zero, L_8018FA64
    if (ctx->r8 == 0) {
        // 0x8018FA48: lui         $t2, 0x8019
        ctx->r10 = S32(0X8019 << 16);
            goto L_8018FA64;
    }
    // 0x8018FA48: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018FA4C: addiu       $t2, $t2, 0x2FE0
    ctx->r10 = ADD32(ctx->r10, 0X2FE0);
    // 0x8018FA50: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8018FA54: jal         0x80004980
    // 0x8018FA58: sw          $a0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r4;
    syTaskmanMalloc(rdram, ctx);
        goto after_30;
    // 0x8018FA58: sw          $a0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r4;
    after_30:
    // 0x8018FA5C: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x8018FA60: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8018FA64:
    // 0x8018FA64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018FA68:
    // 0x8018FA68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018FA6C: bne         $s1, $at, L_8018FA20
    if (ctx->r17 != ctx->r1) {
        // 0x8018FA70: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018FA20;
    }
    // 0x8018FA70: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
L_8018FA74:
    // 0x8018FA74: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018FA78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8018FA7C:
    // 0x8018FA7C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8018FA80: addiu       $t4, $t4, 0x6DD0
    ctx->r12 = ADD32(ctx->r12, 0X6DD0);
    // 0x8018FA84: addiu       $t7, $t4, 0x3C
    ctx->r15 = ADD32(ctx->r12, 0X3C);
    // 0x8018FA88: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
L_8018FA8C:
    // 0x8018FA8C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8018FA90: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018FA94: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8018FA98: sw          $t6, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r14;
    // 0x8018FA9C: lw          $t5, -0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X8);
    // 0x8018FAA0: sw          $t5, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r13;
    // 0x8018FAA4: lw          $t6, -0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, -0X4);
    // 0x8018FAA8: bne         $t4, $t7, L_8018FA8C
    if (ctx->r12 != ctx->r15) {
        // 0x8018FAAC: sw          $t6, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r14;
            goto L_8018FA8C;
    }
    // 0x8018FAAC: sw          $t6, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r14;
    // 0x8018FAB0: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8018FAB4: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018FAB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018FABC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018FAC0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8018FAC4: addiu       $t1, $t1, 0x2FE0
    ctx->r9 = ADD32(ctx->r9, 0X2FE0);
    // 0x8018FAC8: sll         $t0, $s1, 5
    ctx->r8 = S32(ctx->r17 << 5);
    // 0x8018FACC: addu        $v1, $t8, $s2
    ctx->r3 = ADD32(ctx->r24, ctx->r18);
    // 0x8018FAD0: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x8018FAD4: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8018FAD8: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x8018FADC: beq         $t9, $at, L_8018FC34
    if (ctx->r25 == ctx->r1) {
        // 0x8018FAE0: addu        $s0, $t0, $t1
        ctx->r16 = ADD32(ctx->r8, ctx->r9);
            goto L_8018FC34;
    }
    // 0x8018FAE0: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x8018FAE4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8018FAE8: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x8018FAEC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8018FAF0: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x8018FAF4: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    // 0x8018FAF8: jal         0x800D786C
    // 0x8018FAFC: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_31;
    // 0x8018FAFC: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    after_31:
    // 0x8018FB00: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8018FB04: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8018FB08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018FB0C: addu        $t5, $t3, $s2
    ctx->r13 = ADD32(ctx->r11, ctx->r18);
    // 0x8018FB10: lbu         $t6, 0x23($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X23);
    // 0x8018FB14: jal         0x8018D3D8
    // 0x8018FB18: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    sc1PGameGetStartPosition(rdram, ctx);
        goto after_32;
    // 0x8018FB18: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_32:
    // 0x8018FB1C: jal         0x8018F240
    // 0x8018FB20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sc1PGameGetEnemyStartLR(rdram, ctx);
        goto after_33;
    // 0x8018FB20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x8018FB24: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018FB28: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8018FB2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018FB30: addu        $v1, $a0, $s2
    ctx->r3 = ADD32(ctx->r4, ctx->r18);
    // 0x8018FB34: lbu         $t8, 0x24($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X24);
    // 0x8018FB38: sb          $s1, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r17;
    // 0x8018FB3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018FB40: sb          $t8, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r24;
    // 0x8018FB44: lbu         $t0, 0x5($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X5);
    // 0x8018FB48: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x8018FB4C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018FB50: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8018FB54: beql        $at, $zero, L_8018FB68
    if (ctx->r1 == 0) {
        // 0x8018FB58: sb          $t7, 0x72($sp)
        MEM_B(0X72, ctx->r29) = ctx->r15;
            goto L_8018FB68;
    }
    goto skip_6;
    // 0x8018FB58: sb          $t7, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r15;
    skip_6:
    // 0x8018FB5C: b           L_8018FB68
    // 0x8018FB60: sb          $t2, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r10;
        goto L_8018FB68;
    // 0x8018FB60: sb          $t2, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r10;
    // 0x8018FB64: sb          $t7, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r15;
L_8018FB68:
    // 0x8018FB68: lbu         $t4, 0x26($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X26);
    // 0x8018FB6C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8018FB70: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8018FB74: sb          $t4, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r12;
    // 0x8018FB78: lbu         $t3, 0x27($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X27);
    // 0x8018FB7C: sb          $t3, 0x74($sp)
    MEM_B(0X74, ctx->r29) = ctx->r11;
    // 0x8018FB80: lbu         $t5, 0x21($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X21);
    // 0x8018FB84: sb          $t5, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r13;
    // 0x8018FB88: lbu         $t6, 0x20($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X20);
    // 0x8018FB8C: sb          $t6, 0x76($sp)
    MEM_B(0X76, ctx->r29) = ctx->r14;
    // 0x8018FB90: lb          $t8, 0x2B($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2B);
    // 0x8018FB94: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8018FB98: sb          $t8, 0x77($sp)
    MEM_B(0X77, ctx->r29) = ctx->r24;
    // 0x8018FB9C: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x8018FBA0: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x8018FBA4: beq         $v0, $zero, L_8018FBB4
    if (ctx->r2 == 0) {
        // 0x8018FBA8: sw          $t9, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r25;
            goto L_8018FBB4;
    }
    // 0x8018FBA8: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x8018FBAC: b           L_8018FBC0
    // 0x8018FBB0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
        goto L_8018FBC0;
    // 0x8018FBB0: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
L_8018FBB4:
    // 0x8018FBB4: jal         0x800D78B4
    // 0x8018FBB8: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_34;
    // 0x8018FBB8: lbu         $a0, 0x23($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X23);
    after_34:
    // 0x8018FBBC: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
L_8018FBC0:
    // 0x8018FBC0: lbu         $v0, 0x7B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7B);
    // 0x8018FBC4: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x8018FBC8: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x8018FBCC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8018FBD0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8018FBD4: andi        $t6, $v0, 0xFF7F
    ctx->r14 = ctx->r2 & 0XFF7F;
    // 0x8018FBD8: sll         $t5, $t4, 7
    ctx->r13 = S32(ctx->r12 << 7);
    // 0x8018FBDC: or          $v0, $t5, $t6
    ctx->r2 = ctx->r13 | ctx->r14;
    // 0x8018FBE0: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8018FBE4: sb          $t2, 0x7A($sp)
    MEM_B(0X7A, ctx->r29) = ctx->r10;
    // 0x8018FBE8: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8018FBEC: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8018FBF0: andi        $t2, $v0, 0xFFDF
    ctx->r10 = ctx->r2 & 0XFFDF;
    // 0x8018FBF4: or          $v0, $t1, $t2
    ctx->r2 = ctx->r9 | ctx->r10;
    // 0x8018FBF8: sb          $v0, 0x7B($sp)
    MEM_B(0X7B, ctx->r29) = ctx->r2;
    // 0x8018FBFC: jal         0x800D7F3C
    // 0x8018FC00: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    ftManagerMakeFighter(rdram, ctx);
        goto after_35;
    // 0x8018FC00: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_35:
    // 0x8018FC04: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018FC08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018FC0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018FC10: jal         0x800E7C4C
    // 0x8018FC14: sw          $v1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r3;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_36;
    // 0x8018FC14: sw          $v1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r3;
    after_36:
    // 0x8018FC18: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
    // 0x8018FC1C: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x8018FC20: lwc1        $f4, 0x860($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X860);
    // 0x8018FC24: sb          $t7, 0x1D1($v1)
    MEM_B(0X1D1, ctx->r3) = ctx->r15;
    // 0x8018FC28: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8018FC2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018FC30: swc1        $f8, 0x860($v1)
    MEM_W(0X860, ctx->r3) = ctx->f8.u32l;
L_8018FC34:
    // 0x8018FC34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018FC38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018FC3C: bne         $s1, $at, L_8018FA7C
    if (ctx->r17 != ctx->r1) {
        // 0x8018FC40: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018FA7C;
    }
    // 0x8018FC40: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018FC44: jal         0x800D782C
    // 0x8018FC48: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_37;
    // 0x8018FC48: nop

    after_37:
    // 0x8018FC4C: jal         0x80114958
    // 0x8018FC50: nop

    ifCommonBattleSetGameStatusWait(rdram, ctx);
        goto after_38;
    // 0x8018FC50: nop

    after_38:
    // 0x8018FC54: jal         0x8018F1C0
    // 0x8018FC58: nop

    sc1PGameTryInitPlayerArrows(rdram, ctx);
        goto after_39;
    // 0x8018FC58: nop

    after_39:
    // 0x8018FC5C: jal         0x8010E1A4
    // 0x8018FC60: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_40;
    // 0x8018FC60: nop

    after_40:
    // 0x8018FC64: jal         0x80111440
    // 0x8018FC68: nop

    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_41;
    // 0x8018FC68: nop

    after_41:
    // 0x8018FC6C: jal         0x8010DDC4
    // 0x8018FC70: nop

    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_42;
    // 0x8018FC70: nop

    after_42:
    // 0x8018FC74: jal         0x8010E374
    // 0x8018FC78: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_43;
    // 0x8018FC78: nop

    after_43:
    // 0x8018FC7C: jal         0x8010E498
    // 0x8018FC80: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_44;
    // 0x8018FC80: nop

    after_44:
    // 0x8018FC84: jal         0x80111BE4
    // 0x8018FC88: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_45;
    // 0x8018FC88: nop

    after_45:
    // 0x8018FC8C: jal         0x8018E598
    // 0x8018FC90: nop

    sc1PGameSetPlayerInterfacePositions(rdram, ctx);
        goto after_46;
    // 0x8018FC90: nop

    after_46:
    // 0x8018FC94: jal         0x8010F3C0
    // 0x8018FC98: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_47;
    // 0x8018FC98: nop

    after_47:
    // 0x8018FC9C: jal         0x80110514
    // 0x8018FCA0: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_48;
    // 0x8018FCA0: nop

    after_48:
    // 0x8018FCA4: jal         0x8018EE44
    // 0x8018FCA8: nop

    sc1PGameInitTeamStockDisplay(rdram, ctx);
        goto after_49;
    // 0x8018FCA8: nop

    after_49:
    // 0x8018FCAC: jal         0x8018EB68
    // 0x8018FCB0: nop

    sc1PGameSetGameStatusWait(rdram, ctx);
        goto after_50;
    // 0x8018FCB0: nop

    after_50:
    // 0x8018FCB4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018FCB8: lbu         $v0, 0x4AE7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AE7);
    // 0x8018FCBC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018FCC0: beq         $v0, $at, L_8018FCD0
    if (ctx->r2 == ctx->r1) {
        // 0x8018FCC4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018FCD0;
    }
    // 0x8018FCC4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018FCC8: bne         $v0, $at, L_8018FCE8
    if (ctx->r2 != ctx->r1) {
        // 0x8018FCCC: nop
    
            goto L_8018FCE8;
    }
    // 0x8018FCCC: nop

L_8018FCD0:
    // 0x8018FCD0: jal         0x800FC42C
    // 0x8018FCD4: nop

    mpCollisionSetBGM(rdram, ctx);
        goto after_51;
    // 0x8018FCD4: nop

    after_51:
    // 0x8018FCD8: jal         0x800269C0
    // 0x8018FCDC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_800269C0_275C0(rdram, ctx);
        goto after_52;
    // 0x8018FCDC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_52:
    // 0x8018FCE0: b           L_8018FCF8
    // 0x8018FCE4: nop

        goto L_8018FCF8;
    // 0x8018FCE4: nop

L_8018FCE8:
    // 0x8018FCE8: jal         0x800FC3E8
    // 0x8018FCEC: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_53;
    // 0x8018FCEC: nop

    after_53:
    // 0x8018FCF0: jal         0x800269C0
    // 0x8018FCF4: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_54;
    // 0x8018FCF4: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_54:
L_8018FCF8:
    // 0x8018FCF8: jal         0x8018F1F8
    // 0x8018FCFC: nop

    sc1PGameInitTimeUpMessage(rdram, ctx);
        goto after_55;
    // 0x8018FCFC: nop

    after_55:
    // 0x8018FD00: jal         0x80112F68
    // 0x8018FD04: nop

    ifCommonTimerMakeDigits(rdram, ctx);
        goto after_56;
    // 0x8018FD04: nop

    after_56:
    // 0x8018FD08: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018FD0C: addiu       $t4, $t4, 0x2B14
    ctx->r12 = ADD32(ctx->r12, 0X2B14);
    // 0x8018FD10: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8018FD14: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x8018FD18: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8018FD1C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8018FD20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FD24: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018FD28: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018FD2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018FD30: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018FD34: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018FD38: jal         0x800D4060
    // 0x8018FD3C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_57;
    // 0x8018FD3C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_57:
    // 0x8018FD40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018FD44: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018FD48: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018FD4C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018FD50: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018FD54: jr          $ra
    // 0x8018FD58: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8018FD58: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void itMainCheckSetColAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80172F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172FA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172FA4: jal         0x800E974C
    // 0x80172FA8: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    ftParamCheckSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x80172FA8: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    after_0:
    // 0x80172FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80172FB4: jr          $ra
    // 0x80172FB8: nop

    return;
    // 0x80172FB8: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FA2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015FA30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015FA34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015FA38: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015FA3C: jal         0x800DEE98
    // 0x8015FA40: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015FA40: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015FA44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015FA48: addiu       $t7, $zero, 0x4006
    ctx->r15 = ADD32(0, 0X4006);
    // 0x8015FA4C: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015FA50: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015FA54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015FA58: jal         0x800E6F24
    // 0x8015FA5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015FA5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015FA60: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015FA64: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8015FA68: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8015FA6C: addiu       $t8, $t8, -0x6374
    ctx->r24 = ADD32(ctx->r24, -0X6374);
    // 0x8015FA70: addiu       $t9, $t9, -0x633C
    ctx->r25 = ADD32(ctx->r25, -0X633C);
    // 0x8015FA74: sw          $t8, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r24;
    // 0x8015FA78: sw          $t9, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r25;
    // 0x8015FA7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FA80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015FA84: jr          $ra
    // 0x8015FA88: nop

    return;
    // 0x8015FA88: nop

;}
RECOMP_FUNC void syAudioStopBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B08: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020B0C: lw          $t7, -0x2690($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2690);
    // 0x80020B10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80020B14: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80020B18: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80020B1C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80020B20: lw          $t0, -0x268C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X268C);
    // 0x80020B24: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80020B28: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80020B2C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80020B30: jr          $ra
    // 0x80020B34: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    return;
    // 0x80020B34: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
;}
RECOMP_FUNC void mnPlayers1PTrainingReadyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801372D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801372D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801372DC: jal         0x80137274
    // 0x801372E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PTrainingCheckReady(rdram, ctx);
        goto after_0;
    // 0x801372E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801372E4: beq         $v0, $zero, L_80137330
    if (ctx->r2 == 0) {
        // 0x801372E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80137330;
    }
    // 0x801372E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801372EC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801372F0: addiu       $v1, $v1, -0x777C
    ctx->r3 = ADD32(ctx->r3, -0X777C);
    // 0x801372F4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801372F8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801372FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80137300: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80137304: bne         $v0, $at, L_80137314
    if (ctx->r2 != ctx->r1) {
        // 0x80137308: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80137314;
    }
    // 0x80137308: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8013730C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80137310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137314:
    // 0x80137314: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80137318: beq         $at, $zero, L_80137328
    if (ctx->r1 == 0) {
        // 0x8013731C: nop
    
            goto L_80137328;
    }
    // 0x8013731C: nop

    // 0x80137320: b           L_80137344
    // 0x80137324: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80137344;
    // 0x80137324: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80137328:
    // 0x80137328: b           L_80137344
    // 0x8013732C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
        goto L_80137344;
    // 0x8013732C: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80137330:
    // 0x80137330: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137334: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80137338: addiu       $v1, $v1, -0x777C
    ctx->r3 = ADD32(ctx->r3, -0X777C);
    // 0x8013733C: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x80137340: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80137344:
    // 0x80137344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013734C: jr          $ra
    // 0x80137350: nop

    return;
    // 0x80137350: nop

;}
RECOMP_FUNC void mnPlayersVSInitSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AFC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013AFC4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013AFC8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8013AFCC: lw          $t7, -0x4270($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4270);
    // 0x8013AFD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013AFD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013AFD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013AFDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013AFE0: beq         $t7, $at, L_8013B014
    if (ctx->r15 == ctx->r1) {
        // 0x8013AFE4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8013B014;
    }
    // 0x8013AFE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013AFE8: jal         0x80138DEC
    // 0x8013AFEC: nop

    mnPlayersVSMakeCursor(rdram, ctx);
        goto after_0;
    // 0x8013AFEC: nop

    after_0:
    // 0x8013AFF0: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8013AFF4: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8013AFF8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8013AFFC: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8013B000: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013B004: addiu       $t9, $t9, -0x4578
    ctx->r25 = ADD32(ctx->r25, -0X4578);
    // 0x8013B008: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013B00C: b           L_8013B038
    // 0x8013B010: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
        goto L_8013B038;
    // 0x8013B010: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_8013B014:
    // 0x8013B014: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8013B018: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x8013B01C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8013B020: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x8013B024: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013B028: addiu       $t1, $t1, -0x4578
    ctx->r9 = ADD32(ctx->r9, -0X4578);
    // 0x8013B02C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013B030: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8013B034: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8013B038:
    // 0x8013B038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013B03C: jal         0x80139098
    // 0x8013B040: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    mnPlayersVSMakePuck(rdram, ctx);
        goto after_1;
    // 0x8013B040: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8013B044: jal         0x8013365C
    // 0x8013B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakeGate(rdram, ctx);
        goto after_2;
    // 0x8013B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013B04C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8013B050: lw          $t2, 0x58($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X58);
    // 0x8013B054: beql        $t2, $zero, L_8013B080
    if (ctx->r10 == 0) {
        // 0x8013B058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013B080;
    }
    goto skip_0;
    // 0x8013B058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013B05C: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x8013B060: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013B064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013B068: beql        $a2, $at, L_8013B080
    if (ctx->r6 == ctx->r1) {
        // 0x8013B06C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013B080;
    }
    goto skip_1;
    // 0x8013B06C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013B070: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8013B074: jal         0x80134A8C
    // 0x8013B078: lw          $a3, 0x4C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4C);
    mnPlayersVSMakeFighter(rdram, ctx);
        goto after_3;
    // 0x8013B078: lw          $a3, 0x4C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4C);
    after_3:
    // 0x8013B07C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013B080:
    // 0x8013B080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013B084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013B088: jr          $ra
    // 0x8013B08C: nop

    return;
    // 0x8013B08C: nop

;}
RECOMP_FUNC void func_ovl8_8037CF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CF4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037CF50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CF54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037CF58: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x8037CF5C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8037CF60: addiu       $a0, $zero, -0x1FB
    ctx->r4 = ADD32(0, -0X1FB);
    // 0x8037CF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CF68: lwl         $t9, 0x2($t7)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r15, 0X2);
    // 0x8037CF6C: lwl         $t8, 0x6($t7)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r15, 0X6);
    // 0x8037CF70: lwr         $t9, 0x5($t7)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r15, 0X5);
    // 0x8037CF74: lwr         $t8, 0x9($t7)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r15, 0X9);
    // 0x8037CF78: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8037CF7C: swl         $t9, 0x5C($t7)
    do_swl(rdram, 0X5C, ctx->r15, ctx->r25);
    // 0x8037CF80: swl         $t8, 0x60($t7)
    do_swl(rdram, 0X60, ctx->r15, ctx->r24);
    // 0x8037CF84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037CF88: swr         $t9, 0x5F($t7)
    do_swr(rdram, 0X5F, ctx->r15, ctx->r25);
    // 0x8037CF8C: jal         0x80009968
    // 0x8037CF90: swr         $t8, 0x63($t7)
    do_swr(rdram, 0X63, ctx->r15, ctx->r24);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8037CF90: swr         $t8, 0x63($t7)
    do_swr(rdram, 0X63, ctx->r15, ctx->r24);
    after_0:
    // 0x8037CF94: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8037CF98: sw          $v0, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r2;
    // 0x8037CF9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037CFA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CFA4: jr          $ra
    // 0x8037CFA8: nop

    return;
    // 0x8037CFA8: nop

;}
RECOMP_FUNC void alN_PVoiceNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CA20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CA24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002CA28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CA2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002CA30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CA34: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8002CA38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002CA3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002CA40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CA44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CA48: jal         0x8001E5F4
    // 0x8002CA4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002CA4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8002CA50: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8002CA54: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8002CA58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002CA5C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002CA60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CA64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CA68: jal         0x8001E5F4
    // 0x8002CA6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x8002CA6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8002CA70: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8002CA74: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CA78: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x8002CA7C: jalr        $t9
    // 0x8002CA80: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002CA80: nop

    after_2:
    // 0x8002CA84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002CA88: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8002CA8C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8002CA90: sw          $a3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r7;
    // 0x8002CA94: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8002CA98: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8002CA9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002CAA0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002CAA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CAA8: jal         0x8001E5F4
    // 0x8002CAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x8002CAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8002CAB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002CAB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CAB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002CABC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002CAC0: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8002CAC4: sw          $a3, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r7;
    // 0x8002CAC8: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8002CACC: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8002CAD0: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8002CAD4: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8002CAD8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002CADC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002CAE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CAE4: jal         0x8001E5F4
    // 0x8002CAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8002CAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8002CAEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002CAF0: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8002CAF4: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x8002CAF8: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x8002CAFC: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
    // 0x8002CB00: sh          $v1, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r3;
    // 0x8002CB04: sh          $v1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r3;
    // 0x8002CB08: sh          $v1, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r3;
    // 0x8002CB0C: sh          $v1, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r3;
    // 0x8002CB10: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x8002CB14: sh          $zero, 0x62($s0)
    MEM_H(0X62, ctx->r16) = 0;
    // 0x8002CB18: sh          $v1, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r3;
    // 0x8002CB1C: sh          $zero, 0x64($s0)
    MEM_H(0X64, ctx->r16) = 0;
    // 0x8002CB20: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8002CB24: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8002CB28: sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
    // 0x8002CB2C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8002CB30: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x8002CB34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002CB38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002CB3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CB40: jr          $ra
    // 0x8002CB44: nop

    return;
    // 0x8002CB44: nop

;}

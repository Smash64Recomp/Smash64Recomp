#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbRelocGetExternBytesNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDA38: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CDA3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDA40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CDA44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CDA48: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CDA4C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CDA50: jal         0x800CD620
    // 0x800CDA54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDA54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800CDA58: beq         $v0, $zero, L_800CDA68
    if (ctx->r2 == 0) {
        // 0x800CDA5C: lui         $a3, 0x800D
        ctx->r7 = S32(0X800D << 16);
            goto L_800CDA68;
    }
    // 0x800CDA5C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800CDA60: b           L_800CDBB4
    // 0x800CDA64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CDBB4;
    // 0x800CDA64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CDA68:
    // 0x800CDA68: addiu       $a3, $a3, 0x6340
    ctx->r7 = ADD32(ctx->r7, 0X6340);
    // 0x800CDA6C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CDA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CDA74: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDA78: blez        $a0, L_800CDAA8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800CDA7C: lui         $a1, 0x800D
        ctx->r5 = S32(0X800D << 16);
            goto L_800CDAA8;
    }
    // 0x800CDA7C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CDA80: lw          $v1, 0x633C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X633C);
L_800CDA84:
    // 0x800CDA84: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800CDA88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CDA8C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CDA90: bne         $s1, $t6, L_800CDAA0
    if (ctx->r17 != ctx->r14) {
        // 0x800CDA94: nop
    
            goto L_800CDAA0;
    }
    // 0x800CDA94: nop

    // 0x800CDA98: b           L_800CDBB4
    // 0x800CDA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CDBB4;
    // 0x800CDA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CDAA0:
    // 0x800CDAA0: bne         $at, $zero, L_800CDA84
    if (ctx->r1 != 0) {
        // 0x800CDAA4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800CDA84;
    }
    // 0x800CDAA4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800CDAA8:
    // 0x800CDAA8: lw          $a1, 0x6344($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6344);
    // 0x800CDAAC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CDAB0: addiu       $s0, $s0, 0x5F50
    ctx->r16 = ADD32(ctx->r16, 0X5F50);
    // 0x800CDAB4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CDAB8: bne         $at, $zero, L_800CDADC
    if (ctx->r1 != 0) {
        // 0x800CDABC: nop
    
            goto L_800CDADC;
    }
    // 0x800CDABC: nop

L_800CDAC0:
    // 0x800CDAC0: jal         0x80023624
    // 0x800CDAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x800CDAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CDAC8: jal         0x800A3040
    // 0x800CDACC: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x800CDACC: nop

    after_2:
    // 0x800CDAD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CDAD4: b           L_800CDAC0
    // 0x800CDAD8: lw          $a1, 0x6344($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6344);
        goto L_800CDAC0;
    // 0x800CDAD8: lw          $a1, 0x6344($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6344);
L_800CDADC:
    // 0x800CDADC: jal         0x800CD814
    // 0x800CDAE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbRelocReadDmaTableEntry(rdram, ctx);
        goto after_3;
    // 0x800CDAE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800CDAE4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800CDAE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CDAEC: addiu       $t0, $t0, 0x6334
    ctx->r8 = ADD32(ctx->r8, 0X6334);
    // 0x800CDAF0: addiu       $a3, $a3, 0x6340
    ctx->r7 = ADD32(ctx->r7, 0X6340);
    // 0x800CDAF4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800CDAF8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800CDAFC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CDB00: lw          $t7, 0x633C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X633C);
    // 0x800CDB04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CDB08: lhu         $s2, 0xA($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0XA);
    // 0x800CDB0C: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x800CDB10: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800CDB14: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x800CDB18: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800CDB1C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800CDB20: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800CDB24: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800CDB28: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800CDB2C: lw          $t8, 0x6338($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6338);
    // 0x800CDB30: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x800CDB34: addiu       $s2, $s2, 0xF
    ctx->r18 = ADD32(ctx->r18, 0XF);
    // 0x800CDB38: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDB3C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CDB40: and         $s2, $s2, $at
    ctx->r18 = ctx->r18 & ctx->r1;
    // 0x800CDB44: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDB48: lw          $v1, 0x62E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X62E8);
    // 0x800CDB4C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800CDB50: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800CDB54: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CDB58: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800CDB5C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800CDB60: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x800CDB64: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800CDB68: addu        $s0, $a2, $a1
    ctx->r16 = ADD32(ctx->r6, ctx->r5);
    // 0x800CDB6C: addu        $s3, $v1, $t9
    ctx->r19 = ADD32(ctx->r3, ctx->r25);
    // 0x800CDB70: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800CDB74: beq         $at, $zero, L_800CDBB0
    if (ctx->r1 == 0) {
        // 0x800CDB78: or          $s1, $sp, $zero
        ctx->r17 = ctx->r29 | 0;
            goto L_800CDBB0;
    }
    // 0x800CDB78: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x800CDB7C: addiu       $s1, $s1, 0x4B
    ctx->r17 = ADD32(ctx->r17, 0X4B);
    // 0x800CDB80: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDB84: and         $s1, $s1, $at
    ctx->r17 = ctx->r17 & ctx->r1;
L_800CDB88:
    // 0x800CDB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CDB8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CDB90: jal         0x80002CA0
    // 0x800CDB94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    syDmaReadRom(rdram, ctx);
        goto after_4;
    // 0x800CDB94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x800CDB98: jal         0x800CDA38
    // 0x800CDB9C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    lbRelocGetExternBytesNum(rdram, ctx);
        goto after_5;
    // 0x800CDB9C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_5:
    // 0x800CDBA0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800CDBA4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800CDBA8: bne         $at, $zero, L_800CDB88
    if (ctx->r1 != 0) {
        // 0x800CDBAC: addu        $s2, $s2, $v0
        ctx->r18 = ADD32(ctx->r18, ctx->r2);
            goto L_800CDB88;
    }
    // 0x800CDBAC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800CDBB0:
    // 0x800CDBB0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800CDBB4:
    // 0x800CDBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDBB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CDBBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CDBC0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDBC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CDBC8: jr          $ra
    // 0x800CDBCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CDBCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mnSoundTestSelectIDThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133304: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80133308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013330C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133310: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133314: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133318: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013331C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80133320: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80133324: jal         0x80132F50
    // 0x80133328: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    mnSoundTestMakeNumberSObj(rdram, ctx);
        goto after_0;
    // 0x80133328: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013332C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80133330: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133334: addiu       $t9, $t9, 0x4348
    ctx->r25 = ADD32(ctx->r25, 0X4348);
    // 0x80133338: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8013333C: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x80133340: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80133344:
    // 0x80133344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133348: beq         $s0, $v0, L_80133358
    if (ctx->r16 == ctx->r2) {
        // 0x8013334C: nop
    
            goto L_80133358;
    }
    // 0x8013334C: nop

    // 0x80133350: jal         0x80133194
    // 0x80133354: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    mnSoundTestUpdateNumberSprites(rdram, ctx);
        goto after_1;
    // 0x80133354: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
L_80133358:
    // 0x80133358: jal         0x8000B1E8
    // 0x8013335C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_2;
    // 0x8013335C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80133360: b           L_80133344
    // 0x80133364: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80133344;
    // 0x80133364: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80133368: nop

    // 0x8013336C: nop

    // 0x80133370: nop

    // 0x80133374: nop

    // 0x80133378: nop

    // 0x8013337C: nop

    // 0x80133380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133388: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013338C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133390: jr          $ra
    // 0x80133394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80133394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftDisplayMainDecideFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1B7C: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x800F1B80: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800F1B84: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800F1B88: bne         $v0, $zero, L_800F1BB4
    if (ctx->r2 != 0) {
        // 0x800F1B8C: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_800F1BB4;
    }
    // 0x800F1B8C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800F1B90: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800F1B94: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800F1B98: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800F1B9C: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800F1BA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800F1BA4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800F1BA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800F1BAC: jr          $ra
    // 0x800F1BB0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x800F1BB0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800F1BB4:
    // 0x800F1BB4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800F1BB8: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
    // 0x800F1BBC: lui         $t1, 0xF800
    ctx->r9 = S32(0XF800 << 16);
    // 0x800F1BC0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800F1BC4: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x800F1BC8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800F1BCC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800F1BD0: lbu         $t6, 0xED($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XED);
    // 0x800F1BD4: lbu         $t3, 0xEC($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XEC);
    // 0x800F1BD8: lbu         $t0, 0xEE($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XEE);
    // 0x800F1BDC: lbu         $t5, 0xEF($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XEF);
    // 0x800F1BE0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800F1BE4: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800F1BE8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800F1BEC: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800F1BF0: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800F1BF4: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800F1BF8: addiu       $a1, $a1, 0xEC
    ctx->r5 = ADD32(ctx->r5, 0XEC);
    // 0x800F1BFC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800F1C00: jr          $ra
    // 0x800F1C04: nop

    return;
    // 0x800F1C04: nop

;}
RECOMP_FUNC void ifCommonAnnounceEndMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114C80: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80114C84: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80114C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114C90: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80114C94: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114C98: addiu       $a0, $a0, 0x36A4
    ctx->r4 = ADD32(ctx->r4, 0X36A4);
    // 0x80114C9C: slti        $at, $t6, 0x11
    ctx->r1 = SIGNED(ctx->r14) < 0X11 ? 1 : 0;
    // 0x80114CA0: bne         $at, $zero, L_80114CC8
    if (ctx->r1 != 0) {
        // 0x80114CA4: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80114CC8;
    }
    // 0x80114CA4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114CA8: addiu       $a1, $a1, 0x42B4
    ctx->r5 = ADD32(ctx->r5, 0X42B4);
    // 0x80114CAC: addiu       $a2, $zero, 0x1CC
    ctx->r6 = ADD32(0, 0X1CC);
    // 0x80114CB0: jal         0x80114B80
    // 0x80114CB4: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_0;
    // 0x80114CB4: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_0:
    // 0x80114CB8: jal         0x80114A48
    // 0x80114CBC: nop

    ifCommonAnnounceFailureMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80114CBC: nop

    after_1:
    // 0x80114CC0: b           L_80114D4C
    // 0x80114CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80114D4C;
    // 0x80114CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114CC8:
    // 0x80114CC8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80114CCC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80114CD0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80114CD4: bne         $t7, $at, L_80114D28
    if (ctx->r15 != ctx->r1) {
        // 0x80114CD8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80114D28;
    }
    // 0x80114CD8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114CDC: lbu         $t8, 0x4AE3($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4AE3);
    // 0x80114CE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80114CE4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114CE8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80114CEC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80114CF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80114CF4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80114CF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80114CFC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80114D00: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x80114D04: addiu       $a1, $a1, 0x4C20
    ctx->r5 = ADD32(ctx->r5, 0X4C20);
    // 0x80114D08: addiu       $a2, $zero, 0x1E8
    ctx->r6 = ADD32(0, 0X1E8);
    // 0x80114D0C: beq         $t1, $at, L_80114D28
    if (ctx->r9 == ctx->r1) {
        // 0x80114D10: addiu       $a3, $zero, 0x5A
        ctx->r7 = ADD32(0, 0X5A);
            goto L_80114D28;
    }
    // 0x80114D10: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x80114D14: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114D18: jal         0x80114B80
    // 0x80114D1C: addiu       $a0, $a0, 0x36A4
    ctx->r4 = ADD32(ctx->r4, 0X36A4);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_2;
    // 0x80114D1C: addiu       $a0, $a0, 0x36A4
    ctx->r4 = ADD32(ctx->r4, 0X36A4);
    after_2:
    // 0x80114D20: b           L_80114D40
    // 0x80114D24: nop

        goto L_80114D40;
    // 0x80114D24: nop

L_80114D28:
    // 0x80114D28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114D2C: addiu       $a1, $a1, 0x42B4
    ctx->r5 = ADD32(ctx->r5, 0X42B4);
    // 0x80114D30: addiu       $a0, $a0, 0x36A4
    ctx->r4 = ADD32(ctx->r4, 0X36A4);
    // 0x80114D34: addiu       $a2, $zero, 0x1E8
    ctx->r6 = ADD32(0, 0X1E8);
    // 0x80114D38: jal         0x80114B80
    // 0x80114D3C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_3;
    // 0x80114D3C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_3:
L_80114D40:
    // 0x80114D40: jal         0x8011341C
    // 0x80114D44: nop

    ifCommonAnnounceGameSetMakeInterface(rdram, ctx);
        goto after_4;
    // 0x80114D44: nop

    after_4:
    // 0x80114D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114D4C:
    // 0x80114D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114D50: jr          $ra
    // 0x80114D54: nop

    return;
    // 0x80114D54: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPuckAdjustRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136BE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80136BE4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136BE8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136BEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136BF0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136BF4: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80136BF8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136BFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80136C00: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80136C04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80136C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136C0C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80136C10: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x80136C14: sw          $t9, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r25;
    // 0x80136C18: beq         $at, $zero, L_80136C84
    if (ctx->r1 == 0) {
        // 0x80136C1C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_80136C84;
    }
    // 0x80136C1C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80136C20: lwc1        $f4, 0x64($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80136C24: lwc1        $f6, 0x60($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80136C28: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80136C30: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80136C34: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80136C38: beq         $at, $zero, L_80136C5C
    if (ctx->r1 == 0) {
        // 0x80136C3C: div.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_80136C5C;
    }
    // 0x80136C3C: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80136C40: lwc1        $f16, 0x6C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80136C44: lwc1        $f18, 0x68($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80136C48: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80136C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136C50: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80136C54: b           L_80136C74
    // 0x80136C58: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
        goto L_80136C74;
    // 0x80136C58: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
L_80136C5C:
    // 0x80136C5C: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80136C60: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x80136C64: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80136C68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136C6C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80136C70: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_80136C74:
    // 0x80136C74: swc1        $f2, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f2.u32l;
    // 0x80136C78: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x80136C7C: b           L_80136CAC
    // 0x80136C80: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
        goto L_80136CAC;
    // 0x80136C80: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
L_80136C84:
    // 0x80136C84: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80136C88: bne         $v1, $at, L_80136CAC
    if (ctx->r3 != ctx->r1) {
        // 0x80136C8C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80136CAC;
    }
    // 0x80136C8C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80136C90: jal         0x80134CC8
    // 0x80136C94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnPlayers1PTrainingSetCursorGrab(rdram, ctx);
        goto after_0;
    // 0x80136C94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80136C98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80136C9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80136CA0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136CA4: swc1        $f0, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f0.u32l;
    // 0x80136CA8: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
L_80136CAC:
    // 0x80136CAC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80136CB0: bnel        $v1, $at, L_80136CC0
    if (ctx->r3 != ctx->r1) {
        // 0x80136CB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136CC0;
    }
    goto skip_0;
    // 0x80136CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80136CB8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x80136CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136CC0:
    // 0x80136CC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80136CC4: jr          $ra
    // 0x80136CC8: nop

    return;
    // 0x80136CC8: nop

;}
RECOMP_FUNC void syDmaCreateMesgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A68: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002A6C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80002A70: addiu       $a1, $a1, 0x50BC
    ctx->r5 = ADD32(ctx->r5, 0X50BC);
    // 0x80002A74: addiu       $a0, $a0, 0x50C0
    ctx->r4 = ADD32(ctx->r4, 0X50C0);
    // 0x80002A78: jal         0x80034480
    // 0x80002A7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80002A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A88: jr          $ra
    // 0x80002A8C: nop

    return;
    // 0x80002A8C: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser3DProcAbsorb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801076B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801076B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801076B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801076BC: jal         0x800269C0
    // 0x801076C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801076C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801076C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801076C8: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x801076CC: jal         0x801005C8
    // 0x801076D0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801076D0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801076D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801076D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801076DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801076E0: jr          $ra
    // 0x801076E4: nop

    return;
    // 0x801076E4: nop

;}
RECOMP_FUNC void mnBackupClearFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132BA4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132BA8: addiu       $v1, $v1, 0x30E0
    ctx->r3 = ADD32(ctx->r3, 0X30E0);
    // 0x80132BAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132BB0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132BB4: addiu       $a0, $a0, 0x30E4
    ctx->r4 = ADD32(ctx->r4, 0X30E4);
    // 0x80132BB8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80132BBC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132BC4: beq         $v0, $zero, L_80132BD8
    if (ctx->r2 == 0) {
        // 0x80132BC8: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132BD8;
    }
    // 0x80132BC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132BCC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80132BD0: b           L_80132D24
    // 0x80132BD4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_80132D24;
    // 0x80132BD4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80132BD8:
    // 0x80132BD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132BDC: addiu       $v1, $v1, 0x30E8
    ctx->r3 = ADD32(ctx->r3, 0X30E8);
    // 0x80132BE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132BE4: beq         $v0, $zero, L_80132C70
    if (ctx->r2 == 0) {
        // 0x80132BE8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132C70;
    }
    // 0x80132BE8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132BEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80132BF0: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80132BF4: mfhi        $t0
    ctx->r8 = hi;
    // 0x80132BF8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132BFC: bne         $t0, $zero, L_80132C50
    if (ctx->r8 != 0) {
        // 0x80132C00: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80132C50;
    }
    // 0x80132C00: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80132C04: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132C08: lw          $t1, 0x30C8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30C8);
    // 0x80132C0C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132C10: lw          $t2, 0x31B4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31B4);
    // 0x80132C14: lw          $v1, 0x74($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X74);
    // 0x80132C18: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132C1C: addiu       $t3, $t3, 0x7550
    ctx->r11 = ADD32(ctx->r11, 0X7550);
    // 0x80132C20: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x80132C24: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80132C28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132C2C: bne         $t4, $a0, L_80132C48
    if (ctx->r12 != ctx->r4) {
        // 0x80132C30: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80132C48;
    }
    // 0x80132C30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C34: lw          $t5, 0x30D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30D4);
    // 0x80132C38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C3C: sw          $t5, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r13;
    // 0x80132C40: b           L_80132C50
    // 0x80132C44: lw          $v0, 0x30E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30E8);
        goto L_80132C50;
    // 0x80132C44: lw          $v0, 0x30E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30E8);
L_80132C48:
    // 0x80132C48: sw          $a0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r4;
    // 0x80132C4C: lw          $v0, 0x30E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30E8);
L_80132C50:
    // 0x80132C50: bnel        $v0, $zero, L_80132D28
    if (ctx->r2 != 0) {
        // 0x80132C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132D28;
    }
    goto skip_0;
    // 0x80132C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132C58: jal         0x80132124
    // 0x80132C5C: nop

    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_0;
    // 0x80132C5C: nop

    after_0:
    // 0x80132C60: jal         0x80131D44
    // 0x80132C64: nop

    mnBackupClearSetOptionSpriteColors(rdram, ctx);
        goto after_1;
    // 0x80132C64: nop

    after_1:
    // 0x80132C68: b           L_80132D28
    // 0x80132C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D28;
    // 0x80132C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132C70:
    // 0x80132C70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132C74: addiu       $v1, $v1, 0x30DC
    ctx->r3 = ADD32(ctx->r3, 0X30DC);
    // 0x80132C78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C7C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132C80: beq         $v0, $zero, L_80132C8C
    if (ctx->r2 == 0) {
        // 0x80132C84: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80132C8C;
    }
    // 0x80132C84: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80132C88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80132C8C:
    // 0x80132C8C: jal         0x80390A04
    // 0x80132C90: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_2;
    // 0x80132C90: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80132C94: beq         $v0, $zero, L_80132CD0
    if (ctx->r2 == 0) {
        // 0x80132C98: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132CD0;
    }
    // 0x80132C98: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132C9C: jal         0x80390AC0
    // 0x80132CA0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_3;
    // 0x80132CA0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80132CA4: beq         $v0, $zero, L_80132CD0
    if (ctx->r2 == 0) {
        // 0x80132CA8: nop
    
            goto L_80132CD0;
    }
    // 0x80132CA8: nop

    // 0x80132CAC: jal         0x80390804
    // 0x80132CB0: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_4;
    // 0x80132CB0: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_4:
    // 0x80132CB4: bne         $v0, $zero, L_80132CD0
    if (ctx->r2 != 0) {
        // 0x80132CB8: nop
    
            goto L_80132CD0;
    }
    // 0x80132CB8: nop

    // 0x80132CBC: jal         0x80390804
    // 0x80132CC0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x80132CC0: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_5:
    // 0x80132CC4: bne         $v0, $zero, L_80132CD0
    if (ctx->r2 != 0) {
        // 0x80132CC8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132CD0;
    }
    // 0x80132CC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CCC: sw          $zero, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = 0;
L_80132CD0:
    // 0x80132CD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132CD4: lw          $v0, 0x30D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30D0);
    // 0x80132CD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132CDC: beq         $v0, $zero, L_80132CFC
    if (ctx->r2 == 0) {
        // 0x80132CE0: nop
    
            goto L_80132CFC;
    }
    // 0x80132CE0: nop

    // 0x80132CE4: beq         $v0, $at, L_80132D0C
    if (ctx->r2 == ctx->r1) {
        // 0x80132CE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132D0C;
    }
    // 0x80132CE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132CEC: beq         $v0, $at, L_80132D1C
    if (ctx->r2 == ctx->r1) {
        // 0x80132CF0: nop
    
            goto L_80132D1C;
    }
    // 0x80132CF0: nop

    // 0x80132CF4: b           L_80132D28
    // 0x80132CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D28;
    // 0x80132CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132CFC:
    // 0x80132CFC: jal         0x801325D4
    // 0x80132D00: nop

    mnBackupClearUpdateOptionMainMenu(rdram, ctx);
        goto after_6;
    // 0x80132D00: nop

    after_6:
    // 0x80132D04: b           L_80132D28
    // 0x80132D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D28;
    // 0x80132D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132D0C:
    // 0x80132D0C: jal         0x80132930
    // 0x80132D10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnBackupClearUpdateOptionConfirmMenu(rdram, ctx);
        goto after_7;
    // 0x80132D10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80132D14: b           L_80132D28
    // 0x80132D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D28;
    // 0x80132D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132D1C:
    // 0x80132D1C: jal         0x80132930
    // 0x80132D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnBackupClearUpdateOptionConfirmMenu(rdram, ctx);
        goto after_8;
    // 0x80132D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
L_80132D24:
    // 0x80132D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132D28:
    // 0x80132D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D2C: jr          $ra
    // 0x80132D30: nop

    return;
    // 0x80132D30: nop

;}
RECOMP_FUNC void mnVSRecordCheckHaveFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801326F0: beq         $a0, $at, L_8013278C
    if (ctx->r4 == ctx->r1) {
        // 0x801326F4: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_8013278C;
    }
    // 0x801326F4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801326F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801326FC: beq         $a0, $at, L_80132768
    if (ctx->r4 == ctx->r1) {
        // 0x80132700: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132768;
    }
    // 0x80132700: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132704: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80132708: beq         $a0, $at, L_80132744
    if (ctx->r4 == ctx->r1) {
        // 0x8013270C: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80132744;
    }
    // 0x8013270C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132710: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80132714: bne         $a0, $at, L_801327B0
    if (ctx->r4 != ctx->r1) {
        // 0x80132718: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801327B0;
    }
    // 0x80132718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013271C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132720: lhu         $t6, 0x6CBC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X6CBC);
    // 0x80132724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80132728: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8013272C: beq         $t7, $zero, L_8013273C
    if (ctx->r15 == 0) {
        // 0x80132730: nop
    
            goto L_8013273C;
    }
    // 0x80132730: nop

    // 0x80132734: jr          $ra
    // 0x80132738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013273C:
    // 0x8013273C: jr          $ra
    // 0x80132740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132744:
    // 0x80132744: lhu         $t8, 0x6CBC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X6CBC);
    // 0x80132748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013274C: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80132750: beq         $t9, $zero, L_80132760
    if (ctx->r25 == 0) {
        // 0x80132754: nop
    
            goto L_80132760;
    }
    // 0x80132754: nop

    // 0x80132758: jr          $ra
    // 0x8013275C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013275C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132760:
    // 0x80132760: jr          $ra
    // 0x80132764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132768:
    // 0x80132768: lhu         $t0, 0x6CBC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X6CBC);
    // 0x8013276C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80132770: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80132774: beq         $t1, $zero, L_80132784
    if (ctx->r9 == 0) {
        // 0x80132778: nop
    
            goto L_80132784;
    }
    // 0x80132778: nop

    // 0x8013277C: jr          $ra
    // 0x80132780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132784:
    // 0x80132784: jr          $ra
    // 0x80132788: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132788: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013278C:
    // 0x8013278C: lhu         $t2, 0x6CBC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X6CBC);
    // 0x80132790: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80132794: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80132798: beq         $t3, $zero, L_801327A8
    if (ctx->r11 == 0) {
        // 0x8013279C: nop
    
            goto L_801327A8;
    }
    // 0x8013279C: nop

    // 0x801327A0: jr          $ra
    // 0x801327A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801327A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801327A8:
    // 0x801327A8: jr          $ra
    // 0x801327AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801327AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801327B0:
    // 0x801327B0: jr          $ra
    // 0x801327B4: nop

    return;
    // 0x801327B4: nop

;}
RECOMP_FUNC void mnPlayers1PGameUpdateFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013580C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80135810: addiu       $s0, $s0, -0x7118
    ctx->r16 = ADD32(ctx->r16, -0X7118);
    // 0x80135814: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80135818: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013581C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135820: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80135824: bne         $t6, $at, L_80135860
    if (ctx->r14 != ctx->r1) {
        // 0x80135828: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135860;
    }
    // 0x80135828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013582C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80135830: bne         $t7, $zero, L_80135860
    if (ctx->r15 != 0) {
        // 0x80135834: nop
    
            goto L_80135860;
    }
    // 0x80135834: nop

    // 0x80135838: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8013583C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80135840: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80135844: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
    // 0x80135848: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8013584C: jal         0x8013419C
    // 0x80135850: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_0;
    // 0x80135850: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    after_0:
    // 0x80135854: jal         0x80134B3C
    // 0x80135858: nop

    mnPlayers1PGameMakeFighterRecord(rdram, ctx);
        goto after_1;
    // 0x80135858: nop

    after_1:
    // 0x8013585C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135860:
    // 0x80135860: bne         $v0, $zero, L_801358A8
    if (ctx->r2 != 0) {
        // 0x80135864: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801358A8;
    }
    // 0x80135864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135868: jal         0x80134EC0
    // 0x8013586C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PGameGetFreeCostume(rdram, ctx);
        goto after_2;
    // 0x8013586C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x80135870: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80135874: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80135878: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x8013587C: jal         0x80135060
    // 0x80135880: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    mnPlayers1PGameMakeFighter(rdram, ctx);
        goto after_3;
    // 0x80135880: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80135884: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80135888: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    // 0x8013588C: jal         0x8013419C
    // 0x80135890: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_4;
    // 0x80135890: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_4:
    // 0x80135894: jal         0x80134B3C
    // 0x80135898: nop

    mnPlayers1PGameMakeFighterRecord(rdram, ctx);
        goto after_5;
    // 0x80135898: nop

    after_5:
    // 0x8013589C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801358A0: sw          $zero, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = 0;
    // 0x801358A4: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_801358A8:
    // 0x801358A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801358AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801358B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801358B4: jr          $ra
    // 0x801358B8: nop

    return;
    // 0x801358B8: nop

;}
RECOMP_FUNC void scAutoDemoChangeFocus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D624: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D628: lw          $v0, -0x1B14($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1B14);
    // 0x8018D62C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D634: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8018D638: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D63C: sw          $t6, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = ctx->r14;
    // 0x8018D640: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8018D644: beql        $v1, $zero, L_8018D660
    if (ctx->r3 == 0) {
        // 0x8018D648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D660;
    }
    goto skip_0;
    // 0x8018D648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D64C: jalr        $v1
    // 0x8018D650: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8018D650: nop

    after_0:
    // 0x8018D654: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D658: lw          $v0, -0x1B14($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1B14);
    // 0x8018D65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D660:
    // 0x8018D660: addiu       $t7, $v0, 0xC
    ctx->r15 = ADD32(ctx->r2, 0XC);
    // 0x8018D664: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D668: sw          $t7, -0x1B14($at)
    MEM_W(-0X1B14, ctx->r1) = ctx->r15;
    // 0x8018D66C: jr          $ra
    // 0x8018D670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8018D670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itHammerDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017634C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176350: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80176354: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80176358: addiu       $a3, $a3, 0x61C4
    ctx->r7 = ADD32(ctx->r7, 0X61C4);
    // 0x8017635C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80176360: jal         0x80173B24
    // 0x80176364: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80176364: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80176368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017636C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176370: jr          $ra
    // 0x80176374: nop

    return;
    // 0x80176374: nop

;}
RECOMP_FUNC void itLinkBombThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80186228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018622C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80186230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80186234: jal         0x80185CD4
    // 0x80186238: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itLinkBombCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x80186238: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8018623C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80186240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80186244: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80186248: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x8018624C: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80186250: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80186254: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80186258: jal         0x80172EC8
    // 0x8018625C: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018625C: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    after_1:
    // 0x80186260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80186268: jr          $ra
    // 0x8018626C: nop

    return;
    // 0x8018626C: nop

;}
RECOMP_FUNC void itNBumperGDisappearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BED4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017BED8: lw          $a1, 0x2C0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C0);
    // 0x8017BEDC: bne         $a1, $zero, L_8017BEEC
    if (ctx->r5 != 0) {
        // 0x8017BEE0: andi        $t6, $a1, 0x1
        ctx->r14 = ctx->r5 & 0X1;
            goto L_8017BEEC;
    }
    // 0x8017BEE0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8017BEE4: jr          $ra
    // 0x8017BEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8017BEE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017BEEC:
    // 0x8017BEEC: beql        $t6, $zero, L_8017BF0C
    if (ctx->r14 == 0) {
        // 0x8017BEF0: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_8017BF0C;
    }
    goto skip_0;
    // 0x8017BEF0: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017BEF4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017BEF8: lbu         $t7, 0x54($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X54);
    // 0x8017BEFC: xori        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 ^ 0X2;
    // 0x8017BF00: sb          $t8, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r24;
    // 0x8017BF04: lw          $a1, 0x2C0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C0);
    // 0x8017BF08: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
L_8017BF0C:
    // 0x8017BF0C: sw          $t9, 0x2C0($v1)
    MEM_W(0X2C0, ctx->r3) = ctx->r25;
    // 0x8017BF10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017BF14: jr          $ra
    // 0x8017BF18: nop

    return;
    // 0x8017BF18: nop

;}
RECOMP_FUNC void efManagerNessPKThunderTrailProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102768: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8010276C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80102770: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80102774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010277C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102780: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80102784: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80102788: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010278C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102790: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80102794: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80102798: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8010279C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801027A0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801027A4: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x801027A8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801027AC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801027B0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801027B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801027B8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801027BC: ori         $t2, $t2, 0x1E01
    ctx->r10 = ctx->r10 | 0X1E01;
    // 0x801027C0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801027C4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801027C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801027CC: jal         0x800143FC
    // 0x801027D0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x801027D0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x801027D4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801027D8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801027DC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801027E0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801027E4: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801027E8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801027EC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801027F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801027F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801027F8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801027FC: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80102800: ori         $t7, $t7, 0x4340
    ctx->r15 = ctx->r15 | 0X4340;
    // 0x80102804: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80102808: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8010280C: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80102810: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102814: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102818: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8010281C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80102820: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x80102824: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102828: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8010282C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80102830: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80102834: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010283C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102840: jr          $ra
    // 0x80102844: nop

    return;
    // 0x80102844: nop

;}
RECOMP_FUNC void ftPhysicsClampAirVelXStickDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D904C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9054: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800D9058: lw          $a3, 0x50($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X50);
    // 0x800D905C: jal         0x800D8FC8
    // 0x800D9060: lw          $a2, 0x4C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4C);
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_0;
    // 0x800D9060: lw          $a2, 0x4C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4C);
    after_0:
    // 0x800D9064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D906C: jr          $ra
    // 0x800D9070: nop

    return;
    // 0x800D9070: nop

;}
RECOMP_FUNC void mnPlayersVSMakeReadyCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138D4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80138D50: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80138D54: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80138D58: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80138D5C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80138D60: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80138D64: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80138D68: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80138D6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138D70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138D74: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138D78: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138D7C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80138D80: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80138D84: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80138D88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80138D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80138D90: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80138D94: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80138D98: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80138D9C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80138DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138DA4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80138DA8: jal         0x8000B93C
    // 0x80138DAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80138DAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80138DB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80138DB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80138DB8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80138DBC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138DC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138DC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80138DC8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80138DCC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80138DD0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80138DD4: jal         0x80007080
    // 0x80138DD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80138DD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80138DDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80138DE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80138DE4: jr          $ra
    // 0x80138DE8: nop

    return;
    // 0x80138DE8: nop

;}
RECOMP_FUNC void ftHammerCheckMotionWaitOrWalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F37FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800F3800: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    // 0x800F3804: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x800F3808: beq         $v1, $at, L_800F3818
    if (ctx->r3 == ctx->r1) {
        // 0x800F380C: addiu       $at, $zero, 0x85
        ctx->r1 = ADD32(0, 0X85);
            goto L_800F3818;
    }
    // 0x800F380C: addiu       $at, $zero, 0x85
    ctx->r1 = ADD32(0, 0X85);
    // 0x800F3810: bne         $v1, $at, L_800F3820
    if (ctx->r3 != ctx->r1) {
        // 0x800F3814: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F3820;
    }
    // 0x800F3814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3818:
    // 0x800F3818: jr          $ra
    // 0x800F381C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F381C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3820:
    // 0x800F3820: jr          $ra
    // 0x800F3824: nop

    return;
    // 0x800F3824: nop

;}
RECOMP_FUNC void ftCommonThrownProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AF98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014AF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AFA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014AFA4: lw          $a1, 0x844($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X844);
    // 0x8014AFA8: jal         0x800E80C4
    // 0x8014AFAC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamSetThrowParams(rdram, ctx);
        goto after_0;
    // 0x8014AFAC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014AFB0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8014AFB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014AFB8: lw          $t6, -0x3080($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3080);
    // 0x8014AFBC: sw          $t6, 0xB40($a0)
    MEM_W(0XB40, ctx->r4) = ctx->r14;
    // 0x8014AFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014AFC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014AFC8: jr          $ra
    // 0x8014AFCC: nop

    return;
    // 0x8014AFCC: nop

;}
RECOMP_FUNC void ftBossCommonSetDefaultLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80158638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015863C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80158640: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80158644: jal         0x800FC8EC
    // 0x80158648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mpCollisionGetLineCountType(rdram, ctx);
        goto after_0;
    // 0x80158648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8015864C: bnel        $v0, $zero, L_80158678
    if (ctx->r2 != 0) {
        // 0x80158650: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_80158678;
    }
    goto skip_0;
    // 0x80158650: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_0:
    // 0x80158654: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x80158658: addiu       $s0, $s0, -0x3900
    ctx->r16 = ADD32(ctx->r16, -0X3900);
L_8015865C:
    // 0x8015865C: jal         0x80023624
    // 0x80158660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80158660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80158664: jal         0x800A3040
    // 0x80158668: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x80158668: nop

    after_2:
    // 0x8015866C: b           L_8015865C
    // 0x80158670: nop

        goto L_8015865C;
    // 0x80158670: nop

    // 0x80158674: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_80158678:
    // 0x80158678: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8015867C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80158680: lw          $a2, 0xADC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XADC);
    // 0x80158684: jal         0x800FC900
    // 0x80158688: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    mpCollisionGetLineIDsTypeCount(rdram, ctx);
        goto after_3;
    // 0x80158688: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_3:
    // 0x8015868C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80158690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80158694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80158698: jr          $ra
    // 0x8015869C: nop

    return;
    // 0x8015869C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingBackTo1PMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801357CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801357D0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801357D4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801357D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801357DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801357E0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801357E4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x801357E8: jal         0x801375D8
    // 0x801357EC: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    mnPlayers1PTrainingSetSceneData(rdram, ctx);
        goto after_0;
    // 0x801357EC: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_0:
    // 0x801357F0: jal         0x80020A74
    // 0x801357F4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_1;
    // 0x801357F4: nop

    after_1:
    // 0x801357F8: jal         0x800266A0
    // 0x801357FC: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x801357FC: nop

    after_2:
    // 0x80135800: jal         0x80005C74
    // 0x80135804: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80135804: nop

    after_3:
    // 0x80135808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013580C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135810: jr          $ra
    // 0x80135814: nop

    return;
    // 0x80135814: nop

;}
RECOMP_FUNC void mvOpeningSectorMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132500: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132504: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132508: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013250C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132510: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80132514: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132518: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8013251C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132520: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132524: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132528: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013252C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132530: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132534: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132538: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013253C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132540: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132544: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132548: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013254C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132550: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132558: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013255C: jal         0x8000B93C
    // 0x80132560: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132560: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132564: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132568: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013256C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132570: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132574: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132578: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013257C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132580: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132584: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132588: jal         0x80007080
    // 0x8013258C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013258C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132590: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132594: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132598: jr          $ra
    // 0x8013259C: nop

    return;
    // 0x8013259C: nop

;}
RECOMP_FUNC void sc1PTrainingModeLoadSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DD10: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8018DD14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DD18: addiu       $a0, $a0, 0xFE
    ctx->r4 = ADD32(ctx->r4, 0XFE);
    // 0x8018DD1C: jal         0x800CDBD0
    // 0x8018DD20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018DD20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018DD24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DD28: jal         0x80004980
    // 0x8018DD2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018DD2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018DD30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018DD34: jal         0x800CDC88
    // 0x8018DD38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018DD38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018DD3C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DD40: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8018DD44: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018DD48: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8018DD4C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8018DD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DD54: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018DD58: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8018DD5C: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x8018DD60: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x8018DD64: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8018DD68: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x8018DD6C: addiu       $t8, $t8, 0x20
    ctx->r24 = ADD32(ctx->r24, 0X20);
    // 0x8018DD70: addiu       $t0, $t0, 0xBC
    ctx->r8 = ADD32(ctx->r8, 0XBC);
    // 0x8018DD74: addiu       $t2, $t2, 0x13C
    ctx->r10 = ADD32(ctx->r10, 0X13C);
    // 0x8018DD78: addiu       $t4, $t4, 0x10C
    ctx->r12 = ADD32(ctx->r12, 0X10C);
    // 0x8018DD7C: addiu       $t6, $t6, 0x1B8
    ctx->r14 = ADD32(ctx->r14, 0X1B8);
    // 0x8018DD80: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8018DD84: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8018DD88: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8018DD8C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8018DD90: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8018DD94: sw          $t9, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r25;
    // 0x8018DD98: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x8018DD9C: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x8018DDA0: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x8018DDA4: sw          $t7, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r15;
    // 0x8018DDA8: jr          $ra
    // 0x8018DDAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018DDAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PTrainingSetCursorPuckOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134C64: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x80134C68: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134C6C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80134C70: addiu       $a1, $a1, -0x7AA8
    ctx->r5 = ADD32(ctx->r5, -0X7AA8);
    // 0x80134C74: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80134C78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134C7C: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80134C80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134C84: mflo        $t6
    ctx->r14 = lo;
    // 0x80134C88: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x80134C8C: lw          $t7, 0x7C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C);
    // 0x80134C90: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134C94: mflo        $t8
    ctx->r24 = lo;
    // 0x80134C98: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x80134C9C: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80134CA0: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80134CA4: lwc1        $f4, 0x58($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X58);
    // 0x80134CA8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80134CAC: swc1        $f8, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f8.u32l;
    // 0x80134CB0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80134CB4: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80134CB8: lwc1        $f10, 0x5C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x80134CBC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80134CC0: jr          $ra
    // 0x80134CC4: swc1        $f18, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80134CC4: swc1        $f18, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void syMatrixRotRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001BF24: lwc1        $f0, -0x1C48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C48);
    // 0x8001BF28: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BF2C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001BF30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BF34: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001BF38: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8001BF3C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BF40: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001BF44: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8001BF48: addiu       $t4, $t4, -0x46B0
    ctx->r12 = ADD32(ctx->r12, -0X46B0);
    // 0x8001BF4C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001BF50: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001BF54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001BF58: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001BF5C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8001BF60: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001BF64: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001BF68: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8001BF6C: andi        $t7, $a2, 0x7FF
    ctx->r15 = ctx->r6 & 0X7FF;
    // 0x8001BF70: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001BF74: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001BF78: andi        $t6, $a2, 0x800
    ctx->r14 = ctx->r6 & 0X800;
    // 0x8001BF7C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8001BF80: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8001BF84: beq         $t6, $zero, L_8001BF90
    if (ctx->r14 == 0) {
        // 0x8001BF88: lhu         $a3, 0x0($t9)
        ctx->r7 = MEM_HU(ctx->r25, 0X0);
            goto L_8001BF90;
    }
    // 0x8001BF88: lhu         $a3, 0x0($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X0);
    // 0x8001BF8C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_8001BF90:
    // 0x8001BF90: addiu       $v0, $a2, 0x400
    ctx->r2 = ADD32(ctx->r6, 0X400);
    // 0x8001BF94: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8001BF98: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001BF9C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001BFA0: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8001BFA4: beq         $t6, $zero, L_8001BFB0
    if (ctx->r14 == 0) {
        // 0x8001BFA8: lhu         $a1, 0x0($t9)
        ctx->r5 = MEM_HU(ctx->r25, 0X0);
            goto L_8001BFB0;
    }
    // 0x8001BFA8: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x8001BFAC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8001BFB0:
    // 0x8001BFB0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001BFB4: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x8001BFB8: andi        $t8, $t0, 0x7FF
    ctx->r24 = ctx->r8 & 0X7FF;
    // 0x8001BFBC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001BFC0: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001BFC4: andi        $t7, $t0, 0x800
    ctx->r15 = ctx->r8 & 0X800;
    // 0x8001BFC8: beq         $t7, $zero, L_8001BFD4
    if (ctx->r15 == 0) {
        // 0x8001BFCC: lhu         $a2, 0x0($t6)
        ctx->r6 = MEM_HU(ctx->r14, 0X0);
            goto L_8001BFD4;
    }
    // 0x8001BFCC: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x8001BFD0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_8001BFD4:
    // 0x8001BFD4: addiu       $v0, $t0, 0x400
    ctx->r2 = ADD32(ctx->r8, 0X400);
    // 0x8001BFD8: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x8001BFDC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001BFE0: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001BFE4: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x8001BFE8: beq         $t7, $zero, L_8001BFF4
    if (ctx->r15 == 0) {
        // 0x8001BFEC: lhu         $v1, 0x0($t6)
        ctx->r3 = MEM_HU(ctx->r14, 0X0);
            goto L_8001BFF4;
    }
    // 0x8001BFEC: lhu         $v1, 0x0($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X0);
    // 0x8001BFF0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8001BFF4:
    // 0x8001BFF4: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x8001BFF8: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8001BFFC: andi        $t9, $t2, 0x7FF
    ctx->r25 = ctx->r10 & 0X7FF;
    // 0x8001C000: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C004: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C008: andi        $t8, $t2, 0x800
    ctx->r24 = ctx->r10 & 0X800;
    // 0x8001C00C: beq         $t8, $zero, L_8001C018
    if (ctx->r24 == 0) {
        // 0x8001C010: lhu         $v0, 0x0($t7)
        ctx->r2 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C018;
    }
    // 0x8001C010: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C014: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8001C018:
    // 0x8001C018: addiu       $t0, $t2, 0x400
    ctx->r8 = ADD32(ctx->r10, 0X400);
    // 0x8001C01C: andi        $t9, $t0, 0x7FF
    ctx->r25 = ctx->r8 & 0X7FF;
    // 0x8001C020: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C024: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C028: andi        $t8, $t0, 0x800
    ctx->r24 = ctx->r8 & 0X800;
    // 0x8001C02C: beq         $t8, $zero, L_8001C038
    if (ctx->r24 == 0) {
        // 0x8001C030: lhu         $t3, 0x0($t7)
        ctx->r11 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C038;
    }
    // 0x8001C030: lhu         $t3, 0x0($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C034: negu        $t3, $t3
    ctx->r11 = SUB32(0, ctx->r11);
L_8001C038:
    // 0x8001C038: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C03C: lui         $s0, 0xFFFF
    ctx->r16 = S32(0XFFFF << 16);
    // 0x8001C040: negu        $t2, $a2
    ctx->r10 = SUB32(0, ctx->r6);
    // 0x8001C044: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001C048: mflo        $t0
    ctx->r8 = lo;
    // 0x8001C04C: sra         $t0, $t0, 14
    ctx->r8 = S32(SIGNED(ctx->r8) >> 14);
    // 0x8001C050: and         $t9, $t0, $s0
    ctx->r25 = ctx->r8 & ctx->r16;
    // 0x8001C054: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C058: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8001C05C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C060: sra         $t1, $t1, 14
    ctx->r9 = S32(SIGNED(ctx->r9) >> 14);
    // 0x8001C064: srl         $t6, $t1, 16
    ctx->r14 = S32(U32(ctx->r9) >> 16);
    // 0x8001C068: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C06C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8001C070: andi        $t9, $t1, 0xFFFF
    ctx->r25 = ctx->r9 & 0XFFFF;
    // 0x8001C074: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8001C078: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C07C: and         $t7, $t2, $s0
    ctx->r15 = ctx->r10 & ctx->r16;
    // 0x8001C080: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8001C084: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8001C088: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8001C08C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8001C090: mflo        $t4
    ctx->r12 = lo;
    // 0x8001C094: sra         $t4, $t4, 15
    ctx->r12 = S32(SIGNED(ctx->r12) >> 15);
    // 0x8001C098: nop

    // 0x8001C09C: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C0A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C0A4: sra         $t6, $t9, 14
    ctx->r14 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C0A8: nop

    // 0x8001C0AC: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C0B0: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C0B4: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C0B8: subu        $t5, $t6, $t8
    ctx->r13 = SUB32(ctx->r14, ctx->r24);
    // 0x8001C0BC: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C0C0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C0C4: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C0C8: nop

    // 0x8001C0CC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C0D0: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C0D4: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C0D8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001C0DC: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C0E0: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8001C0E4: and         $t7, $t5, $s0
    ctx->r15 = ctx->r13 & ctx->r16;
    // 0x8001C0E8: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8001C0EC: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8001C0F0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001C0F4: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8001C0F8: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001C0FC: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8001C100: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8001C104: mflo        $t0
    ctx->r8 = lo;
    // 0x8001C108: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C10C: sra         $t0, $t0, 14
    ctx->r8 = S32(SIGNED(ctx->r8) >> 14);
    // 0x8001C110: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C114: and         $t7, $t0, $s0
    ctx->r15 = ctx->r8 & ctx->r16;
    // 0x8001C118: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8001C11C: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x8001C120: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8001C124: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8001C128: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8001C12C: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8001C130: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C134: sra         $t1, $t1, 15
    ctx->r9 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8001C138: nop

    // 0x8001C13C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C140: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C144: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C148: nop

    // 0x8001C14C: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C150: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C154: sra         $t9, $t7, 14
    ctx->r25 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C158: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C15C: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C160: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C164: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C168: and         $t6, $t4, $s0
    ctx->r14 = ctx->r12 & ctx->r16;
    // 0x8001C16C: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C170: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C174: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x8001C178: subu        $t2, $t7, $t9
    ctx->r10 = SUB32(ctx->r15, ctx->r25);
    // 0x8001C17C: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C180: srl         $t8, $t2, 16
    ctx->r24 = S32(U32(ctx->r10) >> 16);
    // 0x8001C184: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001C188: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x8001C18C: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8001C190: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C194: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x8001C198: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001C19C: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8001C1A0: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x8001C1A4: mflo        $v0
    ctx->r2 = lo;
    // 0x8001C1A8: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8001C1AC: and         $t7, $v0, $s0
    ctx->r15 = ctx->r2 & ctx->r16;
    // 0x8001C1B0: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001C1B4: sw          $t7, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r15;
    // 0x8001C1B8: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x8001C1BC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001C1C0: jr          $ra
    // 0x8001C1C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001C1C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void efManagerKirbyCutterDownMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102494: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010249C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801024A0: jal         0x800FDB1C
    // 0x801024A4: addiu       $a0, $a0, -0x1C5C
    ctx->r4 = ADD32(ctx->r4, -0X1C5C);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x801024A4: addiu       $a0, $a0, -0x1C5C
    ctx->r4 = ADD32(ctx->r4, -0X1C5C);
    after_0:
    // 0x801024A8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801024AC: bne         $v0, $zero, L_801024BC
    if (ctx->r2 != 0) {
        // 0x801024B0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_801024BC;
    }
    // 0x801024B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801024B4: b           L_801024F8
    // 0x801024B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801024F8;
    // 0x801024B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801024BC:
    // 0x801024BC: lw          $a2, 0x84($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X84);
    // 0x801024C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801024C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801024C8: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x801024CC: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x801024D0: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x801024D4: lw          $t6, 0x8E8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8E8);
    // 0x801024D8: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x801024DC: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x801024E0: lwc1        $f8, 0xA00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA00);
    // 0x801024E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801024E8: nop

    // 0x801024EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801024F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801024F4: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
L_801024F8:
    // 0x801024F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801024FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102500: jr          $ra
    // 0x80102504: nop

    return;
    // 0x80102504: nop

;}
RECOMP_FUNC void ftMainGetBumperDamageAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E3DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3DD8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E3DDC: addiu       $at, $zero, 0x16A
    ctx->r1 = ADD32(0, 0X16A);
    // 0x800E3DE0: lw          $t6, 0x7F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7F4);
    // 0x800E3DE4: bnel        $t6, $at, L_800E3EB0
    if (ctx->r14 != ctx->r1) {
        // 0x800E3DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E3EB0;
    }
    goto skip_0;
    // 0x800E3DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E3DEC: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x800E3DF0: lw          $t8, 0x74($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X74);
    // 0x800E3DF4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800E3DF8: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800E3DFC: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E3E00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E3E04: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800E3E08: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800E3E0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E3E10: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800E3E14: nop

    // 0x800E3E18: bc1fl       L_800E3E2C
    if (!c1cs) {
        // 0x800E3E1C: sw          $t0, 0x7FC($v0)
        MEM_W(0X7FC, ctx->r2) = ctx->r8;
            goto L_800E3E2C;
    }
    goto skip_1;
    // 0x800E3E1C: sw          $t0, 0x7FC($v0)
    MEM_W(0X7FC, ctx->r2) = ctx->r8;
    skip_1:
    // 0x800E3E20: b           L_800E3E2C
    // 0x800E3E24: sw          $t9, 0x7FC($v0)
    MEM_W(0X7FC, ctx->r2) = ctx->r25;
        goto L_800E3E2C;
    // 0x800E3E24: sw          $t9, 0x7FC($v0)
    MEM_W(0X7FC, ctx->r2) = ctx->r25;
    // 0x800E3E28: sw          $t0, 0x7FC($v0)
    MEM_W(0X7FC, ctx->r2) = ctx->r8;
L_800E3E2C:
    // 0x800E3E2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800E3E30: nop

    // 0x800E3E34: bc1fl       L_800E3E44
    if (!c1cs) {
        // 0x800E3E38: lw          $t1, 0x74($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X74);
            goto L_800E3E44;
    }
    goto skip_2;
    // 0x800E3E38: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    skip_2:
    // 0x800E3E3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800E3E40: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
L_800E3E44:
    // 0x800E3E44: lwc1        $f16, 0xB4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x800E3E48: lw          $t2, 0x74($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X74);
    // 0x800E3E4C: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800E3E50: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800E3E54: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800E3E58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800E3E5C: bc1f        L_800E3E74
    if (!c1cs) {
        // 0x800E3E60: sub.s       $f2, $f18, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
            goto L_800E3E74;
    }
    // 0x800E3E60: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800E3E64: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800E3E68: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800E3E6C: b           L_800E3EAC
    // 0x800E3E70: sw          $t4, 0x7F4($v0)
    MEM_W(0X7F4, ctx->r2) = ctx->r12;
        goto L_800E3EAC;
    // 0x800E3E70: sw          $t4, 0x7F4($v0)
    MEM_W(0X7F4, ctx->r2) = ctx->r12;
L_800E3E74:
    // 0x800E3E74: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E3E78: jal         0x80018514
    // 0x800E3E7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    syUtilsArcTan(rdram, ctx);
        goto after_0;
    // 0x800E3E7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E3E80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E3E84: lwc1        $f8, -0x1A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A0);
    // 0x800E3E88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800E3E8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E3E90: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800E3E94: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E3E98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800E3E9C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800E3EA0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800E3EA4: nop

    // 0x800E3EA8: sw          $t6, 0x7F4($v0)
    MEM_W(0X7F4, ctx->r2) = ctx->r14;
L_800E3EAC:
    // 0x800E3EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E3EB0:
    // 0x800E3EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E3EB4: jr          $ra
    // 0x800E3EB8: nop

    return;
    // 0x800E3EB8: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154A8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80154A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154A94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80154A98: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80154A9C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80154AA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80154AA4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80154AA8: jal         0x800DE798
    // 0x80154AAC: addiu       $a1, $a1, 0x49B0
    ctx->r5 = ADD32(ctx->r5, 0X49B0);
    mpCommonCheckFighterPassCliff(rdram, ctx);
        goto after_0;
    // 0x80154AAC: addiu       $a1, $a1, 0x49B0
    ctx->r5 = ADD32(ctx->r5, 0X49B0);
    after_0:
    // 0x80154AB0: beql        $v0, $zero, L_80154B34
    if (ctx->r2 == 0) {
        // 0x80154AB4: lw          $t8, 0x74($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X74);
            goto L_80154B34;
    }
    goto skip_0;
    // 0x80154AB4: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    skip_0:
    // 0x80154AB8: lhu         $t6, 0xD2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XD2);
    // 0x80154ABC: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80154AC0: andi        $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 & 0X3000;
    // 0x80154AC4: beq         $t7, $zero, L_80154ADC
    if (ctx->r15 == 0) {
        // 0x80154AC8: nop
    
            goto L_80154ADC;
    }
    // 0x80154AC8: nop

    // 0x80154ACC: jal         0x80144C24
    // 0x80154AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80154AD4: b           L_80154CAC
    // 0x80154AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80154CAC;
    // 0x80154AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80154ADC:
    // 0x80154ADC: jal         0x800191FC
    // 0x80154AE0: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_2;
    // 0x80154AE0: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_2:
    // 0x80154AE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154AE8: lwc1        $f4, -0x3A14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A14);
    // 0x80154AEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80154AF0: nop

    // 0x80154AF4: bc1f        L_80154B20
    if (!c1cs) {
        // 0x80154AF8: nop
    
            goto L_80154B20;
    }
    // 0x80154AF8: nop

    // 0x80154AFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80154B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80154B04: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80154B08: jal         0x800DEE98
    // 0x80154B0C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_3;
    // 0x80154B0C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80154B10: jal         0x80144498
    // 0x80154B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_4;
    // 0x80154B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80154B18: b           L_80154CAC
    // 0x80154B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80154CAC;
    // 0x80154B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80154B20:
    // 0x80154B20: jal         0x80154CBC
    // 0x80154B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftNessSpecialAirHiJibakuSwitchStatusGround(rdram, ctx);
        goto after_5;
    // 0x80154B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80154B28: b           L_80154CAC
    // 0x80154B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80154CAC;
    // 0x80154B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154B30: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
L_80154B34:
    // 0x80154B34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80154B38: addiu       $a3, $s0, 0x10C
    ctx->r7 = ADD32(ctx->r16, 0X10C);
    // 0x80154B3C: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80154B40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80154B44: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80154B48: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80154B4C: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80154B50: lwc1        $f8, 0x20($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X20);
    // 0x80154B54: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80154B58: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80154B5C: lhu         $t0, 0xCE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XCE);
    // 0x80154B60: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80154B64: beql        $t1, $zero, L_80154BB4
    if (ctx->r9 == 0) {
        // 0x80154B68: lhu         $v0, 0xCE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XCE);
            goto L_80154BB4;
    }
    goto skip_1;
    // 0x80154B68: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
    skip_1:
    // 0x80154B6C: jal         0x800191FC
    // 0x80154B70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_6;
    // 0x80154B70: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x80154B74: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154B78: lwc1        $f10, -0x3A10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A10);
    // 0x80154B7C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80154B80: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154B84: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80154B88: nop

    // 0x80154B8C: bc1fl       L_80154BB4
    if (!c1cs) {
        // 0x80154B90: lhu         $v0, 0xCE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XCE);
            goto L_80154BB4;
    }
    goto skip_2;
    // 0x80154B90: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
    skip_2:
    // 0x80154B94: lwc1        $f18, 0xB0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x80154B98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80154B9C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80154BA0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80154BA4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80154BA8: jal         0x80155114
    // 0x80154BAC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    ftNessSpecialAirHiJibakuBoundSetStatus(rdram, ctx);
        goto after_7;
    // 0x80154BAC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80154BB0: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
L_80154BB4:
    // 0x80154BB4: addiu       $a3, $s0, 0x120
    ctx->r7 = ADD32(ctx->r16, 0X120);
    // 0x80154BB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80154BBC: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80154BC0: beq         $t2, $zero, L_80154C30
    if (ctx->r10 == 0) {
        // 0x80154BC4: addiu       $a1, $s0, 0x48
        ctx->r5 = ADD32(ctx->r16, 0X48);
            goto L_80154C30;
    }
    // 0x80154BC4: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80154BC8: jal         0x800191FC
    // 0x80154BCC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_8;
    // 0x80154BCC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_8:
    // 0x80154BD0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154BD4: lwc1        $f6, -0x3A0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A0C);
    // 0x80154BD8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80154BDC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80154BE0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80154BE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80154BE8: bc1f        L_80154C24
    if (!c1cs) {
        // 0x80154BEC: nop
    
            goto L_80154C24;
    }
    // 0x80154BEC: nop

    // 0x80154BF0: lwc1        $f10, 0xBC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x80154BF4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154BF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80154BFC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80154C00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80154C04: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80154C08: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80154C0C: lwc1        $f4, 0xB4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80154C10: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80154C14: jal         0x80155114
    // 0x80154C18: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    ftNessSpecialAirHiJibakuBoundSetStatus(rdram, ctx);
        goto after_9;
    // 0x80154C18: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80154C1C: b           L_80154C30
    // 0x80154C20: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
        goto L_80154C30;
    // 0x80154C20: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
L_80154C24:
    // 0x80154C24: jal         0x80154598
    // 0x80154C28: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    ftNessSpecialHiCollideWallPhysics(rdram, ctx);
        goto after_10;
    // 0x80154C28: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_10:
    // 0x80154C2C: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
L_80154C30:
    // 0x80154C30: andi        $t3, $v0, 0x20
    ctx->r11 = ctx->r2 & 0X20;
    // 0x80154C34: beq         $t3, $zero, L_80154CA8
    if (ctx->r11 == 0) {
        // 0x80154C38: addiu       $a3, $s0, 0x134
        ctx->r7 = ADD32(ctx->r16, 0X134);
            goto L_80154CA8;
    }
    // 0x80154C38: addiu       $a3, $s0, 0x134
    ctx->r7 = ADD32(ctx->r16, 0X134);
    // 0x80154C3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80154C40: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80154C44: jal         0x800191FC
    // 0x80154C48: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_11;
    // 0x80154C48: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_11:
    // 0x80154C4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154C50: lwc1        $f8, -0x3A08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A08);
    // 0x80154C54: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80154C58: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80154C5C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80154C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80154C64: bc1f        L_80154CA0
    if (!c1cs) {
        // 0x80154C68: nop
    
            goto L_80154CA0;
    }
    // 0x80154C68: nop

    // 0x80154C6C: lwc1        $f16, 0xBC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x80154C70: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80154C78: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80154C7C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80154C80: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80154C84: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80154C88: lwc1        $f6, 0xB4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80154C8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80154C90: jal         0x80155114
    // 0x80154C94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    ftNessSpecialAirHiJibakuBoundSetStatus(rdram, ctx);
        goto after_12;
    // 0x80154C94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x80154C98: b           L_80154CAC
    // 0x80154C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80154CAC;
    // 0x80154C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80154CA0:
    // 0x80154CA0: jal         0x80154598
    // 0x80154CA4: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    ftNessSpecialHiCollideWallPhysics(rdram, ctx);
        goto after_13;
    // 0x80154CA4: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_13:
L_80154CA8:
    // 0x80154CA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80154CAC:
    // 0x80154CAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80154CB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80154CB4: jr          $ra
    // 0x80154CB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80154CB8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftComputerCheckDetectTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EC8: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x80132ECC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80132ED0: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80132ED4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80132ED8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80132EDC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80132EE0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80132EE4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80132EE8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80132EEC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80132EF0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80132EF4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80132EF8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80132EFC: sw          $a1, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r5;
    // 0x80132F00: lw          $t6, 0x238($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X238);
    // 0x80132F04: addiu       $s1, $s1, 0x50E8
    ctx->r17 = ADD32(ctx->r17, 0X50E8);
    // 0x80132F08: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80132F0C: sw          $t6, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r14;
    // 0x80132F10: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80132F14: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80132F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80132F1C: bnel        $t8, $at, L_80132F4C
    if (ctx->r24 != ctx->r1) {
        // 0x80132F20: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80132F4C;
    }
    goto skip_0;
    // 0x80132F20: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80132F24: lw          $a0, 0xEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XEC);
    // 0x80132F28: bltzl       $a0, L_80132F4C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80132F2C: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80132F4C;
    }
    goto skip_1;
    // 0x80132F2C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80132F30: jal         0x800FCA18
    // 0x80132F34: nop

    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_0;
    // 0x80132F34: nop

    after_0:
    // 0x80132F38: beql        $v0, $zero, L_80132F4C
    if (ctx->r2 == 0) {
        // 0x80132F3C: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80132F4C;
    }
    goto skip_2;
    // 0x80132F3C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80132F40: b           L_80133FCC
    // 0x80132F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133FCC;
    // 0x80132F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132F48: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_80132F4C:
    // 0x80132F4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132F50: lbu         $t3, 0x1($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X1);
    // 0x80132F54: bnel        $t3, $at, L_80133040
    if (ctx->r11 != ctx->r1) {
        // 0x80132F58: lw          $v0, 0x8E8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8E8);
            goto L_80133040;
    }
    goto skip_3;
    // 0x80132F58: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    skip_3:
    // 0x80132F5C: lw          $t4, 0x14C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C);
    // 0x80132F60: beql        $t4, $zero, L_80133040
    if (ctx->r12 == 0) {
        // 0x80132F64: lw          $v0, 0x8E8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8E8);
            goto L_80133040;
    }
    goto skip_4;
    // 0x80132F64: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    skip_4:
    // 0x80132F68: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80132F6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80132F70: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132F74: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x80132F78: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80132F7C: nop

    // 0x80132F80: bc1fl       L_80132FA8
    if (!c1cs) {
        // 0x80132F84: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80132FA8;
    }
    goto skip_5;
    // 0x80132F84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_5:
    // 0x80132F88: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132F8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132F90: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132F94: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80132F98: lwc1        $f24, 0x1C($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80132F9C: b           L_80132FB8
    // 0x80132FA0: add.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl + ctx->f8.fl;
        goto L_80132FB8;
    // 0x80132FA0: add.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x80132FA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80132FA8:
    // 0x80132FA8: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132FAC: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80132FB0: lwc1        $f20, 0x1C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80132FB4: add.s       $f24, $f20, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f20.fl + ctx->f16.fl;
L_80132FB8:
    // 0x80132FB8: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80132FBC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80132FC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80132FC4: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80132FC8: lw          $t5, 0x8E8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132FCC: lwc1        $f4, 0x1C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80132FD0: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80132FD4: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80132FD8: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80132FDC: lw          $t6, 0x8E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132FE0: lwc1        $f10, 0x1C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80132FE4: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80132FE8: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80132FEC: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80132FF0: nop

    // 0x80132FF4: bc1fl       L_80133040
    if (!c1cs) {
        // 0x80132FF8: lw          $v0, 0x8E8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8E8);
            goto L_80133040;
    }
    goto skip_6;
    // 0x80132FF8: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    skip_6:
L_80132FFC:
    // 0x80132FFC: jal         0x800F8FFC
    // 0x80133000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_1;
    // 0x80133000: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80133004: bne         $v0, $zero, L_80133014
    if (ctx->r2 != 0) {
        // 0x80133008: lwc1        $f4, 0x90($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
            goto L_80133014;
    }
    // 0x80133008: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8013300C: b           L_80133FCC
    // 0x80133010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133FCC;
    // 0x80133010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133014:
    // 0x80133014: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80133018: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x8013301C: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x80133020: lwc1        $f10, 0x1C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80133024: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80133028: add.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8013302C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80133030: nop

    // 0x80133034: bc1t        L_80132FFC
    if (c1cs) {
        // 0x80133038: nop
    
            goto L_80132FFC;
    }
    // 0x80133038: nop

    // 0x8013303C: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
L_80133040:
    // 0x80133040: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80133044: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80133048: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8013304C: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x80133050: swc1        $f18, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->f18.u32l;
    // 0x80133054: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80133058: jal         0x80018948
    // 0x8013305C: swc1        $f4, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x8013305C: swc1        $f4, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80133060: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x80133064: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80133068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013306C: subu        $t3, $t9, $t8
    ctx->r11 = SUB32(ctx->r25, ctx->r24);
    // 0x80133070: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80133074: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80133078: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8013307C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133080: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133084: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133088: lwc1        $f4, -0x4468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4468);
    // 0x8013308C: lw          $t4, 0x1B0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B0);
    // 0x80133090: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x80133094: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80133098: lwc1        $f6, 0x260($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X260);
    // 0x8013309C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801330A0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801330A4: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801330A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801330AC: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801330B0: add.s       $f2, $f10, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x801330B4: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801330B8: swc1        $f16, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f16.u32l;
    // 0x801330BC: lwc1        $f8, 0x264($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X264);
    // 0x801330C0: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801330C4: swc1        $f18, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->f18.u32l;
    // 0x801330C8: lw          $v0, 0x8E8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8E8);
    // 0x801330CC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801330D0: swc1        $f4, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f4.u32l;
    // 0x801330D4: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801330D8: swc1        $f10, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->f10.u32l;
    // 0x801330DC: lwc1        $f6, 0x48($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X48);
    // 0x801330E0: swc1        $f6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->f6.u32l;
    // 0x801330E4: lwc1        $f16, 0x4C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4C);
    // 0x801330E8: swc1        $f16, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->f16.u32l;
    // 0x801330EC: lw          $v1, 0x9C8($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X9C8);
    // 0x801330F0: lwc1        $f8, 0x5C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801330F4: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x801330F8: swc1        $f18, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->f18.u32l;
    // 0x801330FC: lwc1        $f4, 0x58($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80133100: swc1        $f4, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f4.u32l;
    // 0x80133104: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80133108: swc1        $f10, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f10.u32l;
    // 0x8013310C: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80133110: swc1        $f6, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->f6.u32l;
    // 0x80133114: lw          $a0, 0x9C8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X9C8);
    // 0x80133118: lwc1        $f16, 0x5C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8013311C: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x80133120: swc1        $f8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->f8.u32l;
    // 0x80133124: lwc1        $f18, 0x58($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80133128: swc1        $f18, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->f18.u32l;
    // 0x8013312C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80133130: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80133134: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80133138: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x8013313C: beq         $t7, $zero, L_80133168
    if (ctx->r15 == 0) {
        // 0x80133140: lw          $s2, -0x7F3C($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X7F3C);
            goto L_80133168;
    }
    // 0x80133140: lw          $s2, -0x7F3C($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7F3C);
    // 0x80133144: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80133148: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8013314C: beql        $v0, $t9, L_80133168
    if (ctx->r2 == ctx->r25) {
        // 0x80133150: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_80133168;
    }
    goto skip_7;
    // 0x80133150: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    skip_7:
    // 0x80133154: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
L_80133158:
    // 0x80133158: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8013315C: bnel        $v0, $t8, L_80133158
    if (ctx->r2 != ctx->r24) {
        // 0x80133160: lw          $t8, 0x1C($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X1C);
            goto L_80133158;
    }
    goto skip_8;
    // 0x80133160: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    skip_8:
    // 0x80133164: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_80133168:
    // 0x80133168: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8013316C:
    // 0x8013316C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80133170: beq         $v0, $t1, L_80133A20
    if (ctx->r2 == ctx->r9) {
        // 0x80133174: nop
    
            goto L_80133A20;
    }
    // 0x80133174: nop

    // 0x80133178: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8013317C: beq         $a0, $zero, L_80133A18
    if (ctx->r4 == 0) {
        // 0x80133180: nop
    
            goto L_80133A18;
    }
    // 0x80133180: nop

    // 0x80133184: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80133188: lwc1        $f10, 0x18C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x8013318C: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x80133190: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133194: lwc1        $f4, 0x1A4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x80133198: lwc1        $f16, 0x194($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X194);
    // 0x8013319C: lwc1        $f18, 0x1AC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1AC);
    // 0x801331A0: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x801331A4: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801331A8: mul.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801331AC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x801331B0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x801331B4: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801331B8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x801331BC: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x801331C0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801331C4: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801331C8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801331CC: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801331D0: lwc1        $f6, 0x1A8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x801331D4: lwc1        $f8, 0x19C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x801331D8: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801331DC: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x801331E0: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x801331E4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x801331E8: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
    // 0x801331EC: beq         $t4, $at, L_80133218
    if (ctx->r12 == ctx->r1) {
        // 0x801331F0: lw          $a2, 0x24($t3)
        ctx->r6 = MEM_W(ctx->r11, 0X24);
            goto L_80133218;
    }
    // 0x801331F0: lw          $a2, 0x24($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X24);
    // 0x801331F4: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801331F8: lwc1        $f18, 0x198($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X198);
    // 0x801331FC: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x80133200: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80133204: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80133208: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8013320C: nop

    // 0x80133210: bgtz        $v0, L_80133234
    if (SIGNED(ctx->r2) > 0) {
        // 0x80133214: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80133234;
    }
    // 0x80133214: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80133218:
    // 0x80133218: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8013321C: lwc1        $f16, 0x1A0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x80133220: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x80133224: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133228: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8013322C: b           L_801332DC
    // 0x80133230: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
        goto L_801332DC;
    // 0x80133230: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
L_80133234:
    // 0x80133234: beq         $at, $zero, L_80133280
    if (ctx->r1 == 0) {
        // 0x80133238: nop
    
            goto L_80133280;
    }
    // 0x80133238: nop

    // 0x8013323C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133240: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80133244: lwc1        $f4, 0x1A0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x80133248: lwc1        $f18, 0x198($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X198);
    // 0x8013324C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80133250: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80133254: mflo        $t6
    ctx->r14 = lo;
    // 0x80133258: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8013325C: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80133260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133264: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133268: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8013326C: lwc1        $f8, 0x1A8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x80133270: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80133274: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80133278: b           L_801332DC
    // 0x8013327C: add.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f8.fl;
        goto L_801332DC;
    // 0x8013327C: add.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f8.fl;
L_80133280:
    // 0x80133280: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133284: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80133288: lwc1        $f16, 0x1A0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A0);
    // 0x8013328C: lwc1        $f18, 0x198($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X198);
    // 0x80133290: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133294: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80133298: subu        $t9, $v1, $v0
    ctx->r25 = SUB32(ctx->r3, ctx->r2);
    // 0x8013329C: mflo        $t7
    ctx->r15 = lo;
    // 0x801332A0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801332A4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801332A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801332AC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801332B0: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801332B4: lwc1        $f6, 0x19C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X19C);
    // 0x801332B8: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801332BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801332C0: nop

    // 0x801332C4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801332C8: lwc1        $f4, 0x1A8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x801332CC: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801332D0: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801332D4: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801332D8: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
L_801332DC:
    // 0x801332DC: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801332E0: beq         $a2, $at, L_801333E8
    if (ctx->r6 == ctx->r1) {
        // 0x801332E4: lwc1        $f16, 0x188($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X188);
            goto L_801333E8;
    }
    // 0x801332E4: lwc1        $f16, 0x188($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X188);
    // 0x801332E8: lw          $t3, 0x14C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X14C);
    // 0x801332EC: lwc1        $f6, 0x184($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X184);
    // 0x801332F0: beq         $t3, $zero, L_801333E8
    if (ctx->r11 == 0) {
        // 0x801332F4: nop
    
            goto L_801333E8;
    }
    // 0x801332F4: nop

    // 0x801332F8: lwc1        $f16, 0x188($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X188);
    // 0x801332FC: lwc1        $f8, 0x180($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80133300: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80133304: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80133308: div.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8013330C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80133310: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80133314: nop

    // 0x80133318: bgtz        $v0, L_80133338
    if (SIGNED(ctx->r2) > 0) {
        // 0x8013331C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80133338;
    }
    // 0x8013331C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80133320: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80133324: lwc1        $f10, 0x190($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X190);
    // 0x80133328: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8013332C: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80133330: b           L_801333FC
    // 0x80133334: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
        goto L_801333FC;
    // 0x80133334: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
L_80133338:
    // 0x80133338: beq         $at, $zero, L_80133388
    if (ctx->r1 == 0) {
        // 0x8013333C: lwc1        $f16, 0x188($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X188);
            goto L_80133388;
    }
    // 0x8013333C: lwc1        $f16, 0x188($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80133340: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133344: lwc1        $f6, 0x188($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X188);
    // 0x80133348: lwc1        $f18, 0x190($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X190);
    // 0x8013334C: lwc1        $f8, 0x180($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80133350: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80133354: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80133358: mflo        $t5
    ctx->r13 = lo;
    // 0x8013335C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80133360: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80133364: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133368: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013336C: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80133370: nop

    // 0x80133374: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80133378: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8013337C: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80133380: b           L_801333FC
    // 0x80133384: swc1        $f6, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f6.u32l;
        goto L_801333FC;
    // 0x80133384: swc1        $f6, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f6.u32l;
L_80133388:
    // 0x80133388: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013338C: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80133390: lwc1        $f10, 0x190($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X190);
    // 0x80133394: lwc1        $f8, 0x180($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80133398: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8013339C: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
    // 0x801333A0: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801333A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801333A8: mflo        $t6
    ctx->r14 = lo;
    // 0x801333AC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801333B0: nop

    // 0x801333B4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801333B8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801333BC: lwc1        $f16, 0x184($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X184);
    // 0x801333C0: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801333C4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801333C8: nop

    // 0x801333CC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801333D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801333D4: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801333D8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801333DC: sub.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801333E0: b           L_801333FC
    // 0x801333E4: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
        goto L_801333FC;
    // 0x801333E4: swc1        $f18, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f18.u32l;
L_801333E8:
    // 0x801333E8: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x801333EC: lwc1        $f8, 0x190($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X190);
    // 0x801333F0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801333F4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801333F8: swc1        $f6, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f6.u32l;
L_801333FC:
    // 0x801333FC: blez        $a3, L_80133410
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80133400: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80133410;
    }
    // 0x80133400: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80133404: lwc1        $f24, 0xC($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80133408: b           L_80133420
    // 0x8013340C: lwc1        $f20, 0x10($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X10);
        goto L_80133420;
    // 0x8013340C: lwc1        $f20, 0x10($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X10);
L_80133410:
    // 0x80133410: lwc1        $f24, 0x10($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80133414: lwc1        $f20, 0xC($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80133418: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
    // 0x8013341C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80133420:
    // 0x80133420: lwc1        $f18, 0x18($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80133424: lwc1        $f26, 0x14($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80133428: bne         $a1, $at, L_8013345C
    if (ctx->r5 != ctx->r1) {
        // 0x8013342C: swc1        $f18, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
            goto L_8013345C;
    }
    // 0x8013342C: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x80133430: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133434: lwc1        $f0, -0x4464($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4464);
    // 0x80133438: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8013343C: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80133440: nop

    // 0x80133444: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80133448: nop

    // 0x8013344C: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80133450: nop

    // 0x80133454: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80133458: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_8013345C:
    // 0x8013345C: bne         $t0, $zero, L_801334CC
    if (ctx->r8 != 0) {
        // 0x80133460: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801334CC;
    }
    // 0x80133460: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80133464: beq         $t1, $at, L_80133480
    if (ctx->r9 == ctx->r1) {
        // 0x80133468: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_80133480;
    }
    // 0x80133468: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8013346C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80133470: beq         $v1, $at, L_80133480
    if (ctx->r3 == ctx->r1) {
        // 0x80133474: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80133480;
    }
    // 0x80133474: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80133478: bnel        $v1, $at, L_801334D0
    if (ctx->r3 != ctx->r1) {
        // 0x8013347C: sltiu       $at, $a1, 0x1B
        ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
            goto L_801334D0;
    }
    goto skip_9;
    // 0x8013347C: sltiu       $at, $a1, 0x1B
    ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
    skip_9:
L_80133480:
    // 0x80133480: lw          $v1, 0x84C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84C);
    // 0x80133484: beql        $v1, $zero, L_801334D0
    if (ctx->r3 == 0) {
        // 0x80133488: sltiu       $at, $a1, 0x1B
        ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
            goto L_801334D0;
    }
    goto skip_10;
    // 0x80133488: sltiu       $at, $a1, 0x1B
    ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
    skip_10:
    // 0x8013348C: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80133490: beql        $v0, $zero, L_801334D0
    if (ctx->r2 == 0) {
        // 0x80133494: sltiu       $at, $a1, 0x1B
        ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
            goto L_801334D0;
    }
    goto skip_11;
    // 0x80133494: sltiu       $at, $a1, 0x1B
    ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
    skip_11:
    // 0x80133498: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8013349C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801334A0: beq         $v1, $at, L_801334B4
    if (ctx->r3 == ctx->r1) {
        // 0x801334A4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801334B4;
    }
    // 0x801334A4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801334A8: beq         $v1, $at, L_801334B4
    if (ctx->r3 == ctx->r1) {
        // 0x801334AC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801334B4;
    }
    // 0x801334AC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801334B0: bne         $v1, $at, L_801334CC
    if (ctx->r3 != ctx->r1) {
        // 0x801334B4: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801334CC;
    }
L_801334B4:
    // 0x801334B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801334B8: lwc1        $f0, -0x4460($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4460);
    // 0x801334BC: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x801334C0: nop

    // 0x801334C4: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x801334C8: nop

L_801334CC:
    // 0x801334CC: sltiu       $at, $a1, 0x1B
    ctx->r1 = ctx->r5 < 0X1B ? 1 : 0;
L_801334D0:
    // 0x801334D0: beq         $at, $zero, L_80133520
    if (ctx->r1 == 0) {
        // 0x801334D4: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80133520;
    }
    // 0x801334D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x801334D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801334DC: addu        $at, $at, $t9
    gpr jr_addend_801334E4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801334E0: lw          $t9, -0x445C($at)
    ctx->r25 = ADD32(ctx->r1, -0X445C);
    // 0x801334E4: jr          $t9
    // 0x801334E8: nop

    switch (jr_addend_801334E4 >> 2) {
        case 0: goto L_801334EC; break;
        case 1: goto L_80133520; break;
        case 2: goto L_80133520; break;
        case 3: goto L_80133520; break;
        case 4: goto L_801334EC; break;
        case 5: goto L_80133520; break;
        case 6: goto L_80133510; break;
        case 7: goto L_80133510; break;
        case 8: goto L_80133500; break;
        case 9: goto L_80133520; break;
        case 10: goto L_80133520; break;
        case 11: goto L_80133520; break;
        case 12: goto L_80133520; break;
        case 13: goto L_801334EC; break;
        case 14: goto L_801334EC; break;
        case 15: goto L_80133520; break;
        case 16: goto L_80133520; break;
        case 17: goto L_80133520; break;
        case 18: goto L_801334EC; break;
        case 19: goto L_80133520; break;
        case 20: goto L_80133510; break;
        case 21: goto L_80133510; break;
        case 22: goto L_80133500; break;
        case 23: goto L_80133520; break;
        case 24: goto L_80133520; break;
        case 25: goto L_80133520; break;
        case 26: goto L_80133520; break;
        default: switch_error(__func__, 0x801334E4, 0x8018BBA4);
    }
    // 0x801334E8: nop

L_801334EC:
    // 0x801334EC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801334F0: bne         $t1, $at, L_80133520
    if (ctx->r9 != ctx->r1) {
        // 0x801334F4: nop
    
            goto L_80133520;
    }
    // 0x801334F4: nop

    // 0x801334F8: b           L_80133520
    // 0x801334FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80133520;
    // 0x801334FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80133500:
    // 0x80133500: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80133504: bnel        $t1, $at, L_80133514
    if (ctx->r9 != ctx->r1) {
        // 0x80133508: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80133514;
    }
    goto skip_12;
    // 0x80133508: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    skip_12:
    // 0x8013350C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80133510:
    // 0x80133510: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
L_80133514:
    // 0x80133514: bne         $t1, $at, L_80133520
    if (ctx->r9 != ctx->r1) {
        // 0x80133518: nop
    
            goto L_80133520;
    }
    // 0x80133518: nop

    // 0x8013351C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80133520:
    // 0x80133520: beql        $t2, $zero, L_80133604
    if (ctx->r10 == 0) {
        // 0x80133524: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_80133604;
    }
    goto skip_13;
    // 0x80133524: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_13:
    // 0x80133528: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
    // 0x8013352C: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80133530: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x80133534: lw          $t3, 0x8E8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8E8);
    // 0x80133538: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8013353C: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80133540: sub.s       $f18, $f6, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80133544: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x80133548: lw          $t4, 0x8E8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8E8);
    // 0x8013354C: lwc1        $f0, 0x1C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80133550: add.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80133554: add.s       $f10, $f16, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80133558: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8013355C: nop

    // 0x80133560: bc1fl       L_801335A4
    if (!c1cs) {
        // 0x80133564: addiu       $v1, $s0, 0x1CC
        ctx->r3 = ADD32(ctx->r16, 0X1CC);
            goto L_801335A4;
    }
    goto skip_14;
    // 0x80133564: addiu       $v1, $s0, 0x1CC
    ctx->r3 = ADD32(ctx->r16, 0X1CC);
    skip_14:
L_80133568:
    // 0x80133568: jal         0x800F8FFC
    // 0x8013356C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_3;
    // 0x8013356C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80133570: beq         $v0, $zero, L_80133A14
    if (ctx->r2 == 0) {
        // 0x80133574: lwc1        $f8, 0x90($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
            goto L_80133A14;
    }
    // 0x80133574: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80133578: add.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8013357C: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80133580: lw          $t5, 0x8E8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8E8);
    // 0x80133584: lwc1        $f0, 0x1C($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80133588: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8013358C: add.s       $f16, $f6, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80133590: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80133594: nop

    // 0x80133598: bc1t        L_80133568
    if (c1cs) {
        // 0x8013359C: nop
    
            goto L_80133568;
    }
    // 0x8013359C: nop

    // 0x801335A0: addiu       $v1, $s0, 0x1CC
    ctx->r3 = ADD32(ctx->r16, 0X1CC);
L_801335A4:
    // 0x801335A4: lwc1        $f2, 0x60($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X60);
    // 0x801335A8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801335AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801335B0: nop

    // 0x801335B4: bc1fl       L_801335E8
    if (!c1cs) {
        // 0x801335B8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_801335E8;
    }
    goto skip_15;
    // 0x801335B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_15:
    // 0x801335BC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801335C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801335C4: lwc1        $f18, 0x54($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X54);
    // 0x801335C8: add.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x801335CC: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x801335D0: nop

    // 0x801335D4: bc1fl       L_80133604
    if (!c1cs) {
        // 0x801335D8: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_80133604;
    }
    goto skip_16;
    // 0x801335D8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_16:
    // 0x801335DC: b           L_80133A18
    // 0x801335E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80133A18;
    // 0x801335E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801335E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_801335E8:
    // 0x801335E8: lwc1        $f16, 0x4C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x801335EC: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x801335F0: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x801335F4: nop

    // 0x801335F8: bc1tl       L_80133A18
    if (c1cs) {
        // 0x801335FC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_17;
    // 0x801335FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_17:
    // 0x80133600: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_80133604:
    // 0x80133604: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80133608: bne         $a1, $at, L_801336B4
    if (ctx->r5 != ctx->r1) {
        // 0x8013360C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801336B4;
    }
    // 0x8013360C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133610: lwc1        $f10, 0x1334($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1334);
    // 0x80133614: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80133618: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013361C: lw          $t6, 0x8E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8E8);
    // 0x80133620: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133624: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80133628: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8013362C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80133630: nop

    // 0x80133634: bc1tl       L_80133664
    if (c1cs) {
        // 0x80133638: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_80133664;
    }
    goto skip_18;
    // 0x80133638: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_18:
    // 0x8013363C: lwc1        $f6, 0x1330($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1330);
    // 0x80133640: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80133644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133648: nop

    // 0x8013364C: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80133650: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80133654: nop

    // 0x80133658: bc1fl       L_801336B8
    if (!c1cs) {
        // 0x8013365C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801336B8;
    }
    goto skip_19;
    // 0x8013365C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    skip_19:
    // 0x80133660: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80133664:
    // 0x80133664: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80133668: beq         $v1, $at, L_80133680
    if (ctx->r3 == ctx->r1) {
        // 0x8013366C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80133680;
    }
    // 0x8013366C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80133670: beql        $v1, $at, L_80133A18
    if (ctx->r3 == ctx->r1) {
        // 0x80133674: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_20;
    // 0x80133674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_20:
    // 0x80133678: b           L_801336B0
    // 0x8013367C: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
        goto L_801336B0;
    // 0x8013367C: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
L_80133680:
    // 0x80133680: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80133684: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80133688: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8013368C: nop

    // 0x80133690: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133694: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80133698: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8013369C: nop

    // 0x801336A0: bc1fl       L_801336B8
    if (!c1cs) {
        // 0x801336A4: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801336B8;
    }
    goto skip_21;
    // 0x801336A4: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    skip_21:
    // 0x801336A8: b           L_80133A18
    // 0x801336AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80133A18;
    // 0x801336AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_801336B0:
    // 0x801336B0: bne         $t0, $zero, L_80133A14
    if (ctx->r8 != 0) {
        // 0x801336B4: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80133A14;
    }
L_801336B4:
    // 0x801336B4: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
L_801336B8:
    // 0x801336B8: bne         $a1, $at, L_801336DC
    if (ctx->r5 != ctx->r1) {
        // 0x801336BC: addiu       $v1, $s0, 0x1CC
        ctx->r3 = ADD32(ctx->r16, 0X1CC);
            goto L_801336DC;
    }
    // 0x801336BC: addiu       $v1, $s0, 0x1CC
    ctx->r3 = ADD32(ctx->r16, 0X1CC);
    // 0x801336C0: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x801336C4: beql        $t9, $zero, L_801336E0
    if (ctx->r25 == 0) {
        // 0x801336C8: lw          $t3, 0x48($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X48);
            goto L_801336E0;
    }
    goto skip_22;
    // 0x801336C8: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
    skip_22:
    // 0x801336CC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x801336D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801336D4: beql        $t8, $at, L_80133A18
    if (ctx->r24 == ctx->r1) {
        // 0x801336D8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_23;
    // 0x801336D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_23:
L_801336DC:
    // 0x801336DC: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
L_801336E0:
    // 0x801336E0: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x801336E4: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801336E8: sll         $t5, $t3, 17
    ctx->r13 = S32(ctx->r11 << 17);
    // 0x801336EC: bgez        $t5, L_80133734
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801336F0: lwc1        $f10, 0x174($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
            goto L_80133734;
    }
    // 0x801336F0: lwc1        $f10, 0x174($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X174);
    // 0x801336F4: lw          $t6, 0x6C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X6C);
    // 0x801336F8: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x801336FC: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80133700: beq         $v0, $at, L_80133710
    if (ctx->r2 == ctx->r1) {
        // 0x80133704: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_80133710;
    }
    // 0x80133704: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80133708: bnel        $v0, $at, L_80133738
    if (ctx->r2 != ctx->r1) {
        // 0x8013370C: c.lt.s      $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
            goto L_80133738;
    }
    goto skip_24;
    // 0x8013370C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    skip_24:
L_80133710:
    // 0x80133710: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80133714: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80133718: c.lt.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl < ctx->f4.fl;
    // 0x8013371C: nop

    // 0x80133720: bc1fl       L_80133738
    if (!c1cs) {
        // 0x80133724: c.lt.s      $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
            goto L_80133738;
    }
    goto skip_25;
    // 0x80133724: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    skip_25:
    // 0x80133728: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013372C: nop

    // 0x80133730: sub.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f16.fl;
L_80133734:
    // 0x80133734: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
L_80133738:
    // 0x80133738: lwc1        $f4, 0x178($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8013373C: bc1fl       L_80133A18
    if (!c1cs) {
        // 0x80133740: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_26;
    // 0x80133740: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_26:
    // 0x80133744: sub.s       $f6, $f26, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x80133748: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8013374C: nop

    // 0x80133750: bc1fl       L_80133A18
    if (!c1cs) {
        // 0x80133754: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_27;
    // 0x80133754: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_27:
    // 0x80133758: sub.s       $f16, $f24, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8013375C: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x80133760: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80133764: nop

    // 0x80133768: bc1fl       L_80133A18
    if (!c1cs) {
        // 0x8013376C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_28;
    // 0x8013376C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_28:
    // 0x80133770: add.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80133774: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80133778: nop

    // 0x8013377C: bc1fl       L_80133A18
    if (!c1cs) {
        // 0x80133780: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80133A18;
    }
    goto skip_29;
    // 0x80133780: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_29:
    // 0x80133784: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80133788: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8013378C: addu        $t9, $sp, $a0
    ctx->r25 = ADD32(ctx->r29, ctx->r4);
    // 0x80133790: sw          $t7, 0x10C($t9)
    MEM_W(0X10C, ctx->r25) = ctx->r15;
    // 0x80133794: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80133798: addiu       $t3, $t8, -0x9
    ctx->r11 = ADD32(ctx->r24, -0X9);
    // 0x8013379C: sltiu       $at, $t3, 0x14
    ctx->r1 = ctx->r11 < 0X14 ? 1 : 0;
    // 0x801337A0: beq         $at, $zero, L_80133A08
    if (ctx->r1 == 0) {
        // 0x801337A4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80133A08;
    }
    // 0x801337A4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801337A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801337AC: addu        $at, $at, $t3
    gpr jr_addend_801337B4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801337B0: lw          $t3, -0x43F0($at)
    ctx->r11 = ADD32(ctx->r1, -0X43F0);
    // 0x801337B4: jr          $t3
    // 0x801337B8: nop

    switch (jr_addend_801337B4 >> 2) {
        case 0: goto L_80133830; break;
        case 1: goto L_80133A08; break;
        case 2: goto L_80133A08; break;
        case 3: goto L_80133A08; break;
        case 4: goto L_801339C0; break;
        case 5: goto L_80133A08; break;
        case 6: goto L_80133A08; break;
        case 7: goto L_80133A08; break;
        case 8: goto L_80133A08; break;
        case 9: goto L_80133A08; break;
        case 10: goto L_80133A08; break;
        case 11: goto L_80133A08; break;
        case 12: goto L_801337BC; break;
        case 13: goto L_80133A08; break;
        case 14: goto L_80133A08; break;
        case 15: goto L_80133A08; break;
        case 16: goto L_80133A08; break;
        case 17: goto L_80133A08; break;
        case 18: goto L_801339C0; break;
        case 19: goto L_801339E4; break;
        default: switch_error(__func__, 0x801337B4, 0x8018BC10);
    }
    // 0x801337B8: nop

L_801337BC:
    // 0x801337BC: lw          $v1, 0x84C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84C);
    // 0x801337C0: addiu       $t4, $sp, 0xBC
    ctx->r12 = ADD32(ctx->r29, 0XBC);
    // 0x801337C4: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x801337C8: beql        $v1, $zero, L_80133828
    if (ctx->r3 == 0) {
        // 0x801337CC: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80133828;
    }
    goto skip_30;
    // 0x801337CC: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_30:
    // 0x801337D0: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x801337D4: beq         $a0, $zero, L_801337F4
    if (ctx->r4 == 0) {
        // 0x801337D8: nop
    
            goto L_801337F4;
    }
    // 0x801337D8: nop

    // 0x801337DC: lw          $t5, 0x10($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10);
    // 0x801337E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801337E4: bne         $t5, $at, L_801337F4
    if (ctx->r13 != ctx->r1) {
        // 0x801337E8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801337F4;
    }
    // 0x801337E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801337EC: lwc1        $f6, -0x43A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X43A0);
    // 0x801337F0: swc1        $f6, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->f6.u32l;
L_801337F4:
    // 0x801337F4: beql        $a0, $zero, L_80133828
    if (ctx->r4 == 0) {
        // 0x801337F8: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80133828;
    }
    goto skip_31;
    // 0x801337F8: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_31:
    // 0x801337FC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80133800: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80133804: bnel        $t6, $at, L_80133828
    if (ctx->r14 != ctx->r1) {
        // 0x80133808: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80133828;
    }
    goto skip_32;
    // 0x80133808: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_32:
    // 0x8013380C: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80133810: bnel        $t7, $zero, L_80133828
    if (ctx->r15 != 0) {
        // 0x80133814: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80133828;
    }
    goto skip_33;
    // 0x80133814: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_33:
    // 0x80133818: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x8013381C: b           L_80133A14
    // 0x80133820: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x80133820: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133824: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
L_80133828:
    // 0x80133828: b           L_80133A14
    // 0x8013382C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x8013382C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133830:
    // 0x80133830: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x80133834: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80133838: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8013383C: bnel        $at, $zero, L_801338A0
    if (ctx->r1 != 0) {
        // 0x80133840: lw          $v1, 0x8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8);
            goto L_801338A0;
    }
    goto skip_34;
    // 0x80133840: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    skip_34:
    // 0x80133844: beql        $v0, $zero, L_801338A0
    if (ctx->r2 == 0) {
        // 0x80133848: lw          $v1, 0x8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8);
            goto L_801338A0;
    }
    goto skip_35;
    // 0x80133848: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    skip_35:
    // 0x8013384C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80133850: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80133854: beq         $v1, $at, L_80133864
    if (ctx->r3 == ctx->r1) {
        // 0x80133858: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80133864;
    }
    // 0x80133858: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013385C: bnel        $v1, $at, L_801338A0
    if (ctx->r3 != ctx->r1) {
        // 0x80133860: lw          $v1, 0x8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8);
            goto L_801338A0;
    }
    goto skip_36;
    // 0x80133860: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    skip_36:
L_80133864:
    // 0x80133864: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80133868: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013386C: bne         $a1, $at, L_8013387C
    if (ctx->r5 != ctx->r1) {
        // 0x80133870: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8013387C;
    }
    // 0x80133870: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80133874: b           L_8013387C
    // 0x80133878: lw          $v0, 0xADC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XADC);
        goto L_8013387C;
    // 0x80133878: lw          $v0, 0xADC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XADC);
L_8013387C:
    // 0x8013387C: sltiu       $at, $v0, 0xE
    ctx->r1 = ctx->r2 < 0XE ? 1 : 0;
    // 0x80133880: beq         $at, $zero, L_8013389C
    if (ctx->r1 == 0) {
        // 0x80133884: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8013389C;
    }
    // 0x80133884: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80133888: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013388C: addu        $at, $at, $t8
    gpr jr_addend_80133894 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80133890: lw          $t8, -0x439C($at)
    ctx->r24 = ADD32(ctx->r1, -0X439C);
    // 0x80133894: jr          $t8
    // 0x80133898: nop

    switch (jr_addend_80133894 >> 2) {
        case 0: goto L_80133A14; break;
        case 1: goto L_80133A14; break;
        case 2: goto L_8013389C; break;
        case 3: goto L_80133A14; break;
        case 4: goto L_80133A14; break;
        case 5: goto L_80133A14; break;
        case 6: goto L_8013389C; break;
        case 7: goto L_8013389C; break;
        case 8: goto L_8013389C; break;
        case 9: goto L_80133A14; break;
        case 10: goto L_8013389C; break;
        case 11: goto L_8013389C; break;
        case 12: goto L_8013389C; break;
        case 13: goto L_80133A14; break;
        default: switch_error(__func__, 0x80133894, 0x8018BC64);
    }
    // 0x80133898: nop

L_8013389C:
    // 0x8013389C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
L_801338A0:
    // 0x801338A0: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x801338A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801338A8: beq         $v1, $at, L_801338DC
    if (ctx->r3 == ctx->r1) {
        // 0x801338AC: addu        $v0, $a0, $t3
        ctx->r2 = ADD32(ctx->r4, ctx->r11);
            goto L_801338DC;
    }
    // 0x801338AC: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x801338B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801338B4: beq         $v1, $at, L_8013390C
    if (ctx->r3 == ctx->r1) {
        // 0x801338B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8013390C;
    }
    // 0x801338B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801338BC: beq         $v1, $at, L_8013393C
    if (ctx->r3 == ctx->r1) {
        // 0x801338C0: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8013393C;
    }
    // 0x801338C0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801338C4: beq         $v1, $at, L_801338DC
    if (ctx->r3 == ctx->r1) {
        // 0x801338C8: lwc1        $f18, 0x1BC($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X1BC);
            goto L_801338DC;
    }
    // 0x801338C8: lwc1        $f18, 0x1BC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x801338CC: add.s       $f16, $f28, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f18.fl;
    // 0x801338D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801338D4: b           L_80133A14
    // 0x801338D8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_80133A14;
    // 0x801338D8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_801338DC:
    // 0x801338DC: lw          $t4, 0xADC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XADC);
    // 0x801338E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801338E4: lwc1        $f4, 0x1BC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x801338E8: bnel        $t4, $at, L_80133900
    if (ctx->r12 != ctx->r1) {
        // 0x801338EC: add.s       $f8, $f28, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
            goto L_80133900;
    }
    goto skip_37;
    // 0x801338EC: add.s       $f8, $f28, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
    skip_37:
    // 0x801338F0: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x801338F4: b           L_80133A14
    // 0x801338F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x801338F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801338FC: add.s       $f8, $f28, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
L_80133900:
    // 0x80133900: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133904: b           L_80133A14
    // 0x80133908: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_80133A14;
    // 0x80133908: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8013390C:
    // 0x8013390C: lw          $t5, 0xADC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XADC);
    // 0x80133910: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133914: lwc1        $f10, 0x1BC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x80133918: bnel        $t5, $at, L_80133930
    if (ctx->r13 != ctx->r1) {
        // 0x8013391C: add.s       $f6, $f28, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f28.fl + ctx->f10.fl;
            goto L_80133930;
    }
    goto skip_38;
    // 0x8013391C: add.s       $f6, $f28, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f28.fl + ctx->f10.fl;
    skip_38:
    // 0x80133920: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x80133924: b           L_80133A14
    // 0x80133928: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x80133928: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013392C: add.s       $f6, $f28, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f28.fl + ctx->f10.fl;
L_80133930:
    // 0x80133930: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133934: b           L_80133A14
    // 0x80133938: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80133A14;
    // 0x80133938: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8013393C:
    // 0x8013393C: lw          $v1, 0xADC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XADC);
    // 0x80133940: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133944: beq         $v1, $at, L_80133960
    if (ctx->r3 == ctx->r1) {
        // 0x80133948: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80133960;
    }
    // 0x80133948: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013394C: beql        $v1, $at, L_80133994
    if (ctx->r3 == ctx->r1) {
        // 0x80133950: lw          $t7, 0xAE0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XAE0);
            goto L_80133994;
    }
    goto skip_39;
    // 0x80133950: lw          $t7, 0xAE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XAE0);
    skip_39:
    // 0x80133954: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x80133958: b           L_80133A14
    // 0x8013395C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x8013395C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133960:
    // 0x80133960: lw          $t6, 0xAE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XAE8);
    // 0x80133964: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80133968: lwc1        $f18, 0x1BC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x8013396C: bnel        $t6, $at, L_80133984
    if (ctx->r14 != ctx->r1) {
        // 0x80133970: add.s       $f16, $f28, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f18.fl;
            goto L_80133984;
    }
    goto skip_40;
    // 0x80133970: add.s       $f16, $f28, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f18.fl;
    skip_40:
    // 0x80133974: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x80133978: b           L_80133A14
    // 0x8013397C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x8013397C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133980: add.s       $f16, $f28, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f18.fl;
L_80133984:
    // 0x80133984: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133988: b           L_80133A14
    // 0x8013398C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_80133A14;
    // 0x8013398C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80133990: lw          $t7, 0xAE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XAE0);
L_80133994:
    // 0x80133994: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133998: lwc1        $f4, 0x1BC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x8013399C: bnel        $t7, $at, L_801339B4
    if (ctx->r15 != ctx->r1) {
        // 0x801339A0: add.s       $f8, $f28, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
            goto L_801339B4;
    }
    goto skip_41;
    // 0x801339A0: add.s       $f8, $f28, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
    skip_41:
    // 0x801339A4: swc1        $f30, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f30.u32l;
    // 0x801339A8: b           L_80133A14
    // 0x801339AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x801339AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801339B0: add.s       $f8, $f28, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f4.fl;
L_801339B4:
    // 0x801339B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801339B8: b           L_80133A14
    // 0x801339BC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_80133A14;
    // 0x801339BC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_801339C0:
    // 0x801339C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801339C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801339C8: lwc1        $f10, 0x1BC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1BC);
    // 0x801339CC: addu        $t9, $sp, $a0
    ctx->r25 = ADD32(ctx->r29, ctx->r4);
    // 0x801339D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801339D4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801339D8: add.s       $f16, $f18, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x801339DC: b           L_80133A14
    // 0x801339E0: swc1        $f16, 0xBC($t9)
    MEM_W(0XBC, ctx->r25) = ctx->f16.u32l;
        goto L_80133A14;
    // 0x801339E0: swc1        $f16, 0xBC($t9)
    MEM_W(0XBC, ctx->r25) = ctx->f16.u32l;
L_801339E4:
    // 0x801339E4: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x801339E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801339EC: beq         $a1, $at, L_80133A08
    if (ctx->r5 == ctx->r1) {
        // 0x801339F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80133A08;
    }
    // 0x801339F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801339F4: beq         $a1, $at, L_80133A08
    if (ctx->r5 == ctx->r1) {
        // 0x801339F8: addu        $t8, $sp, $a0
        ctx->r24 = ADD32(ctx->r29, ctx->r4);
            goto L_80133A08;
    }
    // 0x801339F8: addu        $t8, $sp, $a0
    ctx->r24 = ADD32(ctx->r29, ctx->r4);
    // 0x801339FC: swc1        $f30, 0xBC($t8)
    MEM_W(0XBC, ctx->r24) = ctx->f30.u32l;
    // 0x80133A00: b           L_80133A14
    // 0x80133A04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80133A14;
    // 0x80133A04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133A08:
    // 0x80133A08: addu        $t3, $sp, $a0
    ctx->r11 = ADD32(ctx->r29, ctx->r4);
    // 0x80133A0C: swc1        $f28, 0xBC($t3)
    MEM_W(0XBC, ctx->r11) = ctx->f28.u32l;
    // 0x80133A10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133A14:
    // 0x80133A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80133A18:
    // 0x80133A18: b           L_8013316C
    // 0x80133A1C: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
        goto L_8013316C;
    // 0x80133A1C: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_80133A20:
    // 0x80133A20: beq         $s1, $zero, L_80133FCC
    if (ctx->r17 == 0) {
        // 0x80133A24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133FCC;
    }
    // 0x80133A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133A28: addiu       $v1, $s0, 0x1CC
    ctx->r3 = ADD32(ctx->r16, 0X1CC);
    // 0x80133A2C: lbu         $t4, 0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X5);
    // 0x80133A30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133A34: bnel        $t4, $at, L_80133A7C
    if (ctx->r12 != ctx->r1) {
        // 0x80133A38: lbu         $t6, 0x13($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X13);
            goto L_80133A7C;
    }
    goto skip_42;
    // 0x80133A38: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    skip_42:
    // 0x80133A3C: jal         0x80018948
    // 0x80133A40: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_4;
    // 0x80133A40: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_4:
    // 0x80133A44: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x80133A48: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80133A4C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80133A50: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80133A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133A58: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133A5C: add.s       $f6, $f10, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80133A60: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80133A64: nop

    // 0x80133A68: bc1fl       L_80133A7C
    if (!c1cs) {
        // 0x80133A6C: lbu         $t6, 0x13($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X13);
            goto L_80133A7C;
    }
    goto skip_43;
    // 0x80133A6C: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    skip_43:
    // 0x80133A70: b           L_80133FCC
    // 0x80133A74: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
        goto L_80133FCC;
    // 0x80133A74: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
    // 0x80133A78: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
L_80133A7C:
    // 0x80133A7C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80133A80: beql        $at, $zero, L_80133B08
    if (ctx->r1 == 0) {
        // 0x80133A84: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_80133B08;
    }
    goto skip_44;
    // 0x80133A84: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_44:
    // 0x80133A88: jal         0x80018948
    // 0x80133A8C: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_5;
    // 0x80133A8C: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_5:
    // 0x80133A90: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80133A94: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x80133A98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80133A9C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80133AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133AA4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80133AA8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133AAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133AB0: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80133AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133AB8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80133ABC: bgez        $t9, L_80133AD0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80133AC0: add.s       $f10, $f16, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
            goto L_80133AD0;
    }
    // 0x80133AC0: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80133AC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133AC8: nop

    // 0x80133ACC: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_80133AD0:
    // 0x80133AD0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80133AD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133AD8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80133ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133AE0: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80133AE4: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80133AE8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80133AEC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80133AF0: nop

    // 0x80133AF4: bc1fl       L_80133B08
    if (!c1cs) {
        // 0x80133AF8: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_80133B08;
    }
    goto skip_45;
    // 0x80133AF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_45:
    // 0x80133AFC: b           L_80133FCC
    // 0x80133B00: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
        goto L_80133FCC;
    // 0x80133B00: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
    // 0x80133B04: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_80133B08:
    // 0x80133B08: blez        $s1, L_80133E48
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80133B0C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80133E48;
    }
    // 0x80133B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133B10: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80133B14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80133B18: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133B1C: addiu       $v0, $sp, 0xBC
    ctx->r2 = ADD32(ctx->r29, 0XBC);
    // 0x80133B20: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80133B24: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x80133B28: lwc1        $f0, -0x4364($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4364);
    // 0x80133B2C: addiu       $a2, $sp, 0x10C
    ctx->r6 = ADD32(ctx->r29, 0X10C);
L_80133B30:
    // 0x80133B30: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80133B34: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x80133B38: addiu       $t5, $a0, -0x5
    ctx->r13 = ADD32(ctx->r4, -0X5);
    // 0x80133B3C: bne         $t4, $a0, L_80133B50
    if (ctx->r12 != ctx->r4) {
        // 0x80133B40: sltiu       $at, $t5, 0x1E
        ctx->r1 = ctx->r13 < 0X1E ? 1 : 0;
            goto L_80133B50;
    }
    // 0x80133B40: sltiu       $at, $t5, 0x1E
    ctx->r1 = ctx->r13 < 0X1E ? 1 : 0;
    // 0x80133B44: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133B48: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80133B4C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80133B50:
    // 0x80133B50: beq         $at, $zero, L_80133E28
    if (ctx->r1 == 0) {
        // 0x80133B54: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80133E28;
    }
    // 0x80133B54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80133B58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133B5C: addu        $at, $at, $t5
    gpr jr_addend_80133B64 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80133B60: lw          $t5, -0x4360($at)
    ctx->r13 = ADD32(ctx->r1, -0X4360);
    // 0x80133B64: jr          $t5
    // 0x80133B68: nop

    switch (jr_addend_80133B64 >> 2) {
        case 0: goto L_80133BAC; break;
        case 1: goto L_80133E28; break;
        case 2: goto L_80133E28; break;
        case 3: goto L_80133E28; break;
        case 4: goto L_80133D2C; break;
        case 5: goto L_80133E28; break;
        case 6: goto L_80133E28; break;
        case 7: goto L_80133E28; break;
        case 8: goto L_80133D6C; break;
        case 9: goto L_80133E28; break;
        case 10: goto L_80133E28; break;
        case 11: goto L_80133E28; break;
        case 12: goto L_80133E28; break;
        case 13: goto L_80133E28; break;
        case 14: goto L_80133B6C; break;
        case 15: goto L_80133E28; break;
        case 16: goto L_80133BEC; break;
        case 17: goto L_80133E28; break;
        case 18: goto L_80133C2C; break;
        case 19: goto L_80133E28; break;
        case 20: goto L_80133C6C; break;
        case 21: goto L_80133E28; break;
        case 22: goto L_80133DAC; break;
        case 23: goto L_80133DEC; break;
        case 24: goto L_80133E28; break;
        case 25: goto L_80133E28; break;
        case 26: goto L_80133E28; break;
        case 27: goto L_80133CAC; break;
        case 28: goto L_80133E28; break;
        case 29: goto L_80133CEC; break;
        default: switch_error(__func__, 0x80133B64, 0x8018BCA0);
    }
    // 0x80133B68: nop

L_80133B6C:
    // 0x80133B6C: lbu         $t6, 0x39($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X39);
    // 0x80133B70: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133B74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133B78: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80133B7C: bgez        $t6, L_80133B90
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80133B80: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80133B90;
    }
    // 0x80133B80: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133B88: nop

    // 0x80133B8C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80133B90:
    // 0x80133B90: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133B94: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80133B98: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133B9C: lbu         $t7, 0x39($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X39);
    // 0x80133BA0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80133BA4: b           L_80133E28
    // 0x80133BA8: sb          $t9, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r25;
        goto L_80133E28;
    // 0x80133BA8: sb          $t9, 0x39($v1)
    MEM_B(0X39, ctx->r3) = ctx->r25;
L_80133BAC:
    // 0x80133BAC: lbu         $t3, 0x3A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3A);
    // 0x80133BB0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133BB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133BB8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80133BBC: bgez        $t3, L_80133BD0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80133BC0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80133BD0;
    }
    // 0x80133BC0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133BC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133BC8: nop

    // 0x80133BCC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80133BD0:
    // 0x80133BD0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133BD4: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80133BD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133BDC: lbu         $t8, 0x3A($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3A);
    // 0x80133BE0: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80133BE4: b           L_80133E28
    // 0x80133BE8: sb          $t4, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r12;
        goto L_80133E28;
    // 0x80133BE8: sb          $t4, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r12;
L_80133BEC:
    // 0x80133BEC: lbu         $t5, 0x3B($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3B);
    // 0x80133BF0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133BF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133BF8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80133BFC: bgez        $t5, L_80133C10
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80133C00: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80133C10;
    }
    // 0x80133C00: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133C04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133C08: nop

    // 0x80133C0C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80133C10:
    // 0x80133C10: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133C14: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80133C18: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133C1C: lbu         $t6, 0x3B($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3B);
    // 0x80133C20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80133C24: b           L_80133E28
    // 0x80133C28: sb          $t7, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r15;
        goto L_80133E28;
    // 0x80133C28: sb          $t7, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r15;
L_80133C2C:
    // 0x80133C2C: lbu         $t9, 0x3C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3C);
    // 0x80133C30: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133C34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133C38: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80133C3C: bgez        $t9, L_80133C50
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80133C40: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80133C50;
    }
    // 0x80133C40: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133C44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133C48: nop

    // 0x80133C4C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80133C50:
    // 0x80133C50: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133C54: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80133C58: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133C5C: lbu         $t3, 0x3C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3C);
    // 0x80133C60: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80133C64: b           L_80133E28
    // 0x80133C68: sb          $t8, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r24;
        goto L_80133E28;
    // 0x80133C68: sb          $t8, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r24;
L_80133C6C:
    // 0x80133C6C: lbu         $t4, 0x3D($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3D);
    // 0x80133C70: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133C74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133C78: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80133C7C: bgez        $t4, L_80133C90
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80133C80: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80133C90;
    }
    // 0x80133C80: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133C84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133C88: nop

    // 0x80133C8C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80133C90:
    // 0x80133C90: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133C94: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80133C98: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133C9C: lbu         $t5, 0x3D($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3D);
    // 0x80133CA0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80133CA4: b           L_80133E28
    // 0x80133CA8: sb          $t6, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r14;
        goto L_80133E28;
    // 0x80133CA8: sb          $t6, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r14;
L_80133CAC:
    // 0x80133CAC: lbu         $t7, 0x3E($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3E);
    // 0x80133CB0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133CB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133CB8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80133CBC: bgez        $t7, L_80133CD0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80133CC0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80133CD0;
    }
    // 0x80133CC0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133CC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133CC8: nop

    // 0x80133CCC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80133CD0:
    // 0x80133CD0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133CD4: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80133CD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133CDC: lbu         $t9, 0x3E($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3E);
    // 0x80133CE0: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80133CE4: b           L_80133E28
    // 0x80133CE8: sb          $t3, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r11;
        goto L_80133E28;
    // 0x80133CE8: sb          $t3, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r11;
L_80133CEC:
    // 0x80133CEC: lbu         $t8, 0x3F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3F);
    // 0x80133CF0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133CF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133CF8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80133CFC: bgez        $t8, L_80133D10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80133D00: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80133D10;
    }
    // 0x80133D00: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133D04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133D08: nop

    // 0x80133D0C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80133D10:
    // 0x80133D10: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133D14: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80133D18: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133D1C: lbu         $t4, 0x3F($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3F);
    // 0x80133D20: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80133D24: b           L_80133E28
    // 0x80133D28: sb          $t5, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r13;
        goto L_80133E28;
    // 0x80133D28: sb          $t5, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r13;
L_80133D2C:
    // 0x80133D2C: lbu         $t6, 0x40($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X40);
    // 0x80133D30: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133D34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133D38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80133D3C: bgez        $t6, L_80133D50
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80133D40: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80133D50;
    }
    // 0x80133D40: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133D44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133D48: nop

    // 0x80133D4C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80133D50:
    // 0x80133D50: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133D54: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80133D58: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133D5C: lbu         $t7, 0x40($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X40);
    // 0x80133D60: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80133D64: b           L_80133E28
    // 0x80133D68: sb          $t9, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r25;
        goto L_80133E28;
    // 0x80133D68: sb          $t9, 0x40($v1)
    MEM_B(0X40, ctx->r3) = ctx->r25;
L_80133D6C:
    // 0x80133D6C: lbu         $t3, 0x41($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X41);
    // 0x80133D70: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133D74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133D78: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80133D7C: bgez        $t3, L_80133D90
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80133D80: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80133D90;
    }
    // 0x80133D80: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133D84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133D88: nop

    // 0x80133D8C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80133D90:
    // 0x80133D90: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133D94: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80133D98: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133D9C: lbu         $t8, 0x41($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X41);
    // 0x80133DA0: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80133DA4: b           L_80133E28
    // 0x80133DA8: sb          $t4, 0x41($v1)
    MEM_B(0X41, ctx->r3) = ctx->r12;
        goto L_80133E28;
    // 0x80133DA8: sb          $t4, 0x41($v1)
    MEM_B(0X41, ctx->r3) = ctx->r12;
L_80133DAC:
    // 0x80133DAC: lbu         $t5, 0x42($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X42);
    // 0x80133DB0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133DB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133DB8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80133DBC: bgez        $t5, L_80133DD0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80133DC0: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80133DD0;
    }
    // 0x80133DC0: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80133DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133DC8: nop

    // 0x80133DCC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80133DD0:
    // 0x80133DD0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133DD4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80133DD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133DDC: lbu         $t6, 0x42($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X42);
    // 0x80133DE0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80133DE4: b           L_80133E28
    // 0x80133DE8: sb          $t7, 0x42($v1)
    MEM_B(0X42, ctx->r3) = ctx->r15;
        goto L_80133E28;
    // 0x80133DE8: sb          $t7, 0x42($v1)
    MEM_B(0X42, ctx->r3) = ctx->r15;
L_80133DEC:
    // 0x80133DEC: lbu         $t9, 0x43($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X43);
    // 0x80133DF0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133DF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133DF8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80133DFC: bgez        $t9, L_80133E10
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80133E00: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80133E10;
    }
    // 0x80133E00: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133E04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133E08: nop

    // 0x80133E0C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80133E10:
    // 0x80133E10: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80133E14: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80133E18: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80133E1C: lbu         $t3, 0x43($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X43);
    // 0x80133E20: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80133E24: sb          $t8, 0x43($v1)
    MEM_B(0X43, ctx->r3) = ctx->r24;
L_80133E28:
    // 0x80133E28: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133E2C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80133E30: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80133E34: add.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80133E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133E3C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80133E40: bne         $v0, $a1, L_80133B30
    if (ctx->r2 != ctx->r5) {
        // 0x80133E44: lwc1        $f20, -0x4($v0)
        ctx->f20.u32l = MEM_W(ctx->r2, -0X4);
            goto L_80133B30;
    }
    // 0x80133E44: lwc1        $f20, -0x4($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, -0X4);
L_80133E48:
    // 0x80133E48: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x80133E4C: jal         0x80018948
    // 0x80133E50: sw          $a0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x80133E50: sw          $a0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r4;
    after_6:
    // 0x80133E54: mul.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80133E58: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80133E5C: blez        $s1, L_80133FCC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80133E60: lw          $a0, 0xB4($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB4);
            goto L_80133FCC;
    }
    // 0x80133E60: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x80133E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E68: addiu       $v0, $sp, 0xBC
    ctx->r2 = ADD32(ctx->r29, 0XBC);
L_80133E6C:
    // 0x80133E6C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133E70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80133E74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80133E78: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x80133E7C: nop

    // 0x80133E80: bc1f        L_80133FBC
    if (!c1cs) {
        // 0x80133E84: addiu       $t4, $sp, 0x10C
        ctx->r12 = ADD32(ctx->r29, 0X10C);
            goto L_80133FBC;
    }
    // 0x80133E84: addiu       $t4, $sp, 0x10C
    ctx->r12 = ADD32(ctx->r29, 0X10C);
    // 0x80133E88: addu        $a2, $a1, $t4
    ctx->r6 = ADD32(ctx->r5, ctx->r12);
    // 0x80133E8C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80133E90: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x80133E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E98: bnel        $t5, $t6, L_80133ED0
    if (ctx->r13 != ctx->r14) {
        // 0x80133E9C: sb          $zero, 0x37($v1)
        MEM_B(0X37, ctx->r3) = 0;
            goto L_80133ED0;
    }
    goto skip_46;
    // 0x80133E9C: sb          $zero, 0x37($v1)
    MEM_B(0X37, ctx->r3) = 0;
    skip_46:
    // 0x80133EA0: lbu         $t7, 0x37($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X37);
    // 0x80133EA4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80133EA8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80133EAC: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x80133EB0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80133EB4: bne         $at, $zero, L_80133ED0
    if (ctx->r1 != 0) {
        // 0x80133EB8: sb          $t9, 0x37($v1)
        MEM_B(0X37, ctx->r3) = ctx->r25;
            goto L_80133ED0;
    }
    // 0x80133EB8: sb          $t9, 0x37($v1)
    MEM_B(0X37, ctx->r3) = ctx->r25;
    // 0x80133EBC: jal         0x80132758
    // 0x80133EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_7;
    // 0x80133EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80133EC4: b           L_80133FCC
    // 0x80133EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133FCC;
    // 0x80133EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133ECC: sb          $zero, 0x37($v1)
    MEM_B(0X37, ctx->r3) = 0;
L_80133ED0:
    // 0x80133ED0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80133ED4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80133ED8: jal         0x80132564
    // 0x80133EDC: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_8;
    // 0x80133EDC: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_8:
    // 0x80133EE0: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80133EE4: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80133EE8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80133EEC: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x80133EF0: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80133EF4: addiu       $t5, $t4, -0x5
    ctx->r13 = ADD32(ctx->r12, -0X5);
    // 0x80133EF8: sltiu       $at, $t5, 0x1E
    ctx->r1 = ctx->r13 < 0X1E ? 1 : 0;
    // 0x80133EFC: beq         $at, $zero, L_80133F6C
    if (ctx->r1 == 0) {
        // 0x80133F00: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80133F6C;
    }
    // 0x80133F00: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80133F04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133F08: addu        $at, $at, $t5
    gpr jr_addend_80133F10 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80133F0C: lw          $t5, -0x42E8($at)
    ctx->r13 = ADD32(ctx->r1, -0X42E8);
    // 0x80133F10: jr          $t5
    // 0x80133F14: nop

    switch (jr_addend_80133F10 >> 2) {
        case 0: goto L_80133F20; break;
        case 1: goto L_80133F6C; break;
        case 2: goto L_80133F6C; break;
        case 3: goto L_80133F6C; break;
        case 4: goto L_80133F50; break;
        case 5: goto L_80133F6C; break;
        case 6: goto L_80133F6C; break;
        case 7: goto L_80133F6C; break;
        case 8: goto L_80133F58; break;
        case 9: goto L_80133F6C; break;
        case 10: goto L_80133F6C; break;
        case 11: goto L_80133F6C; break;
        case 12: goto L_80133F6C; break;
        case 13: goto L_80133F6C; break;
        case 14: goto L_80133F18; break;
        case 15: goto L_80133F6C; break;
        case 16: goto L_80133F28; break;
        case 17: goto L_80133F6C; break;
        case 18: goto L_80133F30; break;
        case 19: goto L_80133F6C; break;
        case 20: goto L_80133F38; break;
        case 21: goto L_80133F6C; break;
        case 22: goto L_80133F60; break;
        case 23: goto L_80133F68; break;
        case 24: goto L_80133F6C; break;
        case 25: goto L_80133F6C; break;
        case 26: goto L_80133F6C; break;
        case 27: goto L_80133F40; break;
        case 28: goto L_80133F6C; break;
        case 29: goto L_80133F48; break;
        default: switch_error(__func__, 0x80133F10, 0x8018BD18);
    }
    // 0x80133F14: nop

L_80133F18:
    // 0x80133F18: b           L_80133F6C
    // 0x80133F1C: sb          $zero, 0x39($v1)
    MEM_B(0X39, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F1C: sb          $zero, 0x39($v1)
    MEM_B(0X39, ctx->r3) = 0;
L_80133F20:
    // 0x80133F20: b           L_80133F6C
    // 0x80133F24: sb          $zero, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F24: sb          $zero, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = 0;
L_80133F28:
    // 0x80133F28: b           L_80133F6C
    // 0x80133F2C: sb          $zero, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F2C: sb          $zero, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = 0;
L_80133F30:
    // 0x80133F30: b           L_80133F6C
    // 0x80133F34: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F34: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
L_80133F38:
    // 0x80133F38: b           L_80133F6C
    // 0x80133F3C: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F3C: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
L_80133F40:
    // 0x80133F40: b           L_80133F6C
    // 0x80133F44: sb          $zero, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F44: sb          $zero, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = 0;
L_80133F48:
    // 0x80133F48: b           L_80133F6C
    // 0x80133F4C: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F4C: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
L_80133F50:
    // 0x80133F50: b           L_80133F6C
    // 0x80133F54: sb          $zero, 0x40($v1)
    MEM_B(0X40, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F54: sb          $zero, 0x40($v1)
    MEM_B(0X40, ctx->r3) = 0;
L_80133F58:
    // 0x80133F58: b           L_80133F6C
    // 0x80133F5C: sb          $zero, 0x41($v1)
    MEM_B(0X41, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F5C: sb          $zero, 0x41($v1)
    MEM_B(0X41, ctx->r3) = 0;
L_80133F60:
    // 0x80133F60: b           L_80133F6C
    // 0x80133F64: sb          $zero, 0x42($v1)
    MEM_B(0X42, ctx->r3) = 0;
        goto L_80133F6C;
    // 0x80133F64: sb          $zero, 0x42($v1)
    MEM_B(0X42, ctx->r3) = 0;
L_80133F68:
    // 0x80133F68: sb          $zero, 0x43($v1)
    MEM_B(0X43, ctx->r3) = 0;
L_80133F6C:
    // 0x80133F6C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80133F70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80133F74: bne         $t6, $at, L_80133FB4
    if (ctx->r14 != ctx->r1) {
        // 0x80133F78: nop
    
            goto L_80133FB4;
    }
    // 0x80133F78: nop

    // 0x80133F7C: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80133F80: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80133F84: bne         $t7, $at, L_80133FB4
    if (ctx->r15 != ctx->r1) {
        // 0x80133F88: nop
    
            goto L_80133FB4;
    }
    // 0x80133F88: nop

    // 0x80133F8C: jal         0x80018948
    // 0x80133F90: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x80133F90: nop

    after_9:
    // 0x80133F94: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80133F98: lwc1        $f18, -0x4270($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4270);
    // 0x80133F9C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80133FA0: nop

    // 0x80133FA4: bc1f        L_80133FB4
    if (!c1cs) {
        // 0x80133FA8: nop
    
            goto L_80133FB4;
    }
    // 0x80133FA8: nop

    // 0x80133FAC: b           L_80133FCC
    // 0x80133FB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133FCC;
    // 0x80133FB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133FB4:
    // 0x80133FB4: b           L_80133FCC
    // 0x80133FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133FCC;
    // 0x80133FB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133FBC:
    // 0x80133FBC: bne         $a0, $s1, L_80133E6C
    if (ctx->r4 != ctx->r17) {
        // 0x80133FC0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80133E6C;
    }
    // 0x80133FC0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80133FC4: b           L_80133FD0
    // 0x80133FC8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80133FD0;
    // 0x80133FC8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80133FCC:
    // 0x80133FCC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80133FD0:
    // 0x80133FD0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80133FD4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80133FD8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80133FDC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80133FE0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80133FE4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80133FE8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80133FEC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80133FF0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80133FF4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80133FF8: jr          $ra
    // 0x80133FFC: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    return;
    // 0x80133FFC: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
;}
RECOMP_FUNC void func_ovl8_80373308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037330C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80373310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373314: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80373318: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8037331C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80373320: beq         $a0, $zero, L_8037332C
    if (ctx->r4 == 0) {
        // 0x80373324: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8037332C;
    }
    // 0x80373324: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80373328: lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20);
L_8037332C:
    // 0x8037332C: jal         0x8037C3AC
    // 0x80373330: lw          $a0, 0x1C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1C);
    func_ovl8_8037C3AC(rdram, ctx);
        goto after_0;
    // 0x80373330: lw          $a0, 0x1C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1C);
    after_0:
    // 0x80373334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037333C: jr          $ra
    // 0x80373340: nop

    return;
    // 0x80373340: nop

;}
RECOMP_FUNC void func_ovl8_80382AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80382AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80382AAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80382AB0: jal         0x803817C0
    // 0x80382AB4: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_803817C0(rdram, ctx);
        goto after_0;
    // 0x80382AB4: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80382AB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80382ABC: jal         0x80373694
    // 0x80382AC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_80373694(rdram, ctx);
        goto after_1;
    // 0x80382AC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80382AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80382ACC: jr          $ra
    // 0x80382AD0: nop

    return;
    // 0x80382AD0: nop

;}
RECOMP_FUNC void ftCaptainAppearEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013E00C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E010: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013E018: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013E01C: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x8013E020: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013E024: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8013E028: bne         $t6, $at, L_8013E038
    if (ctx->r14 != ctx->r1) {
        // 0x8013E02C: nop
    
            goto L_8013E038;
    }
    // 0x8013E02C: nop

    // 0x8013E030: b           L_8013E038
    // 0x8013E034: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
        goto L_8013E038;
    // 0x8013E034: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
L_8013E038:
    // 0x8013E038: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013E03C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013E040: jal         0x800E6F24
    // 0x8013E044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013E044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013E048: jal         0x8013DBAC
    // 0x8013E04C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonAppearInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8013E04C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013E050: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013E054: lbu         $t7, 0x18E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013E058: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x8013E05C: sb          $t8, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r24;
    // 0x8013E060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013E064: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013E068: jr          $ra
    // 0x8013E06C: nop

    return;
    // 0x8013E06C: nop

;}
RECOMP_FUNC void unref_80004934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004934: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004938: sh          $a0, 0x6624($at)
    MEM_H(0X6624, ctx->r1) = ctx->r4;
    // 0x8000493C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004940: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80004944: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80004948: jr          $ra
    // 0x8000494C: sh          $a1, 0x6626($at)
    MEM_H(0X6626, ctx->r1) = ctx->r5;
    return;
    // 0x8000494C: sh          $a1, 0x6626($at)
    MEM_H(0X6626, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void syAudioSetFXType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A40: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020A44: lw          $t6, -0x34D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X34D8);
    // 0x80020A48: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80020A4C: addiu       $v0, $v0, -0x34D4
    ctx->r2 = ADD32(ctx->r2, -0X34D4);
    // 0x80020A50: beq         $a0, $t6, L_80020A6C
    if (ctx->r4 == ctx->r14) {
        // 0x80020A54: nop
    
            goto L_80020A6C;
    }
    // 0x80020A54: nop

    // 0x80020A58: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80020A5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020A60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80020A64: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020A68: sb          $a0, -0x2648($at)
    MEM_B(-0X2648, ctx->r1) = ctx->r4;
L_80020A6C:
    // 0x80020A6C: jr          $ra
    // 0x80020A70: nop

    return;
    // 0x80020A70: nop

;}
RECOMP_FUNC void ftDonkeySpecialNGetStatusChargeLevelReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B508: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B50C: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B510: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
    // 0x8015B514: jr          $ra
    // 0x8015B518: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
    return;
    // 0x8015B518: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void itBombHeiCommonSetHitStatusNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177208: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017720C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80177210: jr          $ra
    // 0x80177214: sw          $t6, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r14;
    return;
    // 0x80177214: sw          $t6, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157AB8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157ABC: jal         0x800DE6E4
    // 0x80157AC0: addiu       $a1, $a1, 0x7B14
    ctx->r5 = ADD32(ctx->r5, 0X7B14);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80157AC0: addiu       $a1, $a1, 0x7B14
    ctx->r5 = ADD32(ctx->r5, 0X7B14);
    after_0:
    // 0x80157AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157ACC: jr          $ra
    // 0x80157AD0: nop

    return;
    // 0x80157AD0: nop

;}
RECOMP_FUNC void mnMapsModelSecProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F70: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80132F74: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80132F78: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80132F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132F84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132F88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132F8C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80132F90: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80132F94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132F98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80132F9C: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x80132FA0: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x80132FA4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80132FA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132FAC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80132FB0: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80132FB4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132FB8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80132FBC: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80132FC0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80132FC4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132FC8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132FCC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132FD0: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80132FD4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80132FD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132FDC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80132FE0: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80132FE4: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80132FE8: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80132FEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132FF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80132FF4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80132FF8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80132FFC: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80133000: ori         $t7, $t7, 0x49D8
    ctx->r15 = ctx->r15 | 0X49D8;
    // 0x80133004: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80133008: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013300C: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x80133010: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80133014: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80133018: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x8013301C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80133020: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80133024: jal         0x80014768
    // 0x80133028: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80133028: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    after_0:
    // 0x8013302C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133034: jr          $ra
    // 0x80133038: nop

    return;
    // 0x80133038: nop

;}
RECOMP_FUNC void mn1PModeMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132500: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132504: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013250C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132510: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132514: jal         0x80009968
    // 0x80132518: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132518: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013251C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132520: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132528: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013252C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132538: jal         0x80009DF4
    // 0x8013253C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013253C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132540: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132544: lw          $t7, 0x3290($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3290);
    // 0x80132548: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013254C: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x80132550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132554: jal         0x800CCFDC
    // 0x80132558: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132558: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013255C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132560: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132564: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132568: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x8013256C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132570: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132574: lw          $t9, 0x3290($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3290);
    // 0x80132578: addiu       $v1, $v1, 0x2A30
    ctx->r3 = ADD32(ctx->r3, 0X2A30);
    // 0x8013257C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80132580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132584: jal         0x800CCFDC
    // 0x80132588: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132588: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    after_3:
    // 0x8013258C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80132590: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132594: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80132598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013259C: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x801325A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801325A4: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x801325A8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801325AC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801325B0: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x801325B4: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x801325B8: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801325BC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801325C0: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x801325C4: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x801325C8: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801325CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801325D0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801325D4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801325D8: lw          $t7, 0x3290($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3290);
    // 0x801325DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801325E0: jal         0x800CCFDC
    // 0x801325E4: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801325E4: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_4:
    // 0x801325E8: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801325EC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x801325F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801325F4: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x801325F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801325FC: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132600: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132604: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132608: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x8013260C: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80132610: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80132614: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132618: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x8013261C: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132620: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80132624: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132628: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013262C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132630: lw          $t5, 0x3294($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3294);
    // 0x80132634: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132638: addiu       $t6, $t6, 0x50F8
    ctx->r14 = ADD32(ctx->r14, 0X50F8);
    // 0x8013263C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132640: jal         0x800CCFDC
    // 0x80132644: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132644: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x80132648: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x8013264C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132650: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132654: addiu       $v1, $zero, 0x99
    ctx->r3 = ADD32(0, 0X99);
    // 0x80132658: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x8013265C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132660: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80132664: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132668: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013266C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132670: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132674: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132678: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x8013267C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132680: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132684: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80132688: jr          $ra
    // 0x8013268C: nop

    return;
    // 0x8013268C: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueScoreDigitGetSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131CE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CE4: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131CE8: addiu       $t6, $t6, 0x41A8
    ctx->r14 = ADD32(ctx->r14, 0X41A8);
    // 0x80131CEC: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131CF0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131CF4:
    // 0x80131CF4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131CF8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131CFC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131D00: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131D04: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131D08: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131D0C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131D10: bne         $t6, $t0, L_80131CF4
    if (ctx->r14 != ctx->r8) {
        // 0x80131D14: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131CF4;
    }
    // 0x80131D14: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131D18: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D1C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80131D20: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80131D24: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131D28: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131D2C: lw          $t4, 0x4534($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4534);
    // 0x80131D30: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80131D34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D38: jr          $ra
    // 0x80131D3C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    return;
    // 0x80131D3C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
;}
RECOMP_FUNC void SC1PGameBossWallpaper1ProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019149C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801914A0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801914A4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801914A8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801914AC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801914B0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801914B4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801914B8: beq         $v0, $zero, L_801914D4
    if (ctx->r2 == 0) {
        // 0x801914BC: lui         $t2, 0xE300
        ctx->r10 = S32(0XE300 << 16);
            goto L_801914D4;
    }
    // 0x801914BC: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x801914C0: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
L_801914C4:
    // 0x801914C4: sb          $a1, 0x5B($t6)
    MEM_B(0X5B, ctx->r14) = ctx->r5;
    // 0x801914C8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x801914CC: bnel        $v0, $zero, L_801914C4
    if (ctx->r2 != 0) {
        // 0x801914D0: lw          $t6, 0x80($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X80);
            goto L_801914C4;
    }
    goto skip_0;
    // 0x801914D0: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    skip_0:
L_801914D4:
    // 0x801914D4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801914D8: ori         $t2, $t2, 0xA01
    ctx->r10 = ctx->r10 | 0XA01;
    // 0x801914DC: lui         $t3, 0x10
    ctx->r11 = S32(0X10 << 16);
    // 0x801914E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801914E4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801914E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801914EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801914F0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801914F4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x801914F8: lui         $t6, 0xC18
    ctx->r14 = S32(0XC18 << 16);
    // 0x801914FC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80191500: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80191504: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80191508: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019150C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191510: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80191514: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80191518: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019151C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80191520: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191524: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80191528: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8019152C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80191530: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80191534: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191538: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8019153C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80191540: jal         0x80014768
    // 0x80191544: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80191544: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_0:
    // 0x80191548: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8019154C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80191550: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191554: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x80191558: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x8019155C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80191560: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80191564: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191568: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019156C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191570: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80191574: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80191578: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019157C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80191580: ori         $t6, $t6, 0x49D8
    ctx->r14 = ctx->r14 | 0X49D8;
    // 0x80191584: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80191588: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019158C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80191590: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191594: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80191598: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019159C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801915A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801915A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801915A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801915AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801915B0: jr          $ra
    // 0x801915B4: nop

    return;
    // 0x801915B4: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeBonusCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013497C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80134980: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134984: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134988: addiu       $t7, $t7, -0x74E4
    ctx->r15 = ADD32(ctx->r15, -0X74E4);
    // 0x8013498C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134990: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134994: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80134998: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013499C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801349A0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801349A4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801349A8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801349AC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801349B0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801349B4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801349B8: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801349BC: jal         0x80135F34
    // 0x801349C0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    mnPlayers1PGameGetForcePuckFighterKind(rdram, ctx);
        goto after_0;
    // 0x801349C0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    after_0:
    // 0x801349C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801349C8: lw          $a0, -0x7050($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7050);
    // 0x801349CC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801349D0: beql        $a0, $zero, L_801349EC
    if (ctx->r4 == 0) {
        // 0x801349D4: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_801349EC;
    }
    goto skip_0;
    // 0x801349D4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801349D8: jal         0x80009A84
    // 0x801349DC: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x801349DC: nop

    after_1:
    // 0x801349E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801349E4: sw          $zero, -0x7050($at)
    MEM_W(-0X7050, ctx->r1) = 0;
    // 0x801349E8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_801349EC:
    // 0x801349EC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801349F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801349F4: beq         $t0, $at, L_80134B2C
    if (ctx->r8 == ctx->r1) {
        // 0x801349F8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80134B2C;
    }
    // 0x801349F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801349FC: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80134A00: jal         0x80009968
    // 0x80134A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80134A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80134A08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134A0C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134A10: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80134A14: sw          $v0, -0x7050($at)
    MEM_W(-0X7050, ctx->r1) = ctx->r2;
    // 0x80134A18: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80134A1C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80134A20: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134A24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134A28: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80134A2C: jal         0x80009DF4
    // 0x80134A30: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80134A30: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80134A34: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80134A38: lw          $t2, -0x694C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X694C);
    // 0x80134A3C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80134A40: addiu       $t3, $t3, 0x368
    ctx->r11 = ADD32(ctx->r11, 0X368);
    // 0x80134A44: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80134A48: jal         0x800CCFDC
    // 0x80134A4C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80134A4C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_4:
    // 0x80134A50: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80134A54: lui         $at, 0x4381
    ctx->r1 = S32(0X4381 << 16);
    // 0x80134A58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134A5C: lui         $at, 0x4347
    ctx->r1 = S32(0X4347 << 16);
    // 0x80134A60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134A64: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80134A68: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80134A6C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80134A70: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80134A74: addiu       $t9, $zero, 0x6F
    ctx->r25 = ADD32(0, 0X6F);
    // 0x80134A78: addiu       $t0, $zero, 0xCD
    ctx->r8 = ADD32(0, 0XCD);
    // 0x80134A7C: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80134A80: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x80134A84: sb          $t9, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r25;
    // 0x80134A88: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    // 0x80134A8C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134A90: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80134A94: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80134A98: lw          $t1, -0x694C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X694C);
    // 0x80134A9C: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80134AA0: addiu       $t2, $t2, 0x2C8
    ctx->r10 = ADD32(ctx->r10, 0X2C8);
    // 0x80134AA4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80134AA8: jal         0x800CCFDC
    // 0x80134AAC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80134AAC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_5:
    // 0x80134AB0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80134AB4: lui         $at, 0x438F
    ctx->r1 = S32(0X438F << 16);
    // 0x80134AB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134ABC: lui         $at, 0x4347
    ctx->r1 = S32(0X4347 << 16);
    // 0x80134AC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134AC4: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80134AC8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80134ACC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80134AD0: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80134AD4: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x80134AD8: addiu       $t9, $zero, 0xCD
    ctx->r25 = ADD32(0, 0XCD);
    // 0x80134ADC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80134AE0: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80134AE4: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80134AE8: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80134AEC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80134AF0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80134AF4: jal         0x80134968
    // 0x80134AF8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    mnPlayers1PGameGetBonusCount(rdram, ctx);
        goto after_6;
    // 0x80134AF8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80134AFC: lui         $a2, 0x438E
    ctx->r6 = S32(0X438E << 16);
    // 0x80134B00: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x80134B04: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80134B08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134B0C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80134B10: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80134B14: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80134B18: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80134B1C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80134B20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134B24: jal         0x80131CEC
    // 0x80134B28: lui         $a3, 0x4346
    ctx->r7 = S32(0X4346 << 16);
    mnPlayers1PGameMakeNumber(rdram, ctx);
        goto after_7;
    // 0x80134B28: lui         $a3, 0x4346
    ctx->r7 = S32(0X4346 << 16);
    after_7:
L_80134B2C:
    // 0x80134B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134B30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80134B34: jr          $ra
    // 0x80134B38: nop

    return;
    // 0x80134B38: nop

;}
RECOMP_FUNC void syMatrixFastSin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A054: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001A058: lwc1        $f4, -0x1C60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C60);
    // 0x8001A05C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001A060: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001A064: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001A068: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8001A06C: nop

    // 0x8001A070: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8001A074: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001A078: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A07C: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x8001A080: beq         $t9, $zero, L_8001A090
    if (ctx->r25 == 0) {
        // 0x8001A084: lhu         $v1, -0x46B0($v1)
        ctx->r3 = MEM_HU(ctx->r3, -0X46B0);
            goto L_8001A090;
    }
    // 0x8001A084: lhu         $v1, -0x46B0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X46B0);
    // 0x8001A088: jr          $ra
    // 0x8001A08C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    return;
    // 0x8001A08C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8001A090:
    // 0x8001A090: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A094: jr          $ra
    // 0x8001A098: nop

    return;
    // 0x8001A098: nop

;}
RECOMP_FUNC void grDisplayLayer1PriProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104FD8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80104FDC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80104FE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80104FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104FEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80104FF0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80104FF4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80104FF8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80104FFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80105000: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105004: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x80105008: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8010500C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80105010: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80105014: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80105018: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010501C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105020: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80105024: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x80105028: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8010502C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80105030: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80105034: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x80105038: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8010503C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80105040: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80105044: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80105048: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8010504C: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x80105050: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80105054: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80105058: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8010505C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80105060: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80105064: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80105068: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8010506C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80105070: jal         0x80014038
    // 0x80105074: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80105074: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    after_0:
    // 0x80105078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010507C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105080: jr          $ra
    // 0x80105084: nop

    return;
    // 0x80105084: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser2DProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107038: jal         0x80167C04
    // 0x8010703C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8010703C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80107040: beq         $v0, $zero, L_80107060
    if (ctx->r2 == 0) {
        // 0x80107044: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80107060;
    }
    // 0x80107044: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80107048: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8010704C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80107050: jal         0x800FF648
    // 0x80107054: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80107054: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80107058: b           L_80107064
    // 0x8010705C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80107064;
    // 0x8010705C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80107060:
    // 0x80107060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80107064:
    // 0x80107064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010706C: jr          $ra
    // 0x80107070: nop

    return;
    // 0x80107070: nop

;}
RECOMP_FUNC void ftCommonGuardCheckScheduleRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148120: lhu         $t6, 0x1BC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80148124: lhu         $t7, 0x1B8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80148128: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014812C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80148130: bne         $t8, $zero, L_8014813C
    if (ctx->r24 != 0) {
        // 0x80148134: nop
    
            goto L_8014813C;
    }
    // 0x80148134: nop

    // 0x80148138: sw          $t9, 0xB24($a0)
    MEM_W(0XB24, ctx->r4) = ctx->r25;
L_8014813C:
    // 0x8014813C: jr          $ra
    // 0x80148140: nop

    return;
    // 0x80148140: nop

;}
RECOMP_FUNC void ftBossOkupunch3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AA34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015AA38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015AA3C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015AA40: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8015AA44: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    // 0x8015AA48: sw          $t6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r14;
    // 0x8015AA4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015AA50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015AA54: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015AA58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015AA5C: jal         0x800E6F24
    // 0x8015AA60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AA60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015AA64: jal         0x800E0830
    // 0x8015AA68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015AA68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015AA6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8015AA70: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8015AA74: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015AA78: lwc1        $f4, 0xB18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x8015AA7C: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x8015AA80: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8015AA84: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8015AA88: lwc1        $f8, -0x37C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37C0);
    // 0x8015AA8C: lwc1        $f6, 0xB1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB1C);
    // 0x8015AA90: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x8015AA94: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8015AA98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8015AA9C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8015AAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015AAA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015AAA8: jr          $ra
    // 0x8015AAAC: nop

    return;
    // 0x8015AAAC: nop

;}
RECOMP_FUNC void spHide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F18: jal         0x80023870
    // 0x80025F1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    spSetAttribute(rdram, ctx);
        goto after_0;
    // 0x80025F1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80025F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025F28: jr          $ra
    // 0x80025F2C: nop

    return;
    // 0x80025F2C: nop

;}
RECOMP_FUNC void func_ovl8_80386540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80386544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80386548: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8038654C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386550: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80386554: lui         $a0, 0x4B79
    ctx->r4 = S32(0X4B79 << 16);
    // 0x80386558: ori         $a0, $a0, 0x576E
    ctx->r4 = ctx->r4 | 0X576E;
    // 0x8038655C: jal         0x80381B70
    // 0x80386560: addiu       $a1, $a1, 0x67E8
    ctx->r5 = ADD32(ctx->r5, 0X67E8);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_0;
    // 0x80386560: addiu       $a1, $a1, 0x67E8
    ctx->r5 = ADD32(ctx->r5, 0X67E8);
    after_0:
    // 0x80386564: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80386568: addiu       $a0, $a0, -0x7D68
    ctx->r4 = ADD32(ctx->r4, -0X7D68);
    // 0x8038656C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80386570: jal         0x803865D0
    // 0x80386574: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_803865D0(rdram, ctx);
        goto after_1;
    // 0x80386574: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80386578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038657C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80386580: jr          $ra
    // 0x80386584: nop

    return;
    // 0x80386584: nop

;}
RECOMP_FUNC void ftDonkeyThrowFDamageProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E058: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E05C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014E060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014E064: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8014E068: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014E06C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8014E070: nop

    // 0x8014E074: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014E078: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8014E07C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8014E080: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8014E084: nop

    // 0x8014E088: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8014E08C: sw          $t9, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r25;
    // 0x8014E090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014E094: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x8014E098: nop

    // 0x8014E09C: bc1fl       L_8014E0D4
    if (!c1cs) {
        // 0x8014E0A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014E0D4;
    }
    goto skip_0;
    // 0x8014E0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014E0A4: lw          $t0, 0x14C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14C);
    // 0x8014E0A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014E0AC: bne         $t0, $at, L_8014E0C8
    if (ctx->r8 != ctx->r1) {
        // 0x8014E0B0: nop
    
            goto L_8014E0C8;
    }
    // 0x8014E0B0: nop

    // 0x8014E0B4: lwc1        $f8, 0xB20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB20);
    // 0x8014E0B8: jal         0x8014DA98
    // 0x8014E0BC: swc1        $f8, 0x82C($v0)
    MEM_W(0X82C, ctx->r2) = ctx->f8.u32l;
    ftDonkeyThrowFFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E0BC: swc1        $f8, 0x82C($v0)
    MEM_W(0X82C, ctx->r2) = ctx->f8.u32l;
    after_0:
    // 0x8014E0C0: b           L_8014E0D4
    // 0x8014E0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E0D4;
    // 0x8014E0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E0C8:
    // 0x8014E0C8: jal         0x8014D49C
    // 0x8014E0CC: nop

    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014E0CC: nop

    after_1:
    // 0x8014E0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E0D4:
    // 0x8014E0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E0D8: jr          $ra
    // 0x8014E0DC: nop

    return;
    // 0x8014E0DC: nop

;}

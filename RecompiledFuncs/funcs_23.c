#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSModeSetCostumesAndShades(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133A90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133A94: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x80133A98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133A9C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80133AA0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80133AA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133AA8: beq         $v0, $zero, L_80133AD8
    if (ctx->r2 == 0) {
        // 0x80133AAC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80133AD8;
    }
    // 0x80133AAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133AB4: beq         $v0, $at, L_80133AD8
    if (ctx->r2 == ctx->r1) {
        // 0x80133AB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80133AD8;
    }
    // 0x80133AB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133ABC: beq         $v0, $at, L_80133B30
    if (ctx->r2 == ctx->r1) {
        // 0x80133AC0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80133B30;
    }
    // 0x80133AC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80133AC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133AC8: beq         $v0, $at, L_80133B30
    if (ctx->r2 == ctx->r1) {
        // 0x80133ACC: nop
    
            goto L_80133B30;
    }
    // 0x80133ACC: nop

    // 0x80133AD0: b           L_80133B74
    // 0x80133AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80133B74;
    // 0x80133AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80133AD8:
    // 0x80133AD8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80133ADC: addiu       $s0, $s0, 0x4D08
    ctx->r16 = ADD32(ctx->r16, 0X4D08);
    // 0x80133AE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80133AE4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80133AE8: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
L_80133AEC:
    // 0x80133AEC: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    // 0x80133AF0: beql        $s2, $a0, L_80133B20
    if (ctx->r18 == ctx->r4) {
        // 0x80133AF4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80133B20;
    }
    goto skip_0;
    // 0x80133AF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80133AF8: jal         0x8013394C
    // 0x80133AFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnVSModeGetCostume(rdram, ctx);
        goto after_0;
    // 0x80133AFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80133B00: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    // 0x80133B04: jal         0x800EC0EC
    // 0x80133B08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x80133B08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80133B0C: sb          $v0, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r2;
    // 0x80133B10: jal         0x80133850
    // 0x80133B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnVSModeGetShade(rdram, ctx);
        goto after_2;
    // 0x80133B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80133B18: sb          $v0, 0x27($s0)
    MEM_B(0X27, ctx->r16) = ctx->r2;
    // 0x80133B1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133B20:
    // 0x80133B20: bne         $s1, $s3, L_80133AEC
    if (ctx->r17 != ctx->r19) {
        // 0x80133B24: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_80133AEC;
    }
    // 0x80133B24: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x80133B28: b           L_80133B74
    // 0x80133B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80133B74;
    // 0x80133B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80133B30:
    // 0x80133B30: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80133B34: addiu       $s0, $s0, 0x4D08
    ctx->r16 = ADD32(ctx->r16, 0X4D08);
    // 0x80133B38: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80133B3C: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
L_80133B40:
    // 0x80133B40: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    // 0x80133B44: beql        $s2, $a0, L_80133B68
    if (ctx->r18 == ctx->r4) {
        // 0x80133B48: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80133B68;
    }
    goto skip_1;
    // 0x80133B48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80133B4C: jal         0x800EC104
    // 0x80133B50: lbu         $a1, 0x24($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X24);
    ftParamGetCostumeTeamID(rdram, ctx);
        goto after_3;
    // 0x80133B50: lbu         $a1, 0x24($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X24);
    after_3:
    // 0x80133B54: sb          $v0, 0x26($s0)
    MEM_B(0X26, ctx->r16) = ctx->r2;
    // 0x80133B58: jal         0x80133850
    // 0x80133B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnVSModeGetShade(rdram, ctx);
        goto after_4;
    // 0x80133B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80133B60: sb          $v0, 0x27($s0)
    MEM_B(0X27, ctx->r16) = ctx->r2;
    // 0x80133B64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80133B68:
    // 0x80133B68: bne         $s1, $s3, L_80133B40
    if (ctx->r17 != ctx->r19) {
        // 0x80133B6C: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_80133B40;
    }
    // 0x80133B6C: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x80133B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80133B74:
    // 0x80133B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80133B78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80133B7C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80133B80: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80133B84: jr          $ra
    // 0x80133B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80133B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efDisplayInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD18C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FD190: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800FD194: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x800FD198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FD19C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800FD1A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800FD1A4: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FD1A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FD1AC: jal         0x80009968
    // 0x800FD1B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800FD1B0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x800FD1B4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FD1B8: addiu       $a1, $a1, -0x3034
    ctx->r5 = ADD32(ctx->r5, -0X3034);
    // 0x800FD1BC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800FD1C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FD1C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800FD1C8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800FD1CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD1D0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x800FD1D4: jal         0x80009DF4
    // 0x800FD1D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800FD1D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800FD1DC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800FD1E0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800FD1E4: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x800FD1E8: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800FD1EC: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FD1F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FD1F4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FD1F8: jal         0x80009968
    // 0x800FD1FC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x800FD1FC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
    // 0x800FD200: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FD204: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FD208: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800FD20C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD210: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800FD214: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800FD218: jal         0x80009DF4
    // 0x800FD21C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x800FD21C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800FD220: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800FD224: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800FD228: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x800FD22C: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800FD230: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x800FD234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FD238: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800FD23C: jal         0x80009968
    // 0x800FD240: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x800FD240: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x800FD244: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FD248: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800FD24C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FD250: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800FD254: addiu       $a1, $a1, -0x3114
    ctx->r5 = ADD32(ctx->r5, -0X3114);
    // 0x800FD258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD25C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x800FD260: jal         0x80009DF4
    // 0x800FD264: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x800FD264: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x800FD268: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800FD26C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800FD270: sw          $t5, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r13;
    // 0x800FD274: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800FD278: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FD27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FD280: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FD284: jal         0x80009968
    // 0x800FD288: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_6;
    // 0x800FD288: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x800FD28C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FD290: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800FD294: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FD298: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800FD29C: addiu       $a1, $a1, -0x2F54
    ctx->r5 = ADD32(ctx->r5, -0X2F54);
    // 0x800FD2A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD2A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800FD2A8: jal         0x80009DF4
    // 0x800FD2AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_7;
    // 0x800FD2AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x800FD2B0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800FD2B4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800FD2B8: lui         $a0, 0xAC
    ctx->r4 = S32(0XAC << 16);
    // 0x800FD2BC: lui         $a1, 0xAD
    ctx->r5 = S32(0XAD << 16);
    // 0x800FD2C0: lui         $a2, 0xAD
    ctx->r6 = S32(0XAD << 16);
    // 0x800FD2C4: lui         $a3, 0xB1
    ctx->r7 = S32(0XB1 << 16);
    // 0x800FD2C8: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
    // 0x800FD2CC: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x800FD2D0: addiu       $a3, $a3, 0x6C80
    ctx->r7 = ADD32(ctx->r7, 0X6C80);
    // 0x800FD2D4: addiu       $a2, $a2, -0x6220
    ctx->r6 = ADD32(ctx->r6, -0X6220);
    // 0x800FD2D8: addiu       $a1, $a1, -0x6220
    ctx->r5 = ADD32(ctx->r5, -0X6220);
    // 0x800FD2DC: jal         0x801159F8
    // 0x800FD2E0: addiu       $a0, $a0, 0x7340
    ctx->r4 = ADD32(ctx->r4, 0X7340);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_8;
    // 0x800FD2E0: addiu       $a0, $a0, 0x7340
    ctx->r4 = ADD32(ctx->r4, 0X7340);
    after_8:
    // 0x800FD2E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FD2E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD2EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800FD2F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800FD2F4: sw          $v0, 0x13C4($at)
    MEM_W(0X13C4, ctx->r1) = ctx->r2;
    // 0x800FD2F8: jr          $ra
    // 0x800FD2FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FD2FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayersVSGetNumberDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133B08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133B0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133B10: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80133B14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133B18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133B1C: blez        $a1, L_80133B94
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80133B20: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80133B94;
    }
    // 0x80133B20: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80133B24:
    // 0x80133B24: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80133B28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80133B2C: jal         0x80133A1C
    // 0x80133B30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnPlayersVSGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80133B30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80133B34: beq         $v0, $zero, L_80133B7C
    if (ctx->r2 == 0) {
        // 0x80133B38: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80133B7C;
    }
    // 0x80133B38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80133B3C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80133B40: jal         0x80133A1C
    // 0x80133B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80133B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80133B48: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80133B4C: mflo        $v1
    ctx->r3 = lo;
    // 0x80133B50: bne         $v0, $zero, L_80133B5C
    if (ctx->r2 != 0) {
        // 0x80133B54: nop
    
            goto L_80133B5C;
    }
    // 0x80133B54: nop

    // 0x80133B58: break       7
    do_break(2148744024);
L_80133B5C:
    // 0x80133B5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133B60: bne         $v0, $at, L_80133B74
    if (ctx->r2 != ctx->r1) {
        // 0x80133B64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133B74;
    }
    // 0x80133B64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133B68: bne         $s2, $at, L_80133B74
    if (ctx->r18 != ctx->r1) {
        // 0x80133B6C: nop
    
            goto L_80133B74;
    }
    // 0x80133B6C: nop

    // 0x80133B70: break       6
    do_break(2148744048);
L_80133B74:
    // 0x80133B74: b           L_80133B7C
    // 0x80133B78: nop

        goto L_80133B7C;
    // 0x80133B78: nop

L_80133B7C:
    // 0x80133B7C: beq         $v1, $zero, L_80133B8C
    if (ctx->r3 == 0) {
        // 0x80133B80: nop
    
            goto L_80133B8C;
    }
    // 0x80133B80: nop

    // 0x80133B84: b           L_80133B98
    // 0x80133B88: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80133B98;
    // 0x80133B88: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80133B8C:
    // 0x80133B8C: bne         $s0, $zero, L_80133B24
    if (ctx->r16 != 0) {
        // 0x80133B90: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80133B24;
    }
    // 0x80133B90: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80133B94:
    // 0x80133B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133B98:
    // 0x80133B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133B9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133BA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133BA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133BA8: jr          $ra
    // 0x80133BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80133BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PGameMakeStockOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013434C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013435C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80134360: jal         0x80009968
    // 0x80134364: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134364: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134368: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013436C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134370: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80134374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134378: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013437C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134380: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80134384: jal         0x80009DF4
    // 0x80134388: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134388: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013438C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134390: addiu       $a1, $a1, 0x3FA4
    ctx->r5 = ADD32(ctx->r5, 0X3FA4);
    // 0x80134394: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80134398: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013439C: jal         0x80008188
    // 0x801343A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801343A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801343A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801343A8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801343AC: lw          $a1, -0x70F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X70F8);
    // 0x801343B0: jal         0x8013419C
    // 0x801343B4: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_3;
    // 0x801343B4: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    after_3:
    // 0x801343B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801343BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801343C0: jr          $ra
    // 0x801343C4: nop

    return;
    // 0x801343C4: nop

;}
RECOMP_FUNC void mvEndingMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F24: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131F28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80131F2C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80131F30: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80131F34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80131F38: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x80131F3C: addiu       $v0, $v0, 0x2C08
    ctx->r2 = ADD32(ctx->r2, 0X2C08);
    // 0x80131F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131F44: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x80131F48: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_80131F4C:
    // 0x80131F4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F50: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131F54: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131F58: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131F5C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131F60: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131F64: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131F68: bne         $t6, $t0, L_80131F4C
    if (ctx->r14 != ctx->r8) {
        // 0x80131F6C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131F4C;
    }
    // 0x80131F6C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131F70: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F78: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131F7C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131F80: lwc1        $f4, 0x2BB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2BB0);
    // 0x80131F84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F88: lwc1        $f6, 0x2BB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2BB4);
    // 0x80131F8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F90: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80131F94: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80131F98: lw          $t3, 0x2BC8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2BC8);
    // 0x80131F9C: lwc1        $f8, 0x2BB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2BB8);
    // 0x80131FA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80131FA4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80131FA8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80131FAC: sb          $t1, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r9;
    // 0x80131FB0: sb          $t2, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r10;
    // 0x80131FB4: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80131FB8: jal         0x800D7F3C
    // 0x80131FBC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_0;
    // 0x80131FBC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80131FC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FC4: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131FC8: sw          $v0, 0x2BDC($at)
    MEM_W(0X2BDC, ctx->r1) = ctx->r2;
    // 0x80131FCC: ori         $a1, $a1, 0x9
    ctx->r5 = ctx->r5 | 0X9;
    // 0x80131FD0: jal         0x803905CC
    // 0x80131FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x80131FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80131FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131FDC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131FE0: jr          $ra
    // 0x80131FE4: nop

    return;
    // 0x80131FE4: nop

;}
RECOMP_FUNC void ftCommonCaptureKirbyUpdatePositionsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B774: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014B778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014B77C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014B780: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014B784: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014B788: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014B78C: lw          $t6, 0x844($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X844);
    // 0x8014B790: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8014B794: lw          $a3, 0x84($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X84);
    // 0x8014B798: lwc1        $f4, 0xB1C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XB1C);
    // 0x8014B79C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8014B7A0: lwc1        $f6, 0xB20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB20);
    // 0x8014B7A4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8014B7A8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8014B7AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8014B7B0: jal         0x8014B700
    // 0x8014B7B4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    ftCommonCaptureKirbyUpdatePositionsMag(rdram, ctx);
        goto after_0;
    // 0x8014B7B4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8014B7B8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014B7BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8014B7C0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8014B7C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8014B7C8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8014B7CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8014B7D0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8014B7D4: bc1fl       L_8014B7E8
    if (!c1cs) {
        // 0x8014B7D8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8014B7E8;
    }
    goto skip_0;
    // 0x8014B7D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x8014B7DC: b           L_8014B7E8
    // 0x8014B7E0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8014B7E8;
    // 0x8014B7E0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8014B7E4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8014B7E8:
    // 0x8014B7E8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8014B7EC: nop

    // 0x8014B7F0: bc1fl       L_8014B828
    if (!c1cs) {
        // 0x8014B7F4: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8014B828;
    }
    goto skip_1;
    // 0x8014B7F4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8014B7F8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8014B7FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014B800: bc1f        L_8014B810
    if (!c1cs) {
        // 0x8014B804: nop
    
            goto L_8014B810;
    }
    // 0x8014B804: nop

    // 0x8014B808: b           L_8014B810
    // 0x8014B80C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8014B810;
    // 0x8014B80C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8014B810:
    // 0x8014B810: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8014B814: nop

    // 0x8014B818: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8014B81C: mul.s       $f2, $f16, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8014B820: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8014B824: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_8014B828:
    // 0x8014B828: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8014B82C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8014B830: nop

    // 0x8014B834: bc1fl       L_8014B848
    if (!c1cs) {
        // 0x8014B838: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8014B848;
    }
    goto skip_2;
    // 0x8014B838: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x8014B83C: b           L_8014B848
    // 0x8014B840: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8014B848;
    // 0x8014B840: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8014B844: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8014B848:
    // 0x8014B848: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8014B84C: nop

    // 0x8014B850: bc1fl       L_8014B888
    if (!c1cs) {
        // 0x8014B854: lwc1        $f6, 0xB1C($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0XB1C);
            goto L_8014B888;
    }
    goto skip_3;
    // 0x8014B854: lwc1        $f6, 0xB1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB1C);
    skip_3:
    // 0x8014B858: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8014B85C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014B860: bc1f        L_8014B870
    if (!c1cs) {
        // 0x8014B864: nop
    
            goto L_8014B870;
    }
    // 0x8014B864: nop

    // 0x8014B868: b           L_8014B870
    // 0x8014B86C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8014B870;
    // 0x8014B86C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8014B870:
    // 0x8014B870: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8014B874: nop

    // 0x8014B878: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014B87C: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8014B880: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8014B884: lwc1        $f6, 0xB1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB1C);
L_8014B888:
    // 0x8014B888: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014B88C: lwc1        $f16, 0xB20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XB20);
    // 0x8014B890: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8014B894: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8014B898: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8014B89C: swc1        $f10, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->f10.u32l;
    // 0x8014B8A0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8014B8A4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8014B8A8: swc1        $f4, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->f4.u32l;
    // 0x8014B8AC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8014B8B0: lw          $a1, 0x844($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X844);
    // 0x8014B8B4: jal         0x80161DA8
    // 0x8014B8B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    ftKirbySpecialNAddCaptureDistance(rdram, ctx);
        goto after_1;
    // 0x8014B8B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8014B8BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8014B8C0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014B8C4: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8014B8C8: lwc1        $f6, 0xB1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XB1C);
    // 0x8014B8CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014B8D0: swc1        $f10, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f10.u32l;
    // 0x8014B8D4: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8014B8D8: lwc1        $f16, 0xB20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XB20);
    // 0x8014B8DC: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x8014B8E0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8014B8E4: swc1        $f4, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f4.u32l;
    // 0x8014B8E8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8014B8EC: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8014B8F0: lw          $t1, 0x844($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X844);
    // 0x8014B8F4: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x8014B8F8: lwc1        $f6, 0x24($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X24);
    // 0x8014B8FC: swc1        $f6, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f6.u32l;
    // 0x8014B900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014B904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014B908: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014B90C: jr          $ra
    // 0x8014B910: nop

    return;
    // 0x8014B910: nop

;}
RECOMP_FUNC void lbCommonSetupTreeDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B28: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800C8B2C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C8B30: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C8B34: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C8B38: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8B3C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C8B40: andi        $s6, $a3, 0xFF
    ctx->r22 = ctx->r7 & 0XFF;
    // 0x800C8B44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C8B48: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C8B4C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C8B50: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C8B54: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C8B58: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C8B5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C8B60: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800C8B64: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800C8B68: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800C8B6C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800C8B70: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800C8B74: addiu       $v1, $sp, 0x98
    ctx->r3 = ADD32(ctx->r29, 0X98);
L_800C8B78:
    // 0x800C8B78: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C8B7C: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800C8B80: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x800C8B84: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800C8B88: bne         $v0, $v1, L_800C8B78
    if (ctx->r2 != ctx->r3) {
        // 0x800C8B8C: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_800C8B78;
    }
    // 0x800C8B8C: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800C8B90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C8B94: addiu       $fp, $zero, 0x12
    ctx->r30 = ADD32(0, 0X12);
    // 0x800C8B98: addiu       $s7, $sp, 0x50
    ctx->r23 = ADD32(ctx->r29, 0X50);
    // 0x800C8B9C: beq         $fp, $v0, L_800C8C88
    if (ctx->r30 == ctx->r2) {
        // 0x800C8BA0: lbu         $s5, 0xBF($sp)
        ctx->r21 = MEM_BU(ctx->r29, 0XBF);
            goto L_800C8C88;
    }
    // 0x800C8BA0: lbu         $s5, 0xBF($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0XBF);
    // 0x800C8BA4: lbu         $s4, 0xBB($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XBB);
    // 0x800C8BA8: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_800C8BAC:
    // 0x800C8BAC: beq         $v1, $zero, L_800C8BD0
    if (ctx->r3 == 0) {
        // 0x800C8BB0: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800C8BD0;
    }
    // 0x800C8BB0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C8BB4: addu        $s2, $s7, $t6
    ctx->r18 = ADD32(ctx->r23, ctx->r14);
    // 0x800C8BB8: lw          $a0, -0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X4);
    // 0x800C8BBC: jal         0x800093F4
    // 0x800C8BC0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x800C8BC0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_0:
    // 0x800C8BC4: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800C8BC8: b           L_800C8BE4
    // 0x800C8BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800C8BE4;
    // 0x800C8BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C8BD0:
    // 0x800C8BD0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800C8BD4: jal         0x800093F4
    // 0x800C8BD8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_1;
    // 0x800C8BD8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x800C8BDC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800C8BE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C8BE4:
    // 0x800C8BE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800C8BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8BEC: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x800C8BF0: andi        $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 & 0XF000;
    // 0x800C8BF4: beq         $v0, $zero, L_800C8C1C
    if (ctx->r2 == 0) {
        // 0x800C8BF8: andi        $a2, $s4, 0xFF
        ctx->r6 = ctx->r20 & 0XFF;
            goto L_800C8C1C;
    }
    // 0x800C8BF8: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800C8BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8C00: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x800C8C04: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x800C8C08: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    // 0x800C8C0C: jal         0x8000F364
    // 0x800C8C10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x800C8C10: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x800C8C14: b           L_800C8C28
    // 0x800C8C18: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
        goto L_800C8C28;
    // 0x800C8C18: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
L_800C8C1C:
    // 0x800C8C1C: jal         0x8000F2FC
    // 0x800C8C20: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_3;
    // 0x800C8C20: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    after_3:
    // 0x800C8C24: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
L_800C8C28:
    // 0x800C8C28: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x800C8C2C: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800C8C30: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x800C8C34: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x800C8C38: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800C8C3C: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    // 0x800C8C40: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800C8C44: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x800C8C48: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x800C8C4C: lw          $t0, 0x1C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1C);
    // 0x800C8C50: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x800C8C54: lw          $t2, 0x20($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X20);
    // 0x800C8C58: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x800C8C5C: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x800C8C60: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x800C8C64: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x800C8C68: beq         $s3, $zero, L_800C8C78
    if (ctx->r19 == 0) {
        // 0x800C8C6C: sw          $t2, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r10;
            goto L_800C8C78;
    }
    // 0x800C8C6C: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x800C8C70: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x800C8C74: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_800C8C78:
    // 0x800C8C78: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x800C8C7C: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x800C8C80: bnel        $fp, $v0, L_800C8BAC
    if (ctx->r30 != ctx->r2) {
        // 0x800C8C84: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_800C8BAC;
    }
    goto skip_0;
    // 0x800C8C84: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_0:
L_800C8C88:
    // 0x800C8C88: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C8C8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C8C90: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C8C94: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C8C98: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8C9C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C8CA0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C8CA4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C8CA8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C8CAC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C8CB0: jr          $ra
    // 0x800C8CB4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800C8CB4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ftMainUpdateMotionEventsForwardEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0654: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E0658: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E065C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800E0660: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800E0664: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800E0668: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800E066C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800E0670: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800E0674: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800E0678: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E067C: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800E0680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E0684: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800E0688: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E068C: lwc1        $f20, -0x2E0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2E0);
    // 0x800E0690: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E0694: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x800E0698: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
L_800E069C:
    // 0x800E069C: lw          $t6, 0x8AC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8AC);
    // 0x800E06A0: addiu       $s0, $s3, 0x8A8
    ctx->r16 = ADD32(ctx->r19, 0X8A8);
    // 0x800E06A4: beql        $t6, $zero, L_800E07A0
    if (ctx->r14 == 0) {
        // 0x800E06A8: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E07A0;
    }
    goto skip_0;
    // 0x800E06A8: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_0:
    // 0x800E06AC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E06B0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E06B4: nop

    // 0x800E06B8: bc1tl       L_800E06D4
    if (c1cs) {
        // 0x800E06BC: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_800E06D4;
    }
    goto skip_1;
    // 0x800E06BC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800E06C0: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x800E06C4: lwc1        $f4, 0x78($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X78);
    // 0x800E06C8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800E06CC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_800E06D0:
    // 0x800E06D0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800E06D4:
    // 0x800E06D4: beql        $v0, $zero, L_800E07A0
    if (ctx->r2 == 0) {
        // 0x800E06D8: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E07A0;
    }
    goto skip_2;
    // 0x800E06D8: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_2:
    // 0x800E06DC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E06E0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E06E4: nop

    // 0x800E06E8: bc1fl       L_800E0720
    if (!c1cs) {
        // 0x800E06EC: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_800E0720;
    }
    goto skip_3;
    // 0x800E06EC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_3:
    // 0x800E06F0: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800E06F4: lwc1        $f0, 0x78($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800E06F8: lwc1        $f8, 0x78($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X78);
    // 0x800E06FC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800E0700: nop

    // 0x800E0704: bc1tl       L_800E07A0
    if (c1cs) {
        // 0x800E0708: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E07A0;
    }
    goto skip_4;
    // 0x800E0708: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_4:
    // 0x800E070C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800E0710: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E0714: b           L_800E072C
    // 0x800E0718: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_800E072C;
    // 0x800E0718: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800E071C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_800E0720:
    // 0x800E0720: nop

    // 0x800E0724: bc1tl       L_800E07A0
    if (c1cs) {
        // 0x800E0728: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E07A0;
    }
    goto skip_5;
    // 0x800E0728: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_5:
L_800E072C:
    // 0x800E072C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E0730: srl         $a3, $a3, 26
    ctx->r7 = S32(U32(ctx->r7) >> 26);
    // 0x800E0734: sltiu       $at, $a3, 0x2F
    ctx->r1 = ctx->r7 < 0X2F ? 1 : 0;
    // 0x800E0738: beq         $at, $zero, L_800E0790
    if (ctx->r1 == 0) {
        // 0x800E073C: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800E0790;
    }
    // 0x800E073C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800E0740: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E0744: addu        $at, $at, $t9
    gpr jr_addend_800E074C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800E0748: lw          $t9, -0x2DC($at)
    ctx->r25 = ADD32(ctx->r1, -0X2DC);
    // 0x800E074C: jr          $t9
    // 0x800E0750: nop

    switch (jr_addend_800E074C >> 2) {
        case 0: goto L_800E0754; break;
        case 1: goto L_800E0754; break;
        case 2: goto L_800E0754; break;
        case 3: goto L_800E076C; break;
        case 4: goto L_800E076C; break;
        case 5: goto L_800E0790; break;
        case 6: goto L_800E0790; break;
        case 7: goto L_800E0778; break;
        case 8: goto L_800E0790; break;
        case 9: goto L_800E0790; break;
        case 10: goto L_800E0790; break;
        case 11: goto L_800E0790; break;
        case 12: goto L_800E0778; break;
        case 13: goto L_800E0754; break;
        case 14: goto L_800E0790; break;
        case 15: goto L_800E0790; break;
        case 16: goto L_800E0790; break;
        case 17: goto L_800E0790; break;
        case 18: goto L_800E0790; break;
        case 19: goto L_800E0790; break;
        case 20: goto L_800E0790; break;
        case 21: goto L_800E0790; break;
        case 22: goto L_800E0790; break;
        case 23: goto L_800E0790; break;
        case 24: goto L_800E0790; break;
        case 25: goto L_800E0790; break;
        case 26: goto L_800E0790; break;
        case 27: goto L_800E0790; break;
        case 28: goto L_800E0790; break;
        case 29: goto L_800E0790; break;
        case 30: goto L_800E0790; break;
        case 31: goto L_800E0784; break;
        case 32: goto L_800E0754; break;
        case 33: goto L_800E0754; break;
        case 34: goto L_800E0754; break;
        case 35: goto L_800E0754; break;
        case 36: goto L_800E0754; break;
        case 37: goto L_800E0754; break;
        case 38: goto L_800E0754; break;
        case 39: goto L_800E0754; break;
        case 40: goto L_800E0790; break;
        case 41: goto L_800E0790; break;
        case 42: goto L_800E0790; break;
        case 43: goto L_800E0790; break;
        case 44: goto L_800E0790; break;
        case 45: goto L_800E0790; break;
        case 46: goto L_800E0778; break;
        default: switch_error(__func__, 0x800E074C, 0x8012FD24);
    }
    // 0x800E0750: nop

L_800E0754:
    // 0x800E0754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E0758: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E075C: jal         0x800DF0F0
    // 0x800E0760: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    ftMainParseMotionEvent(rdram, ctx);
        goto after_0;
    // 0x800E0760: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800E0764: b           L_800E06D4
    // 0x800E0768: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
        goto L_800E06D4;
    // 0x800E0768: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800E076C:
    // 0x800E076C: addiu       $t0, $v0, 0x14
    ctx->r8 = ADD32(ctx->r2, 0X14);
    // 0x800E0770: b           L_800E06D0
    // 0x800E0774: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
        goto L_800E06D0;
    // 0x800E0774: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_800E0778:
    // 0x800E0778: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800E077C: b           L_800E06D0
    // 0x800E0780: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_800E06D0;
    // 0x800E0780: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_800E0784:
    // 0x800E0784: addiu       $t2, $v0, 0x10
    ctx->r10 = ADD32(ctx->r2, 0X10);
    // 0x800E0788: b           L_800E06D0
    // 0x800E078C: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
        goto L_800E06D0;
    // 0x800E078C: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
L_800E0790:
    // 0x800E0790: addiu       $t3, $v0, 0x4
    ctx->r11 = ADD32(ctx->r2, 0X4);
    // 0x800E0794: b           L_800E06D0
    // 0x800E0798: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
        goto L_800E06D0;
    // 0x800E0798: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E079C: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
L_800E07A0:
    // 0x800E07A0: bne         $s4, $s5, L_800E069C
    if (ctx->r20 != ctx->r21) {
        // 0x800E07A4: addiu       $s3, $s3, 0x20
        ctx->r19 = ADD32(ctx->r19, 0X20);
            goto L_800E069C;
    }
    // 0x800E07A4: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800E07A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E07AC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E07B0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800E07B4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800E07B8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800E07BC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800E07C0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800E07C4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800E07C8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800E07CC: jr          $ra
    // 0x800E07D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E07D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftPikachuSpecialHiStartInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152934: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152938: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015293C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80152940: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80152944: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x80152948: sw          $zero, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = 0;
    // 0x8015294C: sw          $zero, 0xB2C($v0)
    MEM_W(0XB2C, ctx->r2) = 0;
    // 0x80152950: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80152954: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80152958: jr          $ra
    // 0x8015295C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8015295C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void itEggWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801816E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801816E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801816E8: jal         0x80172E74
    // 0x801816EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x801816EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801816F0: jal         0x801816B8
    // 0x801816F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itEggWaitSetModelVars(rdram, ctx);
        goto after_1;
    // 0x801816F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801816F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801816FC: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80181700: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80181704: jal         0x80172EC8
    // 0x80181708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80181708: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8018170C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181714: jr          $ra
    // 0x80181718: nop

    return;
    // 0x80181718: nop

;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E68C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001E690: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001E694: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001E698: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E69C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E6A0: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8001E6A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001E6A8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8001E6AC: blez        $t6, L_8001E6EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001E6B0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001E6EC;
    }
    // 0x8001E6B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001E6B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E6B8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_8001E6BC:
    // 0x8001E6BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001E6C0: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x8001E6C4: beq         $a0, $zero, L_8001E6D4
    if (ctx->r4 == 0) {
        // 0x8001E6C8: sw          $a0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r4;
            goto L_8001E6D4;
    }
    // 0x8001E6C8: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x8001E6CC: jal         0x8001E708
    // 0x8001E6D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    syAudioBnkfPatchBank(rdram, ctx);
        goto after_0;
    // 0x8001E6D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
L_8001E6D4:
    // 0x8001E6D4: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x8001E6D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001E6DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E6E0: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001E6E4: bnel        $at, $zero, L_8001E6BC
    if (ctx->r1 != 0) {
        // 0x8001E6E8: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_8001E6BC;
    }
    goto skip_0;
    // 0x8001E6E8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_0:
L_8001E6EC:
    // 0x8001E6EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001E6F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001E6F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001E6F8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E6FC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001E700: jr          $ra
    // 0x8001E704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001E704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PIntroMakePicturesCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801344CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801344D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801344D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801344D8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801344DC: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801344E0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801344E4: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801344E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801344EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801344F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801344F4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801344F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801344FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134500: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134504: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134508: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013450C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134510: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134514: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134518: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013451C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80134520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134524: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134528: jal         0x8000B93C
    // 0x8013452C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013452C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134530: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134534: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134538: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013453C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134540: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134544: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134548: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013454C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134550: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134554: jal         0x80007080
    // 0x80134558: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134558: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013455C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134560: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134564: jr          $ra
    // 0x80134568: nop

    return;
    // 0x80134568: nop

;}
RECOMP_FUNC void func_ovl8_8037D28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D28C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037D290: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8037D294: lb          $a0, 0x5478($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5478);
    // 0x8037D298: lh          $v0, -0x579C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X579C);
    // 0x8037D29C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037D2A0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8037D2A4: beq         $at, $zero, L_8037D2B0
    if (ctx->r1 == 0) {
        // 0x8037D2A8: negu        $a1, $v0
        ctx->r5 = SUB32(0, ctx->r2);
            goto L_8037D2B0;
    }
    // 0x8037D2A8: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // 0x8037D2AC: lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
L_8037D2B0:
    // 0x8037D2B0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8037D2B4: beq         $at, $zero, L_8037D2C4
    if (ctx->r1 == 0) {
        // 0x8037D2B8: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_8037D2C4;
    }
    // 0x8037D2B8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8037D2BC: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8037D2C0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_8037D2C4:
    // 0x8037D2C4: lb          $a0, 0x5479($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5479);
    // 0x8037D2C8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8037D2CC: beq         $at, $zero, L_8037D2D8
    if (ctx->r1 == 0) {
        // 0x8037D2D0: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8037D2D8;
    }
    // 0x8037D2D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8037D2D4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_8037D2D8:
    // 0x8037D2D8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8037D2DC: beq         $at, $zero, L_8037D2E8
    if (ctx->r1 == 0) {
        // 0x8037D2E0: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_8037D2E8;
    }
    // 0x8037D2E0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8037D2E4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_8037D2E8:
    // 0x8037D2E8: jr          $ra
    // 0x8037D2EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8037D2EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_80382490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80382494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382498: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038249C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803824A0: jal         0x803717A0
    // 0x803824A4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803824A4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x803824A8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803824AC: beq         $v0, $zero, L_803824DC
    if (ctx->r2 == 0) {
        // 0x803824B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803824DC;
    }
    // 0x803824B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803824B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803824B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803824BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803824C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803824C4: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x803824C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803824CC: jal         0x8038259C
    // 0x803824D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8038259C(rdram, ctx);
        goto after_1;
    // 0x803824D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x803824D4: b           L_803824E0
    // 0x803824D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803824E0;
    // 0x803824D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803824DC:
    // 0x803824DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803824E0:
    // 0x803824E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803824E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803824E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803824EC: jr          $ra
    // 0x803824F0: nop

    return;
    // 0x803824F0: nop

;}
RECOMP_FUNC void grPupupuWhispyGetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801058E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801058E4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x801058E8: lw          $a0, 0x66FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66FC);
    // 0x801058EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801058F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801058F4: beq         $a0, $zero, L_80105934
    if (ctx->r4 == 0) {
        // 0x801058F8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80105934;
    }
    // 0x801058F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801058FC: lwc1        $f0, 0xA90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XA90);
    // 0x80105900: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
L_80105904:
    // 0x80105904: lw          $t6, 0x8E8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8E8);
    // 0x80105908: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8010590C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80105910: nop

    // 0x80105914: bc1fl       L_80105928
    if (!c1cs) {
        // 0x80105918: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80105928;
    }
    goto skip_0;
    // 0x80105918: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8010591C: b           L_80105928
    // 0x80105920: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80105928;
    // 0x80105920: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80105924: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80105928:
    // 0x80105928: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x8010592C: bnel        $a0, $zero, L_80105904
    if (ctx->r4 != 0) {
        // 0x80105930: lw          $a1, 0x84($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X84);
            goto L_80105904;
    }
    goto skip_1;
    // 0x80105930: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    skip_1:
L_80105934:
    // 0x80105934: bne         $v0, $v1, L_80105944
    if (ctx->r2 != ctx->r3) {
        // 0x80105938: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80105944;
    }
    // 0x80105938: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8010593C: jr          $ra
    // 0x80105940: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80105940: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80105944:
    // 0x80105944: beq         $at, $zero, L_80105954
    if (ctx->r1 == 0) {
        // 0x80105948: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80105954;
    }
    // 0x80105948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010594C: jr          $ra
    // 0x80105950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80105950: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80105954:
    // 0x80105954: jr          $ra
    // 0x80105958: nop

    return;
    // 0x80105958: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016D86C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016D870: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016D874: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8016D878: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8016D87C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8016D880: lbu         $t6, 0x2A2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2A2);
    // 0x8016D884: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8016D888: bnel        $t7, $zero, L_8016D89C
    if (ctx->r15 != 0) {
        // 0x8016D88C: lw          $t0, 0x8($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X8);
            goto L_8016D89C;
    }
    goto skip_0;
    // 0x8016D88C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8016D890: sb          $t8, 0x2A2($s0)
    MEM_B(0X2A2, ctx->r16) = ctx->r24;
    // 0x8016D894: sw          $t9, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r25;
    // 0x8016D898: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
L_8016D89C:
    // 0x8016D89C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8016D8A0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8016D8A4: lw          $v1, 0x74($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X74);
    // 0x8016D8A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016D8AC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8016D8B0: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8016D8B4: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8016D8B8: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8016D8BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8016D8C0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016D8C4: jal         0x8001863C
    // 0x8016D8C8: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8016D8C8: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    after_0:
    // 0x8016D8CC: swc1        $f0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f0.u32l;
    // 0x8016D8D0: jal         0x8016CC50
    // 0x8016D8D4: addiu       $a0, $s0, 0x2A4
    ctx->r4 = ADD32(ctx->r16, 0X2A4);
    wpLinkBoomerangClampAngle360(rdram, ctx);
        goto after_1;
    // 0x8016D8D4: addiu       $a0, $s0, 0x2A4
    ctx->r4 = ADD32(ctx->r16, 0X2A4);
    after_1:
    // 0x8016D8D8: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016D8DC: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8016D8E0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8016D8E4: nop

    // 0x8016D8E8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016D8EC: jal         0x80033510
    // 0x8016D8F0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016D8F0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x8016D8F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016D8F8: jal         0x8016CF48
    // 0x8016D8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpLinkBoomerangUpdateVelLR(rdram, ctx);
        goto after_3;
    // 0x8016D8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8016D900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016D908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016D90C: jr          $ra
    // 0x8016D910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016D910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mvOpeningDonkeyMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D3F8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D3FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D400: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D404: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D408: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D40C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D410: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D414: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D418: addiu       $t6, $t6, -0x1F90
    ctx->r14 = ADD32(ctx->r14, -0X1F90);
    // 0x8018D41C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D420: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D424: addiu       $s0, $s0, -0x1E18
    ctx->r16 = ADD32(ctx->r16, -0X1E18);
    // 0x8018D428: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D42C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D430: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D434: addiu       $t9, $t9, -0x1F74
    ctx->r25 = ADD32(ctx->r25, -0X1F74);
    // 0x8018D438: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D43C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D440: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D444: addiu       $s1, $s1, -0x1DF8
    ctx->r17 = ADD32(ctx->r17, -0X1DF8);
    // 0x8018D448: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D44C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D454: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D458: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D45C: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D460: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D464: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D468: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D46C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D470: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D474: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D478: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D47C: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D480: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D484: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D488: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D48C: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D490: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D494: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D498: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D49C: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4A0: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4A4: jal         0x8010DB2C
    // 0x8018D4A8: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4A8: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D4B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D4B4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4B8: addiu       $v1, $v1, -0x1E28
    ctx->r3 = ADD32(ctx->r3, -0X1E28);
    // 0x8018D4BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4C0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4C4: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D4D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D4D4: lui         $a3, 0x4352
    ctx->r7 = S32(0X4352 << 16);
    // 0x8018D4D8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4DC: jal         0x80007080
    // 0x8018D4E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D4E8: lwc1        $f6, -0x1E54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E54);
    // 0x8018D4EC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D4F0: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D4F4: jal         0x8000B39C
    // 0x8018D4F8: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D4F8: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    after_2:
    // 0x8018D4FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D500: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D504: addiu       $a1, $a1, -0x2D04
    ctx->r5 = ADD32(ctx->r5, -0X2D04);
    // 0x8018D508: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    // 0x8018D50C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D510: jal         0x80008188
    // 0x8018D514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D518: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D51C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D520: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D524: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D528: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D52C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D530: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D534: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D538: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D53C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D540: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D544: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D548: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D54C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D550: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D554: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D558: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D55C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D560: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D564: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D568: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D56C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D570: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D574: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D578: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D57C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D580: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D584: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D588: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D58C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D590: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D594: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D598: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D59C: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5A0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5A4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5A8: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5AC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5B0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5B4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5B8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5BC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5C0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5C4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5C8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5CC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5D0: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5D4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5D8: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5DC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5E0: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5E4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D5E8: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D5F0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D5F4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D5F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D5FC: jr          $ra
    // 0x8018D600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itKabigonMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E6C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017E6C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017E6C8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8017E6CC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8017E6D0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017E6D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017E6D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017E6DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017E6E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8017E6E4: addiu       $a1, $a1, -0x54C0
    ctx->r5 = ADD32(ctx->r5, -0X54C0);
    // 0x8017E6E8: jal         0x8016E174
    // 0x8017E6EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017E6EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017E6F0: beq         $v0, $zero, L_8017E78C
    if (ctx->r2 == 0) {
        // 0x8017E6F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017E78C;
    }
    // 0x8017E6F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017E6F8: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017E6FC: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x8017E700: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017E704: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017E708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E70C: lw          $t9, 0x2D4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017E710: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x8017E714: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017E718: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x8017E71C: sb          $t8, 0x154($v0)
    MEM_B(0X154, ctx->r2) = ctx->r24;
    // 0x8017E720: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8017E724: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017E728: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017E72C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8017E730: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8017E734: addiu       $t1, $t1, -0x4EA8
    ctx->r9 = ADD32(ctx->r9, -0X4EA8);
    // 0x8017E738: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8017E73C: addiu       $t3, $t3, 0x3624
    ctx->r11 = ADD32(ctx->r11, 0X3624);
    // 0x8017E740: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017E744: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8017E748: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x8017E74C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8017E750: jal         0x8000BD1C
    // 0x8017E754: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017E754: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8017E758: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8017E75C: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8017E760: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017E764: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8017E768: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    // 0x8017E76C: bne         $t4, $at, L_8017E780
    if (ctx->r12 != ctx->r1) {
        // 0x8017E770: nop
    
            goto L_8017E780;
    }
    // 0x8017E770: nop

    // 0x8017E774: jal         0x800269C0
    // 0x8017E778: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017E778: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8017E77C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_8017E780:
    // 0x8017E780: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017E784: addiu       $t5, $t5, -0x1B5C
    ctx->r13 = ADD32(ctx->r13, -0X1B5C);
    // 0x8017E788: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
L_8017E78C:
    // 0x8017E78C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017E794: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8017E798: jr          $ra
    // 0x8017E79C: nop

    return;
    // 0x8017E79C: nop

;}
RECOMP_FUNC void func_ovl8_8037D9B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D9B4: lwl         $t8, 0x0($a0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r4, 0X0);
    // 0x8037D9B8: lwr         $t8, 0x3($a0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r4, 0X3);
    // 0x8037D9BC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D9C0: addiu       $t6, $t6, -0x468
    ctx->r14 = ADD32(ctx->r14, -0X468);
    // 0x8037D9C4: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x8037D9C8: jr          $ra
    // 0x8037D9CC: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    return;
    // 0x8037D9CC: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
;}
RECOMP_FUNC void ftParamResetTexturePartAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E96B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E96B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E96B8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800E96BC: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x800E96C0: addiu       $a1, $v0, 0x9BE
    ctx->r5 = ADD32(ctx->r2, 0X9BE);
    // 0x800E96C4: lw          $a2, 0x330($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X330);
L_800E96C8:
    // 0x800E96C8: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x800E96CC: lb          $t7, 0x1($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1);
    // 0x800E96D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E96D4: beql        $a0, $t7, L_800E9734
    if (ctx->r4 == ctx->r15) {
        // 0x800E96D8: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800E9734;
    }
    goto skip_0;
    // 0x800E96D8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_0:
    // 0x800E96DC: sb          $a0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r4;
    // 0x800E96E0: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800E96E4: lbu         $t4, 0xE($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XE);
    // 0x800E96E8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800E96EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E96F0: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x800E96F4: lw          $a3, 0x8E8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8E8);
    // 0x800E96F8: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x800E96FC: lbu         $t0, 0x0($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X0);
    // 0x800E9700: beql        $a3, $zero, L_800E9734
    if (ctx->r7 == 0) {
        // 0x800E9704: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800E9734;
    }
    goto skip_1;
    // 0x800E9704: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_1:
    // 0x800E9708: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
L_800E970C:
    // 0x800E970C: beql        $a0, $zero, L_800E9734
    if (ctx->r4 == 0) {
        // 0x800E9710: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800E9734;
    }
    goto skip_2;
    // 0x800E9710: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_2:
    // 0x800E9714: beql        $t1, $t0, L_800E972C
    if (ctx->r9 == ctx->r8) {
        // 0x800E9718: lb          $t6, 0x1($a1)
        ctx->r14 = MEM_B(ctx->r5, 0X1);
            goto L_800E972C;
    }
    goto skip_3;
    // 0x800E9718: lb          $t6, 0x1($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1);
    skip_3:
    // 0x800E971C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800E9720: b           L_800E970C
    // 0x800E9724: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_800E970C;
    // 0x800E9724: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800E9728: lb          $t6, 0x1($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1);
L_800E972C:
    // 0x800E972C: sh          $t6, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r14;
    // 0x800E9730: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_800E9734:
    // 0x800E9734: bne         $v1, $t2, L_800E96C8
    if (ctx->r3 != ctx->r10) {
        // 0x800E9738: addiu       $a2, $a2, 0x3
        ctx->r6 = ADD32(ctx->r6, 0X3);
            goto L_800E96C8;
    }
    // 0x800E9738: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x800E973C: lbu         $t7, 0x18C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E9740: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x800E9744: jr          $ra
    // 0x800E9748: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    return;
    // 0x800E9748: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void sc1PBonusStageMakeTaskSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E098: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E09C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E0A8: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8018E0AC: slti        $at, $t7, 0x1D
    ctx->r1 = SIGNED(ctx->r15) < 0X1D ? 1 : 0;
    // 0x8018E0B0: bne         $at, $zero, L_8018E0C8
    if (ctx->r1 != 0) {
        // 0x8018E0B4: nop
    
            goto L_8018E0C8;
    }
    // 0x8018E0B4: nop

    // 0x8018E0B8: jal         0x8018DF3C
    // 0x8018E0BC: nop

    sc1PBonusStageMakePlatformSprites(rdram, ctx);
        goto after_0;
    // 0x8018E0BC: nop

    after_0:
    // 0x8018E0C0: b           L_8018E0D4
    // 0x8018E0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018E0D4;
    // 0x8018E0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018E0C8:
    // 0x8018E0C8: jal         0x8018DDE0
    // 0x8018E0CC: nop

    sc1PBonusStageMakeTargetSprites(rdram, ctx);
        goto after_1;
    // 0x8018E0CC: nop

    after_1:
    // 0x8018E0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018E0D4:
    // 0x8018E0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0D8: jr          $ra
    // 0x8018E0DC: nop

    return;
    // 0x8018E0DC: nop

;}
RECOMP_FUNC void scSubsysFighterSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803905CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803905D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803905D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x803905D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x803905DC: jal         0x800E6F24
    // 0x803905E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x803905E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x803905E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803905E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803905EC: jr          $ra
    // 0x803905F0: nop

    return;
    // 0x803905F0: nop

;}
RECOMP_FUNC void ftLinkSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801637C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801637C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801637C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801637CC: jal         0x800DDDDC
    // 0x801637D0: addiu       $a1, $a1, 0x38AC
    ctx->r5 = ADD32(ctx->r5, 0X38AC);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801637D0: addiu       $a1, $a1, 0x38AC
    ctx->r5 = ADD32(ctx->r5, 0X38AC);
    after_0:
    // 0x801637D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801637D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801637DC: jr          $ra
    // 0x801637E0: nop

    return;
    // 0x801637E0: nop

;}
RECOMP_FUNC void ftCommonGuardPassSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141E40: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80141E44: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80141E48: jal         0x80141DA0
    // 0x80141E4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftCommonPassSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80141E4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80141E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141E58: jr          $ra
    // 0x80141E5C: nop

    return;
    // 0x80141E5C: nop

;}
RECOMP_FUNC void ftCommonAttackLw3CheckInterruptSelf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014FC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FC68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014FC6C: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014FC70: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014FC74: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014FC78: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8014FC7C: beql        $t8, $zero, L_8014FCBC
    if (ctx->r24 == 0) {
        // 0x8014FC80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FCBC;
    }
    goto skip_0;
    // 0x8014FC80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014FC84: lw          $t9, 0x100($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X100);
    // 0x8014FC88: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x8014FC8C: bgezl       $t1, L_8014FCBC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8014FC90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FCBC;
    }
    goto skip_1;
    // 0x8014FC90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014FC94: lw          $t2, 0x180($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X180);
    // 0x8014FC98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014FC9C: beql        $t2, $zero, L_8014FCB8
    if (ctx->r10 == 0) {
        // 0x8014FCA0: sw          $t3, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r11;
            goto L_8014FCB8;
    }
    goto skip_2;
    // 0x8014FCA0: sw          $t3, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r11;
    skip_2:
    // 0x8014FCA4: jal         0x8014FD14
    // 0x8014FCA8: nop

    ftCommonAttackLw3SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014FCA8: nop

    after_0:
    // 0x8014FCAC: b           L_8014FCBC
    // 0x8014FCB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FCBC;
    // 0x8014FCB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014FCB4: sw          $t3, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r11;
L_8014FCB8:
    // 0x8014FCB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014FCBC:
    // 0x8014FCBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014FCC4: jr          $ra
    // 0x8014FCC8: nop

    return;
    // 0x8014FCC8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusUpdateCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134364: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80134368: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013436C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134370: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80134374: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80134378: addiu       $t7, $t7, 0x7410
    ctx->r15 = ADD32(ctx->r15, 0X7410);
    // 0x8013437C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134380: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134384: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80134388: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013438C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134390: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134394: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134398: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013439C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801343A0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801343A4: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801343A8: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801343AC: addiu       $t1, $t1, 0x7428
    ctx->r9 = ADD32(ctx->r9, 0X7428);
    // 0x801343B0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801343B4: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801343B8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801343BC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801343C0: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x801343C4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801343C8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801343CC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801343D0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801343D4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801343D8: addiu       $t5, $t5, 0x7438
    ctx->r13 = ADD32(ctx->r13, 0X7438);
    // 0x801343DC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801343E0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x801343E4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801343E8: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x801343EC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801343F0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801343F4: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801343F8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801343FC: addiu       $t9, $t9, 0x7444
    ctx->r25 = ADD32(ctx->r25, 0X7444);
    // 0x80134400: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80134404: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80134408: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8013440C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80134410: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80134414: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80134418: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8013441C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80134420: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80134424: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80134428: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x8013442C: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80134430: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80134434: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x80134438: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x8013443C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134440: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134444: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80134448: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013444C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80134450: jal         0x8000B760
    // 0x80134454: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80134454: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80134458: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x8013445C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134460: lw          $t5, 0x7DF8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DF8);
    // 0x80134464: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80134468: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8013446C: lw          $t4, 0x38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38);
    // 0x80134470: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80134474: jal         0x800CCFDC
    // 0x80134478: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80134478: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x8013447C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80134480: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80134484: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80134488: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013448C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80134490: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80134494: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80134498: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013449C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801344A0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801344A4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x801344A8: lw          $t3, 0x7DF8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DF8);
    // 0x801344AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x801344B0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801344B4: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x801344B8: lw          $t2, 0x44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44);
    // 0x801344BC: jal         0x800CCFDC
    // 0x801344C0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801344C0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x801344C4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x801344C8: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x801344CC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x801344D0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x801344D4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x801344D8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801344DC: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x801344E0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801344E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x801344E8: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x801344EC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801344F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801344F4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801344F8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801344FC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80134500: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80134504: lwc1        $f16, 0x5C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x80134508: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013450C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80134510: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80134514: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134518: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013451C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80134520: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80134524: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80134528: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8013452C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80134530: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80134534: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80134538: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x8013453C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80134540: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80134544: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80134548: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x8013454C: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80134550: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x80134554: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x80134558: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x8013455C: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x80134560: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x80134564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134568: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8013456C: jr          $ra
    // 0x80134570: nop

    return;
    // 0x80134570: nop

;}
RECOMP_FUNC void func_ovl2_80106DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106DDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80106DE0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80106DE4: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80106DE8: lb          $v0, 0x53($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X53);
    // 0x80106DEC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80106DF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106DF4: beql        $v0, $at, L_80106F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80106DF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80106F1C;
    }
    goto skip_0;
    // 0x80106DF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80106DFC: bltz        $v0, L_80106E90
    if (SIGNED(ctx->r2) < 0) {
        // 0x80106E00: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80106E90;
    }
    // 0x80106E00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80106E04: beq         $v0, $at, L_80106E24
    if (ctx->r2 == ctx->r1) {
        // 0x80106E08: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80106E24;
    }
    // 0x80106E08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80106E0C: beq         $v0, $at, L_80106E34
    if (ctx->r2 == ctx->r1) {
        // 0x80106E10: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80106E34;
    }
    // 0x80106E10: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80106E14: beq         $v0, $at, L_80106E44
    if (ctx->r2 == ctx->r1) {
        // 0x80106E18: nop
    
            goto L_80106E44;
    }
    // 0x80106E18: nop

    // 0x80106E1C: b           L_80106E50
    // 0x80106E20: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_80106E50;
    // 0x80106E20: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80106E24:
    // 0x80106E24: jal         0x80106C88
    // 0x80106E28: nop

    func_ovl2_80106C88(rdram, ctx);
        goto after_0;
    // 0x80106E28: nop

    after_0:
    // 0x80106E2C: b           L_80106E50
    // 0x80106E30: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_80106E50;
    // 0x80106E30: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80106E34:
    // 0x80106E34: jal         0x80106CC4
    // 0x80106E38: nop

    func_ovl2_80106CC4(rdram, ctx);
        goto after_1;
    // 0x80106E38: nop

    after_1:
    // 0x80106E3C: b           L_80106E50
    // 0x80106E40: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_80106E50;
    // 0x80106E40: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80106E44:
    // 0x80106E44: jal         0x80106D00
    // 0x80106E48: nop

    func_ovl2_80106D00(rdram, ctx);
        goto after_2;
    // 0x80106E48: nop

    after_2:
    // 0x80106E4C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80106E50:
    // 0x80106E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106E54: lwc1        $f4, 0xAD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAD4);
    // 0x80106E58: lwc1        $f6, 0x74($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X74);
    // 0x80106E5C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80106E60: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x80106E64: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80106E68: nop

    // 0x80106E6C: bc1fl       L_80106E84
    if (!c1cs) {
        // 0x80106E70: lhu         $t9, 0x46($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X46);
            goto L_80106E84;
    }
    goto skip_1;
    // 0x80106E70: lhu         $t9, 0x46($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X46);
    skip_1:
    // 0x80106E74: sb          $t7, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r15;
    // 0x80106E78: b           L_80106F18
    // 0x80106E7C: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
        goto L_80106F18;
    // 0x80106E7C: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    // 0x80106E80: lhu         $t9, 0x46($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X46);
L_80106E84:
    // 0x80106E84: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80106E88: b           L_80106F18
    // 0x80106E8C: sh          $t0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r8;
        goto L_80106F18;
    // 0x80106E8C: sh          $t0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r8;
L_80106E90:
    // 0x80106E90: lhu         $t1, 0x46($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X46);
    // 0x80106E94: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80106E98: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80106E9C: bne         $t3, $zero, L_80106F18
    if (ctx->r11 != 0) {
        // 0x80106EA0: sh          $t2, 0x46($s0)
        MEM_H(0X46, ctx->r16) = ctx->r10;
            goto L_80106F18;
    }
    // 0x80106EA0: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80106EA4: lbu         $t4, 0x54($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X54);
    // 0x80106EA8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80106EAC: addiu       $t6, $t6, -0x1640
    ctx->r14 = ADD32(ctx->r14, -0X1640);
    // 0x80106EB0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80106EB4: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80106EB8: lbu         $a0, 0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1);
    // 0x80106EBC: jal         0x80018994
    // 0x80106EC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80106EC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80106EC4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80106EC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80106ECC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80106ED0: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80106ED4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80106ED8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80106EDC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80106EE0: lbu         $v1, -0x1678($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1678);
    // 0x80106EE4: beq         $v1, $zero, L_80106F0C
    if (ctx->r3 == 0) {
        // 0x80106EE8: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80106F0C;
    }
    // 0x80106EE8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80106EEC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80106EF0: lw          $t0, -0x16A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X16A0);
    // 0x80106EF4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80106EF8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80106EFC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80106F00: jal         0x80106A40
    // 0x80106F04: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_4;
    // 0x80106F04: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x80106F08: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80106F0C:
    // 0x80106F0C: sb          $v1, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r3;
    // 0x80106F10: lb          $t2, 0x53($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X53);
    // 0x80106F14: sb          $t2, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r10;
L_80106F18:
    // 0x80106F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106F1C:
    // 0x80106F1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80106F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80106F24: jr          $ra
    // 0x80106F28: nop

    return;
    // 0x80106F28: nop

;}
RECOMP_FUNC void itNyarsWeaponCoinMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F2E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017F2E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F2EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017F2F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017F2F4: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017F2F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F2FC: addiu       $a1, $a1, -0x530C
    ctx->r5 = ADD32(ctx->r5, -0X530C);
    // 0x8017F300: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017F304: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8017F308: jal         0x801655C8
    // 0x8017F30C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8017F30C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_0:
    // 0x8017F310: bne         $v0, $zero, L_8017F320
    if (ctx->r2 != 0) {
        // 0x8017F314: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017F320;
    }
    // 0x8017F314: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017F318: b           L_8017F3F8
    // 0x8017F31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017F3F8;
    // 0x8017F31C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017F320:
    // 0x8017F320: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8017F324: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017F328: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8017F32C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017F330: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8017F334: sw          $t6, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->r14;
    // 0x8017F338: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8017F33C: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8017F340: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x8017F344: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017F348: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017F34C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8017F350: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8017F354: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8017F358: bgez        $t7, L_8017F36C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017F35C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8017F36C;
    }
    // 0x8017F35C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017F360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F364: nop

    // 0x8017F368: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8017F36C:
    // 0x8017F36C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017F370: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F374: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8017F378: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017F37C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017F380: lwc1        $f10, -0x319C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X319C);
    // 0x8017F384: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017F388: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F38C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8017F390: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017F394: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017F398: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017F39C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8017F3A0: jal         0x800192D0
    // 0x8017F3A4: nop

    syVectorRotate3D(rdram, ctx);
        goto after_1;
    // 0x8017F3A4: nop

    after_1:
    // 0x8017F3A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8017F3AC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8017F3B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017F3B4: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x8017F3B8: jal         0x80008CC0
    // 0x8017F3BC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017F3BC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8017F3C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F3C4: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8017F3C8: jal         0x80008CC0
    // 0x8017F3CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8017F3CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8017F3D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8017F3D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F3D8: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x8017F3DC: lw          $t3, 0x1C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1C);
    // 0x8017F3E0: sw          $t3, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r11;
    // 0x8017F3E4: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x8017F3E8: sw          $t2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r10;
    // 0x8017F3EC: lw          $t3, 0x24($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X24);
    // 0x8017F3F0: sw          $t3, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r11;
    // 0x8017F3F4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8017F3F8:
    // 0x8017F3F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F3FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017F400: jr          $ra
    // 0x8017F404: nop

    return;
    // 0x8017F404: nop

;}
RECOMP_FUNC void func_ovl8_80373E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80373E30: lhu         $t6, 0x3C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X3C);
    // 0x80373E34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80373E38: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80373E3C: bnel        $t6, $at, L_80373E90
    if (ctx->r14 != ctx->r1) {
        // 0x80373E40: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80373E90;
    }
    goto skip_0;
    // 0x80373E40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x80373E44: beq         $a0, $zero, L_80373E50
    if (ctx->r4 == 0) {
        // 0x80373E48: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80373E50;
    }
    // 0x80373E48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80373E4C: lw          $a3, 0x38($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X38);
L_80373E50:
    // 0x80373E50: lw          $v1, 0x34($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X34);
    // 0x80373E54: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x80373E58: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80373E5C: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x80373E60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80373E64: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80373E68: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x80373E6C: jalr        $t9
    // 0x80373E70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373E70: nop

    after_0:
    // 0x80373E74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80373E78: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80373E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80373E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80373E84: b           L_80373E98
    // 0x80373E88: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
        goto L_80373E98;
    // 0x80373E88: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
    // 0x80373E8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80373E90:
    // 0x80373E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80373E94: swc1        $f6, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f6.u32l;
L_80373E98:
    // 0x80373E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373EA0: jr          $ra
    // 0x80373EA4: nop

    return;
    // 0x80373EA4: nop

;}
RECOMP_FUNC void ftKirbySpecialNEatProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801627E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801627E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801627E8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801627EC: jal         0x800DDDDC
    // 0x801627F0: addiu       $a1, $a1, 0x2BA0
    ctx->r5 = ADD32(ctx->r5, 0X2BA0);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801627F0: addiu       $a1, $a1, 0x2BA0
    ctx->r5 = ADD32(ctx->r5, 0X2BA0);
    after_0:
    // 0x801627F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801627F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801627FC: jr          $ra
    // 0x80162800: nop

    return;
    // 0x80162800: nop

;}
RECOMP_FUNC void func_ovl60_8013275C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013275C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132760: lw          $a0, 0x37D4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D4);
    // 0x80132764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013276C: beql        $a0, $zero, L_80132788
    if (ctx->r4 == 0) {
        // 0x80132770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132788;
    }
    goto skip_0;
    // 0x80132770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132774: jal         0x80009A84
    // 0x80132778: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132778: nop

    after_0:
    // 0x8013277C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132780: sw          $zero, 0x37D4($at)
    MEM_W(0X37D4, ctx->r1) = 0;
    // 0x80132784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132788:
    // 0x80132788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013278C: jr          $ra
    // 0x80132790: nop

    return;
    // 0x80132790: nop

;}
RECOMP_FUNC void syAudioPlayFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D88: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80020D8C: lbu         $a2, -0x2645($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2645);
    // 0x80020D90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020D98: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020D9C: blez        $a2, L_80020DFC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80020DA0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80020DFC;
    }
    // 0x80020DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020DA4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80020DA8: lw          $v0, -0x26AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26AC);
    // 0x80020DAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80020DB0:
    // 0x80020DB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020DB4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020DB8: bne         $t6, $zero, L_80020DEC
    if (ctx->r14 != 0) {
        // 0x80020DBC: andi        $a0, $a3, 0xFFFF
        ctx->r4 = ctx->r7 & 0XFFFF;
            goto L_80020DEC;
    }
    // 0x80020DBC: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x80020DC0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80020DC4: jal         0x800269C0
    // 0x80020DC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80020DC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80020DCC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020DD0: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x80020DD4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80020DD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80020DDC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80020DE0: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80020DE4: b           L_80020E00
    // 0x80020DE8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80020E00;
    // 0x80020DE8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80020DEC:
    // 0x80020DEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020DF0: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80020DF4: bne         $at, $zero, L_80020DB0
    if (ctx->r1 != 0) {
        // 0x80020DF8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80020DB0;
    }
    // 0x80020DF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80020DFC:
    // 0x80020DFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80020E00:
    // 0x80020E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020E04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020E08: jr          $ra
    // 0x80020E0C: nop

    return;
    // 0x80020E0C: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F60C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F614: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F618: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015F61C: addiu       $t6, $t6, -0xC08
    ctx->r14 = ADD32(ctx->r14, -0XC08);
    // 0x8015F620: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8015F624: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F628: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015F62C: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x8015F630: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F634: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015F638: jal         0x800E6F24
    // 0x8015F63C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F63C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015F640: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F644: addiu       $a1, $a1, -0x910
    ctx->r5 = ADD32(ctx->r5, -0X910);
    // 0x8015F648: jal         0x8015F180
    // 0x8015F64C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbyCopyYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x8015F64C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8015F650: jal         0x800E0830
    // 0x8015F654: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015F654: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015F658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F65C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F660: jr          $ra
    // 0x8015F664: nop

    return;
    // 0x8015F664: nop

;}
RECOMP_FUNC void mnCharactersMakeWorksCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133364: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133368: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013336C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133370: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133374: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80133378: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013337C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80133380: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133384: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133388: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013338C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133390: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133394: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133398: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013339C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801333A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801333A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801333A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801333AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801333B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801333B4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801333B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333BC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801333C0: jal         0x8000B93C
    // 0x801333C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801333C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801333C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801333CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801333D0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801333D4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801333D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801333DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801333E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801333E4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801333E8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801333EC: jal         0x80007080
    // 0x801333F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801333F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801333F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801333F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801333FC: jr          $ra
    // 0x80133400: nop

    return;
    // 0x80133400: nop

;}
RECOMP_FUNC void func_ovl8_80375BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375BB4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375BB8: addiu       $t6, $t6, -0x1050
    ctx->r14 = ADD32(ctx->r14, -0X1050);
    // 0x80375BBC: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x80375BC0: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x80375BC4: swl         $t8, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r24);
    // 0x80375BC8: jr          $ra
    // 0x80375BCC: swr         $t8, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r24);
    return;
    // 0x80375BCC: swr         $t8, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r24);
;}
RECOMP_FUNC void sc1PStageClearGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: bne         $a1, $zero, L_80131B68
    if (ctx->r5 != 0) {
        // 0x80131B5C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B68;
    }
    // 0x80131B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B60: jr          $ra
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B68:
    // 0x80131B68: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B6C: bne         $at, $zero, L_80131BEC
    if (ctx->r1 != 0) {
        // 0x80131B70: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BEC;
    }
    // 0x80131B70: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B74: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B78: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B7C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B80: beq         $a3, $zero, L_80131BA4
    if (ctx->r7 == 0) {
        // 0x80131B84: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131BA4;
    }
    // 0x80131B84: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B88:
    // 0x80131B88: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B90: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B94: bne         $a2, $v0, L_80131B88
    if (ctx->r6 != ctx->r2) {
        // 0x80131B98: nop
    
            goto L_80131B88;
    }
    // 0x80131B98: nop

    // 0x80131B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131BA0: beq         $v0, $a1, L_80131BEC
    if (ctx->r2 == ctx->r5) {
        // 0x80131BA4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BEC;
    }
L_80131BA4:
    // 0x80131BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131BA8:
    // 0x80131BA8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BAC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131BB0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB4: nop

    // 0x80131BB8: nop

    // 0x80131BBC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BC0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BC4: nop

    // 0x80131BC8: nop

    // 0x80131BCC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BD4: nop

    // 0x80131BD8: nop

    // 0x80131BDC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BE0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BE4: bne         $v0, $a1, L_80131BA8
    if (ctx->r2 != ctx->r5) {
        // 0x80131BE8: nop
    
            goto L_80131BA8;
    }
    // 0x80131BE8: nop

L_80131BEC:
    // 0x80131BEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: nop

    return;
    // 0x80131BF4: nop

;}
RECOMP_FUNC void mpProcessCheckTestRWallCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAAA8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DAAAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DAAB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DAAB4: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x800DAAB8: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800DAABC: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DAAC0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800DAAC4: jal         0x800D9510
    // 0x800DAAC8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    mpProcessResetMultiWallCount(rdram, ctx);
        goto after_0;
    // 0x800DAAC8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DAACC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DAAD0: jal         0x800FC67C
    // 0x800DAAD4: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_1;
    // 0x800DAAD4: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    after_1:
    // 0x800DAAD8: beql        $v0, $zero, L_800DAAF8
    if (ctx->r2 == 0) {
        // 0x800DAADC: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_800DAAF8;
    }
    goto skip_0;
    // 0x800DAADC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_0:
    // 0x800DAAE0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800DAAE4: jal         0x800FA964
    // 0x800DAAE8: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_2;
    // 0x800DAAE8: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    after_2:
    // 0x800DAAEC: b           L_800DAAFC
    // 0x800DAAF0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_800DAAFC;
    // 0x800DAAF0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800DAAF4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800DAAF8:
    // 0x800DAAF8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800DAAFC:
    // 0x800DAAFC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800DAB00: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800DAB04: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DAB08: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x800DAB0C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DAB10: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800DAB14: addiu       $v0, $t1, 0x38
    ctx->r2 = ADD32(ctx->r9, 0X38);
    // 0x800DAB18: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DAB1C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DAB20: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DAB24: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DAB28: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800DAB2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DAB30: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DAB34: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800DAB38: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DAB3C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DAB40: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800DAB44: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DAB48: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DAB4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DAB50: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800DAB54: lhu         $t3, 0x5C($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X5C);
    // 0x800DAB58: beq         $t2, $t3, L_800DAB88
    if (ctx->r10 == ctx->r11) {
        // 0x800DAB5C: addiu       $a0, $sp, 0x4C
        ctx->r4 = ADD32(ctx->r29, 0X4C);
            goto L_800DAB88;
    }
    // 0x800DAB5C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAB60: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAB64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAB68: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAB6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAB70: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DAB74: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800DAB78: jal         0x800F769C
    // 0x800DAB7C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_3;
    // 0x800DAB7C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x800DAB80: b           L_800DABB0
    // 0x800DAB84: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_800DABB0;
    // 0x800DAB84: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DAB88:
    // 0x800DAB88: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAB8C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAB90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAB94: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAB98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAB9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DABA0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800DABA4: jal         0x800F6B58
    // 0x800DABA8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_4;
    // 0x800DABA8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800DABAC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DABB0:
    // 0x800DABB0: beq         $v0, $zero, L_800DABD8
    if (ctx->r2 == 0) {
        // 0x800DABB4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DABD8;
    }
    // 0x800DABB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DABB8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800DABBC: beql        $a0, $t4, L_800DABDC
    if (ctx->r4 == ctx->r12) {
        // 0x800DABC0: lwc1        $f4, 0x0($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800DABDC;
    }
    goto skip_1;
    // 0x800DABC0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800DABC4: jal         0x800D951C
    // 0x800DABC8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_5;
    // 0x800DABC8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x800DABCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DABD0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800DABD4: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_800DABD8:
    // 0x800DABD8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
L_800DABDC:
    // 0x800DABDC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800DABE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DABE4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800DABE8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DABEC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800DABF0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800DABF4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DABF8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DABFC: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DAC00: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAC04: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAC08: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800DAC0C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DAC10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAC14: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAC18: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DAC1C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DAC20: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800DAC24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DAC28: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800DAC2C: lhu         $t2, 0x5C($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X5C);
    // 0x800DAC30: beql        $t8, $t2, L_800DAC64
    if (ctx->r24 == ctx->r10) {
        // 0x800DAC34: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DAC64;
    }
    goto skip_2;
    // 0x800DAC34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_2:
    // 0x800DAC38: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAC3C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAC40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAC44: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAC48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAC4C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DAC50: jal         0x800F769C
    // 0x800DAC54: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_6;
    // 0x800DAC54: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_6:
    // 0x800DAC58: b           L_800DAC74
    // 0x800DAC5C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_800DAC74;
    // 0x800DAC5C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800DAC60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DAC64:
    // 0x800DAC64: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DAC68: jal         0x800F6B58
    // 0x800DAC6C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_7;
    // 0x800DAC6C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x800DAC70: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DAC74:
    // 0x800DAC74: beq         $v0, $zero, L_800DAC9C
    if (ctx->r2 == 0) {
        // 0x800DAC78: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DAC9C;
    }
    // 0x800DAC78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DAC7C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800DAC80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DAC84: beql        $a0, $t3, L_800DACA0
    if (ctx->r4 == ctx->r11) {
        // 0x800DAC88: lwc1        $f8, 0x0($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800DACA0;
    }
    goto skip_3;
    // 0x800DAC88: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800DAC8C: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800DAC90: jal         0x800D951C
    // 0x800DAC94: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_8;
    // 0x800DAC94: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x800DAC98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DAC9C:
    // 0x800DAC9C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
L_800DACA0:
    // 0x800DACA0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800DACA4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800DACA8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DACAC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DACB0: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800DACB4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800DACB8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DACBC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DACC0: lhu         $t7, 0x1398($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1398);
    // 0x800DACC4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DACC8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DACCC: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DACD0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DACD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DACD8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DACDC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800DACE0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DACE4: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800DACE8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DACEC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800DACF0: lhu         $t8, 0x5C($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X5C);
    // 0x800DACF4: beql        $t7, $t8, L_800DAD24
    if (ctx->r15 == ctx->r24) {
        // 0x800DACF8: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DAD24;
    }
    goto skip_4;
    // 0x800DACF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_4:
    // 0x800DACFC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAD00: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAD04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAD08: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAD0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAD10: jal         0x800F769C
    // 0x800DAD14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_9;
    // 0x800DAD14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x800DAD18: b           L_800DAD2C
    // 0x800DAD1C: nop

        goto L_800DAD2C;
    // 0x800DAD1C: nop

    // 0x800DAD20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DAD24:
    // 0x800DAD24: jal         0x800F6B58
    // 0x800DAD28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_10;
    // 0x800DAD28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
L_800DAD2C:
    // 0x800DAD2C: beq         $v0, $zero, L_800DAD4C
    if (ctx->r2 == 0) {
        // 0x800DAD30: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DAD4C;
    }
    // 0x800DAD30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DAD34: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800DAD38: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DAD3C: beql        $a0, $t2, L_800DAD50
    if (ctx->r4 == ctx->r10) {
        // 0x800DAD40: lwc1        $f16, 0x0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800DAD50;
    }
    goto skip_5;
    // 0x800DAD40: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x800DAD44: jal         0x800D951C
    // 0x800DAD48: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_11;
    // 0x800DAD48: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_11:
L_800DAD4C:
    // 0x800DAD4C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
L_800DAD50:
    // 0x800DAD50: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800DAD54: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DAD58: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800DAD5C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DAD60: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800DAD64: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DAD68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAD6C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DAD70: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DAD74: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800DAD78: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DAD7C: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800DAD80: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DAD84: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DAD88: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DAD8C: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DAD90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DAD94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAD98: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DAD9C: jal         0x800F6B58
    // 0x800DADA0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_12;
    // 0x800DADA0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x800DADA4: beq         $v0, $zero, L_800DADC4
    if (ctx->r2 == 0) {
        // 0x800DADA8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DADC4;
    }
    // 0x800DADA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DADAC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800DADB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DADB4: beql        $a0, $t5, L_800DADC8
    if (ctx->r4 == ctx->r13) {
        // 0x800DADB8: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800DADC8;
    }
    goto skip_6;
    // 0x800DADB8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x800DADBC: jal         0x800D951C
    // 0x800DADC0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_13;
    // 0x800DADC0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_13:
L_800DADC4:
    // 0x800DADC4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_800DADC8:
    // 0x800DADC8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800DADCC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DADD0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DADD4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DADD8: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800DADDC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DADE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DADE4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DADE8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DADEC: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DADF0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DADF4: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800DADF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DADFC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800DAE00: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DAE04: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800DAE08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DAE0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DAE10: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DAE14: jal         0x800F6B58
    // 0x800DAE18: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_14;
    // 0x800DAE18: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x800DAE1C: beq         $v0, $zero, L_800DAE3C
    if (ctx->r2 == 0) {
        // 0x800DAE20: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DAE3C;
    }
    // 0x800DAE20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DAE24: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800DAE28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DAE2C: beql        $a0, $t7, L_800DAE40
    if (ctx->r4 == ctx->r15) {
        // 0x800DAE30: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_800DAE40;
    }
    goto skip_7;
    // 0x800DAE30: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x800DAE34: jal         0x800D951C
    // 0x800DAE38: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_15;
    // 0x800DAE38: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_15:
L_800DAE3C:
    // 0x800DAE3C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
L_800DAE40:
    // 0x800DAE40: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800DAE44: beql        $t2, $zero, L_800DAE5C
    if (ctx->r10 == 0) {
        // 0x800DAE48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DAE5C;
    }
    goto skip_8;
    // 0x800DAE48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800DAE4C: lhu         $t4, 0x56($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X56);
    // 0x800DAE50: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x800DAE54: sh          $t5, 0x56($t3)
    MEM_H(0X56, ctx->r11) = ctx->r13;
    // 0x800DAE58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DAE5C:
    // 0x800DAE5C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800DAE60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DAE64: jr          $ra
    // 0x800DAE68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800DAE68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CED4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8002CED8: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8002CEDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CEE0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002CEE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002CEE8: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x8002CEEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CEF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CEF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002CEF8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002CEFC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8002CF00: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8002CF04: nop

    // 0x8002CF08: sra         $v1, $v0, 15
    ctx->r3 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8002CF0C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8002CF10: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002CF14: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8002CF18: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002CF1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002CF20: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8002CF24: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002CF28: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8002CF2C: nop

    // 0x8002CF30: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
L_8002CF34:
    // 0x8002CF34: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002CF38: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x8002CF3C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002CF40: bne         $at, $zero, L_8002CF34
    if (ctx->r1 != 0) {
        // 0x8002CF44: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_8002CF34;
    }
    // 0x8002CF44: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x8002CF48: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002CF4C: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x8002CF50: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8002CF54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002CF58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002CF5C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8002CF60: div.d       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f10.d, ctx->f12.d);
    // 0x8002CF64: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x8002CF68: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002CF6C: beq         $at, $zero, L_8002CF98
    if (ctx->r1 == 0) {
        // 0x8002CF70: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8002CF98;
    }
    // 0x8002CF70: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_8002CF74:
    // 0x8002CF74: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8002CF78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002CF7C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8002CF80: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8002CF84: mul.d       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x8002CF88: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x8002CF8C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8002CF90: bne         $at, $zero, L_8002CF74
    if (ctx->r1 != 0) {
        // 0x8002CF94: sh          $t2, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r10;
            goto L_8002CF74;
    }
    // 0x8002CF94: sh          $t2, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r10;
L_8002CF98:
    // 0x8002CF98: jr          $ra
    // 0x8002CF9C: nop

    return;
    // 0x8002CF9C: nop

;}
RECOMP_FUNC void efDisplayXLUProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCD64: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800FCD68: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800FCD6C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800FCD70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800FCD74: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FCD78: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800FCD7C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800FCD80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FCD84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800FCD88: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800FCD8C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FCD90: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800FCD94: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800FCD98: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800FCD9C: ori         $t0, $t0, 0x49D8
    ctx->r8 = ctx->r8 | 0X49D8;
    // 0x800FCDA0: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FCDA4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800FCDA8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800FCDAC: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800FCDB0: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x800FCDB4: ori         $t2, $t2, 0x1E01
    ctx->r10 = ctx->r10 | 0X1E01;
    // 0x800FCDB8: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800FCDBC: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800FCDC0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FCDC4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800FCDC8: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800FCDCC: lui         $t4, 0xD9FF
    ctx->r12 = S32(0XD9FF << 16);
    // 0x800FCDD0: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800FCDD4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800FCDD8: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800FCDDC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800FCDE0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800FCDE4: jr          $ra
    // 0x800FCDE8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    return;
    // 0x800FCDE8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void efManagerKirbyCutterDrawMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010250C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102514: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102518: jal         0x800FDB1C
    // 0x8010251C: addiu       $a0, $a0, -0x1C34
    ctx->r4 = ADD32(ctx->r4, -0X1C34);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x8010251C: addiu       $a0, $a0, -0x1C34
    ctx->r4 = ADD32(ctx->r4, -0X1C34);
    after_0:
    // 0x80102520: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80102524: bne         $v0, $zero, L_80102534
    if (ctx->r2 != 0) {
        // 0x80102528: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80102534;
    }
    // 0x80102528: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010252C: b           L_80102550
    // 0x80102530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102550;
    // 0x80102530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102534:
    // 0x80102534: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80102538: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010253C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80102540: lw          $t6, 0x84($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X84);
    // 0x80102544: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x80102548: lw          $t7, 0x92C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X92C);
    // 0x8010254C: sw          $t7, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r15;
L_80102550:
    // 0x80102550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102558: jr          $ra
    // 0x8010255C: nop

    return;
    // 0x8010255C: nop

;}
RECOMP_FUNC void syDebugFramebufferDrawBlackRectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800223F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800223F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800223FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022400: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80022404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002240C: jal         0x80039630
    // 0x80022410: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80022410: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80022414: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80022418: lw          $a1, 0x6678($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6678);
    // 0x8002241C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80022420: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80022424: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80022428: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002242C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80022430: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80022434: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022438: mflo        $t7
    ctx->r15 = lo;
    // 0x8002243C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80022440: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80022444: blez        $s0, L_800224AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80022448: addu        $v1, $t9, $t2
        ctx->r3 = ADD32(ctx->r25, ctx->r10);
            goto L_800224AC;
    }
    // 0x80022448: addu        $v1, $t9, $t2
    ctx->r3 = ADD32(ctx->r25, ctx->r10);
L_8002244C:
    // 0x8002244C: blez        $a2, L_80022498
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80022450: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80022498;
    }
    // 0x80022450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022454: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x80022458: beq         $a3, $zero, L_80022474
    if (ctx->r7 == 0) {
        // 0x8002245C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80022474;
    }
    // 0x8002245C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80022460:
    // 0x80022460: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022464: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80022468: bne         $a1, $v0, L_80022460
    if (ctx->r5 != ctx->r2) {
        // 0x8002246C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80022460;
    }
    // 0x8002246C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80022470: beq         $v0, $a2, L_80022490
    if (ctx->r2 == ctx->r6) {
        // 0x80022474: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80022490;
    }
L_80022474:
    // 0x80022474: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022478: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x8002247C: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x80022480: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x80022484: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80022488: bne         $v0, $a2, L_80022474
    if (ctx->r2 != ctx->r6) {
        // 0x8002248C: sh          $a0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r4;
            goto L_80022474;
    }
    // 0x8002248C: sh          $a0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r4;
L_80022490:
    // 0x80022490: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80022494: lw          $a1, 0x6678($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6678);
L_80022498:
    // 0x80022498: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x8002249C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800224A0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800224A4: bne         $t0, $s0, L_8002244C
    if (ctx->r8 != ctx->r16) {
        // 0x800224A8: addu        $v1, $v1, $t4
        ctx->r3 = ADD32(ctx->r3, ctx->r12);
            goto L_8002244C;
    }
    // 0x800224A8: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
L_800224AC:
    // 0x800224AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800224B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800224B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800224B8: jr          $ra
    // 0x800224BC: nop

    return;
    // 0x800224BC: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateOpen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105CAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105CB0: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105CB4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80105CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105CC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80105CC4: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x80105CC8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80105CCC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80105CD0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80105CD4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80105CD8: bc1fl       L_80105D14
    if (!c1cs) {
        // 0x80105CDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105D14;
    }
    goto skip_0;
    // 0x80105CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105CE0: sb          $t7, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r15;
    // 0x80105CE4: sb          $t9, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = ctx->r25;
    // 0x80105CE8: jal         0x80018994
    // 0x80105CEC: sb          $t9, 0x2B($v1)
    MEM_B(0X2B, ctx->r3) = ctx->r25;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80105CEC: sb          $t9, 0x2B($v1)
    MEM_B(0X2B, ctx->r3) = ctx->r25;
    after_0:
    // 0x80105CF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105CF4: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105CF8: addiu       $t0, $v0, 0xF0
    ctx->r8 = ADD32(ctx->r2, 0XF0);
    // 0x80105CFC: sh          $t0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r8;
    // 0x80105D00: jal         0x80105B18
    // 0x80105D04: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    grPupupuWhispyLeavesMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80105D04: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    after_1:
    // 0x80105D08: jal         0x800269C0
    // 0x80105D0C: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80105D0C: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    after_2:
    // 0x80105D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105D14:
    // 0x80105D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105D18: jr          $ra
    // 0x80105D1C: nop

    return;
    // 0x80105D1C: nop

;}
RECOMP_FUNC void efManagerKirbyInhaleWindMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801042B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801042B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801042BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801042C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801042C4: jal         0x800FD4D8
    // 0x801042C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    efManagerGetEffectForce(rdram, ctx);
        goto after_0;
    // 0x801042C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x801042CC: bne         $v0, $zero, L_801042DC
    if (ctx->r2 != 0) {
        // 0x801042D0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_801042DC;
    }
    // 0x801042D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801042D4: b           L_80104444
    // 0x801042D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104444;
    // 0x801042D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801042DC:
    // 0x801042DC: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x801042E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801042E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801042E8: jal         0x80009968
    // 0x801042EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x801042EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801042F0: bne         $v0, $zero, L_80104308
    if (ctx->r2 != 0) {
        // 0x801042F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80104308;
    }
    // 0x801042F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801042F8: jal         0x800FD4F8
    // 0x801042FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x801042FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80104300: b           L_80104444
    // 0x80104304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104444;
    // 0x80104304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80104308:
    // 0x80104308: sw          $s1, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r17;
    // 0x8010430C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104310: lw          $a0, 0x1080($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1080);
    // 0x80104314: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80104318: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8010431C: jal         0x800CE9E8
    // 0x80104320: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x80104320: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_3:
    // 0x80104324: beq         $v0, $zero, L_80104440
    if (ctx->r2 == 0) {
        // 0x80104328: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80104440;
    }
    // 0x80104328: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010432C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104330: jal         0x800CE1DC
    // 0x80104334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x80104334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80104338: beq         $v0, $zero, L_80104434
    if (ctx->r2 == 0) {
        // 0x8010433C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80104434;
    }
    // 0x8010433C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104340: jal         0x800CEA14
    // 0x80104344: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x80104344: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
    // 0x80104348: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8010434C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80104350: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80104354: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80104358: addiu       $a1, $a1, 0x4240
    ctx->r5 = ADD32(ctx->r5, 0X4240);
    // 0x8010435C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80104360: bnel        $t6, $zero, L_80104374
    if (ctx->r14 != 0) {
        // 0x80104364: lw          $t7, 0x74($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X74);
            goto L_80104374;
    }
    goto skip_0;
    // 0x80104364: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    skip_0:
    // 0x80104368: b           L_80104444
    // 0x8010436C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104444;
    // 0x8010436C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104370: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
L_80104374:
    // 0x80104374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80104378: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010437C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x80104380: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80104384: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80104388: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8010438C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80104390: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80104394: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80104398: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8010439C: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x801043A0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x801043A4: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x801043A8: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x801043AC: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801043B0: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x801043B4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801043B8: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x801043BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801043C0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801043C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801043C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801043CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801043D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801043D4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801043D8: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801043DC: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x801043E0: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x801043E4: lw          $t3, 0x44($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X44);
    // 0x801043E8: bne         $t3, $at, L_801043FC
    if (ctx->r11 != ctx->r1) {
        // 0x801043EC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801043FC;
    }
    // 0x801043EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801043F0: lwc1        $f16, 0xA28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XA28);
    // 0x801043F4: b           L_80104408
    // 0x801043F8: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
        goto L_80104408;
    // 0x801043F8: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_801043FC:
    // 0x801043FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104400: lwc1        $f10, 0xA2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA2C);
    // 0x80104404: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
L_80104408:
    // 0x80104408: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010440C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80104410: jal         0x80008188
    // 0x80104414: sw          $s1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r17;
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80104414: sw          $s1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r17;
    after_6:
    // 0x80104418: lw          $t4, 0x5C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X5C);
    // 0x8010441C: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    // 0x80104420: lbu         $t5, 0x8($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X8);
    // 0x80104424: sh          $t5, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r13;
    // 0x80104428: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8010442C: b           L_80104440
    // 0x80104430: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
        goto L_80104440;
    // 0x80104430: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
L_80104434:
    // 0x80104434: jal         0x800CEA40
    // 0x80104438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_7;
    // 0x80104438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8010443C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80104440:
    // 0x80104440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80104444:
    // 0x80104444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104448: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010444C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80104450: jr          $ra
    // 0x80104454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80104454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80383F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383F7C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80383F80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80383F84: beql        $t6, $zero, L_80383FBC
    if (ctx->r14 == 0) {
        // 0x80383F88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383FBC;
    }
    goto skip_0;
    // 0x80383F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383F8C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80383F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383F94: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383F98: lh          $t7, 0x118($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X118);
    // 0x80383F9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80383FA0: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80383FA4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x80383FA8: jalr        $t9
    // 0x80383FAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383FAC: nop

    after_0:
    // 0x80383FB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80383FB4: sw          $zero, 0x54($a2)
    MEM_W(0X54, ctx->r6) = 0;
    // 0x80383FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383FBC:
    // 0x80383FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383FC0: jr          $ra
    // 0x80383FC4: nop

    return;
    // 0x80383FC4: nop

;}
RECOMP_FUNC void mnPlayers1PGameSetDigitColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131BFC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131C00: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131C04: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131C08: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131C0C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80131C10: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80131C14: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80131C18: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80131C1C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80131C20: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x80131C24: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80131C28: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x80131C2C: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x80131C30: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x80131C34: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80131C38: jr          $ra
    // 0x80131C3C: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
    return;
    // 0x80131C3C: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void grDisplayLayer1SecProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105088: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8010508C: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80105090: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80105094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010509C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801050A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801050A4: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801050A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801050AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801050B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801050B4: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x801050B8: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x801050BC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801050C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801050C4: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x801050C8: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x801050CC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801050D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801050D4: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x801050D8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801050DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801050E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801050E4: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801050E8: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x801050EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801050F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801050F4: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801050F8: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801050FC: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80105100: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80105104: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105108: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8010510C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80105110: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80105114: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80105118: ori         $t7, $t7, 0x49D8
    ctx->r15 = ctx->r15 | 0X49D8;
    // 0x8010511C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80105120: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105124: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x80105128: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8010512C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80105130: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80105134: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80105138: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8010513C: jal         0x80014768
    // 0x80105140: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80105140: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    after_0:
    // 0x80105144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010514C: jr          $ra
    // 0x80105150: nop

    return;
    // 0x80105150: nop

;}
RECOMP_FUNC void wpNessPKFireProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016AA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AA48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016AA4C: jal         0x80167FE8
    // 0x8016AA50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016AA50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8016AA54: beq         $v0, $zero, L_8016AA74
    if (ctx->r2 == 0) {
        // 0x8016AA58: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8016AA74;
    }
    // 0x8016AA58: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8016AA5C: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8016AA60: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016AA64: jal         0x800FF648
    // 0x8016AA68: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016AA68: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016AA6C: b           L_8016AA78
    // 0x8016AA70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016AA78;
    // 0x8016AA70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016AA74:
    // 0x8016AA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016AA78:
    // 0x8016AA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016AA80: jr          $ra
    // 0x8016AA84: nop

    return;
    // 0x8016AA84: nop

;}
RECOMP_FUNC void scStaffrollMakeTextBoxBracketSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801346B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801346B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801346BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801346C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801346C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801346C8: jal         0x80009968
    // 0x801346CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801346CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801346D0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801346D4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801346D8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801346DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801346E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801346E4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x801346E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801346EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x801346F0: jal         0x80009DF4
    // 0x801346F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801346F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801346F8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801346FC: lw          $t7, -0x55F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X55F0);
    // 0x80134700: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80134704: addiu       $t8, $t8, 0x6F98
    ctx->r24 = ADD32(ctx->r24, 0X6F98);
    // 0x80134708: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8013470C: jal         0x800CCFDC
    // 0x80134710: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80134710: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80134714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80134718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013471C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80134720: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134724: jal         0x80009968
    // 0x80134728: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80134728: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x8013472C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80134730: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80134734: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80134738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013473C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80134740: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80134744: jal         0x80009DF4
    // 0x80134748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80134748: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x8013474C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80134750: lw          $t0, -0x55F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X55F0);
    // 0x80134754: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80134758: addiu       $t1, $t1, 0x71D8
    ctx->r9 = ADD32(ctx->r9, 0X71D8);
    // 0x8013475C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80134760: jal         0x800CCFDC
    // 0x80134764: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80134764: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_5:
    // 0x80134768: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8013476C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134770: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134774: lwc1        $f2, -0x5844($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5844);
    // 0x80134778: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8013477C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80134780: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80134784: sh          $t3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r11;
    // 0x80134788: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8013478C: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x80134790: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80134794: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80134798: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x8013479C: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x801347A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801347A4: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
    // 0x801347A8: sb          $t5, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r13;
    // 0x801347AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801347B0: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801347B4: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801347B8: lui         $at, 0x43A4
    ctx->r1 = S32(0X43A4 << 16);
    // 0x801347BC: sb          $t7, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r15;
    // 0x801347C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801347C4: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x801347C8: lui         $at, 0x4413
    ctx->r1 = S32(0X4413 << 16);
    // 0x801347CC: sb          $t9, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r25;
    // 0x801347D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801347D4: swc1        $f12, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f12.u32l;
    // 0x801347D8: swc1        $f12, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f12.u32l;
    // 0x801347DC: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x801347E0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801347E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801347E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801347EC: jr          $ra
    // 0x801347F0: nop

    return;
    // 0x801347F0: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakeLuigi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131E1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131E20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E2C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131E30: jal         0x80009968
    // 0x80131E34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131E3C: jal         0x80131B58
    // 0x80131E40: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    mvOpeningNewcomersCheckLocked(rdram, ctx);
        goto after_1;
    // 0x80131E40: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80131E44: beq         $v0, $zero, L_80131E70
    if (ctx->r2 == 0) {
        // 0x80131E48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80131E70;
    }
    // 0x80131E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E50: lw          $t6, 0x2910($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2910);
    // 0x80131E54: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x80131E58: addiu       $t7, $t7, -0x73D8
    ctx->r15 = ADD32(ctx->r15, -0X73D8);
    // 0x80131E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E60: jal         0x800092D0
    // 0x80131E64: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131E64: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80131E68: b           L_80131E8C
    // 0x80131E6C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80131E8C;
    // 0x80131E6C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131E70:
    // 0x80131E70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131E74: lw          $t8, 0x2910($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2910);
    // 0x80131E78: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80131E7C: addiu       $t9, $t9, -0x37C8
    ctx->r25 = ADD32(ctx->r25, -0X37C8);
    // 0x80131E80: jal         0x800092D0
    // 0x80131E84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131E84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80131E88: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131E8C:
    // 0x80131E8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131E90: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131E94: jal         0x80008CC0
    // 0x80131E98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80131E98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80131E9C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131EA0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131EA4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80131EA8: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80131EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EB0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131EB4: jal         0x80009DF4
    // 0x80131EB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x80131EB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131EBC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131EC0: lw          $t1, 0x2910($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2910);
    // 0x80131EC4: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80131EC8: addiu       $t2, $t2, -0x316C
    ctx->r10 = ADD32(ctx->r10, -0X316C);
    // 0x80131ECC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131ED0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131ED4: jal         0x8000BD1C
    // 0x80131ED8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_6;
    // 0x80131ED8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80131EDC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131EE0: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131EEC: jal         0x80008188
    // 0x80131EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131EF8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131EFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131F00: jr          $ra
    // 0x80131F04: nop

    return;
    // 0x80131F04: nop

;}
RECOMP_FUNC void grYamabukiGateAddAnimOpenEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AF28: jal         0x8010AED8
    // 0x8010AF2C: nop

    grYamabukiGateAddAnimOpen(rdram, ctx);
        goto after_0;
    // 0x8010AF2C: nop

    after_0:
    // 0x8010AF30: jal         0x8010AE3C
    // 0x8010AF34: nop

    grYamabukiGateSetPositionFar(rdram, ctx);
        goto after_1;
    // 0x8010AF34: nop

    after_1:
    // 0x8010AF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AF40: jr          $ra
    // 0x8010AF44: nop

    return;
    // 0x8010AF44: nop

;}

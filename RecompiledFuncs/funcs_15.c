#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itBatFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174F04: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174F08: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80174F0C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80174F10: jal         0x80173F78
    // 0x80174F14: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80174F14: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80174F18: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174F1C: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    // 0x80174F20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174F24: jal         0x80172EC8
    // 0x80174F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174F28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80174F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174F34: jr          $ra
    // 0x80174F38: nop

    return;
    // 0x80174F38: nop

;}
RECOMP_FUNC void syAudioThreadMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF64: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8001FF68: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8001FF6C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001FF70: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8001FF74: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8001FF78: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8001FF7C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8001FF80: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8001FF84: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8001FF88: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8001FF8C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8001FF90: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001FF94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001FF98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001FF9C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8001FFA0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8001FFA4: jal         0x8001F444
    // 0x8001FFA8: sb          $t6, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r14;
    syAudioInit(rdram, ctx);
        goto after_0;
    // 0x8001FFA8: sb          $t6, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r14;
    after_0:
    // 0x8001FFAC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8001FFB0: addiu       $t8, $t8, -0x34C4
    ctx->r24 = ADD32(ctx->r24, -0X34C4);
    // 0x8001FFB4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8001FFB8: addiu       $t7, $t7, -0x2678
    ctx->r15 = ADD32(ctx->r15, -0X2678);
    // 0x8001FFBC: addiu       $t1, $t8, 0x60
    ctx->r9 = ADD32(ctx->r24, 0X60);
L_8001FFC0:
    // 0x8001FFC0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8001FFC4: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8001FFC8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8001FFCC: sw          $t0, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r8;
    // 0x8001FFD0: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8001FFD4: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x8001FFD8: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x8001FFDC: bne         $t8, $t1, L_8001FFC0
    if (ctx->r24 != ctx->r9) {
        // 0x8001FFE0: sw          $t0, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r8;
            goto L_8001FFC0;
    }
    // 0x8001FFE0: sw          $t0, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r8;
    // 0x8001FFE4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8001FFE8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8001FFEC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8001FFF0: jal         0x8001F4C0
    // 0x8001FFF4: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    syAudioLoadAssets(rdram, ctx);
        goto after_1;
    // 0x8001FFF4: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    after_1:
    // 0x8001FFF8: jal         0x8001FA00
    // 0x8001FFFC: nop

    syAudioMakeBGMPlayers(rdram, ctx);
        goto after_2;
    // 0x8001FFFC: nop

    after_2:
    // 0x80020000: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80020004: addiu       $t3, $t3, -0x2678
    ctx->r11 = ADD32(ctx->r11, -0X2678);
    // 0x80020008: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8002000C: addiu       $t2, $t2, -0x34C4
    ctx->r10 = ADD32(ctx->r10, -0X34C4);
    // 0x80020010: addiu       $t6, $t3, 0x60
    ctx->r14 = ADD32(ctx->r11, 0X60);
L_80020014:
    // 0x80020014: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80020018: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8002001C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80020020: sw          $t5, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r13;
    // 0x80020024: lw          $t4, -0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X8);
    // 0x80020028: sw          $t4, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r12;
    // 0x8002002C: lw          $t5, -0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, -0X4);
    // 0x80020030: bne         $t3, $t6, L_80020014
    if (ctx->r11 != ctx->r14) {
        // 0x80020034: sw          $t5, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r13;
            goto L_80020014;
    }
    // 0x80020034: sw          $t5, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r13;
    // 0x80020038: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8002003C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80020040: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020044: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x80020048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002004C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020050: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80020054: jal         0x80030000
    // 0x80020058: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80020058: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    after_3:
    // 0x8002005C: lui         $at, 0x46F0
    ctx->r1 = S32(0X46F0 << 16);
    // 0x80020060: lui         $fp, 0x800A
    ctx->r30 = S32(0X800A << 16);
    // 0x80020064: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x80020068: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x8002006C: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80020070: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80020074: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80020078: addiu       $s4, $s4, -0x2698
    ctx->r20 = ADD32(ctx->r20, -0X2698);
    // 0x8002007C: addiu       $s6, $s6, -0x2690
    ctx->r22 = ADD32(ctx->r22, -0X2690);
    // 0x80020080: addiu       $s7, $s7, -0x26A0
    ctx->r23 = ADD32(ctx->r23, -0X26A0);
    // 0x80020084: addiu       $fp, $fp, -0x26C0
    ctx->r30 = ADD32(ctx->r30, -0X26C0);
    // 0x80020088: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8002008C:
    // 0x8002008C: jal         0x80033490
    // 0x80020090: nop

    osGetCount_recomp(rdram, ctx);
        goto after_4;
    // 0x80020090: nop

    after_4:
    // 0x80020094: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020098: lw          $a0, -0x34D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34D0);
    // 0x8002009C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800200A0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800200A4: andi        $s2, $a0, 0x1
    ctx->r18 = ctx->r4 & 0X1;
    // 0x800200A8: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x800200AC: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x800200B0: addiu       $t8, $t8, -0x26C8
    ctx->r24 = ADD32(ctx->r24, -0X26C8);
    // 0x800200B4: lw          $t1, -0x26B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26B8);
    // 0x800200B8: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
    // 0x800200BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800200C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800200C4: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    // 0x800200C8: sw          $t7, -0x26CC($at)
    MEM_W(-0X26CC, ctx->r1) = ctx->r15;
    // 0x800200CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800200D0: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800200D4: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800200D8: mfhi        $s3
    ctx->r19 = hi;
    // 0x800200DC: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800200E0: slti        $at, $t9, 0x171
    ctx->r1 = SIGNED(ctx->r25) < 0X171 ? 1 : 0;
    // 0x800200E4: bne         $at, $zero, L_800200F8
    if (ctx->r1 != 0) {
        // 0x800200E8: lbu         $t0, 0x73($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X73);
            goto L_800200F8;
    }
    // 0x800200E8: lbu         $t0, 0x73($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X73);
    // 0x800200EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800200F0: bne         $t0, $at, L_80020114
    if (ctx->r8 != ctx->r1) {
        // 0x800200F4: nop
    
            goto L_80020114;
    }
    // 0x800200F4: nop

L_800200F8:
    // 0x800200F8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800200FC: lbu         $t3, 0x73($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X73);
    // 0x80020100: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x80020104: slti        $at, $t6, 0xB9
    ctx->r1 = SIGNED(ctx->r14) < 0XB9 ? 1 : 0;
    // 0x80020108: bne         $at, $zero, L_8002013C
    if (ctx->r1 != 0) {
        // 0x8002010C: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_8002013C;
    }
    // 0x8002010C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80020110: bne         $t3, $zero, L_8002013C
    if (ctx->r11 != 0) {
        // 0x80020114: lui         $t4, 0x8004
        ctx->r12 = S32(0X8004 << 16);
            goto L_8002013C;
    }
L_80020114:
    // 0x80020114: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80020118: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8002011C: lw          $t5, -0x26E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26E0);
    // 0x80020120: addiu       $t4, $t4, -0x34CC
    ctx->r12 = ADD32(ctx->r12, -0X34CC);
    // 0x80020124: sll         $t2, $s3, 1
    ctx->r10 = S32(ctx->r19 << 1);
    // 0x80020128: addu        $s1, $t2, $t4
    ctx->r17 = ADD32(ctx->r10, ctx->r12);
    // 0x8002012C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80020130: sb          $t1, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r9;
    // 0x80020134: b           L_80020160
    // 0x80020138: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
        goto L_80020160;
    // 0x80020138: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
L_8002013C:
    // 0x8002013C: lbu         $t0, 0x73($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X73);
    // 0x80020140: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80020144: lw          $t9, -0x26E4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26E4);
    // 0x80020148: addiu       $t7, $t7, -0x34CC
    ctx->r15 = ADD32(ctx->r15, -0X34CC);
    // 0x8002014C: addu        $s1, $t8, $t7
    ctx->r17 = ADD32(ctx->r24, ctx->r15);
    // 0x80020150: beq         $t0, $zero, L_80020160
    if (ctx->r8 == 0) {
        // 0x80020154: sh          $t9, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r25;
            goto L_80020160;
    }
    // 0x80020154: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x80020158: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x8002015C: sb          $t6, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r14;
L_80020160:
    // 0x80020160: jal         0x80034D50
    // 0x80020164: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80020164: nop

    after_5:
    // 0x80020168: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x8002016C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020170: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020174: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80020178: sw          $v0, -0x2610($at)
    MEM_W(-0X2610, ctx->r1) = ctx->r2;
    // 0x8002017C: sw          $v1, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = ctx->r3;
    // 0x80020180: jal         0x80032150
    // 0x80020184: lw          $a0, -0x26D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26D8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x80020184: lw          $a0, -0x26D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26D8);
    after_6:
    // 0x80020188: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002018C: lw          $a0, -0x26CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26CC);
    // 0x80020190: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80020194: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80020198: jal         0x8002C708
    // 0x8002019C: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    func_8002C708_2D308(rdram, ctx);
        goto after_7;
    // 0x8002019C: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    after_7:
    // 0x800201A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800201A4: sw          $v0, -0x26CC($at)
    MEM_W(-0X26CC, ctx->r1) = ctx->r2;
    // 0x800201A8: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800201AC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800201B0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800201B4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800201B8: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800201BC: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800201C0: addiu       $t0, $t0, -0x2CF0
    ctx->r8 = ADD32(ctx->r8, -0X2CF0);
    // 0x800201C4: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800201C8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800201CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800201D0: sw          $zero, 0x14($t8)
    MEM_W(0X14, ctx->r24) = 0;
    // 0x800201D4: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800201D8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800201DC: sw          $s5, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r21;
    // 0x800201E0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800201E4: sw          $zero, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = 0;
    // 0x800201E8: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800201EC: sw          $t0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r8;
    // 0x800201F0: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800201F4: sw          $t3, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r11;
    // 0x800201F8: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800201FC: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80020200: addiu       $t2, $t2, 0x4C40
    ctx->r10 = ADD32(ctx->r10, 0X4C40);
    // 0x80020204: sw          $zero, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = 0;
    // 0x80020208: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x8002020C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80020210: sw          $t5, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r13;
    // 0x80020214: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80020218: lw          $t8, -0x26CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26CC);
    // 0x8002021C: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80020220: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x80020224: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80020228: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8002022C: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x80020230: sw          $t6, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->r14;
    // 0x80020234: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80020238: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002023C: addiu       $t8, $t8, -0x6940
    ctx->r24 = ADD32(ctx->r24, -0X6940);
    // 0x80020240: sw          $t2, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r10;
    // 0x80020244: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80020248: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x8002024C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020250: sw          $t5, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r13;
    // 0x80020254: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80020258: addiu       $t6, $t6, -0xC00
    ctx->r14 = ADD32(ctx->r14, -0XC00);
    // 0x8002025C: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x80020260: sw          $t8, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r24;
    // 0x80020264: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x80020268: sw          $t9, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r25;
    // 0x8002026C: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80020270: sw          $t6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->r14;
    // 0x80020274: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80020278: sw          $t2, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r10;
    // 0x8002027C: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x80020280: sw          $zero, 0x48($t5)
    MEM_W(0X48, ctx->r13) = 0;
    // 0x80020284: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80020288: sw          $zero, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = 0;
    // 0x8002028C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80020290: sw          $zero, 0x60($t8)
    MEM_W(0X60, ctx->r24) = 0;
    // 0x80020294: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80020298: sw          $zero, 0x64($t7)
    MEM_W(0X64, ctx->r15) = 0;
    // 0x8002029C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800202A0: sw          $zero, 0x50($t9)
    MEM_W(0X50, ctx->r25) = 0;
    // 0x800202A4: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x800202A8: jal         0x80033490
    // 0x800202AC: sw          $zero, 0x54($t0)
    MEM_W(0X54, ctx->r8) = 0;
    osGetCount_recomp(rdram, ctx);
        goto after_8;
    // 0x800202AC: sw          $zero, 0x54($t0)
    MEM_W(0X54, ctx->r8) = 0;
    after_8:
    // 0x800202B0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800202B4: addiu       $at, $zero, 0xB9B
    ctx->r1 = ADD32(0, 0XB9B);
    // 0x800202B8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800202BC: subu        $t3, $v0, $t6
    ctx->r11 = SUB32(ctx->r2, ctx->r14);
    // 0x800202C0: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x800202C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800202C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800202CC: sw          $t2, -0x2D30($at)
    MEM_W(-0X2D30, ctx->r1) = ctx->r10;
    // 0x800202D0: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
    // 0x800202D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800202D8: jal         0x80030210
    // 0x800202DC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800202DC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_9:
        osAiGetLength_recomp(rdram, ctx);
    // 0x800202E0: nop

    // 0x800202E4: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x800202E8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800202EC: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x800202F0: srl         $t1, $t5, 2
    ctx->r9 = S32(U32(ctx->r13) >> 2);
    // 0x800202F4: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x800202F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800202FC: jal         0x80030210
    // 0x80020300: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80020300: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_10:
    // 0x80020304: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80020308: lw          $s3, -0x34D0($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X34D0);
    // 0x8002030C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80020310: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80020314: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80020318: div         $zero, $s3, $at
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r1)));
    // 0x8002031C: lw          $t8, -0x34DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X34DC);
    // 0x80020320: mfhi        $s3
    ctx->r19 = hi;
    // 0x80020324: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    // 0x80020328: bne         $t8, $zero, L_800203B4
    if (ctx->r24 != 0) {
        // 0x8002032C: lui         $t9, 0x8004
        ctx->r25 = S32(0X8004 << 16);
            goto L_800203B4;
    }
    // 0x8002032C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80020330: addiu       $t9, $t9, -0x34CC
    ctx->r25 = ADD32(ctx->r25, -0X34CC);
    // 0x80020334: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    // 0x80020338: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x8002033C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020340: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x80020344: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80020348: blez        $t6, L_800203B4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002034C: lui         $t2, 0x800A
        ctx->r10 = S32(0X800A << 16);
            goto L_800203B4;
    }
    // 0x8002034C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80020350: addiu       $t2, $t2, -0x26D8
    ctx->r10 = ADD32(ctx->r10, -0X26D8);
    // 0x80020354: addu        $s0, $t3, $t2
    ctx->r16 = ADD32(ctx->r11, ctx->r10);
    // 0x80020358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002035C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_80020360:
    // 0x80020360: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80020364: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80020368: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002036C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80020370: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80020374: bgez        $t8, L_80020384
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80020378: sra         $t7, $t8, 1
        ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80020384;
    }
    // 0x80020378: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8002037C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80020380: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80020384:
    // 0x80020384: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x80020388: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8002038C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80020390: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80020394: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    // 0x80020398: sh          $t9, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r25;
    // 0x8002039C: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x800203A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800203A4: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x800203A8: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800203AC: bnel        $at, $zero, L_80020360
    if (ctx->r1 != 0) {
        // 0x800203B0: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_80020360;
    }
    goto skip_0;
    // 0x800203B0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_0:
L_800203B4:
    // 0x800203B4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800203B8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800203BC: addiu       $t8, $t8, -0x26D8
    ctx->r24 = ADD32(ctx->r24, -0X26D8);
    // 0x800203C0: addiu       $t5, $t5, -0x34CC
    ctx->r13 = ADD32(ctx->r13, -0X34CC);
    // 0x800203C4: sll         $t4, $s3, 1
    ctx->r12 = S32(ctx->r19 << 1);
    // 0x800203C8: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x800203CC: addu        $s0, $t1, $t8
    ctx->r16 = ADD32(ctx->r9, ctx->r24);
    // 0x800203D0: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x800203D4: jal         0x80039160
    // 0x800203D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_11;
    // 0x800203D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_11:
    // 0x800203DC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x800203E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800203E4: jal         0x80039550
    // 0x800203E8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_12;
    // 0x800203E8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_12:
    // 0x800203EC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800203F0: lw          $t7, -0x34E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X34E0);
    // 0x800203F4: blez        $t7, L_80020428
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800203F8: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_80020428;
    }
L_800203F8:
    // 0x800203F8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800203FC: addiu       $a0, $a0, -0x2CD8
    ctx->r4 = ADD32(ctx->r4, -0X2CD8);
    // 0x80020400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020404: jal         0x80030210
    // 0x80020408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_13;
    // 0x80020408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8002040C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80020410: lw          $t0, -0x34E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X34E0);
    // 0x80020414: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80020418: slt         $at, $s2, $t0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002041C: bne         $at, $zero, L_800203F8
    if (ctx->r1 != 0) {
        // 0x80020420: nop
    
            goto L_800203F8;
    }
    // 0x80020420: nop

    // 0x80020424: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80020428:
    // 0x80020428: jal         0x80039160
    // 0x8002042C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_14;
    // 0x8002042C: nop

    after_14:
    // 0x80020430: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020434: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    // 0x80020438: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8002043C: jal         0x80030000
    // 0x80020440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_15;
    // 0x80020440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80020444: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80020448: lw          $t9, -0x34D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X34D0);
    // 0x8002044C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020450: lbu         $a0, -0x2645($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2645);
    // 0x80020454: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020458: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8002045C: sw          $t6, -0x34D0($at)
    MEM_W(-0X34D0, ctx->r1) = ctx->r14;
    // 0x80020460: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020464: blez        $a0, L_800204B4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80020468: sw          $zero, -0x34E0($at)
        MEM_W(-0X34E0, ctx->r1) = 0;
            goto L_800204B4;
    }
    // 0x80020468: sw          $zero, -0x34E0($at)
    MEM_W(-0X34E0, ctx->r1) = 0;
    // 0x8002046C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80020470:
    // 0x80020470: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80020474: lw          $t3, -0x26AC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26AC);
    // 0x80020478: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002047C: addu        $v0, $t3, $s1
    ctx->r2 = ADD32(ctx->r11, ctx->r17);
    // 0x80020480: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80020484: beql        $v1, $zero, L_800204A8
    if (ctx->r3 == 0) {
        // 0x80020488: slt         $at, $s2, $a0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800204A8;
    }
    goto skip_1;
    // 0x80020488: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    skip_1:
    // 0x8002048C: lhu         $t2, 0x10($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X10);
    // 0x80020490: bnel        $t2, $zero, L_800204A8
    if (ctx->r10 != 0) {
        // 0x80020494: slt         $at, $s2, $a0
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800204A8;
    }
    goto skip_2;
    // 0x80020494: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    skip_2:
    // 0x80020498: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002049C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800204A0: lbu         $a0, -0x2645($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2645);
    // 0x800204A4: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
L_800204A8:
    // 0x800204A8: bne         $at, $zero, L_80020470
    if (ctx->r1 != 0) {
        // 0x800204AC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80020470;
    }
    // 0x800204AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800204B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800204B4:
    // 0x800204B4: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
L_800204B8:
    // 0x800204B8: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x800204BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800204C0: addu        $v0, $t4, $s2
    ctx->r2 = ADD32(ctx->r12, ctx->r18);
    // 0x800204C4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800204C8: addu        $t5, $s7, $s1
    ctx->r13 = ADD32(ctx->r23, ctx->r17);
    // 0x800204CC: beq         $a0, $s5, L_800204F0
    if (ctx->r4 == ctx->r21) {
        // 0x800204D0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800204F0;
    }
    // 0x800204D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800204D4: beq         $v1, $at, L_80020570
    if (ctx->r3 == ctx->r1) {
        // 0x800204D8: sll         $s1, $s2, 2
        ctx->r17 = S32(ctx->r18 << 2);
            goto L_80020570;
    }
    // 0x800204D8: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x800204DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800204E0: beq         $v1, $at, L_800205F0
    if (ctx->r3 == ctx->r1) {
        // 0x800204E4: sll         $s1, $s2, 2
        ctx->r17 = S32(ctx->r18 << 2);
            goto L_800205F0;
    }
    // 0x800204E4: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x800204E8: b           L_80020620
    // 0x800204EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80020620;
    // 0x800204EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800204F0:
    // 0x800204F0: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800204F4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800204F8: lw          $t1, 0x34($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X34);
    // 0x800204FC: beq         $t1, $zero, L_80020514
    if (ctx->r9 == 0) {
        // 0x80020500: nop
    
            goto L_80020514;
    }
    // 0x80020500: nop

    // 0x80020504: jal         0x8002FE90
    // 0x80020508: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alCSPStop(rdram, ctx);
        goto after_16;
    // 0x80020508: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_16:
    // 0x8002050C: b           L_80020620
    // 0x80020510: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80020620;
    // 0x80020510: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80020514:
    // 0x80020514: lw          $t8, -0x268C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X268C);
    // 0x80020518: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x8002051C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80020520: addu        $t7, $t8, $s1
    ctx->r15 = ADD32(ctx->r24, ctx->r17);
    // 0x80020524: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80020528: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002052C: bgez        $v1, L_8002053C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80020530: sll         $t6, $v1, 3
        ctx->r14 = S32(ctx->r3 << 3);
            goto L_8002053C;
    }
    // 0x80020530: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80020534: b           L_8002061C
    // 0x80020538: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_8002061C;
    // 0x80020538: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_8002053C:
    // 0x8002053C: lw          $t9, -0x26A4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26A4);
    // 0x80020540: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x80020544: lw          $a1, -0x2694($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2694);
    // 0x80020548: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x8002054C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80020550: jal         0x8001E91C
    // 0x80020554: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    syAudioReadRom(rdram, ctx);
        goto after_17;
    // 0x80020554: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_17:
    // 0x80020558: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8002055C: addu        $v0, $t3, $s2
    ctx->r2 = ADD32(ctx->r11, ctx->r18);
    // 0x80020560: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80020564: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80020568: b           L_8002061C
    // 0x8002056C: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
        goto L_8002061C;
    // 0x8002056C: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_80020570:
    // 0x80020570: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80020574: addiu       $t5, $t5, -0x269C
    ctx->r13 = ADD32(ctx->r13, -0X269C);
    // 0x80020578: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002057C: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x80020580: addu        $s3, $s1, $t5
    ctx->r19 = ADD32(ctx->r17, ctx->r13);
    // 0x80020584: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80020588: lw          $a1, -0x2694($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2694);
    // 0x8002058C: jal         0x80028884
    // 0x80020590: addu        $s0, $s7, $s1
    ctx->r16 = ADD32(ctx->r23, ctx->r17);
    n_alCSeqNew(rdram, ctx);
        goto after_18;
    // 0x80020590: addu        $s0, $s7, $s1
    ctx->r16 = ADD32(ctx->r23, ctx->r17);
    after_18:
    // 0x80020594: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80020598: jal         0x8002FA70
    // 0x8002059C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    alCSPSetSeq(rdram, ctx);
        goto after_19;
    // 0x8002059C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_19:
    // 0x800205A0: jal         0x8002FDB0
    // 0x800205A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    alCSPPlay(rdram, ctx);
        goto after_20;
    // 0x800205A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_20:
    // 0x800205A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800205AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800205B0:
    // 0x800205B0: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x800205B4: lbu         $a2, 0x0($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X0);
    // 0x800205B8: jal         0x80025FC0
    // 0x800205BC: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    alCSPSetChlPriority(rdram, ctx);
        goto after_21;
    // 0x800205BC: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    after_21:
    // 0x800205C0: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800205C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800205C8: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800205CC: bnel        $at, $zero, L_800205B0
    if (ctx->r1 != 0) {
        // 0x800205D0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800205B0;
    }
    goto skip_3;
    // 0x800205D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800205D4: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800205D8: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x800205DC: addu        $v0, $t1, $s2
    ctx->r2 = ADD32(ctx->r9, ctx->r18);
    // 0x800205E0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800205E4: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800205E8: b           L_8002061C
    // 0x800205EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8002061C;
    // 0x800205EC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800205F0:
    // 0x800205F0: addu        $t0, $s7, $s1
    ctx->r8 = ADD32(ctx->r23, ctx->r17);
    // 0x800205F4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800205F8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800205FC: lw          $t6, 0x34($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X34);
    // 0x80020600: bnel        $t6, $zero, L_80020620
    if (ctx->r14 != 0) {
        // 0x80020604: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80020620;
    }
    goto skip_4;
    // 0x80020604: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80020608: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8002060C: lw          $t2, -0x268C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X268C);
    // 0x80020610: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80020614: addu        $t4, $t2, $s1
    ctx->r12 = ADD32(ctx->r10, ctx->r17);
    // 0x80020618: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8002061C:
    // 0x8002061C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80020620:
    // 0x80020620: blezl       $s2, L_800204B8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80020624: lw          $t4, 0x0($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X0);
            goto L_800204B8;
    }
    goto skip_5;
    // 0x80020624: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    skip_5:
    // 0x80020628: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8002062C: addiu       $s0, $s0, -0x2688
    ctx->r16 = ADD32(ctx->r16, -0X2688);
    // 0x80020630: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80020634:
    // 0x80020634: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80020638: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8002063C: addiu       $t1, $t1, -0x2684
    ctx->r9 = ADD32(ctx->r9, -0X2684);
    // 0x80020640: beq         $v1, $zero, L_800206C0
    if (ctx->r3 == 0) {
        // 0x80020644: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_800206C0;
    }
    // 0x80020644: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80020648: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002064C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80020650: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x80020654: addu        $v0, $s1, $t1
    ctx->r2 = ADD32(ctx->r17, ctx->r9);
    // 0x80020658: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002065C: lwc1        $f6, -0x2680($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2680);
    // 0x80020660: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80020664: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80020668: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002066C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80020670: nop

    // 0x80020674: bc1fl       L_8002068C
    if (!c1cs) {
        // 0x80020678: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_8002068C;
    }
    goto skip_6;
    // 0x80020678: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_6:
    // 0x8002067C: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x80020680: b           L_800206A0
    // 0x80020684: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
        goto L_800206A0;
    // 0x80020684: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020688: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_8002068C:
    // 0x8002068C: nop

    // 0x80020690: bc1fl       L_800206A4
    if (!c1cs) {
        // 0x80020694: trunc.w.s   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800206A4;
    }
    goto skip_7;
    // 0x80020694: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_7:
    // 0x80020698: swc1        $f22, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f22.u32l;
    // 0x8002069C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_800206A0:
    // 0x800206A0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
L_800206A4:
    // 0x800206A4: addu        $t8, $s7, $s1
    ctx->r24 = ADD32(ctx->r23, ctx->r17);
    // 0x800206A8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800206AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800206B0: nop

    // 0x800206B4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800206B8: jal         0x8002FC10
    // 0x800206BC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_22;
    // 0x800206BC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_22:
L_800206C0:
    // 0x800206C0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800206C4: addiu       $t0, $t0, -0x2684
    ctx->r8 = ADD32(ctx->r8, -0X2684);
    // 0x800206C8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800206CC: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800206D0: bne         $at, $zero, L_80020634
    if (ctx->r1 != 0) {
        // 0x800206D4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80020634;
    }
    // 0x800206D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800206D8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800206DC: lw          $t9, -0x34E4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X34E4);
    // 0x800206E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800206E4: beq         $t9, $zero, L_80020870
    if (ctx->r25 == 0) {
        // 0x800206E8: nop
    
            goto L_80020870;
    }
    // 0x800206E8: nop

    // 0x800206EC: lbu         $a0, -0x2645($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2645);
    // 0x800206F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800206F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800206F8: blez        $a0, L_80020734
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800206FC: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_80020734;
    }
    // 0x800206FC: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80020700: lw          $v0, -0x26AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26AC);
    // 0x80020704: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_80020708:
    // 0x80020708: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002070C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80020710: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80020714: bne         $t6, $zero, L_80020728
    if (ctx->r14 != 0) {
        // 0x80020718: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80020728;
    }
    // 0x80020718: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002071C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80020720: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80020724: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_80020728:
    // 0x80020728: bne         $at, $zero, L_80020708
    if (ctx->r1 != 0) {
        // 0x8002072C: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_80020708;
    }
    // 0x8002072C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80020730: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80020734:
    // 0x80020734: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80020738: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_8002073C:
    // 0x8002073C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80020740: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80020744: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020748: bne         $t2, $zero, L_80020758
    if (ctx->r10 != 0) {
        // 0x8002074C: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_80020758;
    }
    // 0x8002074C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80020750: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80020754: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_80020758:
    // 0x80020758: bne         $s2, $s5, L_8002073C
    if (ctx->r18 != ctx->r21) {
        // 0x8002075C: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_8002073C;
    }
    // 0x8002075C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80020760: bne         $v1, $zero, L_80020860
    if (ctx->r3 != 0) {
        // 0x80020764: sw          $v1, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r3;
            goto L_80020860;
    }
    // 0x80020764: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x80020768: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002076C: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x80020770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020774: jal         0x80030210
    // 0x80020778: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_23;
    // 0x80020778: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_23:
    // 0x8002077C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020780: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x80020784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020788: jal         0x80030000
    // 0x8002078C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_24;
    // 0x8002078C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_24:
    // 0x80020790: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020794: jal         0x8002CE48
    // 0x80020798: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    n_alClose(rdram, ctx);
        goto after_25;
    // 0x80020798: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    after_25:
    // 0x8002079C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800207A0: addiu       $t4, $t4, -0x34C4
    ctx->r12 = ADD32(ctx->r12, -0X34C4);
    // 0x800207A4: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800207A8: addiu       $t3, $t3, -0x2678
    ctx->r11 = ADD32(ctx->r11, -0X2678);
    // 0x800207AC: addiu       $t8, $t4, 0x60
    ctx->r24 = ADD32(ctx->r12, 0X60);
L_800207B0:
    // 0x800207B0: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x800207B4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800207B8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800207BC: sw          $t1, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r9;
    // 0x800207C0: lw          $t5, -0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, -0X8);
    // 0x800207C4: sw          $t5, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r13;
    // 0x800207C8: lw          $t1, -0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, -0X4);
    // 0x800207CC: bne         $t4, $t8, L_800207B0
    if (ctx->r12 != ctx->r24) {
        // 0x800207D0: sw          $t1, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r9;
            goto L_800207B0;
    }
    // 0x800207D0: sw          $t1, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r9;
    // 0x800207D4: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x800207D8: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800207DC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800207E0: jal         0x8001F4C0
    // 0x800207E4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    syAudioLoadAssets(rdram, ctx);
        goto after_26;
    // 0x800207E4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    after_26:
    // 0x800207E8: jal         0x8001FA00
    // 0x800207EC: nop

    syAudioMakeBGMPlayers(rdram, ctx);
        goto after_27;
    // 0x800207EC: nop

    after_27:
    // 0x800207F0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800207F4: addiu       $t0, $t0, -0x2678
    ctx->r8 = ADD32(ctx->r8, -0X2678);
    // 0x800207F8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800207FC: addiu       $t7, $t7, -0x34C4
    ctx->r15 = ADD32(ctx->r15, -0X34C4);
    // 0x80020800: addiu       $t2, $t0, 0x60
    ctx->r10 = ADD32(ctx->r8, 0X60);
L_80020804:
    // 0x80020804: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80020808: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002080C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80020810: sw          $t6, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r14;
    // 0x80020814: lw          $t9, -0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X8);
    // 0x80020818: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x8002081C: lw          $t6, -0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, -0X4);
    // 0x80020820: bne         $t0, $t2, L_80020804
    if (ctx->r8 != ctx->r10) {
        // 0x80020824: sw          $t6, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r14;
            goto L_80020804;
    }
    // 0x80020824: sw          $t6, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r14;
    // 0x80020828: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8002082C: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x80020830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020834: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020838: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002083C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80020840: sw          $zero, -0x34E4($at)
    MEM_W(-0X34E4, ctx->r1) = 0;
    // 0x80020844: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80020848: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x8002084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80020850: jal         0x80030000
    // 0x80020854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_28;
    // 0x80020854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80020858: b           L_80020870
    // 0x8002085C: nop

        goto L_80020870;
    // 0x8002085C: nop

L_80020860:
    // 0x80020860: jal         0x80020A74
    // 0x80020864: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_29;
    // 0x80020864: nop

    after_29:
    // 0x80020868: jal         0x80020E28
    // 0x8002086C: nop

    func_80020E28(rdram, ctx);
        goto after_30;
    // 0x8002086C: nop

    after_30:
L_80020870:
    // 0x80020870: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80020874: lw          $t8, -0x34D4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X34D4);
    // 0x80020878: beq         $t8, $zero, L_8002008C
    if (ctx->r24 == 0) {
        // 0x8002087C: nop
    
            goto L_8002008C;
    }
    // 0x8002087C: nop

    // 0x80020880: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020884: lbu         $a0, -0x2645($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2645);
    // 0x80020888: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002088C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80020890: blez        $a0, L_800208CC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80020894: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800208CC;
    }
    // 0x80020894: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80020898: lw          $v0, -0x26AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26AC);
    // 0x8002089C: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_800208A0:
    // 0x800208A0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800208A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800208A8: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800208AC: bne         $t4, $zero, L_800208C0
    if (ctx->r12 != 0) {
        // 0x800208B0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800208C0;
    }
    // 0x800208B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800208B4: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800208B8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800208BC: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_800208C0:
    // 0x800208C0: bne         $at, $zero, L_800208A0
    if (ctx->r1 != 0) {
        // 0x800208C4: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_800208A0;
    }
    // 0x800208C4: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800208C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800208CC:
    // 0x800208CC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800208D0: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_800208D4:
    // 0x800208D4: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800208D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800208DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800208E0: bne         $t3, $zero, L_800208F0
    if (ctx->r11 != 0) {
        // 0x800208E4: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_800208F0;
    }
    // 0x800208E4: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800208E8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800208EC: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_800208F0:
    // 0x800208F0: bne         $s2, $s5, L_800208D4
    if (ctx->r18 != ctx->r21) {
        // 0x800208F4: lw          $v1, 0x80($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X80);
            goto L_800208D4;
    }
    // 0x800208F4: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800208F8: bne         $v1, $zero, L_800209BC
    if (ctx->r3 != 0) {
        // 0x800208FC: sw          $v1, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r3;
            goto L_800209BC;
    }
    // 0x800208FC: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x80020900: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020904: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x80020908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002090C: jal         0x80030210
    // 0x80020910: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_31;
    // 0x80020910: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_31:
    // 0x80020914: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020918: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8002091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020920: jal         0x80030000
    // 0x80020924: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_32;
    // 0x80020924: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_32:
    // 0x80020928: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002092C: jal         0x8002CE48
    // 0x80020930: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    n_alClose(rdram, ctx);
        goto after_33;
    // 0x80020930: addiu       $a0, $a0, -0x2740
    ctx->r4 = ADD32(ctx->r4, -0X2740);
    after_33:
    // 0x80020934: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80020938: lw          $t5, -0x2D18($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D18);
    // 0x8002093C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80020940: addiu       $v0, $v0, -0x2D28
    ctx->r2 = ADD32(ctx->r2, -0X2D28);
    // 0x80020944: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80020948: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8002094C: lw          $t1, -0x2D14($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D14);
    // 0x80020950: jal         0x8001FA00
    // 0x80020954: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    syAudioMakeBGMPlayers(rdram, ctx);
        goto after_34;
    // 0x80020954: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    after_34:
    // 0x80020958: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8002095C: addiu       $t0, $t0, -0x2678
    ctx->r8 = ADD32(ctx->r8, -0X2678);
    // 0x80020960: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80020964: addiu       $t2, $t2, -0x34C4
    ctx->r10 = ADD32(ctx->r10, -0X34C4);
    // 0x80020968: addiu       $t6, $t0, 0x60
    ctx->r14 = ADD32(ctx->r8, 0X60);
L_8002096C:
    // 0x8002096C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80020970: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80020974: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80020978: sw          $t9, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r25;
    // 0x8002097C: lw          $t7, -0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, -0X8);
    // 0x80020980: sw          $t7, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r15;
    // 0x80020984: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x80020988: bne         $t0, $t6, L_8002096C
    if (ctx->r8 != ctx->r14) {
        // 0x8002098C: sw          $t9, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r25;
            goto L_8002096C;
    }
    // 0x8002098C: sw          $t9, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r25;
    // 0x80020990: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80020994: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80020998: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002099C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800209A0: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800209A4: sw          $zero, -0x34D4($at)
    MEM_W(-0X34D4, ctx->r1) = 0;
        osAiGetLength_recomp(rdram, ctx);
    // 0x800209A8: nop

    // 0x800209AC: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x800209B0: srl         $t3, $t4, 2
    ctx->r11 = S32(U32(ctx->r12) >> 2);
    // 0x800209B4: b           L_8002008C
    // 0x800209B8: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
        goto L_8002008C;
    // 0x800209B8: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
L_800209BC:
    // 0x800209BC: jal         0x80020A74
    // 0x800209C0: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_35;
    // 0x800209C0: nop

    after_35:
    // 0x800209C4: jal         0x80020E28
    // 0x800209C8: nop

    func_80020E28(rdram, ctx);
        goto after_36;
    // 0x800209C8: nop

    after_36:
    // 0x800209CC: b           L_8002008C
    // 0x800209D0: nop

        goto L_8002008C;
    // 0x800209D0: nop

    // 0x800209D4: nop

    // 0x800209D8: nop

    // 0x800209DC: nop

    // 0x800209E0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800209E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800209E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800209EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800209F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800209F4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800209F8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800209FC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80020A00: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80020A04: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80020A08: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80020A0C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80020A10: jr          $ra
    // 0x80020A14: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80020A14: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNReleaseSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F7AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F7B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F7B4: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015F7B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F7BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015F7C0: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x8015F7C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F7C8: jal         0x800E6F24
    // 0x8015F7CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F7CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015F7D0: jal         0x800E0830
    // 0x8015F7D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F7D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015F7D8: jal         0x8015F734
    // 0x8015F7DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyYoshiSpecialNReleaseInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015F7DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015F7E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F7E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F7E8: jr          $ra
    // 0x8015F7EC: nop

    return;
    // 0x8015F7EC: nop

;}
RECOMP_FUNC void mnMapsDestroyPreview(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801332E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801332E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801332E8: bne         $a0, $zero, L_8013334C
    if (ctx->r4 != 0) {
        // 0x801332EC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8013334C;
    }
    // 0x801332EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801332F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801332F4: addiu       $s0, $s0, 0x4BE4
    ctx->r16 = ADD32(ctx->r16, 0X4BE4);
    // 0x801332F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801332FC: beq         $a0, $zero, L_80133310
    if (ctx->r4 == 0) {
        // 0x80133300: nop
    
            goto L_80133310;
    }
    // 0x80133300: nop

    // 0x80133304: jal         0x80009A84
    // 0x80133308: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133308: nop

    after_0:
    // 0x8013330C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80133310:
    // 0x80133310: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133314: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133318: addiu       $s1, $s1, 0x4C00
    ctx->r17 = ADD32(ctx->r17, 0X4C00);
    // 0x8013331C: addiu       $s0, $s0, 0x4BF0
    ctx->r16 = ADD32(ctx->r16, 0X4BF0);
    // 0x80133320: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80133324:
    // 0x80133324: beql        $a0, $zero, L_8013333C
    if (ctx->r4 == 0) {
        // 0x80133328: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8013333C;
    }
    goto skip_0;
    // 0x80133328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8013332C: jal         0x80009A84
    // 0x80133330: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80133330: nop

    after_1:
    // 0x80133334: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80133338: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8013333C:
    // 0x8013333C: bnel        $s0, $s1, L_80133324
    if (ctx->r16 != ctx->r17) {
        // 0x80133340: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80133324;
    }
    goto skip_1;
    // 0x80133340: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80133344: b           L_801333A4
    // 0x80133348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801333A4;
    // 0x80133348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013334C:
    // 0x8013334C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133350: addiu       $s0, $s0, 0x4BE8
    ctx->r16 = ADD32(ctx->r16, 0X4BE8);
    // 0x80133354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80133358: beq         $a0, $zero, L_8013336C
    if (ctx->r4 == 0) {
        // 0x8013335C: nop
    
            goto L_8013336C;
    }
    // 0x8013335C: nop

    // 0x80133360: jal         0x80009A84
    // 0x80133364: nop

    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80133364: nop

    after_2:
    // 0x80133368: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8013336C:
    // 0x8013336C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133370: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133374: addiu       $s1, $s1, 0x4C10
    ctx->r17 = ADD32(ctx->r17, 0X4C10);
    // 0x80133378: addiu       $s0, $s0, 0x4C00
    ctx->r16 = ADD32(ctx->r16, 0X4C00);
    // 0x8013337C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80133380:
    // 0x80133380: beql        $a0, $zero, L_80133398
    if (ctx->r4 == 0) {
        // 0x80133384: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80133398;
    }
    goto skip_2;
    // 0x80133384: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x80133388: jal         0x80009A84
    // 0x8013338C: nop

    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x8013338C: nop

    after_3:
    // 0x80133390: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80133394: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80133398:
    // 0x80133398: bnel        $s0, $s1, L_80133380
    if (ctx->r16 != ctx->r17) {
        // 0x8013339C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80133380;
    }
    goto skip_3;
    // 0x8013339C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x801333A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801333A4:
    // 0x801333A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801333A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801333AC: jr          $ra
    // 0x801333B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801333B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonCaptureKirbyProcCapture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B968: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014B96C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014B970: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014B974: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014B978: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014B97C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014B980: jal         0x800E823C
    // 0x8014B984: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x8014B984: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014B988: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x8014B98C: beql        $v0, $zero, L_8014B9CC
    if (ctx->r2 == 0) {
        // 0x8014B990: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014B9CC;
    }
    goto skip_0;
    // 0x8014B990: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x8014B994: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014B998: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x8014B99C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8014B9A0: bnel        $t8, $zero, L_8014B9CC
    if (ctx->r24 != 0) {
        // 0x8014B9A4: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014B9CC;
    }
    goto skip_1;
    // 0x8014B9A4: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x8014B9A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014B9AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014B9B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8014B9B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8014B9B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8014B9BC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8014B9C0: jal         0x80172AEC
    // 0x8014B9C4: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x8014B9C4: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x8014B9C8: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_8014B9CC:
    // 0x8014B9CC: beql        $a0, $zero, L_8014B9E8
    if (ctx->r4 == 0) {
        // 0x8014B9D0: lw          $a0, 0x844($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X844);
            goto L_8014B9E8;
    }
    goto skip_2;
    // 0x8014B9D0: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    skip_2:
    // 0x8014B9D4: jal         0x8014B330
    // 0x8014B9D8: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x8014B9D8: nop

    after_2:
    // 0x8014B9DC: b           L_8014B9F8
    // 0x8014B9E0: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
        goto L_8014B9F8;
    // 0x8014B9E0: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014B9E4: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
L_8014B9E8:
    // 0x8014B9E8: beql        $a0, $zero, L_8014B9FC
    if (ctx->r4 == 0) {
        // 0x8014B9EC: lbu         $t9, 0x192($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X192);
            goto L_8014B9FC;
    }
    goto skip_3;
    // 0x8014B9EC: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
    skip_3:
    // 0x8014B9F0: jal         0x8014AECC
    // 0x8014B9F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x8014B9F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_8014B9F8:
    // 0x8014B9F8: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
L_8014B9FC:
    // 0x8014B9FC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8014BA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BA04: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8014BA08: sb          $t0, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r8;
    // 0x8014BA0C: sw          $v1, 0x844($s0)
    MEM_W(0X844, ctx->r16) = ctx->r3;
    // 0x8014BA10: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8014BA14: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x8014BA18: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8014BA1C: jal         0x800DEEC8
    // 0x8014BA20: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_4;
    // 0x8014BA20: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    after_4:
    // 0x8014BA24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014BA28: addiu       $a1, $zero, 0xAD
    ctx->r5 = ADD32(0, 0XAD);
    // 0x8014BA2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014BA30: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014BA34: jal         0x800E6F24
    // 0x8014BA38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_5;
    // 0x8014BA38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8014BA3C: jal         0x800E0830
    // 0x8014BA40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_6;
    // 0x8014BA40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8014BA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BA48: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8014BA4C: jal         0x800E806C
    // 0x8014BA50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_7;
    // 0x8014BA50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8014BA54: sh          $zero, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = 0;
    // 0x8014BA58: sh          $zero, 0xB1A($s0)
    MEM_H(0XB1A, ctx->r16) = 0;
    // 0x8014BA5C: sh          $zero, 0xB1C($s0)
    MEM_H(0XB1C, ctx->r16) = 0;
    // 0x8014BA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BA64: jal         0x800E8098
    // 0x8014BA68: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_8;
    // 0x8014BA68: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_8:
    // 0x8014BA6C: jal         0x800D9444
    // 0x8014BA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_9;
    // 0x8014BA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8014BA74: jal         0x8014B914
    // 0x8014BA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCaptureKirbyProcPhysics(rdram, ctx);
        goto after_10;
    // 0x8014BA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8014BA7C: jal         0x800DE348
    // 0x8014BA80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpCommonUpdateFighterProjectFloor(rdram, ctx);
        goto after_11;
    // 0x8014BA80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8014BA84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014BA88: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BA8C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014BA90: jr          $ra
    // 0x8014BA94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014BA94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnVSRecordMakeResortArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132BE4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132BE8: jal         0x80009968
    // 0x80132BEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132BEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132BF0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132BF4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132BF8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132BFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132C00: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132C0C: jal         0x80009DF4
    // 0x80132C10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132C10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132C14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132C18: addiu       $a1, $a1, 0x2BA4
    ctx->r5 = ADD32(ctx->r5, 0X2BA4);
    // 0x80132C1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132C20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132C24: jal         0x80008188
    // 0x80132C28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132C28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132C2C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132C30: lw          $t7, 0x6D88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D88);
    // 0x80132C34: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132C38: addiu       $t8, $t8, 0x1668
    ctx->r24 = ADD32(ctx->r24, 0X1668);
    // 0x80132C3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132C40: jal         0x800CCFDC
    // 0x80132C44: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132C44: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132C48: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132C4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132C50: addiu       $t3, $zero, 0xE3
    ctx->r11 = ADD32(0, 0XE3);
    // 0x80132C54: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132C58: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132C5C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132C60: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132C64: lwc1        $f4, 0x6BCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BCC);
    // 0x80132C68: lui         $at, 0x421C
    ctx->r1 = S32(0X421C << 16);
    // 0x80132C6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132C70: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x80132C74: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132C78: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132C7C: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132C80: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132C84: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132C88: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132C90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132C94: jr          $ra
    // 0x80132C98: nop

    return;
    // 0x80132C98: nop

;}
RECOMP_FUNC void ftBossDrillSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A268: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015A26C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A270: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015A274: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A278: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x8015A27C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A280: jal         0x800E6F24
    // 0x8015A284: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A284: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A288: jal         0x80157F90
    // 0x8015A28C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftBossCommonCheckEdgeInvertLR(rdram, ctx);
        goto after_1;
    // 0x8015A28C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8015A290: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8015A294: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A298: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015A29C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    // 0x8015A2A0: jal         0x800F4428
    // 0x8015A2A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x8015A2A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015A2A8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015A2AC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015A2B0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A2B4: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    // 0x8015A2B8: jal         0x800F4408
    // 0x8015A2BC: swc1        $f4, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f4.u32l;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_3;
    // 0x8015A2BC: swc1        $f4, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f4.u32l;
    after_3:
    // 0x8015A2C0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015A2C4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015A2C8: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x8015A2CC: sh          $t7, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r15;
    // 0x8015A2D0: swc1        $f6, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->f6.u32l;
    // 0x8015A2D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A2D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015A2DC: jr          $ra
    // 0x8015A2E0: nop

    return;
    // 0x8015A2E0: nop

;}
RECOMP_FUNC void func_ovl8_8037CFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CFD8: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8037CFDC: jr          $ra
    // 0x8037CFE0: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    return;
    // 0x8037CFE0: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void itPakkunDamagedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CF88: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CF8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017CF90: addiu       $a1, $a1, -0x561C
    ctx->r5 = ADD32(ctx->r5, -0X561C);
    // 0x8017CF94: jal         0x80172EC8
    // 0x8017CF98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017CF98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8017CF9C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017CFA0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017CFA4: addiu       $t6, $t6, -0x2BA0
    ctx->r14 = ADD32(ctx->r14, -0X2BA0);
    // 0x8017CFA8: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x8017CFAC: sw          $t6, 0x398($t8)
    MEM_W(0X398, ctx->r24) = ctx->r14;
    // 0x8017CFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CFB8: jr          $ra
    // 0x8017CFBC: nop

    return;
    // 0x8017CFBC: nop

;}
RECOMP_FUNC void mn1PModeFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E9C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132EA0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132EA4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132EA8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132EAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132EB0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132EB4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132EB8: addiu       $t8, $t8, 0x31D0
    ctx->r24 = ADD32(ctx->r24, 0X31D0);
    // 0x80132EBC: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80132EC0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80132EC4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80132EC8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132ECC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80132ED0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132ED4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132ED8: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80132EDC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80132EE0: jal         0x800CDF78
    // 0x80132EE4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132EE4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132EE8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132EEC: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x80132EF0: lbu         $v0, 0x5E2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5E2);
    // 0x80132EF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132EF8: addiu       $a0, $a0, 0x3080
    ctx->r4 = ADD32(ctx->r4, 0X3080);
    // 0x80132EFC: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x80132F00: bne         $t0, $zero, L_80132F30
    if (ctx->r8 != 0) {
        // 0x80132F04: nop
    
            goto L_80132F30;
    }
    // 0x80132F04: nop

    // 0x80132F08: lbu         $t1, 0x5E3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5E3);
    // 0x80132F0C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80132F10: slti        $at, $t1, 0x2B
    ctx->r1 = SIGNED(ctx->r9) < 0X2B ? 1 : 0;
    // 0x80132F14: bne         $at, $zero, L_80132F30
    if (ctx->r1 != 0) {
        // 0x80132F18: nop
    
            goto L_80132F30;
    }
    // 0x80132F18: nop

    // 0x80132F1C: lbu         $t2, 0x4D41($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4D41);
    // 0x80132F20: ori         $t3, $v0, 0x2
    ctx->r11 = ctx->r2 | 0X2;
    // 0x80132F24: bne         $t2, $zero, L_80132F30
    if (ctx->r10 != 0) {
        // 0x80132F28: nop
    
            goto L_80132F30;
    }
    // 0x80132F28: nop

    // 0x80132F2C: sb          $t3, 0x5E2($v1)
    MEM_B(0X5E2, ctx->r3) = ctx->r11;
L_80132F30:
    // 0x80132F30: jal         0x800CDEEC
    // 0x80132F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132F38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132F3C: jal         0x80004980
    // 0x80132F40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132F40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132F44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132F48: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132F4C: addiu       $a2, $a2, 0x3290
    ctx->r6 = ADD32(ctx->r6, 0X3290);
    // 0x80132F50: addiu       $a0, $a0, 0x3080
    ctx->r4 = ADD32(ctx->r4, 0X3080);
    // 0x80132F54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132F58: jal         0x800CDE04
    // 0x80132F5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132F5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132F60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132F64: addiu       $a1, $a1, 0x29A8
    ctx->r5 = ADD32(ctx->r5, 0X29A8);
    // 0x80132F68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132F6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132F70: jal         0x80009968
    // 0x80132F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132F78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132F7C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132F80: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132F84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80132F88: jal         0x8000B9FC
    // 0x80132F8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132F8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80132F90: jal         0x80132910
    // 0x80132F94: nop

    mn1PModeInitVars(rdram, ctx);
        goto after_6;
    // 0x80132F94: nop

    after_6:
    // 0x80132F98: jal         0x80132870
    // 0x80132F9C: nop

    mn1PModeMakeDecalsCamera(rdram, ctx);
        goto after_7;
    // 0x80132F9C: nop

    after_7:
    // 0x80132FA0: jal         0x801327D0
    // 0x80132FA4: nop

    mn1PModeMakeLabelsCamera(rdram, ctx);
        goto after_8;
    // 0x80132FA4: nop

    after_8:
    // 0x80132FA8: jal         0x80132730
    // 0x80132FAC: nop

    mn1PModeMakeOptionsCamera(rdram, ctx);
        goto after_9;
    // 0x80132FAC: nop

    after_9:
    // 0x80132FB0: jal         0x80132690
    // 0x80132FB4: nop

    mn1PModeMakeLink3Camera(rdram, ctx);
        goto after_10;
    // 0x80132FB4: nop

    after_10:
    // 0x80132FB8: jal         0x801324FC
    // 0x80132FBC: nop

    mn1PModeMakeDecals(rdram, ctx);
        goto after_11;
    // 0x80132FBC: nop

    after_11:
    // 0x80132FC0: jal         0x801323B0
    // 0x80132FC4: nop

    mn1PModeMakeLabels(rdram, ctx);
        goto after_12;
    // 0x80132FC4: nop

    after_12:
    // 0x80132FC8: jal         0x80131E34
    // 0x80132FCC: nop

    mn1PModeMake1PGame(rdram, ctx);
        goto after_13;
    // 0x80132FCC: nop

    after_13:
    // 0x80132FD0: jal         0x80131F0C
    // 0x80132FD4: nop

    mn1PModeMakeTrainingMode(rdram, ctx);
        goto after_14;
    // 0x80132FD4: nop

    after_14:
    // 0x80132FD8: jal         0x80131FE8
    // 0x80132FDC: nop

    mn1PModeMakeBonus1Practice(rdram, ctx);
        goto after_15;
    // 0x80132FDC: nop

    after_15:
    // 0x80132FE0: jal         0x801320F8
    // 0x80132FE4: nop

    mn1PModeMakeBonus2Practice(rdram, ctx);
        goto after_16;
    // 0x80132FE4: nop

    after_16:
    // 0x80132FE8: jal         0x8013223C
    // 0x80132FEC: nop

    mn1PModeMakeSubtitle(rdram, ctx);
        goto after_17;
    // 0x80132FEC: nop

    after_17:
    // 0x80132FF0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80132FF4: lbu         $t4, 0x4AD1($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AD1);
    // 0x80132FF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132FFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133000: beql        $t4, $at, L_80133014
    if (ctx->r12 == ctx->r1) {
        // 0x80133004: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80133014;
    }
    goto skip_0;
    // 0x80133004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80133008: jal         0x80020AB4
    // 0x8013300C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    syAudioPlayBGM(rdram, ctx);
        goto after_18;
    // 0x8013300C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_18:
    // 0x80133010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80133014:
    // 0x80133014: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80133018: jr          $ra
    // 0x8013301C: nop

    return;
    // 0x8013301C: nop

;}
RECOMP_FUNC void gmCameraPlayerMagnifyFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DE48: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8010DE4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010DE50: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x8010DE54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010DE58: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8010DE5C: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x8010DE60: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8010DE64: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x8010DE68: lw          $a1, 0x74($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X74);
    // 0x8010DE6C: addiu       $v0, $a1, 0x3C
    ctx->r2 = ADD32(ctx->r5, 0X3C);
    // 0x8010DE70: addiu       $v1, $a1, 0x48
    ctx->r3 = ADD32(ctx->r5, 0X48);
    // 0x8010DE74: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8010DE78: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010DE7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010DE80: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8010DE84: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8010DE88: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010DE8C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010DE90: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010DE94: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8010DE98: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8010DE9C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8010DEA0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010DEA4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8010DEA8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010DEAC: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8010DEB0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8010DEB4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8010DEB8: jal         0x80033510
    // 0x8010DEBC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8010DEBC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8010DEC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010DEC4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010DEC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010DECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010DED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010DED4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010DED8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8010DEDC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8010DEE0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8010DEE4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8010DEE8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8010DEEC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8010DEF0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8010DEF4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x8010DEF8: jal         0x8001A0F0
    // 0x8010DEFC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_1;
    // 0x8010DEFC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8010DF00: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x8010DF04: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8010DF08: addiu       $a1, $a1, 0x6FA8
    ctx->r5 = ADD32(ctx->r5, 0X6FA8);
    // 0x8010DF0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8010DF10: jal         0x80034980
    // 0x8010DF14: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x8010DF14: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x8010DF18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010DF1C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8010DF20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010DF24: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010DF28: lw          $t7, 0x1460($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1460);
    // 0x8010DF2C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x8010DF30: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x8010DF34: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x8010DF38: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x8010DF3C: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8010DF40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8010DF44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010DF48: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8010DF4C: jal         0x800EB924
    // 0x8010DF50: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_ovl2_800EB924(rdram, ctx);
        goto after_3;
    // 0x8010DF50: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x8010DF54: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8010DF58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010DF5C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8010DF60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010DF64: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8010DF68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010DF6C: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8010DF70: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010DF74: lui         $at, 0xC3E1
    ctx->r1 = S32(0XC3E1 << 16);
    // 0x8010DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DF7C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8010DF80: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010DF84: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8010DF88: nop

    // 0x8010DF8C: bc1fl       L_8010DF9C
    if (!c1cs) {
        // 0x8010DF90: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8010DF9C;
    }
    goto skip_0;
    // 0x8010DF90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8010DF94: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8010DF98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8010DF9C:
    // 0x8010DF9C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x8010DFA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8010DFA4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010DFA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010DFAC: lui         $at, 0x471C
    ctx->r1 = S32(0X471C << 16);
    // 0x8010DFB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010DFB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010DFB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010DFBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8010DFC0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010DFC4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8010DFC8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8010DFCC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8010DFD0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8010DFD4: jal         0x8001B050
    // 0x8010DFD8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixOrthoF(rdram, ctx);
        goto after_4;
    // 0x8010DFD8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8010DFDC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8010DFE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010DFE4: jal         0x80034980
    // 0x8010DFE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    guMtxCatF(rdram, ctx);
        goto after_5;
    // 0x8010DFE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8010DFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DFF0: jal         0x80019C70
    // 0x8010DFF4: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    syMatrixF2L(rdram, ctx);
        goto after_6;
    // 0x8010DFF4: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    after_6:
    // 0x8010DFF8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010DFFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8010E000: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x8010E004: jr          $ra
    // 0x8010E008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010E008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_ovl56_80132E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132E44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132E48: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80132E4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132E50: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80132E54: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80132E58: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E64: jal         0x80009968
    // 0x80132E68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132E68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132E6C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80132E70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132E78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80132E7C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80132E80: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132E84: sw          $v0, 0x5378($at)
    MEM_W(0X5378, ctx->r1) = ctx->r2;
    // 0x80132E88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132E8C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132E90: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132E94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132E98: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132E9C: jal         0x80009DF4
    // 0x80132EA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132EA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132EA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132EA8: addiu       $a1, $a1, 0x2DC0
    ctx->r5 = ADD32(ctx->r5, 0X2DC0);
    // 0x80132EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132EB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132EB4: jal         0x80008188
    // 0x80132EB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132EB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132EBC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80132EC0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132EC4: lw          $t1, 0x52CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X52CC);
    // 0x80132EC8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80132ECC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80132ED0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80132ED4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80132ED8: sw          $t2, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r10;
    // 0x80132EDC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132EE0: lw          $v1, 0x52EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52EC);
    // 0x80132EE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132EEC: beq         $v1, $at, L_80132F08
    if (ctx->r3 == ctx->r1) {
        // 0x80132EF0: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_80132F08;
    }
    // 0x80132EF0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132EF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132EF8: beq         $v1, $at, L_80132F24
    if (ctx->r3 == ctx->r1) {
        // 0x80132EFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132F24;
    }
    // 0x80132EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132F00: b           L_80132F40
    // 0x80132F04: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_80132F40;
    // 0x80132F04: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80132F08:
    // 0x80132F08: lw          $t3, 0x559C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X559C);
    // 0x80132F0C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132F10: addiu       $t4, $t4, 0x1D0
    ctx->r12 = ADD32(ctx->r12, 0X1D0);
    // 0x80132F14: jal         0x800CCFDC
    // 0x80132F18: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132F18: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80132F1C: b           L_80132F40
    // 0x80132F20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80132F40;
    // 0x80132F20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132F24:
    // 0x80132F24: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132F28: lw          $t5, 0x559C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X559C);
    // 0x80132F2C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132F30: addiu       $t6, $t6, 0xC0
    ctx->r14 = ADD32(ctx->r14, 0XC0);
    // 0x80132F34: jal         0x800CCFDC
    // 0x80132F38: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132F38: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_4:
    // 0x80132F3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132F40:
    // 0x80132F40: lhu         $t7, 0x24($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X24);
    // 0x80132F44: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x80132F48: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80132F4C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80132F50: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x80132F54: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80132F58: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80132F5C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80132F60: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80132F64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132F68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132F6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80132F70: jr          $ra
    // 0x80132F74: nop

    return;
    // 0x80132F74: nop

;}
RECOMP_FUNC void func_ovl29_80131F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F5C: jr          $ra
    // 0x80131F60: nop

    return;
    // 0x80131F60: nop

;}
RECOMP_FUNC void itMBallFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C718: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017C71C: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x8017C720: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017C724: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8017C728: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8017C72C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x8017C730: jal         0x80172558
    // 0x8017C734: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017C734: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017C738: jal         0x801713F4
    // 0x8017C73C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x8017C73C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017C740: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8017C744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C748: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8017C74C: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8017C750: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8017C754: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    // 0x8017C758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C760: jr          $ra
    // 0x8017C764: nop

    return;
    // 0x8017C764: nop

;}
RECOMP_FUNC void ftKirbySpecialNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016336C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80163370: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80163374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80163378: addiu       $a1, $zero, 0x10F
    ctx->r5 = ADD32(0, 0X10F);
    // 0x8016337C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163380: jal         0x800E6F24
    // 0x80163384: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163384: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80163388: jal         0x800E0830
    // 0x8016338C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8016338C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80163390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163394: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163398: jr          $ra
    // 0x8016339C: nop

    return;
    // 0x8016339C: nop

;}
RECOMP_FUNC void osAfterPreNMI(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033528: jal         0x80039670
    // 0x8003352C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    __osSpSetPc_recomp(rdram, ctx);
        goto after_0;
    // 0x8003352C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80033530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033538: jr          $ra
    // 0x8003353C: nop

    return;
    // 0x8003353C: nop

;}
RECOMP_FUNC void sySchedulerReadyBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001764: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80001768: addiu       $a1, $a1, 0x5034
    ctx->r5 = ADD32(ctx->r5, 0X5034);
    // 0x8000176C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80001770: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001778: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8000177C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80001780: sw          $a0, 0x5028($at)
    MEM_W(0X5028, ctx->r1) = ctx->r4;
    // 0x80001784: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001788: bne         $v1, $at, L_80001798
    if (ctx->r3 != ctx->r1) {
        // 0x8000178C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80001798;
    }
    // 0x8000178C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001790: b           L_800017A0
    // 0x80001794: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
        goto L_800017A0;
    // 0x80001794: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_80001798:
    // 0x80001798: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8000179C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
L_800017A0:
    // 0x800017A0: jal         0x800016D8
    // 0x800017A4: nop

    sySchedulerSwapBuffer(rdram, ctx);
        goto after_0;
    // 0x800017A4: nop

    after_0:
    // 0x800017A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800017AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800017B0: jr          $ra
    // 0x800017B4: nop

    return;
    // 0x800017B4: nop

;}
RECOMP_FUNC void lbCommonInitDObj3Transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C89BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C89C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C89C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C89C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C89CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C89D0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C89D4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C89D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C89DC: jal         0x8000F2FC
    // 0x800C89E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_0;
    // 0x800C89E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C89E4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800C89E8: addiu       $t6, $t6, -0x4720
    ctx->r14 = ADD32(ctx->r14, -0X4720);
    // 0x800C89EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C89F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800C89F4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800C89F8: addiu       $t9, $t9, -0x46F8
    ctx->r25 = ADD32(ctx->r25, -0X46F8);
    // 0x800C89FC: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x800C8A00: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800C8A04: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800C8A08: addiu       $t2, $t2, -0x46E8
    ctx->r10 = ADD32(ctx->r10, -0X46E8);
    // 0x800C8A0C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x800C8A10: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800C8A14: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800C8A18: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800C8A1C: sw          $t1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r9;
    // 0x800C8A20: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800C8A24: sw          $t0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r8;
    // 0x800C8A28: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800C8A2C: sw          $t1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r9;
    // 0x800C8A30: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800C8A34: sw          $t4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r12;
    // 0x800C8A38: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800C8A3C: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
    // 0x800C8A40: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800C8A44: sw          $t4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r12;
    // 0x800C8A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8A50: jr          $ra
    // 0x800C8A54: nop

    return;
    // 0x800C8A54: nop

;}
RECOMP_FUNC void itRShellCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A9D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A9D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A9D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A9DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017A9E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A9E4: lw          $t6, 0x298($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X298);
    // 0x8017A9E8: lw          $t7, 0x2A4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2A4);
    // 0x8017A9EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8017A9F0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8017A9F4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8017A9F8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8017A9FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017AA00: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017AA04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017AA08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017AA0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017AA10: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017AA14: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017AA18: nop

    // 0x8017AA1C: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017AA20: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8017AA24: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017AA28: bc1f        L_8017AA3C
    if (!c1cs) {
        // 0x8017AA2C: nop
    
            goto L_8017AA3C;
    }
    // 0x8017AA2C: nop

    // 0x8017AA30: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017AA34: b           L_8017AA40
    // 0x8017AA38: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8017AA40;
    // 0x8017AA38: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8017AA3C:
    // 0x8017AA3C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_8017AA40:
    // 0x8017AA40: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8017AA44: nop

    // 0x8017AA48: bc1fl       L_8017AAA4
    if (!c1cs) {
        // 0x8017AA4C: swc1        $f2, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
            goto L_8017AAA4;
    }
    goto skip_0;
    // 0x8017AA4C: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x8017AA50: sb          $t9, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r25;
    // 0x8017AA54: sw          $t0, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r8;
    // 0x8017AA58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017AA5C: jal         0x8016F280
    // 0x8017AA60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_0;
    // 0x8017AA60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017AA64: jal         0x801727BC
    // 0x8017AA68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainCopyDamageStats(rdram, ctx);
        goto after_1;
    // 0x8017AA68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017AA6C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017AA70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017AA74: lw          $t1, 0x108($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X108);
    // 0x8017AA78: beq         $t1, $zero, L_8017AA90
    if (ctx->r9 == 0) {
        // 0x8017AA7C: nop
    
            goto L_8017AA90;
    }
    // 0x8017AA7C: nop

    // 0x8017AA80: jal         0x8017B1A4
    // 0x8017AA84: nop

    itRShellSpinAirSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017AA84: nop

    after_2:
    // 0x8017AA88: b           L_8017AAAC
    // 0x8017AA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017AAAC;
    // 0x8017AA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017AA90:
    // 0x8017AA90: jal         0x8017B0D4
    // 0x8017AA94: nop

    itRShellSpinSetStatus(rdram, ctx);
        goto after_3;
    // 0x8017AA94: nop

    after_3:
    // 0x8017AA98: b           L_8017AAAC
    // 0x8017AA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017AAAC;
    // 0x8017AA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AAA0: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
L_8017AAA4:
    // 0x8017AAA4: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017AAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017AAAC:
    // 0x8017AAAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017AAB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017AAB4: jr          $ra
    // 0x8017AAB8: nop

    return;
    // 0x8017AAB8: nop

;}
RECOMP_FUNC void itSwordWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174BEC: jal         0x80172E74
    // 0x80174BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80174BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174BF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174BF8: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x80174BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174C00: jal         0x80172EC8
    // 0x80174C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80174C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174C10: jr          $ra
    // 0x80174C14: nop

    return;
    // 0x80174C14: nop

;}
RECOMP_FUNC void mnVSOptionsSetHandicapSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801339C8: lw          $t6, 0x48E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X48E4);
    // 0x801339CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801339D0: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x801339D4: bne         $t6, $at, L_80133A10
    if (ctx->r14 != ctx->r1) {
        // 0x801339D8: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_80133A10;
    }
    // 0x801339D8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x801339DC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801339E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801339E4: sb          $t7, 0x4D29($at)
    MEM_B(0X4D29, ctx->r1) = ctx->r15;
    // 0x801339E8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801339EC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801339F0: sb          $t8, 0x4D9D($at)
    MEM_B(0X4D9D, ctx->r1) = ctx->r24;
    // 0x801339F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801339F8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801339FC: sb          $t9, 0x4E11($at)
    MEM_B(0X4E11, ctx->r1) = ctx->r25;
    // 0x80133A00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133A04: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80133A08: jr          $ra
    // 0x80133A0C: sb          $t0, 0x4E85($at)
    MEM_B(0X4E85, ctx->r1) = ctx->r8;
    return;
    // 0x80133A0C: sb          $t0, 0x4E85($at)
    MEM_B(0X4E85, ctx->r1) = ctx->r8;
L_80133A10:
    // 0x80133A10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133A14: sb          $t1, 0x4D29($at)
    MEM_B(0X4D29, ctx->r1) = ctx->r9;
    // 0x80133A18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133A1C: sb          $t2, 0x4D9D($at)
    MEM_B(0X4D9D, ctx->r1) = ctx->r10;
    // 0x80133A20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133A24: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80133A28: sb          $t3, 0x4E11($at)
    MEM_B(0X4E11, ctx->r1) = ctx->r11;
    // 0x80133A2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133A30: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80133A34: sb          $t4, 0x4E85($at)
    MEM_B(0X4E85, ctx->r1) = ctx->r12;
    // 0x80133A38: jr          $ra
    // 0x80133A3C: nop

    return;
    // 0x80133A3C: nop

;}
RECOMP_FUNC void ftCommonHammerFallCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147E84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80147E88: jal         0x80141E60
    // 0x80147E8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonPassCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80147E8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80147E90: beql        $v0, $zero, L_80147EAC
    if (ctx->r2 == 0) {
        // 0x80147E94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80147EAC;
    }
    goto skip_0;
    // 0x80147E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80147E98: jal         0x80147E34
    // 0x80147E9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerFallSetStatusPass(rdram, ctx);
        goto after_1;
    // 0x80147E9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80147EA0: b           L_80147EAC
    // 0x80147EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147EAC;
    // 0x80147EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80147EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147EAC:
    // 0x80147EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147EB4: jr          $ra
    // 0x80147EB8: nop

    return;
    // 0x80147EB8: nop

;}
RECOMP_FUNC void mvOpeningFoxMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D1B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1BC: addiu       $t7, $t7, -0x1F18
    ctx->r15 = ADD32(ctx->r15, -0X1F18);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1DC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E0: addiu       $t1, $t1, -0x1F08
    ctx->r9 = ADD32(ctx->r9, -0X1F08);
    // 0x8018D1E4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1E8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1EC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D1F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D1F4: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x8018D1F8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D1FC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D200: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D204: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D208: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D20C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D210: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8018D214: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8018D218: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D21C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D228: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D22C: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8018D230: jal         0x80009968
    // 0x8018D234: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D234: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D238: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D23C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D240: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D244: sw          $v0, -0x1E04($at)
    MEM_W(-0X1E04, ctx->r1) = ctx->r2;
    // 0x8018D248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D24C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D250: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D258: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D25C: jal         0x80009DF4
    // 0x8018D260: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D260: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D264: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8018D268: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x8018D26C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8018D270: beq         $t5, $zero, L_8018D2EC
    if (ctx->r13 == 0) {
        // 0x8018D274: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2EC;
    }
    // 0x8018D274: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D278: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D27C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8018D280: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D284: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D288: addiu       $s2, $s2, -0x1BF0
    ctx->r18 = ADD32(ctx->r18, -0X1BF0);
    // 0x8018D28C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D290: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D294: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D298:
    // 0x8018D298: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D29C: jal         0x800CCFDC
    // 0x8018D2A0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D2A0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D2A4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D2A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D2AC: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D2B0: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2B4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2B8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2BC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D2C0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2C4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018D2C8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D2CC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8018D2D0: jal         0x8018D160
    // 0x8018D2D4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    mvOpeningFoxInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2D4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_3:
    // 0x8018D2D8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8018D2DC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8018D2E4: bnel        $v0, $zero, L_8018D298
    if (ctx->r2 != 0) {
        // 0x8018D2E8: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D298;
    }
    goto skip_0;
    // 0x8018D2E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2EC:
    // 0x8018D2EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D2F0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2F4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D2F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D2FC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D300: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D304: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D308: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D30C: jr          $ra
    // 0x8018D310: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8018D310: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800343E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800343E4: beq         $a2, $zero, L_80034404
    if (ctx->r6 == 0) {
        // 0x800343E8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80034404;
    }
    // 0x800343E8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800343EC:
    // 0x800343EC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800343F0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800343F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800343F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800343FC: bne         $a2, $zero, L_800343EC
    if (ctx->r6 != 0) {
        // 0x80034400: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800343EC;
    }
    // 0x80034400: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_80034404:
    // 0x80034404: jr          $ra
    // 0x80034408: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80034408: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void efManagerMakeEffectForce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FDB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDB24: jal         0x800FD778
    // 0x800FDB28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    efManagerMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800FDB28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800FDB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FDB34: jr          $ra
    // 0x800FDB38: nop

    return;
    // 0x800FDB38: nop

;}
RECOMP_FUNC void itBatDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017504C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80175050: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175054: addiu       $a3, $a3, 0x4EC4
    ctx->r7 = ADD32(ctx->r7, 0X4EC4);
    // 0x80175058: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8017505C: jal         0x80173B24
    // 0x80175060: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80175060: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80175064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017506C: jr          $ra
    // 0x80175070: nop

    return;
    // 0x80175070: nop

;}
RECOMP_FUNC void syVectorScale3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800190B4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800190B8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800190BC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800190C0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800190C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800190C8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800190CC: nop

    // 0x800190D0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800190D4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800190D8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800190DC: jr          $ra
    // 0x800190E0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800190E0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftCommonSleepSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D8B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D8B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013D8B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D8BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013D8C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8013D8C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013D8C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013D8CC: jal         0x800E6F24
    // 0x8013D8D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D8D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013D8D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013D8D8: lbu         $t7, 0x18D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18D);
    // 0x8013D8DC: lbu         $t0, 0x18E($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013D8E0: lbu         $t3, 0x191($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X191);
    // 0x8013D8E4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013D8E8: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    // 0x8013D8EC: ori         $t2, $t0, 0x80
    ctx->r10 = ctx->r8 | 0X80;
    // 0x8013D8F0: ori         $t6, $t3, 0x40
    ctx->r14 = ctx->r11 | 0X40;
    // 0x8013D8F4: ori         $t8, $t6, 0x10
    ctx->r24 = ctx->r14 | 0X10;
    // 0x8013D8F8: andi        $t9, $t8, 0xF0
    ctx->r25 = ctx->r24 & 0XF0;
    // 0x8013D8FC: sb          $t6, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r14;
    // 0x8013D900: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8013D904: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8013D908: sb          $t2, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r10;
    // 0x8013D90C: sb          $t8, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r24;
    // 0x8013D910: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x8013D914: sb          $t0, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r8;
    // 0x8013D918: sb          $t3, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r11;
    // 0x8013D91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D920: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013D924: jr          $ra
    // 0x8013D928: nop

    return;
    // 0x8013D928: nop

;}
RECOMP_FUNC void syDebugPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80023628: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002362C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80023630: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80023634: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023638: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002363C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023640: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80023644: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80023648: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8002364C: sb          $t6, -0x3188($at)
    MEM_B(-0X3188, ctx->r1) = ctx->r14;
    // 0x80023650: jal         0x80034870
    // 0x80023654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x80023654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80023658: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002365C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023660: jal         0x80034790
    // 0x80023664: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x80023664: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    after_1:
    // 0x80023668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002366C: jal         0x80022908
    // 0x80023670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_2;
    // 0x80023670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80023674: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80023678: jal         0x80022908
    // 0x8002367C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_3;
    // 0x8002367C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80023680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023684: jal         0x80022908
    // 0x80023688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_4;
    // 0x80023688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8002368C: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    // 0x80023690: jal         0x80022908
    // 0x80023694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_5;
    // 0x80023694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80023698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002369C: jal         0x80022908
    // 0x800236A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_6;
    // 0x800236A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800236A4: ori         $a0, $zero, 0x8200
    ctx->r4 = 0 | 0X8200;
    // 0x800236A8: jal         0x80022908
    // 0x800236AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_7;
    // 0x800236AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800236B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800236B4: jal         0x80022908
    // 0x800236B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_8;
    // 0x800236B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800236BC: addiu       $a0, $zero, 0x4100
    ctx->r4 = ADD32(0, 0X4100);
    // 0x800236C0: jal         0x80022908
    // 0x800236C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_9;
    // 0x800236C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800236C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800236CC: jal         0x80022908
    // 0x800236D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_10;
    // 0x800236D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800236D4: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    // 0x800236D8: jal         0x80022908
    // 0x800236DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_11;
    // 0x800236DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800236E0: or          $s1, $sp, $zero
    ctx->r17 = ctx->r29 | 0;
    // 0x800236E4: addiu       $s1, $s1, 0x2F
    ctx->r17 = ADD32(ctx->r17, 0X2F);
    // 0x800236E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236EC: and         $s1, $s1, $at
    ctx->r17 = ctx->r17 & ctx->r1;
L_800236F0:
    // 0x800236F0: jal         0x80039630
    // 0x800236F4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_12;
    // 0x800236F4: nop

    after_12:
    // 0x800236F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800236FC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80023700: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80023704: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80023708: jal         0x800223F4
    // 0x8002370C: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_13;
    // 0x8002370C: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_13:
    // 0x80023710: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80023714: jal         0x80023010
    // 0x80023718: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    syDebugResetMesgCursor(rdram, ctx);
        goto after_14;
    // 0x80023718: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_14:
    // 0x8002371C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80023720: jal         0x80023024
    // 0x80023724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugFramebufferVPrintfNewLine(rdram, ctx);
        goto after_15;
    // 0x80023724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x80023728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002372C: jal         0x80022908
    // 0x80023730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_16;
    // 0x80023730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80023734: bne         $v0, $zero, L_800236F0
    if (ctx->r2 != 0) {
        // 0x80023738: nop
    
            goto L_800236F0;
    }
    // 0x80023738: nop

    // 0x8002373C: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80023740: jal         0x80022908
    // 0x80023744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_17;
    // 0x80023744: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x80023748: bne         $v0, $zero, L_800236F0
    if (ctx->r2 != 0) {
        // 0x8002374C: nop
    
            goto L_800236F0;
    }
    // 0x8002374C: nop

    // 0x80023750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023754: jal         0x80034790
    // 0x80023758: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_18;
    // 0x80023758: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x8002375C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023760: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023764: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023768: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002376C: sb          $zero, -0x3188($at)
    MEM_B(-0X3188, ctx->r1) = 0;
    // 0x80023770: jr          $ra
    // 0x80023774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80023774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnMapsMakePlaqueCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013354C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133550: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133554: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133558: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013355C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80133560: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133564: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80133568: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013356C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133570: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133574: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133578: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013357C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133580: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133584: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133588: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013358C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133590: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133594: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133598: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013359C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801335A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801335A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335A8: jal         0x8000B93C
    // 0x801335AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801335AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801335B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801335B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801335B8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801335BC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801335C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801335C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335CC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801335D0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801335D4: jal         0x80007080
    // 0x801335D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801335D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801335DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801335E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801335E4: jr          $ra
    // 0x801335E8: nop

    return;
    // 0x801335E8: nop

;}
RECOMP_FUNC void func_ovl8_8037BE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BE9C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8037BEA0: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
    // 0x8037BEA4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037BEA8: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x8037BEAC: lh          $t6, 0x58($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X58);
    // 0x8037BEB0: jalr        $t9
    // 0x8037BEB4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BEB4: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x8037BEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BEC0: jr          $ra
    // 0x8037BEC4: nop

    return;
    // 0x8037BEC4: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DA30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014DA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DA38: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014DA3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014DA40: jal         0x800DE6B0
    // 0x8014DA44: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8014DA44: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014DA48: beq         $v0, $zero, L_8014DA88
    if (ctx->r2 == 0) {
        // 0x8014DA4C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014DA88;
    }
    // 0x8014DA4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014DA50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DA54: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8014DA58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014DA5C: lwc1        $f6, 0x4C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8014DA60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014DA64: nop

    // 0x8014DA68: bc1f        L_8014DA80
    if (!c1cs) {
        // 0x8014DA6C: nop
    
            goto L_8014DA80;
    }
    // 0x8014DA6C: nop

    // 0x8014DA70: jal         0x8014D49C
    // 0x8014DA74: nop

    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DA74: nop

    after_1:
    // 0x8014DA78: b           L_8014DA8C
    // 0x8014DA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014DA8C;
    // 0x8014DA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014DA80:
    // 0x8014DA80: jal         0x8014DCA4
    // 0x8014DA84: nop

    ftDonkeyThrowFLandingSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014DA84: nop

    after_2:
L_8014DA88:
    // 0x8014DA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014DA8C:
    // 0x8014DA8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014DA90: jr          $ra
    // 0x8014DA94: nop

    return;
    // 0x8014DA94: nop

;}
RECOMP_FUNC void mnVSResultsSetPlayerArrowColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135468: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8013546C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80135470: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80135474: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80135478: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8013547C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80135480: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80135484: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80135488: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x8013548C: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80135490: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80135494: jr          $ra
    // 0x80135498: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80135498: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftCommonCliffClimbSlow1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801451CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801451D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801451D4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801451D8: jal         0x800D9480
    // 0x801451DC: addiu       $a1, $a1, 0x55E0
    ctx->r5 = ADD32(ctx->r5, 0X55E0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801451DC: addiu       $a1, $a1, 0x55E0
    ctx->r5 = ADD32(ctx->r5, 0X55E0);
    after_0:
    // 0x801451E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801451E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801451E8: jr          $ra
    // 0x801451EC: nop

    return;
    // 0x801451EC: nop

;}
RECOMP_FUNC void func_ovl8_80374BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374BD8: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374BDC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80374BE0: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80374BE4: lh          $t6, 0x50($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X50);
    // 0x80374BE8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80374BEC: jalr        $t9
    // 0x80374BF0: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374BF0: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374BFC: jr          $ra
    // 0x80374C00: nop

    return;
    // 0x80374C00: nop

;}
RECOMP_FUNC void itLGunFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801755B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801755BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801755C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801755C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801755C8: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x801755CC: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801755D0: jal         0x80173F78
    // 0x801755D4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801755D4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x801755D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801755DC: addiu       $a1, $a1, -0x647C
    ctx->r5 = ADD32(ctx->r5, -0X647C);
    // 0x801755E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801755E4: jal         0x80172EC8
    // 0x801755E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801755E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801755EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801755F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801755F4: jr          $ra
    // 0x801755F8: nop

    return;
    // 0x801755F8: nop

;}
RECOMP_FUNC void ftCommonStopCeilSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801441C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801441C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801441C8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801441CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801441D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801441D4: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    // 0x801441D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801441DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801441E0: jal         0x800E6F24
    // 0x801441E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801441E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801441E8: jal         0x800E0830
    // 0x801441EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801441EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801441F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801441F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801441F8: nop

    // 0x801441FC: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80144200: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80144204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014420C: jr          $ra
    // 0x80144210: nop

    return;
    // 0x80144210: nop

;}
RECOMP_FUNC void ftCommonDamageCommonProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801407A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801407AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801407B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801407B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801407B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801407BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801407C0: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x801407C4: bnel        $t6, $at, L_80140800
    if (ctx->r14 != ctx->r1) {
        // 0x801407C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80140800;
    }
    goto skip_0;
    // 0x801407C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801407CC: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    // 0x801407D0: bnel        $t7, $zero, L_801407EC
    if (ctx->r15 != 0) {
        // 0x801407D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801407EC;
    }
    goto skip_1;
    // 0x801407D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801407D8: jal         0x800D9160
    // 0x801407DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_0;
    // 0x801407DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801407E0: b           L_8014080C
    // 0x801407E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8014080C;
    // 0x801407E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801407E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801407EC:
    // 0x801407EC: jal         0x800D91EC
    // 0x801407F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_1;
    // 0x801407F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x801407F4: b           L_8014080C
    // 0x801407F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8014080C;
    // 0x801407F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801407FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80140800:
    // 0x80140800: jal         0x800D8BB4
    // 0x80140804: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_2;
    // 0x80140804: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80140808: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8014080C:
    // 0x8014080C: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80140810: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80140814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80140818: bnel        $t8, $at, L_80140830
    if (ctx->r24 != ctx->r1) {
        // 0x8014081C: lw          $t9, 0x278($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X278);
            goto L_80140830;
    }
    goto skip_2;
    // 0x8014081C: lw          $t9, 0x278($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X278);
    skip_2:
    // 0x80140820: jal         0x80140744
    // 0x80140824: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftCommonDamageFlyRollUpdateModelPitch(rdram, ctx);
        goto after_3;
    // 0x80140824: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80140828: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014082C: lw          $t9, 0x278($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X278);
L_80140830:
    // 0x80140830: beql        $t9, $zero, L_80140868
    if (ctx->r25 == 0) {
        // 0x80140834: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80140868;
    }
    goto skip_3;
    // 0x80140834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80140838: jal         0x80018F7C
    // 0x8014083C: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    syVectorMag3D(rdram, ctx);
        goto after_4;
    // 0x8014083C: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    after_4:
    // 0x80140840: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80140844: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80140848: nop

    // 0x8014084C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80140850: nop

    // 0x80140854: bc1fl       L_80140868
    if (!c1cs) {
        // 0x80140858: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80140868;
    }
    goto skip_4;
    // 0x80140858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8014085C: jal         0x800E8518
    // 0x80140860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamClearAttackCollAll(rdram, ctx);
        goto after_5;
    // 0x80140860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80140864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80140868:
    // 0x80140868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014086C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80140870: jr          $ra
    // 0x80140874: nop

    return;
    // 0x80140874: nop

;}
RECOMP_FUNC void ftCaptainSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FB00: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FB04: jal         0x800DDE84
    // 0x8015FB08: addiu       $a1, $a1, -0x574
    ctx->r5 = ADD32(ctx->r5, -0X574);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015FB08: addiu       $a1, $a1, -0x574
    ctx->r5 = ADD32(ctx->r5, -0X574);
    after_0:
    // 0x8015FB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FB14: jr          $ra
    // 0x8015FB18: nop

    return;
    // 0x8015FB18: nop

;}
RECOMP_FUNC void mpCommonProcFighterWaitOrLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE93C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE940: jal         0x800DE6E4
    // 0x800DE944: addiu       $a1, $a1, -0x171C
    ctx->r5 = ADD32(ctx->r5, -0X171C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x800DE944: addiu       $a1, $a1, -0x171C
    ctx->r5 = ADD32(ctx->r5, -0X171C);
    after_0:
    // 0x800DE948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE94C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE950: jr          $ra
    // 0x800DE954: nop

    return;
    // 0x800DE954: nop

;}
RECOMP_FUNC void efManagerDamageSpawnOrbsProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF95C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FF960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF968: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FF96C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800FF970: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800FF974: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF978: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x800FF97C: bgez        $t7, L_800FF990
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800FF980: andi        $t8, $t7, 0x3
        ctx->r24 = ctx->r15 & 0X3;
            goto L_800FF990;
    }
    // 0x800FF980: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x800FF984: beq         $t8, $zero, L_800FF990
    if (ctx->r24 == 0) {
        // 0x800FF988: nop
    
            goto L_800FF990;
    }
    // 0x800FF988: nop

    // 0x800FF98C: addiu       $t8, $t8, -0x4
    ctx->r24 = ADD32(ctx->r24, -0X4);
L_800FF990:
    // 0x800FF990: bnel        $t8, $zero, L_800FFA88
    if (ctx->r24 != 0) {
        // 0x800FF994: lw          $t6, 0x18($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X18);
            goto L_800FFA88;
    }
    goto skip_0;
    // 0x800FF994: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x800FF998: jal         0x800FDAFC
    // 0x800FF99C: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FF99C: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    after_0:
    // 0x800FF9A0: beq         $v0, $zero, L_800FFA84
    if (ctx->r2 == 0) {
        // 0x800FF9A4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FFA84;
    }
    // 0x800FF9A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FF9A8: lw          $t9, 0x84($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X84);
    // 0x800FF9AC: lw          $v0, 0x74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74);
    // 0x800FF9B0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800FF9B4: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800FF9B8: sw          $t1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r9;
    // 0x800FF9BC: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x800FF9C0: sw          $t0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r8;
    // 0x800FF9C4: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x800FF9C8: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x800FF9CC: jal         0x80018948
    // 0x800FF9D0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x800FF9D0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x800FF9D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FF9D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FF9DC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800FF9E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF9E4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FF9E8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800FF9EC: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FF9F0: swc1        $f2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f2.u32l;
    // 0x800FF9F4: jal         0x80018948
    // 0x800FF9F8: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x800FF9F8: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    after_2:
    // 0x800FF9FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800FFA00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FFA04: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800FFA08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FFA0C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FFA10: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800FFA14: jal         0x80018948
    // 0x800FFA18: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x800FFA18: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800FFA1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFA20: lwc1        $f6, 0x998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X998);
    // 0x800FFA24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFA28: lwc1        $f10, 0x99C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X99C);
    // 0x800FFA2C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FFA30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFA34: lwc1        $f18, 0x9A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9A0);
    // 0x800FFA38: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FFA3C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800FFA40: jal         0x80035CD0
    // 0x800FFA44: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x800FFA44: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x800FFA48: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800FFA4C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800FFA50: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FFA54: swc1        $f6, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f6.u32l;
    // 0x800FFA58: jal         0x800303F0
    // 0x800FFA5C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800FFA5C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x800FFA60: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800FFA64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800FFA68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800FFA6C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FFA70: jal         0x80018994
    // 0x800FFA74: swc1        $f10, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f10.u32l;
    syUtilsRandIntRange(rdram, ctx);
        goto after_6;
    // 0x800FFA74: swc1        $f10, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f10.u32l;
    after_6:
    // 0x800FFA78: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FFA7C: addiu       $t4, $v0, 0xC
    ctx->r12 = ADD32(ctx->r2, 0XC);
    // 0x800FFA80: sw          $t4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r12;
L_800FFA84:
    // 0x800FFA84: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
L_800FFA88:
    // 0x800FFA88: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800FFA8C: bgez        $t7, L_800FFAA4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800FFA90: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800FFAA4;
    }
    // 0x800FFA90: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800FFA94: jal         0x800FD4F8
    // 0x800FFA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_7;
    // 0x800FFA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800FFA9C: jal         0x80009A84
    // 0x800FFAA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    gcEjectGObj(rdram, ctx);
        goto after_8;
    // 0x800FFAA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
L_800FFAA4:
    // 0x800FFAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFAA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FFAAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FFAB0: jr          $ra
    // 0x800FFAB4: nop

    return;
    // 0x800FFAB4: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwHitSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015252C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80152530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152534: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80152538: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015253C: jal         0x800DEEC8
    // 0x80152540: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80152540: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80152544: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80152548: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x8015254C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80152550: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152554: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152558: jal         0x800E6F24
    // 0x8015255C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015255C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80152560: jal         0x800D8EB8
    // 0x80152564: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80152564: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80152568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152570: jr          $ra
    // 0x80152574: nop

    return;
    // 0x80152574: nop

;}
RECOMP_FUNC void gcAddChildForDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800093F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800093F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800093FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009400: jal         0x80007F84
    // 0x80009404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcGetDObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80009404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80009408: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000940C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80009410: lw          $a2, 0x10($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X10);
    // 0x80009414: beql        $a2, $zero, L_8000944C
    if (ctx->r6 == 0) {
        // 0x80009418: sw          $v0, 0x10($a3)
        MEM_W(0X10, ctx->r7) = ctx->r2;
            goto L_8000944C;
    }
    goto skip_0;
    // 0x80009418: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
    skip_0:
    // 0x8000941C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80009420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80009424: beql        $v1, $zero, L_80009440
    if (ctx->r3 == 0) {
        // 0x80009428: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_80009440;
    }
    goto skip_1;
    // 0x80009428: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    skip_1:
    // 0x8000942C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80009430:
    // 0x80009430: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80009434: bnel        $v1, $zero, L_80009430
    if (ctx->r3 != 0) {
        // 0x80009438: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80009430;
    }
    goto skip_2;
    // 0x80009438: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_2:
    // 0x8000943C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_80009440:
    // 0x80009440: b           L_80009450
    // 0x80009444: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80009450;
    // 0x80009444: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x80009448: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
L_8000944C:
    // 0x8000944C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_80009450:
    // 0x80009450: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80009454: sw          $a3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r7;
    // 0x80009458: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x8000945C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80009460: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80009464: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80009468: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000946C: sw          $t7, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->r15;
    // 0x80009470: jal         0x8000926C
    // 0x80009474: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcInitDObj(rdram, ctx);
        goto after_1;
    // 0x80009474: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80009478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000947C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80009480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009484: jr          $ra
    // 0x80009488: nop

    return;
    // 0x80009488: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015212C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80152130: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152134: jal         0x8015203C
    // 0x80152138: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftPikachuSpecialLwCheckCollideThunder(rdram, ctx);
        goto after_0;
    // 0x80152138: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015213C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80152140: beq         $v0, $zero, L_80152158
    if (ctx->r2 == 0) {
        // 0x80152144: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80152158;
    }
    // 0x80152144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152148: jal         0x80152588
    // 0x8015214C: nop

    ftPikachuSpecialLwHitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015214C: nop

    after_1:
    // 0x80152150: b           L_80152190
    // 0x80152154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152190;
    // 0x80152154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152158:
    // 0x80152158: lw          $t6, 0xADC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XADC);
    // 0x8015215C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80152160: beql        $t7, $zero, L_8015217C
    if (ctx->r15 == 0) {
        // 0x80152164: lw          $t8, 0x180($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X180);
            goto L_8015217C;
    }
    goto skip_0;
    // 0x80152164: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
    skip_0:
    // 0x80152168: jal         0x80152724
    // 0x8015216C: nop

    ftPikachuSpecialLwEndSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015216C: nop

    after_2:
    // 0x80152170: b           L_80152190
    // 0x80152174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152190;
    // 0x80152174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152178: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
L_8015217C:
    // 0x8015217C: beql        $t8, $zero, L_80152190
    if (ctx->r24 == 0) {
        // 0x80152180: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80152190;
    }
    goto skip_1;
    // 0x80152180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80152184: jal         0x80152724
    // 0x80152188: nop

    ftPikachuSpecialLwEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x80152188: nop

    after_3:
    // 0x8015218C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152190:
    // 0x80152190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152194: jr          $ra
    // 0x80152198: nop

    return;
    // 0x80152198: nop

;}
RECOMP_FUNC void mnPlayers1PGamePortraitFlashThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013595C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135960: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80135964: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80135968: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013596C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80135970: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80135974: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80135978: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x8013597C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80135980: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80135984: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80135988:
    // 0x80135988: bne         $s2, $zero, L_80135998
    if (ctx->r18 != 0) {
        // 0x8013598C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80135998;
    }
    // 0x8013598C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80135990: jal         0x80135924
    // 0x80135994: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    mnPlayers1PGameDestroyPortraitFlash(rdram, ctx);
        goto after_0;
    // 0x80135994: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    after_0:
L_80135998:
    // 0x80135998: bne         $s0, $zero, L_801359BC
    if (ctx->r16 != 0) {
        // 0x8013599C: nop
    
            goto L_801359BC;
    }
    // 0x8013599C: nop

    // 0x801359A0: lw          $t6, 0x7C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X7C);
    // 0x801359A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801359A8: bnel        $s3, $t6, L_801359BC
    if (ctx->r19 != ctx->r14) {
        // 0x801359AC: sw          $s3, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->r19;
            goto L_801359BC;
    }
    goto skip_0;
    // 0x801359AC: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
    skip_0:
    // 0x801359B0: b           L_801359BC
    // 0x801359B4: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
        goto L_801359BC;
    // 0x801359B4: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x801359B8: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
L_801359BC:
    // 0x801359BC: jal         0x8000B1E8
    // 0x801359C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x801359C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801359C4: b           L_80135988
    // 0x801359C8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80135988;
    // 0x801359C8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x801359CC: nop

    // 0x801359D0: nop

    // 0x801359D4: nop

    // 0x801359D8: nop

    // 0x801359DC: nop

    // 0x801359E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801359E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801359E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801359EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801359F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801359F4: jr          $ra
    // 0x801359F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801359F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PIntroMakeBonusPicture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013357C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133584: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80133588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013358C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133590: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80133594: jal         0x80009968
    // 0x80133598: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133598: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013359C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801335A0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801335A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801335A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801335AC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801335B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801335B4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801335B8: jal         0x80009DF4
    // 0x801335BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801335BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801335C0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x801335C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801335C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801335CC: beq         $v0, $at, L_801335F4
    if (ctx->r2 == ctx->r1) {
        // 0x801335D0: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_801335F4;
    }
    // 0x801335D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801335D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801335D8: beq         $v0, $at, L_80133638
    if (ctx->r2 == ctx->r1) {
        // 0x801335DC: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_80133638;
    }
    // 0x801335DC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801335E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801335E4: beq         $v0, $at, L_8013367C
    if (ctx->r2 == ctx->r1) {
        // 0x801335E8: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_8013367C;
    }
    // 0x801335E8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801335EC: b           L_801336C0
    // 0x801335F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801336C0;
    // 0x801335F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801335F4:
    // 0x801335F4: lw          $t7, 0x6060($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6060);
    // 0x801335F8: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x801335FC: addiu       $t8, $t8, -0x1680
    ctx->r24 = ADD32(ctx->r24, -0X1680);
    // 0x80133600: jal         0x800CCFDC
    // 0x80133604: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133604: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80133608: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8013360C: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x80133610: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133614: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x80133618: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013361C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133620: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133624: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133628: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013362C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133630: b           L_801336BC
    // 0x80133634: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_801336BC;
    // 0x80133634: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80133638:
    // 0x80133638: lw          $t3, 0x6064($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6064);
    // 0x8013363C: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x80133640: addiu       $t4, $t4, 0x7388
    ctx->r12 = ADD32(ctx->r12, 0X7388);
    // 0x80133644: jal         0x800CCFDC
    // 0x80133648: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133648: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x8013364C: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80133650: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80133654: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133658: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8013365C: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80133660: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133664: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80133668: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013366C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80133670: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80133674: b           L_801336BC
    // 0x80133678: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_801336BC;
    // 0x80133678: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_8013367C:
    // 0x8013367C: lw          $t9, 0x6060($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6060);
    // 0x80133680: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x80133684: addiu       $t0, $t0, -0x59A8
    ctx->r8 = ADD32(ctx->r8, -0X59A8);
    // 0x80133688: jal         0x800CCFDC
    // 0x8013368C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013368C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80133690: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80133694: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133698: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013369C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x801336A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801336A4: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801336A8: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801336AC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801336B0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801336B4: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801336B8: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_801336BC:
    // 0x801336BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801336C0:
    // 0x801336C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801336C4: jr          $ra
    // 0x801336C8: nop

    return;
    // 0x801336C8: nop

;}
RECOMP_FUNC void func_80026A6C_2766C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026A74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026A78: jal         0x80030350
    // 0x80026A7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026A7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026A80: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80026A84: addiu       $a0, $a0, -0x1230
    ctx->r4 = ADD32(ctx->r4, -0X1230);
    // 0x80026A88: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x80026A8C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80026A90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80026A94: beq         $v1, $zero, L_80026B20
    if (ctx->r3 == 0) {
        // 0x80026A98: addiu       $a2, $zero, 0x40
        ctx->r6 = ADD32(0, 0X40);
            goto L_80026B20;
    }
    // 0x80026A98: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80026A9C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80026AA0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80026AA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80026AA8: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
    // 0x80026AAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80026AB0: sw          $v1, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r3;
    // 0x80026AB4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80026AB8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x80026ABC: sh          $t8, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r24;
    // 0x80026AC0: sw          $a3, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r7;
    // 0x80026AC4: sw          $a3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r7;
    // 0x80026AC8: sb          $t9, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r25;
    // 0x80026ACC: sb          $t0, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r8;
    // 0x80026AD0: sb          $a2, 0x34($v1)
    MEM_B(0X34, ctx->r3) = ctx->r6;
    // 0x80026AD4: sb          $zero, 0x36($v1)
    MEM_B(0X36, ctx->r3) = 0;
    // 0x80026AD8: sh          $zero, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = 0;
    // 0x80026ADC: lbu         $t1, 0x4C($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X4C);
    // 0x80026AE0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80026AE4: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x80026AE8: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x80026AEC: sb          $t2, 0x38($v1)
    MEM_B(0X38, ctx->r3) = ctx->r10;
    // 0x80026AF0: sb          $a2, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r6;
    // 0x80026AF4: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
    // 0x80026AF8: sb          $t1, 0x2B($v1)
    MEM_B(0X2B, ctx->r3) = ctx->r9;
    // 0x80026AFC: lhu         $t3, 0x48($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X48);
    // 0x80026B00: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80026B04: andi        $v0, $t4, 0xFFFF
    ctx->r2 = ctx->r12 & 0XFFFF;
    // 0x80026B08: bne         $v0, $zero, L_80026B1C
    if (ctx->r2 != 0) {
        // 0x80026B0C: sh          $t4, 0x48($a0)
        MEM_H(0X48, ctx->r4) = ctx->r12;
            goto L_80026B1C;
    }
    // 0x80026B0C: sh          $t4, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r12;
    // 0x80026B10: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80026B14: sh          $t5, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r13;
    // 0x80026B18: andi        $v0, $t5, 0xFFFF
    ctx->r2 = ctx->r13 & 0XFFFF;
L_80026B1C:
    // 0x80026B1C: sh          $v0, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r2;
L_80026B20:
    // 0x80026B20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80026B24: jal         0x80030350
    // 0x80026B28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026B28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80026B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026B30: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80026B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026B38: jr          $ra
    // 0x80026B3C: nop

    return;
    // 0x80026B3C: nop

;}
RECOMP_FUNC void lbParticleGetGenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D353C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D3540: addiu       $a0, $a0, 0x6398
    ctx->r4 = ADD32(ctx->r4, 0X6398);
    // 0x800D3544: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D3548: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D354C: addiu       $a1, $a1, 0x644A
    ctx->r5 = ADD32(ctx->r5, 0X644A);
    // 0x800D3550: bne         $v1, $zero, L_800D3560
    if (ctx->r3 != 0) {
        // 0x800D3554: lui         $a2, 0x800D
        ctx->r6 = S32(0X800D << 16);
            goto L_800D3560;
    }
    // 0x800D3554: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D3558: jr          $ra
    // 0x800D355C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D355C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3560:
    // 0x800D3560: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800D3564: addiu       $a2, $a2, 0x6450
    ctx->r6 = ADD32(ctx->r6, 0X6450);
    // 0x800D3568: lhu         $t8, 0x0($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X0);
    // 0x800D356C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D3570: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800D3574: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D3578: beq         $at, $zero, L_800D3584
    if (ctx->r1 == 0) {
        // 0x800D357C: sh          $t7, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r15;
            goto L_800D3584;
    }
    // 0x800D357C: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x800D3580: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_800D3584:
    // 0x800D3584: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3588: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800D358C: addiu       $v0, $v0, 0x639C
    ctx->r2 = ADD32(ctx->r2, 0X639C);
    // 0x800D3590: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800D3594: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D3598: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800D359C: addiu       $a1, $a1, 0x6458
    ctx->r5 = ADD32(ctx->r5, 0X6458);
    // 0x800D35A0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800D35A4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800D35A8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D35AC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800D35B0: bne         $t1, $zero, L_800D35BC
    if (ctx->r9 != 0) {
        // 0x800D35B4: addiu       $a0, $a0, 0x5D58
        ctx->r4 = ADD32(ctx->r4, 0X5D58);
            goto L_800D35BC;
    }
    // 0x800D35B4: addiu       $a0, $a0, 0x5D58
    ctx->r4 = ADD32(ctx->r4, 0X5D58);
    // 0x800D35B8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_800D35BC:
    // 0x800D35BC: lhu         $t2, 0x0($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X0);
    // 0x800D35C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D35C4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800D35C8: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x800D35CC: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x800D35D0: sw          $zero, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = 0;
    // 0x800D35D4: jr          $ra
    // 0x800D35D8: nop

    return;
    // 0x800D35D8: nop

;}
RECOMP_FUNC void mvOpeningRunWallpaperProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E28: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131E2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80131E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E34: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131E38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80131E3C: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80131E40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131E44: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131E48: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131E4C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80131E50: nop

    // 0x80131E54: bc1fl       L_80131E74
    if (!c1cs) {
        // 0x80131E58: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_80131E74;
    }
    goto skip_0;
    // 0x80131E58: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    skip_0:
    // 0x80131E5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131E60: nop

    // 0x80131E64: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80131E68: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80131E6C: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131E70: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
L_80131E74:
    // 0x80131E74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131E78: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80131E7C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80131E80: jr          $ra
    // 0x80131E84: swc1        $f6, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f6.u32l;
    return;
    // 0x80131E84: swc1        $f6, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnVSModeFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x47D0
    ctx->r24 = ADD32(ctx->r24, 0X47D0);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}

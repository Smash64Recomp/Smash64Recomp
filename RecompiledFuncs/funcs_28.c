#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopySamusSpecialNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801571A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801571AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801571B0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801571B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801571B8: lhu         $v0, 0x1BE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1BE);
    // 0x801571BC: lhu         $t6, 0x1B6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1B6);
    // 0x801571C0: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x801571C4: bne         $t7, $zero, L_801571E0
    if (ctx->r15 != 0) {
        // 0x801571C8: nop
    
            goto L_801571E0;
    }
    // 0x801571C8: nop

    // 0x801571CC: lhu         $t8, 0x1B4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B4);
    // 0x801571D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801571D4: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x801571D8: beql        $t9, $zero, L_801571F4
    if (ctx->r25 == 0) {
        // 0x801571DC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801571F4;
    }
    goto skip_0;
    // 0x801571DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_0:
L_801571E0:
    // 0x801571E0: jal         0x801575C8
    // 0x801571E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftKirbyCopySamusSpecialNEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x801571E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x801571E8: b           L_8015725C
    // 0x801571EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015725C;
    // 0x801571EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801571F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_801571F4:
    // 0x801571F4: jal         0x801492F8
    // 0x801571F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonEscapeGetStatus(rdram, ctx);
        goto after_1;
    // 0x801571F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x801571FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80157200: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80157204: beq         $v0, $at, L_80157230
    if (ctx->r2 == ctx->r1) {
        // 0x80157208: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80157230;
    }
    // 0x80157208: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8015720C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80157210: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80157214: jal         0x80156E60
    // 0x80157218: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    ftKirbyCopySamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_2;
    // 0x80157218: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015721C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80157220: jal         0x80149294
    // 0x80157224: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftCommonEscapeSetStatus(rdram, ctx);
        goto after_3;
    // 0x80157224: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80157228: b           L_8015725C
    // 0x8015722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015725C;
    // 0x8015722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157230:
    // 0x80157230: lhu         $t0, 0x1BE($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X1BE);
    // 0x80157234: lhu         $t1, 0x1B8($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X1B8);
    // 0x80157238: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8015723C: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80157240: beql        $t2, $zero, L_8015725C
    if (ctx->r10 == 0) {
        // 0x80157244: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015725C;
    }
    goto skip_1;
    // 0x80157244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80157248: jal         0x80156E60
    // 0x8015724C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftKirbyCopySamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_4;
    // 0x8015724C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80157250: jal         0x8013E1C8
    // 0x80157254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_5;
    // 0x80157254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80157258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015725C:
    // 0x8015725C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157260: jr          $ra
    // 0x80157264: nop

    return;
    // 0x80157264: nop

;}
RECOMP_FUNC void mnPlayersVSAnnounceFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801367F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801367F4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801367F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801367FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80136800: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x80136804: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80136808: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013680C: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80136810: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80136814: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80136818: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013681C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80136820: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80136824: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80136828: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013682C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80136830: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80136834: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80136838: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8013683C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80136840: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80136844: addiu       $t1, $t1, -0x4578
    ctx->r9 = ADD32(ctx->r9, -0X4578);
    // 0x80136848: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013684C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80136850: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80136854: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80136858: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013685C: jal         0x80026738
    // 0x80136860: lw          $a0, 0xA8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA8);
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80136860: lw          $a0, 0xA8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA8);
    after_0:
    // 0x80136864: jal         0x800269C0
    // 0x80136868: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80136868: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x8013686C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80136870: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80136874: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80136878: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8013687C: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80136880: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80136884: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80136888: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8013688C: lw          $t4, -0x4530($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4530);
    // 0x80136890: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80136894: addu        $a0, $sp, $t5
    ctx->r4 = ADD32(ctx->r29, ctx->r13);
    // 0x80136898: jal         0x800269C0
    // 0x8013689C: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8013689C: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    after_2:
    // 0x801368A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801368A4: beq         $v0, $zero, L_801368B4
    if (ctx->r2 == 0) {
        // 0x801368A8: sw          $v0, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r2;
            goto L_801368B4;
    }
    // 0x801368A8: sw          $v0, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r2;
    // 0x801368AC: lhu         $t7, 0x26($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X26);
    // 0x801368B0: sh          $t7, 0xAC($v1)
    MEM_H(0XAC, ctx->r3) = ctx->r15;
L_801368B4:
    // 0x801368B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801368B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801368BC: jr          $ra
    // 0x801368C0: nop

    return;
    // 0x801368C0: nop

;}
RECOMP_FUNC void scExplainTapSparkProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D808: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8018D80C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8018D810: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D81C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D820: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D824: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8018D828: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D82C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D830: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D834: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x8018D838: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x8018D83C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D840: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D844: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D848: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D84C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D850: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x8018D854: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8018D858: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018D85C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8018D860: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x8018D864: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x8018D868: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018D86C: jal         0x80013E8C
    // 0x8018D870: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjDLHead1(rdram, ctx);
        goto after_0;
    // 0x8018D870: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x8018D874: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8018D878: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8018D87C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D880: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D884: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x8018D888: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018D88C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018D890: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D894: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018D898: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D89C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8018D8A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D8A4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018D8A8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018D8AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018D8B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018D8B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D8B8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8018D8BC: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8018D8C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D8C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D8C8: ori         $t0, $t0, 0x49D8
    ctx->r8 = ctx->r8 | 0X49D8;
    // 0x8018D8CC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8018D8D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D8D4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018D8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D8E0: jr          $ra
    // 0x8018D8E4: nop

    return;
    // 0x8018D8E4: nop

;}
RECOMP_FUNC void wpYoshiStarProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C71C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C720: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016C724: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C728: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016C72C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C730: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8016C734: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8016C738: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8016C73C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016C740: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016C744: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016C748: jal         0x80019438
    // 0x8016C74C: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8016C74C: nop

    after_0:
    // 0x8016C750: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C754: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8016C758: jal         0x8001863C
    // 0x8016C75C: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8016C75C: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x8016C760: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016C764: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C768: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8016C76C: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8016C770: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8016C774: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8016C778: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8016C77C: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8016C780: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8016C784: nop

    // 0x8016C788: bc1fl       L_8016C79C
    if (!c1cs) {
        // 0x8016C78C: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_8016C79C;
    }
    goto skip_0;
    // 0x8016C78C: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x8016C790: b           L_8016C79C
    // 0x8016C794: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_8016C79C;
    // 0x8016C794: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x8016C798: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_8016C79C:
    // 0x8016C79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C7A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C7A8: jr          $ra
    // 0x8016C7AC: nop

    return;
    // 0x8016C7AC: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801602B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801602B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801602B8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801602BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801602C0: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x801602C4: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x801602C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801602CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801602D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801602D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801602D8: bc1f        L_801602F4
    if (!c1cs) {
        // 0x801602DC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801602F4;
    }
    // 0x801602DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801602E0: lwc1        $f8, -0x3700($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3700);
    // 0x801602E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801602E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801602EC: jal         0x801438F0
    // 0x801602F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x801602F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
L_801602F4:
    // 0x801602F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801602F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801602FC: jr          $ra
    // 0x80160300: nop

    return;
    // 0x80160300: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNCopySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163560: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163568: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016356C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80163570: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163574: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163578: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    // 0x8016357C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163580: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163584: jal         0x800E6F24
    // 0x80163588: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163588: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016358C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80163590: jal         0x800E8098
    // 0x80163594: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x80163594: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x80163598: jal         0x800E0830
    // 0x8016359C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8016359C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801635A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801635A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801635A8: jr          $ra
    // 0x801635AC: nop

    return;
    // 0x801635AC: nop

;}
RECOMP_FUNC void sc1PChallengerMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132040: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132044: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132048: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013204C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132050: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80132054: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132058: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013205C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132060: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132064: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132068: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013206C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132070: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132074: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132078: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013207C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132084: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132088: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013208C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013209C: jal         0x8000B93C
    // 0x801320A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801320A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801320A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801320A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320AC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801320B0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801320B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801320BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801320C0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801320C4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801320C8: jal         0x80007080
    // 0x801320CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801320CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801320D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801320D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801320D8: jr          $ra
    // 0x801320DC: nop

    return;
    // 0x801320DC: nop

;}
RECOMP_FUNC void _n_freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A2D8: jal         0x80028C84
    // 0x8002A2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8002A2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002A2E0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002A2E4: lw          $v0, -0x2CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2CEC);
    // 0x8002A2E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002A2EC: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8002A2F0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8002A2F4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8002A2F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002A2FC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002A300: beql        $v1, $zero, L_8002A310
    if (ctx->r3 == 0) {
        // 0x8002A304: sw          $a0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r4;
            goto L_8002A310;
    }
    goto skip_0;
    // 0x8002A304: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    skip_0:
    // 0x8002A308: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8002A30C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8002A310:
    // 0x8002A310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A318: jr          $ra
    // 0x8002A31C: nop

    return;
    // 0x8002A31C: nop

;}
RECOMP_FUNC void wpProcessUpdateHitPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165F60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80165F64: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80165F68: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80165F6C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80165F70: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80165F74: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80165F78: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80165F7C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80165F80: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80165F84: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80165F88: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80165F8C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80165F90: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80165F94: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x80165F98: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x80165F9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80165FA0: lw          $v1, 0x150($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X150);
    // 0x80165FA4: addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // 0x80165FA8: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x80165FAC: blez        $v1, L_801661A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80165FB0: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_801661A8;
    }
    // 0x80165FB0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80165FB4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80165FB8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80165FBC: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80165FC0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80165FC4: lw          $v0, 0x100($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X100);
L_80165FC8:
    // 0x80165FC8: beql        $v0, $zero, L_8016619C
    if (ctx->r2 == 0) {
        // 0x80165FCC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8016619C;
    }
    goto skip_0;
    // 0x80165FCC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80165FD0: beq         $v0, $fp, L_80165FF0
    if (ctx->r2 == ctx->r30) {
        // 0x80165FD4: nop
    
            goto L_80165FF0;
    }
    // 0x80165FD4: nop

    // 0x80165FD8: beq         $v0, $s4, L_801660BC
    if (ctx->r2 == ctx->r20) {
        // 0x80165FDC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801660BC;
    }
    // 0x80165FDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80165FE0: beq         $v0, $s5, L_801660C0
    if (ctx->r2 == ctx->r21) {
        // 0x80165FE4: nop
    
            goto L_801660C0;
    }
    // 0x80165FE4: nop

    // 0x80165FE8: b           L_8016619C
    // 0x80165FEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8016619C;
    // 0x80165FEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80165FF0:
    // 0x80165FF0: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80165FF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80165FF8: mflo        $t6
    ctx->r14 = lo;
    // 0x80165FFC: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x80166000: addiu       $s0, $s0, 0x154
    ctx->r16 = ADD32(ctx->r16, 0X154);
    // 0x80166004: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80166008: mflo        $t7
    ctx->r15 = lo;
    // 0x8016600C: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x80166010: lw          $t9, 0x110($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X110);
    // 0x80166014: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
    // 0x80166018: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8016601C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80166020: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80166024: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80166028: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x8016602C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80166030: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80166034: nop

    // 0x80166038: bc1f        L_801660A0
    if (!c1cs) {
        // 0x8016603C: nop
    
            goto L_801660A0;
    }
    // 0x8016603C: nop

    // 0x80166040: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80166044: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x80166048: nop

    // 0x8016604C: bc1f        L_801660A0
    if (!c1cs) {
        // 0x80166050: nop
    
            goto L_801660A0;
    }
    // 0x80166050: nop

    // 0x80166054: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80166058: addiu       $v0, $s3, 0x1C
    ctx->r2 = ADD32(ctx->r19, 0X1C);
    // 0x8016605C: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80166060: nop

    // 0x80166064: bc1f        L_801660A0
    if (!c1cs) {
        // 0x80166068: nop
    
            goto L_801660A0;
    }
    // 0x80166068: nop

    // 0x8016606C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80166070: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80166074: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80166078: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016607C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80166080: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80166084: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80166088: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016608C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80166090: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80166094: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80166098: b           L_801660A8
    // 0x8016609C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_801660A8;
    // 0x8016609C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_801660A0:
    // 0x801660A0: jal         0x80165ED0
    // 0x801660A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    wpProcessUpdateHitOffsets(rdram, ctx);
        goto after_0;
    // 0x801660A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_801660A8:
    // 0x801660A8: sw          $s4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->r20;
    // 0x801660AC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x801660B0: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x801660B4: b           L_80166198
    // 0x801660B8: lw          $v1, 0x150($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X150);
        goto L_80166198;
    // 0x801660B8: lw          $v1, 0x150($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X150);
L_801660BC:
    // 0x801660BC: sw          $s5, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->r21;
L_801660C0:
    // 0x801660C0: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801660C4: mflo        $t0
    ctx->r8 = lo;
    // 0x801660C8: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x801660CC: lw          $t2, 0x154($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X154);
    // 0x801660D0: multu       $s2, $s7
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801660D4: lw          $t1, 0x158($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X158);
    // 0x801660D8: sw          $t2, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r10;
    // 0x801660DC: lw          $t2, 0x15C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X15C);
    // 0x801660E0: sw          $t1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r9;
    // 0x801660E4: addiu       $s0, $s0, 0x154
    ctx->r16 = ADD32(ctx->r16, 0X154);
    // 0x801660E8: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
    // 0x801660EC: mflo        $t3
    ctx->r11 = lo;
    // 0x801660F0: addu        $v0, $s1, $t3
    ctx->r2 = ADD32(ctx->r17, ctx->r11);
    // 0x801660F4: lw          $t5, 0x110($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X110);
    // 0x801660F8: addiu       $v0, $v0, 0x110
    ctx->r2 = ADD32(ctx->r2, 0X110);
    // 0x801660FC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80166100: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80166104: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80166108: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8016610C: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x80166110: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80166114: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80166118: nop

    // 0x8016611C: bc1f        L_80166184
    if (!c1cs) {
        // 0x80166120: nop
    
            goto L_80166184;
    }
    // 0x80166120: nop

    // 0x80166124: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80166128: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x8016612C: nop

    // 0x80166130: bc1f        L_80166184
    if (!c1cs) {
        // 0x80166134: nop
    
            goto L_80166184;
    }
    // 0x80166134: nop

    // 0x80166138: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8016613C: addiu       $v0, $s3, 0x1C
    ctx->r2 = ADD32(ctx->r19, 0X1C);
    // 0x80166140: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80166144: nop

    // 0x80166148: bc1f        L_80166184
    if (!c1cs) {
        // 0x8016614C: nop
    
            goto L_80166184;
    }
    // 0x8016614C: nop

    // 0x80166150: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80166154: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80166158: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8016615C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80166160: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80166164: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80166168: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8016616C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80166170: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80166174: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80166178: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016617C: b           L_8016618C
    // 0x80166180: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_8016618C;
    // 0x80166180: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80166184:
    // 0x80166184: jal         0x80165ED0
    // 0x80166188: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    wpProcessUpdateHitOffsets(rdram, ctx);
        goto after_1;
    // 0x80166188: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_8016618C:
    // 0x8016618C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80166190: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x80166194: lw          $v1, 0x150($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X150);
L_80166198:
    // 0x80166198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8016619C:
    // 0x8016619C: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801661A0: bnel        $at, $zero, L_80165FC8
    if (ctx->r1 != 0) {
        // 0x801661A4: lw          $v0, 0x100($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X100);
            goto L_80165FC8;
    }
    goto skip_1;
    // 0x801661A4: lw          $v0, 0x100($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X100);
    skip_1:
L_801661A8:
    // 0x801661A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801661AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801661B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801661B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801661B8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801661BC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801661C0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801661C4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801661C8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801661CC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801661D0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801661D4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801661D8: jr          $ra
    // 0x801661DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801661DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCaptainSpecialLwProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160004: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160008: lhu         $v1, 0xB18($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB18);
    // 0x8016000C: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80160010: beq         $at, $zero, L_80160030
    if (ctx->r1 == 0) {
        // 0x80160014: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80160030;
    }
    // 0x80160014: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80160018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016001C: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80160020: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80160024: sh          $t6, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r14;
    // 0x80160028: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016002C: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
L_80160030:
    // 0x80160030: jr          $ra
    // 0x80160034: nop

    return;
    // 0x80160034: nop

;}
RECOMP_FUNC void func_ovl3_8016C9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C9A0: jr          $ra
    // 0x8016C9A4: nop

    return;
    // 0x8016C9A4: nop

;}
RECOMP_FUNC void ftLinkSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164038: jal         0x80163D44
    // 0x8016403C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftLinkSpecialHiUpdateWeaponVars(rdram, ctx);
        goto after_0;
    // 0x8016403C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80164044: jal         0x80163D94
    // 0x80164048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftLinkSpecialHiMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80164048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8016404C: jal         0x800D8BB4
    // 0x80164050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_2;
    // 0x80164050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80164054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016405C: jr          $ra
    // 0x80164060: nop

    return;
    // 0x80164060: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155B04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155B0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80155B10: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x80155B14: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155B18: jal         0x800E6F24
    // 0x80155B1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155B1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155B20: jal         0x800E0830
    // 0x80155B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155B2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155B30: jr          $ra
    // 0x80155B34: nop

    return;
    // 0x80155B34: nop

;}
RECOMP_FUNC void wpMapTestLRWallCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016796C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167974: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167978: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016797C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80167980: addiu       $a1, $a1, 0x7880
    ctx->r5 = ADD32(ctx->r5, 0X7880);
    // 0x80167984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80167988: jal         0x800DA034
    // 0x8016798C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x8016798C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80167990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167998: jr          $ra
    // 0x8016799C: nop

    return;
    // 0x8016799C: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateCPDisplaySprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E810: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E814: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018E818: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x8018E81C: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x8018E820: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x8018E824: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018E828: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018E82C: lw          $t1, 0x7C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X7C);
    // 0x8018E830: lw          $t4, 0x74($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X74);
    // 0x8018E834: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
L_8018E838:
    // 0x8018E838: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018E83C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018E840: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018E844: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018E848: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018E84C: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018E850: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018E854: bne         $t1, $t5, L_8018E838
    if (ctx->r9 != ctx->r13) {
        // 0x8018E858: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018E838;
    }
    // 0x8018E858: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018E85C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018E860: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018E864: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018E868: jr          $ra
    // 0x8018E86C: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    return;
    // 0x8018E86C: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
;}
RECOMP_FUNC void lbParticleEjectGeneratorAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D397C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3980: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800D3984: lw          $s0, 0x639C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X639C);
    // 0x800D3988: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D398C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3990: beql        $s0, $zero, L_800D39B0
    if (ctx->r16 == 0) {
        // 0x800D3994: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D39B0;
    }
    goto skip_0;
    // 0x800D3994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800D3998:
    // 0x800D3998: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800D399C: jal         0x800D3884
    // 0x800D39A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectGenerator(rdram, ctx);
        goto after_0;
    // 0x800D39A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D39A4: bne         $s1, $zero, L_800D3998
    if (ctx->r17 != 0) {
        // 0x800D39A8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D3998;
    }
    // 0x800D39A8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D39AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D39B0:
    // 0x800D39B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D39B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D39B8: jr          $ra
    // 0x800D39BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D39BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80380FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380FC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80380FC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80380FCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80380FD4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80380FD8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80380FDC: bne         $a0, $zero, L_80380FF4
    if (ctx->r4 != 0) {
        // 0x80380FE0: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80380FF4;
    }
    // 0x80380FE0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80380FE4: jal         0x803717A0
    // 0x80380FE8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80380FE8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80380FEC: beq         $v0, $zero, L_8038107C
    if (ctx->r2 == 0) {
        // 0x80380FF0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8038107C;
    }
    // 0x80380FF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80380FF4:
    // 0x80380FF4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80380FF8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80380FFC: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x80381000: bnel        $t6, $zero, L_80381024
    if (ctx->r14 != 0) {
        // 0x80381004: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80381024;
    }
    goto skip_0;
    // 0x80381004: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80381008: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8038100C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80381010: jal         0x803717E0
    // 0x80381014: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80381014: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80381018: jal         0x8037C2D0
    // 0x8038101C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8038101C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80381020: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80381024:
    // 0x80381024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80381028: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8038102C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80381030: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80381034: jal         0x8037F3A8
    // 0x80381038: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037F3A8(rdram, ctx);
        goto after_3;
    // 0x80381038: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8038103C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80381040: addiu       $t8, $t8, -0x4630
    ctx->r24 = ADD32(ctx->r24, -0X4630);
    // 0x80381044: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80381048: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8038104C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80381050: addiu       $t9, $t9, -0x4550
    ctx->r25 = ADD32(ctx->r25, -0X4550);
    // 0x80381054: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80381058: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8038105C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80381060: addiu       $t1, $t1, -0x43F8
    ctx->r9 = ADD32(ctx->r9, -0X43F8);
    // 0x80381064: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80381068: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8038106C: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80381070: lh          $t3, 0x10($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X10);
    // 0x80381074: jalr        $t9
    // 0x80381078: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80381078: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    after_4:
L_8038107C:
    // 0x8038107C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80381080: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80381084: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80381088: jr          $ra
    // 0x8038108C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8038108C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80020E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020E14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80020E18: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80020E1C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80020E20: jr          $ra
    // 0x80020E24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80020E24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void unref_80014FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014FFC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80015000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015008: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001500C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80015010: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80015014: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80015018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001501C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015020: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x80015024: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015028: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x8001502C: lbu         $t6, 0x54($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X54);
    // 0x80015030: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015034: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80015038: bnel        $t7, $zero, L_8001533C
    if (ctx->r15 != 0) {
        // 0x8001503C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001533C;
    }
    goto skip_0;
    // 0x8001503C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80015040: lw          $s0, 0x50($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X50);
    // 0x80015044: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015048: addiu       $s1, $s1, 0x72A8
    ctx->r17 = ADD32(ctx->r17, 0X72A8);
    // 0x8001504C: beq         $s0, $zero, L_80015338
    if (ctx->r16 == 0) {
        // 0x80015050: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80015338;
    }
    // 0x80015050: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015054: jal         0x80014798
    // 0x80015058: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80015058: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_0:
    // 0x8001505C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80015060: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80015064: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x80015068: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8001506C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80015070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015074: bc1fl       L_800150A4
    if (!c1cs) {
        // 0x80015078: lw          $a2, 0x4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X4);
            goto L_800150A4;
    }
    goto skip_1;
    // 0x80015078: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8001507C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_80015080:
    // 0x80015080: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80015084: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80015088: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8001508C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80015090: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80015094: nop

    // 0x80015098: bc1tl       L_80015080
    if (c1cs) {
        // 0x8001509C: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_80015080;
    }
    goto skip_2;
    // 0x8001509C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x800150A0: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
L_800150A4:
    // 0x800150A4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800150A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800150AC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800150B0: jal         0x80010D70
    // 0x800150B4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_1;
    // 0x800150B4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    after_1:
    // 0x800150B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800150BC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800150C0: beql        $a2, $zero, L_80015220
    if (ctx->r6 == 0) {
        // 0x800150C4: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80015220;
    }
    goto skip_3;
    // 0x800150C4: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_3:
    // 0x800150C8: lbu         $t6, 0x54($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X54);
    // 0x800150CC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800150D0: bnel        $t7, $zero, L_80015220
    if (ctx->r15 != 0) {
        // 0x800150D4: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80015220;
    }
    goto skip_4;
    // 0x800150D4: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_4:
    // 0x800150D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800150DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800150E0: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800150E4: beq         $v0, $at, L_8001521C
    if (ctx->r2 == ctx->r1) {
        // 0x800150E8: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_8001521C;
    }
    // 0x800150E8: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800150EC: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800150F0: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800150F4: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
L_800150F8:
    // 0x800150F8: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x800150FC: addu        $t9, $a3, $s0
    ctx->r25 = ADD32(ctx->r7, ctx->r16);
    // 0x80015100: beql        $t8, $zero, L_8001520C
    if (ctx->r24 == 0) {
        // 0x80015104: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_8001520C;
    }
    goto skip_5;
    // 0x80015104: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_5:
    // 0x80015108: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001510C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80015110: beq         $t5, $a0, L_80015178
    if (ctx->r13 == ctx->r4) {
        // 0x80015114: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_80015178;
    }
    // 0x80015114: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
L_80015118:
    // 0x80015118: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001511C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80015120: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80015124: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80015128: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8001512C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80015130: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80015134: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x80015138: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001513C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80015140: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80015144: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80015148: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8001514C: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x80015150: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80015154: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80015158: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8001515C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80015160: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80015164: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80015168: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x8001516C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80015170: bnel        $t9, $a0, L_80015118
    if (ctx->r25 != ctx->r4) {
        // 0x80015174: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_80015118;
    }
    goto skip_6;
    // 0x80015174: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
    skip_6:
L_80015178:
    // 0x80015178: lw          $t5, 0x80($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X80);
    // 0x8001517C: beql        $t5, $zero, L_800151EC
    if (ctx->r13 == 0) {
        // 0x80015180: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800151EC;
    }
    goto skip_7;
    // 0x80015180: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_7:
    // 0x80015184: bne         $s4, $zero, L_800151C4
    if (ctx->r20 != 0) {
        // 0x80015188: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800151C4;
    }
    // 0x80015188: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x8001518C: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80015190: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80015194: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015198: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x8001519C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800151A0: jal         0x80012D90
    // 0x800151A4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x800151A4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_2:
    // 0x800151A8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800151AC: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800151B0: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800151B4: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800151B8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800151BC: b           L_800151E8
    // 0x800151C0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_800151E8;
    // 0x800151C0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800151C4:
    // 0x800151C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800151C8: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800151CC: ori         $t7, $t7, 0x38
    ctx->r15 = ctx->r15 | 0X38;
    // 0x800151D0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800151D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800151D8: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x800151DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800151E0: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800151E4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800151E8:
    // 0x800151E8: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_800151EC:
    // 0x800151EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800151F0: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800151F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800151F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800151FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80015200: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x80015204: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80015208: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_8001520C:
    // 0x8001520C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80015210: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80015214: bnel        $v0, $at, L_800150F8
    if (ctx->r2 != ctx->r1) {
        // 0x80015218: lw          $t8, 0x4($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X4);
            goto L_800150F8;
    }
    goto skip_8;
    // 0x80015218: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    skip_8:
L_8001521C:
    // 0x8001521C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_80015220:
    // 0x80015220: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015224: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80015228: beql        $a0, $zero, L_80015240
    if (ctx->r4 == 0) {
        // 0x8001522C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80015240;
    }
    goto skip_9;
    // 0x8001522C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_9:
    // 0x80015230: jal         0x80014CD0
    // 0x80015234: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    func_80014CD0(rdram, ctx);
        goto after_3;
    // 0x80015234: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_3:
    // 0x80015238: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8001523C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80015240:
    // 0x80015240: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80015244: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80015248: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x8001524C: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x80015250: addiu       $t4, $t4, 0x70C8
    ctx->r12 = ADD32(ctx->r12, 0X70C8);
    // 0x80015254: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x80015258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001525C: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80015260: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80015264: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_80015268:
    // 0x80015268: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8001526C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80015270: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x80015274: beql        $at, $zero, L_800152BC
    if (ctx->r1 == 0) {
        // 0x80015278: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_800152BC;
    }
    goto skip_10;
    // 0x80015278: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_10:
    // 0x8001527C: beq         $t3, $zero, L_800152B8
    if (ctx->r11 == 0) {
        // 0x80015280: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_800152B8;
    }
    // 0x80015280: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80015284: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80015288: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x8001528C: beql        $t0, $t8, L_800152A4
    if (ctx->r8 == ctx->r24) {
        // 0x80015290: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_800152A4;
    }
    goto skip_11;
    // 0x80015290: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_11:
    // 0x80015294: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80015298: beql        $t9, $zero, L_800152BC
    if (ctx->r25 == 0) {
        // 0x8001529C: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_800152BC;
    }
    goto skip_12;
    // 0x8001529C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_12:
    // 0x800152A0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_800152A4:
    // 0x800152A4: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x800152A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800152AC: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800152B0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800152B4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_800152B8:
    // 0x800152B8: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
L_800152BC:
    // 0x800152BC: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800152C0: beql        $at, $zero, L_80015304
    if (ctx->r1 == 0) {
        // 0x800152C4: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015304;
    }
    goto skip_13;
    // 0x800152C4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_13:
    // 0x800152C8: beq         $t3, $zero, L_80015300
    if (ctx->r11 == 0) {
        // 0x800152CC: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_80015300;
    }
    // 0x800152CC: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x800152D0: lw          $t7, 0x14($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X14);
    // 0x800152D4: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x800152D8: beql        $t0, $t7, L_800152F0
    if (ctx->r8 == ctx->r15) {
        // 0x800152DC: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_800152F0;
    }
    goto skip_14;
    // 0x800152DC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_14:
    // 0x800152E0: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x800152E4: beql        $t8, $zero, L_80015304
    if (ctx->r24 == 0) {
        // 0x800152E8: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015304;
    }
    goto skip_15;
    // 0x800152E8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_15:
    // 0x800152EC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_800152F0:
    // 0x800152F0: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800152F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800152F8: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800152FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80015300:
    // 0x80015300: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80015304:
    // 0x80015304: bne         $a2, $t4, L_80015268
    if (ctx->r6 != ctx->r12) {
        // 0x80015308: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80015268;
    }
    // 0x80015308: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8001530C: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x80015310: bnel        $t5, $zero, L_8001533C
    if (ctx->r13 != 0) {
        // 0x80015314: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001533C;
    }
    goto skip_16;
    // 0x80015314: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x80015318: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x8001531C: beql        $s0, $zero, L_8001533C
    if (ctx->r16 == 0) {
        // 0x80015320: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001533C;
    }
    goto skip_17;
    // 0x80015320: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
L_80015324:
    // 0x80015324: jal         0x80014CD0
    // 0x80015328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80014CD0(rdram, ctx);
        goto after_4;
    // 0x80015328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001532C: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80015330: bne         $s0, $zero, L_80015324
    if (ctx->r16 != 0) {
        // 0x80015334: nop
    
            goto L_80015324;
    }
    // 0x80015334: nop

L_80015338:
    // 0x80015338: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001533C:
    // 0x8001533C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015340: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80015344: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80015348: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001534C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80015350: jr          $ra
    // 0x80015354: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80015354: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itRShellCommonSetStatusWaitOrSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A83C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017A844: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8017A848: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8017A84C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017A850: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8017A854: jal         0x80173F54
    // 0x8017A858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMapSetGround(rdram, ctx);
        goto after_0;
    // 0x8017A858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8017A85C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8017A860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017A864: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017A868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017A86C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8017A870: nop

    // 0x8017A874: bc1fl       L_8017A888
    if (!c1cs) {
        // 0x8017A878: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8017A888;
    }
    goto skip_0;
    // 0x8017A878: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8017A87C: b           L_8017A888
    // 0x8017A880: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8017A888;
    // 0x8017A880: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8017A884: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8017A888:
    // 0x8017A888: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8017A88C: nop

    // 0x8017A890: bc1fl       L_8017A8E8
    if (!c1cs) {
        // 0x8017A894: lbu         $t7, 0x353($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X353);
            goto L_8017A8E8;
    }
    goto skip_1;
    // 0x8017A894: lbu         $t7, 0x353($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X353);
    skip_1:
    // 0x8017A898: jal         0x80172E74
    // 0x8017A89C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_1;
    // 0x8017A89C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8017A8A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017A8A4: sb          $zero, 0x353($s0)
    MEM_B(0X353, ctx->r16) = 0;
    // 0x8017A8A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017A8AC: jal         0x8017279C
    // 0x8017A8B0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    itMainClearOwnerStats(rdram, ctx);
        goto after_2;
    // 0x8017A8B0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x8017A8B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017A8B8: sw          $t6, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r14;
    // 0x8017A8BC: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8017A8C0: jal         0x8017A734
    // 0x8017A8C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itRShellCommonClearAnim(rdram, ctx);
        goto after_3;
    // 0x8017A8C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8017A8C8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A8CC: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017A8D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017A8D4: jal         0x80172EC8
    // 0x8017A8D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x8017A8D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8017A8DC: b           L_8017A954
    // 0x8017A8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8017A954;
    // 0x8017A8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A8E4: lbu         $t7, 0x353($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X353);
L_8017A8E8:
    // 0x8017A8E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017A8EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017A8F0: beq         $t7, $zero, L_8017A910
    if (ctx->r15 == 0) {
        // 0x8017A8F4: nop
    
            goto L_8017A910;
    }
    // 0x8017A8F4: nop

    // 0x8017A8F8: jal         0x8016F280
    // 0x8017A8FC: sw          $t8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r24;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_5;
    // 0x8017A8FC: sw          $t8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r24;
    after_5:
    // 0x8017A900: jal         0x8017B0D4
    // 0x8017A904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itRShellSpinSetStatus(rdram, ctx);
        goto after_6;
    // 0x8017A904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8017A908: b           L_8017A954
    // 0x8017A90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8017A954;
    // 0x8017A90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017A910:
    // 0x8017A910: jal         0x80172E74
    // 0x8017A914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_7;
    // 0x8017A914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8017A918: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017A91C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017A920: jal         0x8017279C
    // 0x8017A924: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    itMainClearOwnerStats(rdram, ctx);
        goto after_8;
    // 0x8017A924: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x8017A928: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017A92C: sw          $t9, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r25;
    // 0x8017A930: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8017A934: jal         0x8017A734
    // 0x8017A938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itRShellCommonClearAnim(rdram, ctx);
        goto after_9;
    // 0x8017A938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8017A93C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A940: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017A944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017A948: jal         0x80172EC8
    // 0x8017A94C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_10;
    // 0x8017A94C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8017A950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017A954:
    // 0x8017A954: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8017A958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8017A95C: jr          $ra
    // 0x8017A960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8017A960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ifCommonBattlePauseEjectGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113F58: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80113F5C: jal         0x800CB608
    // 0x80113F60: lw          $a0, 0x6728($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6728);
    lbCommonEjectGObjLinkedList(rdram, ctx);
        goto after_0;
    // 0x80113F60: lw          $a0, 0x6728($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6728);
    after_0:
    // 0x80113F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113F68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113F6C: jr          $ra
    // 0x80113F70: nop

    return;
    // 0x80113F70: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015786C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157874: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157878: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015787C: jal         0x800DEE98
    // 0x80157880: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80157880: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157884: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157888: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015788C: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x80157890: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157894: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157898: jal         0x800E6F24
    // 0x8015789C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015789C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801578A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801578A4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801578A8: addiu       $t8, $t8, 0x77A0
    ctx->r24 = ADD32(ctx->r24, 0X77A0);
    // 0x801578AC: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x801578B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801578B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801578B8: jr          $ra
    // 0x801578BC: nop

    return;
    // 0x801578BC: nop

;}
RECOMP_FUNC void ftCommonThrownCommonStarProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BE54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014BE58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014BE5C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014BE60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014BE64: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8014BE68: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014BE6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014BE70: jal         0x800E6F24
    // 0x8014BE74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014BE74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014BE78: jal         0x800D8EB8
    // 0x8014BE7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_1;
    // 0x8014BE7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8014BE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BE84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014BE88: jr          $ra
    // 0x8014BE8C: nop

    return;
    // 0x8014BE8C: nop

;}
RECOMP_FUNC void ftFox_SpecialAirLwTurn_SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D098: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015D09C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015D0A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015D0A4: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x8015D0A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D0AC: jal         0x800E6F24
    // 0x8015D0B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D0B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D0B4: jal         0x8015D01C
    // 0x8015D0B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwTurnInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8015D0B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015D0BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D0C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D0C4: jr          $ra
    // 0x8015D0C8: nop

    return;
    // 0x8015D0C8: nop

;}
RECOMP_FUNC void itSawamuraWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018271C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80182720: jal         0x801735A0
    // 0x80182724: addiu       $a1, $a1, 0x26A8
    ctx->r5 = ADD32(ctx->r5, 0X26A8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80182724: addiu       $a1, $a1, 0x26A8
    ctx->r5 = ADD32(ctx->r5, 0X26A8);
    after_0:
    // 0x80182728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018272C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182734: jr          $ra
    // 0x80182738: nop

    return;
    // 0x80182738: nop

;}
RECOMP_FUNC void ftCommonLandingAirNullSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142E10: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80142E14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142E18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142E1C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80142E20: addiu       $a1, $zero, 0xDB
    ctx->r5 = ADD32(0, 0XDB);
    // 0x80142E24: jal         0x80142D44
    // 0x80142E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftCommonLandingSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80142E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80142E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142E34: jr          $ra
    // 0x80142E38: nop

    return;
    // 0x80142E38: nop

;}
RECOMP_FUNC void itGShellSpinProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178B98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178BA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178BA4: jal         0x801785E0
    // 0x80178BA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itGShellSpinUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80178BA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80178BAC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178BB0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80178BB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80178BB8: lbu         $v1, 0x350($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X350);
    // 0x80178BBC: bne         $v1, $zero, L_80178BD8
    if (ctx->r3 != 0) {
        // 0x80178BC0: nop
    
            goto L_80178BD8;
    }
    // 0x80178BC0: nop

    // 0x80178BC4: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x80178BC8: sb          $t9, 0x350($v0)
    MEM_B(0X350, ctx->r2) = ctx->r25;
    // 0x80178BCC: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x80178BD0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80178BD4: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
L_80178BD8:
    // 0x80178BD8: beq         $v1, $at, L_80178BE4
    if (ctx->r3 == ctx->r1) {
        // 0x80178BDC: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80178BE4;
    }
    // 0x80178BDC: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80178BE0: sb          $t0, 0x350($v0)
    MEM_B(0X350, ctx->r2) = ctx->r8;
L_80178BE4:
    // 0x80178BE4: lw          $v1, 0x2C0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C0);
    // 0x80178BE8: bne         $v1, $zero, L_80178BF8
    if (ctx->r3 != 0) {
        // 0x80178BEC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80178BF8;
    }
    // 0x80178BEC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80178BF0: b           L_80178C00
    // 0x80178BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80178C00;
    // 0x80178BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80178BF8:
    // 0x80178BF8: sw          $t1, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r9;
    // 0x80178BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80178C00:
    // 0x80178C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178C08: jr          $ra
    // 0x80178C0C: nop

    return;
    // 0x80178C0C: nop

;}
RECOMP_FUNC void itMSBombFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80176454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176458: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017645C: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x80176460: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80176464: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80176468: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8017646C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80176470: jal         0x80172558
    // 0x80176474: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80176474: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80176478: jal         0x801713F4
    // 0x8017647C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x8017647C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80176480: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80176484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80176488: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8017648C: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80176490: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80176494: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    // 0x80176498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017649C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801764A0: jr          $ra
    // 0x801764A4: nop

    return;
    // 0x801764A4: nop

;}
RECOMP_FUNC void efManagerDamageSpawnSparksRandgcMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100224: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80100228: jal         0x80018994
    // 0x8010022C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010022C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80100230: beq         $v0, $zero, L_80100240
    if (ctx->r2 == 0) {
        // 0x80100234: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80100240;
    }
    // 0x80100234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80100238: b           L_80100248
    // 0x8010023C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100248;
    // 0x8010023C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100240:
    // 0x80100240: jal         0x801001A8
    // 0x80100244: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    efManagerDamageSpawnSparksMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80100244: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80100248:
    // 0x80100248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100250: jr          $ra
    // 0x80100254: nop

    return;
    // 0x80100254: nop

;}
RECOMP_FUNC void wpBossBulletProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DD2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016DD30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DD34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016DD38: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016DD3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016DD40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016DD44: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8016DD48: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8016DD4C: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016DD50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016DD54: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016DD58: jal         0x80019438
    // 0x8016DD5C: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8016DD5C: nop

    after_0:
    // 0x8016DD60: jal         0x80168428
    // 0x8016DD64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainReflectorRotateWeaponModel(rdram, ctx);
        goto after_1;
    // 0x8016DD64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016DD68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DD6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016DD70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016DD74: jr          $ra
    // 0x8016DD78: nop

    return;
    // 0x8016DD78: nop

;}
RECOMP_FUNC void __n_unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E1C4: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8002E1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E1CC: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x8002E1D0: beq         $v1, $zero, L_8002E22C
    if (ctx->r3 == 0) {
        // 0x8002E1D4: nop
    
            goto L_8002E22C;
    }
    // 0x8002E1D4: nop

L_8002E1D8:
    // 0x8002E1D8: bnel        $v1, $a2, L_8002E220
    if (ctx->r3 != ctx->r6) {
        // 0x8002E1DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8002E220;
    }
    goto skip_0;
    // 0x8002E1DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8002E1E0: beql        $v0, $zero, L_8002E1F8
    if (ctx->r2 == 0) {
        // 0x8002E1E4: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_8002E1F8;
    }
    goto skip_1;
    // 0x8002E1E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8002E1E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002E1EC: b           L_8002E1FC
    // 0x8002E1F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_8002E1FC;
    // 0x8002E1F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002E1F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_8002E1F8:
    // 0x8002E1F8: sw          $t7, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r15;
L_8002E1FC:
    // 0x8002E1FC: lw          $t8, 0x70($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X70);
    // 0x8002E200: bnel        $v1, $t8, L_8002E210
    if (ctx->r3 != ctx->r24) {
        // 0x8002E204: lw          $t9, 0x74($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X74);
            goto L_8002E210;
    }
    goto skip_2;
    // 0x8002E204: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    skip_2:
    // 0x8002E208: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8002E20C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
L_8002E210:
    // 0x8002E210: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002E214: jr          $ra
    // 0x8002E218: sw          $v1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r3;
    return;
    // 0x8002E218: sw          $v1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r3;
    // 0x8002E21C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002E220:
    // 0x8002E220: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8002E224: bne         $v1, $zero, L_8002E1D8
    if (ctx->r3 != 0) {
        // 0x8002E228: nop
    
            goto L_8002E1D8;
    }
    // 0x8002E228: nop

L_8002E22C:
    // 0x8002E22C: jr          $ra
    // 0x8002E230: nop

    return;
    // 0x8002E230: nop

;}
RECOMP_FUNC void syDebugMeterProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021B30: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80021B34: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80021B38: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80021B3C: addiu       $s3, $s3, 0x65B0
    ctx->r19 = ADD32(ctx->r19, 0X65B0);
    // 0x80021B40: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80021B44: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80021B48: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80021B4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80021B50: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80021B54: lw          $a1, 0x74($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X74);
    // 0x80021B58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80021B5C: jal         0x80016338
    // 0x80021B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80016338(rdram, ctx);
        goto after_0;
    // 0x80021B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80021B64: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021B68: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80021B6C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80021B70: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80021B74: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80021B78: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80021B7C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80021B80: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021B84: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80021B88: lui         $t0, 0x30
    ctx->r8 = S32(0X30 << 16);
    // 0x80021B8C: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80021B90: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80021B94: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x80021B98: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80021B9C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021BA0: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80021BA4: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x80021BA8: addiu       $t1, $s0, 0x8
    ctx->r9 = ADD32(ctx->r16, 0X8);
    // 0x80021BAC: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80021BB0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80021BB4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80021BB8: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80021BBC: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x80021BC0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80021BC4: addiu       $t3, $s1, 0x8
    ctx->r11 = ADD32(ctx->r17, 0X8);
    // 0x80021BC8: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80021BCC: jal         0x80006D70
    // 0x80021BD0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    syVideoGetFillColor(rdram, ctx);
        goto after_1;
    // 0x80021BD0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    after_1:
    // 0x80021BD4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80021BD8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80021BDC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80021BE0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80021BE4: lb          $a2, 0x5478($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X5478);
    // 0x80021BE8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80021BEC: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // 0x80021BF0: jal         0x800218E0
    // 0x80021BF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800218E0(rdram, ctx);
        goto after_2;
    // 0x80021BF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80021BF8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80021BFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021C00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80021C04: lb          $a2, 0x5479($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X5479);
    // 0x80021C08: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x80021C0C: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // 0x80021C10: jal         0x800218E0
    // 0x80021C14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800218E0(rdram, ctx);
        goto after_3;
    // 0x80021C14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80021C18: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80021C1C: addiu       $s2, $s2, 0x6610
    ctx->r18 = ADD32(ctx->r18, 0X6610);
    // 0x80021C20: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80021C24: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80021C28: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021C2C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80021C30: bgez        $t7, L_80021C48
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80021C34: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021C48;
    }
    // 0x80021C34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021C38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021C3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021C40: nop

    // 0x80021C44: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80021C48:
    // 0x80021C48: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021C50: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80021C54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80021C58: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80021C5C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80021C60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80021C64: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021C68: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80021C6C: jal         0x80021908
    // 0x80021C70: nop

    func_80021908(rdram, ctx);
        goto after_4;
    // 0x80021C70: nop

    after_4:
    // 0x80021C74: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80021C78: lw          $t0, 0x6614($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6614);
    // 0x80021C7C: addiu       $s0, $zero, 0x5F
    ctx->r16 = ADD32(0, 0X5F);
    // 0x80021C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021C84: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80021C88: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021C8C: bgez        $t0, L_80021CA4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80021C90: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80021CA4;
    }
    // 0x80021C90: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80021C94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021C98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021C9C: nop

    // 0x80021CA0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80021CA4:
    // 0x80021CA4: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021CA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021CAC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80021CB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80021CB4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021CB8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80021CBC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80021CC0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021CC4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80021CC8: jal         0x80021908
    // 0x80021CCC: nop

    func_80021908(rdram, ctx);
        goto after_5;
    // 0x80021CCC: nop

    after_5:
    // 0x80021CD0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80021CD4: lw          $t3, 0x4FB4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4FB4);
    // 0x80021CD8: addiu       $s0, $s0, 0x23
    ctx->r16 = ADD32(ctx->r16, 0X23);
    // 0x80021CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021CE0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80021CE4: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021CE8: bgez        $t3, L_80021D00
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80021CEC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80021D00;
    }
    // 0x80021CEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80021CF0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021CF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021CF8: nop

    // 0x80021CFC: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80021D00:
    // 0x80021D00: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021D04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021D08: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80021D0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80021D10: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80021D14: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80021D18: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80021D1C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021D20: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80021D24: jal         0x80021908
    // 0x80021D28: nop

    func_80021908(rdram, ctx);
        goto after_6;
    // 0x80021D28: nop

    after_6:
    // 0x80021D2C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80021D30: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80021D38: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80021D3C: addiu       $s0, $s0, 0x23
    ctx->r16 = ADD32(ctx->r16, 0X23);
    // 0x80021D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D44: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021D48: bgez        $t6, L_80021D60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021D4C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80021D60;
    }
    // 0x80021D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80021D50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021D54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80021D58: nop

    // 0x80021D5C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_80021D60:
    // 0x80021D60: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021D64: lw          $t7, 0x6614($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6614);
    // 0x80021D68: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021D6C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80021D70: bgez        $t7, L_80021D88
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80021D74: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021D88;
    }
    // 0x80021D74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021D78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021D7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021D80: nop

    // 0x80021D84: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80021D88:
    // 0x80021D88: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80021D8C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80021D90: lw          $t8, 0x4FB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4FB4);
    // 0x80021D94: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80021D98: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80021D9C: bgez        $t8, L_80021DB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80021DA0: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021DB4;
    }
    // 0x80021DA0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021DA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021DA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021DAC: nop

    // 0x80021DB0: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80021DB4:
    // 0x80021DB4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80021DB8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80021DBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80021DC0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80021DC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80021DC8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021DCC: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80021DD0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80021DD4: jal         0x80021908
    // 0x80021DD8: nop

    func_80021908(rdram, ctx);
        goto after_7;
    // 0x80021DD8: nop

    after_7:
    // 0x80021DDC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80021DE0: lw          $t1, -0x2D30($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D30);
    // 0x80021DE4: addiu       $s0, $s0, 0x46
    ctx->r16 = ADD32(ctx->r16, 0X46);
    // 0x80021DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021DEC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80021DF0: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021DF4: bgez        $t1, L_80021E0C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80021DF8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80021E0C;
    }
    // 0x80021DF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80021DFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021E00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021E04: nop

    // 0x80021E08: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80021E0C:
    // 0x80021E0C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021E10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80021E14: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80021E18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80021E1C: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80021E20: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80021E24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80021E28: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021E2C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80021E30: jal         0x80021908
    // 0x80021E34: nop

    func_80021908(rdram, ctx);
        goto after_8;
    // 0x80021E34: nop

    after_8:
    // 0x80021E38: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021E3C: lw          $t4, 0x4FB8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4FB8);
    // 0x80021E40: addiu       $a0, $s0, 0x23
    ctx->r4 = ADD32(ctx->r16, 0X23);
    // 0x80021E44: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80021E48: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80021E4C: bgez        $t4, L_80021E64
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80021E50: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80021E64;
    }
    // 0x80021E50: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021E54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80021E58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80021E5C: nop

    // 0x80021E60: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80021E64:
    // 0x80021E64: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80021E68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021E6C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80021E70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021E74: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80021E78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80021E7C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80021E80: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80021E84: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80021E88: jal         0x80021908
    // 0x80021E8C: nop

    func_80021908(rdram, ctx);
        goto after_9;
    // 0x80021E8C: nop

    after_9:
    // 0x80021E90: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021E94: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80021E98: lui         $t0, 0xF700
    ctx->r8 = S32(0XF700 << 16);
    // 0x80021E9C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80021EA0: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80021EA4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80021EA8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80021EAC: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80021EB0: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80021EB4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80021EB8: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x80021EBC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80021EC0: jal         0x80006D70
    // 0x80021EC4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    syVideoGetFillColor(rdram, ctx);
        goto after_10;
    // 0x80021EC4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    after_10:
    // 0x80021EC8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80021ECC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80021ED0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80021ED4: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x80021ED8: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x80021EDC: sltiu       $at, $v1, 0x101
    ctx->r1 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x80021EE0: bne         $at, $zero, L_80021EF0
    if (ctx->r1 != 0) {
        // 0x80021EE4: addiu       $t1, $zero, 0xD3
        ctx->r9 = ADD32(0, 0XD3);
            goto L_80021EF0;
    }
    // 0x80021EE4: addiu       $t1, $zero, 0xD3
    ctx->r9 = ADD32(0, 0XD3);
    // 0x80021EE8: b           L_80021EF4
    // 0x80021EEC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_80021EF4;
    // 0x80021EEC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80021EF0:
    // 0x80021EF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80021EF4:
    // 0x80021EF4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021EF8: addiu       $a3, $v0, 0x1E
    ctx->r7 = ADD32(ctx->r2, 0X1E);
    // 0x80021EFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80021F00: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80021F04: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80021F08: jal         0x80021A34
    // 0x80021F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_11;
    // 0x80021F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80021F10: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021F14: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80021F18: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x80021F1C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80021F20: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80021F24: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80021F28: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80021F2C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x80021F30: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80021F34: addiu       $s1, $zero, 0xD4
    ctx->r17 = ADD32(0, 0XD4);
    // 0x80021F38: addiu       $t5, $s2, 0x8
    ctx->r13 = ADD32(ctx->r18, 0X8);
    // 0x80021F3C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80021F40: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x80021F44: jal         0x80006D70
    // 0x80021F48: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    syVideoGetFillColor(rdram, ctx);
        goto after_12;
    // 0x80021F48: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    after_12:
    // 0x80021F4C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80021F50: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80021F54: lw          $v1, 0x6614($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6614);
    // 0x80021F58: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80021F5C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021F60: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x80021F64: sltiu       $at, $v1, 0x101
    ctx->r1 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x80021F68: bne         $at, $zero, L_80021F78
    if (ctx->r1 != 0) {
        // 0x80021F6C: addiu       $t7, $s1, 0x1
        ctx->r15 = ADD32(ctx->r17, 0X1);
            goto L_80021F78;
    }
    // 0x80021F6C: addiu       $t7, $s1, 0x1
    ctx->r15 = ADD32(ctx->r17, 0X1);
    // 0x80021F70: b           L_80021F7C
    // 0x80021F74: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_80021F7C;
    // 0x80021F74: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80021F78:
    // 0x80021F78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80021F7C:
    // 0x80021F7C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021F80: addiu       $a3, $v0, 0x1E
    ctx->r7 = ADD32(ctx->r2, 0X1E);
    // 0x80021F84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80021F88: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80021F8C: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80021F90: jal         0x80021A34
    // 0x80021F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_13;
    // 0x80021F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80021F98: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80021F9C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80021FA0: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x80021FA4: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80021FA8: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80021FAC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80021FB0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80021FB4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x80021FB8: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80021FBC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80021FC0: addiu       $t1, $s2, 0x8
    ctx->r9 = ADD32(ctx->r18, 0X8);
    // 0x80021FC4: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80021FC8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80021FCC: jal         0x80006D70
    // 0x80021FD0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    syVideoGetFillColor(rdram, ctx);
        goto after_14;
    // 0x80021FD0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    after_14:
    // 0x80021FD4: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80021FD8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80021FDC: lw          $v1, 0x4FB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4FB4);
    // 0x80021FE0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80021FE4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021FE8: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x80021FEC: sltiu       $at, $v1, 0x101
    ctx->r1 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x80021FF0: bne         $at, $zero, L_80022000
    if (ctx->r1 != 0) {
        // 0x80021FF4: addiu       $t3, $s1, 0x1
        ctx->r11 = ADD32(ctx->r17, 0X1);
            goto L_80022000;
    }
    // 0x80021FF4: addiu       $t3, $s1, 0x1
    ctx->r11 = ADD32(ctx->r17, 0X1);
    // 0x80021FF8: b           L_80022004
    // 0x80021FFC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_80022004;
    // 0x80021FFC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80022000:
    // 0x80022000: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80022004:
    // 0x80022004: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022008: addiu       $a3, $v0, 0x1E
    ctx->r7 = ADD32(ctx->r2, 0X1E);
    // 0x8002200C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80022010: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80022014: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80022018: jal         0x80021A34
    // 0x8002201C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_15;
    // 0x8002201C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80022020: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022024: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80022028: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x8002202C: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80022030: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80022034: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022038: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002203C: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x80022040: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80022044: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80022048: addiu       $t7, $s2, 0x8
    ctx->r15 = ADD32(ctx->r18, 0X8);
    // 0x8002204C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80022050: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80022054: jal         0x80006D70
    // 0x80022058: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    syVideoGetFillColor(rdram, ctx);
        goto after_16;
    // 0x80022058: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    after_16:
    // 0x8002205C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80022060: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80022064: lw          $v1, -0x2D30($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2D30);
    // 0x80022068: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8002206C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80022070: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x80022074: sltiu       $at, $v1, 0x101
    ctx->r1 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x80022078: bne         $at, $zero, L_80022088
    if (ctx->r1 != 0) {
        // 0x8002207C: addiu       $t9, $s1, 0x1
        ctx->r25 = ADD32(ctx->r17, 0X1);
            goto L_80022088;
    }
    // 0x8002207C: addiu       $t9, $s1, 0x1
    ctx->r25 = ADD32(ctx->r17, 0X1);
    // 0x80022080: b           L_8002208C
    // 0x80022084: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_8002208C;
    // 0x80022084: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80022088:
    // 0x80022088: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002208C:
    // 0x8002208C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022090: addiu       $a3, $v0, 0x1E
    ctx->r7 = ADD32(ctx->r2, 0X1E);
    // 0x80022094: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022098: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x8002209C: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x800220A0: jal         0x80021A34
    // 0x800220A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_17;
    // 0x800220A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800220A8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800220AC: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800220B0: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800220B4: addiu       $t1, $s0, 0x8
    ctx->r9 = ADD32(ctx->r16, 0X8);
    // 0x800220B8: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x800220BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800220C0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800220C4: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x800220C8: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800220CC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800220D0: addiu       $t3, $s2, 0x8
    ctx->r11 = ADD32(ctx->r18, 0X8);
    // 0x800220D4: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800220D8: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800220DC: jal         0x80006D70
    // 0x800220E0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    syVideoGetFillColor(rdram, ctx);
        goto after_18;
    // 0x800220E0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    after_18:
    // 0x800220E4: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800220E8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800220EC: lw          $v1, 0x4FB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4FB8);
    // 0x800220F0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800220F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800220F8: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x800220FC: sltiu       $at, $v1, 0x101
    ctx->r1 = ctx->r3 < 0X101 ? 1 : 0;
    // 0x80022100: bne         $at, $zero, L_80022110
    if (ctx->r1 != 0) {
        // 0x80022104: addiu       $t5, $s1, 0x1
        ctx->r13 = ADD32(ctx->r17, 0X1);
            goto L_80022110;
    }
    // 0x80022104: addiu       $t5, $s1, 0x1
    ctx->r13 = ADD32(ctx->r17, 0X1);
    // 0x80022108: b           L_80022114
    // 0x8002210C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_80022114;
    // 0x8002210C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80022110:
    // 0x80022110: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80022114:
    // 0x80022114: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022118: addiu       $a3, $v0, 0x1E
    ctx->r7 = ADD32(ctx->r2, 0X1E);
    // 0x8002211C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80022120: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80022124: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80022128: jal         0x80021A34
    // 0x8002212C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_19;
    // 0x8002212C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80022130: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022134: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80022138: lui         $t0, 0xF700
    ctx->r8 = S32(0XF700 << 16);
    // 0x8002213C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80022140: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80022144: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022148: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002214C: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80022150: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80022154: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80022158: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x8002215C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80022160: jal         0x80006D70
    // 0x80022164: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    syVideoGetFillColor(rdram, ctx);
        goto after_20;
    // 0x80022164: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    after_20:
    // 0x80022168: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8002216C: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80022170: addiu       $s1, $s1, 0x5470
    ctx->r17 = ADD32(ctx->r17, 0X5470);
    // 0x80022174: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80022178: lhu         $t1, 0x0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X0);
L_8002217C:
    // 0x8002217C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80022180: sllv        $t3, $t2, $s2
    ctx->r11 = S32(ctx->r10 << (ctx->r18 & 31));
    // 0x80022184: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x80022188: beq         $t4, $zero, L_800221B8
    if (ctx->r12 == 0) {
        // 0x8002218C: sll         $v0, $s2, 2
        ctx->r2 = S32(ctx->r18 << 2);
            goto L_800221B8;
    }
    // 0x8002218C: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80022190: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022194: addiu       $t5, $zero, 0xD0
    ctx->r13 = ADD32(0, 0XD0);
    // 0x80022198: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002219C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800221A0: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800221A4: addiu       $a1, $v0, 0x1E
    ctx->r5 = ADD32(ctx->r2, 0X1E);
    // 0x800221A8: addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // 0x800221AC: addiu       $a3, $v0, 0x21
    ctx->r7 = ADD32(ctx->r2, 0X21);
    // 0x800221B0: jal         0x80021A34
    // 0x800221B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_21;
    // 0x800221B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
L_800221B8:
    // 0x800221B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800221BC: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    // 0x800221C0: bnel        $at, $zero, L_8002217C
    if (ctx->r1 != 0) {
        // 0x800221C4: lhu         $t1, 0x0($s1)
        ctx->r9 = MEM_HU(ctx->r17, 0X0);
            goto L_8002217C;
    }
    goto skip_0;
    // 0x800221C4: lhu         $t1, 0x0($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X0);
    skip_0:
    // 0x800221C8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800221CC: lb          $v0, 0x5478($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5478);
    // 0x800221D0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800221D4: lb          $v1, 0x5479($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5479);
    // 0x800221D8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800221DC: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800221E0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800221E4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800221E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800221EC: bgez        $v0, L_800221F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800221F0: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_800221F8;
    }
    // 0x800221F0: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x800221F4: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
L_800221F8:
    // 0x800221F8: sra         $v0, $at, 2
    ctx->r2 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800221FC: addiu       $a1, $v0, 0x27
    ctx->r5 = ADD32(ctx->r2, 0X27);
    // 0x80022200: bgez        $v1, L_8002220C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80022204: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8002220C;
    }
    // 0x80022204: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80022208: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
L_8002220C:
    // 0x8002220C: sra         $v1, $at, 2
    ctx->r3 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80022210: addiu       $t7, $v1, 0xBA
    ctx->r15 = ADD32(ctx->r3, 0XBA);
    // 0x80022214: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80022218: addiu       $a2, $v1, 0xB8
    ctx->r6 = ADD32(ctx->r3, 0XB8);
    // 0x8002221C: jal         0x80021A34
    // 0x80022220: addiu       $a3, $v0, 0x29
    ctx->r7 = ADD32(ctx->r2, 0X29);
    syDebugFillRectangle(rdram, ctx);
        goto after_22;
    // 0x80022220: addiu       $a3, $v0, 0x29
    ctx->r7 = ADD32(ctx->r2, 0X29);
    after_22:
    // 0x80022224: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022228: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8002222C: lui         $t1, 0xF700
    ctx->r9 = S32(0XF700 << 16);
    // 0x80022230: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80022234: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80022238: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8002223C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022240: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022244: lui         $a0, 0x1010
    ctx->r4 = S32(0X1010 << 16);
    // 0x80022248: ori         $a0, $a0, 0x10FF
    ctx->r4 = ctx->r4 | 0X10FF;
    // 0x8002224C: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80022250: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80022254: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80022258: jal         0x80006D70
    // 0x8002225C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    syVideoGetFillColor(rdram, ctx);
        goto after_23;
    // 0x8002225C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_23:
    // 0x80022260: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80022264: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
    // 0x80022268: addiu       $s2, $zero, 0x15E
    ctx->r18 = ADD32(0, 0X15E);
    // 0x8002226C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80022270: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_80022274:
    // 0x80022274: addiu       $t3, $zero, 0xDC
    ctx->r11 = ADD32(0, 0XDC);
    // 0x80022278: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002227C: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80022280: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80022284: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80022288: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x8002228C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80022290: jal         0x80021A34
    // 0x80022294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_24;
    // 0x80022294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80022298: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x8002229C: bnel        $s1, $s2, L_80022274
    if (ctx->r17 != ctx->r18) {
        // 0x800222A0: lw          $s0, 0x0($s3)
        ctx->r16 = MEM_W(ctx->r19, 0X0);
            goto L_80022274;
    }
    goto skip_1;
    // 0x800222A0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x800222A4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800222A8: addiu       $t5, $zero, 0xCD
    ctx->r13 = ADD32(0, 0XCD);
    // 0x800222AC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800222B0: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800222B4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800222B8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800222BC: addiu       $a2, $zero, 0xA5
    ctx->r6 = ADD32(0, 0XA5);
    // 0x800222C0: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x800222C4: jal         0x80021A34
    // 0x800222C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_25;
    // 0x800222C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800222CC: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800222D0: addiu       $t7, $zero, 0xB9
    ctx->r15 = ADD32(0, 0XB9);
    // 0x800222D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800222D8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800222DC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800222E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800222E4: addiu       $a2, $zero, 0xB9
    ctx->r6 = ADD32(0, 0XB9);
    // 0x800222E8: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x800222EC: jal         0x80021A34
    // 0x800222F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugFillRectangle(rdram, ctx);
        goto after_26;
    // 0x800222F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x800222F4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800222F8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800222FC: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x80022300: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80022304: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80022308: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8002230C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80022310: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022314: ori         $t1, $t1, 0xA01
    ctx->r9 = ctx->r9 | 0XA01;
    // 0x80022318: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x8002231C: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80022320: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80022324: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80022328: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8002232C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80022330: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x80022334: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x80022338: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x8002233C: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80022340: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x80022344: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80022348: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x8002234C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80022350: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80022354: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80022358: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002235C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80022360: jr          $ra
    // 0x80022364: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80022364: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_ovl8_80377330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377338: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037733C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80377340: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80377344: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80377348: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037734C: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80377350: lh          $t6, 0x50($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X50);
    // 0x80377354: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80377358: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8037735C: jalr        $t9
    // 0x80377360: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80377360: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80377364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037736C: jr          $ra
    // 0x80377370: nop

    return;
    // 0x80377370: nop

;}
RECOMP_FUNC void ftCommonCliffEscapeCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801457E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801457E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801457E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801457EC: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x801457F0: lhu         $t7, 0x1B8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B8);
    // 0x801457F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801457F8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801457FC: beq         $t8, $zero, L_80145814
    if (ctx->r24 == 0) {
        // 0x80145800: nop
    
            goto L_80145814;
    }
    // 0x80145800: nop

    // 0x80145804: jal         0x80144FE8
    // 0x80145808: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftCommonCliffQuickOrSlowSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145808: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8014580C: b           L_80145814
    // 0x80145810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80145814;
    // 0x80145810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80145814:
    // 0x80145814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014581C: jr          $ra
    // 0x80145820: nop

    return;
    // 0x80145820: nop

;}
RECOMP_FUNC void sc1PGameBossSetWallpaperTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019223C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80192240: lw          $v1, 0x38E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X38E8);
    // 0x80192244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80192248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019224C: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x80192250: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80192254: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80192258: bne         $t6, $at, L_8019229C
    if (ctx->r14 != ctx->r1) {
        // 0x8019225C: sll         $t2, $a1, 2
        ctx->r10 = S32(ctx->r5 << 2);
            goto L_8019229C;
    }
    // 0x8019225C: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80192260: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80192264: jal         0x80191B44
    // 0x80192268: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_ovl65_80191B44(rdram, ctx);
        goto after_0;
    // 0x80192268: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8019226C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80192270: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80192274: lw          $t7, 0x38E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38E8);
    // 0x80192278: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8019227C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80192280: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80192284: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80192288: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019228C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80192290: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80192294: b           L_801922C4
    // 0x80192298: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
        goto L_801922C4;
    // 0x80192298: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
L_8019229C:
    // 0x8019229C: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x801922A0: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
    // 0x801922A4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801922A8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801922AC: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x801922B0: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x801922B4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801922B8: sw          $t4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r12;
    // 0x801922BC: lw          $t5, 0x14($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X14);
    // 0x801922C0: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
L_801922C4:
    // 0x801922C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801922C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801922CC: jr          $ra
    // 0x801922D0: nop

    return;
    // 0x801922D0: nop

;}
RECOMP_FUNC void grInishieScaleUpdateFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109118: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8010911C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80109120: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109124: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109128: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8010912C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80109130: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010913C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80109140: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80109144: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109148: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010914C: nop

    // 0x80109150: bc1fl       L_80109164
    if (!c1cs) {
        // 0x80109154: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80109164;
    }
    goto skip_0;
    // 0x80109154: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x80109158: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x8010915C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109160: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80109164:
    // 0x80109164: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80109168: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8010916C: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80109170: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80109174: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x80109178: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8010917C: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109180: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80109184: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80109188: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8010918C: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x80109190: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80109194: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80109198: lh          $t7, 0x76($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X76);
    // 0x8010919C: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801091A0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801091A4: nop

    // 0x801091A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801091AC: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801091B0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x801091B4: nop

    // 0x801091B8: bc1fl       L_80109214
    if (!c1cs) {
        // 0x801091BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80109214;
    }
    goto skip_1;
    // 0x801091BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801091C0: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x801091C4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801091C8: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x801091CC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x801091D0: nop

    // 0x801091D4: bc1fl       L_80109214
    if (!c1cs) {
        // 0x801091D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80109214;
    }
    goto skip_2;
    // 0x801091D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801091DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801091E0: sb          $t0, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r8;
    // 0x801091E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801091E8: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x801091EC: jal         0x800FC604
    // 0x801091F0: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_0;
    // 0x801091F0: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    after_0:
    // 0x801091F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801091F8: jal         0x800FC604
    // 0x801091FC: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    mpCollisionSetYakumonoOffID(rdram, ctx);
        goto after_1;
    // 0x801091FC: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    after_1:
    // 0x80109200: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109204: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109208: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x8010920C: sh          $t1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r9;
    // 0x80109210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80109214:
    // 0x80109214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109218: jr          $ra
    // 0x8010921C: nop

    return;
    // 0x8010921C: nop

;}
RECOMP_FUNC void syTaskmanSetIntervals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006A90: sh          $a0, 0x54B8($at)
    MEM_H(0X54B8, ctx->r1) = ctx->r4;
    // 0x80006A94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006A98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80006A9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80006AA0: jr          $ra
    // 0x80006AA4: sh          $a1, 0x54BA($at)
    MEM_H(0X54BA, ctx->r1) = ctx->r5;
    return;
    // 0x80006AA4: sh          $a1, 0x54BA($at)
    MEM_H(0X54BA, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void gmRumbleMakeActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801156E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801156E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801156EC: addiu       $a0, $zero, 0x3F9
    ctx->r4 = ADD32(0, 0X3F9);
    // 0x801156F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801156F4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x801156F8: jal         0x80009968
    // 0x801156FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801156FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80115700: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80115704: addiu       $a1, $a1, 0x5298
    ctx->r5 = ADD32(ctx->r5, 0X5298);
    // 0x80115708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8011570C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80115710: jal         0x80008188
    // 0x80115714: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80115714: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80115718: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8011571C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80115720: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80115724: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80115728: addiu       $t4, $t4, 0x1960
    ctx->r12 = ADD32(ctx->r12, 0X1960);
    // 0x8011572C: addiu       $t0, $t0, 0x1870
    ctx->r8 = ADD32(ctx->r8, 0X1870);
    // 0x80115730: addiu       $t2, $t2, 0x1960
    ctx->r10 = ADD32(ctx->r10, 0X1960);
    // 0x80115734: addiu       $t1, $t1, 0x19F0
    ctx->r9 = ADD32(ctx->r9, 0X19F0);
    // 0x80115738: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8011573C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80115740:
    // 0x80115740: addiu       $a2, $t3, 0x1
    ctx->r6 = ADD32(ctx->r11, 0X1);
    // 0x80115744: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80115748: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x8011574C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80115750: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80115754: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80115758: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8011575C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80115760: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80115764: addiu       $t9, $t9, 0x1870
    ctx->r25 = ADD32(ctx->r25, 0X1870);
    // 0x80115768: addiu       $t7, $t7, 0x1960
    ctx->r15 = ADD32(ctx->r15, 0X1960);
    // 0x8011576C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80115770: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80115774: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80115778: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8011577C: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x80115780: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80115784: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80115788: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8011578C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80115790:
    // 0x80115790: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80115794: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80115798: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8011579C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801157A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801157A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801157A8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x801157AC: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x801157B0: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x801157B4: bne         $a1, $a3, L_80115790
    if (ctx->r5 != ctx->r7) {
        // 0x801157B8: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_80115790;
    }
    // 0x801157B8: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801157BC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801157C0: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x801157C4: addiu       $t0, $t0, 0x3C
    ctx->r8 = ADD32(ctx->r8, 0X3C);
    // 0x801157C8: addiu       $t3, $t3, 0x3
    ctx->r11 = ADD32(ctx->r11, 0X3);
    // 0x801157CC: addiu       $t2, $t2, 0x24
    ctx->r10 = ADD32(ctx->r10, 0X24);
    // 0x801157D0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x801157D4: bne         $t0, $t4, L_80115740
    if (ctx->r8 != ctx->r12) {
        // 0x801157D8: sw          $a2, 0x8($t5)
        MEM_W(0X8, ctx->r13) = ctx->r6;
            goto L_80115740;
    }
    // 0x801157D8: sw          $a2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r6;
    // 0x801157DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801157E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801157E4: jr          $ra
    // 0x801157E8: nop

    return;
    // 0x801157E8: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163438: jal         0x801630A0
    // 0x8016343C: addiu       $a1, $zero, 0x119
    ctx->r5 = ADD32(0, 0X119);
    ftKirbySpecialNCatchEatSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8016343C: addiu       $a1, $zero, 0x119
    ctx->r5 = ADD32(0, 0X119);
    after_0:
    // 0x80163440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163448: jr          $ra
    // 0x8016344C: nop

    return;
    // 0x8016344C: nop

;}
RECOMP_FUNC void lbCommonEjectGObjLinkedList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB610: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800CB614: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CB618: beq         $a1, $zero, L_800CB62C
    if (ctx->r5 == 0) {
        // 0x800CB61C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800CB62C;
    }
    // 0x800CB61C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CB620: jal         0x800CB608
    // 0x800CB624: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    lbCommonEjectGObjLinkedList(rdram, ctx);
        goto after_0;
    // 0x800CB624: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CB628: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_800CB62C:
    // 0x800CB62C: jal         0x80009A84
    // 0x800CB630: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800CB630: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800CB634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB63C: jr          $ra
    // 0x800CB640: nop

    return;
    // 0x800CB640: nop

;}
RECOMP_FUNC void itNessPKFireWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185668: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018566C: jal         0x801735A0
    // 0x80185670: addiu       $a1, $a1, 0x579C
    ctx->r5 = ADD32(ctx->r5, 0X579C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80185670: addiu       $a1, $a1, 0x579C
    ctx->r5 = ADD32(ctx->r5, 0X579C);
    after_0:
    // 0x80185674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018567C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185680: jr          $ra
    // 0x80185684: nop

    return;
    // 0x80185684: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMovePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BB4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80135BB8: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80135BBC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80135BC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135BC4: lwc1        $f6, 0x60($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80135BC8: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80135BCC: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135BD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135BD4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80135BD8: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80135BDC: lwc1        $f16, 0x64($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80135BE0: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80135BE4: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135BE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80135BEC: jr          $ra
    // 0x80135BF0: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80135BF0: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void grYamabukiGateSetPositionNear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AE68: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x8010AE6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010AE70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010AE74: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010AE78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010AE7C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8010AE80: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x8010AE84: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8010AE88: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8010AE8C: jr          $ra
    // 0x8010AE90: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8010AE90: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mvOpeningMarioMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA60: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA68: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA6C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA70: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DA74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DA78: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DA7C: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DA80:
    // 0x8018DA80: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA84: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DA88: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DA8C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DA90: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DA94: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DA98: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DA9C: bne         $t6, $t0, L_8018DA80
    if (ctx->r14 != ctx->r8) {
        // 0x8018DAA0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DA80;
    }
    // 0x8018DAA0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAA4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018DAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DAB0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAB4: jal         0x800EC0EC
    // 0x8018DAB8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DAB8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8018DABC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAC0: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018DAC4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018DAC8: lw          $t1, -0x1DE4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1DE4);
    // 0x8018DACC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DAD0: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DAD8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DADC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAE0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8018DAE4: jal         0x800D7F3C
    // 0x8018DAE8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DAE8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DAEC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DAF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DAF4: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DAF8: jal         0x803905CC
    // 0x8018DAFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DAFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB04: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB08: jal         0x8000A0D0
    // 0x8018DB0C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB0C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB10: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB14: addiu       $a1, $a1, -0x2670
    ctx->r5 = ADD32(ctx->r5, -0X2670);
    // 0x8018DB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB20: jal         0x80008188
    // 0x8018DB24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB30: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB34: swc1        $f0, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f0.u32l;
    // 0x8018DB38: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB3C: swc1        $f0, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB40: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB44: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB50: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB54: jr          $ra
    // 0x8018DB58: nop

    return;
    // 0x8018DB58: nop

;}
RECOMP_FUNC void mnMessageMakeMessageCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131F8C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80131F90: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131F94: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80131F98: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80131F9C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131FA0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80131FA4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131FA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131FAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131FB0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80131FB4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80131FB8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131FBC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131FC0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131FC4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131FC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FCC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131FD0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131FD4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131FD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131FE4: jal         0x8000B93C
    // 0x80131FE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131FE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131FF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FF4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131FF8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131FFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132000: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132004: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132008: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013200C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132010: jal         0x80007080
    // 0x80132014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132018: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013201C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132020: jr          $ra
    // 0x80132024: nop

    return;
    // 0x80132024: nop

;}
RECOMP_FUNC void func_ovl8_80372420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372420: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80372424: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80372428: jr          $ra
    // 0x8037242C: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    return;
    // 0x8037242C: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mnPlayersVSMakePortraitShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132278: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8013227C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132280: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132284: addiu       $t7, $t7, -0x4ACC
    ctx->r15 = ADD32(ctx->r15, -0X4ACC);
    // 0x80132288: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013228C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132290: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132294: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80132298: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_8013229C:
    // 0x8013229C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801322A0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801322A4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801322A8: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801322AC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801322B0: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801322B4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801322B8: bne         $t7, $t0, L_8013229C
    if (ctx->r15 != ctx->r8) {
        // 0x801322BC: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_8013229C;
    }
    // 0x801322BC: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801322C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322C8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x801322CC: jal         0x80009968
    // 0x801322D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801322D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801322D4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801322D8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801322DC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801322E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801322E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801322E8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x801322EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322F0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801322F4: jal         0x80009DF4
    // 0x801322F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801322F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801322FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132300: addiu       $a1, $a1, 0x1EE4
    ctx->r5 = ADD32(ctx->r5, 0X1EE4);
    // 0x80132304: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013230C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132310: jal         0x80008188
    // 0x80132314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132314: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132318: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013231C: lw          $t2, -0x3B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3B4C);
    // 0x80132320: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132324: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x80132328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013232C: jal         0x800CCFDC
    // 0x80132330: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132330: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80132334: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80132338: bne         $at, $zero, L_80132348
    if (ctx->r1 != 0) {
        // 0x8013233C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80132348;
    }
    // 0x8013233C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132340: b           L_8013234C
    // 0x80132344: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
        goto L_8013234C;
    // 0x80132344: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
L_80132348:
    // 0x80132348: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_8013234C:
    // 0x8013234C: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80132350: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80132354: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80132358: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8013235C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80132360: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80132364: addiu       $t5, $t4, 0x19
    ctx->r13 = ADD32(ctx->r12, 0X19);
    // 0x80132368: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8013236C: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x80132370: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132374: bne         $at, $zero, L_80132384
    if (ctx->r1 != 0) {
        // 0x80132378: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80132384;
    }
    // 0x80132378: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8013237C: b           L_80132388
    // 0x80132380: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132388;
    // 0x80132380: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80132384:
    // 0x80132384: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80132388:
    // 0x80132388: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8013238C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132390: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132394: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132398: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013239C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801323A0: addiu       $t7, $t0, 0x24
    ctx->r15 = ADD32(ctx->r8, 0X24);
    // 0x801323A4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801323A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801323AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801323B0: jal         0x80131F54
    // 0x801323B4: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    mnPlayersVSSetPortraitWallpaperPosition(rdram, ctx);
        goto after_4;
    // 0x801323B4: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    after_4:
    // 0x801323B8: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x801323BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323C4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x801323C8: jal         0x80009968
    // 0x801323CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x801323CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x801323D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801323D4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801323D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801323DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323E0: addiu       $a1, $a1, 0x21B8
    ctx->r5 = ADD32(ctx->r5, 0X21B8);
    // 0x801323E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323E8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801323EC: jal         0x80009DF4
    // 0x801323F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x801323F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x801323F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801323FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132400: jal         0x80008188
    // 0x80132404: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80132404: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80132408: jal         0x80132118
    // 0x8013240C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_8;
    // 0x8013240C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80132410: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80132414: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80132418: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013241C: lw          $t1, -0x3B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3B4C);
    // 0x80132420: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x80132424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132428: jal         0x800CCFDC
    // 0x8013242C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x8013242C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_9:
    // 0x80132430: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132438: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013243C: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132440: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132444: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132448: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x8013244C: jal         0x80131F54
    // 0x80132450: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    mnPlayersVSSetPortraitWallpaperPosition(rdram, ctx);
        goto after_10;
    // 0x80132450: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    after_10:
    // 0x80132454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013245C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132460: jal         0x80009968
    // 0x80132464: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_11;
    // 0x80132464: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_11:
    // 0x80132468: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013246C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132470: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132478: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8013247C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132480: jal         0x80009DF4
    // 0x80132484: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_12;
    // 0x80132484: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_12:
    // 0x80132488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013248C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132490: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132494: jal         0x80008188
    // 0x80132498: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x80132498: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x8013249C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801324A0: lw          $t7, -0x3B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3B4C);
    // 0x801324A4: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801324A8: addiu       $t6, $t6, 0xF68
    ctx->r14 = ADD32(ctx->r14, 0XF68);
    // 0x801324AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324B0: jal         0x800CCFDC
    // 0x801324B4: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_14;
    // 0x801324B4: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_14:
    // 0x801324B8: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801324BC: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x801324C0: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x801324C4: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x801324C8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801324CC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801324D0: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x801324D4: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x801324D8: addiu       $t7, $zero, 0xB9
    ctx->r15 = ADD32(0, 0XB9);
    // 0x801324DC: addiu       $t6, $zero, 0xA9
    ctx->r14 = ADD32(0, 0XA9);
    // 0x801324E0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801324E4: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x801324E8: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x801324EC: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x801324F0: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x801324F4: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801324F8: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801324FC: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132504: jal         0x80131F54
    // 0x80132508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSSetPortraitWallpaperPosition(rdram, ctx);
        goto after_15;
    // 0x80132508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x8013250C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132510: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132514: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132518: jr          $ra
    // 0x8013251C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8013251C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void syControllerStartRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000447C: jal         0x800043C0
    // 0x80004480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    syControllerUpdateRumbleEvent(rdram, ctx);
        goto after_0;
    // 0x80004480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80004484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000448C: jr          $ra
    // 0x80004490: nop

    return;
    // 0x80004490: nop

;}
RECOMP_FUNC void mnUnusedFightersFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D655C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800D6560: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
    // 0x800D6564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D656C: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x800D6570: beq         $t6, $zero, L_800D659C
    if (ctx->r14 == 0) {
        // 0x800D6574: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800D659C;
    }
    // 0x800D6574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D6578: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D657C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x800D6580: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D6584: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D6588: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800D658C: jal         0x80005C74
    // 0x800D6590: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x800D6590: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_0:
    // 0x800D6594: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800D6598: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
L_800D659C:
    // 0x800D659C: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    // 0x800D65A0: beq         $t9, $zero, L_800D65B4
    if (ctx->r25 == 0) {
        // 0x800D65A4: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_800D65B4;
    }
    // 0x800D65A4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800D65A8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800D65AC: jal         0x80022368
    // 0x800D65B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    syDebugMakeMeterCamera(rdram, ctx);
        goto after_1;
    // 0x800D65B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800D65B4:
    // 0x800D65B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D65B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D65BC: jr          $ra
    // 0x800D65C0: nop

    return;
    // 0x800D65C0: nop

;}
RECOMP_FUNC void ftCommonRebirthWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D51C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013D520: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D524: addiu       $t6, $zero, 0x106
    ctx->r14 = ADD32(0, 0X106);
    // 0x8013D528: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013D52C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8013D530: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013D534: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013D538: jal         0x800E6F24
    // 0x8013D53C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D53C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013D540: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013D544: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D548: lbu         $t1, 0x18E($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013D54C: lbu         $t8, 0x191($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X191);
    // 0x8013D550: ori         $t4, $t1, 0x80
    ctx->r12 = ctx->r9 | 0X80;
    // 0x8013D554: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x8013D558: sb          $t4, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r12;
    // 0x8013D55C: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x8013D560: sb          $t9, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r25;
    // 0x8013D564: sb          $t5, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r13;
    // 0x8013D568: lwc1        $f4, -0x3FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3FA4);
    // 0x8013D56C: swc1        $f4, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f4.u32l;
    // 0x8013D570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D574: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013D578: jr          $ra
    // 0x8013D57C: nop

    return;
    // 0x8013D57C: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sc1PGameSpawnEnemyTeamNext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E18C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018E190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018E198: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8018E19C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E1A0: addiu       $v1, $v1, 0x2FA8
    ctx->r3 = ADD32(ctx->r3, 0X2FA8);
    // 0x8018E1A4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8018E1A8: lw          $t6, 0x9D0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X9D0);
    // 0x8018E1AC: lw          $a3, 0x9C8($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X9C8);
    // 0x8018E1B0: lbu         $s0, 0xD($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0XD);
    // 0x8018E1B4: bne         $v0, $zero, L_8018E1CC
    if (ctx->r2 != 0) {
        // 0x8018E1B8: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_8018E1CC;
    }
    // 0x8018E1B8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8018E1BC: jal         0x8013D8B0
    // 0x8018E1C0: nop

    ftCommonSleepSetStatus(rdram, ctx);
        goto after_0;
    // 0x8018E1C0: nop

    after_0:
    // 0x8018E1C4: b           L_8018E588
    // 0x8018E1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018E588;
    // 0x8018E1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E1CC:
    // 0x8018E1CC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8018E1D0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8018E1D4: jal         0x800D78E8
    // 0x8018E1D8: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    ftManagerDestroyFighter(rdram, ctx);
        goto after_1;
    // 0x8018E1D8: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    after_1:
    // 0x8018E1DC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018E1E0: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x8018E1E4: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x8018E1E8: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x8018E1EC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8018E1F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018E1F4: addu        $t0, $t0, $s0
    ctx->r8 = ADD32(ctx->r8, ctx->r16);
    // 0x8018E1F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018E1FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018E200: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8018E204: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x8018E208: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x8018E20C: sb          $zero, 0x2B($t9)
    MEM_B(0X2B, ctx->r25) = 0;
    // 0x8018E210: lbu         $v0, 0x17($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X17);
    // 0x8018E214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E218: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018E21C: beq         $v0, $at, L_8018E254
    if (ctx->r2 == ctx->r1) {
        // 0x8018E220: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8018E254;
    }
    // 0x8018E220: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018E224: beq         $v0, $at, L_8018E334
    if (ctx->r2 == ctx->r1) {
        // 0x8018E228: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018E334;
    }
    // 0x8018E228: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018E22C: beq         $v0, $at, L_8018E2F8
    if (ctx->r2 == ctx->r1) {
        // 0x8018E230: lui         $t3, 0x8019
        ctx->r11 = S32(0X8019 << 16);
            goto L_8018E2F8;
    }
    // 0x8018E230: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018E234: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E238: lbu         $v0, 0x2FA9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2FA9);
    // 0x8018E23C: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018E240: addiu       $t3, $t3, 0x2FE0
    ctx->r11 = ADD32(ctx->r11, 0X2FE0);
    // 0x8018E244: sll         $t2, $s0, 5
    ctx->r10 = S32(ctx->r16 << 5);
    // 0x8018E248: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x8018E24C: b           L_8018E388
    // 0x8018E250: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8018E388;
    // 0x8018E250: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8018E254:
    // 0x8018E254: lbu         $t4, 0x2FA9($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2FA9);
    // 0x8018E258: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018E25C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8018E260: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018E264: lbu         $t5, 0x2FB0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2FB0);
    // 0x8018E268: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8018E26C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018E270: sb          $t5, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r13;
    // 0x8018E274: lbu         $t8, 0x14($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X14);
    // 0x8018E278: bnel        $t8, $at, L_8018E2A8
    if (ctx->r24 != ctx->r1) {
        // 0x8018E27C: lw          $t6, 0x0($t1)
        ctx->r14 = MEM_W(ctx->r9, 0X0);
            goto L_8018E2A8;
    }
    goto skip_0;
    // 0x8018E27C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    skip_0:
    // 0x8018E280: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018E284: lbu         $t2, 0x15($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X15);
    // 0x8018E288: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018E28C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8018E290: lbu         $t3, 0x26($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X26);
    // 0x8018E294: bnel        $t2, $t3, L_8018E2A8
    if (ctx->r10 != ctx->r11) {
        // 0x8018E298: lw          $t6, 0x0($t1)
        ctx->r14 = MEM_W(ctx->r9, 0X0);
            goto L_8018E2A8;
    }
    goto skip_1;
    // 0x8018E298: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    skip_1:
    // 0x8018E29C: b           L_8018E2B0
    // 0x8018E2A0: sb          $t4, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r12;
        goto L_8018E2B0;
    // 0x8018E2A0: sb          $t4, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r12;
    // 0x8018E2A4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
L_8018E2A8:
    // 0x8018E2A8: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x8018E2AC: sb          $zero, 0x27($t5)
    MEM_B(0X27, ctx->r13) = 0;
L_8018E2B0:
    // 0x8018E2B0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8018E2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E2B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8018E2BC: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8018E2C0: lbu         $a1, 0x26($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X26);
    // 0x8018E2C4: jal         0x8010FF78
    // 0x8018E2C8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    ifCommonPlayerStockSetLUT(rdram, ctx);
        goto after_2;
    // 0x8018E2C8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8018E2CC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E2D0: lbu         $v0, 0x2FA9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2FA9);
    // 0x8018E2D4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018E2D8: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018E2DC: addiu       $t2, $t2, 0x2FE0
    ctx->r10 = ADD32(ctx->r10, 0X2FE0);
    // 0x8018E2E0: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x8018E2E4: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x8018E2E8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E2EC: addu        $a3, $t9, $t2
    ctx->r7 = ADD32(ctx->r25, ctx->r10);
    // 0x8018E2F0: b           L_8018E388
    // 0x8018E2F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8018E388;
    // 0x8018E2F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8018E2F8:
    // 0x8018E2F8: lbu         $t3, 0x2FA9($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X2FA9);
    // 0x8018E2FC: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018E300: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8018E304: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018E308: lbu         $t4, 0x2FB0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2FB0);
    // 0x8018E30C: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x8018E310: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E314: sb          $t4, 0x23($t5)
    MEM_B(0X23, ctx->r13) = ctx->r12;
    // 0x8018E318: lbu         $v0, 0x2FA9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2FA9);
    // 0x8018E31C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E320: addiu       $t8, $t8, 0x2FE0
    ctx->r24 = ADD32(ctx->r24, 0X2FE0);
    // 0x8018E324: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x8018E328: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8018E32C: b           L_8018E388
    // 0x8018E330: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8018E388;
    // 0x8018E330: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8018E334:
    // 0x8018E334: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E338: lbu         $v0, 0x2FA9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2FA9);
    // 0x8018E33C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018E340: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x8018E344: bne         $v0, $at, L_8018E36C
    if (ctx->r2 != ctx->r1) {
        // 0x8018E348: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8018E36C;
    }
    // 0x8018E348: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018E34C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018E350: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8018E354: lbu         $t3, 0xD75($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XD75);
    // 0x8018E358: addiu       $t2, $t2, 0x2FE0
    ctx->r10 = ADD32(ctx->r10, 0X2FE0);
    // 0x8018E35C: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x8018E360: addu        $a3, $t9, $t2
    ctx->r7 = ADD32(ctx->r25, ctx->r10);
    // 0x8018E364: b           L_8018E388
    // 0x8018E368: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
        goto L_8018E388;
    // 0x8018E368: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
L_8018E36C:
    // 0x8018E36C: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018E370: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8018E374: lbu         $t5, 0x2800($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2800);
    // 0x8018E378: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018E37C: addiu       $t4, $t4, 0x2FE0
    ctx->r12 = ADD32(ctx->r12, 0X2FE0);
    // 0x8018E380: addu        $a3, $t6, $t4
    ctx->r7 = ADD32(ctx->r14, ctx->r12);
    // 0x8018E384: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
L_8018E388:
    // 0x8018E388: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8018E38C: sw          $v1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r3;
    // 0x8018E390: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8018E394: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E398: addiu       $t9, $t9, 0x6DD0
    ctx->r25 = ADD32(ctx->r25, 0X6DD0);
    // 0x8018E39C: sb          $t7, 0x2FA9($at)
    MEM_B(0X2FA9, ctx->r1) = ctx->r15;
    // 0x8018E3A0: addiu       $t6, $t9, 0x3C
    ctx->r14 = ADD32(ctx->r25, 0X3C);
    // 0x8018E3A4: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
L_8018E3A8:
    // 0x8018E3A8: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8018E3AC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018E3B0: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018E3B4: sw          $t3, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r11;
    // 0x8018E3B8: lw          $t2, -0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, -0X8);
    // 0x8018E3BC: sw          $t2, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r10;
    // 0x8018E3C0: lw          $t3, -0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, -0X4);
    // 0x8018E3C4: bne         $t9, $t6, L_8018E3A8
    if (ctx->r25 != ctx->r14) {
        // 0x8018E3C8: sw          $t3, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r11;
            goto L_8018E3A8;
    }
    // 0x8018E3C8: sw          $t3, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r11;
    // 0x8018E3CC: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8018E3D0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8018E3D4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x8018E3D8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8018E3DC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8018E3E0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x8018E3E4: lbu         $t7, 0x23($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X23);
    // 0x8018E3E8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8018E3EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8018E3F0: jal         0x8018D45C
    // 0x8018E3F4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    sc1PGameGetRandomStartPosition(rdram, ctx);
        goto after_3;
    // 0x8018E3F4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    after_3:
    // 0x8018E3F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018E3FC: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8018E400: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E404: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E408: lh          $t6, 0x6C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6C);
    // 0x8018E40C: lh          $t9, 0x74($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X74);
    // 0x8018E410: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018E414: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018E418: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8018E41C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018E420: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8018E424: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018E428: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E42C: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x8018E430: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8018E434: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E438: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018E43C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8018E440: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018E444: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8018E448: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018E44C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8018E450: bc1f        L_8018E460
    if (!c1cs) {
        // 0x8018E454: swc1        $f10, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
            goto L_8018E460;
    }
    // 0x8018E454: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8018E458: b           L_8018E464
    // 0x8018E45C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
        goto L_8018E464;
    // 0x8018E45C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
L_8018E460:
    // 0x8018E460: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
L_8018E464:
    // 0x8018E464: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8018E468: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x8018E46C: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
    // 0x8018E470: sb          $s0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r16;
    // 0x8018E474: sb          $t4, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r12;
    // 0x8018E478: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x8018E47C: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x8018E480: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8018E484: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8018E488: beql        $at, $zero, L_8018E49C
    if (ctx->r1 == 0) {
        // 0x8018E48C: sb          $t8, 0x5A($sp)
        MEM_B(0X5A, ctx->r29) = ctx->r24;
            goto L_8018E49C;
    }
    goto skip_2;
    // 0x8018E48C: sb          $t8, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r24;
    skip_2:
    // 0x8018E490: b           L_8018E49C
    // 0x8018E494: sb          $t9, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r25;
        goto L_8018E49C;
    // 0x8018E494: sb          $t9, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r25;
    // 0x8018E498: sb          $t8, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r24;
L_8018E49C:
    // 0x8018E49C: lbu         $t2, 0x26($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X26);
    // 0x8018E4A0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8018E4A4: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8018E4A8: sb          $t2, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r10;
    // 0x8018E4AC: lbu         $t3, 0x27($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X27);
    // 0x8018E4B0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8018E4B4: addiu       $t8, $t8, 0x5228
    ctx->r24 = ADD32(ctx->r24, 0X5228);
    // 0x8018E4B8: sb          $t3, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r11;
    // 0x8018E4BC: lbu         $t4, 0x21($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X21);
    // 0x8018E4C0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8018E4C4: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x8018E4C8: sb          $t4, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = ctx->r12;
    // 0x8018E4CC: lbu         $t5, 0x20($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X20);
    // 0x8018E4D0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8018E4D4: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x8018E4D8: sb          $t5, 0x5E($sp)
    MEM_B(0X5E, ctx->r29) = ctx->r13;
    // 0x8018E4DC: lb          $t7, 0x2B($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X2B);
    // 0x8018E4E0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8018E4E4: lw          $t5, 0xC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XC);
    // 0x8018E4E8: sb          $t7, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r15;
    // 0x8018E4EC: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x8018E4F0: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8018E4F4: lw          $t2, 0x14($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X14);
    // 0x8018E4F8: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8018E4FC: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x8018E500: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8018E504: sb          $t5, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r13;
    // 0x8018E508: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8018E50C: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x8018E510: ori         $t5, $t6, 0x80
    ctx->r13 = ctx->r14 | 0X80;
    // 0x8018E514: andi        $t7, $t5, 0xDF
    ctx->r15 = ctx->r13 & 0XDF;
    // 0x8018E518: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x8018E51C: or          $t2, $t4, $t7
    ctx->r10 = ctx->r12 | ctx->r15;
    // 0x8018E520: sb          $t5, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r13;
    // 0x8018E524: sb          $t2, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r10;
    // 0x8018E528: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x8018E52C: sb          $t3, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r11;
    // 0x8018E530: jal         0x800D7F3C
    // 0x8018E534: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    ftManagerMakeFighter(rdram, ctx);
        goto after_4;
    // 0x8018E534: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x8018E538: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8018E53C: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x8018E540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018E548: jal         0x800E7C4C
    // 0x8018E54C: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_5;
    // 0x8018E54C: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    after_5:
    // 0x8018E550: jal         0x800E7F68
    // 0x8018E554: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_6;
    // 0x8018E554: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x8018E558: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8018E55C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8018E560: lbu         $t9, 0x18($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X18);
    // 0x8018E564: jal         0x8010F840
    // 0x8018E568: sb          $t9, 0x1D1($a0)
    MEM_B(0X1D1, ctx->r4) = ctx->r25;
    ifCommonPlayerDamageStopBreakAnim(rdram, ctx);
        goto after_7;
    // 0x8018E568: sb          $t9, 0x1D1($a0)
    MEM_B(0X1D1, ctx->r4) = ctx->r25;
    after_7:
    // 0x8018E56C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8018E570: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8018E574: lwc1        $f4, 0x860($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X860);
    // 0x8018E578: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x8018E57C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E580: swc1        $f8, 0x860($a2)
    MEM_W(0X860, ctx->r6) = ctx->f8.u32l;
    // 0x8018E584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E588:
    // 0x8018E588: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018E58C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8018E590: jr          $ra
    // 0x8018E594: nop

    return;
    // 0x8018E594: nop

;}
RECOMP_FUNC void func_80026738_27338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002673C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026740: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80026744: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80026748: jal         0x80030350
    // 0x8002674C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8002674C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026750: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80026754: addiu       $a3, $a3, -0x1230
    ctx->r7 = ADD32(ctx->r7, -0X1230);
    // 0x80026758: lw          $v1, 0x40($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X40);
    // 0x8002675C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80026760: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80026764: beq         $v1, $zero, L_800267DC
    if (ctx->r3 == 0) {
        // 0x80026768: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800267DC;
    }
    // 0x80026768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002676C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_80026770:
    // 0x80026770: beq         $v1, $t0, L_80026784
    if (ctx->r3 == ctx->r8) {
        // 0x80026774: lw          $a2, 0x0($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X0);
            goto L_80026784;
    }
    // 0x80026774: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80026778: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8002677C: bnel        $t0, $t6, L_800267D4
    if (ctx->r8 != ctx->r14) {
        // 0x80026780: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800267D4;
    }
    goto skip_0;
    // 0x80026780: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    skip_0:
L_80026784:
    // 0x80026784: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x80026788: sh          $zero, 0x10($v1)
    MEM_H(0X10, ctx->r3) = 0;
    // 0x8002678C: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x80026790: beq         $a0, $zero, L_800267A4
    if (ctx->r4 == 0) {
        // 0x80026794: nop
    
            goto L_800267A4;
    }
    // 0x80026794: nop

    // 0x80026798: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x8002679C: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x800267A0: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
L_800267A4:
    // 0x800267A4: beql        $a1, $zero, L_800267BC
    if (ctx->r5 == 0) {
        // 0x800267A8: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_800267BC;
    }
    goto skip_1;
    // 0x800267A8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800267AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800267B0: b           L_800267C0
    // 0x800267B4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_800267C0;
    // 0x800267B4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800267B8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_800267BC:
    // 0x800267BC: sw          $t8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r24;
L_800267C0:
    // 0x800267C0: lw          $t9, 0x38($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X38);
    // 0x800267C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800267C8: b           L_800267D4
    // 0x800267CC: sw          $v1, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r3;
        goto L_800267D4;
    // 0x800267CC: sw          $v1, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r3;
    // 0x800267D0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800267D4:
    // 0x800267D4: bne         $a2, $zero, L_80026770
    if (ctx->r6 != 0) {
        // 0x800267D8: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80026770;
    }
    // 0x800267D8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_800267DC:
    // 0x800267DC: jal         0x80030350
    // 0x800267E0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800267E0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x800267E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800267E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800267EC: jr          $ra
    // 0x800267F0: nop

    return;
    // 0x800267F0: nop

;}
RECOMP_FUNC void ftDonkeySpecialNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B328: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015B32C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015B330: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015B334: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015B338: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B33C: jal         0x800E6F24
    // 0x8015B340: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B340: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015B344: jal         0x8015B244
    // 0x8015B348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x8015B348: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015B34C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B354: jr          $ra
    // 0x8015B358: nop

    return;
    // 0x8015B358: nop

;}
RECOMP_FUNC void ftCommonDashProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ECB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013ECB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013ECB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013ECBC: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013ECC0: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8013ECC4: lwc1        $f6, 0x70($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X70);
    // 0x8013ECC8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013ECCC: nop

    // 0x8013ECD0: bc1f        L_8013ECE8
    if (!c1cs) {
        // 0x8013ECD4: nop
    
            goto L_8013ECE8;
    }
    // 0x8013ECD4: nop

    // 0x8013ECD8: jal         0x800DDEE8
    // 0x8013ECDC: nop

    mpCommonProcFighterOnCliffEdge(rdram, ctx);
        goto after_0;
    // 0x8013ECDC: nop

    after_0:
    // 0x8013ECE0: b           L_8013ECF4
    // 0x8013ECE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013ECF4;
    // 0x8013ECE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013ECE8:
    // 0x8013ECE8: jal         0x800DDEC4
    // 0x8013ECEC: nop

    mpCommonSetFighterFallOnGroundBreak(rdram, ctx);
        goto after_1;
    // 0x8013ECEC: nop

    after_1:
    // 0x8013ECF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013ECF4:
    // 0x8013ECF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013ECF8: jr          $ra
    // 0x8013ECFC: nop

    return;
    // 0x8013ECFC: nop

;}
RECOMP_FUNC void efManagerLoseKirbyStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103DF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103E00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80103E04: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80103E08: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80103E0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80103E10: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x80103E14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80103E18: lwc1        $f6, 0xA24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA24);
    // 0x80103E1C: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80103E20: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80103E24: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80103E28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80103E2C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80103E30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80103E34: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80103E38: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x80103E3C: lwc1        $f16, 0x18($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80103E40: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80103E44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80103E48: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x80103E4C: lwc1        $f6, 0x1C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80103E50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80103E54: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80103E58: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80103E5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80103E60: swc1        $f18, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f18.u32l;
    // 0x80103E64: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80103E68: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80103E6C: nop

    // 0x80103E70: bc1fl       L_80103E80
    if (!c1cs) {
        // 0x80103E74: lh          $v1, 0x20($a2)
        ctx->r3 = MEM_H(ctx->r6, 0X20);
            goto L_80103E80;
    }
    goto skip_0;
    // 0x80103E74: lh          $v1, 0x20($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X20);
    skip_0:
    // 0x80103E78: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
    // 0x80103E7C: lh          $v1, 0x20($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X20);
L_80103E80:
    // 0x80103E80: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80103E84: bgtz        $v1, L_80103EC4
    if (SIGNED(ctx->r3) > 0) {
        // 0x80103E88: sh          $t8, 0x20($a2)
        MEM_H(0X20, ctx->r6) = ctx->r24;
            goto L_80103EC4;
    }
    // 0x80103E88: sh          $t8, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r24;
    // 0x80103E8C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80103E90: jal         0x800269C0
    // 0x80103E94: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80103E94: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80103E98: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80103E9C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80103EA0: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80103EA4: jal         0x80102070
    // 0x80103EA8: lh          $a1, 0x22($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X22);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80103EA8: lh          $a1, 0x22($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X22);
    after_1:
    // 0x80103EAC: jal         0x800FD4F8
    // 0x80103EB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x80103EB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80103EB4: jal         0x80009A84
    // 0x80103EB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80103EB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80103EBC: b           L_80103F6C
    // 0x80103EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103F6C;
    // 0x80103EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103EC4:
    // 0x80103EC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80103EC8: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x80103ECC: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80103ED0: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80103ED4: lh          $t9, 0x76($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X76);
    // 0x80103ED8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80103EDC: nop

    // 0x80103EE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80103EE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80103EE8: nop

    // 0x80103EEC: bc1t        L_80103F58
    if (c1cs) {
        // 0x80103EF0: nop
    
            goto L_80103F58;
    }
    // 0x80103EF0: nop

    // 0x80103EF4: lh          $t0, 0x78($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X78);
    // 0x80103EF8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80103EFC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80103F00: nop

    // 0x80103F04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80103F08: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80103F0C: nop

    // 0x80103F10: bc1t        L_80103F58
    if (c1cs) {
        // 0x80103F14: nop
    
            goto L_80103F58;
    }
    // 0x80103F14: nop

    // 0x80103F18: lh          $t1, 0x7A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X7A);
    // 0x80103F1C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80103F20: nop

    // 0x80103F24: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80103F28: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80103F2C: nop

    // 0x80103F30: bc1t        L_80103F58
    if (c1cs) {
        // 0x80103F34: nop
    
            goto L_80103F58;
    }
    // 0x80103F34: nop

    // 0x80103F38: lh          $t2, 0x74($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X74);
    // 0x80103F3C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80103F40: nop

    // 0x80103F44: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80103F48: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80103F4C: nop

    // 0x80103F50: bc1fl       L_80103F6C
    if (!c1cs) {
        // 0x80103F54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103F6C;
    }
    goto skip_1;
    // 0x80103F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80103F58:
    // 0x80103F58: jal         0x800FD4F8
    // 0x80103F5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_4;
    // 0x80103F5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80103F60: jal         0x80009A84
    // 0x80103F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80103F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80103F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103F6C:
    // 0x80103F6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103F70: jr          $ra
    // 0x80103F74: nop

    return;
    // 0x80103F74: nop

;}
RECOMP_FUNC void ftCommonKneeBendGetInputTypeRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F53C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F544: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8013F548: slti        $at, $t6, 0x2D
    ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
    // 0x8013F54C: bne         $at, $zero, L_8013F56C
    if (ctx->r1 != 0) {
        // 0x8013F550: nop
    
            goto L_8013F56C;
    }
    // 0x8013F550: nop

    // 0x8013F554: lbu         $t7, 0x269($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X269);
    // 0x8013F558: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8013F55C: beq         $at, $zero, L_8013F56C
    if (ctx->r1 == 0) {
        // 0x8013F560: nop
    
            goto L_8013F56C;
    }
    // 0x8013F560: nop

    // 0x8013F564: b           L_8013F588
    // 0x8013F568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F588;
    // 0x8013F568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F56C:
    // 0x8013F56C: jal         0x8013F450
    // 0x8013F570: nop

    ftCommonKneeBendCheckButtonTap(rdram, ctx);
        goto after_0;
    // 0x8013F570: nop

    after_0:
    // 0x8013F574: beql        $v0, $zero, L_8013F588
    if (ctx->r2 == 0) {
        // 0x8013F578: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013F588;
    }
    goto skip_0;
    // 0x8013F578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013F57C: b           L_8013F588
    // 0x8013F580: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8013F588;
    // 0x8013F580: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8013F584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F588:
    // 0x8013F588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F58C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F590: jr          $ra
    // 0x8013F594: nop

    return;
    // 0x8013F594: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801370BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801370C0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801370C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801370C8: lwc1        $f26, -0x7AC8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X7AC8);
    // 0x801370CC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801370D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801370D4: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x801370D8: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x801370DC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x801370E0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x801370E4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x801370E8: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x801370EC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801370F0: lwc1        $f24, -0x7AC4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X7AC4);
    // 0x801370F4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x801370F8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x801370FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80137100: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137104: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80137108: lui         $s4, 0x0
    ctx->r20 = S32(0X0 << 16);
    // 0x8013710C: lui         $s5, 0x8001
    ctx->r21 = S32(0X8001 << 16);
    // 0x80137110: lui         $s6, 0x0
    ctx->r22 = S32(0X0 << 16);
    // 0x80137114: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80137118: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x8013711C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80137120: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80137124: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80137128: addiu       $fp, $fp, -0x776C
    ctx->r30 = ADD32(ctx->r30, -0X776C);
    // 0x8013712C: addiu       $s7, $s7, 0x6FC8
    ctx->r23 = ADD32(ctx->r23, 0X6FC8);
    // 0x80137130: addiu       $s6, $s6, 0x408
    ctx->r22 = ADD32(ctx->r22, 0X408);
    // 0x80137134: addiu       $s5, $s5, 0x4768
    ctx->r21 = ADD32(ctx->r21, 0X4768);
    // 0x80137138: addiu       $s4, $s4, 0x568
    ctx->r20 = ADD32(ctx->r20, 0X568);
    // 0x8013713C: addiu       $s3, $s3, -0x7368
    ctx->r19 = ADD32(ctx->r19, -0X7368);
    // 0x80137140: lwc1        $f20, -0x7AC0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7AC0);
    // 0x80137144: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80137148: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x8013714C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80137150:
    // 0x80137150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137154: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80137158: jal         0x80009968
    // 0x8013715C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013715C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_0:
    // 0x80137160: lw          $t6, 0x1C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X1C);
    // 0x80137164: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013716C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137170: jal         0x8000F120
    // 0x80137174: addu        $a1, $t6, $s4
    ctx->r5 = ADD32(ctx->r14, ctx->r20);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80137174: addu        $a1, $t6, $s4
    ctx->r5 = ADD32(ctx->r14, ctx->r20);
    after_1:
    // 0x80137178: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013717C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80137180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137184: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137188: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8013718C: jal         0x80009DF4
    // 0x80137190: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80137190: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x80137194: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80137198: lw          $t8, 0x1C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X1C);
    // 0x8013719C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801371A0: jal         0x8000F8F4
    // 0x801371A4: addu        $a1, $t8, $s6
    ctx->r5 = ADD32(ctx->r24, ctx->r22);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x801371A4: addu        $a1, $t8, $s6
    ctx->r5 = ADD32(ctx->r24, ctx->r22);
    after_3:
    // 0x801371A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801371AC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x801371B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801371B4: jal         0x80008188
    // 0x801371B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x801371B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801371BC: jal         0x8000DF34
    // 0x801371C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x801371C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801371C4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x801371C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801371CC: bnel        $s1, $t9, L_801371F4
    if (ctx->r17 != ctx->r25) {
        // 0x801371D0: lw          $t3, 0x74($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X74);
            goto L_801371F4;
    }
    goto skip_0;
    // 0x801371D0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x801371D4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x801371D8: swc1        $f24, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f24.u32l;
    // 0x801371DC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801371E0: swc1        $f20, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f20.u32l;
    // 0x801371E4: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801371E8: b           L_80137208
    // 0x801371EC: swc1        $f22, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f22.u32l;
        goto L_80137208;
    // 0x801371EC: swc1        $f22, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f22.u32l;
    // 0x801371F0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
L_801371F4:
    // 0x801371F4: swc1        $f26, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f26.u32l;
    // 0x801371F8: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x801371FC: swc1        $f20, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f20.u32l;
    // 0x80137200: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80137204: swc1        $f22, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f22.u32l;
L_80137208:
    // 0x80137208: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013720C: bnel        $s1, $at, L_80137150
    if (ctx->r17 != ctx->r1) {
        // 0x80137210: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80137150;
    }
    goto skip_1;
    // 0x80137210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80137214: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80137218: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8013721C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80137220: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80137224: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80137228: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8013722C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80137230: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80137234: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80137238: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8013723C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80137240: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80137244: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80137248: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8013724C: jr          $ra
    // 0x80137250: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80137250: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mnPlayers1PTrainingSetGateLUTAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133CA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80133CAC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133CB4: addiu       $t7, $t7, -0x7D00
    ctx->r15 = ADD32(ctx->r15, -0X7D00);
    // 0x80133CB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133CBC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133CC0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80133CC4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133CC8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133CCC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133CD0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133CD4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80133CD8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133CDC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133CE0: lw          $a1, -0x776C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X776C);
    // 0x80133CE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133CE8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80133CEC: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80133CF0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80133CF4: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80133CF8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80133CFC: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80133D00: jal         0x80132C24
    // 0x80133D04: lw          $a0, -0x7A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A90);
    mnPlayers1PTrainingSetGateLUT(rdram, ctx);
        goto after_0;
    // 0x80133D04: lw          $a0, -0x7A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A90);
    after_0:
    // 0x80133D08: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80133D0C: lw          $a1, -0x7768($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7768);
    // 0x80133D10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133D14: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80133D18: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80133D1C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80133D20: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80133D24: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80133D28: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80133D2C: jal         0x80132C24
    // 0x80133D30: lw          $a0, -0x7A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A90);
    mnPlayers1PTrainingSetGateLUT(rdram, ctx);
        goto after_1;
    // 0x80133D30: lw          $a0, -0x7A90($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A90);
    after_1:
    // 0x80133D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133D38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80133D3C: jr          $ra
    // 0x80133D40: nop

    return;
    // 0x80133D40: nop

;}
RECOMP_FUNC void itMapTestLRWallCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017356C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173574: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80173578: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017357C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80173580: addiu       $a1, $a1, 0x3480
    ctx->r5 = ADD32(ctx->r5, 0X3480);
    // 0x80173584: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80173588: jal         0x800DA034
    // 0x8017358C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x8017358C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x80173590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173598: jr          $ra
    // 0x8017359C: nop

    return;
    // 0x8017359C: nop

;}
RECOMP_FUNC void unref_80006AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006B00: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006B04: addiu       $a0, $a0, 0x54C8
    ctx->r4 = ADD32(ctx->r4, 0X54C8);
    // 0x80006B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006B0C: jal         0x80030000
    // 0x80006B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80006B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80006B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006B1C: jr          $ra
    // 0x80006B20: nop

    return;
    // 0x80006B20: nop

;}
RECOMP_FUNC void func_ovl8_8037A62C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A62C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037A630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037A634: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037A638: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x8037A63C: sh          $a1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r5;
    // 0x8037A640: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8037A644: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8037A648: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // 0x8037A64C: sh          $t7, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r15;
    // 0x8037A650: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8037A654: sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // 0x8037A658: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    // 0x8037A65C: subu        $t9, $t8, $a1
    ctx->r25 = SUB32(ctx->r24, ctx->r5);
    // 0x8037A660: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x8037A664: jal         0x803787C0
    // 0x8037A668: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_ovl8_803787C0(rdram, ctx);
        goto after_0;
    // 0x8037A668: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_0:
    // 0x8037A66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037A670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037A674: jr          $ra
    // 0x8037A678: nop

    return;
    // 0x8037A678: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeSpotlightCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801337BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801337C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801337C4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801337C8: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x801337CC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801337D0: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x801337D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801337D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801337DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801337E0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801337E4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801337E8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801337EC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801337F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801337F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801337F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801337FC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133800: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133804: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133808: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013380C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133810: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133814: jal         0x8000B93C
    // 0x80133818: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133818: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013381C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133820: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133824: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133828: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013382C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133830: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133834: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133838: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013383C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133840: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80133844: jal         0x80007080
    // 0x80133848: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133848: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013384C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80133850: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80133854: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x80133858: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013385C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133860: jr          $ra
    // 0x80133864: nop

    return;
    // 0x80133864: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetCharacterID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131F60: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80131F64: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80131F68: beq         $a0, $at, L_80131FAC
    if (ctx->r4 == ctx->r1) {
        // 0x80131F6C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131FAC;
    }
    // 0x80131F6C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131F70: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80131F74: beq         $a0, $at, L_80131F9C
    if (ctx->r4 == ctx->r1) {
        // 0x80131F78: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_80131F9C;
    }
    // 0x80131F78: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80131F7C: beq         $a0, $at, L_80131F94
    if (ctx->r4 == ctx->r1) {
        // 0x80131F80: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80131F94;
    }
    // 0x80131F80: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80131F84: beq         $a0, $at, L_80131FA4
    if (ctx->r4 == ctx->r1) {
        // 0x80131F88: nop
    
            goto L_80131FA4;
    }
    // 0x80131F88: nop

    // 0x80131F8C: b           L_80131FB4
    // 0x80131F90: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
        goto L_80131FB4;
    // 0x80131F90: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
L_80131F94:
    // 0x80131F94: jr          $ra
    // 0x80131F98: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x80131F98: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_80131F9C:
    // 0x80131F9C: jr          $ra
    // 0x80131FA0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80131FA0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80131FA4:
    // 0x80131FA4: jr          $ra
    // 0x80131FA8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80131FA8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80131FAC:
    // 0x80131FAC: jr          $ra
    // 0x80131FB0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80131FB0: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80131FB4:
    // 0x80131FB4: bne         $at, $zero, L_80131FC4
    if (ctx->r1 != 0) {
        // 0x80131FB8: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_80131FC4;
    }
    // 0x80131FB8: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x80131FBC: bne         $at, $zero, L_80131FCC
    if (ctx->r1 != 0) {
        // 0x80131FC0: addiu       $v0, $v1, -0x41
        ctx->r2 = ADD32(ctx->r3, -0X41);
            goto L_80131FCC;
    }
    // 0x80131FC0: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
L_80131FC4:
    // 0x80131FC4: jr          $ra
    // 0x80131FC8: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80131FC8: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80131FCC:
    // 0x80131FCC: jr          $ra
    // 0x80131FD0: nop

    return;
    // 0x80131FD0: nop

;}
RECOMP_FUNC void efManagerFoxReflectorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100ED4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100ED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100EDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100EE0: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80100EE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80100EE8: jal         0x8000DF34
    // 0x80100EEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80100EEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80100EF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80100EF4: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80100EF8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80100EFC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80100F00: nop

    // 0x80100F04: bc1fl       L_80100F6C
    if (!c1cs) {
        // 0x80100F08: lw          $a1, 0x1C($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X1C);
            goto L_80100F6C;
    }
    goto skip_0;
    // 0x80100F08: lw          $a1, 0x1C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X1C);
    skip_0:
    // 0x80100F0C: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x80100F10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80100F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100F18: beq         $v0, $zero, L_80100F40
    if (ctx->r2 == 0) {
        // 0x80100F1C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80100F40;
    }
    // 0x80100F1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80100F20: beq         $v0, $at, L_80100F68
    if (ctx->r2 == ctx->r1) {
        // 0x80100F24: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80100F68;
    }
    // 0x80100F24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80100F28: beq         $v0, $at, L_80100F40
    if (ctx->r2 == ctx->r1) {
        // 0x80100F2C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80100F40;
    }
    // 0x80100F2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80100F30: beq         $v0, $at, L_80100F50
    if (ctx->r2 == ctx->r1) {
        // 0x80100F34: nop
    
            goto L_80100F50;
    }
    // 0x80100F34: nop

    // 0x80100F38: b           L_80100F6C
    // 0x80100F3C: lw          $a1, 0x1C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X1C);
        goto L_80100F6C;
    // 0x80100F3C: lw          $a1, 0x1C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X1C);
L_80100F40:
    // 0x80100F40: jal         0x80100E84
    // 0x80100F44: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    efManagerFoxReflectorSetAnimID(rdram, ctx);
        goto after_1;
    // 0x80100F44: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80100F48: b           L_80100F68
    // 0x80100F4C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
        goto L_80100F68;
    // 0x80100F4C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_80100F50:
    // 0x80100F50: jal         0x800FD4F8
    // 0x80100F54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x80100F54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80100F58: jal         0x80009A84
    // 0x80100F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80100F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80100F60: b           L_80100F94
    // 0x80100F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80100F94;
    // 0x80100F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80100F68:
    // 0x80100F68: lw          $a1, 0x1C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X1C);
L_80100F6C:
    // 0x80100F6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80100F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100F74: beql        $a1, $at, L_80100F94
    if (ctx->r5 == ctx->r1) {
        // 0x80100F78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80100F94;
    }
    goto skip_1;
    // 0x80100F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80100F7C: jal         0x80100E84
    // 0x80100F80: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    efManagerFoxReflectorSetAnimID(rdram, ctx);
        goto after_4;
    // 0x80100F80: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x80100F84: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80100F88: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80100F8C: sw          $t6, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r14;
    // 0x80100F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80100F94:
    // 0x80100F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100F9C: jr          $ra
    // 0x80100FA0: nop

    return;
    // 0x80100FA0: nop

;}
RECOMP_FUNC void mnCharactersSetFighterPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801324D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801324D4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x801324D8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801324DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324E0: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x801324E4: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801324E8: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x801324EC: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801324F0: jr          $ra
    // 0x801324F4: swc1        $f0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f0.u32l;
    return;
    // 0x801324F4: swc1        $f0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_ovl2_800FB31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB31C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB320: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FB324: lw          $t3, 0x1384($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1384);
    // 0x800FB328: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800FB32C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FB330: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x800FB334: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800FB338: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800FB33C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800FB340: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800FB344: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800FB348: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800FB34C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800FB350: blez        $t3, L_800FB524
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800FB354: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800FB524;
    }
    // 0x800FB354: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FB358: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800FB35C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800FB360: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800FB364: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800FB368: addiu       $s4, $s4, 0x136C
    ctx->r20 = ADD32(ctx->r20, 0X136C);
    // 0x800FB36C: addiu       $s6, $s6, 0x1370
    ctx->r22 = ADD32(ctx->r22, 0X1370);
    // 0x800FB370: addiu       $s7, $s7, 0x1378
    ctx->r23 = ADD32(ctx->r23, 0X1378);
    // 0x800FB374: addiu       $fp, $fp, 0x1374
    ctx->r30 = ADD32(ctx->r30, 0X1374);
    // 0x800FB378: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800FB37C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FB380: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800FB384: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800FB388:
    // 0x800FB388: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x800FB38C: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x800FB390: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800FB394: addu        $v0, $t2, $s5
    ctx->r2 = ADD32(ctx->r10, ctx->r21);
    // 0x800FB398: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x800FB39C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800FB3A0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800FB3A4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800FB3A8: addu        $t6, $a3, $v1
    ctx->r14 = ADD32(ctx->r7, ctx->r3);
    // 0x800FB3AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800FB3B0: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800FB3B4: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800FB3B8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800FB3BC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800FB3C0: lhu         $t1, -0x2($t6)
    ctx->r9 = MEM_HU(ctx->r14, -0X2);
    // 0x800FB3C4: blez        $t3, L_800FB43C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800FB3C8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FB43C;
    }
    // 0x800FB3C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800FB3CC:
    // 0x800FB3CC: beq         $s0, $a0, L_800FB42C
    if (ctx->r16 == ctx->r4) {
        // 0x800FB3D0: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800FB42C;
    }
    // 0x800FB3D0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800FB3D4: addu        $v1, $t2, $t7
    ctx->r3 = ADD32(ctx->r10, ctx->r15);
    // 0x800FB3D8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800FB3DC: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800FB3E0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800FB3E4: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800FB3E8: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x800FB3EC: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x800FB3F0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800FB3F4: beq         $t0, $a1, L_800FB40C
    if (ctx->r8 == ctx->r5) {
        // 0x800FB3F8: sll         $t7, $a2, 1
        ctx->r15 = S32(ctx->r6 << 1);
            goto L_800FB40C;
    }
    // 0x800FB3F8: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800FB3FC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800FB400: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800FB404: bne         $t0, $t9, L_800FB410
    if (ctx->r8 != ctx->r25) {
        // 0x800FB408: nop
    
            goto L_800FB410;
    }
    // 0x800FB408: nop

L_800FB40C:
    // 0x800FB40C: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
L_800FB410:
    // 0x800FB410: beq         $t1, $a1, L_800FB428
    if (ctx->r9 == ctx->r5) {
        // 0x800FB414: sll         $t6, $a2, 1
        ctx->r14 = S32(ctx->r6 << 1);
            goto L_800FB428;
    }
    // 0x800FB414: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800FB418: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800FB41C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800FB420: bnel        $t1, $t8, L_800FB430
    if (ctx->r9 != ctx->r24) {
        // 0x800FB424: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800FB430;
    }
    goto skip_0;
    // 0x800FB424: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
L_800FB428:
    // 0x800FB428: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800FB42C:
    // 0x800FB42C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800FB430:
    // 0x800FB430: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800FB434: bne         $at, $zero, L_800FB3CC
    if (ctx->r1 != 0) {
        // 0x800FB438: nop
    
            goto L_800FB3CC;
    }
    // 0x800FB438: nop

L_800FB43C:
    // 0x800FB43C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800FB440: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FB444: addu        $v1, $t9, $s1
    ctx->r3 = ADD32(ctx->r25, ctx->r17);
    // 0x800FB448: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800FB44C: beq         $v0, $zero, L_800FB474
    if (ctx->r2 == 0) {
        // 0x800FB450: nop
    
            goto L_800FB474;
    }
    // 0x800FB450: nop

    // 0x800FB454: beq         $v0, $ra, L_800FB474
    if (ctx->r2 == ctx->r31) {
        // 0x800FB458: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800FB474;
    }
    // 0x800FB458: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FB45C: beq         $v0, $at, L_800FB4AC
    if (ctx->r2 == ctx->r1) {
        // 0x800FB460: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FB4AC;
    }
    // 0x800FB460: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FB464: beq         $v0, $at, L_800FB4AC
    if (ctx->r2 == ctx->r1) {
        // 0x800FB468: nop
    
            goto L_800FB4AC;
    }
    // 0x800FB468: nop

    // 0x800FB46C: b           L_800FB4E0
    // 0x800FB470: nop

        goto L_800FB4E0;
    // 0x800FB470: nop

L_800FB474:
    // 0x800FB474: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB478: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800FB47C: mflo        $t6
    ctx->r14 = lo;
    // 0x800FB480: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800FB484: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800FB488: multu       $t0, $s3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB48C: mflo        $t9
    ctx->r25 = lo;
    // 0x800FB490: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x800FB494: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800FB498: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800FB49C: beq         $at, $zero, L_800FB4E0
    if (ctx->r1 == 0) {
        // 0x800FB4A0: nop
    
            goto L_800FB4E0;
    }
    // 0x800FB4A0: nop

    // 0x800FB4A4: b           L_800FB4E0
    // 0x800FB4A8: or          $s2, $ra, $zero
    ctx->r18 = ctx->r31 | 0;
        goto L_800FB4E0;
    // 0x800FB4A8: or          $s2, $ra, $zero
    ctx->r18 = ctx->r31 | 0;
L_800FB4AC:
    // 0x800FB4AC: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB4B0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800FB4B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800FB4B8: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x800FB4BC: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800FB4C0: multu       $t0, $s3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB4C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800FB4C8: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x800FB4CC: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x800FB4D0: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800FB4D4: beq         $at, $zero, L_800FB4E0
    if (ctx->r1 == 0) {
        // 0x800FB4D8: nop
    
            goto L_800FB4E0;
    }
    // 0x800FB4D8: nop

    // 0x800FB4DC: or          $s2, $ra, $zero
    ctx->r18 = ctx->r31 | 0;
L_800FB4E0:
    // 0x800FB4E0: beql        $s2, $zero, L_800FB500
    if (ctx->r18 == 0) {
        // 0x800FB4E4: sh          $t4, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r12;
            goto L_800FB500;
    }
    goto skip_1;
    // 0x800FB4E4: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    skip_1:
    // 0x800FB4E8: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // 0x800FB4EC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800FB4F0: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x800FB4F4: b           L_800FB50C
    // 0x800FB4F8: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
        goto L_800FB50C;
    // 0x800FB4F8: sh          $t4, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r12;
    // 0x800FB4FC: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
L_800FB500:
    // 0x800FB500: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800FB504: addu        $t6, $t8, $s1
    ctx->r14 = ADD32(ctx->r24, ctx->r17);
    // 0x800FB508: sh          $t5, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r13;
L_800FB50C:
    // 0x800FB50C: lw          $t3, 0x1384($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1384);
    // 0x800FB510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800FB514: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800FB518: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800FB51C: bne         $at, $zero, L_800FB388
    if (ctx->r1 != 0) {
        // 0x800FB520: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_800FB388;
    }
    // 0x800FB520: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
L_800FB524:
    // 0x800FB524: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB528: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800FB52C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800FB530: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800FB534: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800FB538: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800FB53C: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB540: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800FB544: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800FB548: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800FB54C: jr          $ra
    // 0x800FB550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FB550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonEntryNullProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013D998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D99C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D9A0: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x8013D9A4: beq         $v1, $zero, L_8013DA04
    if (ctx->r3 == 0) {
        // 0x8013D9A8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8013DA04;
    }
    // 0x8013D9A8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8013D9AC: bne         $t6, $zero, L_8013DA04
    if (ctx->r14 != 0) {
        // 0x8013D9B0: sw          $t6, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r14;
            goto L_8013DA04;
    }
    // 0x8013D9B0: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x8013D9B4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8013D9B8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013D9BC: bnel        $t8, $at, L_8013D9D8
    if (ctx->r24 != ctx->r1) {
        // 0x8013D9C0: lw          $t9, 0xB1C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0XB1C);
            goto L_8013D9D8;
    }
    goto skip_0;
    // 0x8013D9C0: lw          $t9, 0xB1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x8013D9C4: jal         0x80159040
    // 0x8013D9C8: nop

    ftBossWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D9C8: nop

    after_0:
    // 0x8013D9CC: b           L_8013DA08
    // 0x8013D9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013DA08;
    // 0x8013D9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013D9D4: lw          $t9, 0xB1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB1C);
L_8013D9D8:
    // 0x8013D9D8: lw          $t2, 0x854($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X854);
    // 0x8013D9DC: sw          $t9, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r25;
    // 0x8013D9E0: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x8013D9E4: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    // 0x8013D9E8: lw          $t1, 0x858($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X858);
    // 0x8013D9EC: sw          $t1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r9;
    // 0x8013D9F0: lw          $t2, 0x85C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X85C);
    // 0x8013D9F4: sw          $t2, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r10;
    // 0x8013D9F8: lw          $t3, 0xB20($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB20);
    // 0x8013D9FC: jal         0x8013E1C8
    // 0x8013DA00: sw          $t3, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r11;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013DA00: sw          $t3, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r11;
    after_1:
L_8013DA04:
    // 0x8013DA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013DA08:
    // 0x8013DA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DA0C: jr          $ra
    // 0x8013DA10: nop

    return;
    // 0x8013DA10: nop

;}
RECOMP_FUNC void mpProcessResetMultiWallCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9510: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D9514: jr          $ra
    // 0x800D9518: sw          $zero, 0xDE0($at)
    MEM_W(0XDE0, ctx->r1) = 0;
    return;
    // 0x800D9518: sw          $zero, 0xDE0($at)
    MEM_W(0XDE0, ctx->r1) = 0;
;}
RECOMP_FUNC void mnDataMakeDecals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801323A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801323A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801323AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801323B8: jal         0x80009968
    // 0x801323BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801323BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323C0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801323C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801323C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801323CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323D0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801323D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801323DC: jal         0x80009DF4
    // 0x801323E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801323E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801323E4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801323E8: lw          $t7, 0x3160($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3160);
    // 0x801323EC: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801323F0: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x801323F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801323F8: jal         0x800CCFDC
    // 0x801323FC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801323FC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132400: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132404: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132408: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013240C: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80132410: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132414: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132418: lw          $t9, 0x3160($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3160);
    // 0x8013241C: addiu       $v1, $v1, 0x2A30
    ctx->r3 = ADD32(ctx->r3, 0X2A30);
    // 0x80132420: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80132424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132428: jal         0x800CCFDC
    // 0x8013242C: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013242C: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    after_3:
    // 0x80132430: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80132434: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132438: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8013243C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132440: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x80132444: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132448: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x8013244C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132450: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132454: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80132458: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8013245C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80132460: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132464: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132468: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x8013246C: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132470: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132474: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132478: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013247C: lw          $t7, 0x3160($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3160);
    // 0x80132480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132484: jal         0x800CCFDC
    // 0x80132488: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132488: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_4:
    // 0x8013248C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132490: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80132494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132498: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x8013249C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801324A0: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801324A4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801324A8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801324AC: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801324B0: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x801324B4: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801324B8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801324BC: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801324C0: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801324C4: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x801324C8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801324CC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801324D0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801324D4: lw          $t5, 0x3164($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3164);
    // 0x801324D8: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801324DC: addiu       $t6, $t6, 0x4A78
    ctx->r14 = ADD32(ctx->r14, 0X4A78);
    // 0x801324E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324E4: jal         0x800CCFDC
    // 0x801324E8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801324E8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x801324EC: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801324F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324F8: addiu       $v1, $zero, 0x99
    ctx->r3 = ADD32(0, 0X99);
    // 0x801324FC: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x80132500: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132504: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80132508: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8013250C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132510: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132514: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132518: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013251C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132520: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132524: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013252C: jr          $ra
    // 0x80132530: nop

    return;
    // 0x80132530: nop

;}
RECOMP_FUNC void ftParamSetModelPartDefaultID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8EAC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8EB0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800E8EB4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800E8EB8: sb          $a2, 0x974($t7)
    MEM_B(0X974, ctx->r15) = ctx->r6;
    // 0x800E8EBC: lbu         $t9, 0x18C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8EC0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x800E8EC4: jr          $ra
    // 0x800E8EC8: sb          $t0, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r8;
    return;
    // 0x800E8EC8: sb          $t0, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void mvOpeningCliffCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013212C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132134: jal         0x80010580
    // 0x80132138: nop

    gcPlayCamAnim(rdram, ctx);
        goto after_0;
    // 0x80132138: nop

    after_0:
    // 0x8013213C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132144: jr          $ra
    // 0x80132148: nop

    return;
    // 0x80132148: nop

;}
RECOMP_FUNC void func_ovl8_80371DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DDC: jr          $ra
    // 0x80371DE0: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    return;
    // 0x80371DE0: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
;}
RECOMP_FUNC void itCapsuleExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80174344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174348: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017434C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80174350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80174358: lbu         $t7, 0x340($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X340);
    // 0x8017435C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80174360: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80174364: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x80174368: sb          $t8, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r24;
    // 0x8017436C: sh          $t9, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r25;
    // 0x80174370: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80174374: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80174378: jal         0x800269C0
    // 0x8017437C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017437C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80174380: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80174384: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80174388: lbu         $t1, 0x158($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X158);
    // 0x8017438C: sw          $t7, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r15;
    // 0x80174390: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x80174394: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x80174398: andi        $t5, $t3, 0xF7
    ctx->r13 = ctx->r11 & 0XF7;
    // 0x8017439C: andi        $t8, $t5, 0xFB
    ctx->r24 = ctx->r13 & 0XFB;
    // 0x801743A0: sb          $t3, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r11;
    // 0x801743A4: sb          $t5, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r13;
    // 0x801743A8: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x801743AC: sb          $t8, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r24;
    // 0x801743B0: sb          $t9, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r25;
    // 0x801743B4: jal         0x8017279C
    // 0x801743B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x801743B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801743BC: jal         0x8017275C
    // 0x801743C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainRefreshAttackColl(rdram, ctx);
        goto after_2;
    // 0x801743C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801743C4: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801743C8: lw          $t0, -0x69CC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X69CC);
    // 0x801743CC: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801743D0: addiu       $t2, $t2, 0x98
    ctx->r10 = ADD32(ctx->r10, 0X98);
    // 0x801743D4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801743D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801743DC: jal         0x80173180
    // 0x801743E0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_3;
    // 0x801743E0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x801743E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801743E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801743EC: jr          $ra
    // 0x801743F0: nop

    return;
    // 0x801743F0: nop

;}
RECOMP_FUNC void mpCollisionCheckLWallSurfaceTilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8548: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F854C: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F8550: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F8554: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800F8558: subu        $v0, $a2, $a0
    ctx->r2 = SUB32(ctx->r6, ctx->r4);
    // 0x800F855C: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F8560: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F8564: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F8568: bgez        $v0, L_800F857C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F856C: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_800F857C;
    }
    // 0x800F856C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800F8570: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800F8574: b           L_800F8580
    // 0x800F8578: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_800F8580;
    // 0x800F8578: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_800F857C:
    // 0x800F857C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800F8580:
    // 0x800F8580: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F8584: nop

    // 0x800F8588: bc1fl       L_800F85E4
    if (!c1cs) {
        // 0x800F858C: mtc1        $a1, $f6
        ctx->f6.u32l = ctx->r5;
            goto L_800F85E4;
    }
    goto skip_0;
    // 0x800F858C: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    skip_0:
    // 0x800F8590: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800F8594: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8598: lwc1        $f10, 0x8A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8A8);
    // 0x800F859C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F85A0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F85A4: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F85A8: nop

    // 0x800F85AC: bc1t        L_800F85D8
    if (c1cs) {
        // 0x800F85B0: nop
    
            goto L_800F85D8;
    }
    // 0x800F85B0: nop

    // 0x800F85B4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F85B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F85BC: lwc1        $f10, 0x8AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8AC);
    // 0x800F85C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F85C4: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F85C8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F85CC: nop

    // 0x800F85D0: bc1fl       L_800F8634
    if (!c1cs) {
        // 0x800F85D4: lwc1        $f16, 0x7C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_800F8634;
    }
    goto skip_1;
    // 0x800F85D4: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    skip_1:
L_800F85D8:
    // 0x800F85D8: b           L_800F896C
    // 0x800F85DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F85DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F85E0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
L_800F85E4:
    // 0x800F85E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F85E8: lwc1        $f10, 0x8B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8B0);
    // 0x800F85EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F85F0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F85F4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800F85F8: nop

    // 0x800F85FC: bc1t        L_800F8628
    if (c1cs) {
        // 0x800F8600: nop
    
            goto L_800F8628;
    }
    // 0x800F8600: nop

    // 0x800F8604: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F8608: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F860C: lwc1        $f10, 0x8B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8B4);
    // 0x800F8610: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F8614: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F8618: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F861C: nop

    // 0x800F8620: bc1fl       L_800F8634
    if (!c1cs) {
        // 0x800F8624: lwc1        $f16, 0x7C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_800F8634;
    }
    goto skip_2;
    // 0x800F8624: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    skip_2:
L_800F8628:
    // 0x800F8628: b           L_800F896C
    // 0x800F862C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F862C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F8630: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
L_800F8634:
    // 0x800F8634: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F8638: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800F863C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F8640: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F8644: subu        $v1, $a3, $t6
    ctx->r3 = SUB32(ctx->r7, ctx->r14);
    // 0x800F8648: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800F864C: bgez        $v1, L_800F8660
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F8650: swc1        $f0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
            goto L_800F8660;
    }
    // 0x800F8650: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800F8654: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800F8658: b           L_800F8664
    // 0x800F865C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
        goto L_800F8664;
    // 0x800F865C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_800F8660:
    // 0x800F8660: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
L_800F8664:
    // 0x800F8664: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F8668: nop

    // 0x800F866C: bc1fl       L_800F86B8
    if (!c1cs) {
        // 0x800F8670: mtc1        $a2, $f4
        ctx->f4.u32l = ctx->r6;
            goto L_800F86B8;
    }
    goto skip_3;
    // 0x800F8670: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    skip_3:
    // 0x800F8674: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800F8678: nop

    // 0x800F867C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F8680: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800F8684: nop

    // 0x800F8688: bc1t        L_800F86AC
    if (c1cs) {
        // 0x800F868C: nop
    
            goto L_800F86AC;
    }
    // 0x800F868C: nop

    // 0x800F8690: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800F8694: nop

    // 0x800F8698: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F869C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800F86A0: nop

    // 0x800F86A4: bc1fl       L_800F86F8
    if (!c1cs) {
        // 0x800F86A8: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_800F86F8;
    }
    goto skip_4;
    // 0x800F86A8: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_4:
L_800F86AC:
    // 0x800F86AC: b           L_800F896C
    // 0x800F86B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F86B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F86B4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
L_800F86B8:
    // 0x800F86B8: nop

    // 0x800F86BC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F86C0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800F86C4: nop

    // 0x800F86C8: bc1t        L_800F86EC
    if (c1cs) {
        // 0x800F86CC: nop
    
            goto L_800F86EC;
    }
    // 0x800F86CC: nop

    // 0x800F86D0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800F86D4: nop

    // 0x800F86D8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F86DC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800F86E0: nop

    // 0x800F86E4: bc1fl       L_800F86F8
    if (!c1cs) {
        // 0x800F86E8: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_800F86F8;
    }
    goto skip_5;
    // 0x800F86E8: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_5:
L_800F86EC:
    // 0x800F86EC: b           L_800F896C
    // 0x800F86F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F86F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F86F4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_800F86F8:
    // 0x800F86F8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800F86FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800F8700: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F8704: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F8708: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800F870C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F8714: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F8718: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F871C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F8720: swc1        $f14, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f14.u32l;
    // 0x800F8724: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800F8728: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800F872C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F8730: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F8734: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800F8738: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800F873C: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800F8740: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F8744: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800F8748: lwc1        $f10, 0x8B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8B8);
    // 0x800F874C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800F8750: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F8754: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800F8758: nop

    // 0x800F875C: bc1f        L_800F896C
    if (!c1cs) {
        // 0x800F8760: nop
    
            goto L_800F896C;
    }
    // 0x800F8760: nop

    // 0x800F8764: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800F8768: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F876C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8770: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
    // 0x800F8774: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800F8778: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F877C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F8780: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F8784: lwc1        $f10, 0x8BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8BC);
    // 0x800F8788: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F878C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800F8790: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F8794: sub.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800F8798: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F879C: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800F87A0: nop

    // 0x800F87A4: bc1fl       L_800F87F8
    if (!c1cs) {
        // 0x800F87A8: sub.s       $f0, $f8, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
            goto L_800F87F8;
    }
    goto skip_6;
    // 0x800F87A8: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    skip_6:
    // 0x800F87AC: lwc1        $f4, 0x8C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8C0);
    // 0x800F87B0: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F87B4: nop

    // 0x800F87B8: bc1f        L_800F896C
    if (!c1cs) {
        // 0x800F87BC: nop
    
            goto L_800F896C;
    }
    // 0x800F87BC: nop

    // 0x800F87C0: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800F87C4: nop

    // 0x800F87C8: bc1f        L_800F896C
    if (!c1cs) {
        // 0x800F87CC: nop
    
            goto L_800F896C;
    }
    // 0x800F87CC: nop

    // 0x800F87D0: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x800F87D4: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800F87D8: bc1f        L_800F896C
    if (!c1cs) {
        // 0x800F87DC: nop
    
            goto L_800F896C;
    }
    // 0x800F87DC: nop

    // 0x800F87E0: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x800F87E4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F87E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F87EC: b           L_800F896C
    // 0x800F87F0: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
        goto L_800F896C;
    // 0x800F87F0: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x800F87F4: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
L_800F87F8:
    // 0x800F87F8: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F87FC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F8800: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F8804: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F8808: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F880C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F8810: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800F8814: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F8818: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F881C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F8820: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F8824: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F8828: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F882C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F8830: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F8834: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F8838: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800F883C: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F8840: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800F8844: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800F8848: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x800F884C: bc1fl       L_800F8888
    if (!c1cs) {
        // 0x800F8850: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800F8888;
    }
    goto skip_7;
    // 0x800F8850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_7:
    // 0x800F8854: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8858: lwc1        $f4, 0x8C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8C4);
    // 0x800F885C: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800F8860: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F8864: nop

    // 0x800F8868: bc1fl       L_800F887C
    if (!c1cs) {
        // 0x800F886C: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800F887C;
    }
    goto skip_8;
    // 0x800F886C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_8:
    // 0x800F8870: b           L_800F896C
    // 0x800F8874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F8874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F8878: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800F887C:
    // 0x800F887C: b           L_800F88C4
    // 0x800F8880: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
        goto L_800F88C4;
    // 0x800F8880: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F8884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800F8888:
    // 0x800F8888: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F888C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8890: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800F8894: nop

    // 0x800F8898: bc1fl       L_800F88C4
    if (!c1cs) {
        // 0x800F889C: lwc1        $f6, 0x4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800F88C4;
    }
    goto skip_9;
    // 0x800F889C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    skip_9:
    // 0x800F88A0: lwc1        $f8, 0x8C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8C8);
    // 0x800F88A4: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800F88A8: nop

    // 0x800F88AC: bc1fl       L_800F88C0
    if (!c1cs) {
        // 0x800F88B0: mov.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
            goto L_800F88C0;
    }
    goto skip_10;
    // 0x800F88B0: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    skip_10:
    // 0x800F88B4: b           L_800F896C
    // 0x800F88B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F88B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F88BC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800F88C0:
    // 0x800F88C0: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
L_800F88C4:
    // 0x800F88C4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F88C8: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F88CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F88D0: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800F88D4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F88D8: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F88DC: lwc1        $f6, 0x8CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X8CC);
    // 0x800F88E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F88E4: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F88E8: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F88EC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800F88F0: nop

    // 0x800F88F4: bc1t        L_800F8914
    if (c1cs) {
        // 0x800F88F8: nop
    
            goto L_800F8914;
    }
    // 0x800F88F8: nop

    // 0x800F88FC: lwc1        $f10, 0x8D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8D0);
    // 0x800F8900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F8904: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800F8908: nop

    // 0x800F890C: bc1fl       L_800F8920
    if (!c1cs) {
        // 0x800F8910: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800F8920;
    }
    goto skip_11;
    // 0x800F8910: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_11:
L_800F8914:
    // 0x800F8914: b           L_800F896C
    // 0x800F8918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F896C;
    // 0x800F8918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F891C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800F8920:
    // 0x800F8920: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F8924: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F8928: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F892C: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800F8930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F8934: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F8938: nop

    // 0x800F893C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F8940: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F8944: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800F8948: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F894C: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F8950: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800F8954: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F8958: nop

    // 0x800F895C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F8960: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800F8964: b           L_800F896C
    // 0x800F8968: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
        goto L_800F896C;
    // 0x800F8968: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
L_800F896C:
    // 0x800F896C: jr          $ra
    // 0x800F8970: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F8970: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ftCommonWalkSetStatusDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E5FC: jal         0x8013E580
    // 0x8013E600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    ftCommonWalkSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8013E600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8013E604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E60C: jr          $ra
    // 0x8013E610: nop

    return;
    // 0x8013E610: nop

;}
RECOMP_FUNC void mnVSRecordGetTKO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131C10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80131C14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80131C18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131C1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C24: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80131C28: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80131C2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80131C30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131C34: addiu       $s4, $s4, 0x44E0
    ctx->r20 = ADD32(ctx->r20, 0X44E0);
    // 0x80131C38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131C3C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80131C40:
    // 0x80131C40: jal         0x801326EC
    // 0x80131C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x80131C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80131C48: beq         $v0, $zero, L_80131C74
    if (ctx->r2 == 0) {
        // 0x80131C4C: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_80131C74;
    }
    // 0x80131C4C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80131C50: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80131C54: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80131C58: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80131C5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80131C60: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x80131C64: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x80131C68: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80131C6C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80131C70: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
L_80131C74:
    // 0x80131C74: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131C78: bne         $s0, $s2, L_80131C40
    if (ctx->r16 != ctx->r18) {
        // 0x80131C7C: nop
    
            goto L_80131C40;
    }
    // 0x80131C7C: nop

    // 0x80131C80: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80131C84: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80131C88: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80131C8C: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80131C90: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80131C94: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x80131C98: lhu         $t3, 0x26($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X26);
    // 0x80131C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CA4: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
    // 0x80131CA8: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    // 0x80131CAC: bne         $at, $zero, L_80131CBC
    if (ctx->r1 != 0) {
        // 0x80131CB0: lw          $s1, 0x1C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X1C);
            goto L_80131CBC;
    }
    // 0x80131CB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CB4: b           L_80131CC0
    // 0x80131CB8: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
        goto L_80131CC0;
    // 0x80131CB8: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
L_80131CBC:
    // 0x80131CBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131CC0:
    // 0x80131CC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80131CC4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80131CC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80131CCC: jr          $ra
    // 0x80131CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itLGunThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175638: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017563C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80175640: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80175644: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80175648: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8017564C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80175650: bne         $t6, $zero, L_8017566C
    if (ctx->r14 != 0) {
        // 0x80175654: lui         $a3, 0x8017
        ctx->r7 = S32(0X8017 << 16);
            goto L_8017566C;
    }
    // 0x80175654: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175658: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017565C: jal         0x80173DF4
    // 0x80175660: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x80175660: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80175664: b           L_80175678
    // 0x80175668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80175678;
    // 0x80175668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017566C:
    // 0x8017566C: jal         0x80173B24
    // 0x80175670: addiu       $a3, $a3, 0x5584
    ctx->r7 = ADD32(ctx->r7, 0X5584);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x80175670: addiu       $a3, $a3, 0x5584
    ctx->r7 = ADD32(ctx->r7, 0X5584);
    after_1:
    // 0x80175674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175678:
    // 0x80175678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017567C: jr          $ra
    // 0x80175680: nop

    return;
    // 0x80175680: nop

;}
RECOMP_FUNC void mnVSResultsMakeDigit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134808: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8013480C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80134810: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x80134814: addiu       $t6, $t6, -0x6A18
    ctx->r14 = ADD32(ctx->r14, -0X6A18);
    // 0x80134818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013481C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80134820: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80134824: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80134828: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8013482C:
    // 0x8013482C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134830: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80134834: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80134838: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013483C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80134840: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80134844: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80134848: bne         $t6, $t0, L_8013482C
    if (ctx->r14 != ctx->r8) {
        // 0x8013484C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013482C;
    }
    // 0x8013484C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80134850: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134854: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80134858: addiu       $t2, $t2, -0x69F0
    ctx->r10 = ADD32(ctx->r10, -0X69F0);
    // 0x8013485C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80134860: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134864: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x80134868: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8013486C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80134870: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80134874: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80134878: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8013487C: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80134880: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80134884: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80134888: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8013488C: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    // 0x80134890: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80134894: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80134898: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x8013489C: sw          $t4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r12;
    // 0x801348A0: lhu         $t4, 0x1C($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1C);
    // 0x801348A4: addu        $t0, $v0, $t5
    ctx->r8 = ADD32(ctx->r2, ctx->r13);
    // 0x801348A8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801348AC: sh          $t4, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r12;
    // 0x801348B0: lw          $t9, -0x5FA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FA4);
    // 0x801348B4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801348B8: jal         0x800CCFDC
    // 0x801348BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x801348BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_0:
    // 0x801348C0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801348C4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801348C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801348CC: andi        $t1, $t7, 0xFFDF
    ctx->r9 = ctx->r15 & 0XFFDF;
    // 0x801348D0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801348D4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801348D8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801348DC: jal         0x80134770
    // 0x801348E0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    mnVSResultsSetNumberColor(rdram, ctx);
        goto after_1;
    // 0x801348E0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x801348E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801348E8: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x801348EC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801348F0: jr          $ra
    // 0x801348F4: nop

    return;
    // 0x801348F4: nop

;}
RECOMP_FUNC void efManagerBattleScoreMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801040E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801040E8: blez        $a1, L_801040F8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x801040EC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_801040F8;
    }
    // 0x801040EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801040F0: b           L_801040FC
    // 0x801040F4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
        goto L_801040FC;
    // 0x801040F4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
L_801040F8:
    // 0x801040F8: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
L_801040FC:
    // 0x801040FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104100: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80104104: jal         0x800CE9E8
    // 0x80104108: ori         $a0, $a0, 0x18
    ctx->r4 = ctx->r4 | 0X18;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80104108: ori         $a0, $a0, 0x18
    ctx->r4 = ctx->r4 | 0X18;
    after_0:
    // 0x8010410C: beq         $v0, $zero, L_8010418C
    if (ctx->r2 == 0) {
        // 0x80104110: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010418C;
    }
    // 0x80104110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80104118: jal         0x800CE1DC
    // 0x8010411C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x8010411C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80104120: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80104124: bne         $v0, $zero, L_8010413C
    if (ctx->r2 != 0) {
        // 0x80104128: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010413C;
    }
    // 0x80104128: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010412C: jal         0x800CEA40
    // 0x80104130: nop

    lbParticleEjectStruct(rdram, ctx);
        goto after_2;
    // 0x80104130: nop

    after_2:
    // 0x80104134: b           L_80104190
    // 0x80104138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104190;
    // 0x80104138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010413C:
    // 0x8010413C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80104140: jal         0x800CEA14
    // 0x80104144: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x80104144: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x80104148: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8010414C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80104150: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80104154: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80104158: bnel        $t6, $zero, L_8010416C
    if (ctx->r14 != 0) {
        // 0x8010415C: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_8010416C;
    }
    goto skip_0;
    // 0x8010415C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80104160: b           L_80104190
    // 0x80104164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104190;
    // 0x80104164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104168: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_8010416C:
    // 0x8010416C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80104170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80104174: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80104178: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010417C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80104180: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80104184: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x80104188: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_8010418C:
    // 0x8010418C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80104190:
    // 0x80104190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80104198: jr          $ra
    // 0x8010419C: nop

    return;
    // 0x8010419C: nop

;}
RECOMP_FUNC void mpCollisionGetLREdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F41EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F41F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F41F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F41F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F41FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4200: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F4204: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F4208: beq         $a0, $at, L_800F421C
    if (ctx->r4 == ctx->r1) {
        // 0x800F420C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800F421C;
    }
    // 0x800F420C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800F4210: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800F4214: bne         $a0, $at, L_800F4240
    if (ctx->r4 != ctx->r1) {
        // 0x800F4218: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F4240;
    }
    // 0x800F4218: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800F421C:
    // 0x800F421C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F4220: addiu       $s0, $s0, 0x328
    ctx->r16 = ADD32(ctx->r16, 0X328);
    // 0x800F4224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F4228:
    // 0x800F4228: jal         0x80023624
    // 0x800F422C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800F422C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800F4230: jal         0x800A3040
    // 0x800F4234: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800F4234: nop

    after_1:
    // 0x800F4238: b           L_800F4228
    // 0x800F423C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800F4228;
    // 0x800F423C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F4240:
    // 0x800F4240: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800F4244: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800F4248: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800F424C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800F4250: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800F4254: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800F4258: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F425C: lw          $t7, 0x1304($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1304);
    // 0x800F4260: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800F4264: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F4268: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800F426C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800F4270: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F4274: lw          $t9, 0x84($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X84);
    // 0x800F4278: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800F427C: bne         $at, $zero, L_800F42A4
    if (ctx->r1 != 0) {
        // 0x800F4280: nop
    
            goto L_800F42A4;
    }
    // 0x800F4280: nop

    // 0x800F4284: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F4288: addiu       $s0, $s0, 0x340
    ctx->r16 = ADD32(ctx->r16, 0X340);
L_800F428C:
    // 0x800F428C: jal         0x80023624
    // 0x800F4290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800F4290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F4294: jal         0x800A3040
    // 0x800F4298: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800F4298: nop

    after_3:
    // 0x800F429C: b           L_800F428C
    // 0x800F42A0: nop

        goto L_800F428C;
    // 0x800F42A0: nop

L_800F42A4:
    // 0x800F42A4: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F42A8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800F42AC: addiu       $s0, $s0, 0x1374
    ctx->r16 = ADD32(ctx->r16, 0X1374);
    // 0x800F42B0: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800F42B4: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F42B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800F42BC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800F42C0: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x800F42C4: addu        $t9, $a1, $t3
    ctx->r25 = ADD32(ctx->r5, ctx->r11);
    // 0x800F42C8: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x800F42CC: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F42D0: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800F42D4: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F42D8: addu        $a2, $t8, $v1
    ctx->r6 = ADD32(ctx->r24, ctx->r3);
    // 0x800F42DC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800F42E0: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x800F42E4: addu        $t9, $a1, $t4
    ctx->r25 = ADD32(ctx->r5, ctx->r12);
    // 0x800F42E8: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x800F42EC: addiu       $ra, $ra, 0x1370
    ctx->r31 = ADD32(ctx->r31, 0X1370);
    // 0x800F42F0: lw          $a0, 0x0($ra)
    ctx->r4 = MEM_W(ctx->r31, 0X0);
    // 0x800F42F4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800F42F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800F42FC: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4300: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x800F4304: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4308: mflo        $t6
    ctx->r14 = lo;
    // 0x800F430C: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4310: bgez        $t9, L_800F4320
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800F4314: lh          $t1, 0x0($t8)
        ctx->r9 = MEM_H(ctx->r24, 0X0);
            goto L_800F4320;
    }
    // 0x800F4314: lh          $t1, 0x0($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X0);
    // 0x800F4318: b           L_800F4324
    // 0x800F431C: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
        goto L_800F4324;
    // 0x800F431C: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
L_800F4320:
    // 0x800F4320: slt         $v0, $t1, $t0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
L_800F4324:
    // 0x800F4324: beql        $v0, $zero, L_800F4374
    if (ctx->r2 == 0) {
        // 0x800F4328: mtc1        $t1, $f16
        ctx->f16.u32l = ctx->r9;
            goto L_800F4374;
    }
    goto skip_0;
    // 0x800F4328: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    skip_0:
    // 0x800F432C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800F4330: nop

    // 0x800F4334: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F4338: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x800F433C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800F4340: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x800F4344: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x800F4348: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F434C: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4350: mflo        $t6
    ctx->r14 = lo;
    // 0x800F4354: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800F4358: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800F435C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800F4360: nop

    // 0x800F4364: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F4368: b           L_800F43B0
    // 0x800F436C: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
        goto L_800F43B0;
    // 0x800F436C: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x800F4370: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
L_800F4374:
    // 0x800F4374: nop

    // 0x800F4378: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F437C: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x800F4380: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800F4384: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x800F4388: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x800F438C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F4390: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4394: mflo        $t6
    ctx->r14 = lo;
    // 0x800F4398: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800F439C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800F43A0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F43A4: nop

    // 0x800F43A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F43AC: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
L_800F43B0:
    // 0x800F43B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F43B4: nop

    // 0x800F43B8: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x800F43BC: lw          $t7, 0x70($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X70);
    // 0x800F43C0: bnel        $t7, $zero, L_800F43D8
    if (ctx->r15 != 0) {
        // 0x800F43C4: lwc1        $f10, 0x0($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
            goto L_800F43D8;
    }
    goto skip_1;
    // 0x800F43C4: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800F43C8: lw          $t6, 0x84($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X84);
    // 0x800F43CC: beql        $t6, $zero, L_800F43F8
    if (ctx->r14 == 0) {
        // 0x800F43D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F43F8;
    }
    goto skip_2;
    // 0x800F43D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800F43D4: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
L_800F43D8:
    // 0x800F43D8: lwc1        $f16, 0x1C($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800F43DC: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F43E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F43E4: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x800F43E8: lwc1        $f6, 0x20($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800F43EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F43F0: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x800F43F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F43F8:
    // 0x800F43F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F43FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F4400: jr          $ra
    // 0x800F4404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F4404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ifCommonPlayerArrowsRightProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111588: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8011158C: lbu         $t6, 0x158E($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X158E);
    // 0x80111590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111598: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8011159C: beql        $t7, $zero, L_801115B0
    if (ctx->r15 == 0) {
        // 0x801115A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801115B0;
    }
    goto skip_0;
    // 0x801115A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801115A4: jal         0x80014038
    // 0x801115A8: nop

    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x801115A8: nop

    after_0:
    // 0x801115AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801115B0:
    // 0x801115B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801115B4: jr          $ra
    // 0x801115B8: nop

    return;
    // 0x801115B8: nop

;}
RECOMP_FUNC void ftBossCommonInvertLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157F60: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157F64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80157F68: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80157F6C: lw          $t9, 0x8E8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8E8);
    // 0x80157F70: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80157F74: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80157F78: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x80157F7C: lwc1        $f8, -0x38E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X38E8);
    // 0x80157F80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80157F84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80157F88: jr          $ra
    // 0x80157F8C: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
    return;
    // 0x80157F8C: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
;}
RECOMP_FUNC void syAudioSetBGMVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80020B3C: sltiu       $at, $a1, 0x7801
    ctx->r1 = ctx->r5 < 0X7801 ? 1 : 0;
    // 0x80020B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020B44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020B48: bne         $at, $zero, L_80020B54
    if (ctx->r1 != 0) {
        // 0x80020B4C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80020B54;
    }
    // 0x80020B4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80020B50: addiu       $a2, $zero, 0x7800
    ctx->r6 = ADD32(0, 0X7800);
L_80020B54:
    // 0x80020B54: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80020B58: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80020B5C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80020B60: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80020B64: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80020B68: lw          $a0, -0x26A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26A0);
    // 0x80020B6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80020B70: jal         0x8002FC10
    // 0x80020B74: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80020B74: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80020B78: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80020B7C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80020B80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80020B84: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80020B88: bgez        $a2, L_80020B9C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80020B8C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80020B9C;
    }
    // 0x80020B8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020B90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020B94: nop

    // 0x80020B98: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80020B9C:
    // 0x80020B9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020BA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020BA8: swc1        $f6, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = ctx->f6.u32l;
    // 0x80020BAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020BB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020BB4: sw          $zero, -0x2688($at)
    MEM_W(-0X2688, ctx->r1) = 0;
    // 0x80020BB8: jr          $ra
    // 0x80020BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80020BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itSawamuraAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182AB4: jal         0x80182958
    // 0x80182AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itSawamuraAttackInitVars(rdram, ctx);
        goto after_0;
    // 0x80182AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80182ABC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182AC0: addiu       $a1, $a1, -0x4DAC
    ctx->r5 = ADD32(ctx->r5, -0X4DAC);
    // 0x80182AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80182AC8: jal         0x80172EC8
    // 0x80182ACC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80182ACC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80182AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182AD8: jr          $ra
    // 0x80182ADC: nop

    return;
    // 0x80182ADC: nop

;}
RECOMP_FUNC void sc1PStageClearUpdateTotal1PGameScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133EEC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133EF0: lw          $t6, 0x52E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X52E8);
    // 0x80133EF4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133EF8: jr          $ra
    // 0x80133EFC: sw          $t6, 0x4AF0($at)
    MEM_W(0X4AF0, ctx->r1) = ctx->r14;
    return;
    // 0x80133EFC: sw          $t6, 0x4AF0($at)
    MEM_W(0X4AF0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void ftParamMoveDLLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E827C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E8280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8284: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E8288: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800E828C: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x800E8290: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800E8294: jal         0x8000A0D0
    // 0x800E8298: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x800E8298: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800E829C: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x800E82A0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800E82A4: sb          $t7, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r15;
    // 0x800E82A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E82AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E82B0: jr          $ra
    // 0x800E82B4: nop

    return;
    // 0x800E82B4: nop

;}
RECOMP_FUNC void func_ovl3_801741F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801741F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801741F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801741F8: jal         0x80172FE0
    // 0x801741FC: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x801741FC: nop

    after_0:
    // 0x80174200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017420C: jr          $ra
    // 0x80174210: nop

    return;
    // 0x80174210: nop

;}
RECOMP_FUNC void sc1PTrainingModeCheckLagTic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D974: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D978: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018D97C: lbu         $v0, 0xD3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD3);
    // 0x8018D980: bne         $v0, $zero, L_8018D9BC
    if (ctx->r2 != 0) {
        // 0x8018D984: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8018D9BC;
    }
    // 0x8018D984: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8018D988: lbu         $v1, 0xD4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XD4);
    // 0x8018D98C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018D990: bne         $v1, $zero, L_8018D9B4
    if (ctx->r3 != 0) {
        // 0x8018D994: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8018D9B4;
    }
    // 0x8018D994: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8018D998: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8018D99C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D9A0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8018D9A4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D9A8: lbu         $t8, 0x81C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X81C);
    // 0x8018D9AC: b           L_8018D9C0
    // 0x8018D9B0: sb          $t8, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r24;
        goto L_8018D9C0;
    // 0x8018D9B0: sb          $t8, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r24;
L_8018D9B4:
    // 0x8018D9B4: jr          $ra
    // 0x8018D9B8: sb          $t9, 0xD4($a0)
    MEM_B(0XD4, ctx->r4) = ctx->r25;
    return;
    // 0x8018D9B8: sb          $t9, 0xD4($a0)
    MEM_B(0XD4, ctx->r4) = ctx->r25;
L_8018D9BC:
    // 0x8018D9BC: sb          $t0, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r8;
L_8018D9C0:
    // 0x8018D9C0: lbu         $t1, 0xD3($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XD3);
    // 0x8018D9C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D9C8: bne         $t1, $zero, L_8018D9E8
    if (ctx->r9 != 0) {
        // 0x8018D9CC: nop
    
            goto L_8018D9E8;
    }
    // 0x8018D9CC: nop

    // 0x8018D9D0: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x8018D9D4: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018D9D8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8018D9DC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D9E0: lbu         $t4, 0x81D($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X81D);
    // 0x8018D9E4: sb          $t4, 0xD4($a0)
    MEM_B(0XD4, ctx->r4) = ctx->r12;
L_8018D9E8:
    // 0x8018D9E8: jr          $ra
    // 0x8018D9EC: nop

    return;
    // 0x8018D9EC: nop

;}
RECOMP_FUNC void ftCommonCliffWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144DF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144DF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80144DFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80144E00: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80144E04: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80144E08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144E0C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x80144E10: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144E14: jal         0x800E6F24
    // 0x80144E18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144E18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80144E1C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80144E20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80144E24: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x80144E28: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x80144E2C: beq         $at, $zero, L_80144E40
    if (ctx->r1 == 0) {
        // 0x80144E30: addiu       $t8, $zero, 0x1E0
        ctx->r24 = ADD32(0, 0X1E0);
            goto L_80144E40;
    }
    // 0x80144E30: addiu       $t8, $zero, 0x1E0
    ctx->r24 = ADD32(0, 0X1E0);
    // 0x80144E34: addiu       $t7, $zero, 0x438
    ctx->r15 = ADD32(0, 0X438);
    // 0x80144E38: b           L_80144E44
    // 0x80144E3C: sw          $t7, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r15;
        goto L_80144E44;
    // 0x80144E3C: sw          $t7, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r15;
L_80144E40:
    // 0x80144E40: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
L_80144E44:
    // 0x80144E44: lbu         $t0, 0x190($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X190);
    // 0x80144E48: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80144E4C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80144E50: jal         0x800E7F7C
    // 0x80144E54: sb          $t1, 0x190($s0)
    MEM_B(0X190, ctx->r16) = ctx->r9;
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_1;
    // 0x80144E54: sb          $t1, 0x190($s0)
    MEM_B(0X190, ctx->r16) = ctx->r9;
    after_1:
    // 0x80144E58: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80144E5C: addiu       $t2, $t2, 0x4CF8
    ctx->r10 = ADD32(ctx->r10, 0X4CF8);
    // 0x80144E60: sw          $t2, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r10;
    // 0x80144E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80144E68: jal         0x800E8098
    // 0x80144E6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80144E6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80144E70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80144E74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80144E78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144E7C: jr          $ra
    // 0x80144E80: nop

    return;
    // 0x80144E80: nop

;}
RECOMP_FUNC void ftCaptainAppearStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DF7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013DF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DF84: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DF88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013DF8C: jal         0x8013DA14
    // 0x8013DF90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonAppearUpdateEffects(rdram, ctx);
        goto after_0;
    // 0x8013DF90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013DF94: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DF98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013DF9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013DFA0: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x8013DFA4: bne         $t6, $at, L_8013DFEC
    if (ctx->r14 != ctx->r1) {
        // 0x8013DFA8: nop
    
            goto L_8013DFEC;
    }
    // 0x8013DFA8: nop

    // 0x8013DFAC: lbu         $t7, 0x16($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X16);
    // 0x8013DFB0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8013DFB4: beq         $t7, $at, L_8013DFEC
    if (ctx->r15 == ctx->r1) {
        // 0x8013DFB8: nop
    
            goto L_8013DFEC;
    }
    // 0x8013DFB8: nop

    // 0x8013DFBC: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8013DFC0: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8013DFC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013DFC8: lwc1        $f6, 0x24($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X24);
    // 0x8013DFCC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8013DFD0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8013DFD4: nop

    // 0x8013DFD8: bc1f        L_8013DFEC
    if (!c1cs) {
        // 0x8013DFDC: nop
    
            goto L_8013DFEC;
    }
    // 0x8013DFDC: nop

    // 0x8013DFE0: jal         0x800E827C
    // 0x8013DFE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftParamMoveDLLink(rdram, ctx);
        goto after_1;
    // 0x8013DFE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8013DFE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8013DFEC:
    // 0x8013DFEC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013DFF0: jal         0x800D9480
    // 0x8013DFF4: addiu       $a1, $a1, -0x1FF8
    ctx->r5 = ADD32(ctx->r5, -0X1FF8);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013DFF4: addiu       $a1, $a1, -0x1FF8
    ctx->r5 = ADD32(ctx->r5, -0X1FF8);
    after_2:
    // 0x8013DFF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DFFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013E000: jr          $ra
    // 0x8013E004: nop

    return;
    // 0x8013E004: nop

;}
RECOMP_FUNC void func_ovl8_80371D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371D64: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80371D68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80371D6C: jr          $ra
    // 0x80371D70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80371D70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void ifCommonEntryFocusMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801129DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801129E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801129E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801129E8: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x801129EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801129F0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801129F4: jal         0x80009968
    // 0x801129F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801129F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801129FC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80112A00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80112A04: addiu       $a1, $a1, 0x2880
    ctx->r5 = ADD32(ctx->r5, 0X2880);
    // 0x80112A08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80112A10: jal         0x80008188
    // 0x80112A14: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80112A14: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x80112A18: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80112A1C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80112A20: sw          $t6, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r14;
    // 0x80112A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80112A2C: jr          $ra
    // 0x80112A30: nop

    return;
    // 0x80112A30: nop

;}
RECOMP_FUNC void wpSamusBombProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168F98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80168F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80168FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80168FA4: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80168FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80168FAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80168FB0: jal         0x80167FE8
    // 0x80168FB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80168FB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80168FB8: beq         $v0, $zero, L_80168FE4
    if (ctx->r2 == 0) {
        // 0x80168FBC: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80168FE4;
    }
    // 0x80168FBC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80168FC0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80168FC4: jal         0x801005C8
    // 0x80168FC8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80168FC8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80168FCC: jal         0x80168F2C
    // 0x80168FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpSamusBombExplodeInitVars(rdram, ctx);
        goto after_2;
    // 0x80168FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80168FD4: jal         0x800269C0
    // 0x80168FD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80168FD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80168FDC: b           L_801690F4
    // 0x80168FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801690F4;
    // 0x80168FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168FE4:
    // 0x80168FE4: lw          $t6, 0xFC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XFC);
    // 0x80168FE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80168FEC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80168FF0: bne         $t6, $at, L_80169038
    if (ctx->r14 != ctx->r1) {
        // 0x80168FF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80169038;
    }
    // 0x80168FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80168FF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80168FFC: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80169000: jal         0x80168088
    // 0x80169004: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    wpMainApplyGravityClampTVel(rdram, ctx);
        goto after_4;
    // 0x80169004: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x80169008: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8016900C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80169010: lwc1        $f4, -0x3540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3540);
    // 0x80169014: lw          $t7, 0x18($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X18);
    // 0x80169018: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8016901C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80169020: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80169024: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80169028: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8016902C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80169030: b           L_8016906C
    // 0x80169034: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
        goto L_8016906C;
    // 0x80169034: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
L_80169038:
    // 0x80169038: jal         0x80168044
    // 0x8016903C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    wpMainVelGroundTransferAir(rdram, ctx);
        goto after_5;
    // 0x8016903C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x80169040: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80169044: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80169048: lwc1        $f6, -0x353C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X353C);
    // 0x8016904C: lw          $t8, 0x18($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X18);
    // 0x80169050: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80169054: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80169058: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8016905C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80169060: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80169064: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80169068: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
L_8016906C:
    // 0x8016906C: lw          $t9, 0x29C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X29C);
    // 0x80169070: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80169074: bne         $t0, $zero, L_801690F0
    if (ctx->r8 != 0) {
        // 0x80169078: sw          $t0, 0x29C($a3)
        MEM_W(0X29C, ctx->r7) = ctx->r8;
            goto L_801690F0;
    }
    // 0x80169078: sw          $t0, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r8;
    // 0x8016907C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80169080: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80169084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80169088: lw          $v0, 0x80($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X80);
    // 0x8016908C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80169090: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80169094: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80169098: nop

    // 0x8016909C: bc1tl       L_801690B4
    if (c1cs) {
        // 0x801690A0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_801690B4;
    }
    goto skip_0;
    // 0x801690A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x801690A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801690A8: b           L_801690BC
    // 0x801690AC: swc1        $f8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f8.u32l;
        goto L_801690BC;
    // 0x801690AC: swc1        $f8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f8.u32l;
    // 0x801690B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_801690B4:
    // 0x801690B4: nop

    // 0x801690B8: swc1        $f10, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f10.u32l;
L_801690BC:
    // 0x801690BC: lw          $v0, 0x268($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X268);
    // 0x801690C0: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x801690C4: bnel        $at, $zero, L_801690D8
    if (ctx->r1 != 0) {
        // 0x801690C8: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_801690D8;
    }
    goto skip_1;
    // 0x801690C8: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    skip_1:
    // 0x801690CC: b           L_801690F0
    // 0x801690D0: sw          $t3, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r11;
        goto L_801690F0;
    // 0x801690D0: sw          $t3, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r11;
    // 0x801690D4: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
L_801690D8:
    // 0x801690D8: bne         $at, $zero, L_801690EC
    if (ctx->r1 != 0) {
        // 0x801690DC: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_801690EC;
    }
    // 0x801690DC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801690E0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801690E4: b           L_801690F0
    // 0x801690E8: sw          $t4, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r12;
        goto L_801690F0;
    // 0x801690E8: sw          $t4, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r12;
L_801690EC:
    // 0x801690EC: sw          $t5, 0x29C($a3)
    MEM_W(0X29C, ctx->r7) = ctx->r13;
L_801690F0:
    // 0x801690F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801690F4:
    // 0x801690F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801690F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801690FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80169100: jr          $ra
    // 0x80169104: nop

    return;
    // 0x80169104: nop

;}
RECOMP_FUNC void unref_80002A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002A54: jr          $ra
    // 0x80002A58: sw          $a0, 0x5018($at)
    MEM_W(0X5018, ctx->r1) = ctx->r4;
    return;
    // 0x80002A58: sw          $a0, 0x5018($at)
    MEM_W(0X5018, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void itFFlowerDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175CF4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175CF8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80175CFC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80175D00: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80175D04: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175D08: bne         $t6, $zero, L_80175D20
    if (ctx->r14 != 0) {
        // 0x80175D0C: nop
    
            goto L_80175D20;
    }
    // 0x80175D0C: nop

    // 0x80175D10: jal         0x80173DF4
    // 0x80175D14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x80175D14: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80175D18: b           L_80175D2C
    // 0x80175D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80175D2C;
    // 0x80175D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175D20:
    // 0x80175D20: jal         0x80173B24
    // 0x80175D24: addiu       $a3, $a3, 0x5BB0
    ctx->r7 = ADD32(ctx->r7, 0X5BB0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x80175D24: addiu       $a3, $a3, 0x5BB0
    ctx->r7 = ADD32(ctx->r7, 0X5BB0);
    after_1:
    // 0x80175D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175D2C:
    // 0x80175D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175D30: jr          $ra
    // 0x80175D34: nop

    return;
    // 0x80175D34: nop

;}
RECOMP_FUNC void scStaffrollMakeJobDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A78: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80133A7C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133A80: addiu       $t7, $t7, 0x6B10
    ctx->r15 = ADD32(ctx->r15, 0X6B10);
    // 0x80133A84: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80133A88: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80133A8C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80133A90: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80133A94: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80133A98: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80133A9C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80133AA0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80133AA4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80133AA8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80133AAC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80133AB0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80133AB4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80133AB8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80133ABC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80133AC0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80133AC4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80133AC8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80133ACC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80133AD0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80133AD4: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80133AD8: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80133ADC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80133AE0: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x80133AE4: blez        $v1, L_80133DE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80133AE8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80133DE0;
    }
    // 0x80133AE8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80133AEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80133AF0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80133AF4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80133AF8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80133AFC: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80133B00: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133B04: addiu       $t9, $t9, 0x685C
    ctx->r25 = ADD32(ctx->r25, 0X685C);
    // 0x80133B08: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80133B0C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80133B10: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x80133B14: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80133B18: addiu       $fp, $zero, 0x1E
    ctx->r30 = ADD32(0, 0X1E);
    // 0x80133B1C: addiu       $s7, $zero, 0x1A
    ctx->r23 = ADD32(0, 0X1A);
    // 0x80133B20: addiu       $s6, $zero, 0x32
    ctx->r22 = ADD32(0, 0X32);
    // 0x80133B24: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
    // 0x80133B28: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
L_80133B2C:
    // 0x80133B2C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133B30: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80133B34: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133B38: bne         $v0, $at, L_80133B50
    if (ctx->r2 != ctx->r1) {
        // 0x80133B3C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80133B50;
    }
    // 0x80133B3C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80133B40: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80133B44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133B48: b           L_80133DC4
    // 0x80133B4C: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
        goto L_80133DC4;
    // 0x80133B4C: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_80133B50:
    // 0x80133B50: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80133B54: addiu       $t2, $t2, -0x5E78
    ctx->r10 = ADD32(ctx->r10, -0X5E78);
    // 0x80133B58: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80133B5C: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80133B60: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80133B64: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80133B68: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80133B6C: lw          $a1, -0x5828($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5828);
    // 0x80133B70: bgez        $t3, L_80133B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80133B74: cvt.s.w     $f22, $f6
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80133B88;
    }
    // 0x80133B74: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133B78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133B7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133B80: nop

    // 0x80133B84: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
L_80133B88:
    // 0x80133B88: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x80133B8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133B90: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80133B94: bgez        $t4, L_80133BA8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80133B98: cvt.s.w     $f24, $f10
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80133BA8;
    }
    // 0x80133B98: cvt.s.w     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133B9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133BA0: nop

    // 0x80133BA4: add.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f16.fl;
L_80133BA8:
    // 0x80133BA8: jal         0x800093F4
    // 0x80133BAC: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x80133BAC: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    after_0:
    // 0x80133BB0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133BB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133BB8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80133BBC: jal         0x80008CC0
    // 0x80133BC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80133BC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80133BC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133BC8: beq         $s0, $at, L_80133D24
    if (ctx->r16 == ctx->r1) {
        // 0x80133BCC: sub.s       $f18, $f24, $f26
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f26.fl;
            goto L_80133D24;
    }
    // 0x80133BCC: sub.s       $f18, $f24, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80133BD0: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80133BD4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133BD8: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80133BDC: lw          $v1, 0x685C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X685C);
    // 0x80133BE0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80133BE4: beq         $v1, $at, L_80133C0C
    if (ctx->r3 == ctx->r1) {
        // 0x80133BE8: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80133C0C;
    }
    // 0x80133BE8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80133BEC: beq         $v1, $at, L_80133C0C
    if (ctx->r3 == ctx->r1) {
        // 0x80133BF0: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80133C0C;
    }
    // 0x80133BF0: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80133BF4: beq         $v1, $at, L_80133C0C
    if (ctx->r3 == ctx->r1) {
        // 0x80133BF8: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80133C0C;
    }
    // 0x80133BF8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80133BFC: beq         $v1, $at, L_80133C0C
    if (ctx->r3 == ctx->r1) {
        // 0x80133C00: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80133C0C;
    }
    // 0x80133C00: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80133C04: bnel        $v1, $at, L_80133CA8
    if (ctx->r3 != ctx->r1) {
        // 0x80133C08: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80133CA8;
    }
    goto skip_0;
    // 0x80133C08: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_0:
L_80133C0C:
    // 0x80133C0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133C10: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80133C14: beq         $s7, $v0, L_80133C9C
    if (ctx->r23 == ctx->r2) {
        // 0x80133C18: nop
    
            goto L_80133C9C;
    }
    // 0x80133C18: nop

    // 0x80133C1C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C20: nop
    
            goto L_80133C9C;
    }
    // 0x80133C20: nop

    // 0x80133C24: beq         $fp, $v0, L_80133C9C
    if (ctx->r30 == ctx->r2) {
        // 0x80133C28: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_80133C9C;
    }
    // 0x80133C28: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80133C2C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C30: addiu       $at, $zero, 0x26
        ctx->r1 = ADD32(0, 0X26);
            goto L_80133C9C;
    }
    // 0x80133C30: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80133C34: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C38: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_80133C9C;
    }
    // 0x80133C38: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80133C3C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C40: nop
    
            goto L_80133C9C;
    }
    // 0x80133C40: nop

    // 0x80133C44: beq         $s5, $v0, L_80133C9C
    if (ctx->r21 == ctx->r2) {
        // 0x80133C48: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80133C9C;
    }
    // 0x80133C48: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80133C4C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C50: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_80133C9C;
    }
    // 0x80133C50: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80133C54: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C58: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80133C9C;
    }
    // 0x80133C58: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80133C5C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C60: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_80133C9C;
    }
    // 0x80133C60: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80133C64: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C68: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80133C9C;
    }
    // 0x80133C68: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80133C6C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C70: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_80133C9C;
    }
    // 0x80133C70: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80133C74: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C78: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_80133C9C;
    }
    // 0x80133C78: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80133C7C: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C80: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_80133C9C;
    }
    // 0x80133C80: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80133C84: beq         $v0, $at, L_80133C9C
    if (ctx->r2 == ctx->r1) {
        // 0x80133C88: nop
    
            goto L_80133C9C;
    }
    // 0x80133C88: nop

    // 0x80133C8C: beq         $s6, $v0, L_80133C9C
    if (ctx->r22 == ctx->r2) {
        // 0x80133C90: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_80133C9C;
    }
    // 0x80133C90: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80133C94: bnel        $v0, $at, L_80133CA8
    if (ctx->r2 != ctx->r1) {
        // 0x80133C98: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80133CA8;
    }
    goto skip_1;
    // 0x80133C98: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_1:
L_80133C9C:
    // 0x80133C9C: b           L_80133D24
    // 0x80133CA0: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
        goto L_80133D24;
    // 0x80133CA0: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
    // 0x80133CA4: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
L_80133CA8:
    // 0x80133CA8: beq         $v1, $at, L_80133CC0
    if (ctx->r3 == ctx->r1) {
        // 0x80133CAC: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80133CC0;
    }
    // 0x80133CAC: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x80133CB0: beql        $v1, $at, L_80133CC4
    if (ctx->r3 == ctx->r1) {
        // 0x80133CB4: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_80133CC4;
    }
    goto skip_2;
    // 0x80133CB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80133CB8: bne         $s6, $v1, L_80133CE4
    if (ctx->r22 != ctx->r3) {
        // 0x80133CBC: nop
    
            goto L_80133CE4;
    }
    // 0x80133CBC: nop

L_80133CC0:
    // 0x80133CC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80133CC4:
    // 0x80133CC4: beq         $s7, $v0, L_80133CDC
    if (ctx->r23 == ctx->r2) {
        // 0x80133CC8: nop
    
            goto L_80133CDC;
    }
    // 0x80133CC8: nop

    // 0x80133CCC: beq         $fp, $v0, L_80133CDC
    if (ctx->r30 == ctx->r2) {
        // 0x80133CD0: nop
    
            goto L_80133CDC;
    }
    // 0x80133CD0: nop

    // 0x80133CD4: bne         $s5, $v0, L_80133CE4
    if (ctx->r21 != ctx->r2) {
        // 0x80133CD8: nop
    
            goto L_80133CE4;
    }
    // 0x80133CD8: nop

L_80133CDC:
    // 0x80133CDC: b           L_80133D24
    // 0x80133CE0: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
        goto L_80133D24;
    // 0x80133CE0: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
L_80133CE4:
    // 0x80133CE4: bnel        $s5, $v1, L_80133D08
    if (ctx->r21 != ctx->r3) {
        // 0x80133CE8: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80133D08;
    }
    goto skip_3;
    // 0x80133CE8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_3:
    // 0x80133CEC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80133CF0: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80133CF4: bnel        $t6, $at, L_80133D08
    if (ctx->r14 != ctx->r1) {
        // 0x80133CF8: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80133D08;
    }
    goto skip_4;
    // 0x80133CF8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_4:
    // 0x80133CFC: b           L_80133D24
    // 0x80133D00: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
        goto L_80133D24;
    // 0x80133D00: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
    // 0x80133D04: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_80133D08:
    // 0x80133D08: bnel        $v1, $at, L_80133D28
    if (ctx->r3 != ctx->r1) {
        // 0x80133D0C: add.s       $f0, $f20, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80133D28;
    }
    goto skip_5;
    // 0x80133D0C: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
    skip_5:
    // 0x80133D10: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80133D14: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80133D18: bnel        $t7, $at, L_80133D28
    if (ctx->r15 != ctx->r1) {
        // 0x80133D1C: add.s       $f0, $f20, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80133D28;
    }
    goto skip_6;
    // 0x80133D1C: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
    skip_6:
    // 0x80133D20: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
L_80133D24:
    // 0x80133D24: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
L_80133D28:
    // 0x80133D28: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
    // 0x80133D2C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80133D30: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x80133D34: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133D38: add.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80133D3C: bne         $v0, $at, L_80133D58
    if (ctx->r2 != ctx->r1) {
        // 0x80133D40: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80133D58;
    }
    // 0x80133D40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133D44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133D48: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80133D4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80133D50: swc1        $f8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f8.u32l;
    // 0x80133D54: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80133D58:
    // 0x80133D58: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80133D5C: bnel        $v0, $at, L_80133D74
    if (ctx->r2 != ctx->r1) {
        // 0x80133D60: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_80133D74;
    }
    goto skip_7;
    // 0x80133D60: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    skip_7:
    // 0x80133D64: sub.s       $f10, $f26, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f24.fl;
    // 0x80133D68: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    // 0x80133D6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133D70: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
L_80133D74:
    // 0x80133D74: bnel        $v0, $at, L_80133D90
    if (ctx->r2 != ctx->r1) {
        // 0x80133D78: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_80133D90;
    }
    goto skip_8;
    // 0x80133D78: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_8:
    // 0x80133D7C: lwc1        $f16, 0x20($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80133D80: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x80133D84: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
    // 0x80133D88: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133D8C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_80133D90:
    // 0x80133D90: beq         $v0, $at, L_80133DAC
    if (ctx->r2 == ctx->r1) {
        // 0x80133D94: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80133DAC;
    }
    // 0x80133D94: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80133D98: beq         $v0, $at, L_80133DAC
    if (ctx->r2 == ctx->r1) {
        // 0x80133D9C: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_80133DAC;
    }
    // 0x80133D9C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80133DA0: beql        $v0, $at, L_80133DB0
    if (ctx->r2 == ctx->r1) {
        // 0x80133DA4: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_80133DB0;
    }
    goto skip_9;
    // 0x80133DA4: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    skip_9:
    // 0x80133DA8: bne         $s6, $v0, L_80133DBC
    if (ctx->r22 != ctx->r2) {
        // 0x80133DAC: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_80133DBC;
    }
L_80133DAC:
    // 0x80133DAC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
L_80133DB0:
    // 0x80133DB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133DB4: nop

    // 0x80133DB8: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
L_80133DBC:
    // 0x80133DBC: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80133DC0: lw          $v1, 0x4($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X4);
L_80133DC4:
    // 0x80133DC4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80133DC8: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80133DCC: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80133DD0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80133DD4: bne         $at, $zero, L_80133B2C
    if (ctx->r1 != 0) {
        // 0x80133DD8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80133B2C;
    }
    // 0x80133DD8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133DDC: sw          $s2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r18;
L_80133DE0:
    // 0x80133DE0: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x80133DE4: swc1        $f20, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f20.u32l;
    // 0x80133DE8: addiu       $t0, $sp, 0x9C
    ctx->r8 = ADD32(ctx->r29, 0X9C);
    // 0x80133DEC: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80133DF0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80133DF4: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80133DF8: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80133DFC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80133E00: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80133E04: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80133E08: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80133E0C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80133E10: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x80133E14: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x80133E18: sw          $t2, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r10;
    // 0x80133E1C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80133E20: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80133E24: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80133E28: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80133E2C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80133E30: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80133E34: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80133E38: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80133E3C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80133E40: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80133E44: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80133E48: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80133E4C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80133E50: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80133E54: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133E58: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133E5C: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x80133E60: jr          $ra
    // 0x80133E64: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80133E64: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_ovl2_800EE2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE2C0: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE2C4: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EE2C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800EE2CC: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800EE2D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800EE2D4: nop

    // 0x800EE2D8: bc1fl       L_800EE2E8
    if (!c1cs) {
        // 0x800EE2DC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800EE2E8;
    }
    goto skip_0;
    // 0x800EE2DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x800EE2E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EE2E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800EE2E8:
    // 0x800EE2E8: nop

    // 0x800EE2EC: bc1f        L_800EE2F8
    if (!c1cs) {
        // 0x800EE2F0: nop
    
            goto L_800EE2F8;
    }
    // 0x800EE2F0: nop

    // 0x800EE2F4: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
L_800EE2F8:
    // 0x800EE2F8: jr          $ra
    // 0x800EE2FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EE2FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftCommonThrownCopyStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C63C: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    // 0x8014C640: jal         0x8014BE90
    // 0x8014C644: lui         $a2, 0x438C
    ctx->r6 = S32(0X438C << 16);
    ftCommonThrownKirbyStarMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8014C644: lui         $a2, 0x438C
    ctx->r6 = S32(0X438C << 16);
    after_0:
    // 0x8014C648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C64C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C650: jr          $ra
    // 0x8014C654: nop

    return;
    // 0x8014C654: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCheckFighterLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EFC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131F00: beq         $a0, $at, L_80131F9C
    if (ctx->r4 == ctx->r1) {
        // 0x80131F04: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80131F9C;
    }
    // 0x80131F04: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80131F08: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80131F0C: beq         $a0, $at, L_80131F78
    if (ctx->r4 == ctx->r1) {
        // 0x80131F10: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_80131F78;
    }
    // 0x80131F10: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80131F14: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80131F18: beq         $a0, $at, L_80131F54
    if (ctx->r4 == ctx->r1) {
        // 0x80131F1C: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_80131F54;
    }
    // 0x80131F1C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80131F20: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80131F24: bne         $a0, $at, L_80131FC0
    if (ctx->r4 != ctx->r1) {
        // 0x80131F28: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131FC0;
    }
    // 0x80131F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131F2C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131F30: lhu         $t6, -0x7784($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X7784);
    // 0x80131F34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131F38: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80131F3C: beq         $t7, $zero, L_80131F4C
    if (ctx->r15 == 0) {
        // 0x80131F40: nop
    
            goto L_80131F4C;
    }
    // 0x80131F40: nop

    // 0x80131F44: jr          $ra
    // 0x80131F48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131F48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131F4C:
    // 0x80131F4C: jr          $ra
    // 0x80131F50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131F50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131F54:
    // 0x80131F54: lhu         $t8, -0x7784($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X7784);
    // 0x80131F58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131F5C: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80131F60: beq         $t9, $zero, L_80131F70
    if (ctx->r25 == 0) {
        // 0x80131F64: nop
    
            goto L_80131F70;
    }
    // 0x80131F64: nop

    // 0x80131F68: jr          $ra
    // 0x80131F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131F70:
    // 0x80131F70: jr          $ra
    // 0x80131F74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131F74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131F78:
    // 0x80131F78: lhu         $t0, -0x7784($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X7784);
    // 0x80131F7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131F80: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80131F84: beq         $t1, $zero, L_80131F94
    if (ctx->r9 == 0) {
        // 0x80131F88: nop
    
            goto L_80131F94;
    }
    // 0x80131F88: nop

    // 0x80131F8C: jr          $ra
    // 0x80131F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131F94:
    // 0x80131F94: jr          $ra
    // 0x80131F98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131F98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131F9C:
    // 0x80131F9C: lhu         $t2, -0x7784($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X7784);
    // 0x80131FA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131FA4: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80131FA8: beq         $t3, $zero, L_80131FB8
    if (ctx->r11 == 0) {
        // 0x80131FAC: nop
    
            goto L_80131FB8;
    }
    // 0x80131FAC: nop

    // 0x80131FB0: jr          $ra
    // 0x80131FB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131FB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131FB8:
    // 0x80131FB8: jr          $ra
    // 0x80131FBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131FBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131FC0:
    // 0x80131FC0: jr          $ra
    // 0x80131FC4: nop

    return;
    // 0x80131FC4: nop

;}
RECOMP_FUNC void func_ovl8_8037D95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D95C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D960: addiu       $t6, $t6, -0x470
    ctx->r14 = ADD32(ctx->r14, -0X470);
    // 0x8037D964: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8037D968: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8037D96C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8037D970: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8037D974: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8037D978: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8037D97C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8037D980: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8037D984: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8037D988: jr          $ra
    // 0x8037D98C: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    return;
    // 0x8037D98C: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
;}

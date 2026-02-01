#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_8037D434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D434: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8037D438: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D43C: addiu       $t6, $t6, -0x1020
    ctx->r14 = ADD32(ctx->r14, -0X1020);
    // 0x8037D440: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8037D444: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8037D448: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037D44C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8037D450: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8037D454: jr          $ra
    // 0x8037D458: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    return;
    // 0x8037D458: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void dbMenuMakeMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369D78: lui         $t0, 0x8037
    ctx->r8 = S32(0X8037 << 16);
    // 0x80369D7C: addiu       $t0, $t0, 0x1420
    ctx->r8 = ADD32(ctx->r8, 0X1420);
    // 0x80369D80: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80369D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80369D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80369D90: bne         $t6, $zero, L_80369EB0
    if (ctx->r14 != 0) {
        // 0x80369D94: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80369EB0;
    }
    // 0x80369D94: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80369D98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80369D9C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80369DA0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80369DA4: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369DA8: sw          $a3, 0x140C($at)
    MEM_W(0X140C, ctx->r1) = ctx->r7;
    // 0x80369DAC: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369DB0: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x80369DB4: sw          $v0, 0x1410($at)
    MEM_W(0X1410, ctx->r1) = ctx->r2;
    // 0x80369DB8: addiu       $v1, $v1, 0x141C
    ctx->r3 = ADD32(ctx->r3, 0X141C);
    // 0x80369DBC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80369DC0: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369DC4: sw          $zero, 0x1414($at)
    MEM_W(0X1414, ctx->r1) = 0;
    // 0x80369DC8: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369DCC: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369DD0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80369DD4: addiu       $a0, $a0, -0x6084
    ctx->r4 = ADD32(ctx->r4, -0X6084);
    // 0x80369DD8: sw          $t1, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->r9;
    // 0x80369DDC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x80369DE0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80369DE4: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80369DE8: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x80369DEC: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x80369DF0: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x80369DF4: sh          $t4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r12;
    // 0x80369DF8: jal         0x80381C80
    // 0x80369DFC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    func_ovl8_80381C80(rdram, ctx);
        goto after_0;
    // 0x80369DFC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    after_0:
    // 0x80369E00: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x80369E04: addiu       $v1, $v1, 0x1404
    ctx->r3 = ADD32(ctx->r3, 0X1404);
    // 0x80369E08: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80369E0C: jal         0x80374910
    // 0x80369E10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_ovl8_80374910(rdram, ctx);
        goto after_1;
    // 0x80369E10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80369E14: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369E18: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369E1C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369E20: sw          $v0, 0x1408($at)
    MEM_W(0X1408, ctx->r1) = ctx->r2;
    // 0x80369E24: addiu       $a1, $a1, -0x6098
    ctx->r5 = ADD32(ctx->r5, -0X6098);
    // 0x80369E28: jal         0x80369358
    // 0x80369E2C: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    dbMenuDrawBorder(rdram, ctx);
        goto after_2;
    // 0x80369E2C: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_2:
    // 0x80369E30: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369E34: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    // 0x80369E38: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80369E3C: jal         0x80369600
    // 0x80369E40: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    dbMenuDrawMenuOptions(rdram, ctx);
        goto after_3;
    // 0x80369E40: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80369E44: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369E48: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369E4C: lw          $a1, 0x1414($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1414);
    // 0x80369E50: jal         0x80369680
    // 0x80369E54: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    dbMenuDrawCursor(rdram, ctx);
        goto after_4;
    // 0x80369E54: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_4:
    // 0x80369E58: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x80369E5C: addiu       $v1, $v1, 0x1408
    ctx->r3 = ADD32(ctx->r3, 0X1408);
    // 0x80369E60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80369E64: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369E68: lui         $t6, 0x8037
    ctx->r14 = S32(0X8037 << 16);
    // 0x80369E6C: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x80369E70: addiu       $t6, $t6, -0x692C
    ctx->r14 = ADD32(ctx->r14, -0X692C);
    // 0x80369E74: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369E78: sw          $t5, 0x1418($at)
    MEM_W(0X1418, ctx->r1) = ctx->r13;
    // 0x80369E7C: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80369E80: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80369E84: addiu       $a1, $a1, -0x68A4
    ctx->r5 = ADD32(ctx->r5, -0X68A4);
    // 0x80369E88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80369E8C: jal         0x80008188
    // 0x80369E90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80369E90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80369E94: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80369E98: addiu       $v1, $v1, 0x6640
    ctx->r3 = ADD32(ctx->r3, 0X6640);
    // 0x80369E9C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80369EA0: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369EA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80369EA8: sw          $t7, 0x1424($at)
    MEM_W(0X1424, ctx->r1) = ctx->r15;
    // 0x80369EAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80369EB0:
    // 0x80369EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80369EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80369EB8: jr          $ra
    // 0x80369EBC: nop

    return;
    // 0x80369EBC: nop

;}
RECOMP_FUNC void ftFoxSpecialLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D188: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015D18C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015D190: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x8015D194: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D198: jal         0x800E6F24
    // 0x8015D19C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D19C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D1A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D1A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D1A8: jr          $ra
    // 0x8015D1AC: nop

    return;
    // 0x8015D1AC: nop

;}
RECOMP_FUNC void mpCollisionAdvanceUpdateTic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBCF8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FBCFC: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, 0X1398);
    // 0x800FBD00: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800FBD04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800FBD08: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800FBD0C: jr          $ra
    // 0x800FBD10: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800FBD10: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void alSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F8DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002F8E0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8002F8E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002F8E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002F8EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002F8F0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8002F8F4: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8002F8F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002F8FC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8002F900: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002F904: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002F908: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002F90C: bne         $a2, $zero, L_8002F92C
    if (ctx->r6 != 0) {
        // 0x8002F910: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_8002F92C;
    }
    // 0x8002F910: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002F914: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8002F918: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x8002F91C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8002F920: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8002F924: b           L_8002F9D0
    // 0x8002F928: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_8002F9D0;
    // 0x8002F928: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_8002F92C:
    // 0x8002F92C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8002F930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002F934: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8002F938: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8002F93C: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x8002F940: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x8002F944: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x8002F948: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8002F94C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8002F950: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8002F954: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x8002F958: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8002F95C: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x8002F960: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
L_8002F964:
    // 0x8002F964: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x8002F968: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002F96C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F970: jal         0x8002F758
    // 0x8002F974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x8002F974: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8002F978: lh          $t1, 0x50($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X50);
    // 0x8002F97C: bnel        $t1, $s3, L_8002F998
    if (ctx->r9 != ctx->r19) {
        // 0x8002F980: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_8002F998;
    }
    goto skip_0;
    // 0x8002F980: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8002F984: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    // 0x8002F988: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x8002F98C: b           L_8002F9A4
    // 0x8002F990: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
        goto L_8002F9A4;
    // 0x8002F990: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
    // 0x8002F994: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_8002F998:
    // 0x8002F998: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x8002F99C: bnel        $at, $zero, L_8002F964
    if (ctx->r1 != 0) {
        // 0x8002F9A0: lw          $s4, 0x8($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X8);
            goto L_8002F964;
    }
    goto skip_1;
    // 0x8002F9A0: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_8002F9A4:
    // 0x8002F9A4: sw          $s4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r20;
    // 0x8002F9A8: sh          $s5, 0xC($s7)
    MEM_H(0XC, ctx->r23) = ctx->r21;
    // 0x8002F9AC: sw          $s6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r22;
    // 0x8002F9B0: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8002F9B4: sw          $t2, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r10;
    // 0x8002F9B8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F9BC: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8002F9C0: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x8002F9C4: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x8002F9C8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002F9CC: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_8002F9D0:
    // 0x8002F9D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002F9D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002F9D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002F9DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F9E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002F9E4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002F9E8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002F9EC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F9F0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8002F9F4: jr          $ra
    // 0x8002F9F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8002F9F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_803879FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803879FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80387A00: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80387A04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80387A08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80387A0C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80387A10: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80387A14: bne         $a0, $zero, L_80387A2C
    if (ctx->r4 != 0) {
        // 0x80387A18: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_80387A2C;
    }
    // 0x80387A18: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80387A1C: jal         0x803717A0
    // 0x80387A20: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80387A20: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x80387A24: beq         $v0, $zero, L_80387AE4
    if (ctx->r2 == 0) {
        // 0x80387A28: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80387AE4;
    }
    // 0x80387A28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80387A2C:
    // 0x80387A2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80387A30: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80387A34: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x80387A38: bnel        $t6, $zero, L_80387A5C
    if (ctx->r14 != 0) {
        // 0x80387A3C: lw          $a3, 0x44($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X44);
            goto L_80387A5C;
    }
    goto skip_0;
    // 0x80387A3C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80387A40: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80387A44: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80387A48: jal         0x803717E0
    // 0x80387A4C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80387A4C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x80387A50: jal         0x8037C2D0
    // 0x80387A54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80387A54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80387A58: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_80387A5C:
    // 0x80387A5C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80387A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80387A64: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x80387A68: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80387A6C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80387A70: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80387A74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80387A78: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80387A7C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80387A80: jal         0x8037C7D4
    // 0x80387A84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_ovl8_8037C7D4(rdram, ctx);
        goto after_3;
    // 0x80387A84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80387A88: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80387A8C: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // 0x80387A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80387A94: lw          $a1, 0x24($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X24);
    // 0x80387A98: jal         0x80381934
    // 0x80387A9C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_ovl8_80381934(rdram, ctx);
        goto after_4;
    // 0x80387A9C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_4:
    // 0x80387AA0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80387AA4: addiu       $t2, $t2, -0x1520
    ctx->r10 = ADD32(ctx->r10, -0X1520);
    // 0x80387AA8: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x80387AAC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80387AB0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80387AB4: addiu       $t3, $t3, -0x1440
    ctx->r11 = ADD32(ctx->r11, -0X1440);
    // 0x80387AB8: sw          $t3, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->r11;
    // 0x80387ABC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80387AC0: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80387AC4: addiu       $t5, $t5, -0x12E8
    ctx->r13 = ADD32(ctx->r13, -0X12E8);
    // 0x80387AC8: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80387ACC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80387AD0: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x80387AD4: addiu       $t8, $t8, -0x1258
    ctx->r24 = ADD32(ctx->r24, -0X1258);
    // 0x80387AD8: addiu       $t7, $t7, -0x12C0
    ctx->r15 = ADD32(ctx->r15, -0X12C0);
    // 0x80387ADC: sw          $t7, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r15;
    // 0x80387AE0: sw          $t8, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r24;
L_80387AE4:
    // 0x80387AE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80387AE8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80387AEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80387AF0: jr          $ra
    // 0x80387AF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80387AF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void syMatrixRotRpyDF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D440: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D444: lwc1        $f0, -0x1C2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C2C);
    // 0x8001D448: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D44C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D454: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001D458: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001D45C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D460: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001D464: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D468: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D46C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001D470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D474: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D478: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001D47C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8001D480: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D484: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8001D488: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8001D48C: jal         0x8001BDEC
    // 0x8001D490: nop

    syMatrixRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001D490: nop

    after_0:
    // 0x8001D494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D49C: jr          $ra
    // 0x8001D4A0: nop

    return;
    // 0x8001D4A0: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNReleaseSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E6C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E6C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E6C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E6CC: jal         0x800DEE98
    // 0x8015E6D0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015E6D0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E6D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E6D8: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015E6DC: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015E6E0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E6E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E6E8: jal         0x800E6F24
    // 0x8015E6EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E6EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E6F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E6F8: jr          $ra
    // 0x8015E6FC: nop

    return;
    // 0x8015E6FC: nop

;}
RECOMP_FUNC void itBatFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174E98: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174E9C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174EA0: addiu       $a3, $a3, 0x4EC4
    ctx->r7 = ADD32(ctx->r7, 0X4EC4);
    // 0x80174EA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174EA8: jal         0x80173B24
    // 0x80174EAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174EAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174EBC: jr          $ra
    // 0x80174EC0: nop

    return;
    // 0x80174EC0: nop

;}
RECOMP_FUNC void func_ovl8_80374A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374A54: beq         $a0, $zero, L_80374A60
    if (ctx->r4 == 0) {
        // 0x80374A58: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80374A60;
    }
    // 0x80374A58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80374A5C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80374A60:
    // 0x80374A60: lwl         $t7, 0x2($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X2);
    // 0x80374A64: lwr         $t7, 0x5($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X5);
    // 0x80374A68: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x80374A6C: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x80374A70: lwl         $t6, 0x6($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0X6);
    // 0x80374A74: lwr         $t6, 0x9($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0X9);
    // 0x80374A78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80374A7C: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x80374A80: beq         $a0, $zero, L_80374A8C
    if (ctx->r4 == 0) {
        // 0x80374A84: swr         $t6, 0x7($a1)
        do_swr(rdram, 0X7, ctx->r5, ctx->r14);
            goto L_80374A8C;
    }
    // 0x80374A84: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    // 0x80374A88: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80374A8C:
    // 0x80374A8C: lwl         $t9, 0x14($v0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r2, 0X14);
    // 0x80374A90: lwr         $t9, 0x17($v0)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r2, 0X17);
    // 0x80374A94: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80374A98: swl         $t9, 0x8($a1)
    do_swl(rdram, 0X8, ctx->r5, ctx->r25);
    // 0x80374A9C: beq         $a0, $zero, L_80374AA8
    if (ctx->r4 == 0) {
        // 0x80374AA0: swr         $t9, 0xB($a1)
        do_swr(rdram, 0XB, ctx->r5, ctx->r25);
            goto L_80374AA8;
    }
    // 0x80374AA0: swr         $t9, 0xB($a1)
    do_swr(rdram, 0XB, ctx->r5, ctx->r25);
    // 0x80374AA4: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80374AA8:
    // 0x80374AA8: lwl         $t1, 0x18($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r2, 0X18);
    // 0x80374AAC: lwr         $t1, 0x1B($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r2, 0X1B);
    // 0x80374AB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80374AB4: swl         $t1, 0xC($a1)
    do_swl(rdram, 0XC, ctx->r5, ctx->r9);
    // 0x80374AB8: beq         $a0, $zero, L_80374AC4
    if (ctx->r4 == 0) {
        // 0x80374ABC: swr         $t1, 0xF($a1)
        do_swr(rdram, 0XF, ctx->r5, ctx->r9);
            goto L_80374AC4;
    }
    // 0x80374ABC: swr         $t1, 0xF($a1)
    do_swr(rdram, 0XF, ctx->r5, ctx->r9);
    // 0x80374AC0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80374AC4:
    // 0x80374AC4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80374AC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80374ACC: beq         $a0, $zero, L_80374AD8
    if (ctx->r4 == 0) {
        // 0x80374AD0: sw          $t2, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r10;
            goto L_80374AD8;
    }
    // 0x80374AD0: sw          $t2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r10;
    // 0x80374AD4: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80374AD8:
    // 0x80374AD8: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80374ADC: jr          $ra
    // 0x80374AE0: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    return;
    // 0x80374AE0: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void mnVSRecordGetRanking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339D0: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x801339D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801339D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801339DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801339E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x801339E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x801339E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801339EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801339F0: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x801339F4: addiu       $s1, $sp, 0xE8
    ctx->r17 = ADD32(ctx->r29, 0XE8);
    // 0x801339F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_801339FC:
    // 0x801339FC: jal         0x80131B24
    // 0x80133A00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mnVSRecordGetFighterKindByIndex(rdram, ctx);
        goto after_0;
    // 0x80133A00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80133A04: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80133A08: slti        $at, $s3, 0xC
    ctx->r1 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
    // 0x80133A0C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133A10: bne         $at, $zero, L_801339FC
    if (ctx->r1 != 0) {
        // 0x80133A14: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_801339FC;
    }
    // 0x80133A14: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80133A18: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80133A1C: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
L_80133A20:
    // 0x80133A20: jal         0x80131D38
    // 0x80133A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mnVSRecordGetWinPercent(rdram, ctx);
        goto after_1;
    // 0x80133A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80133A28: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80133A2C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80133A30: slti        $at, $s3, 0xC
    ctx->r1 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
    // 0x80133A34: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80133A38: bne         $at, $zero, L_80133A20
    if (ctx->r1 != 0) {
        // 0x80133A3C: sdc1        $f4, -0x8($s0)
        CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, -0X8, ctx->r16);
            goto L_80133A20;
    }
    // 0x80133A3C: sdc1        $f4, -0x8($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, -0X8, ctx->r16);
    // 0x80133A40: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80133A44: addiu       $s4, $sp, 0x118
    ctx->r20 = ADD32(ctx->r29, 0X118);
    // 0x80133A48: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
L_80133A4C:
    // 0x80133A4C: addiu       $s5, $s3, 0x1
    ctx->r21 = ADD32(ctx->r19, 0X1);
    // 0x80133A50: slti        $at, $s5, 0xC
    ctx->r1 = SIGNED(ctx->r21) < 0XC ? 1 : 0;
    // 0x80133A54: beq         $at, $zero, L_80133ADC
    if (ctx->r1 == 0) {
        // 0x80133A58: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_80133ADC;
    }
    // 0x80133A58: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80133A5C: addiu       $t7, $sp, 0xE8
    ctx->r15 = ADD32(ctx->r29, 0XE8);
    // 0x80133A60: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80133A64: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80133A68: addu        $s0, $t8, $t7
    ctx->r16 = ADD32(ctx->r24, ctx->r15);
    // 0x80133A6C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
L_80133A70:
    // 0x80133A70: jal         0x801326EC
    // 0x80133A74: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_2;
    // 0x80133A74: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80133A78: beql        $v0, $zero, L_80133AC4
    if (ctx->r2 == 0) {
        // 0x80133A7C: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80133AC4;
    }
    goto skip_0;
    // 0x80133A7C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80133A80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80133A84: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80133A88: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x80133A8C: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x80133A90: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80133A94: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80133A98: ldc1        $f8, 0x0($t6)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r14, 0X0);
    // 0x80133A9C: ldc1        $f6, 0x0($t4)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r12, 0X0);
    // 0x80133AA0: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80133AA4: nop

    // 0x80133AA8: bc1fl       L_80133AD4
    if (!c1cs) {
        // 0x80133AAC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80133AD4;
    }
    goto skip_1;
    // 0x80133AAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80133AB0: jal         0x801326EC
    // 0x80133AB4: nop

    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_3;
    // 0x80133AB4: nop

    after_3:
    // 0x80133AB8: beql        $v0, $zero, L_80133AD4
    if (ctx->r2 == 0) {
        // 0x80133ABC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80133AD4;
    }
    goto skip_2;
    // 0x80133ABC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x80133AC0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80133AC4:
    // 0x80133AC4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133AC8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80133ACC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80133AD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80133AD4:
    // 0x80133AD4: bne         $s0, $s4, L_80133A70
    if (ctx->r16 != ctx->r20) {
        // 0x80133AD8: nop
    
            goto L_80133A70;
    }
    // 0x80133AD8: nop

L_80133ADC:
    // 0x80133ADC: slti        $at, $s5, 0xC
    ctx->r1 = SIGNED(ctx->r21) < 0XC ? 1 : 0;
    // 0x80133AE0: bne         $at, $zero, L_80133A4C
    if (ctx->r1 != 0) {
        // 0x80133AE4: or          $s3, $s5, $zero
        ctx->r19 = ctx->r21 | 0;
            goto L_80133A4C;
    }
    // 0x80133AE4: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80133AE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133AEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80133AF0: addiu       $s1, $sp, 0xE8
    ctx->r17 = ADD32(ctx->r29, 0XE8);
    // 0x80133AF4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80133AF8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80133AFC: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80133B00: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80133B04: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80133B08: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
L_80133B0C:
    // 0x80133B0C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80133B10: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80133B14: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80133B18: beq         $s3, $a2, L_80133B50
    if (ctx->r19 == ctx->r6) {
        // 0x80133B1C: sw          $v0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r2;
            goto L_80133B50;
    }
    // 0x80133B1C: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80133B20: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80133B24: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80133B28: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80133B2C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80133B30: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80133B34: ldc1        $f16, 0x0($t8)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r24, 0X0);
    // 0x80133B38: ldc1        $f10, 0x0($t4)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r12, 0X0);
    // 0x80133B3C: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x80133B40: nop

    // 0x80133B44: bc1tl       L_80133B54
    if (c1cs) {
        // 0x80133B48: lw          $v1, 0x4($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X4);
            goto L_80133B54;
    }
    goto skip_3;
    // 0x80133B48: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    skip_3:
    // 0x80133B4C: addiu       $v0, $s3, 0x2
    ctx->r2 = ADD32(ctx->r19, 0X2);
L_80133B50:
    // 0x80133B50: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
L_80133B54:
    // 0x80133B54: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80133B58: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80133B5C: beq         $s3, $a3, L_80133B94
    if (ctx->r19 == ctx->r7) {
        // 0x80133B60: sw          $v0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r2;
            goto L_80133B94;
    }
    // 0x80133B60: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80133B64: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80133B68: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80133B6C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80133B70: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80133B74: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80133B78: ldc1        $f4, 0x0($t8)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r24, 0X0);
    // 0x80133B7C: ldc1        $f18, 0x0($t4)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r12, 0X0);
    // 0x80133B80: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x80133B84: nop

    // 0x80133B88: bc1tl       L_80133B98
    if (c1cs) {
        // 0x80133B8C: lw          $v1, 0x8($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X8);
            goto L_80133B98;
    }
    goto skip_4;
    // 0x80133B8C: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    skip_4:
    // 0x80133B90: addiu       $v0, $s3, 0x3
    ctx->r2 = ADD32(ctx->r19, 0X3);
L_80133B94:
    // 0x80133B94: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
L_80133B98:
    // 0x80133B98: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80133B9C: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80133BA0: beq         $s3, $t0, L_80133BD8
    if (ctx->r19 == ctx->r8) {
        // 0x80133BA4: sw          $v0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r2;
            goto L_80133BD8;
    }
    // 0x80133BA4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80133BA8: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x80133BAC: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80133BB0: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80133BB4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80133BB8: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80133BBC: ldc1        $f8, 0x0($t8)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r24, 0X0);
    // 0x80133BC0: ldc1        $f6, 0x0($t4)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r12, 0X0);
    // 0x80133BC4: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80133BC8: nop

    // 0x80133BCC: bc1tl       L_80133BDC
    if (c1cs) {
        // 0x80133BD0: lw          $v1, 0xC($s1)
        ctx->r3 = MEM_W(ctx->r17, 0XC);
            goto L_80133BDC;
    }
    goto skip_5;
    // 0x80133BD0: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    skip_5:
    // 0x80133BD4: addiu       $v0, $s3, 0x4
    ctx->r2 = ADD32(ctx->r19, 0X4);
L_80133BD8:
    // 0x80133BD8: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
L_80133BDC:
    // 0x80133BDC: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    // 0x80133BE0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80133BE4: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x80133BE8: beq         $s3, $t1, L_80133C20
    if (ctx->r19 == ctx->r9) {
        // 0x80133BEC: sw          $v0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r2;
            goto L_80133C20;
    }
    // 0x80133BEC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80133BF0: lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X10);
    // 0x80133BF4: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80133BF8: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80133BFC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80133C00: addu        $t8, $s2, $t6
    ctx->r24 = ADD32(ctx->r18, ctx->r14);
    // 0x80133C04: ldc1        $f16, 0x0($t8)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r24, 0X0);
    // 0x80133C08: ldc1        $f10, 0x0($t4)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r12, 0X0);
    // 0x80133C0C: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x80133C10: nop

    // 0x80133C14: bc1tl       L_80133C24
    if (c1cs) {
        // 0x80133C18: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_80133C24;
    }
    goto skip_6;
    // 0x80133C18: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    skip_6:
    // 0x80133C1C: addiu       $v0, $s3, 0x5
    ctx->r2 = ADD32(ctx->r19, 0X5);
L_80133C20:
    // 0x80133C20: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_80133C24:
    // 0x80133C24: bne         $a0, $t2, L_80133B0C
    if (ctx->r4 != ctx->r10) {
        // 0x80133C28: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80133B0C;
    }
    // 0x80133C28: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80133C2C: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x80133C30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80133C34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80133C38: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80133C3C: addu        $t3, $a1, $t9
    ctx->r11 = ADD32(ctx->r5, ctx->r25);
    // 0x80133C40: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80133C44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80133C48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80133C4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80133C50: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80133C54: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80133C58: jr          $ra
    // 0x80133C5C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80133C5C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void mnPlayers1PTrainingFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void func_ovl0_800C994C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C994C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C9950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9954: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800C9958: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800C995C: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x800C9960: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800C9964: jal         0x800EDBA4
    // 0x800C9968: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800C9968: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C996C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800C9970: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C9974: jal         0x800ECD80
    // 0x800C9978: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    gmCollisionCopyMatrix(rdram, ctx);
        goto after_1;
    // 0x800C9978: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_1:
    // 0x800C997C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C9980: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C9984: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C9988: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C998C: nop

    // 0x800C9990: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9994: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C9998: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C999C: jal         0x80033510
    // 0x800C99A0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C99A0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_2:
    // 0x800C99A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800C99A8: swc1        $f0, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f0.u32l;
    // 0x800C99AC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800C99B0: jal         0x80019EA0
    // 0x800C99B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_3;
    // 0x800C99B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x800C99B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C99BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C99C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C99C4: jr          $ra
    // 0x800C99C8: nop

    return;
    // 0x800C99C8: nop

;}
RECOMP_FUNC void func_ovl8_8037D990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D990: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D994: jr          $ra
    // 0x8037D998: sw          $a0, -0x470($at)
    MEM_W(-0X470, ctx->r1) = ctx->r4;
    return;
    // 0x8037D998: sw          $a0, -0x470($at)
    MEM_W(-0X470, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_80384460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80384464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80384468: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038446C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80384470: jal         0x803717A0
    // 0x80384474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80384474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80384478: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8038447C: beq         $v0, $zero, L_803844AC
    if (ctx->r2 == 0) {
        // 0x80384480: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803844AC;
    }
    // 0x80384480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80384484: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80384488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038448C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80384490: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80384494: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80384498: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8038449C: jal         0x8038456C
    // 0x803844A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8038456C(rdram, ctx);
        goto after_1;
    // 0x803844A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x803844A4: b           L_803844B0
    // 0x803844A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803844B0;
    // 0x803844A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803844AC:
    // 0x803844AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803844B0:
    // 0x803844B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803844B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803844B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803844BC: jr          $ra
    // 0x803844C0: nop

    return;
    // 0x803844C0: nop

;}
RECOMP_FUNC void lbParticleEjectStructID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D39D8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D39DC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D39E0: addiu       $t7, $t7, 0x6358
    ctx->r15 = ADD32(ctx->r15, 0X6358);
    // 0x800D39E4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D39E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D39EC: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x800D39F0: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x800D39F4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D39F8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D39FC: andi        $fp, $a0, 0xFFFF
    ctx->r30 = ctx->r4 & 0XFFFF;
    // 0x800D3A00: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D3A04: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D3A08: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D3A0C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D3A10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D3A14: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D3A18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D3A1C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800D3A20: beq         $s0, $zero, L_800D3AF0
    if (ctx->r16 == 0) {
        // 0x800D3A24: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800D3AF0;
    }
    // 0x800D3A24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D3A28: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800D3A2C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800D3A30: addiu       $s3, $s3, 0x6350
    ctx->r19 = ADD32(ctx->r19, 0X6350);
    // 0x800D3A34: addiu       $s4, $s4, 0x6448
    ctx->r20 = ADD32(ctx->r20, 0X6448);
    // 0x800D3A38: or          $s5, $fp, $zero
    ctx->r21 = ctx->r30 | 0;
    // 0x800D3A3C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_800D3A40:
    // 0x800D3A40: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x800D3A44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800D3A48: bne         $s5, $t8, L_800D3AE4
    if (ctx->r21 != ctx->r24) {
        // 0x800D3A4C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D3AE4;
    }
    // 0x800D3A4C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800D3A50: bnel        $s1, $zero, L_800D3A64
    if (ctx->r17 != 0) {
        // 0x800D3A54: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800D3A64;
    }
    goto skip_0;
    // 0x800D3A54: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    skip_0:
    // 0x800D3A58: b           L_800D3A64
    // 0x800D3A5C: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
        goto L_800D3A64;
    // 0x800D3A5C: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x800D3A60: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800D3A64:
    // 0x800D3A64: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800D3A68: beql        $v0, $zero, L_800D3A9C
    if (ctx->r2 == 0) {
        // 0x800D3A6C: lw          $a0, 0x5C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X5C);
            goto L_800D3A9C;
    }
    goto skip_1;
    // 0x800D3A6C: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    skip_1:
    // 0x800D3A70: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x800D3A74: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x800D3A78: beql        $t0, $zero, L_800D3A9C
    if (ctx->r8 == 0) {
        // 0x800D3A7C: lw          $a0, 0x5C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X5C);
            goto L_800D3A9C;
    }
    goto skip_2;
    // 0x800D3A7C: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    skip_2:
    // 0x800D3A80: lbu         $t1, 0x8($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X8);
    // 0x800D3A84: bnel        $s7, $t1, L_800D3A9C
    if (ctx->r23 != ctx->r9) {
        // 0x800D3A88: lw          $a0, 0x5C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X5C);
            goto L_800D3A9C;
    }
    goto skip_3;
    // 0x800D3A88: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    skip_3:
    // 0x800D3A8C: lhu         $t2, 0x54($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X54);
    // 0x800D3A90: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800D3A94: sh          $t3, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r11;
    // 0x800D3A98: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
L_800D3A9C:
    // 0x800D3A9C: beql        $a0, $zero, L_800D3ACC
    if (ctx->r4 == 0) {
        // 0x800D3AA0: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_800D3ACC;
    }
    goto skip_4;
    // 0x800D3AA0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_4:
    // 0x800D3AA4: lhu         $t4, 0x2A($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D3AA8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800D3AAC: sh          $t5, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r13;
    // 0x800D3AB0: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x800D3AB4: lhu         $t6, 0x2A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D3AB8: bnel        $t6, $zero, L_800D3ACC
    if (ctx->r14 != 0) {
        // 0x800D3ABC: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_800D3ACC;
    }
    goto skip_5;
    // 0x800D3ABC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_5:
    // 0x800D3AC0: jal         0x800CE188
    // 0x800D3AC4: nop

    lbParticleEjectTransform(rdram, ctx);
        goto after_0;
    // 0x800D3AC4: nop

    after_0:
    // 0x800D3AC8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_800D3ACC:
    // 0x800D3ACC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800D3AD0: lhu         $t8, 0x0($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X0);
    // 0x800D3AD4: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x800D3AD8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800D3ADC: b           L_800D3AE8
    // 0x800D3AE0: sh          $t9, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r25;
        goto L_800D3AE8;
    // 0x800D3AE0: sh          $t9, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r25;
L_800D3AE4:
    // 0x800D3AE4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_800D3AE8:
    // 0x800D3AE8: bne         $s2, $zero, L_800D3A40
    if (ctx->r18 != 0) {
        // 0x800D3AEC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800D3A40;
    }
    // 0x800D3AEC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_800D3AF0:
    // 0x800D3AF0: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800D3AF4: addiu       $s6, $s6, 0x639C
    ctx->r22 = ADD32(ctx->r22, 0X639C);
    // 0x800D3AF8: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x800D3AFC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800D3B00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D3B04: beq         $s0, $zero, L_800D3BC8
    if (ctx->r16 == 0) {
        // 0x800D3B08: or          $s5, $fp, $zero
        ctx->r21 = ctx->r30 | 0;
            goto L_800D3BC8;
    }
    // 0x800D3B08: or          $s5, $fp, $zero
    ctx->r21 = ctx->r30 | 0;
    // 0x800D3B0C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x800D3B10: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800D3B14: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800D3B18: addiu       $s3, $s3, 0x6398
    ctx->r19 = ADD32(ctx->r19, 0X6398);
    // 0x800D3B1C: addiu       $s4, $s4, 0x644A
    ctx->r20 = ADD32(ctx->r20, 0X644A);
    // 0x800D3B20: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800D3B24:
    // 0x800D3B24: lhu         $t0, 0x4($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X4);
    // 0x800D3B28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800D3B2C: bne         $s5, $t0, L_800D3BBC
    if (ctx->r21 != ctx->r8) {
        // 0x800D3B30: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800D3BBC;
    }
    // 0x800D3B30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800D3B34: lbu         $t1, 0x8($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X8);
    // 0x800D3B38: bne         $s7, $t1, L_800D3B5C
    if (ctx->r23 != ctx->r9) {
        // 0x800D3B3C: nop
    
            goto L_800D3B5C;
    }
    // 0x800D3B3C: nop

    // 0x800D3B40: lhu         $t2, 0x54($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X54);
    // 0x800D3B44: beq         $t2, $zero, L_800D3B5C
    if (ctx->r10 == 0) {
        // 0x800D3B48: nop
    
            goto L_800D3B5C;
    }
    // 0x800D3B48: nop

    // 0x800D3B4C: swc1        $f20, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f20.u32l;
    // 0x800D3B50: sh          $fp, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r30;
    // 0x800D3B54: b           L_800D3BC0
    // 0x800D3B58: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
        goto L_800D3BC0;
    // 0x800D3B58: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_800D3B5C:
    // 0x800D3B5C: bnel        $s1, $zero, L_800D3B70
    if (ctx->r17 != 0) {
        // 0x800D3B60: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800D3B70;
    }
    goto skip_6;
    // 0x800D3B60: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    skip_6:
    // 0x800D3B64: b           L_800D3B70
    // 0x800D3B68: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
        goto L_800D3B70;
    // 0x800D3B68: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x800D3B6C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_800D3B70:
    // 0x800D3B70: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800D3B74: beql        $a0, $zero, L_800D3BA4
    if (ctx->r4 == 0) {
        // 0x800D3B78: lw          $t6, 0x0($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X0);
            goto L_800D3BA4;
    }
    goto skip_7;
    // 0x800D3B78: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    skip_7:
    // 0x800D3B7C: lhu         $t3, 0x2A($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D3B80: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800D3B84: sh          $t4, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r12;
    // 0x800D3B88: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800D3B8C: lhu         $t5, 0x2A($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D3B90: bnel        $t5, $zero, L_800D3BA4
    if (ctx->r13 != 0) {
        // 0x800D3B94: lw          $t6, 0x0($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X0);
            goto L_800D3BA4;
    }
    goto skip_8;
    // 0x800D3B94: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x800D3B98: jal         0x800CE188
    // 0x800D3B9C: nop

    lbParticleEjectTransform(rdram, ctx);
        goto after_1;
    // 0x800D3B9C: nop

    after_1:
    // 0x800D3BA0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
L_800D3BA4:
    // 0x800D3BA4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D3BA8: lhu         $t7, 0x0($s4)
    ctx->r15 = MEM_HU(ctx->r20, 0X0);
    // 0x800D3BAC: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x800D3BB0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D3BB4: b           L_800D3BC0
    // 0x800D3BB8: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
        goto L_800D3BC0;
    // 0x800D3BB8: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
L_800D3BBC:
    // 0x800D3BBC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_800D3BC0:
    // 0x800D3BC0: bne         $s2, $zero, L_800D3B24
    if (ctx->r18 != 0) {
        // 0x800D3BC4: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800D3B24;
    }
    // 0x800D3BC4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_800D3BC8:
    // 0x800D3BC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D3BCC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D3BD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D3BD4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D3BD8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D3BDC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3BE0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D3BE4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D3BE8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D3BEC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D3BF0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D3BF4: jr          $ra
    // 0x800D3BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D3BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void itTaruBombFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184D74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80184D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184D7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80184D80: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80184D84: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80184D88: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80184D8C: jal         0x80172558
    // 0x80184D90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80184D90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80184D94: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80184D98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80184D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80184DA0: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x80184DA4: lwc1        $f6, 0x350($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X350);
    // 0x80184DA8: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80184DAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80184DB0: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x80184DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184DB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80184DBC: jr          $ra
    // 0x80184DC0: nop

    return;
    // 0x80184DC0: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B59C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B5A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B5A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8015B5A8: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015B5AC: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B5B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B5B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B5B8: bne         $t6, $at, L_8015B5C8
    if (ctx->r14 != ctx->r1) {
        // 0x8015B5BC: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_8015B5C8;
    }
    // 0x8015B5BC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8015B5C0: b           L_8015B5C8
    // 0x8015B5C4: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
        goto L_8015B5C8;
    // 0x8015B5C4: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
L_8015B5C8:
    // 0x8015B5C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B5CC: jal         0x800E6F24
    // 0x8015B5D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B5D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B5D4: jal         0x8015B508
    // 0x8015B5D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeySpecialNGetStatusChargeLevelReset(rdram, ctx);
        goto after_1;
    // 0x8015B5D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015B5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B5E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B5E4: jr          $ra
    // 0x8015B5E8: nop

    return;
    // 0x8015B5E8: nop

;}
RECOMP_FUNC void gmCollisionGetFighterAttackDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0A90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F0A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0A98: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F0A9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800F0AA0: jal         0x800F0850
    // 0x800F0AA4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0AA4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800F0AA8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F0AAC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800F0AB0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800F0AB4: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x800F0AB8: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x800F0ABC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800F0AC0: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x800F0AC4: addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    // 0x800F0AC8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800F0ACC: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x800F0AD0: jal         0x800ED3C0
    // 0x800F0AD4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0AD4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    after_1:
    // 0x800F0AD8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800F0ADC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800F0AE0: jal         0x800F0A48
    // 0x800F0AE4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0AE4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800F0AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0AEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F0AF0: jr          $ra
    // 0x800F0AF4: nop

    return;
    // 0x800F0AF4: nop

;}
RECOMP_FUNC void syMatrixTraRotRScaF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BD08: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BD0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BD10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001BD14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001BD18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001BD1C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001BD20: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8001BD24: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001BD28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001BD2C: jal         0x8001BA78
    // 0x8001BD30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixRotRF(rdram, ctx);
        goto after_0;
    // 0x8001BD30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001BD34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001BD38: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001BD3C: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x8001BD40: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001BD44: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x8001BD48: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001BD4C: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001BD50: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8001BD54: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8001BD58: jal         0x8001B824
    // 0x8001BD5C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    syMatrixRowscaleF(rdram, ctx);
        goto after_1;
    // 0x8001BD5C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8001BD60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BD64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001BD68: jr          $ra
    // 0x8001BD6C: nop

    return;
    // 0x8001BD6C: nop

;}
RECOMP_FUNC void func_ovl8_80373694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037369C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x803736A0: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x803736A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803736A8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x803736AC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x803736B0: nop

    // 0x803736B4: bc1fl       L_803736C8
    if (!c1cs) {
        // 0x803736B8: lwc1        $f0, 0x8($a2)
        ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
            goto L_803736C8;
    }
    goto skip_0;
    // 0x803736B8: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x803736BC: b           L_803736DC
    // 0x803736C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_803736DC;
    // 0x803736C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x803736C4: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
L_803736C8:
    // 0x803736C8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x803736CC: nop

    // 0x803736D0: bc1fl       L_803736E0
    if (!c1cs) {
        // 0x803736D4: lwc1        $f4, 0x0($a2)
        ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
            goto L_803736E0;
    }
    goto skip_1;
    // 0x803736D4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x803736D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_803736DC:
    // 0x803736DC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
L_803736E0:
    // 0x803736E0: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x803736E4: nop

    // 0x803736E8: bc1tl       L_80373744
    if (c1cs) {
        // 0x803736EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80373744;
    }
    goto skip_2;
    // 0x803736EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x803736F0: beq         $a2, $zero, L_803736FC
    if (ctx->r6 == 0) {
        // 0x803736F4: swc1        $f12, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
            goto L_803736FC;
    }
    // 0x803736F4: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x803736F8: lw          $v0, 0x38($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X38);
L_803736FC:
    // 0x803736FC: lw          $a3, 0x34($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X34);
    // 0x80373700: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80373704: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x80373708: lh          $t6, 0x18($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X18);
    // 0x8037370C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80373710: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x80373714: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    // 0x80373718: jalr        $t9
    // 0x8037371C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037371C: nop

    after_0:
    // 0x80373720: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80373724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80373728: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x8037372C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373730: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80373734: lh          $t7, 0x118($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X118);
    // 0x80373738: jalr        $t9
    // 0x8037373C: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037373C: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_1:
    // 0x80373740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80373744:
    // 0x80373744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373748: jr          $ra
    // 0x8037374C: nop

    return;
    // 0x8037374C: nop

;}
RECOMP_FUNC void mvOpeningPortraitsMakeCoverCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132574: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132578: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013257C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132580: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132584: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132588: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8013258C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132590: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132594: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132598: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013259C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801325A0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801325A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801325A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801325AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801325B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801325B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801325B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801325BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801325C0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801325C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801325C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801325CC: jal         0x8000B93C
    // 0x801325D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801325D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801325D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801325D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801325DC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801325E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801325E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801325EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801325F0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801325F4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801325F8: jal         0x80007080
    // 0x801325FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801325FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132600: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132604: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132608: jr          $ra
    // 0x8013260C: nop

    return;
    // 0x8013260C: nop

;}
RECOMP_FUNC void ftKirbySpecialNCopyUpdateCheckCopyStar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801622DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801622E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801622E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801622E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801622EC: lw          $t6, 0x184($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X184);
    // 0x801622F0: beql        $t6, $zero, L_80162364
    if (ctx->r14 == 0) {
        // 0x801622F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80162364;
    }
    goto skip_0;
    // 0x801622F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801622F8: lw          $a0, 0x840($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X840);
    // 0x801622FC: beql        $a0, $zero, L_80162364
    if (ctx->r4 == 0) {
        // 0x80162300: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80162364;
    }
    goto skip_1;
    // 0x80162300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80162304: jal         0x8014C6AC
    // 0x80162308: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftCommonThrownCopyStarSetStatus(rdram, ctx);
        goto after_0;
    // 0x80162308: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8016230C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80162310: jal         0x800303F0
    // 0x80162314: lwc1        $f12, -0x3620($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3620);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80162314: lwc1        $f12, -0x3620($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3620);
    after_1:
    // 0x80162318: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8016231C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80162320: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80162324: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80162328: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8016232C: jal         0x80035CD0
    // 0x80162330: lwc1        $f12, -0x361C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X361C);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80162330: lwc1        $f12, -0x361C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X361C);
    after_2:
    // 0x80162334: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80162338: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8016233C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80162340: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80162344: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80162348: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016234C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80162350: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80162354: nop

    // 0x80162358: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8016235C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80162360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80162364:
    // 0x80162364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80162368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016236C: jr          $ra
    // 0x80162370: nop

    return;
    // 0x80162370: nop

;}
RECOMP_FUNC void efManagerKirbyVulcanJabProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101CA8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80101CAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101CB0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80101CB4: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x80101CB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80101CBC: beq         $t6, $zero, L_80101D14
    if (ctx->r14 == 0) {
        // 0x80101CC0: nop
    
            goto L_80101D14;
    }
    // 0x80101CC0: nop

    // 0x80101CC4: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80101CC8: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80101CCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80101CD0: swc1        $f8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f8.u32l;
    // 0x80101CD4: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80101CD8: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80101CDC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80101CE0: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x80101CE4: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80101CE8: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80101CEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80101CF0: swc1        $f8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f8.u32l;
    // 0x80101CF4: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80101CF8: lwc1        $f16, 0x20($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80101CFC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80101D00: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80101D04: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x80101D08: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80101D0C: b           L_80101D24
    // 0x80101D10: sw          $t8, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r24;
        goto L_80101D24;
    // 0x80101D10: sw          $t8, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r24;
L_80101D14:
    // 0x80101D14: jal         0x800FD4F8
    // 0x80101D18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x80101D18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80101D1C: jal         0x80009A84
    // 0x80101D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80101D20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80101D24:
    // 0x80101D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101D2C: jr          $ra
    // 0x80101D30: nop

    return;
    // 0x80101D30: nop

;}
RECOMP_FUNC void gcResumeGObjProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2B8: bnel        $a0, $zero, L_8000B2CC
    if (ctx->r4 != 0) {
        // 0x8000B2BC: lw          $v0, 0x18($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X18);
            goto L_8000B2CC;
    }
    goto skip_0;
    // 0x8000B2BC: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x8000B2C0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B2C4: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
    // 0x8000B2C8: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
L_8000B2CC:
    // 0x8000B2CC: beq         $v0, $zero, L_8000B2E4
    if (ctx->r2 == 0) {
        // 0x8000B2D0: nop
    
            goto L_8000B2E4;
    }
    // 0x8000B2D0: nop

    // 0x8000B2D4: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
L_8000B2D8:
    // 0x8000B2D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B2DC: bnel        $v0, $zero, L_8000B2D8
    if (ctx->r2 != 0) {
        // 0x8000B2E0: sb          $zero, 0x15($v0)
        MEM_B(0X15, ctx->r2) = 0;
            goto L_8000B2D8;
    }
    goto skip_1;
    // 0x8000B2E0: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    skip_1:
L_8000B2E4:
    // 0x8000B2E4: jr          $ra
    // 0x8000B2E8: nop

    return;
    // 0x8000B2E8: nop

;}
RECOMP_FUNC void lbRelocGetStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD680: jal         0x800CD620
    // 0x800CD684: nop

    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CD684: nop

    after_0:
    // 0x800CD688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD690: jr          $ra
    // 0x800CD694: nop

    return;
    // 0x800CD694: nop

;}
RECOMP_FUNC void sc1PGameWaitThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EADC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018EAE0: lbu         $t6, 0x4AE7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE7);
    // 0x8018EAE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EAE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EAEC: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x8018EAF0: beq         $at, $zero, L_8018EB48
    if (ctx->r1 == 0) {
        // 0x8018EAF4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8018EB48;
    }
    // 0x8018EAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018EAF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018EAFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EB00: addu        $at, $at, $t6
    gpr jr_addend_8018EB08 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018EB04: lw          $t6, 0x2EE0($at)
    ctx->r14 = ADD32(ctx->r1, 0X2EE0);
    // 0x8018EB08: jr          $t6
    // 0x8018EB0C: nop

    switch (jr_addend_8018EB08 >> 2) {
        case 0: goto L_8018EB10; break;
        case 1: goto L_8018EB20; break;
        case 2: goto L_8018EB10; break;
        case 3: goto L_8018EB48; break;
        case 4: goto L_8018EB10; break;
        case 5: goto L_8018EB10; break;
        case 6: goto L_8018EB10; break;
        case 7: goto L_8018EB48; break;
        case 8: goto L_8018EB20; break;
        case 9: goto L_8018EB10; break;
        case 10: goto L_8018EB10; break;
        case 11: goto L_8018EB30; break;
        case 12: goto L_8018EB20; break;
        case 13: goto L_8018EB40; break;
        case 14: goto L_8018EB10; break;
        case 15: goto L_8018EB10; break;
        case 16: goto L_8018EB10; break;
        case 17: goto L_8018EB10; break;
        default: switch_error(__func__, 0x8018EB08, 0x80192EE0);
    }
    // 0x8018EB0C: nop

L_8018EB10:
    // 0x8018EB10: jal         0x8018E670
    // 0x8018EB14: nop

    sc1PGameWaitStageCommonUpdate(rdram, ctx);
        goto after_0;
    // 0x8018EB14: nop

    after_0:
    // 0x8018EB18: b           L_8018EB48
    // 0x8018EB1C: nop

        goto L_8018EB48;
    // 0x8018EB1C: nop

L_8018EB20:
    // 0x8018EB20: jal         0x8018E824
    // 0x8018EB24: nop

    sc1PGameWaitStageTeamUpdate(rdram, ctx);
        goto after_1;
    // 0x8018EB24: nop

    after_1:
    // 0x8018EB28: b           L_8018EB48
    // 0x8018EB2C: nop

        goto L_8018EB48;
    // 0x8018EB2C: nop

L_8018EB30:
    // 0x8018EB30: jal         0x8018E8F8
    // 0x8018EB34: nop

    sc1PGameWaitStageBonus3Update(rdram, ctx);
        goto after_2;
    // 0x8018EB34: nop

    after_2:
    // 0x8018EB38: b           L_8018EB48
    // 0x8018EB3C: nop

        goto L_8018EB48;
    // 0x8018EB3C: nop

L_8018EB40:
    // 0x8018EB40: jal         0x8018E9A4
    // 0x8018EB44: nop

    sc1PGameWaitStageBossUpdate(rdram, ctx);
        goto after_3;
    // 0x8018EB44: nop

    after_3:
L_8018EB48:
    // 0x8018EB48: jal         0x80009A84
    // 0x8018EB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x8018EB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018EB50: jal         0x8000B1E8
    // 0x8018EB54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x8018EB54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8018EB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EB5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EB60: jr          $ra
    // 0x8018EB64: nop

    return;
    // 0x8018EB64: nop

;}
RECOMP_FUNC void grHyruleTwisterUpdateSummon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010A448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010A44C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010A450: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x8010A454: lhu         $t6, 0x20($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X20);
    // 0x8010A458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010A45C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8010A460: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010A464: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A468: bne         $t8, $zero, L_8010A4E0
    if (ctx->r24 != 0) {
        // 0x8010A46C: sh          $t7, 0x20($s0)
        MEM_H(0X20, ctx->r16) = ctx->r15;
            goto L_8010A4E0;
    }
    // 0x8010A46C: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x8010A470: sb          $t9, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r25;
    // 0x8010A474: jal         0x80018994
    // 0x8010A478: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010A478: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_0:
    // 0x8010A47C: addiu       $t0, $v0, 0x208
    ctx->r8 = ADD32(ctx->r2, 0X208);
    // 0x8010A480: jal         0x80018910
    // 0x8010A484: sh          $t0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r8;
    syUtilsRandUShort(rdram, ctx);
        goto after_1;
    // 0x8010A484: sh          $t0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r8;
    after_1:
    // 0x8010A488: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8010A48C: beq         $t1, $zero, L_8010A49C
    if (ctx->r9 == 0) {
        // 0x8010A490: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8010A49C;
    }
    // 0x8010A490: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8010A494: b           L_8010A49C
    // 0x8010A498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A49C;
    // 0x8010A498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A49C:
    // 0x8010A49C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8010A4A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8010A4A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010A4A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010A4AC: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x8010A4B0: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8010A4B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010A4B8: jal         0x80018994
    // 0x8010A4BC: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8010A4BC: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8010A4C0: addiu       $t2, $v0, 0xB4
    ctx->r10 = ADD32(ctx->r2, 0XB4);
    // 0x8010A4C4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010A4C8: sh          $t2, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r10;
    // 0x8010A4CC: addiu       $a1, $a1, -0x548C
    ctx->r5 = ADD32(ctx->r5, -0X548C);
    // 0x8010A4D0: jal         0x800E1D48
    // 0x8010A4D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    ftMainCheckAddGroundObstacle(rdram, ctx);
        goto after_3;
    // 0x8010A4D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8010A4D8: jal         0x800269C0
    // 0x8010A4DC: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8010A4DC: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_4:
L_8010A4E0:
    // 0x8010A4E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A4E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010A4E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010A4EC: jr          $ra
    // 0x8010A4F0: nop

    return;
    // 0x8010A4F0: nop

;}
RECOMP_FUNC void ftCommonAttackS4CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150470: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80150474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150478: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015047C: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80150480: lb          $v0, 0x1C2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C2);
    // 0x80150484: lw          $t0, 0x9C8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X9C8);
    // 0x80150488: bgez        $v0, L_80150498
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015048C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80150498;
    }
    // 0x8015048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80150490: b           L_80150498
    // 0x80150494: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
        goto L_80150498;
    // 0x80150494: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_80150498:
    // 0x80150498: slti        $at, $a1, 0x38
    ctx->r1 = SIGNED(ctx->r5) < 0X38 ? 1 : 0;
    // 0x8015049C: bnel        $at, $zero, L_801505D8
    if (ctx->r1 != 0) {
        // 0x801504A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801505D8;
    }
    goto skip_0;
    // 0x801504A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801504A4: lbu         $t7, 0x268($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X268);
    // 0x801504A8: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801504AC: beql        $at, $zero, L_801505D8
    if (ctx->r1 == 0) {
        // 0x801504B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801505D8;
    }
    goto skip_1;
    // 0x801504B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801504B4: lhu         $t8, 0x1BE($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1BE);
    // 0x801504B8: lhu         $t9, 0x1B4($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X1B4);
    // 0x801504BC: and         $t1, $t8, $t9
    ctx->r9 = ctx->r24 & ctx->r25;
    // 0x801504C0: beql        $t1, $zero, L_801505D8
    if (ctx->r9 == 0) {
        // 0x801504C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801505D8;
    }
    goto skip_2;
    // 0x801504C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801504C8: lw          $a0, 0x84C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84C);
    // 0x801504CC: beql        $a0, $zero, L_801505B0
    if (ctx->r4 == 0) {
        // 0x801504D0: lw          $t7, 0x100($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X100);
            goto L_801505B0;
    }
    goto skip_3;
    // 0x801504D0: lw          $t7, 0x100($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X100);
    skip_3:
    // 0x801504D4: lhu         $t2, 0x1BC($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X1BC);
    // 0x801504D8: lhu         $t3, 0x1B8($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X1B8);
    // 0x801504DC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x801504E0: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x801504E4: bnel        $t4, $zero, L_8015052C
    if (ctx->r12 != 0) {
        // 0x801504E8: lw          $t5, 0x44($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X44);
            goto L_8015052C;
    }
    goto skip_4;
    // 0x801504E8: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
    skip_4:
    // 0x801504EC: lw          $v1, 0x10($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X10);
    // 0x801504F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801504F4: beq         $v1, $at, L_80150528
    if (ctx->r3 == ctx->r1) {
        // 0x801504F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80150528;
    }
    // 0x801504F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801504FC: bnel        $v1, $at, L_8015055C
    if (ctx->r3 != ctx->r1) {
        // 0x80150500: lw          $a1, 0x10($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X10);
            goto L_8015055C;
    }
    goto skip_5;
    // 0x80150500: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    skip_5:
    // 0x80150504: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80150508: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8015050C: jal         0x80172890
    // 0x80150510: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    itMainCheckShootNoAmmo(rdram, ctx);
        goto after_0;
    // 0x80150510: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x80150514: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80150518: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8015051C: beq         $v0, $zero, L_80150558
    if (ctx->r2 == 0) {
        // 0x80150520: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80150558;
    }
    // 0x80150520: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80150524: lb          $v0, 0x1C2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C2);
L_80150528:
    // 0x80150528: lw          $t5, 0x44($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X44);
L_8015052C:
    // 0x8015052C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80150530: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80150534: mflo        $t6
    ctx->r14 = lo;
    // 0x80150538: bltz        $t6, L_80150548
    if (SIGNED(ctx->r14) < 0) {
        // 0x8015053C: nop
    
            goto L_80150548;
    }
    // 0x8015053C: nop

    // 0x80150540: b           L_80150548
    // 0x80150544: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
        goto L_80150548;
    // 0x80150544: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
L_80150548:
    // 0x80150548: jal         0x80146690
    // 0x8015054C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015054C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80150550: b           L_801505D8
    // 0x80150554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801505D8;
    // 0x80150554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150558:
    // 0x80150558: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
L_8015055C:
    // 0x8015055C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80150560: beq         $a1, $at, L_80150578
    if (ctx->r5 == ctx->r1) {
        // 0x80150564: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80150578;
    }
    // 0x80150564: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80150568: beq         $a1, $at, L_80150594
    if (ctx->r5 == ctx->r1) {
        // 0x8015056C: nop
    
            goto L_80150594;
    }
    // 0x8015056C: nop

    // 0x80150570: b           L_801505B0
    // 0x80150574: lw          $t7, 0x100($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X100);
        goto L_801505B0;
    // 0x80150574: lw          $t7, 0x100($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X100);
L_80150578:
    // 0x80150578: jal         0x800E8044
    // 0x8015057C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_2;
    // 0x8015057C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80150580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80150584: jal         0x80146E94
    // 0x80150588: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_3;
    // 0x80150588: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8015058C: b           L_801505D8
    // 0x80150590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801505D8;
    // 0x80150590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150594:
    // 0x80150594: jal         0x800E8044
    // 0x80150598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_4;
    // 0x80150598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8015059C: jal         0x80147844
    // 0x801505A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonItemShootSetStatus(rdram, ctx);
        goto after_5;
    // 0x801505A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801505A4: b           L_801505D8
    // 0x801505A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801505D8;
    // 0x801505A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801505AC: lw          $t7, 0x100($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X100);
L_801505B0:
    // 0x801505B0: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x801505B4: bgezl       $t9, L_801505D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801505B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801505D8;
    }
    goto skip_6;
    // 0x801505B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x801505BC: jal         0x800E8044
    // 0x801505C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_6;
    // 0x801505C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x801505C4: jal         0x8014FFE0
    // 0x801505C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonAttackS4SetStatus(rdram, ctx);
        goto after_7;
    // 0x801505C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x801505CC: b           L_801505D8
    // 0x801505D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801505D8;
    // 0x801505D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801505D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801505D8:
    // 0x801505D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801505DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801505E0: jr          $ra
    // 0x801505E4: nop

    return;
    // 0x801505E4: nop

;}
RECOMP_FUNC void func_ovl16_800D64B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64B4: jr          $ra
    // 0x800D64B8: nop

    return;
    // 0x800D64B8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckBonusCompleteAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136C8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136C90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136C98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80136C9C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_80136CA0:
    // 0x80136CA0: jal         0x80133B7C
    // 0x80136CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusCheckBonusComplete(rdram, ctx);
        goto after_0;
    // 0x80136CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80136CA8: bne         $v0, $zero, L_80136CB8
    if (ctx->r2 != 0) {
        // 0x80136CAC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80136CB8;
    }
    // 0x80136CAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80136CB0: b           L_80136CC4
    // 0x80136CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136CC4;
    // 0x80136CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136CB8:
    // 0x80136CB8: bne         $s0, $s1, L_80136CA0
    if (ctx->r16 != ctx->r17) {
        // 0x80136CBC: nop
    
            goto L_80136CA0;
    }
    // 0x80136CBC: nop

    // 0x80136CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136CC4:
    // 0x80136CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80136CC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136CCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136CD0: jr          $ra
    // 0x80136CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80136CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpBossBulletExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DC2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016DC30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016DC34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8016DC38: lbu         $t8, 0x148($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X148);
    // 0x8016DC3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016DC40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8016DC44: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8016DC48: andi        $t2, $t0, 0xF7
    ctx->r10 = ctx->r8 & 0XF7;
    // 0x8016DC4C: sb          $t0, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r8;
    // 0x8016DC50: andi        $t3, $t2, 0xFB
    ctx->r11 = ctx->r10 & 0XFB;
    // 0x8016DC54: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8016DC58: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8016DC5C: sb          $t2, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r10;
    // 0x8016DC60: sh          $t6, 0x146($v0)
    MEM_H(0X146, ctx->r2) = ctx->r14;
    // 0x8016DC64: sb          $t3, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r11;
    // 0x8016DC68: sw          $t4, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r12;
    // 0x8016DC6C: sw          $t5, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r13;
    // 0x8016DC70: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8016DC74: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8016DC78: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8016DC7C: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x8016DC80: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8016DC84: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8016DC88: addiu       $t7, $t7, -0x2400
    ctx->r15 = ADD32(ctx->r15, -0X2400);
    // 0x8016DC8C: sw          $zero, 0x50($t6)
    MEM_W(0X50, ctx->r14) = 0;
    // 0x8016DC90: sw          $t7, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->r15;
    // 0x8016DC94: sw          $zero, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = 0;
    // 0x8016DC98: sw          $zero, 0x280($v0)
    MEM_W(0X280, ctx->r2) = 0;
    // 0x8016DC9C: sw          $zero, 0x284($v0)
    MEM_W(0X284, ctx->r2) = 0;
    // 0x8016DCA0: sw          $zero, 0x288($v0)
    MEM_W(0X288, ctx->r2) = 0;
    // 0x8016DCA4: sw          $zero, 0x28C($v0)
    MEM_W(0X28C, ctx->r2) = 0;
    // 0x8016DCA8: jr          $ra
    // 0x8016DCAC: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
    return;
    // 0x8016DCAC: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
;}
RECOMP_FUNC void ftFoxSpecialLwTurnDecTurnFrames(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015CF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CF58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015CF5C: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x8015CF60: lw          $t8, 0x180($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X180);
    // 0x8015CF64: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015CF68: bne         $t8, $zero, L_8015CF90
    if (ctx->r24 != 0) {
        // 0x8015CF6C: sw          $t7, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->r15;
            goto L_8015CF90;
    }
    // 0x8015CF6C: sw          $t7, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r15;
    // 0x8015CF70: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x8015CF74: beql        $at, $zero, L_8015CF94
    if (ctx->r1 == 0) {
        // 0x8015CF78: lw          $v1, 0x8E8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8E8);
            goto L_8015CF94;
    }
    goto skip_0;
    // 0x8015CF78: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    skip_0:
    // 0x8015CF7C: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x8015CF80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8015CF84: sw          $t0, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r8;
    // 0x8015CF88: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8015CF8C: sw          $t2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r10;
L_8015CF90:
    // 0x8015CF90: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
L_8015CF94:
    // 0x8015CF94: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015CF98: lwc1        $f6, -0x3750($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3750);
    // 0x8015CF9C: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8015CFA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8015CFA4: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
    // 0x8015CFA8: jal         0x800EB528
    // 0x8015CFAC: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x8015CFAC: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_0:
    // 0x8015CFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015CFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015CFB8: jr          $ra
    // 0x8015CFBC: nop

    return;
    // 0x8015CFBC: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponInFighterRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF414: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EF418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF41C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EF420: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EF424: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800EF428: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800EF42C: lw          $v0, 0x84($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84);
    // 0x800EF430: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EF434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF438: bne         $t7, $at, L_800EF470
    if (ctx->r15 != ctx->r1) {
        // 0x800EF43C: lw          $v1, 0x9C8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X9C8);
            goto L_800EF470;
    }
    // 0x800EF43C: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x800EF440: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800EF444: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800EF448: lw          $a1, 0x74($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X74);
    // 0x800EF44C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800EF450: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800EF454: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x800EF458: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF45C: lw          $a3, 0x28($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X28);
    // 0x800EF460: jal         0x800EF2D0
    // 0x800EF464: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_0;
    // 0x800EF464: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x800EF468: b           L_800EF4E4
    // 0x800EF46C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800EF4E4;
    // 0x800EF46C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF470:
    // 0x800EF470: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800EF474: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800EF478: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF47C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800EF480: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800EF484: lw          $a1, 0x74($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X74);
    // 0x800EF488: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800EF48C: addu        $t0, $s0, $t2
    ctx->r8 = ADD32(ctx->r16, ctx->r10);
    // 0x800EF490: lw          $a3, 0x28($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X28);
    // 0x800EF494: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800EF498: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EF49C: addiu       $a0, $t0, 0x54
    ctx->r4 = ADD32(ctx->r8, 0X54);
    // 0x800EF4A0: jal         0x800EF2D0
    // 0x800EF4A4: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_1;
    // 0x800EF4A4: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x800EF4A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EF4AC: bne         $v0, $zero, L_800EF4D4
    if (ctx->r2 != 0) {
        // 0x800EF4B0: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_800EF4D4;
    }
    // 0x800EF4B0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800EF4B4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800EF4B8: addiu       $a0, $t0, 0x60
    ctx->r4 = ADD32(ctx->r8, 0X60);
    // 0x800EF4BC: lw          $a3, 0x28($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X28);
    // 0x800EF4C0: lw          $a1, 0x74($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X74);
    // 0x800EF4C4: jal         0x800EF2D0
    // 0x800EF4C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800EF4C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x800EF4CC: beql        $v0, $zero, L_800EF4E0
    if (ctx->r2 == 0) {
        // 0x800EF4D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800EF4E0;
    }
    goto skip_0;
    // 0x800EF4D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800EF4D4:
    // 0x800EF4D4: b           L_800EF4E0
    // 0x800EF4D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EF4E0;
    // 0x800EF4D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF4DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF4E0:
    // 0x800EF4E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF4E4:
    // 0x800EF4E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF4E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EF4EC: jr          $ra
    // 0x800EF4F0: nop

    return;
    // 0x800EF4F0: nop

;}
RECOMP_FUNC void itTaruBombCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80184DD0: jal         0x800269C0
    // 0x80184DD4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80184DD4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_0:
    // 0x80184DD8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80184DDC: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80184DE0: jal         0x80184B44
    // 0x80184DE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    itTaruBombContainerSmashMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80184DE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80184DE8: jal         0x801852B8
    // 0x80184DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itTaruBombExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_2;
    // 0x80184DEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80184DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80184DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80184DFC: jr          $ra
    // 0x80184E00: nop

    return;
    // 0x80184E00: nop

;}
RECOMP_FUNC void ifCommonItemArrowSetAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80111F84: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x80111F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111F8C: addiu       $a0, $a0, 0x57
    ctx->r4 = ADD32(ctx->r4, 0X57);
    // 0x80111F90: jal         0x800CDBD0
    // 0x80111F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x80111F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80111F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80111F9C: jal         0x80004980
    // 0x80111FA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x80111FA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80111FA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80111FA8: jal         0x800CDC88
    // 0x80111FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x80111FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80111FB0: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80111FB4: addiu       $t6, $t6, 0x50
    ctx->r14 = ADD32(ctx->r14, 0X50);
    // 0x80111FB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80111FBC: addiu       $a0, $a0, 0x17F0
    ctx->r4 = ADD32(ctx->r4, 0X17F0);
    // 0x80111FC0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80111FC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80111FC8: addiu       $t8, $zero, 0x201
    ctx->r24 = ADD32(0, 0X201);
    // 0x80111FCC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80111FD0: sh          $t8, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r24;
    // 0x80111FD4: sb          $t9, 0x18($t7)
    MEM_B(0X18, ctx->r15) = ctx->r25;
    // 0x80111FD8: sb          $zero, 0x19($t7)
    MEM_B(0X19, ctx->r15) = 0;
    // 0x80111FDC: sb          $zero, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = 0;
    // 0x80111FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111FE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80111FE8: jr          $ra
    // 0x80111FEC: nop

    return;
    // 0x80111FEC: nop

;}
RECOMP_FUNC void itStarmieWeaponSwiftProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801823B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801823B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801823BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801823C0: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801823C4: jal         0x80167FE8
    // 0x801823C8: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x801823C8: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x801823CC: beq         $v0, $zero, L_801823DC
    if (ctx->r2 == 0) {
        // 0x801823D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801823DC;
    }
    // 0x801823D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801823D4: b           L_801823E0
    // 0x801823D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801823E0;
    // 0x801823D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801823DC:
    // 0x801823DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801823E0:
    // 0x801823E0: jr          $ra
    // 0x801823E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801823E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void syMatrixModLookAtReflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AFD0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001AFD4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001AFD8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001AFDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001AFE0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001AFE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001AFE8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001AFEC: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8001AFF0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001AFF4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001AFF8: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001AFFC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001B000: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001B004: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001B008: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001B00C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001B010: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001B014: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001B018: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8001B01C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001B020: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001B024: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001B028: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001B02C: jal         0x8001ABA4
    // 0x8001B030: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixModLookAtReflectF(rdram, ctx);
        goto after_0;
    // 0x8001B030: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001B034: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001B038: jal         0x80019C70
    // 0x8001B03C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001B03C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x8001B040: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001B044: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001B048: jr          $ra
    // 0x8001B04C: nop

    return;
    // 0x8001B04C: nop

;}
RECOMP_FUNC void itTosakintoMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EAD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017EADC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017EAE0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8017EAE4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017EAE8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8017EAEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017EAF0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017EAF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017EAF8: addiu       $a1, $a1, -0x5440
    ctx->r5 = ADD32(ctx->r5, -0X5440);
    // 0x8017EAFC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8017EB00: jal         0x8016E174
    // 0x8017EB04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017EB04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8017EB08: beq         $v0, $zero, L_8017EBC8
    if (ctx->r2 == 0) {
        // 0x8017EB0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8017EBC8;
    }
    // 0x8017EB0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017EB10: jal         0x8017279C
    // 0x8017EB14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017EB14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8017EB18: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8017EB1C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017EB20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017EB24: jal         0x80008CC0
    // 0x8017EB28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017EB28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x8017EB2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017EB30: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8017EB34: jal         0x80008CC0
    // 0x8017EB38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8017EB38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8017EB3C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017EB40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017EB44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017EB48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017EB4C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017EB50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017EB54: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8017EB58: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017EB5C: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x8017EB60: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8017EB64: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8017EB68: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8017EB6C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8017EB70: addiu       $t4, $t4, -0x48F8
    ctx->r12 = ADD32(ctx->r12, -0X48F8);
    // 0x8017EB74: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8017EB78: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x8017EB7C: addiu       $t6, $t6, 0x3624
    ctx->r14 = ADD32(ctx->r14, 0X3624);
    // 0x8017EB80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017EB84: lw          $t0, 0x2D4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017EB88: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017EB8C: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8017EB90: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017EB94: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017EB98: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x8017EB9C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017EBA0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8017EBA4: nop

    // 0x8017EBA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017EBAC: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017EBB0: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8017EBB4: lw          $t2, 0x2D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017EBB8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017EBBC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8017EBC0: jal         0x8000BD1C
    // 0x8017EBC4: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x8017EBC4: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_4:
L_8017EBC8:
    // 0x8017EBC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017EBCC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8017EBD0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017EBD4: jr          $ra
    // 0x8017EBD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017EBD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void efManagerYoshiEggLayMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80103064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010306C: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80103070: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103074: addiu       $a0, $a0, -0x1A24
    ctx->r4 = ADD32(ctx->r4, -0X1A24);
    // 0x80103078: jal         0x800FDB1C
    // 0x8010307C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x8010307C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x80103080: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80103084: bne         $v0, $zero, L_80103094
    if (ctx->r2 != 0) {
        // 0x80103088: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80103094;
    }
    // 0x80103088: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8010308C: b           L_80103140
    // 0x80103090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103140;
    // 0x80103090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103094:
    // 0x80103094: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x80103098: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8010309C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801030A0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801030A4: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
    // 0x801030A8: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x801030AC: lw          $t8, 0x84($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X84);
    // 0x801030B0: lw          $v1, 0x74($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X74);
    // 0x801030B4: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x801030B8: lw          $t9, 0x8E8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8E8);
    // 0x801030BC: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x801030C0: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x801030C4: sw          $t9, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r25;
    // 0x801030C8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801030CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801030D0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x801030D4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801030D8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801030DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801030E0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801030E4: lwc1        $f0, -0x78E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78E0);
    // 0x801030E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801030EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801030F0: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x801030F4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801030F8: swc1        $f4, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f4.u32l;
    // 0x801030FC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80103100: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x80103104: sb          $t5, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r13;
    // 0x80103108: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x8010310C: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x80103110: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80103114: jal         0x80008CC0
    // 0x80103118: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80103118: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8010311C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80103120: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80103124: lw          $t2, 0x1000($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1000);
    // 0x80103128: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8010312C: addiu       $t3, $t3, 0x960
    ctx->r11 = ADD32(ctx->r11, 0X960);
    // 0x80103130: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80103134: jal         0x800C9314
    // 0x80103138: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonSetDObjTransformsForTreeDObjs(rdram, ctx);
        goto after_2;
    // 0x80103138: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x8010313C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80103140:
    // 0x80103140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80103148: jr          $ra
    // 0x8010314C: nop

    return;
    // 0x8010314C: nop

;}
RECOMP_FUNC void ftMainSearchHitHazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1EE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E1EEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E1EF0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E1EF4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E1EF8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E1EFC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E1F00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E1F04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E1F08: lw          $s3, 0x84($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X84);
    // 0x800E1F0C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E1F10: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800E1F14: lw          $t6, 0x190($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X190);
    // 0x800E1F18: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E1F1C: addiu       $s1, $s1, 0x1180
    ctx->r17 = ADD32(ctx->r17, 0X1180);
    // 0x800E1F20: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x800E1F24: bltz        $t8, L_800E1FBC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E1F28: addiu       $s4, $s4, 0x1198
        ctx->r20 = ADD32(ctx->r20, 0X1198);
            goto L_800E1FBC;
    }
    // 0x800E1F28: addiu       $s4, $s4, 0x1198
    ctx->r20 = ADD32(ctx->r20, 0X1198);
    // 0x800E1F2C: lw          $t9, 0x40($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X40);
    // 0x800E1F30: addiu       $s5, $sp, 0x38
    ctx->r21 = ADD32(ctx->r29, 0X38);
    // 0x800E1F34: bnel        $t9, $zero, L_800E1F60
    if (ctx->r25 != 0) {
        // 0x800E1F38: lw          $t2, 0x0($s4)
        ctx->r10 = MEM_W(ctx->r20, 0X0);
            goto L_800E1F60;
    }
    goto skip_0;
    // 0x800E1F38: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    skip_0:
    // 0x800E1F3C: lw          $v0, 0x168($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X168);
    // 0x800E1F40: beq         $v0, $zero, L_800E1F4C
    if (ctx->r2 == 0) {
        // 0x800E1F44: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_800E1F4C;
    }
    // 0x800E1F44: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800E1F48: sw          $t0, 0x168($s3)
    MEM_W(0X168, ctx->r19) = ctx->r8;
L_800E1F4C:
    // 0x800E1F4C: lw          $v0, 0x16C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X16C);
    // 0x800E1F50: beq         $v0, $zero, L_800E1F5C
    if (ctx->r2 == 0) {
        // 0x800E1F54: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800E1F5C;
    }
    // 0x800E1F54: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800E1F58: sw          $t1, 0x16C($s3)
    MEM_W(0X16C, ctx->r19) = ctx->r9;
L_800E1F5C:
    // 0x800E1F5C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
L_800E1F60:
    // 0x800E1F60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E1F64: blezl       $t2, L_800E1FC0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800E1F68: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800E1FC0;
    }
    goto skip_1;
    // 0x800E1F68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800E1F6C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_800E1F70:
    // 0x800E1F70: beql        $a0, $zero, L_800E1FA8
    if (ctx->r4 == 0) {
        // 0x800E1F74: lw          $t3, 0x0($s4)
        ctx->r11 = MEM_W(ctx->r20, 0X0);
            goto L_800E1FA8;
    }
    goto skip_2;
    // 0x800E1F74: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    skip_2:
    // 0x800E1F78: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E1F7C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E1F80: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800E1F84: jalr        $t9
    // 0x800E1F88: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800E1F88: nop

    after_0:
    // 0x800E1F8C: beq         $v0, $zero, L_800E1FA4
    if (ctx->r2 == 0) {
        // 0x800E1F90: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800E1FA4;
    }
    // 0x800E1F90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E1F94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800E1F98: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800E1F9C: jal         0x800E1E88
    // 0x800E1FA0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    ftMainSetHitHazard(rdram, ctx);
        goto after_1;
    // 0x800E1FA0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_1:
L_800E1FA4:
    // 0x800E1FA4: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
L_800E1FA8:
    // 0x800E1FA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E1FAC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800E1FB0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800E1FB4: bnel        $at, $zero, L_800E1F70
    if (ctx->r1 != 0) {
        // 0x800E1FB8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_800E1F70;
    }
    goto skip_3;
    // 0x800E1FB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_3:
L_800E1FBC:
    // 0x800E1FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E1FC0:
    // 0x800E1FC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E1FC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E1FC8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1FCC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E1FD0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E1FD4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E1FD8: jr          $ra
    // 0x800E1FDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E1FDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnPlayersVSSetIdlePlayerNotAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A40C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013A410: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8013A414: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013A418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013A41C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8013A420: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013A424: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x8013A428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013A42C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8013A430:
    // 0x8013A430: lw          $t6, 0x88($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X88);
    // 0x8013A434: bnel        $t6, $zero, L_8013A448
    if (ctx->r14 != 0) {
        // 0x8013A438: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013A448;
    }
    goto skip_0;
    // 0x8013A438: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8013A43C: jal         0x8013A3AC
    // 0x8013A440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSSetPlayerNot(rdram, ctx);
        goto after_0;
    // 0x8013A440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013A444: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8013A448:
    // 0x8013A448: bne         $s0, $s2, L_8013A430
    if (ctx->r16 != ctx->r18) {
        // 0x8013A44C: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_8013A430;
    }
    // 0x8013A44C: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x8013A450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013A454: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013A458: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A45C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8013A460: jr          $ra
    // 0x8013A464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013A464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftPurinSpecialNGetAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151274: bgez        $a0, L_80151284
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80151278: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80151284;
    }
    // 0x80151278: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8015127C: b           L_80151284
    // 0x80151280: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_80151284;
    // 0x80151280: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_80151284:
    // 0x80151284: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80151288: bnel        $at, $zero, L_80151298
    if (ctx->r1 != 0) {
        // 0x8015128C: addiu       $v0, $v0, -0xA
        ctx->r2 = ADD32(ctx->r2, -0XA);
            goto L_80151298;
    }
    goto skip_0;
    // 0x8015128C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    skip_0:
    // 0x80151290: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x80151294: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
L_80151298:
    // 0x80151298: bgez        $v0, L_801512A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015129C: nop
    
            goto L_801512A4;
    }
    // 0x8015129C: nop

    // 0x801512A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801512A4:
    // 0x801512A4: bgezl       $a0, L_801512B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801512A8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801512B4;
    }
    goto skip_1;
    // 0x801512A8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_1:
    // 0x801512AC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x801512B0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_801512B4:
    // 0x801512B4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x801512B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801512BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801512C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801512C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801512C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801512CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801512D0: lwc1        $f16, -0x3AE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3AE0);
    // 0x801512D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801512D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801512DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801512E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801512E4: jr          $ra
    // 0x801512E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    return;
    // 0x801512E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
;}
RECOMP_FUNC void mnPlayers1PTrainingPortraitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131D98: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80131D9C: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x80131DA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80131DA4: lw          $a1, 0x58($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X58);
    // 0x80131DA8: jal         0x80131C70
    // 0x80131DAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    mnPlayers1PTrainingGetNextPortraitX(rdram, ctx);
        goto after_0;
    // 0x80131DAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80131DB0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80131DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DB8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80131DBC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80131DC0: nop

    // 0x80131DC4: bc1tl       L_80131E00
    if (c1cs) {
        // 0x80131DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131E00;
    }
    goto skip_0;
    // 0x80131DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80131DCC: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80131DD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131DD4: swc1        $f0, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f0.u32l;
    // 0x80131DD8: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x80131DDC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80131DE0: beql        $v1, $zero, L_80131E00
    if (ctx->r3 == 0) {
        // 0x80131DE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131E00;
    }
    goto skip_1;
    // 0x80131DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80131DE8: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131DEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131DF0: nop

    // 0x80131DF4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80131DF8: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x80131DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131E00:
    // 0x80131E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131E04: jr          $ra
    // 0x80131E08: nop

    return;
    // 0x80131E08: nop

;}
RECOMP_FUNC void ftCommonDownForwardOrBackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801447E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801447E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801447E8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801447EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801447F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801447F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801447F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801447FC: jal         0x800E6F24
    // 0x80144800: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144800: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80144804: jal         0x800E0830
    // 0x80144808: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80144808: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8014480C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80144810: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
    // 0x80144814: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80144818: sb          $t9, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r25;
    // 0x8014481C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144824: jr          $ra
    // 0x80144828: nop

    return;
    // 0x80144828: nop

;}
RECOMP_FUNC void mnPlayers1PGameSpotlightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137A2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80137A30: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137A34: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x80137A38: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137A3C: addiu       $t6, $t6, -0x73A0
    ctx->r14 = ADD32(ctx->r14, -0X73A0);
    // 0x80137A40: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80137A44: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80137A48: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80137A4C:
    // 0x80137A4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80137A50: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80137A54: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80137A58: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80137A5C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80137A60: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80137A64: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80137A68: bne         $t6, $t0, L_80137A4C
    if (ctx->r14 != ctx->r8) {
        // 0x80137A6C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80137A4C;
    }
    // 0x80137A6C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80137A70: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x80137A74: bnel        $t1, $zero, L_80137AF8
    if (ctx->r9 != 0) {
        // 0x80137A78: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80137AF8;
    }
    goto skip_0;
    // 0x80137A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
    // 0x80137A7C: lw          $t2, 0x20($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X20);
    // 0x80137A80: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80137A84: beql        $t2, $at, L_80137AF8
    if (ctx->r10 == ctx->r1) {
        // 0x80137A88: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80137AF8;
    }
    goto skip_1;
    // 0x80137A88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_1:
    // 0x80137A8C: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
    // 0x80137A90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80137A94: bnel        $a1, $t3, L_80137AA8
    if (ctx->r5 != ctx->r11) {
        // 0x80137A98: sw          $a1, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r5;
            goto L_80137AA8;
    }
    goto skip_2;
    // 0x80137A98: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
    skip_2:
    // 0x80137A9C: b           L_80137AA8
    // 0x80137AA0: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80137AA8;
    // 0x80137AA0: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80137AA4: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
L_80137AA8:
    // 0x80137AA8: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x80137AAC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80137AB0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80137AB4: addu        $t0, $v0, $t5
    ctx->r8 = ADD32(ctx->r2, ctx->r13);
    // 0x80137AB8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80137ABC: swc1        $f4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
    // 0x80137AC0: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80137AC4: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x80137AC8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80137ACC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80137AD0: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80137AD4: swc1        $f6, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f6.u32l;
    // 0x80137AD8: lw          $t2, 0x20($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X20);
    // 0x80137ADC: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x80137AE0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80137AE4: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80137AE8: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80137AEC: b           L_80137AFC
    // 0x80137AF0: swc1        $f8, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f8.u32l;
        goto L_80137AFC;
    // 0x80137AF0: swc1        $f8, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f8.u32l;
    // 0x80137AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80137AF8:
    // 0x80137AF8: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
L_80137AFC:
    // 0x80137AFC: jr          $ra
    // 0x80137B00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80137B00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void syVideoSetFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E18: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006E1C: addiu       $v0, $v0, 0x6680
    ctx->r2 = ADD32(ctx->r2, 0X6680);
    // 0x80006E20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80006E24: andi        $t8, $a0, 0x20
    ctx->r24 = ctx->r4 & 0X20;
    // 0x80006E28: andi        $t0, $a0, 0x10
    ctx->r8 = ctx->r4 & 0X10;
    // 0x80006E2C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80006E30: beq         $t8, $zero, L_80006E44
    if (ctx->r24 == 0) {
        // 0x80006E34: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80006E44;
    }
    // 0x80006E34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80006E38: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80006E3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E40: sw          $t9, 0x6674($at)
    MEM_W(0X6674, ctx->r1) = ctx->r25;
L_80006E44:
    // 0x80006E44: beq         $t0, $zero, L_80006E58
    if (ctx->r8 == 0) {
        // 0x80006E48: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80006E58;
    }
    // 0x80006E48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80006E4C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80006E50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E54: sw          $t1, 0x6674($at)
    MEM_W(0X6674, ctx->r1) = ctx->r9;
L_80006E58:
    // 0x80006E58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E5C: jr          $ra
    // 0x80006E60: sw          $t2, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r10;
    return;
    // 0x80006E60: sw          $t2, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void ftLinkSpecialHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801642EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801642F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801642F4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801642F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801642FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164300: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x80164304: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164308: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8016430C: jal         0x800E6F24
    // 0x80164310: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164310: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80164314: jal         0x800E0830
    // 0x80164318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80164318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8016431C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80164320: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80164324: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80164328: addiu       $t7, $t7, 0x3EFC
    ctx->r15 = ADD32(ctx->r15, 0X3EFC);
    // 0x8016432C: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x80164330: sw          $t7, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r15;
    // 0x80164334: sw          $t8, 0x9FC($v0)
    MEM_W(0X9FC, ctx->r2) = ctx->r24;
    // 0x80164338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016433C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80164340: jr          $ra
    // 0x80164344: nop

    return;
    // 0x80164344: nop

;}
RECOMP_FUNC void itFFlowerWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175B64: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80175B68: jal         0x801735A0
    // 0x80175B6C: addiu       $a1, $a1, 0x5BE4
    ctx->r5 = ADD32(ctx->r5, 0X5BE4);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80175B6C: addiu       $a1, $a1, 0x5BE4
    ctx->r5 = ADD32(ctx->r5, 0X5BE4);
    after_0:
    // 0x80175B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175B7C: jr          $ra
    // 0x80175B80: nop

    return;
    // 0x80175B80: nop

;}
RECOMP_FUNC void wpLinkBoomerangGetAngleSetVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D914: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016D918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D91C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016D920: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016D924: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8016D928: lb          $a3, 0x1C3($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X1C3);
    // 0x8016D92C: bgez        $a3, L_8016D93C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8016D930: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8016D93C;
    }
    // 0x8016D930: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8016D934: b           L_8016D93C
    // 0x8016D938: negu        $v0, $a3
    ctx->r2 = SUB32(0, ctx->r7);
        goto L_8016D93C;
    // 0x8016D938: negu        $v0, $a3
    ctx->r2 = SUB32(0, ctx->r7);
L_8016D93C:
    // 0x8016D93C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8016D940: bnel        $at, $zero, L_8016D9B8
    if (ctx->r1 != 0) {
        // 0x8016D944: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_8016D9B8;
    }
    goto skip_0;
    // 0x8016D944: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x8016D948: lb          $v1, 0x1C2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C2);
    // 0x8016D94C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8016D950: bgez        $v1, L_8016D960
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8016D954: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016D960;
    }
    // 0x8016D954: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016D958: b           L_8016D964
    // 0x8016D95C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8016D964;
    // 0x8016D95C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8016D960:
    // 0x8016D960: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8016D964:
    // 0x8016D964: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8016D968: jal         0x8001863C
    // 0x8016D96C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8016D96C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x8016D970: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D974: lwc1        $f2, -0x3434($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3434);
    // 0x8016D978: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8016D97C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D980: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016D984: nop

    // 0x8016D988: bc1f        L_8016D998
    if (!c1cs) {
        // 0x8016D98C: nop
    
            goto L_8016D998;
    }
    // 0x8016D98C: nop

    // 0x8016D990: b           L_8016D9BC
    // 0x8016D994: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8016D9BC;
    // 0x8016D994: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8016D998:
    // 0x8016D998: lwc1        $f2, -0x3430($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3430);
    // 0x8016D99C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8016D9A0: nop

    // 0x8016D9A4: bc1f        L_8016D9BC
    if (!c1cs) {
        // 0x8016D9A8: nop
    
            goto L_8016D9BC;
    }
    // 0x8016D9A8: nop

    // 0x8016D9AC: b           L_8016D9BC
    // 0x8016D9B0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8016D9BC;
    // 0x8016D9B0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8016D9B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_8016D9B8:
    // 0x8016D9B8: nop

L_8016D9BC:
    // 0x8016D9BC: jal         0x80035CD0
    // 0x8016D9C0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016D9C0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8016D9C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8016D9C8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8016D9CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8016D9D0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8016D9D4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8016D9D8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8016D9DC: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016D9E0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8016D9E4: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8016D9E8: jal         0x800303F0
    // 0x8016D9EC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016D9EC: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8016D9F0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8016D9F4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8016D9F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8016D9FC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8016DA00: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8016DA04: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8016DA08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016DA0C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8016DA10: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x8016DA14: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8016DA18: swc1        $f14, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f14.u32l;
    // 0x8016DA1C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8016DA20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DA24: bnel        $t0, $at, L_8016DA58
    if (ctx->r8 != ctx->r1) {
        // 0x8016DA28: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_8016DA58;
    }
    goto skip_1;
    // 0x8016DA28: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_1:
    // 0x8016DA2C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8016DA30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DA34: bc1f        L_8016DA4C
    if (!c1cs) {
        // 0x8016DA38: nop
    
            goto L_8016DA4C;
    }
    // 0x8016DA38: nop

    // 0x8016DA3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DA40: lwc1        $f10, -0x342C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X342C);
    // 0x8016DA44: b           L_8016DA54
    // 0x8016DA48: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
        goto L_8016DA54;
    // 0x8016DA48: sub.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f12.fl;
L_8016DA4C:
    // 0x8016DA4C: lwc1        $f16, -0x3428($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3428);
    // 0x8016DA50: sub.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f12.fl;
L_8016DA54:
    // 0x8016DA54: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_8016DA58:
    // 0x8016DA58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DA5C: bc1fl       L_8016DA70
    if (!c1cs) {
        // 0x8016DA60: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8016DA70;
    }
    goto skip_2;
    // 0x8016DA60: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x8016DA64: lwc1        $f18, -0x3424($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3424);
    // 0x8016DA68: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x8016DA6C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8016DA70:
    // 0x8016DA70: jr          $ra
    // 0x8016DA74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8016DA74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
